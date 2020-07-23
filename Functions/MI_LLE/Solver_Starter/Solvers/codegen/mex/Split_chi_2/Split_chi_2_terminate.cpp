/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Split_chi_2_terminate.cpp
 *
 * Code generation for function 'Split_chi_2_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Split_chi_2.h"
#include "Split_chi_2_terminate.h"
#include "_coder_Split_chi_2_mex.h"
#include "Split_chi_2_data.h"

/* Function Definitions */
void Split_chi_2_atexit()
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

void Split_chi_2_terminate()
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (Split_chi_2_terminate.cpp) */
