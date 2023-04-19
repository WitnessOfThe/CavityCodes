//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi23_Runge_Kuarong_GPU.cu
//
// Code generation for function 'Chi23_Runge_Kuarong_GPU'
//

// Include files
#include "Chi23_Runge_Kuarong_GPU.h"
#include "Chi23_Runge_Kuarong_GPU_data.h"
#include "Chi23_Runge_Kuarong_GPU_emxutil.h"
#include "Chi23_Runge_Kuarong_GPU_types.h"
#include "rt_nonfinite.h"
#include "MWCUFFTPlanManager.hpp"
#include "MWCudaDimUtility.hpp"
#include "MWLaunchParametersUtilities.hpp"
#include "cufft.h"
#include <cmath>
#include <cstring>

// Function Declarations
static __global__ void Chi23_Runge_Kuarong_GPU_kernel1(const int32_T Runge,
                                                       emxArray_cuint8_T d);

static __global__ void
Chi23_Runge_Kuarong_GPU_kernel2(const real_T Par_dt, const struct0_T *Temp,
                                const struct7_T Runge,
                                creal_T exp_plus_omega_contents[1536],
                                creal_T exp_minus_omega_contents[1536]);

static __global__ void Chi23_Runge_Kuarong_GPU_kernel3(const struct0_T *Temp,
                                                       creal_T F_e[512],
                                                       creal_T y[512]);

static __global__ void Chi23_Runge_Kuarong_GPU_kernel4(const struct0_T *Temp,
                                                       int32_T *i);

static __global__ void
Chi23_Runge_Kuarong_GPU_kernel5(const emxArray_cuint8_T d, const int32_T b_d,
                                emxArray_creal_T c_d);

static __global__ void Chi23_Runge_Kuarong_GPU_kernel6(const creal_T F_e[512],
                                                       creal_T E_temp[512]);

static __global__ void
Chi23_Runge_Kuarong_GPU_kernel7(const creal_T exp_minus_omega_contents[1536],
                                const creal_T F_e[512], creal_T Psio[256]);

static __global__ void
Chi23_Runge_Kuarong_GPU_kernel8(const creal_T exp_minus_omega_contents[1536],
                                const creal_T F_e[512], creal_T Psie[256],
                                creal_T Psio[256]);

static __global__ void Chi23_Runge_Kuarong_GPU_kernel9(creal_T Psie[256]);

static __global__ void ab_Chi23_Runge_Kuarong_GPU_kern(const creal_T F_e[512],
                                                       const creal_T y[512],
                                                       const struct0_T *Temp,
                                                       creal_T b_y[512]);

static __global__ void b_Chi23_Runge_Kuarong_GPU_kerne(creal_T k_e[512]);

static __global__ void bb_Chi23_Runge_Kuarong_GPU_kern(const creal_T y[512],
                                                       const struct0_T *Temp,
                                                       creal_T F_e[512]);

static __global__ void c_Chi23_Runge_Kuarong_GPU_kerne(const creal_T Psie[256],
                                                       const creal_T Psio[256],
                                                       creal_T x[256]);

static __global__ void d_Chi23_Runge_Kuarong_GPU_kerne(const creal_T Psie[256],
                                                       const creal_T Psio[256],
                                                       creal_T x[256]);

static __global__ void
e_Chi23_Runge_Kuarong_GPU_kerne(const creal_T Psio[256], const creal_T x[256],
                                const struct0_T *Temp,
                                const creal_T exp_plus_omega_contents[1536],
                                creal_T k_e[512], creal_T b_x[256]);

static __global__ void f_Chi23_Runge_Kuarong_GPU_kerne(const creal_T Psio[256],
                                                       creal_T Psie[256]);

static __global__ void g_Chi23_Runge_Kuarong_GPU_kerne(
    const creal_T Psie[256], const creal_T x[256], const struct0_T *Temp,
    const creal_T exp_plus_omega_contents[1536], creal_T k_e[512]);

static void gpuEmxEnsureCapacity_creal_T(const emxArray_creal_T *cpu,
                                         emxArray_creal_T *gpu);

static void gpuEmxEnsureCapacity_cuint8_T(const emxArray_cuint8_T *cpu,
                                          emxArray_cuint8_T *gpu);

static void gpuEmxFree_creal_T(emxArray_creal_T *gpu);

static void gpuEmxFree_cuint8_T(emxArray_cuint8_T *gpu);

static void gpuEmxReset_creal_T(emxArray_creal_T *gpu);

static void gpuEmxReset_cuint8_T(emxArray_cuint8_T *gpu);

static __global__ void h_Chi23_Runge_Kuarong_GPU_kerne(const real_T im,
                                                       const real_T re,
                                                       const struct0_T *Temp,
                                                       creal_T k_e[512]);

static __global__ void i_Chi23_Runge_Kuarong_GPU_kerne(const creal_T k_e[512],
                                                       const int32_T iv,
                                                       const int32_T d_dim0,
                                                       emxArray_creal_T d);

static __global__ void
j_Chi23_Runge_Kuarong_GPU_kerne(const emxArray_creal_T d, const int32_T inembed,
                                const real_T ar, const creal_T E_temp[512],
                                const struct0_T *Temp, const int32_T d_dim0,
                                creal_T b_E_temp[512]);

static __global__ void
k_Chi23_Runge_Kuarong_GPU_kerne(const creal_T E_temp[512],
                                const struct0_T *Temp, creal_T b_E_temp[512]);

static __global__ void
l_Chi23_Runge_Kuarong_GPU_kerne(const creal_T exp_minus_omega_contents[1536],
                                const int32_T inembed,
                                const creal_T E_temp[512], creal_T Psio[256]);

static __global__ void m_Chi23_Runge_Kuarong_GPU_kerne(
    const creal_T exp_minus_omega_contents[1536], const int32_T inembed,
    const creal_T E_temp[512], creal_T Psie[256], creal_T Psio[256]);

static __global__ void n_Chi23_Runge_Kuarong_GPU_kerne(creal_T Psie[256]);

static __global__ void o_Chi23_Runge_Kuarong_GPU_kerne(creal_T k_e[512]);

static __global__ void p_Chi23_Runge_Kuarong_GPU_kerne(const creal_T Psie[256],
                                                       const creal_T Psio[256],
                                                       creal_T x[256]);

static __global__ void q_Chi23_Runge_Kuarong_GPU_kerne(const creal_T Psie[256],
                                                       const creal_T Psio[256],
                                                       creal_T x[256]);

static __global__ void r_Chi23_Runge_Kuarong_GPU_kerne(
    const creal_T Psio[256], const creal_T x[256], const struct0_T *Temp,
    const creal_T exp_plus_omega_contents[1536], const int32_T inembed,
    creal_T k_e[512], creal_T b_x[256]);

static __global__ void s_Chi23_Runge_Kuarong_GPU_kerne(const creal_T Psio[256],
                                                       creal_T Psie[256]);

static __global__ void
t_Chi23_Runge_Kuarong_GPU_kerne(const creal_T Psie[256], const creal_T x[256],
                                const struct0_T *Temp,
                                const creal_T exp_plus_omega_contents[1536],
                                const int32_T inembed, creal_T k_e[512]);

static __global__ void u_Chi23_Runge_Kuarong_GPU_kerne(const real_T ar,
                                                       const real_T *q,
                                                       const struct0_T *Temp,
                                                       creal_T k_e[512]);

