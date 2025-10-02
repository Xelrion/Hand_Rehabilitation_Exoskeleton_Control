/*
 * ControlSystem_Refactorization.h
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

#ifndef ControlSystem_Refactorization_h_
#define ControlSystem_Refactorization_h_
#ifndef ControlSystem_Refactorization_COMMON_INCLUDES_
#define ControlSystem_Refactorization_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "dt_info.h"
#include "ext_work.h"
#include "sldrtdef.h"
#endif                      /* ControlSystem_Refactorization_COMMON_INCLUDES_ */

#include "ControlSystem_Refactorization_types.h"
#include "modo_control.h"
#include "act_position.h"
#include "controlador.h"
#include "referencia_control.h"
#include <string.h>
#include "rtGetInf.h"
#include <stddef.h>
#include "rt_defines.h"
#include "zero_crossing_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
#define rtmGetChecksums(rtm)           ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
#define rtmSetChecksums(rtm, val)      ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
#define rtmGetConstBlockIO(rtm)        ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
#define rtmSetConstBlockIO(rtm, val)   ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
#define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
#define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
#define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
#define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
#define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
#define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm)         ()
#endif

#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)    ()
#endif

#ifndef rtmGetDefaultParam
#define rtmGetDefaultParam(rtm)        ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
#define rtmSetDefaultParam(rtm, val)   ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
#define rtmGetDirectFeedThrough(rtm)   ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
#define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
#define rtmGetErrorStatusFlag(rtm)     ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
#define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
#define rtmSetFinalTime(rtm, val)      ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
#define rtmGetFirstInitCondFlag(rtm)   ()
#endif

#ifndef rtmSetFirstInitCondFlag
#define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalRuntimeEventIndices
#define rtmGetMdlRefGlobalRuntimeEventIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalRuntimeEventIndices
#define rtmSetMdlRefGlobalRuntimeEventIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTID
#define rtmGetMdlRefGlobalTID(rtm)     ()
#endif

#ifndef rtmSetMdlRefGlobalTID
#define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefGlobalTimerIndices
#define rtmGetMdlRefGlobalTimerIndices(rtm) ()
#endif

#ifndef rtmSetMdlRefGlobalTimerIndices
#define rtmSetMdlRefGlobalTimerIndices(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
#define rtmGetMdlRefTriggerTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefTriggerTID
#define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
#define rtmGetModelMappingInfo(rtm)    ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
#define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
#define rtmGetModelName(rtm)           ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
#define rtmSetModelName(rtm, val)      ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
#define rtmGetNonInlinedSFcns(rtm)     ()
#endif

#ifndef rtmSetNonInlinedSFcns
#define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
#define rtmGetNumBlockIO(rtm)          ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
#define rtmSetNumBlockIO(rtm, val)     ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
#define rtmGetNumBlockParams(rtm)      ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
#define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
#define rtmGetNumBlocks(rtm)           ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
#define rtmSetNumBlocks(rtm, val)      ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
#define rtmGetNumContStates(rtm)       ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
#define rtmSetNumContStates(rtm, val)  ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
#define rtmGetNumDWork(rtm)            ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
#define rtmSetNumDWork(rtm, val)       ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
#define rtmGetNumInputPorts(rtm)       ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
#define rtmSetNumInputPorts(rtm, val)  ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
#define rtmGetNumNonSampledZCs(rtm)    ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
#define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
#define rtmGetNumOutputPorts(rtm)      ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
#define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
#define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
#define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
#define rtmGetNumSFcnParams(rtm)       ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
#define rtmSetNumSFcnParams(rtm, val)  ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
#define rtmGetNumSFunctions(rtm)       ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
#define rtmSetNumSFunctions(rtm, val)  ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
#define rtmGetNumSampleTimes(rtm)      ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
#define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
#define rtmGetNumU(rtm)                ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
#define rtmSetNumU(rtm, val)           ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
#define rtmGetNumY(rtm)                ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
#define rtmSetNumY(rtm, val)           ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetOffsetTimeArray
#define rtmGetOffsetTimeArray(rtm)     ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
#define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
#define rtmGetOffsetTimePtr(rtm)       ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
#define rtmSetOffsetTimePtr(rtm, val)  ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
#define rtmGetOptions(rtm)             ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
#define rtmSetOptions(rtm, val)        ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
#define rtmGetParamIsMalloced(rtm)     ()
#endif

#ifndef rtmSetParamIsMalloced
#define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
#define rtmGetPath(rtm)                ((rtm)->path)
#endif

#ifndef rtmSetPath
#define rtmSetPath(rtm, val)           ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
#define rtmGetPerTaskSampleHits(rtm)   ()
#endif

#ifndef rtmSetPerTaskSampleHits
#define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
#define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
#define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
#define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
#define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
#define rtmGetPrevZCSigState(rtm)      ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
#define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetProxyFunctions
#define rtmGetProxyFunctions(rtm)      ()
#endif

#ifndef rtmSetProxyFunctions
#define rtmSetProxyFunctions(rtm, val) ()
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
#define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
#define rtmGetRTWGeneratedSFcn(rtm)    ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
#define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
#define rtmGetRTWLogInfo(rtm)          ()
#endif

