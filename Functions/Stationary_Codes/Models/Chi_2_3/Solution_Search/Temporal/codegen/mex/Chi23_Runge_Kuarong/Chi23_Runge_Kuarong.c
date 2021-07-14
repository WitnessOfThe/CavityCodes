/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi23_Runge_Kuarong.c
 *
 * Code generation for function 'Chi23_Runge_Kuarong'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Chi23_Runge_Kuarong.h"
#include "exp.h"
#include "abs.h"
#include "power.h"
#include "mod.h"
#include "eml_int_forloop_overflow_check.h"
#include "nullAssignment.h"
#include "Chi23_Runge_Kuarong_emxutil.h"
#include "fft1.h"
#include "ifft.h"
#include "Chi23_Runge_Kuarong_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 48,    /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 47,  /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 46,  /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 44,  /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 33,  /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 3,   /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 6,   /* lineNo */
  "ref",                               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/ref.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 63,  /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 77,  /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 99,  /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 100, /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 103, /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 104, /* lineNo */
  "Chi23_Runge_Kuarong",               /* fcnName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 65,  /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 189, /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 16,  /* lineNo */
  "abs",                               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/elfun/abs.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 74, /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 49, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 58, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 9,  /* lineNo */
  "sum",                               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 64, /* lineNo */
  "sumprod",                           /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 134,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 193,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 3,   /* lineNo */
  5,                                   /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 33,/* lineNo */
  61,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 63,/* lineNo */
  13,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 77,/* lineNo */
  18,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 39,/* lineNo */
  29,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 40,/* lineNo */
  29,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 44,/* lineNo */
  33,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "abs",                               /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/elfun/abs.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 58,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 46,/* lineNo */
  30,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 47,/* lineNo */
  30,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 48,/* lineNo */
  27,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 1, /* lineNo */
  20,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 44,/* lineNo */
  29,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 65,/* lineNo */
  27,                                  /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  90,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo cb_emlrtRTEI = { 83,/* lineNo */
  18,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  77,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  77,                                  /* lineNo */
  15,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  77,                                  /* lineNo */
  88,                                  /* colNo */
  "exp_minus_omega",                   /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  77,                                  /* lineNo */
  66,                                  /* colNo */
  "exp_plus_omega",                    /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  105,                                 /* colNo */
  "d",                                 /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo db_emlrtRTEI = { 67,/* lineNo */
  22,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 65,/* lineNo */
  18,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  63,                                  /* lineNo */
  9,                                   /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  63,                                  /* lineNo */
  11,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo fb_emlrtRTEI = { 31,/* lineNo */
  14,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 39,    /* lineNo */
  40,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  39,                                  /* lineNo */
  40,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 40,  /* lineNo */
  38,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  40,                                  /* lineNo */
  38,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 40,  /* lineNo */
  53,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  40,                                  /* lineNo */
  53,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 39,  /* lineNo */
  22,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  39,                                  /* lineNo */
  22,                                  /* colNo */
  "Sol.Psio",                          /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  39,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo k_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  40,                                  /* lineNo */
  22,                                  /* colNo */
  "Sol.Psie",                          /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  40,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m"/* pName */
};

static emlrtBCInfo l_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  42,                                  /* colNo */
  "Sol.Psio",                          /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  48,                                  /* colNo */
  "Sol.Psio",                          /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  44,                                  /* lineNo */
  50,                                  /* colNo */
  "Sol.Psio",                          /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 3,   /* lineNo */
  43,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 3,   /* lineNo */
  43,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 25,  /* lineNo */
  30,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 25,  /* lineNo */
  30,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 25,  /* lineNo */
  42,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 25,  /* lineNo */
  42,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 26,  /* lineNo */
  30,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 26,  /* lineNo */
  42,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 28,  /* lineNo */
  32,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 3,   /* lineNo */
  5,                                   /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 3,   /* lineNo */
  5,                                   /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 25,  /* lineNo */
  5,                                   /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 26,  /* lineNo */
  5,                                   /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 28,  /* lineNo */
  5,                                   /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  85,                                  /* lineNo */
  17,                                  /* colNo */
  "Runge.c",                           /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  69,                                  /* lineNo */
  20,                                  /* colNo */
  "Runge.b",                           /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  93,                                  /* lineNo */
  12,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 93,  /* lineNo */
  12,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  87,                                  /* lineNo */
  50,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 87,  /* lineNo */
  50,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  93,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 87,  /* lineNo */
  93,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  71,                                  /* lineNo */
  62,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 71,  /* lineNo */
  62,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  108,                                 /* colNo */
  "d",                                 /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 71,  /* lineNo */
  108,                                 /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  87,                                  /* lineNo */
  17,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = { 87, /* lineNo */
  17,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  71,                                  /* lineNo */
  21,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 71, /* lineNo */
  21,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  42,                                  /* lineNo */
  13,                                  /* colNo */
  "Sol.t",                             /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  93,                                  /* lineNo */
  38,                                  /* colNo */
  "shift_back",                        /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 93, /* lineNo */
  38,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { 1,  /* iFirst */
  256,                                 /* iLast */
  93,                                  /* lineNo */
  38,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = { 1,  /* iFirst */
  256,                                 /* iLast */
  33,                                  /* lineNo */
  9,                                   /* colNo */
  "E_f",                               /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = { 33, /* lineNo */
  9,                                   /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { 1,  /* iFirst */
  256,                                 /* iLast */
  87,                                  /* lineNo */
  46,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = { 87, /* lineNo */
  46,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  87,                                  /* lineNo */
  46,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { 1,  /* iFirst */
  256,                                 /* iLast */
  71,                                  /* lineNo */
  55,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = { 71, /* lineNo */
  55,                                  /* colNo */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  71,                                  /* lineNo */
  55,                                  /* colNo */
  "d",                                 /* aName */
  "Chi23_Runge_Kuarong",               /* fName */
  "/home/dp710/GitHub/CavityCodes/Functions/Stationary_Codes/Models/Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void Chi23_Runge_Kuarong(const emlrtStack *sp, const struct0_T *Temp, const
  struct5_T *Runge, struct6_T *Sol)
{
  emxArray_cuint8_T *d;
  boolean_T b0;
  boolean_T b1;
  int32_T i0;
  real_T d0;
  int32_T loop_ub;
  real_T dt;
  real_T nt;
  int32_T nx;
  real_T b_Runge;
  int32_T k;
  creal_T shift_back_contents[256];
  real_T re_tmp;
  creal_T F_e[256];
  real_T ind_s;
  real_T re;
  real_T im;
  real_T r;
  creal_T exp_minus_omega_contents[768];
  creal_T exp_plus_omega_contents[768];
  int32_T ni;
  emxArray_creal_T *b_d;
  emxArray_int32_T *r0;
  emxArray_creal_T *x;
  emxArray_real_T *a;
  emxArray_real_T *z1;
  emxArray_int32_T *r1;
  emxArray_creal_T *b_Sol;
  boolean_T exitg1;
  creal_T E_temp[256];
  int32_T iv0[2];
  int32_T iv1[2];
  creal_T b_F_e[128];
  creal_T Psio[128];
  creal_T Psie[128];
  creal_T k_e[256];
  real_T dv0[128];
  real_T dv1[128];
  real_T dv2[128];
  real_T dv3[128];
  creal_T dcv0[128];
  real_T dv4[128];
  real_T dv5[128];
  int32_T i2;
  int32_T i1;
  int32_T b_i2;
  int32_T c_d;
  boolean_T guard1 = false;
  int32_T iv2[2];
  int32_T tmp_size[2];
  creal_T tmp_data[256];
  real_T dv6[128];
  real_T dv7[128];
  real_T dv8[128];
  real_T dv9[128];
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_cuint8_T(sp, &d, 2, &emlrtRTEI, true);
  b0 = false;
  b1 = false;
  st.site = &f_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  st.site = &f_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  st.site = &f_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  st.site = &f_emlrtRSI;
  b_st.site = &g_emlrtRSI;
  st.site = &f_emlrtRSI;
  b_st.site = &g_emlrtRSI;
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
  nt = Temp->Par.T / Temp->Par.dt;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (nx = 0; nx < 3; nx++) {
    b_Runge = Runge->a[nx];
    for (k = 0; k < 256; k++) {
      re_tmp = 0.0 * Temp->Eq.L[k].re;
      ind_s = 0.0 * Temp->Eq.L[k].im;
      re = dt * (b_Runge * (re_tmp - (-Temp->Eq.L[k].im)));
      im = dt * (b_Runge * (ind_s + -Temp->Eq.L[k].re));
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

      i0 = nx + 3 * k;
      exp_minus_omega_contents[i0].re = re;
      exp_minus_omega_contents[i0].im = im;
      re = dt * (b_Runge * (re_tmp - Temp->Eq.L[k].im));
      im = dt * (b_Runge * (ind_s + Temp->Eq.L[k].re));
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

      exp_plus_omega_contents[i0].re = re;
      exp_plus_omega_contents[i0].im = im;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  for (i0 = 0; i0 < 256; i0++) {
    shift_back_contents[i0].re = Temp->Par.dt * (0.0 * Temp->Eq.L[i0].re -
      (-Temp->Eq.L[i0].im));
    shift_back_contents[i0].im = Temp->Par.dt * (0.0 * Temp->Eq.L[i0].im +
      -Temp->Eq.L[i0].re);
  }

  b_exp(shift_back_contents);

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  memcpy(&F_e[0], &Temp->In.Psi_Start[0], sizeof(creal_T) << 8);
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

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nt, mxDOUBLE_CLASS, (int32_T)nt,
    &fb_emlrtRTEI, sp);
  ni = 0;
  emxInit_creal_T(sp, &b_d, 2, &e_emlrtRTEI, true);
  emxInit_int32_T(sp, &r0, 1, &p_emlrtRTEI, true);
  emxInit_creal_T(sp, &x, 2, &j_emlrtRTEI, true);
  emxInit_real_T(sp, &a, 2, &q_emlrtRTEI, true);
  emxInit_real_T(sp, &z1, 2, &r_emlrtRTEI, true);
  emxInit_int32_T(sp, &r1, 2, &m_emlrtRTEI, true);
  emxInit_creal_T(sp, &b_Sol, 2, &j_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (ni <= (int32_T)nt - 1)) {
    st.site = &e_emlrtRSI;
    i0 = b_d->size[0] * b_d->size[1];
    b_d->size[0] = d->size[0];
    b_d->size[1] = d->size[1];
    emxEnsureCapacity_creal_T(&st, b_d, i0, &e_emlrtRTEI);
    loop_ub = d->size[0] * d->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      nx = d->data[i0].re;
      k = d->data[i0].im;
      b_d->data[i0].re = nx;
      b_d->data[i0].im = k;
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    memcpy(&E_temp[0], &F_e[0], sizeof(creal_T) << 8);
    i0 = d->size[0];
    if (1 > i0) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &f_emlrtBCI, &st);
    }

    loop_ub = d->size[1];
    i0 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(&st, r0, i0, &f_emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      r0->data[i0] = i0;
    }

    iv0[0] = 1;
    iv0[1] = r0->size[0];
    if (!b1) {
      iv1[0] = 1;
      iv1[1] = 256;
      b1 = true;
    }

    emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &iv1[0], 2, &b_emlrtECI, &st);
    b_st.site = &h_emlrtRSI;
    for (i0 = 0; i0 < 128; i0++) {
      b_F_e[i0].re = F_e[i0].re * exp_minus_omega_contents[3 * i0].re - F_e[i0].
        im * exp_minus_omega_contents[3 * i0].im;
      b_F_e[i0].im = F_e[i0].re * exp_minus_omega_contents[3 * i0].im + F_e[i0].
        im * exp_minus_omega_contents[3 * i0].re;
    }

    c_st.site = &j_emlrtRSI;
    ifft(b_F_e, Psio);
    for (i0 = 0; i0 < 128; i0++) {
      b_F_e[i0].re = F_e[128 + i0].re * exp_minus_omega_contents[3 * (128 + i0)]
        .re - F_e[128 + i0].im * exp_minus_omega_contents[3 * (128 + i0)].im;
      b_F_e[i0].im = F_e[128 + i0].re * exp_minus_omega_contents[3 * (128 + i0)]
        .im + F_e[128 + i0].im * exp_minus_omega_contents[3 * (128 + i0)].re;
    }

    c_st.site = &k_emlrtRSI;
    ifft(b_F_e, Psie);
    memset(&k_e[0], 0, sizeof(creal_T) << 8);
    b_abs(Psio, dv0);
    power(dv0, dv1);
    b_abs(Psie, dv2);
    power(dv2, dv3);
    for (i0 = 0; i0 < 128; i0++) {
      b_Runge = Temp->Eq.gam2o * Psio[i0].re;
      re_tmp = Temp->Eq.gam2o * -Psio[i0].im;
      b_F_e[i0].re = (b_Runge * Psie[i0].re - re_tmp * Psie[i0].im) +
        Temp->Eq.gam3o * (dv1[i0] + 2.0 * dv3[i0]) * Psio[i0].re;
      b_F_e[i0].im = (b_Runge * Psie[i0].im + re_tmp * Psie[i0].re) +
        Temp->Eq.gam3o * (dv1[i0] + 2.0 * dv3[i0]) * Psio[i0].im;
    }

    c_st.site = &l_emlrtRSI;
    fft(b_F_e, dcv0);
    for (i0 = 0; i0 < 128; i0++) {
      re = 0.0 * exp_plus_omega_contents[3 * i0].re - exp_plus_omega_contents[3 *
        i0].im;
      im = 0.0 * exp_plus_omega_contents[3 * i0].im + exp_plus_omega_contents[3 *
        i0].re;
      k_e[i0].re = re * dcv0[i0].re - im * dcv0[i0].im;
      k_e[i0].im = re * dcv0[i0].im + im * dcv0[i0].re;
    }

    b_power(Psio, dcv0);
    b_abs(Psio, dv4);
    power(dv4, dv1);
    b_abs(Psie, dv5);
    power(dv5, dv3);
    for (i0 = 0; i0 < 128; i0++) {
      b_F_e[i0].re = Temp->Eq.gam2e * dcv0[i0].re + Temp->Eq.gam3e * (2.0 *
        dv1[i0] + dv3[i0]) * Psie[i0].re;
      b_F_e[i0].im = Temp->Eq.gam2e * dcv0[i0].im + Temp->Eq.gam3e * (2.0 *
        dv1[i0] + dv3[i0]) * Psie[i0].im;
    }

    c_st.site = &m_emlrtRSI;
    fft(b_F_e, dcv0);
    for (i0 = 0; i0 < 128; i0++) {
      re = 0.0 * exp_plus_omega_contents[3 * (128 + i0)].re -
        exp_plus_omega_contents[3 * (128 + i0)].im;
      im = 0.0 * exp_plus_omega_contents[3 * (128 + i0)].im +
        exp_plus_omega_contents[3 * (128 + i0)].re;
      k_e[128 + i0].re = re * dcv0[i0].re - im * dcv0[i0].im;
      k_e[128 + i0].im = re * dcv0[i0].im + im * dcv0[i0].re;
    }

    b_Runge = 128.0 * exp_plus_omega_contents[0].re;
    re_tmp = 128.0 * exp_plus_omega_contents[0].im;
    if (re_tmp == 0.0) {
      re = b_Runge / 2.0;
      im = 0.0;
    } else if (b_Runge == 0.0) {
      re = 0.0;
      im = re_tmp / 2.0;
    } else {
      re = b_Runge / 2.0;
      im = re_tmp / 2.0;
    }

    k_e[0].re += Temp->Eq.ko * re * Temp->Eq.H_f;
    k_e[0].im += Temp->Eq.ko * im * Temp->Eq.H_f;
    nx = r0->size[0];
    for (i0 = 0; i0 < nx; i0++) {
      b_d->data[b_d->size[0] * r0->data[i0]] = k_e[i0];
    }

    i0 = (int32_T)(Runge->s + -1.0);
    emlrtForLoopVectorCheckR2012b(2.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      (Runge->s + -1.0), &eb_emlrtRTEI, &st);
    for (i2 = 0; i2 < i0; i2++) {
      i1 = (int32_T)(Runge->s - 1.0);
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
        (int32_T)(Runge->s - 1.0), &db_emlrtRTEI, &st);
      for (k = 0; k < i1; k++) {
        b_i2 = (int32_T)(2U + i2);
        if ((b_i2 < 1) || (b_i2 > 3)) {
          emlrtDynamicBoundsCheckR2012b(b_i2, 1, 3, &p_emlrtBCI, &st);
        }

        loop_ub = (int32_T)(1U + k);
        if ((loop_ub < 1) || (loop_ub > 3)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 3, &p_emlrtBCI, &st);
        }

        if (Runge->b[(b_i2 + 3 * (loop_ub - 1)) - 1] != 0.0) {
          b_Runge = dt * Runge->b[(i2 + 3 * k) + 1];
          c_d = b_d->size[1];
          b_i2 = b_d->size[0];
          if ((loop_ub < 1) || (loop_ub > b_i2)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, b_i2, &e_emlrtBCI, &st);
          }

          for (b_i2 = 0; b_i2 < 256; b_i2++) {
            re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[b_i2]);
            if (Temp->Eq.mode_range[b_i2] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &fb_emlrtDCI,
                &st);
            }

            nx = (int32_T)Temp->Eq.mode_range[b_i2];
            if ((nx < 1) || (nx > 256)) {
              emlrtDynamicBoundsCheckR2012b(nx, 1, 256, &eb_emlrtBCI, &st);
            }

            if (Temp->Eq.mode_range[b_i2] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &fb_emlrtDCI,
                &st);
            }

            if ((nx < 1) || (nx > c_d)) {
              emlrtDynamicBoundsCheckR2012b(nx, 1, c_d, &fb_emlrtBCI, &st);
            }

            k_e[b_i2].re = E_temp[nx - 1].re + b_Runge * b_d->data[(loop_ub +
              b_d->size[0] * (nx - 1)) - 1].re;
            if (Temp->Eq.mode_range[b_i2] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &x_emlrtDCI,
                &st);
            }

            if ((nx < 1) || (nx > 256)) {
              emlrtDynamicBoundsCheckR2012b(nx, 1, 256, &t_emlrtBCI, &st);
            }

            if (Temp->Eq.mode_range[b_i2] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &y_emlrtDCI,
                &st);
            }

            if ((nx < 1) || (nx > c_d)) {
              emlrtDynamicBoundsCheckR2012b(nx, 1, c_d, &u_emlrtBCI, &st);
            }

            k_e[b_i2].im = E_temp[nx - 1].im + b_Runge * b_d->data[(loop_ub +
              b_d->size[0] * (nx - 1)) - 1].im;
          }

          for (b_i2 = 0; b_i2 < 256; b_i2++) {
            re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[b_i2]);
            if (Temp->Eq.mode_range[b_i2] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &bb_emlrtDCI,
                &st);
            }

            loop_ub = (int32_T)Temp->Eq.mode_range[b_i2];
            if ((loop_ub < 1) || (loop_ub > 256)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 256, &w_emlrtBCI, &st);
            }

            E_temp[loop_ub - 1].re = k_e[b_i2].re;
            if (Temp->Eq.mode_range[b_i2] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &bb_emlrtDCI,
                &st);
            }

            if ((loop_ub < 1) || (loop_ub > 256)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 256, &w_emlrtBCI, &st);
            }

            E_temp[loop_ub - 1].im = k_e[b_i2].im;
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      i1 = b_d->size[0];
      b_i2 = 2 + i2;
      if ((b_i2 < 1) || (b_i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(b_i2, 1, i1, &b_emlrtBCI, &st);
      }

      loop_ub = b_d->size[1];
      i1 = r0->size[0];
      r0->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(&st, r0, i1, &g_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        r0->data[i1] = i1;
      }

      iv0[0] = 1;
      iv0[1] = r0->size[0];
      if (!b0) {
        iv2[0] = 1;
        iv2[1] = 256;
        b0 = true;
      }

      emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &iv2[0], 2, &emlrtECI, &st);
      b_st.site = &i_emlrtRSI;
      i1 = 2 + i2;
      if ((i1 < 1) || (i1 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 3, &d_emlrtBCI, &b_st);
      }

      i1 = 2 + i2;
      if ((i1 < 1) || (i1 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 3, &c_emlrtBCI, &b_st);
      }

      for (i1 = 0; i1 < 128; i1++) {
        b_F_e[i1].re = E_temp[i1].re * exp_minus_omega_contents[(i2 + 3 * i1) +
          1].re - E_temp[i1].im * exp_minus_omega_contents[(i2 + 3 * i1) + 1].im;
        b_F_e[i1].im = E_temp[i1].re * exp_minus_omega_contents[(i2 + 3 * i1) +
          1].im + E_temp[i1].im * exp_minus_omega_contents[(i2 + 3 * i1) + 1].re;
      }

      c_st.site = &j_emlrtRSI;
      ifft(b_F_e, Psio);
      for (i1 = 0; i1 < 128; i1++) {
        b_F_e[i1].re = E_temp[128 + i1].re * exp_minus_omega_contents[(i2 + 3 *
          (128 + i1)) + 1].re - E_temp[128 + i1].im * exp_minus_omega_contents
          [(i2 + 3 * (128 + i1)) + 1].im;
        b_F_e[i1].im = E_temp[128 + i1].re * exp_minus_omega_contents[(i2 + 3 *
          (128 + i1)) + 1].im + E_temp[128 + i1].im * exp_minus_omega_contents
          [(i2 + 3 * (128 + i1)) + 1].re;
      }

      c_st.site = &k_emlrtRSI;
      ifft(b_F_e, Psie);
      memset(&k_e[0], 0, sizeof(creal_T) << 8);
      b_abs(Psio, dv6);
      power(dv6, dv1);
      b_abs(Psie, dv7);
      power(dv7, dv3);
      for (i1 = 0; i1 < 128; i1++) {
        b_Runge = Temp->Eq.gam2o * Psio[i1].re;
        re_tmp = Temp->Eq.gam2o * -Psio[i1].im;
        b_F_e[i1].re = (b_Runge * Psie[i1].re - re_tmp * Psie[i1].im) +
          Temp->Eq.gam3o * (dv1[i1] + 2.0 * dv3[i1]) * Psio[i1].re;
        b_F_e[i1].im = (b_Runge * Psie[i1].im + re_tmp * Psie[i1].re) +
          Temp->Eq.gam3o * (dv1[i1] + 2.0 * dv3[i1]) * Psio[i1].im;
      }

      c_st.site = &l_emlrtRSI;
      fft(b_F_e, dcv0);
      for (i1 = 0; i1 < 128; i1++) {
        re = 0.0 * exp_plus_omega_contents[(i2 + 3 * i1) + 1].re -
          exp_plus_omega_contents[(i2 + 3 * i1) + 1].im;
        im = 0.0 * exp_plus_omega_contents[(i2 + 3 * i1) + 1].im +
          exp_plus_omega_contents[(i2 + 3 * i1) + 1].re;
        k_e[i1].re = re * dcv0[i1].re - im * dcv0[i1].im;
        k_e[i1].im = re * dcv0[i1].im + im * dcv0[i1].re;
      }

      b_power(Psio, dcv0);
      b_abs(Psio, dv8);
      power(dv8, dv1);
      b_abs(Psie, dv9);
      power(dv9, dv3);
      for (i1 = 0; i1 < 128; i1++) {
        b_F_e[i1].re = Temp->Eq.gam2e * dcv0[i1].re + Temp->Eq.gam3e * (2.0 *
          dv1[i1] + dv3[i1]) * Psie[i1].re;
        b_F_e[i1].im = Temp->Eq.gam2e * dcv0[i1].im + Temp->Eq.gam3e * (2.0 *
          dv1[i1] + dv3[i1]) * Psie[i1].im;
      }

      c_st.site = &m_emlrtRSI;
      fft(b_F_e, dcv0);
      for (i1 = 0; i1 < 128; i1++) {
        re = 0.0 * exp_plus_omega_contents[(i2 + 3 * (128 + i1)) + 1].re -
          exp_plus_omega_contents[(i2 + 3 * (128 + i1)) + 1].im;
        im = 0.0 * exp_plus_omega_contents[(i2 + 3 * (128 + i1)) + 1].im +
          exp_plus_omega_contents[(i2 + 3 * (128 + i1)) + 1].re;
        k_e[128 + i1].re = re * dcv0[i1].re - im * dcv0[i1].im;
        k_e[128 + i1].im = re * dcv0[i1].im + im * dcv0[i1].re;
      }

      b_Runge = 128.0 * exp_plus_omega_contents[i2 + 1].re;
      re_tmp = 128.0 * exp_plus_omega_contents[i2 + 1].im;
      if (re_tmp == 0.0) {
        re = b_Runge / 2.0;
        im = 0.0;
      } else if (b_Runge == 0.0) {
        re = 0.0;
        im = re_tmp / 2.0;
      } else {
        re = b_Runge / 2.0;
        im = re_tmp / 2.0;
      }

      k_e[0].re += Temp->Eq.ko * re * Temp->Eq.H_f;
      k_e[0].im += Temp->Eq.ko * im * Temp->Eq.H_f;
      nx = r0->size[0];
      for (i1 = 0; i1 < nx; i1++) {
        b_d->data[(i2 + b_d->size[0] * r0->data[i1]) + 1] = k_e[i1];
      }

      memcpy(&E_temp[0], &F_e[0], sizeof(creal_T) << 8);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    i0 = (int32_T)Runge->s;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      Runge->s, &cb_emlrtRTEI, &st);
    for (nx = 0; nx < i0; nx++) {
      i1 = (int32_T)(1U + nx);
      if ((i1 < 1) || (i1 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 3, &o_emlrtBCI, &st);
      }

      if (Runge->c[i1 - 1] != 0.0) {
        b_Runge = dt * Runge->c[nx];
        c_d = b_d->size[1];
        b_i2 = b_d->size[0];
        if ((i1 < 1) || (i1 > b_i2)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, b_i2, &emlrtBCI, &st);
        }

        for (b_i2 = 0; b_i2 < 256; b_i2++) {
          re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[b_i2]);
          if (Temp->Eq.mode_range[b_i2] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &eb_emlrtDCI, &st);
          }

          loop_ub = (int32_T)Temp->Eq.mode_range[b_i2];
          if ((loop_ub < 1) || (loop_ub > 256)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 256, &cb_emlrtBCI, &st);
          }

          if (Temp->Eq.mode_range[b_i2] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &eb_emlrtDCI, &st);
          }

          if ((loop_ub < 1) || (loop_ub > c_d)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_d, &db_emlrtBCI, &st);
          }

          k_e[b_i2].re = F_e[loop_ub - 1].re + b_Runge * b_d->data[(i1 +
            b_d->size[0] * (loop_ub - 1)) - 1].re;
          if (Temp->Eq.mode_range[b_i2] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &v_emlrtDCI, &st);
          }

          if ((loop_ub < 1) || (loop_ub > 256)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 256, &r_emlrtBCI, &st);
          }

          if (Temp->Eq.mode_range[b_i2] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[b_i2], &w_emlrtDCI, &st);
          }

          if ((loop_ub < 1) || (loop_ub > c_d)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_d, &s_emlrtBCI, &st);
          }

          k_e[b_i2].im = F_e[loop_ub - 1].im + b_Runge * b_d->data[(i1 +
            b_d->size[0] * (loop_ub - 1)) - 1].im;
        }

        for (i1 = 0; i1 < 256; i1++) {
          re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i1]);
          if (Temp->Eq.mode_range[i1] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &db_emlrtDCI, &st);
          }

          b_i2 = (int32_T)Temp->Eq.mode_range[i1];
          if ((b_i2 < 1) || (b_i2 > 256)) {
            emlrtDynamicBoundsCheckR2012b(b_i2, 1, 256, &bb_emlrtBCI, &st);
          }

          F_e[b_i2 - 1].re = k_e[i1].re;
          if (Temp->Eq.mode_range[i1] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &ab_emlrtDCI, &st);
          }

          if ((b_i2 < 1) || (b_i2 > 256)) {
            emlrtDynamicBoundsCheckR2012b(b_i2, 1, 256, &v_emlrtBCI, &st);
          }

          F_e[b_i2 - 1].im = k_e[i1].im;
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    for (i0 = 0; i0 < 256; i0++) {
      re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i0]);
      if (Temp->Eq.mode_range[i0] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i0], &cb_emlrtDCI, &st);
      }

      i1 = (int32_T)Temp->Eq.mode_range[i0];
      if ((i1 < 1) || (i1 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 256, &y_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i0] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i0], &cb_emlrtDCI, &st);
      }

      if ((i1 < 1) || (i1 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 256, &ab_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i0] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i0], &cb_emlrtDCI, &st);
      }

      if ((i1 < 1) || (i1 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 256, &y_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i0] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i0], &cb_emlrtDCI, &st);
      }

      if ((i1 < 1) || (i1 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 256, &ab_emlrtBCI, &st);
      }

      E_temp[i0].re = shift_back_contents[i1 - 1].re * F_e[i1 - 1].re -
        shift_back_contents[i1 - 1].im * F_e[i1 - 1].im;
      if (Temp->Eq.mode_range[i0] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i0], &cb_emlrtDCI, &st);
      }

      if ((i1 < 1) || (i1 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 256, &y_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i0] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i0], &cb_emlrtDCI, &st);
      }

      if ((i1 < 1) || (i1 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 256, &ab_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i0] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i0], &cb_emlrtDCI, &st);
      }

      if ((i1 < 1) || (i1 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 256, &y_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i0] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i0], &cb_emlrtDCI, &st);
      }

      if ((i1 < 1) || (i1 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 256, &ab_emlrtBCI, &st);
      }

      E_temp[i0].im = shift_back_contents[i1 - 1].re * F_e[i1 - 1].im +
        shift_back_contents[i1 - 1].im * F_e[i1 - 1].re;
    }

    for (i0 = 0; i0 < 256; i0++) {
      re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i0]);
      if (Temp->Eq.mode_range[i0] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i0], &db_emlrtDCI, &st);
      }

      i1 = (int32_T)Temp->Eq.mode_range[i0];
      if ((i1 < 1) || (i1 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 256, &bb_emlrtBCI, &st);
      }

      F_e[i1 - 1].re = E_temp[i0].re;
      if (Temp->Eq.mode_range[i0] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i0], &u_emlrtDCI, &st);
      }

      if ((i1 < 1) || (i1 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, 256, &q_emlrtBCI, &st);
      }

      F_e[i1 - 1].im = E_temp[i0].im;
    }

    /* ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back */
    guard1 = false;
    if (b_mod(1.0 + (real_T)ni, Temp->Par.s_t / Temp->Par.dt) == 0.0) {
      ind_s = muDoubleScalarRound((1.0 + (real_T)ni) * Temp->Par.dt /
        Temp->Par.s_t);
      if (1.0 > Temp->Space.N) {
        loop_ub = 0;
      } else {
        if (Temp->Space.N != (int32_T)muDoubleScalarFloor(Temp->Space.N)) {
          emlrtIntegerCheckR2012b(Temp->Space.N, &emlrtDCI, sp);
        }

        loop_ub = (int32_T)Temp->Space.N;
        if ((loop_ub < 1) || (loop_ub > 256)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 256, &g_emlrtBCI, sp);
        }
      }

      c_d = (int32_T)ind_s;
      if (ind_s != c_d) {
        emlrtIntegerCheckR2012b(ind_s, &d_emlrtDCI, sp);
      }

      i0 = Sol->Psio->size[0];
      if ((c_d < 1) || (c_d > i0)) {
        emlrtDynamicBoundsCheckR2012b(c_d, 1, i0, &j_emlrtBCI, sp);
      }

      nx = Sol->Psio->size[1];
      i0 = r0->size[0];
      r0->size[0] = nx;
      emxEnsureCapacity_int32_T(sp, r0, i0, &h_emlrtRTEI);
      for (i0 = 0; i0 < nx; i0++) {
        r0->data[i0] = i0;
      }

      tmp_size[0] = 1;
      tmp_size[1] = loop_ub;
      for (i0 = 0; i0 < loop_ub; i0++) {
        if (F_e[i0].im == 0.0) {
          tmp_data[i0].re = F_e[i0].re / Temp->Space.N;
          tmp_data[i0].im = 0.0;
        } else if (F_e[i0].re == 0.0) {
          tmp_data[i0].re = 0.0;
          tmp_data[i0].im = F_e[i0].im / Temp->Space.N;
        } else {
          tmp_data[i0].re = F_e[i0].re / Temp->Space.N;
          tmp_data[i0].im = F_e[i0].im / Temp->Space.N;
        }
      }

      iv0[0] = 1;
      iv0[1] = r0->size[0];
      emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &tmp_size[0], 2, &c_emlrtECI, sp);
      for (i0 = 0; i0 < loop_ub; i0++) {
        Sol->Psio->data[(c_d + Sol->Psio->size[0] * r0->data[i0]) - 1] =
          tmp_data[i0];
      }

      if (Temp->Space.N + 1.0 > d0) {
        i0 = 0;
        i1 = 0;
      } else {
        if (Temp->Space.N + 1.0 != (int32_T)muDoubleScalarFloor(Temp->Space.N +
             1.0)) {
          emlrtIntegerCheckR2012b(Temp->Space.N + 1.0, &b_emlrtDCI, sp);
        }

        i0 = (int32_T)(Temp->Space.N + 1.0);
        if ((i0 < 1) || (i0 > 256)) {
          emlrtDynamicBoundsCheckR2012b(i0, 1, 256, &h_emlrtBCI, sp);
        }

        i0--;
        if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
          emlrtIntegerCheckR2012b(d0, &c_emlrtDCI, sp);
        }

        i1 = (int32_T)d0;
        if ((i1 < 1) || (i1 > 256)) {
          emlrtDynamicBoundsCheckR2012b(i1, 1, 256, &i_emlrtBCI, sp);
        }
      }

      b_i2 = Sol->Psie->size[0];
      if ((c_d < 1) || (c_d > b_i2)) {
        emlrtDynamicBoundsCheckR2012b(c_d, 1, b_i2, &k_emlrtBCI, sp);
      }

      loop_ub = Sol->Psie->size[1];
      b_i2 = r0->size[0];
      r0->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(sp, r0, b_i2, &i_emlrtRTEI);
      for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
        r0->data[b_i2] = b_i2;
      }

      tmp_size[0] = 1;
      nx = i1 - i0;
      tmp_size[1] = nx;
      for (i1 = 0; i1 < nx; i1++) {
        b_Runge = F_e[i0 + i1].re;
        re_tmp = F_e[i0 + i1].im;
        if (re_tmp == 0.0) {
          tmp_data[i1].re = b_Runge / Temp->Space.N;
          tmp_data[i1].im = 0.0;
        } else if (b_Runge == 0.0) {
          tmp_data[i1].re = 0.0;
          tmp_data[i1].im = re_tmp / Temp->Space.N;
        } else {
          tmp_data[i1].re = b_Runge / Temp->Space.N;
          tmp_data[i1].im = re_tmp / Temp->Space.N;
        }
      }

      iv0[0] = 1;
      iv0[1] = r0->size[0];
      emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &tmp_size[0], 2, &d_emlrtECI, sp);
      for (i0 = 0; i0 < nx; i0++) {
        Sol->Psie->data[(c_d + Sol->Psie->size[0] * r0->data[i0]) - 1] =
          tmp_data[i0];
      }

      i0 = Sol->t->size[1];
      if ((c_d < 1) || (c_d > i0)) {
        emlrtDynamicBoundsCheckR2012b(c_d, 1, i0, &x_emlrtBCI, sp);
      }

      Sol->t->data[c_d - 1].re = Temp->Par.dt * (1.0 + (real_T)ni);
      i0 = Sol->t->size[1];
      if ((c_d < 1) || (c_d > i0)) {
        emlrtDynamicBoundsCheckR2012b(c_d, 1, i0, &x_emlrtBCI, sp);
      }

      Sol->t->data[c_d - 1].im = 0.0;
      if (2 > Sol->Psio->size[1]) {
        i0 = 1;
        i1 = 1;
      } else {
        i0 = Sol->Psio->size[1];
        if (2 > i0) {
          emlrtDynamicBoundsCheckR2012b(2, 1, i0, &m_emlrtBCI, sp);
        }

        i0 = 2;
        i1 = Sol->Psio->size[1];
        b_i2 = Sol->Psio->size[1];
        if ((b_i2 < 1) || (b_i2 > i1)) {
          emlrtDynamicBoundsCheckR2012b(b_i2, 1, i1, &n_emlrtBCI, sp);
        }

        i1 = b_i2 + 1;
      }

      st.site = &d_emlrtRSI;
      b_i2 = Sol->Psio->size[0];
      if ((c_d < 1) || (c_d > b_i2)) {
        emlrtDynamicBoundsCheckR2012b(c_d, 1, b_i2, &l_emlrtBCI, &st);
      }

      b_i2 = x->size[0] * x->size[1];
      x->size[0] = 1;
      loop_ub = i1 - i0;
      x->size[1] = loop_ub;
      emxEnsureCapacity_creal_T(&st, x, b_i2, &j_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        x->data[i1] = Sol->Psio->data[(c_d + Sol->Psio->size[0] * ((i0 + i1) - 1))
          - 1];
      }

      b_st.site = &y_emlrtRSI;
      nx = loop_ub - 1;
      i1 = b_Sol->size[0] * b_Sol->size[1];
      b_Sol->size[0] = 1;
      b_Sol->size[1] = loop_ub;
      emxEnsureCapacity_creal_T(&b_st, b_Sol, i1, &j_emlrtRTEI);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_Sol->data[i1] = Sol->Psio->data[(c_d + Sol->Psio->size[0] * ((i0 + i1)
          - 1)) - 1];
      }

      i0 = a->size[0] * a->size[1];
      a->size[0] = 1;
      a->size[1] = b_Sol->size[1];
      emxEnsureCapacity_real_T(&b_st, a, i0, &k_emlrtRTEI);
      c_st.site = &ab_emlrtRSI;
      if ((1 <= loop_ub) && (loop_ub > 2147483646)) {
        d_st.site = &x_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }

      for (k = 0; k <= nx; k++) {
        a->data[k] = muDoubleScalarHypot(x->data[k].re, x->data[k].im);
      }

      st.site = &d_emlrtRSI;
      b_st.site = &bb_emlrtRSI;
      c_st.site = &cb_emlrtRSI;
      i0 = z1->size[0] * z1->size[1];
      z1->size[0] = 1;
      z1->size[1] = a->size[1];
      emxEnsureCapacity_real_T(&c_st, z1, i0, &l_emlrtRTEI);
      d_st.site = &v_emlrtRSI;
      nx = a->size[1];
      e_st.site = &w_emlrtRSI;
      overflow = ((1 <= z1->size[1]) && (z1->size[1] > 2147483646));
      if (overflow) {
        f_st.site = &x_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      for (k = 0; k < nx; k++) {
        z1->data[k] = a->data[k] * a->data[k];
      }

      st.site = &d_emlrtRSI;
      b_st.site = &db_emlrtRSI;
      c_st.site = &eb_emlrtRSI;
      nx = z1->size[1];
      if (z1->size[1] == 0) {
        b_Runge = 0.0;
      } else {
        d_st.site = &fb_emlrtRSI;
        b_Runge = z1->data[0];
        e_st.site = &gb_emlrtRSI;
        overflow = ((2 <= z1->size[1]) && (z1->size[1] > 2147483646));
        if (overflow) {
          f_st.site = &x_emlrtRSI;
          check_forloop_overflow_error(&f_st);
        }

        for (k = 2; k <= nx; k++) {
          b_Runge += z1->data[k - 1];
        }
      }

      st.site = &d_emlrtRSI;
      if ((10.0 * muDoubleScalarLog10(b_Runge) <= -100.0) && (c_mod(ind_s) ==
           0.0)) {
        i0 = Sol->Psio->size[0];
        i1 = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        loop_ub = i0 - c_d;
        r1->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(sp, r1, i1, &m_emlrtRTEI);
        for (i0 = 0; i0 < loop_ub; i0++) {
          r1->data[i0] = (c_d + i0) + 1;
        }

        st.site = &c_emlrtRSI;
        nullAssignment(&st, Sol->Psio, r1);
        i0 = Sol->Psie->size[0];
        i1 = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        loop_ub = i0 - c_d;
        r1->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(sp, r1, i1, &n_emlrtRTEI);
        for (i0 = 0; i0 < loop_ub; i0++) {
          r1->data[i0] = (c_d + i0) + 1;
        }

        st.site = &b_emlrtRSI;
        nullAssignment(&st, Sol->Psie, r1);
        i0 = Sol->t->size[1];
        i1 = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        loop_ub = i0 - c_d;
        r1->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(sp, r1, i1, &o_emlrtRTEI);
        for (i0 = 0; i0 < loop_ub; i0++) {
          r1->data[i0] = (c_d + i0) + 1;
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
  emxFree_int32_T(&r1);
  emxFree_real_T(&z1);
  emxFree_real_T(&a);
  emxFree_creal_T(&x);
  emxFree_int32_T(&r0);
  emxFree_creal_T(&b_d);
  emxFree_cuint8_T(&d);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Chi23_Runge_Kuarong.c) */