static __global__ void v_Chi23_Runge_Kuarong_GPU_kerne(const creal_T k_e[512],
                                                       const int32_T inembed,
                                                       const int32_T iv1,
                                                       const int32_T d_dim0,
                                                       emxArray_creal_T d);

static __global__ void w_Chi23_Runge_Kuarong_GPU_kerne(const creal_T F_e[512],
                                                       creal_T E_temp[512]);

static __global__ void
x_Chi23_Runge_Kuarong_GPU_kerne(const emxArray_creal_T d, const int32_T inembed,
                                const real_T ar, const creal_T F_e[512],
                                const struct0_T *Temp, const int32_T d_dim0,
                                creal_T E_temp[512]);

static __global__ void
y_Chi23_Runge_Kuarong_GPU_kerne(const creal_T E_temp[512],
                                const struct0_T *Temp, creal_T F_e[512]);

// Function Definitions
static __global__ __launch_bounds__(
    1024, 1) void Chi23_Runge_Kuarong_GPU_kernel1(const int32_T Runge,
                                                  emxArray_cuint8_T d)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(Runge);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T k;
    k = static_cast<int32_T>(idx);
    d.data[k].re = static_cast<uint8_T>(0U);
    d.data[k].im = static_cast<uint8_T>(0U);
  }
}

static __global__
    __launch_bounds__(512, 1) void Chi23_Runge_Kuarong_GPU_kernel2(
        const real_T Par_dt, const struct0_T *Temp, const struct7_T Runge,
        creal_T exp_plus_omega_contents[1536],
        creal_T exp_minus_omega_contents[1536])
{
  uint64_T threadId;
  int32_T i;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId % 512ULL);
  i = static_cast<int32_T>((threadId - static_cast<uint64_T>(k)) / 512ULL);
  if ((static_cast<int32_T>(i < 3)) && (static_cast<int32_T>(k < 512))) {
    real_T d;
    real_T d1;
    real_T im;
    real_T r;
    real_T re;
    d = Temp->Eq.L[k].re;
    d1 = Temp->Eq.L[k].im;
    re = Par_dt * (Runge.a[i] * (0.0 * d - (-d1)));
    im = Par_dt * (Runge.a[i] * (0.0 * d1 + -d));
    if (im == 0.0) {
      re = exp(re);
      im = 0.0;
    } else if ((static_cast<int32_T>((static_cast<int32_T>(isinf(im))) &&
                                     (static_cast<int32_T>(isinf(re))))) &&
               (static_cast<int32_T>(re < 0.0))) {
      re = 0.0;
      im = 0.0;
    } else {
      r = exp(re / 2.0);
      re = r * (r * cos(im));
      im = r * (r * sin(im));
    }
    exp_minus_omega_contents[i + 3 * k].re = re;
    exp_minus_omega_contents[i + 3 * k].im = im;
    re = Par_dt * (Runge.a[i] * (0.0 * d - d1));
    im = Par_dt * (Runge.a[i] * (0.0 * d1 + d));
    if (im == 0.0) {
      re = exp(re);
      im = 0.0;
    } else if ((static_cast<int32_T>((static_cast<int32_T>(isinf(im))) &&
                                     (static_cast<int32_T>(isinf(re))))) &&
               (static_cast<int32_T>(re < 0.0))) {
      re = 0.0;
      im = 0.0;
    } else {
      r = exp(re / 2.0);
      re = r * (r * cos(im));
      im = r * (r * sin(im));
    }
    exp_plus_omega_contents[i + 3 * k].re = re;
    exp_plus_omega_contents[i + 3 * k].im = im;
  }
}

static __global__
    __launch_bounds__(512, 1) void Chi23_Runge_Kuarong_GPU_kernel3(
        const struct0_T *Temp, creal_T F_e[512], creal_T y[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    real_T im;
    real_T re;
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    re = Temp->Par.dt * (0.0 * Temp->Eq.L[k].re - (-Temp->Eq.L[k].im));
    im = Temp->Par.dt * (0.0 * Temp->Eq.L[k].im + -Temp->Eq.L[k].re);
    y[k].re = re;
    y[k].im = im;
    if (im == 0.0) {
      y[k].re = exp(re);
      y[k].im = 0.0;
    } else if ((static_cast<int32_T>((static_cast<int32_T>(isinf(im))) &&
                                     (static_cast<int32_T>(isinf(re))))) &&
               (static_cast<int32_T>(re < 0.0))) {
      y[k].re = 0.0;
      y[k].im = 0.0;
    } else {
      re = exp(re / 2.0);
      y[k].re = re * (re * cos(im));
      y[k].im = re * (re * sin(im));
    }
    F_e[k] = Temp->In.Psi_Start[k];
  }
}

static __global__ __launch_bounds__(32, 1) void Chi23_Runge_Kuarong_GPU_kernel4(
    const struct0_T *Temp, int32_T *i)
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    *i = static_cast<int32_T>(Temp->Par.T / Temp->Par.dt);
  }
}

static __global__
    __launch_bounds__(1024, 1) void Chi23_Runge_Kuarong_GPU_kernel5(
        const emxArray_cuint8_T d, const int32_T b_d, emxArray_creal_T c_d)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(b_d);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T k;
    k = static_cast<int32_T>(idx);
    c_d.data[k].re = 0.0;
    c_d.data[k].im = static_cast<real_T>(d.data[k].im);
  }
}

static __global__ __launch_bounds__(
    512, 1) void Chi23_Runge_Kuarong_GPU_kernel6(const creal_T F_e[512],
                                                 creal_T E_temp[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    E_temp[k] = F_e[k];
  }
}

static __global__
    __launch_bounds__(256, 1) void Chi23_Runge_Kuarong_GPU_kernel7(
        const creal_T exp_minus_omega_contents[1536], const creal_T F_e[512],
        creal_T Psio[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T im;
    real_T r;
    d = F_e[k].re;
    d1 = F_e[k].im;
    im = exp_minus_omega_contents[3 * k].re;
    r = exp_minus_omega_contents[3 * k].im;
    Psio[k].re = d * im - d1 * r;
    Psio[k].im = d * r + d1 * im;
  }
}

static __global__
    __launch_bounds__(256, 1) void Chi23_Runge_Kuarong_GPU_kernel8(
        const creal_T exp_minus_omega_contents[1536], const creal_T F_e[512],
        creal_T Psie[256], creal_T Psio[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T im;
    real_T r;
    r = Psio[k].re;
    im = Psio[k].im;
    if (im == 0.0) {
      r /= 256.0;
      im = 0.0;
    } else if (r == 0.0) {
      r = 0.0;
      im /= 256.0;
    } else {
      r /= 256.0;
      im /= 256.0;
    }
    Psio[k].re = r;
    Psio[k].im = im;
    d = F_e[k + 256].re;
    d1 = F_e[k + 256].im;
    im = exp_minus_omega_contents[3 * (k + 256)].re;
    r = exp_minus_omega_contents[3 * (k + 256)].im;
    Psie[k].re = d * im - d1 * r;
    Psie[k].im = d * r + d1 * im;
  }
}

