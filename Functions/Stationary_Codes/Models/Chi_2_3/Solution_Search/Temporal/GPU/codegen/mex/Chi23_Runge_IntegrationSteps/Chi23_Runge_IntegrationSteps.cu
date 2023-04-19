//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi23_Runge_IntegrationSteps.cu
//
// Code generation for function 'Chi23_Runge_IntegrationSteps'
//

// Include files
#include "Chi23_Runge_IntegrationSteps.h"
#include "Chi23_Runge_IntegrationSteps_data.h"
#include "Chi23_Runge_IntegrationSteps_types.h"
#include "rt_nonfinite.h"
#include "MWCudaDimUtility.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Variable Definitions
static emlrtMCInfo emlrtMCI{
    21,                   // lineNo
    16,                   // colNo
    "Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/GPU/Chi23_Runge_Integrat"
    "ionSteps.m" // pName
};

static emlrtMCInfo b_emlrtMCI{
    35,                   // lineNo
    21,                   // colNo
    "Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/GPU/Chi23_Runge_Integrat"
    "ionSteps.m" // pName
};

// Function Declarations
static const mxArray *
Chi_3_LLE_Kuar_ins_mex(const mxArray *m1, const mxArray *m2, const mxArray *m3,
                       const mxArray *m4, const mxArray *m5, const mxArray *m6,
                       const mxArray *m7, const mxArray *m8,
                       emlrtMCInfo *location);

static void b_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               creal_T ret[512]);

static void checkCudaError(cudaError_t errCode, const char_T *file,
                           uint32_T line);

static __global__ void d_Chi23_Runge_IntegrationSteps_(const creal_T d[1536],
                                                       creal_T b_d[1536]);

static __global__ void e_Chi23_Runge_IntegrationSteps_(const creal_T F_e[512],
                                                       creal_T E_temp[512]);

static void emlrt_marshallIn(const mxArray *c_a__output_of_Chi_3_LLE_Kuar_i,
                             const char_T *identifier, creal_T y[512]);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             creal_T y[512]);

static __global__ void
f_Chi23_Runge_IntegrationSteps_(const creal_T exp_plus_omega[1536],
                                creal_T u[512]);

static __global__ void
g_Chi23_Runge_IntegrationSteps_(const creal_T exp_minus_omega[1536],
                                creal_T u[512]);

static __global__ void h_Chi23_Runge_IntegrationSteps_(const creal_T u[512],
                                                       creal_T d[1536]);

static __global__ void
i_Chi23_Runge_IntegrationSteps_(const creal_T d[1536], const int32_T ii,
                                const real_T dt, const creal_T E_temp[512],
                                const real_T mode_range[512], creal_T u[512]);

static __global__ void j_Chi23_Runge_IntegrationSteps_(
    const creal_T u[512], const real_T mode_range[512], creal_T E_temp[512]);

static __global__ void
k_Chi23_Runge_IntegrationSteps_(const creal_T exp_plus_omega[1536],
                                const int32_T i, creal_T u[512]);

static __global__ void
l_Chi23_Runge_IntegrationSteps_(const creal_T exp_minus_omega[1536],
                                const int32_T i, creal_T u[512]);

static __global__ void m_Chi23_Runge_IntegrationSteps_(const creal_T F_e[512],
                                                       const creal_T u[512],
                                                       const int32_T i,
                                                       creal_T E_temp[512],
                                                       creal_T d[1536]);

static __global__ void
n_Chi23_Runge_IntegrationSteps_(const creal_T d[1536], const int32_T i6,
                                const real_T dt, const creal_T F_e[512],
                                const real_T mode_range[512], creal_T u[512]);

static __global__ void
o_Chi23_Runge_IntegrationSteps_(const creal_T u[512],
                                const real_T mode_range[512], creal_T F_e[512]);

static __global__ void
p_Chi23_Runge_IntegrationSteps_(const creal_T F_e[512],
                                const creal_T shift_back[512],
                                const real_T mode_range[512], creal_T u[512]);

static __global__ void
q_Chi23_Runge_IntegrationSteps_(const creal_T u[512],
                                const real_T mode_range[512], creal_T F_e[512]);

static void raiseCudaError(uint32_T errCode, const char_T *file, uint32_T line,
                           const char_T *errorName, const char_T *errorString);

