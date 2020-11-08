//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  _coder_Chi_3_LLE_Runge_Kuarong_mex.cpp
//
//  Code generation for function '_coder_Chi_3_LLE_Runge_Kuarong_mex'
//


// Include files
#include "_coder_Chi_3_LLE_Runge_Kuarong_mex.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"
#include "Chi_3_LLE_Runge_Kuarong_initialize.h"
#include "Chi_3_LLE_Runge_Kuarong_terminate.h"
#include "Chi_3_LLE_Runge_Kuarong_types.h"
#include "_coder_Chi_3_LLE_Runge_Kuarong_api.h"
#include "rt_nonfinite.h"

// Function Definitions
void Chi_3_LLE_Runge_Kuarong_mexFunction(c_Chi_3_LLE_Runge_KuarongStackD *SD,
  int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  const mxArray *outputs[1];
  st.tls = emlrtRootTLSGlobal;

  // Check for proper number of arguments.
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        23, "Chi_3_LLE_Runge_Kuarong");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 23,
                        "Chi_3_LLE_Runge_Kuarong");
  }

  // Call the function.
  Chi_3_LLE_Runge_Kuarong_api(SD, prhs, outputs);

  // Copy over outputs to the caller.
  emlrtReturnArrays(1, plhs, &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  c_Chi_3_LLE_Runge_KuarongStackD *d_Chi_3_LLE_Runge_KuarongStackD = NULL;
  d_Chi_3_LLE_Runge_KuarongStackD = new c_Chi_3_LLE_Runge_KuarongStackD;
  mexAtExit(&Chi_3_LLE_Runge_Kuarong_atexit);

  // Module initialization.
  Chi_3_LLE_Runge_Kuarong_initialize();
  try {
    emlrtShouldCleanupOnError(emlrtRootTLSGlobal, false);

    // Dispatch the entry-point.
    Chi_3_LLE_Runge_Kuarong_mexFunction(d_Chi_3_LLE_Runge_KuarongStackD, nlhs,
      plhs, nrhs, prhs);

    // Module termination.
    Chi_3_LLE_Runge_Kuarong_terminate();
  } catch (...) {
    emlrtCleanupOnException(emlrtRootTLSGlobal);
    throw;
  }

  delete d_Chi_3_LLE_Runge_KuarongStackD;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_Chi_3_LLE_Runge_Kuarong_mex.cpp)
