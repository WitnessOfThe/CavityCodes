/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi_3_LLE_Runge_Kuarong_with_Scan_terminate.c
 *
 * Code generation for function 'Chi_3_LLE_Runge_Kuarong_with_Scan_terminate'
 *
 */

/* Include files */
#include "Chi_3_LLE_Runge_Kuarong_with_Scan_terminate.h"
#include "Chi_3_LLE_Runge_Kuarong_with_Scan_data.h"
#include "_coder_Chi_3_LLE_Runge_Kuarong_with_Scan_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Chi_3_LLE_Runge_Kuarong_with_Scan_atexit(void)
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

void Chi_3_LLE_Runge_Kuarong_with_Scan_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (Chi_3_LLE_Runge_Kuarong_with_Scan_terminate.c) */
