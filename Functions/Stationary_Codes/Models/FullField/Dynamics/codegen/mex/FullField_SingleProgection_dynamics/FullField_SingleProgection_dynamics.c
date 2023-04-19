/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FullField_SingleProgection_dynamics.c
 *
 * Code generation for function 'FullField_SingleProgection_dynamics'
 *
 */

/* Include files */
#include "FullField_SingleProgection_dynamics.h"
#include "FullField_SingleProgection_dynamics_data.h"
#include "FullField_SingleProgection_dynamics_emxutil.h"
#include "FullField_SingleProgection_dynamics_types.h"
#include "abs.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "fft.h"
#include "fftw.h"
#include "find.h"
#include "mod.h"
#include "power.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_captured_var
#define typedef_captured_var
typedef struct {
  real_T contents;
} captured_var;
#endif /* typedef_captured_var */

#ifndef typedef_b_captured_var
#define typedef_b_captured_var
typedef struct {
  struct7_T contents;
} b_captured_var;
#endif /* typedef_b_captured_var */

#ifndef typedef_d_captured_var
#define typedef_d_captured_var
typedef struct {
  creal_T contents[3];
} d_captured_var;
#endif /* typedef_d_captured_var */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,                                     /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    16,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    18,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    20,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    33,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    36,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    59,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    60,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    67,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    68,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    69,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    70,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    71,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    84,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    85,                                    /* lineNo */
    "FullField_SingleProgection_dynamics", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    7,         /* lineNo */
    "ref/ref", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/ref.m" /* pathName
                                                                       */
};

static emlrtRSInfo w_emlrtRSI = {
    15,    /* lineNo */
    "max", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/datafun/max.m" /* pathName
                                                                     */
};

