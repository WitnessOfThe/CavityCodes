/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Split_chi_2.cpp
 *
 * Code generation for function 'Split_chi_2'
 *
 */

/* Include files */
#include <string.h>
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Split_chi_2.h"
#include "ifft.h"
#include "fft.h"
#include "Split_chi_2_emxutil.h"
#include "exp.h"
#include "power.h"
#include "Split_chi_2_data.h"

/* Type Definitions */
typedef struct {
  real_T contents;
} coder_internal_ref;

typedef struct {
  struct1_T contents;
} coder_internal_ref_1;

typedef struct {
  real_T contents[3];
} coder_internal_ref_3;

typedef struct {
  real_T contents[9];
} coder_internal_ref_4;

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 4,     /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 14,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 16,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 17,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 18,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 19,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 49,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 50,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 52,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 54,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 55,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 61,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 84,  /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 98, /* lineNo */
  "Split_chi_2",                       /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 14,  /* lineNo */
  19,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 16,/* lineNo */
  41,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 16,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 17,/* lineNo */
  41,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 17,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 18,/* lineNo */
  41,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 18,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 19,/* lineNo */
  41,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 28,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 33,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 34,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 36,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 37,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = { 71,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = { 74,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 49,/* lineNo */
  30,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 75,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 50,/* lineNo */
  30,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = { 54,/* lineNo */
  30,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 55,/* lineNo */
  30,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 14,/* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 83,/* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 84,/* lineNo */
  13,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 98,/* lineNo */
  17,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 108,/* lineNo */
  46,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = { 92,/* lineNo */
  53,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = { 79,/* lineNo */
  30,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = { 122,/* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = { 123,/* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 126,/* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = { 127,/* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = { 129,/* lineNo */
  56,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = { 129,/* lineNo */
  91,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = { 129,/* lineNo */
  145,                                 /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 129,/* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 130,/* lineNo */
  56,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 130,/* lineNo */
  81,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 130,/* lineNo */
  135,                                 /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 130,/* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 132,/* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 117,/* lineNo */
  18,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo emlrtDCI = { 33,    /* lineNo */
  26,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = { 33,  /* lineNo */
  26,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 34,  /* lineNo */
  26,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 36,  /* lineNo */
  26,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 37,  /* lineNo */
  26,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo ub_emlrtRTEI = { 47,/* lineNo */
  14,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo f_emlrtDCI = { 49,  /* lineNo */
  52,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { 1,     /* iFirst */
  32,                                  /* iLast */
  49,                                  /* lineNo */
  52,                                  /* colNo */
  "L_o",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 49,  /* lineNo */
  72,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  49,                                  /* lineNo */
  72,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo emlrtECI = { 2,     /* nDims */
  49,                                  /* lineNo */
  30,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo h_emlrtDCI = { 49,  /* lineNo */
  14,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  49,                                  /* lineNo */
  14,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  49,                                  /* lineNo */
  8,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo i_emlrtDCI = { 50,  /* lineNo */
  52,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  32,                                  /* iLast */
  50,                                  /* lineNo */
  52,                                  /* colNo */
  "L_e",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 50,  /* lineNo */
  69,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  50,                                  /* lineNo */
  69,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 50,  /* lineNo */
  73,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  50,                                  /* lineNo */
  73,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { 2,   /* nDims */
  50,                                  /* lineNo */
  30,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo l_emlrtDCI = { 50,  /* lineNo */
  13,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  50,                                  /* lineNo */
  13,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 50,  /* lineNo */
  17,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  50,                                  /* lineNo */
  17,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  50,                                  /* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo n_emlrtDCI = { 54,  /* lineNo */
  52,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  32,                                  /* iLast */
  54,                                  /* lineNo */
  52,                                  /* colNo */
  "L_o",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 54,  /* lineNo */
  71,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  54,                                  /* lineNo */
  71,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo e_emlrtECI = { 2,   /* nDims */
  54,                                  /* lineNo */
  30,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo p_emlrtDCI = { 54,  /* lineNo */
  15,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  54,                                  /* lineNo */
  15,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  54,                                  /* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo q_emlrtDCI = { 55,  /* lineNo */
  52,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  32,                                  /* iLast */
  55,                                  /* lineNo */
  52,                                  /* colNo */
  "L_e",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 55,  /* lineNo */
  69,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  55,                                  /* lineNo */
  69,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = { 55,  /* lineNo */
  73,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  55,                                  /* lineNo */
  73,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo g_emlrtECI = { 2,   /* nDims */
  55,                                  /* lineNo */
  30,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo t_emlrtDCI = { 55,  /* lineNo */
  13,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  55,                                  /* lineNo */
  13,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = { 55,  /* lineNo */
  17,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  55,                                  /* lineNo */
  17,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  55,                                  /* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo v_emlrtDCI = { 141, /* lineNo */
  30,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  141,                                 /* lineNo */
  30,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = { 142, /* lineNo */
  28,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  142,                                 /* lineNo */
  28,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = { 142, /* lineNo */
  32,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  142,                                 /* lineNo */
  32,                                  /* colNo */
  "Psi",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  22,                                  /* colNo */
  "Psi_o_s",                           /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  36,                                  /* colNo */
  "Psi_e_s",                           /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = { 25,  /* lineNo */
  34,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = { 25, /* lineNo */
  34,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = { 26, /* lineNo */
  34,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = { 26, /* lineNo */
  34,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = { 28, /* lineNo */
  24,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = { 28, /* lineNo */
  24,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = { 31, /* lineNo */
  62,                                  /* colNo */
  "linspace",                          /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/elmat/linspace.m",/* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo gb_emlrtDCI = { 25, /* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo hb_emlrtDCI = { 25, /* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = { 26, /* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo jb_emlrtDCI = { 26, /* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo kb_emlrtDCI = { 28, /* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo lb_emlrtDCI = { 28, /* lineNo */
  5,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  140,                                 /* lineNo */
  6,                                   /* colNo */
  "t_s",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  14,                                  /* colNo */
  "Psi_o_k",                           /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  61,                                  /* lineNo */
  28,                                  /* colNo */
  "Psi_e_k",                           /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo xb_emlrtRTEI = { 86,/* lineNo */
  17,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = { 88,/* lineNo */
  22,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo mb_emlrtDCI = { 92, /* lineNo */
  46,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = { 1,   /* iFirst */
  64,                                  /* iLast */
  92,                                  /* lineNo */
  46,                                  /* colNo */
  "E_temp",                            /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  84,                                  /* lineNo */
  11,                                  /* colNo */
  "d",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  84,                                  /* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtBCInfo bb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  67,                                  /* colNo */
  "d",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  70,                                  /* colNo */
  "d",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo nb_emlrtDCI = { 92, /* lineNo */
  72,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  92,                                  /* lineNo */
  72,                                  /* colNo */
  "d",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo j_emlrtECI = { 2,   /* nDims */
  92,                                  /* lineNo */
  37,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo ob_emlrtDCI = { 92, /* lineNo */
  30,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = { 1,  /* iFirst */
  64,                                  /* iLast */
  92,                                  /* lineNo */
  30,                                  /* colNo */
  "E_temp",                            /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  92,                                  /* lineNo */
  21,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtBCInfo fb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  98,                                  /* lineNo */
  15,                                  /* colNo */
  "d",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo l_emlrtECI = { -1,  /* nDims */
  98,                                  /* lineNo */
  13,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 104,/* lineNo */
  17,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo pb_emlrtDCI = { 108,/* lineNo */
  39,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = { 1,  /* iFirst */
  64,                                  /* iLast */
  108,                                 /* lineNo */
  39,                                  /* colNo */
  "E_f",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  57,                                  /* colNo */
  "d",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  59,                                  /* colNo */
  "d",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo qb_emlrtDCI = { 108,/* lineNo */
  61,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  108,                                 /* lineNo */
  61,                                  /* colNo */
  "d",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo m_emlrtECI = { 2,   /* nDims */
  108,                                 /* lineNo */
  33,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo rb_emlrtDCI = { 108,/* lineNo */
  23,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = { 1,  /* iFirst */
  64,                                  /* iLast */
  108,                                 /* lineNo */
  23,                                  /* colNo */
  "E_f",                               /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo n_emlrtECI = { -1,  /* nDims */
  108,                                 /* lineNo */
  17,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo sb_emlrtDCI = { 83, /* lineNo */
  32,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo tb_emlrtDCI = { 83, /* lineNo */
  32,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo ub_emlrtDCI = { 83, /* lineNo */
  34,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo vb_emlrtDCI = { 83, /* lineNo */
  34,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo wb_emlrtDCI = { 83, /* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo xb_emlrtDCI = { 83, /* lineNo */
  9,                                   /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = { 1,  /* iFirst */
  3,                                   /* iLast */
  106,                                 /* lineNo */
  16,                                  /* colNo */
  "c",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = { 1,  /* iFirst */
  3,                                   /* iLast */
  90,                                  /* lineNo */
  20,                                  /* colNo */
  "b",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = { 1,  /* iFirst */
  3,                                   /* iLast */
  98,                                  /* lineNo */
  59,                                  /* colNo */
  "a",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo yb_emlrtDCI = { 119,/* lineNo */
  19,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = { 1,  /* iFirst */
  64,                                  /* iLast */
  119,                                 /* lineNo */
  19,                                  /* colNo */
  "B",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo ac_emlrtDCI = { 120,/* lineNo */
  17,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = { 1,  /* iFirst */
  64,                                  /* iLast */
  120,                                 /* lineNo */
  17,                                  /* colNo */
  "B",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo bc_emlrtDCI = { 120,/* lineNo */
  21,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = { 1,  /* iFirst */
  64,                                  /* iLast */
  120,                                 /* lineNo */
  21,                                  /* colNo */
  "B",                                 /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo o_emlrtECI = { 2,   /* nDims */
  126,                                 /* lineNo */
  26,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtBCInfo rb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  74,                                  /* colNo */
  "Nonlin_o",                          /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo cc_emlrtDCI = { 129,/* lineNo */
  76,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  129,                                 /* lineNo */
  76,                                  /* colNo */
  "Nonlin_o",                          /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo p_emlrtECI = { 2,   /* nDims */
  129,                                 /* lineNo */
  29,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtBCInfo tb_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  74,                                  /* colNo */
  "Nonlin_e",                          /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo dc_emlrtDCI = { 130,/* lineNo */
  76,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo ub_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  130,                                 /* lineNo */
  76,                                  /* colNo */
  "Nonlin_e",                          /* aName */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  0                                    /* checkKind */
};

static emlrtECInfo q_emlrtECI = { 2,   /* nDims */
  130,                                 /* lineNo */
  29,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m"                            /* pName */
};

static emlrtDCInfo ec_emlrtDCI = { 122,/* lineNo */
  38,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo fc_emlrtDCI = { 122,/* lineNo */
  38,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo gc_emlrtDCI = { 123,/* lineNo */
  38,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo hc_emlrtDCI = { 123,/* lineNo */
  38,                                  /* colNo */
  "Split_chi_2",                       /* fName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Full_LLE_Time_evolution/Functions/Branches Tracking/MI_LLE/Solver_Starter/Solvers/Split_"
  "chi_2.m",                           /* pName */
  4                                    /* checkKind */
};

/* Function Declarations */
static void Equation_Second_Harmonic(const emlrtStack *sp, const
  coder_internal_ref *N, coder_internal_ref_2 *k_o, coder_internal_ref_2 *k_e,
  coder_internal_ref_2 *Nonlin_o, coder_internal_ref_2 *Nonlin_e, const
  coder_internal_ref *delta_o, const coder_internal_ref *kappa_o, const
  coder_internal_ref *gamma_o, const coder_internal_ref *Pump, const
  coder_internal_ref_2 *exp_probe_o_1, const coder_internal_ref_1 *Probes, const
  coder_internal_ref_2 *exp_probe_o_3, const coder_internal_ref *delta_e, const
  coder_internal_ref *kappa_e, const coder_internal_ref *gamma_e, const
  coder_internal_ref_2 *exp_probe_e_2, const coder_internal_ref_2 *exp_probe_e_4,
  const creal_T B[64], real_T t, emxArray_creal_T *k);
static void Runge_Kuarong_Kerr_step(const emlrtStack *sp, const
  coder_internal_ref *N, coder_internal_ref_2 *k_o, coder_internal_ref_2 *k_e,
  coder_internal_ref_2 *Nonlin_o, coder_internal_ref_2 *Nonlin_e, const
  coder_internal_ref *delta_o, const coder_internal_ref *kappa_o, const
  coder_internal_ref *gamma_o, const coder_internal_ref *Pump, const
  coder_internal_ref_2 *exp_probe_o_1, const coder_internal_ref_1 *Probes, const
  coder_internal_ref_2 *exp_probe_o_3, const coder_internal_ref *delta_e, const
  coder_internal_ref *kappa_e, const coder_internal_ref *gamma_e, const
  coder_internal_ref_2 *exp_probe_e_2, const coder_internal_ref_2 *exp_probe_e_4,
  const coder_internal_ref *s, const coder_internal_ref_3 *a, const
  coder_internal_ref_4 *b, const coder_internal_ref_3 *c, const creal_T B_E[64],
  real_T dt, real_T t, creal_T E_f[64]);

/* Function Definitions */
static void Equation_Second_Harmonic(const emlrtStack *sp, const
  coder_internal_ref *N, coder_internal_ref_2 *k_o, coder_internal_ref_2 *k_e,
  coder_internal_ref_2 *Nonlin_o, coder_internal_ref_2 *Nonlin_e, const
  coder_internal_ref *delta_o, const coder_internal_ref *kappa_o, const
  coder_internal_ref *gamma_o, const coder_internal_ref *Pump, const
  coder_internal_ref_2 *exp_probe_o_1, const coder_internal_ref_1 *Probes, const
  coder_internal_ref_2 *exp_probe_o_3, const coder_internal_ref *delta_e, const
  coder_internal_ref *kappa_e, const coder_internal_ref *gamma_e, const
  coder_internal_ref_2 *exp_probe_e_2, const coder_internal_ref_2 *exp_probe_e_4,
  const creal_T B[64], real_T t, emxArray_creal_T *k)
{
  real_T im;
  int32_T loop_ub;
  int32_T B_o_size[2];
  creal_T B_o_data[64];
  real_T r;
  int32_T i20;
  int32_T b_loop_ub;
  int32_T B_e_size_idx_1_tmp;
  creal_T B_e_data[64];
  int32_T iv2[2];
  creal_T tmp_data[64];
  int32_T tmp_size[2];
  real_T y_re;
  real_T y_im;
  int32_T c_loop_ub;
  emxArray_creal_T *r2;
  emxArray_creal_T *r3;
  emxArray_creal_T *r4;
  real_T re_tmp;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  im = N->contents;
  if (1.0 > im) {
    loop_ub = 0;
  } else {
    if (im != (int32_T)muDoubleScalarFloor(im)) {
      emlrtIntegerCheckR2012b(im, &yb_emlrtDCI, sp);
    }

    loop_ub = (int32_T)im;
    if ((loop_ub < 1) || (loop_ub > 64)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 64, &ob_emlrtBCI, sp);
    }
  }

  B_o_size[0] = 1;
  B_o_size[1] = loop_ub;
  if (0 <= loop_ub - 1) {
    memcpy(&B_o_data[0], &B[0], (uint32_T)(loop_ub * (int32_T)sizeof(creal_T)));
  }

  im = N->contents + 1.0;
  r = 2.0 * N->contents;
  if (im > r) {
    i20 = 1;
    b_loop_ub = 1;
  } else {
    if (im != (int32_T)muDoubleScalarFloor(im)) {
      emlrtIntegerCheckR2012b(im, &ac_emlrtDCI, sp);
    }

    i20 = (int32_T)im;
    if ((i20 < 1) || (i20 > 64)) {
      emlrtDynamicBoundsCheckR2012b(i20, 1, 64, &pb_emlrtBCI, sp);
    }

    if (r != (int32_T)muDoubleScalarFloor(r)) {
      emlrtIntegerCheckR2012b(r, &bc_emlrtDCI, sp);
    }

    b_loop_ub = (int32_T)r;
    if ((b_loop_ub < 1) || (b_loop_ub > 64)) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, 64, &qb_emlrtBCI, sp);
    }

    b_loop_ub++;
  }

  B_e_size_idx_1_tmp = b_loop_ub - i20;
  for (b_loop_ub = 0; b_loop_ub < B_e_size_idx_1_tmp; b_loop_ub++) {
    B_e_data[b_loop_ub] = B[(i20 + b_loop_ub) - 1];
  }

  if (!(N->contents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N->contents, &fc_emlrtDCI, sp);
  }

  im = N->contents;
  if (im != (int32_T)muDoubleScalarFloor(im)) {
    emlrtIntegerCheckR2012b(im, &ec_emlrtDCI, sp);
  }

  b_loop_ub = (int32_T)im - 1;
  i20 = k_o->contents->size[0] * k_o->contents->size[1];
  k_o->contents->size[0] = 1;
  if (!(N->contents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N->contents, &fc_emlrtDCI, sp);
  }

  im = N->contents;
  if (im != (int32_T)muDoubleScalarFloor(im)) {
    emlrtIntegerCheckR2012b(im, &ec_emlrtDCI, sp);
  }

  k_o->contents->size[1] = (int32_T)im;
  emxEnsureCapacity_creal_T(sp, k_o->contents, i20, &fb_emlrtRTEI);
  for (i20 = 0; i20 <= b_loop_ub; i20++) {
    k_o->contents->data[i20].re = 0.0;
    k_o->contents->data[i20].im = 0.0;
  }

  if (!(N->contents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N->contents, &hc_emlrtDCI, sp);
  }

  im = N->contents;
  if (im != (int32_T)muDoubleScalarFloor(im)) {
    emlrtIntegerCheckR2012b(im, &gc_emlrtDCI, sp);
  }

  b_loop_ub = (int32_T)im - 1;
  i20 = k_e->contents->size[0] * k_e->contents->size[1];
  k_e->contents->size[0] = 1;
  if (!(N->contents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N->contents, &hc_emlrtDCI, sp);
  }

  im = N->contents;
  if (im != (int32_T)muDoubleScalarFloor(im)) {
    emlrtIntegerCheckR2012b(im, &gc_emlrtDCI, sp);
  }

  k_e->contents->size[1] = (int32_T)im;
  emxEnsureCapacity_creal_T(sp, k_e->contents, i20, &gb_emlrtRTEI);
  for (i20 = 0; i20 <= b_loop_ub; i20++) {
    k_e->contents->data[i20].re = 0.0;
    k_e->contents->data[i20].im = 0.0;
  }

  for (i20 = 0; i20 < loop_ub; i20++) {
    tmp_data[i20].re = B_o_data[i20].re;
    tmp_data[i20].im = -B_o_data[i20].im;
  }

  iv2[0] = 1;
  iv2[1] = B_e_size_idx_1_tmp;
  tmp_size[0] = 1;
  tmp_size[1] = loop_ub;
  if (B_e_size_idx_1_tmp != loop_ub) {
    emlrtSizeEqCheckNDR2012b(&iv2[0], &tmp_size[0], &o_emlrtECI, sp);
  }

  i20 = Nonlin_o->contents->size[0] * Nonlin_o->contents->size[1];
  Nonlin_o->contents->size[0] = 1;
  Nonlin_o->contents->size[1] = B_e_size_idx_1_tmp;
  emxEnsureCapacity_creal_T(sp, Nonlin_o->contents, i20, &hb_emlrtRTEI);
  for (i20 = 0; i20 < B_e_size_idx_1_tmp; i20++) {
    Nonlin_o->contents->data[i20].re = B_e_data[i20].re * tmp_data[i20].re -
      B_e_data[i20].im * tmp_data[i20].im;
    Nonlin_o->contents->data[i20].im = B_e_data[i20].re * tmp_data[i20].im +
      B_e_data[i20].im * tmp_data[i20].re;
  }

  power(B_o_data, B_o_size, tmp_data, tmp_size);
  i20 = Nonlin_e->contents->size[0] * Nonlin_e->contents->size[1];
  Nonlin_e->contents->size[0] = 1;
  Nonlin_e->contents->size[1] = tmp_size[1];
  emxEnsureCapacity_creal_T(sp, Nonlin_e->contents, i20, &ib_emlrtRTEI);
  b_loop_ub = tmp_size[0] * tmp_size[1];
  for (i20 = 0; i20 < b_loop_ub; i20++) {
    Nonlin_e->contents->data[i20] = tmp_data[i20];
  }

  im = N->contents;
  if (1.0 > im) {
    b_loop_ub = 0;
  } else {
    i20 = Nonlin_o->contents->size[1];
    if (1 > i20) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i20, &rb_emlrtBCI, sp);
    }

    if (im != (int32_T)muDoubleScalarFloor(im)) {
      emlrtIntegerCheckR2012b(im, &cc_emlrtDCI, sp);
    }

    i20 = Nonlin_o->contents->size[1];
    b_loop_ub = (int32_T)im;
    if ((b_loop_ub < 1) || (b_loop_ub > i20)) {
      emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i20, &sb_emlrtBCI, sp);
    }
  }

  y_re = delta_o->contents - 0.0 * kappa_o->contents;
  y_im = 0.0 - kappa_o->contents;
  c_loop_ub = loop_ub - 1;
  for (i20 = 0; i20 <= c_loop_ub; i20++) {
    r = B_o_data[i20].re;
    B_o_data[i20].re = y_re * B_o_data[i20].re - y_im * B_o_data[i20].im;
    B_o_data[i20].im = y_re * B_o_data[i20].im + y_im * r;
  }

  emxInit_creal_T(sp, &r2, 2, &sb_emlrtRTEI, true);
  i20 = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = b_loop_ub;
  emxEnsureCapacity_creal_T(sp, r2, i20, &jb_emlrtRTEI);
  for (i20 = 0; i20 < b_loop_ub; i20++) {
    r2->data[i20].re = gamma_o->contents * Nonlin_o->contents->data[i20].re;
    r2->data[i20].im = gamma_o->contents * Nonlin_o->contents->data[i20].im;
  }

  tmp_size[0] = 1;
  tmp_size[1] = loop_ub;
  iv2[0] = r2->size[0];
  iv2[1] = r2->size[1];
  if ((1 != iv2[0]) || (loop_ub != iv2[1])) {
    emlrtSizeEqCheckNDR2012b(&tmp_size[0], &iv2[0], &p_emlrtECI, sp);
  }

  y_re = t * (Probes->contents.omega_probe_o_1 * 0.0);
  y_im = t * -Probes->contents.omega_probe_o_1;
  if (y_im == 0.0) {
    y_re = muDoubleScalarExp(y_re);
    y_im = 0.0;
  } else {
    r = muDoubleScalarExp(y_re / 2.0);
    y_re = r * (r * muDoubleScalarCos(y_im));
    y_im = r * (r * muDoubleScalarSin(y_im));
  }

  emxInit_creal_T(sp, &r3, 2, &sb_emlrtRTEI, true);
  i20 = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  r3->size[1] = exp_probe_o_1->contents->size[1];
  emxEnsureCapacity_creal_T(sp, r3, i20, &kb_emlrtRTEI);
  b_loop_ub = exp_probe_o_1->contents->size[0] * exp_probe_o_1->contents->size[1];
  for (i20 = 0; i20 < b_loop_ub; i20++) {
    r = 0.0 * exp_probe_o_1->contents->data[i20].re - exp_probe_o_1->
      contents->data[i20].im;
    im = 0.0 * exp_probe_o_1->contents->data[i20].im + exp_probe_o_1->
      contents->data[i20].re;
    r3->data[i20].re = r * y_re - im * y_im;
    r3->data[i20].im = r * y_im + im * y_re;
  }

  tmp_size[0] = 1;
  tmp_size[1] = loop_ub;
  iv2[0] = r3->size[0];
  iv2[1] = r3->size[1];
  if ((1 != iv2[0]) || (loop_ub != iv2[1])) {
    emlrtSizeEqCheckNDR2012b(&tmp_size[0], &iv2[0], &p_emlrtECI, sp);
  }

  y_re = t * (Probes->contents.omega_probe_o_3 * 0.0);
  y_im = t * -Probes->contents.omega_probe_o_3;
  if (y_im == 0.0) {
    y_re = muDoubleScalarExp(y_re);
    y_im = 0.0;
  } else {
    r = muDoubleScalarExp(y_re / 2.0);
    y_re = r * (r * muDoubleScalarCos(y_im));
    y_im = r * (r * muDoubleScalarSin(y_im));
  }

  emxInit_creal_T(sp, &r4, 2, &sb_emlrtRTEI, true);
  i20 = r4->size[0] * r4->size[1];
  r4->size[0] = 1;
  r4->size[1] = exp_probe_o_3->contents->size[1];
  emxEnsureCapacity_creal_T(sp, r4, i20, &lb_emlrtRTEI);
  b_loop_ub = exp_probe_o_3->contents->size[0] * exp_probe_o_3->contents->size[1];
  for (i20 = 0; i20 < b_loop_ub; i20++) {
    r = 0.0 * exp_probe_o_3->contents->data[i20].re - exp_probe_o_3->
      contents->data[i20].im;
    im = 0.0 * exp_probe_o_3->contents->data[i20].im + exp_probe_o_3->
      contents->data[i20].re;
    r4->data[i20].re = r * y_re - im * y_im;
    r4->data[i20].im = r * y_im + im * y_re;
  }

  tmp_size[0] = 1;
  tmp_size[1] = loop_ub;
  iv2[0] = r4->size[0];
  iv2[1] = r4->size[1];
  if ((1 != iv2[0]) || (loop_ub != iv2[1])) {
    emlrtSizeEqCheckNDR2012b(&tmp_size[0], &iv2[0], &p_emlrtECI, sp);
  }

  y_re = Pump->contents * 0.0;
  y_im = Pump->contents;
  i20 = k_o->contents->size[0] * k_o->contents->size[1];
  k_o->contents->size[0] = 1;
  k_o->contents->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, k_o->contents, i20, &mb_emlrtRTEI);
  for (i20 = 0; i20 < loop_ub; i20++) {
    r = (((B_o_data[i20].re - r2->data[i20].re) + y_re) + r3->data[i20].re) +
      r4->data[i20].re;
    im = (((B_o_data[i20].im - r2->data[i20].im) + y_im) + r3->data[i20].im) +
      r4->data[i20].im;
    k_o->contents->data[i20].re = 0.0 * r - (-im);
    k_o->contents->data[i20].im = 0.0 * im + -r;
  }

  im = N->contents;
  if (1.0 > im) {
    loop_ub = 0;
  } else {
    i20 = Nonlin_e->contents->size[1];
    if (1 > i20) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i20, &tb_emlrtBCI, sp);
    }

    if (im != (int32_T)muDoubleScalarFloor(im)) {
      emlrtIntegerCheckR2012b(im, &dc_emlrtDCI, sp);
    }

    i20 = Nonlin_e->contents->size[1];
    loop_ub = (int32_T)im;
    if ((loop_ub < 1) || (loop_ub > i20)) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i20, &ub_emlrtBCI, sp);
    }
  }

  y_re = delta_e->contents - 0.0 * kappa_e->contents;
  y_im = 0.0 - kappa_e->contents;
  b_loop_ub = B_e_size_idx_1_tmp - 1;
  for (i20 = 0; i20 <= b_loop_ub; i20++) {
    im = B_e_data[i20].re;
    B_e_data[i20].re = y_re * B_e_data[i20].re - y_im * B_e_data[i20].im;
    B_e_data[i20].im = y_re * B_e_data[i20].im + y_im * im;
  }

  i20 = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, r2, i20, &nb_emlrtRTEI);
  for (i20 = 0; i20 < loop_ub; i20++) {
    r2->data[i20].re = gamma_e->contents * Nonlin_e->contents->data[i20].re;
    r2->data[i20].im = gamma_e->contents * Nonlin_e->contents->data[i20].im;
  }

  tmp_size[0] = 1;
  tmp_size[1] = B_e_size_idx_1_tmp;
  iv2[0] = r2->size[0];
  iv2[1] = r2->size[1];
  if ((1 != iv2[0]) || (B_e_size_idx_1_tmp != iv2[1])) {
    emlrtSizeEqCheckNDR2012b(&tmp_size[0], &iv2[0], &q_emlrtECI, sp);
  }

  re_tmp = Probes->contents.omega_probe_e_2 * 0.0;
  y_re = t * re_tmp;
  y_im = t * -Probes->contents.omega_probe_e_2;
  if (y_im == 0.0) {
    y_re = muDoubleScalarExp(y_re);
    y_im = 0.0;
  } else {
    r = muDoubleScalarExp(y_re / 2.0);
    y_re = r * (r * muDoubleScalarCos(y_im));
    y_im = r * (r * muDoubleScalarSin(y_im));
  }

  i20 = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  r3->size[1] = exp_probe_e_2->contents->size[1];
  emxEnsureCapacity_creal_T(sp, r3, i20, &ob_emlrtRTEI);
  loop_ub = exp_probe_e_2->contents->size[0] * exp_probe_e_2->contents->size[1];
  for (i20 = 0; i20 < loop_ub; i20++) {
    r = 0.0 * exp_probe_e_2->contents->data[i20].re - exp_probe_e_2->
      contents->data[i20].im;
    im = 0.0 * exp_probe_e_2->contents->data[i20].im + exp_probe_e_2->
      contents->data[i20].re;
    r3->data[i20].re = r * y_re - im * y_im;
    r3->data[i20].im = r * y_im + im * y_re;
  }

  tmp_size[0] = 1;
  tmp_size[1] = B_e_size_idx_1_tmp;
  iv2[0] = r3->size[0];
  iv2[1] = r3->size[1];
  if ((1 != iv2[0]) || (B_e_size_idx_1_tmp != iv2[1])) {
    emlrtSizeEqCheckNDR2012b(&tmp_size[0], &iv2[0], &q_emlrtECI, sp);
  }

  y_re = t * re_tmp;
  y_im = t * -Probes->contents.omega_probe_e_2;
  if (y_im == 0.0) {
    y_re = muDoubleScalarExp(y_re);
    y_im = 0.0;
  } else {
    im = muDoubleScalarExp(y_re / 2.0);
    y_re = im * (im * muDoubleScalarCos(y_im));
    y_im = im * (im * muDoubleScalarSin(y_im));
  }

  i20 = r4->size[0] * r4->size[1];
  r4->size[0] = 1;
  r4->size[1] = exp_probe_e_4->contents->size[1];
  emxEnsureCapacity_creal_T(sp, r4, i20, &pb_emlrtRTEI);
  loop_ub = exp_probe_e_4->contents->size[0] * exp_probe_e_4->contents->size[1];
  for (i20 = 0; i20 < loop_ub; i20++) {
    r = 0.0 * exp_probe_e_4->contents->data[i20].re - exp_probe_e_4->
      contents->data[i20].im;
    im = 0.0 * exp_probe_e_4->contents->data[i20].im + exp_probe_e_4->
      contents->data[i20].re;
    r4->data[i20].re = r * y_re - im * y_im;
    r4->data[i20].im = r * y_im + im * y_re;
  }

  tmp_size[0] = 1;
  tmp_size[1] = B_e_size_idx_1_tmp;
  iv2[0] = r4->size[0];
  iv2[1] = r4->size[1];
  if ((1 != iv2[0]) || (B_e_size_idx_1_tmp != iv2[1])) {
    emlrtSizeEqCheckNDR2012b(&tmp_size[0], &iv2[0], &q_emlrtECI, sp);
  }

  i20 = k_e->contents->size[0] * k_e->contents->size[1];
  k_e->contents->size[0] = 1;
  k_e->contents->size[1] = B_e_size_idx_1_tmp;
  emxEnsureCapacity_creal_T(sp, k_e->contents, i20, &qb_emlrtRTEI);
  for (i20 = 0; i20 < B_e_size_idx_1_tmp; i20++) {
    im = ((B_e_data[i20].re - r2->data[i20].re) + r3->data[i20].re) + r4->
      data[i20].re;
    r = ((B_e_data[i20].im - r2->data[i20].im) + r3->data[i20].im) + r4->
      data[i20].im;
    k_e->contents->data[i20].re = 0.0 * im - (-r);
    k_e->contents->data[i20].im = 0.0 * r + -im;
  }

  emxFree_creal_T(&r4);
  emxFree_creal_T(&r3);
  emxFree_creal_T(&r2);
  i20 = k->size[0] * k->size[1];
  k->size[0] = 1;
  k->size[1] = k_o->contents->size[1] + k_e->contents->size[1];
  emxEnsureCapacity_creal_T(sp, k, i20, &rb_emlrtRTEI);
  loop_ub = k_o->contents->size[1];
  for (i20 = 0; i20 < loop_ub; i20++) {
    k->data[i20] = k_o->contents->data[i20];
  }

  loop_ub = k_e->contents->size[1];
  for (i20 = 0; i20 < loop_ub; i20++) {
    k->data[i20 + k_o->contents->size[1]] = k_e->contents->data[i20];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

static void Runge_Kuarong_Kerr_step(const emlrtStack *sp, const
  coder_internal_ref *N, coder_internal_ref_2 *k_o, coder_internal_ref_2 *k_e,
  coder_internal_ref_2 *Nonlin_o, coder_internal_ref_2 *Nonlin_e, const
  coder_internal_ref *delta_o, const coder_internal_ref *kappa_o, const
  coder_internal_ref *gamma_o, const coder_internal_ref *Pump, const
  coder_internal_ref_2 *exp_probe_o_1, const coder_internal_ref_1 *Probes, const
  coder_internal_ref_2 *exp_probe_o_3, const coder_internal_ref *delta_e, const
  coder_internal_ref *kappa_e, const coder_internal_ref *gamma_e, const
  coder_internal_ref_2 *exp_probe_e_2, const coder_internal_ref_2 *exp_probe_e_4,
  const coder_internal_ref *s, const coder_internal_ref_3 *a, const
  coder_internal_ref_4 *b, const coder_internal_ref_3 *c, const creal_T B_E[64],
  real_T dt, real_T t, creal_T E_f[64])
{
  creal_T E_temp[64];
  emxArray_creal_T *d;
  int32_T i16;
  real_T d1;
  real_T b_dt;
  int32_T loop_ub;
  emxArray_int32_T *r0;
  emxArray_creal_T *r1;
  int32_T iv0[2];
  int32_T i;
  int32_T i17;
  int32_T ii;
  int32_T i18;
  int32_T i19;
  int32_T b_loop_ub;
  int32_T iv1[2];
  creal_T E_temp_data[64];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  memcpy(&E_f[0], &B_E[0], sizeof(creal_T) << 6);
  memcpy(&E_temp[0], &B_E[0], sizeof(creal_T) << 6);
  emxInit_creal_T(sp, &d, 2, &y_emlrtRTEI, true);
  i16 = d->size[0] * d->size[1];
  if (!(s->contents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(s->contents, &tb_emlrtDCI, sp);
  }

  d1 = s->contents;
  if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
    emlrtIntegerCheckR2012b(d1, &sb_emlrtDCI, sp);
  }

  d->size[0] = (int32_T)d1;
  d1 = 2.0 * N->contents;
  if (!(d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d1, &vb_emlrtDCI, sp);
  }

  if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
    emlrtIntegerCheckR2012b(d1, &ub_emlrtDCI, sp);
  }

  d->size[1] = (int32_T)d1;
  emxEnsureCapacity_creal_T(sp, d, i16, &y_emlrtRTEI);
  if (!(s->contents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(s->contents, &xb_emlrtDCI, sp);
  }

  b_dt = s->contents;
  if (b_dt != (int32_T)muDoubleScalarFloor(b_dt)) {
    emlrtIntegerCheckR2012b(b_dt, &wb_emlrtDCI, sp);
  }

  if (!(d1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d1, &xb_emlrtDCI, sp);
  }

  if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
    emlrtIntegerCheckR2012b(d1, &wb_emlrtDCI, sp);
  }

  loop_ub = (int32_T)b_dt * (int32_T)d1;
  for (i16 = 0; i16 < loop_ub; i16++) {
    d->data[i16].re = 0.0;
    d->data[i16].im = 0.0;
  }

  emxInit_int32_T(sp, &r0, 1, &eb_emlrtRTEI, true);
  i16 = d->size[0];
  if (1 > i16) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i16, &ab_emlrtBCI, sp);
  }

  loop_ub = d->size[1];
  i16 = r0->size[0];
  r0->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(sp, r0, i16, &ab_emlrtRTEI);
  for (i16 = 0; i16 < loop_ub; i16++) {
    r0->data[i16] = i16;
  }

  emxInit_creal_T(sp, &r1, 2, &eb_emlrtRTEI, true);
  st.site = &y_emlrtRSI;
  Equation_Second_Harmonic(&st, N, k_o, k_e, Nonlin_o, Nonlin_e, delta_o,
    kappa_o, gamma_o, Pump, exp_probe_o_1, Probes, exp_probe_o_3, delta_e,
    kappa_e, gamma_e, exp_probe_e_2, exp_probe_e_4, B_E, t + a->contents[0] * dt,
    r1);
  iv0[0] = 1;
  iv0[1] = r0->size[0];
  emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &(*(int32_T (*)[2])r1->size)[0], 2,
    &i_emlrtECI, sp);
  loop_ub = r1->size[1];
  for (i16 = 0; i16 < loop_ub; i16++) {
    d->data[d->size[0] * r0->data[i16]] = r1->data[i16];
  }

  b_dt = s->contents;
  i16 = (int32_T)(b_dt + -1.0);
  emlrtForLoopVectorCheckR2012b(2.0, 1.0, b_dt, mxDOUBLE_CLASS, (int32_T)(b_dt +
    -1.0), &xb_emlrtRTEI, sp);
  for (i = 0; i < i16; i++) {
    b_dt = s->contents - 1.0;
    i17 = (int32_T)b_dt;
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, b_dt, mxDOUBLE_CLASS, (int32_T)b_dt,
      &yb_emlrtRTEI, sp);
    for (ii = 0; ii < i17; ii++) {
      i18 = (int32_T)(2U + i);
      if ((i18 < 1) || (i18 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i18, 1, 3, &mb_emlrtBCI, sp);
      }

      i19 = (int32_T)(1U + ii);
      if ((i19 < 1) || (i19 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i19, 1, 3, &mb_emlrtBCI, sp);
      }

      if (b->contents[(i18 + 3 * (i19 - 1)) - 1] != 0.0) {
        if (1.0 > d1) {
          loop_ub = 0;
          b_loop_ub = 0;
        } else {
          if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
            emlrtIntegerCheckR2012b(d1, &mb_emlrtDCI, sp);
          }

          loop_ub = (int32_T)d1;
          if ((loop_ub < 1) || (loop_ub > 64)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 64, &y_emlrtBCI, sp);
          }

          i18 = d->size[1];
          if (1 > i18) {
            emlrtDynamicBoundsCheckR2012b(1, 1, i18, &cb_emlrtBCI, sp);
          }

          if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
            emlrtIntegerCheckR2012b(d1, &nb_emlrtDCI, sp);
          }

          i18 = d->size[1];
          b_loop_ub = (int32_T)d1;
          if ((b_loop_ub < 1) || (b_loop_ub > i18)) {
            emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i18, &db_emlrtBCI, sp);
          }
        }

        b_dt = dt * b->contents[(i + 3 * ii) + 1];
        i18 = d->size[0];
        if ((i19 < 1) || (i19 > i18)) {
          emlrtDynamicBoundsCheckR2012b(i19, 1, i18, &bb_emlrtBCI, sp);
        }

        i18 = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        r1->size[1] = b_loop_ub;
        emxEnsureCapacity_creal_T(sp, r1, i18, &db_emlrtRTEI);
        for (i18 = 0; i18 < b_loop_ub; i18++) {
          r1->data[i18].re = b_dt * d->data[(i19 + d->size[0] * i18) - 1].re;
          r1->data[i18].im = b_dt * d->data[(i19 + d->size[0] * i18) - 1].im;
        }

        iv0[0] = 1;
        iv0[1] = loop_ub;
        iv1[0] = r1->size[0];
        iv1[1] = r1->size[1];
        if ((1 != iv1[0]) || (loop_ub != iv1[1])) {
          emlrtSizeEqCheckNDR2012b(&iv0[0], &iv1[0], &j_emlrtECI, sp);
        }

        if (1.0 > d1) {
          i18 = 0;
        } else {
          if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
            emlrtIntegerCheckR2012b(d1, &ob_emlrtDCI, sp);
          }

          i18 = (int32_T)d1;
          if ((i18 < 1) || (i18 > 64)) {
            emlrtDynamicBoundsCheckR2012b(i18, 1, 64, &eb_emlrtBCI, sp);
          }
        }

        if (i18 != loop_ub) {
          emlrtSubAssignSizeCheck1dR2017a(i18, loop_ub, &k_emlrtECI, sp);
        }

        for (i18 = 0; i18 < loop_ub; i18++) {
          E_temp_data[i18].re = E_temp[i18].re + r1->data[i18].re;
          E_temp_data[i18].im = E_temp[i18].im + r1->data[i18].im;
        }

        if (0 <= loop_ub - 1) {
          memcpy(&E_temp[0], &E_temp_data[0], (uint32_T)(loop_ub * (int32_T)
                  sizeof(creal_T)));
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    i17 = d->size[0];
    i18 = 2 + i;
    if ((i18 < 1) || (i18 > i17)) {
      emlrtDynamicBoundsCheckR2012b(i18, 1, i17, &fb_emlrtBCI, sp);
    }

    loop_ub = d->size[1];
    i17 = r0->size[0];
    r0->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(sp, r0, i17, &bb_emlrtRTEI);
    for (i17 = 0; i17 < loop_ub; i17++) {
      r0->data[i17] = i17;
    }

    i17 = (int32_T)(2U + i);
    if ((i17 < 1) || (i17 > 3)) {
      emlrtDynamicBoundsCheckR2012b(i17, 1, 3, &nb_emlrtBCI, sp);
    }

    st.site = &ab_emlrtRSI;
    Equation_Second_Harmonic(&st, N, k_o, k_e, Nonlin_o, Nonlin_e, delta_o,
      kappa_o, gamma_o, Pump, exp_probe_o_1, Probes, exp_probe_o_3, delta_e,
      kappa_e, gamma_e, exp_probe_e_2, exp_probe_e_4, E_temp, t + a->
      contents[i17 - 1] * dt, r1);
    iv0[0] = 1;
    iv0[1] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(&iv0[0], 2, &(*(int32_T (*)[2])r1->size)[0], 2,
      &l_emlrtECI, sp);
    loop_ub = r1->size[1];
    for (i17 = 0; i17 < loop_ub; i17++) {
      d->data[(i + d->size[0] * r0->data[i17]) + 1] = r1->data[i17];
    }

    memcpy(&E_temp[0], &B_E[0], sizeof(creal_T) << 6);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_int32_T(&r0);
  b_dt = s->contents;
  i16 = (int32_T)b_dt;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, b_dt, mxDOUBLE_CLASS, (int32_T)b_dt,
    &ac_emlrtRTEI, sp);
  for (i = 0; i < i16; i++) {
    i17 = (int32_T)(1U + i);
    if ((i17 < 1) || (i17 > 3)) {
      emlrtDynamicBoundsCheckR2012b(i17, 1, 3, &lb_emlrtBCI, sp);
    }

    if (c->contents[i17 - 1] != 0.0) {
      if (1.0 > d1) {
        loop_ub = 0;
        b_loop_ub = 0;
      } else {
        if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
          emlrtIntegerCheckR2012b(d1, &pb_emlrtDCI, sp);
        }

        loop_ub = (int32_T)d1;
        if ((loop_ub < 1) || (loop_ub > 64)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 64, &gb_emlrtBCI, sp);
        }

        i18 = d->size[1];
        if (1 > i18) {
          emlrtDynamicBoundsCheckR2012b(1, 1, i18, &ib_emlrtBCI, sp);
        }

        if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
          emlrtIntegerCheckR2012b(d1, &qb_emlrtDCI, sp);
        }

        i18 = d->size[1];
        b_loop_ub = (int32_T)d1;
        if ((b_loop_ub < 1) || (b_loop_ub > i18)) {
          emlrtDynamicBoundsCheckR2012b(b_loop_ub, 1, i18, &jb_emlrtBCI, sp);
        }
      }

      b_dt = dt * c->contents[i];
      i18 = d->size[0];
      if ((i17 < 1) || (i17 > i18)) {
        emlrtDynamicBoundsCheckR2012b(i17, 1, i18, &hb_emlrtBCI, sp);
      }

      i18 = r1->size[0] * r1->size[1];
      r1->size[0] = 1;
      r1->size[1] = b_loop_ub;
      emxEnsureCapacity_creal_T(sp, r1, i18, &cb_emlrtRTEI);
      for (i18 = 0; i18 < b_loop_ub; i18++) {
        r1->data[i18].re = b_dt * d->data[(i17 + d->size[0] * i18) - 1].re;
        r1->data[i18].im = b_dt * d->data[(i17 + d->size[0] * i18) - 1].im;
      }

      iv0[0] = 1;
      iv0[1] = loop_ub;
      iv1[0] = r1->size[0];
      iv1[1] = r1->size[1];
      if ((1 != iv1[0]) || (loop_ub != iv1[1])) {
        emlrtSizeEqCheckNDR2012b(&iv0[0], &iv1[0], &m_emlrtECI, sp);
      }

      if (1.0 > d1) {
        i17 = 0;
      } else {
        if (d1 != (int32_T)muDoubleScalarFloor(d1)) {
          emlrtIntegerCheckR2012b(d1, &rb_emlrtDCI, sp);
        }

        i17 = (int32_T)d1;
        if ((i17 < 1) || (i17 > 64)) {
          emlrtDynamicBoundsCheckR2012b(i17, 1, 64, &kb_emlrtBCI, sp);
        }
      }

      if (i17 != loop_ub) {
        emlrtSubAssignSizeCheck1dR2017a(i17, loop_ub, &n_emlrtECI, sp);
      }

      for (i17 = 0; i17 < loop_ub; i17++) {
        E_temp_data[i17].re = E_f[i17].re + r1->data[i17].re;
        E_temp_data[i17].im = E_f[i17].im + r1->data[i17].im;
      }

      if (0 <= loop_ub - 1) {
        memcpy(&E_f[0], &E_temp_data[0], (uint32_T)(loop_ub * (int32_T)sizeof
                (creal_T)));
      }
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_creal_T(&r1);
  emxFree_creal_T(&d);

  /*            E_f(1:2*N) = shift_back(1:2*N).*E_f(1:2*N);  */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void Split_chi_2(const emlrtStack *sp, const creal_T Psi_o_0[32], const creal_T
                 Psi_e_0[32], real_T delta_o, real_T delta_e, real_T kappa_o,
                 real_T kappa_e, real_T gamma_o, real_T gamma_e, real_T Pump,
                 const creal_T L_o[32], const creal_T L_e[32], real_T dt, real_T
                 nt, real_T NN, real_T Loops, real_T per_loop, real_T N, const
                 struct0_T *Runge, const struct1_T *Probes, real_T t_start,
                 struct2_T *Temporal)
{
  coder_internal_ref b_delta_o;
  coder_internal_ref b_delta_e;
  coder_internal_ref b_kappa_o;
  coder_internal_ref b_kappa_e;
  coder_internal_ref b_gamma_o;
  coder_internal_ref b_gamma_e;
  coder_internal_ref b_Pump;
  coder_internal_ref b_N;
  coder_internal_ref_1 b_Probes;
  coder_internal_ref_4 b;
  coder_internal_ref_3 c;
  coder_internal_ref_3 a;
  coder_internal_ref s;
  int32_T i0;
  creal_T Psi[64];
  real_T j;
  real_T delta2;
  emxArray_real_T *phi;
  real_T d0;
  emxArray_creal_T *b_b;
  real_T delta1;
  int32_T loop_ub;
  int32_T k;
  coder_internal_ref_2 exp_probe_o_1;
  coder_internal_ref_2 exp_probe_e_2;
  coder_internal_ref_2 exp_probe_o_3;
  coder_internal_ref_2 exp_probe_e_4;
  emxArray_creal_T *Psi_o_s;
  uint32_T i1;
  emxArray_creal_T *Psi_e_s;
  coder_internal_ref_2 k_o;
  coder_internal_ref_2 k_e;
  coder_internal_ref_2 Nonlin_o;
  coder_internal_ref_2 Nonlin_e;
  int32_T ni;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T b_i1;
  int32_T d_loop_ub;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T e_loop_ub;
  int32_T i5;
  int32_T tmp_size[2];
  int32_T i6;
  int32_T f_loop_ub;
  int32_T Psi_size[2];
  creal_T tmp_data[32];
  int32_T g_loop_ub;
  int32_T i7;
  int32_T h_loop_ub;
  creal_T Psi_data[64];
  creal_T Psi_o_k_data[64];
  int32_T Psi_o_k_size[2];
  int32_T Psi_e_k_size[2];
  int32_T Psi_o_k[2];
  int32_T i8;
  int32_T i9;
  int32_T i_loop_ub;
  int32_T b_tmp_size[2];
  int32_T i10;
  int32_T i11;
  creal_T b_tmp_data[32];
  int32_T b_Psi_size[2];
  int32_T c_tmp_size[2];
  int32_T c_Psi_size[2];
  int32_T d_tmp_size[2];
  int32_T d_Psi_size[2];
  int32_T e_tmp_size[2];
  int32_T e_Psi_size[2];
  int32_T i12;
  int32_T f_Psi_size[2];
  int32_T Psi_size_tmp;
  creal_T Psi_e_k_data[64];
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &emlrtRSI;
  b_delta_o.contents = delta_o;
  st.site = &emlrtRSI;
  b_delta_e.contents = delta_e;
  st.site = &emlrtRSI;
  b_kappa_o.contents = kappa_o;
  st.site = &emlrtRSI;
  b_kappa_e.contents = kappa_e;
  st.site = &emlrtRSI;
  b_gamma_o.contents = gamma_o;
  st.site = &emlrtRSI;
  b_gamma_e.contents = gamma_e;
  st.site = &emlrtRSI;
  b_Pump.contents = Pump;
  st.site = &emlrtRSI;
  b_N.contents = N;
  st.site = &emlrtRSI;
  b_Probes.contents = *Probes;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;

  /*  Runge-Kutta Coefficicents */
  memcpy(&b.contents[0], &Runge->b[0], 9U * sizeof(real_T));
  c.contents[0] = Runge->c[0];
  a.contents[0] = Runge->a[0];
  c.contents[1] = Runge->c[1];
  a.contents[1] = Runge->a[1];
  c.contents[2] = Runge->c[2];
  a.contents[2] = Runge->a[2];
  s.contents = 3.0;

  /*  */
  for (i0 = 0; i0 < 32; i0++) {
    Psi[i0] = Psi_o_0[i0];
    Psi[i0 + 32] = Psi_e_0[i0];
  }

  /*          */
  st.site = &b_emlrtRSI;
  j = 3.1415926535897931 - 6.2831853071795862 / N;
  delta2 = N;
  if (N < 0.0) {
    delta2 = 0.0;
  }

  emxInit_real_T(&st, &phi, 2, &x_emlrtRTEI, true);
  d0 = muDoubleScalarFloor(delta2);
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &fb_emlrtDCI, &st);
  }

  i0 = phi->size[0] * phi->size[1];
  phi->size[0] = 1;
  phi->size[1] = (int32_T)d0;
  emxEnsureCapacity_real_T(&st, phi, i0, &emlrtRTEI);
  if (phi->size[1] >= 1) {
    phi->data[phi->size[1] - 1] = j;
    if (phi->size[1] >= 2) {
      phi->data[0] = -3.1415926535897931;
      if (phi->size[1] >= 3) {
        if ((!(j < 0.0)) && (j > 8.9884656743115785E+307)) {
          delta1 = -3.1415926535897931 / ((real_T)phi->size[1] - 1.0);
          delta2 = j / ((real_T)phi->size[1] - 1.0);
          i0 = phi->size[1];
          for (k = 0; k <= i0 - 3; k++) {
            phi->data[k + 1] = (-3.1415926535897931 + delta2 * (1.0 + (real_T)k))
              - delta1 * (1.0 + (real_T)k);
          }
        } else {
          delta1 = (j - -3.1415926535897931) / ((real_T)phi->size[1] - 1.0);
          i0 = phi->size[1];
          for (k = 0; k <= i0 - 3; k++) {
            phi->data[k + 1] = -3.1415926535897931 + (1.0 + (real_T)k) * delta1;
          }
        }
      }
    }
  }

  emxInit_creal_T(&st, &b_b, 2, &b_emlrtRTEI, true);
  i0 = b_b->size[0] * b_b->size[1];
  b_b->size[0] = 1;
  b_b->size[1] = phi->size[1];
  emxEnsureCapacity_creal_T(sp, b_b, i0, &b_emlrtRTEI);
  loop_ub = phi->size[0] * phi->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    delta2 = phi->data[i0] * 0.0;
    delta1 = phi->data[i0];
    b_b->data[i0].re = Probes->mu_p_o_1 * delta2;
    b_b->data[i0].im = Probes->mu_p_o_1 * delta1;
  }

  c_emxInitStruct_coder_internal_(sp, &exp_probe_o_1, &c_emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  b_exp(&st, b_b);
  i0 = exp_probe_o_1.contents->size[0] * exp_probe_o_1.contents->size[1];
  exp_probe_o_1.contents->size[0] = 1;
  exp_probe_o_1.contents->size[1] = b_b->size[1];
  emxEnsureCapacity_creal_T(sp, exp_probe_o_1.contents, i0, &c_emlrtRTEI);
  loop_ub = b_b->size[0] * b_b->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    exp_probe_o_1.contents->data[i0].re = Probes->h_prob_o_1 * b_b->data[i0].re;
    exp_probe_o_1.contents->data[i0].im = Probes->h_prob_o_1 * b_b->data[i0].im;
  }

  i0 = b_b->size[0] * b_b->size[1];
  b_b->size[0] = 1;
  b_b->size[1] = phi->size[1];
  emxEnsureCapacity_creal_T(sp, b_b, i0, &d_emlrtRTEI);
  loop_ub = phi->size[0] * phi->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    delta2 = phi->data[i0] * 0.0;
    delta1 = phi->data[i0];
    b_b->data[i0].re = Probes->mu_p_e_2 * delta2;
    b_b->data[i0].im = Probes->mu_p_e_2 * delta1;
  }

  c_emxInitStruct_coder_internal_(sp, &exp_probe_e_2, &e_emlrtRTEI, true);
  st.site = &d_emlrtRSI;
  b_exp(&st, b_b);
  i0 = exp_probe_e_2.contents->size[0] * exp_probe_e_2.contents->size[1];
  exp_probe_e_2.contents->size[0] = 1;
  exp_probe_e_2.contents->size[1] = b_b->size[1];
  emxEnsureCapacity_creal_T(sp, exp_probe_e_2.contents, i0, &e_emlrtRTEI);
  loop_ub = b_b->size[0] * b_b->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    exp_probe_e_2.contents->data[i0].re = Probes->h_prob_e_2 * b_b->data[i0].re;
    exp_probe_e_2.contents->data[i0].im = Probes->h_prob_e_2 * b_b->data[i0].im;
  }

  i0 = b_b->size[0] * b_b->size[1];
  b_b->size[0] = 1;
  b_b->size[1] = phi->size[1];
  emxEnsureCapacity_creal_T(sp, b_b, i0, &f_emlrtRTEI);
  loop_ub = phi->size[0] * phi->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    delta2 = phi->data[i0] * 0.0;
    delta1 = phi->data[i0];
    b_b->data[i0].re = Probes->mu_p_o_3 * delta2;
    b_b->data[i0].im = Probes->mu_p_o_3 * delta1;
  }

  c_emxInitStruct_coder_internal_(sp, &exp_probe_o_3, &g_emlrtRTEI, true);
  st.site = &e_emlrtRSI;
  b_exp(&st, b_b);
  i0 = exp_probe_o_3.contents->size[0] * exp_probe_o_3.contents->size[1];
  exp_probe_o_3.contents->size[0] = 1;
  exp_probe_o_3.contents->size[1] = b_b->size[1];
  emxEnsureCapacity_creal_T(sp, exp_probe_o_3.contents, i0, &g_emlrtRTEI);
  loop_ub = b_b->size[0] * b_b->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    exp_probe_o_3.contents->data[i0].re = Probes->h_prob_o_3 * b_b->data[i0].re;
    exp_probe_o_3.contents->data[i0].im = Probes->h_prob_o_3 * b_b->data[i0].im;
  }

  i0 = b_b->size[0] * b_b->size[1];
  b_b->size[0] = 1;
  b_b->size[1] = phi->size[1];
  emxEnsureCapacity_creal_T(sp, b_b, i0, &h_emlrtRTEI);
  loop_ub = phi->size[0] * phi->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    delta2 = phi->data[i0] * 0.0;
    delta1 = phi->data[i0];
    b_b->data[i0].re = Probes->mu_p_e_4 * delta2;
    b_b->data[i0].im = Probes->mu_p_e_4 * delta1;
  }

  c_emxInitStruct_coder_internal_(sp, &exp_probe_e_4, &i_emlrtRTEI, true);
  st.site = &f_emlrtRSI;
  b_exp(&st, b_b);
  i0 = exp_probe_e_4.contents->size[0] * exp_probe_e_4.contents->size[1];
  exp_probe_e_4.contents->size[0] = 1;
  exp_probe_e_4.contents->size[1] = b_b->size[1];
  emxEnsureCapacity_creal_T(sp, exp_probe_e_4.contents, i0, &i_emlrtRTEI);
  loop_ub = b_b->size[0] * b_b->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    exp_probe_e_4.contents->data[i0].re = Probes->h_prob_e_4 * b_b->data[i0].re;
    exp_probe_e_4.contents->data[i0].im = Probes->h_prob_e_4 * b_b->data[i0].im;
  }

  emxInit_creal_T(sp, &Psi_o_s, 2, &j_emlrtRTEI, true);
  i1 = 1U;
  j = NN;
  i0 = Psi_o_s->size[0] * Psi_o_s->size[1];
  d0 = Loops * per_loop;
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &ab_emlrtDCI, sp);
  }

  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &y_emlrtDCI, sp);
  }

  Psi_o_s->size[0] = (int32_T)d0;
  Psi_o_s->size[1] = 4;
  emxEnsureCapacity_creal_T(sp, Psi_o_s, i0, &j_emlrtRTEI);
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &hb_emlrtDCI, sp);
  }

  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &gb_emlrtDCI, sp);
  }

  loop_ub = (int32_T)d0 << 2;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Psi_o_s->data[i0].re = 0.0;
    Psi_o_s->data[i0].im = 0.0;
  }

  emxInit_creal_T(sp, &Psi_e_s, 2, &k_emlrtRTEI, true);

  /* size(1:2*N,2)/2) + 1i*zeros(Loops*per_loop,size(1:2*N,2)/2); */
  i0 = Psi_e_s->size[0] * Psi_e_s->size[1];
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &cb_emlrtDCI, sp);
  }

  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &bb_emlrtDCI, sp);
  }

  Psi_e_s->size[0] = (int32_T)d0;
  Psi_e_s->size[1] = 4;
  emxEnsureCapacity_creal_T(sp, Psi_e_s, i0, &k_emlrtRTEI);
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &jb_emlrtDCI, sp);
  }

  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &ib_emlrtDCI, sp);
  }

  loop_ub = (int32_T)d0 << 2;
  for (i0 = 0; i0 < loop_ub; i0++) {
    Psi_e_s->data[i0].re = 0.0;
    Psi_e_s->data[i0].im = 0.0;
  }

  /* size(1:2*N,2)/2) + 1i*zeros(Loops*per_loop,size(1:2*N,2)/2); */
  i0 = phi->size[0] * phi->size[1];
  phi->size[0] = 1;
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &eb_emlrtDCI, sp);
  }

  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &db_emlrtDCI, sp);
  }

  phi->size[1] = (int32_T)d0;
  emxEnsureCapacity_real_T(sp, phi, i0, &l_emlrtRTEI);
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, &lb_emlrtDCI, sp);
  }

  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, &kb_emlrtDCI, sp);
  }

  loop_ub = (int32_T)d0;
  for (i0 = 0; i0 < loop_ub; i0++) {
    phi->data[i0] = 0.0;
  }

  c_emxInitStruct_coder_internal_(sp, &k_o, &m_emlrtRTEI, true);

  /*  Define Time Steps inside the runge */
  if (!(N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N, &emlrtDCI, sp);
  }

  d0 = (int32_T)muDoubleScalarFloor(N);
  if (N != d0) {
    emlrtIntegerCheckR2012b(N, &b_emlrtDCI, sp);
  }

  i0 = k_o.contents->size[0] * k_o.contents->size[1];
  k_o.contents->size[0] = 1;
  loop_ub = (int32_T)N;
  k_o.contents->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, k_o.contents, i0, &m_emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    k_o.contents->data[i0].re = 0.0;
    k_o.contents->data[i0].im = 0.0;
  }

  c_emxInitStruct_coder_internal_(sp, &k_e, &n_emlrtRTEI, true);
  if (N != d0) {
    emlrtIntegerCheckR2012b(N, &c_emlrtDCI, sp);
  }

  i0 = k_e.contents->size[0] * k_e.contents->size[1];
  k_e.contents->size[0] = 1;
  k_e.contents->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, k_e.contents, i0, &n_emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    k_e.contents->data[i0].re = 0.0;
    k_e.contents->data[i0].im = 0.0;
  }

  c_emxInitStruct_coder_internal_(sp, &Nonlin_o, &o_emlrtRTEI, true);
  if (N != d0) {
    emlrtIntegerCheckR2012b(N, &d_emlrtDCI, sp);
  }

  i0 = Nonlin_o.contents->size[0] * Nonlin_o.contents->size[1];
  Nonlin_o.contents->size[0] = 1;
  Nonlin_o.contents->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, Nonlin_o.contents, i0, &o_emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Nonlin_o.contents->data[i0].re = 0.0;
    Nonlin_o.contents->data[i0].im = 0.0;
  }

  c_emxInitStruct_coder_internal_(sp, &Nonlin_e, &p_emlrtRTEI, true);
  if (N != d0) {
    emlrtIntegerCheckR2012b(N, &e_emlrtDCI, sp);
  }

  i0 = Nonlin_e.contents->size[0] * Nonlin_e.contents->size[1];
  Nonlin_e.contents->size[0] = 1;
  Nonlin_e.contents->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, Nonlin_e.contents, i0, &p_emlrtRTEI);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Nonlin_e.contents->data[i0].re = 0.0;
    Nonlin_e.contents->data[i0].im = 0.0;
  }

  /*       h = waitbar(0,'\chi_2,%'); */
  /*  */
  /*         Psi(1:N)     = ifft(exp( -1i*dt/2.*(L_o(1:N) ) ) .*fft(Psi(1:N))) ; */
  /*       Psi(N+1:2*N)  = ifft(exp( -1i*dt/2.*(L_e(1:N) ) ) .*fft(Psi(N+1:2*N))) ; */
  i0 = (int32_T)nt;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nt, mxDOUBLE_CLASS, (int32_T)nt,
    &ub_emlrtRTEI, sp);
  if (0 <= i0 - 1) {
    if (1.0 > N) {
      b_loop_ub = 0;
      c_loop_ub = 0;
      b_i1 = 0;
      d_loop_ub = 0;
    } else {
      if (N != d0) {
        emlrtIntegerCheckR2012b(N, &f_emlrtDCI, sp);
      }

      if ((loop_ub < 1) || (loop_ub > 32)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 32, &emlrtBCI, sp);
      }

      b_loop_ub = loop_ub;
      if (N != d0) {
        emlrtIntegerCheckR2012b(N, &g_emlrtDCI, sp);
      }

      if ((loop_ub < 1) || (loop_ub > 64)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 64, &b_emlrtBCI, sp);
      }

      c_loop_ub = loop_ub;
      if (N != d0) {
        emlrtIntegerCheckR2012b(N, &h_emlrtDCI, sp);
      }

      if ((loop_ub < 1) || (loop_ub > 64)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 64, &c_emlrtBCI, sp);
      }

      b_i1 = loop_ub;
      if (N != d0) {
        emlrtIntegerCheckR2012b(N, &i_emlrtDCI, sp);
      }

      if ((loop_ub < 1) || (loop_ub > 32)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 32, &d_emlrtBCI, sp);
      }

      d_loop_ub = loop_ub;
    }

    delta2 = 2.0 * N;
    if (N + 1.0 > delta2) {
      i3 = 0;
      i4 = 0;
    } else {
      if (N + 1.0 != (int32_T)muDoubleScalarFloor(N + 1.0)) {
        emlrtIntegerCheckR2012b(N + 1.0, &j_emlrtDCI, sp);
      }

      i3 = (int32_T)(N + 1.0);
      if ((i3 < 1) || (i3 > 64)) {
        emlrtDynamicBoundsCheckR2012b(i3, 1, 64, &e_emlrtBCI, sp);
      }

      i3--;
      if (delta2 != (int32_T)muDoubleScalarFloor(delta2)) {
        emlrtIntegerCheckR2012b(delta2, &k_emlrtDCI, sp);
      }

      i4 = (int32_T)delta2;
      if ((i4 < 1) || (i4 > 64)) {
        emlrtDynamicBoundsCheckR2012b(i4, 1, 64, &f_emlrtBCI, sp);
      }
    }

    e_loop_ub = i4 - i3;
    delta2 = 2.0 * N;
    if (N + 1.0 > delta2) {
      i5 = 1;
      i6 = 1;
    } else {
      if (N + 1.0 != (int32_T)muDoubleScalarFloor(N + 1.0)) {
        emlrtIntegerCheckR2012b(N + 1.0, &l_emlrtDCI, sp);
      }

      i5 = (int32_T)(N + 1.0);
      if ((i5 < 1) || (i5 > 64)) {
        emlrtDynamicBoundsCheckR2012b(i5, 1, 64, &g_emlrtBCI, sp);
      }

      if (delta2 != (int32_T)muDoubleScalarFloor(delta2)) {
        emlrtIntegerCheckR2012b(delta2, &m_emlrtDCI, sp);
      }

      i6 = (int32_T)delta2;
      if ((i6 < 1) || (i6 > 64)) {
        emlrtDynamicBoundsCheckR2012b(i6, 1, 64, &h_emlrtBCI, sp);
      }

      i6++;
    }

    if (1.0 > N) {
      f_loop_ub = 0;
      g_loop_ub = 0;
      i7 = 0;
      h_loop_ub = 0;
    } else {
      if (N != d0) {
        emlrtIntegerCheckR2012b(N, &n_emlrtDCI, sp);
      }

      if ((loop_ub < 1) || (loop_ub > 32)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 32, &i_emlrtBCI, sp);
      }

      f_loop_ub = loop_ub;
      if (N != d0) {
        emlrtIntegerCheckR2012b(N, &o_emlrtDCI, sp);
      }

      if ((loop_ub < 1) || (loop_ub > 64)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 64, &j_emlrtBCI, sp);
      }

      g_loop_ub = loop_ub;
      if (N != d0) {
        emlrtIntegerCheckR2012b(N, &p_emlrtDCI, sp);
      }

      if ((loop_ub < 1) || (loop_ub > 64)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 64, &k_emlrtBCI, sp);
      }

      i7 = loop_ub;
      if (N != d0) {
        emlrtIntegerCheckR2012b(N, &q_emlrtDCI, sp);
      }

      if ((loop_ub < 1) || (loop_ub > 32)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 32, &l_emlrtBCI, sp);
      }

      h_loop_ub = loop_ub;
    }

    delta2 = 2.0 * N;
    if (N + 1.0 > delta2) {
      i8 = 0;
      i9 = 0;
    } else {
      if (N + 1.0 != (int32_T)muDoubleScalarFloor(N + 1.0)) {
        emlrtIntegerCheckR2012b(N + 1.0, &r_emlrtDCI, sp);
      }

      i8 = (int32_T)(N + 1.0);
      if ((i8 < 1) || (i8 > 64)) {
        emlrtDynamicBoundsCheckR2012b(i8, 1, 64, &m_emlrtBCI, sp);
      }

      i8--;
      if (delta2 != (int32_T)muDoubleScalarFloor(delta2)) {
        emlrtIntegerCheckR2012b(delta2, &s_emlrtDCI, sp);
      }

      i9 = (int32_T)delta2;
      if ((i9 < 1) || (i9 > 64)) {
        emlrtDynamicBoundsCheckR2012b(i9, 1, 64, &n_emlrtBCI, sp);
      }
    }

    i_loop_ub = i9 - i8;
    delta2 = 2.0 * N;
    if (N + 1.0 > delta2) {
      i10 = 1;
      i11 = 1;
    } else {
      if (N + 1.0 != (int32_T)muDoubleScalarFloor(N + 1.0)) {
        emlrtIntegerCheckR2012b(N + 1.0, &t_emlrtDCI, sp);
      }

      i10 = (int32_T)(N + 1.0);
      if ((i10 < 1) || (i10 > 64)) {
        emlrtDynamicBoundsCheckR2012b(i10, 1, 64, &o_emlrtBCI, sp);
      }

      if (delta2 != (int32_T)muDoubleScalarFloor(delta2)) {
        emlrtIntegerCheckR2012b(delta2, &u_emlrtDCI, sp);
      }

      i11 = (int32_T)delta2;
      if ((i11 < 1) || (i11 > 64)) {
        emlrtDynamicBoundsCheckR2012b(i11, 1, 64, &p_emlrtBCI, sp);
      }

      i11++;
    }
  }

  for (ni = 0; ni < i0; ni++) {
    delta2 = 0.0 * dt;
    if (-dt == 0.0) {
      delta2 /= 2.0;
      delta1 = 0.0;
    } else if (delta2 == 0.0) {
      delta2 = 0.0;
      delta1 = -dt / 2.0;
    } else {
      delta2 = rtNaN;
      delta1 = -dt / 2.0;
    }

    i2 = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    b_b->size[1] = b_loop_ub;
    emxEnsureCapacity_creal_T(sp, b_b, i2, &s_emlrtRTEI);
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      b_b->data[i2].re = delta2 * L_o[i2].re - delta1 * L_o[i2].im;
      b_b->data[i2].im = delta2 * L_o[i2].im + delta1 * L_o[i2].re;
    }

    st.site = &g_emlrtRSI;
    b_exp(&st, b_b);
    tmp_size[1] = b_b->size[1];
    k = b_b->size[0] * b_b->size[1];
    for (i2 = 0; i2 < k; i2++) {
      tmp_data[i2] = b_b->data[i2];
    }

    Psi_size[0] = 1;
    Psi_size[1] = c_loop_ub;
    if (0 <= c_loop_ub - 1) {
      memcpy(&Psi_data[0], &Psi[0], (uint32_T)(c_loop_ub * (int32_T)sizeof
              (creal_T)));
    }

    st.site = &g_emlrtRSI;
    fft(Psi_data, Psi_size, Psi_o_k_data, Psi_o_k_size);
    Psi_e_k_size[0] = 1;
    Psi_o_k[0] = Psi_o_k_size[0];
    Psi_e_k_size[1] = tmp_size[1];
    Psi_o_k[1] = Psi_o_k_size[1];
    if ((1 != Psi_o_k_size[0]) || (tmp_size[1] != Psi_o_k_size[1])) {
      emlrtSizeEqCheckNDR2012b(&Psi_e_k_size[0], &Psi_o_k[0], &emlrtECI, sp);
    }

    b_tmp_size[0] = 1;
    b_tmp_size[1] = tmp_size[1];
    k = tmp_size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_tmp_data[i2].re = tmp_data[i2].re * Psi_o_k_data[i2].re - tmp_data[i2].
        im * Psi_o_k_data[i2].im;
      b_tmp_data[i2].im = tmp_data[i2].re * Psi_o_k_data[i2].im + tmp_data[i2].
        im * Psi_o_k_data[i2].re;
    }

    st.site = &g_emlrtRSI;
    ifft(b_tmp_data, b_tmp_size, tmp_data, tmp_size);
    if (b_i1 != tmp_size[1]) {
      emlrtSubAssignSizeCheck1dR2017a(b_i1, tmp_size[1], &b_emlrtECI, sp);
    }

    if (0 <= tmp_size[1] - 1) {
      memcpy(&Psi[0], &tmp_data[0], (uint32_T)(tmp_size[1] * (int32_T)sizeof
              (creal_T)));
    }

    delta2 = 0.0 * dt;
    if (-dt == 0.0) {
      delta2 /= 2.0;
      delta1 = 0.0;
    } else if (delta2 == 0.0) {
      delta2 = 0.0;
      delta1 = -dt / 2.0;
    } else {
      delta2 = rtNaN;
      delta1 = -dt / 2.0;
    }

    i2 = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    b_b->size[1] = d_loop_ub;
    emxEnsureCapacity_creal_T(sp, b_b, i2, &u_emlrtRTEI);
    for (i2 = 0; i2 < d_loop_ub; i2++) {
      b_b->data[i2].re = delta2 * L_e[i2].re - delta1 * L_e[i2].im;
      b_b->data[i2].im = delta2 * L_e[i2].im + delta1 * L_e[i2].re;
    }

    st.site = &h_emlrtRSI;
    b_exp(&st, b_b);
    tmp_size[1] = b_b->size[1];
    k = b_b->size[0] * b_b->size[1];
    for (i2 = 0; i2 < k; i2++) {
      tmp_data[i2] = b_b->data[i2];
    }

    b_Psi_size[0] = 1;
    b_Psi_size[1] = i4 - i3;
    for (i2 = 0; i2 < e_loop_ub; i2++) {
      Psi_data[i2] = Psi[i3 + i2];
    }

    st.site = &h_emlrtRSI;
    fft(Psi_data, b_Psi_size, Psi_o_k_data, Psi_o_k_size);
    Psi_e_k_size[0] = 1;
    Psi_o_k[0] = Psi_o_k_size[0];
    Psi_e_k_size[1] = tmp_size[1];
    Psi_o_k[1] = Psi_o_k_size[1];
    if ((1 != Psi_o_k_size[0]) || (tmp_size[1] != Psi_o_k_size[1])) {
      emlrtSizeEqCheckNDR2012b(&Psi_e_k_size[0], &Psi_o_k[0], &c_emlrtECI, sp);
    }

    c_tmp_size[0] = 1;
    c_tmp_size[1] = tmp_size[1];
    k = tmp_size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_tmp_data[i2].re = tmp_data[i2].re * Psi_o_k_data[i2].re - tmp_data[i2].
        im * Psi_o_k_data[i2].im;
      b_tmp_data[i2].im = tmp_data[i2].re * Psi_o_k_data[i2].im + tmp_data[i2].
        im * Psi_o_k_data[i2].re;
    }

    st.site = &h_emlrtRSI;
    ifft(b_tmp_data, c_tmp_size, tmp_data, tmp_size);
    k = tmp_size[1];
    i2 = i6 - i5;
    if (i2 != tmp_size[1]) {
      emlrtSubAssignSizeCheck1dR2017a(i2, tmp_size[1], &d_emlrtECI, sp);
    }

    for (i2 = 0; i2 < k; i2++) {
      Psi[(i5 + i2) - 1] = tmp_data[i2];
    }

    memcpy(&Psi_data[0], &Psi[0], sizeof(creal_T) << 6);
    st.site = &i_emlrtRSI;
    Runge_Kuarong_Kerr_step(&st, &b_N, &k_o, &k_e, &Nonlin_o, &Nonlin_e,
      &b_delta_o, &b_kappa_o, &b_gamma_o, &b_Pump, &exp_probe_o_1, &b_Probes,
      &exp_probe_o_3, &b_delta_e, &b_kappa_e, &b_gamma_e, &exp_probe_e_2,
      &exp_probe_e_4, &s, &a, &b, &c, Psi_data, dt, ((1.0 + (real_T)ni) - 1.0) *
      dt + t_start, Psi);
    delta2 = 0.0 * dt;
    if (-dt == 0.0) {
      delta2 /= 2.0;
      delta1 = 0.0;
    } else if (delta2 == 0.0) {
      delta2 = 0.0;
      delta1 = -dt / 2.0;
    } else {
      delta2 = rtNaN;
      delta1 = -dt / 2.0;
    }

    i2 = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    b_b->size[1] = f_loop_ub;
    emxEnsureCapacity_creal_T(sp, b_b, i2, &v_emlrtRTEI);
    for (i2 = 0; i2 < f_loop_ub; i2++) {
      b_b->data[i2].re = delta2 * L_o[i2].re - delta1 * L_o[i2].im;
      b_b->data[i2].im = delta2 * L_o[i2].im + delta1 * L_o[i2].re;
    }

    st.site = &j_emlrtRSI;
    b_exp(&st, b_b);
    tmp_size[1] = b_b->size[1];
    k = b_b->size[0] * b_b->size[1];
    for (i2 = 0; i2 < k; i2++) {
      tmp_data[i2] = b_b->data[i2];
    }

    c_Psi_size[0] = 1;
    c_Psi_size[1] = g_loop_ub;
    if (0 <= g_loop_ub - 1) {
      memcpy(&Psi_data[0], &Psi[0], (uint32_T)(g_loop_ub * (int32_T)sizeof
              (creal_T)));
    }

    st.site = &j_emlrtRSI;
    fft(Psi_data, c_Psi_size, Psi_o_k_data, Psi_o_k_size);
    Psi_e_k_size[0] = 1;
    Psi_o_k[0] = Psi_o_k_size[0];
    Psi_e_k_size[1] = tmp_size[1];
    Psi_o_k[1] = Psi_o_k_size[1];
    if ((1 != Psi_o_k_size[0]) || (tmp_size[1] != Psi_o_k_size[1])) {
      emlrtSizeEqCheckNDR2012b(&Psi_e_k_size[0], &Psi_o_k[0], &e_emlrtECI, sp);
    }

    d_tmp_size[0] = 1;
    d_tmp_size[1] = tmp_size[1];
    k = tmp_size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_tmp_data[i2].re = tmp_data[i2].re * Psi_o_k_data[i2].re - tmp_data[i2].
        im * Psi_o_k_data[i2].im;
      b_tmp_data[i2].im = tmp_data[i2].re * Psi_o_k_data[i2].im + tmp_data[i2].
        im * Psi_o_k_data[i2].re;
    }

    st.site = &j_emlrtRSI;
    ifft(b_tmp_data, d_tmp_size, tmp_data, tmp_size);
    if (i7 != tmp_size[1]) {
      emlrtSubAssignSizeCheck1dR2017a(i7, tmp_size[1], &f_emlrtECI, sp);
    }

    if (0 <= tmp_size[1] - 1) {
      memcpy(&Psi[0], &tmp_data[0], (uint32_T)(tmp_size[1] * (int32_T)sizeof
              (creal_T)));
    }

    delta2 = 0.0 * dt;
    if (-dt == 0.0) {
      delta2 /= 2.0;
      delta1 = 0.0;
    } else if (delta2 == 0.0) {
      delta2 = 0.0;
      delta1 = -dt / 2.0;
    } else {
      delta2 = rtNaN;
      delta1 = -dt / 2.0;
    }

    i2 = b_b->size[0] * b_b->size[1];
    b_b->size[0] = 1;
    b_b->size[1] = h_loop_ub;
    emxEnsureCapacity_creal_T(sp, b_b, i2, &w_emlrtRTEI);
    for (i2 = 0; i2 < h_loop_ub; i2++) {
      b_b->data[i2].re = delta2 * L_e[i2].re - delta1 * L_e[i2].im;
      b_b->data[i2].im = delta2 * L_e[i2].im + delta1 * L_e[i2].re;
    }

    st.site = &k_emlrtRSI;
    b_exp(&st, b_b);
    tmp_size[1] = b_b->size[1];
    k = b_b->size[0] * b_b->size[1];
    for (i2 = 0; i2 < k; i2++) {
      tmp_data[i2] = b_b->data[i2];
    }

    d_Psi_size[0] = 1;
    d_Psi_size[1] = i9 - i8;
    for (i2 = 0; i2 < i_loop_ub; i2++) {
      Psi_data[i2] = Psi[i8 + i2];
    }

    st.site = &k_emlrtRSI;
    fft(Psi_data, d_Psi_size, Psi_o_k_data, Psi_o_k_size);
    Psi_e_k_size[0] = 1;
    Psi_o_k[0] = Psi_o_k_size[0];
    Psi_e_k_size[1] = tmp_size[1];
    Psi_o_k[1] = Psi_o_k_size[1];
    if ((1 != Psi_o_k_size[0]) || (tmp_size[1] != Psi_o_k_size[1])) {
      emlrtSizeEqCheckNDR2012b(&Psi_e_k_size[0], &Psi_o_k[0], &g_emlrtECI, sp);
    }

    e_tmp_size[0] = 1;
    e_tmp_size[1] = tmp_size[1];
    k = tmp_size[1];
    for (i2 = 0; i2 < k; i2++) {
      b_tmp_data[i2].re = tmp_data[i2].re * Psi_o_k_data[i2].re - tmp_data[i2].
        im * Psi_o_k_data[i2].im;
      b_tmp_data[i2].im = tmp_data[i2].re * Psi_o_k_data[i2].im + tmp_data[i2].
        im * Psi_o_k_data[i2].re;
    }

    st.site = &k_emlrtRSI;
    ifft(b_tmp_data, e_tmp_size, tmp_data, tmp_size);
    k = tmp_size[1];
    i2 = i11 - i10;
    if (i2 != tmp_size[1]) {
      emlrtSubAssignSizeCheck1dR2017a(i2, tmp_size[1], &h_emlrtECI, sp);
    }

    for (i2 = 0; i2 < k; i2++) {
      Psi[(i10 + i2) - 1] = tmp_data[i2];
    }

    /*         U_m(:,ni) = Psi(index_m); */
    if (j == NN) {
      st.site = &l_emlrtRSI;
      i2 = phi->size[1];
      if (((int32_T)i1 < 1) || ((int32_T)i1 > i2)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)i1, 1, i2, &v_emlrtBCI, &st);
      }

      i2 = (int32_T)i1 - 1;
      phi->data[i2] = dt * (1.0 + (real_T)ni);
      if (1.0 > N) {
        k = 0;
      } else {
        if (N != d0) {
          emlrtIntegerCheckR2012b(N, &v_emlrtDCI, &st);
        }

        if ((loop_ub < 1) || (loop_ub > 64)) {
          emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 64, &q_emlrtBCI, &st);
        }

        k = loop_ub;
      }

      e_Psi_size[0] = 1;
      e_Psi_size[1] = k;
      if (0 <= k - 1) {
        memcpy(&Psi_data[0], &Psi[0], (uint32_T)(k * (int32_T)sizeof(creal_T)));
      }

      fft(Psi_data, e_Psi_size, Psi_o_k_data, Psi_o_k_size);
      k = Psi_o_k_size[0] * Psi_o_k_size[1] - 1;
      for (i12 = 0; i12 <= k; i12++) {
        if (Psi_o_k_data[i12].im == 0.0) {
          Psi_o_k_data[i12].re /= N;
          Psi_o_k_data[i12].im = 0.0;
        } else if (Psi_o_k_data[i12].re == 0.0) {
          Psi_o_k_data[i12].re = 0.0;
          Psi_o_k_data[i12].im /= N;
        } else {
          Psi_o_k_data[i12].re /= N;
          Psi_o_k_data[i12].im /= N;
        }
      }

      delta2 = 2.0 * N;
      if (N + 1.0 > delta2) {
        i12 = 0;
        k = 0;
      } else {
        if (N + 1.0 != (int32_T)muDoubleScalarFloor(N + 1.0)) {
          emlrtIntegerCheckR2012b(N + 1.0, &w_emlrtDCI, &st);
        }

        i12 = (int32_T)(N + 1.0);
        if ((i12 < 1) || (i12 > 64)) {
          emlrtDynamicBoundsCheckR2012b(i12, 1, 64, &r_emlrtBCI, &st);
        }

        i12--;
        if (delta2 != (int32_T)muDoubleScalarFloor(delta2)) {
          emlrtIntegerCheckR2012b(delta2, &x_emlrtDCI, &st);
        }

        k = (int32_T)delta2;
        if ((k < 1) || (k > 64)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, 64, &s_emlrtBCI, &st);
        }
      }

      f_Psi_size[0] = 1;
      Psi_size_tmp = k - i12;
      f_Psi_size[1] = Psi_size_tmp;
      for (k = 0; k < Psi_size_tmp; k++) {
        Psi_data[k] = Psi[i12 + k];
      }

      fft(Psi_data, f_Psi_size, Psi_e_k_data, Psi_e_k_size);
      k = Psi_e_k_size[0] * Psi_e_k_size[1] - 1;
      for (i12 = 0; i12 <= k; i12++) {
        if (Psi_e_k_data[i12].im == 0.0) {
          Psi_e_k_data[i12].re /= N;
          Psi_e_k_data[i12].im = 0.0;
        } else if (Psi_e_k_data[i12].re == 0.0) {
          Psi_e_k_data[i12].re = 0.0;
          Psi_e_k_data[i12].im /= N;
        } else {
          Psi_e_k_data[i12].re /= N;
          Psi_e_k_data[i12].im /= N;
        }
      }

      i12 = Psi_o_s->size[0];
      if (((int32_T)i1 < 1) || ((int32_T)i1 > i12)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)i1, 1, i12, &t_emlrtBCI, &st);
      }

      if (1 > Psi_o_k_size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, Psi_o_k_size[1], &w_emlrtBCI, &st);
      }

      Psi_o_s->data[i2].re = Psi_o_k_data[0].re;
      Psi_o_s->data[i2].im = Psi_o_k_data[0].im;
      if (2 > Psi_o_k_size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, Psi_o_k_size[1], &w_emlrtBCI, &st);
      }

      Psi_o_s->data[((int32_T)i1 + Psi_o_s->size[0]) - 1].re = Psi_o_k_data[1].
        re;
      Psi_o_s->data[((int32_T)i1 + Psi_o_s->size[0]) - 1].im = Psi_o_k_data[1].
        im;
      if (3 > Psi_o_k_size[1]) {
        emlrtDynamicBoundsCheckR2012b(3, 1, Psi_o_k_size[1], &w_emlrtBCI, &st);
      }

      Psi_o_s->data[((int32_T)i1 + (Psi_o_s->size[0] << 1)) - 1].re =
        Psi_o_k_data[2].re;
      Psi_o_s->data[((int32_T)i1 + (Psi_o_s->size[0] << 1)) - 1].im =
        Psi_o_k_data[2].im;
      if (4 > Psi_o_k_size[1]) {
        emlrtDynamicBoundsCheckR2012b(4, 1, Psi_o_k_size[1], &w_emlrtBCI, &st);
      }

      Psi_o_s->data[((int32_T)i1 + Psi_o_s->size[0] * 3) - 1].re = Psi_o_k_data
        [3].re;
      Psi_o_s->data[((int32_T)i1 + Psi_o_s->size[0] * 3) - 1].im = Psi_o_k_data
        [3].im;
      i12 = Psi_e_s->size[0];
      if (((int32_T)i1 < 1) || ((int32_T)i1 > i12)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)i1, 1, i12, &u_emlrtBCI, &st);
      }

      if (1 > Psi_e_k_size[1]) {
        emlrtDynamicBoundsCheckR2012b(1, 1, Psi_e_k_size[1], &x_emlrtBCI, &st);
      }

      Psi_e_s->data[i2].re = Psi_e_k_data[0].re;
      Psi_e_s->data[i2].im = Psi_e_k_data[0].im;
      if (2 > Psi_e_k_size[1]) {
        emlrtDynamicBoundsCheckR2012b(2, 1, Psi_e_k_size[1], &x_emlrtBCI, &st);
      }

      Psi_e_s->data[((int32_T)i1 + Psi_e_s->size[0]) - 1].re = Psi_e_k_data[1].
        re;
      Psi_e_s->data[((int32_T)i1 + Psi_e_s->size[0]) - 1].im = Psi_e_k_data[1].
        im;
      if (3 > Psi_e_k_size[1]) {
        emlrtDynamicBoundsCheckR2012b(3, 1, Psi_e_k_size[1], &x_emlrtBCI, &st);
      }

      Psi_e_s->data[((int32_T)i1 + (Psi_e_s->size[0] << 1)) - 1].re =
        Psi_e_k_data[2].re;
      Psi_e_s->data[((int32_T)i1 + (Psi_e_s->size[0] << 1)) - 1].im =
        Psi_e_k_data[2].im;
      if (4 > Psi_e_k_size[1]) {
        emlrtDynamicBoundsCheckR2012b(4, 1, Psi_e_k_size[1], &x_emlrtBCI, &st);
      }

      Psi_e_s->data[((int32_T)i1 + Psi_e_s->size[0] * 3) - 1].re = Psi_e_k_data
        [3].re;
      Psi_e_s->data[((int32_T)i1 + Psi_e_s->size[0] * 3) - 1].im = Psi_e_k_data
        [3].im;

      /*     waitbar(ni/nt,h,strcat(Delta.Initial_Guess,Delta.Physics,Delta.Runge_Type,'|||',sprintf('%.4f',ni/nt*100),'%' )) */
      i1++;
      j = 0.0;
    }

    j++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_creal_T(&b_b);
  c_emxFreeStruct_coder_internal_(&exp_probe_o_1);
  c_emxFreeStruct_coder_internal_(&exp_probe_e_2);
  c_emxFreeStruct_coder_internal_(&exp_probe_o_3);
  c_emxFreeStruct_coder_internal_(&exp_probe_e_4);
  c_emxFreeStruct_coder_internal_(&k_o);
  c_emxFreeStruct_coder_internal_(&k_e);
  c_emxFreeStruct_coder_internal_(&Nonlin_o);
  c_emxFreeStruct_coder_internal_(&Nonlin_e);
  i0 = Temporal->t->size[0] * Temporal->t->size[1];
  Temporal->t->size[0] = 1;
  Temporal->t->size[1] = phi->size[1];
  emxEnsureCapacity_real_T(sp, Temporal->t, i0, &q_emlrtRTEI);
  loop_ub = phi->size[0] * phi->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Temporal->t->data[i0] = phi->data[i0];
  }

  emxFree_real_T(&phi);

  /*     Temporal.l_s         = l_s; */
  /*     Temporal.U_m         = U_m; */
  i0 = Temporal->Psi_o_k->size[0] * Temporal->Psi_o_k->size[1];
  Temporal->Psi_o_k->size[0] = Psi_o_s->size[0];
  Temporal->Psi_o_k->size[1] = 4;
  emxEnsureCapacity_creal_T(sp, Temporal->Psi_o_k, i0, &r_emlrtRTEI);
  loop_ub = Psi_o_s->size[0] * Psi_o_s->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Temporal->Psi_o_k->data[i0] = Psi_o_s->data[i0];
  }

  emxFree_creal_T(&Psi_o_s);
  i0 = Temporal->Psi_e_k->size[0] * Temporal->Psi_e_k->size[1];
  Temporal->Psi_e_k->size[0] = Psi_e_s->size[0];
  Temporal->Psi_e_k->size[1] = 4;
  emxEnsureCapacity_creal_T(sp, Temporal->Psi_e_k, i0, &t_emlrtRTEI);
  loop_ub = Psi_e_s->size[0] * Psi_e_s->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    Temporal->Psi_e_k->data[i0] = Psi_e_s->data[i0];
  }

  emxFree_creal_T(&Psi_e_s);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Split_chi_2.cpp) */
