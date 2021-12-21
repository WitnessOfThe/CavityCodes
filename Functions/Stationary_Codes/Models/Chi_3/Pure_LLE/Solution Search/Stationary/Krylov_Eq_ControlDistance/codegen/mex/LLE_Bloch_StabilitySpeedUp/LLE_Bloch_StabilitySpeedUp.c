/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LLE_Bloch_StabilitySpeedUp.c
 *
 * Code generation for function 'LLE_Bloch_StabilitySpeedUp'
 *
 */

/* Include files */
#include "LLE_Bloch_StabilitySpeedUp.h"
#include "LLE_Bloch_StabilitySpeedUp_data.h"
#include "LLE_Bloch_StabilitySpeedUp_emxutil.h"
#include "LLE_Bloch_StabilitySpeedUp_types.h"
#include "diag.h"
#include "eig.h"
#include "factorial.h"
#include "ifft.h"
#include "mtimes.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 3,     /* lineNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 4,   /* lineNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 15,  /* lineNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 24,  /* lineNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 25,  /* lineNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 43,  /* lineNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 44,  /* lineNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 46,  /* lineNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 47,  /* lineNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 80,  /* lineNo */
  "ifft",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\datafun\\ifft.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 27,  /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 102,/* lineNo */
  "cat_impl",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 79, /* lineNo */
  "eml_mtimes_helper",                 /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\eml_mtimes_helper.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 57, /* lineNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 67, /* lineNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 68, /* lineNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 76, /* lineNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 77, /* lineNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 79, /* lineNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 80, /* lineNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 283, /* lineNo */
  27,                                  /* colNo */
  "check_non_axis_size",               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  50,                                  /* lineNo */
  23,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { 2,   /* nDims */
  33,                                  /* lineNo */
  18,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtECInfo c_emlrtECI = { 2,   /* nDims */
  32,                                  /* lineNo */
  18,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  25,                                  /* lineNo */
  12,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  20,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  18,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { 2,   /* nDims */
  25,                                  /* lineNo */
  35,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  42,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  25,                                  /* lineNo */
  40,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  20,                                  /* lineNo */
  8,                                   /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  15,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  20,                                  /* lineNo */
  13,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  24,                                  /* lineNo */
  12,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  19,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  17,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo h_emlrtECI = { 2,   /* nDims */
  24,                                  /* lineNo */
  35,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  42,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  24,                                  /* lineNo */
  40,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  19,                                  /* lineNo */
  8,                                   /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  15,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  19,                                  /* lineNo */
  13,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 16,    /* lineNo */
  42,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 16,  /* lineNo */
  42,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 17,  /* lineNo */
  42,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 16,  /* lineNo */
  9,                                   /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 17,  /* lineNo */
  9,                                   /* colNo */
  "Bloch_Full_Stability_MatrixEigFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  13,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  15,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  62,                                  /* lineNo */
  8,                                   /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  44,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  46,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo k_emlrtECI = { 2,   /* nDims */
  67,                                  /* lineNo */
  39,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  21,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  23,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo l_emlrtECI = { -1,  /* nDims */
  67,                                  /* lineNo */
  16,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  13,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  15,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo m_emlrtECI = { -1,  /* nDims */
  63,                                  /* lineNo */
  8,                                   /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  44,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  46,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo n_emlrtECI = { 2,   /* nDims */
  68,                                  /* lineNo */
  39,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  22,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  24,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo o_emlrtECI = { -1,  /* nDims */
  68,                                  /* lineNo */
  16,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo y_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  37,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  39,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo p_emlrtECI = { 2,   /* nDims */
  72,                                  /* lineNo */
  32,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  14,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  16,                                  /* colNo */
  "L_pl",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo q_emlrtECI = { -1,  /* nDims */
  72,                                  /* lineNo */
  9,                                   /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  37,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  39,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo r_emlrtECI = { 2,   /* nDims */
  73,                                  /* lineNo */
  32,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  14,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  16,                                  /* colNo */
  "L_mn",                              /* aName */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo s_emlrtECI = { -1,  /* nDims */
  73,                                  /* lineNo */
  9,                                   /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtECInfo t_emlrtECI = { 2,   /* nDims */
  83,                                  /* lineNo */
  28,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtDCInfo f_emlrtDCI = { 59,  /* lineNo */
  42,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 59,  /* lineNo */
  42,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 60,  /* lineNo */
  42,                                  /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 59,  /* lineNo */
  9,                                   /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 60,  /* lineNo */
  9,                                   /* colNo */
  "Bloch_Full_Stability_MatrixEigConjFAST",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m",/* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo g_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 19,/* lineNo */
  32,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 20,/* lineNo */
  32,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 24,/* lineNo */
  35,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 27,/* lineNo */
  9,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 25,/* lineNo */
  35,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 303,/* lineNo */
  5,                                   /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 7, /* lineNo */
  18,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 43,/* lineNo */
  27,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 44,/* lineNo */
  26,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 117,/* lineNo */
  10,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 59,/* lineNo */
  9,                                   /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 60,/* lineNo */
  9,                                   /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 62,/* lineNo */
  32,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 63,/* lineNo */
  32,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 72,/* lineNo */
  32,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 67,/* lineNo */
  39,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 73,/* lineNo */
  32,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 68,/* lineNo */
  39,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 76,/* lineNo */
  32,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 77,/* lineNo */
  64,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 76,/* lineNo */
  9,                                   /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 53,/* lineNo */
  22,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 76,/* lineNo */
  27,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 77,/* lineNo */
  26,                                  /* colNo */
  "LLE_Bloch_StabilitySpeedUp",        /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Stationary\\Krylov_E"
  "q_ControlDistance\\LLE_Bloch_StabilitySpeedUp.m"/* pName */
};

/* Function Declarations */
static void c_Bloch_Full_Stability_MatrixEi(c_LLE_Bloch_StabilitySpeedUpSta *SD,
  const emlrtStack *sp, real_T Stat_In_k, real_T Stat_Space_N, const real_T
  Stat_Space_k[512], real_T Stat_Eq_delta, real_T Stat_Eq_kappa, const real_T
  Stat_Eq_D[3], const real_T Stat_Eq_gamma_Kerr[512], real_T Stat_Sol_V, const
  creal_T Stat_Sol_Psi_k[512], const creal_T FF[262144], const creal_T FI[262144],
  creal_T g[1048576]);
static void d_Bloch_Full_Stability_MatrixEi(c_LLE_Bloch_StabilitySpeedUpSta *SD,
  const emlrtStack *sp, real_T Stat_In_k, real_T Stat_Space_N, const real_T
  Stat_Space_k[512], real_T Stat_Eq_delta, real_T Stat_Eq_kappa, const real_T
  Stat_Eq_D[3], const real_T Stat_Eq_gamma_Kerr[512], real_T Stat_Sol_V, const
  creal_T Stat_Sol_Psi_k[512], const creal_T FF[262144], const creal_T FI[262144],
  creal_T g[1048576]);

/* Function Definitions */
static void c_Bloch_Full_Stability_MatrixEi(c_LLE_Bloch_StabilitySpeedUpSta *SD,
  const emlrtStack *sp, real_T Stat_In_k, real_T Stat_Space_N, const real_T
  Stat_Space_k[512], real_T Stat_Eq_delta, real_T Stat_Eq_kappa, const real_T
  Stat_Eq_D[3], const real_T Stat_Eq_gamma_Kerr[512], real_T Stat_Sol_V, const
  creal_T Stat_Sol_Psi_k[512], const creal_T FF[262144], const creal_T FI[262144],
  creal_T g[1048576])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_creal_T *L_mn;
  emxArray_creal_T *L_pl;
  emxArray_creal_T *b_L_pl;
  emxArray_creal_T *b_result;
  emxArray_creal_T *c_result;
  emxArray_creal_T *result;
  emxArray_real_T *r;
  creal_T psi_hat[512];
  creal_T y[512];
  real_T b_Stat_Space_k[512];
  real_T b_y[512];
  real_T ar_tmp;
  real_T d;
  real_T d1;
  real_T d2;
  real_T z_im;
  real_T z_re;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T input_sizes_idx_1;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  L_L.Eq.mask; */
  for (i = 0; i < 512; i++) {
    psi_hat[i].re = Stat_Space_N * Stat_Sol_Psi_k[i].re;
    psi_hat[i].im = Stat_Space_N * Stat_Sol_Psi_k[i].im;
  }

  emxInit_creal_T(sp, &L_pl, 2, &g_emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  b_st.site = &j_emlrtRSI;
  emlrtFFTWSetNumThreads(6);
  emlrtFFTW_1D_C2C((real_T *)&psi_hat[0], (real_T *)&y[0], 1, 512, 512, 1, 1);
  i = L_pl->size[0] * L_pl->size[1];
  L_pl->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, L_pl, i, &g_emlrtRTEI);
  if (!(Stat_Space_N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Stat_Space_N, &b_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(Stat_Space_N);
  if (Stat_Space_N != i) {
    emlrtIntegerCheckR2012b(Stat_Space_N, &emlrtDCI, sp);
  }

  i1 = L_pl->size[0] * L_pl->size[1];
  L_pl->size[1] = (int32_T)Stat_Space_N;
  emxEnsureCapacity_creal_T(sp, L_pl, i1, &g_emlrtRTEI);
  if (Stat_Space_N != i) {
    emlrtIntegerCheckR2012b(Stat_Space_N, &d_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Stat_Space_N;
  for (i1 = 0; i1 < loop_ub; i1++) {
    L_pl->data[i1].re = 0.0;
    L_pl->data[i1].im = 0.0;
  }

  emxInit_creal_T(sp, &L_mn, 2, &h_emlrtRTEI, true);
  i1 = L_mn->size[0] * L_mn->size[1];
  L_mn->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, L_mn, i1, &h_emlrtRTEI);
  if (Stat_Space_N != i) {
    emlrtIntegerCheckR2012b(Stat_Space_N, &c_emlrtDCI, sp);
  }

  i1 = L_mn->size[0] * L_mn->size[1];
  loop_ub = (int32_T)Stat_Space_N;
  L_mn->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, L_mn, i1, &h_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(Stat_Space_N, &e_emlrtDCI, sp);
  }

  for (i = 0; i < loop_ub; i++) {
    L_mn->data[i].re = 0.0;
    L_mn->data[i].im = 0.0;
  }

  if (1.0 > Stat_Space_N) {
    i = 0;
  } else {
    if (1 > L_pl->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, L_pl->size[1], &l_emlrtBCI, sp);
    }

    if (loop_ub > L_pl->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_pl->size[1],
        &k_emlrtBCI, sp);
    }

    i = loop_ub;
  }

  emxInit_real_T(sp, &r, 2, &o_emlrtRTEI, true);
  i1 = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, r, i1, &i_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    r->data[i1] = Stat_Eq_delta;
  }

  if (i != r->size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(i, r->size[1], &i_emlrtECI, sp);
  }

  input_sizes_idx_1 = r->size[1];
  for (i = 0; i < input_sizes_idx_1; i++) {
    L_pl->data[i].re = r->data[i];
    L_pl->data[i].im = 0.0;
  }

  if (1.0 > Stat_Space_N) {
    i = 0;
  } else {
    if (1 > L_mn->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, L_mn->size[1], &f_emlrtBCI, sp);
    }

    if (loop_ub > L_mn->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_mn->size[1],
        &e_emlrtBCI, sp);
    }

    i = loop_ub;
  }

  i1 = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, r, i1, &j_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    r->data[i1] = Stat_Eq_delta;
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
  emxInit_creal_T(sp, &b_L_pl, 2, &k_emlrtRTEI, true);
  for (b_i = 0; b_i < 2; b_i++) {
    if (1.0 > Stat_Space_N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_pl->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_pl->size[1], &j_emlrtBCI, sp);
      }

      if (loop_ub > L_pl->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_pl->size[1],
          &i_emlrtBCI, sp);
      }

      input_sizes_idx_1 = loop_ub;
    }

    iv[0] = 1;
    iv[1] = input_sizes_idx_1;
    iv1[0] = 1;
    iv1[1] = 512;
    if (input_sizes_idx_1 != 512) {
      emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &h_emlrtECI, sp);
    }

    if (1.0 > Stat_Space_N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_pl->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_pl->size[1], &h_emlrtBCI, sp);
      }

      if (loop_ub > L_pl->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_pl->size[1],
          &g_emlrtBCI, sp);
      }

      input_sizes_idx_1 = (int32_T)Stat_Space_N;
    }

    if (input_sizes_idx_1 != 512) {
      emlrtSubAssignSizeCheck1dR2017a(input_sizes_idx_1, 512, &g_emlrtECI, sp);
    }

    st.site = &d_emlrtRSI;
    b_st.site = &w_emlrtRSI;
    for (i = 0; i < 512; i++) {
      b_Stat_Space_k[i] = Stat_Space_k[i] + Stat_In_k;
    }

    st.site = &d_emlrtRSI;
    power(&st, b_Stat_Space_k, (real_T)b_i + 2.0, b_y);
    i = b_L_pl->size[0] * b_L_pl->size[1];
    b_L_pl->size[0] = 1;
    b_L_pl->size[1] = 512;
    emxEnsureCapacity_creal_T(sp, b_L_pl, i, &k_emlrtRTEI);
    for (i = 0; i < 512; i++) {
      b_L_pl->data[i] = L_pl->data[i];
    }

    for (i = 0; i < 512; i++) {
      psi_hat[i].re = b_L_pl->data[i].re + b_y[i] * Stat_Eq_D[b_i + 1] / dv[b_i
        + 1];
      psi_hat[i].im = b_L_pl->data[i].im;
    }

    for (i = 0; i < 512; i++) {
      L_pl->data[i] = psi_hat[i];
    }

    if (1.0 > Stat_Space_N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_mn->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_mn->size[1], &d_emlrtBCI, sp);
      }

      if (loop_ub > L_mn->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_mn->size[1],
          &c_emlrtBCI, sp);
      }

      input_sizes_idx_1 = loop_ub;
    }

    iv[0] = 1;
    iv[1] = input_sizes_idx_1;
    iv1[0] = 1;
    iv1[1] = 512;
    if (input_sizes_idx_1 != 512) {
      emlrtSizeEqCheckNDR2012b(&iv[0], &iv1[0], &e_emlrtECI, sp);
    }

    if (1.0 > Stat_Space_N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_mn->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_mn->size[1], &b_emlrtBCI, sp);
      }

      if (loop_ub > L_mn->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_mn->size[1],
          &emlrtBCI, sp);
      }

      input_sizes_idx_1 = (int32_T)Stat_Space_N;
    }

    if (input_sizes_idx_1 != 512) {
      emlrtSubAssignSizeCheck1dR2017a(input_sizes_idx_1, 512, &d_emlrtECI, sp);
    }

    st.site = &e_emlrtRSI;
    b_st.site = &w_emlrtRSI;
    for (i = 0; i < 512; i++) {
      b_Stat_Space_k[i] = -Stat_Space_k[i] - Stat_In_k;
    }

    st.site = &e_emlrtRSI;
    power(&st, b_Stat_Space_k, (real_T)b_i + 2.0, b_y);
    i = b_L_pl->size[0] * b_L_pl->size[1];
    b_L_pl->size[0] = 1;
    b_L_pl->size[1] = 512;
    emxEnsureCapacity_creal_T(sp, b_L_pl, i, &m_emlrtRTEI);
    for (i = 0; i < 512; i++) {
      b_L_pl->data[i] = L_mn->data[i];
    }

    for (i = 0; i < 512; i++) {
      psi_hat[i].re = b_L_pl->data[i].re + b_y[i] * Stat_Eq_D[b_i + 1] / dv[b_i
        + 1];
      psi_hat[i].im = b_L_pl->data[i].im;
    }

    for (i = 0; i < 512; i++) {
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
  iv[1] = 512;
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])L_pl->size, iv, &c_emlrtECI, sp);
  iv[0] = 1;
  iv[1] = 512;
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])L_mn->size, iv, &b_emlrtECI, sp);

  /*   L_pl  =   L_pl.'.*x(1:Stat.Space.N)                ; */
  /*    L_mn =    L_mn.'.*x(Stat.Space.N+1:2*Stat.Space.N) ; */
  /*         L_pl                   = L_L.Eq.L + 1/2*L_L.In.k^2*L_L.In.Fin_D+L_L.In.k*L_L.In.Fin_D*L_L.Space.k+(L_L.In.k+L_L.Space.k)*L_L.Sol.V; */
  /*        L_mn                   = L_L.Eq.L + 1/2*L_L.In.k^2*L_L.In.Fin_D-L_L.In.k*L_L.In.Fin_D*L_L.Space.k+(-L_L.In.k+L_L.Space.k)*L_L.Sol.V; */
  ar_tmp = 0.0 * Stat_Eq_kappa;
  if (Stat_Eq_kappa == 0.0) {
    z_re = ar_tmp / 2.0;
    z_im = 0.0;
  } else if (ar_tmp == 0.0) {
    z_re = 0.0;
    z_im = Stat_Eq_kappa / 2.0;
  } else {
    z_re = rtNaN;
    z_im = Stat_Eq_kappa / 2.0;
  }

  emxInit_creal_T(sp, &result, 2, &p_emlrtRTEI, true);
  st.site = &f_emlrtRSI;
  for (i = 0; i < 512; i++) {
    psi_hat[i].re = (L_pl->data[i].re - (Stat_Space_k[i] + Stat_In_k) *
                     Stat_Sol_V) - z_re;
    psi_hat[i].im = L_pl->data[i].im - z_im;
  }

  emxFree_creal_T(&L_pl);
  memset(&SD->u1.f2.reshapes_f1[0], 0, 262144U * sizeof(creal_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    SD->u1.f2.reshapes_f1[input_sizes_idx_1 + (input_sizes_idx_1 << 9)] =
      psi_hat[input_sizes_idx_1];
  }

  b_st.site = &y_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  if ((!(Stat_Space_N == 512.0)) && (!(Stat_Space_N == 0.0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if (Stat_Space_N != 0.0) {
    input_sizes_idx_1 = (int32_T)Stat_Space_N;
  } else {
    input_sizes_idx_1 = 0;
  }

  i = result->size[0] * result->size[1];
  result->size[0] = 512;
  result->size[1] = input_sizes_idx_1 + 512;
  emxEnsureCapacity_creal_T(&b_st, result, i, &l_emlrtRTEI);
  for (i = 0; i < 512; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      result->data[i1 + 512 * i] = SD->u1.f2.reshapes_f1[i1 + (i << 9)];
    }
  }

  for (i = 0; i < input_sizes_idx_1; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      b_i = i1 + 512 * (i + 512);
      result->data[b_i].re = 0.0;
      result->data[b_i].im = 0.0;
    }
  }

  if (Stat_Eq_kappa == 0.0) {
    z_re = ar_tmp / 2.0;
    z_im = 0.0;
  } else if (ar_tmp == 0.0) {
    z_re = 0.0;
    z_im = Stat_Eq_kappa / 2.0;
  } else {
    z_re = rtNaN;
    z_im = Stat_Eq_kappa / 2.0;
  }

  emxInit_creal_T(sp, &b_result, 2, &q_emlrtRTEI, true);
  st.site = &g_emlrtRSI;
  for (i = 0; i < 512; i++) {
    psi_hat[i].re = -(L_mn->data[i].re - (-Stat_Space_k[i] - Stat_In_k) *
                      Stat_Sol_V) - z_re;
    psi_hat[i].im = -L_mn->data[i].im - z_im;
  }

  emxFree_creal_T(&L_mn);
  memset(&SD->u1.f2.reshapes_f1[0], 0, 262144U * sizeof(creal_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    SD->u1.f2.reshapes_f1[input_sizes_idx_1 + (input_sizes_idx_1 << 9)] =
      psi_hat[input_sizes_idx_1];
  }

  b_st.site = &y_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  if ((!(Stat_Space_N == 512.0)) && (!(Stat_Space_N == 0.0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if (Stat_Space_N != 0.0) {
    input_sizes_idx_1 = (int32_T)Stat_Space_N;
  } else {
    input_sizes_idx_1 = 0;
  }

  if (Stat_Space_N != 0.0) {
    iv[1] = (int32_T)Stat_Space_N;
  } else {
    iv[1] = 0;
  }

  i = b_result->size[0] * b_result->size[1];
  b_result->size[0] = 512;
  b_result->size[1] = input_sizes_idx_1 + 512;
  emxEnsureCapacity_creal_T(&b_st, b_result, i, &l_emlrtRTEI);
  for (i = 0; i < input_sizes_idx_1; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      b_i = i1 + 512 * i;
      b_result->data[b_i].re = 0.0;
      b_result->data[b_i].im = 0.0;
    }
  }

  for (i = 0; i < 512; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      b_result->data[i1 + 512 * (i + iv[1])] = SD->u1.f2.reshapes_f1[i1 + (i <<
        9)];
    }
  }

  st.site = &f_emlrtRSI;
  b_st.site = &y_emlrtRSI;
  c_st.site = &ab_emlrtRSI;
  if (b_result->size[1] != result->size[1]) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_creal_T(&c_st, &c_result, 2, &r_emlrtRTEI, true);
  i = c_result->size[0] * c_result->size[1];
  c_result->size[0] = 1024;
  c_result->size[1] = result->size[1];
  emxEnsureCapacity_creal_T(&b_st, c_result, i, &n_emlrtRTEI);
  loop_ub = result->size[1];
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      c_result->data[i1 + c_result->size[0] * i] = result->data[i1 + 512 * i];
    }
  }

  loop_ub = result->size[1];
  emxFree_creal_T(&result);
  for (i = 0; i < loop_ub; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      c_result->data[(i1 + c_result->size[0] * i) + 512] = b_result->data[i1 +
        512 * i];
    }
  }

  emxFree_creal_T(&b_result);
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    b_y[input_sizes_idx_1] = muDoubleScalarHypot(y[input_sizes_idx_1].re,
      y[input_sizes_idx_1].im);
  }

  for (i = 0; i < 262144; i++) {
    SD->u1.f2.a_tmp[i].re = -FF[i].re;
    SD->u1.f2.a_tmp[i].im = -FF[i].im;
  }

  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    d = b_y[input_sizes_idx_1];
    b_Stat_Space_k[input_sizes_idx_1] = Stat_Eq_gamma_Kerr[input_sizes_idx_1] *
      (2.0 * (d * d));
  }

  memset(&SD->u1.f2.b_b[0], 0, 262144U * sizeof(real_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    SD->u1.f2.b_b[input_sizes_idx_1 + (input_sizes_idx_1 << 9)] =
      b_Stat_Space_k[input_sizes_idx_1];
  }

  st.site = &h_emlrtRSI;
  for (i = 0; i < 262144; i++) {
    SD->u1.f2.b[i].re = SD->u1.f2.b_b[i];
    SD->u1.f2.b[i].im = 0.0;
  }

  for (i = 0; i < 512; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      z_im = 0.0;
      ar_tmp = 0.0;
      for (b_i = 0; b_i < 512; b_i++) {
        input_sizes_idx_1 = i + (b_i << 9);
        loop_ub = b_i + (i1 << 9);
        d = SD->u1.f2.a_tmp[input_sizes_idx_1].re;
        d1 = SD->u1.f2.a_tmp[input_sizes_idx_1].im;
        d2 = SD->u1.f2.b[loop_ub].re;
        z_re = SD->u1.f2.b[loop_ub].im;
        z_im += d * d2 - d1 * z_re;
        ar_tmp += d * z_re + d1 * d2;
      }

      b_i = i + (i1 << 9);
      SD->u1.f2.reshapes_f1[b_i].re = z_im;
      SD->u1.f2.reshapes_f1[b_i].im = ar_tmp;
    }
  }

  b_st.site = &bb_emlrtRSI;
  mtimes(SD->u1.f2.reshapes_f1, FI, SD->u1.f2.y);
  st.site = &h_emlrtRSI;
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    d = y[input_sizes_idx_1].re;
    d1 = y[input_sizes_idx_1].im;
    z_re = d * d1;
    d2 = Stat_Eq_gamma_Kerr[input_sizes_idx_1];
    psi_hat[input_sizes_idx_1].re = d2 * (d * d - d1 * d1);
    psi_hat[input_sizes_idx_1].im = d2 * (z_re + z_re);
  }

  memset(&SD->u1.f2.b[0], 0, 262144U * sizeof(creal_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    SD->u1.f2.b[input_sizes_idx_1 + (input_sizes_idx_1 << 9)] =
      psi_hat[input_sizes_idx_1];
  }

  b_st.site = &bb_emlrtRSI;
  mtimes(SD->u1.f2.a_tmp, SD->u1.f2.b, SD->u1.f2.reshapes_f1);
  st.site = &h_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  mtimes(SD->u1.f2.reshapes_f1, FI, SD->u1.f2.b_y);
  st.site = &i_emlrtRSI;
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    z_im = y[input_sizes_idx_1].re;
    ar_tmp = -y[input_sizes_idx_1].im;
    z_re = z_im * ar_tmp;
    d = Stat_Eq_gamma_Kerr[input_sizes_idx_1];
    psi_hat[input_sizes_idx_1].re = d * (z_im * z_im - ar_tmp * ar_tmp);
    psi_hat[input_sizes_idx_1].im = d * (z_re + z_re);
  }

  memset(&SD->u1.f2.b[0], 0, 262144U * sizeof(creal_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    SD->u1.f2.b[input_sizes_idx_1 + (input_sizes_idx_1 << 9)] =
      psi_hat[input_sizes_idx_1];
  }

  b_st.site = &bb_emlrtRSI;
  mtimes(FF, SD->u1.f2.b, SD->u1.f2.reshapes_f1);
  st.site = &i_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  mtimes(SD->u1.f2.reshapes_f1, FI, SD->u1.f2.a_tmp);
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    d = muDoubleScalarHypot(y[input_sizes_idx_1].re, y[input_sizes_idx_1].im);
    b_Stat_Space_k[input_sizes_idx_1] = Stat_Eq_gamma_Kerr[input_sizes_idx_1] *
      (2.0 * (d * d));
  }

  memset(&SD->u1.f2.b_b[0], 0, 262144U * sizeof(real_T));
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    SD->u1.f2.b_b[input_sizes_idx_1 + (input_sizes_idx_1 << 9)] =
      b_Stat_Space_k[input_sizes_idx_1];
  }

  st.site = &i_emlrtRSI;
  for (i = 0; i < 262144; i++) {
    SD->u1.f2.b[i].re = SD->u1.f2.b_b[i];
    SD->u1.f2.b[i].im = 0.0;
  }

  for (i = 0; i < 512; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      z_im = 0.0;
      ar_tmp = 0.0;
      for (b_i = 0; b_i < 512; b_i++) {
        input_sizes_idx_1 = i + (b_i << 9);
        loop_ub = b_i + (i1 << 9);
        d = FF[input_sizes_idx_1].re;
        d1 = FF[input_sizes_idx_1].im;
        d2 = SD->u1.f2.b[loop_ub].re;
        z_re = SD->u1.f2.b[loop_ub].im;
        z_im += d * d2 - d1 * z_re;
        ar_tmp += d * z_re + d1 * d2;
      }

      b_i = i + (i1 << 9);
      SD->u1.f2.FF[b_i].re = z_im;
      SD->u1.f2.FF[b_i].im = ar_tmp;
    }
  }

  b_st.site = &bb_emlrtRSI;
  mtimes(SD->u1.f2.FF, FI, SD->u1.f2.reshapes_f1);
  iv[0] = 1024;
  iv[1] = 1024;
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])c_result->size, iv, &emlrtECI, sp);
  for (i = 0; i < 512; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      input_sizes_idx_1 = i1 + (i << 9);
      loop_ub = i1 + (i << 10);
      g[loop_ub] = SD->u1.f2.y[input_sizes_idx_1];
      b_i = i1 + ((i + 512) << 10);
      g[b_i] = SD->u1.f2.b_y[input_sizes_idx_1];
      g[loop_ub + 512] = SD->u1.f2.a_tmp[input_sizes_idx_1];
      g[b_i + 512] = SD->u1.f2.reshapes_f1[input_sizes_idx_1];
    }
  }

  for (i = 0; i < 1048576; i++) {
    z_re = c_result->data[i].re + g[i].re;
    z_im = c_result->data[i].im + g[i].im;
    g[i].re = 0.0 * z_re - (-z_im);
    g[i].im = 0.0 * z_im + -z_re;
  }

  emxFree_creal_T(&c_result);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void d_Bloch_Full_Stability_MatrixEi(c_LLE_Bloch_StabilitySpeedUpSta *SD,
  const emlrtStack *sp, real_T Stat_In_k, real_T Stat_Space_N, const real_T
  Stat_Space_k[512], real_T Stat_Eq_delta, real_T Stat_Eq_kappa, const real_T
  Stat_Eq_D[3], const real_T Stat_Eq_gamma_Kerr[512], real_T Stat_Sol_V, const
  creal_T Stat_Sol_Psi_k[512], const creal_T FF[262144], const creal_T FI[262144],
  creal_T g[1048576])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_creal_T *L_mn;
  emxArray_creal_T *L_pl;
  emxArray_creal_T *Linear_part;
  emxArray_creal_T *b_L_pl;
  emxArray_creal_T *c_result;
  emxArray_creal_T *e_result;
  emxArray_real_T *r;
  creal_T b_Stat_Sol_Psi_k[512];
  creal_T f_psi[512];
  real_T b_Stat_Space_k[512];
  real_T y[512];
  real_T ar_tmp;
  real_T d;
  real_T d1;
  real_T d2;
  real_T z_im;
  real_T z_re;
  int32_T b_result[2];
  int32_T result[2];
  int32_T d_result;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T input_sizes_idx_1;
  int32_T loop_ub;
  int32_T sizes_idx_1;
  boolean_T empty_non_axis_sizes;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  for (i = 0; i < 512; i++) {
    b_Stat_Sol_Psi_k[i].re = Stat_Space_N * Stat_Sol_Psi_k[i].re;
    b_Stat_Sol_Psi_k[i].im = Stat_Space_N * Stat_Sol_Psi_k[i].im;
  }

  st.site = &bc_emlrtRSI;
  ifft(b_Stat_Sol_Psi_k, f_psi);
  emxInit_creal_T(sp, &L_pl, 2, &s_emlrtRTEI, true);
  i = L_pl->size[0] * L_pl->size[1];
  L_pl->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, L_pl, i, &s_emlrtRTEI);
  if (!(Stat_Space_N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Stat_Space_N, &g_emlrtDCI, sp);
  }

  i = (int32_T)muDoubleScalarFloor(Stat_Space_N);
  if (Stat_Space_N != i) {
    emlrtIntegerCheckR2012b(Stat_Space_N, &f_emlrtDCI, sp);
  }

  i1 = L_pl->size[0] * L_pl->size[1];
  L_pl->size[1] = (int32_T)Stat_Space_N;
  emxEnsureCapacity_creal_T(sp, L_pl, i1, &s_emlrtRTEI);
  if (Stat_Space_N != i) {
    emlrtIntegerCheckR2012b(Stat_Space_N, &i_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Stat_Space_N;
  for (i1 = 0; i1 < loop_ub; i1++) {
    L_pl->data[i1].re = 0.0;
    L_pl->data[i1].im = 0.0;
  }

  emxInit_creal_T(sp, &L_mn, 2, &t_emlrtRTEI, true);
  i1 = L_mn->size[0] * L_mn->size[1];
  L_mn->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, L_mn, i1, &t_emlrtRTEI);
  if (Stat_Space_N != i) {
    emlrtIntegerCheckR2012b(Stat_Space_N, &h_emlrtDCI, sp);
  }

  i1 = L_mn->size[0] * L_mn->size[1];
  loop_ub = (int32_T)Stat_Space_N;
  L_mn->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, L_mn, i1, &t_emlrtRTEI);
  if (loop_ub != i) {
    emlrtIntegerCheckR2012b(Stat_Space_N, &j_emlrtDCI, sp);
  }

  for (i = 0; i < loop_ub; i++) {
    L_mn->data[i].re = 0.0;
    L_mn->data[i].im = 0.0;
  }

  if (1.0 > Stat_Space_N) {
    i = 0;
  } else {
    if (1 > L_pl->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, L_pl->size[1], &m_emlrtBCI, sp);
    }

    if (loop_ub > L_pl->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_pl->size[1],
        &n_emlrtBCI, sp);
    }

    i = loop_ub;
  }

  emxInit_real_T(sp, &r, 2, &eb_emlrtRTEI, true);
  i1 = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, r, i1, &u_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    r->data[i1] = Stat_Eq_delta;
  }

  if (i != r->size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(i, r->size[1], &j_emlrtECI, sp);
  }

  input_sizes_idx_1 = r->size[1];
  for (i = 0; i < input_sizes_idx_1; i++) {
    L_pl->data[i].re = r->data[i];
    L_pl->data[i].im = 0.0;
  }

  if (1.0 > Stat_Space_N) {
    i = 0;
  } else {
    if (1 > L_mn->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, L_mn->size[1], &s_emlrtBCI, sp);
    }

    if (loop_ub > L_mn->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_mn->size[1],
        &t_emlrtBCI, sp);
    }

    i = loop_ub;
  }

  i1 = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = loop_ub;
  emxEnsureCapacity_real_T(sp, r, i1, &v_emlrtRTEI);
  for (i1 = 0; i1 < loop_ub; i1++) {
    r->data[i1] = Stat_Eq_delta;
  }

  if (i != r->size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(i, r->size[1], &m_emlrtECI, sp);
  }

  input_sizes_idx_1 = r->size[1];
  for (i = 0; i < input_sizes_idx_1; i++) {
    L_mn->data[i].re = r->data[i];
    L_mn->data[i].im = 0.0;
  }

  emxFree_real_T(&r);
  emxInit_creal_T(sp, &b_L_pl, 2, &x_emlrtRTEI, true);
  for (sizes_idx_1 = 0; sizes_idx_1 < 2; sizes_idx_1++) {
    if (1.0 > Stat_Space_N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_pl->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_pl->size[1], &o_emlrtBCI, sp);
      }

      if (loop_ub > L_pl->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_pl->size[1],
          &p_emlrtBCI, sp);
      }

      input_sizes_idx_1 = loop_ub;
    }

    result[0] = 1;
    result[1] = input_sizes_idx_1;
    b_result[0] = 1;
    b_result[1] = 512;
    if (input_sizes_idx_1 != 512) {
      emlrtSizeEqCheckNDR2012b(&result[0], &b_result[0], &k_emlrtECI, sp);
    }

    if (1.0 > Stat_Space_N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_pl->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_pl->size[1], &q_emlrtBCI, sp);
      }

      if (loop_ub > L_pl->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_pl->size[1],
          &r_emlrtBCI, sp);
      }

      input_sizes_idx_1 = (int32_T)Stat_Space_N;
    }

    if (input_sizes_idx_1 != 512) {
      emlrtSubAssignSizeCheck1dR2017a(input_sizes_idx_1, 512, &l_emlrtECI, sp);
    }

    for (i = 0; i < 512; i++) {
      b_Stat_Space_k[i] = Stat_Space_k[i] + Stat_In_k;
    }

    st.site = &cc_emlrtRSI;
    power(&st, b_Stat_Space_k, (real_T)sizes_idx_1 + 2.0, y);
    d = (real_T)sizes_idx_1 + 2.0;
    st.site = &cc_emlrtRSI;
    factorial(&st, &d);
    i = b_L_pl->size[0] * b_L_pl->size[1];
    b_L_pl->size[0] = 1;
    b_L_pl->size[1] = 512;
    emxEnsureCapacity_creal_T(sp, b_L_pl, i, &x_emlrtRTEI);
    for (i = 0; i < 512; i++) {
      b_L_pl->data[i] = L_pl->data[i];
    }

    for (i = 0; i < 512; i++) {
      b_Stat_Sol_Psi_k[i].re = b_L_pl->data[i].re + y[i] * Stat_Eq_D[sizes_idx_1
        + 1] / d;
      b_Stat_Sol_Psi_k[i].im = b_L_pl->data[i].im;
    }

    for (i = 0; i < 512; i++) {
      L_pl->data[i] = b_Stat_Sol_Psi_k[i];
    }

    if (1.0 > Stat_Space_N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_mn->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_mn->size[1], &u_emlrtBCI, sp);
      }

      if (loop_ub > L_mn->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_mn->size[1],
          &v_emlrtBCI, sp);
      }

      input_sizes_idx_1 = loop_ub;
    }

    result[0] = 1;
    result[1] = input_sizes_idx_1;
    b_result[0] = 1;
    b_result[1] = 512;
    if (input_sizes_idx_1 != 512) {
      emlrtSizeEqCheckNDR2012b(&result[0], &b_result[0], &n_emlrtECI, sp);
    }

    if (1.0 > Stat_Space_N) {
      input_sizes_idx_1 = 0;
    } else {
      if (1 > L_mn->size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, L_mn->size[1], &w_emlrtBCI, sp);
      }

      if (loop_ub > L_mn->size[1]) {
        emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_mn->size[1],
          &x_emlrtBCI, sp);
      }

      input_sizes_idx_1 = (int32_T)Stat_Space_N;
    }

    if (input_sizes_idx_1 != 512) {
      emlrtSubAssignSizeCheck1dR2017a(input_sizes_idx_1, 512, &o_emlrtECI, sp);
    }

    for (i = 0; i < 512; i++) {
      b_Stat_Space_k[i] = -Stat_Space_k[i] - Stat_In_k;
    }

    st.site = &dc_emlrtRSI;
    power(&st, b_Stat_Space_k, (real_T)sizes_idx_1 + 2.0, y);
    d = (real_T)sizes_idx_1 + 2.0;
    st.site = &dc_emlrtRSI;
    factorial(&st, &d);
    i = b_L_pl->size[0] * b_L_pl->size[1];
    b_L_pl->size[0] = 1;
    b_L_pl->size[1] = 512;
    emxEnsureCapacity_creal_T(sp, b_L_pl, i, &ab_emlrtRTEI);
    for (i = 0; i < 512; i++) {
      b_L_pl->data[i] = L_mn->data[i];
    }

    for (i = 0; i < 512; i++) {
      b_Stat_Sol_Psi_k[i].re = b_L_pl->data[i].re + y[i] * Stat_Eq_D[sizes_idx_1
        + 1] / d;
      b_Stat_Sol_Psi_k[i].im = b_L_pl->data[i].im;
    }

    for (i = 0; i < 512; i++) {
      L_mn->data[i] = b_Stat_Sol_Psi_k[i];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  if (1.0 > Stat_Space_N) {
    input_sizes_idx_1 = 0;
  } else {
    if (1 > L_pl->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, L_pl->size[1], &y_emlrtBCI, sp);
    }

    if (loop_ub > L_pl->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_pl->size[1],
        &ab_emlrtBCI, sp);
    }

    input_sizes_idx_1 = loop_ub;
  }

  result[0] = 1;
  result[1] = input_sizes_idx_1;
  b_result[0] = 1;
  b_result[1] = 512;
  if (input_sizes_idx_1 != 512) {
    emlrtSizeEqCheckNDR2012b(&result[0], &b_result[0], &p_emlrtECI, sp);
  }

  if (1.0 > Stat_Space_N) {
    input_sizes_idx_1 = 0;
  } else {
    if (1 > L_pl->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, L_pl->size[1], &bb_emlrtBCI, sp);
    }

    if (loop_ub > L_pl->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_pl->size[1],
        &cb_emlrtBCI, sp);
    }

    input_sizes_idx_1 = (int32_T)Stat_Space_N;
  }

  if (input_sizes_idx_1 != 512) {
    emlrtSubAssignSizeCheck1dR2017a(input_sizes_idx_1, 512, &q_emlrtECI, sp);
  }

  i = b_L_pl->size[0] * b_L_pl->size[1];
  b_L_pl->size[0] = 1;
  b_L_pl->size[1] = 512;
  emxEnsureCapacity_creal_T(sp, b_L_pl, i, &w_emlrtRTEI);
  for (i = 0; i < 512; i++) {
    b_L_pl->data[i] = L_pl->data[i];
  }

  for (i = 0; i < 512; i++) {
    b_Stat_Sol_Psi_k[i].re = b_L_pl->data[i].re - (Stat_Space_k[i] + Stat_In_k) *
      Stat_Sol_V;
    b_Stat_Sol_Psi_k[i].im = b_L_pl->data[i].im;
  }

  for (i = 0; i < 512; i++) {
    L_pl->data[i] = b_Stat_Sol_Psi_k[i];
  }

  if (1.0 > Stat_Space_N) {
    input_sizes_idx_1 = 0;
  } else {
    if (1 > L_mn->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, L_mn->size[1], &db_emlrtBCI, sp);
    }

    if (loop_ub > L_mn->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_mn->size[1],
        &eb_emlrtBCI, sp);
    }

    input_sizes_idx_1 = loop_ub;
  }

  result[0] = 1;
  result[1] = input_sizes_idx_1;
  b_result[0] = 1;
  b_result[1] = 512;
  if (input_sizes_idx_1 != 512) {
    emlrtSizeEqCheckNDR2012b(&result[0], &b_result[0], &r_emlrtECI, sp);
  }

  if (1.0 > Stat_Space_N) {
    input_sizes_idx_1 = 0;
  } else {
    if (1 > L_mn->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, L_mn->size[1], &fb_emlrtBCI, sp);
    }

    if (loop_ub > L_mn->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)Stat_Space_N, 1, L_mn->size[1],
        &gb_emlrtBCI, sp);
    }

    input_sizes_idx_1 = (int32_T)Stat_Space_N;
  }

  if (input_sizes_idx_1 != 512) {
    emlrtSubAssignSizeCheck1dR2017a(input_sizes_idx_1, 512, &s_emlrtECI, sp);
  }

  i = b_L_pl->size[0] * b_L_pl->size[1];
  b_L_pl->size[0] = 1;
  b_L_pl->size[1] = 512;
  emxEnsureCapacity_creal_T(sp, b_L_pl, i, &y_emlrtRTEI);
  for (i = 0; i < 512; i++) {
    b_L_pl->data[i] = L_mn->data[i];
  }

  for (i = 0; i < 512; i++) {
    b_Stat_Sol_Psi_k[i].re = b_L_pl->data[i].re - (-Stat_Space_k[i] - Stat_In_k)
      * Stat_Sol_V;
    b_Stat_Sol_Psi_k[i].im = b_L_pl->data[i].im;
  }

  for (i = 0; i < 512; i++) {
    L_mn->data[i] = b_Stat_Sol_Psi_k[i];
  }

  ar_tmp = 0.0 * Stat_Eq_kappa;
  if (Stat_Eq_kappa == 0.0) {
    z_re = ar_tmp / 2.0;
    z_im = 0.0;
  } else if (ar_tmp == 0.0) {
    z_re = 0.0;
    z_im = Stat_Eq_kappa / 2.0;
  } else {
    z_re = rtNaN;
    z_im = Stat_Eq_kappa / 2.0;
  }

  emxInit_creal_T(sp, &c_result, 2, &fb_emlrtRTEI, true);
  st.site = &ec_emlrtRSI;
  i = b_L_pl->size[0] * b_L_pl->size[1];
  b_L_pl->size[0] = 1;
  b_L_pl->size[1] = L_pl->size[1];
  emxEnsureCapacity_creal_T(&st, b_L_pl, i, &bb_emlrtRTEI);
  input_sizes_idx_1 = L_pl->size[0] * L_pl->size[1];
  for (i = 0; i < input_sizes_idx_1; i++) {
    b_L_pl->data[i].re = L_pl->data[i].re - z_re;
    b_L_pl->data[i].im = L_pl->data[i].im - z_im;
  }

  emxFree_creal_T(&L_pl);
  emxInit_creal_T(&st, &Linear_part, 2, &db_emlrtRTEI, true);
  b_st.site = &ec_emlrtRSI;
  c_diag(&b_st, b_L_pl, Linear_part);
  b_st.site = &y_emlrtRSI;
  if ((Linear_part->size[0] != 0) && (Linear_part->size[1] != 0)) {
    d_result = Linear_part->size[0];
  } else if (Stat_Space_N != 0.0) {
    d_result = loop_ub;
  } else {
    d_result = muIntScalarMax_sint32(Linear_part->size[0], 0);
    if (loop_ub > d_result) {
      d_result = loop_ub;
    }
  }

  c_st.site = &ab_emlrtRSI;
  if ((Linear_part->size[0] != d_result) && ((Linear_part->size[0] != 0) &&
       (Linear_part->size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((loop_ub != d_result) && (!(Stat_Space_N == 0.0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (d_result == 0);
  if (empty_non_axis_sizes || ((Linear_part->size[0] != 0) && (Linear_part->
        size[1] != 0))) {
    input_sizes_idx_1 = Linear_part->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes || (Stat_Space_N != 0.0)) {
    sizes_idx_1 = loop_ub;
  } else {
    sizes_idx_1 = 0;
  }

  i = c_result->size[0] * c_result->size[1];
  c_result->size[0] = d_result;
  c_result->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_creal_T(&b_st, c_result, i, &l_emlrtRTEI);
  for (i = 0; i < input_sizes_idx_1; i++) {
    for (i1 = 0; i1 < d_result; i1++) {
      c_result->data[i1 + c_result->size[0] * i] = Linear_part->data[i1 +
        d_result * i];
    }
  }

  for (i = 0; i < sizes_idx_1; i++) {
    for (i1 = 0; i1 < d_result; i1++) {
      i2 = i + input_sizes_idx_1;
      c_result->data[i1 + c_result->size[0] * i2].re = 0.0;
      c_result->data[i1 + c_result->size[0] * i2].im = 0.0;
    }
  }

  if (Stat_Eq_kappa == 0.0) {
    z_re = ar_tmp / 2.0;
    z_im = 0.0;
  } else if (ar_tmp == 0.0) {
    z_re = 0.0;
    z_im = Stat_Eq_kappa / 2.0;
  } else {
    z_re = rtNaN;
    z_im = Stat_Eq_kappa / 2.0;
  }

  emxInit_creal_T(sp, &e_result, 2, &gb_emlrtRTEI, true);
  st.site = &fc_emlrtRSI;
  i = b_L_pl->size[0] * b_L_pl->size[1];
  b_L_pl->size[0] = 1;
  b_L_pl->size[1] = L_mn->size[1];
  emxEnsureCapacity_creal_T(&st, b_L_pl, i, &cb_emlrtRTEI);
  input_sizes_idx_1 = L_mn->size[0] * L_mn->size[1];
  for (i = 0; i < input_sizes_idx_1; i++) {
    b_L_pl->data[i].re = -L_mn->data[i].re - z_re;
    b_L_pl->data[i].im = -L_mn->data[i].im - z_im;
  }

  emxFree_creal_T(&L_mn);
  b_st.site = &fc_emlrtRSI;
  c_diag(&b_st, b_L_pl, Linear_part);
  b_st.site = &y_emlrtRSI;
  emxFree_creal_T(&b_L_pl);
  if (Stat_Space_N != 0.0) {
    d_result = loop_ub;
  } else if ((Linear_part->size[0] != 0) && (Linear_part->size[1] != 0)) {
    d_result = Linear_part->size[0];
  } else {
    d_result = loop_ub;
    if (Linear_part->size[0] > loop_ub) {
      d_result = Linear_part->size[0];
    }
  }

  c_st.site = &ab_emlrtRSI;
  if ((loop_ub != d_result) && (!(Stat_Space_N == 0.0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((Linear_part->size[0] != d_result) && ((Linear_part->size[0] != 0) &&
       (Linear_part->size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (d_result == 0);
  if (empty_non_axis_sizes || (Stat_Space_N != 0.0)) {
    input_sizes_idx_1 = (int32_T)Stat_Space_N;
  } else {
    input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes || ((Linear_part->size[0] != 0) && (Linear_part->
        size[1] != 0))) {
    sizes_idx_1 = Linear_part->size[1];
  } else {
    sizes_idx_1 = 0;
  }

  i = e_result->size[0] * e_result->size[1];
  e_result->size[0] = d_result;
  e_result->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_creal_T(&b_st, e_result, i, &l_emlrtRTEI);
  for (i = 0; i < input_sizes_idx_1; i++) {
    for (i1 = 0; i1 < d_result; i1++) {
      e_result->data[i1 + e_result->size[0] * i].re = 0.0;
      e_result->data[i1 + e_result->size[0] * i].im = 0.0;
    }
  }

  for (i = 0; i < sizes_idx_1; i++) {
    for (i1 = 0; i1 < d_result; i1++) {
      e_result->data[i1 + e_result->size[0] * (i + input_sizes_idx_1)] =
        Linear_part->data[i1 + d_result * i];
    }
  }

  st.site = &ec_emlrtRSI;
  b_st.site = &y_emlrtRSI;
  if ((c_result->size[0] != 0) && (c_result->size[1] != 0)) {
    d_result = c_result->size[1];
  } else if ((e_result->size[0] != 0) && (e_result->size[1] != 0)) {
    d_result = e_result->size[1];
  } else {
    d_result = muIntScalarMax_sint32(c_result->size[1], 0);
    if (e_result->size[1] > d_result) {
      d_result = e_result->size[1];
    }
  }

  c_st.site = &ab_emlrtRSI;
  if ((c_result->size[1] != d_result) && ((c_result->size[0] != 0) &&
       (c_result->size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if ((e_result->size[1] != d_result) && ((e_result->size[0] != 0) &&
       (e_result->size[1] != 0))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch",
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  empty_non_axis_sizes = (d_result == 0);
  if (empty_non_axis_sizes || ((c_result->size[0] != 0) && (c_result->size[1] !=
        0))) {
    input_sizes_idx_1 = c_result->size[0];
  } else {
    input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes || ((e_result->size[0] != 0) && (e_result->size[1] !=
        0))) {
    sizes_idx_1 = e_result->size[0];
  } else {
    sizes_idx_1 = 0;
  }

  i = Linear_part->size[0] * Linear_part->size[1];
  Linear_part->size[0] = input_sizes_idx_1 + sizes_idx_1;
  Linear_part->size[1] = d_result;
  emxEnsureCapacity_creal_T(&b_st, Linear_part, i, &db_emlrtRTEI);
  for (i = 0; i < d_result; i++) {
    for (i1 = 0; i1 < input_sizes_idx_1; i1++) {
      Linear_part->data[i1 + Linear_part->size[0] * i] = c_result->data[i1 +
        input_sizes_idx_1 * i];
    }
  }

  emxFree_creal_T(&c_result);
  for (i = 0; i < d_result; i++) {
    for (i1 = 0; i1 < sizes_idx_1; i1++) {
      Linear_part->data[(i1 + input_sizes_idx_1) + Linear_part->size[0] * i] =
        e_result->data[i1 + sizes_idx_1 * i];
    }
  }

  emxFree_creal_T(&e_result);
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    y[input_sizes_idx_1] = muDoubleScalarHypot(f_psi[input_sizes_idx_1].re,
      f_psi[input_sizes_idx_1].im);
  }

  for (i = 0; i < 262144; i++) {
    SD->u1.f1.a_tmp[i].re = -FF[i].re;
    SD->u1.f1.a_tmp[i].im = -FF[i].im;
  }

  st.site = &gc_emlrtRSI;
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    d = y[input_sizes_idx_1];
    b_Stat_Space_k[input_sizes_idx_1] = Stat_Eq_gamma_Kerr[input_sizes_idx_1] *
      (2.0 * (d * d));
  }

  b_diag(b_Stat_Space_k, SD->u1.f1.dv);
  for (i = 0; i < 262144; i++) {
    SD->u1.f1.dcv[i].re = SD->u1.f1.dv[i];
    SD->u1.f1.dcv[i].im = 0.0;
  }

  for (i = 0; i < 512; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      z_im = 0.0;
      ar_tmp = 0.0;
      for (i2 = 0; i2 < 512; i2++) {
        input_sizes_idx_1 = i + (i2 << 9);
        sizes_idx_1 = i2 + (i1 << 9);
        d = SD->u1.f1.a_tmp[input_sizes_idx_1].re;
        d1 = SD->u1.f1.a_tmp[input_sizes_idx_1].im;
        d2 = SD->u1.f1.dcv[sizes_idx_1].re;
        z_re = SD->u1.f1.dcv[sizes_idx_1].im;
        z_im += d * d2 - d1 * z_re;
        ar_tmp += d * z_re + d1 * d2;
      }

      i2 = i + (i1 << 9);
      SD->u1.f1.b_a_tmp[i2].re = z_im;
      SD->u1.f1.b_a_tmp[i2].im = ar_tmp;
    }
  }

  b_st.site = &bb_emlrtRSI;
  mtimes(SD->u1.f1.b_a_tmp, FI, SD->u1.f1.y);
  st.site = &gc_emlrtRSI;
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    d = f_psi[input_sizes_idx_1].re;
    d1 = f_psi[input_sizes_idx_1].im;
    z_re = d * d1;
    d2 = Stat_Eq_gamma_Kerr[input_sizes_idx_1];
    b_Stat_Sol_Psi_k[input_sizes_idx_1].re = d2 * (d * d - d1 * d1);
    b_Stat_Sol_Psi_k[input_sizes_idx_1].im = d2 * (z_re + z_re);
  }

  diag(b_Stat_Sol_Psi_k, SD->u1.f1.dcv);
  b_st.site = &bb_emlrtRSI;
  mtimes(SD->u1.f1.a_tmp, SD->u1.f1.dcv, SD->u1.f1.b_a_tmp);
  st.site = &gc_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  mtimes(SD->u1.f1.b_a_tmp, FI, SD->u1.f1.b_y);
  st.site = &hc_emlrtRSI;
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    z_im = f_psi[input_sizes_idx_1].re;
    ar_tmp = -f_psi[input_sizes_idx_1].im;
    z_re = z_im * ar_tmp;
    d = Stat_Eq_gamma_Kerr[input_sizes_idx_1];
    b_Stat_Sol_Psi_k[input_sizes_idx_1].re = d * (z_im * z_im - ar_tmp * ar_tmp);
    b_Stat_Sol_Psi_k[input_sizes_idx_1].im = d * (z_re + z_re);
  }

  diag(b_Stat_Sol_Psi_k, SD->u1.f1.dcv);
  b_st.site = &bb_emlrtRSI;
  mtimes(FF, SD->u1.f1.dcv, SD->u1.f1.b_a_tmp);
  st.site = &hc_emlrtRSI;
  b_st.site = &bb_emlrtRSI;
  mtimes(SD->u1.f1.b_a_tmp, FI, SD->u1.f1.a_tmp);
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    y[input_sizes_idx_1] = muDoubleScalarHypot(f_psi[input_sizes_idx_1].re,
      f_psi[input_sizes_idx_1].im);
  }

  st.site = &hc_emlrtRSI;
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < 512; input_sizes_idx_1++) {
    d = y[input_sizes_idx_1];
    b_Stat_Space_k[input_sizes_idx_1] = Stat_Eq_gamma_Kerr[input_sizes_idx_1] *
      (2.0 * (d * d));
  }

  b_diag(b_Stat_Space_k, SD->u1.f1.dv);
  for (i = 0; i < 262144; i++) {
    SD->u1.f1.dcv[i].re = SD->u1.f1.dv[i];
    SD->u1.f1.dcv[i].im = 0.0;
  }

  for (i = 0; i < 512; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      z_im = 0.0;
      ar_tmp = 0.0;
      for (i2 = 0; i2 < 512; i2++) {
        input_sizes_idx_1 = i + (i2 << 9);
        sizes_idx_1 = i2 + (i1 << 9);
        d = FF[input_sizes_idx_1].re;
        d1 = FF[input_sizes_idx_1].im;
        d2 = SD->u1.f1.dcv[sizes_idx_1].re;
        z_re = SD->u1.f1.dcv[sizes_idx_1].im;
        z_im += d * d2 - d1 * z_re;
        ar_tmp += d * z_re + d1 * d2;
      }

      i2 = i + (i1 << 9);
      SD->u1.f1.FF[i2].re = z_im;
      SD->u1.f1.FF[i2].im = ar_tmp;
    }
  }

  b_st.site = &bb_emlrtRSI;
  mtimes(SD->u1.f1.FF, FI, SD->u1.f1.b_a_tmp);
  result[0] = 1024;
  result[1] = 1024;
  emlrtSizeEqCheckNDR2012b(*(int32_T (*)[2])Linear_part->size, result,
    &t_emlrtECI, sp);
  for (i = 0; i < 512; i++) {
    for (i1 = 0; i1 < 512; i1++) {
      input_sizes_idx_1 = i1 + (i << 9);
      sizes_idx_1 = i1 + (i << 10);
      g[sizes_idx_1] = SD->u1.f1.y[input_sizes_idx_1];
      loop_ub = i1 + ((i + 512) << 10);
      g[loop_ub] = SD->u1.f1.b_y[input_sizes_idx_1];
      g[sizes_idx_1 + 512] = SD->u1.f1.a_tmp[input_sizes_idx_1];
      g[loop_ub + 512] = SD->u1.f1.b_a_tmp[input_sizes_idx_1];
    }
  }

  for (i = 0; i < 1048576; i++) {
    z_re = Linear_part->data[i].re + g[i].re;
    z_im = Linear_part->data[i].im + g[i].im;
    g[i].re = 0.0 * z_re - (-z_im);
    g[i].im = -(0.0 * z_im + -z_re);
  }

  emxFree_creal_T(&Linear_part);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void LLE_Bloch_StabilitySpeedUp(c_LLE_Bloch_StabilitySpeedUpSta *SD, const
  emlrtStack *sp, const struct0_T *Stat, const creal_T FF[262144], const creal_T
  FI[262144], creal_T Vectors[1048576], creal_T Valuestemp[1048576], creal_T
  VectorsStar[1048576], creal_T ValuesStartemp[1048576])
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &emlrtRSI;
  c_Bloch_Full_Stability_MatrixEi(SD, &st, Stat->In.k, Stat->Space.N,
    Stat->Space.k, Stat->Eq.delta, Stat->Eq.kappa, Stat->Eq.D,
    Stat->Eq.gamma_Kerr, Stat->Sol.V, Stat->Sol.Psi_k, FF, FI, SD->f3.dcv);
  st.site = &emlrtRSI;
  eig(SD, &st, SD->f3.dcv, Vectors, Valuestemp);
  st.site = &b_emlrtRSI;
  d_Bloch_Full_Stability_MatrixEi(SD, &st, Stat->In.k, Stat->Space.N,
    Stat->Space.k, Stat->Eq.delta, Stat->Eq.kappa, Stat->Eq.D,
    Stat->Eq.gamma_Kerr, Stat->Sol.V, Stat->Sol.Psi_k, FF, FI, SD->f3.dcv);
  st.site = &b_emlrtRSI;
  eig(SD, &st, SD->f3.dcv, VectorsStar, ValuesStartemp);
}

/* End of code generation (LLE_Bloch_StabilitySpeedUp.c) */