#ifndef rtmSetRTWLogInfo
#define rtmSetRTWLogInfo(rtm, val)     ()
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
#define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
#define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
#define rtmGetRTWSfcnInfo(rtm)         ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
#define rtmSetRTWSfcnInfo(rtm, val)    ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
#define rtmGetRTWSolverInfo(rtm)       ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
#define rtmSetRTWSolverInfo(rtm, val)  ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
#define rtmGetRTWSolverInfoPtr(rtm)    ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
#define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
#define rtmGetReservedForXPC(rtm)      ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
#define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
#define rtmGetSFunctions(rtm)          ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
#define rtmSetSFunctions(rtm, val)     ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
#define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
#define rtmGetSampleHitPtr(rtm)        ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
#define rtmSetSampleHitPtr(rtm, val)   ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
#define rtmGetSampleTimeArray(rtm)     ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
#define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
#define rtmGetSampleTimePtr(rtm)       ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
#define rtmSetSampleTimePtr(rtm, val)  ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
#define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
#define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
#define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
#define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
#define rtmGetSelf(rtm)                ()
#endif

#ifndef rtmSetSelf
#define rtmSetSelf(rtm, val)           ()
#endif

#ifndef rtmGetSimMode
#define rtmGetSimMode(rtm)             ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
#define rtmSetSimMode(rtm, val)        ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
#define rtmGetSimTimeStep(rtm)         ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
#define rtmSetSimTimeStep(rtm, val)    ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
#define rtmGetStartTime(rtm)           ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
#define rtmSetStartTime(rtm, val)      ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
#define rtmSetStepSize(rtm, val)       ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
#define rtmGetStopRequestedFlag(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
#define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStubFunctions
#define rtmGetStubFunctions(rtm)       ()
#endif

#ifndef rtmSetStubFunctions
#define rtmSetStubFunctions(rtm, val)  ()
#endif

#ifndef rtmGetTaskCounters
#define rtmGetTaskCounters(rtm)        ()
#endif

#ifndef rtmSetTaskCounters
#define rtmSetTaskCounters(rtm, val)   ()
#endif

#ifndef rtmGetTaskTimeArray
#define rtmGetTaskTimeArray(rtm)       ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
#define rtmSetTaskTimeArray(rtm, val)  ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
#define rtmGetTimePtr(rtm)             ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
#define rtmSetTimePtr(rtm, val)        ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
#define rtmGetTimingData(rtm)          ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
#define rtmSetTimingData(rtm, val)     ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
#define rtmGetU(rtm)                   ((rtm)->inputs)
#endif

#ifndef rtmSetU
#define rtmSetU(rtm, val)              ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
#define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
#define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
#define rtmGetY(rtm)                   ((rtm)->outputs)
#endif

#ifndef rtmSetY
#define rtmSetY(rtm, val)              ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
#define rtmGetZCSignalValues(rtm)      ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
#define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
#define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
#define rtmGettimingBridge(rtm)        ()
#endif

#ifndef rtmSettimingBridge
#define rtmSettimingBridge(rtm, val)   ()
#endif

#ifndef rtmGetChecksumVal
#define rtmGetChecksumVal(rtm, idx)    ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
#define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
#define rtmGetDWork(rtm, idx)          ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
#define rtmSetDWork(rtm, idx, val)     ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
#define rtmGetOffsetTime(rtm, idx)     ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
#define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
#define rtmGetSFunction(rtm, idx)      ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
#define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
#define rtmGetSampleTime(rtm, idx)     ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
#define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
#define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
#define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
#define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
#define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
#define rtmIsContinuousTask(rtm, tid)  ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
#define rtmIsSampleHit(rtm, sti, tid)  ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
#define rtmSetT(rtm, val)                                        /* Do Nothing */
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
#define rtmSetTStart(rtm, val)         ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
#define rtmGetTaskTime(rtm, sti)       (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
#define rtmSetTaskTime(rtm, sti, val)  (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define ControlSystem_Refactorization_rtModel RT_MODEL_ControlSystem_Refactorization_T

/* Block signals for system '<S27>/Curvatura Actuador 5' */
typedef struct {
  real_T CurvAct;                 /* '<S40>/Modelo de curvatura del actuador' */
} B_CurvaturaActuador5_ControlSystem_Refactorization_T;

/* Block states (default storage) for system '<S27>/Curvatura Actuador 5' */
typedef struct {
  int8_T CurvaturaActuador5_SubsysRanBC;/* '<S27>/Curvatura Actuador 5' */
  boolean_T CurvaturaActuador5_MODE;   /* '<S27>/Curvatura Actuador 5' */
} DW_CurvaturaActuador5_ControlSystem_Refactorization_T;

/* Continuous states for system '<S27>/Curvatura Actuador 5' */
typedef struct {
  real_T Modelodecurvaturadelactuador_CSTATE[5];
                                  /* '<S40>/Modelo de curvatura del actuador' */
} X_CurvaturaActuador5_ControlSystem_Refactorization_T;

/* State derivatives for system '<S27>/Curvatura Actuador 5' */
typedef struct {
  real_T Modelodecurvaturadelactuador_CSTATE[5];
                                  /* '<S40>/Modelo de curvatura del actuador' */
} XDot_CurvaturaActuador5_ControlSystem_Refactorization_T;

