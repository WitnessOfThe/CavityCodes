/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi23_Runge_Kuarong_terminate.c
 *
 * Code generation for function 'Chi23_Runge_Kuarong_terminate'
 *
 */

/* Include files */
#include "Chi23_Runge_Kuarong_terminate.h"
#include "Chi23_Runge_Kuarong_data.h"
#include "_coder_Chi23_Runge_Kuarong_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Chi23_Runge_Kuarong_atexit(void)
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

void Chi23_Runge_Kuarong_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (Chi23_Runge_Kuarong_terminate.c) */