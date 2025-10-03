    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 22;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (ControlSystem_Refactorization_P)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.sistema
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.actuadorBus
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.electroValvulas
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.regulador
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.AnalogInput_MaxMissedTicks
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.AnalogInput1_MaxMissedTicks
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.DigitalOutput_MaxMissedTicks
                    section.data(3).logicalSrcIdx = 10;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_P.AnalogOutput_MaxMissedTicks
                    section.data(4).logicalSrcIdx = 11;
                    section.data(4).dtTransOffset = 3;

                    ;% ControlSystem_Refactorization_P.AnalogInput_YieldWhenWaiting
                    section.data(5).logicalSrcIdx = 12;
                    section.data(5).dtTransOffset = 4;

                    ;% ControlSystem_Refactorization_P.AnalogInput1_YieldWhenWaiting
                    section.data(6).logicalSrcIdx = 13;
                    section.data(6).dtTransOffset = 5;

                    ;% ControlSystem_Refactorization_P.DigitalOutput_YieldWhenWaiting
                    section.data(7).logicalSrcIdx = 14;
                    section.data(7).dtTransOffset = 6;

                    ;% ControlSystem_Refactorization_P.AnalogOutput_YieldWhenWaiting
                    section.data(8).logicalSrcIdx = 15;
                    section.data(8).dtTransOffset = 7;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 11;
            section.data(11)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.DigitalOutput_BitMode
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.AnalogInput_Channels
                    section.data(2).logicalSrcIdx = 17;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.AnalogInput1_Channels
                    section.data(3).logicalSrcIdx = 18;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_P.DigitalOutput_Channels
                    section.data(4).logicalSrcIdx = 19;
                    section.data(4).dtTransOffset = 6;

                    ;% ControlSystem_Refactorization_P.AnalogOutput_Channels
                    section.data(5).logicalSrcIdx = 20;
                    section.data(5).dtTransOffset = 14;

                    ;% ControlSystem_Refactorization_P.AnalogInput_RangeMode
                    section.data(6).logicalSrcIdx = 21;
                    section.data(6).dtTransOffset = 15;

                    ;% ControlSystem_Refactorization_P.AnalogInput1_RangeMode
                    section.data(7).logicalSrcIdx = 22;
                    section.data(7).dtTransOffset = 16;

                    ;% ControlSystem_Refactorization_P.AnalogOutput_RangeMode
                    section.data(8).logicalSrcIdx = 23;
                    section.data(8).dtTransOffset = 17;

                    ;% ControlSystem_Refactorization_P.AnalogInput_VoltRange
                    section.data(9).logicalSrcIdx = 24;
                    section.data(9).dtTransOffset = 18;

                    ;% ControlSystem_Refactorization_P.AnalogInput1_VoltRange
                    section.data(10).logicalSrcIdx = 25;
                    section.data(10).dtTransOffset = 19;

                    ;% ControlSystem_Refactorization_P.AnalogOutput_VoltRange
                    section.data(11).logicalSrcIdx = 26;
                    section.data(11).dtTransOffset = 20;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.CompareToConstant_const
                    section.data(1).logicalSrcIdx = 27;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.CompareToConstant1_const
                    section.data(2).logicalSrcIdx = 28;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.CompareToConstant2_const
                    section.data(3).logicalSrcIdx = 29;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_P.CompareToConstant_const_b
                    section.data(4).logicalSrcIdx = 30;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 39;
            section.data(39)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.RefPresion1_Value
                    section.data(1).logicalSrcIdx = 31;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.RefPresion2_Value
                    section.data(2).logicalSrcIdx = 32;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.RefPresion3_Value
                    section.data(3).logicalSrcIdx = 33;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_P.RefPresion4_Value
                    section.data(4).logicalSrcIdx = 34;
                    section.data(4).dtTransOffset = 3;

                    ;% ControlSystem_Refactorization_P.RefCurvatura1_Value
                    section.data(5).logicalSrcIdx = 35;
                    section.data(5).dtTransOffset = 4;

                    ;% ControlSystem_Refactorization_P.RefCurvatura2_Value
                    section.data(6).logicalSrcIdx = 36;
                    section.data(6).dtTransOffset = 5;

                    ;% ControlSystem_Refactorization_P.RefCurvatura3_Value
                    section.data(7).logicalSrcIdx = 37;
                    section.data(7).dtTransOffset = 6;

                    ;% ControlSystem_Refactorization_P.RefCurvatura4_Value
                    section.data(8).logicalSrcIdx = 38;
                    section.data(8).dtTransOffset = 7;

                    ;% ControlSystem_Refactorization_P.Constant2_Value
                    section.data(9).logicalSrcIdx = 39;
                    section.data(9).dtTransOffset = 8;

                    ;% ControlSystem_Refactorization_P.Constant4_Value
                    section.data(10).logicalSrcIdx = 40;
                    section.data(10).dtTransOffset = 9;

                    ;% ControlSystem_Refactorization_P.Constant5_Value
                    section.data(11).logicalSrcIdx = 41;
                    section.data(11).dtTransOffset = 10;

                    ;% ControlSystem_Refactorization_P.Constant6_Value
                    section.data(12).logicalSrcIdx = 42;
                    section.data(12).dtTransOffset = 11;

                    ;% ControlSystem_Refactorization_P.Constant7_Value
                    section.data(13).logicalSrcIdx = 43;
                    section.data(13).dtTransOffset = 12;

                    ;% ControlSystem_Refactorization_P.Constant8_Value
                    section.data(14).logicalSrcIdx = 44;
                    section.data(14).dtTransOffset = 13;

                    ;% ControlSystem_Refactorization_P.Constant9_Value
                    section.data(15).logicalSrcIdx = 45;
                    section.data(15).dtTransOffset = 14;

                    ;% ControlSystem_Refactorization_P.PresinActuadores_Y0
                    section.data(16).logicalSrcIdx = 46;
                    section.data(16).dtTransOffset = 15;

                    ;% ControlSystem_Refactorization_P.PresinRegulador_Y0
                    section.data(17).logicalSrcIdx = 47;
                    section.data(17).dtTransOffset = 16;

                    ;% ControlSystem_Refactorization_P.CurvaturaActuadores_Y0
                    section.data(18).logicalSrcIdx = 48;
                    section.data(18).dtTransOffset = 17;

                    ;% ControlSystem_Refactorization_P.PresinActuadores_Y0_o
                    section.data(19).logicalSrcIdx = 49;
                    section.data(19).dtTransOffset = 18;

                    ;% ControlSystem_Refactorization_P.PresinRegulador_Y0_f
                    section.data(20).logicalSrcIdx = 50;
                    section.data(20).dtTransOffset = 19;

                    ;% ControlSystem_Refactorization_P.CurvaturaActuadores_Y0_i
                    section.data(21).logicalSrcIdx = 51;
                    section.data(21).dtTransOffset = 20;

                    ;% ControlSystem_Refactorization_P.Modelodelreguladordepresinelectrnico_A
                    section.data(22).logicalSrcIdx = 52;
                    section.data(22).dtTransOffset = 21;

                    ;% ControlSystem_Refactorization_P.Modelodelreguladordepresinelectrnico_C
                    section.data(23).logicalSrcIdx = 53;
                    section.data(23).dtTransOffset = 23;

                    ;% ControlSystem_Refactorization_P.Gain_Gain
                    section.data(24).logicalSrcIdx = 54;
                    section.data(24).dtTransOffset = 25;

                    ;% ControlSystem_Refactorization_P.Integrator_IC
                    section.data(25).logicalSrcIdx = 55;
                    section.data(25).dtTransOffset = 26;

                    ;% ControlSystem_Refactorization_P.Gain2_Gain
                    section.data(26).logicalSrcIdx = 56;
                    section.data(26).dtTransOffset = 27;

                    ;% ControlSystem_Refactorization_P.Gain1_Gain
                    section.data(27).logicalSrcIdx = 57;
                    section.data(27).dtTransOffset = 28;

                    ;% ControlSystem_Refactorization_P.SealControl_Y0
                    section.data(28).logicalSrcIdx = 58;
                    section.data(28).dtTransOffset = 29;

                    ;% ControlSystem_Refactorization_P.Errorestacionario_Y0
                    section.data(29).logicalSrcIdx = 59;
                    section.data(29).dtTransOffset = 30;

                    ;% ControlSystem_Refactorization_P.Errorderivativo_Y0
                    section.data(30).logicalSrcIdx = 60;
                    section.data(30).dtTransOffset = 31;

                    ;% ControlSystem_Refactorization_P.GananciaPresinTensin_Gain
                    section.data(31).logicalSrcIdx = 61;
                    section.data(31).dtTransOffset = 32;

                    ;% ControlSystem_Refactorization_P.Saturacindetensin_UpperSat
                    section.data(32).logicalSrcIdx = 62;
                    section.data(32).dtTransOffset = 33;

                    ;% ControlSystem_Refactorization_P.Saturacindetensin_LowerSat
                    section.data(33).logicalSrcIdx = 63;
                    section.data(33).dtTransOffset = 34;

                    ;% ControlSystem_Refactorization_P.SealControl_Y0_p
                    section.data(34).logicalSrcIdx = 64;
                    section.data(34).dtTransOffset = 35;

                    ;% ControlSystem_Refactorization_P.Errorestacionario_Y0_m
                    section.data(35).logicalSrcIdx = 65;
                    section.data(35).dtTransOffset = 36;

                    ;% ControlSystem_Refactorization_P.Errorderivativo_Y0_b
                    section.data(36).logicalSrcIdx = 66;
                    section.data(36).dtTransOffset = 37;

                    ;% ControlSystem_Refactorization_P.GananciaPresinTensin_Gain_p
                    section.data(37).logicalSrcIdx = 67;
                    section.data(37).dtTransOffset = 38;

                    ;% ControlSystem_Refactorization_P.Saturacindetensin_UpperSat_a
                    section.data(38).logicalSrcIdx = 68;
                    section.data(38).dtTransOffset = 39;

                    ;% ControlSystem_Refactorization_P.Saturacindetensin_LowerSat_m
                    section.data(39).logicalSrcIdx = 69;
                    section.data(39).dtTransOffset = 40;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.EstadoValvula1_Value
                    section.data(1).logicalSrcIdx = 70;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.EstadoValvula2_Value
                    section.data(2).logicalSrcIdx = 71;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.EstadoValvula3_Value
                    section.data(3).logicalSrcIdx = 72;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_P.EstadoValvula4_Value
                    section.data(4).logicalSrcIdx = 73;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.Constant_Value
                    section.data(1).logicalSrcIdx = 74;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.Constant1_Value
                    section.data(1).logicalSrcIdx = 75;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(11) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.ActuadorActivo1_Value
                    section.data(1).logicalSrcIdx = 76;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.ActuadorActivo2_Value
                    section.data(2).logicalSrcIdx = 77;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.ActuadorActivo3_Value
                    section.data(3).logicalSrcIdx = 78;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_P.ActuadorActivo4_Value
                    section.data(4).logicalSrcIdx = 79;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            paramMap.sections(12) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant_const
                    section.data(1).logicalSrcIdx = 80;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant1_const
                    section.data(2).logicalSrcIdx = 81;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant2_const
                    section.data(3).logicalSrcIdx = 82;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant3_const
                    section.data(4).logicalSrcIdx = 83;
                    section.data(4).dtTransOffset = 3;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant4_const
                    section.data(5).logicalSrcIdx = 84;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            paramMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CompareToConstant5_const
                    section.data(1).logicalSrcIdx = 85;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.Constant_Value
                    section.data(1).logicalSrcIdx = 86;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(15) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador1.Out1_Y0
                    section.data(1).logicalSrcIdx = 87;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador1.Modelodecurvaturadelactuador_A
                    section.data(2).logicalSrcIdx = 88;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador1.Modelodecurvaturadelactuador_C
                    section.data(3).logicalSrcIdx = 89;
                    section.data(3).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(16) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador2.Out1_Y0
                    section.data(1).logicalSrcIdx = 90;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador2.Modelodecurvaturadelactuador1_A
                    section.data(2).logicalSrcIdx = 91;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador2.Modelodecurvaturadelactuador1_C
                    section.data(3).logicalSrcIdx = 92;
                    section.data(3).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(17) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador3.Out1_Y0
                    section.data(1).logicalSrcIdx = 93;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador3.Modelodecurvaturadelactuador1_A
                    section.data(2).logicalSrcIdx = 94;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador3.Modelodecurvaturadelactuador1_C
                    section.data(3).logicalSrcIdx = 95;
                    section.data(3).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(18) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador4.Out1_Y0
                    section.data(1).logicalSrcIdx = 96;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador4.Modelodecurvaturadelactuador1_A
                    section.data(2).logicalSrcIdx = 97;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador4.Modelodecurvaturadelactuador1_C
                    section.data(3).logicalSrcIdx = 98;
                    section.data(3).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(19) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador5.Out1_Y0
                    section.data(1).logicalSrcIdx = 99;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador5.Modelodecurvaturadelactuador_A
                    section.data(2).logicalSrcIdx = 100;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pnae.CurvaturaActuador5.Modelodecurvaturadelactuador_C
                    section.data(3).logicalSrcIdx = 101;
                    section.data(3).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            paramMap.sections(20) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pna.CompareToConstant5_const
                    section.data(1).logicalSrcIdx = 102;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(21) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_P.CoreSubsys_pna.Constant_Value
                    section.data(1).logicalSrcIdx = 103;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(22) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 13;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (ControlSystem_Refactorization_B)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.sistema
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.DataStoreRead3
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_B.ImpAsg_InsertedFor_actuadores_at_inport_0
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 20;
            section.data(20)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport2
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport3
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 4;

                    ;% ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_Simulacin_at_inport_3
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 8;

                    ;% ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0
                    section.data(4).logicalSrcIdx = 6;
                    section.data(4).dtTransOffset = 9;

                    ;% ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Curvaturaactuadores_at_inport_0
                    section.data(5).logicalSrcIdx = 7;
                    section.data(5).dtTransOffset = 13;

                    ;% ControlSystem_Refactorization_B.Add
                    section.data(6).logicalSrcIdx = 8;
                    section.data(6).dtTransOffset = 17;

                    ;% ControlSystem_Refactorization_B.Derivative
                    section.data(7).logicalSrcIdx = 9;
                    section.data(7).dtTransOffset = 18;

                    ;% ControlSystem_Refactorization_B.Saturacindetensin
                    section.data(8).logicalSrcIdx = 10;
                    section.data(8).dtTransOffset = 19;

                    ;% ControlSystem_Refactorization_B.Add1
                    section.data(9).logicalSrcIdx = 11;
                    section.data(9).dtTransOffset = 20;

                    ;% ControlSystem_Refactorization_B.Derivative1
                    section.data(10).logicalSrcIdx = 12;
                    section.data(10).dtTransOffset = 21;

                    ;% ControlSystem_Refactorization_B.Saturacindetensin_k
                    section.data(11).logicalSrcIdx = 13;
                    section.data(11).dtTransOffset = 22;

                    ;% ControlSystem_Refactorization_B.Gain2
                    section.data(12).logicalSrcIdx = 14;
                    section.data(12).dtTransOffset = 23;

                    ;% ControlSystem_Refactorization_B.Gain1
                    section.data(13).logicalSrcIdx = 15;
                    section.data(13).dtTransOffset = 24;

                    ;% ControlSystem_Refactorization_B.Modelodelreguladordepresinelectrnico
                    section.data(14).logicalSrcIdx = 16;
                    section.data(14).dtTransOffset = 25;

                    ;% ControlSystem_Refactorization_B.ImpAsg_InsertedFor_PresinActuador_at_inport_0
                    section.data(15).logicalSrcIdx = 17;
                    section.data(15).dtTransOffset = 26;

                    ;% ControlSystem_Refactorization_B.ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0
                    section.data(16).logicalSrcIdx = 18;
                    section.data(16).dtTransOffset = 30;

                    ;% ControlSystem_Refactorization_B.MATLABSystem
                    section.data(17).logicalSrcIdx = 19;
                    section.data(17).dtTransOffset = 34;

                    ;% ControlSystem_Refactorization_B.curv
                    section.data(18).logicalSrcIdx = 20;
                    section.data(18).dtTransOffset = 42;

                    ;% ControlSystem_Refactorization_B.press
                    section.data(19).logicalSrcIdx = 21;
                    section.data(19).dtTransOffset = 46;

                    ;% ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Presinactuadores_at_inport_0_h
                    section.data(20).logicalSrcIdx = 22;
                    section.data(20).dtTransOffset = 47;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 8;
            section.data(8)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport5
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_B.OR
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 4;

                    ;% ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_ControldePresin_at_inport_2
                    section.data(3).logicalSrcIdx = 25;
                    section.data(3).dtTransOffset = 5;

                    ;% ControlSystem_Refactorization_B.Compare
                    section.data(4).logicalSrcIdx = 26;
                    section.data(4).dtTransOffset = 6;

                    ;% ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_ControldeCurvatura_at_inport_3
                    section.data(5).logicalSrcIdx = 27;
                    section.data(5).dtTransOffset = 7;

                    ;% ControlSystem_Refactorization_B.NOT
                    section.data(6).logicalSrcIdx = 28;
                    section.data(6).dtTransOffset = 8;

                    ;% ControlSystem_Refactorization_B.HiddenBuf_InsertedFor_DAQ_at_inport_4
                    section.data(7).logicalSrcIdx = 29;
                    section.data(7).dtTransOffset = 9;

                    ;% ControlSystem_Refactorization_B.Compare_m
                    section.data(8).logicalSrcIdx = 30;
                    section.data(8).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.TmpSignalConversionAtForEachSubsystemInport4
                    section.data(1).logicalSrcIdx = 31;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.ImpAsg_InsertedFor_Actuadoresposicionados_at_inport_0
                    section.data(1).logicalSrcIdx = 32;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].IndexVector1
                    section.data(1).logicalSrcIdx = 33;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section

            section.nData     = 10;
            section.data(10)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].Compare
                    section.data(1).logicalSrcIdx = 34;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].Compare_c
                    section.data(2).logicalSrcIdx = 35;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].Compare_n
                    section.data(3).logicalSrcIdx = 36;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].Compare_i
                    section.data(4).logicalSrcIdx = 37;
                    section.data(4).dtTransOffset = 3;

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].Compare_a
                    section.data(5).logicalSrcIdx = 38;
                    section.data(5).dtTransOffset = 4;

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].HiddenBuf_InsertedFor_CurvaturaActuador1_at_inport_1
                    section.data(6).logicalSrcIdx = 39;
                    section.data(6).dtTransOffset = 5;

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].HiddenBuf_InsertedFor_CurvaturaActuador2_at_inport_1
                    section.data(7).logicalSrcIdx = 40;
                    section.data(7).dtTransOffset = 6;

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].HiddenBuf_InsertedFor_CurvaturaActuador3_at_inport_1
                    section.data(8).logicalSrcIdx = 41;
                    section.data(8).dtTransOffset = 7;

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].HiddenBuf_InsertedFor_CurvaturaActuador4_at_inport_1
                    section.data(9).logicalSrcIdx = 42;
                    section.data(9).dtTransOffset = 8;

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].HiddenBuf_InsertedFor_CurvaturaActuador5_at_inport_1
                    section.data(10).logicalSrcIdx = 43;
                    section.data(10).dtTransOffset = 9;

            nTotData = nTotData + section.nData;
            sigMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].CurvaturaActuador1.CurvAct
                    section.data(1).logicalSrcIdx = 44;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].CurvaturaActuador2.CurvAct
                    section.data(1).logicalSrcIdx = 45;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].CurvaturaActuador3.CurvAct
                    section.data(1).logicalSrcIdx = 46;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].CurvaturaActuador4.CurvAct
                    section.data(1).logicalSrcIdx = 47;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_B.CoreSubsys_pnae[3].CurvaturaActuador5.CurvAct
                    section.data(1).logicalSrcIdx = 48;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(13) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 22;
        sectIdxOffset = 13;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (ControlSystem_Refactorization_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.sistema
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.actuadorBus
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.electroValvulas
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 12;
            section.data(12)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.TimeStampA
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_DW.LastUAtTimeA
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_DW.TimeStampB
                    section.data(3).logicalSrcIdx = 6;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_DW.LastUAtTimeB
                    section.data(4).logicalSrcIdx = 7;
                    section.data(4).dtTransOffset = 3;

                    ;% ControlSystem_Refactorization_DW.TimeStampA_b
                    section.data(5).logicalSrcIdx = 8;
                    section.data(5).dtTransOffset = 4;

                    ;% ControlSystem_Refactorization_DW.LastUAtTimeA_e
                    section.data(6).logicalSrcIdx = 9;
                    section.data(6).dtTransOffset = 5;

                    ;% ControlSystem_Refactorization_DW.TimeStampB_f
                    section.data(7).logicalSrcIdx = 10;
                    section.data(7).dtTransOffset = 6;

                    ;% ControlSystem_Refactorization_DW.LastUAtTimeB_k
                    section.data(8).logicalSrcIdx = 11;
                    section.data(8).dtTransOffset = 7;

                    ;% ControlSystem_Refactorization_DW.TimeStampA_k
                    section.data(9).logicalSrcIdx = 12;
                    section.data(9).dtTransOffset = 8;

                    ;% ControlSystem_Refactorization_DW.LastUAtTimeA_g
                    section.data(10).logicalSrcIdx = 13;
                    section.data(10).dtTransOffset = 9;

                    ;% ControlSystem_Refactorization_DW.TimeStampB_b
                    section.data(11).logicalSrcIdx = 14;
                    section.data(11).dtTransOffset = 10;

                    ;% ControlSystem_Refactorization_DW.LastUAtTimeB_c
                    section.data(12).logicalSrcIdx = 15;
                    section.data(12).dtTransOffset = 11;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.regulador
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.AnalogInput_PWORK
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_DW.AnalogInput1_PWORK
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_DW.DigitalOutput_PWORK
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_DW.AnalogOutput_PWORK
                    section.data(4).logicalSrcIdx = 20;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.sfEvent
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_DW.sfEvent_d
                    section.data(2).logicalSrcIdx = 22;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.obj_b
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.obj_k
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.ControldePresin_SubsysRanBC
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_DW.ControldeCurvatura_SubsysRanBC
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_DW.Simulacin_SubsysRanBC
                    section.data(3).logicalSrcIdx = 27;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_DW.DAQ_SubsysRanBC
                    section.data(4).logicalSrcIdx = 28;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.objisempty
                    section.data(1).logicalSrcIdx = 29;
                    section.data(1).dtTransOffset = 0;

                    ;% ControlSystem_Refactorization_DW.objisempty_e
                    section.data(2).logicalSrcIdx = 30;
                    section.data(2).dtTransOffset = 1;

                    ;% ControlSystem_Refactorization_DW.objisempty_h
                    section.data(3).logicalSrcIdx = 31;
                    section.data(3).dtTransOffset = 2;

                    ;% ControlSystem_Refactorization_DW.doneDoubleBufferReInit
                    section.data(4).logicalSrcIdx = 32;
                    section.data(4).dtTransOffset = 3;

                    ;% ControlSystem_Refactorization_DW.doneDoubleBufferReInit_o
                    section.data(5).logicalSrcIdx = 33;
                    section.data(5).dtTransOffset = 4;

                    ;% ControlSystem_Refactorization_DW.ControldePresin_MODE
                    section.data(6).logicalSrcIdx = 34;
                    section.data(6).dtTransOffset = 5;

                    ;% ControlSystem_Refactorization_DW.ControldeCurvatura_MODE
                    section.data(7).logicalSrcIdx = 35;
                    section.data(7).dtTransOffset = 6;

                    ;% ControlSystem_Refactorization_DW.Simulacin_MODE
                    section.data(8).logicalSrcIdx = 36;
                    section.data(8).dtTransOffset = 7;

                    ;% ControlSystem_Refactorization_DW.DAQ_MODE
                    section.data(9).logicalSrcIdx = 37;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].CurvaturaActuador1.CurvaturaActuador5_SubsysRanBC
                    section.data(1).logicalSrcIdx = 38;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].CurvaturaActuador1.CurvaturaActuador5_MODE
                    section.data(1).logicalSrcIdx = 39;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(14) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].CurvaturaActuador2.CurvaturaActuador4_SubsysRanBC
                    section.data(1).logicalSrcIdx = 40;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(15) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].CurvaturaActuador2.CurvaturaActuador4_MODE
                    section.data(1).logicalSrcIdx = 41;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(16) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].CurvaturaActuador3.CurvaturaActuador4_SubsysRanBC
                    section.data(1).logicalSrcIdx = 42;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(17) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].CurvaturaActuador3.CurvaturaActuador4_MODE
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(18) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].CurvaturaActuador4.CurvaturaActuador4_SubsysRanBC
                    section.data(1).logicalSrcIdx = 44;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(19) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].CurvaturaActuador4.CurvaturaActuador4_MODE
                    section.data(1).logicalSrcIdx = 45;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(20) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].CurvaturaActuador5.CurvaturaActuador5_SubsysRanBC
                    section.data(1).logicalSrcIdx = 46;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(21) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% ControlSystem_Refactorization_DW.CoreSubsys_pnae[3].CurvaturaActuador5.CurvaturaActuador5_MODE
                    section.data(1).logicalSrcIdx = 47;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(22) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 3003190588;
    targMap.checksum1 = 2619320984;
    targMap.checksum2 = 1265173108;
    targMap.checksum3 = 3562307661;