/* State Disabled for system '<S27>/Curvatura Actuador 5' */
typedef struct {
  boolean_T Modelodecurvaturadelactuador_CSTATE[5];
                                  /* '<S40>/Modelo de curvatura del actuador' */
} XDis_CurvaturaActuador5_ControlSystem_Refactorization_T;

/* Block signals for system '<S22>/Modelo de los actuadores' */
typedef struct {
  real_T Constant;                     /* '<S35>/Constant' */
  real_T EstadoValvula_o;              /* '<S27>/Switch1' */
  boolean_T Compare;                   /* '<S28>/Compare' */
  boolean_T Compare_g;                 /* '<S29>/Compare' */
  boolean_T Compare_e;                 /* '<S30>/Compare' */
  boolean_T Compare_d;                 /* '<S31>/Compare' */
  boolean_T Compare_i;                 /* '<S32>/Compare' */
  boolean_T HiddenBuf_InsertedFor_CurvaturaActuador1_at_inport_1;/* '<S27>/Compare To Constant' */
  boolean_T HiddenBuf_InsertedFor_CurvaturaActuador2_at_inport_1;/* '<S27>/Compare To Constant1' */
  boolean_T HiddenBuf_InsertedFor_CurvaturaActuador3_at_inport_1;/* '<S27>/Compare To Constant2' */
  boolean_T HiddenBuf_InsertedFor_CurvaturaActuador4_at_inport_1;/* '<S27>/Compare To Constant3' */
  boolean_T HiddenBuf_InsertedFor_CurvaturaActuador5_at_inport_1;/* '<S27>/Compare To Constant4' */
  B_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador1;/* '<S27>/Curvatura Actuador 1' */
  B_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador2;/* '<S27>/Curvatura Actuador 2' */
  B_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador3;/* '<S27>/Curvatura Actuador 3' */
  B_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador4;/* '<S27>/Curvatura Actuador 4' */
  B_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador5;/* '<S27>/Curvatura Actuador 5' */
} B_CoreSubsys_ControlSystem_Refactorization_caua_T;

/* Block states (default storage) for system '<S22>/Modelo de los actuadores' */
typedef struct {
  DW_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador1;/* '<S27>/Curvatura Actuador 1' */
  DW_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador2;/* '<S27>/Curvatura Actuador 2' */
  DW_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador3;/* '<S27>/Curvatura Actuador 3' */
  DW_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador4;/* '<S27>/Curvatura Actuador 4' */
  DW_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador5;/* '<S27>/Curvatura Actuador 5' */
} DW_CoreSubsys_ControlSystem_Refactorization_fwu4_T;

/* Continuous states for system '<S22>/Modelo de los actuadores' */
typedef struct {
  X_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador1;/* '<S27>/Curvatura Actuador 5' */
  X_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador2;/* '<S27>/Curvatura Actuador 5' */
  X_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador3;/* '<S27>/Curvatura Actuador 5' */
  X_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador4;/* '<S27>/Curvatura Actuador 5' */
  X_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador5;/* '<S27>/Curvatura Actuador 5' */
} X_CoreSubsys_ControlSystem_Refactorization_nymf_T;

/* State derivatives for system '<S22>/Modelo de los actuadores' */
typedef struct {
  XDot_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador1;/* '<S27>/Curvatura Actuador 5' */
  XDot_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador2;/* '<S27>/Curvatura Actuador 5' */
  XDot_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador3;/* '<S27>/Curvatura Actuador 5' */
  XDot_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador4;/* '<S27>/Curvatura Actuador 5' */
  XDot_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador5;/* '<S27>/Curvatura Actuador 5' */
} XDot_CoreSubsys_ControlSystem_Refactorization_n1mv_T;

/* State Disabled for system '<S22>/Modelo de los actuadores' */
typedef struct {
  XDis_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador1;/* '<S27>/Curvatura Actuador 5' */
  XDis_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador2;/* '<S27>/Curvatura Actuador 5' */
  XDis_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador3;/* '<S27>/Curvatura Actuador 5' */
  XDis_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador4;/* '<S27>/Curvatura Actuador 5' */
  XDis_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador5;/* '<S27>/Curvatura Actuador 5' */
} XDis_CoreSubsys_ControlSystem_Refactorization_nenc_T;

