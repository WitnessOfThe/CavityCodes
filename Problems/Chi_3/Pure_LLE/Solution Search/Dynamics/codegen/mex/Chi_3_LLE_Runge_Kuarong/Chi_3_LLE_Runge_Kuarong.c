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
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "Chi_3_LLE_Runge_Kuarong_emxutil.h"
#include "nullAssignment.h"
#include "sum.h"
#include "mod.h"
#include "fft.h"
#include "exp.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 41,    /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 40,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 38,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 31,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 18,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 14,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 13,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 3,   /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 6,   /* lineNo */
  "ref",                               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/ref.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 56,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 70,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 16, /* lineNo */
  "abs",                               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/elfun/abs.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 49, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 58, /* lineNo */
  "power",                             /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 3, /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 8, /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 9, /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 18,/* lineNo */
  18,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 13,/* lineNo */
  27,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 13,/* lineNo */
  32,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 14,/* lineNo */
  27,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 14,/* lineNo */
  32,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 31,/* lineNo */
  61,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 56,/* lineNo */
  46,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 56,/* lineNo */
  66,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 64,/* lineNo */
  62,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 70,/* lineNo */
  51,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 80,/* lineNo */
  72,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 64,/* lineNo */
  84,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 70,/* lineNo */
  72,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 86,/* lineNo */
  16,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 80,/* lineNo */
  21,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 86,/* lineNo */
  38,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 64,/* lineNo */
  55,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 80,/* lineNo */
  46,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 35,/* lineNo */
  28,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 35,/* lineNo */
  33,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 38,/* lineNo */
  33,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "abs",                               /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/elfun/abs.m"/* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 58,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 40,/* lineNo */
  29,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 41,/* lineNo */
  27,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 1,/* lineNo */
  20,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 38,/* lineNo */
  29,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 65,/* lineNo */
  27,                                  /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 94,/* lineNo */
  19,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 88,/* lineNo */
  17,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  86,                                  /* lineNo */
  12,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  80,                                  /* lineNo */
  17,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtECInfo c_emlrtECI = { 2,   /* nDims */
  80,                                  /* lineNo */
  46,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  90,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo tb_emlrtRTEI = { 76,/* lineNo */
  18,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  15,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  70,                                  /* lineNo */
  88,                                  /* colNo */
  "exp_minus_omega",                   /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  70,                                  /* lineNo */
  66,                                  /* colNo */
  "exp_plus_omega",                    /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  64,                                  /* lineNo */
  21,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtECInfo e_emlrtECI = { 2,   /* nDims */
  64,                                  /* lineNo */
  55,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  105,                                 /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo ub_emlrtRTEI = { 60,/* lineNo */
  22,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = { 58,/* lineNo */
  18,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  11,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  13,                                  /* lineNo */
  9,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  14,                                  /* lineNo */
  9,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = { 29,/* lineNo */
  14,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtDCInfo emlrtDCI = { 35,    /* lineNo */
  21,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  21,                                  /* colNo */
  "Sol.Psi",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  35,                                  /* lineNo */
  13,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtBCInfo h_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  41,                                  /* colNo */
  "Sol.Psi",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  47,                                  /* colNo */
  "Sol.Psi",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  38,                                  /* lineNo */
  49,                                  /* colNo */
  "Sol.Psi",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 25,  /* lineNo */
  29,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 25,  /* lineNo */
  29,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 26,  /* lineNo */
  31,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 3,   /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 25,  /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 26,  /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  78,                                  /* lineNo */
  17,                                  /* colNo */
  "Runge.c",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  62,                                  /* lineNo */
  20,                                  /* colNo */
  "Runge.b",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 86,  /* lineNo */
  49,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  86,                                  /* lineNo */
  49,                                  /* colNo */
  "shift_back",                        /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 80,  /* lineNo */
  50,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  80,                                  /* lineNo */
  50,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 86,  /* lineNo */
  74,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  86,                                  /* lineNo */
  74,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 64,  /* lineNo */
  62,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  64,                                  /* lineNo */
  62,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 86,  /* lineNo */
  16,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  86,                                  /* lineNo */
  16,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 80,  /* lineNo */
  21,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  80,                                  /* lineNo */
  21,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 35,  /* lineNo */
  37,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  35,                                  /* lineNo */
  37,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  13,                                  /* colNo */
  "Sol.t",                             /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  80,                                  /* lineNo */
  72,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 80,  /* lineNo */
  72,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  64,                                  /* lineNo */
  84,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 64,  /* lineNo */
  84,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtECInfo i_emlrtECI = { 2,   /* nDims */
  90,                                  /* lineNo */
  47,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtECInfo j_emlrtECI = { 2,   /* nDims */
  94,                                  /* lineNo */
  34,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtECInfo k_emlrtECI = { 2,   /* nDims */
  94,                                  /* lineNo */
  19,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  96,                                  /* lineNo */
  37,                                  /* colNo */
  "Fac_plus",                          /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void Chi_3_LLE_Kuar_ins(const emlrtStack *sp, const creal_T F_Psi[512],
  const emxArray_creal_T *Fac_plus, const emxArray_creal_T *Fac_minus, real_T
  Eq_h, const emxArray_real_T *Eq_gamma_Kerr, creal_T k_e[512]);

/* Function Definitions */
static void Chi_3_LLE_Kuar_ins(const emlrtStack *sp, const creal_T F_Psi[512],
  const emxArray_creal_T *Fac_plus, const emxArray_creal_T *Fac_minus, real_T
  Eq_h, const emxArray_real_T *Eq_gamma_Kerr, creal_T k_e[512])
{
  int32_T iv0[2];
  int32_T b_Fac_minus[2];
  int32_T k;
  creal_T b_F_Psi[512];
  creal_T b_y1[512];
  real_T Fac_plus_re;
  real_T abs_Psi_2[512];
  emxArray_creal_T *r3;
  int32_T loop_ub;
  real_T Fac_plus_im;
  creal_T b_abs_Psi_2[512];
  real_T k_e_re;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  iv0[0] = 1;
  iv0[1] = 512;
  b_Fac_minus[0] = Fac_minus->size[0];
  b_Fac_minus[1] = Fac_minus->size[1];
  if ((1 != b_Fac_minus[0]) || (512 != b_Fac_minus[1])) {
    emlrtSizeEqCheckNDR2012b(&iv0[0], &b_Fac_minus[0], &i_emlrtECI, sp);
  }

  for (k = 0; k < 512; k++) {
    b_F_Psi[k].re = F_Psi[k].re * Fac_minus->data[k].re - F_Psi[k].im *
      Fac_minus->data[k].im;
    b_F_Psi[k].im = F_Psi[k].re * Fac_minus->data[k].im + F_Psi[k].im *
      Fac_minus->data[k].re;
  }

  fft(b_F_Psi, b_y1);
  for (k = 0; k < 512; k++) {
    Fac_plus_re = muDoubleScalarHypot(b_y1[k].re, b_y1[k].im);
    abs_Psi_2[k] = Fac_plus_re * Fac_plus_re;
  }

  b_Fac_minus[0] = Eq_gamma_Kerr->size[0];
  b_Fac_minus[1] = Eq_gamma_Kerr->size[1];
  iv0[0] = 1;
  iv0[1] = 512;
  emxInit_creal_T(sp, &r3, 2, &kb_emlrtRTEI, true);
  if ((b_Fac_minus[0] != 1) || (b_Fac_minus[1] != 512)) {
    emlrtSizeEqCheckNDR2012b(&b_Fac_minus[0], &iv0[0], &j_emlrtECI, sp);
  }

  k = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  r3->size[1] = Fac_plus->size[1];
  emxEnsureCapacity_creal_T(sp, r3, k, &jb_emlrtRTEI);
  loop_ub = Fac_plus->size[0] * Fac_plus->size[1];
  for (k = 0; k < loop_ub; k++) {
    Fac_plus_re = Fac_plus->data[k].re;
    Fac_plus_im = Fac_plus->data[k].im;
    r3->data[k].re = 0.0 * Fac_plus_re - Fac_plus_im;
    r3->data[k].im = 0.0 * Fac_plus_im + Fac_plus_re;
  }

  iv0[0] = r3->size[0];
  iv0[1] = r3->size[1];
  b_Fac_minus[0] = 1;
  b_Fac_minus[1] = 512;
  if ((iv0[0] != 1) || (iv0[1] != 512)) {
    emlrtSizeEqCheckNDR2012b(&iv0[0], &b_Fac_minus[0], &k_emlrtECI, sp);
  }

  for (k = 0; k < 512; k++) {
    b_abs_Psi_2[k].re = abs_Psi_2[k] * b_y1[k].re;
    b_abs_Psi_2[k].im = abs_Psi_2[k] * b_y1[k].im;
  }

  b_fft(b_abs_Psi_2, b_F_Psi);
  memcpy(&k_e[0], &b_F_Psi[0], sizeof(creal_T) << 9);
  for (k = 0; k < 512; k++) {
    Fac_plus_re = Eq_gamma_Kerr->data[k] * k_e[k].re;
    Fac_plus_im = Eq_gamma_Kerr->data[k] * k_e[k].im;
    k_e_re = r3->data[k].re * Fac_plus_re - r3->data[k].im * Fac_plus_im;
    Fac_plus_re = r3->data[k].re * Fac_plus_im + r3->data[k].im * Fac_plus_re;
    k_e[k].re = k_e_re;
    k_e[k].im = Fac_plus_re;
  }

  emxFree_creal_T(&r3);
  k = Fac_plus->size[1];
  if (1 > k) {
    emlrtDynamicBoundsCheckR2012b(1, 1, k, &w_emlrtBCI, sp);
  }

  k_e[0].re += Fac_plus->data[0].re * (512.0 * Eq_h);
  k_e[0].im += Fac_plus->data[0].im * (512.0 * Eq_h);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void Chi_3_LLE_Runge_Kuarong(const emlrtStack *sp, const struct0_T *Temp, real_T
  N_modes, const struct5_T *Runge, struct6_T *Sol)
{
  emxArray_real_T *contents_Eq_gamma_Kerr;
  real_T contents_Par_dt;
  real_T contents_Par_s_t;
  real_T contents_Eq_h;
  int32_T i0;
  int32_T loop_ub;
  emxArray_cuint8_T *d;
  emxArray_creal_T *exp_minus_omega_contents;
  real_T dt;
  real_T nt;
  emxArray_creal_T *exp_plus_omega_contents;
  emxArray_int16_T *r0;
  emxArray_creal_T *r1;
  int32_T loop_ub_tmp;
  int32_T i;
  int16_T i1;
  creal_T F_e[512];
  int32_T b_Temp[2];
  int32_T ni;
  emxArray_creal_T *b_d;
  emxArray_int32_T *r2;
  emxArray_creal_T *x;
  emxArray_real_T *a;
  emxArray_real_T *z1;
  emxArray_creal_T *b_exp_plus_omega_contents;
  emxArray_creal_T *b_exp_minus_omega_contents;
  emxArray_creal_T *E_temp;
  boolean_T exitg1;
  creal_T b_E_temp[512];
  int32_T nx;
  creal_T dcv0[512];
  int32_T i2;
  int32_T i3;
  int32_T i4;
  real_T b_dt;
  int32_T ind_s;
  int32_T c_Temp[2];
  real_T b_ind_s;
  int32_T b_x[2];
  real_T F_e_im;
  boolean_T guard1 = false;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  (void)N_modes;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &contents_Eq_gamma_Kerr, 2, &emlrtRTEI, true);
  contents_Par_dt = Temp->Par.dt;
  contents_Par_s_t = Temp->Par.s_t;
  contents_Eq_h = Temp->Eq.h;
  i0 = contents_Eq_gamma_Kerr->size[0] * contents_Eq_gamma_Kerr->size[1];
  contents_Eq_gamma_Kerr->size[0] = 1;
  contents_Eq_gamma_Kerr->size[1] = Temp->Eq.gamma_Kerr.size[1];
  emxEnsureCapacity_real_T(sp, contents_Eq_gamma_Kerr, i0, &emlrtRTEI);
  loop_ub = Temp->Eq.gamma_Kerr.size[0] * Temp->Eq.gamma_Kerr.size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    contents_Eq_gamma_Kerr->data[i0] = Temp->Eq.gamma_Kerr.data[i0];
  }

  emxInit_cuint8_T(sp, &d, 2, &b_emlrtRTEI, true);
  st.site = &h_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  st.site = &h_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  st.site = &h_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  st.site = &h_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  st.site = &h_emlrtRSI;
  b_st.site = &i_emlrtRSI;
  i0 = d->size[0] * d->size[1];
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &c_emlrtDCI, sp);
  }

  if (Runge->s != (int32_T)muDoubleScalarFloor(Runge->s)) {
    emlrtIntegerCheckR2012b(Runge->s, &b_emlrtDCI, sp);
  }

  d->size[0] = (int32_T)Runge->s;
  d->size[1] = 512;
  emxEnsureCapacity_cuint8_T(sp, d, i0, &b_emlrtRTEI);
  if (Runge->s != (int32_T)muDoubleScalarFloor(Runge->s)) {
    emlrtIntegerCheckR2012b(Runge->s, &g_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Runge->s << 9;
  for (i0 = 0; i0 < loop_ub; i0++) {
    d->data[i0].re = 0U;
    d->data[i0].im = 0U;
  }

  emxInit_creal_T(sp, &exp_minus_omega_contents, 2, &c_emlrtRTEI, true);
  dt = Temp->Par.dt;
  nt = Temp->Par.T / Temp->Par.dt;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  i0 = exp_minus_omega_contents->size[0] * exp_minus_omega_contents->size[1];
  exp_minus_omega_contents->size[0] = 3;
  exp_minus_omega_contents->size[1] = Temp->Eq.L.size[1];
  emxEnsureCapacity_creal_T(sp, exp_minus_omega_contents, i0, &c_emlrtRTEI);
  loop_ub = 3 * Temp->Eq.L.size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    exp_minus_omega_contents->data[i0].re = 0.0;
    exp_minus_omega_contents->data[i0].im = 0.0;
  }

  emxInit_creal_T(sp, &exp_plus_omega_contents, 2, &d_emlrtRTEI, true);
  i0 = exp_plus_omega_contents->size[0] * exp_plus_omega_contents->size[1];
  exp_plus_omega_contents->size[0] = 3;
  exp_plus_omega_contents->size[1] = Temp->Eq.L.size[1];
  emxEnsureCapacity_creal_T(sp, exp_plus_omega_contents, i0, &d_emlrtRTEI);
  loop_ub = 3 * Temp->Eq.L.size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    exp_plus_omega_contents->data[i0].re = 0.0;
    exp_plus_omega_contents->data[i0].im = 0.0;
  }

  emxInit_int16_T(sp, &r0, 1, &gb_emlrtRTEI, true);
  emxInit_creal_T(sp, &r1, 2, &gb_emlrtRTEI, true);
  loop_ub_tmp = Temp->Eq.L.size[0] * Temp->Eq.L.size[1];
  for (i = 0; i < 3; i++) {
    i1 = (int16_T)exp_minus_omega_contents->size[1];
    i0 = r0->size[0];
    r0->size[0] = i1;
    emxEnsureCapacity_int16_T(sp, r0, i0, &f_emlrtRTEI);
    loop_ub = i1 - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
      r0->data[i0] = (int16_T)i0;
    }

    i0 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = Temp->Eq.L.size[1];
    emxEnsureCapacity_creal_T(sp, r1, i0, &g_emlrtRTEI);
    for (i0 = 0; i0 < loop_ub_tmp; i0++) {
      r1->data[i0].re = dt * (Runge->a[i] * (0.0 * Temp->Eq.L.data[i0].re -
        (-Temp->Eq.L.data[i0].im)));
      r1->data[i0].im = dt * (Runge->a[i] * (0.0 * Temp->Eq.L.data[i0].im +
        -Temp->Eq.L.data[i0].re));
    }

    st.site = &g_emlrtRSI;
    b_exp(&st, r1);
    b_Temp[0] = 1;
    b_Temp[1] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(&b_Temp[0], 2, &(*(int32_T (*)[2])r1->size)[0],
      2, &f_emlrtECI, sp);
    loop_ub = r1->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      exp_minus_omega_contents->data[i + 3 * r0->data[i0]] = r1->data[i0];
    }

    i1 = (int16_T)exp_plus_omega_contents->size[1];
    i0 = r0->size[0];
    r0->size[0] = i1;
    emxEnsureCapacity_int16_T(sp, r0, i0, &j_emlrtRTEI);
    loop_ub = i1 - 1;
    for (i0 = 0; i0 <= loop_ub; i0++) {
      r0->data[i0] = (int16_T)i0;
    }

    i0 = r1->size[0] * r1->size[1];
    r1->size[0] = 1;
    r1->size[1] = Temp->Eq.L.size[1];
    emxEnsureCapacity_creal_T(sp, r1, i0, &k_emlrtRTEI);
    for (i0 = 0; i0 < loop_ub_tmp; i0++) {
      r1->data[i0].re = dt * (Runge->a[i] * (0.0 * Temp->Eq.L.data[i0].re -
        Temp->Eq.L.data[i0].im));
      r1->data[i0].im = dt * (Runge->a[i] * (0.0 * Temp->Eq.L.data[i0].im +
        Temp->Eq.L.data[i0].re));
    }

    st.site = &f_emlrtRSI;
    b_exp(&st, r1);
    b_Temp[0] = 1;
    b_Temp[1] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(&b_Temp[0], 2, &(*(int32_T (*)[2])r1->size)[0],
      2, &g_emlrtECI, sp);
    loop_ub = r1->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      exp_plus_omega_contents->data[i + 3 * r0->data[i0]] = r1->data[i0];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  i0 = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  r1->size[1] = Temp->Eq.L.size[1];
  emxEnsureCapacity_creal_T(sp, r1, i0, &e_emlrtRTEI);
  for (i0 = 0; i0 < loop_ub_tmp; i0++) {
    r1->data[i0].re = Temp->Par.dt * (0.0 * Temp->Eq.L.data[i0].re -
      (-Temp->Eq.L.data[i0].im));
    r1->data[i0].im = Temp->Par.dt * (0.0 * Temp->Eq.L.data[i0].im +
      -Temp->Eq.L.data[i0].re);
  }

  st.site = &e_emlrtRSI;
  b_exp(&st, r1);

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  memcpy(&F_e[0], &Temp->In.Psi_Start[0], sizeof(creal_T) << 9);
  i0 = Sol->Psi->size[0] * Sol->Psi->size[1];
  if (!(Temp->Par.dd >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Par.dd, &e_emlrtDCI, sp);
  }

  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &d_emlrtDCI, sp);
  }

  Sol->Psi->size[0] = (int32_T)Temp->Par.dd;
  Sol->Psi->size[1] = Temp->Eq.mode_range.size[1];
  emxEnsureCapacity_creal_T(sp, Sol->Psi, i0, &h_emlrtRTEI);
  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &h_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd * Temp->Eq.mode_range.size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Sol->Psi->data[i0].re = 0.0;
    Sol->Psi->data[i0].im = 0.0;
  }

  i0 = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[0] = 1;
  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &f_emlrtDCI, sp);
  }

  Sol->t->size[1] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->t, i0, &i_emlrtRTEI);
  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &i_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Sol->t->data[i0].re = 0.0;
    Sol->t->data[i0].im = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nt, mxDOUBLE_CLASS, (int32_T)nt,
    &wb_emlrtRTEI, sp);
  ni = 0;
  emxInit_creal_T(sp, &b_d, 2, &l_emlrtRTEI, true);
  emxInit_int32_T(sp, &r2, 2, &o_emlrtRTEI, true);
  emxInit_creal_T(sp, &x, 2, &bb_emlrtRTEI, true);
  emxInit_real_T(sp, &a, 2, &hb_emlrtRTEI, true);
  emxInit_real_T(sp, &z1, 2, &ib_emlrtRTEI, true);
  emxInit_creal_T(sp, &b_exp_plus_omega_contents, 2, &m_emlrtRTEI, true);
  emxInit_creal_T(sp, &b_exp_minus_omega_contents, 2, &n_emlrtRTEI, true);
  emxInit_creal_T(sp, &E_temp, 1, &w_emlrtRTEI, true);
  exitg1 = false;
  while ((!exitg1) && (ni <= (int32_T)nt - 1)) {
    st.site = &d_emlrtRSI;
    i0 = b_d->size[0] * b_d->size[1];
    b_d->size[0] = d->size[0];
    b_d->size[1] = 512;
    emxEnsureCapacity_creal_T(&st, b_d, i0, &l_emlrtRTEI);
    loop_ub = d->size[0] * d->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      i = d->data[i0].re;
      nx = d->data[i0].im;
      b_d->data[i0].re = i;
      b_d->data[i0].im = nx;
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    memcpy(&b_E_temp[0], &F_e[0], sizeof(creal_T) << 9);
    i0 = d->size[0];
    if (1 > i0) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, &f_emlrtBCI, &st);
    }

    loop_ub = exp_plus_omega_contents->size[1];
    i0 = b_exp_plus_omega_contents->size[0] * b_exp_plus_omega_contents->size[1];
    b_exp_plus_omega_contents->size[0] = 1;
    b_exp_plus_omega_contents->size[1] = loop_ub;
    emxEnsureCapacity_creal_T(&st, b_exp_plus_omega_contents, i0, &m_emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_exp_plus_omega_contents->data[i0] = exp_plus_omega_contents->data[3 * i0];
    }

    loop_ub = exp_minus_omega_contents->size[1];
    i0 = b_exp_minus_omega_contents->size[0] * b_exp_minus_omega_contents->size
      [1];
    b_exp_minus_omega_contents->size[0] = 1;
    b_exp_minus_omega_contents->size[1] = loop_ub;
    emxEnsureCapacity_creal_T(&st, b_exp_minus_omega_contents, i0, &n_emlrtRTEI);
    for (i0 = 0; i0 < loop_ub; i0++) {
      b_exp_minus_omega_contents->data[i0] = exp_minus_omega_contents->data[3 *
        i0];
    }

    b_st.site = &m_emlrtRSI;
    Chi_3_LLE_Kuar_ins(&b_st, F_e, b_exp_plus_omega_contents,
                       b_exp_minus_omega_contents, contents_Eq_h,
                       contents_Eq_gamma_Kerr, dcv0);
    for (i0 = 0; i0 < 512; i0++) {
      b_d->data[b_d->size[0] * i0] = dcv0[i0];
    }

    i0 = (int32_T)(Runge->s + -1.0);
    emlrtForLoopVectorCheckR2012b(2.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      (Runge->s + -1.0), &vb_emlrtRTEI, &st);
    for (i = 0; i < i0; i++) {
      i2 = (int32_T)(Runge->s - 1.0);
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
        (int32_T)(Runge->s - 1.0), &ub_emlrtRTEI, &st);
      for (nx = 0; nx < i2; nx++) {
        i3 = (int32_T)(2U + i);
        if ((i3 < 1) || (i3 > 3)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 3, &l_emlrtBCI, &st);
        }

        i4 = (int32_T)(1U + nx);
        if ((i4 < 1) || (i4 > 3)) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, 3, &l_emlrtBCI, &st);
        }

        if (Runge->b[(i3 + 3 * (i4 - 1)) - 1] != 0.0) {
          i3 = r2->size[0] * r2->size[1];
          r2->size[0] = 1;
          r2->size[1] = Temp->Eq.mode_range.size[1];
          emxEnsureCapacity_int32_T(&st, r2, i3, &o_emlrtRTEI);
          loop_ub_tmp = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
          for (i3 = 0; i3 < loop_ub_tmp; i3++) {
            if (Temp->Eq.mode_range.data[i3] != (int32_T)muDoubleScalarFloor
                (Temp->Eq.mode_range.data[i3])) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range.data[i3], &m_emlrtDCI,
                &st);
            }

            ind_s = (int32_T)Temp->Eq.mode_range.data[i3];
            if ((ind_s < 1) || (ind_s > 512)) {
              emlrtDynamicBoundsCheckR2012b(ind_s, 1, 512, &p_emlrtBCI, &st);
            }

            r2->data[i3] = ind_s;
          }

          b_dt = dt * Runge->b[(i + 3 * nx) + 1];
          i3 = b_d->size[0];
          if ((i4 < 1) || (i4 > i3)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &e_emlrtBCI, &st);
          }

          i3 = x->size[0] * x->size[1];
          x->size[0] = 1;
          loop_ub = Temp->Eq.mode_range.size[1];
          x->size[1] = Temp->Eq.mode_range.size[1];
          emxEnsureCapacity_creal_T(&st, x, i3, &r_emlrtRTEI);
          for (i3 = 0; i3 < loop_ub; i3++) {
            b_ind_s = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range.data[i3]);
            if (Temp->Eq.mode_range.data[i3] != b_ind_s) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range.data[i3], &r_emlrtDCI,
                &st);
            }

            ind_s = (int32_T)Temp->Eq.mode_range.data[i3];
            if ((ind_s < 1) || (ind_s > 512)) {
              emlrtDynamicBoundsCheckR2012b(ind_s, 1, 512, &v_emlrtBCI, &st);
            }

            x->data[i3].re = b_dt * b_d->data[(i4 + b_d->size[0] * (ind_s - 1))
              - 1].re;
            if (Temp->Eq.mode_range.data[i3] != b_ind_s) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range.data[i3], &r_emlrtDCI,
                &st);
            }

            if ((ind_s < 1) || (ind_s > 512)) {
              emlrtDynamicBoundsCheckR2012b(ind_s, 1, 512, &v_emlrtBCI, &st);
            }

            x->data[i3].im = b_dt * b_d->data[(i4 + b_d->size[0] * (ind_s - 1))
              - 1].im;
          }

          b_Temp[0] = r2->size[0];
          b_Temp[1] = r2->size[1];
          b_x[0] = x->size[0];
          b_x[1] = x->size[1];
          if ((b_Temp[0] != b_x[0]) || (b_Temp[1] != b_x[1])) {
            emlrtSizeEqCheckNDR2012b(&b_Temp[0], &b_x[0], &e_emlrtECI, &st);
          }

          i3 = r2->size[1];
          i4 = r2->size[1];
          if (i3 != i4) {
            emlrtSubAssignSizeCheck1dR2017a(i3, i4, &d_emlrtECI, &st);
          }

          loop_ub = r2->size[0] * r2->size[1];
          i3 = E_temp->size[0];
          E_temp->size[0] = loop_ub;
          emxEnsureCapacity_creal_T(&st, E_temp, i3, &w_emlrtRTEI);
          for (i3 = 0; i3 < loop_ub; i3++) {
            E_temp->data[i3].re = b_E_temp[r2->data[i3] - 1].re + x->data[i3].re;
            E_temp->data[i3].im = b_E_temp[r2->data[i3] - 1].im + x->data[i3].im;
          }

          loop_ub = E_temp->size[0];
          for (i3 = 0; i3 < loop_ub; i3++) {
            b_E_temp[r2->data[i3] - 1] = E_temp->data[i3];
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      loop_ub = exp_plus_omega_contents->size[1];
      i2 = (int32_T)(2U + i);
      if ((i2 < 1) || (i2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 3, &d_emlrtBCI, &st);
      }

      i2 = b_exp_plus_omega_contents->size[0] * b_exp_plus_omega_contents->size
        [1];
      b_exp_plus_omega_contents->size[0] = 1;
      b_exp_plus_omega_contents->size[1] = loop_ub;
      emxEnsureCapacity_creal_T(&st, b_exp_plus_omega_contents, i2, &p_emlrtRTEI);
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_exp_plus_omega_contents->data[i2] = exp_plus_omega_contents->data[(i +
          3 * i2) + 1];
      }

      loop_ub = exp_minus_omega_contents->size[1];
      i2 = (int32_T)(2U + i);
      if ((i2 < 1) || (i2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 3, &c_emlrtBCI, &st);
      }

      i2 = b_exp_minus_omega_contents->size[0] *
        b_exp_minus_omega_contents->size[1];
      b_exp_minus_omega_contents->size[0] = 1;
      b_exp_minus_omega_contents->size[1] = loop_ub;
      emxEnsureCapacity_creal_T(&st, b_exp_minus_omega_contents, i2,
        &s_emlrtRTEI);
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_exp_minus_omega_contents->data[i2] = exp_minus_omega_contents->data[(i
          + 3 * i2) + 1];
      }

      b_st.site = &n_emlrtRSI;
      Chi_3_LLE_Kuar_ins(&b_st, b_E_temp, b_exp_plus_omega_contents,
                         b_exp_minus_omega_contents, contents_Eq_h,
                         contents_Eq_gamma_Kerr, dcv0);
      i2 = b_d->size[0];
      i3 = (int32_T)(2U + i);
      if ((i3 < 1) || (i3 > i2)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &b_emlrtBCI, &st);
      }

      for (i2 = 0; i2 < 512; i2++) {
        b_d->data[(i + b_d->size[0] * i2) + 1] = dcv0[i2];
      }

      memcpy(&b_E_temp[0], &F_e[0], sizeof(creal_T) << 9);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    i0 = (int32_T)Runge->s;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      Runge->s, &tb_emlrtRTEI, &st);
    for (i = 0; i < i0; i++) {
      i2 = (int32_T)(1U + i);
      if ((i2 < 1) || (i2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 3, &k_emlrtBCI, &st);
      }

      if (Runge->c[i2 - 1] != 0.0) {
        loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
        for (i3 = 0; i3 < loop_ub; i3++) {
          if (Temp->Eq.mode_range.data[i3] != (int32_T)muDoubleScalarFloor
              (Temp->Eq.mode_range.data[i3])) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range.data[i3], &k_emlrtDCI,
              &st);
          }

          i4 = (int32_T)Temp->Eq.mode_range.data[i3];
          if ((i4 < 1) || (i4 > 512)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 512, &n_emlrtBCI, &st);
          }
        }

        b_dt = dt * Runge->c[i];
        i3 = b_d->size[0];
        if ((i2 < 1) || (i2 > i3)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i3, &emlrtBCI, &st);
        }

        i3 = x->size[0] * x->size[1];
        x->size[0] = 1;
        loop_ub = Temp->Eq.mode_range.size[1];
        x->size[1] = Temp->Eq.mode_range.size[1];
        emxEnsureCapacity_creal_T(&st, x, i3, &q_emlrtRTEI);
        for (i3 = 0; i3 < loop_ub; i3++) {
          b_ind_s = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range.data[i3]);
          if (Temp->Eq.mode_range.data[i3] != b_ind_s) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range.data[i3], &q_emlrtDCI,
              &st);
          }

          i4 = (int32_T)Temp->Eq.mode_range.data[i3];
          if ((i4 < 1) || (i4 > 512)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 512, &u_emlrtBCI, &st);
          }

          x->data[i3].re = b_dt * b_d->data[(i2 + b_d->size[0] * (i4 - 1)) - 1].
            re;
          if (Temp->Eq.mode_range.data[i3] != b_ind_s) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range.data[i3], &q_emlrtDCI,
              &st);
          }

          if ((i4 < 1) || (i4 > 512)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 512, &u_emlrtBCI, &st);
          }

          x->data[i3].im = b_dt * b_d->data[(i2 + b_d->size[0] * (i4 - 1)) - 1].
            im;
        }

        c_Temp[0] = Temp->Eq.mode_range.size[0];
        c_Temp[1] = Temp->Eq.mode_range.size[1];
        b_x[0] = x->size[0];
        b_x[1] = x->size[1];
        if ((Temp->Eq.mode_range.size[0] != b_x[0]) || (Temp->
             Eq.mode_range.size[1] != b_x[1])) {
          emlrtSizeEqCheckNDR2012b(&c_Temp[0], &b_x[0], &c_emlrtECI, &st);
        }

        i2 = r2->size[0] * r2->size[1];
        r2->size[0] = 1;
        r2->size[1] = Temp->Eq.mode_range.size[1];
        emxEnsureCapacity_int32_T(&st, r2, i2, &u_emlrtRTEI);
        loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
        for (i2 = 0; i2 < loop_ub; i2++) {
          if (Temp->Eq.mode_range.data[i2] != (int32_T)muDoubleScalarFloor
              (Temp->Eq.mode_range.data[i2])) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range.data[i2], &o_emlrtDCI,
              &st);
          }

          i3 = (int32_T)Temp->Eq.mode_range.data[i2];
          if ((i3 < 1) || (i3 > 512)) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, 512, &r_emlrtBCI, &st);
          }

          r2->data[i2] = i3;
        }

        i2 = r2->size[1];
        if (i2 != Temp->Eq.mode_range.size[1]) {
          emlrtSubAssignSizeCheck1dR2017a(i2, Temp->Eq.mode_range.size[1],
            &b_emlrtECI, &st);
        }

        loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
        i2 = E_temp->size[0];
        E_temp->size[0] = loop_ub;
        emxEnsureCapacity_creal_T(&st, E_temp, i2, &x_emlrtRTEI);
        for (i2 = 0; i2 < loop_ub; i2++) {
          E_temp->data[i2].re = F_e[(int32_T)Temp->Eq.mode_range.data[i2] - 1].
            re + x->data[i2].re;
          E_temp->data[i2].im = F_e[(int32_T)Temp->Eq.mode_range.data[i2] - 1].
            im + x->data[i2].im;
        }

        loop_ub = E_temp->size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          F_e[r2->data[i2] - 1] = E_temp->data[i2];
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    i0 = r1->size[1];
    loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      if (Temp->Eq.mode_range.data[i2] != (int32_T)muDoubleScalarFloor
          (Temp->Eq.mode_range.data[i2])) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range.data[i2], &j_emlrtDCI, &st);
      }

      i3 = (int32_T)Temp->Eq.mode_range.data[i2];
      if ((i3 < 1) || (i3 > i0)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, i0, &m_emlrtBCI, &st);
      }
    }

    loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      if (Temp->Eq.mode_range.data[i0] != (int32_T)muDoubleScalarFloor
          (Temp->Eq.mode_range.data[i0])) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range.data[i0], &l_emlrtDCI, &st);
      }

      i2 = (int32_T)Temp->Eq.mode_range.data[i0];
      if ((i2 < 1) || (i2 > 512)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 512, &o_emlrtBCI, &st);
      }
    }

    i0 = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = Temp->Eq.mode_range.size[1];
    emxEnsureCapacity_int32_T(&st, r2, i0, &t_emlrtRTEI);
    loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      if (Temp->Eq.mode_range.data[i0] != (int32_T)muDoubleScalarFloor
          (Temp->Eq.mode_range.data[i0])) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range.data[i0], &n_emlrtDCI, &st);
      }

      i2 = (int32_T)Temp->Eq.mode_range.data[i0];
      if ((i2 < 1) || (i2 > 512)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 512, &q_emlrtBCI, &st);
      }

      r2->data[i0] = i2;
    }

    i0 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = Temp->Eq.mode_range.size[1];
    emxEnsureCapacity_creal_T(&st, x, i0, &v_emlrtRTEI);
    loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      i = (int32_T)Temp->Eq.mode_range.data[i0] - 1;
      b_dt = r1->data[i].re;
      b_ind_s = r1->data[i].im;
      F_e_im = F_e[(int32_T)Temp->Eq.mode_range.data[i0] - 1].im;
      x->data[i0].re = b_dt * F_e[i].re - b_ind_s * F_e_im;
      x->data[i0].im = b_dt * F_e_im + b_ind_s * F_e[i].re;
    }

    i0 = r2->size[1];
    i2 = x->size[1];
    if (i0 != i2) {
      emlrtSubAssignSizeCheck1dR2017a(i0, i2, &emlrtECI, &st);
    }

    loop_ub = x->size[0] * x->size[1];
    for (i0 = 0; i0 < loop_ub; i0++) {
      F_e[r2->data[i0] - 1] = x->data[i0];
    }

    /* ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back */
    guard1 = false;
    if (b_mod(1.0 + (real_T)ni, contents_Par_s_t / contents_Par_dt) == 0.0) {
      b_ind_s = muDoubleScalarRound((1.0 + (real_T)ni) * contents_Par_dt /
        contents_Par_s_t);
      ind_s = (int32_T)b_ind_s;
      if (b_ind_s != ind_s) {
        emlrtIntegerCheckR2012b(b_ind_s, &emlrtDCI, sp);
      }

      i0 = Sol->Psi->size[0];
      if ((ind_s < 1) || (ind_s > i0)) {
        emlrtDynamicBoundsCheckR2012b(ind_s, 1, i0, &g_emlrtBCI, sp);
      }

      i1 = (int16_T)Sol->Psi->size[1];
      i0 = r0->size[0];
      r0->size[0] = i1;
      emxEnsureCapacity_int16_T(sp, r0, i0, &y_emlrtRTEI);
      loop_ub = i1 - 1;
      for (i0 = 0; i0 <= loop_ub; i0++) {
        r0->data[i0] = (int16_T)i0;
      }

      loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        if (Temp->Eq.mode_range.data[i0] != (int32_T)muDoubleScalarFloor
            (Temp->Eq.mode_range.data[i0])) {
          emlrtIntegerCheckR2012b(Temp->Eq.mode_range.data[i0], &p_emlrtDCI, sp);
        }

        i2 = (int32_T)Temp->Eq.mode_range.data[i0];
        if ((i2 < 1) || (i2 > 512)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, 512, &s_emlrtBCI, sp);
        }
      }

      i0 = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = Temp->Eq.mode_range.size[1];
      emxEnsureCapacity_creal_T(sp, x, i0, &ab_emlrtRTEI);
      loop_ub = Temp->Eq.mode_range.size[0] * Temp->Eq.mode_range.size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        b_dt = F_e[(int32_T)Temp->Eq.mode_range.data[i0] - 1].re;
        F_e_im = F_e[(int32_T)Temp->Eq.mode_range.data[i0] - 1].im;
        if (F_e_im == 0.0) {
          x->data[i0].re = b_dt / Temp->Space.N;
          x->data[i0].im = 0.0;
        } else if (b_dt == 0.0) {
          x->data[i0].re = 0.0;
          x->data[i0].im = F_e_im / Temp->Space.N;
        } else {
          x->data[i0].re = b_dt / Temp->Space.N;
          x->data[i0].im = F_e_im / Temp->Space.N;
        }
      }

      b_Temp[0] = 1;
      b_Temp[1] = r0->size[0];
      emlrtSubAssignSizeCheckR2012b(&b_Temp[0], 2, &(*(int32_T (*)[2])x->size)[0],
        2, &h_emlrtECI, sp);
      loop_ub = x->size[1];
      for (i0 = 0; i0 < loop_ub; i0++) {
        Sol->Psi->data[(ind_s + Sol->Psi->size[0] * r0->data[i0]) - 1] = x->
          data[i0];
      }

      i0 = Sol->t->size[1];
      if ((ind_s < 1) || (ind_s > i0)) {
        emlrtDynamicBoundsCheckR2012b(ind_s, 1, i0, &t_emlrtBCI, sp);
      }

      Sol->t->data[ind_s - 1].re = contents_Par_dt * (1.0 + (real_T)ni);
      i0 = Sol->t->size[1];
      if ((ind_s < 1) || (ind_s > i0)) {
        emlrtDynamicBoundsCheckR2012b(ind_s, 1, i0, &t_emlrtBCI, sp);
      }

      Sol->t->data[ind_s - 1].im = 0.0;
      if (2 > Sol->Psi->size[1]) {
        i0 = 0;
        i3 = 0;
      } else {
        i0 = Sol->Psi->size[1];
        if (2 > i0) {
          emlrtDynamicBoundsCheckR2012b(2, 1, i0, &i_emlrtBCI, sp);
        }

        i0 = 1;
        i2 = Sol->Psi->size[1];
        i3 = Sol->Psi->size[1];
        if ((i3 < 1) || (i3 > i2)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &j_emlrtBCI, sp);
        }
      }

      st.site = &c_emlrtRSI;
      i2 = Sol->Psi->size[0];
      if ((ind_s < 1) || (ind_s > i2)) {
        emlrtDynamicBoundsCheckR2012b(ind_s, 1, i2, &h_emlrtBCI, &st);
      }

      i2 = x->size[0] * x->size[1];
      x->size[0] = 1;
      loop_ub = i3 - i0;
      x->size[1] = loop_ub;
      emxEnsureCapacity_creal_T(&st, x, i2, &bb_emlrtRTEI);
      for (i2 = 0; i2 < loop_ub; i2++) {
        x->data[i2] = Sol->Psi->data[(ind_s + Sol->Psi->size[0] * (i0 + i2)) - 1];
      }

      b_st.site = &bb_emlrtRSI;
      nx = loop_ub - 1;
      i2 = b_exp_plus_omega_contents->size[0] * b_exp_plus_omega_contents->size
        [1];
      b_exp_plus_omega_contents->size[0] = 1;
      b_exp_plus_omega_contents->size[1] = loop_ub;
      emxEnsureCapacity_creal_T(&b_st, b_exp_plus_omega_contents, i2,
        &bb_emlrtRTEI);
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_exp_plus_omega_contents->data[i2] = Sol->Psi->data[(ind_s + Sol->
          Psi->size[0] * (i0 + i2)) - 1];
      }

      i0 = a->size[0] * a->size[1];
      a->size[0] = 1;
      a->size[1] = (int16_T)b_exp_plus_omega_contents->size[1];
      emxEnsureCapacity_real_T(&b_st, a, i0, &cb_emlrtRTEI);
      for (i = 0; i <= nx; i++) {
        a->data[i] = muDoubleScalarHypot(x->data[i].re, x->data[i].im);
      }

      st.site = &c_emlrtRSI;
      b_st.site = &db_emlrtRSI;
      c_st.site = &eb_emlrtRSI;
      i0 = z1->size[0] * z1->size[1];
      z1->size[0] = 1;
      z1->size[1] = (int16_T)a->size[1];
      emxEnsureCapacity_real_T(&c_st, z1, i0, &db_emlrtRTEI);
      nx = (int16_T)a->size[1];
      for (i = 0; i < nx; i++) {
        z1->data[i] = a->data[i] * a->data[i];
      }

      st.site = &c_emlrtRSI;
      b_dt = sum(&st, z1);
      st.site = &c_emlrtRSI;
      b_dt = muDoubleScalarLog10(b_dt);
      if ((10.0 * b_dt <= -50.0) && ((int32_T)muDoubleScalarRem(b_ind_s, 2.0) ==
           0)) {
        i0 = Sol->Psi->size[0];
        i2 = r2->size[0] * r2->size[1];
        r2->size[0] = 1;
        loop_ub = i0 - ind_s;
        r2->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(sp, r2, i2, &eb_emlrtRTEI);
        for (i0 = 0; i0 < loop_ub; i0++) {
          r2->data[i0] = (ind_s + i0) + 1;
        }

        st.site = &b_emlrtRSI;
        nullAssignment(&st, Sol->Psi, r2);
        i0 = Sol->t->size[1];
        i2 = r2->size[0] * r2->size[1];
        r2->size[0] = 1;
        loop_ub = i0 - ind_s;
        r2->size[1] = loop_ub;
        emxEnsureCapacity_int32_T(sp, r2, i2, &fb_emlrtRTEI);
        for (i0 = 0; i0 < loop_ub; i0++) {
          r2->data[i0] = (ind_s + i0) + 1;
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

  emxFree_creal_T(&E_temp);
  emxFree_creal_T(&b_exp_minus_omega_contents);
  emxFree_creal_T(&b_exp_plus_omega_contents);
  emxFree_real_T(&z1);
  emxFree_real_T(&a);
  emxFree_creal_T(&x);
  emxFree_int32_T(&r2);
  emxFree_creal_T(&b_d);
  emxFree_real_T(&contents_Eq_gamma_Kerr);
  emxFree_creal_T(&r1);
  emxFree_int16_T(&r0);
  emxFree_cuint8_T(&d);
  emxFree_creal_T(&exp_minus_omega_contents);
  emxFree_creal_T(&exp_plus_omega_contents);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Chi_3_LLE_Runge_Kuarong.c) */
