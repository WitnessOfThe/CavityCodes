//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_Chi23_Runge_Kuarong_GPU_api.cu
//
// Code generation for function '_coder_Chi23_Runge_Kuarong_GPU_api'
//

// Include files
#include "_coder_Chi23_Runge_Kuarong_GPU_api.h"
#include "Chi23_Runge_Kuarong_GPU.h"
#include "Chi23_Runge_Kuarong_GPU_data.h"
#include "Chi23_Runge_Kuarong_GPU_emxutil.h"
#include "Chi23_Runge_Kuarong_GPU_types.h"
#include "rt_nonfinite.h"

// Function Declarations
static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               creal_T y[256]);

static struct1_T b_emlrt_marshallIn(const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static void b_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[12]);

static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[1032]);

static void c_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               creal_T ret[512]);

static void c_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static real_T c_emlrt_marshallIn(const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static void d_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[256]);

static struct4_T d_emlrt_marshallIn(const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static void d_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               creal_T ret[256]);

static void e_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[512]);

static creal_T e_emlrt_marshallIn(const mxArray *u,
                                  const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T *y);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, char_T y[12]);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct2_T *y);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct3_T *y);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[656]);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct5_T *y);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct6_T *y);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId,
                             creal_T y[512]);

static void emlrt_marshallIn(const mxArray *Runge, const char_T *identifier,
                             struct7_T *y);

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct7_T *y);

static void emlrt_marshallIn(const mxArray *Temp, const char_T *identifier,
                             struct0_T *y);

static const mxArray *emlrt_marshallOut(const struct8_T u);

static void f_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId);

static void f_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9]);

static void g_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3]);

static real_T g_emlrt_marshallIn(const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void h_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[656]);

static creal_T h_emlrt_marshallIn(const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

static void i_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[1032]);

static void j_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2]);

static void k_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[256]);

static void l_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[512]);

static void m_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[9]);

static void n_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[3]);

// Function Definitions
static struct1_T b_emlrt_marshallIn(const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[6]{"Runge_Type", "dt", "s_t",
                                     "T",          "dd", "CW_num"};
  emlrtMsgIdentifier thisId;
  struct1_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 6,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "Runge_Type";
  emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
                                     (const char_T *)"Runge_Type")),
      &thisId, y.Runge_Type);
  thisId.fIdentifier = "dt";
  y.dt = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
                                     (const char_T *)"dt")),
      &thisId);
  thisId.fIdentifier = "s_t";
  y.s_t = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
                                     (const char_T *)"s_t")),
      &thisId);
  thisId.fIdentifier = "T";
  y.T =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 3, (const char_T *)"T")),
                         &thisId);
  thisId.fIdentifier = "dd";
  y.dd = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4,
                                     (const char_T *)"dd")),
      &thisId);
  thisId.fIdentifier = "CW_num";
  y.CW_num = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5,
                                     (const char_T *)"CW_num")),
      &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static void b_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, char_T ret[12])
{
  static const int32_T dims[2]{1, 12};
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"char", false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 12);
  emlrtDestroyArray(&src);
}

static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[1032])
{
  i_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               creal_T y[256])
{
  d_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2])
{
  j_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void c_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               creal_T ret[512])
{
  static const int32_T dims[2]{1, 512};
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", true, 2U, (void *)&dims[0]);
  emlrtImportArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 8, true);
  emlrtDestroyArray(&src);
}

static real_T c_emlrt_marshallIn(const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = g_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void d_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               creal_T ret[256])
{
  static const int32_T dims[2]{1, 256};
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", true, 2U, (void *)&dims[0]);
  emlrtImportArrayR2015b(emlrtRootTLSGlobal, src, &ret[0], 8, true);
  emlrtDestroyArray(&src);
}

