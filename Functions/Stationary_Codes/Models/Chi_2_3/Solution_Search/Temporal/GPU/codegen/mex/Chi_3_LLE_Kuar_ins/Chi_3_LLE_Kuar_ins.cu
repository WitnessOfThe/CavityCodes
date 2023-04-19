//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi_3_LLE_Kuar_ins.cu
//
// Code generation for function 'Chi_3_LLE_Kuar_ins'
//

// Include files
#include "Chi_3_LLE_Kuar_ins.h"
#include "rt_nonfinite.h"
#include "MWCUFFTPlanManager.hpp"
#include "MWCudaDimUtility.hpp"
#include "cufft.h"

// Function Declarations
static __global__ void Chi_3_LLE_Kuar_ins_kernel1(const creal_T Fac_minus[512],
                                                  const creal_T F_Psi[512],
                                                  creal_T Psio[256]);

static __global__ void Chi_3_LLE_Kuar_ins_kernel2(const creal_T Fac_minus[512],
                                                  const creal_T F_Psi[512],
                                                  creal_T Psie[256],
                                                  creal_T Psio[256]);

static __global__ void Chi_3_LLE_Kuar_ins_kernel3(creal_T Psie[256]);

static __global__ void Chi_3_LLE_Kuar_ins_kernel4(const creal_T Psie[256],
                                                  const creal_T Psio[256],
                                                  creal_T x[256]);

static __global__ void Chi_3_LLE_Kuar_ins_kernel5(const creal_T Psie[256],
                                                  const creal_T Psio[256],
                                                  creal_T x[256]);

static __global__ void
Chi_3_LLE_Kuar_ins_kernel6(const creal_T Psio[256], const creal_T x[256],
                           const real_T gam3o[256], const real_T gam2o[256],
                           const creal_T Fac_plus[512], creal_T k_e[512],
                           creal_T b_x[256]);

static __global__ void Chi_3_LLE_Kuar_ins_kernel7(const creal_T Psio[256],
                                                  creal_T Psie[256]);

static __global__ void
Chi_3_LLE_Kuar_ins_kernel8(const creal_T Psie[256], const creal_T x[256],
                           const real_T gam3e[256], const real_T gam2e[256],
                           const creal_T Fac_plus[512], creal_T k_e[512]);

// Function Definitions
static __global__ __launch_bounds__(256, 1) void Chi_3_LLE_Kuar_ins_kernel1(
    const creal_T Fac_minus[512], const creal_T F_Psi[512], creal_T Psio[256])
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
    d = F_Psi[k].re;
    d1 = F_Psi[k].im;
    gam2e_re = Fac_minus[k].re;
    dc1_re = Fac_minus[k].im;
    Psio[k].re = d * gam2e_re - d1 * dc1_re;
    Psio[k].im = d * dc1_re + d1 * gam2e_re;
  }
}

static __global__ __launch_bounds__(256, 1) void Chi_3_LLE_Kuar_ins_kernel2(
    const creal_T Fac_minus[512], const creal_T F_Psi[512], creal_T Psie[256],
    creal_T Psio[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d1;
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
    gam2e_im = F_Psi[k + 256].re;
    d1 = F_Psi[k + 256].im;
    gam2e_re = Fac_minus[k + 256].re;
    dc1_re = Fac_minus[k + 256].im;
    Psie[k].re = gam2e_im * gam2e_re - d1 * dc1_re;
    Psie[k].im = gam2e_im * dc1_re + d1 * gam2e_re;
  }
}

static __global__
    __launch_bounds__(256, 1) void Chi_3_LLE_Kuar_ins_kernel3(creal_T Psie[256])
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

