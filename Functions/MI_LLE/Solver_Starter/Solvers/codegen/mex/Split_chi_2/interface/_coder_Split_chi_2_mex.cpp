/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Split_chi_2_mex.cpp
 *
 * Code generation for function '_coder_Split_chi_2_mex'
 *
 */

/* Include files */
#include "Split_chi_2.h"
#include "_coder_Split_chi_2_mex.h"
#include "Split_chi_2_terminate.h"
#include "_coder_Split_chi_2_api.h"
#include "Split_chi_2_initialize.h"
#include "Split_chi_2_data.h"

/* Function Declarations */
static void Split_chi_2_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[20]);

/* Function Definitions */
static void Split_chi_2_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[20])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 20) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 20, 4,
                        11, "Split_chi_2");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "Split_chi_2");
  }

  /* Call the function. */
  Split_chi_2_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(Split_chi_2_atexit);

  /* Module initialization. */
  Split_chi_2_initialize();

  /* Dispatch the entry-point. */
  Split_chi_2_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Split_chi_2_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Split_chi_2_mex.cpp) */
