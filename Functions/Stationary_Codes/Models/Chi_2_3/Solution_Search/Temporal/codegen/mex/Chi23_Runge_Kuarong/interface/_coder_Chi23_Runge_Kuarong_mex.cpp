//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_Chi23_Runge_Kuarong_mex.cpp
//
// Code generation for function '_coder_Chi23_Runge_Kuarong_mex'
//

// Include files
#include "_coder_Chi23_Runge_Kuarong_mex.h"
#include "Chi23_Runge_Kuarong_data.h"
#include "Chi23_Runge_Kuarong_initialize.h"
#include "Chi23_Runge_Kuarong_terminate.h"
#include "Chi23_Runge_Kuarong_types.h"
#include "_coder_Chi23_Runge_Kuarong_api.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void Chi23_Runge_Kuarong_mexFunction(Chi23_Runge_KuarongStackData *SD,
                                     int32_T nlhs, mxArray *plhs[1],
                                     int32_T nrhs, const mxArray *prhs[2])
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  // Check for proper number of arguments.
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        19, "Chi23_Runge_Kuarong");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 19,
                        "Chi23_Runge_Kuarong");
  }
  // Call the function.
  b_Chi23_Runge_Kuarong_api(SD, prhs, &outputs);
  // Copy over outputs to the caller.
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  Chi23_Runge_KuarongStackData *c_Chi23_Runge_KuarongStackDataG{nullptr};
  c_Chi23_Runge_KuarongStackDataG = new Chi23_Runge_KuarongStackData;
  mexAtExit(&Chi23_Runge_Kuarong_atexit);
  // Module initialization.
  Chi23_Runge_Kuarong_initialize();
  try {
    emlrtShouldCleanupOnError((emlrtCTX *)emlrtRootTLSGlobal, false);
    // Dispatch the entry-point.
    Chi23_Runge_Kuarong_mexFunction(c_Chi23_Runge_KuarongStackDataG, nlhs, plhs,
                                    nrhs, prhs);
    // Module termination.
    Chi23_Runge_Kuarong_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
  delete c_Chi23_Runge_KuarongStackDataG;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_Chi23_Runge_Kuarong_mex.cpp)
