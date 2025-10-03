/*
 * ControlSystem_Refactorization.c
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "ControlSystem_Refactorization".
 *
 * Model version              : 2.37
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Fri Oct  3 17:10:35 2025
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
#include "ControlSystem_Refactorization_private.h"
#include <emmintrin.h>
#include <string.h>
#include <math.h>
#include "controlador.h"
#include "act_position.h"
#include "myvalvestates.h"
#include "modo_control.h"
#include "referencia_control.h"
#include "zero_crossing_types.h"
#include "ControlSystem_Refactorization_dt.h"

/* Named constants for MATLAB Function: '<S20>/MATLAB Function' */
#define ControlSystem_Refactorization_CALL_EVENT (-1)

/* options for Simulink Desktop Real-Time board 0 */
static double SLDRTBoardOptions0[] = {
  1.0, 31.0, 0.0, 0.0, 0.0, 0.0, 0.0
};

/* list of Simulink Desktop Real-Time timers */
const int SLDRTTimerCount = 1;
const double SLDRTTimers[2] = {
  0.0001, 0.0,
};

/* list of Simulink Desktop Real-Time boards */
const int SLDRTBoardCount = 1;
const SLDRTBOARD SLDRTBoards[1] = {
  { "National_Instruments/PCIe-6323", 4294967295U, 7, SLDRTBoardOptions0 },
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
      EstadoValvula_Bloquear           /* estadoValvula */
    }                                  /* ControlManual */
  },                                   /* Configuracion */

  {
    {
      EstadoValvula_Bloquear,          /* estadoValvula */
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
static void
  ControlSystem_Refactorization_sequential_autonomousControlLogic_setupImpl
  (sequential_autonomousControlLogic_ControlSystem_Refactorization_T *obj);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (ControlSystem_Refactorization_M->Timing.TaskCounters.TID[2])++;
  if ((ControlSystem_Refactorization_M->Timing.TaskCounters.TID[2]) > 999) {/* Sample time: [0.1s, 0.0s] */
    ControlSystem_Refactorization_M->Timing.TaskCounters.TID[2] = 0;
  }

  ControlSystem_Refactorization_M->Timing.sampleHits[2] =
    (ControlSystem_Refactorization_M->Timing.TaskCounters.TID[2] == 0) ? 1 : 0;
}

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
 *    '<S26>/Curvatura Actuador 5'
 *    '<S26>/Curvatura Actuador 1'
 */
void ControlSystem_Refactorization_CurvaturaActuador5_Init
  (B_CurvaturaActuador5_ControlSystem_Refactorization_T *localB,
   P_CurvaturaActuador5_ControlSystem_Refactorization_T *localP,
   X_CurvaturaActuador5_ControlSystem_Refactorization_T *localX)
{
  int_T is;

  /* InitializeConditions for TransferFcn: '<S37>/Modelo de curvatura del actuador' */
  for (is = 0; is < 5; is++) {
    localX->Modelodecurvaturadelactuador_CSTATE[is] = 0.0;
  }

  /* End of InitializeConditions for TransferFcn: '<S37>/Modelo de curvatura del actuador' */

  /* SystemInitialize for TransferFcn: '<S37>/Modelo de curvatura del actuador' incorporates:
   *  Outport: '<S37>/Out1'
   */
  localB->CurvAct = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S26>/Curvatura Actuador 5'
 *    '<S26>/Curvatura Actuador 1'
 */
void ControlSystem_Refactorization_CurvaturaActuador5_Disable
  (DW_CurvaturaActuador5_ControlSystem_Refactorization_T *localDW)
{
  localDW->CurvaturaActuador5_MODE = false;
}

/*
 * Start for enable system:
 *    '<S26>/Curvatura Actuador 5'
 *    '<S26>/Curvatura Actuador 1'
 */
void ControlSystem_Refactorization_CurvaturaActuador5_Start
  (B_CurvaturaActuador5_ControlSystem_Refactorization_T *localB,
   DW_CurvaturaActuador5_ControlSystem_Refactorization_T *localDW,
   XDis_CurvaturaActuador5_ControlSystem_Refactorization_T *localXdis)
{
  /* SystemInitialize for TransferFcn: '<S37>/Modelo de curvatura del actuador' */
  localB->CurvAct = 0.0;
  localDW->CurvaturaActuador5_MODE = false;
  (void) memset(&(localXdis->Modelodecurvaturadelactuador_CSTATE), 1,
                5*sizeof(boolean_T));
}

/*
 * Outputs for enable system:
 *    '<S26>/Curvatura Actuador 5'
 *    '<S26>/Curvatura Actuador 1'
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

  /* Outputs for Enabled SubSystem: '<S26>/Curvatura Actuador 5' incorporates:
   *  EnablePort: '<S37>/Enable'
   */
  if ((rtmIsMajorTimeStep(ControlSystem_Refactorization_M) &&
       ControlSystem_Refactorization_M->Timing.TaskCounters.TID[1] == 0) &&
      rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo)) {
    if (rtu_Enable) {
      if (!localDW->CurvaturaActuador5_MODE) {
        (void) memset(&(localXdis->Modelodecurvaturadelactuador_CSTATE), 0,
                      5*sizeof(boolean_T));
        localDW->CurvaturaActuador5_MODE = true;
      }
    } else {
      /* Outputs for Enabled SubSystem: '<S7>/Control de Curvatura' incorporates:
       *  EnablePort: '<S41>/Enable'
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
    /* TransferFcn: '<S37>/Modelo de curvatura del actuador' */
    localB->CurvAct = 0.0;

    /* TransferFcn: '<S37>/Modelo de curvatura del actuador' */
    for (ci = 0; ci < 5; ci++) {
      /* TransferFcn: '<S37>/Modelo de curvatura del actuador' */
      localB->CurvAct += localP->Modelodecurvaturadelactuador_C[ci] *
        localX->Modelodecurvaturadelactuador_CSTATE[ci];
    }

    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      srUpdateBC(localDW->CurvaturaActuador5_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S26>/Curvatura Actuador 5' */
}

/*
 * Derivatives for enable system:
 *    '<S26>/Curvatura Actuador 5'
 *    '<S26>/Curvatura Actuador 1'
 */
void ControlSystem_Refactorization_CurvaturaActuador5_Deriv(real_T rtu_In1,
  DW_CurvaturaActuador5_ControlSystem_Refactorization_T *localDW,
  P_CurvaturaActuador5_ControlSystem_Refactorization_T *localP,
  X_CurvaturaActuador5_ControlSystem_Refactorization_T *localX,
  XDot_CurvaturaActuador5_ControlSystem_Refactorization_T *localXdot)
{
  __m128d tmp;
  int_T is;
  if (localDW->CurvaturaActuador5_MODE) {
    /* Derivatives for TransferFcn: '<S37>/Modelo de curvatura del actuador' */
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
    localXdot->Modelodecurvaturadelactuador_CSTATE[0] += rtu_In1;

    /* End of Derivatives for TransferFcn: '<S37>/Modelo de curvatura del actuador' */
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

/*
 * System initialize for enable system:
 *    '<S26>/Curvatura Actuador 4'
 *    '<S26>/Curvatura Actuador 3'
 *    '<S26>/Curvatura Actuador 2'
 */
void ControlSystem_Refactorization_CurvaturaActuador4_Init
  (B_CurvaturaActuador4_ControlSystem_Refactorization_T *localB,
   P_CurvaturaActuador4_ControlSystem_Refactorization_T *localP,
   X_CurvaturaActuador4_ControlSystem_Refactorization_T *localX)
{
  int_T is;

  /* InitializeConditions for TransferFcn: '<S36>/Modelo de curvatura del actuador1' */
  for (is = 0; is < 5; is++) {
    localX->Modelodecurvaturadelactuador1_CSTATE[is] = 0.0;
  }

  /* End of InitializeConditions for TransferFcn: '<S36>/Modelo de curvatura del actuador1' */

  /* SystemInitialize for TransferFcn: '<S36>/Modelo de curvatura del actuador1' incorporates:
   *  Outport: '<S36>/Out1'
   */
  localB->CurvAct = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S26>/Curvatura Actuador 4'
 *    '<S26>/Curvatura Actuador 3'
 *    '<S26>/Curvatura Actuador 2'
 */
void ControlSystem_Refactorization_CurvaturaActuador4_Disable
  (DW_CurvaturaActuador4_ControlSystem_Refactorization_T *localDW)
{
  localDW->CurvaturaActuador4_MODE = false;
}

/*
 * Start for enable system:
 *    '<S26>/Curvatura Actuador 4'
 *    '<S26>/Curvatura Actuador 3'
 *    '<S26>/Curvatura Actuador 2'
 */
void ControlSystem_Refactorization_CurvaturaActuador4_Start
  (B_CurvaturaActuador4_ControlSystem_Refactorization_T *localB,
   DW_CurvaturaActuador4_ControlSystem_Refactorization_T *localDW,
   XDis_CurvaturaActuador4_ControlSystem_Refactorization_T *localXdis)
{
  /* SystemInitialize for TransferFcn: '<S36>/Modelo de curvatura del actuador1' */
  localB->CurvAct = 0.0;
  localDW->CurvaturaActuador4_MODE = false;
  (void) memset(&(localXdis->Modelodecurvaturadelactuador1_CSTATE), 1,
                5*sizeof(boolean_T));
}

/*
 * Outputs for enable system:
 *    '<S26>/Curvatura Actuador 4'
 *    '<S26>/Curvatura Actuador 3'
 *    '<S26>/Curvatura Actuador 2'
 */
void ControlSystem_Refactorization_CurvaturaActuador4
  (RT_MODEL_ControlSystem_Refactorization_T * const
   ControlSystem_Refactorization_M, boolean_T rtu_Enable,
   B_CurvaturaActuador4_ControlSystem_Refactorization_T *localB,
   DW_CurvaturaActuador4_ControlSystem_Refactorization_T *localDW,
   P_CurvaturaActuador4_ControlSystem_Refactorization_T *localP,
   X_CurvaturaActuador4_ControlSystem_Refactorization_T *localX,
   XDis_CurvaturaActuador4_ControlSystem_Refactorization_T *localXdis)
{
  int_T ci;

  /* Outputs for Enabled SubSystem: '<S26>/Curvatura Actuador 4' incorporates:
   *  EnablePort: '<S36>/Enable'
   */
  if ((rtmIsMajorTimeStep(ControlSystem_Refactorization_M) &&
       ControlSystem_Refactorization_M->Timing.TaskCounters.TID[1] == 0) &&
      rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo)) {
    if (rtu_Enable) {
      if (!localDW->CurvaturaActuador4_MODE) {
        (void) memset(&(localXdis->Modelodecurvaturadelactuador1_CSTATE), 0,
                      5*sizeof(boolean_T));
        localDW->CurvaturaActuador4_MODE = true;
      }
    } else {
      /* Outputs for Enabled SubSystem: '<S7>/Control de Curvatura' incorporates:
       *  EnablePort: '<S41>/Enable'
       */
      if (ControlSystem_Refactorization_M->Timing.t[1] == rtmGetTStart
          (ControlSystem_Refactorization_M)) {
        (void) memset(&(localXdis->Modelodecurvaturadelactuador1_CSTATE), 1,
                      5*sizeof(boolean_T));
      }

      /* End of Outputs for SubSystem: '<S7>/Control de Curvatura' */
      if (localDW->CurvaturaActuador4_MODE) {
        (void) memset(&(localXdis->Modelodecurvaturadelactuador1_CSTATE), 1,
                      5*sizeof(boolean_T));
        ControlSystem_Refactorization_CurvaturaActuador4_Disable(localDW);
      }
    }
  }

  if (localDW->CurvaturaActuador4_MODE) {
    /* TransferFcn: '<S36>/Modelo de curvatura del actuador1' */
    localB->CurvAct = 0.0;

    /* TransferFcn: '<S36>/Modelo de curvatura del actuador1' */
    for (ci = 0; ci < 5; ci++) {
      /* TransferFcn: '<S36>/Modelo de curvatura del actuador1' */
      localB->CurvAct += localP->Modelodecurvaturadelactuador1_C[ci] *
        localX->Modelodecurvaturadelactuador1_CSTATE[ci];
    }

    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      srUpdateBC(localDW->CurvaturaActuador4_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S26>/Curvatura Actuador 4' */
}

/*
 * Derivatives for enable system:
 *    '<S26>/Curvatura Actuador 4'
 *    '<S26>/Curvatura Actuador 3'
 *    '<S26>/Curvatura Actuador 2'
 */
void ControlSystem_Refactorization_CurvaturaActuador4_Deriv(real_T rtu_In1,
  DW_CurvaturaActuador4_ControlSystem_Refactorization_T *localDW,
  P_CurvaturaActuador4_ControlSystem_Refactorization_T *localP,
  X_CurvaturaActuador4_ControlSystem_Refactorization_T *localX,
  XDot_CurvaturaActuador4_ControlSystem_Refactorization_T *localXdot)
{
  __m128d tmp;
  int_T is;
  if (localDW->CurvaturaActuador4_MODE) {
    /* Derivatives for TransferFcn: '<S36>/Modelo de curvatura del actuador1' */
    for (is = 0; is < 5; is++) {
      localXdot->Modelodecurvaturadelactuador1_CSTATE[is] = 0.0;
      localXdot->Modelodecurvaturadelactuador1_CSTATE[0] +=
        localP->Modelodecurvaturadelactuador1_A[is] *
        localX->Modelodecurvaturadelactuador1_CSTATE[is];
    }

    tmp = _mm_add_pd(_mm_loadu_pd(&localX->Modelodecurvaturadelactuador1_CSTATE
      [0]), _mm_loadu_pd(&localXdot->Modelodecurvaturadelactuador1_CSTATE[1]));
    _mm_storeu_pd(&localXdot->Modelodecurvaturadelactuador1_CSTATE[1], tmp);
    tmp = _mm_add_pd(_mm_loadu_pd(&localX->Modelodecurvaturadelactuador1_CSTATE
      [2]), _mm_loadu_pd(&localXdot->Modelodecurvaturadelactuador1_CSTATE[3]));
    _mm_storeu_pd(&localXdot->Modelodecurvaturadelactuador1_CSTATE[3], tmp);
    localXdot->Modelodecurvaturadelactuador1_CSTATE[0] += rtu_In1;

    /* End of Derivatives for TransferFcn: '<S36>/Modelo de curvatura del actuador1' */
  } else {
    {
      real_T *dx;
      int_T i1;
      dx = &(localXdot->Modelodecurvaturadelactuador1_CSTATE[0]);
      for (i1=0; i1 < 5; i1++) {
        dx[i1] = 0.0;
      }
    }
  }
}

static void
  ControlSystem_Refactorization_sequential_autonomousControlLogic_setupImpl
  (sequential_autonomousControlLogic_ControlSystem_Refactorization_T *obj)
{
  /*  Perform one-time calculations, such as computing constants */
  obj->controlHabilitado = false;

  /*  Registra si esta lógica de control se encuentra actualmente activa */
  /* obj.numAct = length(actuadorBus); */
  obj->modoControl = ModoControl_Manual;
  obj->parametroControl = ParametroControl_Presion;
  obj->actuadorSeleccionado = 0.0;
  obj->realimentaciones.presionRegulador = 0.0;
  obj->tolerancias.estacionaria = 0.0;
  obj->tolerancias.derivativa = 0.0;
  obj->tolerancias.equilibrioPresiones = 0.0;
  obj->errorControl.estacionario = 0.0;
  obj->errorControl.derivativo = 0.0;
  obj->referencias[0] = 0.0;
  obj->realimentaciones.presionesEquilibrio[0] = 0.0;
  obj->realimentaciones.actuador[0] = 0.0;
  obj->errores[0] = 0.0;
  obj->actuadoresActivos[0] = false;
  obj->estadoValvulas[0] = EstadoValvula_Expulsar;
  obj->referencias[1] = 0.0;
  obj->realimentaciones.presionesEquilibrio[1] = 0.0;
  obj->realimentaciones.actuador[1] = 0.0;
  obj->errores[1] = 0.0;
  obj->actuadoresActivos[1] = false;
  obj->estadoValvulas[1] = EstadoValvula_Expulsar;
  obj->referencias[2] = 0.0;
  obj->realimentaciones.presionesEquilibrio[2] = 0.0;
  obj->realimentaciones.actuador[2] = 0.0;
  obj->errores[2] = 0.0;
  obj->actuadoresActivos[2] = false;
  obj->estadoValvulas[2] = EstadoValvula_Expulsar;
  obj->referencias[3] = 0.0;
  obj->realimentaciones.presionesEquilibrio[3] = 0.0;
  obj->realimentaciones.actuador[3] = 0.0;
  obj->errores[3] = 0.0;
  obj->actuadoresActivos[3] = false;
  obj->estadoValvulas[3] = EstadoValvula_Expulsar;
}

/* Model output function */
void ControlSystem_Refactorization_output(void)
{
  /* local block i/o variables */
  real_T rtb_Tensin;
  real_T rtb_Tensin_g[4];

  /* local scratch DWork variables */
  int32_T ForEach_itr;
  int32_T ForEach_itr_d;
  int32_T ForEach_itr_h;
  int32_T ForEach_itr_n;
  int32_T ForEach_itr_e;
  int32_T ForEach_itr_no;
  __m128d tmp_1;
  XDis_ControlSystem_Refactorization_T *_rtXdis;
  slBusActuador rtb_ImpAsg_InsertedFor_Out1_at_inport_0[4];
  slBusActuador rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[4];
  slBusElectroValvulas rtb_DataStoreRead6;
  real_T rtb_CurvaturaActuadores[4];
  real_T rtb_PresinActuadores[4];
  real_T actError;
  real_T b_varargout_4;
  real_T b_varargout_5;
  real_T lastTime;
  real_T maxError;
  real_T rtb_DataStoreRead4_Configuracion_Global_numActuadores;
  real_T rtb_DataStoreRead4_Estado_ControlAutomatico_actuadorSeleccionado;
  real_T rtb_Derivative;
  real_T rtb_sistema_Configuracion_ControlManual_actuadorSeleccionado;
  real_T rtb_sistema_Configuracion_Global_ToleranciaCurvatura_derivativa;
  real_T rtb_sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria;
  real_T rtb_sistema_Configuracion_Global_ToleranciaPresion_derivativa;
  real_T rtb_sistema_Estado_Global_realimentacionControl;
  real_T u0;
  real_T *lastU;
  int32_T tmp_data[4];
  int32_T b_k;
  int32_T i;
  int32_T trueCount;
  int32_T trueCount_0;
  uint16_T electroValvulas_Configuracion;
  ActuadorPosicionado tmp[4];
  Controlador b_controlador;
  Controlador rtb_Controladoractivo_i;
  EstadoValvula estadoValvulas_Bloqueo[4];
  EstadoValvula estadoValvulas_Control[4];
  EstadoValvula rtb_EstadodelaselectrovlvulasControlautnomo[4];
  EstadoValvula estadoActuador;
  EstadoValvula
    rtb_ImpSel_InsertedFor_Actuador_at_outport_0_Configuracion_ControlManual_estadoValvula;
  ModoControl rtb_sistema_Configuracion_Global_modoControl;
  ParametroControl rtb_sistema_Configuracion_Global_parametroControl;
  boolean_T actuadoresNoSeleccionados[4];
  boolean_T didZcEventOccur;
  boolean_T exitg1;
  boolean_T rtb_Compare_b;
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
  tmp_0 = (rtmIsMajorTimeStep(ControlSystem_Refactorization_M) &&
           ControlSystem_Refactorization_M->Timing.TaskCounters.TID[1] == 0);
  if (tmp_0) {
    /* SignalConversion generated from: '<S1>/For Each Subsystem' incorporates:
     *  Constant: '<S17>/RefPresion1'
     *  Constant: '<S17>/RefPresion2'
     *  Constant: '<S17>/RefPresion3'
     *  Constant: '<S17>/RefPresion4'
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
     *  Constant: '<S17>/RefCurvatura1'
     *  Constant: '<S17>/RefCurvatura2'
     *  Constant: '<S17>/RefCurvatura3'
     *  Constant: '<S17>/RefCurvatura4'
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
     *  Constant: '<S17>/EstadoValvula1'
     *  Constant: '<S17>/EstadoValvula2'
     *  Constant: '<S17>/EstadoValvula3'
     *  Constant: '<S17>/EstadoValvula4'
     */
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      0] = ControlSystem_Refactorization_P.EstadoValvula1_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      1] = ControlSystem_Refactorization_P.EstadoValvula2_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      2] = ControlSystem_Refactorization_P.EstadoValvula3_Value;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      3] = ControlSystem_Refactorization_P.EstadoValvula4_Value;

    /* SignalConversion generated from: '<S1>/For Each Subsystem' incorporates:
     *  Constant: '<S17>/ActuadorActivo1'
     *  Constant: '<S17>/ActuadorActivo2'
     *  Constant: '<S17>/ActuadorActivo3'
     *  Constant: '<S17>/ActuadorActivo4'
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
   *  ForEach: '<S18>/For Each'
   */
  for (ForEach_itr_no = 0; ForEach_itr_no < 4; ForEach_itr_no++) {
    /* ForEachSliceAssignment generated from: '<S18>/Out1' incorporates:
     *  BusAssignment: '<S18>/Bus Assignment3'
     *  DataStoreRead: '<Root>/Data Store Read3'
     *  ForEachSliceSelector generated from: '<S18>/Actuadores activos - Control autónomo'
     *  ForEachSliceSelector generated from: '<S18>/Bus'
     *  ForEachSliceSelector generated from: '<S18>/Estado válvulas - Control manual'
     *  ForEachSliceSelector generated from: '<S18>/Referencias de curvatura'
     *  ForEachSliceSelector generated from: '<S18>/Referencias de presión'
     */
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_no].
      Configuracion.Global.activo =
      ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport5
      [ForEach_itr_no];
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_no].
      Configuracion.Global.indice =
      ControlSystem_Refactorization_B.DataStoreRead3[ForEach_itr_no].
      Configuracion.Global.indice;
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_no].
      Configuracion.Global.Referencia.presion =
      ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport2
      [ForEach_itr_no];
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_no].
      Configuracion.Global.Referencia.curvatura =
      ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport3
      [ForEach_itr_no];
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_no].
      Configuracion.ControlManual.estadoValvula =
      ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4
      [ForEach_itr_no];
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_no].Estado =
      ControlSystem_Refactorization_B.DataStoreRead3[ForEach_itr_no].Estado;
  }

  /* End of Outputs for SubSystem: '<S1>/For Each Subsystem' */

  /* DataStoreRead: '<Root>/Data Store Read4' */
  rtb_DataStoreRead4_Configuracion_Global_numActuadores =
    ControlSystem_Refactorization_DW.sistema.Configuracion.Global.numActuadores;
  rtb_DataStoreRead4_Estado_ControlAutomatico_actuadorSeleccionado =
    ControlSystem_Refactorization_DW.sistema.Estado.ControlAutomatico.actuadorSeleccionado;

  /* MATLABSystem: '<S6>/ManualControlLogic' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S19>/Constant4'
   *  DataStoreRead: '<Root>/Data Store Read5'
   *  ForEachSliceAssignment generated from: '<S18>/Out1'
   */
  /*  1. INICIALIZACIÓN DE VARIABLES */
  /*  2. INICIALIZACIÓN DE SALIDAS */
  rtb_Controladoractivo_i = Controlador_Presion;

  /*  1. No hay ningún actuador seleccionado o el modo de control */
  /*  manual está deshabilitado */
  rtb_Compare_b = (ControlSystem_Refactorization_P.Constant4_Value == 0.0);
  if (rtb_Compare_b || (rtb_Compare_b ||
                        (ControlSystem_Refactorization_P.Constant_Value !=
                         ModoControl_Manual))) {
    b_varargout_5 = ControlSystem_Refactorization_DW.regulador.Estado.presion;
    b_varargout_4 = ControlSystem_Refactorization_DW.regulador.Estado.presion;
  } else {
    /*  2. Se escogen las señales en función del actuador */
    /*  seleccionado y del parámetro de control activo */
    switch (ControlSystem_Refactorization_P.Constant1_Value) {
     case ParametroControl_Presion:
      rtb_Controladoractivo_i = Controlador_Presion;
      b_varargout_5 = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[(int32_T)
        ControlSystem_Refactorization_P.Constant4_Value - 1].
        Configuracion.Global.Referencia.presion;
      b_varargout_4 = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[(int32_T)
        ControlSystem_Refactorization_P.Constant4_Value - 1].
        Estado.Realimentacion.presion;
      break;

     case ParametroControl_Curvatura:
      rtb_Controladoractivo_i = Controlador_Curvatura;
      b_varargout_5 = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[(int32_T)
        ControlSystem_Refactorization_P.Constant4_Value - 1].
        Configuracion.Global.Referencia.curvatura;
      b_varargout_4 = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[(int32_T)
        ControlSystem_Refactorization_P.Constant4_Value - 1].
        Estado.Realimentacion.curvatura;
      break;
    }
  }

  /* MATLABSystem: '<S6>/SequentialAutonomousControlLogic' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S19>/Constant5'
   *  Constant: '<S19>/Constant6'
   *  Constant: '<S19>/Constant7'
   *  Constant: '<S19>/Constant8'
   *  Constant: '<S19>/Constant9'
   *  DataStoreRead: '<Root>/Data Store Read4'
   *  DataStoreRead: '<Root>/Data Store Read5'
   *  ForEachSliceAssignment generated from: '<S18>/Out1'
   */
  /*  1. REINICIO DE ESTADO */
  /*  Se reinicia el actuador seleccionado al deshabilitar esta */
  /*  lógica de control o cambiar el parámetro de control */
  if ((!ControlSystem_Refactorization_DW.obj.controlHabilitado) ||
      (ControlSystem_Refactorization_P.Constant1_Value !=
       ControlSystem_Refactorization_DW.obj.parametroControl)) {
    ControlSystem_Refactorization_DW.obj.controlHabilitado = true;
    ControlSystem_Refactorization_DW.obj.actuadorSeleccionado = 0.0;
  }

  /*  2. INICIALIZACIÓN DE VARIABLES */
  /*  Registra el estado actual del sistema de control */
  ControlSystem_Refactorization_DW.obj.parametroControl =
    ControlSystem_Refactorization_P.Constant1_Value;
  if (ControlSystem_Refactorization_DW.obj.parametroControl ==
      ParametroControl_Presion) {
    ControlSystem_Refactorization_DW.obj.referencias[0] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].
      Configuracion.Global.Referencia.presion;
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[0] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].Estado.Realimentacion.presion;
    ControlSystem_Refactorization_DW.obj.referencias[1] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].
      Configuracion.Global.Referencia.presion;
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[1] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].Estado.Realimentacion.presion;
    ControlSystem_Refactorization_DW.obj.referencias[2] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].
      Configuracion.Global.Referencia.presion;
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[2] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].Estado.Realimentacion.presion;
    ControlSystem_Refactorization_DW.obj.referencias[3] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].
      Configuracion.Global.Referencia.presion;
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[3] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].Estado.Realimentacion.presion;
    ControlSystem_Refactorization_DW.obj.tolerancias.estacionaria =
      ControlSystem_Refactorization_P.Constant5_Value;
    ControlSystem_Refactorization_DW.obj.tolerancias.derivativa =
      ControlSystem_Refactorization_P.Constant6_Value;
    b_controlador = Controlador_Presion;
  } else {
    ControlSystem_Refactorization_DW.obj.referencias[0] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].
      Configuracion.Global.Referencia.curvatura;
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[0] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].Estado.Realimentacion.curvatura;
    ControlSystem_Refactorization_DW.obj.referencias[1] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].
      Configuracion.Global.Referencia.curvatura;
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[1] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].Estado.Realimentacion.curvatura;
    ControlSystem_Refactorization_DW.obj.referencias[2] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].
      Configuracion.Global.Referencia.curvatura;
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[2] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].Estado.Realimentacion.curvatura;
    ControlSystem_Refactorization_DW.obj.referencias[3] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].
      Configuracion.Global.Referencia.curvatura;
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[3] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].Estado.Realimentacion.curvatura;
    ControlSystem_Refactorization_DW.obj.tolerancias.estacionaria =
      ControlSystem_Refactorization_P.Constant7_Value;
    ControlSystem_Refactorization_DW.obj.tolerancias.derivativa =
      ControlSystem_Refactorization_P.Constant8_Value;
    b_controlador = Controlador_Curvatura;
  }

  ControlSystem_Refactorization_DW.obj.modoControl =
    ControlSystem_Refactorization_P.Constant_Value;
  ControlSystem_Refactorization_DW.obj.realimentaciones.presionRegulador =
    ControlSystem_Refactorization_DW.regulador.Estado.presion;
  ControlSystem_Refactorization_DW.obj.tolerancias.equilibrioPresiones =
    ControlSystem_Refactorization_P.Constant9_Value;
  ControlSystem_Refactorization_DW.obj.errorControl.estacionario =
    ControlSystem_Refactorization_DW.sistema.Estado.Global.errorEstacionario;
  ControlSystem_Refactorization_DW.obj.errorControl.derivativo =
    ControlSystem_Refactorization_DW.sistema.Estado.Global.errorDerivativo;

  /*  3. INICIALIZACIÓN DE SALIDAS */
  rtb_Derivative =
    ControlSystem_Refactorization_DW.sistema.Estado.Global.realimentacionControl;
  maxError =
    ControlSystem_Refactorization_DW.sistema.Configuracion.Global.referenciaControl;
  ControlSystem_Refactorization_DW.obj.realimentaciones.presionesEquilibrio[0] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].Estado.Realimentacion.presion;
  ControlSystem_Refactorization_DW.obj.actuadoresActivos[0] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].Configuracion.Global.activo;
  ControlSystem_Refactorization_DW.obj.errores[0] =
    ControlSystem_Refactorization_DW.obj.referencias[0] -
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[0];
  ControlSystem_Refactorization_DW.obj.estadoValvulas[0] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].
    Estado.ControlAutomatico.estadoValvula;
  tmp[0] = ActuadorPosicionado_Desposicionado;

  /* Start for MATLABSystem: '<S6>/SequentialAutonomousControlLogic' incorporates:
   *  ForEachSliceAssignment generated from: '<S18>/Out1'
   */
  estadoValvulas_Bloqueo[0] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].
    Estado.ControlAutomatico.estadoValvula;

  /* MATLABSystem: '<S6>/SequentialAutonomousControlLogic' incorporates:
   *  ForEachSliceAssignment generated from: '<S18>/Out1'
   */
  ControlSystem_Refactorization_DW.obj.realimentaciones.presionesEquilibrio[1] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].Estado.Realimentacion.presion;
  ControlSystem_Refactorization_DW.obj.actuadoresActivos[1] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].Configuracion.Global.activo;
  ControlSystem_Refactorization_DW.obj.errores[1] =
    ControlSystem_Refactorization_DW.obj.referencias[1] -
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[1];
  ControlSystem_Refactorization_DW.obj.estadoValvulas[1] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].
    Estado.ControlAutomatico.estadoValvula;
  tmp[1] = ActuadorPosicionado_Desposicionado;

  /* Start for MATLABSystem: '<S6>/SequentialAutonomousControlLogic' incorporates:
   *  ForEachSliceAssignment generated from: '<S18>/Out1'
   */
  estadoValvulas_Bloqueo[1] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].
    Estado.ControlAutomatico.estadoValvula;

  /* MATLABSystem: '<S6>/SequentialAutonomousControlLogic' incorporates:
   *  ForEachSliceAssignment generated from: '<S18>/Out1'
   */
  ControlSystem_Refactorization_DW.obj.realimentaciones.presionesEquilibrio[2] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].Estado.Realimentacion.presion;
  ControlSystem_Refactorization_DW.obj.actuadoresActivos[2] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].Configuracion.Global.activo;
  ControlSystem_Refactorization_DW.obj.errores[2] =
    ControlSystem_Refactorization_DW.obj.referencias[2] -
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[2];
  ControlSystem_Refactorization_DW.obj.estadoValvulas[2] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].
    Estado.ControlAutomatico.estadoValvula;
  tmp[2] = ActuadorPosicionado_Desposicionado;

  /* Start for MATLABSystem: '<S6>/SequentialAutonomousControlLogic' incorporates:
   *  ForEachSliceAssignment generated from: '<S18>/Out1'
   */
  estadoValvulas_Bloqueo[2] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].
    Estado.ControlAutomatico.estadoValvula;

  /* MATLABSystem: '<S6>/SequentialAutonomousControlLogic' incorporates:
   *  ForEachSliceAssignment generated from: '<S18>/Out1'
   */
  ControlSystem_Refactorization_DW.obj.realimentaciones.presionesEquilibrio[3] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].Estado.Realimentacion.presion;
  ControlSystem_Refactorization_DW.obj.actuadoresActivos[3] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].Configuracion.Global.activo;
  ControlSystem_Refactorization_DW.obj.errores[3] =
    ControlSystem_Refactorization_DW.obj.referencias[3] -
    ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[3];
  ControlSystem_Refactorization_DW.obj.estadoValvulas[3] =
    rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].
    Estado.ControlAutomatico.estadoValvula;
  tmp[3] = ActuadorPosicionado_Desposicionado;

  /* Start for MATLABSystem: '<S6>/SequentialAutonomousControlLogic' incorporates:
   *  ForEachSliceAssignment generated from: '<S18>/Out1'
   */
  estadoValvulas_Bloqueo[3] = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].
    Estado.ControlAutomatico.estadoValvula;

  /* MATLABSystem: '<S6>/SequentialAutonomousControlLogic' */
  /*  4. FINALIZAR EJECUCIÓN SI LÓGICA DESHABILITADA */
  /*  La ejecución termina directamente si esta lógica de control */
  /*  está deshabilitada, para no consumir recursos */
  if (ControlSystem_Refactorization_DW.obj.modoControl !=
      ModoControl_Autonomo_Secuencial) {
    ControlSystem_Refactorization_DW.obj.controlHabilitado = false;
  } else {
    /*  5. LÓGICA DE CONTROL */
    /*  5.1 Se comprueba el posicionamiento actual de los actuadores */
    /*  Verifica si los actuadores están posicionados o */
    /*  desposicionados */
    /*  Comprueba si los actuadores se encuentran posicionados o desposicionados */
    for (b_k = 0; b_k < 4; b_k++) {
      /*  1. Actuador desactivado */
      if (!ControlSystem_Refactorization_DW.obj.actuadoresActivos[b_k]) {
        tmp[b_k] = ActuadorPosicionado_Control_Manual;

        /*  2. Actuador seleccionado como referencia para control */
      } else if (((real_T)b_k + 1.0 ==
                  ControlSystem_Refactorization_DW.obj.actuadorSeleccionado) &&
                 (fabs
                  (ControlSystem_Refactorization_DW.obj.errorControl.estacionario)
                  <=
                  ControlSystem_Refactorization_DW.obj.tolerancias.estacionaria)
                 && (fabs
                     (ControlSystem_Refactorization_DW.obj.errorControl.derivativo)
                     <=
                     ControlSystem_Refactorization_DW.obj.tolerancias.derivativa))
      {
        tmp[b_k] = ActuadorPosicionado_Posicionado;
        ControlSystem_Refactorization_DW.obj.actuadorSeleccionado = 0.0;
      } else if (!((real_T)b_k + 1.0 ==
                   ControlSystem_Refactorization_DW.obj.actuadorSeleccionado)) {
        /*  3. Actuador previamente posicionado */
        if (fabs(ControlSystem_Refactorization_DW.obj.errores[b_k]) >
            ControlSystem_Refactorization_DW.obj.tolerancias.estacionaria) {
          tmp[b_k] = ActuadorPosicionado_Desposicionado;

          /*  4. Actuador previamente desposicionado */
        } else if (fabs(ControlSystem_Refactorization_DW.obj.errores[b_k]) <=
                   ControlSystem_Refactorization_DW.obj.tolerancias.estacionaria)
        {
          tmp[b_k] = ActuadorPosicionado_Posicionado;
        }
      }
    }

    /*  5.2 Se selecciona el actuador utilizado como referencia para el control */
    /*  Selecciona el actuador a utilizar como referencia de control */
    rtb_Derivative = ControlSystem_Refactorization_DW.obj.actuadorSeleccionado;

    /*  1. Si ya hay un actuador en control, se mantiene como */
    /*  referencia hasta que haya sido posicionado */
    if ((ControlSystem_Refactorization_DW.obj.actuadorSeleccionado != 0.0) &&
        (tmp[(int32_T)ControlSystem_Refactorization_DW.obj.actuadorSeleccionado
         - 1] != ActuadorPosicionado_Posicionado)) {
    } else {
      /*  2. Si todos los actuadores ya están posicionados, no se selecciona */
      /*  ninguno */
      rtb_Compare_b = false;
      b_k = 0;
      exitg1 = false;
      while ((!exitg1) && (b_k < 4)) {
        if (tmp[b_k] == ActuadorPosicionado_Desposicionado) {
          rtb_Compare_b = true;
          exitg1 = true;
        } else {
          b_k++;
        }
      }

      if (!rtb_Compare_b) {
        rtb_Derivative = 0.0;
      } else {
        /*  3. Se selecciona el actuador activo con mayor error estacionario */
        maxError = 0.0;
        actError = fabs(ControlSystem_Refactorization_DW.obj.errores[0]);
        if ((actError > 0.0) &&
            ControlSystem_Refactorization_DW.obj.actuadoresActivos[0]) {
          maxError = actError;
          rtb_Derivative = 1.0;
        }

        actError = fabs(ControlSystem_Refactorization_DW.obj.errores[1]);
        if ((actError > maxError) &&
            ControlSystem_Refactorization_DW.obj.actuadoresActivos[1]) {
          maxError = actError;
          rtb_Derivative = 2.0;
        }

        actError = fabs(ControlSystem_Refactorization_DW.obj.errores[2]);
        if ((actError > maxError) &&
            ControlSystem_Refactorization_DW.obj.actuadoresActivos[2]) {
          maxError = actError;
          rtb_Derivative = 3.0;
        }

        if ((fabs(ControlSystem_Refactorization_DW.obj.errores[3]) > maxError) &&
            ControlSystem_Refactorization_DW.obj.actuadoresActivos[3]) {
          rtb_Derivative = 4.0;
        }
      }
    }

    ControlSystem_Refactorization_DW.obj.actuadorSeleccionado = rtb_Derivative;

    /*  5.3 Se establecen los estados de las electroválvulas */
    /*  Establece la posición de las electroválvulas para el instante */
    /*  actual */
    if (ControlSystem_Refactorization_DW.obj.parametroControl ==
        ParametroControl_Presion) {
      b_controlador = Controlador_Presion;
    } else {
      b_controlador = Controlador_Curvatura;
    }

    /*  INICIALIZACIÓN DE REFERENCIAS */
    /*  1. Referencia de estado para válvulas en posición de bloqueo */
    estadoValvulas_Bloqueo[0] = EstadoValvula_Bloquear;
    estadoValvulas_Bloqueo[1] = EstadoValvula_Bloquear;
    estadoValvulas_Bloqueo[2] = EstadoValvula_Bloquear;
    estadoValvulas_Bloqueo[3] = EstadoValvula_Bloquear;
    for (i = 0; i < 4; i++) {
      if (!ControlSystem_Refactorization_DW.obj.actuadoresActivos[i]) {
        estadoValvulas_Bloqueo[i] = EstadoValvula_Expulsar;
      }
    }

    /*  2. Referencia de estado para válvulas en posición de control */
    /*  activo */
    estadoValvulas_Control[0] = estadoValvulas_Bloqueo[0];
    estadoValvulas_Control[1] = estadoValvulas_Bloqueo[1];
    estadoValvulas_Control[2] = estadoValvulas_Bloqueo[2];
    estadoValvulas_Control[3] = estadoValvulas_Bloqueo[3];
    if (ControlSystem_Refactorization_DW.obj.actuadorSeleccionado != 0.0) {
      estadoValvulas_Control[(int32_T)
        ControlSystem_Refactorization_DW.obj.actuadorSeleccionado - 1] =
        EstadoValvula_Inyectar;
    }

    /*  3. Referencia de actuadores no seleccionados para el control */
    actuadoresNoSeleccionados[0] =
      (ControlSystem_Refactorization_DW.obj.actuadorSeleccionado != 1.0);
    actuadoresNoSeleccionados[1] =
      (ControlSystem_Refactorization_DW.obj.actuadorSeleccionado != 2.0);
    actuadoresNoSeleccionados[2] =
      (ControlSystem_Refactorization_DW.obj.actuadorSeleccionado != 3.0);
    actuadoresNoSeleccionados[3] =
      (ControlSystem_Refactorization_DW.obj.actuadorSeleccionado != 4.0);

    /*  SELECCIÓN DE ESTADO DE ELECTROVÁLVULAS */
    /*  1. Si hay actuadores distintos al seleccionado */
    /*  inyectando aire, o no hay actuadores seleccionados, */
    /*  se cierran todas las válvulas en esta etapa de ejecución */
    rtb_Compare_b = false;
    trueCount = 0;
    for (i = 0; i < 4; i++) {
      if (actuadoresNoSeleccionados[i]) {
        trueCount++;
      }
    }

    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k <= trueCount - 1)) {
      trueCount_0 = 0;
      for (i = 0; i < 4; i++) {
        if (actuadoresNoSeleccionados[i]) {
          tmp_data[trueCount_0] = i;
          trueCount_0++;
        }
      }

      if (ControlSystem_Refactorization_DW.obj.estadoValvulas[tmp_data[b_k]] ==
          EstadoValvula_Inyectar) {
        rtb_Compare_b = true;
        exitg1 = true;
      } else {
        b_k++;
      }
    }

    if ((!rtb_Compare_b) &&
        (!(ControlSystem_Refactorization_DW.obj.actuadorSeleccionado == 0.0))) {
      /*  2. Si todas las válvulas están cerradas, y la presión del */
      /*  regulador es distinta a la del actuador seleccionado, se */
      /*  continúa el proceso de equilibrio de presiones. */
      if ((ControlSystem_Refactorization_DW.obj.estadoValvulas[(int32_T)
           ControlSystem_Refactorization_DW.obj.actuadorSeleccionado - 1] ==
           EstadoValvula_Bloquear) && (fabs
           (ControlSystem_Refactorization_DW.obj.realimentaciones.presionesEquilibrio
            [(int32_T)ControlSystem_Refactorization_DW.obj.actuadorSeleccionado
            - 1] -
            ControlSystem_Refactorization_DW.obj.realimentaciones.presionRegulador)
           >
           ControlSystem_Refactorization_DW.obj.tolerancias.equilibrioPresiones))
      {
        b_controlador = Controlador_EquilibrioPresiones;
      } else {
        /*  3. En otro caso, se continúa con el control del actuador */
        estadoValvulas_Bloqueo[0] = estadoValvulas_Control[0];
        estadoValvulas_Bloqueo[1] = estadoValvulas_Control[1];
        estadoValvulas_Bloqueo[2] = estadoValvulas_Control[2];
        estadoValvulas_Bloqueo[3] = estadoValvulas_Control[3];
      }
    }

    /*  5.4 Se definen las señales de control */
    /*  Selecciona las señales de control para realimentación y */
    /*  referencia, según el estado del sistema */
    /*  1. No hay actuadores seleccionados */
    if (ControlSystem_Refactorization_DW.obj.actuadorSeleccionado == 0.0) {
      rtb_Derivative =
        ControlSystem_Refactorization_DW.obj.realimentaciones.presionRegulador;
      maxError =
        ControlSystem_Refactorization_DW.obj.realimentaciones.presionRegulador;

      /*  2. Equilibrio de presiones */
    } else if (b_controlador == Controlador_EquilibrioPresiones) {
      rtb_Derivative =
        ControlSystem_Refactorization_DW.obj.realimentaciones.presionRegulador;
      maxError =
        ControlSystem_Refactorization_DW.obj.realimentaciones.presionesEquilibrio
        [(int32_T)ControlSystem_Refactorization_DW.obj.actuadorSeleccionado - 1];
    } else {
      /*  3. Control del actuador */
      rtb_Derivative =
        ControlSystem_Refactorization_DW.obj.realimentaciones.actuador[(int32_T)
        ControlSystem_Refactorization_DW.obj.actuadorSeleccionado - 1];
      maxError = ControlSystem_Refactorization_DW.obj.referencias[(int32_T)
        ControlSystem_Refactorization_DW.obj.actuadorSeleccionado - 1];
    }
  }

  /* MultiPortSwitch generated from: '<S6>/Index Vector1' incorporates:
   *  Constant: '<S19>/Constant'
   *  ForEachSliceAssignment generated from: '<S18>/Out1'
   *  MATLABSystem: '<S6>/ManualControlLogic'
   *  MATLABSystem: '<S6>/SequentialAutonomousControlLogic'
   * */
  if (ControlSystem_Refactorization_P.Constant_Value == ModoControl_Manual) {
    estadoValvulas_Control[0] = 2U;
    rtb_EstadodelaselectrovlvulasControlautnomo[0] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[0].
      Estado.ControlAutomatico.estadoValvula;
    estadoValvulas_Control[1] = 2U;
    rtb_EstadodelaselectrovlvulasControlautnomo[1] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[1].
      Estado.ControlAutomatico.estadoValvula;
    estadoValvulas_Control[2] = 2U;
    rtb_EstadodelaselectrovlvulasControlautnomo[2] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[2].
      Estado.ControlAutomatico.estadoValvula;
    estadoValvulas_Control[3] = 2U;
    rtb_EstadodelaselectrovlvulasControlautnomo[3] =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[3].
      Estado.ControlAutomatico.estadoValvula;
  } else {
    estadoValvulas_Control[0] = tmp[0];
    rtb_EstadodelaselectrovlvulasControlautnomo[0] = estadoValvulas_Bloqueo[0];
    estadoValvulas_Control[1] = tmp[1];
    rtb_EstadodelaselectrovlvulasControlautnomo[1] = estadoValvulas_Bloqueo[1];
    estadoValvulas_Control[2] = tmp[2];
    rtb_EstadodelaselectrovlvulasControlautnomo[2] = estadoValvulas_Bloqueo[2];
    estadoValvulas_Control[3] = tmp[3];
    rtb_EstadodelaselectrovlvulasControlautnomo[3] = estadoValvulas_Bloqueo[3];
  }

  /* Outputs for Iterator SubSystem: '<Root>/For Each Subsystem4' incorporates:
   *  ForEach: '<S3>/For Each'
   */
  for (ForEach_itr_e = 0; ForEach_itr_e < 4; ForEach_itr_e++) {
    /* ForEachSliceAssignment generated from: '<S3>/actuadores' incorporates:
     *  BusAssignment: '<S3>/Bus Assignment'
     *  ForEachSliceAssignment generated from: '<S18>/Out1'
     *  ForEachSliceSelector generated from: '<S3>/actuadorBus'
     *  ForEachSliceSelector generated from: '<S3>/actuadoresPosicionados'
     *  ForEachSliceSelector generated from: '<S3>/estadoElectrovalvulas_controlAutonomo'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_e]
      .Configuracion = rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_e].
      Configuracion;
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_e]
      .Estado.ControlAutomatico.estadoValvula =
      rtb_EstadodelaselectrovlvulasControlautnomo[ForEach_itr_e];
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_e]
      .Estado.ControlAutomatico.actuadorPosicionado =
      estadoValvulas_Control[ForEach_itr_e];
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr_e]
      .Estado.Realimentacion =
      rtb_ImpAsg_InsertedFor_Out1_at_inport_0[ForEach_itr_e].
      Estado.Realimentacion;
  }

  /* End of Outputs for SubSystem: '<Root>/For Each Subsystem4' */

  /* MultiPortSwitch generated from: '<S6>/Index Vector1' incorporates:
   *  Constant: '<S19>/Constant'
   *  MATLABSystem: '<S6>/ManualControlLogic'
   *  MATLABSystem: '<S6>/SequentialAutonomousControlLogic'
   * */
  if (ControlSystem_Refactorization_P.Constant_Value == ModoControl_Manual) {
    rtb_Derivative = b_varargout_4;
    maxError = b_varargout_5;
  } else {
    rtb_Controladoractivo_i = b_controlador;
  }

  /* BusAssignment: '<Root>/Bus Assignment' incorporates:
   *  Constant: '<S19>/Constant'
   *  Constant: '<S19>/Constant1'
   *  Constant: '<S19>/Constant2'
   *  Constant: '<S19>/Constant4'
   *  Constant: '<S19>/Constant5'
   *  Constant: '<S19>/Constant6'
   *  Constant: '<S19>/Constant7'
   *  Constant: '<S19>/Constant8'
   *  Constant: '<S19>/Constant9'
   */
  rtb_sistema_Configuracion_Global_modoControl =
    ControlSystem_Refactorization_P.Constant_Value;
  rtb_sistema_Configuracion_Global_parametroControl =
    ControlSystem_Refactorization_P.Constant1_Value;
  b_varargout_5 = ControlSystem_Refactorization_P.Constant2_Value;
  b_varargout_4 = ControlSystem_Refactorization_P.Constant9_Value;
  actError = ControlSystem_Refactorization_P.Constant5_Value;
  rtb_sistema_Configuracion_Global_ToleranciaPresion_derivativa =
    ControlSystem_Refactorization_P.Constant6_Value;
  rtb_sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria =
    ControlSystem_Refactorization_P.Constant7_Value;
  rtb_sistema_Configuracion_Global_ToleranciaCurvatura_derivativa =
    ControlSystem_Refactorization_P.Constant8_Value;
  rtb_sistema_Configuracion_ControlManual_actuadorSeleccionado =
    ControlSystem_Refactorization_P.Constant4_Value;
  rtb_sistema_Estado_Global_realimentacionControl = rtb_Derivative;

  /* Logic: '<S7>/OR' incorporates:
   *  Constant: '<S39>/Constant'
   *  Constant: '<S40>/Constant'
   *  RelationalOperator: '<S39>/Compare'
   *  RelationalOperator: '<S40>/Compare'
   */
  ControlSystem_Refactorization_B.OR = ((rtb_Controladoractivo_i ==
    ControlSystem_Refactorization_P.CompareToConstant1_const) ||
    (rtb_Controladoractivo_i ==
     ControlSystem_Refactorization_P.CompareToConstant2_const));
  if (tmp_0) {
    /* SignalConversion generated from: '<S42>/Enable' */
    ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_ControldePresin_at_inport_2
      = ControlSystem_Refactorization_B.OR;

    /* Outputs for Enabled SubSystem: '<S7>/Control de Presión' incorporates:
     *  EnablePort: '<S42>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      if (ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_ControldePresin_at_inport_2)
      {
        if (!ControlSystem_Refactorization_DW.ControldePresin_MODE) {
          /* InitializeConditions for Derivative: '<S42>/Derivative' */
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
   *  EnablePort: '<S42>/Enable'
   */
  if (ControlSystem_Refactorization_DW.ControldePresin_MODE) {
    /* Sum: '<S42>/Add' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment'
     */
    ControlSystem_Refactorization_B.Add = maxError - rtb_Derivative;

    /* Derivative: '<S42>/Derivative' */
    u0 = ControlSystem_Refactorization_M->Timing.t[0];
    if ((ControlSystem_Refactorization_DW.TimeStampA >= u0) &&
        (ControlSystem_Refactorization_DW.TimeStampB >= u0)) {
      /* Derivative: '<S42>/Derivative' */
      ControlSystem_Refactorization_B.Derivative = 0.0;
    } else {
      lastTime = ControlSystem_Refactorization_DW.TimeStampA;
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA;
      if (ControlSystem_Refactorization_DW.TimeStampA <
          ControlSystem_Refactorization_DW.TimeStampB) {
        if (ControlSystem_Refactorization_DW.TimeStampB < u0) {
          lastTime = ControlSystem_Refactorization_DW.TimeStampB;
          lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB;
        }
      } else if (ControlSystem_Refactorization_DW.TimeStampA >= u0) {
        lastTime = ControlSystem_Refactorization_DW.TimeStampB;
        lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB;
      }

      /* Derivative: '<S42>/Derivative' */
      ControlSystem_Refactorization_B.Derivative =
        (ControlSystem_Refactorization_B.Add - *lastU) / (u0 - lastTime);
    }

    /* End of Derivative: '<S42>/Derivative' */

    /* Gain: '<S42>/Ganancia Presión -> Tensión' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment'
     */
    u0 = ControlSystem_Refactorization_P.GananciaPresinTensin_Gain_p * maxError;

    /* Saturate: '<S42>/Saturación de tensión' */
    if (u0 > ControlSystem_Refactorization_P.Saturacindetensin_UpperSat_a) {
      /* Saturate: '<S42>/Saturación de tensión' */
      ControlSystem_Refactorization_B.Saturacindetensin =
        ControlSystem_Refactorization_P.Saturacindetensin_UpperSat_a;
    } else if (u0 < ControlSystem_Refactorization_P.Saturacindetensin_LowerSat_m)
    {
      /* Saturate: '<S42>/Saturación de tensión' */
      ControlSystem_Refactorization_B.Saturacindetensin =
        ControlSystem_Refactorization_P.Saturacindetensin_LowerSat_m;
    } else {
      /* Saturate: '<S42>/Saturación de tensión' */
      ControlSystem_Refactorization_B.Saturacindetensin = u0;
    }

    /* End of Saturate: '<S42>/Saturación de tensión' */
    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      srUpdateBC(ControlSystem_Refactorization_DW.ControldePresin_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S7>/Control de Presión' */

  /* RelationalOperator: '<S38>/Compare' incorporates:
   *  Constant: '<S38>/Constant'
   */
  ControlSystem_Refactorization_B.Compare = (rtb_Controladoractivo_i ==
    ControlSystem_Refactorization_P.CompareToConstant_const_b);
  if (tmp_0) {
    /* SignalConversion generated from: '<S41>/Enable' */
    ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_ControldeCurvatura_at_inport_3
      = ControlSystem_Refactorization_B.Compare;

    /* Outputs for Enabled SubSystem: '<S7>/Control de Curvatura' incorporates:
     *  EnablePort: '<S41>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      if (ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_ControldeCurvatura_at_inport_3)
      {
        if (!ControlSystem_Refactorization_DW.ControldeCurvatura_MODE) {
          (void) memset(&(ControlSystem_Refactorization_XDis.Integrator_CSTATE),
                        0,
                        1*sizeof(boolean_T));

          /* InitializeConditions for Derivative: '<S41>/Derivative1' */
          ControlSystem_Refactorization_DW.TimeStampA_b = (rtInf);
          ControlSystem_Refactorization_DW.TimeStampB_f = (rtInf);

          /* SystemReset for Atomic SubSystem: '<S41>/Controlador de posición PID' */
          /* InitializeConditions for Integrator: '<S43>/Integrator' */
          ControlSystem_Refactorization_X.Integrator_CSTATE =
            ControlSystem_Refactorization_P.Integrator_IC;

          /* InitializeConditions for Derivative: '<S43>/Derivative' */
          ControlSystem_Refactorization_DW.TimeStampA_k = (rtInf);
          ControlSystem_Refactorization_DW.TimeStampB_b = (rtInf);

          /* End of SystemReset for SubSystem: '<S41>/Controlador de posición PID' */
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
   *  EnablePort: '<S41>/Enable'
   */
  if (ControlSystem_Refactorization_DW.ControldeCurvatura_MODE) {
    /* Sum: '<S41>/Add1' incorporates:
     *  BusAssignment: '<Root>/Bus Assignment'
     *  Sum: '<S41>/Sum'
     */
    rtb_Derivative = maxError - rtb_Derivative;

    /* Sum: '<S41>/Add1' */
    ControlSystem_Refactorization_B.Add1 = rtb_Derivative;

    /* Gain: '<S41>/Ganancia Presión -> Tensión' */
    maxError = rtb_Derivative *
      ControlSystem_Refactorization_P.GananciaPresinTensin_Gain;

    /* Outputs for Atomic SubSystem: '<S41>/Controlador de posición PID' */
    /* RelationalOperator: '<S44>/Compare' incorporates:
     *  Constant: '<S44>/Constant'
     */
    ControlSystem_Refactorization_B.Compare_m = (rtb_Controladoractivo_i ==
      ControlSystem_Refactorization_P.CompareToConstant_const);

    /* Integrator: '<S43>/Integrator' */
    rtb_Compare_b = rtsiIsModeUpdateTimeStep
      (&ControlSystem_Refactorization_M->solverInfo);
    if (rtb_Compare_b) {
      didZcEventOccur =
        (((ControlSystem_Refactorization_PrevZCX.Integrator_Reset_ZCE ==
           POS_ZCSIG) != (int32_T)ControlSystem_Refactorization_B.Compare_m) &&
         (ControlSystem_Refactorization_PrevZCX.Integrator_Reset_ZCE !=
          UNINITIALIZED_ZCSIG));
      ControlSystem_Refactorization_PrevZCX.Integrator_Reset_ZCE =
        ControlSystem_Refactorization_B.Compare_m;

      /* evaluate zero-crossings */
      if (didZcEventOccur) {
        ControlSystem_Refactorization_X.Integrator_CSTATE =
          ControlSystem_Refactorization_P.Integrator_IC;
      }
    }

    /* Gain: '<S43>/Gain2' */
    ControlSystem_Refactorization_B.Gain2 =
      ControlSystem_Refactorization_P.Gain2_Gain * maxError;

    /* Derivative: '<S43>/Derivative' incorporates:
     *  Derivative: '<S41>/Derivative1'
     */
    u0 = ControlSystem_Refactorization_M->Timing.t[0];
    if ((ControlSystem_Refactorization_DW.TimeStampA_k >= u0) &&
        (ControlSystem_Refactorization_DW.TimeStampB_b >= u0)) {
      rtb_Derivative = 0.0;
    } else {
      lastTime = ControlSystem_Refactorization_DW.TimeStampA_k;
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA_g;
      if (ControlSystem_Refactorization_DW.TimeStampA_k <
          ControlSystem_Refactorization_DW.TimeStampB_b) {
        if (ControlSystem_Refactorization_DW.TimeStampB_b < u0) {
          lastTime = ControlSystem_Refactorization_DW.TimeStampB_b;
          lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_c;
        }
      } else if (ControlSystem_Refactorization_DW.TimeStampA_k >= u0) {
        lastTime = ControlSystem_Refactorization_DW.TimeStampB_b;
        lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_c;
      }

      rtb_Derivative = (ControlSystem_Refactorization_B.Gain2 - *lastU) / (u0 -
        lastTime);
    }

    /* End of Derivative: '<S43>/Derivative' */

    /* Gain: '<S43>/Gain1' */
    ControlSystem_Refactorization_B.Gain1 =
      ControlSystem_Refactorization_P.Gain1_Gain * maxError;

    /* End of Outputs for SubSystem: '<S41>/Controlador de posición PID' */

    /* Derivative: '<S41>/Derivative1' */
    if ((ControlSystem_Refactorization_DW.TimeStampA_b >= u0) &&
        (ControlSystem_Refactorization_DW.TimeStampB_f >= u0)) {
      /* Derivative: '<S41>/Derivative1' */
      ControlSystem_Refactorization_B.Derivative1 = 0.0;
    } else {
      lastTime = ControlSystem_Refactorization_DW.TimeStampA_b;
      lastU = &ControlSystem_Refactorization_DW.LastUAtTimeA_e;
      if (ControlSystem_Refactorization_DW.TimeStampA_b <
          ControlSystem_Refactorization_DW.TimeStampB_f) {
        if (ControlSystem_Refactorization_DW.TimeStampB_f < u0) {
          lastTime = ControlSystem_Refactorization_DW.TimeStampB_f;
          lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_k;
        }
      } else if (ControlSystem_Refactorization_DW.TimeStampA_b >= u0) {
        lastTime = ControlSystem_Refactorization_DW.TimeStampB_f;
        lastU = &ControlSystem_Refactorization_DW.LastUAtTimeB_k;
      }

      /* Derivative: '<S41>/Derivative1' */
      ControlSystem_Refactorization_B.Derivative1 =
        (ControlSystem_Refactorization_B.Add1 - *lastU) / (u0 - lastTime);
    }

    /* Outputs for Atomic SubSystem: '<S41>/Controlador de posición PID' */
    /* Sum: '<S43>/Add' incorporates:
     *  Gain: '<S43>/Gain'
     *  Integrator: '<S43>/Integrator'
     */
    u0 = (ControlSystem_Refactorization_P.Gain_Gain * maxError +
          ControlSystem_Refactorization_X.Integrator_CSTATE) + rtb_Derivative;

    /* End of Outputs for SubSystem: '<S41>/Controlador de posición PID' */

    /* Saturate: '<S41>/Saturación de tensión' */
    if (u0 > ControlSystem_Refactorization_P.Saturacindetensin_UpperSat) {
      /* Saturate: '<S41>/Saturación de tensión' */
      ControlSystem_Refactorization_B.Saturacindetensin_k =
        ControlSystem_Refactorization_P.Saturacindetensin_UpperSat;
    } else if (u0 < ControlSystem_Refactorization_P.Saturacindetensin_LowerSat)
    {
      /* Saturate: '<S41>/Saturación de tensión' */
      ControlSystem_Refactorization_B.Saturacindetensin_k =
        ControlSystem_Refactorization_P.Saturacindetensin_LowerSat;
    } else {
      /* Saturate: '<S41>/Saturación de tensión' */
      ControlSystem_Refactorization_B.Saturacindetensin_k = u0;
    }

    /* End of Saturate: '<S41>/Saturación de tensión' */
    if (rtb_Compare_b) {
      srUpdateBC(ControlSystem_Refactorization_DW.ControldeCurvatura_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S7>/Control de Curvatura' */

  /* MultiPortSwitch: '<S7>/Index Vector1' incorporates:
   *  BusAssignment: '<Root>/Bus Assignment'
   *  MultiPortSwitch generated from: '<S6>/Index Vector1'
   */
  switch (rtb_Controladoractivo_i) {
   case Controlador_Presion:
    /* BusAssignment: '<Root>/Bus Assignment1' */
    ControlSystem_Refactorization_B.sistema.Configuracion.Global.referenciaControl
      = ControlSystem_Refactorization_B.Saturacindetensin;
    ControlSystem_Refactorization_B.sistema.Estado.Global.errorEstacionario =
      ControlSystem_Refactorization_B.Add;
    ControlSystem_Refactorization_B.sistema.Estado.Global.errorDerivativo =
      ControlSystem_Refactorization_B.Derivative;
    break;

   case Controlador_EquilibrioPresiones:
    /* BusAssignment: '<Root>/Bus Assignment1' */
    ControlSystem_Refactorization_B.sistema.Configuracion.Global.referenciaControl
      = ControlSystem_Refactorization_B.Saturacindetensin;
    ControlSystem_Refactorization_B.sistema.Estado.Global.errorEstacionario =
      ControlSystem_Refactorization_B.Add;
    ControlSystem_Refactorization_B.sistema.Estado.Global.errorDerivativo =
      ControlSystem_Refactorization_B.Derivative;
    break;

   default:
    /* BusAssignment: '<Root>/Bus Assignment1' */
    ControlSystem_Refactorization_B.sistema.Configuracion.Global.referenciaControl
      = ControlSystem_Refactorization_B.Saturacindetensin_k;
    ControlSystem_Refactorization_B.sistema.Estado.Global.errorEstacionario =
      ControlSystem_Refactorization_B.Add1;
    ControlSystem_Refactorization_B.sistema.Estado.Global.errorDerivativo =
      ControlSystem_Refactorization_B.Derivative1;
    break;
  }

  /* End of MultiPortSwitch: '<S7>/Index Vector1' */

  /* BusAssignment: '<Root>/Bus Assignment1' incorporates:
   *  BusAssignment: '<Root>/Bus Assignment'
   *  BusAssignment: '<S2>/Bus Assignment3'
   *  DataStoreRead: '<Root>/Data Store Read4'
   *  MultiPortSwitch generated from: '<S6>/Index Vector1'
   */
  ControlSystem_Refactorization_B.sistema.Configuracion.Global.numActuadores =
    rtb_DataStoreRead4_Configuracion_Global_numActuadores;
  ControlSystem_Refactorization_B.sistema.Configuracion.Global.modoControl =
    rtb_sistema_Configuracion_Global_modoControl;
  ControlSystem_Refactorization_B.sistema.Configuracion.Global.parametroControl =
    rtb_sistema_Configuracion_Global_parametroControl;
  ControlSystem_Refactorization_B.sistema.Configuracion.Global.controlador =
    rtb_Controladoractivo_i;
  ControlSystem_Refactorization_B.sistema.Configuracion.Global.simulacionActiva =
    b_varargout_5;
  ControlSystem_Refactorization_B.sistema.Configuracion.Global.toleranciaEquilibrioPresiones
    = b_varargout_4;
  ControlSystem_Refactorization_B.sistema.Configuracion.Global.ToleranciaPresion.estacionaria
    = actError;
  ControlSystem_Refactorization_B.sistema.Configuracion.Global.ToleranciaPresion.derivativa
    = rtb_sistema_Configuracion_Global_ToleranciaPresion_derivativa;
  ControlSystem_Refactorization_B.sistema.Configuracion.Global.ToleranciaCurvatura.estacionaria
    = rtb_sistema_Configuracion_Global_ToleranciaCurvatura_estacionaria;
  ControlSystem_Refactorization_B.sistema.Configuracion.Global.ToleranciaCurvatura.derivativa
    = rtb_sistema_Configuracion_Global_ToleranciaCurvatura_derivativa;
  ControlSystem_Refactorization_B.sistema.Configuracion.ControlManual.actuadorSeleccionado
    = rtb_sistema_Configuracion_ControlManual_actuadorSeleccionado;
  ControlSystem_Refactorization_B.sistema.Estado.Global.realimentacionControl =
    rtb_sistema_Estado_Global_realimentacionControl;
  ControlSystem_Refactorization_B.sistema.Estado.ControlAutomatico.actuadorSeleccionado
    = rtb_DataStoreRead4_Estado_ControlAutomatico_actuadorSeleccionado;

  /* DataStoreRead: '<Root>/Data Store Read6' */
  rtb_DataStoreRead6 = ControlSystem_Refactorization_DW.electroValvulas;

  /* Logic: '<S5>/NOT' */
  ControlSystem_Refactorization_B.NOT =
    !(ControlSystem_Refactorization_B.sistema.Configuracion.Global.simulacionActiva
      != 0.0);
  if (tmp_0) {
    /* SignalConversion generated from: '<S20>/Enable' */
    ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_DAQ_at_inport_4 =
      ControlSystem_Refactorization_B.NOT;

    /* Outputs for Enabled SubSystem: '<S5>/DAQ' incorporates:
     *  EnablePort: '<S20>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      ControlSystem_Refactorization_DW.DAQ_MODE =
        ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_DAQ_at_inport_4;
    }

    /* End of Outputs for SubSystem: '<S5>/DAQ' */
  }

  /* Outputs for Enabled SubSystem: '<S5>/DAQ' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  if (ControlSystem_Refactorization_DW.DAQ_MODE) {
    /* MATLABSystem: '<S20>/MATLAB System' */
    /*  Implement algorithm. Calculate y as a function of input u and */
    /*  internal states. */
    /*  Inicialización de variables */
    memset(&ControlSystem_Refactorization_B.MATLABSystem[0], 0, sizeof(real_T) <<
           3U);

    /* MATLABSystem: '<S20>/MATLAB System' incorporates:
     *  DataStoreRead: '<Root>/Data Store Read6'
     *  ForEachSliceAssignment generated from: '<S3>/actuadores'
     */
    /*  Selección de tensiones de salida */
    for (b_k = 0; b_k < 4; b_k++) {
      /*  Estado del actuador */
      if (ControlSystem_Refactorization_B.sistema.Configuracion.Global.modoControl
          == ModoControl_Manual) {
        estadoActuador =
          ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
          [b_k].Configuracion.ControlManual.estadoValvula;
      } else {
        estadoActuador =
          ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
          [b_k].Estado.ControlAutomatico.estadoValvula;
      }

      /*  Puertos de conexión de la electoválvula del actuador */
      /*  Tensiones de salida para este actuador */
      switch (estadoActuador) {
       case EstadoValvula_Bloquear:
        rtb_DataStoreRead4_Configuracion_Global_numActuadores = 0.0;
        rtb_DataStoreRead4_Estado_ControlAutomatico_actuadorSeleccionado = 0.0;
        break;

       case EstadoValvula_Inyectar:
        rtb_DataStoreRead4_Configuracion_Global_numActuadores = 1.0;
        rtb_DataStoreRead4_Estado_ControlAutomatico_actuadorSeleccionado = 0.0;
        break;

       default:
        rtb_DataStoreRead4_Configuracion_Global_numActuadores = 0.0;
        rtb_DataStoreRead4_Estado_ControlAutomatico_actuadorSeleccionado = 1.0;
        break;
      }

      /*  Asignar tensiones de salida a los puertos correspondientes */
      for (i = 0; i < 8; i++) {
        electroValvulas_Configuracion =
          ControlSystem_Refactorization_DW.electroValvulas.Configuracion.PuertosDigitales
          [i];
        if (electroValvulas_Configuracion ==
            ControlSystem_Refactorization_DW.electroValvulas.Configuracion.ConexionActuadores
            [b_k].terminalA) {
          ControlSystem_Refactorization_B.MATLABSystem[i] =
            rtb_DataStoreRead4_Configuracion_Global_numActuadores;
        }

        if (electroValvulas_Configuracion ==
            ControlSystem_Refactorization_DW.electroValvulas.Configuracion.ConexionActuadores
            [b_k].terminalB) {
          ControlSystem_Refactorization_B.MATLABSystem[i] =
            rtb_DataStoreRead4_Estado_ControlAutomatico_actuadorSeleccionado;
        }
      }
    }

    rtb_Compare_b = (rtmIsMajorTimeStep(ControlSystem_Refactorization_M) &&
                     ControlSystem_Refactorization_M->Timing.TaskCounters.TID[2]
                     == 0);
    if (rtb_Compare_b) {
      /* S-Function (sldrtai): '<S20>/Analog Input' */
      /* S-Function Block: <S20>/Analog Input */
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          ControlSystem_Refactorization_P.AnalogInput_RangeMode;
        parm.rangeidx = ControlSystem_Refactorization_P.AnalogInput_VoltRange;
        RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 1,
                       &ControlSystem_Refactorization_P.AnalogInput_Channels,
                       &rtb_Tensin, &parm);
      }

      /* S-Function (sldrtai): '<S20>/Analog Input1' */
      /* S-Function Block: <S20>/Analog Input1 */
      {
        ANALOGIOPARM parm;
        parm.mode = (RANGEMODE)
          ControlSystem_Refactorization_P.AnalogInput1_RangeMode;
        parm.rangeidx = ControlSystem_Refactorization_P.AnalogInput1_VoltRange;
        RTBIO_DriverIO(0, ANALOGINPUT, IOREAD, 4,
                       ControlSystem_Refactorization_P.AnalogInput1_Channels,
                       &rtb_Tensin_g[0], &parm);
      }

      /* MATLAB Function: '<S20>/MATLAB Function' */
      ControlSystem_Refactorization_DW.sfEvent_d =
        ControlSystem_Refactorization_CALL_EVENT;
      ControlSystem_Refactorization_B.press = (rtb_Tensin - 0.9836) /
        0.81400000000000006;
    }

    /* Outputs for Iterator SubSystem: '<S20>/Flujo de aire en los actuadores' incorporates:
     *  ForEach: '<S22>/For Each'
     */
    for (ForEach_itr_h = 0; ForEach_itr_h < 4; ForEach_itr_h++) {
      /* Switch: '<S22>/Switch' incorporates:
       *  Constant: '<S25>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S22>/Actuador'
       *  RelationalOperator: '<S25>/Compare'
       */
      if (ControlSystem_Refactorization_B.sistema.Configuracion.Global.modoControl
          ==
          ControlSystem_Refactorization_P.CoreSubsys_pna.CompareToConstant5_const)
      {
        estadoActuador =
          ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
          [ForEach_itr_h].Configuracion.ControlManual.estadoValvula;
      } else {
        estadoActuador =
          ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
          [ForEach_itr_h].Estado.ControlAutomatico.estadoValvula;
      }

      /* MultiPortSwitch: '<S22>/Index Vector1' incorporates:
       *  Switch: '<S22>/Switch'
       */
      switch (estadoActuador) {
       case EstadoValvula_Bloquear:
        /* ForEachSliceAssignment generated from: '<S22>/Presión actuadores' incorporates:
         *  ForEachSliceAssignment generated from: '<S3>/actuadores'
         *  ForEachSliceSelector generated from: '<S22>/Actuador'
         */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
          [ForEach_itr_h] =
          ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
          [ForEach_itr_h].Estado.Realimentacion.presion;
        break;

       case EstadoValvula_Inyectar:
        /* ForEachSliceAssignment generated from: '<S22>/Presión actuadores' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
          [ForEach_itr_h] = ControlSystem_Refactorization_B.press;
        break;

       default:
        /* ForEachSliceAssignment generated from: '<S22>/Presión actuadores' incorporates:
         *  Constant: '<S22>/Constant'
         */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
          [ForEach_itr_h] =
          ControlSystem_Refactorization_P.CoreSubsys_pna.Constant_Value;
        break;
      }

      /* End of MultiPortSwitch: '<S22>/Index Vector1' */
    }

    /* End of Outputs for SubSystem: '<S20>/Flujo de aire en los actuadores' */
    if (rtb_Compare_b) {
      /* MATLAB Function: '<S20>/MATLAB Function1' */
      ControlSystem_Refactorization_DW.sfEvent =
        ControlSystem_Refactorization_CALL_EVENT;
      tmp_1 = _mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&rtb_Tensin_g[0]), _mm_set_pd
        (2.3916, 2.3357)), _mm_set_pd(63.6333, 62.6723));
      _mm_storeu_pd(&ControlSystem_Refactorization_B.curv[0], tmp_1);

      /* MATLAB Function: '<S20>/MATLAB Function1' */
      tmp_1 = _mm_div_pd(_mm_sub_pd(_mm_loadu_pd(&rtb_Tensin_g[2]), _mm_set_pd
        (2.4385, 2.4152)), _mm_set_pd(62.6754, 63.6685));
      _mm_storeu_pd(&ControlSystem_Refactorization_B.curv[2], tmp_1);

      /* S-Function (sldrtdo): '<S20>/Digital Output' */
      /* S-Function Block: <S20>/Digital Output */
      {
        RTBIO_DriverIO(0, DIGITALOUTPUT, IOWRITE, 8,
                       ControlSystem_Refactorization_P.DigitalOutput_Channels,
                       ((real_T*) (ControlSystem_Refactorization_B.MATLABSystem)),
                       &ControlSystem_Refactorization_P.DigitalOutput_BitMode);
      }

      /* S-Function (sldrtao): '<S20>/Analog Output' */
      /* S-Function Block: <S20>/Analog Output */
      {
        {
          ANALOGIOPARM parm;
          parm.mode = (RANGEMODE)
            ControlSystem_Refactorization_P.AnalogOutput_RangeMode;
          parm.rangeidx = ControlSystem_Refactorization_P.AnalogOutput_VoltRange;
          RTBIO_DriverIO(0, ANALOGOUTPUT, IOWRITE, 1,
                         &ControlSystem_Refactorization_P.AnalogOutput_Channels,
                         ((real_T*)
                          (&ControlSystem_Refactorization_B.sistema.Configuracion.Global.referenciaControl)),
                         &parm);
        }
      }
    }

    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      srUpdateBC(ControlSystem_Refactorization_DW.DAQ_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S5>/DAQ' */
  if (tmp_0) {
    /* SignalConversion generated from: '<S21>/Enable' */
    ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_Simulacin_at_inport_3 =
      ControlSystem_Refactorization_B.sistema.Configuracion.Global.simulacionActiva;

    /* Outputs for Enabled SubSystem: '<S5>/Simulación' incorporates:
     *  EnablePort: '<S21>/Enable'
     */
    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      if (ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_Simulacin_at_inport_3
          > 0.0) {
        if (!ControlSystem_Refactorization_DW.Simulacin_MODE) {
          (void) memset
            (&(ControlSystem_Refactorization_XDis.Modelodelreguladordepresinelectrnico_CSTATE),
             0,
             102*sizeof(boolean_T));
          ControlSystem_Refactorization_DW.Simulacin_MODE = true;
        }
      } else {
        /* Outputs for Enabled SubSystem: '<S7>/Control de Curvatura' incorporates:
         *  EnablePort: '<S41>/Enable'
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

          /* Disable for Iterator SubSystem: '<S21>/Modelo de los actuadores' */
          for (ForEach_itr_d = 0; ForEach_itr_d < 4; ForEach_itr_d++) {
            /* Disable for Enabled SubSystem: '<S26>/Curvatura Actuador 1' */
            if (ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
                CurvaturaActuador1.CurvaturaActuador5_MODE) {
              ControlSystem_Refactorization_CurvaturaActuador5_Disable
                (&ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d]
                 .CurvaturaActuador1);
            }

            /* End of Disable for SubSystem: '<S26>/Curvatura Actuador 1' */

            /* Disable for Enabled SubSystem: '<S26>/Curvatura Actuador 2' */
            if (ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
                CurvaturaActuador2.CurvaturaActuador4_MODE) {
              ControlSystem_Refactorization_CurvaturaActuador4_Disable
                (&ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d]
                 .CurvaturaActuador2);
            }

            /* End of Disable for SubSystem: '<S26>/Curvatura Actuador 2' */

            /* Disable for Enabled SubSystem: '<S26>/Curvatura Actuador 3' */
            if (ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
                CurvaturaActuador3.CurvaturaActuador4_MODE) {
              ControlSystem_Refactorization_CurvaturaActuador4_Disable
                (&ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d]
                 .CurvaturaActuador3);
            }

            /* End of Disable for SubSystem: '<S26>/Curvatura Actuador 3' */

            /* Disable for Enabled SubSystem: '<S26>/Curvatura Actuador 4' */
            if (ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
                CurvaturaActuador4.CurvaturaActuador4_MODE) {
              ControlSystem_Refactorization_CurvaturaActuador4_Disable
                (&ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d]
                 .CurvaturaActuador4);
            }

            /* End of Disable for SubSystem: '<S26>/Curvatura Actuador 4' */

            /* Disable for Enabled SubSystem: '<S26>/Curvatura Actuador 5' */
            if (ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
                CurvaturaActuador5.CurvaturaActuador5_MODE) {
              ControlSystem_Refactorization_CurvaturaActuador5_Disable
                (&ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d]
                 .CurvaturaActuador5);
            }

            /* End of Disable for SubSystem: '<S26>/Curvatura Actuador 5' */
          }

          /* End of Disable for SubSystem: '<S21>/Modelo de los actuadores' */
          ControlSystem_Refactorization_DW.Simulacin_MODE = false;
        }
      }
    }

    /* End of Outputs for SubSystem: '<S5>/Simulación' */
  }

  /* Outputs for Enabled SubSystem: '<S5>/Simulación' incorporates:
   *  EnablePort: '<S21>/Enable'
   */
  if (ControlSystem_Refactorization_DW.Simulacin_MODE) {
    /* TransferFcn: '<S21>/Modelo del regulador de presión electrónico' */
    ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico = 0.0;
    ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico +=
      ControlSystem_Refactorization_P.Modelodelreguladordepresinelectrnico_C[0] *
      ControlSystem_Refactorization_X.Modelodelreguladordepresinelectrnico_CSTATE
      [0];
    ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico +=
      ControlSystem_Refactorization_P.Modelodelreguladordepresinelectrnico_C[1] *
      ControlSystem_Refactorization_X.Modelodelreguladordepresinelectrnico_CSTATE
      [1];

    /* Outputs for Iterator SubSystem: '<S21>/Modelo de los actuadores' incorporates:
     *  ForEach: '<S26>/For Each'
     */
    for (ForEach_itr_d = 0; ForEach_itr_d < 4; ForEach_itr_d++) {
      /* ForEachSliceSelector generated from: '<S26>/Actuador' incorporates:
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       */
      rtb_DataStoreRead4_Configuracion_Global_numActuadores =
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
        [ForEach_itr_d].Configuracion.Global.indice;
      rtb_ImpSel_InsertedFor_Actuador_at_outport_0_Configuracion_ControlManual_estadoValvula
        =
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
        [ForEach_itr_d].Configuracion.ControlManual.estadoValvula;
      estadoActuador =
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
        [ForEach_itr_d].Estado.ControlAutomatico.estadoValvula;
      rtb_DataStoreRead4_Estado_ControlAutomatico_actuadorSeleccionado =
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
        [ForEach_itr_d].Estado.Realimentacion.presion;

      /* RelationalOperator: '<S27>/Compare' incorporates:
       *  Constant: '<S27>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S26>/Actuador'
       */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare =
        (ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
         [ForEach_itr_d].Configuracion.Global.indice ==
         ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant_const);

      /* RelationalOperator: '<S28>/Compare' incorporates:
       *  Constant: '<S28>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S26>/Actuador'
       */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_c =
        (ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
         [ForEach_itr_d].Configuracion.Global.indice ==
         ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant1_const);

      /* RelationalOperator: '<S29>/Compare' incorporates:
       *  Constant: '<S29>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S26>/Actuador'
       */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_n =
        (ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
         [ForEach_itr_d].Configuracion.Global.indice ==
         ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant2_const);

      /* RelationalOperator: '<S30>/Compare' incorporates:
       *  Constant: '<S30>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S26>/Actuador'
       */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_i =
        (ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
         [ForEach_itr_d].Configuracion.Global.indice ==
         ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant3_const);

      /* RelationalOperator: '<S31>/Compare' incorporates:
       *  Constant: '<S31>/Constant'
       *  ForEachSliceAssignment generated from: '<S3>/actuadores'
       *  ForEachSliceSelector generated from: '<S26>/Actuador'
       */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_a =
        (ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
         [ForEach_itr_d].Configuracion.Global.indice ==
         ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant4_const);

      /* RelationalOperator: '<S32>/Compare' incorporates:
       *  Constant: '<S32>/Constant'
       */
      rtb_Compare_b =
        (ControlSystem_Refactorization_B.sistema.Configuracion.Global.modoControl
         ==
         ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant5_const);
      tmp_0 = (rtmIsMajorTimeStep(ControlSystem_Refactorization_M) &&
               ControlSystem_Refactorization_M->Timing.TaskCounters.TID[1] == 0);
      if (tmp_0) {
        /* SignalConversion generated from: '<S33>/Enable' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          HiddenBuf_InsertedFor_CurvaturaActuador1_at_inport_1 =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare;
      }

      /* Outputs for Enabled SubSystem: '<S26>/Curvatura Actuador 1' */
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

      /* End of Outputs for SubSystem: '<S26>/Curvatura Actuador 1' */
      if (tmp_0) {
        /* SignalConversion generated from: '<S34>/Enable' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          HiddenBuf_InsertedFor_CurvaturaActuador2_at_inport_1 =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          Compare_c;
      }

      /* Outputs for Enabled SubSystem: '<S26>/Curvatura Actuador 2' */
      ControlSystem_Refactorization_CurvaturaActuador4
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

      /* End of Outputs for SubSystem: '<S26>/Curvatura Actuador 2' */
      if (tmp_0) {
        /* SignalConversion generated from: '<S35>/Enable' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          HiddenBuf_InsertedFor_CurvaturaActuador3_at_inport_1 =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          Compare_n;
      }

      /* Outputs for Enabled SubSystem: '<S26>/Curvatura Actuador 3' */
      ControlSystem_Refactorization_CurvaturaActuador4
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

      /* End of Outputs for SubSystem: '<S26>/Curvatura Actuador 3' */
      if (tmp_0) {
        /* SignalConversion generated from: '<S36>/Enable' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          HiddenBuf_InsertedFor_CurvaturaActuador4_at_inport_1 =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          Compare_i;
      }

      /* Outputs for Enabled SubSystem: '<S26>/Curvatura Actuador 4' */
      ControlSystem_Refactorization_CurvaturaActuador4
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

      /* End of Outputs for SubSystem: '<S26>/Curvatura Actuador 4' */
      if (tmp_0) {
        /* SignalConversion generated from: '<S37>/Enable' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          HiddenBuf_InsertedFor_CurvaturaActuador5_at_inport_1 =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          Compare_a;
      }

      /* Outputs for Enabled SubSystem: '<S26>/Curvatura Actuador 5' */
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

      /* End of Outputs for SubSystem: '<S26>/Curvatura Actuador 5' */

      /* MultiPortSwitch: '<S26>/Index Vector2' incorporates:
       *  ForEachSliceSelector generated from: '<S26>/Actuador'
       */
      switch ((int32_T)rtb_DataStoreRead4_Configuracion_Global_numActuadores) {
       case 1:
        /* ForEachSliceAssignment generated from: '<S26>/Curvatura Actuador' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
          [ForEach_itr_d] =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          CurvaturaActuador1.CurvAct;
        break;

       case 2:
        /* ForEachSliceAssignment generated from: '<S26>/Curvatura Actuador' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
          [ForEach_itr_d] =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          CurvaturaActuador2.CurvAct;
        break;

       case 3:
        /* ForEachSliceAssignment generated from: '<S26>/Curvatura Actuador' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
          [ForEach_itr_d] =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          CurvaturaActuador3.CurvAct;
        break;

       case 4:
        /* ForEachSliceAssignment generated from: '<S26>/Curvatura Actuador' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
          [ForEach_itr_d] =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          CurvaturaActuador4.CurvAct;
        break;

       default:
        /* ForEachSliceAssignment generated from: '<S26>/Curvatura Actuador' */
        ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
          [ForEach_itr_d] =
          ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          CurvaturaActuador5.CurvAct;
        break;
      }

      /* End of MultiPortSwitch: '<S26>/Index Vector2' */

      /* Switch: '<S26>/Switch' incorporates:
       *  ForEachSliceSelector generated from: '<S26>/Actuador'
       */
      if (rtb_Compare_b) {
        estadoActuador =
          rtb_ImpSel_InsertedFor_Actuador_at_outport_0_Configuracion_ControlManual_estadoValvula;
      }

      /* MultiPortSwitch: '<S26>/Index Vector1' incorporates:
       *  Switch: '<S26>/Switch'
       */
      switch (estadoActuador) {
       case EstadoValvula_Bloquear:
        /* MultiPortSwitch: '<S26>/Index Vector1' incorporates:
         *  ForEachSliceSelector generated from: '<S26>/Actuador'
         */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          IndexVector1 =
          rtb_DataStoreRead4_Estado_ControlAutomatico_actuadorSeleccionado;
        break;

       case EstadoValvula_Inyectar:
        /* MultiPortSwitch: '<S26>/Index Vector1' */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          IndexVector1 =
          ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico;
        break;

       default:
        /* MultiPortSwitch: '<S26>/Index Vector1' incorporates:
         *  Constant: '<S26>/Constant'
         */
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
          IndexVector1 =
          ControlSystem_Refactorization_P.CoreSubsys_pnae.Constant_Value;
        break;
      }

      /* End of MultiPortSwitch: '<S26>/Index Vector1' */

      /* ForEachSliceAssignment generated from: '<S26>/Presión Actuador' */
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
        [ForEach_itr_d] =
        ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        IndexVector1;
    }

    /* End of Outputs for SubSystem: '<S21>/Modelo de los actuadores' */
    if (rtsiIsModeUpdateTimeStep(&ControlSystem_Refactorization_M->solverInfo))
    {
      srUpdateBC(ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC);
    }
  }

  /* End of Outputs for SubSystem: '<S5>/Simulación' */

  /* MultiPortSwitch generated from: '<S5>/Index Vector1' incorporates:
   *  ForEachSliceAssignment generated from: '<S22>/Presión actuadores'
   *  ForEachSliceAssignment generated from: '<S26>/Curvatura Actuador'
   *  ForEachSliceAssignment generated from: '<S26>/Presión Actuador'
   */
  if ((int32_T)
      ControlSystem_Refactorization_B.sistema.Configuracion.Global.simulacionActiva
      == 0) {
    rtb_PresinActuadores[0] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
      [0];
    rtb_CurvaturaActuadores[0] = ControlSystem_Refactorization_B.curv[0];
    rtb_PresinActuadores[1] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
      [1];
    rtb_CurvaturaActuadores[1] = ControlSystem_Refactorization_B.curv[1];
    rtb_PresinActuadores[2] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
      [2];
    rtb_CurvaturaActuadores[2] = ControlSystem_Refactorization_B.curv[2];
    rtb_PresinActuadores[3] =
      ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
      [3];
    rtb_CurvaturaActuadores[3] = ControlSystem_Refactorization_B.curv[3];
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
  if ((int32_T)
      ControlSystem_Refactorization_B.sistema.Configuracion.Global.simulacionActiva
      == 0) {
    /* DataStoreWrite: '<Root>/Data Store Write5' */
    ControlSystem_Refactorization_DW.regulador.Estado.presion =
      ControlSystem_Refactorization_B.press;
  } else {
    /* DataStoreWrite: '<Root>/Data Store Write5' */
    ControlSystem_Refactorization_DW.regulador.Estado.presion =
      ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico;
  }

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
   *  ForEach: '<S45>/For Each'
   */
  for (ForEach_itr = 0; ForEach_itr < 4; ForEach_itr++) {
    /* ForEachSliceAssignment generated from: '<S45>/Presión actuadores' incorporates:
     *  ForEachSliceAssignment generated from: '<S4>/actuadores'
     *  ForEachSliceSelector generated from: '<S45>/actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0
      [ForEach_itr] = rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr]
      .Estado.Realimentacion.presion;

    /* ForEachSliceAssignment generated from: '<S45>/Curvatura actuadores' incorporates:
     *  ForEachSliceAssignment generated from: '<S4>/actuadores'
     *  ForEachSliceSelector generated from: '<S45>/actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Curvaturaactuadores_at_inport_0
      [ForEach_itr] = rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr]
      .Estado.Realimentacion.curvatura;

    /* ForEachSliceAssignment generated from: '<S45>/Actuadores posicionados' incorporates:
     *  ForEachSliceAssignment generated from: '<S4>/actuadores'
     *  ForEachSliceSelector generated from: '<S45>/actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Actuadoresposicionados_at_inport_0
      [ForEach_itr] = rtb_ImpAsg_InsertedFor_actuadores_at_inport_0[ForEach_itr]
      .Estado.ControlAutomatico.actuadorPosicionado;
  }

  /* End of Outputs for SubSystem: '<S8>/DATOS DE ACTUADORES' */
}

/* Model update function */
void ControlSystem_Refactorization_update(void)
{
  real_T *lastU;

  /* Update for Enabled SubSystem: '<S7>/Control de Presión' incorporates:
   *  EnablePort: '<S42>/Enable'
   */
  if (ControlSystem_Refactorization_DW.ControldePresin_MODE) {
    /* Update for Derivative: '<S42>/Derivative' */
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

    /* End of Update for Derivative: '<S42>/Derivative' */
  }

  /* End of Update for SubSystem: '<S7>/Control de Presión' */

  /* Update for Enabled SubSystem: '<S7>/Control de Curvatura' incorporates:
   *  EnablePort: '<S41>/Enable'
   */
  if (ControlSystem_Refactorization_DW.ControldeCurvatura_MODE) {
    /* Update for Atomic SubSystem: '<S41>/Controlador de posición PID' */
    /* Update for Derivative: '<S43>/Derivative' */
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

    /* End of Update for Derivative: '<S43>/Derivative' */
    /* End of Update for SubSystem: '<S41>/Controlador de posición PID' */

    /* Update for Derivative: '<S41>/Derivative1' */
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

    /* End of Update for Derivative: '<S41>/Derivative1' */
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

  if (rtmIsMajorTimeStep(ControlSystem_Refactorization_M) &&
      ControlSystem_Refactorization_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.1s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++ControlSystem_Refactorization_M->Timing.clockTick2)) {
      ++ControlSystem_Refactorization_M->Timing.clockTickH2;
    }

    ControlSystem_Refactorization_M->Timing.t[2] =
      ControlSystem_Refactorization_M->Timing.clockTick2 *
      ControlSystem_Refactorization_M->Timing.stepSize2 +
      ControlSystem_Refactorization_M->Timing.clockTickH2 *
      ControlSystem_Refactorization_M->Timing.stepSize2 * 4294967296.0;
  }

  rate_scheduler();
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
    /* Derivatives for Atomic SubSystem: '<S41>/Controlador de posición PID' */
    /* Derivatives for Integrator: '<S43>/Integrator' */
    _rtXdot->Integrator_CSTATE = ControlSystem_Refactorization_B.Gain1;

    /* End of Derivatives for SubSystem: '<S41>/Controlador de posición PID' */
  } else {
    ((XDot_ControlSystem_Refactorization_T *)
      ControlSystem_Refactorization_M->derivs)->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for SubSystem: '<S7>/Control de Curvatura' */

  /* Derivatives for Enabled SubSystem: '<S5>/Simulación' */
  if (ControlSystem_Refactorization_DW.Simulacin_MODE) {
    /* Derivatives for TransferFcn: '<S21>/Modelo del regulador de presión electrónico' */
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
       [0]), _mm_set_pd
      (ControlSystem_Refactorization_B.sistema.Configuracion.Global.referenciaControl,
       _rtXdot->Modelodelreguladordepresinelectrnico_CSTATE[1])));
    _rtXdot->Modelodelreguladordepresinelectrnico_CSTATE[1] = tmp[0];
    _rtXdot->Modelodelreguladordepresinelectrnico_CSTATE[0] = tmp[1];

    /* Derivatives for Iterator SubSystem: '<S21>/Modelo de los actuadores' */
    for (ForEach_itr_d = 0; ForEach_itr_d < 4; ForEach_itr_d++) {
      /* Derivatives for Iterator SubSystem: '<S21>/Modelo de los actuadores' */
      /* Derivatives for Enabled SubSystem: '<S26>/Curvatura Actuador 1' */
      ControlSystem_Refactorization_CurvaturaActuador5_Deriv
        (ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         IndexVector1,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador1,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1, &_rtXdot->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1);

      /* End of Derivatives for SubSystem: '<S26>/Curvatura Actuador 1' */

      /* Derivatives for Enabled SubSystem: '<S26>/Curvatura Actuador 2' */
      ControlSystem_Refactorization_CurvaturaActuador4_Deriv
        (ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         IndexVector1,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador2,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2, &_rtXdot->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2);

      /* End of Derivatives for SubSystem: '<S26>/Curvatura Actuador 2' */

      /* Derivatives for Enabled SubSystem: '<S26>/Curvatura Actuador 3' */
      ControlSystem_Refactorization_CurvaturaActuador4_Deriv
        (ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         IndexVector1,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador3,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3, &_rtXdot->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3);

      /* End of Derivatives for SubSystem: '<S26>/Curvatura Actuador 3' */

      /* Derivatives for Enabled SubSystem: '<S26>/Curvatura Actuador 4' */
      ControlSystem_Refactorization_CurvaturaActuador4_Deriv
        (ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         IndexVector1,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador4,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4, &_rtXdot->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4);

      /* End of Derivatives for SubSystem: '<S26>/Curvatura Actuador 4' */

      /* Derivatives for Enabled SubSystem: '<S26>/Curvatura Actuador 5' */
      ControlSystem_Refactorization_CurvaturaActuador5_Deriv
        (ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         IndexVector1,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador5,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5, &_rtXdot->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5);

      /* End of Derivatives for SubSystem: '<S26>/Curvatura Actuador 5' */
      /* End of Derivatives for SubSystem: '<S21>/Modelo de los actuadores' */
    }

    /* End of Derivatives for SubSystem: '<S21>/Modelo de los actuadores' */
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

    /* Start for MATLABSystem: '<S6>/ManualControlLogic' */
    ControlSystem_Refactorization_DW.objisempty_e = true;
    ControlSystem_Refactorization_DW.obj_k.isInitialized = 1;

    /* Start for MATLABSystem: '<S6>/SequentialAutonomousControlLogic' */
    /*  Perform one-time calculations, such as computing constants */
    ControlSystem_Refactorization_DW.objisempty = true;
    ControlSystem_Refactorization_DW.obj.isInitialized = 1;
    ControlSystem_Refactorization_sequential_autonomousControlLogic_setupImpl
      (&ControlSystem_Refactorization_DW.obj);

    /* Start for Enabled SubSystem: '<S7>/Control de Presión' */
    ControlSystem_Refactorization_DW.ControldePresin_MODE = false;

    /* End of Start for SubSystem: '<S7>/Control de Presión' */

    /* Start for Enabled SubSystem: '<S7>/Control de Curvatura' */
    ControlSystem_Refactorization_DW.ControldeCurvatura_MODE = false;
    (void) memset(&(ControlSystem_Refactorization_XDis.Integrator_CSTATE), 1,
                  1*sizeof(boolean_T));

    /* End of Start for SubSystem: '<S7>/Control de Curvatura' */

    /* Start for Enabled SubSystem: '<S5>/DAQ' */
    ControlSystem_Refactorization_DW.DAQ_MODE = false;

    /* Start for MATLABSystem: '<S20>/MATLAB System' */
    ControlSystem_Refactorization_DW.objisempty_h = true;
    ControlSystem_Refactorization_DW.obj_b.isInitialized = 1;

    /* Start for S-Function (sldrtdo): '<S20>/Digital Output' */
    /*  Perform one-time calculations, such as computing constants */

    /* S-Function Block: <S20>/Digital Output */

    /* no initial value required */

    /* Start for S-Function (sldrtao): '<S20>/Analog Output' */

    /* S-Function Block: <S20>/Analog Output */

    /* no initial value required */

    /* End of Start for SubSystem: '<S5>/DAQ' */

    /* Start for Enabled SubSystem: '<S5>/Simulación' */
    ControlSystem_Refactorization_DW.Simulacin_MODE = false;
    (void) memset
      (&(ControlSystem_Refactorization_XDis.Modelodelreguladordepresinelectrnico_CSTATE),
       1,
       102*sizeof(boolean_T));

    /* Start for Iterator SubSystem: '<S21>/Modelo de los actuadores' */
    for (ForEach_itr_d = 0; ForEach_itr_d < 4; ForEach_itr_d++) {
      /* Start for RelationalOperator: '<S27>/Compare' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare =
        false;

      /* Start for RelationalOperator: '<S28>/Compare' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_c =
        false;

      /* Start for RelationalOperator: '<S29>/Compare' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_n =
        false;

      /* Start for RelationalOperator: '<S30>/Compare' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_i =
        false;

      /* Start for RelationalOperator: '<S31>/Compare' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].Compare_a =
        false;

      /* Start for SignalConversion generated from: '<S33>/Enable' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        HiddenBuf_InsertedFor_CurvaturaActuador1_at_inport_1 = false;

      /* Start for SignalConversion generated from: '<S34>/Enable' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        HiddenBuf_InsertedFor_CurvaturaActuador2_at_inport_1 = false;

      /* Start for SignalConversion generated from: '<S35>/Enable' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        HiddenBuf_InsertedFor_CurvaturaActuador3_at_inport_1 = false;

      /* Start for SignalConversion generated from: '<S36>/Enable' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        HiddenBuf_InsertedFor_CurvaturaActuador4_at_inport_1 = false;

      /* Start for SignalConversion generated from: '<S37>/Enable' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        HiddenBuf_InsertedFor_CurvaturaActuador5_at_inport_1 = false;

      /* Start for MultiPortSwitch: '<S26>/Index Vector1' */
      ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
        IndexVector1 = 0.0;

      /* Start for Enabled SubSystem: '<S26>/Curvatura Actuador 1' */
      ControlSystem_Refactorization_CurvaturaActuador5_Start
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1);

      /* End of Start for SubSystem: '<S26>/Curvatura Actuador 1' */

      /* Start for Enabled SubSystem: '<S26>/Curvatura Actuador 2' */
      ControlSystem_Refactorization_CurvaturaActuador4_Start
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2);

      /* End of Start for SubSystem: '<S26>/Curvatura Actuador 2' */

      /* Start for Enabled SubSystem: '<S26>/Curvatura Actuador 3' */
      ControlSystem_Refactorization_CurvaturaActuador4_Start
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3);

      /* End of Start for SubSystem: '<S26>/Curvatura Actuador 3' */

      /* Start for Enabled SubSystem: '<S26>/Curvatura Actuador 4' */
      ControlSystem_Refactorization_CurvaturaActuador4_Start
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4);

      /* End of Start for SubSystem: '<S26>/Curvatura Actuador 4' */

      /* Start for Enabled SubSystem: '<S26>/Curvatura Actuador 5' */
      ControlSystem_Refactorization_CurvaturaActuador5_Start
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5,
         &ControlSystem_Refactorization_DW.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5, &_rtXdis->CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5);

      /* End of Start for SubSystem: '<S26>/Curvatura Actuador 5' */
    }

    /* End of Start for SubSystem: '<S21>/Modelo de los actuadores' */
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
    /* InitializeConditions for Derivative: '<S42>/Derivative' */
    ControlSystem_Refactorization_DW.TimeStampA = (rtInf);
    ControlSystem_Refactorization_DW.TimeStampB = (rtInf);

    /* SystemInitialize for Saturate: '<S42>/Saturación de tensión' incorporates:
     *  Outport: '<S42>/SeñalControl'
     */
    ControlSystem_Refactorization_B.Saturacindetensin =
      ControlSystem_Refactorization_P.SealControl_Y0_p;

    /* SystemInitialize for Sum: '<S42>/Add' incorporates:
     *  Outport: '<S42>/Error estacionario'
     */
    ControlSystem_Refactorization_B.Add =
      ControlSystem_Refactorization_P.Errorestacionario_Y0_m;

    /* SystemInitialize for Derivative: '<S42>/Derivative' incorporates:
     *  Outport: '<S42>/Error derivativo'
     */
    ControlSystem_Refactorization_B.Derivative =
      ControlSystem_Refactorization_P.Errorderivativo_Y0_b;

    /* End of SystemInitialize for SubSystem: '<S7>/Control de Presión' */

    /* SystemInitialize for Enabled SubSystem: '<S7>/Control de Curvatura' */
    /* InitializeConditions for Derivative: '<S41>/Derivative1' */
    ControlSystem_Refactorization_DW.TimeStampA_b = (rtInf);
    ControlSystem_Refactorization_DW.TimeStampB_f = (rtInf);

    /* SystemInitialize for Atomic SubSystem: '<S41>/Controlador de posición PID' */
    /* InitializeConditions for Integrator: '<S43>/Integrator' */
    ControlSystem_Refactorization_X.Integrator_CSTATE =
      ControlSystem_Refactorization_P.Integrator_IC;

    /* InitializeConditions for Derivative: '<S43>/Derivative' */
    ControlSystem_Refactorization_DW.TimeStampA_k = (rtInf);
    ControlSystem_Refactorization_DW.TimeStampB_b = (rtInf);

    /* End of SystemInitialize for SubSystem: '<S41>/Controlador de posición PID' */

    /* SystemInitialize for Saturate: '<S41>/Saturación de tensión' incorporates:
     *  Outport: '<S41>/SeñalControl'
     */
    ControlSystem_Refactorization_B.Saturacindetensin_k =
      ControlSystem_Refactorization_P.SealControl_Y0;

    /* SystemInitialize for Sum: '<S41>/Add1' incorporates:
     *  Outport: '<S41>/Error estacionario'
     */
    ControlSystem_Refactorization_B.Add1 =
      ControlSystem_Refactorization_P.Errorestacionario_Y0;

    /* SystemInitialize for Derivative: '<S41>/Derivative1' incorporates:
     *  Outport: '<S41>/Error derivativo'
     */
    ControlSystem_Refactorization_B.Derivative1 =
      ControlSystem_Refactorization_P.Errorderivativo_Y0;

    /* End of SystemInitialize for SubSystem: '<S7>/Control de Curvatura' */

    /* SystemInitialize for Enabled SubSystem: '<S5>/DAQ' */
    /* SystemInitialize for MATLAB Function: '<S20>/MATLAB Function' */
    ControlSystem_Refactorization_DW.sfEvent_d =
      ControlSystem_Refactorization_CALL_EVENT;

    /* SystemInitialize for MATLAB Function: '<S20>/MATLAB Function1' */
    ControlSystem_Refactorization_DW.sfEvent =
      ControlSystem_Refactorization_CALL_EVENT;

    /* SystemInitialize for Outport: '<S20>/Presión Regulador' */
    ControlSystem_Refactorization_B.press =
      ControlSystem_Refactorization_P.PresinRegulador_Y0;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S22>/Presión actuadores' incorporates:
     *  Outport: '<S20>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
      [0] = ControlSystem_Refactorization_P.PresinActuadores_Y0;

    /* SystemInitialize for Outport: '<S20>/Curvatura Actuadores' */
    ControlSystem_Refactorization_B.curv[0] =
      ControlSystem_Refactorization_P.CurvaturaActuadores_Y0;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S22>/Presión actuadores' incorporates:
     *  Outport: '<S20>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
      [1] = ControlSystem_Refactorization_P.PresinActuadores_Y0;

    /* SystemInitialize for Outport: '<S20>/Curvatura Actuadores' */
    ControlSystem_Refactorization_B.curv[1] =
      ControlSystem_Refactorization_P.CurvaturaActuadores_Y0;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S22>/Presión actuadores' incorporates:
     *  Outport: '<S20>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
      [2] = ControlSystem_Refactorization_P.PresinActuadores_Y0;

    /* SystemInitialize for Outport: '<S20>/Curvatura Actuadores' */
    ControlSystem_Refactorization_B.curv[2] =
      ControlSystem_Refactorization_P.CurvaturaActuadores_Y0;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S22>/Presión actuadores' incorporates:
     *  Outport: '<S20>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
      [3] = ControlSystem_Refactorization_P.PresinActuadores_Y0;

    /* SystemInitialize for Outport: '<S20>/Curvatura Actuadores' */
    ControlSystem_Refactorization_B.curv[3] =
      ControlSystem_Refactorization_P.CurvaturaActuadores_Y0;

    /* End of SystemInitialize for SubSystem: '<S5>/DAQ' */

    /* SystemInitialize for Enabled SubSystem: '<S5>/Simulación' */
    /* InitializeConditions for TransferFcn: '<S21>/Modelo del regulador de presión electrónico' */
    ControlSystem_Refactorization_X.Modelodelreguladordepresinelectrnico_CSTATE
      [0] = 0.0;
    ControlSystem_Refactorization_X.Modelodelreguladordepresinelectrnico_CSTATE
      [1] = 0.0;

    /* End of SystemInitialize for SubSystem: '<S5>/Simulación' */
    /* SystemInitialize for Enabled SubSystem: '<S5>/Simulación' */
    /* SystemInitialize for Iterator SubSystem: '<S21>/Modelo de los actuadores' */
    for (ForEach_itr_d = 0; ForEach_itr_d < 4; ForEach_itr_d++) {
      /* SystemInitialize for Enabled SubSystem: '<S5>/Simulación' */
      /* SystemInitialize for Iterator SubSystem: '<S21>/Modelo de los actuadores' */
      /* SystemInitialize for Enabled SubSystem: '<S26>/Curvatura Actuador 1' */
      ControlSystem_Refactorization_CurvaturaActuador5_Init
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador1,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador1);

      /* End of SystemInitialize for SubSystem: '<S26>/Curvatura Actuador 1' */

      /* SystemInitialize for Enabled SubSystem: '<S26>/Curvatura Actuador 2' */
      ControlSystem_Refactorization_CurvaturaActuador4_Init
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador2,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador2);

      /* End of SystemInitialize for SubSystem: '<S26>/Curvatura Actuador 2' */

      /* SystemInitialize for Enabled SubSystem: '<S26>/Curvatura Actuador 3' */
      ControlSystem_Refactorization_CurvaturaActuador4_Init
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador3,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador3);

      /* End of SystemInitialize for SubSystem: '<S26>/Curvatura Actuador 3' */

      /* SystemInitialize for Enabled SubSystem: '<S26>/Curvatura Actuador 4' */
      ControlSystem_Refactorization_CurvaturaActuador4_Init
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador4,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador4);

      /* End of SystemInitialize for SubSystem: '<S26>/Curvatura Actuador 4' */

      /* SystemInitialize for Enabled SubSystem: '<S26>/Curvatura Actuador 5' */
      ControlSystem_Refactorization_CurvaturaActuador5_Init
        (&ControlSystem_Refactorization_B.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5,
         &ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador5,
         &ControlSystem_Refactorization_X.CoreSubsys_pnae[ForEach_itr_d].
         CurvaturaActuador5);

      /* End of SystemInitialize for SubSystem: '<S26>/Curvatura Actuador 5' */
      /* End of SystemInitialize for SubSystem: '<S21>/Modelo de los actuadores' */
      /* End of SystemInitialize for SubSystem: '<S5>/Simulación' */
    }

    /* End of SystemInitialize for SubSystem: '<S21>/Modelo de los actuadores' */
    /* End of SystemInitialize for SubSystem: '<S5>/Simulación' */
    /* SystemInitialize for Enabled SubSystem: '<S5>/Simulación' */
    /* SystemInitialize for TransferFcn: '<S21>/Modelo del regulador de presión electrónico' incorporates:
     *  Outport: '<S21>/Presión Regulador'
     */
    ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico =
      ControlSystem_Refactorization_P.PresinRegulador_Y0_f;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S26>/Presión Actuador' incorporates:
     *  Outport: '<S21>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [0] = ControlSystem_Refactorization_P.PresinActuadores_Y0_o;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S26>/Curvatura Actuador' incorporates:
     *  Outport: '<S21>/Curvatura Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [0] = ControlSystem_Refactorization_P.CurvaturaActuadores_Y0_i;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S26>/Presión Actuador' incorporates:
     *  Outport: '<S21>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [1] = ControlSystem_Refactorization_P.PresinActuadores_Y0_o;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S26>/Curvatura Actuador' incorporates:
     *  Outport: '<S21>/Curvatura Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [1] = ControlSystem_Refactorization_P.CurvaturaActuadores_Y0_i;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S26>/Presión Actuador' incorporates:
     *  Outport: '<S21>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [2] = ControlSystem_Refactorization_P.PresinActuadores_Y0_o;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S26>/Curvatura Actuador' incorporates:
     *  Outport: '<S21>/Curvatura Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [2] = ControlSystem_Refactorization_P.CurvaturaActuadores_Y0_i;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S26>/Presión Actuador' incorporates:
     *  Outport: '<S21>/Presión Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
      [3] = ControlSystem_Refactorization_P.PresinActuadores_Y0_o;

    /* SystemInitialize for ForEachSliceAssignment generated from: '<S26>/Curvatura Actuador' incorporates:
     *  Outport: '<S21>/Curvatura Actuadores'
     */
    ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
      [3] = ControlSystem_Refactorization_P.CurvaturaActuadores_Y0_i;

    /* End of SystemInitialize for SubSystem: '<S5>/Simulación' */
  }
}

