//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi23_Runge_Kuarong_GPU_terminate.cu
//
// Code generation for function 'Chi23_Runge_Kuarong_GPU_terminate'
//

// Include files
#include "Chi23_Runge_Kuarong_GPU_terminate.h"
#include "Chi23_Runge_Kuarong_GPU_data.h"
#include "_coder_Chi23_Runge_Kuarong_GPU_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void Chi23_Runge_Kuarong_GPU_atexit()
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void Chi23_Runge_Kuarong_GPU_terminate()
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

// End of code generation (Chi23_Runge_Kuarong_GPU_terminate.cu)
