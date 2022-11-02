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
#include "Chi23_Runge_Kuarong.h"
#include "Chi23_Runge_Kuarong_data.h"
#include "Chi23_Runge_Kuarong_emxutil.h"
#include "Chi23_Runge_Kuarong_types.h"
#include "fft.h"
#include "ifft.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    33,                    /* lineNo */
    "Chi23_Runge_Kuarong", /* fcnName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    3,                     /* lineNo */
    "Chi23_Runge_Kuarong", /* fcnName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    77,                                       /* lineNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fcnName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                                       /* iFirst */
    -1,                                       /* iLast */
    87,                                       /* lineNo */
    90,                                       /* colNo */
    "d",                                      /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = {
    83,                                       /* lineNo */
    18,                                       /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    -1,                                       /* nDims */
    77,                                       /* lineNo */
    13,                                       /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                                       /* iFirst */
    -1,                                       /* iLast */
    77,                                       /* lineNo */
    15,                                       /* colNo */
    "d",                                      /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    1,                                        /* iFirst */
    3,                                        /* iLast */
    77,                                       /* lineNo */
    66,                                       /* colNo */
    "exp_plus_omega",                         /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,                                       /* iFirst */
    -1,                                       /* iLast */
    71,                                       /* lineNo */
    105,                                      /* colNo */
    "d",                                      /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = {
    67,                                       /* lineNo */
    22,                                       /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    65,                                       /* lineNo */
    18,                                       /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    -1,                                       /* nDims */
    63,                                       /* lineNo */
    9,                                        /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                                       /* iFirst */
    -1,                                       /* iLast */
    63,                                       /* lineNo */
    11,                                       /* colNo */
    "d",                                      /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    31,                    /* lineNo */
    14,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtDCInfo emlrtDCI = {
    39,                    /* lineNo */
    40,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    1,                     /* iFirst */
    512,                   /* iLast */
    39,                    /* lineNo */
    40,                    /* colNo */
    "F_e",                 /* aName */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    40,                    /* lineNo */
    38,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    1,                     /* iFirst */
    512,                   /* iLast */
    40,                    /* lineNo */
    38,                    /* colNo */
    "F_e",                 /* aName */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    40,                    /* lineNo */
    53,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    1,                     /* iFirst */
    512,                   /* iLast */
    40,                    /* lineNo */
    53,                    /* colNo */
    "F_e",                 /* aName */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    39,                    /* lineNo */
    22,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    39,                    /* lineNo */
    22,                    /* colNo */
    "Sol.Psio",            /* aName */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtECInfo c_emlrtECI = {
    -1,                    /* nDims */
    39,                    /* lineNo */
    13,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    40,                    /* lineNo */
    22,                    /* colNo */
    "Sol.Psie",            /* aName */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtECInfo d_emlrtECI = {
    -1,                    /* nDims */
    40,                    /* lineNo */
    13,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtDCInfo e_emlrtDCI = {
    3,                     /* lineNo */
    35,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    3,                     /* lineNo */
    35,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    4       /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    3,                     /* lineNo */
    43,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = {
    3,                     /* lineNo */
    43,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    4       /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = {
    25,                    /* lineNo */
    30,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = {
    25,                    /* lineNo */
    30,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    4       /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = {
    25,                    /* lineNo */
    42,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = {
    25,                    /* lineNo */
    42,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    4       /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = {
    26,                    /* lineNo */
    30,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = {
    26,                    /* lineNo */
    42,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = {
    28,                    /* lineNo */
    32,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = {
    3,                     /* lineNo */
    5,                     /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = {
    25,                    /* lineNo */
    5,                     /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = {
    26,                    /* lineNo */
    5,                     /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtDCInfo s_emlrtDCI = {
    28,                    /* lineNo */
    5,                     /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    1,                                        /* iFirst */
    3,                                        /* iLast */
    85,                                       /* lineNo */
    25,                                       /* colNo */
    "Runge.c",                                /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    1,                                        /* iFirst */
    3,                                        /* iLast */
    69,                                       /* lineNo */
    28,                                       /* colNo */
    "Runge.b",                                /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    1,                                        /* iFirst */
    3,                                        /* iLast */
    69,                                       /* lineNo */
    31,                                       /* colNo */
    "Runge.b",                                /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = {
    1,                                        /* iFirst */
    512,                                      /* iLast */
    93,                                       /* lineNo */
    12,                                       /* colNo */
    "E_f",                                    /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    3       /* checkKind */
};

static emlrtDCInfo t_emlrtDCI = {
    93,                                       /* lineNo */
    12,                                       /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = {
    1,                                        /* iFirst */
    512,                                      /* iLast */
    87,                                       /* lineNo */
    50,                                       /* colNo */
    "E_f",                                    /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtDCInfo u_emlrtDCI = {
    87,                                       /* lineNo */
    50,                                       /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = {
    -1,                                       /* iFirst */
    -1,                                       /* iLast */
    87,                                       /* lineNo */
    93,                                       /* colNo */
    "d",                                      /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtDCInfo v_emlrtDCI = {
    87,                                       /* lineNo */
    93,                                       /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    1,                                        /* iFirst */
    512,                                      /* iLast */
    71,                                       /* lineNo */
    62,                                       /* colNo */
    "E_temp",                                 /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtDCInfo w_emlrtDCI = {
    71,                                       /* lineNo */
    62,                                       /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    -1,                                       /* iFirst */
    -1,                                       /* iLast */
    71,                                       /* lineNo */
    108,                                      /* colNo */
    "d",                                      /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtDCInfo x_emlrtDCI = {
    71,                                       /* lineNo */
    108,                                      /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo s_emlrtBCI = {
    1,                                        /* iFirst */
    512,                                      /* iLast */
    87,                                       /* lineNo */
    17,                                       /* colNo */
    "E_f",                                    /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    3       /* checkKind */
};

static emlrtDCInfo y_emlrtDCI = {
    87,                                       /* lineNo */
    17,                                       /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo t_emlrtBCI = {
    1,                                        /* iFirst */
    512,                                      /* iLast */
    71,                                       /* lineNo */
    21,                                       /* colNo */
    "E_temp",                                 /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    3       /* checkKind */
};

static emlrtDCInfo ab_emlrtDCI = {
    71,                                       /* lineNo */
    21,                                       /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    -1,                    /* iFirst */
    -1,                    /* iLast */
    42,                    /* lineNo */
    21,                    /* colNo */
    "Sol.t",               /* aName */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo v_emlrtBCI = {
    1,                                        /* iFirst */
    512,                                      /* iLast */
    93,                                       /* lineNo */
    38,                                       /* colNo */
    "shift_back",                             /* aName */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    0       /* checkKind */
};

static emlrtDCInfo bb_emlrtDCI = {
    93,                                       /* lineNo */
    38,                                       /* colNo */
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m", /* pName */
    1       /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = {
    3,                     /* lineNo */
    5,                     /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = {
    25,                    /* lineNo */
    5,                     /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = {
    26,                    /* lineNo */
    5,                     /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = {
    28,                    /* lineNo */
    5,                     /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    33,                    /* lineNo */
    61,                    /* colNo */
    "Chi23_Runge_Kuarong", /* fName */
    "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_"
    "Codes\\Models\\Chi_2_3\\Solution_Search\\Temporal\\Chi23_Runge_Kuaro"
    "ng.m" /* pName */
};

/* Function Definitions */
void Chi23_Runge_Kuarong(const emlrtStack *sp, const struct0_T *Temp,
                         const struct7_T *Runge, struct8_T *Sol)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_creal_T *c_d;
  emxArray_cuint8_T *d;
  creal_T exp_minus_omega_contents[1536];
  creal_T exp_plus_omega_contents[1536];
  creal_T E_temp[512];
  creal_T F_e[512];
  creal_T k_e[512];
  creal_T y[512];
  creal_T Psie[256];
  creal_T Psio[256];
  creal_T b_F_e[256];
  creal_T c_y[256];
  creal_T dcv[256];
  creal_T *b_d_data;
  cuint8_T *d_data;
  real_T b[256];
  real_T d_y[256];
  real_T b_d;
  real_T b_im;
  real_T b_re;
  real_T b_re_tmp;
  real_T b_y;
  real_T d1;
  real_T d2;
  real_T dt_tmp_tmp;
  real_T im;
  real_T im_tmp;
  real_T ind_s;
  real_T nt;
  real_T q;
  real_T r;
  real_T re;
  real_T re_tmp;
  int32_T iv[2];
  int32_T iv1[2];
  int32_T tmp_size[2];
  int32_T b_i;
  int32_T b_i2;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T loop_ub;
  int32_T ni;
  boolean_T rEQ0;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_cuint8_T(sp, &d, &e_emlrtRTEI);
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &f_emlrtDCI, (emlrtCTX)sp);
  }
  r = (int32_T)muDoubleScalarFloor(Runge->s);
  if (Runge->s != r) {
    emlrtIntegerCheckR2012b(Runge->s, &e_emlrtDCI, (emlrtCTX)sp);
  }
  i = d->size[0] * d->size[1];
  d->size[0] = (int32_T)Runge->s;
  emxEnsureCapacity_cuint8_T(sp, d, i, &e_emlrtRTEI);
  b_d = 2.0 * Temp->Space.N;
  if (!(b_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(b_d, &h_emlrtDCI, (emlrtCTX)sp);
  }
  d1 = (int32_T)muDoubleScalarFloor(b_d);
  if (b_d != d1) {
    emlrtIntegerCheckR2012b(b_d, &g_emlrtDCI, (emlrtCTX)sp);
  }
  i = d->size[0] * d->size[1];
  d->size[1] = (int32_T)b_d;
  emxEnsureCapacity_cuint8_T(sp, d, i, &e_emlrtRTEI);
  d_data = d->data;
  if (Runge->s != r) {
    emlrtIntegerCheckR2012b(Runge->s, &p_emlrtDCI, (emlrtCTX)sp);
  }
  if (b_d != d1) {
    emlrtIntegerCheckR2012b(b_d, &p_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = (int32_T)Runge->s * (int32_T)b_d;
  for (i = 0; i < loop_ub; i++) {
    d_data[i].re = 0U;
    d_data[i].im = 0U;
  }
  dt_tmp_tmp = Temp->Par.dt;
  nt = Temp->Par.T / Temp->Par.dt;
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  for (b_i = 0; b_i < 3; b_i++) {
    q = Runge->a[b_i];
    for (loop_ub = 0; loop_ub < 512; loop_ub++) {
      re_tmp = Temp->Eq.L[loop_ub].im;
      b_re_tmp = Temp->Eq.L[loop_ub].re;
      ind_s = 0.0 * b_re_tmp;
      im_tmp = 0.0 * re_tmp;
      re = dt_tmp_tmp * (q * (ind_s - (-re_tmp)));
      im = dt_tmp_tmp * (q * (im_tmp + -b_re_tmp));
      if (im == 0.0) {
        re = muDoubleScalarExp(re);
        im = 0.0;
      } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) &&
                 (re < 0.0)) {
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
      re = dt_tmp_tmp * (q * (ind_s - re_tmp));
      im = dt_tmp_tmp * (q * (im_tmp + b_re_tmp));
      if (im == 0.0) {
        re = muDoubleScalarExp(re);
        im = 0.0;
      } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) &&
                 (re < 0.0)) {
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
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
   */
  for (loop_ub = 0; loop_ub < 512; loop_ub++) {
    re_tmp = Temp->Eq.L[loop_ub].im;
    b_re_tmp = Temp->Eq.L[loop_ub].re;
    re = dt_tmp_tmp * (0.0 * b_re_tmp - (-re_tmp));
    im = dt_tmp_tmp * (0.0 * re_tmp + -b_re_tmp);
    y[loop_ub].re = re;
    y[loop_ub].im = im;
    if (im == 0.0) {
      y[loop_ub].re = muDoubleScalarExp(re);
      y[loop_ub].im = 0.0;
    } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) &&
               (re < 0.0)) {
      y[loop_ub].re = 0.0;
      y[loop_ub].im = 0.0;
    } else {
      r = muDoubleScalarExp(re / 2.0);
      y[loop_ub].re = r * (r * muDoubleScalarCos(im));
      y[loop_ub].im = r * (r * muDoubleScalarSin(im));
    }
    F_e[loop_ub] = Temp->In.Psi_Start[loop_ub];
  }
  if (!(Temp->Par.dd >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Par.dd, &j_emlrtDCI, (emlrtCTX)sp);
  }
  r = (int32_T)muDoubleScalarFloor(Temp->Par.dd);
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &i_emlrtDCI, (emlrtCTX)sp);
  }
  i = Sol->Psio->size[0] * Sol->Psio->size[1];
  loop_ub = (int32_T)Temp->Par.dd;
  Sol->Psio->size[0] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->Psio, i, &f_emlrtRTEI);
  if (!(Temp->Space.N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Space.N, &l_emlrtDCI, (emlrtCTX)sp);
  }
  d2 = (int32_T)muDoubleScalarFloor(Temp->Space.N);
  if (Temp->Space.N != d2) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &k_emlrtDCI, (emlrtCTX)sp);
  }
  i = Sol->Psio->size[0] * Sol->Psio->size[1];
  i1 = (int32_T)Temp->Space.N;
  Sol->Psio->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_creal_T(sp, Sol->Psio, i, &f_emlrtRTEI);
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &q_emlrtDCI, (emlrtCTX)sp);
  }
  if (Temp->Space.N != d2) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &q_emlrtDCI, (emlrtCTX)sp);
  }
  b_i = (int32_T)Temp->Par.dd * (int32_T)Temp->Space.N;
  for (i = 0; i < b_i; i++) {
    Sol->Psio->data[i].re = 0.0;
    Sol->Psio->data[i].im = 0.0;
  }
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &m_emlrtDCI, (emlrtCTX)sp);
  }
  i = Sol->Psie->size[0] * Sol->Psie->size[1];
  Sol->Psie->size[0] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->Psie, i, &g_emlrtRTEI);
  if (Temp->Space.N != d2) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &n_emlrtDCI, (emlrtCTX)sp);
  }
  i = Sol->Psie->size[0] * Sol->Psie->size[1];
  Sol->Psie->size[1] = (int32_T)Temp->Space.N;
  emxEnsureCapacity_creal_T(sp, Sol->Psie, i, &g_emlrtRTEI);
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &r_emlrtDCI, (emlrtCTX)sp);
  }
  if (Temp->Space.N != d2) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &r_emlrtDCI, (emlrtCTX)sp);
  }
  for (i = 0; i < b_i; i++) {
    Sol->Psie->data[i].re = 0.0;
    Sol->Psie->data[i].im = 0.0;
  }
  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &h_emlrtRTEI);
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &o_emlrtDCI, (emlrtCTX)sp);
  }
  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[1] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &h_emlrtRTEI);
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &s_emlrtDCI, (emlrtCTX)sp);
  }
  for (i = 0; i < loop_ub; i++) {
    Sol->t->data[i].re = 0.0;
    Sol->t->data[i].im = 0.0;
  }
  i = (int32_T)nt;
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, nt, mxDOUBLE_CLASS, (int32_T)nt,
                                &d_emlrtRTEI, (emlrtCTX)sp);
  if (0 <= (int32_T)nt - 1) {
    b_loop_ub = d->size[0] * d->size[1];
    i2 = (int32_T)(Runge->s + -1.0);
    i3 = (int32_T)Runge->s;
    b_y = Temp->Par.s_t / Temp->Par.dt;
  }
  emxInit_creal_T(sp, &c_d, &i_emlrtRTEI);
  if (0 <= i - 1) {
    q = 256.0 * exp_plus_omega_contents[0].re;
    im_tmp = 256.0 * exp_plus_omega_contents[0].im;
    if (im_tmp == 0.0) {
      b_re = q / 2.0;
      b_im = 0.0;
    } else if (q == 0.0) {
      b_re = 0.0;
      b_im = im_tmp / 2.0;
    } else {
      b_re = q / 2.0;
      b_im = im_tmp / 2.0;
    }
  }
  for (ni = 0; ni < i; ni++) {
    st.site = &emlrtRSI;
    i4 = c_d->size[0] * c_d->size[1];
    c_d->size[0] = d->size[0];
    c_d->size[1] = d->size[1];
    emxEnsureCapacity_creal_T(&st, c_d, i4, &i_emlrtRTEI);
    b_d_data = c_d->data;
    for (i4 = 0; i4 < b_loop_ub; i4++) {
      b_d_data[i4].re = 0.0;
      b_d_data[i4].im = d_data[i4].im;
    }
    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
     */
    memcpy(&E_temp[0], &F_e[0], 512U * sizeof(creal_T));
    if (1 > d->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, d->size[0], &e_emlrtBCI, &st);
    }
    iv[0] = 1;
    iv[1] = d->size[1];
    iv1[0] = 1;
    iv1[1] = 512;
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &b_emlrtECI, &st);
    for (i4 = 0; i4 < 256; i4++) {
      r = F_e[i4].re;
      b_re_tmp = exp_minus_omega_contents[3 * i4].im;
      ind_s = F_e[i4].im;
      im_tmp = exp_minus_omega_contents[3 * i4].re;
      b_F_e[i4].re = r * im_tmp - ind_s * b_re_tmp;
      b_F_e[i4].im = r * b_re_tmp + ind_s * im_tmp;
    }
    ifft(b_F_e, Psio);
    for (i4 = 0; i4 < 256; i4++) {
      i5 = 3 * (i4 + 256);
      r = F_e[i4 + 256].re;
      b_re_tmp = exp_minus_omega_contents[i5].im;
      ind_s = F_e[i4 + 256].im;
      im_tmp = exp_minus_omega_contents[i5].re;
      b_F_e[i4].re = r * im_tmp - ind_s * b_re_tmp;
      b_F_e[i4].im = r * b_re_tmp + ind_s * im_tmp;
    }
    ifft(b_F_e, Psie);
    memset(&k_e[0], 0, 512U * sizeof(creal_T));
    for (loop_ub = 0; loop_ub < 256; loop_ub++) {
      r = Psie[loop_ub].re;
      b_re_tmp = Psie[loop_ub].im;
      ind_s = muDoubleScalarHypot(r, b_re_tmp);
      b[loop_ub] = ind_s * ind_s;
      q = Psio[loop_ub].re;
      im_tmp = Psio[loop_ub].im;
      ind_s = muDoubleScalarHypot(q, im_tmp);
      d_y[loop_ub] = ind_s * ind_s;
      b_F_e[loop_ub].re = q * r - -im_tmp * b_re_tmp;
      b_F_e[loop_ub].im = q * b_re_tmp + -im_tmp * r;
    }
    fft(b_F_e, dcv);
    for (i4 = 0; i4 < 256; i4++) {
      r = d_y[i4] + 2.0 * b[i4];
      b_F_e[i4].re = r * Psio[i4].re;
      b_F_e[i4].im = r * Psio[i4].im;
    }
    fft(b_F_e, c_y);
    /*  */
    for (loop_ub = 0; loop_ub < 256; loop_ub++) {
      re_tmp = exp_plus_omega_contents[3 * loop_ub].im;
      b_re_tmp = exp_plus_omega_contents[3 * loop_ub].re;
      re = 0.0 * b_re_tmp - re_tmp;
      im = 0.0 * re_tmp + b_re_tmp;
      r = Temp->Eq.gam2o[loop_ub];
      b_re_tmp = Temp->Eq.gam3o[loop_ub];
      re_tmp = r * dcv[loop_ub].re + b_re_tmp * c_y[loop_ub].re;
      q = r * dcv[loop_ub].im + b_re_tmp * c_y[loop_ub].im;
      k_e[loop_ub].re = re * re_tmp - im * q;
      k_e[loop_ub].im = re * q + im * re_tmp;
      r = Psio[loop_ub].re;
      b_re_tmp = Psio[loop_ub].im;
      ind_s = muDoubleScalarHypot(r, b_re_tmp);
      b[loop_ub] = ind_s * ind_s;
      c_y[loop_ub].re = r * r - b_re_tmp * b_re_tmp;
      r *= b_re_tmp;
      c_y[loop_ub].im = r + r;
      ind_s = muDoubleScalarHypot(Psie[loop_ub].re, Psie[loop_ub].im);
      d_y[loop_ub] = ind_s * ind_s;
    }
    fft(c_y, dcv);
    for (i4 = 0; i4 < 256; i4++) {
      r = 2.0 * b[i4] + d_y[i4];
      Psie[i4].re *= r;
      Psie[i4].im *= r;
    }
    fft(Psie, c_y);
    for (i4 = 0; i4 < 256; i4++) {
      b_i = 3 * (i4 + 256);
      re_tmp = exp_plus_omega_contents[b_i].im;
      b_re_tmp = exp_plus_omega_contents[b_i].re;
      re = 0.0 * b_re_tmp - re_tmp;
      im = 0.0 * re_tmp + b_re_tmp;
      r = Temp->Eq.gam2e[i4];
      b_re_tmp = Temp->Eq.gam3e[i4];
      re_tmp = r * dcv[i4].re + b_re_tmp * c_y[i4].re;
      q = r * dcv[i4].im + b_re_tmp * c_y[i4].im;
      k_e[i4 + 256].re = re * re_tmp - im * q;
      k_e[i4 + 256].im = re * q + im * re_tmp;
    }
    /*   */
    k_e[0].re += Temp->Eq.ko * b_re * Temp->Eq.H_f;
    k_e[0].im += Temp->Eq.ko * b_im * Temp->Eq.H_f;
    loop_ub = d->size[1];
    for (i4 = 0; i4 < loop_ub; i4++) {
      b_d_data[c_d->size[0] * i4] = k_e[i4];
    }
    emlrtForLoopVectorCheckR2021a(2.0, 1.0, Runge->s, mxDOUBLE_CLASS,
                                  (int32_T)(Runge->s + -1.0), &c_emlrtRTEI,
                                  &st);
    if (0 <= i2 - 1) {
      iv1[0] = 1;
      iv1[1] = 512;
    }
    if (0 <= i2 - 1) {
      i6 = (int32_T)(Runge->s - 1.0);
    }
    for (b_i2 = 0; b_i2 < i2; b_i2++) {
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
                                    (int32_T)(Runge->s - 1.0), &b_emlrtRTEI,
                                    &st);
      for (loop_ub = 0; loop_ub < i6; loop_ub++) {
        if (((int32_T)(b_i2 + 2U) < 1) || ((int32_T)(b_i2 + 2U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i2 + 2U), 1, 3, &l_emlrtBCI,
                                        &st);
        }
        if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, 3,
                                        &m_emlrtBCI, &st);
        }
        r = Runge->b[(b_i2 + 3 * loop_ub) + 1];
        if (r != 0.0) {
          q = dt_tmp_tmp * r;
          if (((int32_T)(loop_ub + 1U) < 1) ||
              ((int32_T)(loop_ub + 1U) > c_d->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1,
                                          c_d->size[0], &d_emlrtBCI, &st);
          }
          for (i4 = 0; i4 < 512; i4++) {
            r = Temp->Eq.mode_range[i4];
            i5 = (int32_T)muDoubleScalarFloor(r);
            if (r != i5) {
              emlrtIntegerCheckR2012b(r, &w_emlrtDCI, &st);
            }
            b_i = (int32_T)r;
            if ((b_i < 1) || (b_i > 512)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, 512, &q_emlrtBCI, &st);
            }
            if (b_i != i5) {
              emlrtIntegerCheckR2012b(r, &x_emlrtDCI, &st);
            }
            if (b_i > c_d->size[1]) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &r_emlrtBCI,
                                            &st);
            }
            k_e[i4].re = E_temp[b_i - 1].re +
                         q * b_d_data[loop_ub + c_d->size[0] * (b_i - 1)].re;
            if (b_i != i5) {
              emlrtIntegerCheckR2012b(r, &w_emlrtDCI, &st);
            }
            if (b_i > c_d->size[1]) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &r_emlrtBCI,
                                            &st);
            }
            k_e[i4].im = E_temp[b_i - 1].im +
                         q * b_d_data[loop_ub + c_d->size[0] * (b_i - 1)].im;
          }
          for (i4 = 0; i4 < 512; i4++) {
            r = Temp->Eq.mode_range[i4];
            i5 = (int32_T)muDoubleScalarFloor(r);
            if (r != i5) {
              emlrtIntegerCheckR2012b(r, &ab_emlrtDCI, &st);
            }
            b_i = (int32_T)r;
            if ((b_i < 1) || (b_i > 512)) {
              emlrtDynamicBoundsCheckR2012b(b_i, 1, 512, &t_emlrtBCI, &st);
            }
            E_temp[b_i - 1].re = k_e[i4].re;
            if (b_i != i5) {
              emlrtIntegerCheckR2012b(r, &ab_emlrtDCI, &st);
            }
            E_temp[b_i - 1].im = k_e[i4].im;
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
      for (i4 = 0; i4 < 256; i4++) {
        i5 = (b_i2 + 3 * i4) + 1;
        r = E_temp[i4].re;
        b_re_tmp = exp_minus_omega_contents[i5].im;
        ind_s = E_temp[i4].im;
        im_tmp = exp_minus_omega_contents[i5].re;
        b_F_e[i4].re = r * im_tmp - ind_s * b_re_tmp;
        b_F_e[i4].im = r * b_re_tmp + ind_s * im_tmp;
      }
      ifft(b_F_e, Psio);
      for (i4 = 0; i4 < 256; i4++) {
        i5 = (b_i2 + 3 * (i4 + 256)) + 1;
        r = E_temp[i4 + 256].re;
        b_re_tmp = exp_minus_omega_contents[i5].im;
        ind_s = E_temp[i4 + 256].im;
        im_tmp = exp_minus_omega_contents[i5].re;
        b_F_e[i4].re = r * im_tmp - ind_s * b_re_tmp;
        b_F_e[i4].im = r * b_re_tmp + ind_s * im_tmp;
      }
      ifft(b_F_e, Psie);
      memset(&k_e[0], 0, 512U * sizeof(creal_T));
      for (loop_ub = 0; loop_ub < 256; loop_ub++) {
        r = Psie[loop_ub].re;
        b_re_tmp = Psie[loop_ub].im;
        ind_s = muDoubleScalarHypot(r, b_re_tmp);
        b[loop_ub] = ind_s * ind_s;
        q = Psio[loop_ub].re;
        im_tmp = Psio[loop_ub].im;
        ind_s = muDoubleScalarHypot(q, im_tmp);
        d_y[loop_ub] = ind_s * ind_s;
        b_F_e[loop_ub].re = q * r - -im_tmp * b_re_tmp;
        b_F_e[loop_ub].im = q * b_re_tmp + -im_tmp * r;
      }
      fft(b_F_e, dcv);
      for (i4 = 0; i4 < 256; i4++) {
        r = d_y[i4] + 2.0 * b[i4];
        b_F_e[i4].re = r * Psio[i4].re;
        b_F_e[i4].im = r * Psio[i4].im;
      }
      fft(b_F_e, c_y);
      /*  */
      for (loop_ub = 0; loop_ub < 256; loop_ub++) {
        b_i = (b_i2 + 3 * loop_ub) + 1;
        re_tmp = exp_plus_omega_contents[b_i].im;
        b_re_tmp = exp_plus_omega_contents[b_i].re;
        re = 0.0 * b_re_tmp - re_tmp;
        im = 0.0 * re_tmp + b_re_tmp;
        r = Temp->Eq.gam2o[loop_ub];
        b_re_tmp = Temp->Eq.gam3o[loop_ub];
        re_tmp = r * dcv[loop_ub].re + b_re_tmp * c_y[loop_ub].re;
        q = r * dcv[loop_ub].im + b_re_tmp * c_y[loop_ub].im;
        k_e[loop_ub].re = re * re_tmp - im * q;
        k_e[loop_ub].im = re * q + im * re_tmp;
        r = Psio[loop_ub].re;
        b_re_tmp = Psio[loop_ub].im;
        ind_s = muDoubleScalarHypot(r, b_re_tmp);
        b[loop_ub] = ind_s * ind_s;
        c_y[loop_ub].re = r * r - b_re_tmp * b_re_tmp;
        r *= b_re_tmp;
        c_y[loop_ub].im = r + r;
        ind_s = muDoubleScalarHypot(Psie[loop_ub].re, Psie[loop_ub].im);
        d_y[loop_ub] = ind_s * ind_s;
      }
      fft(c_y, dcv);
      for (i4 = 0; i4 < 256; i4++) {
        r = 2.0 * b[i4] + d_y[i4];
        Psie[i4].re *= r;
        Psie[i4].im *= r;
      }
      fft(Psie, c_y);
      for (i4 = 0; i4 < 256; i4++) {
        b_i = (b_i2 + 3 * (i4 + 256)) + 1;
        re_tmp = exp_plus_omega_contents[b_i].im;
        b_re_tmp = exp_plus_omega_contents[b_i].re;
        re = 0.0 * b_re_tmp - re_tmp;
        im = 0.0 * re_tmp + b_re_tmp;
        r = Temp->Eq.gam2e[i4];
        b_re_tmp = Temp->Eq.gam3e[i4];
        re_tmp = r * dcv[i4].re + b_re_tmp * c_y[i4].re;
        q = r * dcv[i4].im + b_re_tmp * c_y[i4].im;
        k_e[i4 + 256].re = re * re_tmp - im * q;
        k_e[i4 + 256].im = re * q + im * re_tmp;
      }
      /*   */
      q = 256.0 * exp_plus_omega_contents[b_i2 + 1].re;
      im_tmp = 256.0 * exp_plus_omega_contents[b_i2 + 1].im;
      if (im_tmp == 0.0) {
        re = q / 2.0;
        im = 0.0;
      } else if (q == 0.0) {
        re = 0.0;
        im = im_tmp / 2.0;
      } else {
        re = q / 2.0;
        im = im_tmp / 2.0;
      }
      k_e[0].re += Temp->Eq.ko * re * Temp->Eq.H_f;
      k_e[0].im += Temp->Eq.ko * im * Temp->Eq.H_f;
      loop_ub = c_d->size[1];
      for (i4 = 0; i4 < loop_ub; i4++) {
        b_d_data[(b_i2 + c_d->size[0] * i4) + 1] = k_e[i4];
      }
      memcpy(&E_temp[0], &F_e[0], 512U * sizeof(creal_T));
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, Runge->s, mxDOUBLE_CLASS,
                                  (int32_T)Runge->s, &emlrtRTEI, &st);
    for (loop_ub = 0; loop_ub < i3; loop_ub++) {
      if (((int32_T)(loop_ub + 1U) < 1) || ((int32_T)(loop_ub + 1U) > 3)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1, 3,
                                      &k_emlrtBCI, &st);
      }
      r = Runge->c[loop_ub];
      if (r != 0.0) {
        q = dt_tmp_tmp * r;
        if (((int32_T)(loop_ub + 1U) < 1) ||
            ((int32_T)(loop_ub + 1U) > c_d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(loop_ub + 1U), 1,
                                        c_d->size[0], &emlrtBCI, &st);
        }
        for (i4 = 0; i4 < 512; i4++) {
          r = Temp->Eq.mode_range[i4];
          i5 = (int32_T)muDoubleScalarFloor(r);
          if (r != i5) {
            emlrtIntegerCheckR2012b(r, &u_emlrtDCI, &st);
          }
          b_i = (int32_T)r;
          if ((b_i < 1) || (b_i > 512)) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, 512, &o_emlrtBCI, &st);
          }
          if (b_i != i5) {
            emlrtIntegerCheckR2012b(r, &v_emlrtDCI, &st);
          }
          if (b_i > c_d->size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &p_emlrtBCI,
                                          &st);
          }
          k_e[i4].re = F_e[b_i - 1].re +
                       q * b_d_data[loop_ub + c_d->size[0] * (b_i - 1)].re;
          if (b_i != i5) {
            emlrtIntegerCheckR2012b(r, &u_emlrtDCI, &st);
          }
          if (b_i > c_d->size[1]) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, c_d->size[1], &p_emlrtBCI,
                                          &st);
          }
          k_e[i4].im = F_e[b_i - 1].im +
                       q * b_d_data[loop_ub + c_d->size[0] * (b_i - 1)].im;
        }
        for (i4 = 0; i4 < 512; i4++) {
          r = Temp->Eq.mode_range[i4];
          i5 = (int32_T)muDoubleScalarFloor(r);
          if (r != i5) {
            emlrtIntegerCheckR2012b(r, &y_emlrtDCI, &st);
          }
          b_i = (int32_T)r;
          if ((b_i < 1) || (b_i > 512)) {
            emlrtDynamicBoundsCheckR2012b(b_i, 1, 512, &s_emlrtBCI, &st);
          }
          F_e[b_i - 1].re = k_e[i4].re;
          if (b_i != i5) {
            emlrtIntegerCheckR2012b(r, &y_emlrtDCI, &st);
          }
          F_e[b_i - 1].im = k_e[i4].im;
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    for (i4 = 0; i4 < 512; i4++) {
      r = Temp->Eq.mode_range[i4];
      i5 = (int32_T)muDoubleScalarFloor(r);
      if (r != i5) {
        emlrtIntegerCheckR2012b(r, &bb_emlrtDCI, &st);
      }
      b_i = (int32_T)r;
      if ((b_i < 1) || (b_i > 512)) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, 512, &v_emlrtBCI, &st);
      }
      if (b_i != i5) {
        emlrtIntegerCheckR2012b(r, &bb_emlrtDCI, &st);
      }
      b_re_tmp = y[b_i - 1].re;
      ind_s = F_e[b_i - 1].im;
      im_tmp = y[b_i - 1].im;
      q = F_e[b_i - 1].re;
      E_temp[i4].re = b_re_tmp * q - im_tmp * ind_s;
      if (b_i != i5) {
        emlrtIntegerCheckR2012b(r, &bb_emlrtDCI, &st);
      }
      E_temp[i4].im = b_re_tmp * ind_s + im_tmp * q;
    }
    for (i4 = 0; i4 < 512; i4++) {
      r = Temp->Eq.mode_range[i4];
      i5 = (int32_T)muDoubleScalarFloor(r);
      if (r != i5) {
        emlrtIntegerCheckR2012b(r, &t_emlrtDCI, &st);
      }
      b_i = (int32_T)r;
      if ((b_i < 1) || (b_i > 512)) {
        emlrtDynamicBoundsCheckR2012b(b_i, 1, 512, &n_emlrtBCI, &st);
      }
      F_e[b_i - 1].re = E_temp[i4].re;
      if (b_i != i5) {
        emlrtIntegerCheckR2012b(r, &t_emlrtDCI, &st);
      }
      F_e[b_i - 1].im = E_temp[i4].im;
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
        } else if (b_y < 0.0) {
          r += b_y;
        }
      }
    }
    if (r == 0.0) {
      re_tmp = ((real_T)ni + 1.0) * dt_tmp_tmp;
      ind_s = muDoubleScalarRound(re_tmp / Temp->Par.s_t);
      if (1.0 > Temp->Space.N) {
        loop_ub = 0;
      } else {
        if (Temp->Space.N != d2) {
          emlrtIntegerCheckR2012b(Temp->Space.N, &emlrtDCI, (emlrtCTX)sp);
        }
        if ((i1 < 1) || (i1 > 512)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)Temp->Space.N, 1, 512,
                                        &f_emlrtBCI, (emlrtCTX)sp);
        }
        loop_ub = (int32_T)Temp->Space.N;
      }
      if (ind_s != (int32_T)ind_s) {
        emlrtIntegerCheckR2012b(ind_s, &d_emlrtDCI, (emlrtCTX)sp);
      }
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->Psio->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->Psio->size[0],
                                      &i_emlrtBCI, (emlrtCTX)sp);
      }
      tmp_size[0] = 1;
      tmp_size[1] = loop_ub;
      for (i4 = 0; i4 < loop_ub; i4++) {
        q = F_e[i4].re;
        im_tmp = F_e[i4].im;
        if (im_tmp == 0.0) {
          E_temp[i4].re = q / Temp->Space.N;
          E_temp[i4].im = 0.0;
        } else if (q == 0.0) {
          E_temp[i4].re = 0.0;
          E_temp[i4].im = im_tmp / Temp->Space.N;
        } else {
          E_temp[i4].re = q / Temp->Space.N;
          E_temp[i4].im = im_tmp / Temp->Space.N;
        }
      }
      iv[0] = 1;
      iv[1] = Sol->Psio->size[1];
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &c_emlrtECI,
                                    (emlrtCTX)sp);
      for (i4 = 0; i4 < loop_ub; i4++) {
        Sol->Psio->data[((int32_T)ind_s + Sol->Psio->size[0] * i4) - 1] =
            E_temp[i4];
      }
      if (Temp->Space.N + 1.0 > b_d) {
        i4 = 0;
        i5 = 0;
      } else {
        if (Temp->Space.N + 1.0 !=
            (int32_T)muDoubleScalarFloor(Temp->Space.N + 1.0)) {
          emlrtIntegerCheckR2012b(Temp->Space.N + 1.0, &b_emlrtDCI,
                                  (emlrtCTX)sp);
        }
        if (((int32_T)(Temp->Space.N + 1.0) < 1) ||
            ((int32_T)(Temp->Space.N + 1.0) > 512)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(Temp->Space.N + 1.0), 1, 512,
                                        &g_emlrtBCI, (emlrtCTX)sp);
        }
        i4 = (int32_T)(Temp->Space.N + 1.0) - 1;
        if (b_d != d1) {
          emlrtIntegerCheckR2012b(b_d, &c_emlrtDCI, (emlrtCTX)sp);
        }
        if (((int32_T)b_d < 1) || ((int32_T)b_d > 512)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_d, 1, 512, &h_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        i5 = (int32_T)b_d;
      }
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->Psie->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->Psie->size[0],
                                      &j_emlrtBCI, (emlrtCTX)sp);
      }
      tmp_size[0] = 1;
      loop_ub = i5 - i4;
      tmp_size[1] = loop_ub;
      for (i5 = 0; i5 < loop_ub; i5++) {
        b_i = i4 + i5;
        q = F_e[b_i].re;
        im_tmp = F_e[b_i].im;
        if (im_tmp == 0.0) {
          E_temp[i5].re = q / Temp->Space.N;
          E_temp[i5].im = 0.0;
        } else if (q == 0.0) {
          E_temp[i5].re = 0.0;
          E_temp[i5].im = im_tmp / Temp->Space.N;
        } else {
          E_temp[i5].re = q / Temp->Space.N;
          E_temp[i5].im = im_tmp / Temp->Space.N;
        }
      }
      iv[0] = 1;
      iv[1] = Sol->Psie->size[1];
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &d_emlrtECI,
                                    (emlrtCTX)sp);
      for (i4 = 0; i4 < loop_ub; i4++) {
        Sol->Psie->data[((int32_T)ind_s + Sol->Psie->size[0] * i4) - 1] =
            E_temp[i4];
      }
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->t->size[1],
                                      &u_emlrtBCI, (emlrtCTX)sp);
      }
      Sol->t->data[(int32_T)ind_s - 1].re = re_tmp;
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->t->size[1],
                                      &u_emlrtBCI, (emlrtCTX)sp);
      }
      Sol->t->data[(int32_T)ind_s - 1].im = 0.0;
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
  emxFree_cuint8_T(sp, &d);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (Chi23_Runge_Kuarong.c) */
