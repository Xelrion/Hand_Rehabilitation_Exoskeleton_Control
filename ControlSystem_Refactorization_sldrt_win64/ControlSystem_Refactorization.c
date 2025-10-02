/*
 * ControlSystem_Refactorization.c
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

#include "ControlSystem_Refactorization.h"
#include "rtwtypes.h"
#include "ControlSystem_Refactorization_types.h"
#include "modo_control.h"
#include "referencia_control.h"
#include "controlador.h"
#include "act_position.h"
#include "ControlSystem_Refactorization_private.h"
#include <emmintrin.h>
#include <string.h>
#include <math.h>
#include "zero_crossing_types.h"
#include "ControlSystem_Refactorization_dt.h"

/* Named constants for MATLAB Function: '<S21>/MATLAB Function' */
#define ControlSystem_Refactorization_CALL_EVENT (-1)

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.0001, 0.0,
};

const slBusActuador ControlSystem_Refactorization_rtZslBusActuador = {
  {
    {
      false,                           /* activo */
      0.0,                             /* indice */

      {
        0.0,                           /* presion */
        0.0                            /* curvatura */
      }                                /* Referencia */
    },                                 /* Global */

    {
      false                            /* valvulaCerrada */
    }                                  /* ControlManual */
  },                                   /* Configuracion */

  {
    {
      false,                           /* valvulaCerrada */
      ActuadorPosicionado_Desposicionado/* actuadorPosicionado */
    },                                 /* ControlAutomatico */

    {
      0.0,                             /* presion */
      0.0                              /* curvatura */
    }                                  /* Realimentacion */
  }                                    /* Estado */
};                                     /* slBusActuador ground */

/* Block signals (default storage) */
B_ControlSystem_Refactorization_T ControlSystem_Refactorization_B;

/* Continuous states */
X_ControlSystem_Refactorization_T ControlSystem_Refactorization_X;

/* Disabled State Vector */
XDis_ControlSystem_Refactorization_T ControlSystem_Refactorization_XDis;

/* Block states (default storage) */
DW_ControlSystem_Refactorization_T ControlSystem_Refactorization_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_ControlSystem_Refactorization_T ControlSystem_Refactorization_PrevZCX;

/* Real-time model */
static RT_MODEL_ControlSystem_Refactorization_T ControlSystem_Refactorization_M_;
RT_MODEL_ControlSystem_Refactorization_T *const ControlSystem_Refactorization_M =
  &ControlSystem_Refactorization_M_;

/* Forward declaration for local functions */
static boolean_T ControlSystem_Refactorization_isMember(const
  ActuadorPosicionado s[4]);
static boolean_T ControlSystem_Refactorization_isMember_d(const boolean_T
  s_data[], const int32_T *s_size);
static void
  ControlSystem_Refactorization_sequential_autonomousControlLogic_controlSignals
  (const slBusActuador actuadorBus[4], real_T regulador_Estado_presion, real_T
   actuadorSeleccionado, Controlador controlador, real_T *referencia_presion,
   real_T *referencia_curvatura, real_T *realimentacion_presion, real_T
   *realimentacion_curvatura);
static void
  ControlSystem_Refactorization_sequential_autonomousControlLogic_stepImpl
  (sequential_autonomousControlLogic_ControlSystem_Refactorization_T *obj,
   ModoControl sistema_Configuracion_Global_modoControl, ParametroControl
   sistema_Configuracion_Global_parametroControl, Controlador
   sistema_Configuracion_Global_controlador, real_T
   sistema_Configuracion_Global_toleranciaEquilibrioPresiones, real_T
   sistema_Configuracion_Global_ToleranciaPresion_estacionaria, real_T
   sistema_Configuracion_Global_ToleranciaPresion_derivativa, real_T
   sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria, real_T
   sistema_Configuracion_Global_ToleranciaCurvatura_derivativa, real_T
   sistema_Estado_Global_errorEstacionario_presion, real_T
   sistema_Estado_Global_errorEstacionario_curvatura, real_T
   sistema_Estado_Global_errorDerivativo_presion, real_T
   sistema_Estado_Global_errorDerivativo_curvatura, const slBusActuador
   actuadorBus[4], real_T regulador_Estado_presion, Controlador *controlador,
   ActuadorPosicionado actuadoresPosicionados[4], boolean_T
   valvulasCerradas_controlAutonomo[4], real_T *realimentacion_presion, real_T
   *realimentacion_curvatura, real_T *referencia_presion, real_T
   *referencia_curvatura);

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 103;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  ControlSystem_Refactorization_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  ControlSystem_Refactorization_output();
  ControlSystem_Refactorization_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  ControlSystem_Refactorization_output();
  ControlSystem_Refactorization_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for enable system:
 *    '<S27>/Curvatura Actuador 5'
 *    '<S27>/Curvatura Actuador 4'
 *    '<S27>/Curvatura Actuador 3'
 *    '<S27>/Curvatura Actuador 2'
 *    '<S27>/Curvatura Actuador 1'
 */
void ControlSystem_Refactorization_CurvaturaActuador5_Init
  (B_CurvaturaActuador5_ControlSystem_Refactorization_T *localB,
   P_CurvaturaActuador5_ControlSystem_Refactorization_T *localP,
   X_CurvaturaActuador5_ControlSystem_Refactorization_T *localX)
{
  int_T is;

  /* InitializeConditions for TransferFcn: '<S40>/Modelo de curvatura del actuador' */
  for (is = 0; is < 5; is++) {
    localX->Modelodecurvaturadelactuador_CSTATE[is] = 0.0;
  }

  /* End of InitializeConditions for TransferFcn: '<S40>/Modelo de curvatura del actuador' */

  /* SystemInitialize for TransferFcn: '<S40>/Modelo de curvatura del actuador' incorporates:
   *  Outport: '<S40>/Curvatura'
   */
  localB->CurvAct = localP->Curvatura_Y0;
}

/*
 * Disable for enable system:
 *    '<S27>/Curvatura Actuador 5'
 *    '<S27>/Curvatura Actuador 4'
 *    '<S27>/Curvatura Actuador 3'
 *    '<S27>/Curvatura Actuador 2'
 *    '<S27>/Curvatura Actuador 1'
 */
void ControlSystem_Refactorization_CurvaturaActuador5_Disable
  (DW_CurvaturaActuador5_ControlSystem_Refactorization_T *localDW)
{
  localDW->CurvaturaActuador5_MODE = false;
}

/*
 * Start for enable system:
 *    '<S27>/Curvatura Actuador 5'
 *    '<S27>/Curvatura Actuador 4'
 *    '<S27>/Curvatura Actuador 3'
 *    '<S27>/Curvatura Actuador 2'
 *    '<S27>/Curvatura Actuador 1'
 */
void ControlSystem_Refactorization_CurvaturaActuador5_Start
  (B_CurvaturaActuador5_ControlSystem_Refactorization_T *localB,
   DW_CurvaturaActuador5_ControlSystem_Refactorization_T *localDW,
   XDis_CurvaturaActuador5_ControlSystem_Refactorization_T *localXdis)
{
  /* SystemInitialize for TransferFcn: '<S40>/Modelo de curvatura del actuador' */
  localB->CurvAct = 0.0;
  localDW->CurvaturaActuador5_MODE = false;
  (void) memset(&(localXdis->Modelodecurvaturadelactuador_CSTATE), 1,
                5*sizeof(boolean_T));
}

/*
 * Outputs for enable system:
 *    '<S27>/Curvatura Actuador 5'
 *    '<S27>/Curvatura Actuador 4'
 *    '<S27>/Curvatura Actuador 3'
 *    '<S27>/Curvatura Actuador 2'
 *    '<S27>/Curvatura Actuador 1'
 */
