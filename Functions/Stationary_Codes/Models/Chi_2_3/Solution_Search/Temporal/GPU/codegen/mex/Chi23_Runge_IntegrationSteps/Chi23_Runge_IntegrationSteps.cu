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
#include "MWCUFFTPlanManager.hpp"
#include "MWCudaDimUtility.hpp"
#include "MWErrorCodeUtils.hpp"
#include "cufft.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
static __global__ void ab_Chi23_Runge_IntegrationSteps(
    const creal_T Psio[256], const creal_T x[256], const real_T gam3o[256],
    const real_T gam2o[256], const creal_T exp_plus_omega[1536],
    const int32_T inembed, creal_T k_e[512], creal_T b_x[256]);

static void b_raiseCudaError(uint32_T errCode, const char_T *file,
                             uint32_T line, const char_T *errorName,
                             const char_T *errorString);

static __global__ void bb_Chi23_Runge_IntegrationSteps(const creal_T Psio[256],
                                                       creal_T Psie[256]);

static __global__ void cb_Chi23_Runge_IntegrationSteps(
    const creal_T Psie[256], const creal_T x[256], const real_T gam3e[256],
    const real_T gam2e[256], const creal_T exp_plus_omega[1536],
    const int32_T inembed, creal_T k_e[512]);

static void checkCudaError(cudaError_t errCode, const char_T *file,
                           uint32_T line);

static void cufftCheck(cufftResult_t errCode, const char_T *file,
                       uint32_T line);

static __global__ void
d_Chi23_Runge_IntegrationSteps_(const creal_T exp_plus_omega[1536],
                                creal_T *b_exp_plus_omega);

static __global__ void db_Chi23_Runge_IntegrationSteps(const creal_T F_e[512],
                                                       const creal_T k_e[512],
                                                       const int32_T inembed,
                                                       creal_T E_temp[512],
                                                       creal_T d[1536]);

static __global__ void e_Chi23_Runge_IntegrationSteps_(const creal_T d[1536],
                                                       creal_T b_d[1536]);

static __global__ void eb_Chi23_Runge_IntegrationSteps(
    const creal_T d[1536], const int32_T inembed, const real_T dt,
    const creal_T F_e[512], const real_T mode_range[512], creal_T E_temp[512]);

static __global__ void f_Chi23_Runge_IntegrationSteps_(const creal_T F_e[512],
                                                       creal_T E_temp[512]);

static __global__ void
fb_Chi23_Runge_IntegrationSteps(const creal_T E_temp[512],
                                const real_T mode_range[512], creal_T F_e[512]);

static __global__ void
g_Chi23_Runge_IntegrationSteps_(const creal_T F_e[512],
                                const creal_T exp_minus_omega[1536],
                                creal_T Psio[256]);

static __global__ void gb_Chi23_Runge_IntegrationSteps(
    const creal_T F_e[512], const creal_T shift_back[512],
    const real_T mode_range[512], creal_T E_temp[512]);

static __global__ void
h_Chi23_Runge_IntegrationSteps_(const creal_T F_e[512],
                                const creal_T exp_minus_omega[1536],
                                creal_T Psie[256], creal_T Psio[256]);

static __global__ void
hb_Chi23_Runge_IntegrationSteps(const creal_T E_temp[512],
                                const real_T mode_range[512], creal_T F_e[512]);

static __global__ void i_Chi23_Runge_IntegrationSteps_(creal_T Psie[256]);

static __global__ void
j_Chi23_Runge_IntegrationSteps_(const creal_T *exp_plus_omega,
                                const real_T H_f[512], creal_T k_e[512]);

static __global__ void k_Chi23_Runge_IntegrationSteps_(const creal_T Psie[256],
                                                       const creal_T Psio[256],
                                                       creal_T x[256]);

static __global__ void l_Chi23_Runge_IntegrationSteps_(const creal_T Psie[256],
                                                       const creal_T Psio[256],
                                                       creal_T x[256]);

static __global__ void m_Chi23_Runge_IntegrationSteps_(
    const creal_T Psio[256], const creal_T x[256], const real_T gam3o[256],
    const real_T gam2o[256], const creal_T exp_plus_omega[1536],
    creal_T k_e[512], creal_T b_x[256]);

static __global__ void n_Chi23_Runge_IntegrationSteps_(const creal_T Psio[256],
                                                       creal_T Psie[256]);

static __global__ void o_Chi23_Runge_IntegrationSteps_(
    const creal_T Psie[256], const creal_T x[256], const real_T gam3e[256],
    const real_T gam2e[256], const creal_T exp_plus_omega[1536],
    creal_T k_e[512]);

static __global__ void p_Chi23_Runge_IntegrationSteps_(const creal_T k_e[512],
                                                       creal_T d[1536]);

static __global__ void
q_Chi23_Runge_IntegrationSteps_(const creal_T d[1536], const int32_T inembed,
                                const real_T dt, const creal_T E_temp[512],
                                const real_T mode_range[512],
                                creal_T b_E_temp[512]);