/* Block signals (default storage) */
typedef struct {
  slBusSistema sistema;                /* '<Root>/Bus Assignment1' */
  slBusActuador DataStoreRead3[4];     /* '<Root>/Data Store Read3' */
  slBusActuador ImpAsg_InsertedFor_actuadores_at_inport_0[4];/* '<S3>/Bus Assignment' */
  real_T TmpSignalConversionAtForEachSubsystemInport2[4];/* '<S1>/Configuración de usuario' */
  real_T TmpSignalConversionAtForEachSubsystemInport3[4];/* '<S1>/Configuración de usuario' */
  real_T Constant;                     /* '<S48>/Constant' */
  real_T PresinRegulador;              /* '<S8>/Switch2' */
  real_T ImpAsg_InsertedFor_Presinactuadores_at_inport_0[4];
  real_T ImpAsg_InsertedFor_Curvaturaactuadores_at_inport_0[4];
  real_T Add;                          /* '<S45>/Add' */
  real_T Derivative;                   /* '<S45>/Derivative' */
  real_T presion;                      /* '<S45>/Saturación de tensión' */
  real_T curvatura;                    /* '<S45>/Constant1' */
  real_T curvatura_g;                  /* '<S45>/Constant' */
  real_T Add1;                         /* '<S44>/Add1' */
  real_T Derivative1;                  /* '<S44>/Derivative1' */
  real_T Saturacindetensin;            /* '<S44>/Saturación de tensión' */
  real_T presion_b;                    /* '<S44>/Constant1' */
  real_T presion_bl;                   /* '<S44>/Constant' */
  real_T Gain2;                        /* '<S46>/Gain2' */
  real_T Gain1;                        /* '<S46>/Gain1' */
  real_T Abs;                          /* '<S22>/Abs' */
  real_T Modelodelreguladordepresinelectrnico;
                       /* '<S22>/Modelo del regulador de presión electrónico' */
  real_T ImpAsg_InsertedFor_PresinActuador_at_inport_0[4];
  real_T ImpAsg_InsertedFor_CurvaturaActuador_at_inport_0[4];
  real_T OutportBufferForCurvaturaActuadores[4];
  real_T press;                        /* '<S21>/MATLAB Function' */
  real_T ImpAsg_InsertedFor_Out1_at_inport_0[4];
  real_T Constant_j[4];                /* '<S21>/Constant' */
  boolean_T TmpSignalConversionAtForEachSubsystemInport4[4];/* '<S1>/Configuración de usuario' */
  boolean_T TmpSignalConversionAtForEachSubsystemInport5[4];/* '<S1>/Configuración de usuario' */
  boolean_T OR1;                       /* '<S7>/OR1' */
  boolean_T HiddenBuf_InsertedFor_ControldePresin_at_inport_2;/* '<S7>/OR1' */
  boolean_T Compare;                   /* '<S41>/Compare' */
  boolean_T HiddenBuf_InsertedFor_ControldeCurvatura_at_inport_3;/* '<S7>/Compare To Constant' */
  boolean_T NOT;                       /* '<S5>/NOT' */
  boolean_T HiddenBuf_InsertedFor_DAQ_at_inport_3;/* '<S5>/NOT' */
  boolean_T HiddenBuf_InsertedFor_Simulacin_at_inport_2;
  boolean_T simulacionActiva;
  boolean_T Compare_k;                 /* '<S47>/Compare' */
  ModoControl modoControl;
  ActuadorPosicionado ImpAsg_InsertedFor_Actuadoresposicionados_at_inport_0[4];
  B_CoreSubsys_ControlSystem_Refactorization_caua_T CoreSubsys_pnae[4];/* '<S22>/Modelo de los actuadores' */
} B_ControlSystem_Refactorization_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  slBusSistema sistema;                /* '<Root>/Data Store Memory1' */
  slBusActuador actuadorBus[4];        /* '<Root>/Data Store Memory' */
  slBusElectroValvulas electroValvulas;/* '<Root>/Data Store Memory3' */
  sequential_autonomousControlLogic_ControlSystem_Refactorization_T obj;/* '<S6>/MATLAB System1' */
  real_T TimeStampA;                   /* '<S45>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S45>/Derivative' */
  real_T TimeStampB;                   /* '<S45>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S45>/Derivative' */
  real_T TimeStampA_b;                 /* '<S44>/Derivative1' */
  real_T LastUAtTimeA_e;               /* '<S44>/Derivative1' */
  real_T TimeStampB_f;                 /* '<S44>/Derivative1' */
  real_T LastUAtTimeB_k;               /* '<S44>/Derivative1' */
  real_T TimeStampA_k;                 /* '<S46>/Derivative' */
  real_T LastUAtTimeA_g;               /* '<S46>/Derivative' */
  real_T TimeStampB_b;                 /* '<S46>/Derivative' */
  real_T LastUAtTimeB_c;               /* '<S46>/Derivative' */
  slBusRegulador regulador;            /* '<Root>/Data Store Memory2' */
  int32_T sfEvent;                     /* '<S21>/MATLAB Function' */
  elegirTensionesElectrovalvulas_ControlSystem_Refactorization_T obj_b;/* '<S21>/MATLAB System' */
  manualControlLogic_ControlSystem_Refactorization_T obj_k;/* '<S6>/MATLAB System' */
  int8_T ControldePresin_SubsysRanBC;  /* '<S7>/Control de Presión' */
  int8_T ControldeCurvatura_SubsysRanBC;/* '<S7>/Control de Curvatura' */
  int8_T Simulacin_SubsysRanBC;        /* '<S5>/Simulación' */
  int8_T DAQ_SubsysRanBC;              /* '<S5>/DAQ' */
  boolean_T objisempty;                /* '<S6>/MATLAB System1' */
  boolean_T objisempty_e;              /* '<S6>/MATLAB System' */
  boolean_T objisempty_h;              /* '<S21>/MATLAB System' */
  boolean_T doneDoubleBufferReInit;    /* '<S21>/MATLAB Function' */
  boolean_T ControldePresin_MODE;      /* '<S7>/Control de Presión' */
  boolean_T ControldeCurvatura_MODE;   /* '<S7>/Control de Curvatura' */
  boolean_T Simulacin_MODE;            /* '<S5>/Simulación' */
  boolean_T DAQ_MODE;                  /* '<S5>/DAQ' */
  DW_CoreSubsys_ControlSystem_Refactorization_fwu4_T CoreSubsys_pnae[4];/* '<S22>/Modelo de los actuadores' */
} DW_ControlSystem_Refactorization_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S46>/Integrator' */
  real_T Modelodelreguladordepresinelectrnico_CSTATE[2];
                       /* '<S22>/Modelo del regulador de presión electrónico' */
  X_CoreSubsys_ControlSystem_Refactorization_nymf_T CoreSubsys_pnae[4];/* '<S27>/CoreSubsys' */
} X_ControlSystem_Refactorization_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE;            /* '<S46>/Integrator' */
  real_T Modelodelreguladordepresinelectrnico_CSTATE[2];
                       /* '<S22>/Modelo del regulador de presión electrónico' */
  XDot_CoreSubsys_ControlSystem_Refactorization_n1mv_T CoreSubsys_pnae[4];/* '<S27>/CoreSubsys' */
} XDot_ControlSystem_Refactorization_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE;         /* '<S46>/Integrator' */
  boolean_T Modelodelreguladordepresinelectrnico_CSTATE[2];
                       /* '<S22>/Modelo del regulador de presión electrónico' */
  XDis_CoreSubsys_ControlSystem_Refactorization_nenc_T CoreSubsys_pnae[4];/* '<S27>/CoreSubsys' */
} XDis_ControlSystem_Refactorization_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S46>/Integrator' */
} PrevZCX_ControlSystem_Refactorization_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Backward compatible GRT Identifiers */
#define rtB                            ControlSystem_Refactorization_B
#define BlockIO                        B_ControlSystem_Refactorization_T
#define rtX                            ControlSystem_Refactorization_X
#define ContinuousStates               X_ControlSystem_Refactorization_T
#define rtXdot                         ControlSystem_Refactorization_XDot
#define StateDerivatives               XDot_ControlSystem_Refactorization_T
#define tXdis                          ControlSystem_Refactorization_XDis
#define StateDisabled                  XDis_ControlSystem_Refactorization_T
#define rtP                            ControlSystem_Refactorization_P
#define Parameters                     P_ControlSystem_Refactorization_T
#define rtDWork                        ControlSystem_Refactorization_DW
#define D_Work                         DW_ControlSystem_Refactorization_T
#define rtPrevZCSigState               ControlSystem_Refactorization_PrevZCX
#define PrevZCSigStates                PrevZCX_ControlSystem_Refactorization_T