static struct4_T d_emlrt_marshallIn(const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[7]{"eta", "delta", "m_p", "W",
                                     "N",   "Nenv",  "g"};
  emlrtMsgIdentifier thisId;
  struct4_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 7,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "eta";
  y.eta = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
                                     (const char_T *)"eta")),
      &thisId);
  thisId.fIdentifier = "delta";
  y.delta = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
                                     (const char_T *)"delta")),
      &thisId);
  thisId.fIdentifier = "m_p";
  y.m_p = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
                                     (const char_T *)"m_p")),
      &thisId);
  thisId.fIdentifier = "W";
  y.W =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 3, (const char_T *)"W")),
                         &thisId);
  thisId.fIdentifier = "N";
  y.N =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 4, (const char_T *)"N")),
                         &thisId);
  thisId.fIdentifier = "Nenv";
  y.Nenv = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5,
                                     (const char_T *)"Nenv")),
      &thisId);
  thisId.fIdentifier = "g";
  y.g =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 6, (const char_T *)"g")),
                         &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static void d_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[256])
{
  k_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[512])
{
  l_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static creal_T e_emlrt_marshallIn(const mxArray *u,
                                  const emlrtMsgIdentifier *parentId)
{
  creal_T y;
  y = h_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct5_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[6]{"N", "lenght", "dphi", "phi", "dk", "k"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 6,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "N";
  y->N =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 0, (const char_T *)"N")),
                         &thisId);
  thisId.fIdentifier = "lenght";
  y->lenght = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
                                     (const char_T *)"lenght")),
      &thisId);
  thisId.fIdentifier = "dphi";
  y->dphi = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
                                     (const char_T *)"dphi")),
      &thisId);
  thisId.fIdentifier = "phi";
  d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3,
                                                    (const char_T *)"phi")),
                     &thisId, y->phi);
  thisId.fIdentifier = "dk";
  y->dk = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4,
                                     (const char_T *)"dk")),
      &thisId);
  thisId.fIdentifier = "k";
  d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5,
                                                    (const char_T *)"k")),
                     &thisId, y->k);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *Temp, const char_T *identifier,
                             struct0_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(emlrtAlias(Temp), &thisId, y);
  emlrtDestroyArray(&Temp);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct0_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[5]{"Met", "Par", "In", "Space", "Eq"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 5,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "Met";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
                                                  (const char_T *)"Met")),
                   &thisId);
  thisId.fIdentifier = "Par";
  y->Par = b_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
                                     (const char_T *)"Par")),
      &thisId);
  thisId.fIdentifier = "In";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
                                                  (const char_T *)"In")),
                   &thisId, &y->In);
  thisId.fIdentifier = "Space";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3,
                                                  (const char_T *)"Space")),
                   &thisId, &y->Space);
  thisId.fIdentifier = "Eq";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4,
                                                  (const char_T *)"Eq")),
                   &thisId, &y->Eq);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId)
{
  f_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, char_T y[12])
{
  b_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct2_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[33]{
      "eta",        "delta_o",   "W",        "ko",     "ke",      "eps",
      "eps_2",      "Do",        "De",       "gam2o",  "gam2e",   "gam3o",
      "gam3e",      "Finess",    "Finess_e", "H_Star", "Wf_Star", "Ws_Star",
      "Omega_Star", "D",         "N_mode",   "N",      "kMI",     "mu_bl",
      "delta",      "delta_e",   "H_f",      "H_s",    "Omega_f", "Omega_s",
      "d",          "Psi_Start", "t_start"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 33,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "eta";
  y->eta = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
                                     (const char_T *)"eta")),
      &thisId);
  thisId.fIdentifier = "delta_o";
  y->delta_o = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
                                     (const char_T *)"delta_o")),
      &thisId);
  thisId.fIdentifier = "W";
  y->W =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 2, (const char_T *)"W")),
                         &thisId);
  thisId.fIdentifier = "ko";
  y->ko = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3,
                                     (const char_T *)"ko")),
      &thisId);
  thisId.fIdentifier = "ke";
  y->ke = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4,
                                     (const char_T *)"ke")),
      &thisId);
  thisId.fIdentifier = "eps";
  y->eps = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5,
                                     (const char_T *)"eps")),
      &thisId);
  thisId.fIdentifier = "eps_2";
  y->eps_2 = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 6,
                                     (const char_T *)"eps_2")),
      &thisId);
  thisId.fIdentifier = "Do";
  y->Do = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 7,
                                     (const char_T *)"Do")),
      &thisId);
  thisId.fIdentifier = "De";
  y->De = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 8,
                                     (const char_T *)"De")),
      &thisId);
  thisId.fIdentifier = "gam2o";
  y->gam2o = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 9,
                                     (const char_T *)"gam2o")),
      &thisId);
  thisId.fIdentifier = "gam2e";
  y->gam2e = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 10,
                                     (const char_T *)"gam2e")),
      &thisId);
  thisId.fIdentifier = "gam3o";
  y->gam3o = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 11,
                                     (const char_T *)"gam3o")),
      &thisId);
  thisId.fIdentifier = "gam3e";
  y->gam3e = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 12,
                                     (const char_T *)"gam3e")),
      &thisId);
  thisId.fIdentifier = "Finess";
  y->Finess = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 13,
                                     (const char_T *)"Finess")),
      &thisId);
  thisId.fIdentifier = "Finess_e";
  y->Finess_e = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 14,
                                     (const char_T *)"Finess_e")),
      &thisId);
  thisId.fIdentifier = "H_Star";
  y->H_Star = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 15,
                                     (const char_T *)"H_Star")),
      &thisId);
  thisId.fIdentifier = "Wf_Star";
  y->Wf_Star = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 16,
                                     (const char_T *)"Wf_Star")),
      &thisId);
  thisId.fIdentifier = "Ws_Star";
  y->Ws_Star = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 17,
                                     (const char_T *)"Ws_Star")),
      &thisId);
  thisId.fIdentifier = "Omega_Star";
  y->Omega_Star = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 18,
                                     (const char_T *)"Omega_Star")),
      &thisId);
  thisId.fIdentifier = "D";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 19,
                                                  (const char_T *)"D")),
                   &thisId, &y->D);
  thisId.fIdentifier = "N_mode";
  y->N_mode = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 20,
                                     (const char_T *)"N_mode")),
      &thisId);
  thisId.fIdentifier = "N";
  y->N = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 21,
                                     (const char_T *)"N")),
      &thisId);
  thisId.fIdentifier = "kMI";
  c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0,
                                                    22, (const char_T *)"kMI")),
                     &thisId, y->kMI);
  thisId.fIdentifier = "mu_bl";
  y->mu_bl = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 23,
                                     (const char_T *)"mu_bl")),
      &thisId);
  thisId.fIdentifier = "delta";
  y->delta = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 24,
                                     (const char_T *)"delta")),
      &thisId);
  thisId.fIdentifier = "delta_e";
  y->delta_e = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 25,
                                     (const char_T *)"delta_e")),
      &thisId);
  thisId.fIdentifier = "H_f";
  y->H_f = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 26,
                                     (const char_T *)"H_f")),
      &thisId);
  thisId.fIdentifier = "H_s";
  y->H_s = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 27,
                                     (const char_T *)"H_s")),
      &thisId);
  thisId.fIdentifier = "Omega_f";
  y->Omega_f = e_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 28,
                                     (const char_T *)"Omega_f")),
      &thisId);
  thisId.fIdentifier = "Omega_s";
  y->Omega_s = e_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 29,
                                     (const char_T *)"Omega_s")),
      &thisId);
  thisId.fIdentifier = "d";
  y->d = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 30,
                                     (const char_T *)"d")),
      &thisId);
  thisId.fIdentifier = "Psi_Start";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 31,
                                                  (const char_T *)"Psi_Start")),
                   &thisId, y->Psi_Start);
  thisId.fIdentifier = "t_start";
  y->t_start = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 32,
                                     (const char_T *)"t_start")),
      &thisId);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct3_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[12]{
      "omega",  "m", "D1",        "n_o",        "n_e",   "gamma2",
      "gamma3", "S", "gamma2_SH", "gamma2_OPO", "kappa", "In"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 12,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "omega";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
                                                  (const char_T *)"omega")),
                   &thisId, y->omega);
  thisId.fIdentifier = "m";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
                                                  (const char_T *)"m")),
                   &thisId, y->m);
  thisId.fIdentifier = "D1";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
                                                  (const char_T *)"D1")),
                   &thisId, y->D1);
  thisId.fIdentifier = "n_o";
  b_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3,
                                                    (const char_T *)"n_o")),
                     &thisId, y->n_o);
  thisId.fIdentifier = "n_e";
  b_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4,
                                                    (const char_T *)"n_e")),
                     &thisId, y->n_e);
  thisId.fIdentifier = "gamma2";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5,
                                                  (const char_T *)"gamma2")),
                   &thisId, y->gamma2);
  thisId.fIdentifier = "gamma3";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 6,
                                                  (const char_T *)"gamma3")),
                   &thisId, y->gamma3);
  thisId.fIdentifier = "S";
  b_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 7,
                                                    (const char_T *)"S")),
                     &thisId, y->S);
  thisId.fIdentifier = "gamma2_SH";
  b_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 8,
                                     (const char_T *)"gamma2_SH")),
      &thisId, y->gamma2_SH);
  thisId.fIdentifier = "gamma2_OPO";
  b_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 9,
                                     (const char_T *)"gamma2_OPO")),
      &thisId, y->gamma2_OPO);
  thisId.fIdentifier = "kappa";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 10,
                                                  (const char_T *)"kappa")),
                   &thisId, y->kappa);
  thisId.fIdentifier = "In";
  y->In = d_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 11,
                                     (const char_T *)"In")),
      &thisId);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, real_T y[656])
{
  h_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct6_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[19]{
      "H_f",   "H_s",        "delta_o", "delta_e", "eps", "ko", "ke",
      "gam2o", "gam2e",      "gam3o",   "gam3e",   "Do",  "De", "d",
      "norm",  "mode_range", "Lo",      "Le",      "L"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 19,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "H_f";
  y->H_f = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
                                     (const char_T *)"H_f")),
      &thisId);
  thisId.fIdentifier = "H_s";
  y->H_s = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
                                     (const char_T *)"H_s")),
      &thisId);
  thisId.fIdentifier = "delta_o";
  y->delta_o = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
                                     (const char_T *)"delta_o")),
      &thisId);
  thisId.fIdentifier = "delta_e";
  y->delta_e = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 3,
                                     (const char_T *)"delta_e")),
      &thisId);
  thisId.fIdentifier = "eps";
  y->eps = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 4,
                                     (const char_T *)"eps")),
      &thisId);
  thisId.fIdentifier = "ko";
  y->ko = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 5,
                                     (const char_T *)"ko")),
      &thisId);
  thisId.fIdentifier = "ke";
  y->ke = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 6,
                                     (const char_T *)"ke")),
      &thisId);
  thisId.fIdentifier = "gam2o";
  d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 7,
                                                    (const char_T *)"gam2o")),
                     &thisId, y->gam2o);
  thisId.fIdentifier = "gam2e";
  d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 8,
                                                    (const char_T *)"gam2e")),
                     &thisId, y->gam2e);
  thisId.fIdentifier = "gam3o";
  d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 9,
                                                    (const char_T *)"gam3o")),
                     &thisId, y->gam3o);
  thisId.fIdentifier = "gam3e";
  d_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 10,
                                     (const char_T *)"gam3e")),
      &thisId, y->gam3e);
  thisId.fIdentifier = "Do";
  y->Do = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 11,
                                     (const char_T *)"Do")),
      &thisId);
  thisId.fIdentifier = "De";
  y->De = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 12,
                                     (const char_T *)"De")),
      &thisId);
  thisId.fIdentifier = "d";
  y->d = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 13,
                                     (const char_T *)"d")),
      &thisId);
  thisId.fIdentifier = "norm";
  y->norm = c_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 14,
                                     (const char_T *)"norm")),
      &thisId);
  thisId.fIdentifier = "mode_range";
  e_emlrt_marshallIn(
      emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 15,
                                     (const char_T *)"mode_range")),
      &thisId, y->mode_range);
  thisId.fIdentifier = "Lo";
  b_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0,
                                                    16, (const char_T *)"Lo")),
                     &thisId, y->Lo);
  thisId.fIdentifier = "Le";
  b_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0,
                                                    17, (const char_T *)"Le")),
                     &thisId, y->Le);
  thisId.fIdentifier = "L";
  emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 18,
                                                  (const char_T *)"L")),
                   &thisId, y->L);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, creal_T y[512])
{
  c_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const mxArray *Runge, const char_T *identifier,
                             struct7_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char_T *>(identifier);
  thisId.fParent = nullptr;
  thisId.bParentIsCell = false;
  emlrt_marshallIn(emlrtAlias(Runge), &thisId, y);
  emlrtDestroyArray(&Runge);
}

