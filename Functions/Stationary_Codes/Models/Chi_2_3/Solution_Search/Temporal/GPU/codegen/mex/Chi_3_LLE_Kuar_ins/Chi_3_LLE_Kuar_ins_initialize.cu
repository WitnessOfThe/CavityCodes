//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi_3_LLE_Kuar_ins_initialize.cu
//
// Code generation for function 'Chi_3_LLE_Kuar_ins_initialize'
//

// Include files
#include "Chi_3_LLE_Kuar_ins_initialize.h"
#include "Chi_3_LLE_Kuar_ins_data.h"
#include "_coder_Chi_3_LLE_Kuar_ins_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void Chi_3_LLE_Kuar_ins_initialize()
{
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLicenseCheckR2012b(emlrtRootTLSGlobal,
                          (const char_T *)"distrib_computing_toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
  cudaGetLastError();
}

// End of code generation (Chi_3_LLE_Kuar_ins_initialize.cu)