static __global__ void
r_Chi23_Runge_IntegrationSteps_(const creal_T E_temp[512],
                                const real_T mode_range[512],
                                creal_T b_E_temp[512]);

static void raiseCudaError(uint32_T errCode, const char_T *file, uint32_T line,
                           const char_T *errorName, const char_T *errorString);

static __global__ void
s_Chi23_Runge_IntegrationSteps_(const creal_T exp_minus_omega[1536],
                                const int32_T inembed,
                                const creal_T E_temp[512], creal_T Psio[256]);

static __global__ void t_Chi23_Runge_IntegrationSteps_(
    const creal_T exp_minus_omega[1536], const int32_T inembed,
    const creal_T E_temp[512], creal_T Psie[256], creal_T Psio[256]);

static __global__ void u_Chi23_Runge_IntegrationSteps_(creal_T Psie[256]);

static __global__ void
v_Chi23_Runge_IntegrationSteps_(const creal_T exp_plus_omega[1536],
                                const int32_T i2, creal_T *b_exp_plus_omega);

static __global__ void
w_Chi23_Runge_IntegrationSteps_(const creal_T *exp_plus_omega,
                                const real_T H_f[512], creal_T k_e[512]);

static __global__ void x_Chi23_Runge_IntegrationSteps_(const creal_T Psie[256],
                                                       const creal_T Psio[256],
                                                       creal_T x[256]);

static __global__ void y_Chi23_Runge_IntegrationSteps_(const creal_T Psie[256],
                                                       const creal_T Psio[256],
                                                       creal_T x[256]);

// Function Definitions
static __global__
    __launch_bounds__(256, 1) void ab_Chi23_Runge_IntegrationSteps(
        const creal_T Psio[256], const creal_T x[256], const real_T gam3o[256],
        const real_T gam2o[256], const creal_T exp_plus_omega[1536],
        const int32_T inembed, creal_T k_e[512], creal_T b_x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T dc1_im;
    real_T dc1_re;
    real_T gam2e_im;
    //
    dc1_re = 0.0 * exp_plus_omega[inembed + 3 * k].re -
             exp_plus_omega[inembed + 3 * k].im;
    dc1_im = 0.0 * exp_plus_omega[inembed + 3 * k].im +
             exp_plus_omega[inembed + 3 * k].re;
    d = gam2o[k];
    d1 = gam3o[k];
    gam2e_im = d * b_x[k].re + d1 * x[k].re;
    d = d * b_x[k].im + d1 * x[k].im;
    k_e[k].re = dc1_re * gam2e_im - dc1_im * d;
    k_e[k].im = dc1_re * d + dc1_im * gam2e_im;
    d = Psio[k].re;
    d1 = Psio[k].im;
    b_x[k].re = d * d - d1 * d1;
    b_x[k].im = d * d1 + d1 * d;
  }
}

static void b_raiseCudaError(uint32_T errCode, const char_T *file,
                             uint32_T line, const char_T *errorName,
                             const char_T *errorString)
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

static __global__ __launch_bounds__(
    256, 1) void bb_Chi23_Runge_IntegrationSteps(const creal_T Psio[256],
                                                 creal_T Psie[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T dc1_re;
    real_T gam2e_re;
    d = hypot(Psio[k].re, Psio[k].im);
    d1 = d * d;
    gam2e_re = Psie[k].re;
    dc1_re = Psie[k].im;
    d = hypot(gam2e_re, dc1_re);
    gam2e_re *= 2.0 * d1 + d * d;
    Psie[k].re = gam2e_re;
    dc1_re *= 2.0 * d1 + d * d;
    Psie[k].im = dc1_re;
  }
}

static __global__
    __launch_bounds__(256, 1) void cb_Chi23_Runge_IntegrationSteps(
        const creal_T Psie[256], const creal_T x[256], const real_T gam3e[256],
        const real_T gam2e[256], const creal_T exp_plus_omega[1536],
        const int32_T inembed, creal_T k_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T dc1_im;
    real_T dc1_re;
    real_T gam2e_re;
    dc1_re = 0.0 * exp_plus_omega[inembed + 3 * (k + 256)].re -
             exp_plus_omega[inembed + 3 * (k + 256)].im;
    dc1_im = 0.0 * exp_plus_omega[inembed + 3 * (k + 256)].im +
             exp_plus_omega[inembed + 3 * (k + 256)].re;
    d = gam2e[k];
    d1 = gam3e[k];
    gam2e_re = d * x[k].re + d1 * Psie[k].re;
    d = d * x[k].im + d1 * Psie[k].im;
    k_e[k + 256].re = dc1_re * gam2e_re - dc1_im * d;
    k_e[k + 256].im = dc1_re * d + dc1_im * gam2e_re;
  }
}