static __global__ __launch_bounds__(256, 1) void Chi_3_LLE_Kuar_ins_kernel4(
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

static __global__ __launch_bounds__(256, 1) void Chi_3_LLE_Kuar_ins_kernel5(
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

static __global__ __launch_bounds__(256, 1) void Chi_3_LLE_Kuar_ins_kernel6(
    const creal_T Psio[256], const creal_T x[256], const real_T gam3o[256],
    const real_T gam2o[256], const creal_T Fac_plus[512], creal_T k_e[512],
    creal_T b_x[256])
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
    d = Fac_plus[k].re;
    d1 = Fac_plus[k].im;
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

static __global__ __launch_bounds__(256, 1) void Chi_3_LLE_Kuar_ins_kernel7(
    const creal_T Psio[256], creal_T Psie[256])
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

static __global__ __launch_bounds__(256, 1) void Chi_3_LLE_Kuar_ins_kernel8(
    const creal_T Psie[256], const creal_T x[256], const real_T gam3e[256],
    const real_T gam2e[256], const creal_T Fac_plus[512], creal_T k_e[512])
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
    d = Fac_plus[k + 256].re;
    d1 = Fac_plus[k + 256].im;
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

void Chi_3_LLE_Kuar_ins(const creal_T F_Psi[512], const creal_T Fac_plus[512],
                        const creal_T Fac_minus[512], const real_T gam2o[256],
                        const real_T gam2e[256], const real_T gam3o[256],
                        const real_T gam3e[256], const real_T[512],
                        creal_T k_e[512])
{
  cufftHandle b_fftPlanHandle;
  cufftHandle c_fftPlanHandle;
  cufftHandle d_fftPlanHandle;
  cufftHandle e_fftPlanHandle;
  cufftHandle f_fftPlanHandle;
  cufftHandle fftPlanHandle;
  creal_T(*b_gpu_x)[256];
  creal_T(*gpu_Psie)[256];
  creal_T(*gpu_Psio)[256];
  creal_T(*gpu_x)[256];
  int32_T inembed;
  cudaMalloc(&b_gpu_x, 4096UL);
  cudaMalloc(&gpu_x, 4096UL);
  cudaMalloc(&gpu_Psie, 4096UL);
  cudaMalloc(&gpu_Psio, 4096UL);
  Chi_3_LLE_Kuar_ins_kernel1<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
      Fac_minus, F_Psi, *gpu_Psio);
  inembed = 256;
  fftPlanHandle = acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
  cufftExecZ2Z(fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psio)[0],
               (cufftDoubleComplex *)&(*gpu_Psio)[0], CUFFT_INVERSE);
  Chi_3_LLE_Kuar_ins_kernel2<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
      Fac_minus, F_Psi, *gpu_Psie, *gpu_Psio);
  inembed = 256;
  b_fftPlanHandle = acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
  cufftExecZ2Z(b_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psie)[0],
               (cufftDoubleComplex *)&(*gpu_Psie)[0], CUFFT_INVERSE);
  Chi_3_LLE_Kuar_ins_kernel3<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
      *gpu_Psie);
  Chi_3_LLE_Kuar_ins_kernel4<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
      *gpu_Psie, *gpu_Psio, *gpu_x);
  inembed = 256;
  c_fftPlanHandle = acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
  cufftExecZ2Z(c_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_x)[0],
               (cufftDoubleComplex *)&(*gpu_x)[0], CUFFT_FORWARD);
  Chi_3_LLE_Kuar_ins_kernel5<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
      *gpu_Psie, *gpu_Psio, *b_gpu_x);
  inembed = 256;
  d_fftPlanHandle = acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
  cufftExecZ2Z(d_fftPlanHandle, (cufftDoubleComplex *)&(*b_gpu_x)[0],
               (cufftDoubleComplex *)&(*b_gpu_x)[0], CUFFT_FORWARD);
  //
  Chi_3_LLE_Kuar_ins_kernel6<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
      *gpu_Psio, *b_gpu_x, gam3o, gam2o, Fac_plus, k_e, *gpu_x);
  inembed = 256;
  e_fftPlanHandle = acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
  cufftExecZ2Z(e_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_x)[0],
               (cufftDoubleComplex *)&(*gpu_x)[0], CUFFT_FORWARD);
  Chi_3_LLE_Kuar_ins_kernel7<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
      *gpu_Psio, *gpu_Psie);
  inembed = 256;
  f_fftPlanHandle = acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, CUFFT_Z2Z, 1);
  cufftExecZ2Z(f_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psie)[0],
               (cufftDoubleComplex *)&(*gpu_Psie)[0], CUFFT_FORWARD);
  Chi_3_LLE_Kuar_ins_kernel8<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
      *gpu_Psie, *gpu_x, gam3e, gam2e, Fac_plus, k_e);
  //
  //     k_e(1)      = k_e(1) + ;
  cudaFree(*gpu_Psio);
  cudaFree(*gpu_Psie);
  cudaFree(*gpu_x);
  cudaFree(*b_gpu_x);
}

// End of code generation (Chi_3_LLE_Kuar_ins.cu)
