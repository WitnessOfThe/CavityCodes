/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Chi_3_LLE_Runge_Kuarong_with_Scan_mex.c
 *
 * Code generation for function '_coder_Chi_3_LLE_Runge_Kuarong_with_Scan_mex'
 *
 */

/* Include files */
#include "_coder_Chi_3_LLE_Runge_Kuarong_with_Scan_mex.h"
#include "Chi_3_LLE_Runge_Kuarong_with_Scan_data.h"
#include "Chi_3_LLE_Runge_Kuarong_with_Scan_initialize.h"
#include "Chi_3_LLE_Runge_Kuarong_with_Scan_terminate.h"
#include "_coder_Chi_3_LLE_Runge_Kuarong_with_Scan_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Chi_3_LLE_Runge_Kuarong_with_Scan_mexFunction(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[1];
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        33, "Chi_3_LLE_Runge_Kuarong_with_Scan");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 33,
                        "Chi_3_LLE_Runge_Kuarong_with_Scan");
  }

  /* Call the function. */
  c_Chi_3_LLE_Runge_Kuarong_with_(prhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&Chi_3_LLE_Runge_Kuarong_with_Scan_atexit);

  /* Module initialization. */
  Chi_3_LLE_Runge_Kuarong_with_Scan_initialize();

  /* Dispatch the entry-point. */
  Chi_3_LLE_Runge_Kuarong_with_Scan_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Chi_3_LLE_Runge_Kuarong_with_Scan_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Chi_3_LLE_Runge_Kuarong_with_Scan_mex.c) */
