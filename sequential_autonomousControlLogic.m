classdef sequential_autonomousControlLogic < matlab.System
    % Lógica de control autónomo secuencial
    %
    % Este sistema, en base al estado actual de los actuadores y las referencias solicitadas por el usuario,
    % determina qué actuadores se encuentran posicionados correctamente, selecciona el controlador y las referencias de control
    % para la etapa actual de ejecución, y el estado de las electroválvulas de cada actuador.

    % Public, tunable properties
    properties
        
    end

    properties (Nontunable)
        numAct (1,1) double {mustBeInteger, mustBeNonnegative} = 0
    end

    % Pre-computed constants or internal states
    properties (Access = private)
        controlHabilitado
        modoControl
        parametroControl
        actuadorSeleccionado
        referencias
        realimentaciones
        tolerancias
        errores
        errorControl
        actuadoresActivos
        estadoValvulas
    end

    methods (Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
            obj.controlHabilitado = false; % Registra si esta lógica de control se encuentra actualmente activa
            %obj.numAct = length(actuadorBus);
            obj.modoControl = ModoControl.Manual;
            obj.parametroControl = ParametroControl.Presion;
            obj.actuadorSeleccionado = 0;
            obj.referencias = repmat(double(0),obj.numAct,1);
            obj.realimentaciones = struct( ...
                'presionRegulador', double(0), ...
                'presionesEquilibrio', repmat(double(0),obj.numAct,1), ...
                'actuador', repmat(double(0),obj.numAct,1) ...
            );
            obj.tolerancias = struct( ...
                'estacionaria', double(0), ...
                'derivativa', double(0), ...
                'equilibrioPresiones', double(0) ...
            );
            obj.errores = repmat(double(0),obj.numAct,1);
            obj.errorControl = struct( ...
                'estacionario', double(0), ...
                'derivativo', double(0) ...
            );
            obj.actuadoresActivos = false(obj.numAct,1);
            obj.estadoValvulas = repmat(EstadoValvula.Expulsar,1,obj.numAct);
        end

        function [controlador, actuadoresPosicionados, ...
                estadoValvulas_ControlAutonomo, ...
                realimentacionControl, referenciaControl] ...
                = stepImpl(obj, sistema, actuadorBus, regulador)

            % 1. REINICIO DE ESTADO
            % Se reinicia el actuador seleccionado al deshabilitar esta
            % lógica de control o cambiar el parámetro de control
            if ~obj.controlHabilitado || sistema.Configuracion.Global.parametroControl ~= obj.parametroControl
                obj.controlHabilitado = true;
                obj.parametroControl = sistema.Configuracion.Global.parametroControl;
                obj.actuadorSeleccionado = 0;
            end

            % 2. INICIALIZACIÓN DE VARIABLES
            % Registra el estado actual del sistema de control
            obj.parametroControl = sistema.Configuracion.Global.parametroControl;
            switch obj.parametroControl
                case ParametroControl.Presion
                    obj.referencias = arrayfun(@(x) x.Configuracion.Global.Referencia.presion, actuadorBus);
                    obj.realimentaciones.actuador = arrayfun(@(x) x.Estado.Realimentacion.presion, actuadorBus);
                    obj.tolerancias.estacionaria = sistema.Configuracion.Global.ToleranciaPresion.estacionaria;
                    obj.tolerancias.derivativa = sistema.Configuracion.Global.ToleranciaPresion.derivativa;
                    controlador = Controlador.Presion;
                case ParametroControl.Curvatura
                    obj.referencias = arrayfun(@(x) x.Configuracion.Global.Referencia.curvatura, actuadorBus);
                    obj.realimentaciones.actuador = arrayfun(@(x) x.Estado.Realimentacion.curvatura, actuadorBus);
                    obj.tolerancias.estacionaria = sistema.Configuracion.Global.ToleranciaCurvatura.estacionaria;
                    obj.tolerancias.derivativa = sistema.Configuracion.Global.ToleranciaCurvatura.derivativa;
                    controlador = Controlador.Curvatura;
                otherwise
                    error('No se ha escogido un parámetro de control correcto.');
            end
            obj.modoControl = sistema.Configuracion.Global.modoControl;
            obj.realimentaciones.presionRegulador = regulador.Estado.presion;
            obj.realimentaciones.presionesEquilibrio = arrayfun(@(x) x.Estado.Realimentacion.presion, actuadorBus);
            obj.actuadoresActivos = arrayfun(@(x) x.Configuracion.Global.activo, actuadorBus);
            obj.errores = obj.referencias - obj.realimentaciones.actuador;
            obj.tolerancias.equilibrioPresiones = sistema.Configuracion.Global.toleranciaEquilibrioPresiones;
            obj.errorControl.estacionario = sistema.Estado.Global.errorEstacionario;
            obj.errorControl.derivativo = sistema.Estado.Global.errorDerivativo;
            obj.estadoValvulas = arrayfun(@(x) x.Estado.ControlAutomatico.estadoValvula, actuadorBus)';
            
            % 3. INICIALIZACIÓN DE SALIDAS
            actuadoresPosicionados = repmat(ActuadorPosicionado.Desposicionado,1,obj.numAct);
            realimentacionControl = sistema.Estado.Global.realimentacionControl;
            referenciaControl = sistema.Configuracion.Global.referenciaControl;
            estadoValvulas_ControlAutonomo = arrayfun(@(x) x.Estado.ControlAutomatico.estadoValvula, actuadorBus)';
            
            % 4. FINALIZAR EJECUCIÓN SI LÓGICA DESHABILITADA
            % La ejecución termina directamente si esta lógica de control
            % está deshabilitada, para no consumir recursos
            if obj.modoControl ~= ModoControl.Autonomo_Secuencial
                obj.controlHabilitado = false;
                return
            end

            % 5. LÓGICA DE CONTROL
            % 5.1 Se comprueba el posicionamiento actual de los actuadores
            actuadoresPosicionados = actualizarPosicionamiento(obj);
            % 5.2 Se selecciona el actuador utilizado como referencia para el control
            obj.actuadorSeleccionado = seleccionarActuador(obj, actuadoresPosicionados);
            % 5.3 Se establecen los estados de las electroválvulas
            [estadoValvulas_ControlAutonomo, controlador] = obj.elegirEstadoValvulas();
            % 5.4 Se definen las señales de control
            [referenciaControl, realimentacionControl] = controlSignals(obj, controlador);

        end

        function resetImpl(obj)
            % Initialize / reset internal properties
        end

        function actuadoresPosicionados = actualizarPosicionamiento(obj)
            % Verifica si los actuadores están posicionados o
            % desposicionados
            actuadoresPosicionados = repmat(ActuadorPosicionado.Desposicionado,1,obj.numAct);
            % Comprueba si los actuadores se encuentran posicionados o desposicionados
            for act = 1:obj.numAct
                % 1. Actuador desactivado
                if ~obj.actuadoresActivos(act)
                    actuadoresPosicionados(act) = ActuadorPosicionado.Control_Manual;
                    continue
                end
                % 2. Actuador seleccionado como referencia para control
                if act == obj.actuadorSeleccionado & ...
                        abs(obj.errorControl.estacionario) <= obj.tolerancias.estacionaria & ...
                        abs(obj.errorControl.derivativo) <= obj.tolerancias.derivativa
                    actuadoresPosicionados(act) = ActuadorPosicionado.Posicionado;
                    obj.actuadorSeleccionado = 0;
                    continue
                elseif act == obj.actuadorSeleccionado
                    continue
                end
                % 3. Actuador previamente posicionado
                if abs(obj.errores(act)) > obj.tolerancias.estacionaria
                    actuadoresPosicionados(act) = ActuadorPosicionado.Desposicionado;
                    continue
                end
                % 4. Actuador previamente desposicionado
                if abs(obj.errores(act)) <= obj.tolerancias.estacionaria
                    actuadoresPosicionados(act) = ActuadorPosicionado.Posicionado;
                    continue
                end
            end
        end

        function actuadorSeleccionado = seleccionarActuador(obj, actuadoresPosicionados)
            % Selecciona el actuador a utilizar como referencia de control
            actuadorSeleccionado = obj.actuadorSeleccionado;
            % 1. Si ya hay un actuador en control, se mantiene como
            % referencia hasta que haya sido posicionado
            if obj.actuadorSeleccionado ~= 0 && actuadoresPosicionados(obj.actuadorSeleccionado) ~= ActuadorPosicionado.Posicionado
                return
            end
            % 2. Si todos los actuadores ya están posicionados, no se selecciona
            % ninguno
            if ~ismember(ActuadorPosicionado.Desposicionado, actuadoresPosicionados)
                actuadorSeleccionado = 0;
                return
            end
            % 3. Se selecciona el actuador activo con mayor error estacionario
            maxError = double(0);
            for act = 1:obj.numAct
                actError = abs(obj.errores(act));
                if actError > maxError && obj.actuadoresActivos(act) == true
                    maxError = actError;
                    actuadorSeleccionado = act;
                end
            end
        end

        function [estadoValvulas, controlador] = elegirEstadoValvulas(obj)
            % Establece la posición de las electroválvulas para el instante
            % actual
            estadoValvulas = obj.estadoValvulas;
            switch obj.parametroControl
                case ParametroControl.Presion
                    controlador = Controlador.Presion;
                case ParametroControl.Curvatura
                    controlador = Controlador.Curvatura;
                otherwise
                    error('No se ha escogido un parámetro de control correcto.');
            end

            % INICIALIZACIÓN DE REFERENCIAS
            % 1. Referencia de estado para válvulas en posición de bloqueo
            estadoValvulas_Bloqueo = repmat(EstadoValvula.Bloquear,1,obj.numAct);
            estadoValvulas_Bloqueo(~obj.actuadoresActivos) = EstadoValvula.Expulsar;
            % 2. Referencia de estado para válvulas en posición de control
            % activo
            estadoValvulas_Control = estadoValvulas_Bloqueo;
            if obj.actuadorSeleccionado ~= 0
                estadoValvulas_Control(obj.actuadorSeleccionado) = EstadoValvula.Inyectar;
            end
            % 3. Referencia de actuadores no seleccionados para el control
            actuadoresNoSeleccionados = (1:obj.numAct ~= obj.actuadorSeleccionado);

            % SELECCIÓN DE ESTADO DE ELECTROVÁLVULAS
            % 1. Si hay actuadores distintos al seleccionado
            % inyectando aire, o no hay actuadores seleccionados,
            % se cierran todas las válvulas en esta etapa de ejecución
            if  ismember(EstadoValvula.Inyectar, obj.estadoValvulas(actuadoresNoSeleccionados)) | obj.actuadorSeleccionado == 0
                estadoValvulas = estadoValvulas_Bloqueo;
                return
            end
            % 2. Si todas las válvulas están cerradas, y la presión del
            % regulador es distinta a la del actuador seleccionado, se
            % continúa el proceso de equilibrio de presiones.
            diferenciaPresion = abs(obj.realimentaciones.presionesEquilibrio(obj.actuadorSeleccionado) - obj.realimentaciones.presionRegulador);
            if estadoValvulas(obj.actuadorSeleccionado) == EstadoValvula.Bloquear & diferenciaPresion > obj.tolerancias.equilibrioPresiones
                estadoValvulas = estadoValvulas_Bloqueo;
                controlador = Controlador.EquilibrioPresiones;
                return
            end
            % 3. En otro caso, se continúa con el control del actuador
            estadoValvulas = estadoValvulas_Control;
        end

        function [referenciaControl, realimentacionControl] = controlSignals(obj, controlador)

            % Selecciona las señales de control para realimentación y
            % referencia, según el estado del sistema
            % 1. No hay actuadores seleccionados
            if obj.actuadorSeleccionado == 0
                realimentacionControl = obj.realimentaciones.presionRegulador;
                referenciaControl = realimentacionControl;
                return
            end
            % 2. Equilibrio de presiones
            if controlador == Controlador.EquilibrioPresiones
                realimentacionControl = obj.realimentaciones.presionRegulador;
                referenciaControl = obj.realimentaciones.presionesEquilibrio(obj.actuadorSeleccionado);
                return
            end
            % 3. Control del actuador
            realimentacionControl = obj.realimentaciones.actuador(obj.actuadorSeleccionado);
            referenciaControl = obj.referencias(obj.actuadorSeleccionado);
        end
    end
end