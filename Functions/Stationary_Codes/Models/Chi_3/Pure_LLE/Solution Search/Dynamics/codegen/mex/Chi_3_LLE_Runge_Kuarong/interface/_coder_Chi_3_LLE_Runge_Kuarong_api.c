/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Chi_3_LLE_Runge_Kuarong_api.c
 *
 * Code generation for function '_coder_Chi_3_LLE_Runge_Kuarong_api'
 *
 */

/* Include files */
#include "_coder_Chi_3_LLE_Runge_Kuarong_api.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"
#include "Chi_3_LLE_Runge_Kuarong_emxutil.h"
#include "Chi_3_LLE_Runge_Kuarong_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo ob_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "_coder_Chi_3_LLE_Runge_Kuarong_api",/* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[256]);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2]);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2]);
static struct1_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret_data[], int32_T ret_size[2]);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[12]);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2]);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *Temp, const
  char_T *identifier, struct0_T *y);
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const struct6_T u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[9]);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y);
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[3]);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[256]);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2]);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[256]);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct3_T *y);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2]);
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct4_T *y);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2]);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y_data[], int32_T y_size[2]);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2]);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Runge, const
  char_T *identifier, struct5_T *y);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct5_T *y);
static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9]);
static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3]);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[12]);
static real_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[256]);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret[2]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret[256])
{
  static const int32_T dims[2] = { 1, 256 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", true, 2U, dims);
  emlrtImportArrayR2015b(sp, src, ret, 8, true);
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[5] = { "Met", "Par", "In", "Space", "Eq" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 5, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Met";
  c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "Met")),
                     &thisId);
  thisId.fIdentifier = "Par";
  y->Par = d_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "Par")), &thisId);
  thisId.fIdentifier = "In";
  g_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "In")),
                     &thisId, &y->In);
  thisId.fIdentifier = "Space";
  k_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "Space")),
                     &thisId, &y->Space);
  thisId.fIdentifier = "Eq";
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "Eq")),
                     &thisId, &y->Eq);
  emlrtDestroyArray(&u);
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = { 1, 1024 };

  int32_T iv[2];
  const boolean_T bv[2] = { false, true };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b(sp, src, (void *)ret_data, 8, false);
  emlrtDestroyArray(&src);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = { 1, 6 };

  int32_T iv[2];
  const boolean_T bv[2] = { false, true };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b(sp, src, (void *)ret_data, 8, false);
  emlrtDestroyArray(&src);
}

static struct1_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[6] = { "Runge_Type", "dt", "s_t", "T", "dd",
    "CW_num" };

  emlrtMsgIdentifier thisId;
  struct1_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 6, fieldNames, 0U, &dims);
  thisId.fIdentifier = "Runge_Type";
  e_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "Runge_Type")), &thisId, y.Runge_Type);
  thisId.fIdentifier = "dt";
  y.dt = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "dt")),
    &thisId);
  thisId.fIdentifier = "s_t";
  y.s_t = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "s_t")), &thisId);
  thisId.fIdentifier = "T";
  y.T = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "T")),
    &thisId);
  thisId.fIdentifier = "dd";
  y.dd = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "dd")),
    &thisId);
  thisId.fIdentifier = "CW_num";
  y.CW_num = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5,
    "CW_num")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, creal_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = { 1, 1024 };

  int32_T iv[2];
  const boolean_T bv[2] = { false, true };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", true, 2U, dims, &bv[0], iv);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b(sp, src, (void *)ret_data, 8, true);
  emlrtDestroyArray(&src);
}

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, char_T y[12])
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, real_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = { 1, 600 };

  int32_T iv[2];
  const boolean_T bv[2] = { false, true };

  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv[0],
    iv);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b(sp, src, (void *)ret_data, 8, false);
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
  static const char_T *sv[2] = { "Psi", "t" };

  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 2, sv));
  b_y = NULL;
  iv[0] = u.Psi->size[0];
  iv[1] = u.Psi->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m, &u.Psi->data[0], 8);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, "Psi", b_y, 0);
  c_y = NULL;
  iv[0] = u.t->size[0];
  iv[1] = u.t->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m, &u.t->data[0], 8);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, "t", c_y, 1);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = w_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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