/* Parameters for system: '<S21>/Flujo de aire en los actuadores' */
struct P_CoreSubsys_ControlSystem_Refactorization_gmy_T_ {
  ModoControl CompareToConstant5_const;
                                     /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S25>/Constant'
                                      */
  boolean_T CompareToConstant6_const;/* Mask Parameter: CompareToConstant6_const
                                      * Referenced by: '<S26>/Constant'
                                      */
};

/* Parameters for system: '<S27>/Curvatura Actuador 5' */
struct P_CurvaturaActuador5_ControlSystem_Refactorization_T_ {
  real_T Curvatura_Y0;                 /* Computed Parameter: Curvatura_Y0
                                        * Referenced by: '<S40>/Curvatura'
                                        */
  real_T Modelodecurvaturadelactuador_A[5];
                           /* Computed Parameter: Modelodecurvaturadelactuador_A
                            * Referenced by: '<S40>/Modelo de curvatura del actuador'
                            */
  real_T Modelodecurvaturadelactuador_C[5];
                           /* Computed Parameter: Modelodecurvaturadelactuador_C
                            * Referenced by: '<S40>/Modelo de curvatura del actuador'
                            */
};

/* Parameters for system: '<S22>/Modelo de los actuadores' */
struct P_CoreSubsys_ControlSystem_Refactorization_gmy0_T_ {
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S28>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S29>/Constant'
                                      */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S30>/Constant'
                                      */
  real_T CompareToConstant3_const;   /* Mask Parameter: CompareToConstant3_const
                                      * Referenced by: '<S31>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S32>/Constant'
                                      */
  ModoControl CompareToConstant5_const;
                                     /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S33>/Constant'
                                      */
  boolean_T CompareToConstant6_const;/* Mask Parameter: CompareToConstant6_const
                                      * Referenced by: '<S34>/Constant'
                                      */
  boolean_T CompareToConstant7_const;/* Mask Parameter: CompareToConstant7_const
                                      * Referenced by: '<S35>/Constant'
                                      */
  P_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador1;/* '<S27>/Curvatura Actuador 1' */
  P_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador2;/* '<S27>/Curvatura Actuador 2' */
  P_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador3;/* '<S27>/Curvatura Actuador 3' */
  P_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador4;/* '<S27>/Curvatura Actuador 4' */
  P_CurvaturaActuador5_ControlSystem_Refactorization_T CurvaturaActuador5;/* '<S27>/Curvatura Actuador 5' */
};

