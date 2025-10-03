/*
 * ControlSystem_Refactorization_types.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "ControlSystem_Refactorization".
 *
 * Model version              : 2.13
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Fri Oct  3 17:02:47 2025
 *
 * Target selection: sldrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ControlSystem_Refactorization_types_h_
#define ControlSystem_Refactorization_types_h_
#include "rtwtypes.h"
#include "referencia_control.h"
#include "modo_control.h"
#include "controlador.h"
#include "act_position.h"
#include "myvalvestates.h"
#ifndef DEFINED_TYPEDEF_FOR_Referencia_
#define DEFINED_TYPEDEF_FOR_Referencia_

typedef struct {
  real_T presion;
  real_T curvatura;
} Referencia;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Global_
#define DEFINED_TYPEDEF_FOR_Global_

typedef struct {
  boolean_T activo;
  real_T indice;
  Referencia Referencia;
} Global;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ControlManual_
#define DEFINED_TYPEDEF_FOR_ControlManual_

typedef struct {
  boolean_T valvulaCerrada;
} ControlManual;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Configuracion_
#define DEFINED_TYPEDEF_FOR_Configuracion_

typedef struct {
  Global Global;
  ControlManual ControlManual;
} Configuracion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ControlAutomatico_
#define DEFINED_TYPEDEF_FOR_ControlAutomatico_

typedef struct {
  boolean_T valvulaCerrada;
  ActuadorPosicionado actuadorPosicionado;
} ControlAutomatico;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Realimentacion_
#define DEFINED_TYPEDEF_FOR_Realimentacion_

typedef struct {
  real_T presion;
  real_T curvatura;
} Realimentacion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Estado_
#define DEFINED_TYPEDEF_FOR_Estado_

typedef struct {
  ControlAutomatico ControlAutomatico;
  Realimentacion Realimentacion;
} Estado;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBusActuador_
#define DEFINED_TYPEDEF_FOR_slBusActuador_

typedef struct {
  Configuracion Configuracion;
  Estado Estado;
} slBusActuador;

#endif

#ifndef DEFINED_TYPEDEF_FOR_referenciaControl_
#define DEFINED_TYPEDEF_FOR_referenciaControl_

typedef struct {
  real_T presion;
  real_T curvatura;
} referenciaControl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ToleranciaPresion_
#define DEFINED_TYPEDEF_FOR_ToleranciaPresion_

typedef struct {
  real_T estacionaria;
  real_T derivativa;
} ToleranciaPresion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ToleranciaCurvatura_
#define DEFINED_TYPEDEF_FOR_ToleranciaCurvatura_

typedef struct {
  real_T estacionaria;
  real_T derivativa;
} ToleranciaCurvatura;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBus1_Global_
#define DEFINED_TYPEDEF_FOR_slBus1_Global_

typedef struct {
  real_T numActuadores;
  ModoControl modoControl;
  ParametroControl parametroControl;
  Controlador controlador;
  referenciaControl referenciaControl;
  boolean_T simulacionActiva;
  real_T toleranciaEquilibrioPresiones;
  ToleranciaPresion ToleranciaPresion;
  ToleranciaCurvatura ToleranciaCurvatura;
} slBus1_Global;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBus2_ControlManual_
#define DEFINED_TYPEDEF_FOR_slBus2_ControlManual_

typedef struct {
  real_T actuadorSeleccionado;
} slBus2_ControlManual;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBus3_Configuracion_
#define DEFINED_TYPEDEF_FOR_slBus3_Configuracion_

typedef struct {
  slBus1_Global Global;
  slBus2_ControlManual ControlManual;
} slBus3_Configuracion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_realimentacionControl_
#define DEFINED_TYPEDEF_FOR_realimentacionControl_

typedef struct {
  real_T presion;
  real_T curvatura;
} realimentacionControl;

#endif

#ifndef DEFINED_TYPEDEF_FOR_errorEstacionario_
#define DEFINED_TYPEDEF_FOR_errorEstacionario_

typedef struct {
  real_T presion;
  real_T curvatura;
} errorEstacionario;

#endif

#ifndef DEFINED_TYPEDEF_FOR_errorDerivativo_
#define DEFINED_TYPEDEF_FOR_errorDerivativo_

typedef struct {
  real_T presion;
  real_T curvatura;
} errorDerivativo;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBus4_Global_
#define DEFINED_TYPEDEF_FOR_slBus4_Global_

typedef struct {
  real_T tensionControl;
  realimentacionControl realimentacionControl;
  errorEstacionario errorEstacionario;
  errorDerivativo errorDerivativo;
} slBus4_Global;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBus5_ControlAutomatico_
#define DEFINED_TYPEDEF_FOR_slBus5_ControlAutomatico_

typedef struct {
  real_T actuadorSeleccionado;
} slBus5_ControlAutomatico;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBus6_Estado_
#define DEFINED_TYPEDEF_FOR_slBus6_Estado_

typedef struct {
  slBus4_Global Global;
  slBus5_ControlAutomatico ControlAutomatico;
} slBus6_Estado;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBusSistema_
#define DEFINED_TYPEDEF_FOR_slBusSistema_

typedef struct {
  slBus3_Configuracion Configuracion;
  slBus6_Estado Estado;
} slBusSistema;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBus1_Estado_
#define DEFINED_TYPEDEF_FOR_slBus1_Estado_

typedef struct {
  real_T presion;
} slBus1_Estado;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBusRegulador_
#define DEFINED_TYPEDEF_FOR_slBusRegulador_

typedef struct {
  slBus1_Estado Estado;
} slBusRegulador;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ConexionActuadores_
#define DEFINED_TYPEDEF_FOR_ConexionActuadores_

typedef struct {
  uint16_T terminalA;
  uint16_T terminalB;
} ConexionActuadores;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBus1_Configuracion_
#define DEFINED_TYPEDEF_FOR_slBus1_Configuracion_

typedef struct {
  ConexionActuadores ConexionActuadores[4];
  uint16_T PuertosDigitales[8];
} slBus1_Configuracion;

#endif

#ifndef DEFINED_TYPEDEF_FOR_slBusElectroValvulas_
#define DEFINED_TYPEDEF_FOR_slBusElectroValvulas_

typedef struct {
  slBus1_Configuracion Configuracion;
} slBusElectroValvulas;

#endif

#ifndef struct_tag_ZL3n9Q5Ep0XRki5EATNaWH
#define struct_tag_ZL3n9Q5Ep0XRki5EATNaWH

struct tag_ZL3n9Q5Ep0XRki5EATNaWH
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_ZL3n9Q5Ep0XRki5EATNaWH */

