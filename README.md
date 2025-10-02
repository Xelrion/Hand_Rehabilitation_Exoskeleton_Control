# Hand_Rehabilitation_Exoskeleton_Control
Software de control desarrollado para la simulación y el control en tiempo real de un exoesqueleto blando para rehabilitación de manos, fabricado con actuadores neumáticos de hidrogel CN.

Este repositorio forma parte de un Trabajo Fin de Máster (TFM) en Robótica y Automática.

El software se ha desarrollado mediante Simulink Desktop Real-Time, en Matlab 2025a, y sido desarrollado para comunicarse con la tarjeta de adquisición de datos NI PCIe-6323.
## Archivos del programa
### ControlSystem_Refactorization.slx
El modelo de Simulink principal, donde se integra toda la lógica del programa, la interacción con el hardware, los modelos de simulación, y la interfaz de usuario desplegable.
### inicializarBuses.m
Código que se ejecuta automáticamente al iniciar el modelo *ControlSystem_Refactorization*, mediante su propiedad *preLoad_fcn*. Genera todas las estructuras de datos que utiliza el modelo para transmitir la información del sistema,
como la configuración y referencias establecidas por el usuario, o el estado de los actuadores y la señal activa de control. También configura los terminales de entrada y salida de la tarjeta de adquisición de datos, asociándolos
a sus conexiones con el hardware del sistema (control y realimentación del regulador electrónico de presión, terminales A y B de control de las electroválvulas, sensores de curvatura de los actuadores...).
### manualControlLogic.m
Implementa la lógica de control manual, en la que el usuario controla de manera activa el estado de todas las electroválvulas del sistema y la referencia de control activa.
### sequential_autonomousControlLogic.m
Implementa la lógica de control autónoma secuencial, en la que el sistema se encarga de posicionar todos los actuadores activos en las referencias de posición deseadas. Para ello, gestiona de manera automática el actuador
seleccionado en cada momento y el estado de las electroválvulas.
### elegirTensionesElectrovalvulas.m
Recibe el flujo de aire deseado para cada uno de los actuadores del sistema, y determina todas las señales eléctricas que deben ser enviadas a las electroválvulas.
