/*
 * ControlSystem_Refactorization_data.c
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
        Controlador_Curvatura,

        {
          0.0,
          0.0
        },
        0,
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

        {
          0.0,
          0.0
        },

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
          1
        }
      },

      {
        {
          1,
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
          1
        }
      },

      {
        {
          1,
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
          1
        }
      },

      {
        {
          1,
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
          1
        }
      },

      {
        {
          1,
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

  /* Mask Parameter: AnalogOutput_MaxMissedTicks
   * Referenced by: '<S21>/Analog Output'
   */
  10.0,

  /* Mask Parameter: DigitalOutput_MaxMissedTicks
   * Referenced by: '<S21>/Digital Output'
   */
  10.0,

  /* Mask Parameter: AnalogInput_MaxMissedTicks
   * Referenced by: '<S21>/Analog Input'
   */
  10.0,

  /* Mask Parameter: AnalogInput1_MaxMissedTicks
   * Referenced by: '<S21>/Analog Input1'
   */
  10.0,

  /* Mask Parameter: AnalogOutput_YieldWhenWaiting
   * Referenced by: '<S21>/Analog Output'
   */
  0.0,

  /* Mask Parameter: DigitalOutput_YieldWhenWaiting
   * Referenced by: '<S21>/Digital Output'
   */
  0.0,

  /* Mask Parameter: AnalogInput_YieldWhenWaiting
   * Referenced by: '<S21>/Analog Input'
   */
  0.0,

  /* Mask Parameter: AnalogInput1_YieldWhenWaiting
   * Referenced by: '<S21>/Analog Input1'
   */
  0.0,

  /* Mask Parameter: DigitalOutput_BitMode
   * Referenced by: '<S21>/Digital Output'
   */
  0,

  /* Mask Parameter: AnalogOutput_Channels
   * Referenced by: '<S21>/Analog Output'
   */
  0,

  /* Mask Parameter: DigitalOutput_Channels
   * Referenced by: '<S21>/Digital Output'
   */
  { 0, 1, 2, 3, 4, 5, 6, 7 },

  /* Mask Parameter: AnalogInput_Channels
   * Referenced by: '<S21>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogInput1_Channels
   * Referenced by: '<S21>/Analog Input1'
   */
  { 1, 2, 3, 4 },

  /* Mask Parameter: AnalogOutput_RangeMode
   * Referenced by: '<S21>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_RangeMode
   * Referenced by: '<S21>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogInput1_RangeMode
   * Referenced by: '<S21>/Analog Input1'
   */
  0,

  /* Mask Parameter: AnalogOutput_VoltRange
   * Referenced by: '<S21>/Analog Output'
   */
  0,

  /* Mask Parameter: AnalogInput_VoltRange
   * Referenced by: '<S21>/Analog Input'
   */
  0,

  /* Mask Parameter: AnalogInput1_VoltRange
   * Referenced by: '<S21>/Analog Input1'
   */
  0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S48>/Constant'
   */
  Controlador_Curvatura,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S43>/Constant'
   */
  Controlador_Presion,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S44>/Constant'
   */
  Controlador_EquilibrioPresiones,

  /* Mask Parameter: CompareToConstant_const_b
   * Referenced by: '<S42>/Constant'
   */
  Controlador_Curvatura,

  /* Mask Parameter: CompareToConstant7_const
   * Referenced by: '<S49>/Constant'
   */
  false,

  /* Computed Parameter: Errorestacionario_Y0
   * Referenced by: '<S45>/Error estacionario'
   */
  {
    0.0,                               /* presion */
    0.0                                /* curvatura */
  },

  /* Computed Parameter: Errorderivativo_Y0
   * Referenced by: '<S45>/Error derivativo'
   */
  {
    0.0,                               /* presion */
    0.0                                /* curvatura */
  },

  /* Computed Parameter: Errorestacionario_Y0_i
   * Referenced by: '<S46>/Error estacionario'
   */
  {
    0.0,                               /* presion */
    0.0                                /* curvatura */
  },

  /* Computed Parameter: Errorderivativo_Y0_b
   * Referenced by: '<S46>/Error derivativo'
   */
  {
    0.0,                               /* presion */
    0.0                                /* curvatura */
  },

  /* Expression: 0.2124727184153514
   * Referenced by: '<S18>/RefPresion1'
   */
  0.2124727184153514,

  /* Expression: 0.2071400809278029
   * Referenced by: '<S18>/RefPresion2'
   */
  0.20714008092780289,

  /* Expression: 0.12850570026206
   * Referenced by: '<S18>/RefPresion3'
   */
  0.12850570026206,

  /* Expression: -0.1744085316685976
   * Referenced by: '<S18>/RefPresion4'
   */
  -0.1744085316685976,

  /* Expression: 0.00946380894507531
   * Referenced by: '<S18>/RefCurvatura1'
   */
  0.00946380894507531,

  /* Expression: 0.01717447711309256
   * Referenced by: '<S18>/RefCurvatura2'
   */
  0.01717447711309256,

  /* Expression: 0.01408231226304131
   * Referenced by: '<S18>/RefCurvatura3'
   */
  0.014082312263041311,

  /* Expression: 0.006023788509316939
   * Referenced by: '<S18>/RefCurvatura4'
   */
  0.0060237885093169389,

  /* Expression: 1
   * Referenced by: '<S20>/Constant4'
   */
  1.0,

  /* Expression: 0.01
   * Referenced by: '<S20>/Constant5'
   */
  0.01,

  /* Expression: 0.01
   * Referenced by: '<S20>/Constant6'
   */
  0.01,

  /* Expression: 0.001
   * Referenced by: '<S20>/Constant7'
   */
  0.001,

  /* Expression: 1e-05
   * Referenced by: '<S20>/Constant8'
   */
  1.0E-5,

  /* Expression: 0.01
   * Referenced by: '<S20>/Constant9'
   */
  0.01,

  /* Computed Parameter: PresinActuadores_Y0
   * Referenced by: '<S21>/Presión Actuadores'
   */
  0.0,

  /* Computed Parameter: PresinRegulador_Y0
   * Referenced by: '<S21>/Presión Regulador'
   */
  0.0,

  /* Computed Parameter: CurvaturaActuadores_Y0
   * Referenced by: '<S21>/Curvatura Actuadores'
   */
  0.0,

  /* Computed Parameter: PresinActuadores_Y0_o
   * Referenced by: '<S22>/Presión Actuadores'
   */
  0.0,

  /* Computed Parameter: PresinReguladores_Y0
   * Referenced by: '<S22>/Presión Reguladores'
   */
  0.0,

  /* Computed Parameter: CurvaturaActuadores_Y0_i
   * Referenced by: '<S22>/Curvatura Actuadores'
   */
  0.0,

  /* Computed Parameter: Modelodelreguladordepresinelectrnico_A
   * Referenced by: '<S22>/Modelo del regulador de presión electrónico'
   */
  { -53.39, -1528.0 },

  /* Computed Parameter: Modelodelreguladordepresinelectrnico_C
   * Referenced by: '<S22>/Modelo del regulador de presión electrónico'
   */
  { 0.0, 152.48 },

  /* Expression: 65
   * Referenced by: '<S47>/Gain'
   */
  65.0,

  /* Expression: 0
   * Referenced by: '<S47>/Integrator'
   */
  0.0,

  /* Expression: 1.25
   * Referenced by: '<S47>/Gain2'
   */
  1.25,

  /* Expression: 233.3
   * Referenced by: '<S47>/Gain1'
   */
  233.3,

  /* Computed Parameter: SealControl_Y0
   * Referenced by: '<S45>/SeñalControl'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S45>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S45>/Constant1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S45>/Ganancia Presión -> Tensión'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<S45>/Saturación de tensión'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S45>/Saturación de tensión'
   */
  -10.0,

  /* Computed Parameter: SealControl_Y0_p
   * Referenced by: '<S46>/SeñalControl'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S46>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S46>/Constant1'
   */
  0.0,

  /* Expression: 10
   * Referenced by: '<S46>/Ganancia Presión -> Tensión'
   */
  10.0,

  /* Expression: 10
   * Referenced by: '<S46>/Saturación de tensión'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S46>/Saturación de tensión'
   */
  -10.0,

  /* Expression: ModoControl(1)
   * Referenced by: '<S20>/Constant'
   */
  ModoControl_Autonomo_Secuencial,

  /* Expression: ParametroControl(1)
   * Referenced by: '<S20>/Constant1'
   */
  ParametroControl_Curvatura,

  /* Expression: logical(0)
   * Referenced by: '<S18>/BloqueoManual1'
   */
  false,

  /* Expression: logical(0)
   * Referenced by: '<S18>/BloqueoManual2'
   */
  false,

  /* Expression: logical(0)
   * Referenced by: '<S18>/BloqueoManual3'
   */
  false,

  /* Expression: logical(0)
   * Referenced by: '<S18>/BloqueoManual4'
   */
  false,

  /* Expression: logical(1)
   * Referenced by: '<S18>/ActuadorActivo1'
   */
  true,

  /* Expression: logical(1)
   * Referenced by: '<S18>/ActuadorActivo2'
   */
  true,

  /* Expression: logical(1)
   * Referenced by: '<S18>/ActuadorActivo3'
   */
  true,

  /* Expression: true
   * Referenced by: '<S18>/ActuadorActivo4'
   */
  true,

  /* Expression: true
   * Referenced by: '<S20>/Constant2'
   */
  true,

  /* Start of '<S28>/CoreSubsys' */
  {
    /* Mask Parameter: CompareToConstant_const
     * Referenced by: '<S29>/Constant'
     */
    1.0,

    /* Mask Parameter: CompareToConstant1_const
     * Referenced by: '<S30>/Constant'
     */
    2.0,

    /* Mask Parameter: CompareToConstant2_const
     * Referenced by: '<S31>/Constant'
     */
    3.0,

    /* Mask Parameter: CompareToConstant3_const
     * Referenced by: '<S32>/Constant'
     */
    4.0,

    /* Mask Parameter: CompareToConstant4_const
     * Referenced by: '<S33>/Constant'
     */
    5.0,

    /* Mask Parameter: CompareToConstant5_const
     * Referenced by: '<S34>/Constant'
     */
    ModoControl_Manual,

    /* Mask Parameter: CompareToConstant6_const
     * Referenced by: '<S35>/Constant'
     */
    false,

    /* Mask Parameter: CompareToConstant7_const
     * Referenced by: '<S36>/Constant'
     */
    false,

    /* Start of '<S28>/Curvatura Actuador 1' */
    {
      /* Computed Parameter: Curvatura_Y0
       * Referenced by: '<S37>/Curvatura'
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
    ,

    /* End of '<S28>/Curvatura Actuador 1' */

    /* Start of '<S28>/Curvatura Actuador 2' */
    {
      /* Computed Parameter: Curvatura_Y0
       * Referenced by: '<S38>/Curvatura'
       */
      0.0,

      /* Computed Parameter: Modelodecurvaturadelactuador_A
       * Referenced by: '<S38>/Modelo de curvatura del actuador'
       */
      { -11410.0, -74880.0, -72390.0, -14230.0, -143.0 },

      /* Computed Parameter: Modelodecurvaturadelactuador_C
       * Referenced by: '<S38>/Modelo de curvatura del actuador'
       */
      { 0.0, 995.3, 1595.0, 424.3, 7.903 }
    }
    ,

    /* End of '<S28>/Curvatura Actuador 2' */

    /* Start of '<S28>/Curvatura Actuador 3' */
    {
      /* Computed Parameter: Curvatura_Y0
       * Referenced by: '<S39>/Curvatura'
       */
      0.0,

      /* Computed Parameter: Modelodecurvaturadelactuador_A
       * Referenced by: '<S39>/Modelo de curvatura del actuador'
       */
      { -11410.0, -74880.0, -72390.0, -14230.0, -143.0 },

      /* Computed Parameter: Modelodecurvaturadelactuador_C
       * Referenced by: '<S39>/Modelo de curvatura del actuador'
       */
      { 0.0, 995.3, 1595.0, 424.3, 7.903 }
    }
    ,

    /* End of '<S28>/Curvatura Actuador 3' */

    /* Start of '<S28>/Curvatura Actuador 4' */
    {
      /* Computed Parameter: Curvatura_Y0
       * Referenced by: '<S40>/Curvatura'
       */
      0.0,

      /* Computed Parameter: Modelodecurvaturadelactuador_A
       * Referenced by: '<S40>/Modelo de curvatura del actuador'
       */
      { -11410.0, -74880.0, -72390.0, -14230.0, -143.0 },

      /* Computed Parameter: Modelodecurvaturadelactuador_C
       * Referenced by: '<S40>/Modelo de curvatura del actuador'
       */
      { 0.0, 995.3, 1595.0, 424.3, 7.903 }
    }
    ,

    /* End of '<S28>/Curvatura Actuador 4' */

    /* Start of '<S28>/Curvatura Actuador 5' */
    {
      /* Computed Parameter: Curvatura_Y0
       * Referenced by: '<S41>/Curvatura'
       */
      0.0,

      /* Computed Parameter: Modelodecurvaturadelactuador_A
       * Referenced by: '<S41>/Modelo de curvatura del actuador'
       */
      { -11410.0, -74880.0, -72390.0, -14230.0, -143.0 },

      /* Computed Parameter: Modelodecurvaturadelactuador_C
       * Referenced by: '<S41>/Modelo de curvatura del actuador'
       */
      { 0.0, 995.3, 1595.0, 424.3, 7.903 }
    }
    /* End of '<S28>/Curvatura Actuador 5' */
  }
  ,

  /* End of '<S28>/CoreSubsys' */

  /* Start of '<S23>/CoreSubsys' */
  {
    /* Mask Parameter: CompareToConstant5_const
     * Referenced by: '<S26>/Constant'
     */
    ModoControl_Manual,

    /* Mask Parameter: CompareToConstant6_const
     * Referenced by: '<S27>/Constant'
     */
    false
  }
  /* End of '<S23>/CoreSubsys' */
};
