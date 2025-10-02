classdef manualControlLogic < matlab.System
    % Lógica de control manual
    %
    % Este sistema, en base al estado actual de los actuadores y las referencias solicitadas por el usuario,
    % determina qué actuadores se encuentran posicionados correctamente, selecciona el controlador y las referencias de control
    % para la etapa actual de ejecución, y el estado de las electroválvulas de cada actuador.

    % Public, tunable properties
    properties

    end

    % Pre-computed constants or internal states
    properties (Access = private)

    end

    methods (Access = protected)
        function setupImpl(obj)
            % Perform one-time calculations, such as computing constants
        end

        function [controlador, actuadoresPosicionados, ...
            valvulasCerradas_controlAutonomo, ...
            realimentacion_presion, realimentacion_curvatura, ...
            referencia_presion, referencia_curvatura] = ...
            stepImpl(obj, sistema, actuadorBus, regulador)
            % Implement algorithm. Calculate y as a function of input u and
            % internal states.

            % Inicializar variables
            numAct = length(actuadorBus);
            modoControl = sistema.Configuracion.Global.modoControl;
            parametroControl = sistema.Configuracion.Global.parametroControl;
            actuadorSeleccionado = sistema.Configuracion.ControlManual.actuadorSeleccionado;
            referencias = struct( ...
                'presion', arrayfun(@(x) x.Configuracion.Global.Referencia.presion, actuadorBus), ...
                'curvatura', arrayfun(@(x) x.Configuracion.Global.Referencia.curvatura, actuadorBus) ...
            );
            realimentaciones = struct( ...
                'presionRegulador', regulador.Estado.presion, ...
                'actuador', struct( ...
                    'presion', arrayfun(@(x) x.Estado.Realimentacion.presion, actuadorBus), ...
                    'curvatura', arrayfun(@(x) x.Estado.Realimentacion.curvatura, actuadorBus) ...
                ) ...
            );

            % Inicializar salidas
            % 1. Controlador activo
            controlador = Controlador.Presion;
            % 2. Actuadores posicionados
            actuadoresPosicionados = repmat(ActuadorPosicionado.Control_Manual,1,numAct);
            % 3. Realimentación y referencias por defecto
            realimentacion_presion = realimentaciones.presionRegulador;
            realimentacion_curvatura = double(0);
            referencia_presion = realimentacion_presion;
            referencia_curvatura = realimentacion_curvatura;
            % 4. Estado electroválvulas (control autónomo)
            valvulasCerradas_controlAutonomo = arrayfun(@(x) x.Estado.ControlAutomatico.valvulaCerrada, actuadorBus)';
            % Finalizar lógica de control si está deshabilitada o no hay ningún actuador seleccionado
            if modoControl ~= ModoControl.Manual | actuadorSeleccionado == 0 
                return
            end

            % Lógica de control
            % 1. Señales de control
            if actuadorSeleccionado ~= 0
                % 1.1 Referencias
                referencia_presion = referencias.presion(actuadorSeleccionado);
                referencia_curvatura = referencias.curvatura(actuadorSeleccionado);
                % 1.2 Realimentaciones
                realimentacion_presion = realimentaciones.actuador.presion(actuadorSeleccionado);
                realimentacion_curvatura = realimentaciones.actuador.curvatura(actuadorSeleccionado);
            end
            % 2. Controlador activo
            if parametroControl == ParametroControl.Curvatura
                controlador = Controlador.Curvatura;
            end

        end

        function resetImpl(obj)
            % Initialize / reset internal properties
        end
    end
end