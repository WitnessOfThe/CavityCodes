//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_Chi_3_LLE_Kuar_ins_mex.cu
//
// Code generation for function '_coder_Chi_3_LLE_Kuar_ins_mex'
//

// Include files
#include "_coder_Chi_3_LLE_Kuar_ins_mex.h"
#include "Chi_3_LLE_Kuar_ins_data.h"
#include "Chi_3_LLE_Kuar_ins_initialize.h"
#include "Chi_3_LLE_Kuar_ins_terminate.h"
#include "_coder_Chi_3_LLE_Kuar_ins_api.h"
#include "rt_nonfinite.h"

// Function Definitions
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&Chi_3_LLE_Kuar_ins_atexit);
  // Module initialization.
  Chi_3_LLE_Kuar_ins_initialize();
  // Dispatch the entry-point.
  unsafe_Chi_3_LLE_Kuar_ins_mexFunction(nlhs, plhs, nrhs, prhs);
  // Module termination.
  Chi_3_LLE_Kuar_ins_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, nullptr, 1,
                           nullptr);
  return emlrtRootTLSGlobal;
}

void unsafe_Chi_3_LLE_Kuar_ins_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                           int32_T nrhs, const mxArray *prhs[8])
{
  const mxArray *outputs[1];
  // Check for proper number of arguments.
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 8, 4, 18, "Chi_3_LLE_Kuar_ins");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "Chi_3_LLE_Kuar_ins");
  }
  // Call the function.
  Chi_3_LLE_Kuar_ins_api(prhs, outputs);
  // Copy over outputs to the caller.
  emlrtReturnArrays(1, &plhs[0], &outputs[0]);
}

// End of code generation (_coder_Chi_3_LLE_Kuar_ins_mex.cu)
