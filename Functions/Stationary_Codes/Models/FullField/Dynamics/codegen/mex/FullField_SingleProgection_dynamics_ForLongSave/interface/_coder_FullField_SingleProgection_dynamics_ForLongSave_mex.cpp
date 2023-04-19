//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_FullField_SingleProgection_dynamics_ForLongSave_mex.cpp
//
// Code generation for function
// '_coder_FullField_SingleProgection_dynamics_ForLongSave_mex'
//

// Include files
#include "_coder_FullField_SingleProgection_dynamics_ForLongSave_mex.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_data.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_initialize.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_terminate.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_types.h"
#include "_coder_FullField_SingleProgection_dynamics_ForLongSave_api.h"
#include "rt_nonfinite.h"
#include <stdexcept>

void emlrtExceptionBridge();
void emlrtExceptionBridge()
{
  throw std::runtime_error("");
}
// Function Definitions
void FullField_SingleProgection_dynamics_ForLongSave_mexFunction(
    e_FullField_SingleProgection_dy *SD, int32_T nlhs, mxArray *plhs[1],
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
                        47, "FullField_SingleProgection_dynamics_ForLongSave");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 47,
                        "FullField_SingleProgection_dynamics_ForLongSave");
  }
  // Call the function.
  f_FullField_SingleProgection_dy(SD, prhs, &outputs);
  // Copy over outputs to the caller.
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  e_FullField_SingleProgection_dy *g_FullField_SingleProgection_dy{nullptr};
  g_FullField_SingleProgection_dy = new e_FullField_SingleProgection_dy;
  mexAtExit(&FullField_SingleProgection_dynamics_ForLongSave_atexit);
  // Module initialization.
  FullField_SingleProgection_dynamics_ForLongSave_initialize();
  try {
    emlrtShouldCleanupOnError((emlrtCTX *)emlrtRootTLSGlobal, false);
    // Dispatch the entry-point.
    FullField_SingleProgection_dynamics_ForLongSave_mexFunction(
        g_FullField_SingleProgection_dy, nlhs, plhs, nrhs, prhs);
    // Module termination.
    FullField_SingleProgection_dynamics_ForLongSave_terminate();
  } catch (...) {
    emlrtCleanupOnException((emlrtCTX *)emlrtRootTLSGlobal);
    throw;
  }
  delete g_FullField_SingleProgection_dy;
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           (void *)&emlrtExceptionBridge);
  return emlrtRootTLSGlobal;
}

// End of code generation
// (_coder_FullField_SingleProgection_dynamics_ForLongSave_mex.cpp)
