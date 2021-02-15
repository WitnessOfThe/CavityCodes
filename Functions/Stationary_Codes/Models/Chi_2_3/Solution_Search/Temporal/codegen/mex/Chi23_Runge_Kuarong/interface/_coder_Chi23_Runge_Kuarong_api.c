/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Chi23_Runge_Kuarong_api.c
 *
 * Code generation for function '_coder_Chi23_Runge_Kuarong_api'
 *
 */

/* Include files */
#include "_coder_Chi23_Runge_Kuarong_api.h"
#include "Chi23_Runge_Kuarong.h"
#include "Chi23_Runge_Kuarong_data.h"
#include "Chi23_Runge_Kuarong_emxutil.h"
#include "Chi23_Runge_Kuarong_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo j_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_Chi23_Runge_Kuarong_api",    /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[256]);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[512]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[256]);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9]);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Temp, const
  char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct6_T u);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static creal_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[512]);
static struct2_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[12]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[256]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct4_T *y);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[512]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[256]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Runge, const
  char_T *identifier, struct5_T *y);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct5_T *y);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9]);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);
static creal_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[512]);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[12]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[256])
{
  static const int32_T dims[2] = { 1, 256 };

  real_T (*r)[256];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[256])emlrtMxGetData(src);
  for (i = 0; i < 256; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[5] = { "Met", "In", "Par", "Space", "Eq" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 5, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Met";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "Met")),
                     &thisId);
  thisId.fIdentifier = "In";
  d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "In")),
                     &thisId, &y->In);
  thisId.fIdentifier = "Par";
  y->Par = i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "Par")), &thisId);
  thisId.fIdentifier = "Space";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "Space")),
                     &thisId, &y->Space);
  thisId.fIdentifier = "Eq";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "Eq")),
                     &thisId, &y->Eq);
  emlrtDestroyArray(&u);
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[512])
{
  static const int32_T dims[2] = { 1, 512 };

  real_T (*r)[512];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[512])emlrtMxGetData(src);
  for (i = 0; i < 512; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[256])
{
  static const int32_T dims[2] = { 1, 256 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", true, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 8, true);
  emlrtDestroyArray(&src);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[24] = { "eta", "ko", "ke", "gam2o", "gam2e",
    "gam3o", "gam3e", "Do", "De", "Finess", "H_Star", "W_Star", "Omega_Star",
    "eps", "delta_o", "N", "W", "delta", "delta_e", "H", "Omega_f", "Omega_s",
    "Psi_Start", "t_start" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 24, fieldNames, 0U, &dims);
  thisId.fIdentifier = "eta";
  y->eta = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "eta")), &thisId);
  thisId.fIdentifier = "ko";
  y->ko = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "ko")), &thisId);
  thisId.fIdentifier = "ke";
  y->ke = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "ke")), &thisId);
  thisId.fIdentifier = "gam2o";
  y->gam2o = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "gam2o")), &thisId);
  thisId.fIdentifier = "gam2e";
  y->gam2e = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "gam2e")), &thisId);
  thisId.fIdentifier = "gam3o";
  y->gam3o = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5,
    "gam3o")), &thisId);
  thisId.fIdentifier = "gam3e";
  y->gam3e = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "gam3e")), &thisId);
  thisId.fIdentifier = "Do";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7, "Do")),
                     &thisId, y->Do);
  thisId.fIdentifier = "De";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8, "De")),
                     &thisId, y->De);
  thisId.fIdentifier = "Finess";
  y->Finess = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "Finess")), &thisId);
  thisId.fIdentifier = "H_Star";
  y->H_Star = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "H_Star")), &thisId);
  thisId.fIdentifier = "W_Star";
  y->W_Star = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "W_Star")), &thisId);
  thisId.fIdentifier = "Omega_Star";
  y->Omega_Star = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    12, "Omega_Star")), &thisId);
  thisId.fIdentifier = "eps";
  y->eps = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13,
    "eps")), &thisId);
  thisId.fIdentifier = "delta_o";
  y->delta_o = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    14, "delta_o")), &thisId);
  thisId.fIdentifier = "N";
  y->N = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 15, "N")),
    &thisId);
  thisId.fIdentifier = "W";
  y->W = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 16, "W")),
    &thisId);
  thisId.fIdentifier = "delta";
  y->delta = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17,
    "delta")), &thisId);
  thisId.fIdentifier = "delta_e";
  y->delta_e = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    18, "delta_e")), &thisId);
  thisId.fIdentifier = "H";
  y->H = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 19, "H")),
    &thisId);
  thisId.fIdentifier = "Omega_f";
  y->Omega_f = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    20, "Omega_f")), &thisId);
  thisId.fIdentifier = "Omega_s";
  y->Omega_s = g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    21, "Omega_s")), &thisId);
  thisId.fIdentifier = "Psi_Start";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 22,
    "Psi_Start")), &thisId, y->Psi_Start);
  thisId.fIdentifier = "t_start";
  y->t_start = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    23, "t_start")), &thisId);
  emlrtDestroyArray(&u);
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9])
{
  static const int32_T dims[2] = { 3, 3 };

  real_T (*r)[9];
  int32_T i;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[9])emlrtMxGetData(src);
  for (i = 0; i < 9; i++) {
    ret[i] = (*r)[i];
  }

  emlrtDestroyArray(&src);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3])
{
  static const int32_T dims[2] = { 1, 3 };

  real_T (*r)[3];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[3])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  ret[2] = (*r)[2];
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Temp, const
  char_T *identifier, struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(Temp), &thisId, y);
  emlrtDestroyArray(&Temp);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct6_T u)
{
  static const char_T *sv[3] = { "Psio", "Psie", "t" };

  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, sv));
  b_y = NULL;
  iv[0] = u.Psio->size[0];
  iv[1] = u.Psio->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m, &u.Psio->data[0], 8);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "Psio", b_y, 0);
  c_y = NULL;
  iv[0] = u.Psie->size[0];
  iv[1] = u.Psie->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m, &u.Psie->data[0], 8);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "Psie", c_y, 1);
  d_y = NULL;
  iv[0] = u.t->size[0];
  iv[1] = u.t->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m, &u.t->data[0], 8);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, "t", d_y, 2);
  return y;
}

