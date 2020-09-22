/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Chi_3_LLE_Kuar_mex.c
 *
 * Code generation for function '_coder_Chi_3_LLE_Kuar_mex'
 *
 */

/* Include files */
#include "Chi_3_LLE_Kuar.h"
#include "_coder_Chi_3_LLE_Kuar_mex.h"
#include "Chi_3_LLE_Kuar_terminate.h"
#include "_coder_Chi_3_LLE_Kuar_api.h"
#include "Chi_3_LLE_Kuar_initialize.h"
#include "Chi_3_LLE_Kuar_data.h"

/* Function Declarations */
static void Chi_3_LLE_Kuar_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[5]);

/* Function Definitions */
static void Chi_3_LLE_Kuar_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[5])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        14, "Chi_3_LLE_Kuar");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "Chi_3_LLE_Kuar");
  }

  /* Call the function. */
  Chi_3_LLE_Kuar_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(Chi_3_LLE_Kuar_atexit);

  /* Module initialization. */
  Chi_3_LLE_Kuar_initialize();

  /* Dispatch the entry-point. */
  Chi_3_LLE_Kuar_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Chi_3_LLE_Kuar_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Chi_3_LLE_Kuar_mex.c) */