static void checkCudaError(cudaError_t errCode, const char_T *file,
                           uint32_T line)
{
  if (errCode != cudaSuccess) {
    b_raiseCudaError(errCode, file, line, cudaGetErrorName(errCode),
                     cudaGetErrorString(errCode));
  }
}

static void cufftCheck(cufftResult_t errCode, const char_T *file, uint32_T line)
{
  const char *errName;
  const char *errString;
  if (errCode != CUFFT_SUCCESS) {
    cufftGetErrorName(static_cast<int32_T>(errCode), &errName);
    cufftGetErrorString(static_cast<int32_T>(errCode), &errString);
    raiseCudaError(errCode, file, line, errName, errString);
  }
}

static __global__ __launch_bounds__(32, 1) void d_Chi23_Runge_IntegrationSteps_(
    const creal_T exp_plus_omega[1536], creal_T *b_exp_plus_omega)
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *b_exp_plus_omega = exp_plus_omega[0];
  }
}

static __global__
    __launch_bounds__(512, 1) void db_Chi23_Runge_IntegrationSteps(
        const creal_T F_e[512], const creal_T k_e[512], const int32_T inembed,
        creal_T E_temp[512], creal_T d[1536])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    d[inembed + 3 * k] = k_e[k];
    E_temp[k] = F_e[k];
  }
}

static __global__ __launch_bounds__(
    512, 1) void e_Chi23_Runge_IntegrationSteps_(const creal_T d[1536],
                                                 creal_T b_d[1536])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 1536) {
    b_d[k] = d[k];
  }
}

static __global__
    __launch_bounds__(512, 1) void eb_Chi23_Runge_IntegrationSteps(
        const creal_T d[1536], const int32_T inembed, const real_T dt,
        const creal_T F_e[512], const real_T mode_range[512],
        creal_T E_temp[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    real_T b_d;
    b_d = mode_range[k];
    E_temp[k].re = F_e[static_cast<int32_T>(b_d) - 1].re +
                   dt * d[inembed + 3 * (static_cast<int32_T>(b_d) - 1)].re;
    E_temp[k].im = F_e[static_cast<int32_T>(b_d) - 1].im +
                   dt * d[inembed + 3 * (static_cast<int32_T>(b_d) - 1)].im;
  }
}

static __global__ __launch_bounds__(
    512, 1) void f_Chi23_Runge_IntegrationSteps_(const creal_T F_e[512],
                                                 creal_T E_temp[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    //     coder.gpu.kernelfun;
    //    coder.gpu.kernel;
    E_temp[k] = F_e[k];
  }
}

static __global__ __launch_bounds__(
    512, 1) void fb_Chi23_Runge_IntegrationSteps(const creal_T E_temp[512],
                                                 const real_T mode_range[512],
                                                 creal_T F_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    F_e[static_cast<int32_T>(mode_range[k]) - 1] = E_temp[k];
  }
}

static __global__
    __launch_bounds__(256, 1) void g_Chi23_Runge_IntegrationSteps_(
        const creal_T F_e[512], const creal_T exp_minus_omega[1536],
        creal_T Psio[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    d = exp_minus_omega[3 * k].re;
    d1 = exp_minus_omega[3 * k].im;
    Psio[k].re = F_e[k].re * d - F_e[k].im * d1;
    Psio[k].im = F_e[k].re * d1 + F_e[k].im * d;
  }
}

static __global__ __launch_bounds__(
    512, 1) void gb_Chi23_Runge_IntegrationSteps(const creal_T F_e[512],
                                                 const creal_T shift_back[512],
                                                 const real_T mode_range[512],
                                                 creal_T E_temp[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    real_T d;
    d = mode_range[k];
    E_temp[k].re = shift_back[static_cast<int32_T>(d) - 1].re *
                       F_e[static_cast<int32_T>(d) - 1].re -
                   shift_back[static_cast<int32_T>(d) - 1].im *
                       F_e[static_cast<int32_T>(d) - 1].im;
    E_temp[k].im = shift_back[static_cast<int32_T>(d) - 1].re *
                       F_e[static_cast<int32_T>(d) - 1].im +
                   shift_back[static_cast<int32_T>(d) - 1].im *
                       F_e[static_cast<int32_T>(d) - 1].re;
  }
}

static __global__
    __launch_bounds__(256, 1) void h_Chi23_Runge_IntegrationSteps_(
        const creal_T F_e[512], const creal_T exp_minus_omega[1536],
        creal_T Psie[256], creal_T Psio[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T dc1_re;
    real_T gam2e_im;
    real_T gam2e_re;
    gam2e_im = Psio[k].re;
    dc1_re = Psio[k].im;
    if (dc1_re == 0.0) {
      gam2e_re = gam2e_im / 256.0;
      gam2e_im = 0.0;
    } else if (gam2e_im == 0.0) {
      gam2e_re = 0.0;
      gam2e_im = dc1_re / 256.0;
    } else {
      gam2e_re = gam2e_im / 256.0;
      gam2e_im = dc1_re / 256.0;
    }
    Psio[k].re = gam2e_re;
    Psio[k].im = gam2e_im;
    gam2e_im = exp_minus_omega[3 * (k + 256)].re;
    dc1_re = exp_minus_omega[3 * (k + 256)].im;
    Psie[k].re = F_e[k + 256].re * gam2e_im - F_e[k + 256].im * dc1_re;
    Psie[k].im = F_e[k + 256].re * dc1_re + F_e[k + 256].im * gam2e_im;
  }
}

