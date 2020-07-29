/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Split_chi_2_api.cpp
 *
 * Code generation for function '_coder_Split_chi_2_api'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Split_chi_2.h"
#include "_coder_Split_chi_2_api.h"
#include "Split_chi_2_emxutil.h"
#include "Split_chi_2_data.h"

/* Variable Definitions */
static emlrtRTEInfo tb_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "_coder_Split_chi_2_api",            /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[32]);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *delta_o,
  const char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Runge, const
  char_T *identifier, struct0_T *y);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Psi_o_0, const
  char_T *identifier, creal_T y[32]);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct2_T u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Probes,
  const char_T *identifier, struct1_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[32]);
static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9]);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3]);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[32])
{
  k_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *delta_o,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(delta_o), &thisId);
  emlrtDestroyArray(&delta_o);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = l_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Runge, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(Runge), &thisId, y);
  emlrtDestroyArray(&Runge);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Psi_o_0, const
  char_T *identifier, creal_T y[32])
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(Psi_o_0), &thisId, y);
  emlrtDestroyArray(&Psi_o_0);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct2_T u)
{
  const mxArray *y;
  emxArray_real_T *b_u;
  static const char * sv0[3] = { "t", "Psi_o_k", "Psi_e_k" };

  int32_T i21;
  int32_T loop_ub;
  const mxArray *b_y;
  const mxArray *m0;
  real_T *pData;
  emxArray_creal_T *c_u;
  const mxArray *m1;
  const mxArray *m2;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &b_u, 2, (emlrtRTEInfo *)NULL, true);
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, *(const char * (*)[3])&sv0[0]));
  i21 = b_u->size[0] * b_u->size[1];
  b_u->size[0] = 1;
  b_u->size[1] = u.t->size[1];
  emxEnsureCapacity_real_T(sp, b_u, i21, (emlrtRTEInfo *)NULL);
  loop_ub = u.t->size[0] * u.t->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    b_u->data[i21] = u.t->data[i21];
  }

  b_y = NULL;
  m0 = emlrtCreateNumericArray(2, *(int32_T (*)[2])b_u->size, mxDOUBLE_CLASS,
    mxREAL);
  pData = emlrtMxGetPr(m0);
  i21 = 0;
  loop_ub = 0;
  emxFree_real_T(&b_u);
  while (loop_ub < u.t->size[1]) {
    pData[i21] = u.t->data[loop_ub];
    i21++;
    loop_ub++;
  }

  emxInit_creal_T(sp, &c_u, 2, (emlrtRTEInfo *)NULL, true);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "t", b_y, 0);
  i21 = c_u->size[0] * c_u->size[1];
  c_u->size[0] = u.Psi_o_k->size[0];
  c_u->size[1] = 4;
  emxEnsureCapacity_creal_T(sp, c_u, i21, (emlrtRTEInfo *)NULL);
  loop_ub = u.Psi_o_k->size[0] * u.Psi_o_k->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    c_u->data[i21] = u.Psi_o_k->data[i21];
  }

  b_y = NULL;
  m1 = emlrtCreateNumericArray(2, *(int32_T (*)[2])c_u->size, mxDOUBLE_CLASS,
    mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m1, &c_u->data[0], 8);
  emlrtAssign(&b_y, m1);
  emlrtSetFieldR2017b(y, 0, "Psi_o_k", b_y, 1);
  i21 = c_u->size[0] * c_u->size[1];
  c_u->size[0] = u.Psi_e_k->size[0];
  c_u->size[1] = 4;
  emxEnsureCapacity_creal_T(sp, c_u, i21, (emlrtRTEInfo *)NULL);
  loop_ub = u.Psi_e_k->size[0] * u.Psi_e_k->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    c_u->data[i21] = u.Psi_e_k->data[i21];
  }

  b_y = NULL;
  m2 = emlrtCreateNumericArray(2, *(int32_T (*)[2])c_u->size, mxDOUBLE_CLASS,
    mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m2, &c_u->data[0], 8);
  emlrtAssign(&b_y, m2);
  emlrtSetFieldR2017b(y, 0, "Psi_e_k", b_y, 2);
  emxFree_creal_T(&c_u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "b", "a", "c" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, (int32_T *)&dims);
  thisId.fIdentifier = "b";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "b")),
                     &thisId, y->b);
  thisId.fIdentifier = "a";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "a")),
                     &thisId, y->a);
  thisId.fIdentifier = "c";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "c")),
                     &thisId, y->c);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9])
{
  m_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3])
{
  n_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Probes,
  const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(Probes), &thisId, y);
  emlrtDestroyArray(&Probes);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[12] = { "omega_probe_o_1", "omega_probe_o_3",
    "omega_probe_e_2", "omega_probe_e_4", "h_prob_o_1", "h_prob_o_3",
    "h_prob_e_2", "h_prob_e_4", "mu_p_o_1", "mu_p_e_2", "mu_p_o_3", "mu_p_e_4" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 12, fieldNames, 0U, (int32_T *)&dims);
  thisId.fIdentifier = "omega_probe_o_1";
  y->omega_probe_o_1 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 0, "omega_probe_o_1")), &thisId);
  thisId.fIdentifier = "omega_probe_o_3";
  y->omega_probe_o_3 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 1, "omega_probe_o_3")), &thisId);
  thisId.fIdentifier = "omega_probe_e_2";
  y->omega_probe_e_2 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 2, "omega_probe_e_2")), &thisId);
  thisId.fIdentifier = "omega_probe_e_4";
  y->omega_probe_e_4 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp,
    u, 0, 3, "omega_probe_e_4")), &thisId);
  thisId.fIdentifier = "h_prob_o_1";
  y->h_prob_o_1 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    4, "h_prob_o_1")), &thisId);
  thisId.fIdentifier = "h_prob_o_3";
  y->h_prob_o_3 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    5, "h_prob_o_3")), &thisId);
  thisId.fIdentifier = "h_prob_e_2";
  y->h_prob_e_2 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    6, "h_prob_e_2")), &thisId);
  thisId.fIdentifier = "h_prob_e_4";
  y->h_prob_e_4 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    7, "h_prob_e_4")), &thisId);
  thisId.fIdentifier = "mu_p_o_1";
  y->mu_p_o_1 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    8, "mu_p_o_1")), &thisId);
  thisId.fIdentifier = "mu_p_e_2";
  y->mu_p_e_2 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    9, "mu_p_e_2")), &thisId);
  thisId.fIdentifier = "mu_p_o_3";
  y->mu_p_o_3 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    10, "mu_p_o_3")), &thisId);
  thisId.fIdentifier = "mu_p_e_4";
  y->mu_p_e_4 = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    11, "mu_p_e_4")), &thisId);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[32])
{
  static const int32_T dims[2] = { 1, 32 };

  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    true, 2U, *(int32_T (*)[2])&dims[0]);
  emlrtImportArrayR2015b(sp, src, ret, 8, true);
  emlrtDestroyArray(&src);
}

