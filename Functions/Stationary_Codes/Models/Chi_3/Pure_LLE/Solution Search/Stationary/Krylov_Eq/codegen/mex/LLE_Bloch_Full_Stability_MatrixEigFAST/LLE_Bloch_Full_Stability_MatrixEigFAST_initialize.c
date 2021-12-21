/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LLE_Bloch_Full_Stability_MatrixEigFAST_initialize.c
 *
 * Code generation for function 'LLE_Bloch_Full_Stability_MatrixEigFAST_initialize'
 *
 */

/* Include files */
#include "LLE_Bloch_Full_Stability_MatrixEigFAST_initialize.h"
#include "LLE_Bloch_Full_Stability_MatrixEigFAST_data.h"
#include "_coder_LLE_Bloch_Full_Stability_MatrixEigFAST_mex.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void LLE_Bloch_Full_Stability_MatrixEigFAST_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (LLE_Bloch_Full_Stability_MatrixEigFAST_initialize.c) */
