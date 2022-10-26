/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi_3_LLE_Runge_Kuarong.c
 *
 * Code generation for function 'Chi_3_LLE_Runge_Kuarong'
 *
 */

/* Include files */
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"
#include "Chi_3_LLE_Runge_Kuarong_emxutil.h"
#include "Chi_3_LLE_Runge_Kuarong_types.h"
#include "fft.h"
#include "ifft.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    31,                        /* lineNo */
    "Chi_3_LLE_Runge_Kuarong", /* fcnName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    3,                         /* lineNo */
    "Chi_3_LLE_Runge_Kuarong", /* fcnName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    70,                                           /* lineNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fcnName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m" /* pathName */
};

static emlrtDCInfo emlrtDCI = {
    35,                        /* lineNo */
    21,                        /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    35,                        /* lineNo */
    21,                        /* colNo */
    "Sol.Psi",                 /* aName */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    80,                                           /* lineNo */
    90,                                           /* colNo */
    "d",                                          /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    76,                                           /* lineNo */
    18,                                           /* colNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m" /* pName */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    70,                                           /* lineNo */
    15,                                           /* colNo */
    "d",                                          /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,                                            /* iFirst */
    3,                                            /* iLast */
    70,                                           /* lineNo */
    66,                                           /* colNo */
    "exp_plus_omega",                             /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    64,                                           /* lineNo */
    105,                                          /* colNo */
    "d",                                          /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    60,                                           /* lineNo */
    22,                                           /* colNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    58,                                           /* lineNo */
    18,                                           /* colNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m" /* pName */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                                           /* iFirst */
    -1,                                           /* iLast */
    56,                                           /* lineNo */
    11,                                           /* colNo */
    "d",                                          /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    29,                        /* lineNo */
    14,                        /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m" /* pName */
};

