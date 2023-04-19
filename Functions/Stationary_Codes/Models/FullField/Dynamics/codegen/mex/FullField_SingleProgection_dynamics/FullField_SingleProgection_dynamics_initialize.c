/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FullField_SingleProgection_dynamics_initialize.c
 *
 * Code generation for function 'FullField_SingleProgection_dynamics_initialize'
 *
 */

/* Include files */
#include "FullField_SingleProgection_dynamics_initialize.h"
#include "FullField_SingleProgection_dynamics_data.h"
#include "_coder_FullField_SingleProgection_dynamics_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void FullField_SingleProgection_dynamics_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (FullField_SingleProgection_dynamics_initialize.c) */