/* Parameters (default storage) */
struct P_ControlSystem_Refactorization_T_ {
  slBusSistema sistema;                /* Variable: sistema
                                        * Referenced by: '<Root>/Data Store Memory1'
                                        */
  slBusActuador actuadorBus[4];        /* Variable: actuadorBus
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  slBusElectroValvulas electroValvulas;/* Variable: electroValvulas
                                        * Referenced by: '<Root>/Data Store Memory3'
                                        */
  slBusRegulador regulador;            /* Variable: regulador
                                        * Referenced by: '<Root>/Data Store Memory2'
                                        */
  Controlador CompareToConstant_const;/* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S47>/Constant'
                                       */
  Controlador CompareToConstant1_const;
                                     /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S42>/Constant'
                                      */
  Controlador CompareToConstant4_const;
                                     /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S43>/Constant'
                                      */
  Controlador CompareToConstant_const_b;
                                    /* Mask Parameter: CompareToConstant_const_b
                                     * Referenced by: '<S41>/Constant'
                                     */
  boolean_T CompareToConstant7_const;/* Mask Parameter: CompareToConstant7_const
                                      * Referenced by: '<S48>/Constant'
                                      */
  Referencia Errorestacionario_Y0;   /* Computed Parameter: Errorestacionario_Y0
                                      * Referenced by: '<S44>/Error estacionario'
                                      */
  Referencia Errorderivativo_Y0;       /* Computed Parameter: Errorderivativo_Y0
                                        * Referenced by: '<S44>/Error derivativo'
                                        */
  Referencia Errorestacionario_Y0_i;
                                   /* Computed Parameter: Errorestacionario_Y0_i
                                    * Referenced by: '<S45>/Error estacionario'
                                    */
  Referencia Errorderivativo_Y0_b;   /* Computed Parameter: Errorderivativo_Y0_b
                                      * Referenced by: '<S45>/Error derivativo'
                                      */
  real_T RefPresion1_Value;            /* Expression: 0.2124727184153514
                                        * Referenced by: '<S18>/RefPresion1'
                                        */
  real_T RefPresion2_Value;            /* Expression: 0.2071400809278029
                                        * Referenced by: '<S18>/RefPresion2'
                                        */
  real_T RefPresion3_Value;            /* Expression: 0.12850570026206
                                        * Referenced by: '<S18>/RefPresion3'
                                        */
  real_T RefPresion4_Value;            /* Expression: -0.1744085316685976
                                        * Referenced by: '<S18>/RefPresion4'
                                        */
  real_T RefCurvatura1_Value;          /* Expression: 0.00946380894507531
                                        * Referenced by: '<S18>/RefCurvatura1'
                                        */
  real_T RefCurvatura2_Value;          /* Expression: 0.01717447711309256
                                        * Referenced by: '<S18>/RefCurvatura2'
                                        */
  real_T RefCurvatura3_Value;          /* Expression: 0.01408231226304131
                                        * Referenced by: '<S18>/RefCurvatura3'
                                        */
  real_T RefCurvatura4_Value;          /* Expression: 0.006023788509316939
                                        * Referenced by: '<S18>/RefCurvatura4'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S20>/Constant4'
                                        */
  real_T Constant5_Value;              /* Expression: 0.01
                                        * Referenced by: '<S20>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 0.01
                                        * Referenced by: '<S20>/Constant6'
                                        */
  real_T Constant7_Value;              /* Expression: 0.001
                                        * Referenced by: '<S20>/Constant7'
                                        */
  real_T Constant8_Value;              /* Expression: 1e-05
                                        * Referenced by: '<S20>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 0.01
                                        * Referenced by: '<S20>/Constant9'
                                        */
  real_T PresinActuadores_Y0;         /* Computed Parameter: PresinActuadores_Y0
                                       * Referenced by: '<S21>/Presión Actuadores'
                                       */
  real_T PresinRegulador_Y0;           /* Computed Parameter: PresinRegulador_Y0
                                        * Referenced by: '<S21>/Presión Regulador'
                                        */
  real_T Constant_Value[4];          /* Expression: zeros(1,length(actuadorBus))
                                      * Referenced by: '<S21>/Constant'
                                      */
  real_T PresinActuadores_Y0_o;     /* Computed Parameter: PresinActuadores_Y0_o
                                     * Referenced by: '<S22>/Presión Actuadores'
                                     */
  real_T PresinReguladores_Y0;       /* Computed Parameter: PresinReguladores_Y0
                                      * Referenced by: '<S22>/Presión Reguladores'
                                      */
  real_T CurvaturaActuadores_Y0;   /* Computed Parameter: CurvaturaActuadores_Y0
                                    * Referenced by: '<S22>/Curvatura Actuadores'
                                    */
  real_T Modelodelreguladordepresinelectrnico_A[2];
                   /* Computed Parameter: Modelodelreguladordepresinelectrnico_A
                    * Referenced by: '<S22>/Modelo del regulador de presión electrónico'
                    */
  real_T Modelodelreguladordepresinelectrnico_C[2];
                   /* Computed Parameter: Modelodelreguladordepresinelectrnico_C
                    * Referenced by: '<S22>/Modelo del regulador de presión electrónico'
                    */
  real_T Gain_Gain;                    /* Expression: 65
                                        * Referenced by: '<S46>/Gain'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S46>/Integrator'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1.25
                                        * Referenced by: '<S46>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 233.3
                                        * Referenced by: '<S46>/Gain1'
                                        */
  real_T SealControl_Y0;               /* Computed Parameter: SealControl_Y0
                                        * Referenced by: '<S44>/SeñalControl'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S44>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S44>/Constant1'
                                        */
  real_T GananciaPresinTensin_Gain;    /* Expression: 10
                                        * Referenced by: '<S44>/Ganancia Presión -> Tensión'
                                        */
  real_T Saturacindetensin_UpperSat;   /* Expression: 10
                                        * Referenced by: '<S44>/Saturación de tensión'
                                        */
  real_T Saturacindetensin_LowerSat;   /* Expression: -10
                                        * Referenced by: '<S44>/Saturación de tensión'
                                        */
  real_T SealControl_Y0_p;             /* Computed Parameter: SealControl_Y0_p
                                        * Referenced by: '<S45>/SeñalControl'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 0
                                        * Referenced by: '<S45>/Constant1'
                                        */
  real_T GananciaPresinTensin_Gain_p;  /* Expression: 10
                                        * Referenced by: '<S45>/Ganancia Presión -> Tensión'
                                        */
  real_T Saturacindetensin_UpperSat_a; /* Expression: 10
                                        * Referenced by: '<S45>/Saturación de tensión'
                                        */
  real_T Saturacindetensin_LowerSat_m; /* Expression: -10
                                        * Referenced by: '<S45>/Saturación de tensión'
                                        */
  ModoControl Constant_Value_f;        /* Expression: ModoControl(1)
                                        * Referenced by: '<S20>/Constant'
                                        */
  ParametroControl Constant1_Value_e;  /* Expression: ParametroControl(1)
                                        * Referenced by: '<S20>/Constant1'
                                        */
  boolean_T BloqueoManual1_Value;      /* Expression: logical(0)
                                        * Referenced by: '<S18>/BloqueoManual1'
                                        */
  boolean_T BloqueoManual2_Value;      /* Expression: logical(0)
                                        * Referenced by: '<S18>/BloqueoManual2'
                                        */
  boolean_T BloqueoManual3_Value;      /* Expression: logical(0)
                                        * Referenced by: '<S18>/BloqueoManual3'
                                        */
  boolean_T BloqueoManual4_Value;      /* Expression: logical(0)
                                        * Referenced by: '<S18>/BloqueoManual4'
                                        */
  boolean_T ActuadorActivo1_Value;     /* Expression: logical(1)
                                        * Referenced by: '<S18>/ActuadorActivo1'
                                        */
  boolean_T ActuadorActivo2_Value;     /* Expression: logical(1)
                                        * Referenced by: '<S18>/ActuadorActivo2'
                                        */
  boolean_T ActuadorActivo3_Value;     /* Expression: logical(1)
                                        * Referenced by: '<S18>/ActuadorActivo3'
                                        */
  boolean_T ActuadorActivo4_Value;     /* Expression: true
                                        * Referenced by: '<S18>/ActuadorActivo4'
                                        */
  boolean_T Constant2_Value;           /* Expression: true
                                        * Referenced by: '<S20>/Constant2'
                                        */
  P_CoreSubsys_ControlSystem_Refactorization_gmy0_T CoreSubsys_pnae;/* '<S22>/Modelo de los actuadores' */
  P_CoreSubsys_ControlSystem_Refactorization_gmy_T CoreSubsys_pna;
                                   /* '<S21>/Flujo de aire en los actuadores' */
};