static __global__ __launch_bounds__(
    512, 1) void hb_Chi23_Runge_IntegrationSteps(const creal_T E_temp[512],
                                                 const real_T mode_range[512],
                                                 creal_T F_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    F_e[static_cast<int32_T>(mode_range[k]) - 1] = E_temp[k];
  }
}

static __global__
    __launch_bounds__(256,
                      1) void i_Chi23_Runge_IntegrationSteps_(creal_T Psie[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T dc1_re;
    real_T gam2e_im;
    real_T gam2e_re;
    gam2e_im = Psie[k].re;
    dc1_re = Psie[k].im;
    if (dc1_re == 0.0) {
      gam2e_re = gam2e_im / 256.0;
      gam2e_im = 0.0;
    } else if (gam2e_im == 0.0) {
      gam2e_re = 0.0;
      gam2e_im = dc1_re / 256.0;
    } else {
      gam2e_re = gam2e_im / 256.0;
      gam2e_im = dc1_re / 256.0;
    }
    Psie[k].re = gam2e_re;
    Psie[k].im = gam2e_im;
  }
}

static __global__
    __launch_bounds__(512, 1) void j_Chi23_Runge_IntegrationSteps_(
        const creal_T *exp_plus_omega, const real_T H_f[512], creal_T k_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    real_T d;
    d = H_f[k];
    k_e[k].re = d * exp_plus_omega->re;
    k_e[k].im = d * exp_plus_omega->im;
  }
}

static __global__
    __launch_bounds__(256, 1) void k_Chi23_Runge_IntegrationSteps_(
        const creal_T Psie[256], const creal_T Psio[256], creal_T x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T dc1_re;
    real_T gam2e_im;
    dc1_re = Psio[k].re;
    gam2e_im = -Psio[k].im;
    d = Psie[k].re;
    d1 = Psie[k].im;
    x[k].re = dc1_re * d - gam2e_im * d1;
    x[k].im = dc1_re * d1 + gam2e_im * d;
  }
}

static __global__
    __launch_bounds__(256, 1) void l_Chi23_Runge_IntegrationSteps_(
        const creal_T Psie[256], const creal_T Psio[256], creal_T x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T dc1_re;
    real_T gam2e_re;
    d = Psio[k].re;
    d1 = Psio[k].im;
    gam2e_re = hypot(d, d1);
    dc1_re = gam2e_re * gam2e_re;
    gam2e_re = hypot(Psie[k].re, Psie[k].im);
    x[k].re = (dc1_re + 2.0 * (gam2e_re * gam2e_re)) * d;
    x[k].im = (dc1_re + 2.0 * (gam2e_re * gam2e_re)) * d1;
  }
}

static __global__
    __launch_bounds__(256, 1) void m_Chi23_Runge_IntegrationSteps_(
        const creal_T Psio[256], const creal_T x[256], const real_T gam3o[256],
        const real_T gam2o[256], const creal_T exp_plus_omega[1536],
        creal_T k_e[512], creal_T b_x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T dc1_im;
    real_T dc1_re;
    real_T gam2e_im;
    //
    d = exp_plus_omega[3 * k].re;
    d1 = exp_plus_omega[3 * k].im;
    dc1_re = 0.0 * d - d1;
    dc1_im = 0.0 * d1 + d;
    d = gam2o[k];
    d1 = gam3o[k];
    gam2e_im = d * b_x[k].re + d1 * x[k].re;
    d = d * b_x[k].im + d1 * x[k].im;
    k_e[k].re = dc1_re * gam2e_im - dc1_im * d;
    k_e[k].im = dc1_re * d + dc1_im * gam2e_im;
    d = Psio[k].re;
    d1 = Psio[k].im;
    b_x[k].re = d * d - d1 * d1;
    b_x[k].im = d * d1 + d1 * d;
  }
}

static __global__ __launch_bounds__(
    256, 1) void n_Chi23_Runge_IntegrationSteps_(const creal_T Psio[256],
                                                 creal_T Psie[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T dc1_re;
    real_T gam2e_re;
    d = hypot(Psio[k].re, Psio[k].im);
    d1 = d * d;
    gam2e_re = Psie[k].re;
    dc1_re = Psie[k].im;
    d = hypot(gam2e_re, dc1_re);
    gam2e_re *= 2.0 * d1 + d * d;
    Psie[k].re = gam2e_re;
    dc1_re *= 2.0 * d1 + d * d;
    Psie[k].im = dc1_re;
  }
}