static real_T l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 0U, (int32_T *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2] = { 3, 3 };

  real_T (*r5)[9];
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 2U, *(int32_T (*)[2])&dims[0]);
  r5 = (real_T (*)[9])emlrtMxGetData(src);
  memcpy(&ret[0], &(*r5)[0], 9U * sizeof(real_T));
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims[2] = { 1, 3 };

  real_T (*r6)[3];
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 2U, *(int32_T (*)[2])&dims[0]);
  r6 = (real_T (*)[3])emlrtMxGetData(src);
  ret[0] = (*r6)[0];
  ret[1] = (*r6)[1];
  ret[2] = (*r6)[2];
  emlrtDestroyArray(&src);
}

void Split_chi_2_api(const mxArray * const prhs[20], int32_T, const mxArray
                     *plhs[1])
{
  struct2_T Temporal;
  creal_T Psi_o_0[32];
  creal_T Psi_e_0[32];
  real_T delta_o;
  real_T delta_e;
  real_T kappa_o;
  real_T kappa_e;
  real_T gamma_o;
  real_T gamma_e;
  real_T Pump;
  creal_T L_o[32];
  creal_T L_e[32];
  real_T dt;
  real_T nt;
  real_T NN;
  real_T Loops;
  real_T per_loop;
  real_T N;
  struct0_T Runge;
  struct1_T Probes;
  real_T t_start;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInitStruct_struct2_T(&st, &Temporal, &tb_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "Psi_o_0", Psi_o_0);
  emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "Psi_e_0", Psi_e_0);
  delta_o = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "delta_o");
  delta_e = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "delta_e");
  kappa_o = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "kappa_o");
  kappa_e = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "kappa_e");
  gamma_o = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "gamma_o");
  gamma_e = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "gamma_e");
  Pump = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "Pump");
  emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "L_o", L_o);
  emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "L_e", L_e);
  dt = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "dt");
  nt = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "nt");
  NN = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "NN");
  Loops = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "Loops");
  per_loop = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "per_loop");
  N = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[16]), "N");
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[17]), "Runge", &Runge);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[18]), "Probes", &Probes);
  t_start = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[19]), "t_start");

  /* Invoke the target function */
  Split_chi_2(&st, Psi_o_0, Psi_e_0, delta_o, delta_e, kappa_o, kappa_e, gamma_o,
              gamma_e, Pump, L_o, L_e, dt, nt, NN, Loops, per_loop, N, &Runge,
              &Probes, t_start, &Temporal);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, Temporal);
  emxFreeStruct_struct2_T(&Temporal);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_Split_chi_2_api.cpp) */
