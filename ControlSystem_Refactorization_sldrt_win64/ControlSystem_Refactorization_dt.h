/*
 * ControlSystem_Refactorization_dt.h
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
  sizeof(referenciaControl),
  sizeof(ToleranciaPresion),
  sizeof(ToleranciaCurvatura),
  sizeof(slBus1_Global),
  sizeof(slBus2_ControlManual),
  sizeof(slBus3_Configuracion),
  sizeof(realimentacionControl),
  sizeof(errorEstacionario),
  sizeof(errorDerivativo),
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
  sizeof(EstadoValvula),
  sizeof(selectElectrovalvesVoltage_ControlSystem_Refactorization_T),
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
  "struct_F5uhD4669REqk8ilv99yzE",
  "struct_nCAIZ4xegaKiMIqo5f73mF",
  "ActuadorPosicionado",
  "struct_tRE3KLlDSnHtadVgB14kLF",
  "struct_bRez4MLern7xVfiUozLUE",
  "struct_kxHCIlyGRqOqeDC8u5LDZD",
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
  "struct_DkGQbEQRaYnkW0wi1G3WtH",
  "struct_gqzhm13gdWNDdNckRWO7HG",
  "struct_xRkashwzv8A9Egkx0x07ED",
  "struct_ONYdVClh8vS21U4bgEQqDB",
  "struct_I5jDjHa31eZijXPNVbrcSH",
  "struct_C5SahwPDV7IifNndgUxaVB",
  "referenciaControl",
  "ToleranciaPresion",
  "ToleranciaCurvatura",
  "slBus1_Global",
  "slBus2_ControlManual",
  "slBus3_Configuracion",
  "realimentacionControl",
  "errorEstacionario",
  "errorDerivativo",
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
  "EstadoValvula",
  "selectElectrovalvesVoltage_ControlSystem_Refactorization_T",
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
  { (char_T *)(&ControlSystem_Refactorization_B.sistema), 55, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_B.DataStoreRead3[0]), 34, 0, 8 },

  { (char_T *)
    (&ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport2
     [0]), 0, 0, 58 },

  { (char_T *)
    (&ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4
     [0]), 8, 0, 17 },

  { (char_T *)(&ControlSystem_Refactorization_B.modoControl), 17, 0, 1 },

  { (char_T *)
    (&ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Actuadoresposicionados_at_inport_0
     [0]), 23, 0, 4 },

  { (char_T *)(&ControlSystem_Refactorization_B.CoreSubsys_pnae[3].Constant), 0,
    0, 2 },

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

  { (char_T *)(&ControlSystem_Refactorization_DW.sistema), 55, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.actuadorBus[0]), 34, 0, 4 },

  { (char_T *)(&ControlSystem_Refactorization_DW.electroValvulas), 65, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.obj), 69, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.TimeStampA), 0, 0, 12 },

  { (char_T *)(&ControlSystem_Refactorization_DW.regulador), 59, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.AnalogOutput_PWORK), 11, 0, 4 },

  { (char_T *)(&ControlSystem_Refactorization_DW.sfEvent), 6, 0, 2 },

  { (char_T *)(&ControlSystem_Refactorization_DW.obj_b), 67, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.obj_k), 68, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.ControldePresin_SubsysRanBC), 2,
    0, 4 },

  { (char_T *)(&ControlSystem_Refactorization_DW.objisempty), 8, 0, 9 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador1.CurvaturaActuador5_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador1.CurvaturaActuador5_MODE), 8, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador2.CurvaturaActuador5_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador2.CurvaturaActuador5_MODE), 8, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador3.CurvaturaActuador5_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador3.CurvaturaActuador5_MODE), 8, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador4.CurvaturaActuador5_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador4.CurvaturaActuador5_MODE), 8, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador5.CurvaturaActuador5_SubsysRanBC), 2, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].
               CurvaturaActuador5.CurvaturaActuador5_MODE), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  35U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&ControlSystem_Refactorization_P.sistema), 55, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_P.actuadorBus[0]), 34, 0, 4 },

  { (char_T *)(&ControlSystem_Refactorization_P.electroValvulas), 65, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_P.regulador), 59, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_P.AnalogOutput_MaxMissedTicks), 0,
    0, 8 },

  { (char_T *)(&ControlSystem_Refactorization_P.DigitalOutput_BitMode), 6, 0, 21
  },

  { (char_T *)(&ControlSystem_Refactorization_P.CompareToConstant_const), 18, 0,
    4 },

  { (char_T *)(&ControlSystem_Refactorization_P.CompareToConstant7_const), 8, 0,
    1 },

  { (char_T *)(&ControlSystem_Refactorization_P.Errorestacionario_Y0), 27, 0, 1
  },

  { (char_T *)(&ControlSystem_Refactorization_P.Errorderivativo_Y0), 27, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_P.Errorestacionario_Y0_i), 27, 0,
    1 },

  { (char_T *)(&ControlSystem_Refactorization_P.Errorderivativo_Y0_b), 27, 0, 1
  },

  { (char_T *)(&ControlSystem_Refactorization_P.RefPresion1_Value), 0, 0, 40 },

  { (char_T *)(&ControlSystem_Refactorization_P.Constant_Value_f), 17, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_P.Constant1_Value_e), 35, 0, 1 },

  { (char_T *)(&ControlSystem_Refactorization_P.BloqueoManual1_Value), 8, 0, 9 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant_const),
    0, 0, 5 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant5_const),
    17, 0, 1 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant6_const),
    8, 0, 2 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador1.Curvatura_Y0),
    0, 0, 11 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador2.Curvatura_Y0),
    0, 0, 11 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador3.Curvatura_Y0),
    0, 0, 11 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador4.Curvatura_Y0),
    0, 0, 11 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador5.Curvatura_Y0),
    0, 0, 11 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pna.CompareToConstant5_const),
    17, 0, 1 },

  { (char_T *)
    (&ControlSystem_Refactorization_P.CoreSubsys_pna.CompareToConstant6_const),
    8, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  26U,
  rtPTransitions
};

/* [EOF] ControlSystem_Refactorization_dt.h */