void ControlSystem_Refactorization_CurvaturaActuador5
  (RT_MODEL_ControlSystem_Refactorization_T * const
   ControlSystem_Refactorization_M, boolean_T rtu_Enable,
   B_CurvaturaActuador5_ControlSystem_Refactorization_T *localB,
   DW_CurvaturaActuador5_ControlSystem_Refactorization_T *localDW,
   P_CurvaturaActuador5_ControlSystem_Refactorization_T *localP,
   X_CurvaturaActuador5_ControlSystem_Refactorization_T *localX,
   XDis_CurvaturaActuador5_ControlSystem_Refactorization_T *localXdis)
{
  int_T ci;

  /* Outputs for Enabled SubSystem: '<S27>/Curvatura Actuador 5' incorporates:
   *  EnablePort: '<S40>/Enable'
   */
  if (rtmIsMajorTimeStep(ControlSystem_Refactorization_M) &&
      rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo)) {
    if (rtu_Enable) {
      if (!localDW->CurvaturaActuador5_MODE) {
        (void) memset(&(localXdis->Modelodecurvaturadelactuador_CSTATE), 0,
                      5*sizeof(boolean_T));
        localDW->CurvaturaActuador5_MODE = true;
      }
    } else {
      /* Outputs for Enabled SubSystem: '<S7>/Control de Curvatura' incorporates:
       *  EnablePort: '<S44>/Enable'
       */
      if (ControlSystem_Refactorization_M->Timing.t[1] == rtmGetTStart
          (ControlSystem_Refactorization_M)) {
        (void) memset(&(localXdis->Modelodecurvaturadelactuador_CSTATE), 1,
                      5*sizeof(boolean_T));
      }

      /* End of Outputs for SubSystem: '<S7>/Control de Curvatura' */
      if (localDW->CurvaturaActuador5_MODE) {
        (void) memset(&(localXdis->Modelodecurvaturadelactuador_CSTATE), 1,
                      5*sizeof(boolean_T));
        ControlSystem_Refactorization_CurvaturaActuador5_Disable(localDW);
      }
    }
  }

  if (localDW->CurvaturaActuador5_MODE) {
    /* TransferFcn: '<S40>/Modelo de curvatura del actuador' */
    localB->CurvAct = 0.0;

    /* TransferFcn: '<S40>/Modelo de curvatura del actuador' */
    for (ci = 0; ci < 5; ci++) {
      /* TransferFcn: '<S40>/Modelo de curvatura del actuador' */
      localB->CurvAct += localP->Modelodecurvaturadelactuador_C[ci] *
        localX->Modelodecurvaturadelactuador_CSTATE[ci];
    }

    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      srUpdateBC(localDW->CurvaturaActuador5_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S27>/Curvatura Actuador 5' */
}

/*
 * Derivatives for enable system:
 *    '<S27>/Curvatura Actuador 5'
 *    '<S27>/Curvatura Actuador 4'
 *    '<S27>/Curvatura Actuador 3'
 *    '<S27>/Curvatura Actuador 2'
 *    '<S27>/Curvatura Actuador 1'
 */
void ControlSystem_Refactorization_CurvaturaActuador5_Deriv(real_T
  rtu_PresinEntrada, DW_CurvaturaActuador5_ControlSystem_Refactorization_T
  *localDW, P_CurvaturaActuador5_ControlSystem_Refactorization_T *localP,
  X_CurvaturaActuador5_ControlSystem_Refactorization_T *localX,
  XDot_CurvaturaActuador5_ControlSystem_Refactorization_T *localXdot)
{
  __m128d tmp;
  int_T is;
  if (localDW->CurvaturaActuador5_MODE) {
    /* Derivatives for TransferFcn: '<S40>/Modelo de curvatura del actuador' */
    for (is = 0; is < 5; is++) {
      localXdot->Modelodecurvaturadelactuador_CSTATE[is] = 0.0;
      localXdot->Modelodecurvaturadelactuador_CSTATE[0] +=
        localP->Modelodecurvaturadelactuador_A[is] *
        localX->Modelodecurvaturadelactuador_CSTATE[is];
    }

    tmp = _mm_add_pd(_mm_loadu_pd(&localX->Modelodecurvaturadelactuador_CSTATE[0]),
                     _mm_loadu_pd
                     (&localXdot->Modelodecurvaturadelactuador_CSTATE[1]));
    _mm_storeu_pd(&localXdot->Modelodecurvaturadelactuador_CSTATE[1], tmp);
    tmp = _mm_add_pd(_mm_loadu_pd(&localX->Modelodecurvaturadelactuador_CSTATE[2]),
                     _mm_loadu_pd
                     (&localXdot->Modelodecurvaturadelactuador_CSTATE[3]));
    _mm_storeu_pd(&localXdot->Modelodecurvaturadelactuador_CSTATE[3], tmp);
    localXdot->Modelodecurvaturadelactuador_CSTATE[0] += rtu_PresinEntrada;

    /* End of Derivatives for TransferFcn: '<S40>/Modelo de curvatura del actuador' */
  } else {
    {
      real_T *dx;
      int_T i1;
      dx = &(localXdot->Modelodecurvaturadelactuador_CSTATE[0]);
      for (i1=0; i1 < 5; i1++) {
        dx[i1] = 0.0;
      }
    }
  }
}

static boolean_T ControlSystem_Refactorization_isMember(const
  ActuadorPosicionado s[4])
{
  int32_T b_k;
  boolean_T exitg1;
  boolean_T tf;
  tf = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k < 4)) {
    if (s[b_k] == ActuadorPosicionado_Desposicionado) {
      tf = true;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  return tf;
}

static boolean_T ControlSystem_Refactorization_isMember_d(const boolean_T
  s_data[], const int32_T *s_size)
{
  int32_T b_k;
  boolean_T exitg1;
  boolean_T tf;
  tf = false;
  b_k = 0;
  exitg1 = false;
  while ((!exitg1) && (b_k <= *s_size - 1)) {
    if (!s_data[b_k]) {
      tf = true;
      exitg1 = true;
    } else {
      b_k++;
    }
  }

  return tf;
}

static void
  ControlSystem_Refactorization_sequential_autonomousControlLogic_controlSignals
  (const slBusActuador actuadorBus[4], real_T regulador_Estado_presion, real_T
   actuadorSeleccionado, Controlador controlador, real_T *referencia_presion,
   real_T *referencia_curvatura, real_T *realimentacion_presion, real_T
   *realimentacion_curvatura)
{
  real_T b_curvatura[4];
  real_T b_presion[4];
  real_T referencias_curvatura[4];
  real_T referencias_presion[4];

  /* Start for MATLABSystem: '<S6>/MATLAB System1' */
  /*  Inicialización de variables */
  referencias_presion[0] = actuadorBus[0].
    Configuracion.Global.Referencia.presion;
  referencias_curvatura[0] = actuadorBus[0].
    Configuracion.Global.Referencia.curvatura;
  b_presion[0] = actuadorBus[0].Estado.Realimentacion.presion;
  b_curvatura[0] = actuadorBus[0].Estado.Realimentacion.curvatura;
  referencias_presion[1] = actuadorBus[1].
    Configuracion.Global.Referencia.presion;
  referencias_curvatura[1] = actuadorBus[1].
    Configuracion.Global.Referencia.curvatura;
  b_presion[1] = actuadorBus[1].Estado.Realimentacion.presion;
  b_curvatura[1] = actuadorBus[1].Estado.Realimentacion.curvatura;
  referencias_presion[2] = actuadorBus[2].
    Configuracion.Global.Referencia.presion;
  referencias_curvatura[2] = actuadorBus[2].
    Configuracion.Global.Referencia.curvatura;
  b_presion[2] = actuadorBus[2].Estado.Realimentacion.presion;
  b_curvatura[2] = actuadorBus[2].Estado.Realimentacion.curvatura;
  referencias_presion[3] = actuadorBus[3].
    Configuracion.Global.Referencia.presion;
  referencias_curvatura[3] = actuadorBus[3].
    Configuracion.Global.Referencia.curvatura;
  b_presion[3] = actuadorBus[3].Estado.Realimentacion.presion;
  b_curvatura[3] = actuadorBus[3].Estado.Realimentacion.curvatura;

  /*  Selecciona las señales de control para realimentación y */
  /*  referencia, según el estado del sistema */
  /*  1. No hay actuadores seleccionados */
  if (actuadorSeleccionado == 0.0) {
    /* Start for MATLABSystem: '<S6>/MATLAB System1' */
    *realimentacion_presion = regulador_Estado_presion;
    *realimentacion_curvatura = 0.0;

    /* Start for MATLABSystem: '<S6>/MATLAB System1' */
    *referencia_presion = regulador_Estado_presion;
    *referencia_curvatura = 0.0;

    /*  2. Equilibrio de presiones */
  } else if (controlador == Controlador_EquilibrioPresiones) {
    /* Start for MATLABSystem: '<S6>/MATLAB System1' */
    *realimentacion_presion = regulador_Estado_presion;
    *realimentacion_curvatura = b_curvatura[(int32_T)actuadorSeleccionado - 1];
    *referencia_presion = b_presion[(int32_T)actuadorSeleccionado - 1];
    *referencia_curvatura = referencias_curvatura[(int32_T)actuadorSeleccionado
      - 1];
  } else {
    /* Start for MATLABSystem: '<S6>/MATLAB System1' */
    /*  3. Control del actuador */
    *realimentacion_presion = b_presion[(int32_T)actuadorSeleccionado - 1];
    *realimentacion_curvatura = b_curvatura[(int32_T)actuadorSeleccionado - 1];
    *referencia_presion = referencias_presion[(int32_T)actuadorSeleccionado - 1];
    *referencia_curvatura = referencias_curvatura[(int32_T)actuadorSeleccionado
      - 1];
  }
}

static void
  ControlSystem_Refactorization_sequential_autonomousControlLogic_stepImpl
  (sequential_autonomousControlLogic_ControlSystem_Refactorization_T *obj,
   ModoControl sistema_Configuracion_Global_modoControl, ParametroControl
   sistema_Configuracion_Global_parametroControl, Controlador
   sistema_Configuracion_Global_controlador, real_T
   sistema_Configuracion_Global_toleranciaEquilibrioPresiones, real_T
   sistema_Configuracion_Global_ToleranciaPresion_estacionaria, real_T
   sistema_Configuracion_Global_ToleranciaPresion_derivativa, real_T
   sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria, real_T
   sistema_Configuracion_Global_ToleranciaCurvatura_derivativa, real_T
   sistema_Estado_Global_errorEstacionario_presion, real_T
   sistema_Estado_Global_errorEstacionario_curvatura, real_T
   sistema_Estado_Global_errorDerivativo_presion, real_T
   sistema_Estado_Global_errorDerivativo_curvatura, const slBusActuador
   actuadorBus[4], real_T regulador_Estado_presion, Controlador *controlador,
   ActuadorPosicionado actuadoresPosicionados[4], boolean_T
   valvulasCerradas_controlAutonomo[4], real_T *realimentacion_presion, real_T
   *realimentacion_curvatura, real_T *referencia_presion, real_T
   *referencia_curvatura)
{
  real_T f_presion[4];
  real_T actError;
  real_T actuadorSeleccionado;
  real_T maxError;
  int32_T i;
  int32_T tmp_size_idx_1;
  int32_T trueCount;
  int8_T tmp_data[4];
  boolean_T actuadoresActivos[4];
  boolean_T actuadoresActivos_data[4];
  boolean_T actuadorControlPosicionado;

  /*  Implement algorithm. Calculate y as a function of input u and */
  /*  internal states. */
  /*  Inicializar variables generales */
  /*  Inicializar salidas */
  /*  1. Controlador activo */
  *controlador = sistema_Configuracion_Global_controlador;

  /* Start for MATLABSystem: '<S6>/MATLAB System1' */
  /*  2. Actuadores posicionados */
  /*  3. Realimentación y referencias por defecto */
  *realimentacion_presion = regulador_Estado_presion;
  *realimentacion_curvatura = 0.0;
  *referencia_presion = 0.0;
  *referencia_curvatura = 0.0;

  /*  5. Estado electroválvulas (control autónomo) */
  actuadoresPosicionados[0] = ActuadorPosicionado_Desposicionado;

  /* Start for MATLABSystem: '<S6>/MATLAB System1' */
  valvulasCerradas_controlAutonomo[0] = actuadorBus[0].
    Estado.ControlAutomatico.valvulaCerrada;
  actuadoresPosicionados[1] = ActuadorPosicionado_Desposicionado;

  /* Start for MATLABSystem: '<S6>/MATLAB System1' */
  valvulasCerradas_controlAutonomo[1] = actuadorBus[1].
    Estado.ControlAutomatico.valvulaCerrada;
  actuadoresPosicionados[2] = ActuadorPosicionado_Desposicionado;

  /* Start for MATLABSystem: '<S6>/MATLAB System1' */
  valvulasCerradas_controlAutonomo[2] = actuadorBus[2].
    Estado.ControlAutomatico.valvulaCerrada;
  actuadoresPosicionados[3] = ActuadorPosicionado_Desposicionado;

  /* Start for MATLABSystem: '<S6>/MATLAB System1' */
  valvulasCerradas_controlAutonomo[3] = actuadorBus[3].
    Estado.ControlAutomatico.valvulaCerrada;

  /*  Finalizar lógica de control si está deshabilitada */
  if (sistema_Configuracion_Global_modoControl !=
      ModoControl_Autonomo_Secuencial) {
    obj->controlHabilitado = false;
  } else {
    /*  Lógica aplicada a cada parámetro de control */
    if (sistema_Configuracion_Global_parametroControl ==
        ParametroControl_Presion) {
      /*  Control de presión */
      /*  1. Actualiza y reinicia las variables de control cuando se produce */
      /*  algún cambio en la lógica de control */
      if ((!obj->controlHabilitado) || (obj->parametroControl !=
           ParametroControl_Presion)) {
        obj->controlHabilitado = true;
        obj->parametroControl = ParametroControl_Presion;
      }

      /*  2. Se comprueba el posicionamiento actual de los actuadores */
      /*  Inicialización de variables */
      /*  1. Información sobre actuadores */
      actuadorSeleccionado = obj->actuadorSeleccionado;

      /*  2. Estado de todos los actuadores */
      /*  3. Estado del actuador de control */
      /*  Comprueba si los errores del actuador actualmente seleccionado para el control cumplen o no las tolerancias permitidas */
      /*  1. Tolerancias de error */
      /*  2. Estado del actuador de control */
      /*  3. Comprobación de errores */
      actuadorControlPosicionado = true;
      if ((fabs(sistema_Estado_Global_errorEstacionario_presion) >
           sistema_Configuracion_Global_ToleranciaPresion_estacionaria) || (fabs
           (sistema_Estado_Global_errorDerivativo_presion) >
           sistema_Configuracion_Global_ToleranciaPresion_derivativa)) {
        actuadorControlPosicionado = false;
      }

      /*  4. Tolerancias de error */
      /*  Comprueba si los actuadores se encuentran posicionados o desposicionados */
      /*  3. Se selecciona el actuador utilizado como referencia para el control */
      /*  Selecciona el actuador a utilizar como referencia de control */
      /*  Inicialización de variables */
      /*  1. Información de los actuadores */
      /*  2. Referencias y realimentación de los actuadores */
      /*  1. Actuador desactivado */
      if (!actuadorBus[0].Configuracion.Global.activo) {
        actuadoresPosicionados[0] = ActuadorPosicionado_Control_Manual;

        /*  2. Actuador seleccionado como referencia para control */
      } else if ((obj->actuadorSeleccionado == 1.0) &&
                 actuadorControlPosicionado) {
        actuadoresPosicionados[0] = ActuadorPosicionado_Posicionado;
        obj->actuadorSeleccionado = 0.0;
      } else if (!(obj->actuadorSeleccionado == 1.0)) {
        /*  3. Actuador previamente posicionado */
        maxError = fabs(actuadorBus[0].Configuracion.Global.Referencia.presion -
                        actuadorBus[0].Estado.Realimentacion.presion);
        if (maxError >
            sistema_Configuracion_Global_ToleranciaPresion_estacionaria) {
          actuadoresPosicionados[0] = ActuadorPosicionado_Desposicionado;

          /*  4. Actuador previamente desposicionado */
        } else if (maxError <=
                   sistema_Configuracion_Global_ToleranciaPresion_estacionaria)
        {
          actuadoresPosicionados[0] = ActuadorPosicionado_Posicionado;
        }
      }

      /*  1. Actuador desactivado */
      if (!actuadorBus[1].Configuracion.Global.activo) {
        actuadoresPosicionados[1] = ActuadorPosicionado_Control_Manual;

        /*  2. Actuador seleccionado como referencia para control */
      } else if ((actuadorSeleccionado == 2.0) && actuadorControlPosicionado) {
        actuadoresPosicionados[1] = ActuadorPosicionado_Posicionado;
        obj->actuadorSeleccionado = 0.0;
      } else if (!(actuadorSeleccionado == 2.0)) {
        /*  3. Actuador previamente posicionado */
        maxError = fabs(actuadorBus[1].Configuracion.Global.Referencia.presion -
                        actuadorBus[1].Estado.Realimentacion.presion);
        if (maxError >
            sistema_Configuracion_Global_ToleranciaPresion_estacionaria) {
          actuadoresPosicionados[1] = ActuadorPosicionado_Desposicionado;

          /*  4. Actuador previamente desposicionado */
        } else if (maxError <=
                   sistema_Configuracion_Global_ToleranciaPresion_estacionaria)
        {
          actuadoresPosicionados[1] = ActuadorPosicionado_Posicionado;
        }
      }

      /*  1. Actuador desactivado */
      if (!actuadorBus[2].Configuracion.Global.activo) {
        actuadoresPosicionados[2] = ActuadorPosicionado_Control_Manual;

        /*  2. Actuador seleccionado como referencia para control */
      } else if ((actuadorSeleccionado == 3.0) && actuadorControlPosicionado) {
        actuadoresPosicionados[2] = ActuadorPosicionado_Posicionado;
        obj->actuadorSeleccionado = 0.0;
      } else if (!(actuadorSeleccionado == 3.0)) {
        /*  3. Actuador previamente posicionado */
        maxError = fabs(actuadorBus[2].Configuracion.Global.Referencia.presion -
                        actuadorBus[2].Estado.Realimentacion.presion);
        if (maxError >
            sistema_Configuracion_Global_ToleranciaPresion_estacionaria) {
          actuadoresPosicionados[2] = ActuadorPosicionado_Desposicionado;

          /*  4. Actuador previamente desposicionado */
        } else if (maxError <=
                   sistema_Configuracion_Global_ToleranciaPresion_estacionaria)
        {
          actuadoresPosicionados[2] = ActuadorPosicionado_Posicionado;
        }
      }

      /*  1. Actuador desactivado */
      if (!actuadorBus[3].Configuracion.Global.activo) {
        actuadoresPosicionados[3] = ActuadorPosicionado_Control_Manual;

        /*  2. Actuador seleccionado como referencia para control */
      } else if ((actuadorSeleccionado == 4.0) && actuadorControlPosicionado) {
        actuadoresPosicionados[3] = ActuadorPosicionado_Posicionado;
        obj->actuadorSeleccionado = 0.0;
      } else if (!(actuadorSeleccionado == 4.0)) {
        /*  3. Actuador previamente posicionado */
        maxError = fabs(actuadorBus[3].Configuracion.Global.Referencia.presion -
                        actuadorBus[3].Estado.Realimentacion.presion);
        if (maxError >
            sistema_Configuracion_Global_ToleranciaPresion_estacionaria) {
          actuadoresPosicionados[3] = ActuadorPosicionado_Desposicionado;

          /*  4. Actuador previamente desposicionado */
        } else if (maxError <=
                   sistema_Configuracion_Global_ToleranciaPresion_estacionaria)
        {
          actuadoresPosicionados[3] = ActuadorPosicionado_Posicionado;
        }
      }

      actuadorSeleccionado = obj->actuadorSeleccionado;

      /*  Lógica de selección */
      /*  1. Si ya hay un actuador en control, se mantiene como */
      /*  referencia hasta que haya sido posicionado */
      if ((obj->actuadorSeleccionado != 0.0) && (actuadoresPosicionados[(int32_T)
           obj->actuadorSeleccionado - 1] != ActuadorPosicionado_Posicionado)) {
        /*  2. Si todos los actuadores ya están posicionados, no se selecciona */
        /*  ninguno */
      } else if (!ControlSystem_Refactorization_isMember(actuadoresPosicionados))
      {
        actuadorSeleccionado = 0.0;
      } else {
        /*  3. Se selecciona el actuador activo con mayor error estacionario */
        maxError = 0.0;
        actError = fabs(actuadorBus[0].Configuracion.Global.Referencia.presion -
                        actuadorBus[0].Estado.Realimentacion.presion);
        if ((actError > 0.0) && (actuadoresPosicionados[0] !=
             ActuadorPosicionado_Control_Manual)) {
          maxError = actError;
          actuadorSeleccionado = 1.0;
        }

        actError = fabs(actuadorBus[1].Configuracion.Global.Referencia.presion -
                        actuadorBus[1].Estado.Realimentacion.presion);
        if ((actError > maxError) && (actuadoresPosicionados[1] !=
             ActuadorPosicionado_Control_Manual)) {
          maxError = actError;
          actuadorSeleccionado = 2.0;
        }

        actError = fabs(actuadorBus[2].Configuracion.Global.Referencia.presion -
                        actuadorBus[2].Estado.Realimentacion.presion);
        if ((actError > maxError) && (actuadoresPosicionados[2] !=
             ActuadorPosicionado_Control_Manual)) {
          maxError = actError;
          actuadorSeleccionado = 3.0;
        }

        if ((fabs(actuadorBus[3].Configuracion.Global.Referencia.presion -
                  actuadorBus[3].Estado.Realimentacion.presion) > maxError) &&
            (actuadoresPosicionados[3] != ActuadorPosicionado_Control_Manual)) {
          actuadorSeleccionado = 4.0;
        }
      }

      /*  4. Se establecen los estados de las electroválvulas */
      /*  Inicialización de variables */
      /*  Inicializar controlador */
      *controlador = Controlador_Presion;

      /*  Determina el estado en el que deben encontrarse las */
      /*  electroválvulas para el control del actuador */
      actuadoresActivos[0] = actuadorBus[0].
        Estado.ControlAutomatico.valvulaCerrada;
      f_presion[0] = actuadorBus[0].Estado.Realimentacion.presion;
      valvulasCerradas_controlAutonomo[0] = true;
      actuadoresActivos[1] = actuadorBus[1].
        Estado.ControlAutomatico.valvulaCerrada;
      f_presion[1] = actuadorBus[1].Estado.Realimentacion.presion;
      valvulasCerradas_controlAutonomo[1] = true;
      actuadoresActivos[2] = actuadorBus[2].
        Estado.ControlAutomatico.valvulaCerrada;
      f_presion[2] = actuadorBus[2].Estado.Realimentacion.presion;
      valvulasCerradas_controlAutonomo[2] = true;
      actuadoresActivos[3] = actuadorBus[3].
        Estado.ControlAutomatico.valvulaCerrada;
      f_presion[3] = actuadorBus[3].Estado.Realimentacion.presion;
      valvulasCerradas_controlAutonomo[3] = true;
      if (actuadorSeleccionado != 0.0) {
        valvulasCerradas_controlAutonomo[(int32_T)actuadorSeleccionado - 1] =
          false;
      }

      /*  1. Si hay actuadores distintos al seleccionado */
      /*  inyectando aire, o no hay actuadores seleccionados, */
      /*  se cierran todas las válvulas en esta etapa de ejecución */
      trueCount = 0;
      for (i = 0; i < 4; i++) {
        if ((real_T)i + 1.0 != actuadorSeleccionado) {
          trueCount++;
        }
      }

      tmp_size_idx_1 = trueCount;
      trueCount = 0;
      for (i = 0; i < 4; i++) {
        if ((real_T)i + 1.0 != actuadorSeleccionado) {
          tmp_data[trueCount] = (int8_T)i;
          trueCount++;
        }
      }

      for (i = 0; i < tmp_size_idx_1; i++) {
        actuadoresActivos_data[i] = actuadoresActivos[tmp_data[i]];
      }

      if (ControlSystem_Refactorization_isMember_d(actuadoresActivos_data,
           &tmp_size_idx_1) || (actuadorSeleccionado == 0.0)) {
        valvulasCerradas_controlAutonomo[0] = true;
        valvulasCerradas_controlAutonomo[1] = true;
        valvulasCerradas_controlAutonomo[2] = true;
        valvulasCerradas_controlAutonomo[3] = true;

        /*  2. Si todas las válvulas están cerradas, y la presión del */
        /*  regulador es distinta a la del actuador seleccionado, se */
        /*  continúa el proceso de equilibrio de presiones. */
        /*  La presión del regulador siempre se registra con un valor */
        /*  positivo, así que es necesario trabajar con la realimentación */
        /*  en valor absoluto para calcular correctamente el error. */
      } else if (actuadoresActivos[(int32_T)actuadorSeleccionado - 1] && (fabs
                  (fabs(f_presion[(int32_T)actuadorSeleccionado - 1]) -
                   regulador_Estado_presion) >
                  sistema_Configuracion_Global_toleranciaEquilibrioPresiones)) {
        valvulasCerradas_controlAutonomo[0] = true;
        valvulasCerradas_controlAutonomo[1] = true;
        valvulasCerradas_controlAutonomo[2] = true;
        valvulasCerradas_controlAutonomo[3] = true;
        *controlador = Controlador_EquilibrioPresiones;
      } else {
        /*  3. En otro caso, se continúa con el control del actuador */
      }

      /*  5. Se definen las señales de control */
      ControlSystem_Refactorization_sequential_autonomousControlLogic_controlSignals
        (actuadorBus, regulador_Estado_presion, actuadorSeleccionado,
         *controlador, referencia_presion, referencia_curvatura,
         realimentacion_presion, realimentacion_curvatura);

      /*  Control de curvatura */
    } else {
      /*  1. Actualiza y reinicia las variables de control cuando se produce */
      /*  algún cambio en la lógica de control */
      if ((!obj->controlHabilitado) || (obj->parametroControl !=
           ParametroControl_Curvatura)) {
        obj->controlHabilitado = true;
        obj->parametroControl = ParametroControl_Curvatura;
        obj->actuadorSeleccionado = 0.0;
      }

      /*  2. Se comprueba el posicionamiento actual de los actuadores */
      /*  Inicialización de variables */
      /*  1. Información sobre actuadores */
      actuadorSeleccionado = obj->actuadorSeleccionado;

      /*  2. Estado de todos los actuadores */
      /*  3. Estado del actuador de control */
      /*  Comprueba si los errores del actuador actualmente seleccionado para el control cumplen o no las tolerancias permitidas */
      /*  1. Tolerancias de error */
      /*  2. Estado del actuador de control */
      /*  3. Controlador activo */
      /*  4. Comprobación de errores */
      actuadorControlPosicionado = true;

      /*  Controlador: equilibrio de presiones */
      if (sistema_Configuracion_Global_controlador ==
          Controlador_EquilibrioPresiones) {
        if ((fabs(sistema_Estado_Global_errorEstacionario_presion) >
             sistema_Configuracion_Global_ToleranciaPresion_estacionaria) ||
            (fabs(sistema_Estado_Global_errorDerivativo_presion) >
             sistema_Configuracion_Global_ToleranciaPresion_derivativa)) {
          actuadorControlPosicionado = false;
        } else {
          /*  Controlador: curvatura */
        }
      } else if ((fabs(sistema_Estado_Global_errorEstacionario_curvatura) >
                  sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria)
                 || (fabs(sistema_Estado_Global_errorDerivativo_curvatura) >
                     sistema_Configuracion_Global_ToleranciaCurvatura_derivativa))
      {
        actuadorControlPosicionado = false;
      }

      /*  4. Tolerancias de error */
      /*  Comprueba si los actuadores se encuentran posicionados o desposicionados */
      /*  3. Se selecciona el actuador utilizado como referencia para el control */
      /*  Selecciona el actuador a utilizar como referencia de control */
      /*  Inicialización de variables */
      /*  1. Información de los actuadores */
      /*  2. Estado de todos los actuadores */
      /*  1. Actuador desactivado */
      if (!actuadorBus[0].Configuracion.Global.activo) {
        actuadoresPosicionados[0] = ActuadorPosicionado_Control_Manual;

        /*  2. Actuador seleccionado como referencia para control */
      } else if ((obj->actuadorSeleccionado == 1.0) &&
                 actuadorControlPosicionado) {
        actuadoresPosicionados[0] = ActuadorPosicionado_Posicionado;
        obj->actuadorSeleccionado = 0.0;
      } else if (!(obj->actuadorSeleccionado == 1.0)) {
        /*  3. Actuador previamente posicionado */
        maxError = fabs(actuadorBus[0].Configuracion.Global.Referencia.curvatura
                        - actuadorBus[0].Estado.Realimentacion.curvatura);
        if (maxError >
            sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria) {
          actuadoresPosicionados[0] = ActuadorPosicionado_Desposicionado;

          /*  4. Actuador previamente desposicionado */
        } else if (maxError <=
                   sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria)
        {
          actuadoresPosicionados[0] = ActuadorPosicionado_Posicionado;
        }
      }

      /*  1. Actuador desactivado */
      if (!actuadorBus[1].Configuracion.Global.activo) {
        actuadoresPosicionados[1] = ActuadorPosicionado_Control_Manual;

        /*  2. Actuador seleccionado como referencia para control */
      } else if ((actuadorSeleccionado == 2.0) && actuadorControlPosicionado) {
        actuadoresPosicionados[1] = ActuadorPosicionado_Posicionado;
        obj->actuadorSeleccionado = 0.0;
      } else if (!(actuadorSeleccionado == 2.0)) {
        /*  3. Actuador previamente posicionado */
        maxError = fabs(actuadorBus[1].Configuracion.Global.Referencia.curvatura
                        - actuadorBus[1].Estado.Realimentacion.curvatura);
        if (maxError >
            sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria) {
          actuadoresPosicionados[1] = ActuadorPosicionado_Desposicionado;

          /*  4. Actuador previamente desposicionado */
        } else if (maxError <=
                   sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria)
        {
          actuadoresPosicionados[1] = ActuadorPosicionado_Posicionado;
        }
      }

      /*  1. Actuador desactivado */
      if (!actuadorBus[2].Configuracion.Global.activo) {
        actuadoresPosicionados[2] = ActuadorPosicionado_Control_Manual;

        /*  2. Actuador seleccionado como referencia para control */
      } else if ((actuadorSeleccionado == 3.0) && actuadorControlPosicionado) {
        actuadoresPosicionados[2] = ActuadorPosicionado_Posicionado;
        obj->actuadorSeleccionado = 0.0;
      } else if (!(actuadorSeleccionado == 3.0)) {
        /*  3. Actuador previamente posicionado */
        maxError = fabs(actuadorBus[2].Configuracion.Global.Referencia.curvatura
                        - actuadorBus[2].Estado.Realimentacion.curvatura);
        if (maxError >
            sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria) {
          actuadoresPosicionados[2] = ActuadorPosicionado_Desposicionado;

          /*  4. Actuador previamente desposicionado */
        } else if (maxError <=
                   sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria)
        {
          actuadoresPosicionados[2] = ActuadorPosicionado_Posicionado;
        }
      }

      /*  1. Actuador desactivado */
      if (!actuadorBus[3].Configuracion.Global.activo) {
        actuadoresPosicionados[3] = ActuadorPosicionado_Control_Manual;

        /*  2. Actuador seleccionado como referencia para control */
      } else if ((actuadorSeleccionado == 4.0) && actuadorControlPosicionado) {
        actuadoresPosicionados[3] = ActuadorPosicionado_Posicionado;
        obj->actuadorSeleccionado = 0.0;
      } else if (!(actuadorSeleccionado == 4.0)) {
        /*  3. Actuador previamente posicionado */
        maxError = fabs(actuadorBus[3].Configuracion.Global.Referencia.curvatura
                        - actuadorBus[3].Estado.Realimentacion.curvatura);
        if (maxError >
            sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria) {
          actuadoresPosicionados[3] = ActuadorPosicionado_Desposicionado;

          /*  4. Actuador previamente desposicionado */
        } else if (maxError <=
                   sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria)
        {
          actuadoresPosicionados[3] = ActuadorPosicionado_Posicionado;
        }
      }

      actuadorSeleccionado = obj->actuadorSeleccionado;

      /*  Lógica de selección */
      /*  1. Si ya hay un actuador en control, se mantiene como */
      /*  referencia hasta que haya sido posicionado */
      if ((obj->actuadorSeleccionado != 0.0) && (actuadoresPosicionados[(int32_T)
           obj->actuadorSeleccionado - 1] != ActuadorPosicionado_Posicionado)) {
        /*  2. Si todos los actuadores ya están posicionados, no se selecciona */
        /*  ninguno */
      } else if (!ControlSystem_Refactorization_isMember(actuadoresPosicionados))
      {
        actuadorSeleccionado = 0.0;
      } else {
        /*  3. Se selecciona el actuador activo con mayor error estacionario */
        maxError = 0.0;
        actError = fabs(actuadorBus[0].Configuracion.Global.Referencia.curvatura
                        - actuadorBus[0].Estado.Realimentacion.curvatura);
        if ((actError > 0.0) && (actuadoresPosicionados[0] !=
             ActuadorPosicionado_Control_Manual)) {
          maxError = actError;
          actuadorSeleccionado = 1.0;
        }

        actError = fabs(actuadorBus[1].Configuracion.Global.Referencia.curvatura
                        - actuadorBus[1].Estado.Realimentacion.curvatura);
        if ((actError > maxError) && (actuadoresPosicionados[1] !=
             ActuadorPosicionado_Control_Manual)) {
          maxError = actError;
          actuadorSeleccionado = 2.0;
        }

        actError = fabs(actuadorBus[2].Configuracion.Global.Referencia.curvatura
                        - actuadorBus[2].Estado.Realimentacion.curvatura);
        if ((actError > maxError) && (actuadoresPosicionados[2] !=
             ActuadorPosicionado_Control_Manual)) {
          maxError = actError;
          actuadorSeleccionado = 3.0;
        }

        if ((fabs(actuadorBus[3].Configuracion.Global.Referencia.curvatura -
                  actuadorBus[3].Estado.Realimentacion.curvatura) > maxError) &&
            (actuadoresPosicionados[3] != ActuadorPosicionado_Control_Manual)) {
          actuadorSeleccionado = 4.0;
        }
      }

      /*  4. Se establecen los estados de las electroválvulas */
      /*  Inicialización de variables */
      /*  Inicializar controlador */
      *controlador = Controlador_Curvatura;

      /*  Determina el estado en el que deben encontrarse las */
      /*  electroválvulas para el control del actuador */
      actuadoresActivos[0] = actuadorBus[0].
        Estado.ControlAutomatico.valvulaCerrada;
      f_presion[0] = actuadorBus[0].Estado.Realimentacion.presion;
      valvulasCerradas_controlAutonomo[0] = true;
      actuadoresActivos[1] = actuadorBus[1].
        Estado.ControlAutomatico.valvulaCerrada;
      f_presion[1] = actuadorBus[1].Estado.Realimentacion.presion;
      valvulasCerradas_controlAutonomo[1] = true;
      actuadoresActivos[2] = actuadorBus[2].
        Estado.ControlAutomatico.valvulaCerrada;
      f_presion[2] = actuadorBus[2].Estado.Realimentacion.presion;
      valvulasCerradas_controlAutonomo[2] = true;
      actuadoresActivos[3] = actuadorBus[3].
        Estado.ControlAutomatico.valvulaCerrada;
      f_presion[3] = actuadorBus[3].Estado.Realimentacion.presion;
      valvulasCerradas_controlAutonomo[3] = true;
      if (actuadorSeleccionado != 0.0) {
        valvulasCerradas_controlAutonomo[(int32_T)actuadorSeleccionado - 1] =
          false;
      }

      /*  1. Si hay actuadores distintos al seleccionado */
      /*  inyectando aire, o no hay actuadores seleccionados, */
      /*  se cierran/liberan todas las válvulas en esta etapa de ejecución */
      trueCount = 0;
      for (i = 0; i < 4; i++) {
        if ((real_T)i + 1.0 != actuadorSeleccionado) {
          trueCount++;
        }
      }

      tmp_size_idx_1 = trueCount;
      trueCount = 0;
      for (i = 0; i < 4; i++) {
        if ((real_T)i + 1.0 != actuadorSeleccionado) {
          tmp_data[trueCount] = (int8_T)i;
          trueCount++;
        }
      }

      for (i = 0; i < tmp_size_idx_1; i++) {
        actuadoresActivos_data[i] = actuadoresActivos[tmp_data[i]];
      }

      if (ControlSystem_Refactorization_isMember_d(actuadoresActivos_data,
           &tmp_size_idx_1) || (actuadorSeleccionado == 0.0)) {
        valvulasCerradas_controlAutonomo[0] = true;
        valvulasCerradas_controlAutonomo[1] = true;
        valvulasCerradas_controlAutonomo[2] = true;
        valvulasCerradas_controlAutonomo[3] = true;

        /*  2. Si todas las válvulas están cerradas, y la presión del */
        /*  regulador es distinta a la del actuador seleccionado, se */
        /*  continúa el proceso de equilibrio de presiones. */
        /*  La presión del regulador siempre se registra con un valor */
        /*  positivo, así que es necesario trabajar con la realimentación */
        /*  en valor absoluto para calcular correctamente el error. */
      } else if (actuadoresActivos[(int32_T)actuadorSeleccionado - 1] && (fabs
                  (fabs(f_presion[(int32_T)actuadorSeleccionado - 1]) -
                   regulador_Estado_presion) >
                  sistema_Configuracion_Global_toleranciaEquilibrioPresiones)) {
        valvulasCerradas_controlAutonomo[0] = true;
        valvulasCerradas_controlAutonomo[1] = true;
        valvulasCerradas_controlAutonomo[2] = true;
        valvulasCerradas_controlAutonomo[3] = true;
        *controlador = Controlador_EquilibrioPresiones;
      } else {
        /*  3. En otro caso, se continúa con el control del actuador */
      }

      /*  5. Se definen las señales de control */
      ControlSystem_Refactorization_sequential_autonomousControlLogic_controlSignals
        (actuadorBus, regulador_Estado_presion, actuadorSeleccionado,
         *controlador, referencia_presion, referencia_curvatura,
         realimentacion_presion, realimentacion_curvatura);
    }

    /*  Actualizamos el actuador seleccionado */
    obj->actuadorSeleccionado = actuadorSeleccionado;

    /*  Las señales de control se trasladan al formato de salida (sin estructuras) */
    /*  1. Realimentación */
    /*  2. Referencias */
  }
}

/* Model output function */
void ControlSystem_Refactorization_output(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_d;
  int32_T ForEach_itr_g;
  int32_T ForEach_itr_n;
  int32_T ForEach_itr_e;
  int32_T ForEach_itr_c;
  XDis_ControlSystem_Refactorization_T *_rtXdis;
  slBusActuador rtb_ImpAsg_InsertedFor_Out1_at_inport_0[4];
  slBusActuador rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[4];
  slBusElectroValvulas rtb_DataStoreRead6;
  slBusSistema rtb_BusAssignment3;
  real_T d_curvatura[4];
  real_T d_presion[4];
  real_T rtb_CurvaturaActuadores[4];
  real_T rtb_PresinActuadores[4];
  real_T b_varargout_4;
  real_T b_varargout_4_0;
  real_T b_varargout_5;
  real_T b_varargout_6;
  real_T b_varargout_7;
  real_T rtb_PresinRegulador;
  real_T rtb_curvatura_f;
  real_T rtb_tensionControl;
  real_T *lastU;
  ActuadorPosicionado rtb_Actuadoresposicionados[4];
  ActuadorPosicionado tmp[4];
  Controlador b_varargout_1;
  Controlador rtb_Controladoractivo_i;
  boolean_T rtb_VlvulasbloqueadasControlautnomo[4];
  boolean_T b;
  boolean_T rtb_Compare_k;
  boolean_T tmp_0;
  if (rtmIsMajorTimeStep(ControlSystem_Refactorization_M)) {
    /* set solver stop time */
    if (!(ControlSystem_Refactorization_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&ControlSystem_Refactorization_M->solverInfo,
                            ((ControlSystem_Refactorization_M->Timing.clockTickH0
        + 1) * ControlSystem_Refactorization_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&ControlSystem_Refactorization_M->solverInfo,
                            ((ControlSystem_Refactorization_M->Timing.clockTick0
        + 1) * ControlSystem_Refactorization_M->Timing.stepSize0 +
        ControlSystem_Refactorization_M->Timing.clockTickH0 *
        ControlSystem_Refactorization_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(ControlSystem_Refactorization_M)) {
    ControlSystem_Refactorization_M->Timing.t[0] = rtsiGetT
      (&ControlSystem_Refactorization_M->solverInfo);
  }

  _rtXdis = ((XDis_ControlSystem_Refactorization_T *)
             ControlSystem_Refactorization_M->contStateDisabled);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ControlSystem_Refactorization_DW.DAQ_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ControlSystem_Refactorization_DW.ControldeCurvatura_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(ControlSystem_Refactorization_DW.ControldePresin_SubsysRanBC);

  /* DataStoreRead: '<Root>/Data Store Read3' */
  memcpy(&ControlSystem_Refactorization_B.DataStoreRead3[0],
         &ControlSystem_Refactorization_DW.actuadorBus[0], sizeof(slBusActuador)
         << 2U);
  tmp_0 = rtmIsMajorTimeStep(ControlSystem_Refactorization_M);
  if (tmp_0) {
    /* SignalConversion generated from: '<S1>/For Each Subsystem' incorporates:
     *  Constant: '<S18>/RefPresion1'
     *  Constant: '<S18>/RefPresion2'
     *  Constant: '<S18>/RefPresion3'
     *  Constant: '<S18>/RefPresion4'
     */
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport2[
      0] = ControlSystem_Refactorization_P.RefPresion1_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport2[
      1] = ControlSystem_Refactorization_P.RefPresion2_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport2[
      2] = ControlSystem_Refactorization_P.RefPresion3_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport2[
      3] = ControlSystem_Refactorization_P.RefPresion4_Value;

    /* SignalConversion generated from: '<S1>/For Each Subsystem' incorporates:
     *  Constant: '<S18>/RefCurvatura1'
     *  Constant: '<S18>/RefCurvatura2'
     *  Constant: '<S18>/RefCurvatura3'
     *  Constant: '<S18>/RefCurvatura4'
     */
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport3[
      0] = ControlSystem_Refactorization_P.RefCurvatura1_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport3[
      1] = ControlSystem_Refactorization_P.RefCurvatura2_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport3[
      2] = ControlSystem_Refactorization_P.RefCurvatura3_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport3[
      3] = ControlSystem_Refactorization_P.RefCurvatura4_Value;

    /* SignalConversion generated from: '<S1>/For Each Subsystem' incorporates:
     *  Constant: '<S18>/BloqueoManual1'
     *  Constant: '<S18>/BloqueoManual2'
     *  Constant: '<S18>/BloqueoManual3'
     *  Constant: '<S18>/BloqueoManual4'
     */
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      0] = ControlSystem_Refactorization_P.BloqueoManual1_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      1] = ControlSystem_Refactorization_P.BloqueoManual2_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      2] = ControlSystem_Refactorization_P.BloqueoManual3_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      3] = ControlSystem_Refactorization_P.BloqueoManual4_Value;

    /* SignalConversion generated from: '<S1>/For Each Subsystem' incorporates:
     *  Constant: '<S18>/ActuadorActivo1'
     *  Constant: '<S18>/ActuadorActivo2'
     *  Constant: '<S18>/ActuadorActivo3'
     *  Constant: '<S18>/ActuadorActivo4'
     */
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport5[
      0] = ControlSystem_Refactorization_P.ActuadorActivo1_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport5[
      1] = ControlSystem_Refactorization_P.ActuadorActivo2_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport5[
      2] = ControlSystem_Refactorization_P.ActuadorActivo3_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport5[
      3] = ControlSystem_Refactorization_P.ActuadorActivo4_Value;
  }

  /* Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
   *  ForEach: '<S19>/For Each'
   */
  for (ForEach_itr_c = 0; ForEach_itr_c < 4; ForEach_itr_c++) {
    /* ForEachSliceAssignment generated from: '<S19>/Out1' incorporates:
     *  BusAssignment: '<S19>/Bus Assignment3'
     *  DataStoreRead: '<Root>/Data Store Read3'
     *  ForEachSliceSelector generated from: '<S19>/Actuadores activos - Control autónomo'
     *  ForEachSliceSelector generated from: '<S19>/Bus'
     *  ForEachSliceSelector generated from: '<S19>/Referencias de curvatura'
     *  ForEachSliceSelector generated from: '<S19>/Referencias de presión'
     *  ForEachSliceSelector generated from: '<S19>/Válvulas cerradas - Control manual'
     */
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_c].
      Configuracion.Global.activo =
      ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport5
      [ForEach_itr_c];
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_c].
      Configuracion.Global.indice =
      ControlSystem_Refactorization_B.DataStoreRead3[ForEach_itr_c].
      Configuracion.Global.indice;
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_c].
      Configuracion.Global.Referencia.presion =
      ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport2
      [ForEach_itr_c];
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_c].
      Configuracion.Global.Referencia.curvatura =
      ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport3
      [ForEach_itr_c];
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_c].
      Configuracion.ControlManual.valvulaCerrada =
      ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4
      [ForEach_itr_c];
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_c].Estado =
      ControlSystem_Refactorization_B.DataStoreRead3[ForEach_itr_c].Estado;
  }

  /* End of Outputs for SubSystem: '<S1>/For Each Subsystem' */

  /* BusAssignment: '<S2>/Bus Assignment3' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/Constant1'
   *  Constant: '<S20>/Constant2'
   *  Constant: '<S20>/Constant4'
   *  Constant: '<S20>/Constant5'
   *  Constant: '<S20>/Constant6'
   *  Constant: '<S20>/Constant7'
   *  Constant: '<S20>/Constant8'
   *  Constant: '<S20>/Constant9'
   *  DataStoreRead: '<Root>/Data Store Read4'
   */
  rtb_BusAssignment3 = ControlSystem_Refactorization_DW.sistema;
  rtb_BusAssignment3.Configuracion.Global.modoControl =
    ControlSystem_Refactorization_P.Constant_Value_f;
  rtb_BusAssignment3.Configuracion.Global.parametroControl =
    ControlSystem_Refactorization_P.Constant1_Value_e;
  rtb_BusAssignment3.Configuracion.Global.simulacionActiva =
    ControlSystem_Refactorization_P.Constant2_Value;
  rtb_BusAssignment3.Configuracion.ControlManual.actuadorSeleccionado =
    ControlSystem_Refactorization_P.Constant4_Value;
  rtb_BusAssignment3.Configuracion.Global.ToleranciaPresion.estacionaria =
    ControlSystem_Refactorization_P.Constant5_Value;
  rtb_BusAssignment3.Configuracion.Global.ToleranciaPresion.derivativa =
    ControlSystem_Refactorization_P.Constant6_Value;
  rtb_BusAssignment3.Configuracion.Global.ToleranciaCurvatura.estacionaria =
    ControlSystem_Refactorization_P.Constant7_Value;
  rtb_BusAssignment3.Configuracion.Global.ToleranciaCurvatura.derivativa =
    ControlSystem_Refactorization_P.Constant8_Value;
  rtb_BusAssignment3.Configuracion.Global.toleranciaEquilibrioPresiones =
    ControlSystem_Refactorization_P.Constant9_Value;

  /* MATLABSystem: '<S6>/MATLAB System' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/Constant1'
   *  Constant: '<S20>/Constant4'
   *  DataStoreRead: '<Root>/Data Store Read5'
   *  ForEachSliceAssignment generated from: '<S19>/Out1'
   */
  /*  Implement algorithm. Calculate y as a function of input u and */
  /*  internal states. */
  /*  Inicializar variables */
  /*  Inicializar salidas */
  /*  1. Controlador activo */
  rtb_Controladoractivo_i = Controlador_Presion;

  /*  2. Actuadores posicionados */
  /*  3. Realimentación y referencias por defecto */
  b_varargout_4 = ControlSystem_Refactorization_DW.regulador.Estado.presion;
  rtb_PresinRegulador = 0.0;
  b_varargout_6 = ControlSystem_Refactorization_DW.regulador.Estado.presion;
  b_varargout_7 = 0.0;

  /*  4. Estado electroválvulas (control autónomo) */
  rtb_PresinActuadores[0] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].
    Configuracion.Global.Referencia.presion;
  rtb_CurvaturaActuadores[0] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].
    Configuracion.Global.Referencia.curvatura;
  d_presion[0] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].
    Estado.Realimentacion.presion;
  d_curvatura[0] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].
    Estado.Realimentacion.curvatura;
  rtb_PresinActuadores[1] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].
    Configuracion.Global.Referencia.presion;
  rtb_CurvaturaActuadores[1] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].
    Configuracion.Global.Referencia.curvatura;
  d_presion[1] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].
    Estado.Realimentacion.presion;
  d_curvatura[1] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].
    Estado.Realimentacion.curvatura;
  rtb_PresinActuadores[2] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].
    Configuracion.Global.Referencia.presion;
  rtb_CurvaturaActuadores[2] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].
    Configuracion.Global.Referencia.curvatura;
  d_presion[2] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].
    Estado.Realimentacion.presion;
  d_curvatura[2] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].
    Estado.Realimentacion.curvatura;
  rtb_PresinActuadores[3] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].
    Configuracion.Global.Referencia.presion;
  rtb_CurvaturaActuadores[3] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].
    Configuracion.Global.Referencia.curvatura;
  d_presion[3] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].
    Estado.Realimentacion.presion;
  d_curvatura[3] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].
    Estado.Realimentacion.curvatura;

  /*  Finalizar lógica de control si está deshabilitada o no hay ningún actuador seleccionado */
  b = (ControlSystem_Refactorization_P.Constant_Value_f == ModoControl_Manual);
  if (b && (b && (!(ControlSystem_Refactorization_P.Constant4_Value == 0.0)))) {
    /*  Lógica de control */
    /*  1. Señales de control */
    if (ControlSystem_Refactorization_P.Constant4_Value != 0.0) {
      /*  1.1 Referencias */
      b_varargout_6 = rtb_PresinActuadores[(int32_T)
        ControlSystem_Refactorization_P.Constant4_Value - 1];
      b_varargout_7 = rtb_CurvaturaActuadores[(int32_T)
        ControlSystem_Refactorization_P.Constant4_Value - 1];

      /*  1.2 Realimentaciones */
      b_varargout_4 = d_presion[(int32_T)
        ControlSystem_Refactorization_P.Constant4_Value - 1];
      rtb_PresinRegulador = d_curvatura[(int32_T)
        ControlSystem_Refactorization_P.Constant4_Value - 1];
    }

    /*  2. Controlador activo */
    if (ControlSystem_Refactorization_P.Constant1_Value_e ==
        ParametroControl_Curvatura) {
      rtb_Controladoractivo_i = Controlador_Curvatura;
    }
  }

  /* MATLABSystem: '<S6>/MATLAB System1' incorporates:
   *  BusAssignment: '<S2>/Bus Assignment3'
   *  DataStoreRead: '<Root>/Data Store Read5'
   *  ForEachSliceAssignment generated from: '<S19>/Out1'
   */
  ControlSystem_Refactorization_sequential_autonomousControlLogic_stepImpl
    (&ControlSystem_Refactorization_DW.obj,
     rtb_BusAssignment3.Configuracion.Global.modoControl,
     rtb_BusAssignment3.Configuracion.Global.parametroControl,
     rtb_BusAssignment3.Configuracion.Global.controlador,
     rtb_BusAssignment3.Configuracion.Global.toleranciaEquilibrioPresiones,
     rtb_BusAssignment3.Configuracion.Global.ToleranciaPresion.estacionaria,
     rtb_BusAssignment3.Configuracion.Global.ToleranciaPresion.derivativa,
     rtb_BusAssignment3.Configuracion.Global.ToleranciaCurvatura.estacionaria,
     rtb_BusAssignment3.Configuracion.Global.ToleranciaCurvatura.derivativa,
     rtb_BusAssignment3.Estado.Global.errorEstacionario.presion,
     rtb_BusAssignment3.Estado.Global.errorEstacionario.curvatura,
     rtb_BusAssignment3.Estado.Global.errorDerivativo.presion,
     rtb_BusAssignment3.Estado.Global.errorDerivativo.curvatura,
     rtb_ImpAsg_InsertedFor_Out1_at_inport_0,
     ControlSystem_Refactorization_DW.regulador.Estado.presion, &b_varargout_1,
     tmp, rtb_VlvulasbloqueadasControlautnomo, &b_varargout_4_0, &b_varargout_5,
     &rtb_tensionControl, &rtb_curvatura_f);

  /* MultiPortSwitch generated from: '<S6>/Index Vector1' incorporates:
   *  Constant: '<S20>/Constant'
   *  ForEachSliceAssignment generated from: '<S19>/Out1'
   *  MATLABSystem: '<S6>/MATLAB System'
   *  MATLABSystem: '<S6>/MATLAB System1'
   * */
  if (ControlSystem_Refactorization_P.Constant_Value_f == ModoControl_Manual) {
    rtb_Actuadoresposicionados[0] = 2U;
    rtb_VlvulasbloqueadasControlautnomo[0] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].
      Estado.ControlAutomatico.valvulaCerrada;
    rtb_Actuadoresposicionados[1] = 2U;
    rtb_VlvulasbloqueadasControlautnomo[1] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].
      Estado.ControlAutomatico.valvulaCerrada;
    rtb_Actuadoresposicionados[2] = 2U;
    rtb_VlvulasbloqueadasControlautnomo[2] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].
      Estado.ControlAutomatico.valvulaCerrada;
    rtb_Actuadoresposicionados[3] = 2U;
    rtb_VlvulasbloqueadasControlautnomo[3] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].
      Estado.ControlAutomatico.valvulaCerrada;
  } else {
    rtb_Actuadoresposicionados[0] = tmp[0];
    rtb_Actuadoresposicionados[1] = tmp[1];
    rtb_Actuadoresposicionados[2] = tmp[2];
    rtb_Actuadoresposicionados[3] = tmp[3];
  }

  /* Outputs for Iterator SubSystem: '<Root>/For Each Subsystem4' incorporates:
   *  ForEach: '<S3>/For Each'
   */
  for (ForEach_itr_e = 0; ForEach_itr_e < 4; ForEach_itr_e++) {
    /* ForEachSliceAssignment generated from: '<S3>/actuadores' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  ForEachSliceAssignment generated from: '<S19>/Out1'
     *  ForEachSliceSelector generated from: '<S3>/actuadorBus'
     *  ForEachSliceSelector generated from: '<S3>/actuadoresPosicionados'
     *  ForEachSliceSelector generated from: '<S3>/valvulasBloqueadas_controlAutonomo'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_e]
      .Configuracion = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_e].
      Configuracion;
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_e]
      .Estado.ControlAutomatico.valvulaCerrada =
      rtb_VlvulasbloqueadasControlautnomo[ForEach_itr_e];
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_e]
      .Estado.ControlAutomatico.actuadorPosicionado =
      rtb_Actuadoresposicionados[ForEach_itr_e];
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_e]
      .Estado.Realimentacion =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_e].
      Estado.Realimentacion;
  }

  /* End of Outputs for SubSystem: '<Root>/For Each Subsystem4' */

  /* MultiPortSwitch generated from: '<S6>/Index Vector1' incorporates:
   *  Constant: '<S20>/Constant'
   *  MATLABSystem: '<S6>/MATLAB System'
   *  MATLABSystem: '<S6>/MATLAB System1'
   * */
  if (ControlSystem_Refactorization_P.Constant_Value_f == ModoControl_Manual) {
    /* BusCreator generated from: '<Root>/Bus Assignment' incorporates:
     *  MATLABSystem: '<S6>/MATLAB System'
     * */
    b_varargout_4_0 = b_varargout_4;
    b_varargout_5 = rtb_PresinRegulador;
    rtb_tensionControl = b_varargout_6;
    rtb_curvatura_f = b_varargout_7;
  } else {
    rtb_Controladoractivo_i = b_varargout_1;
  }

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  BusCreator generated from: '<Root>/Bus Assignment'
   *  MultiPortSwitch generated from: '<S6>/Index Vector1'
   * */
  rtb_BusAssignment3.Configuracion.Global.controlador = rtb_Controladoractivo_i;
  rtb_BusAssignment3.Estado.Global.realimentacionControl.presion =
    b_varargout_4_0;
  rtb_BusAssignment3.Estado.Global.realimentacionControl.curvatura =
    b_varargout_5;
  rtb_BusAssignment3.Configuracion.Global.referenciaControl.presion =
    rtb_tensionControl;
  rtb_BusAssignment3.Configuracion.Global.referenciaControl.curvatura =
    rtb_curvatura_f;

  /* Logic: '<S7>/OR1' incorporates:
   *  Constant: '<S42>/Constant'
   *  Constant: '<S43>/Constant'
   *  RelationalOperator: '<S42>/Compare'
   *  RelationalOperator: '<S43>/Compare'
   */
  ControlSystem_Refactorization_B.OR1 = ((rtb_Controladoractivo_i ==
    ControlSystem_Refactorization_P.CompareToConstant1_const) ||
    (rtb_Controladoractivo_i ==
     ControlSystem_Refactorization_P.CompareToConstant4_const));
  if (tmp_0) {
    /* SignalConversion generated from: '<S45>/Enable' */
    ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_ControldePresin_at_inport_2
      = ControlSystem_Refactorization_B.OR1;

    /* Outputs for Enabled SubSystem: '<S7>/Control de Presión' incorporates:
     *  EnablePort: '<S45>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      if (ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_ControldePresin_at_inport_2)
      {
        if (!ControlSystem_Refactorization_DW.ControldePresin_MODE) {
          /* InitializeConditions for Derivative: '<S45>/Derivative' */
          ControlSystem_Refactorization_DW.TimeStampA = (rtInf);
          ControlSystem_Refactorization_DW.TimeStampB = (rtInf);
          ControlSystem_Refactorization_DW.ControldePresin_MODE = true;
        }
      } else {
        ControlSystem_Refactorization_DW.ControldePresin_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S7>/Control de Presión' */
  }

  /* Outputs for Enabled SubSystem: '<S7>/Control de Presión' incorporates:
   *  EnablePort: '<S45>/Enable'
   */
  if (ControlSystem_Refactorization_DW.ControldePresin_MODE) {
    /* Sum: '<S45>/Add' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment'
     *  BusCreator generated from: '<Root>/Bus Assignment'
     * */
    ControlSystem_Refactorization_B.Add = rtb_tensionControl - b_varargout_4_0;

    /* Derivative: '<S45>/Derivative' */
    b_varargout_4 = ControlSystem_Refactorization_M->Timing.t[0];
    if ((ControlSystem_Refactorization_DW.TimeStampA >= b_varargout_4) &&
        (ControlSystem_Refactorization_DW.TimeStampB >= b_varargout_4)) {
      /* Derivative: '<S45>/Derivative' */
      ControlSystem_Refactorization_B.Derivative = 0.0;
    } else {
      rtb_PresinRegulador = ControlSystem_Refactorization_DW.TimeStampA;
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA;
      if (ControlSystem_Refactorization_DW.TimeStampA <
          ControlSystem_Refactorization_DW.TimeStampB) {
        if (ControlSystem_Refactorization_DW.TimeStampB < b_varargout_4) {
          rtb_PresinRegulador = ControlSystem_Refactorization_DW.TimeStampB;
          lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB;
        }
      } else if (ControlSystem_Refactorization_DW.TimeStampA >= b_varargout_4) {
        rtb_PresinRegulador = ControlSystem_Refactorization_DW.TimeStampB;
        lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB;
      }

      /* Derivative: '<S45>/Derivative' */
      ControlSystem_Refactorization_B.Derivative =
        (ControlSystem_Refactorization_B.Add - *lastU) / (b_varargout_4 -
        rtb_PresinRegulador);
    }

    /* End of Derivative: '<S45>/Derivative' */

    /* Gain: '<S45>/Ganancia Presión -> Tensión' incorporates:
     *  BusCreator generated from: '<Root>/Bus Assignment'
     */
    b_varargout_4 = ControlSystem_Refactorization_P.GananciaPresinTensin_Gain_p *
      rtb_tensionControl;

    /* Saturate: '<S45>/Saturación de tensión' */
    if (b_varargout_4 >
        ControlSystem_Refactorization_P.Saturacindetensin_UpperSat_a) {
      /* Saturate: '<S45>/Saturación de tensión' */
      ControlSystem_Refactorization_B.presion =
        ControlSystem_Refactorization_P.Saturacindetensin_UpperSat_a;
    } else if (b_varargout_4 <
               ControlSystem_Refactorization_P.Saturacindetensin_LowerSat_m) {
      /* Saturate: '<S45>/Saturación de tensión' */
      ControlSystem_Refactorization_B.presion =
        ControlSystem_Refactorization_P.Saturacindetensin_LowerSat_m;
    } else {
      /* Saturate: '<S45>/Saturación de tensión' */
      ControlSystem_Refactorization_B.presion = b_varargout_4;
    }

    /* End of Saturate: '<S45>/Saturación de tensión' */
    if (rtmIsMajorTimeStep(ControlSystem_Refactorization_M)) {
      /* SignalConversion generated from: '<S45>/Constant1' incorporates:
       *  Constant: '<S45>/Constant1'
       */
      ControlSystem_Refactorization_B.curvatura =
        ControlSystem_Refactorization_P.Constant1_Value_m;

      /* SignalConversion generated from: '<S45>/Constant' incorporates:
       *  Constant: '<S45>/Constant'
       */
      ControlSystem_Refactorization_B.curvatura_g =
        ControlSystem_Refactorization_P.Constant_Value_k;
    }

    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      srUpdateBC(ControlSystem_Refactorization_DW.ControldePresin_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S7>/Control de Presión' */

  /* RelationalOperator: '<S41>/Compare' incorporates:
   *  Constant: '<S41>/Constant'
   */
  ControlSystem_Refactorization_B.Compare = (rtb_Controladoractivo_i ==
    ControlSystem_Refactorization_P.CompareToConstant_const_b);
  if (tmp_0) {
    /* SignalConversion generated from: '<S44>/Enable' */
    ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_ControldeCurvatura_at_inport_3
      = ControlSystem_Refactorization_B.Compare;

    /* Outputs for Enabled SubSystem: '<S7>/Control de Curvatura' incorporates:
     *  EnablePort: '<S44>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      if (ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_ControldeCurvatura_at_inport_3)
      {
        if (!ControlSystem_Refactorization_DW.ControldeCurvatura_MODE) {
          (void) memset(&(ControlSystem_Refactorization_XDis.Integrator_CSTATE),
                        0,
                        1*sizeof(boolean_T));

          /* InitializeConditions for Derivative: '<S44>/Derivative1' */
          ControlSystem_Refactorization_DW.TimeStampA_b = (rtInf);
          ControlSystem_Refactorization_DW.TimeStampB_f = (rtInf);

          /* SystemReset for Atomic SubSystem: '<S44>/Controlador de posición PID' */
          /* InitializeConditions for Integrator: '<S46>/Integrator' */
          ControlSystem_Refactorization_X.Integrator_CSTATE =
            ControlSystem_Refactorization_P.Integrator_IC;

          /* InitializeConditions for Derivative: '<S46>/Derivative' */
          ControlSystem_Refactorization_DW.TimeStampA_k = (rtInf);
          ControlSystem_Refactorization_DW.TimeStampB_b = (rtInf);

          /* End of SystemReset for SubSystem: '<S44>/Controlador de posición PID' */
          ControlSystem_Refactorization_DW.ControldeCurvatura_MODE = true;
        }
      } else {
        if (ControlSystem_Refactorization_M->Timing.t[1] == rtmGetTStart
            (ControlSystem_Refactorization_M)) {
          (void) memset(&(ControlSystem_Refactorization_XDis.Integrator_CSTATE),
                        1,
                        1*sizeof(boolean_T));
        }

        if (ControlSystem_Refactorization_DW.ControldeCurvatura_MODE) {
          (void) memset(&(ControlSystem_Refactorization_XDis.Integrator_CSTATE),
                        1,
                        1*sizeof(boolean_T));
          ControlSystem_Refactorization_DW.ControldeCurvatura_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S7>/Control de Curvatura' */
  }

  /* Outputs for Enabled SubSystem: '<S7>/Control de Curvatura' incorporates:
   *  EnablePort: '<S44>/Enable'
   */
  if (ControlSystem_Refactorization_DW.ControldeCurvatura_MODE) {
    /* Sum: '<S44>/Add1' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment'
     *  BusCreator generated from: '<Root>/Bus Assignment'
     *  Sum: '<S44>/Sum'
     * */
    b_varargout_5 = rtb_curvatura_f - b_varargout_5;

    /* Sum: '<S44>/Add1' */
    ControlSystem_Refactorization_B.Add1 = b_varargout_5;

    /* Gain: '<S44>/Ganancia Presión -> Tensión' */
    rtb_curvatura_f = b_varargout_5 *
      ControlSystem_Refactorization_P.GananciaPresinTensin_Gain;

    /* Outputs for Atomic SubSystem: '<S44>/Controlador de posición PID' */
    /* RelationalOperator: '<S47>/Compare' incorporates:
     *  Constant: '<S47>/Constant'
     */
    ControlSystem_Refactorization_B.Compare_k = (rtb_Controladoractivo_i ==
      ControlSystem_Refactorization_P.CompareToConstant_const);

    /* Integrator: '<S46>/Integrator' */
    b = rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo);
    if (b) {
      rtb_Compare_k =
        (((ControlSystem_Refactorization_PrevZCX.Integrator_Reset_ZCE ==
           POS_ZCSIG) != (int32_T)ControlSystem_Refactorization_B.Compare_k) &&
         (ControlSystem_Refactorization_PrevZCX.Integrator_Reset_ZCE !=
          UNINITIALIZED_ZCSIG));
      ControlSystem_Refactorization_PrevZCX.Integrator_Reset_ZCE =
        ControlSystem_Refactorization_B.Compare_k;

      /* evaluate zero-crossings */
      if (rtb_Compare_k) {
        ControlSystem_Refactorization_X.Integrator_CSTATE =
          ControlSystem_Refactorization_P.Integrator_IC;
      }
    }

    /* Gain: '<S46>/Gain2' */
    ControlSystem_Refactorization_B.Gain2 =
      ControlSystem_Refactorization_P.Gain2_Gain * rtb_curvatura_f;

    /* Derivative: '<S46>/Derivative' incorporates:
     *  Derivative: '<S44>/Derivative1'
     */
    b_varargout_4 = ControlSystem_Refactorization_M->Timing.t[0];
    if ((ControlSystem_Refactorization_DW.TimeStampA_k >= b_varargout_4) &&
        (ControlSystem_Refactorization_DW.TimeStampB_b >= b_varargout_4)) {
      rtb_tensionControl = 0.0;
    } else {
      rtb_PresinRegulador = ControlSystem_Refactorization_DW.TimeStampA_k;
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA_g;
      if (ControlSystem_Refactorization_DW.TimeStampA_k <
          ControlSystem_Refactorization_DW.TimeStampB_b) {
        if (ControlSystem_Refactorization_DW.TimeStampB_b < b_varargout_4) {
          rtb_PresinRegulador = ControlSystem_Refactorization_DW.TimeStampB_b;
          lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_c;
        }
      } else if (ControlSystem_Refactorization_DW.TimeStampA_k >= b_varargout_4)
      {
        rtb_PresinRegulador = ControlSystem_Refactorization_DW.TimeStampB_b;
        lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_c;
      }

      rtb_tensionControl = (ControlSystem_Refactorization_B.Gain2 - *lastU) /
        (b_varargout_4 - rtb_PresinRegulador);
    }

    /* End of Derivative: '<S46>/Derivative' */

    /* Gain: '<S46>/Gain1' */
    ControlSystem_Refactorization_B.Gain1 =
      ControlSystem_Refactorization_P.Gain1_Gain * rtb_curvatura_f;

    /* End of Outputs for SubSystem: '<S44>/Controlador de posición PID' */

    /* Derivative: '<S44>/Derivative1' */
    if ((ControlSystem_Refactorization_DW.TimeStampA_b >= b_varargout_4) &&
        (ControlSystem_Refactorization_DW.TimeStampB_f >= b_varargout_4)) {
      /* Derivative: '<S44>/Derivative1' */
      ControlSystem_Refactorization_B.Derivative1 = 0.0;
    } else {
      rtb_PresinRegulador = ControlSystem_Refactorization_DW.TimeStampA_b;
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA_e;
      if (ControlSystem_Refactorization_DW.TimeStampA_b <
          ControlSystem_Refactorization_DW.TimeStampB_f) {
        if (ControlSystem_Refactorization_DW.TimeStampB_f < b_varargout_4) {
          rtb_PresinRegulador = ControlSystem_Refactorization_DW.TimeStampB_f;
          lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_k;
        }
      } else if (ControlSystem_Refactorization_DW.TimeStampA_b >= b_varargout_4)
      {
        rtb_PresinRegulador = ControlSystem_Refactorization_DW.TimeStampB_f;
        lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_k;
      }

      /* Derivative: '<S44>/Derivative1' */
      ControlSystem_Refactorization_B.Derivative1 =
        (ControlSystem_Refactorization_B.Add1 - *lastU) / (b_varargout_4 -
        rtb_PresinRegulador);
    }

    /* Outputs for Atomic SubSystem: '<S44>/Controlador de posición PID' */
    /* Sum: '<S46>/Add' incorporates:
     *  Gain: '<S46>/Gain'
     *  Integrator: '<S46>/Integrator'
     */
    b_varargout_4 = (ControlSystem_Refactorization_P.Gain_Gain * rtb_curvatura_f
                     + ControlSystem_Refactorization_X.Integrator_CSTATE) +
      rtb_tensionControl;

    /* End of Outputs for SubSystem: '<S44>/Controlador de posición PID' */

    /* Saturate: '<S44>/Saturación de tensión' */
    if (b_varargout_4 >
        ControlSystem_Refactorization_P.Saturacindetensin_UpperSat) {
      /* Saturate: '<S44>/Saturación de tensión' */
      ControlSystem_Refactorization_B.Saturacindetensin =
        ControlSystem_Refactorization_P.Saturacindetensin_UpperSat;
    } else if (b_varargout_4 <
               ControlSystem_Refactorization_P.Saturacindetensin_LowerSat) {
      /* Saturate: '<S44>/Saturación de tensión' */
      ControlSystem_Refactorization_B.Saturacindetensin =
        ControlSystem_Refactorization_P.Saturacindetensin_LowerSat;
    } else {
      /* Saturate: '<S44>/Saturación de tensión' */
      ControlSystem_Refactorization_B.Saturacindetensin = b_varargout_4;
    }

    /* End of Saturate: '<S44>/Saturación de tensión' */
    if (rtmIsMajorTimeStep(ControlSystem_Refactorization_M)) {
      /* SignalConversion generated from: '<S44>/Constant1' incorporates:
       *  Constant: '<S44>/Constant1'
       */
      ControlSystem_Refactorization_B.presion_b =
        ControlSystem_Refactorization_P.Constant1_Value;

      /* SignalConversion generated from: '<S44>/Constant' incorporates:
       *  Constant: '<S44>/Constant'
       */
      ControlSystem_Refactorization_B.presion_bl =
        ControlSystem_Refactorization_P.Constant_Value_d;
    }

    if (b) {
      srUpdateBC(ControlSystem_Refactorization_DW.ControldeCurvatura_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S7>/Control de Curvatura' */

  /* MultiPortSwitch generated from: '<S7>/Index Vector' incorporates:
   *  BusAssignment: '<Root>/Bus Assignment'
   *  MultiPortSwitch generated from: '<S6>/Index Vector1'
   */
  switch (rtb_Controladoractivo_i) {
   case Controlador_Presion:
    rtb_tensionControl = ControlSystem_Refactorization_B.presion;

    /* BusCreator generated from: '<Root>/Bus Assignment1' */
    b_varargout_5 = ControlSystem_Refactorization_B.Add;
    b_varargout_4 = ControlSystem_Refactorization_B.curvatura_g;
    rtb_PresinRegulador = ControlSystem_Refactorization_B.Derivative;
    rtb_curvatura_f = ControlSystem_Refactorization_B.curvatura;
    break;

   case Controlador_EquilibrioPresiones:
    rtb_tensionControl = ControlSystem_Refactorization_B.presion;

    /* BusCreator generated from: '<Root>/Bus Assignment1' */
    b_varargout_5 = ControlSystem_Refactorization_B.Add;
    b_varargout_4 = ControlSystem_Refactorization_B.curvatura_g;
    rtb_PresinRegulador = ControlSystem_Refactorization_B.Derivative;
    rtb_curvatura_f = ControlSystem_Refactorization_B.curvatura;
    break;

   default:
    rtb_tensionControl = ControlSystem_Refactorization_B.Saturacindetensin;

    /* BusCreator generated from: '<Root>/Bus Assignment1' */
    b_varargout_5 = ControlSystem_Refactorization_B.presion_bl;
    b_varargout_4 = ControlSystem_Refactorization_B.Add1;
    rtb_PresinRegulador = ControlSystem_Refactorization_B.presion_b;
    rtb_curvatura_f = ControlSystem_Refactorization_B.Derivative1;
    break;
  }

  /* End of MultiPortSwitch generated from: '<S7>/Index Vector' */

  /* BusAssignment: '<Root>/Bus Assignment1' incorporates:
   *  BusAssignment: '<Root>/Bus Assignment'
   */
  ControlSystem_Refactorization_B.sistema = rtb_BusAssignment3;

  /* BusAssignment: '<Root>/Bus Assignment1' incorporates:
   *  BusCreator generated from: '<Root>/Bus Assignment1'
   * */
  ControlSystem_Refactorization_B.sistema.Estado.Global.tensionControl =
    rtb_tensionControl;
  ControlSystem_Refactorization_B.sistema.Estado.Global.errorEstacionario.presion
    = b_varargout_5;
  ControlSystem_Refactorization_B.sistema.Estado.Global.errorEstacionario.curvatura
    = b_varargout_4;
  ControlSystem_Refactorization_B.sistema.Estado.Global.errorDerivativo.presion =
    rtb_PresinRegulador;
  ControlSystem_Refactorization_B.sistema.Estado.Global.errorDerivativo.curvatura
    = rtb_curvatura_f;

  /* DataStoreRead: '<Root>/Data Store Read6' */
  rtb_DataStoreRead6 = ControlSystem_Refactorization_DW.electroValvulas;

  /* Logic: '<S5>/NOT' */
  ControlSystem_Refactorization_B.NOT =
    !ControlSystem_Refactorization_B.sistema.Configuracion.Global.simulacionActiva;
  if (tmp_0) {
    /* SignalConversion generated from: '<S21>/Enable' */
    ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_DAQ_at_inport_3 =
      ControlSystem_Refactorization_B.NOT;

    /* Outputs for Enabled SubSystem: '<S5>/DAQ' incorporates:
     *  EnablePort: '<S21>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      ControlSystem_Refactorization_DW.DAQ_MODE =
        ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_DAQ_at_inport_3;
    }

    /* End of Outputs for SubSystem: '<S5>/DAQ' */
  }

  /* Outputs for Enabled SubSystem: '<S5>/DAQ' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  if (ControlSystem_Refactorization_DW.DAQ_MODE) {
    b = rtmIsMajorTimeStep(ControlSystem_Refactorization_M);
    if (b) {
      /* MATLAB Function: '<S21>/MATLAB Function' */
      ControlSystem_Refactorization_DW.sfEvent =
        ControlSystem_Refactorization_CALL_EVENT;
      ControlSystem_Refactorization_B.press = -1.2083538083538083;
    }

    /* Outputs for Iterator SubSystem: '<S21>/Flujo de aire en los actuadores' incorporates:
     *  ForEach: '<S23>/For Each'
     */
    for (ForEach_itr_g = 0; ForEach_itr_g < 4; ForEach_itr_g++) {
      /* Switch: '<S23>/Switch' incorporates:
       *  Constant: '<S25>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S23>/Actuador'
       *  RelationalOperator: '<S25>/Compare'
       */
      if (ControlSystem_Refactorization_B.sistema.Configuracion.Global.modoControl
          ==
          ControlSystem_Refactorization_P.CoreSubsys_pna.CompareToConstant5_const)
      {
        rtb_Compare_k =
          ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
          [ForEach_itr_g].Configuracion.ControlManual.valvulaCerrada;
      } else {
        rtb_Compare_k =
          ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
          [ForEach_itr_g].Estado.ControlAutomatico.valvulaCerrada;
      }

      /* Switch: '<S23>/Switch1' incorporates:
       *  Constant: '<S26>/Constant'
       *  RelationalOperator: '<S26>/Compare'
       *  Switch: '<S23>/Switch'
       */
      if (rtb_Compare_k ==
          ControlSystem_Refactorization_P.CoreSubsys_pna.CompareToConstant6_const)
      {
        /* ForEachSliceAssignment generated from: '<S23>/Out1' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_g]
          = ControlSystem_Refactorization_B.press;
      } else {
        /* ForEachSliceAssignment generated from: '<S23>/Out1' incorporates:
         *  ForEachSliceAssignment generated from: '<S3>/actuadores'
         *  ForEachSliceSelector generated from: '<S23>/Actuador'
         */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_g]
          =
          ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
          [ForEach_itr_g].Estado.Realimentacion.presion;
      }

      /* End of Switch: '<S23>/Switch1' */
    }

    /* End of Outputs for SubSystem: '<S21>/Flujo de aire en los actuadores' */
    /*  Implement algorithm. Calculate y as a function of input u and */
    /*  internal states. */
    /*  Inicialización de variables */
    /*  Seleccionar cámara de control */
    /*  Selección de tensiones de salida */
    if (b) {
      /* Constant: '<S21>/Constant' */
      ControlSystem_Refactorization_B.Constant_j[0] =
        ControlSystem_Refactorization_P.Constant_Value[0];

      /* SignalConversion generated from: '<S21>/Curvatura Actuadores' incorporates:
       *  Constant: '<S21>/Constant'
       */
      ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[0] =
        ControlSystem_Refactorization_P.Constant_Value[0];

      /* Constant: '<S21>/Constant' */
      ControlSystem_Refactorization_B.Constant_j[1] =
        ControlSystem_Refactorization_P.Constant_Value[1];

      /* SignalConversion generated from: '<S21>/Curvatura Actuadores' incorporates:
       *  Constant: '<S21>/Constant'
       */
      ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[1] =
        ControlSystem_Refactorization_P.Constant_Value[1];

      /* Constant: '<S21>/Constant' */
      ControlSystem_Refactorization_B.Constant_j[2] =
        ControlSystem_Refactorization_P.Constant_Value[2];

      /* SignalConversion generated from: '<S21>/Curvatura Actuadores' incorporates:
       *  Constant: '<S21>/Constant'
       */
      ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[2] =
        ControlSystem_Refactorization_P.Constant_Value[2];

      /* Constant: '<S21>/Constant' */
      ControlSystem_Refactorization_B.Constant_j[3] =
        ControlSystem_Refactorization_P.Constant_Value[3];

      /* SignalConversion generated from: '<S21>/Curvatura Actuadores' incorporates:
       *  Constant: '<S21>/Constant'
       */
      ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[3] =
        ControlSystem_Refactorization_P.Constant_Value[3];
    }

    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      srUpdateBC(ControlSystem_Refactorization_DW.DAQ_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S5>/DAQ' */
  if (tmp_0) {
    /* SignalConversion generated from: '<S22>/Enable' */
    ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_Simulacin_at_inport_2 =
      ControlSystem_Refactorization_B.sistema.Configuracion.Global.simulacionActiva;

    /* Outputs for Enabled SubSystem: '<S5>/Simulación' incorporates:
     *  EnablePort: '<S22>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      if (ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_Simulacin_at_inport_2)
      {
        if (!ControlSystem_Refactorization_DW.Simulacin_MODE) {
          (void) memset
            (&(ControlSystem_Refactorization_XDis.Modelodelreguladordepresinelectrnico_CSTATE),
             0,
             102*sizeof(boolean_T));
          ControlSystem_Refactorization_DW.Simulacin_MODE = true;
        }
      } else {
        /* Outputs for Enabled SubSystem: '<S7>/Control de Curvatura' incorporates:
         *  EnablePort: '<S44>/Enable'
         */
        if (ControlSystem_Refactorization_M->Timing.t[1] == rtmGetTStart
            (ControlSystem_Refactorization_M)) {
          (void) memset
            (&(ControlSystem_Refactorization_XDis.Modelodelreguladordepresinelectrnico_CSTATE),
             1,
             102*sizeof(boolean_T));
        }

        /* End of Outputs for SubSystem: '<S7>/Control de Curvatura' */
        if (ControlSystem_Refactorization_DW.Simulacin_MODE) {
          (void) memset
            (&(ControlSystem_Refactorization_XDis.Modelodelreguladordepresinelectrnico_CSTATE),
             1,
             102*sizeof(boolean_T));

          /* Disable for Iterator SubSystem: '<S22>/Modelo de los actuadores' */
          for (ForEach_itr_d = 0; ForEach_itr_d < 4; ForEach_itr_d++) {
            /* Disable for Enabled SubSystem: '<S27>/Curvatura Actuador 1' */
            if (ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
                CurvaturaActuador1.CurvaturaActuador5_MODE) {
              ControlSystem_Refactorization_CurvaturaActuador5_Disable
                (&ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d]
                 .CurvaturaActuador1);
            }

            /* End of Disable for SubSystem: '<S27>/Curvatura Actuador 1' */

            /* Disable for Enabled SubSystem: '<S27>/Curvatura Actuador 2' */
            if (ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
                CurvaturaActuador2.CurvaturaActuador5_MODE) {
              ControlSystem_Refactorization_CurvaturaActuador5_Disable
                (&ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d]
                 .CurvaturaActuador2);
            }

            /* End of Disable for SubSystem: '<S27>/Curvatura Actuador 2' */

            /* Disable for Enabled SubSystem: '<S27>/Curvatura Actuador 3' */
            if (ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
                CurvaturaActuador3.CurvaturaActuador5_MODE) {
              ControlSystem_Refactorization_CurvaturaActuador5_Disable
                (&ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d]
                 .CurvaturaActuador3);
            }

            /* End of Disable for SubSystem: '<S27>/Curvatura Actuador 3' */

            /* Disable for Enabled SubSystem: '<S27>/Curvatura Actuador 4' */
            if (ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
                CurvaturaActuador4.CurvaturaActuador5_MODE) {
              ControlSystem_Refactorization_CurvaturaActuador5_Disable
                (&ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d]
                 .CurvaturaActuador4);
            }

            /* End of Disable for SubSystem: '<S27>/Curvatura Actuador 4' */

            /* Disable for Enabled SubSystem: '<S27>/Curvatura Actuador 5' */
            if (ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
                CurvaturaActuador5.CurvaturaActuador5_MODE) {
              ControlSystem_Refactorization_CurvaturaActuador5_Disable
                (&ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d]
                 .CurvaturaActuador5);
            }

            /* End of Disable for SubSystem: '<S27>/Curvatura Actuador 5' */
          }

          /* End of Disable for SubSystem: '<S22>/Modelo de los actuadores' */
          ControlSystem_Refactorization_DW.Simulacin_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S5>/Simulación' */
  }

  /* Outputs for Enabled SubSystem: '<S5>/Simulación' incorporates:
   *  EnablePort: '<S22>/Enable'
   */
  if (ControlSystem_Refactorization_DW.Simulacin_MODE) {
    /* Abs: '<S22>/Abs' */
    ControlSystem_Refactorization_B.Abs = fabs
      (ControlSystem_Refactorization_B.sistema.Estado.Global.tensionControl);

    /* TransferFcn: '<S22>/Modelo del regulador de presión electrónico' */
    ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico = 0.0;
    ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico +=
      ControlSystem_Refactorization_P.Modelodelreguladordepresinelectrnico_C[0] *
      ControlSystem_Refactorization_X.Modelodelreguladordepresinelectrnico_CSTATE
      [0];
    ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico +=
      ControlSystem_Refactorization_P.Modelodelreguladordepresinelectrnico_C[1] *
      ControlSystem_Refactorization_X.Modelodelreguladordepresinelectrnico_CSTATE
      [1];

    /* Outputs for Iterator SubSystem: '<S22>/Modelo de los actuadores' incorporates:
     *  ForEach: '<S27>/For Each'
     */
    for (ForEach_itr_d = 0; ForEach_itr_d < 4; ForEach_itr_d++) {
      /* ForEachSliceSelector generated from: '<S27>/Actuador' incorporates:
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       */
      rtb_tensionControl =
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
        [ForEach_itr_d].Configuracion.Global.indice;
      rtb_curvatura_f =
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
        [ForEach_itr_d].Estado.Realimentacion.presion;

      /* RelationalOperator: '<S28>/Compare' incorporates:
       *  Constant: '<S28>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S27>/Actuador'
       */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare =
        (ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
         [ForEach_itr_d].Configuracion.Global.indice ==
         ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant_const);

      /* RelationalOperator: '<S29>/Compare' incorporates:
       *  Constant: '<S29>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S27>/Actuador'
       */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_g =
        (ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
         [ForEach_itr_d].Configuracion.Global.indice ==
         ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant1_const);

      /* RelationalOperator: '<S30>/Compare' incorporates:
       *  Constant: '<S30>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S27>/Actuador'
       */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_e =
        (ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
         [ForEach_itr_d].Configuracion.Global.indice ==
         ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant2_const);

      /* RelationalOperator: '<S31>/Compare' incorporates:
       *  Constant: '<S31>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S27>/Actuador'
       */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_d =
        (ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
         [ForEach_itr_d].Configuracion.Global.indice ==
         ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant3_const);

      /* RelationalOperator: '<S32>/Compare' incorporates:
       *  Constant: '<S32>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S27>/Actuador'
       */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_i =
        (ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
         [ForEach_itr_d].Configuracion.Global.indice ==
         ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant4_const);

      /* Switch: '<S27>/Switch' incorporates:
       *  Constant: '<S33>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S27>/Actuador'
       *  RelationalOperator: '<S33>/Compare'
       */
      if (ControlSystem_Refactorization_B.sistema.Configuracion.Global.modoControl
          ==
          ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant5_const)
      {
        rtb_Compare_k =
          ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
          [ForEach_itr_d].Configuracion.ControlManual.valvulaCerrada;
      } else {
        rtb_Compare_k =
          ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
          [ForEach_itr_d].Estado.ControlAutomatico.valvulaCerrada;
      }

      /* RelationalOperator: '<S34>/Compare' incorporates:
       *  Constant: '<S34>/Constant'
       *  Switch: '<S27>/Switch'
       */
      rtb_Compare_k = (rtb_Compare_k ==
                       ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant6_const);
      b = rtmIsMajorTimeStep(ControlSystem_Refactorization_M);
      if (b) {
        /* Constant: '<S35>/Constant' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Constant =
          ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant7_const;

        /* SignalConversion generated from: '<S36>/Enable' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          HiddenBuf_InsertedFor_CurvaturaActuador1_at_inport_1 =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare;
      }

      /* Outputs for Enabled SubSystem: '<S27>/Curvatura Actuador 1' */
      ControlSystem_Refactorization_CurvaturaActuador5
        (ControlSystem_Refactorization_M,
         ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         HiddenBuf_InsertedFor_CurvaturaActuador1_at_inport_1,
         &ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador1,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1);

      /* End of Outputs for SubSystem: '<S27>/Curvatura Actuador 1' */
      if (b) {
        /* SignalConversion generated from: '<S37>/Enable' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          HiddenBuf_InsertedFor_CurvaturaActuador2_at_inport_1 =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          Compare_g;
      }

      /* Outputs for Enabled SubSystem: '<S27>/Curvatura Actuador 2' */
      ControlSystem_Refactorization_CurvaturaActuador5
        (ControlSystem_Refactorization_M,
         ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         HiddenBuf_InsertedFor_CurvaturaActuador2_at_inport_1,
         &ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador2,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2);

      /* End of Outputs for SubSystem: '<S27>/Curvatura Actuador 2' */
      if (b) {
        /* SignalConversion generated from: '<S38>/Enable' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          HiddenBuf_InsertedFor_CurvaturaActuador3_at_inport_1 =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          Compare_e;
      }

      /* Outputs for Enabled SubSystem: '<S27>/Curvatura Actuador 3' */
      ControlSystem_Refactorization_CurvaturaActuador5
        (ControlSystem_Refactorization_M,
         ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         HiddenBuf_InsertedFor_CurvaturaActuador3_at_inport_1,
         &ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador3,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3);

      /* End of Outputs for SubSystem: '<S27>/Curvatura Actuador 3' */
      if (b) {
        /* SignalConversion generated from: '<S39>/Enable' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          HiddenBuf_InsertedFor_CurvaturaActuador4_at_inport_1 =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          Compare_d;
      }

      /* Outputs for Enabled SubSystem: '<S27>/Curvatura Actuador 4' */
      ControlSystem_Refactorization_CurvaturaActuador5
        (ControlSystem_Refactorization_M,
         ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         HiddenBuf_InsertedFor_CurvaturaActuador4_at_inport_1,
         &ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador4,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4);

      /* End of Outputs for SubSystem: '<S27>/Curvatura Actuador 4' */
      if (b) {
        /* SignalConversion generated from: '<S40>/Enable' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          HiddenBuf_InsertedFor_CurvaturaActuador5_at_inport_1 =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          Compare_i;
      }

      /* Outputs for Enabled SubSystem: '<S27>/Curvatura Actuador 5' */
      ControlSystem_Refactorization_CurvaturaActuador5
        (ControlSystem_Refactorization_M,
         ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         HiddenBuf_InsertedFor_CurvaturaActuador5_at_inport_1,
         &ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador5,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5);

      /* End of Outputs for SubSystem: '<S27>/Curvatura Actuador 5' */

      /* MultiPortSwitch: '<S27>/Index Vector2' incorporates:
       *  ForEachSliceSelector generated from: '<S27>/Actuador'
       */
      switch ((int32_T)rtb_tensionControl) {
       case 1:
        /* ForEachSliceAssignment generated from: '<S27>/Curvatura Actuador' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
          [ForEach_itr_d] =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          CurvaturaActuador1.CurvAct;
        break;

       case 2:
        /* ForEachSliceAssignment generated from: '<S27>/Curvatura Actuador' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
          [ForEach_itr_d] =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          CurvaturaActuador2.CurvAct;
        break;

       case 3:
        /* ForEachSliceAssignment generated from: '<S27>/Curvatura Actuador' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
          [ForEach_itr_d] =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          CurvaturaActuador3.CurvAct;
        break;

       case 4:
        /* ForEachSliceAssignment generated from: '<S27>/Curvatura Actuador' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
          [ForEach_itr_d] =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          CurvaturaActuador4.CurvAct;
        break;

       default:
        /* ForEachSliceAssignment generated from: '<S27>/Curvatura Actuador' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
          [ForEach_itr_d] =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          CurvaturaActuador5.CurvAct;
        break;
      }

      /* End of MultiPortSwitch: '<S27>/Index Vector2' */

      /* Switch: '<S27>/Switch1' */
      if (rtb_Compare_k) {
        /* Switch: '<S27>/Switch2' incorporates:
         *  RelationalOperator: '<S35>/Compare'
         */
        if (ControlSystem_Refactorization_B.sistema.Estado.Global.tensionControl
            >= ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
            Constant) {
          /* Switch: '<S27>/Switch1' */
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
            EstadoValvula_o =
            ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico;
        } else {
          /* Switch: '<S27>/Switch1' incorporates:
           *  UnaryMinus: '<S27>/Unary Minus'
           */
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
            EstadoValvula_o =
            -ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico;
        }
      } else {
        /* Switch: '<S27>/Switch1' incorporates:
         *  ForEachSliceSelector generated from: '<S27>/Actuador'
         *  Switch: '<S27>/Switch2'
         */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          EstadoValvula_o = rtb_curvatura_f;
      }

      /* End of Switch: '<S27>/Switch1' */

      /* ForEachSliceAssignment generated from: '<S27>/Presión Actuador' */
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
        [ForEach_itr_d] =
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        EstadoValvula_o;
    }

    /* End of Outputs for SubSystem: '<S22>/Modelo de los actuadores' */
    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      srUpdateBC(ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S5>/Simulación' */

  /* MultiPortSwitch generated from: '<S5>/Index Vector1' incorporates:
   *  ForEachSliceAssignment generated from: '<S23>/Out1'
   *  ForEachSliceAssignment generated from: '<S27>/Curvatura Actuador'
   *  ForEachSliceAssignment generated from: '<S27>/Presión Actuador'
   */
  if (!ControlSystem_Refactorization_B.sistema.Configuracion.Global.simulacionActiva)
  {
    rtb_PresinActuadores[0] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Out1_at_inport_0[0];
    rtb_CurvaturaActuadores[0] =
      ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[0];
    rtb_PresinActuadores[1] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Out1_at_inport_0[1];
    rtb_CurvaturaActuadores[1] =
      ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[1];
    rtb_PresinActuadores[2] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Out1_at_inport_0[2];
    rtb_CurvaturaActuadores[2] =
      ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[2];
    rtb_PresinActuadores[3] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Out1_at_inport_0[3];
    rtb_CurvaturaActuadores[3] =
      ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[3];
  } else {
    rtb_PresinActuadores[0] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [0];
    rtb_CurvaturaActuadores[0] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [0];
    rtb_PresinActuadores[1] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [1];
    rtb_CurvaturaActuadores[1] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [1];
    rtb_PresinActuadores[2] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [2];
    rtb_CurvaturaActuadores[2] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [2];
    rtb_PresinActuadores[3] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [3];
    rtb_CurvaturaActuadores[3] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [3];
  }

  /* Outputs for Iterator SubSystem: '<Root>/For Each Subsystem5' incorporates:
   *  ForEach: '<S4>/For Each'
   */
  for (ForEach_itr_n = 0; ForEach_itr_n < 4; ForEach_itr_n++) {
    /* ForEachSliceAssignment generated from: '<S4>/actuadores' incorporates:
     *  BusAssignment: '<S4>/Bus Assignment'
     *  ForEachSliceAssignment generated from: '<S3>/actuadores'
     *  ForEachSliceSelector generated from: '<S4>/actuadorBus'
     *  ForEachSliceSelector generated from: '<S4>/curvaturaActuadores'
     *  ForEachSliceSelector generated from: '<S4>/presionActuadores'
     */
    rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_n].Configuracion =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_n]
      .Configuracion;
    rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_n].
      Estado.ControlAutomatico =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_n]
      .Estado.ControlAutomatico;
    rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_n].
      Estado.Realimentacion.presion = rtb_PresinActuadores[ForEach_itr_n];
    rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_n].
      Estado.Realimentacion.curvatura = rtb_CurvaturaActuadores[ForEach_itr_n];
  }

  /* End of Outputs for SubSystem: '<Root>/For Each Subsystem5' */

  /* DataStoreWrite: '<Root>/Data Store Write4' incorporates:
   *  ForEachSliceAssignment generated from: '<S4>/actuadores'
   */
  memcpy(&ControlSystem_Refactorization_DW.actuadorBus[0],
         &rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[0], sizeof(slBusActuador)
         << 2U);

  /* MultiPortSwitch generated from: '<S5>/Index Vector1' */
  if (!ControlSystem_Refactorization_B.sistema.Configuracion.Global.simulacionActiva)
  {
    rtb_PresinRegulador = ControlSystem_Refactorization_B.press;
  } else {
    rtb_PresinRegulador =
      ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico;
  }

  /* DataStoreWrite: '<Root>/Data Store Write5' incorporates:
   *  BusAssignment: '<Root>/Bus Assignment2'
   */
  ControlSystem_Refactorization_DW.regulador.Estado.presion =
    rtb_PresinRegulador;

  /* DataStoreWrite: '<Root>/Data Store Write6' incorporates:
   *  BusAssignment: '<Root>/Bus Assignment1'
   */
  ControlSystem_Refactorization_DW.sistema =
    ControlSystem_Refactorization_B.sistema;

  /* DataStoreWrite: '<Root>/Data Store Write7' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read6'
   */
  ControlSystem_Refactorization_DW.electroValvulas = rtb_DataStoreRead6;

  /* Outputs for Iterator SubSystem: '<S8>/DATOS DE ACTUADORES' incorporates:
   *  ForEach: '<S49>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
    /* ForEachSliceAssignment generated from: '<S49>/Presión actuadores' incorporates:
     *  ForEachSliceAssignment generated from: '<S4>/actuadores'
     *  ForEachSliceSelector generated from: '<S49>/actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0
      [ForEach_itr] = rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr]
      .Estado.Realimentacion.presion;

    /* ForEachSliceAssignment generated from: '<S49>/Curvatura actuadores' incorporates:
     *  ForEachSliceAssignment generated from: '<S4>/actuadores'
     *  ForEachSliceSelector generated from: '<S49>/actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Curvaturaactuadores_at_inport_0
      [ForEach_itr] = rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr]
      .Estado.Realimentacion.curvatura;

    /* ForEachSliceAssignment generated from: '<S49>/Actuadores posicionados' incorporates:
     *  ForEachSliceAssignment generated from: '<S4>/actuadores'
     *  ForEachSliceSelector generated from: '<S49>/actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Actuadoresposicionados_at_inport_0
      [ForEach_itr] = rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr]
      .Estado.ControlAutomatico.actuadorPosicionado;
  }

  /* End of Outputs for SubSystem: '<S8>/DATOS DE ACTUADORES' */

  /* SignalConversion generated from: '<S8>/Bus Selector' */
  ControlSystem_Refactorization_B.simulacionActiva =
    ControlSystem_Refactorization_B.sistema.Configuracion.Global.simulacionActiva;

  /* SignalConversion generated from: '<S8>/Bus Selector' */
  ControlSystem_Refactorization_B.modoControl =
    ControlSystem_Refactorization_B.sistema.Configuracion.Global.modoControl;
  if (tmp_0) {
    /* Constant: '<S48>/Constant' */
    ControlSystem_Refactorization_B.Constant =
      ControlSystem_Refactorization_P.CompareToConstant7_const;
  }

  /* Switch: '<S8>/Switch2' incorporates:
   *  RelationalOperator: '<S48>/Compare'
   */
  if (ControlSystem_Refactorization_B.sistema.Estado.Global.tensionControl >=
      ControlSystem_Refactorization_B.Constant) {
    /* Switch: '<S8>/Switch2' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment2'
     */
    ControlSystem_Refactorization_B.PresinRegulador = rtb_PresinRegulador;
  } else {
    /* Switch: '<S8>/Switch2' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment2'
     *  UnaryMinus: '<S8>/Unary Minus'
     */
    ControlSystem_Refactorization_B.PresinRegulador = -rtb_PresinRegulador;
  }

  /* End of Switch: '<S8>/Switch2' */
}

/* Model update function */
void ControlSystem_Refactorization_update(void)
{
  real_T *lastU;

  /* Update for Enabled SubSystem: '<S7>/Control de Presión' incorporates:
   *  EnablePort: '<S45>/Enable'
   */
  if (ControlSystem_Refactorization_DW.ControldePresin_MODE) {
    /* Update for Derivative: '<S45>/Derivative' */
    if (ControlSystem_Refactorization_DW.TimeStampA == (rtInf)) {
      ControlSystem_Refactorization_DW.TimeStampA =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA;
    } else if (ControlSystem_Refactorization_DW.TimeStampB == (rtInf)) {
      ControlSystem_Refactorization_DW.TimeStampB =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB;
    } else if (ControlSystem_Refactorization_DW.TimeStampA <
               ControlSystem_Refactorization_DW.TimeStampB) {
      ControlSystem_Refactorization_DW.TimeStampA =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA;
    } else {
      ControlSystem_Refactorization_DW.TimeStampB =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB;
    }

    *lastU = ControlSystem_Refactorization_B.Add;

    /* End of Update for Derivative: '<S45>/Derivative' */
  }

  /* End of Update for SubSystem: '<S7>/Control de Presión' */

  /* Update for Enabled SubSystem: '<S7>/Control de Curvatura' incorporates:
   *  EnablePort: '<S44>/Enable'
   */
  if (ControlSystem_Refactorization_DW.ControldeCurvatura_MODE) {
    /* Update for Atomic SubSystem: '<S44>/Controlador de posición PID' */
    /* Update for Derivative: '<S46>/Derivative' */
    if (ControlSystem_Refactorization_DW.TimeStampA_k == (rtInf)) {
      ControlSystem_Refactorization_DW.TimeStampA_k =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA_g;
    } else if (ControlSystem_Refactorization_DW.TimeStampB_b == (rtInf)) {
      ControlSystem_Refactorization_DW.TimeStampB_b =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_c;
    } else if (ControlSystem_Refactorization_DW.TimeStampA_k <
               ControlSystem_Refactorization_DW.TimeStampB_b) {
      ControlSystem_Refactorization_DW.TimeStampA_k =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA_g;
    } else {
      ControlSystem_Refactorization_DW.TimeStampB_b =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_c;
    }

    *lastU = ControlSystem_Refactorization_B.Gain2;

    /* End of Update for Derivative: '<S46>/Derivative' */
    /* End of Update for SubSystem: '<S44>/Controlador de posición PID' */

    /* Update for Derivative: '<S44>/Derivative1' */
    if (ControlSystem_Refactorization_DW.TimeStampA_b == (rtInf)) {
      ControlSystem_Refactorization_DW.TimeStampA_b =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA_e;
    } else if (ControlSystem_Refactorization_DW.TimeStampB_f == (rtInf)) {
      ControlSystem_Refactorization_DW.TimeStampB_f =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_k;
    } else if (ControlSystem_Refactorization_DW.TimeStampA_b <
               ControlSystem_Refactorization_DW.TimeStampB_f) {
      ControlSystem_Refactorization_DW.TimeStampA_b =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA_e;
    } else {
      ControlSystem_Refactorization_DW.TimeStampB_f =
        ControlSystem_Refactorization_M->Timing.t[0];
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_k;
    }

    *lastU = ControlSystem_Refactorization_B.Add1;

    /* End of Update for Derivative: '<S44>/Derivative1' */
  }

  /* End of Update for SubSystem: '<S7>/Control de Curvatura' */
  if (rtmIsMajorTimeStep(ControlSystem_Refactorization_M)) {
    rt_ertODEUpdateContinuousStates(&ControlSystem_Refactorization_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++ControlSystem_Refactorization_M->Timing.clockTick0)) {
    ++ControlSystem_Refactorization_M->Timing.clockTickH0;
  }

  ControlSystem_Refactorization_M->Timing.t[0] = rtsiGetSolverStopTime
    (&ControlSystem_Refactorization_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.0001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ControlSystem_Refactorization_M->Timing.clockTick1)) {
      ++ControlSystem_Refactorization_M->Timing.clockTickH1;
    }

    ControlSystem_Refactorization_M->Timing.t[1] =
      ControlSystem_Refactorization_M->Timing.clockTick1 *
      ControlSystem_Refactorization_M->Timing.stepSize1 +
      ControlSystem_Refactorization_M->Timing.clockTickH1 *
      ControlSystem_Refactorization_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void ControlSystem_Refactorization_derivatives(void)
{
  /* local scratch DWork variables */
  int32_T ForEach_itr_d;
  XDot_ControlSystem_Refactorization_T *_rtXdot;
  real_T tmp[2];
  _rtXdot = ((XDot_ControlSystem_Refactorization_T *)
             ControlSystem_Refactorization_M->derivs);

  /* Derivatives for Enabled SubSystem: '<S7>/Control de Curvatura' */
  if (ControlSystem_Refactorization_DW.ControldeCurvatura_MODE) {
    /* Derivatives for Atomic SubSystem: '<S44>/Controlador de posición PID' */
    /* Derivatives for Integrator: '<S46>/Integrator' */
    _rtXdot->Integrator_CSTATE = ControlSystem_Refactorization_B.Gain1;

    /* End of Derivatives for SubSystem: '<S44>/Controlador de posición PID' */
  } else {
    ((XDot_ControlSystem_Refactorization_T *)
      ControlSystem_Refactorization_M->derivs)->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for SubSystem: '<S7>/Control de Curvatura' */

  /* Derivatives for Enabled SubSystem: '<S5>/Simulación' */
  if (ControlSystem_Refactorization_DW.Simulacin_MODE) {
    /* Derivatives for TransferFcn: '<S22>/Modelo del regulador de presión electrónico' */
    _rtXdot->Modelodelreguladordepresinelectrnico_CSTATE[0] = 0.0;
    _rtXdot->Modelodelreguladordepresinelectrnico_CSTATE[0] +=
      ControlSystem_Refactorization_P.Modelodelreguladordepresinelectrnico_A[0] *
      ControlSystem_Refactorization_X.Modelodelreguladordepresinelectrnico_CSTATE
      [0];
    _rtXdot->Modelodelreguladordepresinelectrnico_CSTATE[1] = 0.0;
    _rtXdot->Modelodelreguladordepresinelectrnico_CSTATE[0] +=
      ControlSystem_Refactorization_P.Modelodelreguladordepresinelectrnico_A[1] *
      ControlSystem_Refactorization_X.Modelodelreguladordepresinelectrnico_CSTATE
      [1];
    _mm_storeu_pd(&tmp[0], _mm_add_pd(_mm_set_pd
      (_rtXdot->Modelodelreguladordepresinelectrnico_CSTATE[0],
       ControlSystem_Refactorization_X.Modelodelreguladordepresinelectrnico_CSTATE
       [0]), _mm_set_pd(ControlSystem_Refactorization_B.Abs,
                        _rtXdot->Modelodelreguladordepresinelectrnico_CSTATE[1])));
    _rtXdot->Modelodelreguladordepresinelectrnico_CSTATE[1] = tmp[0];
    _rtXdot->Modelodelreguladordepresinelectrnico_CSTATE[0] = tmp[1];

    /* Derivatives for Iterator SubSystem: '<S22>/Modelo de los actuadores' */
    for (ForEach_itr_d = 0; ForEach_itr_d < 4; ForEach_itr_d++) {
      /* Derivatives for Iterator SubSystem: '<S22>/Modelo de los actuadores' */
      /* Derivatives for Enabled SubSystem: '<S27>/Curvatura Actuador 1' */
      ControlSystem_Refactorization_CurvaturaActuador5_Deriv
        (ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         EstadoValvula_o,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador1,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1, &_rtXdot->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1);

      /* End of Derivatives for SubSystem: '<S27>/Curvatura Actuador 1' */

      /* Derivatives for Enabled SubSystem: '<S27>/Curvatura Actuador 2' */
      ControlSystem_Refactorization_CurvaturaActuador5_Deriv
        (ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         EstadoValvula_o,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador2,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2, &_rtXdot->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2);

      /* End of Derivatives for SubSystem: '<S27>/Curvatura Actuador 2' */

      /* Derivatives for Enabled SubSystem: '<S27>/Curvatura Actuador 3' */
      ControlSystem_Refactorization_CurvaturaActuador5_Deriv
        (ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         EstadoValvula_o,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador3,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3, &_rtXdot->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3);

      /* End of Derivatives for SubSystem: '<S27>/Curvatura Actuador 3' */

      /* Derivatives for Enabled SubSystem: '<S27>/Curvatura Actuador 4' */
      ControlSystem_Refactorization_CurvaturaActuador5_Deriv
        (ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         EstadoValvula_o,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador4,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4, &_rtXdot->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4);

      /* End of Derivatives for SubSystem: '<S27>/Curvatura Actuador 4' */

      /* Derivatives for Enabled SubSystem: '<S27>/Curvatura Actuador 5' */
      ControlSystem_Refactorization_CurvaturaActuador5_Deriv
        (ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         EstadoValvula_o,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador5,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5, &_rtXdot->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5);

      /* End of Derivatives for SubSystem: '<S27>/Curvatura Actuador 5' */
      /* End of Derivatives for SubSystem: '<S22>/Modelo de los actuadores' */
    }

    /* End of Derivatives for SubSystem: '<S22>/Modelo de los actuadores' */
  } else {
    {
      real_T *dx;
      int_T i1;
      dx = &(((XDot_ControlSystem_Refactorization_T *)
              ControlSystem_Refactorization_M->derivs)
             ->Modelodelreguladordepresinelectrnico_CSTATE[0]);
      for (i1=0; i1 < 102; i1++) {
        dx[i1] = 0.0;
      }
    }
  }

  /* End of Derivatives for SubSystem: '<S5>/Simulación' */
}

/* Model initialize function */
void ControlSystem_Refactorization_initialize(void)
{
  {
    /* local scratch DWork variables */
    int32_T ForEach_itr_d;
    XDis_ControlSystem_Refactorization_T *_rtXdis;
    _rtXdis = ((XDis_ControlSystem_Refactorization_T *)
               ControlSystem_Refactorization_M->contStateDisabled);

    /* Start for MATLABSystem: '<S6>/MATLAB System' */
    ControlSystem_Refactorization_DW.objisempty_e = true;
    ControlSystem_Refactorization_DW.obj_k.isInitialized = 1;

    /* Start for MATLABSystem: '<S6>/MATLAB System1' */
    /*  Perform one-time calculations, such as computing constants */
    ControlSystem_Refactorization_DW.obj.controlHabilitado = false;
    ControlSystem_Refactorization_DW.obj.parametroControl =
      ParametroControl_Presion;
    ControlSystem_Refactorization_DW.obj.actuadorSeleccionado = 0.0;
    ControlSystem_Refactorization_DW.objisempty = true;
    ControlSystem_Refactorization_DW.obj.isInitialized = 1;

    /* Start for Enabled SubSystem: '<S7>/Control de Presión' */
    /*  Perform one-time calculations, such as computing constants */
    ControlSystem_Refactorization_DW.ControldePresin_MODE = false;

    /* End of Start for SubSystem: '<S7>/Control de Presión' */

    /* Start for Enabled SubSystem: '<S7>/Control de Curvatura' */
    ControlSystem_Refactorization_DW.ControldeCurvatura_MODE = false;
    (void) memset(&(ControlSystem_Refactorization_XDis.Integrator_CSTATE), 1,
                  1*sizeof(boolean_T));

    /* End of Start for SubSystem: '<S7>/Control de Curvatura' */

    /* Start for Enabled SubSystem: '<S5>/DAQ' */
    ControlSystem_Refactorization_DW.DAQ_MODE = false;

    /* Start for MATLABSystem: '<S21>/MATLAB System' */
    ControlSystem_Refactorization_DW.objisempty_h = true;
    ControlSystem_Refactorization_DW.obj_b.isInitialized = 1;

    /* Start for Constant: '<S21>/Constant' */
    /*  Perform one-time calculations, such as computing constants */
    ControlSystem_Refactorization_B.Constant_j[0] =
      ControlSystem_Refactorization_P.Constant_Value[0];
    ControlSystem_Refactorization_B.Constant_j[1] =
      ControlSystem_Refactorization_P.Constant_Value[1];
    ControlSystem_Refactorization_B.Constant_j[2] =
      ControlSystem_Refactorization_P.Constant_Value[2];
    ControlSystem_Refactorization_B.Constant_j[3] =
      ControlSystem_Refactorization_P.Constant_Value[3];

    /* End of Start for SubSystem: '<S5>/DAQ' */

    /* Start for Enabled SubSystem: '<S5>/Simulación' */
    ControlSystem_Refactorization_DW.Simulacin_MODE = false;
    (void) memset
      (&(ControlSystem_Refactorization_XDis.Modelodelreguladordepresinelectrnico_CSTATE),
       1,
       102*sizeof(boolean_T));

    /* Start for Iterator SubSystem: '<S22>/Modelo de los actuadores' */
    for (ForEach_itr_d = 0; ForEach_itr_d < 4; ForEach_itr_d++) {
      /* Start for RelationalOperator: '<S28>/Compare' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare =
        false;

      /* Start for RelationalOperator: '<S29>/Compare' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_g =
        false;

      /* Start for RelationalOperator: '<S30>/Compare' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_e =
        false;

      /* Start for RelationalOperator: '<S31>/Compare' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_d =
        false;

      /* Start for RelationalOperator: '<S32>/Compare' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_i =
        false;

      /* Start for Constant: '<S35>/Constant' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Constant =
        0.0;

      /* Start for SignalConversion generated from: '<S36>/Enable' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        HiddenBuf_InsertedFor_CurvaturaActuador1_at_inport_1 = false;

      /* Start for SignalConversion generated from: '<S37>/Enable' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        HiddenBuf_InsertedFor_CurvaturaActuador2_at_inport_1 = false;

      /* Start for SignalConversion generated from: '<S38>/Enable' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        HiddenBuf_InsertedFor_CurvaturaActuador3_at_inport_1 = false;

      /* Start for SignalConversion generated from: '<S39>/Enable' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        HiddenBuf_InsertedFor_CurvaturaActuador4_at_inport_1 = false;

      /* Start for SignalConversion generated from: '<S40>/Enable' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        HiddenBuf_InsertedFor_CurvaturaActuador5_at_inport_1 = false;

      /* Start for Switch: '<S27>/Switch1' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        EstadoValvula_o = 0.0;

      /* Start for Enabled SubSystem: '<S27>/Curvatura Actuador 1' */
      ControlSystem_Refactorization_CurvaturaActuador5_Start
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1);

      /* End of Start for SubSystem: '<S27>/Curvatura Actuador 1' */

      /* Start for Enabled SubSystem: '<S27>/Curvatura Actuador 2' */
      ControlSystem_Refactorization_CurvaturaActuador5_Start
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2);

      /* End of Start for SubSystem: '<S27>/Curvatura Actuador 2' */

      /* Start for Enabled SubSystem: '<S27>/Curvatura Actuador 3' */
      ControlSystem_Refactorization_CurvaturaActuador5_Start
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3);

      /* End of Start for SubSystem: '<S27>/Curvatura Actuador 3' */

      /* Start for Enabled SubSystem: '<S27>/Curvatura Actuador 4' */
      ControlSystem_Refactorization_CurvaturaActuador5_Start
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4);

      /* End of Start for SubSystem: '<S27>/Curvatura Actuador 4' */

      /* Start for Enabled SubSystem: '<S27>/Curvatura Actuador 5' */
      ControlSystem_Refactorization_CurvaturaActuador5_Start
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5);

      /* End of Start for SubSystem: '<S27>/Curvatura Actuador 5' */
    }

    /* End of Start for SubSystem: '<S22>/Modelo de los actuadores' */
    /* End of Start for SubSystem: '<S5>/Simulación' */

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    memcpy(&ControlSystem_Refactorization_DW.actuadorBus[0],
           &ControlSystem_Refactorization_P.actuadorBus[0], sizeof(slBusActuador)
           << 2U);

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    ControlSystem_Refactorization_DW.sistema =
      ControlSystem_Refactorization_P.sistema;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    ControlSystem_Refactorization_DW.regulador =
      ControlSystem_Refactorization_P.regulador;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    ControlSystem_Refactorization_DW.electroValvulas =
      ControlSystem_Refactorization_P.electroValvulas;
  }

  ControlSystem_Refactorization_PrevZCX.Integrator_Reset_ZCE =
    UNINITIALIZED_ZCSIG;

  {
    /* local scratch DWork variables */
    int32_T ForEach_itr_d;

    /* SystemInitialize for Enabled SubSystem: '<S7>/Control de Presión' */
    /* InitializeConditions for Derivative: '<S45>/Derivative' */
    ControlSystem_Refactorization_DW.TimeStampA = (rtInf);
    ControlSystem_Refactorization_DW.TimeStampB = (rtInf);

    /* SystemInitialize for Saturate: '<S45>/Saturación de tensión' incorporates:
     *  Outport: '<S45>/SeñalControl'
     */
    ControlSystem_Refactorization_B.presion =
      ControlSystem_Refactorization_P.SealControl_Y0_p;

    /* SystemInitialize for Sum: '<S45>/Add' incorporates:
     *  Outport: '<S45>/Error estacionario'
     */
    ControlSystem_Refactorization_B.Add =
      ControlSystem_Refactorization_P.Errorestacionario_Y0_i.presion;

    /* SystemInitialize for SignalConversion generated from: '<S45>/Constant' incorporates:
     *  Outport: '<S45>/Error estacionario'
     */
    ControlSystem_Refactorization_B.curvatura_g =
      ControlSystem_Refactorization_P.Errorestacionario_Y0_i.curvatura;

    /* SystemInitialize for Derivative: '<S45>/Derivative' incorporates:
     *  Outport: '<S45>/Error derivativo'
     */
    ControlSystem_Refactorization_B.Derivative =
      ControlSystem_Refactorization_P.Errorderivativo_Y0_b.presion;

    /* SystemInitialize for SignalConversion generated from: '<S45>/Constant1' incorporates:
     *  Outport: '<S45>/Error derivativo'
     */
    ControlSystem_Refactorization_B.curvatura =
      ControlSystem_Refactorization_P.Errorderivativo_Y0_b.curvatura;

    /* End of SystemInitialize for SubSystem: '<S7>/Control de Presión' */

    /* SystemInitialize for Enabled SubSystem: '<S7>/Control de Curvatura' */
    /* InitializeConditions for Derivative: '<S44>/Derivative1' */
    ControlSystem_Refactorization_DW.TimeStampA_b = (rtInf);
    ControlSystem_Refactorization_DW.TimeStampB_f = (rtInf);

    /* SystemInitialize for Atomic SubSystem: '<S44>/Controlador de posición PID' */
    /* InitializeConditions for Integrator: '<S46>/Integrator' */
    ControlSystem_Refactorization_X.Integrator_CSTATE =
      ControlSystem_Refactorization_P.Integrator_IC;

    /* InitializeConditions for Derivative: '<S46>/Derivative' */
    ControlSystem_Refactorization_DW.TimeStampA_k = (rtInf);
    ControlSystem_Refactorization_DW.TimeStampB_b = (rtInf);

    /* End of SystemInitialize for SubSystem: '<S44>/Controlador de posición PID' */

    /* SystemInitialize for Saturate: '<S44>/Saturación de tensión' incorporates:
     *  Outport: '<S44>/SeñalControl'
     */
    ControlSystem_Refactorization_B.Saturacindetensin =
      ControlSystem_Refactorization_P.SealControl_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S44>/Constant' incorporates:
     *  Outport: '<S44>/Error estacionario'
     */
    ControlSystem_Refactorization_B.presion_bl =
      ControlSystem_Refactorization_P.Errorestacionario_Y0.presion;

    /* SystemInitialize for Sum: '<S44>/Add1' incorporates:
     *  Outport: '<S44>/Error estacionario'
     */
    ControlSystem_Refactorization_B.Add1 =
      ControlSystem_Refactorization_P.Errorestacionario_Y0.curvatura;

    /* SystemInitialize for SignalConversion generated from: '<S44>/Constant1' incorporates:
     *  Outport: '<S44>/Error derivativo'
     */
    ControlSystem_Refactorization_B.presion_b =
      ControlSystem_Refactorization_P.Errorderivativo_Y0.presion;

    /* SystemInitialize for Derivative: '<S44>/Derivative1' incorporates:
     *  Outport: '<S44>/Error derivativo'
     */
    ControlSystem_Refactorization_B.Derivative1 =
      ControlSystem_Refactorization_P.Errorderivativo_Y0.curvatura;

    /* End of SystemInitialize for SubSystem: '<S7>/Control de Curvatura' */

    /* SystemInitialize for Enabled SubSystem: '<S5>/DAQ' */
    /* SystemInitialize for MATLAB Function: '<S21>/MATLAB Function' */
    ControlSystem_Refactorization_DW.sfEvent =
      ControlSystem_Refactorization_CALL_EVENT;

    /* SystemInitialize for SignalConversion generated from: '<S21>/Curvatura Actuadores' */
    ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[0] =
      ControlSystem_Refactorization_B.Constant_j[0];

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S23>/Out1' incorporates:
     *  Outport: '<S21>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Out1_at_inport_0[0] =
      ControlSystem_Refactorization_P.PresinActuadores_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S21>/Curvatura Actuadores' */
    ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[1] =
      ControlSystem_Refactorization_B.Constant_j[1];

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S23>/Out1' incorporates:
     *  Outport: '<S21>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Out1_at_inport_0[1] =
      ControlSystem_Refactorization_P.PresinActuadores_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S21>/Curvatura Actuadores' */
    ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[2] =
      ControlSystem_Refactorization_B.Constant_j[2];

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S23>/Out1' incorporates:
     *  Outport: '<S21>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Out1_at_inport_0[2] =
      ControlSystem_Refactorization_P.PresinActuadores_Y0;

    /* SystemInitialize for SignalConversion generated from: '<S21>/Curvatura Actuadores' */
    ControlSystem_Refactorization_B.OutportBufferForCurvaturaActuadores[3] =
      ControlSystem_Refactorization_B.Constant_j[3];

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S23>/Out1' incorporates:
     *  Outport: '<S21>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Out1_at_inport_0[3] =
      ControlSystem_Refactorization_P.PresinActuadores_Y0;

    /* SystemInitialize for Outport: '<S21>/Presión Regulador' */
    ControlSystem_Refactorization_B.press =
      ControlSystem_Refactorization_P.PresinRegulador_Y0;

    /* End of SystemInitialize for SubSystem: '<S5>/DAQ' */

    /* SystemInitialize for Enabled SubSystem: '<S5>/Simulación' */
    /* InitializeConditions for TransferFcn: '<S22>/Modelo del regulador de presión electrónico' */
    ControlSystem_Refactorization_X.Modelodelreguladordepresinelectrnico_CSTATE
      [0] = 0.0;
    ControlSystem_Refactorization_X.Modelodelreguladordepresinelectrnico_CSTATE
      [1] = 0.0;

    /* End of SystemInitialize for SubSystem: '<S5>/Simulación' */
    /* SystemInitialize for Enabled SubSystem: '<S5>/Simulación' */
    /* SystemInitialize for Iterator SubSystem: '<S22>/Modelo de los actuadores' */
    for (ForEach_itr_d = 0; ForEach_itr_d < 4; ForEach_itr_d++) {
      /* SystemInitialize for Enabled SubSystem: '<S5>/Simulación' */
      /* SystemInitialize for Iterator SubSystem: '<S22>/Modelo de los actuadores' */
      /* SystemInitialize for Enabled SubSystem: '<S27>/Curvatura Actuador 1' */
      ControlSystem_Refactorization_CurvaturaActuador5_Init
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador1,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1);

      /* End of SystemInitialize for SubSystem: '<S27>/Curvatura Actuador 1' */

      /* SystemInitialize for Enabled SubSystem: '<S27>/Curvatura Actuador 2' */
      ControlSystem_Refactorization_CurvaturaActuador5_Init
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador2,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2);

      /* End of SystemInitialize for SubSystem: '<S27>/Curvatura Actuador 2' */

      /* SystemInitialize for Enabled SubSystem: '<S27>/Curvatura Actuador 3' */
      ControlSystem_Refactorization_CurvaturaActuador5_Init
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador3,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3);

      /* End of SystemInitialize for SubSystem: '<S27>/Curvatura Actuador 3' */

      /* SystemInitialize for Enabled SubSystem: '<S27>/Curvatura Actuador 4' */
      ControlSystem_Refactorization_CurvaturaActuador5_Init
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador4,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4);

      /* End of SystemInitialize for SubSystem: '<S27>/Curvatura Actuador 4' */

      /* SystemInitialize for Enabled SubSystem: '<S27>/Curvatura Actuador 5' */
      ControlSystem_Refactorization_CurvaturaActuador5_Init
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador5,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5);

      /* End of SystemInitialize for SubSystem: '<S27>/Curvatura Actuador 5' */
      /* End of SystemInitialize for SubSystem: '<S22>/Modelo de los actuadores' */
      /* End of SystemInitialize for SubSystem: '<S5>/Simulación' */
    }

    /* End of SystemInitialize for SubSystem: '<S22>/Modelo de los actuadores' */
    /* End of SystemInitialize for SubSystem: '<S5>/Simulación' */
    /* SystemInitialize for Enabled SubSystem: '<S5>/Simulación' */
    /* SystemInitialize for TransferFcn: '<S22>/Modelo del regulador de presión electrónico' incorporates:
     *  Outport: '<S22>/Presión Reguladores'
     */
    ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico =
      ControlSystem_Refactorization_P.PresinReguladores_Y0;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S27>/Presión Actuador' incorporates:
     *  Outport: '<S22>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [0] = ControlSystem_Refactorization_P.PresinActuadores_Y0_o;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S27>/Curvatura Actuador' incorporates:
     *  Outport: '<S22>/Curvatura Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [0] = ControlSystem_Refactorization_P.CurvaturaActuadores_Y0;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S27>/Presión Actuador' incorporates:
     *  Outport: '<S22>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [1] = ControlSystem_Refactorization_P.PresinActuadores_Y0_o;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S27>/Curvatura Actuador' incorporates:
     *  Outport: '<S22>/Curvatura Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [1] = ControlSystem_Refactorization_P.CurvaturaActuadores_Y0;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S27>/Presión Actuador' incorporates:
     *  Outport: '<S22>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [2] = ControlSystem_Refactorization_P.PresinActuadores_Y0_o;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S27>/Curvatura Actuador' incorporates:
     *  Outport: '<S22>/Curvatura Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [2] = ControlSystem_Refactorization_P.CurvaturaActuadores_Y0;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S27>/Presión Actuador' incorporates:
     *  Outport: '<S22>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [3] = ControlSystem_Refactorization_P.PresinActuadores_Y0_o;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S27>/Curvatura Actuador' incorporates:
     *  Outport: '<S22>/Curvatura Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [3] = ControlSystem_Refactorization_P.CurvaturaActuadores_Y0;

    /* End of SystemInitialize for SubSystem: '<S5>/Simulación' */
  }
}

