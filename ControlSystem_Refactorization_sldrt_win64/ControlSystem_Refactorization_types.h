/*
 * ControlSystem_Refactorization_types.h
 *
 * Trial License - for use to evaluate programs for possible purchase as
 * an end-user only.
 *
 * Code generation for model "ControlSystem_Refactorization".
 *
 * Model version              : 2.31
 * Simulink Coder version : 25.1 (R2025a) 21-Nov-2024
 * C source code generated on : Sat Sep 13 19:46:30 2025
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
#include "modo_control.h"
#include "referencia_control.h"
#include "myvalvestates.h"
#include "controlador.h"
#include "act_position.h"
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
  EstadoValvula estadoValvula;
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
  EstadoValvula estadoValvula;
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
  real_T referenciaControl;
  Controlador controlador;
  real_T simulacionActiva;
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

#ifndef DEFINED_TYPEDEF_FOR_slBus4_Global_
#define DEFINED_TYPEDEF_FOR_slBus4_Global_

typedef struct {
  real_T realimentacionControl;
  real_T errorEstacionario;
  real_T errorDerivativo;
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

#ifndef struct_tag_G5Ngtf6UwfZyYzVc1FFaYG
#define struct_tag_G5Ngtf6UwfZyYzVc1FFaYG

struct tag_G5Ngtf6UwfZyYzVc1FFaYG
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_G5Ngtf6UwfZyYzVc1FFaYG */

#ifndef typedef_elegirTensionesElectrovalvulas_ControlSystem_Refactorization_T
#define typedef_elegirTensionesElectrovalvulas_ControlSystem_Refactorization_T

typedef struct tag_G5Ngtf6UwfZyYzVc1FFaYG
  elegirTensionesElectrovalvulas_ControlSystem_Refactorization_T;

#endif
    /* typedef_elegirTensionesElectrovalvulas_ControlSystem_Refactorization_T */

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

#ifndef struct_tag_s3Zh1fqUhMb4DUz4uJXlqfD
#define struct_tag_s3Zh1fqUhMb4DUz4uJXlqfD

struct tag_s3Zh1fqUhMb4DUz4uJXlqfD
{
  real_T presionRegulador;
  real_T presionesEquilibrio[4];
  real_T actuador[4];
};

#endif                                 /* struct_tag_s3Zh1fqUhMb4DUz4uJXlqfD */

#ifndef typedef_s3Zh1fqUhMb4DUz4uJXlqfD_ControlSystem_Refactorization_T
#define typedef_s3Zh1fqUhMb4DUz4uJXlqfD_ControlSystem_Refactorization_T

typedef struct tag_s3Zh1fqUhMb4DUz4uJXlqfD
  s3Zh1fqUhMb4DUz4uJXlqfD_ControlSystem_Refactorization_T;

#endif     /* typedef_s3Zh1fqUhMb4DUz4uJXlqfD_ControlSystem_Refactorization_T */

#ifndef struct_tag_s7ZPPf7C83RtBPv6RIN9RQG
#define struct_tag_s7ZPPf7C83RtBPv6RIN9RQG

struct tag_s7ZPPf7C83RtBPv6RIN9RQG
{
  real_T estacionaria;
  real_T derivativa;
  real_T equilibrioPresiones;
};

#endif                                 /* struct_tag_s7ZPPf7C83RtBPv6RIN9RQG */

#ifndef typedef_s7ZPPf7C83RtBPv6RIN9RQG_ControlSystem_Refactorization_T
#define typedef_s7ZPPf7C83RtBPv6RIN9RQG_ControlSystem_Refactorization_T

typedef struct tag_s7ZPPf7C83RtBPv6RIN9RQG
  s7ZPPf7C83RtBPv6RIN9RQG_ControlSystem_Refactorization_T;

#endif     /* typedef_s7ZPPf7C83RtBPv6RIN9RQG_ControlSystem_Refactorization_T */

#ifndef struct_tag_s0BuO0sMFvbwNcEVTZBihWB
#define struct_tag_s0BuO0sMFvbwNcEVTZBihWB

struct tag_s0BuO0sMFvbwNcEVTZBihWB
{
  real_T estacionario;
  real_T derivativo;
};

#endif                                 /* struct_tag_s0BuO0sMFvbwNcEVTZBihWB */

#ifndef typedef_s0BuO0sMFvbwNcEVTZBihWB_ControlSystem_Refactorization_T
#define typedef_s0BuO0sMFvbwNcEVTZBihWB_ControlSystem_Refactorization_T

typedef struct tag_s0BuO0sMFvbwNcEVTZBihWB
  s0BuO0sMFvbwNcEVTZBihWB_ControlSystem_Refactorization_T;

#endif     /* typedef_s0BuO0sMFvbwNcEVTZBihWB_ControlSystem_Refactorization_T */

#ifndef struct_tag_QttgpUQSlreahlCDZyHl1E
#define struct_tag_QttgpUQSlreahlCDZyHl1E

struct tag_QttgpUQSlreahlCDZyHl1E
{
  int32_T isInitialized;
  boolean_T controlHabilitado;
  ModoControl modoControl;
  ParametroControl parametroControl;
  real_T actuadorSeleccionado;
  real_T referencias[4];
  s3Zh1fqUhMb4DUz4uJXlqfD_ControlSystem_Refactorization_T realimentaciones;
  s7ZPPf7C83RtBPv6RIN9RQG_ControlSystem_Refactorization_T tolerancias;
  real_T errores[4];
  s0BuO0sMFvbwNcEVTZBihWB_ControlSystem_Refactorization_T errorControl;
  boolean_T actuadoresActivos[4];
  EstadoValvula estadoValvulas[4];
};

#endif                                 /* struct_tag_QttgpUQSlreahlCDZyHl1E */

#ifndef typedef_sequential_autonomousControlLogic_ControlSystem_Refactorization_T
#define typedef_sequential_autonomousControlLogic_ControlSystem_Refactorization_T

typedef struct tag_QttgpUQSlreahlCDZyHl1E
  sequential_autonomousControlLogic_ControlSystem_Refactorization_T;

#endif
/* typedef_sequential_autonomousControlLogic_ControlSystem_Refactorization_T */

/* Parameters for system: '<S18>/Flujo de aire en los actuadores' */
typedef struct P_CoreSubsys_ControlSystem_Refactorization_gmy_T_
  P_CoreSubsys_ControlSystem_Refactorization_gmy_T;

/* Parameters for system: '<S24>/Curvatura Actuador 5' */
typedef struct P_CurvaturaActuador5_ControlSystem_Refactorization_T_
  P_CurvaturaActuador5_ControlSystem_Refactorization_T;

/* Parameters for system: '<S24>/Curvatura Actuador 4' */
typedef struct P_CurvaturaActuador4_ControlSystem_Refactorization_T_
  P_CurvaturaActuador4_ControlSystem_Refactorization_T;

/* Parameters for system: '<S19>/Modelo de los actuadores' */
typedef struct P_CoreSubsys_ControlSystem_Refactorization_gmy0_T_
  P_CoreSubsys_ControlSystem_Refactorization_gmy0_T;

/* Parameters (default storage) */
typedef struct P_ControlSystem_Refactorization_T_
  P_ControlSystem_Refactorization_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_ControlSystem_Refactorization_T
  RT_MODEL_ControlSystem_Refactorization_T;

#endif                              /* ControlSystem_Refactorization_types_h_ */
