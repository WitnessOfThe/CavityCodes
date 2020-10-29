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
#include "ifft.h"
#include "fft1.h"
#include "power.h"
#include "abs.h"
#include "Chi_3_LLE_Runge_Kuarong_emxutil.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 31,    /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 3,   /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 31,/* lineNo */
  61,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtDCInfo emlrtDCI = { 36,    /* lineNo */
  17,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  17,                                  /* colNo */
  "Sol.Psi",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  74,                                  /* lineNo */
  90,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo f_emlrtRTEI = { 70,/* lineNo */
  18,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  15,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  64,                                  /* lineNo */
  88,                                  /* colNo */
  "exp_minus_omega",                   /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  64,                                  /* lineNo */
  66,                                  /* colNo */
  "exp_plus_omega",                    /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  58,                                  /* lineNo */
  105,                                 /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo g_emlrtRTEI = { 54,/* lineNo */
  22,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 52,/* lineNo */
  18,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
};

static emlrtBCInfo g_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  50,                                  /* lineNo */
  11,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo i_emlrtRTEI = { 29,/* lineNo */
  14,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pName */
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

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  72,                                  /* lineNo */
  17,                                  /* colNo */
  "Runge.c",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  56,                                  /* lineNo */
  20,                                  /* colNo */
  "Runge.b",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  80,                                  /* lineNo */
  12,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 80,  /* lineNo */
  12,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  74,                                  /* lineNo */
  50,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 74,  /* lineNo */
  50,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  74,                                  /* lineNo */
  93,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 74,  /* lineNo */
  93,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  58,                                  /* lineNo */
  62,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 58,  /* lineNo */
  62,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  58,                                  /* lineNo */
  108,                                 /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 58,  /* lineNo */
  108,                                 /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  74,                                  /* lineNo */
  17,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 74,  /* lineNo */
  17,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  58,                                  /* lineNo */
  21,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 58,  /* lineNo */
  21,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 36,  /* lineNo */
  61,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  36,                                  /* lineNo */
  61,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  37,                                  /* lineNo */
  9,                                   /* colNo */
  "Sol.t",                             /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 37,  /* lineNo */
  9,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  80,                                  /* lineNo */
  38,                                  /* colNo */
  "shift_back",                        /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 80,  /* lineNo */
  38,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  80,                                  /* lineNo */
  38,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  31,                                  /* lineNo */
  9,                                   /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = { 31,  /* lineNo */
  9,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  74,                                  /* lineNo */
  46,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 74,  /* lineNo */
  46,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  74,                                  /* lineNo */
  46,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  58,                                  /* lineNo */
  55,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = { 58,  /* lineNo */
  55,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { 1,   /* iFirst */
  256,                                 /* iLast */
  58,                                  /* lineNo */
  55,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong",           /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m",                          /* pName */
  0                                    /* checkKind */
};

/* Function Declarations */
static void Chi_3_LLE_Kuar_ins(const creal_T F_Psi[256], const creal_T Fac_plus
  [256], const creal_T Fac_minus[256], real_T Eq_h, const real_T Eq_gamma_Kerr
  [256], creal_T k_e[256]);

/* Function Definitions */
static void Chi_3_LLE_Kuar_ins(const creal_T F_Psi[256], const creal_T Fac_plus
  [256], const creal_T Fac_minus[256], real_T Eq_h, const real_T Eq_gamma_Kerr
  [256], creal_T k_e[256])
{
  int32_T i5;
  creal_T b_F_Psi[256];
  creal_T Psi[256];
  real_T dv0[256];
  real_T dv1[256];
  real_T re;
  real_T im;
  real_T Eq_gamma_Kerr_re;
  real_T Eq_gamma_Kerr_im;
  for (i5 = 0; i5 < 256; i5++) {
    b_F_Psi[i5].re = F_Psi[i5].re * Fac_minus[i5].re - F_Psi[i5].im *
      Fac_minus[i5].im;
    b_F_Psi[i5].im = F_Psi[i5].re * Fac_minus[i5].im + F_Psi[i5].im *
      Fac_minus[i5].re;
  }

  ifft(b_F_Psi, Psi);
  b_abs(Psi, dv0);
  power(dv0, dv1);
  for (i5 = 0; i5 < 256; i5++) {
    b_F_Psi[i5].re = dv1[i5] * Psi[i5].re;
    b_F_Psi[i5].im = dv1[i5] * Psi[i5].im;
  }

  b_fft(b_F_Psi, k_e);
  for (i5 = 0; i5 < 256; i5++) {
    re = 0.0 * Fac_plus[i5].re - Fac_plus[i5].im;
    im = 0.0 * Fac_plus[i5].im + Fac_plus[i5].re;
    Eq_gamma_Kerr_re = Eq_gamma_Kerr[i5] * k_e[i5].re;
    Eq_gamma_Kerr_im = Eq_gamma_Kerr[i5] * k_e[i5].im;
    k_e[i5].re = re * Eq_gamma_Kerr_re - im * Eq_gamma_Kerr_im;
    k_e[i5].im = re * Eq_gamma_Kerr_im + im * Eq_gamma_Kerr_re;
  }

  k_e[0].re += (0.0 * Fac_plus[0].re - Fac_plus[0].im) * (256.0 * Eq_h);
  k_e[0].im += (0.0 * Fac_plus[0].im + Fac_plus[0].re) * (256.0 * Eq_h);
}

void Chi_3_LLE_Runge_Kuarong(const emlrtStack *sp, const struct0_T *Temp, real_T
  N_modes, const struct5_T *Runge, struct6_T *Sol)
{
  emxArray_cuint8_T *d;
  int32_T i0;
  int32_T loop_ub;
  real_T dt;
  real_T nt;
  real_T q;
  int32_T k;
  real_T re;
  real_T re_tmp;
  real_T im;
  real_T im_tmp;
  creal_T y[256];
  real_T r;
  creal_T F_e[256];
  creal_T exp_minus_omega_contents[768];
  creal_T exp_plus_omega_contents[768];
  emxArray_creal_T *b_d;
  int32_T ni;
  int32_T i1;
  creal_T E_temp[256];
  int32_T d_im;
  creal_T b_exp_plus_omega_contents[256];
  creal_T b_exp_minus_omega_contents[256];
  creal_T dcv0[256];
  int32_T i2;
  int32_T i3;
  int32_T i4;
  creal_T b_E_temp[200];
  boolean_T rEQ0;
  emlrtStack st;
  (void)N_modes;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_cuint8_T(sp, &d, 2, &emlrtRTEI, true);
  i0 = d->size[0] * d->size[1];
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &c_emlrtDCI, sp);
  }

  if (Runge->s != (int32_T)muDoubleScalarFloor(Runge->s)) {
    emlrtIntegerCheckR2012b(Runge->s, &b_emlrtDCI, sp);
  }

  d->size[0] = (int32_T)Runge->s;
  d->size[1] = 256;
  emxEnsureCapacity_cuint8_T(sp, d, i0, &emlrtRTEI);
  if (Runge->s != (int32_T)muDoubleScalarFloor(Runge->s)) {
    emlrtIntegerCheckR2012b(Runge->s, &g_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Runge->s << 8;
  for (i0 = 0; i0 < loop_ub; i0++) {
    d->data[i0].re = 0U;
    d->data[i0].im = 0U;
  }

  dt = Temp->Par.dt;
  nt = Temp->Par.T / Temp->Par.dt;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (loop_ub = 0; loop_ub < 3; loop_ub++) {
    q = Runge->a[loop_ub];
    for (k = 0; k < 256; k++) {
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

      i0 = loop_ub + 3 * k;
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
  for (k = 0; k < 256; k++) {
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

    F_e[k] = Temp->In.Psi_Start[k];
  }

  i0 = Sol->Psi->size[0] * Sol->Psi->size[1];
  if (!(Temp->Par.dd >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Par.dd, &e_emlrtDCI, sp);
  }

  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &d_emlrtDCI, sp);
  }

  Sol->Psi->size[0] = (int32_T)Temp->Par.dd;
  Sol->Psi->size[1] = 200;
  emxEnsureCapacity_creal_T(sp, Sol->Psi, i0, &b_emlrtRTEI);
  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &h_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd * 200;
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
  emxEnsureCapacity_creal_T(sp, Sol->t, i0, &c_emlrtRTEI);
  if (Temp->Par.dd != (int32_T)muDoubleScalarFloor(Temp->Par.dd)) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &i_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Sol->t->data[i0].re = 0.0;
    Sol->t->data[i0].im = 0.0;
  }

  i0 = (int32_T)nt;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nt, mxDOUBLE_CLASS, (int32_T)nt,
    &i_emlrtRTEI, sp);
  emxInit_creal_T(sp, &b_d, 2, &d_emlrtRTEI, true);
  for (ni = 0; ni < i0; ni++) {
    st.site = &emlrtRSI;
    i1 = b_d->size[0] * b_d->size[1];
    b_d->size[0] = d->size[0];
    b_d->size[1] = 256;
    emxEnsureCapacity_creal_T(&st, b_d, i1, &d_emlrtRTEI);
    loop_ub = d->size[0] * d->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      k = d->data[i1].re;
      d_im = d->data[i1].im;
      b_d->data[i1].re = k;
      b_d->data[i1].im = d_im;
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    memcpy(&E_temp[0], &F_e[0], sizeof(creal_T) << 8);
    i1 = d->size[0];
    if (1 > i1) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i1, &g_emlrtBCI, &st);
    }

    for (i1 = 0; i1 < 256; i1++) {
      b_exp_plus_omega_contents[i1] = exp_plus_omega_contents[3 * i1];
      b_exp_minus_omega_contents[i1] = exp_minus_omega_contents[3 * i1];
    }

    Chi_3_LLE_Kuar_ins(F_e, b_exp_plus_omega_contents,
                       b_exp_minus_omega_contents, Temp->Eq.h,
                       Temp->Eq.gamma_Kerr, dcv0);
    for (i1 = 0; i1 < 256; i1++) {
      b_d->data[b_d->size[0] * i1] = dcv0[i1];
    }

    i1 = (int32_T)(Runge->s + -1.0);
    emlrtForLoopVectorCheckR2012b(2.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      (Runge->s + -1.0), &h_emlrtRTEI, &st);
    for (k = 0; k < i1; k++) {
      i2 = (int32_T)(Runge->s - 1.0);
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
        (int32_T)(Runge->s - 1.0), &g_emlrtRTEI, &st);
      for (loop_ub = 0; loop_ub < i2; loop_ub++) {
        i3 = (int32_T)(2U + k);
        if ((i3 < 1) || (i3 > 3)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 3, &i_emlrtBCI, &st);
        }

        i4 = (int32_T)(1U + loop_ub);
        if ((i4 < 1) || (i4 > 3)) {
          emlrtDynamicBoundsCheckR2012b(i4, 1, 3, &i_emlrtBCI, &st);
        }

        if (Runge->b[(i3 + 3 * (i4 - 1)) - 1] != 0.0) {
          nt = dt * Runge->b[(k + 3 * loop_ub) + 1];
          i3 = b_d->size[0];
          if ((i4 < 1) || (i4 > i3)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, i3, &f_emlrtBCI, &st);
          }

          for (i3 = 0; i3 < 200; i3++) {
            re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i3]);
            if (Temp->Eq.mode_range[i3] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &v_emlrtDCI, &st);
            }

            d_im = (int32_T)Temp->Eq.mode_range[i3];
            if ((d_im < 1) || (d_im > 256)) {
              emlrtDynamicBoundsCheckR2012b(d_im, 1, 256, &x_emlrtBCI, &st);
            }

            if (Temp->Eq.mode_range[i3] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &v_emlrtDCI, &st);
            }

            if ((d_im < 1) || (d_im > 256)) {
              emlrtDynamicBoundsCheckR2012b(d_im, 1, 256, &y_emlrtBCI, &st);
            }

            b_E_temp[i3].re = E_temp[d_im - 1].re + nt * b_d->data[(i4 +
              b_d->size[0] * (d_im - 1)) - 1].re;
            if (Temp->Eq.mode_range[i3] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &m_emlrtDCI, &st);
            }

            if ((d_im < 1) || (d_im > 256)) {
              emlrtDynamicBoundsCheckR2012b(d_im, 1, 256, &m_emlrtBCI, &st);
            }

            if (Temp->Eq.mode_range[i3] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &n_emlrtDCI, &st);
            }

            if ((d_im < 1) || (d_im > 256)) {
              emlrtDynamicBoundsCheckR2012b(d_im, 1, 256, &n_emlrtBCI, &st);
            }

            b_E_temp[i3].im = E_temp[d_im - 1].im + nt * b_d->data[(i4 +
              b_d->size[0] * (d_im - 1)) - 1].im;
          }

          for (i3 = 0; i3 < 200; i3++) {
            re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i3]);
            if (Temp->Eq.mode_range[i3] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &p_emlrtDCI, &st);
            }

            i4 = (int32_T)Temp->Eq.mode_range[i3];
            if ((i4 < 1) || (i4 > 256)) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, 256, &p_emlrtBCI, &st);
            }

            E_temp[i4 - 1].re = b_E_temp[i3].re;
            if (Temp->Eq.mode_range[i3] != re_tmp) {
              emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &p_emlrtDCI, &st);
            }

            if ((i4 < 1) || (i4 > 256)) {
              emlrtDynamicBoundsCheckR2012b(i4, 1, 256, &p_emlrtBCI, &st);
            }

            E_temp[i4 - 1].im = b_E_temp[i3].im;
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      i2 = (int32_T)(2U + k);
      if ((i2 < 1) || (i2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 3, &e_emlrtBCI, &st);
      }

      for (i2 = 0; i2 < 256; i2++) {
        b_exp_plus_omega_contents[i2] = exp_plus_omega_contents[(k + 3 * i2) + 1];
      }

      i2 = (int32_T)(2U + k);
      if ((i2 < 1) || (i2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 3, &d_emlrtBCI, &st);
      }

      for (i2 = 0; i2 < 256; i2++) {
        b_exp_minus_omega_contents[i2] = exp_minus_omega_contents[(k + 3 * i2) +
          1];
      }

      Chi_3_LLE_Kuar_ins(E_temp, b_exp_plus_omega_contents,
                         b_exp_minus_omega_contents, Temp->Eq.h,
                         Temp->Eq.gamma_Kerr, dcv0);
      i2 = b_d->size[0];
      i3 = (int32_T)(2U + k);
      if ((i3 < 1) || (i3 > i2)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, i2, &c_emlrtBCI, &st);
      }

      for (i2 = 0; i2 < 256; i2++) {
        b_d->data[(k + b_d->size[0] * i2) + 1] = dcv0[i2];
      }

      memcpy(&E_temp[0], &F_e[0], sizeof(creal_T) << 8);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    i1 = (int32_T)Runge->s;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      Runge->s, &f_emlrtRTEI, &st);
    for (k = 0; k < i1; k++) {
      i2 = (int32_T)(1U + k);
      if ((i2 < 1) || (i2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 3, &h_emlrtBCI, &st);
      }

      if (Runge->c[i2 - 1] != 0.0) {
        nt = dt * Runge->c[k];
        i3 = b_d->size[0];
        if ((i2 < 1) || (i2 > i3)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, i3, &b_emlrtBCI, &st);
        }

        for (i3 = 0; i3 < 200; i3++) {
          re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i3]);
          if (Temp->Eq.mode_range[i3] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &u_emlrtDCI, &st);
          }

          i4 = (int32_T)Temp->Eq.mode_range[i3];
          if ((i4 < 1) || (i4 > 256)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 256, &v_emlrtBCI, &st);
          }

          if (Temp->Eq.mode_range[i3] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &u_emlrtDCI, &st);
          }

          if ((i4 < 1) || (i4 > 256)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 256, &w_emlrtBCI, &st);
          }

          b_E_temp[i3].re = F_e[i4 - 1].re + nt * b_d->data[(i2 + b_d->size[0] *
            (i4 - 1)) - 1].re;
          if (Temp->Eq.mode_range[i3] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &k_emlrtDCI, &st);
          }

          if ((i4 < 1) || (i4 > 256)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 256, &k_emlrtBCI, &st);
          }

          if (Temp->Eq.mode_range[i3] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i3], &l_emlrtDCI, &st);
          }

          if ((i4 < 1) || (i4 > 256)) {
            emlrtDynamicBoundsCheckR2012b(i4, 1, 256, &l_emlrtBCI, &st);
          }

          b_E_temp[i3].im = F_e[i4 - 1].im + nt * b_d->data[(i2 + b_d->size[0] *
            (i4 - 1)) - 1].im;
        }

        for (i2 = 0; i2 < 200; i2++) {
          re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i2]);
          if (Temp->Eq.mode_range[i2] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i2], &t_emlrtDCI, &st);
          }

          i3 = (int32_T)Temp->Eq.mode_range[i2];
          if ((i3 < 1) || (i3 > 256)) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, 256, &u_emlrtBCI, &st);
          }

          F_e[i3 - 1].re = b_E_temp[i2].re;
          if (Temp->Eq.mode_range[i2] != re_tmp) {
            emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i2], &o_emlrtDCI, &st);
          }

          if ((i3 < 1) || (i3 > 256)) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, 256, &o_emlrtBCI, &st);
          }

          F_e[i3 - 1].im = b_E_temp[i2].im;
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    for (i1 = 0; i1 < 200; i1++) {
      re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i1]);
      if (Temp->Eq.mode_range[i1] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &s_emlrtDCI, &st);
      }

      i2 = (int32_T)Temp->Eq.mode_range[i1];
      if ((i2 < 1) || (i2 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 256, &s_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &s_emlrtDCI, &st);
      }

      if ((i2 < 1) || (i2 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 256, &t_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &s_emlrtDCI, &st);
      }

      if ((i2 < 1) || (i2 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 256, &s_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &s_emlrtDCI, &st);
      }

      if ((i2 < 1) || (i2 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 256, &t_emlrtBCI, &st);
      }

      b_E_temp[i1].re = y[i2 - 1].re * F_e[i2 - 1].re - y[i2 - 1].im * F_e[i2 -
        1].im;
      if (Temp->Eq.mode_range[i1] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &s_emlrtDCI, &st);
      }

      if ((i2 < 1) || (i2 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 256, &s_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &s_emlrtDCI, &st);
      }

      if ((i2 < 1) || (i2 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 256, &t_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &s_emlrtDCI, &st);
      }

      if ((i2 < 1) || (i2 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 256, &s_emlrtBCI, &st);
      }

      if (Temp->Eq.mode_range[i1] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &s_emlrtDCI, &st);
      }

      if ((i2 < 1) || (i2 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 256, &t_emlrtBCI, &st);
      }

      b_E_temp[i1].im = y[i2 - 1].re * F_e[i2 - 1].im + y[i2 - 1].im * F_e[i2 -
        1].re;
    }

    for (i1 = 0; i1 < 200; i1++) {
      re_tmp = (int32_T)muDoubleScalarFloor(Temp->Eq.mode_range[i1]);
      if (Temp->Eq.mode_range[i1] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &t_emlrtDCI, &st);
      }

      i2 = (int32_T)Temp->Eq.mode_range[i1];
      if ((i2 < 1) || (i2 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 256, &u_emlrtBCI, &st);
      }

      F_e[i2 - 1].re = b_E_temp[i1].re;
      if (Temp->Eq.mode_range[i1] != re_tmp) {
        emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &j_emlrtDCI, &st);
      }

      if ((i2 < 1) || (i2 > 256)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, 256, &j_emlrtBCI, &st);
      }

      F_e[i2 - 1].im = b_E_temp[i1].im;
    }

    /* ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back */
    /*      Temp      =   Temp.Met.Ev_Save(F_e,Temp,ni);                        */
    nt = Temp->Par.s_t / Temp->Par.dt;
    r = 1.0 + (real_T)ni;
    if ((!muDoubleScalarIsInf(nt)) && (!muDoubleScalarIsNaN(nt))) {
      if (nt != 0.0) {
        r = muDoubleScalarRem(1.0 + (real_T)ni, nt);
        rEQ0 = (r == 0.0);
        if ((!rEQ0) && (nt > muDoubleScalarFloor(nt))) {
          q = muDoubleScalarAbs((1.0 + (real_T)ni) / nt);
          rEQ0 = (muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) <=
                  2.2204460492503131E-16 * q);
        }

        if (rEQ0) {
          r = nt * 0.0;
        } else {
          if (nt < 0.0) {
            r += nt;
          }
        }
      }
    } else {
      if (nt != 0.0) {
        r = rtNaN;
      }
    }

    if (r == 0.0) {
      /*    toc      */
      for (i1 = 0; i1 < 200; i1++) {
        if (Temp->Eq.mode_range[i1] != (int32_T)muDoubleScalarFloor
            (Temp->Eq.mode_range[i1])) {
          emlrtIntegerCheckR2012b(Temp->Eq.mode_range[i1], &q_emlrtDCI, sp);
        }

        i2 = (int32_T)Temp->Eq.mode_range[i1];
        if ((i2 < 1) || (i2 > 256)) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, 256, &q_emlrtBCI, sp);
        }
      }

      i1 = Sol->Psi->size[0];
      re_tmp = (1.0 + (real_T)ni) * Temp->Par.dt;
      nt = muDoubleScalarRound(re_tmp / Temp->Par.s_t);
      i2 = (int32_T)nt;
      if (nt != i2) {
        emlrtIntegerCheckR2012b(nt, &emlrtDCI, sp);
      }

      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &emlrtBCI, sp);
      }

      for (i1 = 0; i1 < 200; i1++) {
        nt = F_e[(int32_T)Temp->Eq.mode_range[i1] - 1].re;
        q = F_e[(int32_T)Temp->Eq.mode_range[i1] - 1].im;
        if (q == 0.0) {
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i1) - 1].re = nt /
            Temp->Space.N;
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i1) - 1].im = 0.0;
        } else if (nt == 0.0) {
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i1) - 1].re = 0.0;
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i1) - 1].im = q /
            Temp->Space.N;
        } else {
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i1) - 1].re = nt /
            Temp->Space.N;
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i1) - 1].im = q /
            Temp->Space.N;
        }
      }

      i1 = Sol->t->size[1];
      nt = muDoubleScalarRound(re_tmp / Temp->Par.s_t);
      if (nt != (int32_T)nt) {
        emlrtIntegerCheckR2012b(nt, &r_emlrtDCI, sp);
      }

      i2 = (int32_T)nt;
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &r_emlrtBCI, sp);
      }

      Sol->t->data[i2 - 1].re = Temp->Par.dt * (1.0 + (real_T)ni);
      i1 = Sol->t->size[1];
      re_tmp = muDoubleScalarRound(re_tmp / Temp->Par.s_t);
      if (re_tmp != (int32_T)re_tmp) {
        emlrtIntegerCheckR2012b(re_tmp, &r_emlrtDCI, sp);
      }

      i2 = (int32_T)re_tmp;
      if ((i2 < 1) || (i2 > i1)) {
        emlrtDynamicBoundsCheckR2012b(i2, 1, i1, &r_emlrtBCI, sp);
      }

      Sol->t->data[i2 - 1].im = 0.0;

      /*     tic */
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_creal_T(&b_d);
  emxFree_cuint8_T(&d);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Chi_3_LLE_Runge_Kuarong.c) */