static emlrtDCInfo b_emlrtDCI = {
    3,                         /* lineNo */
    35,                        /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    3,                         /* lineNo */
    35,                        /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    4                  /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    25,                        /* lineNo */
    29,                        /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    25,                        /* lineNo */
    29,                        /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    4                  /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    26,                        /* lineNo */
    31,                        /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    3,                         /* lineNo */
    5,                         /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    25,                        /* lineNo */
    5,                         /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    26,                        /* lineNo */
    5,                         /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    1,                                            /* iFirst */
    3,                                            /* iLast */
    78,                                           /* lineNo */
    25,                                           /* colNo */
    "Runge.c",                                    /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    1,                                            /* iFirst */
    3,                                            /* iLast */
    62,                                           /* lineNo */
    28,                                           /* colNo */
    "Runge.b",                                    /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    1,                                            /* iFirst */
    3,                                            /* iLast */
    62,                                           /* lineNo */
    31,                                           /* colNo */
    "Runge.b",                                    /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    1,                                            /* iFirst */
    256,                                          /* iLast */
    86,                                           /* lineNo */
    12,                                           /* colNo */
    "E_f",                                        /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    3                  /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    86,                                           /* lineNo */
    12,                                           /* colNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    1,                                            /* iFirst */
    256,                                          /* iLast */
    80,                                           /* lineNo */
    50,                                           /* colNo */
    "E_f",                                        /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    80,                                           /* lineNo */
    50,                                           /* colNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    80,                                           /* lineNo */
    93,                                           /* colNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    1,                                            /* iFirst */
    256,                                          /* iLast */
    64,                                           /* lineNo */
    62,                                           /* colNo */
    "E_temp",                                     /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    64,                                           /* lineNo */
    62,                                           /* colNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    64,                                           /* lineNo */
    108,                                          /* colNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    1,                                            /* iFirst */
    256,                                          /* iLast */
    80,                                           /* lineNo */
    17,                                           /* colNo */
    "E_f",                                        /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    3                  /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = {
    80,                                           /* lineNo */
    17,                                           /* colNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    1,                                            /* iFirst */
    256,                                          /* iLast */
    64,                                           /* lineNo */
    21,                                           /* colNo */
    "E_temp",                                     /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    3                  /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = {
    64,                                           /* lineNo */
    21,                                           /* colNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = {
    35,                        /* lineNo */
    37,                        /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    1,                         /* iFirst */
    256,                       /* iLast */
    35,                        /* lineNo */
    37,                        /* colNo */
    "F_e",                     /* aName */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    36,                        /* lineNo */
    21,                        /* colNo */
    "Sol.t",                   /* aName */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    1,                                            /* iFirst */
    256,                                          /* iLast */
    86,                                           /* lineNo */
    38,                                           /* colNo */
    "shift_back",                                 /* aName */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    0                  /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = {
    86,                                           /* lineNo */
    38,                                           /* colNo */
    "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m", /* pName */
    1                  /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    3,                         /* lineNo */
    5,                         /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    25,                        /* lineNo */
    5,                         /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    26,                        /* lineNo */
    5,                         /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    31,                        /* lineNo */
    61,                        /* colNo */
    "Chi_3_LLE_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
    "Runge_Kuarong.m" /* pName */
};

/* Function Definitions */
void Chi_3_LLE_Runge_Kuarong(const emlrtStack *sp, const struct0_T *Temp,
                             const struct5_T *Runge, struct6_T *Sol)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_creal_T *b_d;
  emxArray_cuint8_T *d;
  creal_T exp_minus_omega_contents[768];
  creal_T exp_plus_omega_contents[768];
  creal_T E_temp[256];
  creal_T F_e[256];
  creal_T Psi[256];
  creal_T b_F_e[256];
  creal_T dcv[256];
  creal_T *b_d_data;
  cuint8_T *d_data;
  real_T b_re_tmp;
  real_T c_d;
  real_T dt_tmp_tmp;
  real_T im;
  real_T im_tmp;
  real_T ind_s;
  real_T nt;
  real_T q;
  real_T r;
  real_T re;
  real_T re_tmp;
  real_T y;
  int32_T b_i;
  int32_T b_i2;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T ii;
  int32_T loop_ub;
  int32_T ni;
  boolean_T rEQ0;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_cuint8_T(sp, &d, &e_emlrtRTEI);
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &c_emlrtDCI, (emlrtCTX)sp);
  }
  re_tmp = (int32_T)muDoubleScalarFloor(Runge->s);
  if (Runge->s != re_tmp) {
    emlrtIntegerCheckR2012b(Runge->s, &b_emlrtDCI, (emlrtCTX)sp);
  }
  i = d->size[0] * d->size[1];
  i1 = (int32_T)Runge->s;
  d->size[0] = (int32_T)Runge->s;
  d->size[1] = 256;
  emxEnsureCapacity_cuint8_T(sp, d, i, &e_emlrtRTEI);
  d_data = d->data;
  if (Runge->s != re_tmp) {
    emlrtIntegerCheckR2012b(Runge->s, &g_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = (int32_T)Runge->s << 8;
  for (i = 0; i < loop_ub; i++) {
    d_data[i].re = 0U;
    d_data[i].im = 0U;
  }
  dt_tmp_tmp = Temp->Par.dt;
  nt = Temp->Par.T / Temp->Par.dt;
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  for (b_i = 0; b_i < 3; b_i++) {
    q = Runge->a[b_i];
    for (loop_ub = 0; loop_ub < 256; loop_ub++) {
      ind_s = Temp->Eq.L[loop_ub].im;
      re_tmp = Temp->Eq.L[loop_ub].re;
      b_re_tmp = 0.0 * re_tmp;
      im_tmp = 0.0 * ind_s;
      re = dt_tmp_tmp * (q * (b_re_tmp - (-ind_s)));
      im = dt_tmp_tmp * (q * (im_tmp + -re_tmp));
      if (im == 0.0) {
        re = muDoubleScalarExp(re);
        im = 0.0;
      } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) &&
                 (re < 0.0)) {
        re = 0.0;
        im = 0.0;
      } else {
        r = muDoubleScalarExp(re / 2.0);
        re = r * (r * muDoubleScalarCos(im));
        im = r * (r * muDoubleScalarSin(im));
      }
      i = b_i + 3 * loop_ub;
      exp_minus_omega_contents[i].re = re;
      exp_minus_omega_contents[i].im = im;
      re = dt_tmp_tmp * (q * (b_re_tmp - ind_s));
      im = dt_tmp_tmp * (q * (im_tmp + re_tmp));
      if (im == 0.0) {
        re = muDoubleScalarExp(re);
        im = 0.0;
      } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) &&
                 (re < 0.0)) {
        re = 0.0;
        im = 0.0;
      } else {
        r = muDoubleScalarExp(re / 2.0);
        re = r * (r * muDoubleScalarCos(im));
        im = r * (r * muDoubleScalarSin(im));
      }
      exp_plus_omega_contents[i].re = re;
      exp_plus_omega_contents[i].im = im;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  for (loop_ub = 0; loop_ub < 256; loop_ub++) {
    ind_s = Temp->Eq.L[loop_ub].im;
    re_tmp = Temp->Eq.L[loop_ub].re;
    re = dt_tmp_tmp * (0.0 * re_tmp - (-ind_s));
    im = dt_tmp_tmp * (0.0 * ind_s + -re_tmp);
    dcv[loop_ub].re = re;
    dcv[loop_ub].im = im;
    if (im == 0.0) {
      dcv[loop_ub].re = muDoubleScalarExp(re);
      dcv[loop_ub].im = 0.0;
    } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) &&
               (re < 0.0)) {
      dcv[loop_ub].re = 0.0;
      dcv[loop_ub].im = 0.0;
    } else {
      r = muDoubleScalarExp(re / 2.0);
      dcv[loop_ub].re = r * (r * muDoubleScalarCos(im));
      dcv[loop_ub].im = r * (r * muDoubleScalarSin(im));
    }
    F_e[loop_ub] = Temp->In.Psi_Start[loop_ub];
  }
  if (!(Temp->Par.dd >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Par.dd, &e_emlrtDCI, (emlrtCTX)sp);
  }
  re_tmp = (int32_T)muDoubleScalarFloor(Temp->Par.dd);
  if (Temp->Par.dd != re_tmp) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &d_emlrtDCI, (emlrtCTX)sp);
  }
  i = Sol->Psi->size[0] * Sol->Psi->size[1];
  loop_ub = (int32_T)Temp->Par.dd;
  Sol->Psi->size[0] = (int32_T)Temp->Par.dd;
  Sol->Psi->size[1] = 256;
  emxEnsureCapacity_creal_T(sp, Sol->Psi, i, &f_emlrtRTEI);
  if (Temp->Par.dd != re_tmp) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &h_emlrtDCI, (emlrtCTX)sp);
  }
  b_i = (int32_T)Temp->Par.dd << 8;
  for (i = 0; i < b_i; i++) {
    Sol->Psi->data[i].re = 0.0;
    Sol->Psi->data[i].im = 0.0;
  }
  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &g_emlrtRTEI);
  if (Temp->Par.dd != re_tmp) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &f_emlrtDCI, (emlrtCTX)sp);
  }
  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[1] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &g_emlrtRTEI);
  if (Temp->Par.dd != re_tmp) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &i_emlrtDCI, (emlrtCTX)sp);
  }
  for (i = 0; i < loop_ub; i++) {
    Sol->t->data[i].re = 0.0;
    Sol->t->data[i].im = 0.0;
  }
  i = (int32_T)nt;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, nt, mxDOUBLE_CLASS, (int32_T)nt,
                                &d_emlrtRTEI, (emlrtCTX)sp);
  emxInit_creal_T(sp, &b_d, &h_emlrtRTEI);
  if (0 <= i - 1) {
    c_d = 256.0 * Temp->Eq.h;
    i2 = (int32_T)(Runge->s + -1.0);
    y = Temp->Par.s_t / dt_tmp_tmp;
  }
  for (ni = 0; ni < i; ni++) {
    st.site = &emlrtRSI;
    i3 = b_d->size[0] * b_d->size[1];
    b_d->size[0] = d->size[0];
    b_d->size[1] = 256;
    emxEnsureCapacity_creal_T(&st, b_d, i3, &h_emlrtRTEI);
    b_d_data = b_d->data;
    loop_ub = d->size[0] * 256;
    for (i3 = 0; i3 < loop_ub; i3++) {
      b_d_data[i3].re = 0.0;
      b_d_data[i3].im = d_data[i3].im;
    }
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
     */
    memcpy(&E_temp[0], &F_e[0], 256U * sizeof(creal_T));
    if (1 > d->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, d->size[0], &f_emlrtBCI, &st);
    }
    for (i3 = 0; i3 < 256; i3++) {
      re_tmp = F_e[i3].re;
      q = exp_minus_omega_contents[3 * i3].im;
      im_tmp = F_e[i3].im;
      nt = exp_minus_omega_contents[3 * i3].re;
      b_F_e[i3].re = re_tmp * nt - im_tmp * q;
      b_F_e[i3].im = re_tmp * q + im_tmp * nt;
    }
    ifft(b_F_e, Psi);
    for (loop_ub = 0; loop_ub < 256; loop_ub++) {
      re_tmp = Psi[loop_ub].re;
      q = Psi[loop_ub].im;
      im_tmp = muDoubleScalarHypot(re_tmp, q);
      im_tmp *= im_tmp;
      b_F_e[loop_ub].re = im_tmp * re_tmp;
      b_F_e[loop_ub].im = im_tmp * q;
    }
    fft(b_F_e, Psi);
    for (i3 = 0; i3 < 256; i3++) {
      ind_s = exp_plus_omega_contents[3 * i3].im;
      re_tmp = exp_plus_omega_contents[3 * i3].re;
      re = 0.0 * re_tmp - ind_s;
      im = 0.0 * ind_s + re_tmp;
      re_tmp = Temp->Eq.gamma_Kerr[i3];
      im_tmp = re_tmp * Psi[i3].re;
      q = re_tmp * Psi[i3].im;
      Psi[i3].re = re * im_tmp - im * q;
      Psi[i3].im = re * q + im * im_tmp;
    }
    Psi[0].re += exp_plus_omega_contents[0].re * c_d;
    Psi[0].im += exp_plus_omega_contents[0].im * c_d;
    for (i3 = 0; i3 < 256; i3++) {
      b_d_data[b_d->size[0] * i3] = Psi[i3];
    }
    emlrtForLoopVectorCheckR2021a(2.0, 1.0, Runge->s, mxDOUBLE_CLASS,
                                  (int32_T)(Runge->s + -1.0), &c_emlrtRTEI,
                                  &st);
    if (0 <= i2 - 1) {
      i4 = (int32_T)(Runge->s - 1.0);
    }
    for (b_i2 = 0; b_i2 < i2; b_i2++) {
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
                                    (int32_T)(Runge->s - 1.0), &b_emlrtRTEI,
                                    &st);
      for (ii = 0; ii < i4; ii++) {
        if (((int32_T)(b_i2 + 2U) < 1) || ((int32_T)(b_i2 + 2U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i2 + 2U), 1, 3, &h_emlrtBCI,
                                        &st);
        }
        if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, 3, &i_emlrtBCI,
                                        &st);
        }
        re_tmp = Runge->b[(b_i2 + 3 * ii) + 1];
        if (re_tmp != 0.0) {
          q = dt_tmp_tmp * re_tmp;
          if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > b_d->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, b_d->size[0],
                                          &e_emlrtBCI, &st);
          }
          for (i3 = 0; i3 < 256; i3++) {
            re_tmp = Temp->Eq.mode_range[i3];
            b_i = (int32_T)muDoubleScalarFloor(re_tmp);
            if (re_tmp != b_i) {
              emlrtIntegerCheckR2012b(re_tmp, &m_emlrtDCI, &st);
            }
            loop_ub = (int32_T)re_tmp;
            if ((loop_ub < 1) || (loop_ub > 256)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 256, &l_emlrtBCI, &st);
            }
            if (loop_ub != b_i) {
              emlrtIntegerCheckR2012b(re_tmp, &n_emlrtDCI, &st);
            }
            b_F_e[i3].re = E_temp[loop_ub - 1].re +
                           q * b_d_data[ii + b_d->size[0] * (loop_ub - 1)].re;
            if (loop_ub != b_i) {
              emlrtIntegerCheckR2012b(re_tmp, &m_emlrtDCI, &st);
            }
            b_F_e[i3].im = E_temp[loop_ub - 1].im +
                           q * b_d_data[ii + b_d->size[0] * (loop_ub - 1)].im;
          }
          for (i3 = 0; i3 < 256; i3++) {
            re_tmp = Temp->Eq.mode_range[i3];
            b_i = (int32_T)muDoubleScalarFloor(re_tmp);
            if (re_tmp != b_i) {
              emlrtIntegerCheckR2012b(re_tmp, &p_emlrtDCI, &st);
            }
            loop_ub = (int32_T)re_tmp;
            if ((loop_ub < 1) || (loop_ub > 256)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 256, &n_emlrtBCI, &st);
            }
            E_temp[loop_ub - 1].re = b_F_e[i3].re;
            if (loop_ub != b_i) {
              emlrtIntegerCheckR2012b(re_tmp, &p_emlrtDCI, &st);
            }
            E_temp[loop_ub - 1].im = b_F_e[i3].im;
          }
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      b_st.site = &e_emlrtRSI;
      if ((b_i2 + 2 < 1) || (b_i2 + 2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(b_i2 + 2, 1, 3, &d_emlrtBCI, &b_st);
      }
      for (i3 = 0; i3 < 256; i3++) {
        b_i = (b_i2 + 3 * i3) + 1;
        ind_s = E_temp[i3].re;
        re_tmp = exp_minus_omega_contents[b_i].im;
        b_re_tmp = E_temp[i3].im;
        q = exp_minus_omega_contents[b_i].re;
        E_temp[i3].re = ind_s * q - b_re_tmp * re_tmp;
        E_temp[i3].im = ind_s * re_tmp + b_re_tmp * q;
      }
      ifft(E_temp, Psi);
      for (loop_ub = 0; loop_ub < 256; loop_ub++) {
        re_tmp = Psi[loop_ub].re;
        q = Psi[loop_ub].im;
        im_tmp = muDoubleScalarHypot(re_tmp, q);
        im_tmp *= im_tmp;
        b_F_e[loop_ub].re = im_tmp * re_tmp;
        b_F_e[loop_ub].im = im_tmp * q;
      }
      fft(b_F_e, Psi);
      for (i3 = 0; i3 < 256; i3++) {
        b_i = (b_i2 + 3 * i3) + 1;
        ind_s = exp_plus_omega_contents[b_i].im;
        re_tmp = exp_plus_omega_contents[b_i].re;
        re = 0.0 * re_tmp - ind_s;
        im = 0.0 * ind_s + re_tmp;
        re_tmp = Temp->Eq.gamma_Kerr[i3];
        im_tmp = re_tmp * Psi[i3].re;
        q = re_tmp * Psi[i3].im;
        Psi[i3].re = re * im_tmp - im * q;
        Psi[i3].im = re * q + im * im_tmp;
      }
      Psi[0].re += exp_plus_omega_contents[b_i2 + 1].re * c_d;
      Psi[0].im += exp_plus_omega_contents[b_i2 + 1].im * c_d;
      if (((int32_T)(b_i2 + 2U) < 1) || ((int32_T)(b_i2 + 2U) > b_d->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i2 + 2U), 1, b_d->size[0],
                                      &c_emlrtBCI, &st);
      }
      for (i3 = 0; i3 < 256; i3++) {
        b_d_data[(b_i2 + b_d->size[0] * i3) + 1] = Psi[i3];
        E_temp[i3] = F_e[i3];
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, Runge->s, mxDOUBLE_CLASS,
                                  (int32_T)Runge->s, &emlrtRTEI, &st);
    for (ii = 0; ii < i1; ii++) {
      if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > 3)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, 3, &g_emlrtBCI,
                                      &st);
      }
      re_tmp = Runge->c[ii];
      if (re_tmp != 0.0) {
        q = dt_tmp_tmp * re_tmp;
        if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > b_d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, b_d->size[0],
                                        &b_emlrtBCI, &st);
        }
        for (i3 = 0; i3 < 256; i3++) {
          re_tmp = Temp->Eq.mode_range[i3];
          b_i = (int32_T)muDoubleScalarFloor(re_tmp);
          if (re_tmp != b_i) {
            emlrtIntegerCheckR2012b(re_tmp, &k_emlrtDCI, &st);
          }
          loop_ub = (int32_T)re_tmp;
          if ((loop_ub < 1) || (loop_ub > 256)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 256, &k_emlrtBCI, &st);
          }
          if (loop_ub != b_i) {
            emlrtIntegerCheckR2012b(re_tmp, &l_emlrtDCI, &st);
          }
          b_F_e[i3].re = F_e[loop_ub - 1].re +
                         q * b_d_data[ii + b_d->size[0] * (loop_ub - 1)].re;
          if (loop_ub != b_i) {
            emlrtIntegerCheckR2012b(re_tmp, &k_emlrtDCI, &st);
          }
          b_F_e[i3].im = F_e[loop_ub - 1].im +
                         q * b_d_data[ii + b_d->size[0] * (loop_ub - 1)].im;
        }
        for (i3 = 0; i3 < 256; i3++) {
          re_tmp = Temp->Eq.mode_range[i3];
          b_i = (int32_T)muDoubleScalarFloor(re_tmp);
          if (re_tmp != b_i) {
            emlrtIntegerCheckR2012b(re_tmp, &o_emlrtDCI, &st);
          }
          loop_ub = (int32_T)re_tmp;
          if ((loop_ub < 1) || (loop_ub > 256)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 256, &m_emlrtBCI, &st);
          }
          F_e[loop_ub - 1].re = b_F_e[i3].re;
          if (loop_ub != b_i) {
            emlrtIntegerCheckR2012b(re_tmp, &o_emlrtDCI, &st);
          }
          F_e[loop_ub - 1].im = b_F_e[i3].im;
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    for (i3 = 0; i3 < 256; i3++) {
      re_tmp = Temp->Eq.mode_range[i3];
      b_i = (int32_T)muDoubleScalarFloor(re_tmp);
      if (re_tmp != b_i) {
        emlrtIntegerCheckR2012b(re_tmp, &r_emlrtDCI, &st);
      }
      loop_ub = (int32_T)re_tmp;
      if ((loop_ub < 1) || (loop_ub > 256)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 256, &q_emlrtBCI, &st);
      }
      if (loop_ub != b_i) {
        emlrtIntegerCheckR2012b(re_tmp, &r_emlrtDCI, &st);
      }
      q = dcv[loop_ub - 1].re;
      im_tmp = F_e[loop_ub - 1].im;
      nt = dcv[loop_ub - 1].im;
      ind_s = F_e[loop_ub - 1].re;
      Psi[i3].re = q * ind_s - nt * im_tmp;
      if (loop_ub != b_i) {
        emlrtIntegerCheckR2012b(re_tmp, &r_emlrtDCI, &st);
      }
      Psi[i3].im = q * im_tmp + nt * ind_s;
    }
    for (i3 = 0; i3 < 256; i3++) {
      re_tmp = Temp->Eq.mode_range[i3];
      b_i = (int32_T)muDoubleScalarFloor(re_tmp);
      if (re_tmp != b_i) {
        emlrtIntegerCheckR2012b(re_tmp, &j_emlrtDCI, &st);
      }
      loop_ub = (int32_T)re_tmp;
      if ((loop_ub < 1) || (loop_ub > 256)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 256, &j_emlrtBCI, &st);
      }
      F_e[loop_ub - 1].re = Psi[i3].re;
      if (loop_ub != b_i) {
        emlrtIntegerCheckR2012b(re_tmp, &j_emlrtDCI, &st);
      }
      F_e[loop_ub - 1].im = Psi[i3].im;
    }
    /* ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back */
    r = (real_T)ni + 1.0;
    if (!(y == 0.0)) {
      if (muDoubleScalarIsNaN(y)) {
        r = rtNaN;
      } else if (muDoubleScalarIsInf(y)) {
        if (y < 0.0) {
          r = y;
        }
      } else {
        r = muDoubleScalarRem((real_T)ni + 1.0, y);
        rEQ0 = (r == 0.0);
        if ((!rEQ0) && (y > muDoubleScalarFloor(y))) {
          q = muDoubleScalarAbs(((real_T)ni + 1.0) / y);
          rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
                   2.2204460492503131E-16 * q);
        }
        if (rEQ0) {
          r = y * 0.0;
        } else if (y < 0.0) {
          r += y;
        }
      }
    }
    if (r == 0.0) {
      nt = ((real_T)ni + 1.0) * dt_tmp_tmp;
      ind_s = muDoubleScalarRound(nt / Temp->Par.s_t);
      for (i3 = 0; i3 < 256; i3++) {
        re_tmp = Temp->Eq.mode_range[i3];
        if (re_tmp != (int32_T)muDoubleScalarFloor(re_tmp)) {
          emlrtIntegerCheckR2012b(re_tmp, &q_emlrtDCI, (emlrtCTX)sp);
        }
        if (((int32_T)re_tmp < 1) || ((int32_T)re_tmp > 256)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)re_tmp, 1, 256, &o_emlrtBCI,
                                        (emlrtCTX)sp);
        }
      }
      if (ind_s != (int32_T)ind_s) {
        emlrtIntegerCheckR2012b(ind_s, &emlrtDCI, (emlrtCTX)sp);
      }
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->Psi->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->Psi->size[0],
                                      &emlrtBCI, (emlrtCTX)sp);
      }
      for (i3 = 0; i3 < 256; i3++) {
        b_i = (int32_T)Temp->Eq.mode_range[i3] - 1;
        q = F_e[b_i].re;
        im_tmp = F_e[b_i].im;
        if (im_tmp == 0.0) {
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].re =
              q / Temp->Space.N;
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].im =
              0.0;
        } else if (q == 0.0) {
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].re =
              0.0;
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].im =
              im_tmp / Temp->Space.N;
        } else {
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].re =
              q / Temp->Space.N;
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].im =
              im_tmp / Temp->Space.N;
        }
      }
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->t->size[1],
                                      &p_emlrtBCI, (emlrtCTX)sp);
      }
      Sol->t->data[(int32_T)ind_s - 1].re = nt;
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->t->size[1],
                                      &p_emlrtBCI, (emlrtCTX)sp);
      }
      Sol->t->data[(int32_T)ind_s - 1].im = 0.0;
      /*              if 10*log10(sum(abs(Sol.Psi(ind_s,2:end)).^2)) <= -70 &&
       * (mod(ind_s,2) ==0) */
      /*   */
      /*                      Sol.Psi(ind_s+1:end,:) = []; */
      /*                      Sol.t(ind_s+1:end)     = [];                 */
      /*                      break; */
      /*   */
      /*              end */
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_creal_T(sp, &b_d);
  emxFree_cuint8_T(sp, &d);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (Chi_3_LLE_Runge_Kuarong.c) */