static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct2_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[20] = { "eta", "omega", "omega_p", "D",
    "omega_int", "gamma", "range", "N_mode", "mu_bl", "kappa", "delta", "P",
    "Finess", "Fin_D", "H", "W", "W_Star", "W_WStar", "Psi_Start", "t_start" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 20, fieldNames, 0U, &dims);
  thisId.fIdentifier = "eta";
  y->eta = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "eta")), &thisId);
  thisId.fIdentifier = "omega";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "omega")),
                     &thisId, y->omega);
  thisId.fIdentifier = "omega_p";
  y->omega_p = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "omega_p")), &thisId);
  thisId.fIdentifier = "D";
  i_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "D")),
                     &thisId, y->D);
  thisId.fIdentifier = "omega_int";
  h_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "omega_int")),
                     &thisId, y->omega_int);
  thisId.fIdentifier = "gamma";
  y->gamma = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5,
    "gamma")), &thisId);
  thisId.fIdentifier = "range";
  y->range = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "range")), &thisId);
  thisId.fIdentifier = "N_mode";
  y->N_mode = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "N_mode")), &thisId);
  thisId.fIdentifier = "mu_bl";
  y->mu_bl = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "mu_bl")), &thisId);
  thisId.fIdentifier = "kappa";
  y->kappa = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "kappa")), &thisId);
  thisId.fIdentifier = "delta";
  y->delta = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "delta")), &thisId);
  thisId.fIdentifier = "P";
  y->P = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11, "P")),
    &thisId);
  thisId.fIdentifier = "Finess";
  y->Finess = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12,
    "Finess")), &thisId);
  thisId.fIdentifier = "Fin_D";
  y->Fin_D = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 13,
    "Fin_D")), &thisId);
  thisId.fIdentifier = "H";
  y->H = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 14, "H")),
    &thisId);
  thisId.fIdentifier = "W";
  y->W = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 15, "W")),
    &thisId);
  thisId.fIdentifier = "W_Star";
  y->W_Star = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 16,
    "W_Star")), &thisId);
  thisId.fIdentifier = "W_WStar";
  y->W_WStar = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    17, "W_WStar")), &thisId);
  thisId.fIdentifier = "Psi_Start";
  j_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 18,
    "Psi_Start")), &thisId, y->Psi_Start);
  thisId.fIdentifier = "t_start";
  y->t_start = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    19, "t_start")), &thisId);
  emlrtDestroyArray(&u);
}

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[256])
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[2])
{
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y[256])
{
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
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
  y->N = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "N")),
    &thisId);
  thisId.fIdentifier = "lenght";
  y->lenght = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "lenght")), &thisId);
  thisId.fIdentifier = "dphi";
  y->dphi = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "dphi")), &thisId);
  thisId.fIdentifier = "phi";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "phi")),
                     &thisId, y->phi.data, y->phi.size);
  thisId.fIdentifier = "dk";
  y->dk = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "dk")), &thisId);
  thisId.fIdentifier = "k";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "k")),
                     &thisId, y->k.data, y->k.size);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2])
{
  bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct4_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[12] = { "delta", "kappa", "gamma_3", "D", "h",
    "omega_j", "gamma_Kerr", "mask", "kappa_vector", "mode_range", "L", "norm" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 12, fieldNames, 0U, &dims);
  thisId.fIdentifier = "delta";
  y->delta = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "delta")), &thisId);
  thisId.fIdentifier = "kappa";
  y->kappa = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "kappa")), &thisId);
  thisId.fIdentifier = "gamma_3";
  y->gamma_3 = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "gamma_3")), &thisId);
  thisId.fIdentifier = "D";
  n_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "D")),
                     &thisId, y->D.data, y->D.size);
  thisId.fIdentifier = "h";
  y->h = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4, "h")),
    &thisId);
  thisId.fIdentifier = "omega_j";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5, "omega_j")),
                     &thisId, y->omega_j.data, y->omega_j.size);
  thisId.fIdentifier = "gamma_Kerr";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "gamma_Kerr")), &thisId, y->gamma_Kerr.data, y->gamma_Kerr.size);
  thisId.fIdentifier = "mask";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7, "mask")),
                     &thisId, y->mask.data, y->mask.size);
  thisId.fIdentifier = "kappa_vector";
  l_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "kappa_vector")), &thisId, y->kappa_vector.data, y->kappa_vector.size);
  thisId.fIdentifier = "mode_range";
  p_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "mode_range")), &thisId, y->mode_range.data, y->mode_range.size);
  thisId.fIdentifier = "L";
  o_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10, "L")),
                     &thisId, y->L.data, y->L.size);
  thisId.fIdentifier = "norm";
  y->norm = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "norm")), &thisId);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2])
{
  cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, creal_T y_data[], int32_T y_size[2])
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y_data[], int32_T y_size[2])
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Runge, const
  char_T *identifier, struct5_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  r_emlrt_marshallIn(sp, emlrtAlias(Runge), &thisId, y);
  emlrtDestroyArray(&Runge);
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct5_T *y)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[4] = { "b", "a", "c", "s" };

  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 4, fieldNames, 0U, &dims);
  thisId.fIdentifier = "b";
  s_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "b")),
                     &thisId, y->b);
  thisId.fIdentifier = "a";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "a")),
                     &thisId, y->a);
  thisId.fIdentifier = "c";
  t_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2, "c")),
                     &thisId, y->c);
  thisId.fIdentifier = "s";
  y->s = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3, "s")),
    &thisId);
  emlrtDestroyArray(&u);
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[9])
{
  fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, real_T y[3])
{
  gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = { 0, 0 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, char_T ret[12])
{
  static const int32_T dims[2] = { 1, 12 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "char", false, 2U, dims);
  emlrtImportCharArrayR2015b(sp, src, &ret[0], 12);
  emlrtDestroyArray(&src);
}

static real_T w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
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

void Chi_3_LLE_Runge_Kuarong_api(const mxArray * const prhs[2], const mxArray
  *plhs[1])
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
  emxInitStruct_struct6_T(&st, &Sol, &ob_emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "Temp", &Temp);
  q_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "Runge", &Runge);

  /* Invoke the target function */
  Chi_3_LLE_Runge_Kuarong(&st, &Temp, &Runge, &Sol);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, Sol);
  emxFreeStruct_struct6_T(&Sol);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_Chi_3_LLE_Runge_Kuarong_api.c) */