static __global__
    __launch_bounds__(256,
                      1) void Chi23_Runge_Kuarong_GPU_kernel9(creal_T Psie[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T im;
    real_T r;
    r = Psie[k].re;
    im = Psie[k].im;
    if (im == 0.0) {
      r /= 256.0;
      im = 0.0;
    } else if (r == 0.0) {
      r = 0.0;
      im /= 256.0;
    } else {
      r /= 256.0;
      im /= 256.0;
    }
    Psie[k].re = r;
    Psie[k].im = im;
  }
}

static __global__ __launch_bounds__(
    512, 1) void ab_Chi23_Runge_Kuarong_GPU_kern(const creal_T F_e[512],
                                                 const creal_T y[512],
                                                 const struct0_T *Temp,
                                                 creal_T b_y[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    real_T d;
    d = Temp->Eq.mode_range[k];
    b_y[k].re =
        y[static_cast<int32_T>(d) - 1].re *
            F_e[static_cast<int32_T>(d) - 1].re -
        y[static_cast<int32_T>(d) - 1].im * F_e[static_cast<int32_T>(d) - 1].im;
    b_y[k].im =
        y[static_cast<int32_T>(d) - 1].re *
            F_e[static_cast<int32_T>(d) - 1].im +
        y[static_cast<int32_T>(d) - 1].im * F_e[static_cast<int32_T>(d) - 1].re;
  }
}

static __global__
    __launch_bounds__(512,
                      1) void b_Chi23_Runge_Kuarong_GPU_kerne(creal_T k_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    k_e[k].re = 0.0;
    k_e[k].im = 0.0;
  }
}

static __global__
    __launch_bounds__(512, 1) void bb_Chi23_Runge_Kuarong_GPU_kern(
        const creal_T y[512], const struct0_T *Temp, creal_T F_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    F_e[static_cast<int32_T>(Temp->Eq.mode_range[k]) - 1] = y[k];
  }
}

static __global__
    __launch_bounds__(256, 1) void c_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T Psie[256], const creal_T Psio[256], creal_T x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T im;
    real_T r;
    im = Psio[k].re;
    r = -Psio[k].im;
    d = Psie[k].re;
    d1 = Psie[k].im;
    x[k].re = im * d - r * d1;
    x[k].im = im * d1 + r * d;
  }
}

static __global__
    __launch_bounds__(256, 1) void d_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T Psie[256], const creal_T Psio[256], creal_T x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T im;
    real_T r;
    d = Psio[k].re;
    d1 = Psio[k].im;
    im = hypot(d, d1);
    r = im * im;
    im = hypot(Psie[k].re, Psie[k].im);
    x[k].re = (r + 2.0 * (im * im)) * d;
    x[k].im = (r + 2.0 * (im * im)) * d1;
  }
}

static __global__
    __launch_bounds__(256, 1) void e_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T Psio[256], const creal_T x[256], const struct0_T *Temp,
        const creal_T exp_plus_omega_contents[1536], creal_T k_e[512],
        creal_T b_x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T Temp_re;
    real_T d;
    real_T d1;
    real_T im;
    real_T re;
    //
    d = exp_plus_omega_contents[3 * k].re;
    d1 = exp_plus_omega_contents[3 * k].im;
    im = 0.0 * d - d1;
    re = 0.0 * d1 + d;
    d = Temp->Eq.gam2o[k];
    d1 = Temp->Eq.gam3o[k];
    Temp_re = d * b_x[k].re + d1 * x[k].re;
    d = d * b_x[k].im + d1 * x[k].im;
    k_e[k].re = im * Temp_re - re * d;
    k_e[k].im = im * d + re * Temp_re;
    d = Psio[k].re;
    d1 = Psio[k].im;
    b_x[k].re = d * d - d1 * d1;
    b_x[k].im = d * d1 + d1 * d;
  }
}

static __global__ __launch_bounds__(
    256, 1) void f_Chi23_Runge_Kuarong_GPU_kerne(const creal_T Psio[256],
                                                 creal_T Psie[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T im;
    real_T r;
    d = hypot(Psio[k].re, Psio[k].im);
    d1 = d * d;
    im = Psie[k].re;
    r = Psie[k].im;
    d = hypot(im, r);
    im *= 2.0 * d1 + d * d;
    Psie[k].re = im;
    r *= 2.0 * d1 + d * d;
    Psie[k].im = r;
  }
}

static __global__
    __launch_bounds__(256, 1) void g_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T Psie[256], const creal_T x[256], const struct0_T *Temp,
        const creal_T exp_plus_omega_contents[1536], creal_T k_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T Temp_re;
    real_T d;
    real_T d1;
    real_T im;
    real_T re;
    d = exp_plus_omega_contents[3 * (k + 256)].re;
    d1 = exp_plus_omega_contents[3 * (k + 256)].im;
    im = 0.0 * d - d1;
    re = 0.0 * d1 + d;
    d = Temp->Eq.gam2e[k];
    d1 = Temp->Eq.gam3e[k];
    Temp_re = d * x[k].re + d1 * Psie[k].re;
    d = d * x[k].im + d1 * Psie[k].im;
    k_e[k + 256].re = im * Temp_re - re * d;
    k_e[k + 256].im = im * d + re * Temp_re;
  }
}

static void gpuEmxEnsureCapacity_creal_T(const emxArray_creal_T *cpu,
                                         emxArray_creal_T *gpu)
{
  creal_T *newData;
  if (gpu->data == 0) {
    newData = 0ULL;
    cudaMalloc(&newData, cpu->allocatedSize * sizeof(creal_T));
    gpu->numDimensions = cpu->numDimensions;
    gpu->size = (int32_T *)emlrtCallocMex(
        static_cast<uint32_T>(gpu->numDimensions), sizeof(int32_T));
    for (int32_T i{0}; i < cpu->numDimensions; i++) {
      gpu->size[i] = cpu->size[i];
    }
    gpu->allocatedSize = cpu->allocatedSize;
    gpu->canFreeData = true;
    gpu->data = newData;
  } else {
    int32_T actualSizeCpu;
    int32_T actualSizeGpu;
    actualSizeCpu = 1;
    actualSizeGpu = 1;
    for (int32_T i{0}; i < cpu->numDimensions; i++) {
      actualSizeGpu *= gpu->size[i];
      actualSizeCpu *= cpu->size[i];
      gpu->size[i] = cpu->size[i];
    }
    if (gpu->allocatedSize < actualSizeCpu) {
      newData = 0ULL;
      cudaMalloc(&newData, cpu->allocatedSize * sizeof(creal_T));
      cudaMemcpy(newData, gpu->data, actualSizeGpu * sizeof(creal_T),
                 cudaMemcpyDeviceToDevice);
      gpu->allocatedSize = cpu->allocatedSize;
      if (gpu->canFreeData) {
        cudaFree(gpu->data);
      }
      gpu->canFreeData = true;
      gpu->data = newData;
    }
  }
}

