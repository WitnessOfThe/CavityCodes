/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi23OPO_Runge_Kuarong_terminate.c
 *
 * Code generation for function 'Chi23OPO_Runge_Kuarong_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Chi23OPO_Runge_Kuarong.h"
#include "Chi23OPO_Runge_Kuarong_terminate.h"
#include "_coder_Chi23OPO_Runge_Kuarong_mex.h"
#include "Chi23OPO_Runge_Kuarong_data.h"

/* Function Definitions */
void Chi23OPO_Runge_Kuarong_atexit(void)
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
}

void Chi23OPO_Runge_Kuarong_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (Chi23OPO_Runge_Kuarong_terminate.c) */