// Function Definitions
static const mxArray *
Chi_3_LLE_Kuar_ins_mex(const mxArray *m1, const mxArray *m2, const mxArray *m3,
                       const mxArray *m4, const mxArray *m5, const mxArray *m6,
                       const mxArray *m7, const mxArray *m8,
                       emlrtMCInfo *location)
{
  const mxArray *pArrays[8];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  pArrays[3] = m4;
  pArrays[4] = m5;
  pArrays[5] = m6;
  pArrays[6] = m7;
  pArrays[7] = m8;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m, 8, &pArrays[0],
                               (const char_T *)"Chi_3_LLE_Kuar_ins_mex", true,
                               location);
}

static void b_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               creal_T ret[512])
{
  static const int32_T dims[2]{1, 512};
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", true, 2U, (void *)&dims[0]);
  emlrtImportArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 8, true);
  emlrtDestroyArray(&src);
}

static void checkCudaError(cudaError_t errCode, const char_T *file,
                           uint32_T line)
{
  if (errCode != cudaSuccess) {
    raiseCudaError(errCode, file, line, cudaGetErrorName(errCode),
                   cudaGetErrorString(errCode));
  }
}

static __global__ __launch_bounds__(
    512, 1) void d_Chi23_Runge_IntegrationSteps_(const creal_T d[1536],
                                                 creal_T b_d[1536])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 1536) {
    b_d[i] = d[i];
  }
}

static __global__ __launch_bounds__(
    512, 1) void e_Chi23_Runge_IntegrationSteps_(const creal_T F_e[512],
                                                 creal_T E_temp[512])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 512) {
    E_temp[i] = F_e[i];
  }
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, creal_T y[512])
{
  b_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *c_a__output_of_Chi_3_LLE_Kuar_i,
                             const char_T *identifier, creal_T y[512])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(emlrtAlias(c_a__output_of_Chi_3_LLE_Kuar_i), &thisId, y);
  emlrtDestroyArray(&c_a__output_of_Chi_3_LLE_Kuar_i);
}

static __global__
    __launch_bounds__(512, 1) void f_Chi23_Runge_IntegrationSteps_(
        const creal_T exp_plus_omega[1536], creal_T u[512])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 512) {
    u[i] = exp_plus_omega[3 * i];
  }
}

static __global__
    __launch_bounds__(512, 1) void g_Chi23_Runge_IntegrationSteps_(
        const creal_T exp_minus_omega[1536], creal_T u[512])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 512) {
    u[i] = exp_minus_omega[3 * i];
  }
}

static __global__ __launch_bounds__(
    512, 1) void h_Chi23_Runge_IntegrationSteps_(const creal_T u[512],
                                                 creal_T d[1536])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 512) {
    d[3 * i] = u[i];
  }
}

static __global__
    __launch_bounds__(512, 1) void i_Chi23_Runge_IntegrationSteps_(
        const creal_T d[1536], const int32_T ii, const real_T dt,
        const creal_T E_temp[512], const real_T mode_range[512], creal_T u[512])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 512) {
    real_T b_d;
    b_d = mode_range[i];
    u[i].re = E_temp[static_cast<int32_T>(b_d) - 1].re +
              dt * d[ii + 3 * (static_cast<int32_T>(b_d) - 1)].re;
    u[i].im = E_temp[static_cast<int32_T>(b_d) - 1].im +
              dt * d[ii + 3 * (static_cast<int32_T>(b_d) - 1)].im;
  }
}

static __global__
    __launch_bounds__(512, 1) void j_Chi23_Runge_IntegrationSteps_(
        const creal_T u[512], const real_T mode_range[512], creal_T E_temp[512])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 512) {
    E_temp[static_cast<int32_T>(mode_range[i]) - 1] = u[i];
  }
}

static __global__
    __launch_bounds__(512, 1) void k_Chi23_Runge_IntegrationSteps_(
        const creal_T exp_plus_omega[1536], const int32_T i, creal_T u[512])
{
  uint64_T threadId;
  int32_T b_i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  b_i = static_cast<int32_T>(threadId);
  if (b_i < 512) {
    u[b_i] = exp_plus_omega[i + 3 * b_i];
  }
}

static __global__
    __launch_bounds__(512, 1) void l_Chi23_Runge_IntegrationSteps_(
        const creal_T exp_minus_omega[1536], const int32_T i, creal_T u[512])
{
  uint64_T threadId;
  int32_T b_i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  b_i = static_cast<int32_T>(threadId);
  if (b_i < 512) {
    u[b_i] = exp_minus_omega[i + 3 * b_i];
  }
}