/* Model terminate function */
void ControlSystem_Refactorization_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  ControlSystem_Refactorization_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  ControlSystem_Refactorization_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  ControlSystem_Refactorization_initialize();
}

void MdlTerminate(void)
{
  ControlSystem_Refactorization_terminate();
}

/* Registration function */
RT_MODEL_ControlSystem_Refactorization_T *ControlSystem_Refactorization(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ControlSystem_Refactorization_M, 0,
                sizeof(RT_MODEL_ControlSystem_Refactorization_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&ControlSystem_Refactorization_M->solverInfo,
                          &ControlSystem_Refactorization_M->Timing.simTimeStep);
    rtsiSetTPtr(&ControlSystem_Refactorization_M->solverInfo, &rtmGetTPtr
                (ControlSystem_Refactorization_M));
    rtsiSetStepSizePtr(&ControlSystem_Refactorization_M->solverInfo,
                       &ControlSystem_Refactorization_M->Timing.stepSize0);
    rtsiSetdXPtr(&ControlSystem_Refactorization_M->solverInfo,
                 &ControlSystem_Refactorization_M->derivs);
    rtsiSetContStatesPtr(&ControlSystem_Refactorization_M->solverInfo, (real_T **)
                         &ControlSystem_Refactorization_M->contStates);
    rtsiSetNumContStatesPtr(&ControlSystem_Refactorization_M->solverInfo,
      &ControlSystem_Refactorization_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&ControlSystem_Refactorization_M->solverInfo,
      &ControlSystem_Refactorization_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&ControlSystem_Refactorization_M->solverInfo,
       &ControlSystem_Refactorization_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&ControlSystem_Refactorization_M->solverInfo,
       &ControlSystem_Refactorization_M->periodicContStateRanges);
    rtsiSetContStateDisabledPtr(&ControlSystem_Refactorization_M->solverInfo,
      (boolean_T**) &ControlSystem_Refactorization_M->contStateDisabled);
    rtsiSetErrorStatusPtr(&ControlSystem_Refactorization_M->solverInfo,
                          (&rtmGetErrorStatus(ControlSystem_Refactorization_M)));
    rtsiSetRTModelPtr(&ControlSystem_Refactorization_M->solverInfo,
                      ControlSystem_Refactorization_M);
  }

  rtsiSetSimTimeStep(&ControlSystem_Refactorization_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange
    (&ControlSystem_Refactorization_M->solverInfo, false);
  rtsiSetIsContModeFrozen(&ControlSystem_Refactorization_M->solverInfo, false);
  ControlSystem_Refactorization_M->intgData.y =
    ControlSystem_Refactorization_M->odeY;
  ControlSystem_Refactorization_M->intgData.f[0] =
    ControlSystem_Refactorization_M->odeF[0];
  ControlSystem_Refactorization_M->intgData.f[1] =
    ControlSystem_Refactorization_M->odeF[1];
  ControlSystem_Refactorization_M->intgData.f[2] =
    ControlSystem_Refactorization_M->odeF[2];
  ControlSystem_Refactorization_M->contStates = ((real_T *)
    &ControlSystem_Refactorization_X);
  ControlSystem_Refactorization_M->contStateDisabled = ((boolean_T *)
    &ControlSystem_Refactorization_XDis);
  ControlSystem_Refactorization_M->Timing.tStart = (0.0);
  rtsiSetSolverData(&ControlSystem_Refactorization_M->solverInfo, (void *)
                    &ControlSystem_Refactorization_M->intgData);
  rtsiSetSolverName(&ControlSystem_Refactorization_M->solverInfo,"ode3");

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      ControlSystem_Refactorization_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    ControlSystem_Refactorization_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ControlSystem_Refactorization_M->Timing.sampleTimes =
      (&ControlSystem_Refactorization_M->Timing.sampleTimesArray[0]);
    ControlSystem_Refactorization_M->Timing.offsetTimes =
      (&ControlSystem_Refactorization_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ControlSystem_Refactorization_M->Timing.sampleTimes[0] = (0.0);
    ControlSystem_Refactorization_M->Timing.sampleTimes[1] = (0.0001);

    /* task offsets */
    ControlSystem_Refactorization_M->Timing.offsetTimes[0] = (0.0);
    ControlSystem_Refactorization_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(ControlSystem_Refactorization_M,
             &ControlSystem_Refactorization_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      ControlSystem_Refactorization_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    ControlSystem_Refactorization_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ControlSystem_Refactorization_M, -1);
  ControlSystem_Refactorization_M->Timing.stepSize0 = 0.0001;
  ControlSystem_Refactorization_M->Timing.stepSize1 = 0.0001;

  /* External mode info */
  ControlSystem_Refactorization_M->Sizes.checksums[0] = (2668591595U);
  ControlSystem_Refactorization_M->Sizes.checksums[1] = (3414525608U);
  ControlSystem_Refactorization_M->Sizes.checksums[2] = (2594676355U);
  ControlSystem_Refactorization_M->Sizes.checksums[3] = (3369075016U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[32];
    ControlSystem_Refactorization_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.DAQ_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.DAQ_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.DAQ_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.DAQ_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.DAQ_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
      CurvaturaActuador5.CurvaturaActuador5_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
      CurvaturaActuador4.CurvaturaActuador5_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
      CurvaturaActuador3.CurvaturaActuador5_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
      CurvaturaActuador2.CurvaturaActuador5_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
      CurvaturaActuador1.CurvaturaActuador5_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.ControldeCurvatura_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.ControldeCurvatura_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.ControldePresin_SubsysRanBC;
    systemRan[29] = &rtAlwaysEnabled;
    systemRan[30] = &rtAlwaysEnabled;
    systemRan[31] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ControlSystem_Refactorization_M->extModeInfo,
      &ControlSystem_Refactorization_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ControlSystem_Refactorization_M->extModeInfo,
                        ControlSystem_Refactorization_M->Sizes.checksums);
    rteiSetTPtr(ControlSystem_Refactorization_M->extModeInfo, rtmGetTPtr
                (ControlSystem_Refactorization_M));
  }

  ControlSystem_Refactorization_M->solverInfoPtr =
    (&ControlSystem_Refactorization_M->solverInfo);
  ControlSystem_Refactorization_M->Timing.stepSize = (0.0001);
  rtsiSetFixedStepSize(&ControlSystem_Refactorization_M->solverInfo, 0.0001);
  rtsiSetSolverMode(&ControlSystem_Refactorization_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  ControlSystem_Refactorization_M->blockIO = ((void *)
    &ControlSystem_Refactorization_B);
  (void) memset(((void *) &ControlSystem_Refactorization_B), 0,
                sizeof(B_ControlSystem_Refactorization_T));

  {
    ControlSystem_Refactorization_B.DataStoreRead3[0] =
      ControlSystem_Refactorization_rtZslBusActuador;
    ControlSystem_Refactorization_B.DataStoreRead3[1] =
      ControlSystem_Refactorization_rtZslBusActuador;
    ControlSystem_Refactorization_B.DataStoreRead3[2] =
      ControlSystem_Refactorization_rtZslBusActuador;
    ControlSystem_Refactorization_B.DataStoreRead3[3] =
      ControlSystem_Refactorization_rtZslBusActuador;
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[0]
      = ControlSystem_Refactorization_rtZslBusActuador;
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[1]
      = ControlSystem_Refactorization_rtZslBusActuador;
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[2]
      = ControlSystem_Refactorization_rtZslBusActuador;
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[3]
      = ControlSystem_Refactorization_rtZslBusActuador;
    ControlSystem_Refactorization_B.modoControl = ModoControl_Manual;
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Actuadoresposicionados_at_inport_0
      [0] = ActuadorPosicionado_Desposicionado;
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Actuadoresposicionados_at_inport_0
      [1] = ActuadorPosicionado_Desposicionado;
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Actuadoresposicionados_at_inport_0
      [2] = ActuadorPosicionado_Desposicionado;
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Actuadoresposicionados_at_inport_0
      [3] = ActuadorPosicionado_Desposicionado;
  }

  /* parameters */
  ControlSystem_Refactorization_M->defaultParam = ((real_T *)
    &ControlSystem_Refactorization_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &ControlSystem_Refactorization_X;
    ControlSystem_Refactorization_M->contStates = (x);
    (void) memset((void *)&ControlSystem_Refactorization_X, 0,
                  sizeof(X_ControlSystem_Refactorization_T));
  }

  /* disabled states */
  {
    boolean_T *xdis = (boolean_T *) &ControlSystem_Refactorization_XDis;
    ControlSystem_Refactorization_M->contStateDisabled = (xdis);
    (void) memset((void *)&ControlSystem_Refactorization_XDis, 0,
                  sizeof(XDis_ControlSystem_Refactorization_T));
  }

  /* states (dwork) */
  ControlSystem_Refactorization_M->dwork = ((void *)
    &ControlSystem_Refactorization_DW);
  (void) memset((void *)&ControlSystem_Refactorization_DW, 0,
                sizeof(DW_ControlSystem_Refactorization_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ControlSystem_Refactorization_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 76;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  ControlSystem_Refactorization_M->Sizes.numContStates = (103);/* Number of continuous states */
  ControlSystem_Refactorization_M->Sizes.numPeriodicContStates = (0);
                                      /* Number of periodic continuous states */
  ControlSystem_Refactorization_M->Sizes.numY = (0);/* Number of model outputs */
  ControlSystem_Refactorization_M->Sizes.numU = (0);/* Number of model inputs */
  ControlSystem_Refactorization_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  ControlSystem_Refactorization_M->Sizes.numSampTimes = (2);/* Number of sample times */
  ControlSystem_Refactorization_M->Sizes.numBlocks = (222);/* Number of blocks */
  ControlSystem_Refactorization_M->Sizes.numBlockIO = (59);/* Number of block outputs */
  ControlSystem_Refactorization_M->Sizes.numBlockPrms = (135);/* Sum of parameter "widths" */
  return ControlSystem_Refactorization_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