static emlrtRSInfo x_emlrtRSI = {
    44,         /* lineNo */
    "minOrMax", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo y_emlrtRSI = {
    79,        /* lineNo */
    "maximum", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/minOrMax.m" /* pathName
                                                                            */
};

static emlrtRSInfo ab_emlrtRSI =
    {
        186,             /* lineNo */
        "unaryMinOrMax", /* fcnName */
        "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI =
    {
        897,                    /* lineNo */
        "maxRealVectorOmitNaN", /* fcnName */
        "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    62,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    54,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    103,         /* lineNo */
    "findFirst", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    120,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo gb_emlrtRSI = {
    39,                                                            /* lineNo */
    "find",                                                        /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/elmat/find.m" /* pathName
                                                                    */
};

static emlrtRSInfo pb_emlrtRSI = {
    130,                                                      /* lineNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    144,                                                      /* lineNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    169,                                                      /* lineNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo sb_emlrtRSI = {
    174,                                                      /* lineNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo tb_emlrtRSI = {
    182,                                                      /* lineNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo ub_emlrtRSI = {
    204,                                             /* lineNo */
    "FullField_SingleProgection_dynamics/Get_Field", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo vb_emlrtRSI = {
    206,                                             /* lineNo */
    "FullField_SingleProgection_dynamics/Get_Field", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

static emlrtRSInfo wb_emlrtRSI = {
    37,                                                            /* lineNo */
    "flip",                                                        /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/elmat/flip.m" /* pathName
                                                                    */
};

static emlrtRSInfo xb_emlrtRSI = {
    80,     /* lineNo */
    "ifft", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/datafun/ifft.m" /* pathName
                                                                      */
};

static emlrtRTEInfo emlrtRTEI =
    {
        130,             /* lineNo */
        27,              /* colNo */
        "unaryMinOrMax", /* fName */
        "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" /* pName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    118,                                   /* lineNo */
    21,                                    /* colNo */
    "Sol.Psi",                             /* aName */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    101,                                   /* lineNo */
    21,                                    /* colNo */
    "Sol.Psi",                             /* aName */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    101,                                   /* lineNo */
    21,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    86,                                    /* lineNo */
    39,                                    /* colNo */
    "Field",                               /* aName */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtRTEInfo c_emlrtRTEI = {
    79,                                    /* lineNo */
    14,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    -1,                                    /* nDims */
    60,                                    /* lineNo */
    9,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    -1,                                    /* nDims */
    59,                                    /* lineNo */
    9,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtDCInfo b_emlrtDCI = {
    43,                                    /* lineNo */
    26,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtECInfo c_emlrtECI = {
    2,                                     /* nDims */
    18,                                    /* lineNo */
    13,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtECInfo d_emlrtECI = {
    2,                                     /* nDims */
    16,                                    /* lineNo */
    13,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    14,                                    /* lineNo */
    13,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtDCInfo c_emlrtDCI = {
    3,                                     /* lineNo */
    35,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    3,                                     /* lineNo */
    35,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    4                                                           /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    3,                                     /* lineNo */
    43,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    3,                                     /* lineNo */
    43,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    4                                                           /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    13,                                    /* lineNo */
    19,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    24,                                    /* lineNo */
    59,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    30,                                    /* lineNo */
    59,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    47,                                    /* lineNo */
    29,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    47,                                    /* lineNo */
    29,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    4                                                           /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    50,                                    /* lineNo */
    39,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    51,                                    /* lineNo */
    39,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    51,                                    /* lineNo */
    39,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    4                                                           /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = {
    3,                                     /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = {
    13,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = {
    24,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    25,                                    /* lineNo */
    5,                                     /* colNo */
    "Eq.L",                                /* aName */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = {
    25,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = {
    30,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = {
    47,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = {
    50,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = {
    51,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    1,                                     /* iFirst */
    2048,                                  /* iLast */
    118,                                   /* lineNo */
    35,                                    /* colNo */
    "F_e",                                 /* aName */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = {
    118,                                   /* lineNo */
    35,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    119,                                   /* lineNo */
    21,                                    /* colNo */
    "Sol.t",                               /* aName */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    86,                                    /* lineNo */
    21,                                    /* colNo */
    "Sol.PsiReal",                         /* aName */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    1,                                     /* iFirst */
    2048,                                  /* iLast */
    101,                                   /* lineNo */
    37,                                    /* colNo */
    "F_e",                                 /* aName */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = {
    101,                                   /* lineNo */
    37,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    104,                                   /* lineNo */
    21,                                    /* colNo */
    "Sol.t",                               /* aName */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    130,                                                      /* lineNo */
    11,                                                       /* colNo */
    "d",                                                      /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtECInfo e_emlrtECI = {
    -1,                                                       /* nDims */
    130,                                                      /* lineNo */
    9,                                                        /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    132,                                                      /* lineNo */
    18,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    134,                                                      /* lineNo */
    22,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    138,                                                      /* lineNo */
    105,                                                      /* colNo */
    "d",                                                      /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    1,                                                        /* iFirst */
    3,                                                        /* iLast */
    144,                                                      /* lineNo */
    66,                                                       /* colNo */
    "exp_plus_omega",                                         /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    144,                                                      /* lineNo */
    15,                                                       /* colNo */
    "d",                                                      /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtECInfo f_emlrtECI = {
    -1,                                                       /* nDims */
    144,                                                      /* lineNo */
    13,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    150,                                                      /* lineNo */
    18,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtBCInfo n_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    154,                                                      /* lineNo */
    90,                                                       /* colNo */
    "d",                                                      /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = {
    160,                                                      /* lineNo */
    16,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    1,                                                        /* iFirst */
    2048,                                                     /* iLast */
    160,                                                      /* lineNo */
    16,                                                       /* colNo */
    "E_f",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    3                                                           /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    1,                                                        /* iFirst */
    3,                                                        /* iLast */
    152,                                                      /* lineNo */
    25,                                                       /* colNo */
    "Runge.c",                                                /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    1,                                                        /* iFirst */
    3,                                                        /* iLast */
    136,                                                      /* lineNo */
    28,                                                       /* colNo */
    "Runge.b",                                                /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    1,                                                        /* iFirst */
    3,                                                        /* iLast */
    136,                                                      /* lineNo */
    31,                                                       /* colNo */
    "Runge.b",                                                /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = {
    160,                                                      /* lineNo */
    42,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    1,                                                        /* iFirst */
    2048,                                                     /* iLast */
    160,                                                      /* lineNo */
    42,                                                       /* colNo */
    "E_f",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo cb_emlrtDCI = {
    154,                                                      /* lineNo */
    21,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    1,                                                        /* iFirst */
    2048,                                                     /* iLast */
    154,                                                      /* lineNo */
    21,                                                       /* colNo */
    "E_f",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    3                                                           /* checkKind */
};

static emlrtDCInfo db_emlrtDCI = {
    154,                                                      /* lineNo */
    50,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    1,                                                        /* iFirst */
    2048,                                                     /* iLast */
    154,                                                      /* lineNo */
    50,                                                       /* colNo */
    "E_f",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo eb_emlrtDCI = {
    160,                                                      /* lineNo */
    74,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    160,                                                      /* lineNo */
    74,                                                       /* colNo */
    "shift_back",                                             /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    1,                                                        /* iFirst */
    2048,                                                     /* iLast */
    138,                                                      /* lineNo */
    62,                                                       /* colNo */
    "E_temp",                                                 /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo fb_emlrtDCI = {
    138,                                                      /* lineNo */
    62,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo x_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    138,                                                      /* lineNo */
    108,                                                      /* colNo */
    "d",                                                      /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo gb_emlrtDCI = {
    138,                                                      /* lineNo */
    108,                                                      /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo hb_emlrtDCI = {
    154,                                                      /* lineNo */
    93,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo y_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    154,                                                      /* lineNo */
    93,                                                       /* colNo */
    "d",                                                      /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo ab_emlrtBCI = {
    1,                                                        /* iFirst */
    2048,                                                     /* iLast */
    138,                                                      /* lineNo */
    21,                                                       /* colNo */
    "E_temp",                                                 /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    3                                                           /* checkKind */
};

static emlrtDCInfo ib_emlrtDCI = {
    138,                                                      /* lineNo */
    21,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtECInfo g_emlrtECI = {
    2,                                                        /* nDims */
    174,                                                      /* lineNo */
    29,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtECInfo h_emlrtECI = {
    -1,                                                       /* nDims */
    174,                                                      /* lineNo */
    9,                                                        /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtECInfo i_emlrtECI = {
    -1,                                                       /* nDims */
    182,                                                      /* lineNo */
    9,                                                        /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtDCInfo jb_emlrtDCI = {
    191,                                                      /* lineNo */
    76,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    1,                                                        /* iFirst */
    1309,                                                     /* iLast */
    191,                                                      /* lineNo */
    76,                                                       /* colNo */
    "Eq.kappa",                                               /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtECInfo j_emlrtECI = {
    2,                                                        /* nDims */
    191,                                                      /* lineNo */
    28,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtECInfo k_emlrtECI = {
    -1,                                                       /* nDims */
    191,                                                      /* lineNo */
    9,                                                        /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtDCInfo kb_emlrtDCI = {
    165,                                                      /* lineNo */
    47,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo lb_emlrtDCI = {
    165,                                                      /* lineNo */
    47,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    4                                                           /* checkKind */
};

static emlrtDCInfo mb_emlrtDCI = {
    165,                                                      /* lineNo */
    9,                                                        /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo nb_emlrtDCI = {
    165,                                                      /* lineNo */
    9,                                                        /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    4                                                           /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    185,                                                      /* lineNo */
    36,                                                       /* colNo */
    "k_e",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    185,                                                      /* lineNo */
    9,                                                        /* colNo */
    "k_e",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    191,                                                      /* lineNo */
    32,                                                       /* colNo */
    "k_e",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo ob_emlrtDCI = {
    191,                                                      /* lineNo */
    32,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    191,                                                      /* lineNo */
    52,                                                       /* colNo */
    "Fac_plus",                                               /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo pb_emlrtDCI = {
    191,                                                      /* lineNo */
    52,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo qb_emlrtDCI = {
    191,                                                      /* lineNo */
    13,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    191,                                                      /* lineNo */
    13,                                                       /* colNo */
    "k_e",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    1,                                                        /* iFirst */
    2048,                                                     /* iLast */
    166,                                                      /* lineNo */
    9,                                                        /* colNo */
    "B_Psi",                                                  /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    166,                                                      /* lineNo */
    9,                                                        /* colNo */
    "k_e",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo rb_emlrtDCI = {
    166,                                                      /* lineNo */
    9,                                                        /* colNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    167,                                                      /* lineNo */
    31,                                                       /* colNo */
    "Fac_minus",                                              /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    186,                                                      /* lineNo */
    14,                                                       /* colNo */
    "k_zero",                                                 /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    186,                                                      /* lineNo */
    53,                                                       /* colNo */
    "k_zero",                                                 /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    185,                                                      /* lineNo */
    51,                                                       /* colNo */
    "Fac_plus",                                               /* aName */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    1,                                               /* iFirst */
    2048,                                            /* iLast */
    204,                                             /* lineNo */
    44,                                              /* colNo */
    "F_e",                                           /* aName */
    "FullField_SingleProgection_dynamics/Get_Field", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    204,                                             /* lineNo */
    16,                                              /* colNo */
    "F_e_shifted",                                   /* aName */
    "FullField_SingleProgection_dynamics/Get_Field", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    204,                                             /* lineNo */
    18,                                              /* colNo */
    "F_e_shifted",                                   /* aName */
    "FullField_SingleProgection_dynamics/Get_Field", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtECInfo l_emlrtECI = {
    -1,                                              /* nDims */
    204,                                             /* lineNo */
    4,                                               /* colNo */
    "FullField_SingleProgection_dynamics/Get_Field", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtDCInfo sb_emlrtDCI = {
    202,                                             /* lineNo */
    44,                                              /* colNo */
    "FullField_SingleProgection_dynamics/Get_Field", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtDCInfo tb_emlrtDCI = {
    202,                                             /* lineNo */
    44,                                              /* colNo */
    "FullField_SingleProgection_dynamics/Get_Field", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    4                                                           /* checkKind */
};

static emlrtDCInfo ub_emlrtDCI = {
    202,                                             /* lineNo */
    4,                                               /* colNo */
    "FullField_SingleProgection_dynamics/Get_Field", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    1,                                                        /* iFirst */
    2048,                                                     /* iLast */
    160,                                                      /* lineNo */
    12,                                                       /* colNo */
    "E_f",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    3                                                           /* checkKind */
};

static emlrtDCInfo vb_emlrtDCI = {
    160,                                                      /* lineNo */
    12,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    1,                                                        /* iFirst */
    2048,                                                     /* iLast */
    154,                                                      /* lineNo */
    17,                                                       /* colNo */
    "E_f",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    3                                                           /* checkKind */
};

static emlrtDCInfo wb_emlrtDCI = {
    154,                                                      /* lineNo */
    17,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    1,                                                        /* iFirst */
    2048,                                                     /* iLast */
    160,                                                      /* lineNo */
    38,                                                       /* colNo */
    "E_f",                                                    /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtDCInfo xb_emlrtDCI = {
    160,                                                      /* lineNo */
    38,                                                       /* colNo */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    1                                                           /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,                                                       /* iFirst */
    -1,                                                       /* iLast */
    160,                                                      /* lineNo */
    38,                                                       /* colNo */
    "shift_back",                                             /* aName */
    "FullField_SingleProgection_dynamics/Runge_Kuarong_step", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtRTEInfo k_emlrtRTEI = {
    3,                                     /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo l_emlrtRTEI = {
    28,                                                           /* lineNo */
    9,                                                            /* colNo */
    "colon",                                                      /* fName */
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/ops/colon.m" /* pName */
};

static emlrtRTEInfo m_emlrtRTEI = {
    10,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo n_emlrtRTEI = {
    13,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo o_emlrtRTEI = {
    16,                                    /* lineNo */
    57,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    16,                                    /* lineNo */
    53,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    16,                                    /* lineNo */
    47,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo r_emlrtRTEI = {
    16,                                    /* lineNo */
    17,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    20,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo t_emlrtRTEI = {
    24,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    16,                                    /* lineNo */
    9,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    18,                                    /* lineNo */
    57,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo w_emlrtRTEI = {
    27,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    18,                                    /* lineNo */
    53,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo y_emlrtRTEI = {
    28,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = {
    18,                                    /* lineNo */
    47,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = {
    30,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    18,                                    /* lineNo */
    17,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    18,                                    /* lineNo */
    9,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    32,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    33,                                    /* lineNo */
    21,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo gb_emlrtRTEI = {
    33,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    36,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo ib_emlrtRTEI = {
    43,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    47,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo kb_emlrtRTEI = {
    50,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    51,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    59,                                    /* lineNo */
    35,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    60,                                    /* lineNo */
    35,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    69,                                    /* lineNo */
    71,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    121,                                   /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    84,                                    /* lineNo */
    65,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = {
    7,                                     /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    70,                                    /* lineNo */
    5,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    1,                                     /* lineNo */
    16,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    31,                                                            /* lineNo */
    6,                                                             /* colNo */
    "find",                                                        /* fName */
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/elmat/find.m" /* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    130,                                   /* lineNo */
    46,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    130,                                   /* lineNo */
    66,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    130,                                   /* lineNo */
    119,                                   /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    144,                                   /* lineNo */
    51,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo gc_emlrtRTEI = {
    144,                                   /* lineNo */
    72,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    144,                                   /* lineNo */
    127,                                   /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    125,                                   /* lineNo */
    31,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = {
    165,                                   /* lineNo */
    9,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    174,                                   /* lineNo */
    38,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = {
    174,                                   /* lineNo */
    29,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    174,                                   /* lineNo */
    25,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI =
    {
        31,            /* lineNo */
        30,            /* colNo */
        "unsafeSxfun", /* fName */
        "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
        "unsafeSxfun.m" /* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = {
    182,                                   /* lineNo */
    25,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = {
    191,                                   /* lineNo */
    28,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    191,                                   /* lineNo */
    43,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    191,                                   /* lineNo */
    13,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    162,                                   /* lineNo */
    20,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = {
    202,                                   /* lineNo */
    4,                                     /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo uc_emlrtRTEI =
    {
        76,                  /* lineNo */
        9,                   /* colNo */
        "eml_mtimes_helper", /* fName */
        "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    206,                                   /* lineNo */
    33,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    18,                                    /* lineNo */
    13,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = {
    16,                                    /* lineNo */
    13,                                    /* colNo */
    "FullField_SingleProgection_dynamics", /* fName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pName */
};

static emlrtRSInfo kc_emlrtRSI = {
    191,                                                      /* lineNo */
    "FullField_SingleProgection_dynamics/Chi_3_LLE_Kuar_ins", /* fcnName */
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics.m" /* pathName */
};

/* Function Declarations */
static void Chi_3_LLE_Kuar_ins(
    const emlrtStack *sp, const captured_var *N, const c_captured_var *Temp,
    e_captured_var *Field, const f_captured_var *G_theta,
    const f_captured_var *ind_pump, creal_T B_Psi[2048],
    const emxArray_creal_T *Fac_plus, const emxArray_creal_T *Fac_minus,
    const creal_T pump_phase_substep, const real_T Eq_mode_range[1309],
    real_T Eq_Pump_ind_pump, real_T Eq_Pump_H, const real_T Eq_kappa[1309],
    const real_T Eq_gamma2[1309], const real_T Eq_gamma3[1309],
    emxArray_creal_T *k_zero, const creal_T pump_phase, emxArray_creal_T *k_e);

static void Get_Field(const emlrtStack *sp, real_T N, const creal_T F_e[2048],
                      emxArray_creal_T *Field);

static void Runge_Kuarong_step(
    const emlrtStack *sp, const captured_var *N, const c_captured_var *Temp,
    e_captured_var *Field, const f_captured_var *G_theta,
    const f_captured_var *ind_pump, const e_captured_var *exp_plus_omega,
    const e_captured_var *exp_minus_omega,
    const d_captured_var *pump_phase_substep, const b_captured_var *Runge,
    const e_captured_var *shift_back, const creal_T B_E[2048], real_T dt,
    const creal_T pump_phase, emxArray_creal_T *d,
    const emxArray_creal_T *k_zero);

static void b_Runge_Kuarong_step(
    const emlrtStack *sp, const captured_var *N, const c_captured_var *Temp,
    e_captured_var *Field, const f_captured_var *G_theta,
    const f_captured_var *ind_pump, const e_captured_var *exp_plus_omega,
    const e_captured_var *exp_minus_omega,
    const d_captured_var *pump_phase_substep, const b_captured_var *Runge,
    const e_captured_var *shift_back, creal_T B_E[2048], real_T dt,
    const creal_T pump_phase, emxArray_creal_T *d,
    const emxArray_creal_T *k_zero);

static void b_plus(const emlrtStack *sp, emxArray_creal_T *r3,
                   const emxArray_creal_T *x);

static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *x,
                             emlrtRSInfo lc_emlrtRSI,
                             const f_captured_var *G_theta,
                             const emxArray_creal_T *r1);

static void minus(const emlrtStack *sp, emxArray_real_T *G,
                  const emxArray_real_T *r1);

static void plus(const emlrtStack *sp, emxArray_real_T *G,
                 const emxArray_real_T *r1);

/* Function Definitions */
static void Chi_3_LLE_Kuar_ins(
    const emlrtStack *sp, const captured_var *N, const c_captured_var *Temp,
    e_captured_var *Field, const f_captured_var *G_theta,
    const f_captured_var *ind_pump, creal_T B_Psi[2048],
    const emxArray_creal_T *Fac_plus, const emxArray_creal_T *Fac_minus,
    const creal_T pump_phase_substep, const real_T Eq_mode_range[1309],
    real_T Eq_Pump_ind_pump, real_T Eq_Pump_H, const real_T Eq_kappa[1309],
    const real_T Eq_gamma2[1309], const real_T Eq_gamma3[1309],
    emxArray_creal_T *k_zero, const creal_T pump_phase, emxArray_creal_T *k_e)
{
  emlrtStack st;
  emxArray_creal_T *b_G_theta;
  emxArray_creal_T *r;
  emxArray_creal_T *x;
  emxArray_int32_T *r2;
  creal_T b_Fac_minus[1309];
  const creal_T *Fac_minus_data;
  const creal_T *Fac_plus_data;
  creal_T varargin_1;
  creal_T varargout_1;
  creal_T *G_theta_data;
  creal_T *k_e_data;
  creal_T *k_zero_data;
  creal_T *r1;
  real_T ai;
  real_T b_im;
  real_T b_r;
  real_T b_re;
  real_T b_re_tmp;
  real_T d;
  real_T im;
  real_T re;
  real_T re_tmp;
  real_T y;
  int32_T iv[2];
  int32_T b_k_e;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T *r3;
  st.prev = sp;
  st.tls = sp->tls;
  k_zero_data = k_zero->data;
  Fac_minus_data = Fac_minus->data;
  Fac_plus_data = Fac_plus->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  i = k_e->size[0] * k_e->size[1];
  k_e->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, k_e, i, &jc_emlrtRTEI);
  if (!(N->contents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N->contents, &lb_emlrtDCI, (emlrtCTX)sp);
  }
  d = N->contents;
  if (d != (int32_T)muDoubleScalarFloor(d)) {
    emlrtIntegerCheckR2012b(d, &kb_emlrtDCI, (emlrtCTX)sp);
  }
  i = k_e->size[0] * k_e->size[1];
  k_e->size[1] = (int32_T)d;
  emxEnsureCapacity_creal_T(sp, k_e, i, &jc_emlrtRTEI);
  k_e_data = k_e->data;
  if (!(N->contents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N->contents, &nb_emlrtDCI, (emlrtCTX)sp);
  }
  d = N->contents;
  if (d != (int32_T)muDoubleScalarFloor(d)) {
    emlrtIntegerCheckR2012b(d, &mb_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = (int32_T)d;
  for (i = 0; i < loop_ub; i++) {
    k_e_data[i].re = 0.0;
    k_e_data[i].im = 0.0;
  }
  b_k_e = k_e->size[1];
  for (i = 0; i < 1309; i++) {
    d = Eq_mode_range[i];
    if (((int32_T)d < 1) || ((int32_T)d > 2048)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, 2048, &hb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = (int32_T)muDoubleScalarFloor(d);
    if (d != i1) {
      emlrtIntegerCheckR2012b(d, &rb_emlrtDCI, (emlrtCTX)sp);
    }
    if ((int32_T)d > b_k_e) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, b_k_e, &ib_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    k_e_data[(int32_T)d - 1].re =
        -0.5 * Temp->contents.Eq.kappa[i] * B_Psi[(int32_T)d - 1].re;
    if ((int32_T)d != i1) {
      emlrtIntegerCheckR2012b(d, &rb_emlrtDCI, (emlrtCTX)sp);
    }
    if ((int32_T)d > b_k_e) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, b_k_e, &ib_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    k_e_data[(int32_T)d - 1].im =
        -0.5 * Temp->contents.Eq.kappa[i] * B_Psi[(int32_T)d - 1].im;
  }
  for (i = 0; i < 1309; i++) {
    d = Eq_mode_range[i];
    if (((int32_T)d < 1) || ((int32_T)d > Fac_minus->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Fac_minus->size[1],
                                    &jb_emlrtBCI, (emlrtCTX)sp);
    }
    im = Fac_minus_data[(int32_T)d - 1].re;
    y = B_Psi[(int32_T)d - 1].im;
    b_r = Fac_minus_data[(int32_T)d - 1].im;
    ai = B_Psi[(int32_T)d - 1].re;
    b_Fac_minus[i].re = im * ai - b_r * y;
    if ((int32_T)d > Fac_minus->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Fac_minus->size[1],
                                    &jb_emlrtBCI, (emlrtCTX)sp);
    }
    b_Fac_minus[i].im = im * y + b_r * ai;
  }
  for (i = 0; i < 1309; i++) {
    B_Psi[(int32_T)Eq_mode_range[i] - 1] = b_Fac_minus[i];
  }
  emxInit_creal_T(sp, &r, &nc_emlrtRTEI);
  st.site = &rb_emlrtRSI;
  Get_Field(&st, N->contents / 2.0, B_Psi, Field->contents);
  /*     GField        = ifft(B_Psi)*N/2; */
  /*     B_Psi     */
  /*     E_1  = B_Psi(185).*exp(1i*Temp.Space.phi*m(185)); */
  /*     E_2  = B_Psi(185).*exp(1i*Temp.Space.phi*m(185)); */
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = Field->contents->size[1];
  emxEnsureCapacity_creal_T(sp, r, i, &kc_emlrtRTEI);
  r1 = r->data;
  loop_ub = Field->contents->size[1];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = Field->contents->data[i];
    varargout_1.re =
        varargin_1.re * varargin_1.re - varargin_1.im * varargin_1.im;
    b_r = varargin_1.re * varargin_1.im;
    varargout_1.im = b_r + b_r;
    r1[i] = varargout_1;
  }
  i = G_theta->contents->size[1];
  if ((i != r->size[1]) && ((i != 1) && (r->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(i, r->size[1], &g_emlrtECI, (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &x, &mc_emlrtRTEI);
  if (G_theta->contents->size[1] == r->size[1]) {
    emxInit_creal_T(sp, &b_G_theta, &lc_emlrtRTEI);
    i = b_G_theta->size[0] * b_G_theta->size[1];
    b_G_theta->size[0] = 1;
    b_G_theta->size[1] = G_theta->contents->size[1];
    emxEnsureCapacity_creal_T(sp, b_G_theta, i, &lc_emlrtRTEI);
    G_theta_data = b_G_theta->data;
    loop_ub = G_theta->contents->size[1];
    for (i = 0; i < loop_ub; i++) {
      G_theta_data[i].re = G_theta->contents->data[i] * r1[i].re;
      G_theta_data[i].im = G_theta->contents->data[i] * r1[i].im;
    }
    st.site = &sb_emlrtRSI;
    fft(&st, b_G_theta, x);
    emxFree_creal_T(sp, &b_G_theta);
  } else {
    st.site = &sb_emlrtRSI;
    binary_expand_op(&st, x, sb_emlrtRSI, G_theta, r);
  }
  y = N->contents;
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, x, i, &mc_emlrtRTEI);
  G_theta_data = x->data;
  loop_ub = x->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_r = G_theta_data[i].re;
    ai = G_theta_data[i].im;
    if (ai == 0.0) {
      re = b_r / y;
      b_im = 0.0;
    } else if (b_r == 0.0) {
      re = 0.0;
      b_im = ai / y;
    } else {
      re = b_r / y;
      b_im = ai / y;
    }
    G_theta_data[i].re = re;
    G_theta_data[i].im = b_im;
  }
  iv[0] = 1;
  iv[1] = k_zero->size[1];
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &x->size[0], 2, &h_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = x->size[1];
  for (i = 0; i < loop_ub; i++) {
    k_zero_data[2 * i] = G_theta_data[i];
  }
  /*     exp(1i*Temp.Space.phi*411)*B_Psi(412) +
   * exp(1i*Temp.Space.phi*411)*B_Psi(412) */
  /*     k_zero(1,:)   = fft(G_theta.*(E_1.^2+E_2.*E_1)/N;%Field.^2 */
  /*    k_zero(1,1:2048)   = fft(GG_theta.*( GField.^2 +
   * GField.*conj(GField)))/N*2; */
  /*     k_zero(1,185) =
   * 1/2*B_Psi(412).*conj(B_Psi(185))+1/2*B_Psi(326).*conj(B_Psi(185)); */
  /*    k_zero(1,326) = 1/2*B_Psi(185).^2; */
  /*   k_zero(1,412) = 1/2*B_Psi(185).^2; */
  /*   mode_cut(Eq.mode_range).*   */
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = Field->contents->size[1];
  emxEnsureCapacity_creal_T(sp, r, i, &nc_emlrtRTEI);
  r1 = r->data;
  loop_ub = Field->contents->size[1];
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = Field->contents->data[i];
    if ((varargin_1.im == 0.0) && (varargin_1.re >= 0.0)) {
      varargout_1.re = muDoubleScalarPower(varargin_1.re, 3.0);
      varargout_1.im = 0.0;
    } else if (varargin_1.re == 0.0) {
      varargout_1.re = 0.0;
      varargout_1.im = -muDoubleScalarPower(varargin_1.im, 3.0);
    } else {
      if (varargin_1.im == 0.0) {
        if (varargin_1.re < 0.0) {
          b_r = muDoubleScalarLog(muDoubleScalarAbs(varargin_1.re));
          y = 3.1415926535897931;
        } else {
          b_r = muDoubleScalarLog(varargin_1.re);
          y = 0.0;
        }
      } else if ((muDoubleScalarAbs(varargin_1.re) > 8.9884656743115785E+307) ||
                 (muDoubleScalarAbs(varargin_1.im) > 8.9884656743115785E+307)) {
        b_r = muDoubleScalarLog(muDoubleScalarHypot(varargin_1.re / 2.0,
                                                    varargin_1.im / 2.0)) +
              0.69314718055994529;
        y = muDoubleScalarAtan2(varargin_1.im, varargin_1.re);
      } else {
        b_r = muDoubleScalarLog(
            muDoubleScalarHypot(varargin_1.re, varargin_1.im));
        y = muDoubleScalarAtan2(varargin_1.im, varargin_1.re);
      }
      varargout_1.re = 3.0 * b_r;
      varargout_1.im = 3.0 * y;
      if (varargout_1.im == 0.0) {
        d = varargout_1.re;
        varargout_1.re = muDoubleScalarExp(d);
        varargout_1.im = 0.0;
      } else if (muDoubleScalarIsInf(varargout_1.im) &&
                 muDoubleScalarIsInf(varargout_1.re) &&
                 (varargout_1.re < 0.0)) {
        varargout_1.re = 0.0;
        varargout_1.im = 0.0;
      } else {
        b_r = muDoubleScalarExp(varargout_1.re / 2.0);
        d = varargout_1.im;
        im = varargout_1.im;
        varargout_1.re = b_r * (b_r * muDoubleScalarCos(d));
        varargout_1.im = b_r * (b_r * muDoubleScalarSin(im));
      }
    }
    r1[i] = varargout_1;
  }
  st.site = &tb_emlrtRSI;
  fft(&st, r, x);
  y = N->contents;
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, x, i, &oc_emlrtRTEI);
  G_theta_data = x->data;
  loop_ub = x->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_r = G_theta_data[i].re;
    ai = G_theta_data[i].im;
    if (ai == 0.0) {
      re = b_r / y;
      b_im = 0.0;
    } else if (b_r == 0.0) {
      re = 0.0;
      b_im = ai / y;
    } else {
      re = b_r / y;
      b_im = ai / y;
    }
    G_theta_data[i].re = re;
    G_theta_data[i].im = b_im;
  }
  iv[0] = 1;
  iv[1] = k_zero->size[1];
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &x->size[0], 2, &i_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = x->size[1];
  for (i = 0; i < loop_ub; i++) {
    k_zero_data[2 * i + 1] = G_theta_data[i];
  }
  /* mode_cut(Eq.mode_range).* */
  b_k_e = k_e->size[1];
  for (i = 0; i < 1309; i++) {
    b_im = Eq_gamma2[i];
    re = b_im * 0.0;
    d = Eq_mode_range[i];
    if (((int32_T)d < 1) || ((int32_T)d > k_zero->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, k_zero->size[1],
                                    &kb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)d > k_zero->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, k_zero->size[1],
                                    &kb_emlrtBCI, (emlrtCTX)sp);
    }
    loop_ub = 2 * ((int32_T)d - 1);
    y = k_zero_data[loop_ub].im;
    ai = k_zero_data[loop_ub].re;
    if ((int32_T)d > k_zero->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, k_zero->size[1],
                                    &kb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)d > k_zero->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, k_zero->size[1],
                                    &kb_emlrtBCI, (emlrtCTX)sp);
    }
    im = Eq_gamma3[i];
    b_r = im * 0.0;
    if ((int32_T)d > k_zero->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, k_zero->size[1],
                                    &lb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)d > k_zero->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, k_zero->size[1],
                                    &lb_emlrtBCI, (emlrtCTX)sp);
    }
    re_tmp = k_zero_data[loop_ub + 1].im;
    b_re_tmp = k_zero_data[loop_ub + 1].re;
    if ((int32_T)d > k_zero->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, k_zero->size[1],
                                    &lb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)d > k_zero->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, k_zero->size[1],
                                    &lb_emlrtBCI, (emlrtCTX)sp);
    }
    b_re = (re * ai - b_im * y) + (b_r * b_re_tmp - im * re_tmp);
    b_im = (re * y + b_im * ai) + (b_r * re_tmp + im * b_re_tmp);
    if ((int32_T)d > Fac_plus->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Fac_plus->size[1],
                                    &mb_emlrtBCI, (emlrtCTX)sp);
    }
    b_r = Fac_plus_data[(int32_T)d - 1].re;
    y = Fac_plus_data[(int32_T)d - 1].im;
    if ((int32_T)d > Fac_plus->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, Fac_plus->size[1],
                                    &mb_emlrtBCI, (emlrtCTX)sp);
    }
    if ((int32_T)d > k_e->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, k_e->size[1], &cb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_Fac_minus[i].re = k_e_data[(int32_T)d - 1].re + (b_r * b_re - y * b_im);
    if ((int32_T)d > k_e->size[1]) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, k_e->size[1], &cb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_Fac_minus[i].im = k_e_data[(int32_T)d - 1].im + (b_r * b_im + y * b_re);
  }
  for (i = 0; i < 1309; i++) {
    d = Eq_mode_range[i];
    if (((int32_T)d < 1) || ((int32_T)d > b_k_e)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, b_k_e, &db_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    k_e_data[(int32_T)d - 1].re = b_Fac_minus[i].re;
    if ((int32_T)d > b_k_e) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, b_k_e, &db_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    k_e_data[(int32_T)d - 1].im = b_Fac_minus[i].im;
  }
  /*     k_e                = k_e - 1/2*Eq.kappa.*B_Psi; */
  /*  Fac_plus(Eq.Pump.ind_pump).* */
  /* -Fac_minus(Eq.Pump.ind_pump).*1/2*Eq.kappa(Eq.Pump.ind_pump).*B_Psi(Eq.Pump.ind_pump)
   */
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = ind_pump->contents->size[1];
  emxEnsureCapacity_creal_T(sp, r, i, &pc_emlrtRTEI);
  r1 = r->data;
  loop_ub = ind_pump->contents->size[1];
  for (i = 0; i < loop_ub; i++) {
    i1 = (int32_T)muDoubleScalarFloor(ind_pump->contents->data[i]);
    if (ind_pump->contents->data[i] != i1) {
      emlrtIntegerCheckR2012b(ind_pump->contents->data[i], &ob_emlrtDCI,
                              (emlrtCTX)sp);
    }
    b_k_e = (int32_T)ind_pump->contents->data[i];
    if ((b_k_e < 1) || (b_k_e > k_e->size[1])) {
      emlrtDynamicBoundsCheckR2012b(b_k_e, 1, k_e->size[1], &eb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    r1[i].re = k_e_data[b_k_e - 1].re;
    if (ind_pump->contents->data[i] != i1) {
      emlrtIntegerCheckR2012b(ind_pump->contents->data[i], &ob_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (b_k_e > k_e->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_k_e, 1, k_e->size[1], &eb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    r1[i].im = k_e_data[b_k_e - 1].im;
  }
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = ind_pump->contents->size[1];
  emxEnsureCapacity_creal_T(sp, x, i, &qc_emlrtRTEI);
  G_theta_data = x->data;
  loop_ub = ind_pump->contents->size[1];
  for (i = 0; i < loop_ub; i++) {
    i1 = (int32_T)muDoubleScalarFloor(ind_pump->contents->data[i]);
    if (ind_pump->contents->data[i] != i1) {
      emlrtIntegerCheckR2012b(ind_pump->contents->data[i], &pb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    b_k_e = (int32_T)ind_pump->contents->data[i];
    if ((b_k_e < 1) || (b_k_e > Fac_plus->size[1])) {
      emlrtDynamicBoundsCheckR2012b(b_k_e, 1, Fac_plus->size[1], &fb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    G_theta_data[i].re = Fac_plus_data[b_k_e - 1].re;
    if (ind_pump->contents->data[i] != i1) {
      emlrtIntegerCheckR2012b(ind_pump->contents->data[i], &pb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (b_k_e > Fac_plus->size[1]) {
      emlrtDynamicBoundsCheckR2012b(b_k_e, 1, Fac_plus->size[1], &fb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    G_theta_data[i].im = Fac_plus_data[b_k_e - 1].im;
  }
  if (Eq_Pump_ind_pump != (int32_T)muDoubleScalarFloor(Eq_Pump_ind_pump)) {
    emlrtIntegerCheckR2012b(Eq_Pump_ind_pump, &jb_emlrtDCI, (emlrtCTX)sp);
  }
  if (((int32_T)Eq_Pump_ind_pump < 1) || ((int32_T)Eq_Pump_ind_pump > 1309)) {
    emlrtDynamicBoundsCheckR2012b((int32_T)Eq_Pump_ind_pump, 1, 1309,
                                  &bb_emlrtBCI, (emlrtCTX)sp);
  }
  i = x->size[0] * x->size[1];
  x->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, x, i, &qc_emlrtRTEI);
  G_theta_data = x->data;
  loop_ub = x->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_r = G_theta_data[i].re;
    ai = G_theta_data[i].im;
    if (ai == 0.0) {
      im = b_r / 2.0;
      b_r = 0.0;
    } else if (b_r == 0.0) {
      im = 0.0;
      b_r = ai / 2.0;
    } else {
      im = b_r / 2.0;
      b_r = ai / 2.0;
    }
    y = Eq_kappa[(int32_T)Eq_Pump_ind_pump - 1];
    im = Eq_Pump_H * (y * im);
    b_r = Eq_Pump_H * (y * b_r);
    y = im * pump_phase_substep.re - b_r * pump_phase_substep.im;
    b_r = im * pump_phase_substep.im + b_r * pump_phase_substep.re;
    G_theta_data[i].re = y * pump_phase.re - b_r * pump_phase.im;
    G_theta_data[i].im = y * pump_phase.im + b_r * pump_phase.re;
  }
  i = ind_pump->contents->size[1];
  if ((i != x->size[1]) && ((i != 1) && (x->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(i, x->size[1], &j_emlrtECI, (emlrtCTX)sp);
  }
  emxInit_int32_T(sp, &r2, &sc_emlrtRTEI);
  i = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = ind_pump->contents->size[1];
  emxEnsureCapacity_int32_T(sp, r2, i, &rc_emlrtRTEI);
  r3 = r2->data;
  loop_ub = ind_pump->contents->size[1];
  for (i = 0; i < loop_ub; i++) {
    if (ind_pump->contents->data[i] !=
        (int32_T)muDoubleScalarFloor(ind_pump->contents->data[i])) {
      emlrtIntegerCheckR2012b(ind_pump->contents->data[i], &qb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    i1 = (int32_T)ind_pump->contents->data[i];
    if ((i1 < 1) || (i1 > k_e->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)ind_pump->contents->data[i], 1,
                                    k_e->size[1], &gb_emlrtBCI, (emlrtCTX)sp);
    }
    r3[i] = i1;
  }
  if (r->size[1] == x->size[1]) {
    loop_ub = r->size[1] - 1;
    i = r->size[0] * r->size[1];
    r->size[0] = 1;
    emxEnsureCapacity_creal_T(sp, r, i, &pc_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i <= loop_ub; i++) {
      r1[i].re += G_theta_data[i].re;
      r1[i].im += G_theta_data[i].im;
    }
  } else {
    st.site = &kc_emlrtRSI;
    b_plus(&st, r, x);
    r1 = r->data;
  }
  emxFree_creal_T(sp, &x);
  if (r2->size[1] != r->size[1]) {
    emlrtSubAssignSizeCheck1dR2017a(r2->size[1], r->size[1], &k_emlrtECI,
                                    (emlrtCTX)sp);
  }
  loop_ub = r->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    k_e_data[r3[i] - 1] = r1[i];
  }
  emxFree_int32_T(sp, &r2);
  emxFree_creal_T(sp, &r);
  /*     k_e(ind_pump)    = k_e(ind_pump) +
   * 1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1).*pump_phase_substep*pump_phase;
   */
  /*     k_e(ind_pump)    = k_e(ind_pump) +
   * Fac_plus(ind_pump).*1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1).*pump_phase_substep*pump_phase;
   */
  /*     k_e(ind_pump)    = k_e(ind_pump)+
   * 1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1).*exp(1i*Temp.Eq.Pump.delta*t);
   */
  /*     k_e(ind_pump)    = k_e(ind_pump)+
   * 1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1)*pump_phase_substep*pump_phase;
   */
  /* Fac_plus(Eq.Pump.ind_pump).*Fac_plus(Eq.Pump.ind_pump).*
   * Fac_minus(Eq.Pump.ind_pump).* */
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void Get_Field(const emlrtStack *sp, real_T N, const creal_T F_e[2048],
                      emxArray_creal_T *Field)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  emxArray_creal_T *F_e_shifted;
  emxArray_creal_T *y;
  creal_T tmp_data[2048];
  creal_T *F_e_shifted_data;
  creal_T *y_data;
  real_T tmp_im;
  real_T tmp_re;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T k;
  int32_T loop_ub;
  int32_T nd2;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_creal_T(sp, &F_e_shifted, &tc_emlrtRTEI);
  i = F_e_shifted->size[0] * F_e_shifted->size[1];
  F_e_shifted->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, F_e_shifted, i, &tc_emlrtRTEI);
  if (!(N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N, &tb_emlrtDCI, (emlrtCTX)sp);
  }
  tmp_re = (int32_T)muDoubleScalarFloor(N);
  if (N != tmp_re) {
    emlrtIntegerCheckR2012b(N, &sb_emlrtDCI, (emlrtCTX)sp);
  }
  i = F_e_shifted->size[0] * F_e_shifted->size[1];
  loop_ub = (int32_T)N;
  F_e_shifted->size[1] = (int32_T)N;
  emxEnsureCapacity_creal_T(sp, F_e_shifted, i, &tc_emlrtRTEI);
  F_e_shifted_data = F_e_shifted->data;
  if (N != tmp_re) {
    emlrtIntegerCheckR2012b(N, &ub_emlrtDCI, (emlrtCTX)sp);
  }
  for (i = 0; i < loop_ub; i++) {
    F_e_shifted_data[i].re = 0.0;
    F_e_shifted_data[i].im = 0.0;
  }
  /*    F_e_shifted(2:N)    =   conj(F_e(N:-1:2)); */
  if (2.0 > N) {
    i = 0;
    k = 0;
    i1 = 0;
    i2 = 0;
  } else {
    i = 1;
    if (((int32_T)N < 1) || ((int32_T)N > 2048)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)N, 1, 2048, &nb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    k = (int32_T)N;
    if (2 > F_e_shifted->size[1]) {
      emlrtDynamicBoundsCheckR2012b(2, 1, F_e_shifted->size[1], &ob_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    i1 = 1;
    if (((int32_T)N < 1) || ((int32_T)N > F_e_shifted->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)N, 1, F_e_shifted->size[1],
                                    &pb_emlrtBCI, (emlrtCTX)sp);
    }
    i2 = (int32_T)N;
  }
  st.site = &ub_emlrtRSI;
  loop_ub = k - i;
  for (k = 0; k < loop_ub; k++) {
    nd2 = i + k;
    tmp_data[k].re = F_e[nd2].re;
    tmp_data[k].im = -F_e[nd2].im;
  }
  if ((loop_ub != 0) && (loop_ub > 1)) {
    nd2 = loop_ub >> 1;
    b_st.site = &wb_emlrtRSI;
    for (k = 0; k < nd2; k++) {
      tmp_re = tmp_data[k].re;
      tmp_im = tmp_data[k].im;
      i = (loop_ub - k) - 1;
      tmp_data[k] = tmp_data[i];
      tmp_data[i].re = tmp_re;
      tmp_data[i].im = tmp_im;
    }
  }
  i = i2 - i1;
  if (i != loop_ub) {
    emlrtSubAssignSizeCheck1dR2017a(i, loop_ub, &l_emlrtECI, (emlrtCTX)sp);
  }
  for (i = 0; i < loop_ub; i++) {
    F_e_shifted_data[i1 + i] = tmp_data[i];
  }
  emxInit_creal_T(sp, &y, &wc_emlrtRTEI);
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = F_e_shifted->size[1] + 2048;
  emxEnsureCapacity_creal_T(sp, y, i, &uc_emlrtRTEI);
  y_data = y->data;
  for (i = 0; i < 2048; i++) {
    y_data[i].re = N * (2.0 * F_e[i].re);
    y_data[i].im = N * (2.0 * F_e[i].im);
  }
  loop_ub = F_e_shifted->size[1];
  for (i = 0; i < loop_ub; i++) {
    y_data[i + 2048].re = N * (2.0 * F_e_shifted_data[i].re);
    y_data[i + 2048].im = N * (2.0 * F_e_shifted_data[i].im);
  }
  emxFree_creal_T(sp, &F_e_shifted);
  st.site = &vb_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &yb_emlrtRSI;
  d_st.site = &ac_emlrtRSI;
  e_st.site = &bc_emlrtRSI;
  f_st.site = &cc_emlrtRSI;
  emlrtFFTWSetNumThreads(36);
  i = Field->size[0] * Field->size[1];
  Field->size[0] = 1;
  Field->size[1] = y->size[1];
  emxEnsureCapacity_creal_T(&f_st, Field, i, &vc_emlrtRTEI);
  F_e_shifted_data = Field->data;
  emlrtFFTW_1D_C2C((real_T *)&y_data[0], (real_T *)&F_e_shifted_data[0], 1,
                   y->size[1], y->size[1], 1, 1);
  emxFree_creal_T(sp, &y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void Runge_Kuarong_step(
    const emlrtStack *sp, const captured_var *N, const c_captured_var *Temp,
    e_captured_var *Field, const f_captured_var *G_theta,
    const f_captured_var *ind_pump, const e_captured_var *exp_plus_omega,
    const e_captured_var *exp_minus_omega,
    const d_captured_var *pump_phase_substep, const b_captured_var *Runge,
    const e_captured_var *shift_back, const creal_T B_E[2048], real_T dt,
    const creal_T pump_phase, emxArray_creal_T *d,
    const emxArray_creal_T *k_zero)
{
  emlrtStack st;
  emxArray_creal_T *b_exp_minus_omega;
  emxArray_creal_T *b_exp_plus_omega;
  emxArray_creal_T *b_k_zero;
  emxArray_creal_T *r;
  creal_T E_temp[2048];
  creal_T b_B_E[2048];
  creal_T b_E_temp[1309];
  const creal_T *k_zero_data;
  creal_T *d_data;
  creal_T *exp_plus_omega_data;
  real_T b_d;
  real_T b_dt;
  real_T d1;
  int32_T iv[2];
  int32_T b_i2;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T ii;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  k_zero_data = k_zero->data;
  d_data = d->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*     Sol.Pric = F_Intermid;  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  memcpy(&E_temp[0], &B_E[0], 2048U * sizeof(creal_T));
  if (1 > d->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, d->size[0], &j_emlrtBCI, (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &b_exp_plus_omega, &cc_emlrtRTEI);
  loop_ub = exp_plus_omega->contents->size[1];
  i = b_exp_plus_omega->size[0] * b_exp_plus_omega->size[1];
  b_exp_plus_omega->size[0] = 1;
  b_exp_plus_omega->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, b_exp_plus_omega, i, &cc_emlrtRTEI);
  exp_plus_omega_data = b_exp_plus_omega->data;
  for (i = 0; i < loop_ub; i++) {
    exp_plus_omega_data[i] = exp_plus_omega->contents->data[3 * i];
  }
  emxInit_creal_T(sp, &b_exp_minus_omega, &dc_emlrtRTEI);
  loop_ub = exp_minus_omega->contents->size[1];
  i = b_exp_minus_omega->size[0] * b_exp_minus_omega->size[1];
  b_exp_minus_omega->size[0] = 1;
  b_exp_minus_omega->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, b_exp_minus_omega, i, &dc_emlrtRTEI);
  exp_plus_omega_data = b_exp_minus_omega->data;
  for (i = 0; i < loop_ub; i++) {
    exp_plus_omega_data[i] = exp_minus_omega->contents->data[3 * i];
  }
  emxInit_creal_T(sp, &b_k_zero, &ec_emlrtRTEI);
  i = b_k_zero->size[0] * b_k_zero->size[1];
  b_k_zero->size[0] = 2;
  b_k_zero->size[1] = k_zero->size[1];
  emxEnsureCapacity_creal_T(sp, b_k_zero, i, &ec_emlrtRTEI);
  exp_plus_omega_data = b_k_zero->data;
  loop_ub = k_zero->size[0] * k_zero->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    exp_plus_omega_data[i] = k_zero_data[i];
  }
  emxInit_creal_T(sp, &r, &ic_emlrtRTEI);
  memcpy(&b_B_E[0], &B_E[0], 2048U * sizeof(creal_T));
  st.site = &pb_emlrtRSI;
  Chi_3_LLE_Kuar_ins(&st, N, Temp, Field, G_theta, ind_pump, b_B_E,
                     b_exp_plus_omega, b_exp_minus_omega,
                     pump_phase_substep->contents[0],
                     Temp->contents.Eq.mode_range,
                     Temp->contents.Eq.Pump.ind_pump, Temp->contents.Eq.Pump.H,
                     Temp->contents.Eq.kappa, Temp->contents.Eq.gamma2,
                     Temp->contents.Eq.gamma3, b_k_zero, pump_phase, r);
  exp_plus_omega_data = r->data;
  iv[0] = 1;
  iv[1] = d->size[1];
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &r->size[0], 2, &e_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = r->size[1];
  for (i = 0; i < loop_ub; i++) {
    d_data[d->size[0] * i] = exp_plus_omega_data[i];
  }
  b_d = Runge->contents.s;
  i = (int32_T)(b_d + -1.0);
  emlrtForLoopVectorCheckR2021a(2.0, 1.0, b_d, mxDOUBLE_CLASS,
                                (int32_T)(b_d + -1.0), &f_emlrtRTEI,
                                (emlrtCTX)sp);
  if (0 <= (int32_T)(b_d + -1.0) - 1) {
    d1 = b_d - 1.0;
    i1 = (int32_T)(b_d - 1.0);
    b_loop_ub = exp_plus_omega->contents->size[1];
    c_loop_ub = exp_minus_omega->contents->size[1];
    iv[0] = 1;
  }
  for (i2 = 0; i2 < i; i2++) {
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, d1, mxDOUBLE_CLASS, (int32_T)d1,
                                  &g_emlrtRTEI, (emlrtCTX)sp);
    for (ii = 0; ii < i1; ii++) {
      if (((int32_T)(i2 + 2U) < 1) || ((int32_T)(i2 + 2U) > 3)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(i2 + 2U), 1, 3, &q_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > 3)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, 3, &r_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_dt = Runge->contents.b[(i2 + 3 * ii) + 1];
      if (b_dt != 0.0) {
        b_dt *= dt;
        if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, d->size[0],
                                        &k_emlrtBCI, (emlrtCTX)sp);
        }
        for (b_i2 = 0; b_i2 < 1309; b_i2++) {
          loop_ub =
              (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[b_i2]);
          if (Temp->contents.Eq.mode_range[b_i2] != loop_ub) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &fb_emlrtDCI, (emlrtCTX)sp);
          }
          i3 = (int32_T)Temp->contents.Eq.mode_range[b_i2];
          if ((i3 < 1) || (i3 > 2048)) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, 2048, &w_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (Temp->contents.Eq.mode_range[b_i2] != loop_ub) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &gb_emlrtDCI, (emlrtCTX)sp);
          }
          if (i3 > d->size[1]) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, d->size[1], &x_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          b_E_temp[b_i2].re =
              E_temp[i3 - 1].re + b_dt * d_data[ii + d->size[0] * (i3 - 1)].re;
          if (Temp->contents.Eq.mode_range[b_i2] != loop_ub) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &fb_emlrtDCI, (emlrtCTX)sp);
          }
          if (i3 > d->size[1]) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, d->size[1], &x_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          b_E_temp[b_i2].im =
              E_temp[i3 - 1].im + b_dt * d_data[ii + d->size[0] * (i3 - 1)].im;
        }
        for (b_i2 = 0; b_i2 < 1309; b_i2++) {
          loop_ub =
              (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[b_i2]);
          if (Temp->contents.Eq.mode_range[b_i2] != loop_ub) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &ib_emlrtDCI, (emlrtCTX)sp);
          }
          i3 = (int32_T)Temp->contents.Eq.mode_range[b_i2];
          if ((i3 < 1) || (i3 > 2048)) {
            emlrtDynamicBoundsCheckR2012b(i3, 1, 2048, &ab_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          E_temp[i3 - 1].re = b_E_temp[b_i2].re;
          if (Temp->contents.Eq.mode_range[b_i2] != loop_ub) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &ib_emlrtDCI, (emlrtCTX)sp);
          }
          E_temp[i3 - 1].im = b_E_temp[b_i2].im;
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if ((i2 + 2 < 1) || (i2 + 2 > d->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2 + 2, 1, d->size[0], &m_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (((int32_T)(i2 + 2U) < 1) || ((int32_T)(i2 + 2U) > 3)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(i2 + 2U), 1, 3, &l_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_i2 = b_exp_plus_omega->size[0] * b_exp_plus_omega->size[1];
    b_exp_plus_omega->size[0] = 1;
    b_exp_plus_omega->size[1] = b_loop_ub;
    emxEnsureCapacity_creal_T(sp, b_exp_plus_omega, b_i2, &fc_emlrtRTEI);
    exp_plus_omega_data = b_exp_plus_omega->data;
    for (b_i2 = 0; b_i2 < b_loop_ub; b_i2++) {
      exp_plus_omega_data[b_i2] =
          exp_plus_omega->contents->data[(i2 + 3 * b_i2) + 1];
    }
    b_i2 = b_exp_minus_omega->size[0] * b_exp_minus_omega->size[1];
    b_exp_minus_omega->size[0] = 1;
    b_exp_minus_omega->size[1] = c_loop_ub;
    emxEnsureCapacity_creal_T(sp, b_exp_minus_omega, b_i2, &gc_emlrtRTEI);
    exp_plus_omega_data = b_exp_minus_omega->data;
    for (b_i2 = 0; b_i2 < c_loop_ub; b_i2++) {
      exp_plus_omega_data[b_i2] =
          exp_minus_omega->contents->data[(i2 + 3 * b_i2) + 1];
    }
    b_i2 = b_k_zero->size[0] * b_k_zero->size[1];
    b_k_zero->size[0] = 2;
    b_k_zero->size[1] = k_zero->size[1];
    emxEnsureCapacity_creal_T(sp, b_k_zero, b_i2, &hc_emlrtRTEI);
    exp_plus_omega_data = b_k_zero->data;
    loop_ub = k_zero->size[0] * k_zero->size[1] - 1;
    for (b_i2 = 0; b_i2 <= loop_ub; b_i2++) {
      exp_plus_omega_data[b_i2] = k_zero_data[b_i2];
    }
    st.site = &qb_emlrtRSI;
    Chi_3_LLE_Kuar_ins(
        &st, N, Temp, Field, G_theta, ind_pump, E_temp, b_exp_plus_omega,
        b_exp_minus_omega, pump_phase_substep->contents[i2 + 1],
        Temp->contents.Eq.mode_range, Temp->contents.Eq.Pump.ind_pump,
        Temp->contents.Eq.Pump.H, Temp->contents.Eq.kappa,
        Temp->contents.Eq.gamma2, Temp->contents.Eq.gamma3, b_k_zero,
        pump_phase, r);
    exp_plus_omega_data = r->data;
    iv[1] = d->size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &r->size[0], 2, &f_emlrtECI,
                                  (emlrtCTX)sp);
    loop_ub = r->size[1];
    for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
      d_data[(i2 + d->size[0] * b_i2) + 1] = exp_plus_omega_data[b_i2];
    }
    memcpy(&E_temp[0], &B_E[0], 2048U * sizeof(creal_T));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_creal_T(sp, &b_k_zero);
  emxFree_creal_T(sp, &b_exp_minus_omega);
  emxFree_creal_T(sp, &b_exp_plus_omega);
  emxFree_creal_T(sp, &r);
  i = (int32_T)b_d;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, b_d, mxDOUBLE_CLASS, (int32_T)b_d,
                                &h_emlrtRTEI, (emlrtCTX)sp);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) > 3)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, 3, &p_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (Runge->contents.c[loop_ub] != 0.0) {
      for (i1 = 0; i1 < 1309; i1++) {
        if (Temp->contents.Eq.mode_range[i1] !=
            (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[i1])) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &cb_emlrtDCI, (emlrtCTX)sp);
        }
        b_i2 = (int32_T)Temp->contents.Eq.mode_range[i1];
        if ((b_i2 < 1) || (b_i2 > 2048)) {
          emlrtDynamicBoundsCheckR2012b(b_i2, 1, 2048, &t_emlrtBCI,
                                        (emlrtCTX)sp);
        }
      }
      for (i1 = 0; i1 < 1309; i1++) {
        if (Temp->contents.Eq.mode_range[i1] !=
            (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[i1])) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &db_emlrtDCI, (emlrtCTX)sp);
        }
        b_i2 = (int32_T)Temp->contents.Eq.mode_range[i1];
        if ((b_i2 < 1) || (b_i2 > 2048)) {
          emlrtDynamicBoundsCheckR2012b(b_i2, 1, 2048, &u_emlrtBCI,
                                        (emlrtCTX)sp);
        }
      }
      if ((loop_ub + 1 < 1) || (loop_ub + 1 > d->size[0])) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, d->size[0], &n_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      for (i1 = 0; i1 < 1309; i1++) {
        if (Temp->contents.Eq.mode_range[i1] !=
            (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[i1])) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &hb_emlrtDCI, (emlrtCTX)sp);
        }
        b_i2 = (int32_T)Temp->contents.Eq.mode_range[i1];
        if ((b_i2 < 1) || (b_i2 > d->size[1])) {
          emlrtDynamicBoundsCheckR2012b(b_i2, 1, d->size[1], &y_emlrtBCI,
                                        (emlrtCTX)sp);
        }
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  for (i = 0; i < 1309; i++) {
    if (Temp->contents.Eq.mode_range[i] !=
        (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[i])) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &ab_emlrtDCI,
                              (emlrtCTX)sp);
    }
    i1 = (int32_T)Temp->contents.Eq.mode_range[i];
    if ((i1 < 1) || (i1 > 2048)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 2048, &o_emlrtBCI, (emlrtCTX)sp);
    }
  }
  for (i = 0; i < 1309; i++) {
    if (Temp->contents.Eq.mode_range[i] !=
        (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[i])) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &bb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    i1 = (int32_T)Temp->contents.Eq.mode_range[i];
    if ((i1 < 1) || (i1 > 2048)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, 2048, &s_emlrtBCI, (emlrtCTX)sp);
    }
  }
  loop_ub = shift_back->contents->size[1];
  for (i = 0; i < 1309; i++) {
    if (Temp->contents.Eq.mode_range[i] !=
        (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[i])) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &eb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    i1 = (int32_T)Temp->contents.Eq.mode_range[i];
    if ((i1 < 1) || (i1 > loop_ub)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, loop_ub, &v_emlrtBCI, (emlrtCTX)sp);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void b_Runge_Kuarong_step(
    const emlrtStack *sp, const captured_var *N, const c_captured_var *Temp,
    e_captured_var *Field, const f_captured_var *G_theta,
    const f_captured_var *ind_pump, const e_captured_var *exp_plus_omega,
    const e_captured_var *exp_minus_omega,
    const d_captured_var *pump_phase_substep, const b_captured_var *Runge,
    const e_captured_var *shift_back, creal_T B_E[2048], real_T dt,
    const creal_T pump_phase, emxArray_creal_T *d,
    const emxArray_creal_T *k_zero)
{
  emlrtStack st;
  emxArray_creal_T *b_exp_minus_omega;
  emxArray_creal_T *b_exp_plus_omega;
  emxArray_creal_T *b_k_zero;
  emxArray_creal_T *r;
  creal_T E_temp[2048];
  creal_T b_B_E[2048];
  creal_T b_E_temp[1309];
  const creal_T *k_zero_data;
  creal_T *d_data;
  creal_T *exp_plus_omega_data;
  real_T b_d;
  real_T b_dt;
  real_T d1;
  int32_T iv[2];
  int32_T b_i2;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T ii;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  k_zero_data = k_zero->data;
  d_data = d->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*     Sol.Pric = F_Intermid;  */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  memcpy(&E_temp[0], &B_E[0], 2048U * sizeof(creal_T));
  if (1 > d->size[0]) {
    emlrtDynamicBoundsCheckR2012b(1, 1, d->size[0], &j_emlrtBCI, (emlrtCTX)sp);
  }
  emxInit_creal_T(sp, &b_exp_plus_omega, &cc_emlrtRTEI);
  loop_ub = exp_plus_omega->contents->size[1];
  i = b_exp_plus_omega->size[0] * b_exp_plus_omega->size[1];
  b_exp_plus_omega->size[0] = 1;
  b_exp_plus_omega->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, b_exp_plus_omega, i, &cc_emlrtRTEI);
  exp_plus_omega_data = b_exp_plus_omega->data;
  for (i = 0; i < loop_ub; i++) {
    exp_plus_omega_data[i] = exp_plus_omega->contents->data[3 * i];
  }
  emxInit_creal_T(sp, &b_exp_minus_omega, &dc_emlrtRTEI);
  loop_ub = exp_minus_omega->contents->size[1];
  i = b_exp_minus_omega->size[0] * b_exp_minus_omega->size[1];
  b_exp_minus_omega->size[0] = 1;
  b_exp_minus_omega->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(sp, b_exp_minus_omega, i, &dc_emlrtRTEI);
  exp_plus_omega_data = b_exp_minus_omega->data;
  for (i = 0; i < loop_ub; i++) {
    exp_plus_omega_data[i] = exp_minus_omega->contents->data[3 * i];
  }
  emxInit_creal_T(sp, &b_k_zero, &ec_emlrtRTEI);
  i = b_k_zero->size[0] * b_k_zero->size[1];
  b_k_zero->size[0] = 2;
  b_k_zero->size[1] = k_zero->size[1];
  emxEnsureCapacity_creal_T(sp, b_k_zero, i, &ec_emlrtRTEI);
  exp_plus_omega_data = b_k_zero->data;
  loop_ub = k_zero->size[0] * k_zero->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    exp_plus_omega_data[i] = k_zero_data[i];
  }
  emxInit_creal_T(sp, &r, &ic_emlrtRTEI);
  memcpy(&b_B_E[0], &B_E[0], 2048U * sizeof(creal_T));
  st.site = &pb_emlrtRSI;
  Chi_3_LLE_Kuar_ins(&st, N, Temp, Field, G_theta, ind_pump, b_B_E,
                     b_exp_plus_omega, b_exp_minus_omega,
                     pump_phase_substep->contents[0],
                     Temp->contents.Eq.mode_range,
                     Temp->contents.Eq.Pump.ind_pump, Temp->contents.Eq.Pump.H,
                     Temp->contents.Eq.kappa, Temp->contents.Eq.gamma2,
                     Temp->contents.Eq.gamma3, b_k_zero, pump_phase, r);
  exp_plus_omega_data = r->data;
  iv[0] = 1;
  iv[1] = d->size[1];
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &r->size[0], 2, &e_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = r->size[1];
  for (i = 0; i < loop_ub; i++) {
    d_data[d->size[0] * i] = exp_plus_omega_data[i];
  }
  b_d = Runge->contents.s;
  i = (int32_T)(b_d + -1.0);
  emlrtForLoopVectorCheckR2021a(2.0, 1.0, b_d, mxDOUBLE_CLASS,
                                (int32_T)(b_d + -1.0), &f_emlrtRTEI,
                                (emlrtCTX)sp);
  if (0 <= (int32_T)(b_d + -1.0) - 1) {
    d1 = b_d - 1.0;
    i1 = (int32_T)(b_d - 1.0);
    b_loop_ub = exp_plus_omega->contents->size[1];
    c_loop_ub = exp_minus_omega->contents->size[1];
    iv[0] = 1;
  }
  for (i2 = 0; i2 < i; i2++) {
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, d1, mxDOUBLE_CLASS, (int32_T)d1,
                                  &g_emlrtRTEI, (emlrtCTX)sp);
    for (ii = 0; ii < i1; ii++) {
      if (((int32_T)(i2 + 2U) < 1) || ((int32_T)(i2 + 2U) > 3)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(i2 + 2U), 1, 3, &q_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > 3)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, 3, &r_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_dt = Runge->contents.b[(i2 + 3 * ii) + 1];
      if (b_dt != 0.0) {
        b_dt *= dt;
        if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, d->size[0],
                                        &k_emlrtBCI, (emlrtCTX)sp);
        }
        for (b_i2 = 0; b_i2 < 1309; b_i2++) {
          i3 = (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[b_i2]);
          if (Temp->contents.Eq.mode_range[b_i2] != i3) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &fb_emlrtDCI, (emlrtCTX)sp);
          }
          loop_ub = (int32_T)Temp->contents.Eq.mode_range[b_i2];
          if ((loop_ub < 1) || (loop_ub > 2048)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 2048, &w_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (Temp->contents.Eq.mode_range[b_i2] != i3) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &gb_emlrtDCI, (emlrtCTX)sp);
          }
          if (loop_ub > d->size[1]) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, d->size[1], &x_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          b_E_temp[b_i2].re = E_temp[loop_ub - 1].re +
                              b_dt * d_data[ii + d->size[0] * (loop_ub - 1)].re;
          if (Temp->contents.Eq.mode_range[b_i2] != i3) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &fb_emlrtDCI, (emlrtCTX)sp);
          }
          if (loop_ub > d->size[1]) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, d->size[1], &x_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          b_E_temp[b_i2].im = E_temp[loop_ub - 1].im +
                              b_dt * d_data[ii + d->size[0] * (loop_ub - 1)].im;
        }
        for (b_i2 = 0; b_i2 < 1309; b_i2++) {
          i3 = (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[b_i2]);
          if (Temp->contents.Eq.mode_range[b_i2] != i3) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &ib_emlrtDCI, (emlrtCTX)sp);
          }
          loop_ub = (int32_T)Temp->contents.Eq.mode_range[b_i2];
          if ((loop_ub < 1) || (loop_ub > 2048)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 2048, &ab_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          E_temp[loop_ub - 1].re = b_E_temp[b_i2].re;
          if (Temp->contents.Eq.mode_range[b_i2] != i3) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &ib_emlrtDCI, (emlrtCTX)sp);
          }
          E_temp[loop_ub - 1].im = b_E_temp[b_i2].im;
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if ((i2 + 2 < 1) || (i2 + 2 > d->size[0])) {
      emlrtDynamicBoundsCheckR2012b(i2 + 2, 1, d->size[0], &m_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (((int32_T)(i2 + 2U) < 1) || ((int32_T)(i2 + 2U) > 3)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(i2 + 2U), 1, 3, &l_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_i2 = b_exp_plus_omega->size[0] * b_exp_plus_omega->size[1];
    b_exp_plus_omega->size[0] = 1;
    b_exp_plus_omega->size[1] = b_loop_ub;
    emxEnsureCapacity_creal_T(sp, b_exp_plus_omega, b_i2, &fc_emlrtRTEI);
    exp_plus_omega_data = b_exp_plus_omega->data;
    for (b_i2 = 0; b_i2 < b_loop_ub; b_i2++) {
      exp_plus_omega_data[b_i2] =
          exp_plus_omega->contents->data[(i2 + 3 * b_i2) + 1];
    }
    b_i2 = b_exp_minus_omega->size[0] * b_exp_minus_omega->size[1];
    b_exp_minus_omega->size[0] = 1;
    b_exp_minus_omega->size[1] = c_loop_ub;
    emxEnsureCapacity_creal_T(sp, b_exp_minus_omega, b_i2, &gc_emlrtRTEI);
    exp_plus_omega_data = b_exp_minus_omega->data;
    for (b_i2 = 0; b_i2 < c_loop_ub; b_i2++) {
      exp_plus_omega_data[b_i2] =
          exp_minus_omega->contents->data[(i2 + 3 * b_i2) + 1];
    }
    b_i2 = b_k_zero->size[0] * b_k_zero->size[1];
    b_k_zero->size[0] = 2;
    b_k_zero->size[1] = k_zero->size[1];
    emxEnsureCapacity_creal_T(sp, b_k_zero, b_i2, &hc_emlrtRTEI);
    exp_plus_omega_data = b_k_zero->data;
    loop_ub = k_zero->size[0] * k_zero->size[1] - 1;
    for (b_i2 = 0; b_i2 <= loop_ub; b_i2++) {
      exp_plus_omega_data[b_i2] = k_zero_data[b_i2];
    }
    st.site = &qb_emlrtRSI;
    Chi_3_LLE_Kuar_ins(
        &st, N, Temp, Field, G_theta, ind_pump, E_temp, b_exp_plus_omega,
        b_exp_minus_omega, pump_phase_substep->contents[i2 + 1],
        Temp->contents.Eq.mode_range, Temp->contents.Eq.Pump.ind_pump,
        Temp->contents.Eq.Pump.H, Temp->contents.Eq.kappa,
        Temp->contents.Eq.gamma2, Temp->contents.Eq.gamma3, b_k_zero,
        pump_phase, r);
    exp_plus_omega_data = r->data;
    iv[1] = d->size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &r->size[0], 2, &f_emlrtECI,
                                  (emlrtCTX)sp);
    loop_ub = r->size[1];
    for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
      d_data[(i2 + d->size[0] * b_i2) + 1] = exp_plus_omega_data[b_i2];
    }
    memcpy(&E_temp[0], &B_E[0], 2048U * sizeof(creal_T));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_creal_T(sp, &b_k_zero);
  emxFree_creal_T(sp, &b_exp_minus_omega);
  emxFree_creal_T(sp, &b_exp_plus_omega);
  emxFree_creal_T(sp, &r);
  i = (int32_T)b_d;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, b_d, mxDOUBLE_CLASS, (int32_T)b_d,
                                &h_emlrtRTEI, (emlrtCTX)sp);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) > 3)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, 3, &p_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (Runge->contents.c[loop_ub] != 0.0) {
      b_dt = dt * Runge->contents.c[loop_ub];
      if (((int32_T)(loop_ub + 1U) < 1) ||
          ((int32_T)(loop_ub + 1U) > d->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, d->size[0],
                                      &n_emlrtBCI, (emlrtCTX)sp);
      }
      for (i1 = 0; i1 < 1309; i1++) {
        b_i2 = (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[i1]);
        if (Temp->contents.Eq.mode_range[i1] != b_i2) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &db_emlrtDCI, (emlrtCTX)sp);
        }
        i3 = (int32_T)Temp->contents.Eq.mode_range[i1];
        if ((i3 < 1) || (i3 > 2048)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 2048, &u_emlrtBCI, (emlrtCTX)sp);
        }
        if (Temp->contents.Eq.mode_range[i1] != b_i2) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &hb_emlrtDCI, (emlrtCTX)sp);
        }
        if (i3 > d->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, d->size[1], &y_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_E_temp[i1].re =
            B_E[i3 - 1].re + b_dt * d_data[loop_ub + d->size[0] * (i3 - 1)].re;
        if (Temp->contents.Eq.mode_range[i1] != b_i2) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &db_emlrtDCI, (emlrtCTX)sp);
        }
        if (i3 > d->size[1]) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, d->size[1], &y_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_E_temp[i1].im =
            B_E[i3 - 1].im + b_dt * d_data[loop_ub + d->size[0] * (i3 - 1)].im;
      }
      for (i1 = 0; i1 < 1309; i1++) {
        b_i2 = (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[i1]);
        if (Temp->contents.Eq.mode_range[i1] != b_i2) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &wb_emlrtDCI, (emlrtCTX)sp);
        }
        i3 = (int32_T)Temp->contents.Eq.mode_range[i1];
        if ((i3 < 1) || (i3 > 2048)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 2048, &rb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        B_E[i3 - 1].re = b_E_temp[i1].re;
        if (Temp->contents.Eq.mode_range[i1] != b_i2) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &wb_emlrtDCI, (emlrtCTX)sp);
        }
        B_E[i3 - 1].im = b_E_temp[i1].im;
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  loop_ub = shift_back->contents->size[1];
  for (i = 0; i < 1309; i++) {
    i1 = (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[i]);
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &xb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    b_i2 = (int32_T)Temp->contents.Eq.mode_range[i];
    if ((b_i2 < 1) || (b_i2 > 2048)) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, 2048, &sb_emlrtBCI, (emlrtCTX)sp);
    }
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &xb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (b_i2 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, loop_ub, &tb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &xb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (b_i2 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, loop_ub, &tb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_d = B_E[b_i2 - 1].re;
    d1 = B_E[b_i2 - 1].im;
    b_E_temp[i].re = b_d * shift_back->contents->data[b_i2 - 1].re -
                     d1 * shift_back->contents->data[b_i2 - 1].im;
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &xb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (b_i2 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, loop_ub, &tb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &xb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (b_i2 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, loop_ub, &tb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_E_temp[i].im = b_d * shift_back->contents->data[b_i2 - 1].im +
                     d1 * shift_back->contents->data[b_i2 - 1].re;
  }
  for (i = 0; i < 1309; i++) {
    i1 = (int32_T)muDoubleScalarFloor(Temp->contents.Eq.mode_range[i]);
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &vb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    b_i2 = (int32_T)Temp->contents.Eq.mode_range[i];
    if ((b_i2 < 1) || (b_i2 > 2048)) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, 2048, &qb_emlrtBCI, (emlrtCTX)sp);
    }
    B_E[b_i2 - 1].re = b_E_temp[i].re;
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &vb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    B_E[b_i2 - 1].im = b_E_temp[i].im;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void b_plus(const emlrtStack *sp, emxArray_creal_T *r3,
                   const emxArray_creal_T *x)
{
  emxArray_creal_T *r1;
  const creal_T *x_data;
  creal_T *r;
  creal_T *r2;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  x_data = x->data;
  r = r3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_creal_T(sp, &r1, &pc_emlrtRTEI);
  i = r1->size[0] * r1->size[1];
  r1->size[0] = 1;
  if (x->size[1] == 1) {
    r1->size[1] = r3->size[1];
  } else {
    r1->size[1] = x->size[1];
  }
  emxEnsureCapacity_creal_T(sp, r1, i, &pc_emlrtRTEI);
  r2 = r1->data;
  stride_0_1 = (r3->size[1] != 1);
  stride_1_1 = (x->size[1] != 1);
  if (x->size[1] == 1) {
    loop_ub = r3->size[1];
  } else {
    loop_ub = x->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = i * stride_1_1;
    r2[i].re = r[i * stride_0_1].re + x_data[i1].re;
    r2[i].im = r[i * stride_0_1].im + x_data[i1].im;
  }
  i = r3->size[0] * r3->size[1];
  r3->size[0] = 1;
  r3->size[1] = r1->size[1];
  emxEnsureCapacity_creal_T(sp, r3, i, &pc_emlrtRTEI);
  r = r3->data;
  loop_ub = r1->size[1];
  for (i = 0; i < loop_ub; i++) {
    r[i] = r2[i];
  }
  emxFree_creal_T(sp, &r1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp, emxArray_creal_T *x,
                             emlrtRSInfo lc_emlrtRSI,
                             const f_captured_var *G_theta,
                             const emxArray_creal_T *r1)
{
  emlrtStack st;
  emxArray_creal_T *b_G_theta;
  const creal_T *r;
  creal_T *G_theta_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  st.prev = sp;
  st.tls = sp->tls;
  r = r1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_creal_T(sp, &b_G_theta, &lc_emlrtRTEI);
  i = b_G_theta->size[0] * b_G_theta->size[1];
  b_G_theta->size[0] = 1;
  if (r1->size[1] == 1) {
    b_G_theta->size[1] = G_theta->contents->size[1];
  } else {
    b_G_theta->size[1] = r1->size[1];
  }
  emxEnsureCapacity_creal_T(sp, b_G_theta, i, &lc_emlrtRTEI);
  G_theta_data = b_G_theta->data;
  stride_0_1 = (G_theta->contents->size[1] != 1);
  stride_1_1 = (r1->size[1] != 1);
  if (r1->size[1] == 1) {
    loop_ub = G_theta->contents->size[1];
  } else {
    loop_ub = r1->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    i1 = i * stride_1_1;
    G_theta_data[i].re = G_theta->contents->data[i * stride_0_1] * r[i1].re;
    G_theta_data[i].im = G_theta->contents->data[i * stride_0_1] * r[i1].im;
  }
  st.site = &lc_emlrtRSI;
  fft(&st, b_G_theta, x);
  emxFree_creal_T(sp, &b_G_theta);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void minus(const emlrtStack *sp, emxArray_real_T *G,
                  const emxArray_real_T *r1)
{
  emxArray_real_T *b_G;
  const real_T *r;
  real_T *G_data;
  real_T *b_G_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  r = r1->data;
  G_data = G->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_G, &ad_emlrtRTEI);
  i = b_G->size[0] * b_G->size[1];
  b_G->size[0] = 1;
  if (r1->size[1] == 1) {
    b_G->size[1] = G->size[1];
  } else {
    b_G->size[1] = r1->size[1];
  }
  emxEnsureCapacity_real_T(sp, b_G, i, &ad_emlrtRTEI);
  b_G_data = b_G->data;
  stride_0_1 = (G->size[1] != 1);
  stride_1_1 = (r1->size[1] != 1);
  if (r1->size[1] == 1) {
    loop_ub = G->size[1];
  } else {
    loop_ub = r1->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    b_G_data[i] = G_data[i * stride_0_1] - r[i * stride_1_1];
  }
  i = G->size[0] * G->size[1];
  G->size[0] = 1;
  G->size[1] = b_G->size[1];
  emxEnsureCapacity_real_T(sp, G, i, &ad_emlrtRTEI);
  G_data = G->data;
  loop_ub = b_G->size[1];
  for (i = 0; i < loop_ub; i++) {
    G_data[i] = b_G_data[i];
  }
  emxFree_real_T(sp, &b_G);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void plus(const emlrtStack *sp, emxArray_real_T *G,
                 const emxArray_real_T *r1)
{
  emxArray_real_T *b_G;
  const real_T *r;
  real_T *G_data;
  real_T *b_G_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  r = r1->data;
  G_data = G->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &b_G, &bd_emlrtRTEI);
  i = b_G->size[0] * b_G->size[1];
  b_G->size[0] = 1;
  if (r1->size[1] == 1) {
    b_G->size[1] = G->size[1];
  } else {
    b_G->size[1] = r1->size[1];
  }
  emxEnsureCapacity_real_T(sp, b_G, i, &bd_emlrtRTEI);
  b_G_data = b_G->data;
  stride_0_1 = (G->size[1] != 1);
  stride_1_1 = (r1->size[1] != 1);
  if (r1->size[1] == 1) {
    loop_ub = G->size[1];
  } else {
    loop_ub = r1->size[1];
  }
  for (i = 0; i < loop_ub; i++) {
    b_G_data[i] = G_data[i * stride_0_1] + r[i * stride_1_1];
  }
  i = G->size[0] * G->size[1];
  G->size[0] = 1;
  G->size[1] = b_G->size[1];
  emxEnsureCapacity_real_T(sp, G, i, &bd_emlrtRTEI);
  G_data = G->data;
  loop_ub = b_G->size[1];
  for (i = 0; i < loop_ub; i++) {
    G_data[i] = b_G_data[i];
  }
  emxFree_real_T(sp, &b_G);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void FullField_SingleProgection_dynamics(f_FullField_SingleProgection_dy *SD,
                                         const emlrtStack *sp,
                                         const struct0_T *Temp,
                                         const struct7_T *Runge, struct8_T *Sol)
{
  static const real_T p[8] = {-1.716185138865495,  24.76565080557592,
                              -379.80425647094563, 629.3311553128184,
                              866.96620279041326,  -31451.272968848367,
                              -36144.413418691176, 66456.143820240541};
  static const real_T q[8] = {-30.840230011973897, 315.35062697960416,
                              -1015.1563674902192, -3107.7716715723109,
                              22538.11842098015,   4755.8462775278813,
                              -134659.95986496931, -115132.25967555349};
  b_captured_var b_Runge;
  captured_var N;
  d_captured_var pump_phase_substep;
  e_captured_var Field;
  e_captured_var exp_minus_omega;
  e_captured_var exp_plus_omega;
  e_captured_var shift_back;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_boolean_T *c_phi;
  emxArray_char_T *fftinfo;
  emxArray_creal_T *Eq_L;
  emxArray_creal_T *c_d;
  emxArray_creal_T *d;
  emxArray_creal_T *k_zero;
  emxArray_creal_T *r2;
  emxArray_int32_T *ii;
  emxArray_real_T *G;
  emxArray_real_T *b_phi;
  emxArray_real_T *b_r;
  emxArray_real_T *phi;
  f_captured_var G_theta;
  f_captured_var ind_pump;
  creal_T F_e[2048];
  creal_T phase_pump;
  creal_T *Eq_L_data;
  creal_T *d_data;
  creal_T *k_zero_data;
  real_T alpha;
  real_T b_d;
  real_T dt_tmp_tmp;
  real_T g;
  real_T mu;
  real_T nt;
  real_T r;
  real_T xden;
  real_T xnum;
  real_T *G_data;
  real_T *phi_data;
  real_T *r1;
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T k;
  int32_T last;
  int32_T loop_ub;
  int32_T *ii_data;
  boolean_T exitg1;
  boolean_T *b_phi_data;
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_creal_T(sp, &d, &k_emlrtRTEI);
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  SD->f0.Temp.contents = *Temp;
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  b_Runge.contents = *Runge;
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &p_emlrtRSI;
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &d_emlrtDCI, (emlrtCTX)sp);
  }
  mu = (int32_T)muDoubleScalarFloor(Runge->s);
  if (Runge->s != mu) {
    emlrtIntegerCheckR2012b(Runge->s, &c_emlrtDCI, (emlrtCTX)sp);
  }
  i = d->size[0] * d->size[1];
  d->size[0] = (int32_T)Runge->s;
  emxEnsureCapacity_creal_T(sp, d, i, &k_emlrtRTEI);
  if (!(Temp->Space.N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Space.N, &f_emlrtDCI, (emlrtCTX)sp);
  }
  b_d = (int32_T)muDoubleScalarFloor(Temp->Space.N);
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &e_emlrtDCI, (emlrtCTX)sp);
  }
  i = d->size[0] * d->size[1];
  loop_ub = (int32_T)Temp->Space.N;
  d->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_creal_T(sp, d, i, &k_emlrtRTEI);
  d_data = d->data;
  if (Runge->s != mu) {
    emlrtIntegerCheckR2012b(Runge->s, &o_emlrtDCI, (emlrtCTX)sp);
  }
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &o_emlrtDCI, (emlrtCTX)sp);
  }
  idx = (int32_T)Runge->s * (int32_T)Temp->Space.N;
  for (i = 0; i < idx; i++) {
    d_data[i].re = 0.0;
    d_data[i].im = 0.0;
  }
  emxInit_real_T(sp, &phi, &m_emlrtRTEI);
  dt_tmp_tmp = Temp->Par.dt;
  nt = Temp->Par.T / Temp->Par.dt;
  N.contents = Temp->Space.N;
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  /* +exp(-1i*Temp.Space.phi*Temp.Eq.g); */
  g = muDoubleScalarAbs(Temp->Eq.g);
  if (Temp->Space.N - 1.0 < 0.0) {
    phi->size[1] = 0;
  } else if (muDoubleScalarIsInf(Temp->Space.N - 1.0) &&
             (0.0 == Temp->Space.N - 1.0)) {
    i = phi->size[0] * phi->size[1];
    phi->size[0] = 1;
    phi->size[1] = 1;
    emxEnsureCapacity_real_T(sp, phi, i, &l_emlrtRTEI);
    phi_data = phi->data;
    phi_data[0] = rtNaN;
  } else {
    i = phi->size[0] * phi->size[1];
    phi->size[0] = 1;
    idx = (int32_T)muDoubleScalarFloor(Temp->Space.N - 1.0);
    phi->size[1] = idx + 1;
    emxEnsureCapacity_real_T(sp, phi, i, &l_emlrtRTEI);
    phi_data = phi->data;
    for (i = 0; i <= idx; i++) {
      phi_data[i] = i;
    }
  }
  r = 6.2831853071795862 / Temp->Space.N;
  i = phi->size[0] * phi->size[1];
  phi->size[0] = 1;
  emxEnsureCapacity_real_T(sp, phi, i, &m_emlrtRTEI);
  phi_data = phi->data;
  idx = phi->size[1] - 1;
  for (i = 0; i <= idx; i++) {
    phi_data[i] *= r;
  }
  emxInit_real_T(sp, &G, &n_emlrtRTEI);
  alpha = 3.1415926535897931 / g / 2.0;
  i = G->size[0] * G->size[1];
  G->size[0] = 1;
  emxEnsureCapacity_real_T(sp, G, i, &n_emlrtRTEI);
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &g_emlrtDCI, (emlrtCTX)sp);
  }
  i = G->size[0] * G->size[1];
  G->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_real_T(sp, G, i, &n_emlrtRTEI);
  G_data = G->data;
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &p_emlrtDCI, (emlrtCTX)sp);
  }
  for (i = 0; i < loop_ub; i++) {
    G_data[i] = 0.0;
  }
  i = (int32_T)(g + 1.0);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, g + 1.0, mxDOUBLE_CLASS,
                                (int32_T)(g + 1.0), &d_emlrtRTEI, (emlrtCTX)sp);
  emxInit_real_T(sp, &b_r, &p_emlrtRTEI);
  emxInit_real_T(sp, &b_phi, &o_emlrtRTEI);
  for (b_i = 0; b_i < i; b_i++) {
    r = 6.2831853071795862 / g * (((real_T)b_i + 1.0) - 1.0);
    xnum = 0.0;
    xden = 1.0;
    for (last = 0; last < 8; last++) {
      xnum = (xnum + p[last]) * 0.25;
      xden = xden * 0.25 + q[last];
    }
    i1 = b_phi->size[0] * b_phi->size[1];
    b_phi->size[0] = 1;
    b_phi->size[1] = phi->size[1];
    emxEnsureCapacity_real_T(sp, b_phi, i1, &o_emlrtRTEI);
    G_data = b_phi->data;
    idx = phi->size[1];
    for (i1 = 0; i1 < idx; i1++) {
      G_data[i1] = phi_data[i1] - r;
    }
    st.site = &b_emlrtRSI;
    b_abs(&st, b_phi, b_r);
    r1 = b_r->data;
    i1 = b_phi->size[0] * b_phi->size[1];
    b_phi->size[0] = 1;
    b_phi->size[1] = b_r->size[1];
    emxEnsureCapacity_real_T(sp, b_phi, i1, &p_emlrtRTEI);
    G_data = b_phi->data;
    idx = b_r->size[1];
    for (i1 = 0; i1 < idx; i1++) {
      G_data[i1] = r1[i1] / alpha;
    }
    st.site = &b_emlrtRSI;
    power(&st, b_phi, b_r);
    i1 = b_r->size[0] * b_r->size[1];
    b_r->size[0] = 1;
    emxEnsureCapacity_real_T(sp, b_r, i1, &q_emlrtRTEI);
    r1 = b_r->data;
    idx = b_r->size[1] - 1;
    for (i1 = 0; i1 <= idx; i1++) {
      r1[i1] = -r1[i1];
    }
    st.site = &b_emlrtRSI;
    b_exp(&st, b_r);
    i1 = b_r->size[0] * b_r->size[1];
    b_r->size[0] = 1;
    emxEnsureCapacity_real_T(sp, b_r, i1, &r_emlrtRTEI);
    r1 = b_r->data;
    mu = 4.0 / (2.0 * alpha * ((xnum / xden + 1.0) / 0.25));
    idx = b_r->size[1] - 1;
    for (i1 = 0; i1 <= idx; i1++) {
      r1[i1] *= mu;
    }
    if ((G->size[1] != b_r->size[1]) &&
        ((G->size[1] != 1) && (b_r->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(G->size[1], b_r->size[1], &d_emlrtECI,
                                  (emlrtCTX)sp);
    }
    if (G->size[1] == b_r->size[1]) {
      idx = G->size[1] - 1;
      i1 = G->size[0] * G->size[1];
      G->size[0] = 1;
      emxEnsureCapacity_real_T(sp, G, i1, &u_emlrtRTEI);
      G_data = G->data;
      for (i1 = 0; i1 <= idx; i1++) {
        G_data[i1] += r1[i1];
      }
    } else {
      st.site = &b_emlrtRSI;
      plus(&st, G, b_r);
    }
    mu = 3.1415926535897931 / g + r;
    xnum = 0.0;
    xden = 1.0;
    for (last = 0; last < 8; last++) {
      xnum = (xnum + p[last]) * 0.25;
      xden = xden * 0.25 + q[last];
    }
    i1 = b_phi->size[0] * b_phi->size[1];
    b_phi->size[0] = 1;
    b_phi->size[1] = phi->size[1];
    emxEnsureCapacity_real_T(sp, b_phi, i1, &v_emlrtRTEI);
    G_data = b_phi->data;
    idx = phi->size[1];
    for (i1 = 0; i1 < idx; i1++) {
      G_data[i1] = phi_data[i1] - mu;
    }
    st.site = &c_emlrtRSI;
    b_abs(&st, b_phi, b_r);
    r1 = b_r->data;
    i1 = b_phi->size[0] * b_phi->size[1];
    b_phi->size[0] = 1;
    b_phi->size[1] = b_r->size[1];
    emxEnsureCapacity_real_T(sp, b_phi, i1, &x_emlrtRTEI);
    G_data = b_phi->data;
    idx = b_r->size[1];
    for (i1 = 0; i1 < idx; i1++) {
      G_data[i1] = r1[i1] / alpha;
    }
    st.site = &c_emlrtRSI;
    power(&st, b_phi, b_r);
    i1 = b_r->size[0] * b_r->size[1];
    b_r->size[0] = 1;
    emxEnsureCapacity_real_T(sp, b_r, i1, &ab_emlrtRTEI);
    r1 = b_r->data;
    idx = b_r->size[1] - 1;
    for (i1 = 0; i1 <= idx; i1++) {
      r1[i1] = -r1[i1];
    }
    st.site = &c_emlrtRSI;
    b_exp(&st, b_r);
    i1 = b_r->size[0] * b_r->size[1];
    b_r->size[0] = 1;
    emxEnsureCapacity_real_T(sp, b_r, i1, &cb_emlrtRTEI);
    r1 = b_r->data;
    mu = 4.0 / (2.0 * alpha * ((xnum / xden + 1.0) / 0.25));
    idx = b_r->size[1] - 1;
    for (i1 = 0; i1 <= idx; i1++) {
      r1[i1] *= mu;
    }
    if ((G->size[1] != b_r->size[1]) &&
        ((G->size[1] != 1) && (b_r->size[1] != 1))) {
      emlrtDimSizeImpxCheckR2021b(G->size[1], b_r->size[1], &c_emlrtECI,
                                  (emlrtCTX)sp);
    }
    if (G->size[1] == b_r->size[1]) {
      idx = G->size[1] - 1;
      i1 = G->size[0] * G->size[1];
      G->size[0] = 1;
      emxEnsureCapacity_real_T(sp, G, i1, &db_emlrtRTEI);
      G_data = G->data;
      for (i1 = 0; i1 <= idx; i1++) {
        G_data[i1] -= r1[i1];
      }
    } else {
      st.site = &c_emlrtRSI;
      minus(&st, G, b_r);
      G_data = G->data;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_real_T(sp, &b_phi);
  emxFree_real_T(sp, &b_r);
  st.site = &d_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  b_abs(&b_st, G, phi);
  phi_data = phi->data;
  b_st.site = &w_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  d_st.site = &y_emlrtRSI;
  if (phi->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &ab_emlrtRSI;
  f_st.site = &bb_emlrtRSI;
  last = phi->size[1];
  if (phi->size[1] <= 2) {
    if (phi->size[1] == 1) {
      r = phi_data[0];
    } else if ((phi_data[0] < phi_data[1]) ||
               (muDoubleScalarIsNaN(phi_data[0]) &&
                (!muDoubleScalarIsNaN(phi_data[1])))) {
      r = phi_data[1];
    } else {
      r = phi_data[0];
    }
  } else {
    g_st.site = &db_emlrtRSI;
    if (!muDoubleScalarIsNaN(phi_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      h_st.site = &eb_emlrtRSI;
      if (phi->size[1] > 2147483646) {
        i_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!muDoubleScalarIsNaN(phi_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      r = phi_data[0];
    } else {
      g_st.site = &cb_emlrtRSI;
      r = phi_data[idx - 1];
      b_i = idx + 1;
      h_st.site = &fb_emlrtRSI;
      if ((idx + 1 <= phi->size[1]) && (phi->size[1] > 2147483646)) {
        i_st.site = &s_emlrtRSI;
        check_forloop_overflow_error(&i_st);
      }
      for (k = b_i; k <= last; k++) {
        mu = phi_data[k - 1];
        if (r < mu) {
          r = mu;
        }
      }
    }
  }
  emxInitStruct_captured_var1(&f_st, &G_theta, &rb_emlrtRTEI);
  i = G_theta.contents->size[0] * G_theta.contents->size[1];
  G_theta.contents->size[0] = 1;
  G_theta.contents->size[1] = G->size[1];
  emxEnsureCapacity_real_T(sp, G_theta.contents, i, &s_emlrtRTEI);
  idx = G->size[1];
  for (i = 0; i < idx; i++) {
    G_theta.contents->data[i] = G_data[i] / r;
  }
  emxFree_real_T(sp, &G);
  emxInit_creal_T(sp, &Eq_L, &t_emlrtRTEI);
  /*     G_theta                             =
   * cos(Temp.Space.phi*Temp.Eq.g);%+exp(-1i*Temp.Space.phi*Temp.Eq.g); */
  /* +exp(-1i*Temp.Space.phi*Temp.Eq.g); */
  i = Eq_L->size[0] * Eq_L->size[1];
  Eq_L->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, Eq_L, i, &t_emlrtRTEI);
  mu = Temp->Space.N / 2.0;
  r = (int32_T)muDoubleScalarFloor(mu);
  if (mu != r) {
    emlrtIntegerCheckR2012b(mu, &h_emlrtDCI, (emlrtCTX)sp);
  }
  i = Eq_L->size[0] * Eq_L->size[1];
  idx = (int32_T)mu;
  Eq_L->size[1] = (int32_T)mu;
  emxEnsureCapacity_creal_T(sp, Eq_L, i, &t_emlrtRTEI);
  Eq_L_data = Eq_L->data;
  if (mu != r) {
    emlrtIntegerCheckR2012b(mu, &q_emlrtDCI, (emlrtCTX)sp);
  }
  for (i = 0; i < idx; i++) {
    Eq_L_data[i].re = 0.0;
    Eq_L_data[i].im = 0.0;
  }
  last = Eq_L->size[1];
  for (i = 0; i < 1309; i++) {
    mu = Temp->Eq.mode_range[i];
    i1 = (int32_T)muDoubleScalarFloor(mu);
    if (mu != i1) {
      emlrtIntegerCheckR2012b(mu, &r_emlrtDCI, (emlrtCTX)sp);
    }
    b_i = (int32_T)mu;
    if ((b_i < 1) || (b_i > last)) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, last, &d_emlrtBCI, (emlrtCTX)sp);
    }
    Eq_L_data[b_i - 1].re = Temp->Eq.omega[i];
    if (b_i != i1) {
      emlrtIntegerCheckR2012b(mu, &r_emlrtDCI, (emlrtCTX)sp);
    }
    if (b_i > last) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, last, &d_emlrtBCI, (emlrtCTX)sp);
    }
    Eq_L_data[b_i - 1].im = 0.0;
  }
  emxInitStruct_captured_var(sp, &exp_minus_omega, &w_emlrtRTEI);
  /* -1i*1/2*Temp.Eq.kappa; */
  i = exp_minus_omega.contents->size[0] * exp_minus_omega.contents->size[1];
  exp_minus_omega.contents->size[0] = 3;
  exp_minus_omega.contents->size[1] = Eq_L->size[1];
  emxEnsureCapacity_creal_T(sp, exp_minus_omega.contents, i, &w_emlrtRTEI);
  idx = 3 * Eq_L->size[1];
  for (i = 0; i < idx; i++) {
    exp_minus_omega.contents->data[i].re = 0.0;
    exp_minus_omega.contents->data[i].im = 0.0;
  }
  emxInitStruct_captured_var(sp, &exp_plus_omega, &y_emlrtRTEI);
  i = exp_plus_omega.contents->size[0] * exp_plus_omega.contents->size[1];
  exp_plus_omega.contents->size[0] = 3;
  exp_plus_omega.contents->size[1] = Eq_L->size[1];
  emxEnsureCapacity_creal_T(sp, exp_plus_omega.contents, i, &y_emlrtRTEI);
  idx = 3 * Eq_L->size[1];
  for (i = 0; i < idx; i++) {
    exp_plus_omega.contents->data[i].re = 0.0;
    exp_plus_omega.contents->data[i].im = 0.0;
  }
  emxInit_creal_T(sp, &k_zero, &bb_emlrtRTEI);
  i = k_zero->size[0] * k_zero->size[1];
  k_zero->size[0] = 2;
  emxEnsureCapacity_creal_T(sp, k_zero, i, &bb_emlrtRTEI);
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &i_emlrtDCI, (emlrtCTX)sp);
  }
  i = k_zero->size[0] * k_zero->size[1];
  k_zero->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_creal_T(sp, k_zero, i, &bb_emlrtRTEI);
  k_zero_data = k_zero->data;
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &s_emlrtDCI, (emlrtCTX)sp);
  }
  idx = (int32_T)Temp->Space.N << 1;
  for (i = 0; i < idx; i++) {
    k_zero_data[i].re = 0.0;
    k_zero_data[i].im = 0.0;
  }
  if (muDoubleScalarIsNaN(Temp->In.N - 1.0)) {
    i = phi->size[0] * phi->size[1];
    phi->size[0] = 1;
    phi->size[1] = 1;
    emxEnsureCapacity_real_T(sp, phi, i, &eb_emlrtRTEI);
    phi_data = phi->data;
    phi_data[0] = rtNaN;
  } else if (Temp->In.N - 1.0 < 0.0) {
    phi->size[0] = 1;
    phi->size[1] = 0;
  } else if (muDoubleScalarIsInf(Temp->In.N - 1.0) &&
             (0.0 == Temp->In.N - 1.0)) {
    i = phi->size[0] * phi->size[1];
    phi->size[0] = 1;
    phi->size[1] = 1;
    emxEnsureCapacity_real_T(sp, phi, i, &eb_emlrtRTEI);
    phi_data = phi->data;
    phi_data[0] = rtNaN;
  } else {
    i = phi->size[0] * phi->size[1];
    phi->size[0] = 1;
    idx = (int32_T)muDoubleScalarFloor(Temp->In.N - 1.0);
    phi->size[1] = idx + 1;
    emxEnsureCapacity_real_T(sp, phi, i, &eb_emlrtRTEI);
    phi_data = phi->data;
    for (i = 0; i <= idx; i++) {
      phi_data[i] = i;
    }
  }
  emxInit_boolean_T(sp, &c_phi, &fb_emlrtRTEI);
  st.site = &e_emlrtRSI;
  i = c_phi->size[0] * c_phi->size[1];
  c_phi->size[0] = 1;
  c_phi->size[1] = phi->size[1];
  emxEnsureCapacity_boolean_T(&st, c_phi, i, &fb_emlrtRTEI);
  b_phi_data = c_phi->data;
  idx = phi->size[1];
  for (i = 0; i < idx; i++) {
    b_phi_data[i] = (phi_data[i] == Temp->In.Pump.m_p);
  }
  emxFree_real_T(&st, &phi);
  emxInitStruct_captured_var1(&st, &ind_pump, &gb_emlrtRTEI);
  emxInit_int32_T(&st, &ii, &ub_emlrtRTEI);
  b_st.site = &gb_emlrtRSI;
  eml_find(&b_st, c_phi, ii);
  ii_data = ii->data;
  i = ind_pump.contents->size[0] * ind_pump.contents->size[1];
  ind_pump.contents->size[0] = 1;
  ind_pump.contents->size[1] = ii->size[1];
  emxEnsureCapacity_real_T(&st, ind_pump.contents, i, &gb_emlrtRTEI);
  idx = ii->size[1];
  emxFree_boolean_T(&st, &c_phi);
  for (i = 0; i < idx; i++) {
    ind_pump.contents->data[i] = ii_data[i];
  }
  emxFree_int32_T(&st, &ii);
  emxInitStruct_captured_var(&st, &shift_back, &hb_emlrtRTEI);
  i = shift_back.contents->size[0] * shift_back.contents->size[1];
  shift_back.contents->size[0] = 1;
  shift_back.contents->size[1] = Eq_L->size[1];
  emxEnsureCapacity_creal_T(sp, shift_back.contents, i, &hb_emlrtRTEI);
  idx = Eq_L->size[1];
  for (i = 0; i < idx; i++) {
    xnum = Eq_L_data[i].im;
    mu = Eq_L_data[i].re;
    shift_back.contents->data[i].re = dt_tmp_tmp * (0.0 * mu - (-xnum));
    shift_back.contents->data[i].im = dt_tmp_tmp * (0.0 * xnum + -mu);
  }
  st.site = &f_emlrtRSI;
  c_exp(&st, shift_back.contents);
  /*     mask  = zeros(1,N); */
  /*    mask(m == Temp.In.Pump.m_p) = 1; */
  /*   mask(m == 2*Temp.In.Pump.m_p) = 1; */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  memcpy(&F_e[0], &Temp->In.Psi_Start[0], 2048U * sizeof(creal_T));
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &b_emlrtDCI, (emlrtCTX)sp);
  }
  emxInitStruct_captured_var(sp, &Field, &ib_emlrtRTEI);
  i = Field.contents->size[0] * Field.contents->size[1];
  Field.contents->size[0] = 1;
  Field.contents->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_creal_T(sp, Field.contents, i, &ib_emlrtRTEI);
  for (i = 0; i < loop_ub; i++) {
    Field.contents->data[i].re = 0.0;
    Field.contents->data[i].im = 0.0;
  }
  xden = Temp->In.t_start;
  if (!(Temp->Par.dd >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Par.dd, &k_emlrtDCI, (emlrtCTX)sp);
  }
  mu = (int32_T)muDoubleScalarFloor(Temp->Par.dd);
  if (Temp->Par.dd != mu) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &j_emlrtDCI, (emlrtCTX)sp);
  }
  i = Sol->Psi->size[0] * Sol->Psi->size[1];
  loop_ub = (int32_T)Temp->Par.dd;
  Sol->Psi->size[0] = (int32_T)Temp->Par.dd;
  Sol->Psi->size[1] = 1309;
  emxEnsureCapacity_creal_T(sp, Sol->Psi, i, &jb_emlrtRTEI);
  if (Temp->Par.dd != mu) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &t_emlrtDCI, (emlrtCTX)sp);
  }
  idx = (int32_T)Temp->Par.dd * 1309;
  for (i = 0; i < idx; i++) {
    Sol->Psi->data[i].re = 0.0;
    Sol->Psi->data[i].im = 0.0;
  }
  /*     Sol.Psie = complex(zeros(Temp.Par.dd,Temp.Space.N)); */
  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &kb_emlrtRTEI);
  if (Temp->Par.dd != mu) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &l_emlrtDCI, (emlrtCTX)sp);
  }
  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[1] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &kb_emlrtRTEI);
  if (Temp->Par.dd != mu) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &u_emlrtDCI, (emlrtCTX)sp);
  }
  for (i = 0; i < loop_ub; i++) {
    Sol->t->data[i].re = 0.0;
    Sol->t->data[i].im = 0.0;
  }
  r = muDoubleScalarRound(nt);
  i = Sol->PsiReal->size[0] * Sol->PsiReal->size[1];
  Sol->PsiReal->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, Sol->PsiReal, i, &lb_emlrtRTEI);
  if (!(r >= 0.0)) {
    emlrtNonNegativeCheckR2012b(r, &n_emlrtDCI, (emlrtCTX)sp);
  }
  if (r != (int32_T)r) {
    emlrtIntegerCheckR2012b(r, &m_emlrtDCI, (emlrtCTX)sp);
  }
  i = Sol->PsiReal->size[0] * Sol->PsiReal->size[1];
  Sol->PsiReal->size[1] = (int32_T)r;
  emxEnsureCapacity_creal_T(sp, Sol->PsiReal, i, &lb_emlrtRTEI);
  if (r != (int32_T)r) {
    emlrtIntegerCheckR2012b(r, &v_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = (int32_T)r;
  for (i = 0; i < loop_ub; i++) {
    Sol->PsiReal->data[i].re = 0.0;
    Sol->PsiReal->data[i].im = 0.0;
  }
  /*     NRF        = round(1/dt/10); */
  /*     F_Intermid = complex(zeros(NRF,size(Temp.Eq.mode_range,2))); */
  /*     nii = 0; */
  /*    phase_pump       = complex(0); */
  loop_ub = Eq_L->size[1];
  idx = Eq_L->size[1];
  emxInit_creal_T(sp, &r2, &tb_emlrtRTEI);
  for (b_i = 0; b_i < 3; b_i++) {
    r = Runge->a[b_i] * dt_tmp_tmp;
    i = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = Eq_L->size[1];
    emxEnsureCapacity_creal_T(sp, r2, i, &mb_emlrtRTEI);
    k_zero_data = r2->data;
    for (i = 0; i < loop_ub; i++) {
      xnum = Eq_L_data[i].im;
      mu = Eq_L_data[i].re;
      k_zero_data[i].re = r * (0.0 * mu - (-xnum));
      k_zero_data[i].im = r * (0.0 * xnum + -mu);
    }
    st.site = &g_emlrtRSI;
    c_exp(&st, r2);
    k_zero_data = r2->data;
    iv[0] = 1;
    iv[1] = exp_minus_omega.contents->size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &r2->size[0], 2, &b_emlrtECI,
                                  (emlrtCTX)sp);
    last = r2->size[1];
    for (i = 0; i < last; i++) {
      exp_minus_omega.contents->data[b_i + 3 * i] = k_zero_data[i];
    }
    i = r2->size[0] * r2->size[1];
    r2->size[0] = 1;
    r2->size[1] = Eq_L->size[1];
    emxEnsureCapacity_creal_T(sp, r2, i, &nb_emlrtRTEI);
    k_zero_data = r2->data;
    for (i = 0; i < idx; i++) {
      xnum = Eq_L_data[i].im;
      mu = Eq_L_data[i].re;
      k_zero_data[i].re = r * (0.0 * mu - xnum);
      k_zero_data[i].im = r * (0.0 * xnum + mu);
    }
    st.site = &h_emlrtRSI;
    c_exp(&st, r2);
    k_zero_data = r2->data;
    iv[0] = 1;
    iv[1] = exp_plus_omega.contents->size[1];
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &r2->size[0], 2, &emlrtECI,
                                  (emlrtCTX)sp);
    last = r2->size[1];
    for (i = 0; i < last; i++) {
      exp_plus_omega.contents->data[b_i + 3 * i] = k_zero_data[i];
    }
    r += xden;
    phase_pump.re = r * (Temp->Eq.Pump.omega_p * 0.0);
    phase_pump.im = r * -Temp->Eq.Pump.omega_p;
    if (phase_pump.im == 0.0) {
      pump_phase_substep.contents[b_i].re = muDoubleScalarExp(phase_pump.re);
      pump_phase_substep.contents[b_i].im = 0.0;
    } else {
      r = muDoubleScalarExp(phase_pump.re / 2.0);
      pump_phase_substep.contents[b_i].re =
          r * (r * muDoubleScalarCos(phase_pump.im));
      pump_phase_substep.contents[b_i].im =
          r * (r * muDoubleScalarSin(phase_pump.im));
    }
    /*      pump_phase_substep (i)    = exp(  1i*Eq.L(ind_pump)*(t_zero
     * +Runge.a(i)*dt)).*exp( -1i*Temp.Eq.Pump.omega_p*(t_zero +Runge.a(i)*dt));
     */
    /*       pump_phase_substep(i)   = exp( 1i*Temp.Eq.Pump.delta*(t_zero
     * +Runge.a(i)*dt)); */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_creal_T(sp, &r2);
  emxFree_creal_T(sp, &Eq_L);
  /*     NFSr = floor(Temp.Eq.omega/Temp.Eq.Pump.D1); */
  st.site = &i_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &kb_emlrtRSI;
  emlrtFFTWForgetDoublePlan();
  st.site = &j_emlrtRSI;
  fftw(&st);
  xnum = Temp->Eq.Pump.omega_p * 0.0;
  phase_pump.re = Temp->In.t_start * xnum;
  phase_pump.im = Temp->In.t_start * -Temp->Eq.Pump.omega_p;
  if (phase_pump.im == 0.0) {
    mu = phase_pump.re;
    phase_pump.re = muDoubleScalarExp(mu);
    phase_pump.im = 0.0;
  } else {
    r = muDoubleScalarExp(phase_pump.re / 2.0);
    mu = phase_pump.im;
    b_d = phase_pump.im;
    phase_pump.re = r * (r * muDoubleScalarCos(mu));
    phase_pump.im = r * (r * muDoubleScalarSin(b_d));
  }
  emxInit_creal_T(sp, &c_d, &ob_emlrtRTEI);
  i = c_d->size[0] * c_d->size[1];
  c_d->size[0] = d->size[0];
  c_d->size[1] = d->size[1];
  emxEnsureCapacity_creal_T(sp, c_d, i, &ob_emlrtRTEI);
  k_zero_data = c_d->data;
  loop_ub = d->size[0] * d->size[1] - 1;
  for (i = 0; i <= loop_ub; i++) {
    k_zero_data[i] = d_data[i];
  }
  emxInit_char_T(sp, &fftinfo, &sb_emlrtRTEI);
  st.site = &k_emlrtRSI;
  Runge_Kuarong_step(&st, &N, &SD->f0.Temp, &Field, &G_theta, &ind_pump,
                     &exp_plus_omega, &exp_minus_omega, &pump_phase_substep,
                     &b_Runge, &shift_back, Temp->In.Psi_Start, Temp->Par.dt,
                     phase_pump, c_d, k_zero);
  st.site = &l_emlrtRSI;
  b_fftw(&st, fftinfo);
  st.site = &m_emlrtRSI;
  c_fftw(&st, fftinfo);
  /*     mode_cut  = zeros(1,1024); */
  /*     mode_cut(185)  =  1; */
  /*   mode_cut(326)  =  1; */
  /*     mode_cut(412)  =  1; */
  i = (int32_T)((nt - 1.0) + 1.0);
  emlrtForLoopVectorCheckR2021a(0.0, 1.0, nt - 1.0, mxDOUBLE_CLASS,
                                (int32_T)((nt - 1.0) + 1.0), &c_emlrtRTEI,
                                (emlrtCTX)sp);
  idx = 0;
  emxFree_char_T(sp, &fftinfo);
  for (k = 0; k < i; k++) {
    idx = k;
    r = (real_T)k * dt_tmp_tmp;
    phase_pump.re = r * xnum;
    phase_pump.im = r * -Temp->Eq.Pump.omega_p;
    if (phase_pump.im == 0.0) {
      mu = phase_pump.re;
      phase_pump.re = muDoubleScalarExp(mu);
      phase_pump.im = 0.0;
    } else {
      r = muDoubleScalarExp(phase_pump.re / 2.0);
      mu = phase_pump.im;
      b_d = phase_pump.im;
      phase_pump.re = r * (r * muDoubleScalarCos(mu));
      phase_pump.im = r * (r * muDoubleScalarSin(b_d));
    }
    /*        phase_pump       = exp(1i*Temp.Eq.Pump.delta*( ni*dt)); */
    i1 = c_d->size[0] * c_d->size[1];
    c_d->size[0] = d->size[0];
    c_d->size[1] = d->size[1];
    emxEnsureCapacity_creal_T(sp, c_d, i1, &qb_emlrtRTEI);
    k_zero_data = c_d->data;
    loop_ub = d->size[0] * d->size[1] - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
      k_zero_data[i1] = d_data[i1];
    }
    st.site = &n_emlrtRSI;
    b_Runge_Kuarong_step(&st, &N, &SD->f0.Temp, &Field, &G_theta, &ind_pump,
                         &exp_plus_omega, &exp_minus_omega, &pump_phase_substep,
                         &b_Runge, &shift_back, F_e, dt_tmp_tmp, phase_pump,
                         c_d, k_zero);
    /* ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back */
    st.site = &o_emlrtRSI;
    Get_Field(&st, N.contents / 2.0, F_e, Field.contents);
    if (1 > Field.contents->size[1]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, Field.contents->size[1], &c_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (((int32_T)(k + 1U) < 1) ||
        ((int32_T)(k + 1U) > Sol->PsiReal->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, Sol->PsiReal->size[1],
                                    &g_emlrtBCI, (emlrtCTX)sp);
    }
    Sol->PsiReal->data[k].re = Field.contents->data[0].re;
    if (((int32_T)(k + 1U) < 1) ||
        ((int32_T)(k + 1U) > Sol->PsiReal->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(k + 1U), 1, Sol->PsiReal->size[1],
                                    &g_emlrtBCI, (emlrtCTX)sp);
    }
    Sol->PsiReal->data[k].im = Field.contents->data[0].im;
    /*         nii = nii +1; */
    /*         F_Intermid(nii,:) = F_e(Temp.Eq.mode_range); */
    /*         if mod(ni,NRF) == 0 */
    /*             nii = 0; */
    /*         end */
    if (b_mod(k, Temp->Par.s_t / Temp->Par.dt) == 0.0) {
      r = muDoubleScalarRound((real_T)k * Temp->Par.dt / Temp->Par.s_t);
      if (r + 1.0 != (int32_T)(r + 1.0)) {
        emlrtIntegerCheckR2012b(r + 1.0, &emlrtDCI, (emlrtCTX)sp);
      }
      if (((int32_T)(r + 1.0) < 1) ||
          ((int32_T)(r + 1.0) > Sol->Psi->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(r + 1.0), 1, Sol->Psi->size[0],
                                      &b_emlrtBCI, (emlrtCTX)sp);
      }
      for (i1 = 0; i1 < 1309; i1++) {
        mu = Temp->Eq.mode_range[i1];
        b_i = (int32_T)muDoubleScalarFloor(mu);
        if (mu != b_i) {
          emlrtIntegerCheckR2012b(mu, &x_emlrtDCI, (emlrtCTX)sp);
        }
        last = (int32_T)mu;
        if ((last < 1) || (last > 2048)) {
          emlrtDynamicBoundsCheckR2012b(last, 1, 2048, &h_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        Sol->Psi->data[((int32_T)(r + 1.0) + Sol->Psi->size[0] * i1) - 1].re =
            F_e[last - 1].re;
        if (last != b_i) {
          emlrtIntegerCheckR2012b(mu, &x_emlrtDCI, (emlrtCTX)sp);
        }
        Sol->Psi->data[((int32_T)(r + 1.0) + Sol->Psi->size[0] * i1) - 1].im =
            F_e[last - 1].im;
      }
      /*             Sol.Psie(ind_s ,:) =
       * F_e(Temp.Space.N+1:2*Temp.Space.N)/Temp.Space.N; */
      if (((int32_T)(r + 1.0) < 1) || ((int32_T)(r + 1.0) > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(r + 1.0), 1, Sol->t->size[1],
                                      &i_emlrtBCI, (emlrtCTX)sp);
      }
      Sol->t->data[(int32_T)(r + 1.0) - 1].re =
          xden + dt_tmp_tmp * ((real_T)k + 1.0);
      if (((int32_T)(r + 1.0) < 1) || ((int32_T)(r + 1.0) > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(r + 1.0), 1, Sol->t->size[1],
                                      &i_emlrtBCI, (emlrtCTX)sp);
      }
      Sol->t->data[(int32_T)(r + 1.0) - 1].im = 0.0;
      /*             if 10*log10(sum(abs(Sol.Psio(ind_s,2:end)).^2)) <= -100 &&
       * (mod(ind_s,2) == 0) */
      /*                    Sol.Psio(ind_s+1:end,:) = []; */
      /*                   Sol.Psie(ind_s+1:end,:) = []; */
      /*                  Sol.t(ind_s+1:end)     = [];                 */
      /*                 break; */
      /*        end */
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_creal_T(sp, &c_d);
  emxFree_creal_T(sp, &k_zero);
  emxFree_creal_T(sp, &d);
  emxFreeStruct_captured_var(sp, &exp_minus_omega);
  emxFreeStruct_captured_var(sp, &exp_plus_omega);
  emxFreeStruct_captured_var1(sp, &ind_pump);
  emxFreeStruct_captured_var(sp, &shift_back);
  emxFreeStruct_captured_var(sp, &Field);
  last = Sol->Psi->size[0];
  if (Sol->Psi->size[0] < 1) {
    emlrtDynamicBoundsCheckR2012b(Sol->Psi->size[0], 1, Sol->Psi->size[0],
                                  &emlrtBCI, (emlrtCTX)sp);
  }
  for (i = 0; i < 1309; i++) {
    mu = Temp->Eq.mode_range[i];
    i1 = (int32_T)muDoubleScalarFloor(mu);
    if (mu != i1) {
      emlrtIntegerCheckR2012b(mu, &w_emlrtDCI, (emlrtCTX)sp);
    }
    b_i = (int32_T)mu;
    if ((b_i < 1) || (b_i > 2048)) {
      emlrtDynamicBoundsCheckR2012b(b_i, 1, 2048, &e_emlrtBCI, (emlrtCTX)sp);
    }
    Sol->Psi->data[(last + Sol->Psi->size[0] * i) - 1].re = F_e[b_i - 1].re;
    if (b_i != i1) {
      emlrtIntegerCheckR2012b(mu, &w_emlrtDCI, (emlrtCTX)sp);
    }
    Sol->Psi->data[(last + Sol->Psi->size[0] * i) - 1].im = F_e[b_i - 1].im;
  }
  if (Sol->t->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(Sol->t->size[1], 1, Sol->t->size[1],
                                  &f_emlrtBCI, (emlrtCTX)sp);
  }
  Sol->t->data[Sol->t->size[1] - 1].re =
      Temp->In.t_start + Temp->Par.dt * ((real_T)idx + 1.0);
  if (Sol->t->size[1] < 1) {
    emlrtDynamicBoundsCheckR2012b(Sol->t->size[1], 1, Sol->t->size[1],
                                  &f_emlrtBCI, (emlrtCTX)sp);
  }
  Sol->t->data[Sol->t->size[1] - 1].im = 0.0;
  i = Sol->G->size[0] * Sol->G->size[1];
  Sol->G->size[0] = 1;
  Sol->G->size[1] = G_theta.contents->size[1];
  emxEnsureCapacity_real_T(sp, Sol->G, i, &pb_emlrtRTEI);
  loop_ub = G_theta.contents->size[1];
  for (i = 0; i < loop_ub; i++) {
    Sol->G->data[i] = G_theta.contents->data[i];
  }
  emxFreeStruct_captured_var1(sp, &G_theta);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (FullField_SingleProgection_dynamics.c) */