static __global__
    __launch_bounds__(256, 1) void o_Chi23_Runge_IntegrationSteps_(
        const creal_T Psie[256], const creal_T x[256], const real_T gam3e[256],
        const real_T gam2e[256], const creal_T exp_plus_omega[1536],
        creal_T k_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T dc1_im;
    real_T dc1_re;
    real_T gam2e_re;
    d = exp_plus_omega[3 * (k + 256)].re;
    d1 = exp_plus_omega[3 * (k + 256)].im;
    dc1_re = 0.0 * d - d1;
    dc1_im = 0.0 * d1 + d;
    d = gam2e[k];
    d1 = gam3e[k];
    gam2e_re = d * x[k].re + d1 * Psie[k].re;
    d = d * x[k].im + d1 * Psie[k].im;
    k_e[k + 256].re = dc1_re * gam2e_re - dc1_im * d;
    k_e[k + 256].im = dc1_re * d + dc1_im * gam2e_re;
  }
}

static __global__ __launch_bounds__(
    512, 1) void p_Chi23_Runge_IntegrationSteps_(const creal_T k_e[512],
                                                 creal_T d[1536])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    //
    //     k_e(1)      = k_e(1) + ;
    d[3 * k] = k_e[k];
  }
}

static __global__
    __launch_bounds__(512, 1) void q_Chi23_Runge_IntegrationSteps_(
        const creal_T d[1536], const int32_T inembed, const real_T dt,
        const creal_T E_temp[512], const real_T mode_range[512],
        creal_T b_E_temp[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    real_T b_d;
    b_d = mode_range[k];
    b_E_temp[k].re = E_temp[static_cast<int32_T>(b_d) - 1].re +
                     dt * d[inembed + 3 * (static_cast<int32_T>(b_d) - 1)].re;
    b_E_temp[k].im = E_temp[static_cast<int32_T>(b_d) - 1].im +
                     dt * d[inembed + 3 * (static_cast<int32_T>(b_d) - 1)].im;
  }
}

static __global__ __launch_bounds__(
    512, 1) void r_Chi23_Runge_IntegrationSteps_(const creal_T E_temp[512],
                                                 const real_T mode_range[512],
                                                 creal_T b_E_temp[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    b_E_temp[static_cast<int32_T>(mode_range[k]) - 1] = E_temp[k];
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
  pn = (char_T *)std::calloc(len + 1U, 1U);
  fn = (char_T *)std::calloc(len + 1U, 1U);
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

static __global__
    __launch_bounds__(256, 1) void s_Chi23_Runge_IntegrationSteps_(
        const creal_T exp_minus_omega[1536], const int32_T inembed,
        const creal_T E_temp[512], creal_T Psio[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    d = E_temp[k].re;
    d1 = E_temp[k].im;
    Psio[k].re = d * exp_minus_omega[inembed + 3 * k].re -
                 d1 * exp_minus_omega[inembed + 3 * k].im;
    Psio[k].im = d * exp_minus_omega[inembed + 3 * k].im +
                 d1 * exp_minus_omega[inembed + 3 * k].re;
  }
}

static __global__
    __launch_bounds__(256, 1) void t_Chi23_Runge_IntegrationSteps_(
        const creal_T exp_minus_omega[1536], const int32_T inembed,
        const creal_T E_temp[512], creal_T Psie[256], creal_T Psio[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T dc1_re;
    real_T gam2e_im;
    real_T gam2e_re;
    gam2e_im = Psio[k].re;
    dc1_re = Psio[k].im;
    if (dc1_re == 0.0) {
      gam2e_re = gam2e_im / 256.0;
      gam2e_im = 0.0;
    } else if (gam2e_im == 0.0) {
      gam2e_re = 0.0;
      gam2e_im = dc1_re / 256.0;
    } else {
      gam2e_re = gam2e_im / 256.0;
      gam2e_im = dc1_re / 256.0;
    }
    Psio[k].re = gam2e_re;
    Psio[k].im = gam2e_im;
    gam2e_im = E_temp[k + 256].re;
    dc1_re = E_temp[k + 256].im;
    Psie[k].re = gam2e_im * exp_minus_omega[inembed + 3 * (k + 256)].re -
                 dc1_re * exp_minus_omega[inembed + 3 * (k + 256)].im;
    Psie[k].im = gam2e_im * exp_minus_omega[inembed + 3 * (k + 256)].im +
                 dc1_re * exp_minus_omega[inembed + 3 * (k + 256)].re;
  }
}

static __global__
    __launch_bounds__(256,
                      1) void u_Chi23_Runge_IntegrationSteps_(creal_T Psie[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T dc1_re;
    real_T gam2e_im;
    real_T gam2e_re;
    gam2e_im = Psie[k].re;
    dc1_re = Psie[k].im;
    if (dc1_re == 0.0) {
      gam2e_re = gam2e_im / 256.0;
      gam2e_im = 0.0;
    } else if (gam2e_im == 0.0) {
      gam2e_re = 0.0;
      gam2e_im = dc1_re / 256.0;
    } else {
      gam2e_re = gam2e_im / 256.0;
      gam2e_im = dc1_re / 256.0;
    }
    Psie[k].re = gam2e_re;
    Psie[k].im = gam2e_im;
  }
}

static __global__ __launch_bounds__(32, 1) void v_Chi23_Runge_IntegrationSteps_(
    const creal_T exp_plus_omega[1536], const int32_T i2,
    creal_T *b_exp_plus_omega)
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *b_exp_plus_omega = exp_plus_omega[i2 + 1];
  }
}