static void emlrt_marshallIn(const mxArray *u,
                             const emlrtMsgIdentifier *parentId, struct7_T *y)
{
  static const int32_T dims{0};
  static const char_T *fieldNames[4]{"b", "a", "c", "s"};
  emlrtMsgIdentifier thisId;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 4,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "b";
  f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 0,
                                                    (const char_T *)"b")),
                     &thisId, y->b);
  thisId.fIdentifier = "a";
  g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 1,
                                                    (const char_T *)"a")),
                     &thisId, y->a);
  thisId.fIdentifier = "c";
  g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(emlrtRootTLSGlobal, u, 0, 2,
                                                    (const char_T *)"c")),
                     &thisId, y->c);
  thisId.fIdentifier = "s";
  y->s =
      c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2017b(
                             emlrtRootTLSGlobal, u, 0, 3, (const char_T *)"s")),
                         &thisId);
  emlrtDestroyArray(&u);
}

static const mxArray *emlrt_marshallOut(const struct8_T u)
{
  static const char_T *sv1[3]{"Psio", "Psie", "t"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  y = nullptr;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 3, (const char_T **)&sv1[0]));
  b_y = nullptr;
  iv[0] = u.Psio->size[0];
  iv[1] = u.Psio->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(emlrtRootTLSGlobal, m, &u.Psio->data[0], 8);
  emlrtAssign(&b_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Psio", b_y, 0);
  c_y = nullptr;
  iv[0] = u.Psie->size[0];
  iv[1] = u.Psie->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(emlrtRootTLSGlobal, m, &u.Psie->data[0], 8);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"Psie", c_y, 1);
  d_y = nullptr;
  iv[0] = 1;
  iv[1] = u.t->size[1];
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxCOMPLEX);
  emlrtExportNumericArrayR2013b(emlrtRootTLSGlobal, m, &u.t->data[0], 8);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"t", d_y, 2);
  return y;
}