#ifndef typedef_selectElectrovalvesVoltage_ControlSystem_Refactorization_T
#define typedef_selectElectrovalvesVoltage_ControlSystem_Refactorization_T

typedef struct tag_ZL3n9Q5Ep0XRki5EATNaWH
  selectElectrovalvesVoltage_ControlSystem_Refactorization_T;

#endif  /* typedef_selectElectrovalvesVoltage_ControlSystem_Refactorization_T */

#ifndef struct_tag_tNTZQzHg4pRnqsm6ksfZPG
#define struct_tag_tNTZQzHg4pRnqsm6ksfZPG

struct tag_tNTZQzHg4pRnqsm6ksfZPG
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_tNTZQzHg4pRnqsm6ksfZPG */

#ifndef typedef_manualControlLogic_ControlSystem_Refactorization_T
#define typedef_manualControlLogic_ControlSystem_Refactorization_T

typedef struct tag_tNTZQzHg4pRnqsm6ksfZPG
  manualControlLogic_ControlSystem_Refactorization_T;

#endif          /* typedef_manualControlLogic_ControlSystem_Refactorization_T */

#ifndef struct_tag_GvdguwzjehF0xqhwdOmYeH
#define struct_tag_GvdguwzjehF0xqhwdOmYeH

struct tag_GvdguwzjehF0xqhwdOmYeH
{
  int32_T isInitialized;
  boolean_T controlHabilitado;
  ParametroControl parametroControl;
  real_T actuadorSeleccionado;
};

#endif                                 /* struct_tag_GvdguwzjehF0xqhwdOmYeH */

#ifndef typedef_sequential_autonomousControlLogic_ControlSystem_Refactorization_T
#define typedef_sequential_autonomousControlLogic_ControlSystem_Refactorization_T

typedef struct tag_GvdguwzjehF0xqhwdOmYeH
  sequential_autonomousControlLogic_ControlSystem_Refactorization_T;

#endif
/* typedef_sequential_autonomousControlLogic_ControlSystem_Refactorization_T */

/* Parameters for system: '<S21>/Flujo de aire en los actuadores' */
typedef struct P_CoreSubsys_ControlSystem_Refactorization_gmy_T_
  P_CoreSubsys_ControlSystem_Refactorization_gmy_T;

/* Parameters for system: '<S28>/Curvatura Actuador 5' */
typedef struct P_CurvaturaActuador5_ControlSystem_Refactorization_T_
  P_CurvaturaActuador5_ControlSystem_Refactorization_T;

/* Parameters for system: '<S22>/Modelo de los actuadores' */
typedef struct P_CoreSubsys_ControlSystem_Refactorization_gmy0_T_
  P_CoreSubsys_ControlSystem_Refactorization_gmy0_T;

/* Parameters (default storage) */
typedef struct P_ControlSystem_Refactorization_T_
  P_ControlSystem_Refactorization_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ControlSystem_Refactorization_T
  RT_MODEL_ControlSystem_Refactorization_T;

#endif                              /* ControlSystem_Refactorization_types_h_ */
