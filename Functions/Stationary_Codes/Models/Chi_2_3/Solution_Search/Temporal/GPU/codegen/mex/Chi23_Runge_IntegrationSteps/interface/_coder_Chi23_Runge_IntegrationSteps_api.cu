//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_Chi23_Runge_IntegrationSteps_api.cu
//
// Code generation for function '_coder_Chi23_Runge_IntegrationSteps_api'
//

// Include files
#include "_coder_Chi23_Runge_IntegrationSteps_api.h"
#include "Chi23_Runge_IntegrationSteps.h"
#include "Chi23_Runge_IntegrationSteps_data.h"
#include "Chi23_Runge_IntegrationSteps_types.h"
#include "rt_nonfinite.h"

// Function Declarations
static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static real_T (*b_emlrt_marshallIn(const mxArray *mode_range,
                                   const char_T *identifier))[512];

static real_T (*b_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[512];

static void c_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9]);

static real_T c_emlrt_marshallIn(const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void d_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[3]);

static real_T (*d_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[512];

static real_T emlrt_marshallIn(const mxArray *nt, const char_T *identifier);

static void emlrt_marshallIn(const mxArray *Runge, const char_T *identifier,
                             struct0_T *y);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T *y);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[9]);

static real_T emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

// Function Definitions
static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3])
{
  d_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*b_emlrt_marshallIn(const mxArray *mode_range,
                                   const char_T *identifier))[512]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[512];
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(emlrtAlias(mode_range), &thisId);
  emlrtDestroyArray(&mode_range);
  return y;
}

