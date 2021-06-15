/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi23OPO_Runge_Kuarong.c
 *
 * Code generation for function 'Chi23OPO_Runge_Kuarong'
 *
 */

/* Include files */
#include "Chi23OPO_Runge_Kuarong.h"
#include "Chi23OPO_Runge_Kuarong_data.h"
#include "Chi23OPO_Runge_Kuarong_emxutil.h"
#include "Chi23OPO_Runge_Kuarong_types.h"
#include "abs.h"
#include "fft.h"
#include "ifft.h"
#include "mod.h"
#include "nullAssignment.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 48,    /* lineNo */
  "Chi23OPO_Runge_Kuarong",            /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 47,  /* lineNo */
  "Chi23OPO_Runge_Kuarong",            /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 46,  /* lineNo */
  "Chi23OPO_Runge_Kuarong",            /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 44,  /* lineNo */
  "Chi23OPO_Runge_Kuarong",            /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 33,  /* lineNo */
  "Chi23OPO_Runge_Kuarong",            /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 3,   /* lineNo */
  "Chi23OPO_Runge_Kuarong",            /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 77,  /* lineNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  50,                                  /* colNo */
  "Sol.Psio",                          /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  48,                                  /* colNo */
  "Sol.Psio",                          /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  42,                                  /* colNo */
  "Sol.Psio",                          /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  40,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  22,                                  /* colNo */
  "Sol.Psie",                          /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  39,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  22,                                  /* colNo */
  "Sol.Psio",                          /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo emlrtDCI = { 39,    /* lineNo */
  22,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  40,                                  /* lineNo */
  53,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 40,  /* lineNo */
  53,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  40,                                  /* lineNo */
  38,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 40,  /* lineNo */
  38,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  39,                                  /* lineNo */
  40,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 39,  /* lineNo */
  40,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 31,  /* lineNo */
  14,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  11,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  63,                                  /* lineNo */
  9,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 65,/* lineNo */
  18,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 67,/* lineNo */
  22,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  105,                                 /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  77,                                  /* lineNo */
  66,                                  /* colNo */
  "exp_plus_omega",                    /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  15,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  77,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 83,/* lineNo */
  18,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  90,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 3,   /* lineNo */
  43,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 3,   /* lineNo */
  43,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 25,  /* lineNo */
  30,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 25,  /* lineNo */
  30,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 25,  /* lineNo */
  42,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 25,  /* lineNo */
  42,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 26,  /* lineNo */
  30,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 26,  /* lineNo */
  42,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 28,  /* lineNo */
  32,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 3,   /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 25,  /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 26,  /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 28,  /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  85,                                  /* lineNo */
  17,                                  /* colNo */
  "Runge.c",                           /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  69,                                  /* lineNo */
  20,                                  /* colNo */
  "Runge.b",                           /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  93,                                  /* lineNo */
  12,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 93,  /* lineNo */
  12,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  87,                                  /* lineNo */
  50,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 87,  /* lineNo */
  50,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  93,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 87,  /* lineNo */
  93,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  71,                                  /* lineNo */
  62,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 71,  /* lineNo */
  62,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  108,                                 /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 71,  /* lineNo */
  108,                                 /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  87,                                  /* lineNo */
  17,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 87,  /* lineNo */
  17,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  71,                                  /* lineNo */
  21,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = { 71, /* lineNo */
  21,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  13,                                  /* colNo */
  "Sol.t",                             /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  93,                                  /* lineNo */
  38,                                  /* colNo */
  "shift_back",                        /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 93, /* lineNo */
  38,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo k_emlrtRTEI = { 3, /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 33,/* lineNo */
  61,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 44,/* lineNo */
  33,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 46,/* lineNo */
  30,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 47,/* lineNo */
  30,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 48,/* lineNo */
  27,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 44,/* lineNo */
  29,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

/* Function Definitions */
void Chi23OPO_Runge_Kuarong(const emlrtStack *sp, const struct0_T *Temp, const
  struct5_T *Runge, struct6_T *Sol)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_creal_T *b_Sol;
  emxArray_creal_T *c_d;
  emxArray_cuint8_T *d;
  emxArray_int32_T *r2;
  emxArray_real_T *b_r;
  emxArray_real_T *r1;
  creal_T exp_minus_omega_contents[1536];
  creal_T exp_plus_omega_contents[1536];
  creal_T E_temp[512];
  creal_T F_e[512];
  creal_T k_e[512];
  creal_T y[512];
  creal_T Psie[256];
  creal_T Psio[256];
  creal_T b_F_e[256];
  creal_T z1[256];
  real_T b_Runge;
  real_T b_d;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T dt;
  real_T im;
  real_T ind_s;
  real_T nt;
  real_T r;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T tmp_size[2];
  int32_T b_i;
  int32_T b_i2;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T loop_ub;
  int32_T ni;
  boolean_T exitg1;
  boolean_T guard1 = false;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_cuint8_T(sp, &d, 2, &k_emlrtRTEI, true);
  st.site = &f_emlrtRSI;
  st.site = &f_emlrtRSI;
  st.site = &f_emlrtRSI;
  st.site = &f_emlrtRSI;
  st.site = &f_emlrtRSI;
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &f_emlrtDCI, sp);
  }

  b_d = (int32_T)muDoubleScalarFloor(Runge->s);
  if (Runge->s != b_d) {
    emlrtIntegerCheckR2012b(Runge->s, &e_emlrtDCI, sp);
  }

  i = d->size[0] * d->size[1];
  d->size[0] = (int32_T)Runge->s;
  emxEnsureCapacity_cuint8_T(sp, d, i, &k_emlrtRTEI);
  d1 = 2.0 * Temp->Space.N;
  if (!(d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d1, &h_emlrtDCI, sp);
  }

  d2 = (int32_T)muDoubleScalarFloor(d1);
  if (d1 != d2) {
    emlrtIntegerCheckR2012b(d1, &g_emlrtDCI, sp);
  }

  i = d->size[0] * d->size[1];
  d->size[1] = (int32_T)d1;
  emxEnsureCapacity_cuint8_T(sp, d, i, &k_emlrtRTEI);
  if (Runge->s != b_d) {
    emlrtIntegerCheckR2012b(Runge->s, &p_emlrtDCI, sp);
  }

  if (d1 != d2) {
    emlrtIntegerCheckR2012b(d1, &p_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Runge->s * (int32_T)d1;
  for (i = 0; i < loop_ub; i++) {
    d->data[i].re = 0U;
    d->data[i].im = 0U;
  }

  dt = Temp->Par.dt;
  nt = Temp->Par.T / Temp->Par.dt;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (b_i = 0; b_i < 3; b_i++) {
    b_Runge = Runge->a[b_i];
    for (loop_ub = 0; loop_ub < 512; loop_ub++) {
      b_d = Temp->Eq.L[loop_ub].re;
      d3 = Temp->Eq.L[loop_ub].im;
      ind_s = dt * (b_Runge * (0.0 * b_d - (-d3)));
      im = dt * (b_Runge * (0.0 * d3 + -b_d));
      if (im == 0.0) {
        ind_s = muDoubleScalarExp(ind_s);
        im = 0.0;
      } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(ind_s) && (ind_s
                  < 0.0)) {
        ind_s = 0.0;
        im = 0.0;
      } else {
        r = muDoubleScalarExp(ind_s / 2.0);
        ind_s = r * (r * muDoubleScalarCos(im));
        im = r * (r * muDoubleScalarSin(im));
      }

      i = b_i + 3 * loop_ub;
      exp_minus_omega_contents[i].re = ind_s;
      exp_minus_omega_contents[i].im = im;
      ind_s = dt * (b_Runge * (0.0 * b_d - d3));
      im = dt * (b_Runge * (0.0 * d3 + b_d));
      if (im == 0.0) {
        ind_s = muDoubleScalarExp(ind_s);
        im = 0.0;
      } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(ind_s) && (ind_s
                  < 0.0)) {
        ind_s = 0.0;
        im = 0.0;
      } else {
        r = muDoubleScalarExp(ind_s / 2.0);
        ind_s = r * (r * muDoubleScalarCos(im));
        im = r * (r * muDoubleScalarSin(im));
      }

      exp_plus_omega_contents[i].re = ind_s;
      exp_plus_omega_contents[i].im = im;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (loop_ub = 0; loop_ub < 512; loop_ub++) {
    ind_s = Temp->Par.dt * (0.0 * Temp->Eq.L[loop_ub].re - (-Temp->Eq.L[loop_ub]
      .im));
    im = Temp->Par.dt * (0.0 * Temp->Eq.L[loop_ub].im + -Temp->Eq.L[loop_ub].re);
    y[loop_ub].re = ind_s;
    y[loop_ub].im = im;
    if (im == 0.0) {
      y[loop_ub].re = muDoubleScalarExp(ind_s);
      y[loop_ub].im = 0.0;
    } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(ind_s) && (ind_s <
                0.0)) {
      y[loop_ub].re = 0.0;
      y[loop_ub].im = 0.0;
    } else {
      r = muDoubleScalarExp(ind_s / 2.0);
      y[loop_ub].re = r * (r * muDoubleScalarCos(im));
      y[loop_ub].im = r * (r * muDoubleScalarSin(im));
    }

    F_e[loop_ub].re = Temp->In.Psi_Start[loop_ub];
    F_e[loop_ub].im = 0.0;
  }

  if (!(Temp->Par.dd >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Par.dd, &j_emlrtDCI, sp);
  }

  b_d = (int32_T)muDoubleScalarFloor(Temp->Par.dd);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &i_emlrtDCI, sp);
  }

  i = Sol->Psio->size[0] * Sol->Psio->size[1];
  Sol->Psio->size[0] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->Psio, i, &l_emlrtRTEI);
  if (!(Temp->Space.N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Space.N, &l_emlrtDCI, sp);
  }

  d3 = (int32_T)muDoubleScalarFloor(Temp->Space.N);
  if (Temp->Space.N != d3) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &k_emlrtDCI, sp);
  }

  i = Sol->Psio->size[0] * Sol->Psio->size[1];
  Sol->Psio->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_creal_T(sp, Sol->Psio, i, &l_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &q_emlrtDCI, sp);
  }

  if (Temp->Space.N != d3) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &q_emlrtDCI, sp);
  }

  b_i = (int32_T)Temp->Par.dd * (int32_T)Temp->Space.N;
  for (i = 0; i < b_i; i++) {
    Sol->Psio->data[i].re = 0.0;
    Sol->Psio->data[i].im = 0.0;
  }

  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &m_emlrtDCI, sp);
  }

  i = Sol->Psie->size[0] * Sol->Psie->size[1];
  Sol->Psie->size[0] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->Psie, i, &m_emlrtRTEI);
  if (Temp->Space.N != d3) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &n_emlrtDCI, sp);
  }

  i = Sol->Psie->size[0] * Sol->Psie->size[1];
  Sol->Psie->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_creal_T(sp, Sol->Psie, i, &m_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &r_emlrtDCI, sp);
  }

  if (Temp->Space.N != d3) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &r_emlrtDCI, sp);
  }

  for (i = 0; i < b_i; i++) {
    Sol->Psie->data[i].re = 0.0;
    Sol->Psie->data[i].im = 0.0;
  }

  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &n_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &o_emlrtDCI, sp);
  }

  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[1] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &n_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &s_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd;
  for (i = 0; i < loop_ub; i++) {
    Sol->t->data[i].re = 0.0;
    Sol->t->data[i].im = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nt, mxDOUBLE_CLASS, (int32_T)nt,
    &emlrtRTEI, sp);
  ni = 0;
  emxInit_creal_T(sp, &c_d, 2, &o_emlrtRTEI, true);
  emxInit_real_T(sp, &b_r, 2, &t_emlrtRTEI, true);
  emxInit_real_T(sp, &r1, 2, &t_emlrtRTEI, true);
  emxInit_int32_T(sp, &r2, 2, &q_emlrtRTEI, true);
  emxInit_creal_T(sp, &b_Sol, 2, &p_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (ni <= (int32_T)nt - 1)) {
    st.site = &e_emlrtRSI;
    i = c_d->size[0] * c_d->size[1];
    c_d->size[0] = d->size[0];
    c_d->size[1] = d->size[1];
    emxEnsureCapacity_creal_T(&st, c_d, i, &o_emlrtRTEI);
    loop_ub = d->size[0] * d->size[1];
    for (i = 0; i < loop_ub; i++) {
      c_d->data[i].re = d->data[i].re;
      c_d->data[i].im = d->data[i].im;
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    memcpy(&E_temp[0], &F_e[0], 512U * sizeof(creal_T));
    if (1 > d->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, d->size[0], &i_emlrtBCI, &st);
    }

    iv[0] = 1;
    iv[1] = d->size[1];
    iv1[0] = 1;
    iv1[1] = 512;
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &c_emlrtECI, &st);
    for (i = 0; i < 256; i++) {
      b_d = F_e[i].re;
      d4 = F_e[i].im;
      d5 = exp_minus_omega_contents[3 * i].re;
      d6 = exp_minus_omega_contents[3 * i].im;
      b_F_e[i].re = b_d * d5 - d4 * d6;
      b_F_e[i].im = b_d * d6 + d4 * d5;
    }

    ifft(b_F_e, Psio);
    for (i = 0; i < 256; i++) {
      i1 = 3 * (i + 256);
      b_d = F_e[i + 256].re;
      d4 = F_e[i + 256].im;
      d5 = exp_minus_omega_contents[i1].re;
      d6 = exp_minus_omega_contents[i1].im;
      b_F_e[i].re = b_d * d5 - d4 * d6;
      b_F_e[i].im = b_d * d6 + d4 * d5;
    }

    ifft(b_F_e, Psie);
    memset(&k_e[0], 0, 512U * sizeof(creal_T));
    for (loop_ub = 0; loop_ub < 256; loop_ub++) {
      b_d = Psie[loop_ub].re;
      d4 = Psie[loop_ub].im;
      d5 = muDoubleScalarHypot(b_d, d4);
      d6 = d5 * d5;
      ind_s = Psio[loop_ub].re;
      im = Psio[loop_ub].im;
      d5 = muDoubleScalarHypot(ind_s, im);
      b_Runge = Temp->Eq.gam2o * ind_s;
      r = Temp->Eq.gam2o * -im;
      d5 = Temp->Eq.gam3o * (d5 * d5 + 2.0 * d6);
      b_F_e[loop_ub].re = (b_Runge * b_d - r * d4) + d5 * ind_s;
      b_F_e[loop_ub].im = (b_Runge * d4 + r * b_d) + d5 * im;
    }

    fft(b_F_e, z1);
    for (loop_ub = 0; loop_ub < 256; loop_ub++) {
      b_d = exp_plus_omega_contents[3 * loop_ub].re;
      d4 = exp_plus_omega_contents[3 * loop_ub].im;
      ind_s = 0.0 * b_d - d4;
      im = 0.0 * d4 + b_d;
      b_d = z1[loop_ub].re;
      d4 = z1[loop_ub].im;
      k_e[loop_ub].re = ind_s * b_d - im * d4;
      k_e[loop_ub].im = ind_s * d4 + im * b_d;
      b_d = Psio[loop_ub].re;
      d4 = Psio[loop_ub].im;
      d5 = muDoubleScalarHypot(b_d, d4);
      d6 = d5 * d5;
      ind_s = b_d * b_d - d4 * d4;
      b_Runge = b_d * d4;
      im = b_Runge + b_Runge;
      z1[loop_ub].re = ind_s;
      z1[loop_ub].im = im;
      b_d = Psie[loop_ub].re;
      d4 = Psie[loop_ub].im;
      d5 = muDoubleScalarHypot(b_d, d4);
      d5 = Temp->Eq.gam3e * (2.0 * d6 + d5 * d5);
      b_d = Temp->Eq.gam2e * ind_s + d5 * b_d;
      Psie[loop_ub].re = b_d;
      d4 = Temp->Eq.gam2e * im + d5 * d4;
      Psie[loop_ub].im = d4;
    }

    fft(Psie, z1);
    for (i = 0; i < 256; i++) {
      b_i = 3 * (i + 256);
      b_d = exp_plus_omega_contents[b_i].re;
      d4 = exp_plus_omega_contents[b_i].im;
      ind_s = 0.0 * b_d - d4;
      im = 0.0 * d4 + b_d;
      b_d = z1[i].re;
      d4 = z1[i].im;
      k_e[i + 256].re = ind_s * b_d - im * d4;
      k_e[i + 256].im = ind_s * d4 + im * b_d;
    }

    b_Runge = 256.0 * exp_plus_omega_contents[768].re;
    im = 256.0 * exp_plus_omega_contents[768].im;
    if (im == 0.0) {
      ind_s = b_Runge / 2.0;
      im = 0.0;
    } else if (b_Runge == 0.0) {
      ind_s = 0.0;
      im /= 2.0;
    } else {
      ind_s = b_Runge / 2.0;
      im /= 2.0;
    }

    k_e[256].re += Temp->Eq.ke * ind_s * Temp->Eq.H_s;
    k_e[256].im += Temp->Eq.ke * im * Temp->Eq.H_s;
    loop_ub = d->size[1];
    for (i = 0; i < loop_ub; i++) {
      c_d->data[c_d->size[0] * i] = k_e[i];
    }

    i = (int32_T)(Runge->s + -1.0);
    emlrtForLoopVectorCheckR2012b(2.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      (Runge->s + -1.0), &b_emlrtRTEI, &st);
    if (0 <= (int32_T)(Runge->s + -1.0) - 1) {
      iv1[0] = 1;
      iv1[1] = 512;
    }

    if (0 <= i - 1) {
      i2 = (int32_T)(Runge->s - 1.0);
    }

    for (b_i2 = 0; b_i2 < i; b_i2++) {
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
        (int32_T)(Runge->s - 1.0), &c_emlrtRTEI, &st);
      for (loop_ub = 0; loop_ub < i2; loop_ub++) {
        if (((int32_T)(b_i2 + 2U) < 1) || ((int32_T)(b_i2 + 2U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i2 + 2U), 1, 3, &o_emlrtBCI,
            &st);
        }

        if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, 3,
            &o_emlrtBCI, &st);
        }

        b_d = Runge->b[(b_i2 + 3 * loop_ub) + 1];
        if (b_d != 0.0) {
          b_Runge = dt * b_d;
          if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) >
               c_d->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, c_d->size
              [0], &j_emlrtBCI, &st);
          }

          for (i1 = 0; i1 < 512; i1++) {
            b_d = Temp->Eq.mode_range[i1];
            i3 = (int32_T)muDoubleScalarFloor(b_d);
            if (b_d != i3) {
              emlrtIntegerCheckR2012b(b_d, &w_emlrtDCI, &st);
            }

            b_i = (int32_T)b_d;
            if ((b_i < 1) || (b_i > 512)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, 512, &s_emlrtBCI, &st);
            }

            if (b_i != i3) {
              emlrtIntegerCheckR2012b(b_d, &x_emlrtDCI, &st);
            }

            if (b_i > c_d->size[1]) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &t_emlrtBCI,
                &st);
            }

            k_e[i1].re = E_temp[b_i - 1].re + b_Runge * c_d->data[loop_ub +
              c_d->size[0] * (b_i - 1)].re;
            if (b_i != i3) {
              emlrtIntegerCheckR2012b(b_d, &w_emlrtDCI, &st);
            }

            if (b_i > c_d->size[1]) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &t_emlrtBCI,
                &st);
            }

            k_e[i1].im = E_temp[b_i - 1].im + b_Runge * c_d->data[loop_ub +
              c_d->size[0] * (b_i - 1)].im;
          }

          for (i1 = 0; i1 < 512; i1++) {
            b_d = Temp->Eq.mode_range[i1];
            i3 = (int32_T)muDoubleScalarFloor(b_d);
            if (b_d != i3) {
              emlrtIntegerCheckR2012b(b_d, &ab_emlrtDCI, &st);
            }

            b_i = (int32_T)b_d;
            if ((b_i < 1) || (b_i > 512)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, 512, &v_emlrtBCI, &st);
            }

            E_temp[b_i - 1].re = k_e[i1].re;
            if (b_i != i3) {
              emlrtIntegerCheckR2012b(b_d, &ab_emlrtDCI, &st);
            }

            E_temp[b_i - 1].im = k_e[i1].im;
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      if ((b_i2 + 2 < 1) || (b_i2 + 2 > c_d->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i2 + 2, 1, c_d->size[0], &l_emlrtBCI,
          &st);
      }

      iv[0] = 1;
      iv[1] = c_d->size[1];
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &d_emlrtECI, &st);
      b_st.site = &i_emlrtRSI;
      if ((b_i2 + 2 < 1) || (b_i2 + 2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(b_i2 + 2, 1, 3, &k_emlrtBCI, &b_st);
      }

      for (i1 = 0; i1 < 256; i1++) {
        i3 = (b_i2 + 3 * i1) + 1;
        b_d = E_temp[i1].re;
        d4 = E_temp[i1].im;
        b_F_e[i1].re = b_d * exp_minus_omega_contents[i3].re - d4 *
          exp_minus_omega_contents[i3].im;
        b_F_e[i1].im = b_d * exp_minus_omega_contents[i3].im + d4 *
          exp_minus_omega_contents[i3].re;
      }

      ifft(b_F_e, Psio);
      for (i1 = 0; i1 < 256; i1++) {
        i3 = (b_i2 + 3 * (i1 + 256)) + 1;
        b_d = E_temp[i1 + 256].re;
        d4 = E_temp[i1 + 256].im;
        b_F_e[i1].re = b_d * exp_minus_omega_contents[i3].re - d4 *
          exp_minus_omega_contents[i3].im;
        b_F_e[i1].im = b_d * exp_minus_omega_contents[i3].im + d4 *
          exp_minus_omega_contents[i3].re;
      }

      ifft(b_F_e, Psie);
      memset(&k_e[0], 0, 512U * sizeof(creal_T));
      for (loop_ub = 0; loop_ub < 256; loop_ub++) {
        b_d = Psie[loop_ub].re;
        d4 = Psie[loop_ub].im;
        d5 = muDoubleScalarHypot(b_d, d4);
        d6 = d5 * d5;
        ind_s = Psio[loop_ub].re;
        im = Psio[loop_ub].im;
        d5 = muDoubleScalarHypot(ind_s, im);
        b_Runge = Temp->Eq.gam2o * ind_s;
        r = Temp->Eq.gam2o * -im;
        d5 = Temp->Eq.gam3o * (d5 * d5 + 2.0 * d6);
        b_F_e[loop_ub].re = (b_Runge * b_d - r * d4) + d5 * ind_s;
        b_F_e[loop_ub].im = (b_Runge * d4 + r * b_d) + d5 * im;
      }

      fft(b_F_e, z1);
      for (loop_ub = 0; loop_ub < 256; loop_ub++) {
        b_i = (b_i2 + 3 * loop_ub) + 1;
        ind_s = 0.0 * exp_plus_omega_contents[b_i].re -
          exp_plus_omega_contents[b_i].im;
        im = 0.0 * exp_plus_omega_contents[b_i].im + exp_plus_omega_contents[b_i]
          .re;
        b_d = z1[loop_ub].re;
        d4 = z1[loop_ub].im;
        k_e[loop_ub].re = ind_s * b_d - im * d4;
        k_e[loop_ub].im = ind_s * d4 + im * b_d;
        b_d = Psio[loop_ub].re;
        d4 = Psio[loop_ub].im;
        d5 = muDoubleScalarHypot(b_d, d4);
        d6 = d5 * d5;
        ind_s = b_d * b_d - d4 * d4;
        b_Runge = b_d * d4;
        im = b_Runge + b_Runge;
        z1[loop_ub].re = ind_s;
        z1[loop_ub].im = im;
        b_d = Psie[loop_ub].re;
        d4 = Psie[loop_ub].im;
        d5 = muDoubleScalarHypot(b_d, d4);
        d5 = Temp->Eq.gam3e * (2.0 * d6 + d5 * d5);
        b_d = Temp->Eq.gam2e * ind_s + d5 * b_d;
        Psie[loop_ub].re = b_d;
        d4 = Temp->Eq.gam2e * im + d5 * d4;
        Psie[loop_ub].im = d4;
      }

      fft(Psie, z1);
      for (i1 = 0; i1 < 256; i1++) {
        b_i = (b_i2 + 3 * (i1 + 256)) + 1;
        ind_s = 0.0 * exp_plus_omega_contents[b_i].re -
          exp_plus_omega_contents[b_i].im;
        im = 0.0 * exp_plus_omega_contents[b_i].im + exp_plus_omega_contents[b_i]
          .re;
        b_d = z1[i1].re;
        d4 = z1[i1].im;
        k_e[i1 + 256].re = ind_s * b_d - im * d4;
        k_e[i1 + 256].im = ind_s * d4 + im * b_d;
      }

      b_Runge = 256.0 * exp_plus_omega_contents[b_i2 + 769].re;
      im = 256.0 * exp_plus_omega_contents[b_i2 + 769].im;
      if (im == 0.0) {
        ind_s = b_Runge / 2.0;
        im = 0.0;
      } else if (b_Runge == 0.0) {
        ind_s = 0.0;
        im /= 2.0;
      } else {
        ind_s = b_Runge / 2.0;
        im /= 2.0;
      }

      k_e[256].re += Temp->Eq.ke * ind_s * Temp->Eq.H_s;
      k_e[256].im += Temp->Eq.ke * im * Temp->Eq.H_s;
      loop_ub = c_d->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        c_d->data[(b_i2 + c_d->size[0] * i1) + 1] = k_e[i1];
      }

      memcpy(&E_temp[0], &F_e[0], 512U * sizeof(creal_T));
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    i = (int32_T)Runge->s;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      Runge->s, &d_emlrtRTEI, &st);
    for (loop_ub = 0; loop_ub < i; loop_ub++) {
      if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) > 3)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, 3, &n_emlrtBCI,
          &st);
      }

      b_d = Runge->c[loop_ub];
      if (b_d != 0.0) {
        b_Runge = dt * b_d;
        if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) >
             c_d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, c_d->size[0],
            &m_emlrtBCI, &st);
        }

        for (i1 = 0; i1 < 512; i1++) {
          b_d = Temp->Eq.mode_range[i1];
          i3 = (int32_T)muDoubleScalarFloor(b_d);
          if (b_d != i3) {
            emlrtIntegerCheckR2012b(b_d, &u_emlrtDCI, &st);
          }

          b_i = (int32_T)b_d;
          if ((b_i < 1) || (b_i > 512)) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, 512, &q_emlrtBCI, &st);
          }

          if (b_i != i3) {
            emlrtIntegerCheckR2012b(b_d, &v_emlrtDCI, &st);
          }

          if (b_i > c_d->size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &r_emlrtBCI, &st);
          }

          k_e[i1].re = F_e[b_i - 1].re + b_Runge * c_d->data[loop_ub + c_d->
            size[0] * (b_i - 1)].re;
          if (b_i != i3) {
            emlrtIntegerCheckR2012b(b_d, &u_emlrtDCI, &st);
          }

          if (b_i > c_d->size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &r_emlrtBCI, &st);
          }

          k_e[i1].im = F_e[b_i - 1].im + b_Runge * c_d->data[loop_ub + c_d->
            size[0] * (b_i - 1)].im;
        }

        for (i1 = 0; i1 < 512; i1++) {
          b_d = Temp->Eq.mode_range[i1];
          i3 = (int32_T)muDoubleScalarFloor(b_d);
          if (b_d != i3) {
            emlrtIntegerCheckR2012b(b_d, &y_emlrtDCI, &st);
          }

          b_i = (int32_T)b_d;
          if ((b_i < 1) || (b_i > 512)) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, 512, &u_emlrtBCI, &st);
          }

          F_e[b_i - 1].re = k_e[i1].re;
          if (b_i != i3) {
            emlrtIntegerCheckR2012b(b_d, &y_emlrtDCI, &st);
          }

          F_e[b_i - 1].im = k_e[i1].im;
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    for (i = 0; i < 512; i++) {
      b_d = Temp->Eq.mode_range[i];
      i1 = (int32_T)muDoubleScalarFloor(b_d);
      if (b_d != i1) {
        emlrtIntegerCheckR2012b(b_d, &bb_emlrtDCI, &st);
      }

      i3 = (int32_T)b_d;
      if ((i3 < 1) || (i3 > 512)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 512, &x_emlrtBCI, &st);
      }

      if (i3 != i1) {
        emlrtIntegerCheckR2012b(b_d, &bb_emlrtDCI, &st);
      }

      E_temp[i].re = y[i3 - 1].re * F_e[i3 - 1].re - y[i3 - 1].im * F_e[i3 - 1].
        im;
      if (i3 != i1) {
        emlrtIntegerCheckR2012b(b_d, &bb_emlrtDCI, &st);
      }

      E_temp[i].im = y[i3 - 1].re * F_e[i3 - 1].im + y[i3 - 1].im * F_e[i3 - 1].
        re;
    }

    for (i = 0; i < 512; i++) {
      b_d = Temp->Eq.mode_range[i];
      i1 = (int32_T)muDoubleScalarFloor(b_d);
      if (b_d != i1) {
        emlrtIntegerCheckR2012b(b_d, &t_emlrtDCI, &st);
      }

      i3 = (int32_T)b_d;
      if ((i3 < 1) || (i3 > 512)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 512, &p_emlrtBCI, &st);
      }

      F_e[i3 - 1].re = E_temp[i].re;
      if (i3 != i1) {
        emlrtIntegerCheckR2012b(b_d, &t_emlrtDCI, &st);
      }

      F_e[i3 - 1].im = E_temp[i].im;
    }

    /* ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back */
    guard1 = false;
    if (b_mod((real_T)ni + 1.0, Temp->Par.s_t / Temp->Par.dt) == 0.0) {
      r = ((real_T)ni + 1.0) * Temp->Par.dt;
      ind_s = muDoubleScalarRound(r / Temp->Par.s_t);
      if (1.0 > Temp->Space.N) {
        loop_ub = 0;
      } else {
        if (Temp->Space.N != d3) {
          emlrtIntegerCheckR2012b(Temp->Space.N, &d_emlrtDCI, sp);
        }

        if (((int32_T)Temp->Space.N < 1) || ((int32_T)Temp->Space.N > 512)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)Temp->Space.N, 1, 512,
            &h_emlrtBCI, sp);
        }

        loop_ub = (int32_T)Temp->Space.N;
      }

      if (ind_s != (int32_T)ind_s) {
        emlrtIntegerCheckR2012b(ind_s, &emlrtDCI, sp);
      }

      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->Psio->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->Psio->size[0],
          &e_emlrtBCI, sp);
      }

      tmp_size[0] = 1;
      tmp_size[1] = loop_ub;
      for (i = 0; i < loop_ub; i++) {
        b_Runge = F_e[i].re;
        im = F_e[i].im;
        if (im == 0.0) {
          E_temp[i].re = b_Runge / Temp->Space.N;
          E_temp[i].im = 0.0;
        } else if (b_Runge == 0.0) {
          E_temp[i].re = 0.0;
          E_temp[i].im = im / Temp->Space.N;
        } else {
          E_temp[i].re = b_Runge / Temp->Space.N;
          E_temp[i].im = im / Temp->Space.N;
        }
      }

      iv[0] = 1;
      iv[1] = Sol->Psio->size[1];
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &b_emlrtECI, sp);
      for (i = 0; i < loop_ub; i++) {
        Sol->Psio->data[((int32_T)ind_s + Sol->Psio->size[0] * i) - 1] =
          E_temp[i];
      }

      if (Temp->Space.N + 1.0 > d1) {
        i = 0;
        i1 = 0;
      } else {
        if (Temp->Space.N + 1.0 != (int32_T)muDoubleScalarFloor(Temp->Space.N +
             1.0)) {
          emlrtIntegerCheckR2012b(Temp->Space.N + 1.0, &c_emlrtDCI, sp);
        }

        if (((int32_T)(Temp->Space.N + 1.0) < 1) || ((int32_T)(Temp->Space.N +
              1.0) > 512)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(Temp->Space.N + 1.0), 1, 512,
            &g_emlrtBCI, sp);
        }

        i = (int32_T)(Temp->Space.N + 1.0) - 1;
        if (d1 != d2) {
          emlrtIntegerCheckR2012b(d1, &b_emlrtDCI, sp);
        }

        if (((int32_T)d1 < 1) || ((int32_T)d1 > 512)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 512, &f_emlrtBCI, sp);
        }

        i1 = (int32_T)d1;
      }

      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->Psie->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->Psie->size[0],
          &d_emlrtBCI, sp);
      }

      tmp_size[0] = 1;
      loop_ub = i1 - i;
      tmp_size[1] = loop_ub;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_i = i + i1;
        b_Runge = F_e[b_i].re;
        im = F_e[b_i].im;
        if (im == 0.0) {
          E_temp[i1].re = b_Runge / Temp->Space.N;
          E_temp[i1].im = 0.0;
        } else if (b_Runge == 0.0) {
          E_temp[i1].re = 0.0;
          E_temp[i1].im = im / Temp->Space.N;
        } else {
          E_temp[i1].re = b_Runge / Temp->Space.N;
          E_temp[i1].im = im / Temp->Space.N;
        }
      }

      iv[0] = 1;
      iv[1] = Sol->Psie->size[1];
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &emlrtECI, sp);
      for (i = 0; i < loop_ub; i++) {
        Sol->Psie->data[((int32_T)ind_s + Sol->Psie->size[0] * i) - 1] =
          E_temp[i];
      }

      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->t->size[1],
          &w_emlrtBCI, sp);
      }

      Sol->t->data[(int32_T)ind_s - 1].re = r;
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->t->size[1],
          &w_emlrtBCI, sp);
      }

      Sol->t->data[(int32_T)ind_s - 1].im = 0.0;
      if (2 > Sol->Psio->size[1]) {
        i = 0;
        i1 = 0;
      } else {
        if (2 > Sol->Psio->size[1]) {
          emlrtDynamicBoundsCheckR2012b(2, 1, Sol->Psio->size[1], &b_emlrtBCI,
            sp);
        }

        i = 1;
        if (Sol->Psio->size[1] < 1) {
          emlrtDynamicBoundsCheckR2012b(Sol->Psio->size[1], 1, Sol->Psio->size[1],
            &emlrtBCI, sp);
        }

        i1 = Sol->Psio->size[1];
      }

      st.site = &d_emlrtRSI;
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->Psio->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->Psio->size[0],
          &c_emlrtBCI, &st);
      }

      i3 = b_Sol->size[0] * b_Sol->size[1];
      b_Sol->size[0] = 1;
      loop_ub = i1 - i;
      b_Sol->size[1] = loop_ub;
      emxEnsureCapacity_creal_T(&st, b_Sol, i3, &p_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_Sol->data[i1] = Sol->Psio->data[((int32_T)ind_s + Sol->Psio->size[0] *
          (i + i1)) - 1];
      }

      b_st.site = &d_emlrtRSI;
      b_abs(&b_st, b_Sol, b_r);
      b_st.site = &d_emlrtRSI;
      power(&b_st, b_r, r1);
      b_st.site = &d_emlrtRSI;
      b_Runge = sum(&b_st, r1);
      b_Runge = muDoubleScalarLog10(b_Runge);
      if ((10.0 * b_Runge <= -100.0) && (muDoubleScalarRem(ind_s, 2.0) == 0.0))
      {
        i = r2->size[0] * r2->size[1];
        r2->size[0] = 1;
        r2->size[1] = Sol->Psio->size[0] - (int32_T)ind_s;
        emxEnsureCapacity_int32_T(sp, r2, i, &q_emlrtRTEI);
        loop_ub = Sol->Psio->size[0] - (int32_T)ind_s;
        for (i = 0; i < loop_ub; i++) {
          r2->data[i] = ((int32_T)ind_s + i) + 1;
        }

        st.site = &c_emlrtRSI;
        nullAssignment(&st, Sol->Psio, r2);
        i = r2->size[0] * r2->size[1];
        r2->size[0] = 1;
        r2->size[1] = Sol->Psie->size[0] - (int32_T)ind_s;
        emxEnsureCapacity_int32_T(sp, r2, i, &r_emlrtRTEI);
        loop_ub = Sol->Psie->size[0] - (int32_T)ind_s;
        for (i = 0; i < loop_ub; i++) {
          r2->data[i] = ((int32_T)ind_s + i) + 1;
        }

        st.site = &b_emlrtRSI;
        nullAssignment(&st, Sol->Psie, r2);
        i = r2->size[0] * r2->size[1];
        r2->size[0] = 1;
        r2->size[1] = Sol->t->size[1] - (int32_T)ind_s;
        emxEnsureCapacity_int32_T(sp, r2, i, &s_emlrtRTEI);
        loop_ub = Sol->t->size[1] - (int32_T)ind_s;
        for (i = 0; i < loop_ub; i++) {
          r2->data[i] = ((int32_T)ind_s + i) + 1;
        }

        st.site = &emlrtRSI;
        b_nullAssignment(&st, Sol->t, r2);
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
  emxFree_int32_T(&r2);
  emxFree_real_T(&r1);
  emxFree_real_T(&b_r);
  emxFree_creal_T(&c_d);
  emxFree_cuint8_T(&d);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Chi23OPO_Runge_Kuarong.c) */
