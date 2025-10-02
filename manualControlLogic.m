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
                estadoValvulas_ControlAutonomo, ...
                realimentacionControl, referenciaControl] ...
                = stepImpl(obj, sistema, actuadorBus, regulador)

            % 1. INICIALIZACIÓN DE VARIABLES
            numAct = length(actuadorBus);
            modoControl = sistema.Configuracion.Global.modoControl;
            parametroControl = sistema.Configuracion.Global.parametroControl;
            actuadorSeleccionado = sistema.Configuracion.ControlManual.actuadorSeleccionado;

            % 2. INICIALIZACIÓN DE SALIDAS
            actuadoresPosicionados = repmat(ActuadorPosicionado.Control_Manual,1,numAct);
            estadoValvulas_ControlAutonomo = arrayfun(@(x) x.Estado.ControlAutomatico.estadoValvula, actuadorBus)';
            controlador = Controlador.Presion;
            % 1. No hay ningún actuador seleccionado o el modo de control
            % manual está deshabilitado
            if actuadorSeleccionado == 0 | modoControl ~= ModoControl.Manual
                referenciaControl = regulador.Estado.presion;
                realimentacionControl = regulador.Estado.presion;
                return
            end
            % 2. Se escogen las señales en función del actuador
            % seleccionado y del parámetro de control activo
            switch parametroControl
                case ParametroControl.Presion
                    controlador = Controlador.Presion;
                    referenciaControl = actuadorBus(actuadorSeleccionado).Configuracion.Global.Referencia.presion;
                    realimentacionControl = actuadorBus(actuadorSeleccionado).Estado.Realimentacion.presion;
                case ParametroControl.Curvatura
                    controlador = Controlador.Curvatura;
                    referenciaControl = actuadorBus(actuadorSeleccionado).Configuracion.Global.Referencia.curvatura;
                    realimentacionControl = actuadorBus(actuadorSeleccionado).Estado.Realimentacion.curvatura;
                otherwise
                    error('No se ha escogido un parámetro de control correcto.');
            end
        end

        function resetImpl(obj)
            % Initialize / reset internal properties
        end
    end
end
