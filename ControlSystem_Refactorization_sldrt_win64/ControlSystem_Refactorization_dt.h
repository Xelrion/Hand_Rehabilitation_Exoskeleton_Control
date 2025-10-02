/*
 * ControlSystem_Refactorization_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(int64_T),
  sizeof(uint64_T),
  sizeof(ModoControl),
  sizeof(Controlador),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(EstadoValvula),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(ActuadorPosicionado),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(Referencia),
  sizeof(Global),
  sizeof(ControlManual),
  sizeof(Configuracion),
  sizeof(ControlAutomatico),
  sizeof(Realimentacion),
  sizeof(Estado),
  sizeof(slBusActuador),
  sizeof(ParametroControl),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(ToleranciaPresion),
  sizeof(ToleranciaCurvatura),
  sizeof(slBus1_Global),
  sizeof(slBus2_ControlManual),
  sizeof(slBus3_Configuracion),
  sizeof(slBus4_Global),
  sizeof(slBus5_ControlAutomatico),
  sizeof(slBus6_Estado),
  sizeof(slBusSistema),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(slBus1_Estado),
  sizeof(slBusRegulador),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(int32_T),
  sizeof(ConexionActuadores),
  sizeof(slBus1_Configuracion),
  sizeof(slBusElectroValvulas),
  sizeof(elegirTensionesElectrovalvulas_ControlSystem_Refactorization_T),
  sizeof(manualControlLogic_ControlSystem_Refactorization_T),
  sizeof(sequential_autonomousControlLogic_ControlSystem_Refactorization_T),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "physical_connection",
  "int64_T",
  "uint64_T",
  "ModoControl",
  "Controlador",
  "struct_CPSYnxCWethLU9QIJHM1EH",
  "struct_eXzH5KP5yBot48ZvxrXAwD",
  "EstadoValvula",
  "struct_H0LLDpqNeIsneCiFAA22oC",
  "struct_njQFvBN3sajhrwz4TxOHYC",
  "ActuadorPosicionado",
  "struct_uUwnPxxRWvgY1g0UOPPGc",
  "struct_cYVU3ufdQmpSwvT6knf62C",
  "struct_tlFSC06dcPiUE7LnTIKxKD",
  "Referencia",
  "Global",
  "ControlManual",
  "Configuracion",
  "ControlAutomatico",
  "Realimentacion",
  "Estado",
  "slBusActuador",
  "ParametroControl",
  "struct_SWu0u3MiLxjwa3mw20mbsC",
  "struct_K4jPPdC2VUeNVCoqVfEXBE",
  "struct_gqzhm13gdWNDdNckRWO7HG",
  "struct_pVDOHh28IFpckNXXMTOjb",
  "struct_EsKGlnl7tMxVQ4Aw6vHIyE",
  "struct_4FLGrzkPRph1CEQYLwGGKH",
  "struct_GU8cKbP31Z2HFzqsEOK2hF",
  "ToleranciaPresion",
  "ToleranciaCurvatura",
  "slBus1_Global",
  "slBus2_ControlManual",
  "slBus3_Configuracion",
  "slBus4_Global",
  "slBus5_ControlAutomatico",
  "slBus6_Estado",
  "slBusSistema",
  "struct_FkkBemg6kObzvG0s8LRyj",
  "struct_XXZnMkfGj5Fryu0nTp9aa",
  "slBus1_Estado",
  "slBusRegulador",
  "struct_QXbiDM4LWas2VFklHAWB0",
  "struct_9NxKN9xCAUQDM1OWkHgnuH",
  "struct_EG3YlqevsVKqNeA2JcpM5F",
  "ConexionActuadores",
  "slBus1_Configuracion",
  "slBusElectroValvulas",
  "elegirTensionesElectrovalvulas_ControlSystem_Refactorization_T",
  "manualControlLogic_ControlSystem_Refactorization_T",
  "sequential_autonomousControlLogic_ControlSystem_Refactorization_T",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&ControlSystem_Refactorization_B.sistema), 52, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_B.DataStoreRead3[0]), 35, 0, 8 },

  { (char_T *)
    (&ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_Simulacin_at_inport_3),
    0, 0, 47 },

  { (char_T *)(&ControlSystem_Refactorization_B.OR), 8, 0, 7 },

  { (char_T *)
    (&ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Actuadoresposicionados_at_inport_0
     [0]), 24, 0, 4 },

  { (char_T *)(&ControlSystem_Refactorization_B.CoreSubsys_pnae[3].IndexVector1),
    0, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_B.CoreSubsys_pnae[3].Compare), 8,
    0, 10 },

  { (char_T *)(&ControlSystem_Refactorization_B.CoreSubsys_pnae[3].
               CurvaturaActuador1.CurvAct), 0, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_B.CoreSubsys_pnae[3].
               CurvaturaActuador2.CurvAct), 0, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_B.CoreSubsys_pnae[3].
               CurvaturaActuador3.CurvAct), 0, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_B.CoreSubsys_pnae[3].
               CurvaturaActuador4.CurvAct), 0, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_B.CoreSubsys_pnae[3].
               CurvaturaActuador5.CurvAct), 0, 0, 1 }
  ,

  { (char_T *)(&ControlSystem_Refactorization_DW.obj), 65, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.sistema), 52, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.actuadorBus[0]), 35, 0, 4 },

  { (char_T *)(&ControlSystem_Refactorization_DW.electroValvulas), 62, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.TimeStampA), 0, 0, 12 },

  { (char_T *)(&ControlSystem_Refactorization_DW.regulador), 56, 0, 1 },

  { (char_T *)
    (&ControlSystem_Refactorization_DW.TAQSigLogging_InsertedFor_DATOSDEACTUADORES_at_outport_1_PWORK.AQHandles),
    11, 0, 5 },

  { (char_T *)(&ControlSystem_Refactorization_DW.sfEvent), 6, 0, 2 },

  { (char_T *)(&ControlSystem_Refactorization_DW.obj_b), 63, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.obj_k), 64, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.ControldePresin_SubsysRanBC), 2,
    0, 4 },

  { (char_T *)(&ControlSystem_Refactorization_DW.objisempty), 8, 0, 9 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador1.CurvaturaActuador5_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador1.CurvaturaActuador5_MODE), 8, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador2.CurvaturaActuador4_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador2.CurvaturaActuador4_MODE), 8, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador3.CurvaturaActuador4_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador3.CurvaturaActuador4_MODE), 8, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador4.CurvaturaActuador4_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador4.CurvaturaActuador4_MODE), 8, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador5.CurvaturaActuador5_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador5.CurvaturaActuador5_MODE), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  34U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&ControlSystem_Refactorization_P.sistema), 52, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_P.actuadorBus[0]), 35, 0, 4 },

  { (char_T *)(&ControlSystem_Refactorization_P.electroValvulas), 62, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_P.regulador), 56, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_P.AnalogInput_MaxMissedTicks), 0,
    0, 8 },

  { (char_T *)(&ControlSystem_Refactorization_P.DigitalOutput_BitMode), 6, 0, 21
  },

  { (char_T *)(&ControlSystem_Refactorization_P.CompareToConstant_const), 18, 0,
    4 },

  { (char_T *)(&ControlSystem_Refactorization_P.PresinActuadores_Y0), 0, 0, 26 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant_const),
    0, 0, 5 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant5_const),
    17, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_P.CoreSubsys_pnae.Constant_Value),
    0, 0, 1 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador1.Out1_Y0),
    0, 0, 11 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador2.Out1_Y0),
    0, 0, 11 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador3.Out1_Y0),
    0, 0, 11 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador4.Out1_Y0),
    0, 0, 11 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador5.Out1_Y0),
    0, 0, 11 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pna.CompareToConstant5_const),
    17, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_P.CoreSubsys_pna.Constant_Value),
    0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  18U,
  rtPTransitions
};

/* [EOF] ControlSystem_Refactorization_dt.h */
