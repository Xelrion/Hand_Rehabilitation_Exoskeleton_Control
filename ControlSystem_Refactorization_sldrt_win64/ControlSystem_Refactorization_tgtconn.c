/*
 * ControlSystem_Refactorization_tgtconn.c
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

#include "rtwtypes.h"
#define EXTERN_C
#include <stddef.h>
#include "ToAsyncQueueTgtAppSvc/ToAsyncQueueTgtAppSvcCIntrf.h"

EXTERN_C void TgtConnBackgroundTask()
{
}

EXTERN_C const char_T *TgtConnInit(int_T argc, char_T *argv[])
{
  const char_T *result = (NULL);       /* assume success */
  if (startToAsyncQueueTgtAppSvc()) {
    result = "Could not start ToAsyncQueue app service";
    return(result);
  }

  return(result);
}

EXTERN_C void TgtConnTerm()
{
  terminateToAsyncQueueTgtAppSvc();
}

EXTERN_C void TgtConnPreStep(int_T tid)
{
}

EXTERN_C void TgtConnPostStep(int_T tid)
{
}

/* EOF: ControlSystem_Refactorization_tgtconn.c */