static __global__
    __launch_bounds__(512, 1) void w_Chi23_Runge_IntegrationSteps_(
        const creal_T *exp_plus_omega, const real_T H_f[512], creal_T k_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    real_T d;
    d = H_f[k];
    k_e[k].re = d * exp_plus_omega->re;
    k_e[k].im = d * exp_plus_omega->im;
  }
}

static __global__
    __launch_bounds__(256, 1) void x_Chi23_Runge_IntegrationSteps_(
        const creal_T Psie[256], const creal_T Psio[256], creal_T x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T dc1_re;
    real_T gam2e_im;
    dc1_re = Psio[k].re;
    gam2e_im = -Psio[k].im;
    d = Psie[k].re;
    d1 = Psie[k].im;
    x[k].re = dc1_re * d - gam2e_im * d1;
    x[k].im = dc1_re * d1 + gam2e_im * d;
  }
}

static __global__
    __launch_bounds__(256, 1) void y_Chi23_Runge_IntegrationSteps_(
        const creal_T Psie[256], const creal_T Psio[256], creal_T x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T dc1_re;
    real_T gam2e_re;
    d = Psio[k].re;
    d1 = Psio[k].im;
    gam2e_re = hypot(d, d1);
    dc1_re = gam2e_re * gam2e_re;
    gam2e_re = hypot(Psie[k].re, Psie[k].im);
    x[k].re = (dc1_re + 2.0 * (gam2e_re * gam2e_re)) * d;
    x[k].im = (dc1_re + 2.0 * (gam2e_re * gam2e_re)) * d1;
  }
}