static __global__
    __launch_bounds__(512, 1) void m_Chi23_Runge_IntegrationSteps_(
        const creal_T F_e[512], const creal_T u[512], const int32_T i,
        creal_T E_temp[512], creal_T d[1536])
{
  uint64_T threadId;
  int32_T b_i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  b_i = static_cast<int32_T>(threadId);
  if (b_i < 512) {
    d[i + 3 * b_i] = u[b_i];
    E_temp[b_i] = F_e[b_i];
  }
}

static __global__
    __launch_bounds__(512, 1) void n_Chi23_Runge_IntegrationSteps_(
        const creal_T d[1536], const int32_T i6, const real_T dt,
        const creal_T F_e[512], const real_T mode_range[512], creal_T u[512])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 512) {
    real_T b_d;
    b_d = mode_range[i];
    u[i].re = F_e[static_cast<int32_T>(b_d) - 1].re +
              dt * d[i6 + 3 * (static_cast<int32_T>(b_d) - 1)].re;
    u[i].im = F_e[static_cast<int32_T>(b_d) - 1].im +
              dt * d[i6 + 3 * (static_cast<int32_T>(b_d) - 1)].im;
  }
}

static __global__
    __launch_bounds__(512, 1) void o_Chi23_Runge_IntegrationSteps_(
        const creal_T u[512], const real_T mode_range[512], creal_T F_e[512])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 512) {
    F_e[static_cast<int32_T>(mode_range[i]) - 1] = u[i];
  }
}

static __global__ __launch_bounds__(
    512, 1) void p_Chi23_Runge_IntegrationSteps_(const creal_T F_e[512],
                                                 const creal_T shift_back[512],
                                                 const real_T mode_range[512],
                                                 creal_T u[512])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 512) {
    real_T d;
    d = mode_range[i];
    u[i].re = shift_back[static_cast<int32_T>(d) - 1].re *
                  F_e[static_cast<int32_T>(d) - 1].re -
              shift_back[static_cast<int32_T>(d) - 1].im *
                  F_e[static_cast<int32_T>(d) - 1].im;
    u[i].im = shift_back[static_cast<int32_T>(d) - 1].re *
                  F_e[static_cast<int32_T>(d) - 1].im +
              shift_back[static_cast<int32_T>(d) - 1].im *
                  F_e[static_cast<int32_T>(d) - 1].re;
  }
}

static __global__
    __launch_bounds__(512, 1) void q_Chi23_Runge_IntegrationSteps_(
        const creal_T u[512], const real_T mode_range[512], creal_T F_e[512])
{
  uint64_T threadId;
  int32_T i;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  i = static_cast<int32_T>(threadId);
  if (i < 512) {
    F_e[static_cast<int32_T>(mode_range[i]) - 1] = u[i];
  }
}

static void raiseCudaError(uint32_T errCode, const char_T *file, uint32_T line,
                           const char_T *errorName, const char_T *errorString)
{
  emlrtRTEInfo rtInfo;
  uint32_T len;
  char_T *brk;
  char_T *fn;
  char_T *pn;
  len = strlen(file);
  pn = (char_T *)calloc(len + 1U, 1U);
  fn = (char_T *)calloc(len + 1U, 1U);
  memcpy(pn, file, len);
  memcpy(fn, file, len);
  brk = strrchr(fn, '.');
  *brk = '\x00';
  brk = strrchr(fn, '/');
  if (brk == nullptr) {
    brk = strrchr(fn, '\\');
  }
  if (brk == nullptr) {
    brk = fn;
  } else {
    brk++;
  }
  rtInfo.lineNo = static_cast<int32_T>(line);
  rtInfo.colNo = 0;
  rtInfo.fName = brk;
  rtInfo.pName = pn;
  emlrtCUDAError(errCode, (char_T *)errorName, (char_T *)errorString, &rtInfo,
                 emlrtRootTLSGlobal);
}

