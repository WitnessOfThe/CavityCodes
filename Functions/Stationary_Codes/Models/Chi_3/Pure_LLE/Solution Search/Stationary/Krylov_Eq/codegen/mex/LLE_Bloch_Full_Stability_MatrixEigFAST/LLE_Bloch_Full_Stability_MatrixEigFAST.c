/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LLE_Bloch_Full_Stability_MatrixEigFAST.c
 *
 * Code generation for function 'LLE_Bloch_Full_Stability_MatrixEigFAST'
 *
 */

/* Include files */
#include "LLE_Bloch_Full_Stability_MatrixEigFAST.h"
#include "LLE_Bloch_Full_Stability_MatrixEigFAST_data.h"
#include "LLE_Bloch_Full_Stability_MatrixEigFAST_emxutil.h"
#include "LLE_Bloch_Full_Stability_MatrixEigFAST_types.h"
#include "mtimes.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 9,     /* lineNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 18,  /* lineNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 19,  /* lineNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 37,  /* lineNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 38,  /* lineNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 40,  /* lineNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 41,  /* lineNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 80,  /* lineNo */
  "ifft",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\ifft.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 10,  /* lineNo */
  "factorial",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\specfun\\factorial.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 27,  /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 102, /* lineNo */
  "cat_impl",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 79,  /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 283, /* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  44,                                  /* lineNo */
  23,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 38,    /* lineNo */
  32,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 37,  /* lineNo */
  64,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { 2,   /* nDims */
  27,                                  /* lineNo */
  18,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { 2,   /* nDims */
  26,                                  /* lineNo */
  18,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  19,                                  /* lineNo */
  12,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  20,                                  /* colNo */
  "L_mn",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 19,  /* lineNo */
  20,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  18,                                  /* colNo */
  "L_mn",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { 2,   /* nDims */
  19,                                  /* lineNo */
  35,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  42,                                  /* colNo */
  "L_mn",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 19,  /* lineNo */
  42,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  40,                                  /* colNo */
  "L_mn",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  14,                                  /* lineNo */
  8,                                   /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  15,                                  /* colNo */
  "L_mn",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 14,  /* lineNo */
  15,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  14,                                  /* lineNo */
  13,                                  /* colNo */
  "L_mn",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  18,                                  /* lineNo */
  12,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  19,                                  /* colNo */
  "L_pl",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 18,  /* lineNo */
  19,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  17,                                  /* colNo */
  "L_pl",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo h_emlrtECI = { 2,   /* nDims */
  18,                                  /* lineNo */
  35,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  42,                                  /* colNo */
  "L_pl",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 18,  /* lineNo */
  42,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  40,                                  /* colNo */
  "L_pl",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  13,                                  /* lineNo */
  8,                                   /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  15,                                  /* colNo */
  "L_pl",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 13,  /* lineNo */
  15,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  13,                                  /* lineNo */
  13,                                  /* colNo */
  "L_pl",                              /* aName */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 14,  /* lineNo */
  53,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 13,  /* lineNo */
  53,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 10,  /* lineNo */
  42,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 10,  /* lineNo */
  42,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 11,  /* lineNo */
  42,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 10,  /* lineNo */
  9,                                   /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 11,  /* lineNo */
  9,                                   /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = { 10,/* lineNo */
  9,                                   /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 11,/* lineNo */
  9,                                   /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 13,/* lineNo */
  32,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 14,/* lineNo */
  32,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 18,/* lineNo */
  35,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 27,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 19,/* lineNo */
  35,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 37,/* lineNo */
  9,                                   /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 1, /* lineNo */
  18,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 37,/* lineNo */
  27,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 38,/* lineNo */
  26,                                  /* colNo */
  "LLE_Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q\\LLE_Bloch_Full_Stability_MatrixEigFAST.m"/* pName */
};

/* Function Definitions */
void LLE_Bloch_Full_Stability_MatrixEigFAST(d_LLE_Bloch_Full_Stability_Matr *SD,
  const emlrtStack *sp, const struct0_T *Stat, const creal_T FF[1048576], const
  creal_T FI[1048576], creal_T g[4194304])
{
  static const real_T dv[170] = { 1.0, 2.0, 6.0, 24.0, 120.0, 720.0, 5040.0,
    40320.0, 362880.0, 3.6288E+6, 3.99168E+7, 4.790016E+8, 6.2270208E+9,
    8.71782912E+10, 1.307674368E+12, 2.0922789888E+13, 3.55687428096E+14,
    6.402373705728E+15, 1.21645100408832E+17, 2.43290200817664E+18,
    5.109094217170944E+19, 1.1240007277776077E+21, 2.5852016738884978E+22,
    6.2044840173323941E+23, 1.5511210043330986E+25, 4.0329146112660565E+26,
    1.0888869450418352E+28, 3.0488834461171384E+29, 8.8417619937397008E+30,
    2.6525285981219103E+32, 8.2228386541779224E+33, 2.6313083693369352E+35,
    8.6833176188118859E+36, 2.9523279903960412E+38, 1.0333147966386144E+40,
    3.7199332678990118E+41, 1.3763753091226343E+43, 5.23022617466601E+44,
    2.0397882081197442E+46, 8.1591528324789768E+47, 3.3452526613163803E+49,
    1.4050061177528798E+51, 6.0415263063373834E+52, 2.6582715747884485E+54,
    1.1962222086548019E+56, 5.5026221598120885E+57, 2.5862324151116818E+59,
    1.2413915592536073E+61, 6.0828186403426752E+62, 3.0414093201713376E+64,
    1.5511187532873822E+66, 8.0658175170943877E+67, 4.2748832840600255E+69,
    2.3084369733924138E+71, 1.2696403353658276E+73, 7.1099858780486348E+74,
    4.0526919504877221E+76, 2.3505613312828789E+78, 1.3868311854568986E+80,
    8.3209871127413916E+81, 5.0758021387722484E+83, 3.1469973260387939E+85,
    1.98260831540444E+87, 1.2688693218588417E+89, 8.2476505920824715E+90,
    5.4434493907744307E+92, 3.6471110918188683E+94, 2.4800355424368305E+96,
    1.711224524281413E+98, 1.197857166996989E+100, 8.5047858856786218E+101,
    6.1234458376886077E+103, 4.4701154615126834E+105, 3.3078854415193856E+107,
    2.4809140811395391E+109, 1.8854947016660498E+111, 1.4518309202828584E+113,
    1.1324281178206295E+115, 8.9461821307829729E+116, 7.1569457046263779E+118,
    5.7971260207473655E+120, 4.75364333701284E+122, 3.9455239697206569E+124,
    3.314240134565352E+126, 2.8171041143805494E+128, 2.4227095383672724E+130,
    2.1077572983795269E+132, 1.8548264225739836E+134, 1.6507955160908452E+136,
    1.4857159644817607E+138, 1.3520015276784023E+140, 1.24384140546413E+142,
    1.1567725070816409E+144, 1.0873661566567424E+146, 1.0329978488239052E+148,
    9.916779348709491E+149, 9.6192759682482062E+151, 9.426890448883242E+153,
    9.33262154439441E+155, 9.33262154439441E+157, 9.4259477598383536E+159,
    9.6144667150351211E+161, 9.9029007164861754E+163, 1.0299016745145622E+166,
    1.0813967582402903E+168, 1.1462805637347078E+170, 1.2265202031961373E+172,
    1.3246418194518284E+174, 1.4438595832024928E+176, 1.5882455415227421E+178,
    1.7629525510902437E+180, 1.9745068572210728E+182, 2.2311927486598123E+184,
    2.5435597334721862E+186, 2.9250936934930141E+188, 3.3931086844518965E+190,
    3.969937160808719E+192, 4.6845258497542883E+194, 5.5745857612076033E+196,
    6.6895029134491239E+198, 8.09429852527344E+200, 9.8750442008335976E+202,
    1.2146304367025325E+205, 1.5061417415111404E+207, 1.8826771768889254E+209,
    2.3721732428800459E+211, 3.0126600184576582E+213, 3.8562048236258025E+215,
    4.9745042224772855E+217, 6.4668554892204716E+219, 8.4715806908788174E+221,
    1.1182486511960039E+224, 1.4872707060906852E+226, 1.9929427461615181E+228,
    2.6904727073180495E+230, 3.6590428819525472E+232, 5.01288874827499E+234,
    6.9177864726194859E+236, 9.6157231969410859E+238, 1.346201247571752E+241,
    1.89814375907617E+243, 2.6953641378881614E+245, 3.8543707171800706E+247,
    5.5502938327393013E+249, 8.0479260574719866E+251, 1.17499720439091E+254,
    1.7272458904546376E+256, 2.5563239178728637E+258, 3.8089226376305671E+260,
    5.7133839564458505E+262, 8.6272097742332346E+264, 1.3113358856834518E+267,
    2.0063439050956811E+269, 3.0897696138473489E+271, 4.7891429014633912E+273,
    7.47106292628289E+275, 1.1729568794264138E+278, 1.8532718694937338E+280,
    2.9467022724950369E+282, 4.714723635992059E+284, 7.5907050539472148E+286,
    1.2296942187394488E+289, 2.0044015765453015E+291, 3.2872185855342945E+293,
    5.423910666131586E+295, 9.0036917057784329E+297, 1.5036165148649983E+300,
    2.5260757449731969E+302, 4.2690680090047027E+304, 7.257415615307994E+306 };

  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_creal_T *L_mn;
  emxArray_creal_T *L_pl;
  emxArray_creal_T *Linear_part;
  emxArray_creal_T *b_L_pl;
  emxArray_creal_T *b_result;
  emxArray_creal_T *result;
  emxArray_real_T *r;
  creal_T psi_hat[1024];
  creal_T y[1024];
  real_T b_Stat[1024];
  real_T b_y[1024];
  real_T ar_tmp;
  real_T d;
  real_T d1;
  real_T d2;
  real_T z_im;
  real_T z_re;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T b_i;
  int32_T g_tmp;
  int32_T i;
  int32_T i1;
  int32_T input_sizes_idx_1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  L_L.Eq.mask; */
  for (i = 0; i < 1024; i++) {
    psi_hat[i].re = Stat->Space.N * Stat->Sol.Psi_k[i].re;
    psi_hat[i].im = Stat->Space.N * Stat->Sol.Psi_k[i].im;
  }

  emxInit_creal_T(sp, &L_pl, 2, &c_emlrtRTEI, true);
  st.site = &emlrtRSI;
  b_st.site = &h_emlrtRSI;
  emlrtFFTWSetNumThreads(6);
  emlrtFFTW_1D_C2C((real_T *)&psi_hat[0], (real_T *)&y[0], 1, 1024, 1024, 1, 1);
  i = L_pl->size[0] * L_pl->size[1];
  L_pl->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, L_pl, i, &c_emlrtRTEI);
  if (!(Stat->Space.N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Stat->Space.N, &l_emlrtDCI, sp);
  }

  d = (int32_T)muDoubleScalarFloor(Stat->Space.N);
  if (Stat->Space.N != d) {
    emlrtIntegerCheckR2012b(Stat->Space.N, &k_emlrtDCI, sp);
  }

  i = L_pl->size[0] * L_pl->size[1];
  L_pl->size[1] = (int32_T)Stat->Space.N;
  emxEnsureCapacity_creal_T(sp, L_pl, i, &c_emlrtRTEI);
  if (Stat->Space.N != d) {
    emlrtIntegerCheckR2012b(Stat->Space.N, &n_emlrtDCI, sp);
  }

  input_sizes_idx_1 = (int32_T)Stat->Space.N;
  for (i = 0; i < input_sizes_idx_1; i++) {
    L_pl->data[i].re = 0.0;
    L_pl->data[i].im = 0.0;
  }

  emxInit_creal_T(sp, &L_mn, 2, &d_emlrtRTEI, true);
  i = L_mn->size[0] * L_mn->size[1];
  L_mn->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, L_mn, i, &d_emlrtRTEI);
  if (Stat->Space.N != d) {
    emlrtIntegerCheckR2012b(Stat->Space.N, &m_emlrtDCI, sp);
  }

  i = L_mn->size[0] * L_mn->size[1];
  L_mn->size[1] = (int32_T)Stat->Space.N;
  emxEnsureCapacity_creal_T(sp, L_mn, i, &d_emlrtRTEI);
  if (Stat->Space.N != d) {
    emlrtIntegerCheckR2012b(Stat->Space.N, &o_emlrtDCI, sp);
  }

  input_sizes_idx_1 = (int32_T)Stat->Space.N;
  for (i = 0; i < input_sizes_idx_1; i++) {
    L_mn->data[i].re = 0.0;
    L_mn->data[i].im = 0.0;
  }

  if (1.0 > Stat->Space.N) {
    i = 0;
  } else {
    if (1 > L_pl->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, L_pl->size[1], &l_emlrtBCI, sp);
    }

    if (Stat->Space.N != d) {
      emlrtIntegerCheckR2012b(Stat->Space.N, &h_emlrtDCI, sp);
    }

    if (((int32_T)Stat->Space.N < 1) || ((int32_T)Stat->Space.N > L_pl->size[1]))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)Stat->Space.N, 1, L_pl->size[1],
        &k_emlrtBCI, sp);
    }

    i = (int32_T)Stat->Space.N;
  }

  if (Stat->Space.N != d) {
    emlrtIntegerCheckR2012b(Stat->Space.N, &j_emlrtDCI, sp);
  }

  emxInit_real_T(sp, &r, 2, &k_emlrtRTEI, true);
  i1 = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = (int32_T)Stat->Space.N;
  emxEnsureCapacity_real_T(sp, r, i1, &e_emlrtRTEI);
  input_sizes_idx_1 = (int32_T)Stat->Space.N;
  for (i1 = 0; i1 < input_sizes_idx_1; i1++) {
    r->data[i1] = Stat->Eq.delta;
  }

  if (i != r->size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(i, r->size[1], &i_emlrtECI, sp);
  }

  input_sizes_idx_1 = r->size[1];
  for (i = 0; i < input_sizes_idx_1; i++) {
    L_pl->data[i].re = r->data[i];
    L_pl->data[i].im = 0.0;
  }

  if (1.0 > Stat->Space.N) {
    i = 0;
  } else {
    if (1 > L_mn->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, L_mn->size[1], &f_emlrtBCI, sp);
    }

    if (Stat->Space.N != d) {
      emlrtIntegerCheckR2012b(Stat->Space.N, &e_emlrtDCI, sp);
    }

    if (((int32_T)Stat->Space.N < 1) || ((int32_T)Stat->Space.N > L_mn->size[1]))
    {
      emlrtDynamicBoundsCheckR2012b((int32_T)Stat->Space.N, 1, L_mn->size[1],
        &e_emlrtBCI, sp);
    }

    i = (int32_T)Stat->Space.N;
  }

  if (Stat->Space.N != d) {
    emlrtIntegerCheckR2012b(Stat->Space.N, &i_emlrtDCI, sp);
  }

  i1 = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = (int32_T)Stat->Space.N;
  emxEnsureCapacity_real_T(sp, r, i1, &f_emlrtRTEI);
  input_sizes_idx_1 = (int32_T)Stat->Space.N;
  for (i1 = 0; i1 < input_sizes_idx_1; i1++) {
    r->data[i1] = Stat->Eq.delta;
  }

  if (i != r->size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(i, r->size[1], &f_emlrtECI, sp);
  }

  input_sizes_idx_1 = r->size[1];
  for (i = 0; i < input_sizes_idx_1; i++) {
    L_mn->data[i].re = r->data[i];
    L_mn->data[i].im = 0.0;
  }

  emxFree_real_T(&r);
  emxInit_creal_T(sp, &b_L_pl, 2, &g_emlrtRTEI, true);
  for (b_i = 0; b_i < 2; b_i++) {
    if (1.0 > Stat->Space.N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_pl->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_pl->size[1], &j_emlrtBCI, sp);
      }

      if (Stat->Space.N != d) {
        emlrtIntegerCheckR2012b(Stat->Space.N, &g_emlrtDCI, sp);
      }

      if (((int32_T)Stat->Space.N < 1) || ((int32_T)Stat->Space.N > L_pl->size[1]))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat->Space.N, 1, L_pl->size[1],
          &i_emlrtBCI, sp);
      }

      input_sizes_idx_1 = (int32_T)Stat->Space.N;
    }

    iv[0] = 1;
    iv[1] = input_sizes_idx_1;
    iv1[0] = 1;
    iv1[1] = 1024;
    if (input_sizes_idx_1 != 1024) {
      emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &h_emlrtECI, sp);
    }

    if (1.0 > Stat->Space.N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_pl->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_pl->size[1], &h_emlrtBCI, sp);
      }

      if (Stat->Space.N != d) {
        emlrtIntegerCheckR2012b(Stat->Space.N, &f_emlrtDCI, sp);
      }

      if (((int32_T)Stat->Space.N < 1) || ((int32_T)Stat->Space.N > L_pl->size[1]))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat->Space.N, 1, L_pl->size[1],
          &g_emlrtBCI, sp);
      }

      input_sizes_idx_1 = (int32_T)Stat->Space.N;
    }

    if (input_sizes_idx_1 != 1024) {
      emlrtSubAssignSizeCheck1dR2017a(input_sizes_idx_1, 1024, &g_emlrtECI, sp);
    }

    st.site = &b_emlrtRSI;
    b_st.site = &p_emlrtRSI;
    for (i = 0; i < 1024; i++) {
      b_Stat[i] = Stat->Space.k[i] + Stat->In.k;
    }

    st.site = &b_emlrtRSI;
    power(&st, b_Stat, (real_T)b_i + 2.0, b_y);
    i = b_L_pl->size[0] * b_L_pl->size[1];
    b_L_pl->size[0] = 1;
    b_L_pl->size[1] = 1024;
    emxEnsureCapacity_creal_T(sp, b_L_pl, i, &g_emlrtRTEI);
    for (i = 0; i < 1024; i++) {
      b_L_pl->data[i] = L_pl->data[i];
    }

    for (i = 0; i < 1024; i++) {
      psi_hat[i].re = b_L_pl->data[i].re + b_y[i] * Stat->Eq.D[b_i + 1] / dv[b_i
        + 1];
      psi_hat[i].im = b_L_pl->data[i].im;
    }

    for (i = 0; i < 1024; i++) {
      L_pl->data[i] = psi_hat[i];
    }

    if (1.0 > Stat->Space.N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_mn->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_mn->size[1], &d_emlrtBCI, sp);
      }

      if (Stat->Space.N != d) {
        emlrtIntegerCheckR2012b(Stat->Space.N, &d_emlrtDCI, sp);
      }

      if (((int32_T)Stat->Space.N < 1) || ((int32_T)Stat->Space.N > L_mn->size[1]))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat->Space.N, 1, L_mn->size[1],
          &c_emlrtBCI, sp);
      }

      input_sizes_idx_1 = (int32_T)Stat->Space.N;
    }

    iv[0] = 1;
    iv[1] = input_sizes_idx_1;
    iv1[0] = 1;
    iv1[1] = 1024;
    if (input_sizes_idx_1 != 1024) {
      emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &e_emlrtECI, sp);
    }

    if (1.0 > Stat->Space.N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_mn->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_mn->size[1], &b_emlrtBCI, sp);
      }

      if (Stat->Space.N != d) {
        emlrtIntegerCheckR2012b(Stat->Space.N, &c_emlrtDCI, sp);
      }

      if (((int32_T)Stat->Space.N < 1) || ((int32_T)Stat->Space.N > L_mn->size[1]))
      {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat->Space.N, 1, L_mn->size[1],
          &emlrtBCI, sp);
      }

      input_sizes_idx_1 = (int32_T)Stat->Space.N;
    }

    if (input_sizes_idx_1 != 1024) {
      emlrtSubAssignSizeCheck1dR2017a(input_sizes_idx_1, 1024, &d_emlrtECI, sp);
    }

    st.site = &c_emlrtRSI;
    b_st.site = &p_emlrtRSI;
    for (i = 0; i < 1024; i++) {
      b_Stat[i] = -Stat->Space.k[i] - Stat->In.k;
    }

    st.site = &c_emlrtRSI;
    power(&st, b_Stat, (real_T)b_i + 2.0, b_y);
    i = b_L_pl->size[0] * b_L_pl->size[1];
    b_L_pl->size[0] = 1;
    b_L_pl->size[1] = 1024;
    emxEnsureCapacity_creal_T(sp, b_L_pl, i, &i_emlrtRTEI);
    for (i = 0; i < 1024; i++) {
      b_L_pl->data[i] = L_mn->data[i];
    }

    for (i = 0; i < 1024; i++) {
      psi_hat[i].re = b_L_pl->data[i].re + b_y[i] * Stat->Eq.D[b_i + 1] / dv[b_i
        + 1];
      psi_hat[i].im = b_L_pl->data[i].im;
    }

    for (i = 0; i < 1024; i++) {
      L_mn->data[i] = psi_hat[i];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_creal_T(&b_L_pl);

  /*      i=3; */
  /*         L_pl = L_pl + 1i*(1i)^i*( Stat.Space.k+Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i) ; */
  /*       L_mn = L_mn + 1i*(1i)^i*(Stat.Space.k+Stat.In.k).^i.*Stat.Eq.D(i)/factorial(i); */
  iv[0] = 1;
  iv[1] = 1024;
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])L_pl->size, iv, &c_emlrtECI, sp);
  iv[0] = 1;
  iv[1] = 1024;
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])L_mn->size, iv, &b_emlrtECI, sp);

  /*   L_pl  =   L_pl.'.*x(1:Stat.Space.N)                ; */
  /*    L_mn =    L_mn.'.*x(Stat.Space.N+1:2*Stat.Space.N) ; */
  /*         L_pl                   = L_L.Eq.L + 1/2*L_L.In.k^2*L_L.In.Fin_D+L_L.In.k*L_L.In.Fin_D*L_L.Space.k+(L_L.In.k+L_L.Space.k)*L_L.Sol.V; */
  /*        L_mn                   = L_L.Eq.L + 1/2*L_L.In.k^2*L_L.In.Fin_D-L_L.In.k*L_L.In.Fin_D*L_L.Space.k+(-L_L.In.k+L_L.Space.k)*L_L.Sol.V; */
  ar_tmp = 0.0 * Stat->Eq.kappa;
  if (Stat->Eq.kappa == 0.0) {
    z_re = ar_tmp / 2.0;
    z_im = 0.0;
  } else if (ar_tmp == 0.0) {
    z_re = 0.0;
    z_im = Stat->Eq.kappa / 2.0;
  } else {
    z_re = rtNaN;
    z_im = Stat->Eq.kappa / 2.0;
  }

  emxInit_creal_T(sp, &result, 2, &l_emlrtRTEI, true);
  st.site = &d_emlrtRSI;
  for (i = 0; i < 1024; i++) {
    psi_hat[i].re = (L_pl->data[i].re - (Stat->Space.k[i] + Stat->In.k) *
                     Stat->Sol.V) - z_re;
    psi_hat[i].im = L_pl->data[i].im - z_im;
  }

  emxFree_creal_T(&L_pl);
  memset(&SD->f0.reshapes_f1[0], 0, 1048576U * sizeof(creal_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 1024; input_sizes_idx_1++) {
    SD->f0.reshapes_f1[input_sizes_idx_1 + (input_sizes_idx_1 << 10)] =
      psi_hat[input_sizes_idx_1];
  }

  if (Stat->Space.N != d) {
    emlrtIntegerCheckR2012b(Stat->Space.N, &b_emlrtDCI, &st);
  }

  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  if (((int32_T)Stat->Space.N != 1024) && ((int32_T)Stat->Space.N != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((int32_T)Stat->Space.N != 0) {
    input_sizes_idx_1 = (int32_T)Stat->Space.N;
  } else {
    input_sizes_idx_1 = 0;
  }

  i = result->size[0] * result->size[1];
  result->size[0] = 1024;
  result->size[1] = input_sizes_idx_1 + 1024;
  emxEnsureCapacity_creal_T(&b_st, result, i, &h_emlrtRTEI);
  for (i = 0; i < 1024; i++) {
    for (i1 = 0; i1 < 1024; i1++) {
      result->data[i1 + 1024 * i] = SD->f0.reshapes_f1[i1 + (i << 10)];
    }
  }

  for (i = 0; i < input_sizes_idx_1; i++) {
    for (i1 = 0; i1 < 1024; i1++) {
      g_tmp = i1 + 1024 * (i + 1024);
      result->data[g_tmp].re = 0.0;
      result->data[g_tmp].im = 0.0;
    }
  }

  if (Stat->Eq.kappa == 0.0) {
    z_re = ar_tmp / 2.0;
    z_im = 0.0;
  } else if (ar_tmp == 0.0) {
    z_re = 0.0;
    z_im = Stat->Eq.kappa / 2.0;
  } else {
    z_re = rtNaN;
    z_im = Stat->Eq.kappa / 2.0;
  }

  emxInit_creal_T(sp, &b_result, 2, &m_emlrtRTEI, true);
  st.site = &e_emlrtRSI;
  if (Stat->Space.N != d) {
    emlrtIntegerCheckR2012b(Stat->Space.N, &emlrtDCI, &st);
  }

  for (i = 0; i < 1024; i++) {
    psi_hat[i].re = -(L_mn->data[i].re - (-Stat->Space.k[i] - Stat->In.k) *
                      Stat->Sol.V) - z_re;
    psi_hat[i].im = -L_mn->data[i].im - z_im;
  }

  emxFree_creal_T(&L_mn);
  memset(&SD->f0.reshapes_f1[0], 0, 1048576U * sizeof(creal_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 1024; input_sizes_idx_1++) {
    SD->f0.reshapes_f1[input_sizes_idx_1 + (input_sizes_idx_1 << 10)] =
      psi_hat[input_sizes_idx_1];
  }

  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  if (((int32_T)Stat->Space.N != 1024) && ((int32_T)Stat->Space.N != 0)) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((int32_T)Stat->Space.N != 0) {
    input_sizes_idx_1 = (int32_T)Stat->Space.N;
  } else {
    input_sizes_idx_1 = 0;
  }

  if ((int32_T)Stat->Space.N != 0) {
    iv[1] = (int32_T)Stat->Space.N;
  } else {
    iv[1] = 0;
  }

  i = b_result->size[0] * b_result->size[1];
  b_result->size[0] = 1024;
  b_result->size[1] = input_sizes_idx_1 + 1024;
  emxEnsureCapacity_creal_T(&b_st, b_result, i, &h_emlrtRTEI);
  for (i = 0; i < input_sizes_idx_1; i++) {
    for (i1 = 0; i1 < 1024; i1++) {
      g_tmp = i1 + 1024 * i;
      b_result->data[g_tmp].re = 0.0;
      b_result->data[g_tmp].im = 0.0;
    }
  }

  for (i = 0; i < 1024; i++) {
    for (i1 = 0; i1 < 1024; i1++) {
      b_result->data[i1 + 1024 * (i + iv[1])] = SD->f0.reshapes_f1[i1 + (i << 10)];
    }
  }

  st.site = &d_emlrtRSI;
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  if (b_result->size[1] != result->size[1]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_creal_T(&c_st, &Linear_part, 2, &j_emlrtRTEI, true);
  i = Linear_part->size[0] * Linear_part->size[1];
  Linear_part->size[0] = 2048;
  Linear_part->size[1] = result->size[1];
  emxEnsureCapacity_creal_T(&b_st, Linear_part, i, &j_emlrtRTEI);
  input_sizes_idx_1 = result->size[1];
  for (i = 0; i < input_sizes_idx_1; i++) {
    for (i1 = 0; i1 < 1024; i1++) {
      Linear_part->data[i1 + Linear_part->size[0] * i] = result->data[i1 + 1024 *
        i];
    }
  }

  input_sizes_idx_1 = result->size[1];
  emxFree_creal_T(&result);
  for (i = 0; i < input_sizes_idx_1; i++) {
    for (i1 = 0; i1 < 1024; i1++) {
      Linear_part->data[(i1 + Linear_part->size[0] * i) + 1024] = b_result->
        data[i1 + 1024 * i];
    }
  }

  emxFree_creal_T(&b_result);
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 1024; input_sizes_idx_1++) {
    b_y[input_sizes_idx_1] = muDoubleScalarHypot(y[input_sizes_idx_1].re,
      y[input_sizes_idx_1].im);
  }

  for (i = 0; i < 1048576; i++) {
    SD->f0.a_tmp[i].re = -FF[i].re;
    SD->f0.a_tmp[i].im = -FF[i].im;
  }

  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 1024; input_sizes_idx_1++) {
    d = b_y[input_sizes_idx_1];
    b_Stat[input_sizes_idx_1] = Stat->Eq.gamma_Kerr[input_sizes_idx_1] * (2.0 *
      (d * d));
  }

  memset(&SD->f0.b_b[0], 0, 1048576U * sizeof(real_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 1024; input_sizes_idx_1++) {
    SD->f0.b_b[input_sizes_idx_1 + (input_sizes_idx_1 << 10)] =
      b_Stat[input_sizes_idx_1];
  }

  st.site = &f_emlrtRSI;
  for (i = 0; i < 1048576; i++) {
    SD->f0.b[i].re = SD->f0.b_b[i];
    SD->f0.b[i].im = 0.0;
  }

  for (i = 0; i < 1024; i++) {
    for (i1 = 0; i1 < 1024; i1++) {
      z_im = 0.0;
      ar_tmp = 0.0;
      for (g_tmp = 0; g_tmp < 1024; g_tmp++) {
        input_sizes_idx_1 = i + (g_tmp << 10);
        b_i = g_tmp + (i1 << 10);
        d = SD->f0.a_tmp[input_sizes_idx_1].re;
        d1 = SD->f0.a_tmp[input_sizes_idx_1].im;
        d2 = SD->f0.b[b_i].re;
        z_re = SD->f0.b[b_i].im;
        z_im += d * d2 - d1 * z_re;
        ar_tmp += d * z_re + d1 * d2;
      }

      g_tmp = i + (i1 << 10);
      SD->f0.reshapes_f1[g_tmp].re = z_im;
      SD->f0.reshapes_f1[g_tmp].im = ar_tmp;
    }
  }

  b_st.site = &t_emlrtRSI;
  mtimes(SD->f0.reshapes_f1, FI, SD->f0.y);
  st.site = &f_emlrtRSI;
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 1024; input_sizes_idx_1++) {
    d = y[input_sizes_idx_1].re;
    d1 = y[input_sizes_idx_1].im;
    z_re = d * d1;
    d2 = Stat->Eq.gamma_Kerr[input_sizes_idx_1];
    psi_hat[input_sizes_idx_1].re = d2 * (d * d - d1 * d1);
    psi_hat[input_sizes_idx_1].im = d2 * (z_re + z_re);
  }

  memset(&SD->f0.b[0], 0, 1048576U * sizeof(creal_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 1024; input_sizes_idx_1++) {
    SD->f0.b[input_sizes_idx_1 + (input_sizes_idx_1 << 10)] =
      psi_hat[input_sizes_idx_1];
  }

  b_st.site = &t_emlrtRSI;
  mtimes(SD->f0.a_tmp, SD->f0.b, SD->f0.reshapes_f1);
  st.site = &f_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  mtimes(SD->f0.reshapes_f1, FI, SD->f0.b_y);
  st.site = &g_emlrtRSI;
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 1024; input_sizes_idx_1++) {
    z_im = y[input_sizes_idx_1].re;
    ar_tmp = -y[input_sizes_idx_1].im;
    z_re = z_im * ar_tmp;
    d = Stat->Eq.gamma_Kerr[input_sizes_idx_1];
    psi_hat[input_sizes_idx_1].re = d * (z_im * z_im - ar_tmp * ar_tmp);
    psi_hat[input_sizes_idx_1].im = d * (z_re + z_re);
  }

  memset(&SD->f0.b[0], 0, 1048576U * sizeof(creal_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 1024; input_sizes_idx_1++) {
    SD->f0.b[input_sizes_idx_1 + (input_sizes_idx_1 << 10)] =
      psi_hat[input_sizes_idx_1];
  }

  b_st.site = &t_emlrtRSI;
  mtimes(FF, SD->f0.b, SD->f0.reshapes_f1);
  st.site = &g_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  mtimes(SD->f0.reshapes_f1, FI, SD->f0.a_tmp);
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 1024; input_sizes_idx_1++) {
    d = muDoubleScalarHypot(y[input_sizes_idx_1].re, y[input_sizes_idx_1].im);
    b_Stat[input_sizes_idx_1] = Stat->Eq.gamma_Kerr[input_sizes_idx_1] * (2.0 *
      (d * d));
  }

  memset(&SD->f0.b_b[0], 0, 1048576U * sizeof(real_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 1024; input_sizes_idx_1++) {
    SD->f0.b_b[input_sizes_idx_1 + (input_sizes_idx_1 << 10)] =
      b_Stat[input_sizes_idx_1];
  }

  st.site = &g_emlrtRSI;
  for (i = 0; i < 1048576; i++) {
    SD->f0.b[i].re = SD->f0.b_b[i];
    SD->f0.b[i].im = 0.0;
  }

  for (i = 0; i < 1024; i++) {
    for (i1 = 0; i1 < 1024; i1++) {
      z_im = 0.0;
      ar_tmp = 0.0;
      for (g_tmp = 0; g_tmp < 1024; g_tmp++) {
        input_sizes_idx_1 = i + (g_tmp << 10);
        b_i = g_tmp + (i1 << 10);
        d = FF[input_sizes_idx_1].re;
        d1 = FF[input_sizes_idx_1].im;
        d2 = SD->f0.b[b_i].re;
        z_re = SD->f0.b[b_i].im;
        z_im += d * d2 - d1 * z_re;
        ar_tmp += d * z_re + d1 * d2;
      }

      g_tmp = i + (i1 << 10);
      SD->f0.FF[g_tmp].re = z_im;
      SD->f0.FF[g_tmp].im = ar_tmp;
    }
  }

  b_st.site = &t_emlrtRSI;
  mtimes(SD->f0.FF, FI, SD->f0.reshapes_f1);
  iv[0] = 2048;
  iv[1] = 2048;
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])Linear_part->size, iv, &emlrtECI, sp);
  for (i = 0; i < 1024; i++) {
    for (i1 = 0; i1 < 1024; i1++) {
      input_sizes_idx_1 = i1 + (i << 10);
      b_i = i1 + (i << 11);
      g[b_i] = SD->f0.y[input_sizes_idx_1];
      g_tmp = i1 + ((i + 1024) << 11);
      g[g_tmp] = SD->f0.b_y[input_sizes_idx_1];
      g[b_i + 1024] = SD->f0.a_tmp[input_sizes_idx_1];
      g[g_tmp + 1024] = SD->f0.reshapes_f1[input_sizes_idx_1];
    }
  }

  for (i = 0; i < 4194304; i++) {
    z_re = Linear_part->data[i].re + g[i].re;
    z_im = Linear_part->data[i].im + g[i].im;
    g[i].re = 0.0 * z_re - (-z_im);
    g[i].im = 0.0 * z_im + -z_re;
  }

  emxFree_creal_T(&Linear_part);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (LLE_Bloch_Full_Stability_MatrixEigFAST.c) */
