/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Split_chi_2_initialize.cpp
 *
 * Code generation for function 'Split_chi_2_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Split_chi_2.h"
#include "Split_chi_2_initialize.h"
#include "_coder_Split_chi_2_mex.h"
#include "Split_chi_2_data.h"

/* Function Definitions */
void Split_chi_2_initialize()
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

/* End of code generation (Split_chi_2_initialize.cpp) */