/* Model terminate function */
void ControlSystem_Refactorization_terminate(void)
{
  /* Terminate for Enabled SubSystem: '<S5>/DAQ' */
  /* Terminate for S-Function (sldrtdo): '<S20>/Digital Output' */

  /* S-Function Block: <S20>/Digital Output */

  /* no final value required */

  /* Terminate for S-Function (sldrtao): '<S20>/Analog Output' */

  /* S-Function Block: <S20>/Analog Output */

  /* no final value required */

  /* End of Terminate for SubSystem: '<S5>/DAQ' */
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
    mdlTsMap[2] = 2;
    ControlSystem_Refactorization_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    ControlSystem_Refactorization_M->Timing.sampleTimes =
      (&ControlSystem_Refactorization_M->Timing.sampleTimesArray[0]);
    ControlSystem_Refactorization_M->Timing.offsetTimes =
      (&ControlSystem_Refactorization_M->Timing.offsetTimesArray[0]);

    /* task periods */
    ControlSystem_Refactorization_M->Timing.sampleTimes[0] = (0.0);
    ControlSystem_Refactorization_M->Timing.sampleTimes[1] = (0.0001);
    ControlSystem_Refactorization_M->Timing.sampleTimes[2] = (0.1);

    /* task offsets */
    ControlSystem_Refactorization_M->Timing.offsetTimes[0] = (0.0);
    ControlSystem_Refactorization_M->Timing.offsetTimes[1] = (0.0);
    ControlSystem_Refactorization_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(ControlSystem_Refactorization_M,
             &ControlSystem_Refactorization_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      ControlSystem_Refactorization_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    ControlSystem_Refactorization_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(ControlSystem_Refactorization_M, -1);
  ControlSystem_Refactorization_M->Timing.stepSize0 = 0.0001;
  ControlSystem_Refactorization_M->Timing.stepSize1 = 0.0001;
  ControlSystem_Refactorization_M->Timing.stepSize2 = 0.1;

  /* External mode info */
  ControlSystem_Refactorization_M->Sizes.checksums[0] = (3003190588U);
  ControlSystem_Refactorization_M->Sizes.checksums[1] = (2619320984U);
  ControlSystem_Refactorization_M->Sizes.checksums[2] = (1265173108U);
  ControlSystem_Refactorization_M->Sizes.checksums[3] = (3562307661U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[30];
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
      &ControlSystem_Refactorization_DW.DAQ_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
      CurvaturaActuador5.CurvaturaActuador5_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
      CurvaturaActuador4.CurvaturaActuador4_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
      CurvaturaActuador3.CurvaturaActuador4_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
      CurvaturaActuador2.CurvaturaActuador4_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
      CurvaturaActuador1.CurvaturaActuador5_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.ControldeCurvatura_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.ControldeCurvatura_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &ControlSystem_Refactorization_DW.ControldePresin_SubsysRanBC;
    systemRan[28] = &rtAlwaysEnabled;
    systemRan[29] = &rtAlwaysEnabled;
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
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      0] = EstadoValvula_Bloquear;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      1] = EstadoValvula_Bloquear;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      2] = EstadoValvula_Bloquear;
    ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4[
      3] = EstadoValvula_Bloquear;
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
    dtInfo.numDataTypes = 72;
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
  ControlSystem_Refactorization_M->Sizes.numSampTimes = (3);/* Number of sample times */
  ControlSystem_Refactorization_M->Sizes.numBlocks = (190);/* Number of blocks */
  ControlSystem_Refactorization_M->Sizes.numBlockIO = (49);/* Number of block outputs */
  ControlSystem_Refactorization_M->Sizes.numBlockPrms = (155);/* Sum of parameter "widths" */
  return ControlSystem_Refactorization_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
