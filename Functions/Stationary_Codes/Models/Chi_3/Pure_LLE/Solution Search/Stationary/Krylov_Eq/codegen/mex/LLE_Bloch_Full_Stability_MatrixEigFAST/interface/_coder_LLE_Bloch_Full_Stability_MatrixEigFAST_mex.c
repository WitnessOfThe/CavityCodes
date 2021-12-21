/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_LLE_Bloch_Full_Stability_MatrixEigFAST_mex.c
 *
 * Code generation for function '_coder_LLE_Bloch_Full_Stability_MatrixEigFAST_mex'
 *
 */

/* Include files */
#include "_coder_LLE_Bloch_Full_Stability_MatrixEigFAST_mex.h"
#include "LLE_Bloch_Full_Stability_MatrixEigFAST_data.h"
#include "LLE_Bloch_Full_Stability_MatrixEigFAST_initialize.h"
#include "LLE_Bloch_Full_Stability_MatrixEigFAST_terminate.h"
#include "LLE_Bloch_Full_Stability_MatrixEigFAST_types.h"
#include "_coder_LLE_Bloch_Full_Stability_MatrixEigFAST_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void LLE_Bloch_Full_Stability_MatrixEigFAST_mexFunction
  (d_LLE_Bloch_Full_Stability_Matr *SD, int32_T nlhs, mxArray *plhs[1], int32_T
   nrhs, const mxArray *prhs[3])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[1];
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        38, "LLE_Bloch_Full_Stability_MatrixEigFAST");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 38,
                        "LLE_Bloch_Full_Stability_MatrixEigFAST");
  }

  /* Call the function. */
  c_LLE_Bloch_Full_Stability_Matr(SD, prhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  d_LLE_Bloch_Full_Stability_Matr *e_LLE_Bloch_Full_Stability_Matr = NULL;
  e_LLE_Bloch_Full_Stability_Matr = (d_LLE_Bloch_Full_Stability_Matr *)
    emlrtMxCalloc(1, (size_t)1U * sizeof(d_LLE_Bloch_Full_Stability_Matr));
  mexAtExit(&LLE_Bloch_Full_Stability_MatrixEigFAST_atexit);

  /* Module initialization. */
  LLE_Bloch_Full_Stability_MatrixEigFAST_initialize();

  /* Dispatch the entry-point. */
  LLE_Bloch_Full_Stability_MatrixEigFAST_mexFunction
    (e_LLE_Bloch_Full_Stability_Matr, nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  LLE_Bloch_Full_Stability_MatrixEigFAST_terminate();
  emlrtMxFree(e_LLE_Bloch_Full_Stability_Matr);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_LLE_Bloch_Full_Stability_MatrixEigFAST_mex.c) */
