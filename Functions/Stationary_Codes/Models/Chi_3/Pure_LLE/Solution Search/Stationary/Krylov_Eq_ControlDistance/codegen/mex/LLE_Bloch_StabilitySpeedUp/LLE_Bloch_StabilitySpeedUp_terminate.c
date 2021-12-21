/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LLE_Bloch_StabilitySpeedUp_terminate.c
 *
 * Code generation for function 'LLE_Bloch_StabilitySpeedUp_terminate'
 *
 */

/* Include files */
#include "LLE_Bloch_StabilitySpeedUp_terminate.h"
#include "LLE_Bloch_StabilitySpeedUp_data.h"
#include "_coder_LLE_Bloch_StabilitySpeedUp_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void LLE_Bloch_StabilitySpeedUp_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void LLE_Bloch_StabilitySpeedUp_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (LLE_Bloch_StabilitySpeedUp_terminate.c) */
