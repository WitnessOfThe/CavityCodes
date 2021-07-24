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
#include "mwmathutil.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "Chi23OPO_Runge_Kuarong.h"
#include "ifft.h"
#include "fft1.h"
#include "Chi23OPO_Runge_Kuarong_emxutil.h"
#include "Chi23OPO_Runge_Kuarong_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 33,    /* lineNo */
  "Chi23OPO_Runge_Kuarong",            /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 3,   /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 33,/* lineNo */
  61,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 63,/* lineNo */
  13,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 77,/* lineNo */
  18,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 39,/* lineNo */
  29,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 40,/* lineNo */
  29,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 1, /* lineNo */
  20,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  90,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo l_emlrtRTEI = { 83,/* lineNo */
  18,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  77,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  15,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  77,                                  /* lineNo */
  88,                                  /* colNo */
  "exp_minus_omega",                   /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  77,                                  /* lineNo */
  66,                                  /* colNo */
  "exp_plus_omega",                    /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  105,                                 /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo m_emlrtRTEI = { 67,/* lineNo */
  22,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 65,/* lineNo */
  18,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  63,                                  /* lineNo */
  9,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  11,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo o_emlrtRTEI = { 31,/* lineNo */
  14,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 39,    /* lineNo */
  40,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  39,                                  /* lineNo */
  40,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 40,  /* lineNo */
  38,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  40,                                  /* lineNo */
  38,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 40,  /* lineNo */
  53,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  40,                                  /* lineNo */
  53,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 39,  /* lineNo */
  22,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  22,                                  /* colNo */
  "Sol.Psio",                          /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  39,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  22,                                  /* colNo */
  "Sol.Psie",                          /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  40,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m"/* pName */
};

static emlrtDCInfo e_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 3,   /* lineNo */
  43,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 3,   /* lineNo */
  43,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 25,  /* lineNo */
  30,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 25,  /* lineNo */
  30,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 25,  /* lineNo */
  42,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 25,  /* lineNo */
  42,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 26,  /* lineNo */
  30,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 26,  /* lineNo */
  42,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 28,  /* lineNo */
  32,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 3,   /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 3,   /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 25,  /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 26,  /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 28,  /* lineNo */
  5,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  85,                                  /* lineNo */
  17,                                  /* colNo */
  "Runge.c",                           /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  69,                                  /* lineNo */
  20,                                  /* colNo */
  "Runge.b",                           /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  93,                                  /* lineNo */
  12,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 93,  /* lineNo */
  12,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  87,                                  /* lineNo */
  50,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 87,  /* lineNo */
  50,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  93,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 87,  /* lineNo */
  93,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  71,                                  /* lineNo */
  62,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 71,  /* lineNo */
  62,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  108,                                 /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 71,  /* lineNo */
  108,                                 /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  87,                                  /* lineNo */
  17,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = { 87, /* lineNo */
  17,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  71,                                  /* lineNo */
  21,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 71, /* lineNo */
  21,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  13,                                  /* colNo */
  "Sol.t",                             /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  93,                                  /* lineNo */
  38,                                  /* colNo */
  "shift_back",                        /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 93, /* lineNo */
  38,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  93,                                  /* lineNo */
  38,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  33,                                  /* lineNo */
  9,                                   /* colNo */
  "E_f",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = { 33, /* lineNo */
  9,                                   /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  87,                                  /* lineNo */
  46,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = { 87, /* lineNo */
  46,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  46,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { 1,  /* iFirst */
  64,                                  /* iLast */
  71,                                  /* lineNo */
  55,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = { 71, /* lineNo */
  55,                                  /* colNo */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  55,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23OPO_Runge_Kuarong",            /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23OPO_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void Chi_3_LLE_Kuar_ins(const creal_T F_Psi[64], const creal_T Fac_plus
  [64], const creal_T Fac_minus[64], real_T Eq_H_s, real_T Eq_ke, real_T
  Eq_gam2o, real_T Eq_gam2e, real_T Eq_gam3o, real_T Eq_gam3e, creal_T k_e[64]);

/* Function Definitions */
static void Chi_3_LLE_Kuar_ins(const creal_T F_Psi[64], const creal_T Fac_plus
  [64], const creal_T Fac_minus[64], real_T Eq_H_s, real_T Eq_ke, real_T
  Eq_gam2o, real_T Eq_gam2e, real_T Eq_gam3o, real_T Eq_gam3e, creal_T k_e[64])
{
  int32_T k;
  creal_T b_F_Psi[32];
  creal_T Psio[32];
  creal_T Psie[32];
  real_T im;
  real_T z1[32];
  creal_T b_z1[32];
  real_T Eq_gam2o_re;
  real_T Eq_gam2o_im;
  for (k = 0; k < 32; k++) {
    b_F_Psi[k].re = F_Psi[k].re * Fac_minus[k].re - F_Psi[k].im * Fac_minus[k].
      im;
    b_F_Psi[k].im = F_Psi[k].re * Fac_minus[k].im + F_Psi[k].im * Fac_minus[k].
      re;
  }

  ifft(b_F_Psi, Psio);
  for (k = 0; k < 32; k++) {
    b_F_Psi[k].re = F_Psi[32 + k].re * Fac_minus[32 + k].re - F_Psi[32 + k].im *
      Fac_minus[32 + k].im;
    b_F_Psi[k].im = F_Psi[32 + k].re * Fac_minus[32 + k].im + F_Psi[32 + k].im *
      Fac_minus[32 + k].re;
  }

  ifft(b_F_Psi, Psie);
  for (k = 0; k < 32; k++) {
    im = muDoubleScalarHypot(Psio[k].re, Psio[k].im);
    z1[k] = im * im;
  }

  for (k = 0; k < 32; k++) {
    im = muDoubleScalarHypot(Psie[k].re, Psie[k].im);
    Eq_gam2o_re = Eq_gam2o * Psio[k].re;
    Eq_gam2o_im = Eq_gam2o * -Psio[k].im;
    b_F_Psi[k].re = (Eq_gam2o_re * Psie[k].re - Eq_gam2o_im * Psie[k].im) +
      Eq_gam3o * (z1[k] + 2.0 * (im * im)) * Psio[k].re;
    b_F_Psi[k].im = (Eq_gam2o_re * Psie[k].im + Eq_gam2o_im * Psie[k].re) +
      Eq_gam3o * (z1[k] + 2.0 * (im * im)) * Psio[k].im;
  }

  fft(b_F_Psi, b_z1);
  for (k = 0; k < 32; k++) {
    Eq_gam2o_re = 0.0 * Fac_plus[k].re - Fac_plus[k].im;
    im = 0.0 * Fac_plus[k].im + Fac_plus[k].re;
    k_e[k].re = Eq_gam2o_re * b_z1[k].re - im * b_z1[k].im;
    k_e[k].im = Eq_gam2o_re * b_z1[k].im + im * b_z1[k].re;
  }

  for (k = 0; k < 32; k++) {
    b_z1[k].re = Psio[k].re * Psio[k].re - Psio[k].im * Psio[k].im;
    b_z1[k].im = Psio[k].re * Psio[k].im + Psio[k].im * Psio[k].re;
    im = muDoubleScalarHypot(Psio[k].re, Psio[k].im);
    z1[k] = im * im;
  }

  for (k = 0; k < 32; k++) {
    im = muDoubleScalarHypot(Psie[k].re, Psie[k].im);
    b_F_Psi[k].re = Eq_gam2e * b_z1[k].re + Eq_gam3e * (2.0 * z1[k] + im * im) *
      Psie[k].re;
    b_F_Psi[k].im = Eq_gam2e * b_z1[k].im + Eq_gam3e * (2.0 * z1[k] + im * im) *
      Psie[k].im;
  }

  fft(b_F_Psi, b_z1);
  for (k = 0; k < 32; k++) {
    Eq_gam2o_re = 0.0 * Fac_plus[32 + k].re - Fac_plus[32 + k].im;
    im = 0.0 * Fac_plus[32 + k].im + Fac_plus[32 + k].re;
    k_e[32 + k].re = Eq_gam2o_re * b_z1[k].re - im * b_z1[k].im;
    k_e[32 + k].im = Eq_gam2o_re * b_z1[k].im + im * b_z1[k].re;
  }

  im = 32.0 * Fac_plus[32].re;
  Eq_gam2o_im = 32.0 * Fac_plus[32].im;
  if (Eq_gam2o_im == 0.0) {
    Eq_gam2o_re = im / 2.0;
    im = 0.0;
  } else if (im == 0.0) {
    Eq_gam2o_re = 0.0;
    im = Eq_gam2o_im / 2.0;
  } else {
    Eq_gam2o_re = im / 2.0;
    im = Eq_gam2o_im / 2.0;
  }

  k_e[32].re += Eq_ke * Eq_gam2o_re * Eq_H_s;
  k_e[32].im += Eq_ke * im * Eq_H_s;

  /*     k_e(N+2)      = k_e(N+2) + N.*Fac_plus(N+2).*1/2*Eq.ke*Eq.H_s*exp(-1i*t*(real(Eq.Le(2)) - Eq.delta_e2) ); */
  /*     k_e(end)      = k_e(end) + N.*Fac_plus(end).*1/2*Eq.ke*Eq.H_s.*exp(-1i*t*(real(Eq.Le(end)) + Eq.delta_e) ); */
}

void Chi23OPO_Runge_Kuarong(const emlrtStack *sp, const struct0_T *Temp, const
  struct5_T *Runge, struct6_T *Sol)
{
  emxArray_cuint8_T *d;
  boolean_T b0;
  boolean_T b1;
  int32_T i0;
  real_T d0;
  int32_T loop_ub;
  real_T dt;
  real_T ind_s;
  int32_T i;
  real_T q;
  int32_T k;
  real_T re;
  real_T re_tmp;
  real_T im;
  real_T im_tmp;
  creal_T y[64];
  real_T r;
  creal_T F_e[64];
  creal_T exp_minus_omega_contents[192];
  creal_T exp_plus_omega_contents[192];
  emxArray_creal_T *b_d;
  emxArray_int32_T *r0;
  int32_T ni;
  int32_T i1;
  creal_T E_temp[64];
  int32_T iv0[2];
  int32_T iv1[2];
  creal_T b_exp_plus_omega_contents[64];
  creal_T b_exp_minus_omega_contents[64];
  creal_T b_E_temp[64];
  int32_T i2;
  int32_T b_i2;
  int32_T i3;
  int32_T i4;
  boolean_T rEQ0;
  int32_T iv2[2];
  int32_T tmp_size[2];
  creal_T tmp_data[64];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_cuint8_T(sp, &d, 2, &emlrtRTEI, true);
  b0 = false;
  b1 = false;
  i0 = d->size[0] * d->size[1];
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &f_emlrtDCI, sp);
  }

  if (Runge->s != (int32_T)muDoubleScalarFloor(Runge->s)) {
    emlrtIntegerCheckR2012b(Runge->s, &e_emlrtDCI, sp);
  }

  d->size[0] = (int32_T)Runge->s;
  d0 = 2.0 * Temp->Space.N;
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &h_emlrtDCI, sp);
  }

  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &g_emlrtDCI, sp);
  }

  d->size[1] = (int32_T)d0;
  emxEnsureCapacity_cuint8_T(sp, d, i0, &emlrtRTEI);
  if (Runge->s != (int32_T)muDoubleScalarFloor(Runge->s)) {
    emlrtIntegerCheckR2012b(Runge->s, &p_emlrtDCI, sp);
  }

  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &q_emlrtDCI, sp);
  }

  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &p_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Runge->s * (int32_T)d0;
  for (i0 = 0; i0 < loop_ub; i0++) {
    d->data[i0].re = 0U;
    d->data[i0].im = 0U;
  }

  dt = Temp->Par.dt;
  ind_s = Temp->Par.T / Temp->Par.dt;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (i = 0; i < 3; i++) {
    q = Runge->a[i];
    for (k = 0; k < 64; k++) {
      re_tmp = 0.0 * Temp->Eq.L[k].re;
      im_tmp = 0.0 * Temp->Eq.L[k].im;
      re = dt * (q * (re_tmp - (-Temp->Eq.L[k].im)));
      im = dt * (q * (im_tmp + -Temp->Eq.L[k].re));
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

      i0 = i + 3 * k;
      exp_minus_omega_contents[i0].re = re;
      exp_minus_omega_contents[i0].im = im;
      re = dt * (q * (re_tmp - Temp->Eq.L[k].im));
      im = dt * (q * (im_tmp + Temp->Eq.L[k].re));
      y[k].re = re;
      y[k].im = im;
      if (im == 0.0) {
        re = muDoubleScalarExp(re);
        im = 0.0;
        y[k].re = re;
        y[k].im = 0.0;
      } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) && (re < 0.0))
      {
        re = 0.0;
        im = 0.0;
        y[k].re = 0.0;
        y[k].im = 0.0;
      } else {
        r = muDoubleScalarExp(re / 2.0);
        re = r * (r * muDoubleScalarCos(im));
        im = r * (r * muDoubleScalarSin(im));
        y[k].re = re;
        y[k].im = im;
      }

      exp_plus_omega_contents[i0].re = re;
      exp_plus_omega_contents[i0].im = im;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (k = 0; k < 64; k++) {
    re = Temp->Par.dt * (0.0 * Temp->Eq.L[k].re - (-Temp->Eq.L[k].im));
    im = Temp->Par.dt * (0.0 * Temp->Eq.L[k].im + -Temp->Eq.L[k].re);
    y[k].re = re;
    y[k].im = im;
    if (im == 0.0) {
      re = muDoubleScalarExp(re);
      y[k].re = re;
      y[k].im = 0.0;
    } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) && (re < 0.0))
    {
      y[k].re = 0.0;
      y[k].im = 0.0;
    } else {
      r = muDoubleScalarExp(re / 2.0);
      re = r * (r * muDoubleScalarCos(im));
      im = r * (r * muDoubleScalarSin(im));
      y[k].re = re;
      y[k].im = im;
    }

    F_e[k].re = Temp->In.Psi_Start[k];
    F_e[k].im = 0.0;
  }

  i0 = Sol->Psio->size[0] * Sol->Psio->size[1];
  if (!(Temp->Par.dd >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Par.dd, &j_emlrtDCI, sp);
  }

  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &i_emlrtDCI, sp);
  }

  Sol->Psio->size[0] = (int32_T)Temp->Par.dd;
  if (!(Temp->Space.N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Space.N, &l_emlrtDCI, sp);
  }

  if (Temp->Space.N != (int32_T)muDoubleScalarFloor(Temp->Space.N)) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &k_emlrtDCI, sp);
  }

  Sol->Psio->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_creal_T(sp, Sol->Psio, i0, &b_emlrtRTEI);
  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &r_emlrtDCI, sp);
  }

  if (Temp->Space.N != (int32_T)muDoubleScalarFloor(Temp->Space.N)) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &r_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd * (int32_T)Temp->Space.N;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Sol->Psio->data[i0].re = 0.0;
    Sol->Psio->data[i0].im = 0.0;
  }

  i0 = Sol->Psie->size[0] * Sol->Psie->size[1];
  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &m_emlrtDCI, sp);
  }

  Sol->Psie->size[0] = (int32_T)Temp->Par.dd;
  if (Temp->Space.N != (int32_T)muDoubleScalarFloor(Temp->Space.N)) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &n_emlrtDCI, sp);
  }

  Sol->Psie->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_creal_T(sp, Sol->Psie, i0, &c_emlrtRTEI);
  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &s_emlrtDCI, sp);
  }

  if (Temp->Space.N != (int32_T)muDoubleScalarFloor(Temp->Space.N)) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &s_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd * (int32_T)Temp->Space.N;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Sol->Psie->data[i0].re = 0.0;
    Sol->Psie->data[i0].im = 0.0;
  }

  i0 = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[0] = 1;
  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &o_emlrtDCI, sp);
  }

  Sol->t->size[1] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->t, i0, &d_emlrtRTEI);
  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &t_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Sol->t->data[i0].re = 0.0;
    Sol->t->data[i0].im = 0.0;
  }

  i0 = (int32_T)ind_s;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, ind_s, mxDOUBLE_CLASS, (int32_T)ind_s,
    &o_emlrtRTEI, sp);
  emxInit_creal_T(sp, &b_d, 2, &e_emlrtRTEI, true);
  emxInit_int32_T(sp, &r0, 1, &j_emlrtRTEI, true);
  for (ni = 0; ni < i0; ni++) {
    st.site = &emlrtRSI;
    i1 = b_d->size[0] * b_d->size[1];
    b_d->size[0] = d->size[0];
    b_d->size[1] = d->size[1];
    emxEnsureCapacity_creal_T(&st, b_d, i1, &e_emlrtRTEI);
    loop_ub = d->size[0] * d->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      i = d->data[i1].re;
      k = d->data[i1].im;
      b_d->data[i1].re = i;
      b_d->data[i1].im = k;
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    memcpy(&E_temp[0], &F_e[0], sizeof(creal_T) << 6);
    i1 = d->size[0];
    if (1 > i1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, &f_emlrtBCI, &st);
    }

    loop_ub = d->size[1];
    i1 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(&st, r0, i1, &f_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r0->data[i1] = i1;
    }

    iv0[0] = 1;
    iv0[1] = r0->size[0];
    if (!b1) {
      iv1[0] = 1;
      iv1[1] = 64;
      b1 = true;
    }

    emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &iv1[0], 2, &b_emlrtECI, &st);
    for (i1 = 0; i1 < 64; i1++) {
      b_exp_plus_omega_contents[i1] = exp_plus_omega_contents[3 * i1];
      b_exp_minus_omega_contents[i1] = exp_minus_omega_contents[3 * i1];
    }

    Chi_3_LLE_Kuar_ins(F_e, b_exp_plus_omega_contents,
                       b_exp_minus_omega_contents, Temp->Eq.H_s, Temp->Eq.ke,
                       Temp->Eq.gam2o, Temp->Eq.gam2e, Temp->Eq.gam3o,
                       Temp->Eq.gam3e, b_E_temp);
    i = r0->size[0];
    for (i1 = 0; i1 < i; i1++) {
      b_d->data[b_d->size[0] * r0->data[i1]] = b_E_temp[i1];
    }

    i1 = (int32_T)(Runge->s + -1.0);
    emlrtForLoopVectorCheckR2012b(2.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      (Runge->s + -1.0), &n_emlrtRTEI, &st);
    for (i2 = 0; i2 < i1; i2++) {
      b_i2 = (int32_T)(Runge->s - 1.0);
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
        (int32_T)(Runge->s - 1.0), &m_emlrtRTEI, &st);
      for (i = 0; i < b_i2; i++) {
        i3 = (int32_T)(2U + i2);
        if ((i3 < 1) || (i3 > 3)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 3, &m_emlrtBCI, &st);
        }

        i4 = (int32_T)(1U + i);
        if ((i4 < 1) || (i4 > 3)) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, 3, &m_emlrtBCI, &st);
        }

        if (Runge->b[(i3 + 3 * (i4 - 1)) - 1] != 0.0) {
          ind_s = dt * Runge->b[(i2 + 3 * i) + 1];
          loop_ub = b_d->size[1];
          i3 = b_d->size[0];
          if ((i4 < 1) || (i4 > i3)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &e_emlrtBCI, &st);
          }

          for (i3 = 0; i3 < 64; i3++) {
            q = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i3]);
            if (Temp->Eq.mode_range[i3] != q) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &fb_emlrtDCI, &st);
            }

            k = (int32_T)Temp->Eq.mode_range[i3];
            if ((k < 1) || (k > 64)) {
              emlrtDynamicBoundsCheckR2012b(k, 1, 64, &bb_emlrtBCI, &st);
            }

            if (Temp->Eq.mode_range[i3] != q) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &fb_emlrtDCI, &st);
            }

            if ((k < 1) || (k > loop_ub)) {
              emlrtDynamicBoundsCheckR2012b(k, 1, loop_ub, &cb_emlrtBCI, &st);
            }

            b_E_temp[i3].re = E_temp[k - 1].re + ind_s * b_d->data[(i4 +
              b_d->size[0] * (k - 1)) - 1].re;
            if (Temp->Eq.mode_range[i3] != q) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &x_emlrtDCI, &st);
            }

            if ((k < 1) || (k > 64)) {
              emlrtDynamicBoundsCheckR2012b(k, 1, 64, &q_emlrtBCI, &st);
            }

            if (Temp->Eq.mode_range[i3] != q) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &y_emlrtDCI, &st);
            }

            if ((k < 1) || (k > loop_ub)) {
              emlrtDynamicBoundsCheckR2012b(k, 1, loop_ub, &r_emlrtBCI, &st);
            }

            b_E_temp[i3].im = E_temp[k - 1].im + ind_s * b_d->data[(i4 +
              b_d->size[0] * (k - 1)) - 1].im;
          }

          for (i3 = 0; i3 < 64; i3++) {
            q = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i3]);
            if (Temp->Eq.mode_range[i3] != q) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &bb_emlrtDCI, &st);
            }

            i4 = (int32_T)Temp->Eq.mode_range[i3];
            if ((i4 < 1) || (i4 > 64)) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, 64, &t_emlrtBCI, &st);
            }

            E_temp[i4 - 1].re = b_E_temp[i3].re;
            if (Temp->Eq.mode_range[i3] != q) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &bb_emlrtDCI, &st);
            }

            if ((i4 < 1) || (i4 > 64)) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, 64, &t_emlrtBCI, &st);
            }

            E_temp[i4 - 1].im = b_E_temp[i3].im;
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      b_i2 = b_d->size[0];
      i3 = 2 + i2;
      if ((i3 < 1) || (i3 > b_i2)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, b_i2, &b_emlrtBCI, &st);
      }

      loop_ub = b_d->size[1];
      b_i2 = r0->size[0];
      r0->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(&st, r0, b_i2, &g_emlrtRTEI);
      for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
        r0->data[b_i2] = b_i2;
      }

      iv0[0] = 1;
      iv0[1] = r0->size[0];
      if (!b0) {
        iv2[0] = 1;
        iv2[1] = 64;
        b0 = true;
      }

      emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &iv2[0], 2, &emlrtECI, &st);
      b_i2 = (int32_T)(2U + i2);
      if ((b_i2 < 1) || (b_i2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 3, &d_emlrtBCI, &st);
      }

      for (b_i2 = 0; b_i2 < 64; b_i2++) {
        b_exp_plus_omega_contents[b_i2] = exp_plus_omega_contents[(i2 + 3 * b_i2)
          + 1];
      }

      b_i2 = (int32_T)(2U + i2);
      if ((b_i2 < 1) || (b_i2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 3, &c_emlrtBCI, &st);
      }

      for (b_i2 = 0; b_i2 < 64; b_i2++) {
        b_exp_minus_omega_contents[b_i2] = exp_minus_omega_contents[(i2 + 3 *
          b_i2) + 1];
      }

      Chi_3_LLE_Kuar_ins(E_temp, b_exp_plus_omega_contents,
                         b_exp_minus_omega_contents, Temp->Eq.H_s, Temp->Eq.ke,
                         Temp->Eq.gam2o, Temp->Eq.gam2e, Temp->Eq.gam3o,
                         Temp->Eq.gam3e, b_E_temp);
      i = r0->size[0];
      for (b_i2 = 0; b_i2 < i; b_i2++) {
        b_d->data[(i2 + b_d->size[0] * r0->data[b_i2]) + 1] = b_E_temp[b_i2];
      }

      memcpy(&E_temp[0], &F_e[0], sizeof(creal_T) << 6);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    i1 = (int32_T)Runge->s;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      Runge->s, &l_emlrtRTEI, &st);
    for (i = 0; i < i1; i++) {
      b_i2 = (int32_T)(1U + i);
      if ((b_i2 < 1) || (b_i2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 3, &l_emlrtBCI, &st);
      }

      if (Runge->c[b_i2 - 1] != 0.0) {
        ind_s = dt * Runge->c[i];
        loop_ub = b_d->size[1];
        i3 = b_d->size[0];
        if ((b_i2 < 1) || (b_i2 > i3)) {
          emlrtDynamicBoundsCheckR2012b(b_i2, 1, i3, &emlrtBCI, &st);
        }

        for (i3 = 0; i3 < 64; i3++) {
          q = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i3]);
          if (Temp->Eq.mode_range[i3] != q) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &eb_emlrtDCI, &st);
          }

          i4 = (int32_T)Temp->Eq.mode_range[i3];
          if ((i4 < 1) || (i4 > 64)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 64, &y_emlrtBCI, &st);
          }

          if (Temp->Eq.mode_range[i3] != q) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &eb_emlrtDCI, &st);
          }

          if ((i4 < 1) || (i4 > loop_ub)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, loop_ub, &ab_emlrtBCI, &st);
          }

          b_E_temp[i3].re = F_e[i4 - 1].re + ind_s * b_d->data[(b_i2 + b_d->
            size[0] * (i4 - 1)) - 1].re;
          if (Temp->Eq.mode_range[i3] != q) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &v_emlrtDCI, &st);
          }

          if ((i4 < 1) || (i4 > 64)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 64, &o_emlrtBCI, &st);
          }

          if (Temp->Eq.mode_range[i3] != q) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &w_emlrtDCI, &st);
          }

          if ((i4 < 1) || (i4 > loop_ub)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, loop_ub, &p_emlrtBCI, &st);
          }

          b_E_temp[i3].im = F_e[i4 - 1].im + ind_s * b_d->data[(b_i2 + b_d->
            size[0] * (i4 - 1)) - 1].im;
        }

        for (b_i2 = 0; b_i2 < 64; b_i2++) {
          q = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[b_i2]);
          if (Temp->Eq.mode_range[b_i2] != q) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &db_emlrtDCI, &st);
          }

          i3 = (int32_T)Temp->Eq.mode_range[b_i2];
          if ((i3 < 1) || (i3 > 64)) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, 64, &x_emlrtBCI, &st);
          }

          F_e[i3 - 1].re = b_E_temp[b_i2].re;
          if (Temp->Eq.mode_range[b_i2] != q) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &ab_emlrtDCI, &st);
          }

          if ((i3 < 1) || (i3 > 64)) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, 64, &s_emlrtBCI, &st);
          }

          F_e[i3 - 1].im = b_E_temp[b_i2].im;
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    for (i1 = 0; i1 < 64; i1++) {
      q = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i1]);
      if (Temp->Eq.mode_range[i1] != q) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &cb_emlrtDCI, &st);
      }

      b_i2 = (int32_T)Temp->Eq.mode_range[i1];
      if ((b_i2 < 1) || (b_i2 > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 64, &v_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != q) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &cb_emlrtDCI, &st);
      }

      if ((b_i2 < 1) || (b_i2 > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 64, &w_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != q) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &cb_emlrtDCI, &st);
      }

      if ((b_i2 < 1) || (b_i2 > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 64, &v_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != q) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &cb_emlrtDCI, &st);
      }

      if ((b_i2 < 1) || (b_i2 > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 64, &w_emlrtBCI, &st);
      }

      E_temp[i1].re = y[b_i2 - 1].re * F_e[b_i2 - 1].re - y[b_i2 - 1].im *
        F_e[b_i2 - 1].im;
      if (Temp->Eq.mode_range[i1] != q) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &cb_emlrtDCI, &st);
      }

      if ((b_i2 < 1) || (b_i2 > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 64, &v_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != q) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &cb_emlrtDCI, &st);
      }

      if ((b_i2 < 1) || (b_i2 > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 64, &w_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != q) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &cb_emlrtDCI, &st);
      }

      if ((b_i2 < 1) || (b_i2 > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 64, &v_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != q) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &cb_emlrtDCI, &st);
      }

      if ((b_i2 < 1) || (b_i2 > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 64, &w_emlrtBCI, &st);
      }

      E_temp[i1].im = y[b_i2 - 1].re * F_e[b_i2 - 1].im + y[b_i2 - 1].im *
        F_e[b_i2 - 1].re;
    }

    for (i1 = 0; i1 < 64; i1++) {
      q = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i1]);
      if (Temp->Eq.mode_range[i1] != q) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &db_emlrtDCI, &st);
      }

      b_i2 = (int32_T)Temp->Eq.mode_range[i1];
      if ((b_i2 < 1) || (b_i2 > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 64, &x_emlrtBCI, &st);
      }

      F_e[b_i2 - 1].re = E_temp[i1].re;
      if (Temp->Eq.mode_range[i1] != q) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &u_emlrtDCI, &st);
      }

      if ((b_i2 < 1) || (b_i2 > 64)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, 64, &n_emlrtBCI, &st);
      }

      F_e[b_i2 - 1].im = E_temp[i1].im;
    }

    /* ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back */
    ind_s = Temp->Par.s_t / Temp->Par.dt;
    r = 1.0 + (real_T)ni;
    if ((!muDoubleScalarIsInf(ind_s)) && (!muDoubleScalarIsNaN(ind_s))) {
      if (ind_s != 0.0) {
        r = muDoubleScalarRem(1.0 + (real_T)ni, ind_s);
        rEQ0 = (r == 0.0);
        if ((!rEQ0) && (ind_s > muDoubleScalarFloor(ind_s))) {
          q = muDoubleScalarAbs((1.0 + (real_T)ni) / ind_s);
          rEQ0 = (muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) <=
                  2.2204460492503131E-16 * q);
        }

        if (rEQ0) {
          r = ind_s * 0.0;
        } else {
          if (ind_s < 0.0) {
            r += ind_s;
          }
        }
      }
    } else {
      if (ind_s != 0.0) {
        r = rtNaN;
      }
    }

    if (r == 0.0) {
      ind_s = muDoubleScalarRound((1.0 + (real_T)ni) * Temp->Par.dt /
        Temp->Par.s_t);
      if (1.0 > Temp->Space.N) {
        loop_ub = 0;
      } else {
        if (Temp->Space.N != (int32_T)muDoubleScalarFloor(Temp->Space.N)) {
          emlrtIntegerCheckR2012b(Temp->Space.N, &emlrtDCI, sp);
        }

        loop_ub = (int32_T)Temp->Space.N;
        if ((loop_ub < 1) || (loop_ub > 64)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 64, &g_emlrtBCI, sp);
        }
      }

      i1 = (int32_T)ind_s;
      if (ind_s != i1) {
        emlrtIntegerCheckR2012b(ind_s, &d_emlrtDCI, sp);
      }

      b_i2 = Sol->Psio->size[0];
      if ((i1 < 1) || (i1 > b_i2)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_i2, &j_emlrtBCI, sp);
      }

      i = Sol->Psio->size[1];
      b_i2 = r0->size[0];
      r0->size[0] = i;
      emxEnsureCapacity_int32_T(sp, r0, b_i2, &h_emlrtRTEI);
      for (b_i2 = 0; b_i2 < i; b_i2++) {
        r0->data[b_i2] = b_i2;
      }

      tmp_size[0] = 1;
      tmp_size[1] = loop_ub;
      for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
        if (F_e[b_i2].im == 0.0) {
          tmp_data[b_i2].re = F_e[b_i2].re / Temp->Space.N;
          tmp_data[b_i2].im = 0.0;
        } else if (F_e[b_i2].re == 0.0) {
          tmp_data[b_i2].re = 0.0;
          tmp_data[b_i2].im = F_e[b_i2].im / Temp->Space.N;
        } else {
          tmp_data[b_i2].re = F_e[b_i2].re / Temp->Space.N;
          tmp_data[b_i2].im = F_e[b_i2].im / Temp->Space.N;
        }
      }

      iv0[0] = 1;
      iv0[1] = r0->size[0];
      emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &tmp_size[0], 2, &c_emlrtECI, sp);
      for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
        Sol->Psio->data[(i1 + Sol->Psio->size[0] * r0->data[b_i2]) - 1] =
          tmp_data[b_i2];
      }

      if (Temp->Space.N + 1.0 > d0) {
        b_i2 = 0;
        i3 = 0;
      } else {
        if (Temp->Space.N + 1.0 != (int32_T)muDoubleScalarFloor(Temp->Space.N +
             1.0)) {
          emlrtIntegerCheckR2012b(Temp->Space.N + 1.0, &b_emlrtDCI, sp);
        }

        b_i2 = (int32_T)(Temp->Space.N + 1.0);
        if ((b_i2 < 1) || (b_i2 > 64)) {
          emlrtDynamicBoundsCheckR2012b(b_i2, 1, 64, &h_emlrtBCI, sp);
        }

        b_i2--;
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &c_emlrtDCI, sp);
        }

        i3 = (int32_T)d0;
        if ((i3 < 1) || (i3 > 64)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 64, &i_emlrtBCI, sp);
        }
      }

      i4 = Sol->Psie->size[0];
      if ((i1 < 1) || (i1 > i4)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, i4, &k_emlrtBCI, sp);
      }

      loop_ub = Sol->Psie->size[1];
      i4 = r0->size[0];
      r0->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(sp, r0, i4, &i_emlrtRTEI);
      for (i4 = 0; i4 < loop_ub; i4++) {
        r0->data[i4] = i4;
      }

      tmp_size[0] = 1;
      i = i3 - b_i2;
      tmp_size[1] = i;
      for (i3 = 0; i3 < i; i3++) {
        ind_s = F_e[b_i2 + i3].re;
        q = F_e[b_i2 + i3].im;
        if (q == 0.0) {
          tmp_data[i3].re = ind_s / Temp->Space.N;
          tmp_data[i3].im = 0.0;
        } else if (ind_s == 0.0) {
          tmp_data[i3].re = 0.0;
          tmp_data[i3].im = q / Temp->Space.N;
        } else {
          tmp_data[i3].re = ind_s / Temp->Space.N;
          tmp_data[i3].im = q / Temp->Space.N;
        }
      }

      iv0[0] = 1;
      iv0[1] = r0->size[0];
      emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &tmp_size[0], 2, &d_emlrtECI, sp);
      for (b_i2 = 0; b_i2 < i; b_i2++) {
        Sol->Psie->data[(i1 + Sol->Psie->size[0] * r0->data[b_i2]) - 1] =
          tmp_data[b_i2];
      }

      b_i2 = Sol->t->size[1];
      if ((i1 < 1) || (i1 > b_i2)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_i2, &u_emlrtBCI, sp);
      }

      Sol->t->data[i1 - 1].re = Temp->Par.dt * (1.0 + (real_T)ni);
      b_i2 = Sol->t->size[1];
      if ((i1 < 1) || (i1 > b_i2)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, b_i2, &u_emlrtBCI, sp);
      }

      Sol->t->data[i1 - 1].im = 0.0;

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

  emxFree_int32_T(&r0);
  emxFree_creal_T(&b_d);
  emxFree_cuint8_T(&d);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Chi23OPO_Runge_Kuarong.c) */
