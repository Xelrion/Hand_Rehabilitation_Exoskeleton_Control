#ifndef act_position_h_
#define act_position_h_
#include "rtwtypes.h"

typedef uint8_T ActuadorPosicionado;

/* enum ActuadorPosicionado */
#define ActuadorPosicionado_Posicionado ((ActuadorPosicionado)0U)
#define ActuadorPosicionado_Desposicionado ((ActuadorPosicionado)1U) /* Default value */
#define ActuadorPosicionado_Control_Manual ((ActuadorPosicionado)2U)
#endif                                 /* act_position_h_ */
