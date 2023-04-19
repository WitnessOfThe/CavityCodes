//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi_3_LLE_Kuar_ins_terminate.cu
//
// Code generation for function 'Chi_3_LLE_Kuar_ins_terminate'
//

// Include files
#include "Chi_3_LLE_Kuar_ins_terminate.h"
#include "Chi_3_LLE_Kuar_ins_data.h"
#include "_coder_Chi_3_LLE_Kuar_ins_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void Chi_3_LLE_Kuar_ins_atexit()
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Chi_3_LLE_Kuar_ins_terminate()
{
  cudaError_t errCode;
  errCode = cudaGetLastError();
  if (errCode != cudaSuccess) {
    emlrtThinCUDAError(static_cast<uint32_T>(errCode),
                       (char_T *)cudaGetErrorName(errCode),
                       (char_T *)cudaGetErrorString(errCode),
                       (char_T *)"SafeBuild", emlrtRootTLSGlobal);
  }
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (Chi_3_LLE_Kuar_ins_terminate.cu)
