/*
 * ControlSystem_Refactorization_data.c
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

/* Block parameters (default storage) */
P_ControlSystem_Refactorization_T ControlSystem_Refactorization_P = {
  /* Variable: sistema
   * Referenced by: '<Root>/Data Store Memory1'
   */
  {
    {
      {
        4.0,
        ModoControl_Manual,
        ParametroControl_Presion,
        0.0,
        Controlador_Presion,
        0.0,
        0.0,

        {
          0.0,
          0.0
        },

        {
          0.0,
          0.0
        }
      },

      {
        0.0
      }
    },

    {
      {
        0.0,
        0.0,
        0.0
      },

      {
        0.0
      }
    }
  },

  /* Variable: actuadorBus
   * Referenced by: '<Root>/Data Store Memory'
   */
  { {
      {
        {
          0,
          1.0,

          {
            0.0,
            0.0
          }
        },

        {
          EstadoValvula_Bloquear
        }
      },

      {
        {
          EstadoValvula_Bloquear,
          ActuadorPosicionado_Desposicionado
        },

        {
          0.0,
          0.0
        }
      }
    }, { {
        {
          0,
          2.0,

          {
            0.0,
            0.0
          }
        },

        {
          EstadoValvula_Bloquear
        }
      },

      {
        {
          EstadoValvula_Bloquear,
          ActuadorPosicionado_Desposicionado
        },

        {
          0.0,
          0.0
        }
      }
    }, { {
        {
          0,
          3.0,

          {
            0.0,
            0.0
          }
        },

        {
          EstadoValvula_Bloquear
        }
      },

      {
        {
          EstadoValvula_Bloquear,
          ActuadorPosicionado_Desposicionado
        },

        {
          0.0,
          0.0
        }
      }
    }, { {
        {
          0,
          4.0,

          {
            0.0,
            0.0
          }
        },

        {
          EstadoValvula_Bloquear
        }
      },

      {
        {
          EstadoValvula_Bloquear,
          ActuadorPosicionado_Desposicionado
        },

        {
          0.0,
          0.0
        }
      }
    } },

  /* Variable: electroValvulas
   * Referenced by: '<Root>/Data Store Memory3'
   */
  {
    {
      {
        {
          5U,
          6U
        }, {
          7U,
          8U
        }, {
          1U,
          2U
        }, {
          3U,
          4U
        } }
      ,

      { 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U }
    }
  },

  /* Variable: regulador
   * Referenced by: '<Root>/Data Store Memory2'
   */
  {
    {
      0.0
    }
  },

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<S20>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogInput1_MaxMissedTicks
   * Referenced by: '<S20>/Analog Input1'
   */
  10.0,

  /* Mask Parameter: DigitalOutput_MaxMissedTicks
   * Referenced by: '<S20>/Digital Output'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<S20>/Analog Output'
   */
  10.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<S20>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogInput1_YieldWhenWaiting
   * Referenced by: '<S20>/Analog Input1'
   */
  0.0,

  /* Mask Parameter: DigitalOutput_YieldWhenWaiting
   * Referenced by: '<S20>/Digital Output'
   */
  0.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<S20>/Analog Output'
   */
  0.0,

  /* Mask Parameter: DigitalOutput_BitMode
   * Referenced by: '<S20>/Digital Output'
   */
  0,

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<S20>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogInput1_Channels
   * Referenced by: '<S20>/Analog Input1'
   */
  { 1, 2, 3, 4 },

  /* Mask Parameter: DigitalOutput_Channels
   * Referenced by: '<S20>/Digital Output'
   */
  { 0, 1, 2, 3, 4, 5, 6, 7 },

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<S20>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<S20>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogInput1_RangeMode
   * Referenced by: '<S20>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<S20>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<S20>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogInput1_VoltRange
   * Referenced by: '<S20>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<S20>/Analog Output'
   */
  0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S44>/Constant'
   */
  Controlador_Curvatura,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S39>/Constant'
   */
  Controlador_Presion,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S40>/Constant'
   */
  Controlador_EquilibrioPresiones,

  /* Mask Parameter: CompareToConstant_const_b
   * Referenced by: '<S38>/Constant'
   */
  Controlador_Curvatura,

  /* Expression: 0
   * Referenced by: '<S17>/RefPresion1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/RefPresion2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/RefPresion3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/RefPresion4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/RefCurvatura1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/RefCurvatura2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/RefCurvatura3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S17>/RefCurvatura4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S19>/Constant2'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S19>/Constant4'
   */
  1.0,

  /* Expression: 0.01
   * Referenced by: '<S19>/Constant5'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S19>/Constant6'
   */
  0.01,

  /* Expression: 0.001
   * Referenced by: '<S19>/Constant7'
   */
  0.001,

  /* Expression: 0.001
   * Referenced by: '<S19>/Constant8'
   */
  0.001,

  /* Expression: 0.01
   * Referenced by: '<S19>/Constant9'
   */
  0.01,

  /* Computed Parameter: PresinActuadores_Y0
   * Referenced by: '<S20>/Presión Actuadores'
   */
  0.0,

  /* Computed Parameter: PresinRegulador_Y0
   * Referenced by: '<S20>/Presión Regulador'
   */
  0.0,

  /* Computed Parameter: CurvaturaActuadores_Y0
   * Referenced by: '<S20>/Curvatura Actuadores'
   */
  0.0,

  /* Computed Parameter: PresinActuadores_Y0_o
   * Referenced by: '<S21>/Presión Actuadores'
   */
  0.0,

  /* Computed Parameter: PresinRegulador_Y0_f
   * Referenced by: '<S21>/Presión Regulador'
   */
  0.0,

  /* Computed Parameter: CurvaturaActuadores_Y0_i
   * Referenced by: '<S21>/Curvatura Actuadores'
   */
  0.0,

  /* Computed Parameter: Modelodelreguladordepresinelectrnico_A
   * Referenced by: '<S21>/Modelo del regulador de presión electrónico'
   */
  { -53.39, -1528.0 },

  /* Computed Parameter: Modelodelreguladordepresinelectrnico_C
   * Referenced by: '<S21>/Modelo del regulador de presión electrónico'
   */
  { 0.0, 152.48 },

  /* Expression: 65
   * Referenced by: '<S43>/Gain'
   */
  65.0,

  /* Expression: 0
   * Referenced by: '<S43>/Integrator'
   */
  0.0,

  /* Expression: 1.25
   * Referenced by: '<S43>/Gain2'
   */
  1.25,

  /* Expression: 233.3
   * Referenced by: '<S43>/Gain1'
   */
  233.3,

  /* Computed Parameter: SealControl_Y0
   * Referenced by: '<S41>/SeñalControl'
   */
  0.0,

  /* Computed Parameter: Errorestacionario_Y0
   * Referenced by: '<S41>/Error estacionario'
   */
  0.0,

  /* Computed Parameter: Errorderivativo_Y0
   * Referenced by: '<S41>/Error derivativo'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S41>/Ganancia Presión -> Tensión'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<S41>/Saturación de tensión'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S41>/Saturación de tensión'
   */
  0.0,

  /* Computed Parameter: SealControl_Y0_p
   * Referenced by: '<S42>/SeñalControl'
   */
  0.0,

  /* Computed Parameter: Errorestacionario_Y0_m
   * Referenced by: '<S42>/Error estacionario'
   */
  0.0,

  /* Computed Parameter: Errorderivativo_Y0_b
   * Referenced by: '<S42>/Error derivativo'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S42>/Ganancia Presión -> Tensión'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<S42>/Saturación de tensión'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<S42>/Saturación de tensión'
   */
  0.0,

  /* Expression: EstadoValvula.Expulsar
   * Referenced by: '<S17>/EstadoValvula1'
   */
  EstadoValvula_Expulsar,

  /* Expression: EstadoValvula.Expulsar
   * Referenced by: '<S17>/EstadoValvula2'
   */
  EstadoValvula_Expulsar,

  /* Expression: EstadoValvula.Expulsar
   * Referenced by: '<S17>/EstadoValvula3'
   */
  EstadoValvula_Expulsar,

  /* Expression: EstadoValvula.Expulsar
   * Referenced by: '<S17>/EstadoValvula4'
   */
  EstadoValvula_Expulsar,

  /* Expression: ModoControl(1)
   * Referenced by: '<S19>/Constant'
   */
  ModoControl_Autonomo_Secuencial,

  /* Expression: ParametroControl(0)
   * Referenced by: '<S19>/Constant1'
   */
  ParametroControl_Presion,

  /* Expression: logical(1)
   * Referenced by: '<S17>/ActuadorActivo1'
   */
  true,

  /* Expression: logical(1)
   * Referenced by: '<S17>/ActuadorActivo2'
   */
  true,

  /* Expression: logical(1)
   * Referenced by: '<S17>/ActuadorActivo3'
   */
  true,

  /* Expression: true
   * Referenced by: '<S17>/ActuadorActivo4'
   */
  true,

  /* Start of '<S26>/CoreSubsys' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S27>/Constant'
     */
    1.0,

    /* Mask Parameter: CompareToConstant1_const
     * Referenced by: '<S28>/Constant'
     */
    2.0,

    /* Mask Parameter: CompareToConstant2_const
     * Referenced by: '<S29>/Constant'
     */
    3.0,

    /* Mask Parameter: CompareToConstant3_const
     * Referenced by: '<S30>/Constant'
     */
    4.0,

    /* Mask Parameter: CompareToConstant4_const
     * Referenced by: '<S31>/Constant'
     */
    5.0,

    /* Mask Parameter: CompareToConstant5_const
     * Referenced by: '<S32>/Constant'
     */
    ModoControl_Manual,

    /* Expression: 0
     * Referenced by: '<S26>/Constant'
     */
    0.0,

    /* Start of '<S26>/Curvatura Actuador 1' */
    {
      /* Computed Parameter: Out1_Y0
       * Referenced by: '<S33>/Out1'
       */
      0.0,

      /* Computed Parameter: Modelodecurvaturadelactuador_A
       * Referenced by: '<S33>/Modelo de curvatura del actuador'
       */
      { -11410.0, -74880.0, -72390.0, -14230.0, -143.0 },

      /* Computed Parameter: Modelodecurvaturadelactuador_C
       * Referenced by: '<S33>/Modelo de curvatura del actuador'
       */
      { 0.0, 995.3, 1595.0, 424.3, 7.903 }
    }
    ,

    /* End of '<S26>/Curvatura Actuador 1' */

    /* Start of '<S26>/Curvatura Actuador 2' */
    {
      /* Computed Parameter: Out1_Y0
       * Referenced by: '<S34>/Out1'
       */
      0.0,

      /* Computed Parameter: Modelodecurvaturadelactuador1_A
       * Referenced by: '<S34>/Modelo de curvatura del actuador1'
       */
      { -11410.0, -74880.0, -72390.0, -14230.0, -143.0 },

      /* Computed Parameter: Modelodecurvaturadelactuador1_C
       * Referenced by: '<S34>/Modelo de curvatura del actuador1'
       */
      { 0.0, 995.3, 1595.0, 424.3, 7.903 }
    }
    ,

    /* End of '<S26>/Curvatura Actuador 2' */

    /* Start of '<S26>/Curvatura Actuador 3' */
    {
      /* Computed Parameter: Out1_Y0
       * Referenced by: '<S35>/Out1'
       */
      0.0,

      /* Computed Parameter: Modelodecurvaturadelactuador1_A
       * Referenced by: '<S35>/Modelo de curvatura del actuador1'
       */
      { -11410.0, -74880.0, -72390.0, -14230.0, -143.0 },

      /* Computed Parameter: Modelodecurvaturadelactuador1_C
       * Referenced by: '<S35>/Modelo de curvatura del actuador1'
       */
      { 0.0, 995.3, 1595.0, 424.3, 7.903 }
    }
    ,

    /* End of '<S26>/Curvatura Actuador 3' */

    /* Start of '<S26>/Curvatura Actuador 4' */
    {
      /* Computed Parameter: Out1_Y0
       * Referenced by: '<S36>/Out1'
       */
      0.0,

      /* Computed Parameter: Modelodecurvaturadelactuador1_A
       * Referenced by: '<S36>/Modelo de curvatura del actuador1'
       */
      { -11410.0, -74880.0, -72390.0, -14230.0, -143.0 },

      /* Computed Parameter: Modelodecurvaturadelactuador1_C
       * Referenced by: '<S36>/Modelo de curvatura del actuador1'
       */
      { 0.0, 995.3, 1595.0, 424.3, 7.903 }
    }
    ,

    /* End of '<S26>/Curvatura Actuador 4' */

    /* Start of '<S26>/Curvatura Actuador 5' */
    {
      /* Computed Parameter: Out1_Y0
       * Referenced by: '<S37>/Out1'
       */
      0.0,

      /* Computed Parameter: Modelodecurvaturadelactuador_A
       * Referenced by: '<S37>/Modelo de curvatura del actuador'
       */
      { -11410.0, -74880.0, -72390.0, -14230.0, -143.0 },

      /* Computed Parameter: Modelodecurvaturadelactuador_C
       * Referenced by: '<S37>/Modelo de curvatura del actuador'
       */
      { 0.0, 995.3, 1595.0, 424.3, 7.903 }
    }
    /* End of '<S26>/Curvatura Actuador 5' */
  }
  ,

  /* End of '<S26>/CoreSubsys' */

  /* Start of '<S22>/CoreSubsys' */
  {
    /* Mask Parameter: CompareToConstant5_const
     * Referenced by: '<S25>/Constant'
     */
    ModoControl_Manual,

    /* Expression: 0
     * Referenced by: '<S22>/Constant'
     */
    0.0
  }
  /* End of '<S22>/CoreSubsys' */
};