static void gpuEmxEnsureCapacity_cuint8_T(const emxArray_cuint8_T *cpu,
                                          emxArray_cuint8_T *gpu)
{
  cuint8_T *newData;
  if (gpu->data == 0) {
    newData = 0ULL;
    cudaMalloc(&newData, cpu->allocatedSize * sizeof(cuint8_T));
    gpu->numDimensions = cpu->numDimensions;
    gpu->size = (int32_T *)emlrtCallocMex(
        static_cast<uint32_T>(gpu->numDimensions), sizeof(int32_T));
    for (int32_T i{0}; i < cpu->numDimensions; i++) {
      gpu->size[i] = cpu->size[i];
    }
    gpu->allocatedSize = cpu->allocatedSize;
    gpu->canFreeData = true;
    gpu->data = newData;
  } else {
    int32_T actualSizeCpu;
    int32_T actualSizeGpu;
    actualSizeCpu = 1;
    actualSizeGpu = 1;
    for (int32_T i{0}; i < cpu->numDimensions; i++) {
      actualSizeGpu *= gpu->size[i];
      actualSizeCpu *= cpu->size[i];
      gpu->size[i] = cpu->size[i];
    }
    if (gpu->allocatedSize < actualSizeCpu) {
      newData = 0ULL;
      cudaMalloc(&newData, cpu->allocatedSize * sizeof(cuint8_T));
      cudaMemcpy(newData, gpu->data, actualSizeGpu * sizeof(cuint8_T),
                 cudaMemcpyDeviceToDevice);
      gpu->allocatedSize = cpu->allocatedSize;
      if (gpu->canFreeData) {
        cudaFree(gpu->data);
      }
      gpu->canFreeData = true;
      gpu->data = newData;
    }
  }
}

static void gpuEmxFree_creal_T(emxArray_creal_T *gpu)
{
  if (gpu->data != (void *)4207599121ULL) {
    cudaFree(gpu->data);
  }
  emlrtFreeMex(gpu->size);
}

static void gpuEmxFree_cuint8_T(emxArray_cuint8_T *gpu)
{
  if (gpu->data != (void *)4207599121ULL) {
    cudaFree(gpu->data);
  }
  emlrtFreeMex(gpu->size);
}

static void gpuEmxReset_creal_T(emxArray_creal_T *gpu)
{
  std::memset(gpu, 0, sizeof(emxArray_creal_T));
}

static void gpuEmxReset_cuint8_T(emxArray_cuint8_T *gpu)
{
  std::memset(gpu, 0, sizeof(emxArray_cuint8_T));
}

static __global__ __launch_bounds__(32, 1) void h_Chi23_Runge_Kuarong_GPU_kerne(
    const real_T im, const real_T re, const struct0_T *Temp, creal_T k_e[512])
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    //
    k_e[0].re += Temp->Eq.ko * re * Temp->Eq.H_f;
    k_e[0].im += Temp->Eq.ko * im * Temp->Eq.H_f;
  }
}

static __global__ __launch_bounds__(
    1024, 1) void i_Chi23_Runge_Kuarong_GPU_kerne(const creal_T k_e[512],
                                                  const int32_T iv,
                                                  const int32_T d_dim0,
                                                  emxArray_creal_T d)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(iv);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T k;
    k = static_cast<int32_T>(idx);
    d.data[d_dim0 * k] = k_e[k];
  }
}

static __global__
    __launch_bounds__(512, 1) void j_Chi23_Runge_Kuarong_GPU_kerne(
        const emxArray_creal_T d, const int32_T inembed, const real_T ar,
        const creal_T E_temp[512], const struct0_T *Temp, const int32_T d_dim0,
        creal_T b_E_temp[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    real_T b_d;
    b_d = Temp->Eq.mode_range[k];
    b_E_temp[k].re =
        E_temp[static_cast<int32_T>(b_d) - 1].re +
        ar * d.data[inembed + d_dim0 * (static_cast<int32_T>(b_d) - 1)].re;
    b_E_temp[k].im =
        E_temp[static_cast<int32_T>(b_d) - 1].im +
        ar * d.data[inembed + d_dim0 * (static_cast<int32_T>(b_d) - 1)].im;
  }
}

static __global__
    __launch_bounds__(512, 1) void k_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T E_temp[512], const struct0_T *Temp, creal_T b_E_temp[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    b_E_temp[static_cast<int32_T>(Temp->Eq.mode_range[k]) - 1] = E_temp[k];
  }
}

static __global__
    __launch_bounds__(256, 1) void l_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T exp_minus_omega_contents[1536], const int32_T inembed,
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
    Psio[k].re = d * exp_minus_omega_contents[inembed + 3 * k].re -
                 d1 * exp_minus_omega_contents[inembed + 3 * k].im;
    Psio[k].im = d * exp_minus_omega_contents[inembed + 3 * k].im +
                 d1 * exp_minus_omega_contents[inembed + 3 * k].re;
  }
}

static __global__
    __launch_bounds__(256, 1) void m_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T exp_minus_omega_contents[1536], const int32_T inembed,
        const creal_T E_temp[512], creal_T Psie[256], creal_T Psio[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T im;
    real_T r;
    r = Psio[k].re;
    im = Psio[k].im;
    if (im == 0.0) {
      r /= 256.0;
      im = 0.0;
    } else if (r == 0.0) {
      r = 0.0;
      im /= 256.0;
    } else {
      r /= 256.0;
      im /= 256.0;
    }
    Psio[k].re = r;
    Psio[k].im = im;
    r = E_temp[k + 256].re;
    im = E_temp[k + 256].im;
    Psie[k].re = r * exp_minus_omega_contents[inembed + 3 * (k + 256)].re -
                 im * exp_minus_omega_contents[inembed + 3 * (k + 256)].im;
    Psie[k].im = r * exp_minus_omega_contents[inembed + 3 * (k + 256)].im +
                 im * exp_minus_omega_contents[inembed + 3 * (k + 256)].re;
  }
}

static __global__
    __launch_bounds__(256,
                      1) void n_Chi23_Runge_Kuarong_GPU_kerne(creal_T Psie[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T im;
    real_T r;
    r = Psie[k].re;
    im = Psie[k].im;
    if (im == 0.0) {
      r /= 256.0;
      im = 0.0;
    } else if (r == 0.0) {
      r = 0.0;
      im /= 256.0;
    } else {
      r /= 256.0;
      im /= 256.0;
    }
    Psie[k].re = r;
    Psie[k].im = im;
  }
}

static __global__
    __launch_bounds__(512,
                      1) void o_Chi23_Runge_Kuarong_GPU_kerne(creal_T k_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    k_e[k].re = 0.0;
    k_e[k].im = 0.0;
  }
}

static __global__
    __launch_bounds__(256, 1) void p_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T Psie[256], const creal_T Psio[256], creal_T x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T im;
    real_T r;
    im = Psio[k].re;
    r = -Psio[k].im;
    d = Psie[k].re;
    d1 = Psie[k].im;
    x[k].re = im * d - r * d1;
    x[k].im = im * d1 + r * d;
  }
}

static __global__
    __launch_bounds__(256, 1) void q_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T Psie[256], const creal_T Psio[256], creal_T x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T im;
    real_T r;
    d = Psio[k].re;
    d1 = Psio[k].im;
    im = hypot(d, d1);
    r = im * im;
    im = hypot(Psie[k].re, Psie[k].im);
    x[k].re = (r + 2.0 * (im * im)) * d;
    x[k].im = (r + 2.0 * (im * im)) * d1;
  }
}

