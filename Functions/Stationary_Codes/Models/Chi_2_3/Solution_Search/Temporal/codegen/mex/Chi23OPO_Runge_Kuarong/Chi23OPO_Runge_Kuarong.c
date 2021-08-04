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
#include "fft.h"
#include "ifft.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 33,    /* lineNo */
  "Chi23OPO_Runge_Kuarong",            /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 3,   /* lineNo */
  "Chi23OPO_Runge_Kuarong",            /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 77,  /* lineNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pathName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  90,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 83,  /* lineNo */
  18,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  77,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  15,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  77,                                  /* lineNo */
  66,                                  /* colNo */
  "exp_plus_omega",                    /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  105,                                 /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 67,/* lineNo */
  22,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 65,/* lineNo */
  18,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  63,                                  /* lineNo */
  9,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  11,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = { 31,/* lineNo */
  14,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtDCInfo emlrtDCI = { 39,    /* lineNo */
  40,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  39,                                  /* lineNo */
  40,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 40,  /* lineNo */
  38,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  40,                                  /* lineNo */
  38,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 40,  /* lineNo */
  53,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  40,                                  /* lineNo */
  53,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 39,  /* lineNo */
  22,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  22,                                  /* colNo */
  "Sol.Psio",                          /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  39,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  22,                                  /* colNo */
  "Sol.Psie",                          /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  40,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
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

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  85,                                  /* lineNo */
  17,                                  /* colNo */
  "Runge.c",                           /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  69,                                  /* lineNo */
  20,                                  /* colNo */
  "Runge.b",                           /* aName */
  "Chi23OPO_Runge_Kuarong/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
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

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
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

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
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

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
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

static emlrtBCInfo q_emlrtBCI = { -1,  /* iFirst */
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

static emlrtBCInfo r_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
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

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
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

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  13,                                  /* colNo */
  "Sol.t",                             /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
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

static emlrtRTEInfo e_emlrtRTEI = { 3, /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23OPO_Runge_Ku"
  "arong.m"                            /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 33,/* lineNo */
  61,                                  /* colNo */
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
  emxArray_creal_T *c_d;
  emxArray_cuint8_T *d;
  creal_T exp_minus_omega_contents[192];
  creal_T exp_plus_omega_contents[192];
  creal_T E_temp[64];
  creal_T F_e[64];
  creal_T k_e[64];
  creal_T y[64];
  creal_T Psie[32];
  creal_T Psio[32];
  creal_T b_F_e[32];
  creal_T z1[32];
  real_T b_Runge;
  real_T b_d;
  real_T b_im;
  real_T b_re;
  real_T b_y;
  real_T d1;
  real_T d2;
  real_T d3;
  real_T d4;
  real_T d5;
  real_T d6;
  real_T dt;
  real_T im;
  real_T q;
  real_T r;
  real_T re;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T tmp_size[2];
  int32_T b_i;
  int32_T b_i2;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T loop_ub;
  int32_T ni;
  boolean_T rEQ0;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_cuint8_T(sp, &d, 2, &e_emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &f_emlrtDCI, sp);
  }

  b_d = (int32_T)muDoubleScalarFloor(Runge->s);
  if (Runge->s != b_d) {
    emlrtIntegerCheckR2012b(Runge->s, &e_emlrtDCI, sp);
  }

  i = d->size[0] * d->size[1];
  d->size[0] = (int32_T)Runge->s;
  emxEnsureCapacity_cuint8_T(sp, d, i, &e_emlrtRTEI);
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
  emxEnsureCapacity_cuint8_T(sp, d, i, &e_emlrtRTEI);
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
  q = Temp->Par.T / Temp->Par.dt;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (b_i = 0; b_i < 3; b_i++) {
    b_Runge = Runge->a[b_i];
    for (loop_ub = 0; loop_ub < 64; loop_ub++) {
      b_d = Temp->Eq.L[loop_ub].re;
      d3 = Temp->Eq.L[loop_ub].im;
      re = dt * (b_Runge * (0.0 * b_d - (-d3)));
      im = dt * (b_Runge * (0.0 * d3 + -b_d));
      if (im == 0.0) {
        re = muDoubleScalarExp(re);
        im = 0.0;
      } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) && (re < 0.0))
      {
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
      re = dt * (b_Runge * (0.0 * b_d - d3));
      im = dt * (b_Runge * (0.0 * d3 + b_d));
      if (im == 0.0) {
        re = muDoubleScalarExp(re);
        im = 0.0;
      } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) && (re < 0.0))
      {
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
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (loop_ub = 0; loop_ub < 64; loop_ub++) {
    re = Temp->Par.dt * (0.0 * Temp->Eq.L[loop_ub].re - (-Temp->Eq.L[loop_ub].im));
    im = Temp->Par.dt * (0.0 * Temp->Eq.L[loop_ub].im + -Temp->Eq.L[loop_ub].re);
    y[loop_ub].re = re;
    y[loop_ub].im = im;
    if (im == 0.0) {
      y[loop_ub].re = muDoubleScalarExp(re);
      y[loop_ub].im = 0.0;
    } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) && (re < 0.0))
    {
      y[loop_ub].re = 0.0;
      y[loop_ub].im = 0.0;
    } else {
      r = muDoubleScalarExp(re / 2.0);
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
  emxEnsureCapacity_creal_T(sp, Sol->Psio, i, &f_emlrtRTEI);
  if (!(Temp->Space.N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Space.N, &l_emlrtDCI, sp);
  }

  d3 = (int32_T)muDoubleScalarFloor(Temp->Space.N);
  if (Temp->Space.N != d3) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &k_emlrtDCI, sp);
  }

  i = Sol->Psio->size[0] * Sol->Psio->size[1];
  Sol->Psio->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_creal_T(sp, Sol->Psio, i, &f_emlrtRTEI);
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
  emxEnsureCapacity_creal_T(sp, Sol->Psie, i, &g_emlrtRTEI);
  if (Temp->Space.N != d3) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &n_emlrtDCI, sp);
  }

  i = Sol->Psie->size[0] * Sol->Psie->size[1];
  Sol->Psie->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_creal_T(sp, Sol->Psie, i, &g_emlrtRTEI);
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
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &h_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &o_emlrtDCI, sp);
  }

  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[1] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &h_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &s_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd;
  for (i = 0; i < loop_ub; i++) {
    Sol->t->data[i].re = 0.0;
    Sol->t->data[i].im = 0.0;
  }

  i = (int32_T)q;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, q, mxDOUBLE_CLASS, (int32_T)q,
    &d_emlrtRTEI, sp);
  if (0 <= (int32_T)q - 1) {
    b_loop_ub = d->size[0] * d->size[1];
    i1 = (int32_T)(Runge->s + -1.0);
    i2 = (int32_T)Runge->s;
    b_y = Temp->Par.s_t / Temp->Par.dt;
  }

  emxInit_creal_T(sp, &c_d, 2, &i_emlrtRTEI, true);
  if (0 <= i - 1) {
    q = 32.0 * exp_plus_omega_contents[96].re;
    im = 32.0 * exp_plus_omega_contents[96].im;
    if (im == 0.0) {
      b_re = q / 2.0;
      b_im = 0.0;
    } else if (q == 0.0) {
      b_re = 0.0;
      b_im = im / 2.0;
    } else {
      b_re = q / 2.0;
      b_im = im / 2.0;
    }

    c_loop_ub = d->size[1];
  }

  for (ni = 0; ni < i; ni++) {
    st.site = &emlrtRSI;
    i3 = c_d->size[0] * c_d->size[1];
    c_d->size[0] = d->size[0];
    c_d->size[1] = d->size[1];
    emxEnsureCapacity_creal_T(&st, c_d, i3, &i_emlrtRTEI);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      c_d->data[i3].re = d->data[i3].re;
      c_d->data[i3].im = d->data[i3].im;
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    memcpy(&E_temp[0], &F_e[0], 64U * sizeof(creal_T));
    if (1 > d->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, d->size[0], &e_emlrtBCI, &st);
    }

    iv[0] = 1;
    iv[1] = d->size[1];
    iv1[0] = 1;
    iv1[1] = 64;
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &b_emlrtECI, &st);
    for (i3 = 0; i3 < 32; i3++) {
      b_d = F_e[i3].re;
      d4 = F_e[i3].im;
      d5 = exp_minus_omega_contents[3 * i3].re;
      d6 = exp_minus_omega_contents[3 * i3].im;
      b_F_e[i3].re = b_d * d5 - d4 * d6;
      b_F_e[i3].im = b_d * d6 + d4 * d5;
    }

    ifft(b_F_e, Psio);
    for (i3 = 0; i3 < 32; i3++) {
      i4 = 3 * (i3 + 32);
      b_d = F_e[i3 + 32].re;
      d4 = F_e[i3 + 32].im;
      d5 = exp_minus_omega_contents[i4].re;
      d6 = exp_minus_omega_contents[i4].im;
      b_F_e[i3].re = b_d * d5 - d4 * d6;
      b_F_e[i3].im = b_d * d6 + d4 * d5;
    }

    ifft(b_F_e, Psie);
    memset(&k_e[0], 0, 64U * sizeof(creal_T));
    for (loop_ub = 0; loop_ub < 32; loop_ub++) {
      b_d = Psie[loop_ub].re;
      d4 = Psie[loop_ub].im;
      d5 = muDoubleScalarHypot(b_d, d4);
      d6 = d5 * d5;
      b_Runge = Psio[loop_ub].re;
      r = Psio[loop_ub].im;
      d5 = muDoubleScalarHypot(b_Runge, r);
      q = Temp->Eq.gam2o * b_Runge;
      im = Temp->Eq.gam2o * -r;
      d5 = Temp->Eq.gam3o * (d5 * d5 + 2.0 * d6);
      b_F_e[loop_ub].re = (q * b_d - im * d4) + d5 * b_Runge;
      b_F_e[loop_ub].im = (q * d4 + im * b_d) + d5 * r;
    }

    fft(b_F_e, z1);
    for (loop_ub = 0; loop_ub < 32; loop_ub++) {
      b_d = exp_plus_omega_contents[3 * loop_ub].re;
      d4 = exp_plus_omega_contents[3 * loop_ub].im;
      re = 0.0 * b_d - d4;
      im = 0.0 * d4 + b_d;
      b_d = z1[loop_ub].re;
      d4 = z1[loop_ub].im;
      k_e[loop_ub].re = re * b_d - im * d4;
      k_e[loop_ub].im = re * d4 + im * b_d;
      b_d = Psio[loop_ub].re;
      d4 = Psio[loop_ub].im;
      d5 = muDoubleScalarHypot(b_d, d4);
      d6 = d5 * d5;
      re = b_d * b_d - d4 * d4;
      q = b_d * d4;
      im = q + q;
      z1[loop_ub].re = re;
      z1[loop_ub].im = im;
      b_d = Psie[loop_ub].re;
      d4 = Psie[loop_ub].im;
      d5 = muDoubleScalarHypot(b_d, d4);
      d5 = Temp->Eq.gam3e * (2.0 * d6 + d5 * d5);
      b_d = Temp->Eq.gam2e * re + d5 * b_d;
      Psie[loop_ub].re = b_d;
      d4 = Temp->Eq.gam2e * im + d5 * d4;
      Psie[loop_ub].im = d4;
    }

    fft(Psie, z1);
    for (i3 = 0; i3 < 32; i3++) {
      b_i = 3 * (i3 + 32);
      b_d = exp_plus_omega_contents[b_i].re;
      d4 = exp_plus_omega_contents[b_i].im;
      re = 0.0 * b_d - d4;
      im = 0.0 * d4 + b_d;
      b_d = z1[i3].re;
      d4 = z1[i3].im;
      k_e[i3 + 32].re = re * b_d - im * d4;
      k_e[i3 + 32].im = re * d4 + im * b_d;
    }

    k_e[32].re += Temp->Eq.ke * b_re * Temp->Eq.H_s;
    k_e[32].im += Temp->Eq.ke * b_im * Temp->Eq.H_s;

    /*     k_e(N+2)      = k_e(N+2) + N.*Fac_plus(N+2).*1/2*Eq.ke*Eq.H_s*exp(-1i*t*(real(Eq.Le(2)) - Eq.delta_e2) ); */
    /*     k_e(end)      = k_e(end) + N.*Fac_plus(end).*1/2*Eq.ke*Eq.H_s.*exp(-1i*t*(real(Eq.Le(end)) + Eq.delta_e) ); */
    for (i3 = 0; i3 < c_loop_ub; i3++) {
      c_d->data[c_d->size[0] * i3] = k_e[i3];
    }

    emlrtForLoopVectorCheckR2012b(2.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      (Runge->s + -1.0), &c_emlrtRTEI, &st);
    if (0 <= i1 - 1) {
      iv1[0] = 1;
      iv1[1] = 64;
    }

    if (0 <= i1 - 1) {
      i5 = (int32_T)(Runge->s - 1.0);
    }

    for (b_i2 = 0; b_i2 < i1; b_i2++) {
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
        (int32_T)(Runge->s - 1.0), &b_emlrtRTEI, &st);
      for (loop_ub = 0; loop_ub < i5; loop_ub++) {
        if (((int32_T)(b_i2 + 2U) < 1) || ((int32_T)(b_i2 + 2U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i2 + 2U), 1, 3, &l_emlrtBCI,
            &st);
        }

        if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, 3,
            &l_emlrtBCI, &st);
        }

        b_d = Runge->b[(b_i2 + 3 * loop_ub) + 1];
        if (b_d != 0.0) {
          q = dt * b_d;
          if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) >
               c_d->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, c_d->size
              [0], &d_emlrtBCI, &st);
          }

          for (i3 = 0; i3 < 64; i3++) {
            b_d = Temp->Eq.mode_range[i3];
            i4 = (int32_T)muDoubleScalarFloor(b_d);
            if (b_d != i4) {
              emlrtIntegerCheckR2012b(b_d, &w_emlrtDCI, &st);
            }

            b_i = (int32_T)b_d;
            if ((b_i < 1) || (b_i > 64)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, 64, &p_emlrtBCI, &st);
            }

            if (b_i != i4) {
              emlrtIntegerCheckR2012b(b_d, &x_emlrtDCI, &st);
            }

            if (b_i > c_d->size[1]) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &q_emlrtBCI,
                &st);
            }

            k_e[i3].re = E_temp[b_i - 1].re + q * c_d->data[loop_ub + c_d->size
              [0] * (b_i - 1)].re;
            if (b_i != i4) {
              emlrtIntegerCheckR2012b(b_d, &w_emlrtDCI, &st);
            }

            if (b_i > c_d->size[1]) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &q_emlrtBCI,
                &st);
            }

            k_e[i3].im = E_temp[b_i - 1].im + q * c_d->data[loop_ub + c_d->size
              [0] * (b_i - 1)].im;
          }

          for (i3 = 0; i3 < 64; i3++) {
            b_d = Temp->Eq.mode_range[i3];
            i4 = (int32_T)muDoubleScalarFloor(b_d);
            if (b_d != i4) {
              emlrtIntegerCheckR2012b(b_d, &ab_emlrtDCI, &st);
            }

            b_i = (int32_T)b_d;
            if ((b_i < 1) || (b_i > 64)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, 64, &s_emlrtBCI, &st);
            }

            E_temp[b_i - 1].re = k_e[i3].re;
            if (b_i != i4) {
              emlrtIntegerCheckR2012b(b_d, &ab_emlrtDCI, &st);
            }

            E_temp[b_i - 1].im = k_e[i3].im;
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      if ((b_i2 + 2 < 1) || (b_i2 + 2 > c_d->size[0])) {
        emlrtDynamicBoundsCheckR2012b(b_i2 + 2, 1, c_d->size[0], &b_emlrtBCI,
          &st);
      }

      iv[0] = 1;
      iv[1] = c_d->size[1];
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &emlrtECI, &st);
      b_st.site = &e_emlrtRSI;
      if ((b_i2 + 2 < 1) || (b_i2 + 2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(b_i2 + 2, 1, 3, &c_emlrtBCI, &b_st);
      }

      for (i3 = 0; i3 < 32; i3++) {
        i4 = (b_i2 + 3 * i3) + 1;
        b_d = E_temp[i3].re;
        d4 = E_temp[i3].im;
        b_F_e[i3].re = b_d * exp_minus_omega_contents[i4].re - d4 *
          exp_minus_omega_contents[i4].im;
        b_F_e[i3].im = b_d * exp_minus_omega_contents[i4].im + d4 *
          exp_minus_omega_contents[i4].re;
      }

      ifft(b_F_e, Psio);
      for (i3 = 0; i3 < 32; i3++) {
        i4 = (b_i2 + 3 * (i3 + 32)) + 1;
        b_d = E_temp[i3 + 32].re;
        d4 = E_temp[i3 + 32].im;
        b_F_e[i3].re = b_d * exp_minus_omega_contents[i4].re - d4 *
          exp_minus_omega_contents[i4].im;
        b_F_e[i3].im = b_d * exp_minus_omega_contents[i4].im + d4 *
          exp_minus_omega_contents[i4].re;
      }

      ifft(b_F_e, Psie);
      memset(&k_e[0], 0, 64U * sizeof(creal_T));
      for (loop_ub = 0; loop_ub < 32; loop_ub++) {
        b_d = Psie[loop_ub].re;
        d4 = Psie[loop_ub].im;
        d5 = muDoubleScalarHypot(b_d, d4);
        d6 = d5 * d5;
        b_Runge = Psio[loop_ub].re;
        r = Psio[loop_ub].im;
        d5 = muDoubleScalarHypot(b_Runge, r);
        q = Temp->Eq.gam2o * b_Runge;
        im = Temp->Eq.gam2o * -r;
        d5 = Temp->Eq.gam3o * (d5 * d5 + 2.0 * d6);
        b_F_e[loop_ub].re = (q * b_d - im * d4) + d5 * b_Runge;
        b_F_e[loop_ub].im = (q * d4 + im * b_d) + d5 * r;
      }

      fft(b_F_e, z1);
      for (loop_ub = 0; loop_ub < 32; loop_ub++) {
        b_i = (b_i2 + 3 * loop_ub) + 1;
        re = 0.0 * exp_plus_omega_contents[b_i].re - exp_plus_omega_contents[b_i]
          .im;
        im = 0.0 * exp_plus_omega_contents[b_i].im + exp_plus_omega_contents[b_i]
          .re;
        b_d = z1[loop_ub].re;
        d4 = z1[loop_ub].im;
        k_e[loop_ub].re = re * b_d - im * d4;
        k_e[loop_ub].im = re * d4 + im * b_d;
        b_d = Psio[loop_ub].re;
        d4 = Psio[loop_ub].im;
        d5 = muDoubleScalarHypot(b_d, d4);
        d6 = d5 * d5;
        re = b_d * b_d - d4 * d4;
        q = b_d * d4;
        im = q + q;
        z1[loop_ub].re = re;
        z1[loop_ub].im = im;
        b_d = Psie[loop_ub].re;
        d4 = Psie[loop_ub].im;
        d5 = muDoubleScalarHypot(b_d, d4);
        d5 = Temp->Eq.gam3e * (2.0 * d6 + d5 * d5);
        b_d = Temp->Eq.gam2e * re + d5 * b_d;
        Psie[loop_ub].re = b_d;
        d4 = Temp->Eq.gam2e * im + d5 * d4;
        Psie[loop_ub].im = d4;
      }

      fft(Psie, z1);
      for (i3 = 0; i3 < 32; i3++) {
        b_i = (b_i2 + 3 * (i3 + 32)) + 1;
        re = 0.0 * exp_plus_omega_contents[b_i].re - exp_plus_omega_contents[b_i]
          .im;
        im = 0.0 * exp_plus_omega_contents[b_i].im + exp_plus_omega_contents[b_i]
          .re;
        b_d = z1[i3].re;
        d4 = z1[i3].im;
        k_e[i3 + 32].re = re * b_d - im * d4;
        k_e[i3 + 32].im = re * d4 + im * b_d;
      }

      q = 32.0 * exp_plus_omega_contents[b_i2 + 97].re;
      im = 32.0 * exp_plus_omega_contents[b_i2 + 97].im;
      if (im == 0.0) {
        re = q / 2.0;
        im = 0.0;
      } else if (q == 0.0) {
        re = 0.0;
        im /= 2.0;
      } else {
        re = q / 2.0;
        im /= 2.0;
      }

      k_e[32].re += Temp->Eq.ke * re * Temp->Eq.H_s;
      k_e[32].im += Temp->Eq.ke * im * Temp->Eq.H_s;

      /*     k_e(N+2)      = k_e(N+2) + N.*Fac_plus(N+2).*1/2*Eq.ke*Eq.H_s*exp(-1i*t*(real(Eq.Le(2)) - Eq.delta_e2) ); */
      /*     k_e(end)      = k_e(end) + N.*Fac_plus(end).*1/2*Eq.ke*Eq.H_s.*exp(-1i*t*(real(Eq.Le(end)) + Eq.delta_e) ); */
      loop_ub = c_d->size[1];
      for (i3 = 0; i3 < loop_ub; i3++) {
        c_d->data[(b_i2 + c_d->size[0] * i3) + 1] = k_e[i3];
      }

      memcpy(&E_temp[0], &F_e[0], 64U * sizeof(creal_T));
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      Runge->s, &emlrtRTEI, &st);
    for (loop_ub = 0; loop_ub < i2; loop_ub++) {
      if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) > 3)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, 3, &k_emlrtBCI,
          &st);
      }

      b_d = Runge->c[loop_ub];
      if (b_d != 0.0) {
        q = dt * b_d;
        if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) >
             c_d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, c_d->size[0],
            &emlrtBCI, &st);
        }

        for (i3 = 0; i3 < 64; i3++) {
          b_d = Temp->Eq.mode_range[i3];
          i4 = (int32_T)muDoubleScalarFloor(b_d);
          if (b_d != i4) {
            emlrtIntegerCheckR2012b(b_d, &u_emlrtDCI, &st);
          }

          b_i = (int32_T)b_d;
          if ((b_i < 1) || (b_i > 64)) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, 64, &n_emlrtBCI, &st);
          }

          if (b_i != i4) {
            emlrtIntegerCheckR2012b(b_d, &v_emlrtDCI, &st);
          }

          if (b_i > c_d->size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &o_emlrtBCI, &st);
          }

          k_e[i3].re = F_e[b_i - 1].re + q * c_d->data[loop_ub + c_d->size[0] *
            (b_i - 1)].re;
          if (b_i != i4) {
            emlrtIntegerCheckR2012b(b_d, &u_emlrtDCI, &st);
          }

          if (b_i > c_d->size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &o_emlrtBCI, &st);
          }

          k_e[i3].im = F_e[b_i - 1].im + q * c_d->data[loop_ub + c_d->size[0] *
            (b_i - 1)].im;
        }

        for (i3 = 0; i3 < 64; i3++) {
          b_d = Temp->Eq.mode_range[i3];
          i4 = (int32_T)muDoubleScalarFloor(b_d);
          if (b_d != i4) {
            emlrtIntegerCheckR2012b(b_d, &y_emlrtDCI, &st);
          }

          b_i = (int32_T)b_d;
          if ((b_i < 1) || (b_i > 64)) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, 64, &r_emlrtBCI, &st);
          }

          F_e[b_i - 1].re = k_e[i3].re;
          if (b_i != i4) {
            emlrtIntegerCheckR2012b(b_d, &y_emlrtDCI, &st);
          }

          F_e[b_i - 1].im = k_e[i3].im;
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    for (i3 = 0; i3 < 64; i3++) {
      b_d = Temp->Eq.mode_range[i3];
      i4 = (int32_T)muDoubleScalarFloor(b_d);
      if (b_d != i4) {
        emlrtIntegerCheckR2012b(b_d, &bb_emlrtDCI, &st);
      }

      b_i = (int32_T)b_d;
      if ((b_i < 1) || (b_i > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, 64, &u_emlrtBCI, &st);
      }

      if (b_i != i4) {
        emlrtIntegerCheckR2012b(b_d, &bb_emlrtDCI, &st);
      }

      E_temp[i3].re = y[b_i - 1].re * F_e[b_i - 1].re - y[b_i - 1].im * F_e[b_i
        - 1].im;
      if (b_i != i4) {
        emlrtIntegerCheckR2012b(b_d, &bb_emlrtDCI, &st);
      }

      E_temp[i3].im = y[b_i - 1].re * F_e[b_i - 1].im + y[b_i - 1].im * F_e[b_i
        - 1].re;
    }

    for (i3 = 0; i3 < 64; i3++) {
      b_d = Temp->Eq.mode_range[i3];
      i4 = (int32_T)muDoubleScalarFloor(b_d);
      if (b_d != i4) {
        emlrtIntegerCheckR2012b(b_d, &t_emlrtDCI, &st);
      }

      b_i = (int32_T)b_d;
      if ((b_i < 1) || (b_i > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, 64, &m_emlrtBCI, &st);
      }

      F_e[b_i - 1].re = E_temp[i3].re;
      if (b_i != i4) {
        emlrtIntegerCheckR2012b(b_d, &t_emlrtDCI, &st);
      }

      F_e[b_i - 1].im = E_temp[i3].im;
    }

    /* ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back */
    r = (real_T)ni + 1.0;
    if (!(b_y == 0.0)) {
      if (muDoubleScalarIsNaN(b_y)) {
        r = rtNaN;
      } else if (muDoubleScalarIsInf(b_y)) {
        if (b_y < 0.0) {
          r = b_y;
        }
      } else {
        r = muDoubleScalarRem((real_T)ni + 1.0, b_y);
        rEQ0 = (r == 0.0);
        if ((!rEQ0) && (b_y > muDoubleScalarFloor(b_y))) {
          q = muDoubleScalarAbs(((real_T)ni + 1.0) / b_y);
          rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
                   2.2204460492503131E-16 * q);
        }

        if (rEQ0) {
          r = b_y * 0.0;
        } else {
          if (b_y < 0.0) {
            r += b_y;
          }
        }
      }
    }

    if (r == 0.0) {
      b_Runge = ((real_T)ni + 1.0) * Temp->Par.dt;
      r = muDoubleScalarRound(b_Runge / Temp->Par.s_t);
      if (1.0 > Temp->Space.N) {
        loop_ub = 0;
      } else {
        if (Temp->Space.N != d3) {
          emlrtIntegerCheckR2012b(Temp->Space.N, &emlrtDCI, sp);
        }

        if (((int32_T)Temp->Space.N < 1) || ((int32_T)Temp->Space.N > 64)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)Temp->Space.N, 1, 64,
            &f_emlrtBCI, sp);
        }

        loop_ub = (int32_T)Temp->Space.N;
      }

      if (r != (int32_T)r) {
        emlrtIntegerCheckR2012b(r, &d_emlrtDCI, sp);
      }

      if (((int32_T)r < 1) || ((int32_T)r > Sol->Psio->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)r, 1, Sol->Psio->size[0],
          &i_emlrtBCI, sp);
      }

      tmp_size[0] = 1;
      tmp_size[1] = loop_ub;
      for (i3 = 0; i3 < loop_ub; i3++) {
        q = F_e[i3].re;
        im = F_e[i3].im;
        if (im == 0.0) {
          E_temp[i3].re = q / Temp->Space.N;
          E_temp[i3].im = 0.0;
        } else if (q == 0.0) {
          E_temp[i3].re = 0.0;
          E_temp[i3].im = im / Temp->Space.N;
        } else {
          E_temp[i3].re = q / Temp->Space.N;
          E_temp[i3].im = im / Temp->Space.N;
        }
      }

      iv[0] = 1;
      iv[1] = Sol->Psio->size[1];
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &c_emlrtECI, sp);
      for (i3 = 0; i3 < loop_ub; i3++) {
        Sol->Psio->data[((int32_T)r + Sol->Psio->size[0] * i3) - 1] = E_temp[i3];
      }

      if (Temp->Space.N + 1.0 > d1) {
        i3 = 0;
        i4 = 0;
      } else {
        if (Temp->Space.N + 1.0 != (int32_T)muDoubleScalarFloor(Temp->Space.N +
             1.0)) {
          emlrtIntegerCheckR2012b(Temp->Space.N + 1.0, &b_emlrtDCI, sp);
        }

        if (((int32_T)(Temp->Space.N + 1.0) < 1) || ((int32_T)(Temp->Space.N +
              1.0) > 64)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(Temp->Space.N + 1.0), 1, 64,
            &g_emlrtBCI, sp);
        }

        i3 = (int32_T)(Temp->Space.N + 1.0) - 1;
        if (d1 != d2) {
          emlrtIntegerCheckR2012b(d1, &c_emlrtDCI, sp);
        }

        if (((int32_T)d1 < 1) || ((int32_T)d1 > 64)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)d1, 1, 64, &h_emlrtBCI, sp);
        }

        i4 = (int32_T)d1;
      }

      if (((int32_T)r < 1) || ((int32_T)r > Sol->Psie->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)r, 1, Sol->Psie->size[0],
          &j_emlrtBCI, sp);
      }

      tmp_size[0] = 1;
      loop_ub = i4 - i3;
      tmp_size[1] = loop_ub;
      for (i4 = 0; i4 < loop_ub; i4++) {
        b_i = i3 + i4;
        q = F_e[b_i].re;
        im = F_e[b_i].im;
        if (im == 0.0) {
          E_temp[i4].re = q / Temp->Space.N;
          E_temp[i4].im = 0.0;
        } else if (q == 0.0) {
          E_temp[i4].re = 0.0;
          E_temp[i4].im = im / Temp->Space.N;
        } else {
          E_temp[i4].re = q / Temp->Space.N;
          E_temp[i4].im = im / Temp->Space.N;
        }
      }

      iv[0] = 1;
      iv[1] = Sol->Psie->size[1];
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &d_emlrtECI, sp);
      for (i3 = 0; i3 < loop_ub; i3++) {
        Sol->Psie->data[((int32_T)r + Sol->Psie->size[0] * i3) - 1] = E_temp[i3];
      }

      if (((int32_T)r < 1) || ((int32_T)r > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)r, 1, Sol->t->size[1],
          &t_emlrtBCI, sp);
      }

      Sol->t->data[(int32_T)r - 1].re = b_Runge;
      if (((int32_T)r < 1) || ((int32_T)r > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)r, 1, Sol->t->size[1],
          &t_emlrtBCI, sp);
      }

      Sol->t->data[(int32_T)r - 1].im = 0.0;

      /*              if 10*log10(sum(abs(Sol.Psio(ind_s,2:end)).^2)) <= -100 && (mod(ind_s,2) == 0) */
      /*   */
      /*                      Sol.Psio(ind_s+1:end,:) = []; */
      /*                      Sol.Psie(ind_s+1:end,:) = []; */
      /*                      Sol.t(ind_s+1:end)     = [];                 */
      /*                      break; */
      /*   */
      /*              end */
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_creal_T(&c_d);
  emxFree_cuint8_T(&d);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Chi23OPO_Runge_Kuarong.c) */
