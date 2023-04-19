//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_Chi_3_LLE_Kuar_ins_api.cu
//
// Code generation for function '_coder_Chi_3_LLE_Kuar_ins_api'
//

// Include files
#include "_coder_Chi_3_LLE_Kuar_ins_api.h"
#include "Chi_3_LLE_Kuar_ins.h"
#include "Chi_3_LLE_Kuar_ins_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void Chi_3_LLE_Kuar_ins_api(const mxArray *const prhs[8],
                            const mxArray *plhs[1])
{
  static const int32_T b_dims[2]{1, 512};
  static const int32_T c_dims[2]{1, 512};
  static const int32_T d_dims[2]{1, 256};
  static const int32_T dims[2]{1, 512};
  static const int32_T e_dims[2]{1, 256};
  static const int32_T f_dims[2]{1, 256};
  static const int32_T g_dims[2]{1, 256};
  static const int32_T h_dims[2]{1, 512};
  static const int32_T i_dims[2]{1, 512};
  const mxGPUArray *F_Psi_gpu;
  const mxGPUArray *Fac_minus_gpu;
  const mxGPUArray *Fac_plus_gpu;
  const mxGPUArray *H_f_gpu;
  const mxGPUArray *gam2e_gpu;
  const mxGPUArray *gam2o_gpu;
  const mxGPUArray *gam3e_gpu;
  const mxGPUArray *gam3o_gpu;
  mxGPUArray *k_e_gpu;
  creal_T(*F_Psi)[512];
  creal_T(*Fac_minus)[512];
  creal_T(*Fac_plus)[512];
  creal_T(*k_e)[512];
  real_T(*H_f)[512];
  real_T(*gam2e)[256];
  real_T(*gam2o)[256];
  real_T(*gam3e)[256];
  real_T(*gam3o)[256];
  emlrtInitGPU(emlrtRootTLSGlobal);
  // Marshall function inputs
  F_Psi_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[0], (const char_T *)"F_Psi",
      (const char_T *)"double", true, 2, (void *)&dims[0], false);
  F_Psi = (creal_T(*)[512])emlrtGPUGetDataReadOnly(F_Psi_gpu);
  Fac_plus_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[1], (const char_T *)"Fac_plus",
      (const char_T *)"double", true, 2, (void *)&b_dims[0], false);
  Fac_plus = (creal_T(*)[512])emlrtGPUGetDataReadOnly(Fac_plus_gpu);
  Fac_minus_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[2], (const char_T *)"Fac_minus",
      (const char_T *)"double", true, 2, (void *)&c_dims[0], false);
  Fac_minus = (creal_T(*)[512])emlrtGPUGetDataReadOnly(Fac_minus_gpu);
  gam2o_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[3], (const char_T *)"gam2o",
      (const char_T *)"double", false, 2, (void *)&d_dims[0], true);
  gam2o = (real_T(*)[256])emlrtGPUGetDataReadOnly(gam2o_gpu);
  gam2e_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[4], (const char_T *)"gam2e",
      (const char_T *)"double", false, 2, (void *)&e_dims[0], true);
  gam2e = (real_T(*)[256])emlrtGPUGetDataReadOnly(gam2e_gpu);
  gam3o_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[5], (const char_T *)"gam3o",
      (const char_T *)"double", false, 2, (void *)&f_dims[0], true);
  gam3o = (real_T(*)[256])emlrtGPUGetDataReadOnly(gam3o_gpu);
  gam3e_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[6], (const char_T *)"gam3e",
      (const char_T *)"double", false, 2, (void *)&g_dims[0], true);
  gam3e = (real_T(*)[256])emlrtGPUGetDataReadOnly(gam3e_gpu);
  H_f_gpu = emlrt_marshallInGPU(emlrtRootTLSGlobal, prhs[7],
                                (const char_T *)"H_f", (const char_T *)"double",
                                false, 2, (void *)&h_dims[0], true);
  H_f = (real_T(*)[512])emlrtGPUGetDataReadOnly(H_f_gpu);
  // Create GpuArrays for outputs
  k_e_gpu = emlrtGPUCreateNumericArray((const char_T *)"double", true, 2,
                                       (void *)&i_dims[0]);
  k_e = (creal_T(*)[512])emlrtGPUGetData(k_e_gpu);
  // Invoke the target function
  Chi_3_LLE_Kuar_ins(*F_Psi, *Fac_plus, *Fac_minus, *gam2o, *gam2e, *gam3o,
                     *gam3e, *H_f, *k_e);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOutGPU(k_e_gpu);
  emlrtDestroyGPUArray(k_e_gpu);
  // Destroy GPUArrays
  emlrtDestroyGPUArray(F_Psi_gpu);
  emlrtDestroyGPUArray(Fac_plus_gpu);
  emlrtDestroyGPUArray(Fac_minus_gpu);
  emlrtDestroyGPUArray(gam2o_gpu);
  emlrtDestroyGPUArray(gam2e_gpu);
  emlrtDestroyGPUArray(gam3o_gpu);
  emlrtDestroyGPUArray(gam3e_gpu);
  emlrtDestroyGPUArray(H_f_gpu);
}

// End of code generation (_coder_Chi_3_LLE_Kuar_ins_api.cu)