static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static creal_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  creal_T y;
  y = w_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[512])
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static struct2_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[6] = { "Runge_Type", "dt", "s_t", "T", "dd",
    "CW_num" };

  emlrtMsgIdentifier thisId;
  struct2_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 6, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Runge_Type";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "Runge_Type")), &thisId, y.Runge_Type);
  thisId.fIdentifier = "dt";
  y.dt = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "dt")),
    &thisId);
  thisId.fIdentifier = "s_t";
  y.s_t = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "s_t")), &thisId);
  thisId.fIdentifier = "T";
  y.T = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "T")),
    &thisId);
  thisId.fIdentifier = "dd";
  y.dd = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "dd")),
    &thisId);
  thisId.fIdentifier = "CW_num";
  y.CW_num = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5,
    "CW_num")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[12])
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[6] = { "N", "lenght", "dphi", "phi", "dk", "k"
  };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 6, fieldNames, 0U, &dims);
  thisId.fIdentifier = "N";
  y->N = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "N")),
    &thisId);
  thisId.fIdentifier = "lenght";
  y->lenght = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "lenght")), &thisId);
  thisId.fIdentifier = "dphi";
  y->dphi = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "dphi")), &thisId);
  thisId.fIdentifier = "phi";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "phi")),
                     &thisId, y->phi);
  thisId.fIdentifier = "dk";
  y->dk = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "dk")), &thisId);
  thisId.fIdentifier = "k";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "k")),
                     &thisId, y->k);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[256])
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct4_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[18] = { "H", "delta_o", "delta_e", "eps", "ko",
    "ke", "gam2o", "gam2e", "gam3o", "gam3e", "Do", "De", "d", "norm",
    "mode_range", "Lo", "Le", "L" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 18, fieldNames, 0U, &dims);
  thisId.fIdentifier = "H";
  y->H = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "H")),
    &thisId);
  thisId.fIdentifier = "delta_o";
  y->delta_o = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "delta_o")), &thisId);
  thisId.fIdentifier = "delta_e";
  y->delta_e = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "delta_e")), &thisId);
  thisId.fIdentifier = "eps";
  y->eps = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "eps")), &thisId);
  thisId.fIdentifier = "ko";
  y->ko = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "ko")), &thisId);
  thisId.fIdentifier = "ke";
  y->ke = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5,
    "ke")), &thisId);
  thisId.fIdentifier = "gam2o";
  y->gam2o = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "gam2o")), &thisId);
  thisId.fIdentifier = "gam2e";
  y->gam2e = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "gam2e")), &thisId);
  thisId.fIdentifier = "gam3o";
  y->gam3o = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "gam3o")), &thisId);
  thisId.fIdentifier = "gam3e";
  y->gam3e = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "gam3e")), &thisId);
  thisId.fIdentifier = "Do";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10, "Do")),
                     &thisId, y->Do);
  thisId.fIdentifier = "De";
  f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11, "De")),
                     &thisId, y->De);
  thisId.fIdentifier = "d";
  y->d = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12, "d")),
    &thisId);
  thisId.fIdentifier = "norm";
  y->norm = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13,
    "norm")), &thisId);
  thisId.fIdentifier = "mode_range";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 14,
    "mode_range")), &thisId, y->mode_range);
  thisId.fIdentifier = "Lo";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 15, "Lo")),
                     &thisId, y->Lo);
  thisId.fIdentifier = "Le";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 16, "Le")),
                     &thisId, y->Le);
  thisId.fIdentifier = "L";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 17, "L")),
                     &thisId, y->L);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[512])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[256])
{
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Runge, const
  char_T *identifier, struct5_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  q_emlrt_marshallIn(sp, emlrtAlias(Runge), &thisId, y);
  emlrtDestroyArray(&Runge);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct5_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[4] = { "b", "a", "c", "s" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 4, fieldNames, 0U, &dims);
  thisId.fIdentifier = "b";
  r_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "b")),
                     &thisId, y->b);
  thisId.fIdentifier = "a";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "a")),
                     &thisId, y->a);
  thisId.fIdentifier = "c";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "c")),
                     &thisId, y->c);
  thisId.fIdentifier = "s";
  y->s = e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "s")),
    &thisId);
  emlrtDestroyArray(&u);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9])
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3])
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static real_T u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = { 1, 2 };

  real_T (*r)[2];
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  r = (real_T (*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static creal_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  creal_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", true, 0U, &dims);
  emlrtImportArrayR2015b(sp, src, &ret, 8, true);
  emlrtDestroyArray(&src);
  return ret;
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[512])
{
  static const int32_T dims[2] = { 1, 512 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", true, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 8, true);
  emlrtDestroyArray(&src);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[12])
{
  static const int32_T dims[2] = { 1, 12 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 12);
  emlrtDestroyArray(&src);
}

void Chi23_Runge_Kuarong_api(const mxArray * const prhs[2], const mxArray *plhs
  [1])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  struct0_T Temp;
  struct5_T Runge;
  struct6_T Sol;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInitStruct_struct6_T(&st, &Sol, &j_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "Temp", &Temp);
  p_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "Runge", &Runge);

  /* Invoke the target function */
  Chi23_Runge_Kuarong(&st, &Temp, &Runge, &Sol);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, Sol);
  emxFreeStruct_struct6_T(&Sol);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_Chi23_Runge_Kuarong_api.c) */