void Chi23_Runge_IntegrationSteps(
    real_T nt, real_T dt, const creal_T d[1536], creal_T F_e[512],
    const creal_T exp_plus_omega[1536], const creal_T exp_minus_omega[1536],
    const struct0_T *Runge, const creal_T shift_back[512],
    const real_T gam2o[256], const real_T gam2e[256], const real_T gam3o[256],
    const real_T gam3e[256], const real_T H_f[512],
    const real_T mode_range[512])
{
  static const int32_T iv[2]{1, 512};
  static const int32_T iv1[2]{1, 512};
  static const int32_T iv10[2]{1, 512};
  static const int32_T iv11[2]{1, 256};
  static const int32_T iv12[2]{1, 256};
  static const int32_T iv13[2]{1, 256};
  static const int32_T iv14[2]{1, 256};
  static const int32_T iv15[2]{1, 512};
  static const int32_T iv2[2]{1, 512};
  static const int32_T iv3[2]{1, 256};
  static const int32_T iv4[2]{1, 256};
  static const int32_T iv5[2]{1, 256};
  static const int32_T iv6[2]{1, 256};
  static const int32_T iv7[2]{1, 512};
  static const int32_T iv8[2]{1, 512};
  static const int32_T iv9[2]{1, 512};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *y;
  creal_T(*gpu_d)[1536];
  creal_T E_temp[512];
  creal_T u[512];
  creal_T(*cpu_F_e)[512];
  creal_T(*gpu_E_temp)[512];
  creal_T(*gpu_u)[512];
  real_T cpu_H_f[512];
  real_T(*gpu_mode_range)[512];
  real_T cpu_gam2e[256];
  real_T cpu_gam2o[256];
  real_T cpu_gam3e[256];
  real_T cpu_gam3o[256];
  real_T *pData;
  int32_T i;
  boolean_T cpu_H_f_dirtyOnGpu;
  boolean_T cpu_gam2e_dirtyOnGpu;
  boolean_T cpu_gam2o_dirtyOnGpu;
  boolean_T cpu_gam3e_dirtyOnGpu;
  boolean_T cpu_gam3o_dirtyOnGpu;
  boolean_T mode_range_dirtyOnCpu;
#define CUDACHECK(errCall) checkCudaError(errCall, __FILE__, __LINE__)
  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  cudaMalloc(&gpu_mode_range, 4096UL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&gpu_u, 8192UL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&gpu_E_temp, 8192UL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&gpu_d, 24576UL);
  CUDACHECK(cudaGetLastError());
  cpu_F_e = (creal_T(*)[512])malloc(8192U);
  cpu_H_f_dirtyOnGpu = true;
  cpu_gam3e_dirtyOnGpu = true;
  cpu_gam3o_dirtyOnGpu = true;
  cpu_gam2e_dirtyOnGpu = true;
  cpu_gam2o_dirtyOnGpu = true;
  mode_range_dirtyOnCpu = true;
  i = static_cast<int32_T>(nt);
  for (int32_T ni{0}; ni < i; ni++) {
    real_T b_dt;
    int32_T b_i;
    int32_T i6;
    d_Chi23_Runge_IntegrationSteps_<<<dim3(3U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        d, *gpu_d);
    CUDACHECK(cudaGetLastError());
    e_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        F_e, *gpu_E_temp);
    CUDACHECK(cudaGetLastError());
    y = nullptr;
    m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS,
                                mxCOMPLEX);
    cudaMemcpy(*cpu_F_e, F_e, 8192UL, cudaMemcpyDeviceToHost);
    CUDACHECK(cudaGetLastError());
    emlrtExportNumericArrayR2013b(emlrtRootTLSGlobal, m, &(*cpu_F_e)[0], 8);
    emlrtAssign(&y, m);
    f_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        exp_plus_omega, *gpu_u);
    CUDACHECK(cudaGetLastError());
    b_y = nullptr;
    m = emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS,
                                mxCOMPLEX);
    cudaMemcpy(u, *gpu_u, 8192UL, cudaMemcpyDeviceToHost);
    CUDACHECK(cudaGetLastError());
    emlrtExportNumericArrayR2013b(emlrtRootTLSGlobal, m, &u[0], 8);
    emlrtAssign(&b_y, m);
    g_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        exp_minus_omega, *gpu_u);
    CUDACHECK(cudaGetLastError());
    c_y = nullptr;
    m = emlrtCreateNumericArray(2, (const void *)&iv2[0], mxDOUBLE_CLASS,
                                mxCOMPLEX);
    cudaMemcpy(u, *gpu_u, 8192UL, cudaMemcpyDeviceToHost);
    CUDACHECK(cudaGetLastError());
    emlrtExportNumericArrayR2013b(emlrtRootTLSGlobal, m, &u[0], 8);
    emlrtAssign(&c_y, m);
    d_y = nullptr;
    m = emlrtCreateNumericArray(2, (const void *)&iv3[0], mxDOUBLE_CLASS,
                                mxREAL);
    pData = emlrtMxGetPr(m);
    for (b_i = 0; b_i < 256; b_i++) {
      if (cpu_gam2o_dirtyOnGpu) {
        cudaMemcpy(cpu_gam2o, gam2o, 2048UL, cudaMemcpyDeviceToHost);
        CUDACHECK(cudaGetLastError());
      }
      cpu_gam2o_dirtyOnGpu = false;
      pData[b_i] = cpu_gam2o[b_i];
    }
    emlrtAssign(&d_y, m);
    e_y = nullptr;
    m = emlrtCreateNumericArray(2, (const void *)&iv4[0], mxDOUBLE_CLASS,
                                mxREAL);
    pData = emlrtMxGetPr(m);
    for (b_i = 0; b_i < 256; b_i++) {
      if (cpu_gam2e_dirtyOnGpu) {
        cudaMemcpy(cpu_gam2e, gam2e, 2048UL, cudaMemcpyDeviceToHost);
        CUDACHECK(cudaGetLastError());
      }
      cpu_gam2e_dirtyOnGpu = false;
      pData[b_i] = cpu_gam2e[b_i];
    }
    emlrtAssign(&e_y, m);
    f_y = nullptr;
    m = emlrtCreateNumericArray(2, (const void *)&iv5[0], mxDOUBLE_CLASS,
                                mxREAL);
    pData = emlrtMxGetPr(m);
    for (b_i = 0; b_i < 256; b_i++) {
      if (cpu_gam3o_dirtyOnGpu) {
        cudaMemcpy(cpu_gam3o, gam3o, 2048UL, cudaMemcpyDeviceToHost);
        CUDACHECK(cudaGetLastError());
      }
      cpu_gam3o_dirtyOnGpu = false;
      pData[b_i] = cpu_gam3o[b_i];
    }
    emlrtAssign(&f_y, m);
    g_y = nullptr;
    m = emlrtCreateNumericArray(2, (const void *)&iv6[0], mxDOUBLE_CLASS,
                                mxREAL);
    pData = emlrtMxGetPr(m);
    for (b_i = 0; b_i < 256; b_i++) {
      if (cpu_gam3e_dirtyOnGpu) {
        cudaMemcpy(cpu_gam3e, gam3e, 2048UL, cudaMemcpyDeviceToHost);
        CUDACHECK(cudaGetLastError());
      }
      cpu_gam3e_dirtyOnGpu = false;
      pData[b_i] = cpu_gam3e[b_i];
    }
    emlrtAssign(&g_y, m);
    h_y = nullptr;
    m = emlrtCreateNumericArray(2, (const void *)&iv7[0], mxDOUBLE_CLASS,
                                mxREAL);
    pData = emlrtMxGetPr(m);
    for (b_i = 0; b_i < 512; b_i++) {
      if (cpu_H_f_dirtyOnGpu) {
        cudaMemcpy(cpu_H_f, H_f, 4096UL, cudaMemcpyDeviceToHost);
        CUDACHECK(cudaGetLastError());
      }
      cpu_H_f_dirtyOnGpu = false;
      pData[b_i] = cpu_H_f[b_i];
    }
    emlrtAssign(&h_y, m);
    emlrt_marshallIn(emlrtCoerceToClassR2014b(
                         Chi_3_LLE_Kuar_ins_mex(y, b_y, c_y, d_y, e_y, f_y, g_y,
                                                h_y, &emlrtMCI),
                         (char_T *)"double"),
                     "<output of Chi_3_LLE_Kuar_ins_mex>", u);
    cudaMemcpy(*gpu_u, u, 8192UL, cudaMemcpyHostToDevice);
    CUDACHECK(cudaGetLastError());
    h_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        *gpu_u, *gpu_d);
    CUDACHECK(cudaGetLastError());
    i6 = static_cast<int32_T>(Runge->s + -1.0);
    for (int32_T i2{0}; i2 < i6; i2++) {
      b_i = static_cast<int32_T>(Runge->s - 1.0);
      for (int32_T ii{0}; ii < b_i; ii++) {
        b_dt = Runge->b[(i2 + 3 * ii) + 1];
        if (b_dt != 0.0) {
          b_dt *= dt;
          if (mode_range_dirtyOnCpu) {
            cudaMemcpy(*gpu_mode_range, mode_range, 4096UL,
                       cudaMemcpyHostToDevice);
            CUDACHECK(cudaGetLastError());
          }
          i_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U),
                                            dim3(512U, 1U, 1U)>>>(
              *gpu_d, ii, b_dt, *gpu_E_temp, *gpu_mode_range, *gpu_u);
          CUDACHECK(cudaGetLastError());
          mode_range_dirtyOnCpu = false;
          j_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U),
                                            dim3(512U, 1U, 1U)>>>(
              *gpu_u, *gpu_mode_range, *gpu_E_temp);
          CUDACHECK(cudaGetLastError());
        }
      }
      i_y = nullptr;
      m = emlrtCreateNumericArray(2, (const void *)&iv8[0], mxDOUBLE_CLASS,
                                  mxCOMPLEX);
      cudaMemcpy(E_temp, *gpu_E_temp, 8192UL, cudaMemcpyDeviceToHost);
      CUDACHECK(cudaGetLastError());
      emlrtExportNumericArrayR2013b(emlrtRootTLSGlobal, m, &E_temp[0], 8);
      emlrtAssign(&i_y, m);
      k_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
          exp_plus_omega, i2 + 1, *gpu_u);
      CUDACHECK(cudaGetLastError());
      j_y = nullptr;
      m = emlrtCreateNumericArray(2, (const void *)&iv9[0], mxDOUBLE_CLASS,
                                  mxCOMPLEX);
      cudaMemcpy(u, *gpu_u, 8192UL, cudaMemcpyDeviceToHost);
      CUDACHECK(cudaGetLastError());
      emlrtExportNumericArrayR2013b(emlrtRootTLSGlobal, m, &u[0], 8);
      emlrtAssign(&j_y, m);
      l_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
          exp_minus_omega, i2 + 1, *gpu_u);
      CUDACHECK(cudaGetLastError());
      k_y = nullptr;
      m = emlrtCreateNumericArray(2, (const void *)&iv10[0], mxDOUBLE_CLASS,
                                  mxCOMPLEX);
      cudaMemcpy(u, *gpu_u, 8192UL, cudaMemcpyDeviceToHost);
      CUDACHECK(cudaGetLastError());
      emlrtExportNumericArrayR2013b(emlrtRootTLSGlobal, m, &u[0], 8);
      emlrtAssign(&k_y, m);
      l_y = nullptr;
      m = emlrtCreateNumericArray(2, (const void *)&iv11[0], mxDOUBLE_CLASS,
                                  mxREAL);
      pData = emlrtMxGetPr(m);
      for (b_i = 0; b_i < 256; b_i++) {
        if (cpu_gam2o_dirtyOnGpu) {
          cudaMemcpy(cpu_gam2o, gam2o, 2048UL, cudaMemcpyDeviceToHost);
          CUDACHECK(cudaGetLastError());
        }
        cpu_gam2o_dirtyOnGpu = false;
        pData[b_i] = cpu_gam2o[b_i];
      }
      emlrtAssign(&l_y, m);
      m_y = nullptr;
      m = emlrtCreateNumericArray(2, (const void *)&iv12[0], mxDOUBLE_CLASS,
                                  mxREAL);
      pData = emlrtMxGetPr(m);
      for (b_i = 0; b_i < 256; b_i++) {
        if (cpu_gam2e_dirtyOnGpu) {
          cudaMemcpy(cpu_gam2e, gam2e, 2048UL, cudaMemcpyDeviceToHost);
          CUDACHECK(cudaGetLastError());
        }
        cpu_gam2e_dirtyOnGpu = false;
        pData[b_i] = cpu_gam2e[b_i];
      }
      emlrtAssign(&m_y, m);
      n_y = nullptr;
      m = emlrtCreateNumericArray(2, (const void *)&iv13[0], mxDOUBLE_CLASS,
                                  mxREAL);
      pData = emlrtMxGetPr(m);
      for (b_i = 0; b_i < 256; b_i++) {
        if (cpu_gam3o_dirtyOnGpu) {
          cudaMemcpy(cpu_gam3o, gam3o, 2048UL, cudaMemcpyDeviceToHost);
          CUDACHECK(cudaGetLastError());
        }
        cpu_gam3o_dirtyOnGpu = false;
        pData[b_i] = cpu_gam3o[b_i];
      }
      emlrtAssign(&n_y, m);
      o_y = nullptr;
      m = emlrtCreateNumericArray(2, (const void *)&iv14[0], mxDOUBLE_CLASS,
                                  mxREAL);
      pData = emlrtMxGetPr(m);
      for (b_i = 0; b_i < 256; b_i++) {
        if (cpu_gam3e_dirtyOnGpu) {
          cudaMemcpy(cpu_gam3e, gam3e, 2048UL, cudaMemcpyDeviceToHost);
          CUDACHECK(cudaGetLastError());
        }
        cpu_gam3e_dirtyOnGpu = false;
        pData[b_i] = cpu_gam3e[b_i];
      }
      emlrtAssign(&o_y, m);
      p_y = nullptr;
      m = emlrtCreateNumericArray(2, (const void *)&iv15[0], mxDOUBLE_CLASS,
                                  mxREAL);
      pData = emlrtMxGetPr(m);
      for (b_i = 0; b_i < 512; b_i++) {
        if (cpu_H_f_dirtyOnGpu) {
          cudaMemcpy(cpu_H_f, H_f, 4096UL, cudaMemcpyDeviceToHost);
          CUDACHECK(cudaGetLastError());
        }
        cpu_H_f_dirtyOnGpu = false;
        pData[b_i] = cpu_H_f[b_i];
      }
      emlrtAssign(&p_y, m);
      emlrt_marshallIn(emlrtCoerceToClassR2014b(
                           Chi_3_LLE_Kuar_ins_mex(i_y, j_y, k_y, l_y, m_y, n_y,
                                                  o_y, p_y, &b_emlrtMCI),
                           (char_T *)"double"),
                       "<output of Chi_3_LLE_Kuar_ins_mex>", u);
      cudaMemcpy(*gpu_u, u, 8192UL, cudaMemcpyHostToDevice);
      CUDACHECK(cudaGetLastError());
      m_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
          F_e, *gpu_u, i2 + 1, *gpu_E_temp, *gpu_d);
      CUDACHECK(cudaGetLastError());
    }
    b_i = static_cast<int32_T>(Runge->s);
    for (i6 = 0; i6 < b_i; i6++) {
      b_dt = Runge->c[i6];
      if (b_dt != 0.0) {
        b_dt *= dt;
        if (mode_range_dirtyOnCpu) {
          cudaMemcpy(*gpu_mode_range, mode_range, 4096UL,
                     cudaMemcpyHostToDevice);
          CUDACHECK(cudaGetLastError());
        }
        n_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U),
                                          dim3(512U, 1U, 1U)>>>(
            *gpu_d, i6, b_dt, F_e, *gpu_mode_range, *gpu_u);
        CUDACHECK(cudaGetLastError());
        mode_range_dirtyOnCpu = false;
        o_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U),
                                          dim3(512U, 1U, 1U)>>>(
            *gpu_u, *gpu_mode_range, F_e);
        CUDACHECK(cudaGetLastError());
      }
    }
    if (mode_range_dirtyOnCpu) {
      cudaMemcpy(*gpu_mode_range, mode_range, 4096UL, cudaMemcpyHostToDevice);
      CUDACHECK(cudaGetLastError());
    }
    p_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        F_e, shift_back, *gpu_mode_range, *gpu_u);
    CUDACHECK(cudaGetLastError());
    mode_range_dirtyOnCpu = false;
    q_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        *gpu_u, *gpu_mode_range, F_e);
    CUDACHECK(cudaGetLastError());
    // ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back
  }
  free(*cpu_F_e);
  cudaFree(*gpu_d);
  CUDACHECK(cudaGetLastError());
  cudaFree(*gpu_E_temp);
  CUDACHECK(cudaGetLastError());
  cudaFree(*gpu_u);
  CUDACHECK(cudaGetLastError());
  cudaFree(*gpu_mode_range);
  CUDACHECK(cudaGetLastError());
#undef CUDACHECK
}

// End of code generation (Chi23_Runge_IntegrationSteps.cu)
