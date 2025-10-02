classdef elegirTensionesElectrovalvulas < matlab.System
    % Control de electroválvulas
    %
    % Este sistema controla las señales de tensión digitales enviadas a
    % cada una de las electroválvulas conectadas a los actuadores.
    %
    % 1. Lee el vector con los índices de los puertos de tensión digitales
    % asignados a cada uno de los actuadores
    % 2. Genera un vector de tensiones de salida, del mismo tamaño
    % 3. Recorre cada uno de los actuadores del sistema
    % 4. Comprueba el flujo de aire asignado a cada actuador (bloquear,
    % flexión, extensión) y determina los valores de tensión necesarios
    % 5. Asigna los valores de tensión a los índices de los puertos de
    % tensión conectados con ese actuador

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

        function tensionesSalida = stepImpl(obj, sistema, actuadorBus, electroValvulas)
            % Implement algorithm. Calculate y as a function of input u and
            % internal states.
            
            % Inicialización de variables
            modoControl = sistema.Configuracion.Global.modoControl;
            tensionControl = sistema.Estado.Global.tensionControl;
            puertosDigitales = electroValvulas.Configuracion.PuertosDigitales;
            tensionesSalida = zeros(length(puertosDigitales),1);

            % Seleccionar cámara de control
            valvulaControl = EstadoValvula.Flexion;
            if tensionControl < double(0)
                valvulaControl = EstadoValvula.Extension;
            end

            % Selección de tensiones de salida
            for actuador = 1:length(actuadorBus)
                % Estado del actuador
                if modoControl == ModoControl.Manual
                    if actuadorBus(actuador).Configuracion.ControlManual.valvulaCerrada == true
                        estadoActuador = EstadoValvula.Bloquear;
                    else
                        estadoActuador = valvulaControl;
                    end
                else
                    if actuadorBus(actuador).Estado.ControlAutomatico.valvulaCerrada == true
                        estadoActuador = EstadoValvula.Bloquear;
                    else
                        estadoActuador = valvulaControl;
                    end
                end
                % Puertos de conexión de la electoválvula del actuador
                puertoTerminalA = electroValvulas.Configuracion.ConexionActuadores(actuador).terminalA;
                puertoTerminalB = electroValvulas.Configuracion.ConexionActuadores(actuador).terminalB;
                % Tensiones de salida para este actuador
                [tensionTerminalA, tensionTerminalB] = obj.asignarTensiones(estadoActuador);
                % Asignar tensiones de salida a los puertos correspondientes
                tensionesSalida(puertosDigitales == puertoTerminalA) = tensionTerminalA;
                tensionesSalida(puertosDigitales == puertoTerminalB) = tensionTerminalB;
            end
        end

        function [tensionTerminalA, tensionTerminalB] = asignarTensiones(obj, estadoActuador)
            switch estadoActuador
                case EstadoValvula.Bloquear
                    tensionTerminalA = 0;
                    tensionTerminalB = 0;
                case EstadoValvula.Flexion
                    tensionTerminalA = 1;
                    tensionTerminalB = 0;
                case EstadoValvula.Extension
                    tensionTerminalA = 0;
                    tensionTerminalB = 1;
                otherwise
                    tensionTerminalA = 0;
                    tensionTerminalB = 0;
                    warning('El estado de electroválvula escogido no está definido.');
            end
        end

        function resetImpl(obj)
            % Initialize / reset internal properties
        end
    end
end
