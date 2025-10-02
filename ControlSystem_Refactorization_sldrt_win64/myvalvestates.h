#ifndef myvalvestates_h_
#define myvalvestates_h_
#include "rtwtypes.h"

typedef uint8_T EstadoValvula;

/* enum EstadoValvula */
#define EstadoValvula_Bloquear         ((EstadoValvula)0U)       /* Default value */
#define EstadoValvula_Flexion          ((EstadoValvula)1U)
#define EstadoValvula_Extension        ((EstadoValvula)2U)
#endif                                 /* myvalvestates_h_ */