static void f_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2]{0, 0};
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 2U,
                          (void *)&dims[0]);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void f_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[9])
{
  m_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void g_emlrt_marshallIn(const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[3])
{
  n_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T g_emlrt_marshallIn(const mxArray *src,
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

static creal_T h_emlrt_marshallIn(const mxArray *src,
                                  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims{0};
  creal_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", true, 0U, (void *)&dims);
  emlrtImportArrayR2015b(emlrtRootTLSGlobal, src, &ret, 8, true);
  emlrtDestroyArray(&src);
  return ret;
}

static void h_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[656])
{
  static const int32_T dims[2]{1, 656};
  real_T(*r)[656];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 2U,
                          (void *)&dims[0]);
  r = (real_T(*)[656])emlrtMxGetData(src);
  for (int32_T i{0}; i < 656; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               real_T ret[1032])
{
  static const int32_T dims[2]{1, 1032};
  real_T(*r)[1032];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 2U,
                          (void *)&dims[0]);
  r = (real_T(*)[1032])emlrtMxGetData(src);
  for (int32_T i{0}; i < 1032; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void j_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2]{1, 2};
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 2U,
                          (void *)&dims[0]);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[256])
{
  static const int32_T dims[2]{1, 256};
  real_T(*r)[256];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 2U,
                          (void *)&dims[0]);
  r = (real_T(*)[256])emlrtMxGetData(src);
  for (int32_T i{0}; i < 256; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[512])
{
  static const int32_T dims[2]{1, 512};
  real_T(*r)[512];
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src,
                          (const char_T *)"double", false, 2U,
                          (void *)&dims[0]);
  r = (real_T(*)[512])emlrtMxGetData(src);
  for (int32_T i{0}; i < 512; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const mxArray *src,
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

static void n_emlrt_marshallIn(const mxArray *src,
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

void Chi23_Runge_Kuarong_GPU_api(const mxArray *const prhs[2],
                                 const mxArray *plhs[1])
{
  struct0_T Temp;
  struct7_T Runge;
  struct8_T Sol;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInitStruct_struct8_T(&Sol, true);
  // Marshall function inputs
  emlrt_marshallIn(emlrtAliasP(prhs[0]), "Temp", &Temp);
  emlrt_marshallIn(emlrtAliasP(prhs[1]), "Runge", &Runge);
  // Invoke the target function
  Chi23_Runge_Kuarong_GPU(&Temp, &Runge, &Sol);
  // Marshall function outputs
  plhs[0] = emlrt_marshallOut(Sol);
  emxFreeStruct_struct8_T(&Sol);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

// End of code generation (_coder_Chi23_Runge_Kuarong_GPU_api.cu)