static __global__
    __launch_bounds__(256, 1) void r_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T Psio[256], const creal_T x[256], const struct0_T *Temp,
        const creal_T exp_plus_omega_contents[1536], const int32_T inembed,
        creal_T k_e[512], creal_T b_x[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T Temp_re;
    real_T d;
    real_T d1;
    real_T im;
    real_T re;
    //
    im = 0.0 * exp_plus_omega_contents[inembed + 3 * k].re -
         exp_plus_omega_contents[inembed + 3 * k].im;
    re = 0.0 * exp_plus_omega_contents[inembed + 3 * k].im +
         exp_plus_omega_contents[inembed + 3 * k].re;
    d = Temp->Eq.gam2o[k];
    d1 = Temp->Eq.gam3o[k];
    Temp_re = d * b_x[k].re + d1 * x[k].re;
    d = d * b_x[k].im + d1 * x[k].im;
    k_e[k].re = im * Temp_re - re * d;
    k_e[k].im = im * d + re * Temp_re;
    d = Psio[k].re;
    d1 = Psio[k].im;
    b_x[k].re = d * d - d1 * d1;
    b_x[k].im = d * d1 + d1 * d;
  }
}

static __global__ __launch_bounds__(
    256, 1) void s_Chi23_Runge_Kuarong_GPU_kerne(const creal_T Psio[256],
                                                 creal_T Psie[256])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T d;
    real_T d1;
    real_T im;
    real_T r;
    d = hypot(Psio[k].re, Psio[k].im);
    d1 = d * d;
    im = Psie[k].re;
    r = Psie[k].im;
    d = hypot(im, r);
    im *= 2.0 * d1 + d * d;
    Psie[k].re = im;
    r *= 2.0 * d1 + d * d;
    Psie[k].im = r;
  }
}

static __global__
    __launch_bounds__(256, 1) void t_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T Psie[256], const creal_T x[256], const struct0_T *Temp,
        const creal_T exp_plus_omega_contents[1536], const int32_T inembed,
        creal_T k_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 256) {
    real_T Temp_re;
    real_T d;
    real_T d1;
    real_T im;
    real_T re;
    im = 0.0 * exp_plus_omega_contents[inembed + 3 * (k + 256)].re -
         exp_plus_omega_contents[inembed + 3 * (k + 256)].im;
    re = 0.0 * exp_plus_omega_contents[inembed + 3 * (k + 256)].im +
         exp_plus_omega_contents[inembed + 3 * (k + 256)].re;
    d = Temp->Eq.gam2e[k];
    d1 = Temp->Eq.gam3e[k];
    Temp_re = d * x[k].re + d1 * Psie[k].re;
    d = d * x[k].im + d1 * Psie[k].im;
    k_e[k + 256].re = im * Temp_re - re * d;
    k_e[k + 256].im = im * d + re * Temp_re;
  }
}

static __global__ __launch_bounds__(32, 1) void u_Chi23_Runge_Kuarong_GPU_kerne(
    const real_T ar, const real_T *q, const struct0_T *Temp, creal_T k_e[512])
{
  uint64_T threadId;
  int32_T tmpIdx;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  tmpIdx = static_cast<int32_T>(threadId);
  if (tmpIdx < 1) {
    k_e[0].re += Temp->Eq.ko * *q * Temp->Eq.H_f;
    k_e[0].im += Temp->Eq.ko * ar * Temp->Eq.H_f;
  }
}

static __global__
    __launch_bounds__(1024, 1) void v_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T k_e[512], const int32_T inembed, const int32_T iv1,
        const int32_T d_dim0, emxArray_creal_T d)
{
  uint64_T loopEnd;
  uint64_T threadId;
  uint64_T threadStride;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  threadStride = mwGetTotalThreadsLaunched();
  loopEnd = static_cast<uint64_T>(iv1);
  for (uint64_T idx{threadId}; idx <= loopEnd; idx += threadStride) {
    int32_T k;
    k = static_cast<int32_T>(idx);
    d.data[inembed + d_dim0 * k] = k_e[k];
  }
}

static __global__ __launch_bounds__(
    512, 1) void w_Chi23_Runge_Kuarong_GPU_kerne(const creal_T F_e[512],
                                                 creal_T E_temp[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    E_temp[k] = F_e[k];
  }
}

static __global__
    __launch_bounds__(512, 1) void x_Chi23_Runge_Kuarong_GPU_kerne(
        const emxArray_creal_T d, const int32_T inembed, const real_T ar,
        const creal_T F_e[512], const struct0_T *Temp, const int32_T d_dim0,
        creal_T E_temp[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    real_T b_d;
    b_d = Temp->Eq.mode_range[k];
    E_temp[k].re =
        F_e[static_cast<int32_T>(b_d) - 1].re +
        ar * d.data[inembed + d_dim0 * (static_cast<int32_T>(b_d) - 1)].re;
    E_temp[k].im =
        F_e[static_cast<int32_T>(b_d) - 1].im +
        ar * d.data[inembed + d_dim0 * (static_cast<int32_T>(b_d) - 1)].im;
  }
}

static __global__
    __launch_bounds__(512, 1) void y_Chi23_Runge_Kuarong_GPU_kerne(
        const creal_T E_temp[512], const struct0_T *Temp, creal_T F_e[512])
{
  uint64_T threadId;
  int32_T k;
  threadId = static_cast<uint64_T>(mwGetGlobalThreadIndexInXDimension());
  k = static_cast<int32_T>(threadId);
  if (k < 512) {
    F_e[static_cast<int32_T>(Temp->Eq.mode_range[k]) - 1] = E_temp[k];
  }
}

