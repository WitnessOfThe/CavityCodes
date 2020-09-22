/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Chi_3_LLE_Kuar_api.c
 *
 * Code generation for function '_coder_Chi_3_LLE_Kuar_api'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Kuar.h"
#include "_coder_Chi_3_LLE_Kuar_api.h"
#include "Chi_3_LLE_Kuar_data.h"

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[1024]);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *t, const
  char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Eq, const
  char_T *identifier, struct0_T *y);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *F_Psi, const
  char_T *identifier, creal_T y[1024]);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u
  [1024]);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[1024]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[600]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[1024]);
static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[1024]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[600]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[1024])
{
  j_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *t, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(t), &thisId);
  emlrtDestroyArray(&t);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = k_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Eq, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(Eq), &thisId, y);
  emlrtDestroyArray(&Eq);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *F_Psi, const
  char_T *identifier, creal_T y[1024])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(F_Psi), &thisId, y);
  emlrtDestroyArray(&F_Psi);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const creal_T u
  [1024])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 1, 1024 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m0, (void *)&u[0], 8);
  emlrtAssign(&y, m0);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[12] = { "delta", "kappa", "gamma_3", "D", "h",
    "omega_j", "gamma_Kerr", "mask", "kappa_vector", "mode_range", "L", "norm" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 12, fieldNames, 0U, &dims);
  thisId.fIdentifier = "delta";
  y->delta = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "delta")), &thisId);
  thisId.fIdentifier = "kappa";
  y->kappa = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "kappa")), &thisId);
  thisId.fIdentifier = "gamma_3";
  y->gamma_3 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "gamma_3")), &thisId);
  thisId.fIdentifier = "D";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "D")),
                     &thisId, y->D);
  thisId.fIdentifier = "h";
  y->h = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "h")),
    &thisId);
  thisId.fIdentifier = "omega_j";
  b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "omega_j")),
                     &thisId, y->omega_j);
  thisId.fIdentifier = "gamma_Kerr";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "gamma_Kerr")), &thisId, y->gamma_Kerr);
  thisId.fIdentifier = "mask";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7, "mask")),
                     &thisId, y->mask);
  thisId.fIdentifier = "kappa_vector";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "kappa_vector")), &thisId, y->kappa_vector);
  thisId.fIdentifier = "mode_range";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "mode_range")), &thisId, y->mode_range);
  thisId.fIdentifier = "L";
  b_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10, "L")),
                     &thisId, y->L);
  thisId.fIdentifier = "norm";
  y->norm = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "norm")), &thisId);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[4])
{
  l_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[1024])
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[600])
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[1024])
{
  static const int32_T dims[2] = { 1, 1024 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", true, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 8, true);
  emlrtDestroyArray(&src);
}

static real_T k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[4])
{
  static const int32_T dims[2] = { 1, 4 };

  real_T (*r0)[4];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r0 = (real_T (*)[4])emlrtMxGetData(src);
  ret[0] = (*r0)[0];
  ret[1] = (*r0)[1];
  ret[2] = (*r0)[2];
  ret[3] = (*r0)[3];
  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[1024])
{
  static const int32_T dims[2] = { 1, 1024 };

  real_T (*r1)[1024];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r1 = (real_T (*)[1024])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r1)[0], sizeof(real_T) << 10);
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[600])
{
  static const int32_T dims[2] = { 1, 600 };

  real_T (*r2)[600];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r2 = (real_T (*)[600])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r2)[0], 600U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

void Chi_3_LLE_Kuar_api(const mxArray * const prhs[5], int32_T nlhs, const
  mxArray *plhs[1])
{
  creal_T F_Psi[1024];
  creal_T Fac_plus[1024];
  creal_T Fac_minus[1024];
  real_T t;
  struct0_T Eq;
  creal_T k_e[1024];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "F_Psi", F_Psi);
  emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "Fac_plus", Fac_plus);
  emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "Fac_minus", Fac_minus);
  t = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "t");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "Eq", &Eq);

  /* Invoke the target function */
  Chi_3_LLE_Kuar(&st, F_Psi, Fac_plus, Fac_minus, t, &Eq, k_e);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, k_e);
}

/* End of code generation (_coder_Chi_3_LLE_Kuar_api.c) */
