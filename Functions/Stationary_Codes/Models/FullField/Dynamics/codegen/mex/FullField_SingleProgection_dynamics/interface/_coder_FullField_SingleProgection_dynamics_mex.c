/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_FullField_SingleProgection_dynamics_mex.c
 *
 * Code generation for function '_coder_FullField_SingleProgection_dynamics_mex'
 *
 */

/* Include files */
#include "_coder_FullField_SingleProgection_dynamics_mex.h"
#include "FullField_SingleProgection_dynamics_data.h"
#include "FullField_SingleProgection_dynamics_initialize.h"
#include "FullField_SingleProgection_dynamics_terminate.h"
#include "FullField_SingleProgection_dynamics_types.h"
#include "_coder_FullField_SingleProgection_dynamics_api.h"
#include "rt_nonfinite.h"
#include <stddef.h>

/* Function Definitions */
void FullField_SingleProgection_dynamics_mexFunction(
    f_FullField_SingleProgection_dy *SD, int32_T nlhs, mxArray *plhs[1],
    int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        35, "FullField_SingleProgection_dynamics");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 35,
                        "FullField_SingleProgection_dynamics");
  }
  /* Call the function. */
  c_FullField_SingleProgection_dy(SD, prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  f_FullField_SingleProgection_dy *g_FullField_SingleProgection_dy = NULL;
  g_FullField_SingleProgection_dy =
      (f_FullField_SingleProgection_dy *)emlrtMxCalloc(
          (size_t)1, (size_t)1U * sizeof(f_FullField_SingleProgection_dy));
  mexAtExit(&FullField_SingleProgection_dynamics_atexit);
  /* Module initialization. */
  FullField_SingleProgection_dynamics_initialize();
  /* Dispatch the entry-point. */
  FullField_SingleProgection_dynamics_mexFunction(
      g_FullField_SingleProgection_dy, nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  FullField_SingleProgection_dynamics_terminate();
  emlrtMxFree(g_FullField_SingleProgection_dy);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_FullField_SingleProgection_dynamics_mex.c) */