void Chi23_Runge_Kuarong_GPU(const struct0_T *Temp, const struct7_T *Runge,
                             struct8_T *Sol)
{
  cufftType b_fftType;
  cufftType c_fftType;
  cufftType d_fftType;
  cufftType e_fftType;
  cufftType f_fftType;
  cufftType fftType;
  cufftType g_fftType;
  cufftType h_fftType;
  cufftType i_fftType;
  cufftType j_fftType;
  cufftType k_fftType;
  cufftType l_fftType;
  int b_fftDirection;
  int c_fftDirection;
  int d_fftDirection;
  int e_fftDirection;
  int f_fftDirection;
  int fftDirection;
  int g_fftDirection;
  int h_fftDirection;
  int i_fftDirection;
  int j_fftDirection;
  int k_fftDirection;
  int l_fftDirection;
  dim3 block;
  dim3 grid;
  emxArray_creal_T b_gpu_d;
  emxArray_creal_T *b_d;
  emxArray_cuint8_T gpu_d;
  emxArray_cuint8_T *d;
  struct0_T *gpu_Temp;
  creal_T exp_plus_omega_contents[1536];
  creal_T(*gpu_exp_minus_omega_contents)[1536];
  creal_T(*gpu_exp_plus_omega_contents)[1536];
  creal_T F_e[512];
  creal_T(*b_gpu_E_temp)[512];
  creal_T(*b_gpu_y)[512];
  creal_T(*gpu_E_temp)[512];
  creal_T(*gpu_F_e)[512];
  creal_T(*gpu_k_e)[512];
  creal_T(*gpu_y)[512];
  creal_T(*b_gpu_x)[256];
  creal_T(*gpu_Psie)[256];
  creal_T(*gpu_Psio)[256];
  creal_T(*gpu_x)[256];
  real_T Par_dt;
  real_T ai;
  real_T ar;
  real_T im;
  real_T q;
  real_T re;
  real_T y;
  real_T *gpu_q;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T *gpu_i;
  boolean_T c_exp_plus_omega_contents_dirty;
  boolean_T validLaunchParams;
  cudaMalloc(&gpu_q, 8ULL);
  cudaMalloc(&b_gpu_E_temp, 8192ULL);
  cudaMalloc(&b_gpu_y, 8192ULL);
  cudaMalloc(&b_gpu_x, 4096ULL);
  cudaMalloc(&gpu_x, 4096ULL);
  cudaMalloc(&gpu_k_e, 8192ULL);
  cudaMalloc(&gpu_Psie, 4096ULL);
  cudaMalloc(&gpu_Psio, 4096ULL);
  cudaMalloc(&gpu_E_temp, 8192ULL);
  gpuEmxReset_creal_T(&b_gpu_d);
  cudaMalloc(&gpu_i, 4ULL);
  cudaMalloc(&gpu_y, 8192ULL);
  cudaMalloc(&gpu_F_e, 8192ULL);
  cudaMalloc(&gpu_exp_minus_omega_contents, 24576ULL);
  cudaMalloc(&gpu_exp_plus_omega_contents, 24576ULL);
  cudaMalloc(&gpu_Temp, 114232ULL);
  gpuEmxReset_cuint8_T(&gpu_d);
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_cuint8_T(&d, 2, true);
  //     coder.gpu.iterations
  i = d->size[0] * d->size[1];
  d->size[0] = static_cast<int32_T>(Runge->s);
  d->size[1] = static_cast<int32_T>(2.0 * Temp->Space.N);
  emxEnsureCapacity_cuint8_T(d, i);
  gpuEmxEnsureCapacity_cuint8_T(d, &gpu_d);
  i = static_cast<int32_T>(Runge->s) *
          static_cast<int32_T>(2.0 * Temp->Space.N) -
      1;
  validLaunchParams = mwGetLaunchParameters1D(static_cast<real_T>(i + 1LL),
                                              &grid, &block, 1024U, 65535U);
  if (validLaunchParams) {
    Chi23_Runge_Kuarong_GPU_kernel1<<<grid, block>>>(i, gpu_d);
  }
  Par_dt = Temp->Par.dt;
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  cudaMemcpy(gpu_Temp, Temp, 114232ULL, cudaMemcpyHostToDevice);
  Chi23_Runge_Kuarong_GPU_kernel2<<<dim3(3U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
      Par_dt, gpu_Temp, *Runge, *gpu_exp_plus_omega_contents,
      *gpu_exp_minus_omega_contents);
  c_exp_plus_omega_contents_dirty = true;
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  Chi23_Runge_Kuarong_GPU_kernel3<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
      gpu_Temp, *gpu_F_e, *gpu_y);
  i = Sol->Psio->size[0] * Sol->Psio->size[1];
  Sol->Psio->size[0] = static_cast<int32_T>(Temp->Par.dd);
  Sol->Psio->size[1] = static_cast<int32_T>(Temp->Space.N);
  emxEnsureCapacity_creal_T(Sol->Psio, i);
  i = Sol->Psie->size[0] * Sol->Psie->size[1];
  Sol->Psie->size[0] = static_cast<int32_T>(Temp->Par.dd);
  Sol->Psie->size[1] = static_cast<int32_T>(Temp->Space.N);
  emxEnsureCapacity_creal_T(Sol->Psie, i);
  for (i = 0; i < static_cast<int32_T>(Temp->Par.dd) *
                      static_cast<int32_T>(Temp->Space.N);
       i++) {
    Sol->Psio->data[i].re = 0.0;
    Sol->Psio->data[i].im = 0.0;
    Sol->Psie->data[i].re = 0.0;
    Sol->Psie->data[i].im = 0.0;
  }
  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[0] = 1;
  Sol->t->size[1] = static_cast<int32_T>(Temp->Par.dd);
  emxEnsureCapacity_creal_T(Sol->t, i);
  for (i = 0; i < static_cast<int32_T>(Temp->Par.dd); i++) {
    Sol->t->data[i].re = 0.0;
    Sol->t->data[i].im = 0.0;
  }
  Chi23_Runge_Kuarong_GPU_kernel4<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
      gpu_Temp, gpu_i);
  cudaMemcpy(&b_i, gpu_i, 4ULL, cudaMemcpyDeviceToHost);
  if (0 <= b_i - 1) {
    fftDirection = CUFFT_INVERSE;
    fftType = CUFFT_Z2Z;
    b_fftDirection = CUFFT_INVERSE;
    b_fftType = CUFFT_Z2Z;
    c_fftDirection = CUFFT_FORWARD;
    c_fftType = CUFFT_Z2Z;
    d_fftDirection = CUFFT_FORWARD;
    d_fftType = CUFFT_Z2Z;
    e_fftDirection = CUFFT_FORWARD;
    e_fftType = CUFFT_Z2Z;
    f_fftDirection = CUFFT_FORWARD;
    f_fftType = CUFFT_Z2Z;
    iv[1] = d->size[1];
    i1 = static_cast<int32_T>(Runge->s + -1.0);
    i2 = static_cast<int32_T>(Runge->s);
    y = Temp->Par.s_t / Temp->Par.dt;
  }
  emxInit_creal_T(&b_d, 2, true);
  if (0 <= b_i - 1) {
    cudaMemcpy(exp_plus_omega_contents, *gpu_exp_plus_omega_contents, 24576ULL,
               cudaMemcpyDeviceToHost);
    ar = 256.0 * exp_plus_omega_contents[0].re;
    c_exp_plus_omega_contents_dirty = false;
    ai = 256.0 * exp_plus_omega_contents[0].im;
    if (ai == 0.0) {
      re = ar / 2.0;
      im = 0.0;
    } else if (ar == 0.0) {
      re = 0.0;
      im = ai / 2.0;
    } else {
      re = ar / 2.0;
      im = ai / 2.0;
    }
  }
  for (int32_T ni{0}; ni < b_i; ni++) {
    cufftHandle b_fftPlanHandle;
    cufftHandle c_fftPlanHandle;
    cufftHandle d_fftPlanHandle;
    cufftHandle e_fftPlanHandle;
    cufftHandle f_fftPlanHandle;
    cufftHandle fftPlanHandle;
    int32_T b_i2;
    int32_T inembed;
    i = b_d->size[0] * b_d->size[1];
    b_d->size[0] = d->size[0];
    b_d->size[1] = d->size[1];
    emxEnsureCapacity_creal_T(b_d, i);
    gpuEmxEnsureCapacity_creal_T(b_d, &b_gpu_d);
    i = d->size[0] * d->size[1] - 1;
    validLaunchParams = mwGetLaunchParameters1D(static_cast<real_T>(i + 1LL),
                                                &grid, &block, 1024U, 65535U);
    if (validLaunchParams) {
      Chi23_Runge_Kuarong_GPU_kernel5<<<grid, block>>>(gpu_d, i, b_gpu_d);
    }
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    Chi23_Runge_Kuarong_GPU_kernel6<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        *gpu_F_e, *gpu_E_temp);
    Chi23_Runge_Kuarong_GPU_kernel7<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_exp_minus_omega_contents, *gpu_F_e, *gpu_Psio);
    inembed = 256;
    fftPlanHandle = acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, fftType, 1);
    cufftExecZ2Z(fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psio)[0],
                 (cufftDoubleComplex *)&(*gpu_Psio)[0], fftDirection);
    Chi23_Runge_Kuarong_GPU_kernel8<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_exp_minus_omega_contents, *gpu_F_e, *gpu_Psie, *gpu_Psio);
    inembed = 256;
    b_fftPlanHandle =
        acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, b_fftType, 1);
    cufftExecZ2Z(b_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psie)[0],
                 (cufftDoubleComplex *)&(*gpu_Psie)[0], b_fftDirection);
    Chi23_Runge_Kuarong_GPU_kernel9<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psie);
    b_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        *gpu_k_e);
    c_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psie, *gpu_Psio, *gpu_x);
    inembed = 256;
    c_fftPlanHandle =
        acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, c_fftType, 1);
    cufftExecZ2Z(c_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_x)[0],
                 (cufftDoubleComplex *)&(*gpu_x)[0], c_fftDirection);
    d_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psie, *gpu_Psio, *b_gpu_x);
    inembed = 256;
    d_fftPlanHandle =
        acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, d_fftType, 1);
    cufftExecZ2Z(d_fftPlanHandle, (cufftDoubleComplex *)&(*b_gpu_x)[0],
                 (cufftDoubleComplex *)&(*b_gpu_x)[0], d_fftDirection);
    //
    e_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psio, *b_gpu_x, gpu_Temp, *gpu_exp_plus_omega_contents, *gpu_k_e,
        *gpu_x);
    inembed = 256;
    e_fftPlanHandle =
        acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, e_fftType, 1);
    cufftExecZ2Z(e_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_x)[0],
                 (cufftDoubleComplex *)&(*gpu_x)[0], e_fftDirection);
    f_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psio, *gpu_Psie);
    inembed = 256;
    f_fftPlanHandle =
        acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, f_fftType, 1);
    cufftExecZ2Z(f_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psie)[0],
                 (cufftDoubleComplex *)&(*gpu_Psie)[0], f_fftDirection);
    g_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
        *gpu_Psie, *gpu_x, gpu_Temp, *gpu_exp_plus_omega_contents, *gpu_k_e);
    //
    h_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
        im, re, gpu_Temp, *gpu_k_e);
    i = b_d->size[0];
    validLaunchParams = mwGetLaunchParameters1D(
        static_cast<real_T>((iv[1] - 1) + 1LL), &grid, &block, 1024U, 65535U);
    if (validLaunchParams) {
      i_Chi23_Runge_Kuarong_GPU_kerne<<<grid, block>>>(*gpu_k_e, iv[1] - 1, i,
                                                       b_gpu_d);
    }
    if (0 <= i1 - 1) {
      i3 = static_cast<int32_T>(Runge->s - 1.0);
      g_fftDirection = CUFFT_INVERSE;
      g_fftType = CUFFT_Z2Z;
      h_fftDirection = CUFFT_INVERSE;
      h_fftType = CUFFT_Z2Z;
      i_fftDirection = CUFFT_FORWARD;
      i_fftType = CUFFT_Z2Z;
      j_fftDirection = CUFFT_FORWARD;
      j_fftType = CUFFT_Z2Z;
      k_fftDirection = CUFFT_FORWARD;
      k_fftType = CUFFT_Z2Z;
      l_fftDirection = CUFFT_FORWARD;
      l_fftType = CUFFT_Z2Z;
    }
    for (b_i2 = 0; b_i2 < i1; b_i2++) {
      for (inembed = 0; inembed < i3; inembed++) {
        ar = Runge->b[(b_i2 + 3 * inembed) + 1];
        if (ar != 0.0) {
          ar *= Par_dt;
          i = b_d->size[0];
          j_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U),
                                            dim3(512U, 1U, 1U)>>>(
              b_gpu_d, inembed, ar, *gpu_E_temp, gpu_Temp, i, *b_gpu_E_temp);
          k_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U),
                                            dim3(512U, 1U, 1U)>>>(
              *b_gpu_E_temp, gpu_Temp, *gpu_E_temp);
        }
      }
      cufftHandle g_fftPlanHandle;
      cufftHandle h_fftPlanHandle;
      cufftHandle i_fftPlanHandle;
      cufftHandle j_fftPlanHandle;
      cufftHandle k_fftPlanHandle;
      cufftHandle l_fftPlanHandle;
      l_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_exp_minus_omega_contents, b_i2 + 1, *gpu_E_temp, *gpu_Psio);
      inembed = 256;
      g_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, g_fftType, 1);
      cufftExecZ2Z(g_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psio)[0],
                   (cufftDoubleComplex *)&(*gpu_Psio)[0], g_fftDirection);
      m_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_exp_minus_omega_contents, b_i2 + 1, *gpu_E_temp, *gpu_Psie,
          *gpu_Psio);
      inembed = 256;
      h_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, h_fftType, 1);
      cufftExecZ2Z(h_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psie)[0],
                   (cufftDoubleComplex *)&(*gpu_Psie)[0], h_fftDirection);
      n_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psie);
      o_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
          *gpu_k_e);
      p_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psie, *gpu_Psio, *gpu_x);
      inembed = 256;
      i_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, i_fftType, 1);
      cufftExecZ2Z(i_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_x)[0],
                   (cufftDoubleComplex *)&(*gpu_x)[0], i_fftDirection);
      q_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psie, *gpu_Psio, *b_gpu_x);
      inembed = 256;
      j_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, j_fftType, 1);
      cufftExecZ2Z(j_fftPlanHandle, (cufftDoubleComplex *)&(*b_gpu_x)[0],
                   (cufftDoubleComplex *)&(*b_gpu_x)[0], j_fftDirection);
      //
      r_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psio, *b_gpu_x, gpu_Temp, *gpu_exp_plus_omega_contents, b_i2 + 1,
          *gpu_k_e, *gpu_x);
      inembed = 256;
      k_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, k_fftType, 1);
      cufftExecZ2Z(k_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_x)[0],
                   (cufftDoubleComplex *)&(*gpu_x)[0], k_fftDirection);
      s_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psio, *gpu_Psie);
      inembed = 256;
      l_fftPlanHandle =
          acquireCUFFTPlan(1, &inembed, &inembed, 1, 1, l_fftType, 1);
      cufftExecZ2Z(l_fftPlanHandle, (cufftDoubleComplex *)&(*gpu_Psie)[0],
                   (cufftDoubleComplex *)&(*gpu_Psie)[0], l_fftDirection);
      t_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(256U, 1U, 1U)>>>(
          *gpu_Psie, *gpu_x, gpu_Temp, *gpu_exp_plus_omega_contents, b_i2 + 1,
          *gpu_k_e);
      //
      if (c_exp_plus_omega_contents_dirty) {
        cudaMemcpy(exp_plus_omega_contents, *gpu_exp_plus_omega_contents,
                   24576ULL, cudaMemcpyDeviceToHost);
      }
      ar = 256.0 * exp_plus_omega_contents[b_i2 + 1].re;
      c_exp_plus_omega_contents_dirty = false;
      ai = 256.0 * exp_plus_omega_contents[b_i2 + 1].im;
      if (ai == 0.0) {
        q = ar / 2.0;
        ar = 0.0;
      } else if (ar == 0.0) {
        q = 0.0;
        ar = ai / 2.0;
      } else {
        q = ar / 2.0;
        ar = ai / 2.0;
      }
      cudaMemcpy(gpu_q, &q, 8ULL, cudaMemcpyHostToDevice);
      u_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(32U, 1U, 1U)>>>(
          ar, gpu_q, gpu_Temp, *gpu_k_e);
      iv1[1] = b_d->size[1];
      i = b_d->size[0];
      validLaunchParams =
          mwGetLaunchParameters1D(static_cast<real_T>((iv1[1] - 1) + 1LL),
                                  &grid, &block, 1024U, 65535U);
      if (validLaunchParams) {
        v_Chi23_Runge_Kuarong_GPU_kerne<<<grid, block>>>(
            *gpu_k_e, b_i2 + 1, iv1[1] - 1, i, b_gpu_d);
      }
      w_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
          *gpu_F_e, *gpu_E_temp);
    }
    for (inembed = 0; inembed < i2; inembed++) {
      ar = Runge->c[inembed];
      if (ar != 0.0) {
        ar *= Par_dt;
        i = b_d->size[0];
        x_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U),
                                          dim3(512U, 1U, 1U)>>>(
            b_gpu_d, inembed, ar, *gpu_F_e, gpu_Temp, i, *b_gpu_E_temp);
        y_Chi23_Runge_Kuarong_GPU_kerne<<<dim3(1U, 1U, 1U),
                                          dim3(512U, 1U, 1U)>>>(
            *b_gpu_E_temp, gpu_Temp, *gpu_F_e);
      }
    }
    ab_Chi23_Runge_Kuarong_GPU_kern<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        *gpu_F_e, *gpu_y, gpu_Temp, *b_gpu_y);
    bb_Chi23_Runge_Kuarong_GPU_kern<<<dim3(1U, 1U, 1U), dim3(512U, 1U, 1U)>>>(
        *b_gpu_y, gpu_Temp, *gpu_F_e);
    validLaunchParams = true;
    // ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back
    ar = static_cast<real_T>(ni) + 1.0;
    if (!(y == 0.0)) {
      if (std::isnan(y)) {
        ar = rtNaN;
      } else if (std::isinf(y)) {
        if (y < 0.0) {
          ar = y;
        }
      } else {
        boolean_T rEQ0;
        ar = std::fmod(static_cast<real_T>(ni) + 1.0, y);
        rEQ0 = (ar == 0.0);
        if ((!rEQ0) && (y > std::floor(y))) {
          q = std::abs((static_cast<real_T>(ni) + 1.0) / y);
          rEQ0 =
              !(std::abs(q - std::floor(q + 0.5)) > 2.2204460492503131E-16 * q);
        }
        if (rEQ0) {
          ar = y * 0.0;
        } else if (y < 0.0) {
          ar += y;
        }
      }
    }
    if (ar == 0.0) {
      q = std::round((static_cast<real_T>(ni) + 1.0) * Temp->Par.dt /
                     Temp->Par.s_t);
      if (1.0 > Temp->Space.N) {
        inembed = 0;
      } else {
        inembed = static_cast<int32_T>(Temp->Space.N);
      }
      for (i = 0; i < inembed; i++) {
        if (validLaunchParams) {
          cudaMemcpy(F_e, *gpu_F_e, 8192ULL, cudaMemcpyDeviceToHost);
        }
        ar = F_e[i].re;
        validLaunchParams = false;
        ai = F_e[i].im;
        if (ai == 0.0) {
          Sol->Psio
              ->data[(static_cast<int32_T>(q) + Sol->Psio->size[0] * i) - 1]
              .re = ar / Temp->Space.N;
          Sol->Psio
              ->data[(static_cast<int32_T>(q) + Sol->Psio->size[0] * i) - 1]
              .im = 0.0;
        } else if (ar == 0.0) {
          Sol->Psio
              ->data[(static_cast<int32_T>(q) + Sol->Psio->size[0] * i) - 1]
              .re = 0.0;
          Sol->Psio
              ->data[(static_cast<int32_T>(q) + Sol->Psio->size[0] * i) - 1]
              .im = ai / Temp->Space.N;
        } else {
          Sol->Psio
              ->data[(static_cast<int32_T>(q) + Sol->Psio->size[0] * i) - 1]
              .re = ar / Temp->Space.N;
          Sol->Psio
              ->data[(static_cast<int32_T>(q) + Sol->Psio->size[0] * i) - 1]
              .im = ai / Temp->Space.N;
        }
      }
      ar = 2.0 * Temp->Space.N;
      if (Temp->Space.N + 1.0 > ar) {
        inembed = 0;
        b_i2 = 0;
      } else {
        inembed = static_cast<int32_T>(Temp->Space.N + 1.0) - 1;
        b_i2 = static_cast<int32_T>(ar);
      }
      for (i = 0; i < b_i2 - inembed; i++) {
        if (validLaunchParams) {
          cudaMemcpy(F_e, *gpu_F_e, 8192ULL, cudaMemcpyDeviceToHost);
        }
        ar = F_e[inembed + i].re;
        validLaunchParams = false;
        ai = F_e[inembed + i].im;
        if (ai == 0.0) {
          Sol->Psie
              ->data[(static_cast<int32_T>(q) + Sol->Psie->size[0] * i) - 1]
              .re = ar / Temp->Space.N;
          Sol->Psie
              ->data[(static_cast<int32_T>(q) + Sol->Psie->size[0] * i) - 1]
              .im = 0.0;
        } else if (ar == 0.0) {
          Sol->Psie
              ->data[(static_cast<int32_T>(q) + Sol->Psie->size[0] * i) - 1]
              .re = 0.0;
          Sol->Psie
              ->data[(static_cast<int32_T>(q) + Sol->Psie->size[0] * i) - 1]
              .im = ai / Temp->Space.N;
        } else {
          Sol->Psie
              ->data[(static_cast<int32_T>(q) + Sol->Psie->size[0] * i) - 1]
              .re = ar / Temp->Space.N;
          Sol->Psie
              ->data[(static_cast<int32_T>(q) + Sol->Psie->size[0] * i) - 1]
              .im = ai / Temp->Space.N;
        }
      }
      Sol->t->data[static_cast<int32_T>(q) - 1].re =
          Temp->Par.dt * (static_cast<real_T>(ni) + 1.0);
      Sol->t->data[static_cast<int32_T>(q) - 1].im = 0.0;
      //             if 10*log10(sum(abs(Sol.Psio(ind_s,2:end)).^2)) <= -100 &&
      //             (mod(ind_s,2) == 0)
      //                    Sol.Psio(ind_s+1:end,:) = [];
      //                   Sol.Psie(ind_s+1:end,:) = [];
      //                  Sol.t(ind_s+1:end)     = [];
      //                 break;
      //        end
    }
  }
  emxFree_creal_T(&b_d);
  emxFree_cuint8_T(&d);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
  gpuEmxFree_cuint8_T(&gpu_d);
  cudaFree(gpu_Temp);
  cudaFree(*gpu_exp_plus_omega_contents);
  cudaFree(*gpu_exp_minus_omega_contents);
  cudaFree(*gpu_F_e);
  cudaFree(*gpu_y);
  cudaFree(gpu_i);
  gpuEmxFree_creal_T(&b_gpu_d);
  cudaFree(*gpu_E_temp);
  cudaFree(*gpu_Psio);
  cudaFree(*gpu_Psie);
  cudaFree(*gpu_k_e);
  cudaFree(*gpu_x);
  cudaFree(*b_gpu_x);
  cudaFree(*b_gpu_y);
  cudaFree(*b_gpu_E_temp);
  cudaFree(gpu_q);
}

// End of code generation (Chi23_Runge_Kuarong_GPU.cu)
