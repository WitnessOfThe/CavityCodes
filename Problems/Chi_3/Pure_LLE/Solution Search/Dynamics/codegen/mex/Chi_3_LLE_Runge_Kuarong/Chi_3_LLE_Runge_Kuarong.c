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
#include "exp.h"
#include "fft.h"
#include "ifft.h"
#include "nullAssignment.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 41,    /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 40,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 38,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 31,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 18,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 14,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 13,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 3,   /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 56,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 70,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 18, /* lineNo */
  "abs",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m"/* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  49,                                  /* colNo */
  "Sol.Psi",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  47,                                  /* colNo */
  "Sol.Psi",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  41,                                  /* colNo */
  "Sol.Psi",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  35,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  21,                                  /* colNo */
  "Sol.Psi",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 35,    /* lineNo */
  21,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 29,  /* lineNo */
  14,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  14,                                  /* lineNo */
  9,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  13,                                  /* lineNo */
  9,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  11,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 58,/* lineNo */
  18,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 60,/* lineNo */
  22,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  105,                                 /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { 2,   /* nDims */
  64,                                  /* lineNo */
  55,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  64,                                  /* lineNo */
  21,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  70,                                  /* lineNo */
  66,                                  /* colNo */
  "exp_plus_omega",                    /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  15,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = { 76,/* lineNo */
  18,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  90,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { 2,   /* nDims */
  80,                                  /* lineNo */
  46,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  80,                                  /* lineNo */
  17,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { 2,   /* nDims */
  86,                                  /* lineNo */
  38,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  86,                                  /* lineNo */
  12,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { 2,   /* nDims */
  90,                                  /* lineNo */
  47,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Chi_3_LLE_Kuar_ins",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo k_emlrtECI = { 2,   /* nDims */
  94,                                  /* lineNo */
  34,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Chi_3_LLE_Kuar_ins",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { 2,   /* nDims */
  94,                                  /* lineNo */
  19,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Chi_3_LLE_Kuar_ins",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  40,                                  /* colNo */
  "Fac_plus",                          /* aName */
  "Chi_3_LLE_Runge_Kuarong/Chi_3_LLE_Kuar_ins",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 25,  /* lineNo */
  29,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 25,  /* lineNo */
  29,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 26,  /* lineNo */
  31,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 3,   /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 25,  /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 26,  /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  78,                                  /* lineNo */
  17,                                  /* colNo */
  "Runge.c",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  62,                                  /* lineNo */
  20,                                  /* colNo */
  "Runge.b",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 86,  /* lineNo */
  49,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  49,                                  /* colNo */
  "shift_back",                        /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 80,  /* lineNo */
  50,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  80,                                  /* lineNo */
  50,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 64,  /* lineNo */
  62,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  64,                                  /* lineNo */
  62,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 86,  /* lineNo */
  74,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  86,                                  /* lineNo */
  74,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 80,  /* lineNo */
  21,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  80,                                  /* lineNo */
  21,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 64,  /* lineNo */
  28,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  64,                                  /* lineNo */
  28,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 35,  /* lineNo */
  37,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  35,                                  /* lineNo */
  37,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  13,                                  /* colNo */
  "Sol.t",                             /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  80,                                  /* lineNo */
  72,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 80,  /* lineNo */
  72,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  64,                                  /* lineNo */
  84,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 64,  /* lineNo */
  84,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo k_emlrtRTEI = { 3, /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 8, /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 9, /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 18,/* lineNo */
  18,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 13,/* lineNo */
  32,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 14,/* lineNo */
  32,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 31,/* lineNo */
  61,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 56,/* lineNo */
  66,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 94,/* lineNo */
  19,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 86,/* lineNo */
  74,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 70,/* lineNo */
  72,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 86,/* lineNo */
  38,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 80,/* lineNo */
  72,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 64,/* lineNo */
  84,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 80,/* lineNo */
  21,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 64,/* lineNo */
  28,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 80,/* lineNo */
  46,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 64,/* lineNo */
  55,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 35,/* lineNo */
  33,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 38,/* lineNo */
  33,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 31,/* lineNo */
  21,                                  /* colNo */
  "applyScalarFunction",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 40,/* lineNo */
  29,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 41,/* lineNo */
  27,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 38,/* lineNo */
  29,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"/* pName */
};

/* Function Definitions */
void Chi_3_LLE_Runge_Kuarong(const emlrtStack *sp, const struct0_T *Temp, real_T
  N_modes, const struct5_T *Runge, struct6_T *Sol)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_creal_T *E_temp;
  emxArray_creal_T *b_Sol;
  emxArray_creal_T *b_exp_minus_omega_contents;
  emxArray_creal_T *c_d;
  emxArray_creal_T *exp_minus_omega_contents;
  emxArray_creal_T *exp_plus_omega_contents;
  emxArray_creal_T *r;
  emxArray_cuint8_T *d;
  emxArray_int32_T *r1;
  emxArray_real_T *r2;
  emxArray_real_T *y;
  creal_T F_e[256];
  creal_T Psi[256];
  creal_T b_E_temp[256];
  creal_T b_F_e[256];
  real_T abs_Psi_2[256];
  real_T Temp_im;
  real_T Temp_re;
  real_T b_d;
  real_T contents_Eq_h;
  real_T dt;
  real_T ind_s;
  real_T nt;
  real_T q;
  int32_T iv[2];
  int32_T b_i2;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T ii;
  int32_T loop_ub;
  int32_T loop_ub_tmp;
  int32_T ni;
  int32_T nx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T rEQ0;
  (void)N_modes;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_cuint8_T(sp, &d, 2, &k_emlrtRTEI, true);
  st.site = &h_emlrtRSI;
  contents_Eq_h = Temp->Eq.h;
  st.site = &h_emlrtRSI;
  st.site = &h_emlrtRSI;
  st.site = &h_emlrtRSI;
  st.site = &h_emlrtRSI;
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &c_emlrtDCI, sp);
  }

  b_d = (int32_T)muDoubleScalarFloor(Runge->s);
  if (Runge->s != b_d) {
    emlrtIntegerCheckR2012b(Runge->s, &b_emlrtDCI, sp);
  }

  i = d->size[0] * d->size[1];
  d->size[0] = (int32_T)Runge->s;
  d->size[1] = 256;
  emxEnsureCapacity_cuint8_T(sp, d, i, &k_emlrtRTEI);
  if (Runge->s != b_d) {
    emlrtIntegerCheckR2012b(Runge->s, &g_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Runge->s << 8;
  for (i = 0; i < loop_ub; i++) {
    d->data[i].re = 0U;
    d->data[i].im = 0U;
  }

  emxInit_creal_T(sp, &exp_minus_omega_contents, 2, &l_emlrtRTEI, true);
  dt = Temp->Par.dt;
  nt = Temp->Par.T / Temp->Par.dt;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  i = exp_minus_omega_contents->size[0] * exp_minus_omega_contents->size[1];
  exp_minus_omega_contents->size[0] = 3;
  exp_minus_omega_contents->size[1] = Temp->Eq.L.size[1];
  emxEnsureCapacity_creal_T(sp, exp_minus_omega_contents, i, &l_emlrtRTEI);
  loop_ub_tmp = 3 * Temp->Eq.L.size[1];
  for (i = 0; i < loop_ub_tmp; i++) {
    exp_minus_omega_contents->data[i].re = 0.0;
    exp_minus_omega_contents->data[i].im = 0.0;
  }

  emxInit_creal_T(sp, &exp_plus_omega_contents, 2, &m_emlrtRTEI, true);
  i = exp_plus_omega_contents->size[0] * exp_plus_omega_contents->size[1];
  exp_plus_omega_contents->size[0] = 3;
  exp_plus_omega_contents->size[1] = Temp->Eq.L.size[1];
  emxEnsureCapacity_creal_T(sp, exp_plus_omega_contents, i, &m_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    exp_plus_omega_contents->data[i].re = 0.0;
    exp_plus_omega_contents->data[i].im = 0.0;
  }

  loop_ub_tmp = Temp->Eq.L.size[0] * Temp->Eq.L.size[1];
  emxInit_creal_T(sp, &r, 2, &kb_emlrtRTEI, true);
  for (nx = 0; nx < 3; nx++) {
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = Temp->Eq.L.size[1];
    emxEnsureCapacity_creal_T(sp, r, i, &o_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      b_d = Runge->a[nx];
      Temp_re = Temp->Eq.L.data[i].re;
      Temp_im = Temp->Eq.L.data[i].im;
      r->data[i].re = dt * (b_d * (0.0 * Temp_re - (-Temp_im)));
      r->data[i].im = dt * (b_d * (0.0 * Temp_im + -Temp_re));
    }

    st.site = &g_emlrtRSI;
    b_exp(&st, r);
    iv[0] = 1;
    iv[1] = exp_minus_omega_contents->size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &r->size[0], 2, &c_emlrtECI, sp);
    loop_ub = r->size[1];
    for (i = 0; i < loop_ub; i++) {
      exp_minus_omega_contents->data[nx + 3 * i] = r->data[i];
    }

    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = Temp->Eq.L.size[1];
    emxEnsureCapacity_creal_T(sp, r, i, &p_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      b_d = Runge->a[nx];
      Temp_re = Temp->Eq.L.data[i].re;
      Temp_im = Temp->Eq.L.data[i].im;
      r->data[i].re = dt * (b_d * (0.0 * Temp_re - Temp_im));
      r->data[i].im = dt * (b_d * (0.0 * Temp_im + Temp_re));
    }

    st.site = &f_emlrtRSI;
    b_exp(&st, r);
    iv[0] = 1;
    iv[1] = exp_plus_omega_contents->size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &r->size[0], 2, &b_emlrtECI, sp);
    loop_ub = r->size[1];
    for (i = 0; i < loop_ub; i++) {
      exp_plus_omega_contents->data[nx + 3 * i] = r->data[i];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = Temp->Eq.L.size[1];
  emxEnsureCapacity_creal_T(sp, r, i, &n_emlrtRTEI);
  for (i = 0; i < loop_ub_tmp; i++) {
    r->data[i].re = Temp->Par.dt * (0.0 * Temp->Eq.L.data[i].re -
      (-Temp->Eq.L.data[i].im));
    r->data[i].im = Temp->Par.dt * (0.0 * Temp->Eq.L.data[i].im +
      -Temp->Eq.L.data[i].re);
  }

  st.site = &e_emlrtRSI;
  b_exp(&st, r);

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  memcpy(&F_e[0], &Temp->In.Psi_Start[0], 256U * sizeof(creal_T));
  if (!(Temp->Par.dd >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Par.dd, &e_emlrtDCI, sp);
  }

  b_d = (int32_T)muDoubleScalarFloor(Temp->Par.dd);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &d_emlrtDCI, sp);
  }

  i = Sol->Psi->size[0] * Sol->Psi->size[1];
  Sol->Psi->size[0] = (int32_T)Temp->Par.dd;
  Sol->Psi->size[1] = Temp->Eq.mode_range.size[1];
  emxEnsureCapacity_creal_T(sp, Sol->Psi, i, &q_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &h_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd * Temp->Eq.mode_range.size[1];
  for (i = 0; i < loop_ub; i++) {
    Sol->Psi->data[i].re = 0.0;
    Sol->Psi->data[i].im = 0.0;
  }

  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &r_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &f_emlrtDCI, sp);
  }

  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[1] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &r_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &i_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd;
  for (i = 0; i < loop_ub; i++) {
    Sol->t->data[i].re = 0.0;
    Sol->t->data[i].im = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nt, mxDOUBLE_CLASS, (int32_T)nt,
    &emlrtRTEI, sp);
  ni = 0;
  emxInit_creal_T(sp, &c_d, 2, &s_emlrtRTEI, true);
  emxInit_int32_T(sp, &r1, 2, &v_emlrtRTEI, true);
  emxInit_real_T(sp, &y, 2, &lb_emlrtRTEI, true);
  emxInit_real_T(sp, &r2, 2, &lb_emlrtRTEI, true);
  emxInit_creal_T(sp, &b_exp_minus_omega_contents, 2, &t_emlrtRTEI, true);
  emxInit_creal_T(sp, &E_temp, 1, &eb_emlrtRTEI, true);
  emxInit_creal_T(sp, &b_Sol, 2, &gb_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (ni <= (int32_T)nt - 1)) {
    st.site = &d_emlrtRSI;
    i = c_d->size[0] * c_d->size[1];
    c_d->size[0] = d->size[0];
    c_d->size[1] = 256;
    emxEnsureCapacity_creal_T(&st, c_d, i, &s_emlrtRTEI);
    loop_ub = d->size[0] * d->size[1];
    for (i = 0; i < loop_ub; i++) {
      c_d->data[i].re = d->data[i].re;
      c_d->data[i].im = d->data[i].im;
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    memcpy(&b_E_temp[0], &F_e[0], 256U * sizeof(creal_T));
    if (1 > d->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, d->size[0], &e_emlrtBCI, &st);
    }

    b_st.site = &m_emlrtRSI;
    loop_ub = exp_minus_omega_contents->size[1];
    i = b_exp_minus_omega_contents->size[0] * b_exp_minus_omega_contents->size[1];
    b_exp_minus_omega_contents->size[0] = 1;
    b_exp_minus_omega_contents->size[1] = exp_minus_omega_contents->size[1];
    emxEnsureCapacity_creal_T(&b_st, b_exp_minus_omega_contents, i, &t_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_exp_minus_omega_contents->data[i] = exp_minus_omega_contents->data[3 * i];
    }

    iv[0] = 1;
    iv[1] = 256;
    emlrtSizeEqCheckNDR2012b(iv, *(int32_T (*)[2])
      b_exp_minus_omega_contents->size, &j_emlrtECI, &b_st);
    loop_ub = exp_minus_omega_contents->size[1];
    i = b_exp_minus_omega_contents->size[0] * b_exp_minus_omega_contents->size[1];
    b_exp_minus_omega_contents->size[0] = 1;
    b_exp_minus_omega_contents->size[1] = exp_minus_omega_contents->size[1];
    emxEnsureCapacity_creal_T(&b_st, b_exp_minus_omega_contents, i, &t_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_exp_minus_omega_contents->data[i] = exp_minus_omega_contents->data[3 * i];
    }

    for (i = 0; i < 256; i++) {
      b_d = F_e[i].re;
      Temp_re = F_e[i].im;
      b_F_e[i].re = b_d * b_exp_minus_omega_contents->data[i].re - Temp_re *
        b_exp_minus_omega_contents->data[i].im;
      b_F_e[i].im = b_d * b_exp_minus_omega_contents->data[i].im + Temp_re *
        b_exp_minus_omega_contents->data[i].re;
    }

    ifft(b_F_e, Psi);
    for (loop_ub_tmp = 0; loop_ub_tmp < 256; loop_ub_tmp++) {
      b_d = muDoubleScalarHypot(Psi[loop_ub_tmp].re, Psi[loop_ub_tmp].im);
      abs_Psi_2[loop_ub_tmp] = b_d * b_d;
    }

    iv[0] = 1;
    iv[1] = 256;
    emlrtSizeEqCheckNDR2012b(Temp->Eq.gamma_Kerr.size, iv, &k_emlrtECI, &b_st);
    loop_ub = exp_plus_omega_contents->size[1];
    i = b_exp_minus_omega_contents->size[0] * b_exp_minus_omega_contents->size[1];
    b_exp_minus_omega_contents->size[0] = 1;
    b_exp_minus_omega_contents->size[1] = exp_plus_omega_contents->size[1];
    emxEnsureCapacity_creal_T(&b_st, b_exp_minus_omega_contents, i, &u_emlrtRTEI);
    for (i = 0; i < loop_ub; i++) {
      b_exp_minus_omega_contents->data[i].re = 0.0 *
        exp_plus_omega_contents->data[3 * i].re - exp_plus_omega_contents->data
        [3 * i].im;
      b_exp_minus_omega_contents->data[i].im = 0.0 *
        exp_plus_omega_contents->data[3 * i].im + exp_plus_omega_contents->data
        [3 * i].re;
    }

    iv[0] = 1;
    iv[1] = 256;
    emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])b_exp_minus_omega_contents->size,
      iv, &l_emlrtECI, &b_st);
    for (i = 0; i < 256; i++) {
      b_d = abs_Psi_2[i];
      b_F_e[i].re = b_d * Psi[i].re;
      b_F_e[i].im = b_d * Psi[i].im;
    }

    fft(b_F_e, Psi);
    for (i = 0; i < 256; i++) {
      b_d = Temp->Eq.gamma_Kerr.data[i];
      Temp_re = b_d * Psi[i].re;
      Temp_im = b_d * Psi[i].im;
      Psi[i].re = b_exp_minus_omega_contents->data[i].re * Temp_re -
        b_exp_minus_omega_contents->data[i].im * Temp_im;
      Psi[i].im = b_exp_minus_omega_contents->data[i].re * Temp_im +
        b_exp_minus_omega_contents->data[i].im * Temp_re;
    }

    if (1 > exp_plus_omega_contents->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, exp_plus_omega_contents->size[1],
        &j_emlrtBCI, &b_st);
    }

    Psi[0].re += (0.0 * exp_plus_omega_contents->data[0].re -
                  exp_plus_omega_contents->data[0].im) * (256.0 * contents_Eq_h);
    Psi[0].im += (0.0 * exp_plus_omega_contents->data[0].im +
                  exp_plus_omega_contents->data[0].re) * (256.0 * contents_Eq_h);
    for (i = 0; i < 256; i++) {
      c_d->data[c_d->size[0] * i] = Psi[i];
    }

    i = (int32_T)(Runge->s + -1.0);
    emlrtForLoopVectorCheckR2012b(2.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      (Runge->s + -1.0), &b_emlrtRTEI, &st);
    if (0 <= i - 1) {
      i1 = (int32_T)(Runge->s - 1.0);
    }

    for (i2 = 0; i2 < i; i2++) {
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
        (int32_T)(Runge->s - 1.0), &c_emlrtRTEI, &st);
      for (ii = 0; ii < i1; ii++) {
        if (((int32_T)(i2 + 2U) < 1) || ((int32_T)(i2 + 2U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(i2 + 2U), 1, 3, &l_emlrtBCI,
            &st);
        }

        if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, 3, &l_emlrtBCI,
            &st);
        }

        b_d = Runge->b[(i2 + 3 * ii) + 1];
        if (b_d != 0.0) {
          loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
          for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
            Temp_re = Temp->Eq.mode_range.data[b_i2];
            if (Temp_re != (int32_T)muDoubleScalarFloor(Temp_re)) {
              emlrtIntegerCheckR2012b(Temp_re, &l_emlrtDCI, &st);
            }

            if (((int32_T)Temp_re < 1) || ((int32_T)Temp_re > 256)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)Temp_re, 1, 256,
                &o_emlrtBCI, &st);
            }
          }

          Temp_im = dt * b_d;
          if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > c_d->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, c_d->size[0],
              &f_emlrtBCI, &st);
          }

          b_i2 = b_exp_minus_omega_contents->size[0] *
            b_exp_minus_omega_contents->size[1];
          b_exp_minus_omega_contents->size[0] = 1;
          loop_ub = Temp->Eq.mode_range.size[1];
          b_exp_minus_omega_contents->size[1] = Temp->Eq.mode_range.size[1];
          emxEnsureCapacity_creal_T(&st, b_exp_minus_omega_contents, b_i2,
            &ab_emlrtRTEI);
          for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
            b_d = Temp->Eq.mode_range.data[b_i2];
            nx = (int32_T)muDoubleScalarFloor(b_d);
            if (b_d != nx) {
              emlrtIntegerCheckR2012b(b_d, &r_emlrtDCI, &st);
            }

            loop_ub_tmp = (int32_T)b_d;
            if ((loop_ub_tmp < 1) || (loop_ub_tmp > 256)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub_tmp, 1, 256, &v_emlrtBCI,
                &st);
            }

            b_exp_minus_omega_contents->data[b_i2].re = Temp_im * c_d->data[ii +
              c_d->size[0] * (loop_ub_tmp - 1)].re;
            if (loop_ub_tmp != nx) {
              emlrtIntegerCheckR2012b(b_d, &r_emlrtDCI, &st);
            }

            b_exp_minus_omega_contents->data[b_i2].im = Temp_im * c_d->data[ii +
              c_d->size[0] * (loop_ub_tmp - 1)].im;
          }

          emlrtSizeEqCheckNDR2012b(Temp->Eq.mode_range.size, *(int32_T (*)[2])
            b_exp_minus_omega_contents->size, &d_emlrtECI, &st);
          b_i2 = r1->size[0] * r1->size[1];
          r1->size[0] = 1;
          r1->size[1] = Temp->Eq.mode_range.size[1];
          emxEnsureCapacity_int32_T(&st, r1, b_i2, &cb_emlrtRTEI);
          loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
          for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
            b_d = Temp->Eq.mode_range.data[b_i2];
            if (b_d != (int32_T)muDoubleScalarFloor(b_d)) {
              emlrtIntegerCheckR2012b(b_d, &o_emlrtDCI, &st);
            }

            if (((int32_T)b_d < 1) || ((int32_T)b_d > 256)) {
              emlrtDynamicBoundsCheckR2012b((int32_T)b_d, 1, 256, &r_emlrtBCI,
                &st);
            }

            r1->data[b_i2] = (int32_T)b_d;
          }

          if (r1->size[1] != Temp->Eq.mode_range.size[1]) {
            emlrtSubAssignSizeCheck1dR2017a(r1->size[1],
              Temp->Eq.mode_range.size[1], &e_emlrtECI, &st);
          }

          loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
          b_i2 = E_temp->size[0];
          E_temp->size[0] = loop_ub;
          emxEnsureCapacity_creal_T(&st, E_temp, b_i2, &eb_emlrtRTEI);
          for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
            nx = (int32_T)Temp->Eq.mode_range.data[b_i2] - 1;
            E_temp->data[b_i2].re = b_E_temp[nx].re +
              b_exp_minus_omega_contents->data[b_i2].re;
            E_temp->data[b_i2].im = b_E_temp[nx].im +
              b_exp_minus_omega_contents->data[b_i2].im;
          }

          loop_ub = E_temp->size[0];
          for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
            b_E_temp[r1->data[b_i2] - 1] = E_temp->data[b_i2];
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      b_st.site = &n_emlrtRSI;
      if ((i2 + 2 < 1) || (i2 + 2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i2 + 2, 1, 3, &g_emlrtBCI, &b_st);
      }

      loop_ub = exp_minus_omega_contents->size[1];
      b_i2 = b_exp_minus_omega_contents->size[0] *
        b_exp_minus_omega_contents->size[1];
      b_exp_minus_omega_contents->size[0] = 1;
      b_exp_minus_omega_contents->size[1] = exp_minus_omega_contents->size[1];
      emxEnsureCapacity_creal_T(&b_st, b_exp_minus_omega_contents, b_i2,
        &w_emlrtRTEI);
      for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
        b_exp_minus_omega_contents->data[b_i2] = exp_minus_omega_contents->data
          [(i2 + 3 * b_i2) + 1];
      }

      iv[0] = 1;
      iv[1] = 256;
      emlrtSizeEqCheckNDR2012b(iv, *(int32_T (*)[2])
        b_exp_minus_omega_contents->size, &j_emlrtECI, &b_st);
      loop_ub = exp_minus_omega_contents->size[1];
      b_i2 = b_exp_minus_omega_contents->size[0] *
        b_exp_minus_omega_contents->size[1];
      b_exp_minus_omega_contents->size[0] = 1;
      b_exp_minus_omega_contents->size[1] = exp_minus_omega_contents->size[1];
      emxEnsureCapacity_creal_T(&b_st, b_exp_minus_omega_contents, b_i2,
        &w_emlrtRTEI);
      for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
        b_exp_minus_omega_contents->data[b_i2] = exp_minus_omega_contents->data
          [(i2 + 3 * b_i2) + 1];
      }

      for (b_i2 = 0; b_i2 < 256; b_i2++) {
        b_d = b_E_temp[b_i2].re;
        Temp_re = b_E_temp[b_i2].im;
        Temp_im = b_d * b_exp_minus_omega_contents->data[b_i2].im + Temp_re *
          b_exp_minus_omega_contents->data[b_i2].re;
        b_d = b_d * b_exp_minus_omega_contents->data[b_i2].re - Temp_re *
          b_exp_minus_omega_contents->data[b_i2].im;
        b_E_temp[b_i2].re = b_d;
        b_E_temp[b_i2].im = Temp_im;
      }

      ifft(b_E_temp, Psi);
      for (loop_ub_tmp = 0; loop_ub_tmp < 256; loop_ub_tmp++) {
        b_d = muDoubleScalarHypot(Psi[loop_ub_tmp].re, Psi[loop_ub_tmp].im);
        abs_Psi_2[loop_ub_tmp] = b_d * b_d;
      }

      iv[0] = 1;
      iv[1] = 256;
      emlrtSizeEqCheckNDR2012b(Temp->Eq.gamma_Kerr.size, iv, &k_emlrtECI, &b_st);
      loop_ub = exp_plus_omega_contents->size[1];
      b_i2 = b_exp_minus_omega_contents->size[0] *
        b_exp_minus_omega_contents->size[1];
      b_exp_minus_omega_contents->size[0] = 1;
      b_exp_minus_omega_contents->size[1] = exp_plus_omega_contents->size[1];
      emxEnsureCapacity_creal_T(&b_st, b_exp_minus_omega_contents, b_i2,
        &u_emlrtRTEI);
      for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
        nx = (i2 + 3 * b_i2) + 1;
        b_exp_minus_omega_contents->data[b_i2].re = 0.0 *
          exp_plus_omega_contents->data[nx].re - exp_plus_omega_contents->
          data[nx].im;
        b_exp_minus_omega_contents->data[b_i2].im = 0.0 *
          exp_plus_omega_contents->data[nx].im + exp_plus_omega_contents->
          data[nx].re;
      }

      iv[0] = 1;
      iv[1] = 256;
      emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])b_exp_minus_omega_contents->size,
        iv, &l_emlrtECI, &b_st);
      for (b_i2 = 0; b_i2 < 256; b_i2++) {
        b_d = abs_Psi_2[b_i2];
        b_F_e[b_i2].re = b_d * Psi[b_i2].re;
        b_F_e[b_i2].im = b_d * Psi[b_i2].im;
      }

      fft(b_F_e, Psi);
      for (b_i2 = 0; b_i2 < 256; b_i2++) {
        b_d = Temp->Eq.gamma_Kerr.data[b_i2];
        Temp_re = b_d * Psi[b_i2].re;
        Temp_im = b_d * Psi[b_i2].im;
        Psi[b_i2].re = b_exp_minus_omega_contents->data[b_i2].re * Temp_re -
          b_exp_minus_omega_contents->data[b_i2].im * Temp_im;
        Psi[b_i2].im = b_exp_minus_omega_contents->data[b_i2].re * Temp_im +
          b_exp_minus_omega_contents->data[b_i2].im * Temp_re;
      }

      if (1 > exp_plus_omega_contents->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, exp_plus_omega_contents->size[1],
          &j_emlrtBCI, &b_st);
      }

      Psi[0].re += (0.0 * exp_plus_omega_contents->data[i2 + 1].re -
                    exp_plus_omega_contents->data[i2 + 1].im) * (256.0 *
        contents_Eq_h);
      Psi[0].im += (0.0 * exp_plus_omega_contents->data[i2 + 1].im +
                    exp_plus_omega_contents->data[i2 + 1].re) * (256.0 *
        contents_Eq_h);
      if (((int32_T)(i2 + 2U) < 1) || ((int32_T)(i2 + 2U) > c_d->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(i2 + 2U), 1, c_d->size[0],
          &h_emlrtBCI, &st);
      }

      for (b_i2 = 0; b_i2 < 256; b_i2++) {
        c_d->data[(i2 + c_d->size[0] * b_i2) + 1] = Psi[b_i2];
        b_E_temp[b_i2] = F_e[b_i2];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    i = (int32_T)Runge->s;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      Runge->s, &d_emlrtRTEI, &st);
    for (ii = 0; ii < i; ii++) {
      if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > 3)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, 3, &k_emlrtBCI, &st);
      }

      if (Runge->c[ii] != 0.0) {
        loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
        for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
          b_d = Temp->Eq.mode_range.data[b_i2];
          if (b_d != (int32_T)muDoubleScalarFloor(b_d)) {
            emlrtIntegerCheckR2012b(b_d, &k_emlrtDCI, &st);
          }

          if (((int32_T)b_d < 1) || ((int32_T)b_d > 256)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)b_d, 1, 256, &n_emlrtBCI, &st);
          }
        }

        Temp_im = dt * Runge->c[ii];
        if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > c_d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, c_d->size[0],
            &i_emlrtBCI, &st);
        }

        b_i2 = b_exp_minus_omega_contents->size[0] *
          b_exp_minus_omega_contents->size[1];
        b_exp_minus_omega_contents->size[0] = 1;
        loop_ub = Temp->Eq.mode_range.size[1];
        b_exp_minus_omega_contents->size[1] = Temp->Eq.mode_range.size[1];
        emxEnsureCapacity_creal_T(&st, b_exp_minus_omega_contents, b_i2,
          &y_emlrtRTEI);
        for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
          b_d = Temp->Eq.mode_range.data[b_i2];
          nx = (int32_T)muDoubleScalarFloor(b_d);
          if (b_d != nx) {
            emlrtIntegerCheckR2012b(b_d, &q_emlrtDCI, &st);
          }

          loop_ub_tmp = (int32_T)b_d;
          if ((loop_ub_tmp < 1) || (loop_ub_tmp > 256)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub_tmp, 1, 256, &u_emlrtBCI, &st);
          }

          b_exp_minus_omega_contents->data[b_i2].re = Temp_im * c_d->data[ii +
            c_d->size[0] * (loop_ub_tmp - 1)].re;
          if (loop_ub_tmp != nx) {
            emlrtIntegerCheckR2012b(b_d, &q_emlrtDCI, &st);
          }

          b_exp_minus_omega_contents->data[b_i2].im = Temp_im * c_d->data[ii +
            c_d->size[0] * (loop_ub_tmp - 1)].im;
        }

        emlrtSizeEqCheckNDR2012b(Temp->Eq.mode_range.size, *(int32_T (*)[2])
          b_exp_minus_omega_contents->size, &f_emlrtECI, &st);
        b_i2 = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        r1->size[1] = Temp->Eq.mode_range.size[1];
        emxEnsureCapacity_int32_T(&st, r1, b_i2, &bb_emlrtRTEI);
        loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
        for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
          b_d = Temp->Eq.mode_range.data[b_i2];
          if (b_d != (int32_T)muDoubleScalarFloor(b_d)) {
            emlrtIntegerCheckR2012b(b_d, &n_emlrtDCI, &st);
          }

          if (((int32_T)b_d < 1) || ((int32_T)b_d > 256)) {
            emlrtDynamicBoundsCheckR2012b((int32_T)b_d, 1, 256, &q_emlrtBCI, &st);
          }

          r1->data[b_i2] = (int32_T)b_d;
        }

        if (r1->size[1] != Temp->Eq.mode_range.size[1]) {
          emlrtSubAssignSizeCheck1dR2017a(r1->size[1], Temp->Eq.mode_range.size
            [1], &g_emlrtECI, &st);
        }

        loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
        b_i2 = E_temp->size[0];
        E_temp->size[0] = loop_ub;
        emxEnsureCapacity_creal_T(&st, E_temp, b_i2, &db_emlrtRTEI);
        for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
          nx = (int32_T)Temp->Eq.mode_range.data[b_i2] - 1;
          E_temp->data[b_i2].re = F_e[nx].re + b_exp_minus_omega_contents->
            data[b_i2].re;
          E_temp->data[b_i2].im = F_e[nx].im + b_exp_minus_omega_contents->
            data[b_i2].im;
        }

        loop_ub = E_temp->size[0];
        for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
          F_e[r1->data[b_i2] - 1] = E_temp->data[b_i2];
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    loop_ub_tmp = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
    for (i = 0; i < loop_ub_tmp; i++) {
      b_d = Temp->Eq.mode_range.data[i];
      if (b_d != (int32_T)muDoubleScalarFloor(b_d)) {
        emlrtIntegerCheckR2012b(b_d, &j_emlrtDCI, &st);
      }

      if (((int32_T)b_d < 1) || ((int32_T)b_d > r->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_d, 1, r->size[1], &m_emlrtBCI,
          &st);
      }
    }

    i = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = Temp->Eq.mode_range.size[1];
    emxEnsureCapacity_int32_T(&st, r1, i, &v_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      b_d = Temp->Eq.mode_range.data[i];
      if (b_d != (int32_T)muDoubleScalarFloor(b_d)) {
        emlrtIntegerCheckR2012b(b_d, &m_emlrtDCI, &st);
      }

      if (((int32_T)b_d < 1) || ((int32_T)b_d > 256)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)b_d, 1, 256, &p_emlrtBCI, &st);
      }

      r1->data[i] = (int32_T)b_d;
    }

    emlrtSizeEqCheckNDR2012b(Temp->Eq.mode_range.size, *(int32_T (*)[2])r1->size,
      &h_emlrtECI, &st);
    i = b_exp_minus_omega_contents->size[0] * b_exp_minus_omega_contents->size[1];
    b_exp_minus_omega_contents->size[0] = 1;
    b_exp_minus_omega_contents->size[1] = Temp->Eq.mode_range.size[1];
    emxEnsureCapacity_creal_T(&st, b_exp_minus_omega_contents, i, &x_emlrtRTEI);
    for (i = 0; i < loop_ub_tmp; i++) {
      b_i2 = (int32_T)Temp->Eq.mode_range.data[i] - 1;
      b_exp_minus_omega_contents->data[i].re = r->data[b_i2].re * F_e[r1->data[i]
        - 1].re - r->data[b_i2].im * F_e[r1->data[i] - 1].im;
      b_exp_minus_omega_contents->data[i].im = r->data[b_i2].re * F_e[r1->data[i]
        - 1].im + r->data[b_i2].im * F_e[r1->data[i] - 1].re;
    }

    if (r1->size[1] != b_exp_minus_omega_contents->size[1]) {
      emlrtSubAssignSizeCheck1dR2017a(r1->size[1],
        b_exp_minus_omega_contents->size[1], &i_emlrtECI, &st);
    }

    loop_ub = b_exp_minus_omega_contents->size[0] *
      b_exp_minus_omega_contents->size[1];
    for (i = 0; i < loop_ub; i++) {
      F_e[r1->data[i] - 1] = b_exp_minus_omega_contents->data[i];
    }

    /* ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back */
    Temp_im = Temp->Par.s_t / Temp->Par.dt;
    Temp_re = (real_T)ni + 1.0;
    if (!(Temp_im == 0.0)) {
      if (muDoubleScalarIsNaN(Temp_im)) {
        Temp_re = rtNaN;
      } else if (muDoubleScalarIsInf(Temp_im)) {
        if (Temp_im < 0.0) {
          Temp_re = Temp_im;
        }
      } else {
        Temp_re = muDoubleScalarRem((real_T)ni + 1.0, Temp_im);
        rEQ0 = (Temp_re == 0.0);
        if ((!rEQ0) && (Temp_im > muDoubleScalarFloor(Temp_im))) {
          q = muDoubleScalarAbs(((real_T)ni + 1.0) / Temp_im);
          rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
                   2.2204460492503131E-16 * q);
        }

        if (rEQ0) {
          Temp_re = Temp_im * 0.0;
        } else {
          if (Temp_im < 0.0) {
            Temp_re += Temp_im;
          }
        }
      }
    }

    guard1 = false;
    if (Temp_re == 0.0) {
      q = ((real_T)ni + 1.0) * Temp->Par.dt;
      ind_s = muDoubleScalarRound(q / Temp->Par.s_t);
      if (ind_s != (int32_T)ind_s) {
        emlrtIntegerCheckR2012b(ind_s, &emlrtDCI, sp);
      }

      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->Psi->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->Psi->size[0],
          &d_emlrtBCI, sp);
      }

      for (i = 0; i < loop_ub_tmp; i++) {
        b_d = Temp->Eq.mode_range.data[i];
        if (b_d != (int32_T)muDoubleScalarFloor(b_d)) {
          emlrtIntegerCheckR2012b(b_d, &p_emlrtDCI, sp);
        }

        if (((int32_T)b_d < 1) || ((int32_T)b_d > 256)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_d, 1, 256, &s_emlrtBCI, sp);
        }
      }

      i = b_exp_minus_omega_contents->size[0] * b_exp_minus_omega_contents->
        size[1];
      b_exp_minus_omega_contents->size[0] = 1;
      b_exp_minus_omega_contents->size[1] = Temp->Eq.mode_range.size[1];
      emxEnsureCapacity_creal_T(sp, b_exp_minus_omega_contents, i, &fb_emlrtRTEI);
      for (i = 0; i < loop_ub_tmp; i++) {
        nx = (int32_T)Temp->Eq.mode_range.data[i] - 1;
        Temp_im = F_e[nx].re;
        Temp_re = F_e[nx].im;
        if (Temp_re == 0.0) {
          b_exp_minus_omega_contents->data[i].re = Temp_im / Temp->Space.N;
          b_exp_minus_omega_contents->data[i].im = 0.0;
        } else if (Temp_im == 0.0) {
          b_exp_minus_omega_contents->data[i].re = 0.0;
          b_exp_minus_omega_contents->data[i].im = Temp_re / Temp->Space.N;
        } else {
          b_exp_minus_omega_contents->data[i].re = Temp_im / Temp->Space.N;
          b_exp_minus_omega_contents->data[i].im = Temp_re / Temp->Space.N;
        }
      }

      iv[0] = 1;
      iv[1] = Sol->Psi->size[1];
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &b_exp_minus_omega_contents->
        size[0], 2, &emlrtECI, sp);
      loop_ub = b_exp_minus_omega_contents->size[1];
      for (i = 0; i < loop_ub; i++) {
        Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i) - 1] =
          b_exp_minus_omega_contents->data[i];
      }

      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->t->size[1],
          &t_emlrtBCI, sp);
      }

      Sol->t->data[(int32_T)ind_s - 1].re = q;
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->t->size[1],
          &t_emlrtBCI, sp);
      }

      Sol->t->data[(int32_T)ind_s - 1].im = 0.0;
      if (2 > Sol->Psi->size[1]) {
        i = 0;
        b_i2 = 0;
      } else {
        if (2 > Sol->Psi->size[1]) {
          emlrtDynamicBoundsCheckR2012b(2, 1, Sol->Psi->size[1], &b_emlrtBCI, sp);
        }

        i = 1;
        if (Sol->Psi->size[1] < 1) {
          emlrtDynamicBoundsCheckR2012b(Sol->Psi->size[1], 1, Sol->Psi->size[1],
            &emlrtBCI, sp);
        }

        b_i2 = Sol->Psi->size[1];
      }

      st.site = &c_emlrtRSI;
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->Psi->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->Psi->size[0],
          &c_emlrtBCI, &st);
      }

      nx = b_exp_minus_omega_contents->size[0] *
        b_exp_minus_omega_contents->size[1];
      b_exp_minus_omega_contents->size[0] = 1;
      loop_ub = b_i2 - i;
      b_exp_minus_omega_contents->size[1] = loop_ub;
      emxEnsureCapacity_creal_T(&st, b_exp_minus_omega_contents, nx,
        &gb_emlrtRTEI);
      for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
        b_exp_minus_omega_contents->data[b_i2] = Sol->Psi->data[((int32_T)ind_s
          + Sol->Psi->size[0] * (i + b_i2)) - 1];
      }

      b_st.site = &bb_emlrtRSI;
      nx = loop_ub - 1;
      b_i2 = b_Sol->size[0] * b_Sol->size[1];
      b_Sol->size[0] = 1;
      b_Sol->size[1] = loop_ub;
      emxEnsureCapacity_creal_T(&b_st, b_Sol, b_i2, &gb_emlrtRTEI);
      for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
        b_Sol->data[b_i2] = Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] *
          (i + b_i2)) - 1];
      }

      i = y->size[0] * y->size[1];
      y->size[0] = 1;
      y->size[1] = (int16_T)b_Sol->size[1];
      emxEnsureCapacity_real_T(&b_st, y, i, &hb_emlrtRTEI);
      for (loop_ub_tmp = 0; loop_ub_tmp <= nx; loop_ub_tmp++) {
        y->data[loop_ub_tmp] = muDoubleScalarHypot
          (b_exp_minus_omega_contents->data[loop_ub_tmp].re,
           b_exp_minus_omega_contents->data[loop_ub_tmp].im);
      }

      st.site = &c_emlrtRSI;
      b_st.site = &c_emlrtRSI;
      power(&b_st, y, r2);
      b_st.site = &c_emlrtRSI;
      Temp_im = sum(&b_st, r2);
      Temp_im = muDoubleScalarLog10(Temp_im);
      if ((10.0 * Temp_im <= -50.0) && (muDoubleScalarRem(ind_s, 2.0) == 0.0)) {
        i = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        r1->size[1] = Sol->Psi->size[0] - (int32_T)ind_s;
        emxEnsureCapacity_int32_T(sp, r1, i, &ib_emlrtRTEI);
        loop_ub = Sol->Psi->size[0] - (int32_T)ind_s;
        for (i = 0; i < loop_ub; i++) {
          r1->data[i] = ((int32_T)ind_s + i) + 1;
        }

        st.site = &b_emlrtRSI;
        nullAssignment(&st, Sol->Psi, r1);
        i = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        r1->size[1] = Sol->t->size[1] - (int32_T)ind_s;
        emxEnsureCapacity_int32_T(sp, r1, i, &jb_emlrtRTEI);
        loop_ub = Sol->t->size[1] - (int32_T)ind_s;
        for (i = 0; i < loop_ub; i++) {
          r1->data[i] = ((int32_T)ind_s + i) + 1;
        }

        st.site = &emlrtRSI;
        b_nullAssignment(&st, Sol->t, r1);
        exitg1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      ni++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }
  }

  emxFree_creal_T(&b_Sol);
  emxFree_creal_T(&E_temp);
  emxFree_creal_T(&b_exp_minus_omega_contents);
  emxFree_real_T(&r2);
  emxFree_real_T(&y);
  emxFree_int32_T(&r1);
  emxFree_creal_T(&c_d);
  emxFree_creal_T(&r);
  emxFree_cuint8_T(&d);
  emxFree_creal_T(&exp_minus_omega_contents);
  emxFree_creal_T(&exp_plus_omega_contents);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Chi_3_LLE_Runge_Kuarong.c) */
