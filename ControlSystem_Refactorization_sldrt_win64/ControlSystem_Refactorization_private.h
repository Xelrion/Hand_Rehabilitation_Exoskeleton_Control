/*
 * ControlSystem_Refactorization_private.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "ControlSystem_Refactorization".
 *
 * Model version              : 2.9
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Sun Sep 14 20:33:31 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ControlSystem_Refactorization_private_h_
#define ControlSystem_Refactorization_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "ControlSystem_Refactorization.h"
#include "ControlSystem_Refactorization_types.h"

extern void ControlSystem_Refactorization_CurvaturaActuador5_Init
  (B_CurvaturaActuador5_ControlSystem_Refactorization_T *localB,
   P_CurvaturaActuador5_ControlSystem_Refactorization_T *localP,
   X_CurvaturaActuador5_ControlSystem_Refactorization_T *localX);
extern void ControlSystem_Refactorization_CurvaturaActuador5_Start
  (B_CurvaturaActuador5_ControlSystem_Refactorization_T *localB,
   DW_CurvaturaActuador5_ControlSystem_Refactorization_T *localDW,
   XDis_CurvaturaActuador5_ControlSystem_Refactorization_T *localXdis);
extern void ControlSystem_Refactorization_CurvaturaActuador5_Deriv(real_T
  rtu_PresinEntrada, DW_CurvaturaActuador5_ControlSystem_Refactorization_T
  *localDW, P_CurvaturaActuador5_ControlSystem_Refactorization_T *localP,
  X_CurvaturaActuador5_ControlSystem_Refactorization_T *localX,
  XDot_CurvaturaActuador5_ControlSystem_Refactorization_T *localXdot);
extern void ControlSystem_Refactorization_CurvaturaActuador5_Disable
  (DW_CurvaturaActuador5_ControlSystem_Refactorization_T *localDW);
extern void ControlSystem_Refactorization_CurvaturaActuador5
  (RT_MODEL_ControlSystem_Refactorization_T * const
   ControlSystem_Refactorization_M, boolean_T rtu_Enable,
   B_CurvaturaActuador5_ControlSystem_Refactorization_T *localB,
   DW_CurvaturaActuador5_ControlSystem_Refactorization_T *localDW,
   P_CurvaturaActuador5_ControlSystem_Refactorization_T *localP,
   X_CurvaturaActuador5_ControlSystem_Refactorization_T *localX,
   XDis_CurvaturaActuador5_ControlSystem_Refactorization_T *localXdis);

/* private model entry point functions */
extern void ControlSystem_Refactorization_derivatives(void);

#endif                            /* ControlSystem_Refactorization_private_h_ */