void Chi23_Runge_IntegrationSteps(
    real_T nt, real_T dt, const creal_T d[1536], creal_T F_e[512],
    const creal_T exp_plus_omega[1536], const creal_T exp_minus_omega[1536],
    const struct0_T *Runge, real_T t, const creal_T shift_back[512],
    const real_T gam2o[256], const real_T gam2e[256], const real_T gam3o[256],
    const real_T gam3e[256], const real_T H_f[512],
    const real_T mode_range[512])
{
  creal_T(*gpu_d)[1536];
  creal_T(*b_gpu_E_temp)[512];
  creal_T(*gpu_E_temp)[512];
  creal_T(*gpu_k_e)[512];
  creal_T(*b_gpu_x)[256];
  creal_T(*gpu_Psie)[256];
  creal_T(*gpu_Psio)[256];
  creal_T(*gpu_x)[256];
  creal_T *b_gpu_exp_plus_omega;
  creal_T *gpu_exp_plus_omega;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  (void)t;
#define CUDACHECK(errCall) checkCudaError(errCall, __FILE__, __LINE__)
  checkCudaError(cudaGetLastError(), __FILE__, __LINE__);
  cudaMalloc(&b_gpu_exp_plus_omega, 16ULL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&b_gpu_E_temp, 8192ULL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&b_gpu_x, 4096ULL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&gpu_x, 4096ULL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&gpu_k_e, 8192ULL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&gpu_Psie, 4096ULL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&gpu_Psio, 4096ULL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&gpu_E_temp, 8192ULL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&gpu_d, 24576ULL);
  CUDACHECK(cudaGetLastError());
  cudaMalloc(&gpu_exp_plus_omega, 16ULL);
  CUDACHECK(cudaGetLastError());
  i = static_cast<int32_T>(nt);
  if (0 <= static_cast<int32_T>(nt) - 1) {
    d_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
        exp_plus_omega, gpu_exp_plus_omega);
    CUDACHECK(cudaGetLastError());
    i1 = static_cast<int32_T>(Runge->s + -1.0);
    i2 = static_cast<int32_T>(Runge->s);
  }
  for (int32_T ni{0}; ni < i; ni++) {
    cufftHandle b_fftPlanHandle;
    cufftHandle c_fftPlanHandle;
    cufftHandle d_fftPlanHandle;
    cufftHandle e_fftPlanHandle;
    cufftHandle f_fftPlanHandle;
    cufftHandle fftPlanHandle;
    real_T b_dt;
    int32_T inembed;
    e_Chi23_Runge_IntegrationSteps_<<<dim3(3U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        d, *gpu_d);
    CUDACHECK(cudaGetLastError());
    //     coder.gpu.kernelfun;
    //    coder.gpu.kernel;
    f_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        F_e, *gpu_E_temp);
    CUDACHECK(cudaGetLastError());
    g_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        F_e, exp_minus_omega, *gpu_Psio);
    CUDACHECK(cudaGetLastError());
    inembed = 256;
    fftPlanHandle = acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
    cufftCheck(
        cufftExecZ2Z(fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psio)[0],
                     (cufftDoubleComplex *)&(*gpu_Psio)[0], CUFFT_INVERSE),
        __FILE__, __LINE__);
    h_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        F_e, exp_minus_omega, *gpu_Psie, *gpu_Psio);
    CUDACHECK(cudaGetLastError());
    inembed = 256;
    b_fftPlanHandle =
        acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
    cufftCheck(
        cufftExecZ2Z(b_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psie)[0],
                     (cufftDoubleComplex *)&(*gpu_Psie)[0], CUFFT_INVERSE),
        __FILE__, __LINE__);
    i_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psie);
    CUDACHECK(cudaGetLastError());
    j_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        gpu_exp_plus_omega, H_f, *gpu_k_e);
    CUDACHECK(cudaGetLastError());
    k_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psie, *gpu_Psio, *gpu_x);
    CUDACHECK(cudaGetLastError());
    inembed = 256;
    c_fftPlanHandle =
        acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
    cufftCheck(cufftExecZ2Z(c_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_x)[0],
                            (cufftDoubleComplex *)&(*gpu_x)[0], CUFFT_FORWARD),
               __FILE__, __LINE__);
    l_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psie, *gpu_Psio, *b_gpu_x);
    CUDACHECK(cudaGetLastError());
    inembed = 256;
    d_fftPlanHandle =
        acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
    cufftCheck(
        cufftExecZ2Z(d_fftPlanHandle, (cufftDoubleComplex *)&(*b_gpu_x)[0],
                     (cufftDoubleComplex *)&(*b_gpu_x)[0], CUFFT_FORWARD),
        __FILE__, __LINE__);
    //
    m_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psio, *b_gpu_x, gam3o, gam2o, exp_plus_omega, *gpu_k_e, *gpu_x);
    CUDACHECK(cudaGetLastError());
    inembed = 256;
    e_fftPlanHandle =
        acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
    cufftCheck(cufftExecZ2Z(e_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_x)[0],
                            (cufftDoubleComplex *)&(*gpu_x)[0], CUFFT_FORWARD),
               __FILE__, __LINE__);
    n_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psio, *gpu_Psie);
    CUDACHECK(cudaGetLastError());
    inembed = 256;
    f_fftPlanHandle =
        acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
    cufftCheck(
        cufftExecZ2Z(f_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psie)[0],
                     (cufftDoubleComplex *)&(*gpu_Psie)[0], CUFFT_FORWARD),
        __FILE__, __LINE__);
    o_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psie, *gpu_x, gam3e, gam2e, exp_plus_omega, *gpu_k_e);
    CUDACHECK(cudaGetLastError());
    //
    //     k_e(1)      = k_e(1) + ;
    p_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        *gpu_k_e, *gpu_d);
    CUDACHECK(cudaGetLastError());
    if (0 <= i1 - 1) {
      i3 = static_cast<int32_T>(Runge->s - 1.0);
    }
    for (int32_T b_i2{0}; b_i2 < i1; b_i2++) {
      for (inembed = 0; inembed < i3; inembed++) {
        b_dt = Runge->b[(b_i2 + 3 * inembed) + 1];
        if (b_dt != 0.0) {
          b_dt *= dt;
          q_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U),
                                            dim3(512U, 1U, 1U)>>>(
              *gpu_d, inembed, b_dt, *gpu_E_temp, mode_range, *b_gpu_E_temp);
          CUDACHECK(cudaGetLastError());
          r_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U),
                                            dim3(512U, 1U, 1U)>>>(
              *b_gpu_E_temp, mode_range, *gpu_E_temp);
          CUDACHECK(cudaGetLastError());
        }
      }
      cufftHandle g_fftPlanHandle;
      cufftHandle h_fftPlanHandle;
      cufftHandle i_fftPlanHandle;
      cufftHandle j_fftPlanHandle;
      cufftHandle k_fftPlanHandle;
      cufftHandle l_fftPlanHandle;
      s_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          exp_minus_omega, b_i2 + 1, *gpu_E_temp, *gpu_Psio);
      CUDACHECK(cudaGetLastError());
      inembed = 256;
      g_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
      cufftCheck(
          cufftExecZ2Z(g_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psio)[0],
                       (cufftDoubleComplex *)&(*gpu_Psio)[0], CUFFT_INVERSE),
          __FILE__, __LINE__);
      t_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          exp_minus_omega, b_i2 + 1, *gpu_E_temp, *gpu_Psie, *gpu_Psio);
      CUDACHECK(cudaGetLastError());
      inembed = 256;
      h_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
      cufftCheck(
          cufftExecZ2Z(h_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psie)[0],
                       (cufftDoubleComplex *)&(*gpu_Psie)[0], CUFFT_INVERSE),
          __FILE__, __LINE__);
      u_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psie);
      CUDACHECK(cudaGetLastError());
      v_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
          exp_plus_omega, b_i2, b_gpu_exp_plus_omega);
      CUDACHECK(cudaGetLastError());
      w_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
          b_gpu_exp_plus_omega, H_f, *gpu_k_e);
      CUDACHECK(cudaGetLastError());
      x_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psie, *gpu_Psio, *gpu_x);
      CUDACHECK(cudaGetLastError());
      inembed = 256;
      i_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
      cufftCheck(
          cufftExecZ2Z(i_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_x)[0],
                       (cufftDoubleComplex *)&(*gpu_x)[0], CUFFT_FORWARD),
          __FILE__, __LINE__);
      y_Chi23_Runge_IntegrationSteps_<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psie, *gpu_Psio, *b_gpu_x);
      CUDACHECK(cudaGetLastError());
      inembed = 256;
      j_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
      cufftCheck(
          cufftExecZ2Z(j_fftPlanHandle, (cufftDoubleComplex *)&(*b_gpu_x)[0],
                       (cufftDoubleComplex *)&(*b_gpu_x)[0], CUFFT_FORWARD),
          __FILE__, __LINE__);
      //
      ab_Chi23_Runge_IntegrationSteps<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psio, *b_gpu_x, gam3o, gam2o, exp_plus_omega, b_i2 + 1, *gpu_k_e,
          *gpu_x);
      CUDACHECK(cudaGetLastError());
      inembed = 256;
      k_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
      cufftCheck(
          cufftExecZ2Z(k_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_x)[0],
                       (cufftDoubleComplex *)&(*gpu_x)[0], CUFFT_FORWARD),
          __FILE__, __LINE__);
      bb_Chi23_Runge_IntegrationSteps<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psio, *gpu_Psie);
      CUDACHECK(cudaGetLastError());
      inembed = 256;
      l_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
      cufftCheck(
          cufftExecZ2Z(l_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psie)[0],
                       (cufftDoubleComplex *)&(*gpu_Psie)[0], CUFFT_FORWARD),
          __FILE__, __LINE__);
      cb_Chi23_Runge_IntegrationSteps<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psie, *gpu_x, gam3e, gam2e, exp_plus_omega, b_i2 + 1, *gpu_k_e);
      CUDACHECK(cudaGetLastError());
      //
      //     k_e(1)      = k_e(1) + ;
      db_Chi23_Runge_IntegrationSteps<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
          F_e, *gpu_k_e, b_i2 + 1, *gpu_E_temp, *gpu_d);
      CUDACHECK(cudaGetLastError());
    }
    for (inembed = 0; inembed < i2; inembed++) {
      b_dt = Runge->c[inembed];
      if (b_dt != 0.0) {
        b_dt *= dt;
        eb_Chi23_Runge_IntegrationSteps<<<dim3(1U, 1U, 1U),
                                          dim3(512U, 1U, 1U)>>>(
            *gpu_d, inembed, b_dt, F_e, mode_range, *b_gpu_E_temp);
        CUDACHECK(cudaGetLastError());
        fb_Chi23_Runge_IntegrationSteps<<<dim3(1U, 1U, 1U),
                                          dim3(512U, 1U, 1U)>>>(
            *b_gpu_E_temp, mode_range, F_e);
        CUDACHECK(cudaGetLastError());
      }
    }
    gb_Chi23_Runge_IntegrationSteps<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        F_e, shift_back, mode_range, *b_gpu_E_temp);
    CUDACHECK(cudaGetLastError());
    hb_Chi23_Runge_IntegrationSteps<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        *b_gpu_E_temp, mode_range, F_e);
    CUDACHECK(cudaGetLastError());
    // ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back
  }
  cudaFree(gpu_exp_plus_omega);
  CUDACHECK(cudaGetLastError());
  cudaFree(*gpu_d);
  CUDACHECK(cudaGetLastError());
  cudaFree(*gpu_E_temp);
  CUDACHECK(cudaGetLastError());
  cudaFree(*gpu_Psio);
  CUDACHECK(cudaGetLastError());
  cudaFree(*gpu_Psie);
  CUDACHECK(cudaGetLastError());
  cudaFree(*gpu_k_e);
  CUDACHECK(cudaGetLastError());
  cudaFree(*gpu_x);
  CUDACHECK(cudaGetLastError());
  cudaFree(*b_gpu_x);
  CUDACHECK(cudaGetLastError());
  cudaFree(*b_gpu_E_temp);
  CUDACHECK(cudaGetLastError());
  cudaFree(b_gpu_exp_plus_omega);
  CUDACHECK(cudaGetLastError());
#undef CUDACHECK
}

// End of code generation (Chi23_Runge_IntegrationSteps.cu)
