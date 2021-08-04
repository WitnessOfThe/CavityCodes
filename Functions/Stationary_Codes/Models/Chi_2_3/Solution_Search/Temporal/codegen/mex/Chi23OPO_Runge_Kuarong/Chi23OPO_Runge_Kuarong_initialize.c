/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi23OPO_Runge_Kuarong_initialize.c
 *
 * Code generation for function 'Chi23OPO_Runge_Kuarong_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Chi23OPO_Runge_Kuarong.h"
#include "Chi23OPO_Runge_Kuarong_initialize.h"
#include "_coder_Chi23OPO_Runge_Kuarong_mex.h"
#include "Chi23OPO_Runge_Kuarong_data.h"

/* Function Definitions */
void Chi23OPO_Runge_Kuarong_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (Chi23OPO_Runge_Kuarong_initialize.c) */