static real_T (*b_emlrt_marshallIn(const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[512]
{
  real_T(*y)[512];
  y = d_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void c_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2]{3, 3};
  real_T(*r)[9];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 2U,
                          (void *)&dims[0]);
  r = (real_T(*)[9])emlrtMxGetData(src);
  for (int32_T i{0}; i < 9; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static real_T c_emlrt_marshallIn(const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void d_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims[2]{1, 3};
  real_T(*r)[3];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 2U,
                          (void *)&dims[0]);
  r = (real_T(*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

static real_T (*d_emlrt_marshallIn(const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[512]
{
  static const int32_T dims[2]{1, 512};
  real_T(*ret)[512];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 2U,
                          (void *)&dims[0]);
  ret = (real_T(*)[512])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const mxArray *nt, const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  y = emlrt_marshallIn(emlrtAlias(nt), &thisId);
  emlrtDestroyArray(&nt);
  return y;
}

static void emlrt_marshallIn(const mxArray *Runge, const char_T *identifier,
                             struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(emlrtAlias(Runge), &thisId, y);
  emlrtDestroyArray(&Runge);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[4]{"b", "a", "c", "s"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 4,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "b";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
                                                  (const char_T *)"b")),
                   &thisId, y->b);
  thisId.fIdentifier = "a";
  b_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
                                                    (const char_T *)"a")),
                     &thisId, y->a);
  thisId.fIdentifier = "c";
  b_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
                                                    (const char_T *)"c")),
                     &thisId, y->c);
  thisId.fIdentifier = "s";
  y->s =
      emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0,
                                                      3, (const char_T *)"s")),
                       &thisId);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[9])
{
  c_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

void c_Chi23_Runge_IntegrationSteps_(const mxArray *const prhs[14],
                                     const mxArray *plhs[1])
{
  static const int32_T b_dims[2]{1, 512};
  static const int32_T c_dims[2]{3, 512};
  static const int32_T d_dims[2]{3, 512};
  static const int32_T dims[2]{3, 512};
  static const int32_T e_dims[2]{1, 512};
  static const int32_T f_dims[2]{1, 256};
  static const int32_T g_dims[2]{1, 256};
  static const int32_T h_dims[2]{1, 256};
  static const int32_T i_dims[2]{1, 256};
  static const int32_T j_dims[2]{1, 512};
  const mxGPUArray *F_e_gpu;
  const mxGPUArray *H_f_gpu;
  const mxGPUArray *d_gpu;
  const mxGPUArray *exp_minus_omega_gpu;
  const mxGPUArray *exp_plus_omega_gpu;
  const mxGPUArray *gam2e_gpu;
  const mxGPUArray *gam2o_gpu;
  const mxGPUArray *gam3e_gpu;
  const mxGPUArray *gam3o_gpu;
  const mxGPUArray *shift_back_gpu;
  struct0_T Runge;
  creal_T(*d)[1536];
  creal_T(*exp_minus_omega)[1536];
  creal_T(*exp_plus_omega)[1536];
  creal_T(*F_e)[512];
  creal_T(*shift_back)[512];
  real_T(*H_f)[512];
  real_T(*mode_range)[512];
  real_T(*gam2e)[256];
  real_T(*gam2o)[256];
  real_T(*gam3e)[256];
  real_T(*gam3o)[256];
  real_T dt;
  real_T nt;
  emlrtInitGPU(emlrtRootTLSGlobal);
  // Marshall function inputs
  nt = emlrt_marshallIn(emlrtAliasP(prhs[0]), "nt");
  dt = emlrt_marshallIn(emlrtAliasP(prhs[1]), "dt");
  d_gpu = emlrt_marshallInGPU(emlrtRootTLSGlobal, prhs[2], (const char_T *)"d",
                              (const char_T *)"double", true, 2,
                              (void *)&dims[0], false);
  d = (creal_T(*)[1536])emlrtGPUGetDataReadOnly(d_gpu);
  F_e_gpu = emlrt_marshallInGPU(emlrtRootTLSGlobal, prhs[3],
                                (const char_T *)"F_e", (const char_T *)"double",
                                true, 2, (void *)&b_dims[0], false);
  F_e = (creal_T(*)[512])emlrtGPUGetDataReadOnly(F_e_gpu);
  exp_plus_omega_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[4], (const char_T *)"exp_plus_omega",
      (const char_T *)"double", true, 2, (void *)&c_dims[0], false);
  exp_plus_omega =
      (creal_T(*)[1536])emlrtGPUGetDataReadOnly(exp_plus_omega_gpu);
  exp_minus_omega_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[5], (const char_T *)"exp_minus_omega",
      (const char_T *)"double", true, 2, (void *)&d_dims[0], false);
  exp_minus_omega =
      (creal_T(*)[1536])emlrtGPUGetDataReadOnly(exp_minus_omega_gpu);
  emlrt_marshallIn(emlrtAliasP(prhs[6]), "Runge", &Runge);
  shift_back_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[7], (const char_T *)"shift_back",
      (const char_T *)"double", true, 2, (void *)&e_dims[0], false);
  shift_back = (creal_T(*)[512])emlrtGPUGetDataReadOnly(shift_back_gpu);
  gam2o_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[8], (const char_T *)"gam2o",
      (const char_T *)"double", false, 2, (void *)&f_dims[0], true);
  gam2o = (real_T(*)[256])emlrtGPUGetDataReadOnly(gam2o_gpu);
  gam2e_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[9], (const char_T *)"gam2e",
      (const char_T *)"double", false, 2, (void *)&g_dims[0], true);
  gam2e = (real_T(*)[256])emlrtGPUGetDataReadOnly(gam2e_gpu);
  gam3o_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[10], (const char_T *)"gam3o",
      (const char_T *)"double", false, 2, (void *)&h_dims[0], true);
  gam3o = (real_T(*)[256])emlrtGPUGetDataReadOnly(gam3o_gpu);
  gam3e_gpu = emlrt_marshallInGPU(
      emlrtRootTLSGlobal, prhs[11], (const char_T *)"gam3e",
      (const char_T *)"double", false, 2, (void *)&i_dims[0], true);
  gam3e = (real_T(*)[256])emlrtGPUGetDataReadOnly(gam3e_gpu);
  H_f_gpu = emlrt_marshallInGPU(emlrtRootTLSGlobal, prhs[12],
                                (const char_T *)"H_f", (const char_T *)"double",
                                false, 2, (void *)&j_dims[0], true);
  H_f = (real_T(*)[512])emlrtGPUGetDataReadOnly(H_f_gpu);
  mode_range = b_emlrt_marshallIn(emlrtAlias(prhs[13]), "mode_range");
  // Invoke the target function
  Chi23_Runge_IntegrationSteps(nt, dt, *d, *F_e, *exp_plus_omega,
                               *exp_minus_omega, &Runge, *shift_back, *gam2o,
                               *gam2e, *gam3o, *gam3e, *H_f, *mode_range);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOutGPU(F_e_gpu);
  // Destroy GPUArrays
  emlrtDestroyGPUArray(d_gpu);
  emlrtDestroyGPUArray(F_e_gpu);
  emlrtDestroyGPUArray(exp_plus_omega_gpu);
  emlrtDestroyGPUArray(exp_minus_omega_gpu);
  emlrtDestroyGPUArray(shift_back_gpu);
  emlrtDestroyGPUArray(gam2o_gpu);
  emlrtDestroyGPUArray(gam2e_gpu);
  emlrtDestroyGPUArray(gam3o_gpu);
  emlrtDestroyGPUArray(gam3e_gpu);
  emlrtDestroyGPUArray(H_f_gpu);
}

// End of code generation (_coder_Chi23_Runge_IntegrationSteps_api.cu)