/* Real-time Model Data Structure */
struct tag_RTM_ControlSystem_Refactorization_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[103];
  real_T odeF[3][103];
  ODE3_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_ControlSystem_Refactorization_T ControlSystem_Refactorization_P;

/* Block signals (default storage) */
extern B_ControlSystem_Refactorization_T ControlSystem_Refactorization_B;

/* Continuous states (default storage) */
extern X_ControlSystem_Refactorization_T ControlSystem_Refactorization_X;

/* Disabled states (default storage) */
extern XDis_ControlSystem_Refactorization_T ControlSystem_Refactorization_XDis;

/* Block states (default storage) */
extern DW_ControlSystem_Refactorization_T ControlSystem_Refactorization_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_ControlSystem_Refactorization_T
  ControlSystem_Refactorization_PrevZCX;

/* External data declarations for dependent source files */
extern const slBusActuador ControlSystem_Refactorization_rtZslBusActuador;/* slBusActuador ground */

/* Model entry point functions */
extern void ControlSystem_Refactorization_initialize(void);
extern void ControlSystem_Refactorization_output(void);
extern void ControlSystem_Refactorization_update(void);
extern void ControlSystem_Refactorization_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern ControlSystem_Refactorization_rtModel *ControlSystem_Refactorization(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_ControlSystem_Refactorization_T *const
  ControlSystem_Refactorization_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'ControlSystem_Refactorization'
 * '<S1>'   : 'ControlSystem_Refactorization/Configuración Actuadores'
 * '<S2>'   : 'ControlSystem_Refactorization/Configuración Sistema'
 * '<S3>'   : 'ControlSystem_Refactorization/For Each Subsystem4'
 * '<S4>'   : 'ControlSystem_Refactorization/For Each Subsystem5'
 * '<S5>'   : 'ControlSystem_Refactorization/Hardware'
 * '<S6>'   : 'ControlSystem_Refactorization/Lógica de control'
 * '<S7>'   : 'ControlSystem_Refactorization/Sistema de control'
 * '<S8>'   : 'ControlSystem_Refactorization/Visualización de datos en interfaz'
 * '<S9>'   : 'ControlSystem_Refactorization/untitledPanel'
 * '<S10>'  : 'ControlSystem_Refactorization/untitledPanel1'
 * '<S11>'  : 'ControlSystem_Refactorization/untitledPanel10'
 * '<S12>'  : 'ControlSystem_Refactorization/untitledPanel2'
 * '<S13>'  : 'ControlSystem_Refactorization/untitledPanel3'
 * '<S14>'  : 'ControlSystem_Refactorization/untitledPanel4'
 * '<S15>'  : 'ControlSystem_Refactorization/untitledPanel5'
 * '<S16>'  : 'ControlSystem_Refactorization/untitledPanel6'
 * '<S17>'  : 'ControlSystem_Refactorization/untitledPanel7'
 * '<S18>'  : 'ControlSystem_Refactorization/Configuración Actuadores/Configuración de usuario'
 * '<S19>'  : 'ControlSystem_Refactorization/Configuración Actuadores/For Each Subsystem'
 * '<S20>'  : 'ControlSystem_Refactorization/Configuración Sistema/Configuración de usuario'
 * '<S21>'  : 'ControlSystem_Refactorization/Hardware/DAQ'
 * '<S22>'  : 'ControlSystem_Refactorization/Hardware/Simulación'
 * '<S23>'  : 'ControlSystem_Refactorization/Hardware/DAQ/Flujo de aire en los actuadores'
 * '<S24>'  : 'ControlSystem_Refactorization/Hardware/DAQ/MATLAB Function'
 * '<S25>'  : 'ControlSystem_Refactorization/Hardware/DAQ/Flujo de aire en los actuadores/Compare To Constant5'
 * '<S26>'  : 'ControlSystem_Refactorization/Hardware/DAQ/Flujo de aire en los actuadores/Compare To Constant6'
 * '<S27>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores'
 * '<S28>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Compare To Constant'
 * '<S29>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Compare To Constant1'
 * '<S30>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Compare To Constant2'
 * '<S31>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Compare To Constant3'
 * '<S32>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Compare To Constant4'
 * '<S33>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Compare To Constant5'
 * '<S34>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Compare To Constant6'
 * '<S35>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Compare To Constant7'
 * '<S36>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Curvatura Actuador 1'
 * '<S37>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Curvatura Actuador 2'
 * '<S38>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Curvatura Actuador 3'
 * '<S39>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Curvatura Actuador 4'
 * '<S40>'  : 'ControlSystem_Refactorization/Hardware/Simulación/Modelo de los actuadores/Curvatura Actuador 5'
 * '<S41>'  : 'ControlSystem_Refactorization/Sistema de control/Compare To Constant'
 * '<S42>'  : 'ControlSystem_Refactorization/Sistema de control/Compare To Constant1'
 * '<S43>'  : 'ControlSystem_Refactorization/Sistema de control/Compare To Constant4'
 * '<S44>'  : 'ControlSystem_Refactorization/Sistema de control/Control de Curvatura'
 * '<S45>'  : 'ControlSystem_Refactorization/Sistema de control/Control de Presión'
 * '<S46>'  : 'ControlSystem_Refactorization/Sistema de control/Control de Curvatura/Controlador de posición PID'
 * '<S47>'  : 'ControlSystem_Refactorization/Sistema de control/Control de Curvatura/Controlador de posición PID/Compare To Constant'
 * '<S48>'  : 'ControlSystem_Refactorization/Visualización de datos en interfaz/Compare To Constant7'
 * '<S49>'  : 'ControlSystem_Refactorization/Visualización de datos en interfaz/DATOS DE ACTUADORES'
 */
#endif                                 /* ControlSystem_Refactorization_h_ */
