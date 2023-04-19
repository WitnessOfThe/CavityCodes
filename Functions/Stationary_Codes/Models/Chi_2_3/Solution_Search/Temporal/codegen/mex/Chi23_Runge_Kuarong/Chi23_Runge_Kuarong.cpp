//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi23_Runge_Kuarong.cpp
//
// Code generation for function 'Chi23_Runge_Kuarong'
//

// Include files
#include "Chi23_Runge_Kuarong.h"
#include "Chi23_Runge_Kuarong_data.h"
#include "Chi23_Runge_Kuarong_types.h"
#include "fft.h"
#include "ifft.h"
#include "ref.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>
#include <cstring>

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    3,                     // lineNo
    "Chi23_Runge_Kuarong", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    33,                    // lineNo
    "Chi23_Runge_Kuarong", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    77,                                       // lineNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pathName
};

static emlrtBCInfo emlrtBCI{
    -1,                                       // iFirst
    -1,                                       // iLast
    87,                                       // lineNo
    90,                                       // colNo
    "d",                                      // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtRTEInfo emlrtRTEI{
    83,                                       // lineNo
    18,                                       // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtECInfo emlrtECI{
    -1,                                       // nDims
    77,                                       // lineNo
    13,                                       // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtBCInfo b_emlrtBCI{
    -1,                                       // iFirst
    -1,                                       // iLast
    77,                                       // lineNo
    15,                                       // colNo
    "d",                                      // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    1,                                        // iFirst
    3,                                        // iLast
    77,                                       // lineNo
    66,                                       // colNo
    "exp_plus_omega",                         // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    -1,                                       // iFirst
    -1,                                       // iLast
    71,                                       // lineNo
    105,                                      // colNo
    "d",                                      // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtRTEInfo b_emlrtRTEI{
    67,                                       // lineNo
    22,                                       // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    65,                                       // lineNo
    18,                                       // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtECInfo b_emlrtECI{
    -1,                                       // nDims
    63,                                       // lineNo
    9,                                        // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtBCInfo e_emlrtBCI{
    -1,                                       // iFirst
    -1,                                       // iLast
    63,                                       // lineNo
    11,                                       // colNo
    "d",                                      // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtECInfo c_emlrtECI{
    -1,                    // nDims
    40,                    // lineNo
    13,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtBCInfo f_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    40,                    // lineNo
    22,                    // colNo
    "Sol.Psie",            // aName
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo emlrtDCI{
    40,                    // lineNo
    22,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtECInfo d_emlrtECI{
    -1,                    // nDims
    39,                    // lineNo
    13,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtBCInfo g_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    39,                    // lineNo
    22,                    // colNo
    "Sol.Psio",            // aName
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo b_emlrtDCI{
    39,                    // lineNo
    22,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo h_emlrtBCI{
    1,                     // iFirst
    512,                   // iLast
    40,                    // lineNo
    55,                    // colNo
    "F_e",                 // aName
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo c_emlrtDCI{
    40,                    // lineNo
    55,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    1,                     // iFirst
    512,                   // iLast
    40,                    // lineNo
    40,                    // colNo
    "F_e",                 // aName
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    40,                    // lineNo
    40,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    1,                     // iFirst
    512,                   // iLast
    39,                    // lineNo
    42,                    // colNo
    "F_e",                 // aName
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo e_emlrtDCI{
    39,                    // lineNo
    42,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtRTEInfo d_emlrtRTEI{
    31,                    // lineNo
    14,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtDCInfo f_emlrtDCI{
    3,                     // lineNo
    35,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtDCInfo g_emlrtDCI{
    3,                     // lineNo
    35,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    4                                                         // checkKind
};

static emlrtDCInfo h_emlrtDCI{
    3,                     // lineNo
    43,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtDCInfo i_emlrtDCI{
    3,                     // lineNo
    43,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    4                                                         // checkKind
};

static emlrtDCInfo j_emlrtDCI{
    25,                    // lineNo
    30,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtDCInfo k_emlrtDCI{
    25,                    // lineNo
    30,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    4                                                         // checkKind
};

static emlrtDCInfo l_emlrtDCI{
    25,                    // lineNo
    42,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtDCInfo m_emlrtDCI{
    25,                    // lineNo
    42,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    4                                                         // checkKind
};

static emlrtDCInfo n_emlrtDCI{
    26,                    // lineNo
    30,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtDCInfo o_emlrtDCI{
    26,                    // lineNo
    42,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtDCInfo p_emlrtDCI{
    28,                    // lineNo
    32,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtDCInfo q_emlrtDCI{
    3,                     // lineNo
    5,                     // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtDCInfo r_emlrtDCI{
    25,                    // lineNo
    5,                     // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtDCInfo s_emlrtDCI{
    26,                    // lineNo
    5,                     // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtDCInfo t_emlrtDCI{
    28,                    // lineNo
    5,                     // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    1,                                        // iFirst
    3,                                        // iLast
    85,                                       // lineNo
    25,                                       // colNo
    "Runge.c",                                // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    1,                                        // iFirst
    3,                                        // iLast
    69,                                       // lineNo
    28,                                       // colNo
    "Runge.b",                                // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo m_emlrtBCI{
    1,                                        // iFirst
    3,                                        // iLast
    69,                                       // lineNo
    31,                                       // colNo
    "Runge.b",                                // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtBCInfo n_emlrtBCI{
    1,                                        // iFirst
    512,                                      // iLast
    93,                                       // lineNo
    12,                                       // colNo
    "E_f",                                    // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    3                                                         // checkKind
};

static emlrtDCInfo u_emlrtDCI{
    93,                                       // lineNo
    12,                                       // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo o_emlrtBCI{
    1,                                        // iFirst
    512,                                      // iLast
    87,                                       // lineNo
    50,                                       // colNo
    "E_f",                                    // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo v_emlrtDCI{
    87,                                       // lineNo
    50,                                       // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo p_emlrtBCI{
    -1,                                       // iFirst
    -1,                                       // iLast
    87,                                       // lineNo
    93,                                       // colNo
    "d",                                      // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo w_emlrtDCI{
    87,                                       // lineNo
    93,                                       // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo q_emlrtBCI{
    1,                                        // iFirst
    512,                                      // iLast
    71,                                       // lineNo
    62,                                       // colNo
    "E_temp",                                 // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo x_emlrtDCI{
    71,                                       // lineNo
    62,                                       // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo r_emlrtBCI{
    -1,                                       // iFirst
    -1,                                       // iLast
    71,                                       // lineNo
    108,                                      // colNo
    "d",                                      // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo y_emlrtDCI{
    71,                                       // lineNo
    108,                                      // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo s_emlrtBCI{
    1,                                        // iFirst
    512,                                      // iLast
    87,                                       // lineNo
    17,                                       // colNo
    "E_f",                                    // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    3                                                         // checkKind
};

static emlrtDCInfo ab_emlrtDCI{
    87,                                       // lineNo
    17,                                       // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo t_emlrtBCI{
    1,                                        // iFirst
    512,                                      // iLast
    71,                                       // lineNo
    21,                                       // colNo
    "E_temp",                                 // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    3                                                         // checkKind
};

static emlrtDCInfo bb_emlrtDCI{
    71,                                       // lineNo
    21,                                       // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,                    // iFirst
    -1,                    // iLast
    42,                    // lineNo
    21,                    // colNo
    "Sol.t",               // aName
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo cb_emlrtDCI{
    42,                    // lineNo
    21,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    1,                                        // iFirst
    512,                                      // iLast
    93,                                       // lineNo
    38,                                       // colNo
    "shift_back",                             // aName
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    0                                                         // checkKind
};

static emlrtDCInfo db_emlrtDCI{
    93,                                       // lineNo
    38,                                       // colNo
    "Chi23_Runge_Kuarong/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m", // pName
    1                                                         // checkKind
};

static emlrtRTEInfo e_emlrtRTEI{
    3,                     // lineNo
    5,                     // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtRTEInfo f_emlrtRTEI{
    25,                    // lineNo
    5,                     // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtRTEInfo g_emlrtRTEI{
    26,                    // lineNo
    5,                     // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtRTEInfo h_emlrtRTEI{
    28,                    // lineNo
    5,                     // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

static emlrtRTEInfo i_emlrtRTEI{
    33,                    // lineNo
    61,                    // colNo
    "Chi23_Runge_Kuarong", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "Chi_2_3/Solution_Search/Temporal/Chi23_Runge_Kuarong.m" // pName
};

// Function Definitions
void Chi23_Runge_Kuarong(const emlrtStack *sp, const struct0_T *Temp,
                         const struct7_T *Runge, struct8_T *Sol)
{
  coder::captured_var exp_minus_omega;
  coder::captured_var exp_plus_omega;
  coder::array<creal_T, 2U> c_d;
  coder::array<cuint8_T, 2U> d;
  emlrtStack b_st;
  emlrtStack st;
  creal_T E_temp[512];
  creal_T F_e[512];
  creal_T k_e[512];
  creal_T y[512];
  creal_T Psie[256];
  creal_T Psio[256];
  creal_T b_F_e[256];
  creal_T c_y[256];
  creal_T dcv[256];
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
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i5;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  st.site = &emlrtRSI;
  //  coder.gpu.kernelfun;
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &g_emlrtDCI, (emlrtCTX)sp);
  }
  r = static_cast<int32_T>(muDoubleScalarFloor(Runge->s));
  if (Runge->s != r) {
    emlrtIntegerCheckR2012b(Runge->s, &f_emlrtDCI, (emlrtCTX)sp);
  }
  d.set_size(&e_emlrtRTEI, sp, static_cast<int32_T>(Runge->s), d.size(1));
  b_d = 2.0 * Temp->Space.N;
  if (!(b_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(b_d, &i_emlrtDCI, (emlrtCTX)sp);
  }
  d1 = static_cast<int32_T>(muDoubleScalarFloor(b_d));
  if (b_d != d1) {
    emlrtIntegerCheckR2012b(b_d, &h_emlrtDCI, (emlrtCTX)sp);
  }
  d.set_size(&e_emlrtRTEI, sp, d.size(0), static_cast<int32_T>(b_d));
  if (Runge->s != r) {
    emlrtIntegerCheckR2012b(Runge->s, &q_emlrtDCI, (emlrtCTX)sp);
  }
  if (b_d != d1) {
    emlrtIntegerCheckR2012b(b_d, &q_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(Runge->s) * static_cast<int32_T>(b_d);
  for (i = 0; i < loop_ub; i++) {
    d[i].re = 0U;
    d[i].im = 0U;
  }
  dt_tmp_tmp = Temp->Par.dt;
  nt = Temp->Par.T / Temp->Par.dt;
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
      exp_minus_omega.contents[i].re = re;
      exp_minus_omega.contents[i].im = im;
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
      exp_plus_omega.contents[i].re = re;
      exp_plus_omega.contents[i].im = im;
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
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
    emlrtNonNegativeCheckR2012b(Temp->Par.dd, &k_emlrtDCI, (emlrtCTX)sp);
  }
  r = static_cast<int32_T>(muDoubleScalarFloor(Temp->Par.dd));
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &j_emlrtDCI, (emlrtCTX)sp);
  }
  Sol->Psio.set_size(&f_emlrtRTEI, sp, static_cast<int32_T>(Temp->Par.dd),
                     Sol->Psio.size(1));
  if (!(Temp->Space.N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Space.N, &m_emlrtDCI, (emlrtCTX)sp);
  }
  d2 = static_cast<int32_T>(muDoubleScalarFloor(Temp->Space.N));
  if (Temp->Space.N != d2) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &l_emlrtDCI, (emlrtCTX)sp);
  }
  Sol->Psio.set_size(&f_emlrtRTEI, sp, Sol->Psio.size(0),
                     static_cast<int32_T>(Temp->Space.N));
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &r_emlrtDCI, (emlrtCTX)sp);
  }
  if (Temp->Space.N != d2) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &r_emlrtDCI, (emlrtCTX)sp);
  }
  b_i =
      static_cast<int32_T>(Temp->Par.dd) * static_cast<int32_T>(Temp->Space.N);
  for (i = 0; i < b_i; i++) {
    Sol->Psio[i].re = 0.0;
    Sol->Psio[i].im = 0.0;
  }
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &n_emlrtDCI, (emlrtCTX)sp);
  }
  Sol->Psie.set_size(&g_emlrtRTEI, sp, static_cast<int32_T>(Temp->Par.dd),
                     Sol->Psie.size(1));
  if (Temp->Space.N != d2) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &o_emlrtDCI, (emlrtCTX)sp);
  }
  Sol->Psie.set_size(&g_emlrtRTEI, sp, Sol->Psie.size(0),
                     static_cast<int32_T>(Temp->Space.N));
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &s_emlrtDCI, (emlrtCTX)sp);
  }
  if (Temp->Space.N != d2) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &s_emlrtDCI, (emlrtCTX)sp);
  }
  for (i = 0; i < b_i; i++) {
    Sol->Psie[i].re = 0.0;
    Sol->Psie[i].im = 0.0;
  }
  Sol->t.set_size(&h_emlrtRTEI, sp, 1, Sol->t.size(1));
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &p_emlrtDCI, (emlrtCTX)sp);
  }
  Sol->t.set_size(&h_emlrtRTEI, sp, Sol->t.size(0),
                  static_cast<int32_T>(Temp->Par.dd));
  if (Temp->Par.dd != r) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &t_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(Temp->Par.dd);
  for (i = 0; i < loop_ub; i++) {
    Sol->t[i].re = 0.0;
    Sol->t[i].im = 0.0;
  }
  i = static_cast<int32_T>((nt - 1.0) + 1.0);
  emlrtForLoopVectorCheckR2021a(
      0.0, 1.0, nt - 1.0, mxDOUBLE_CLASS,
      static_cast<int32_T>((Temp->Par.T / Temp->Par.dt - 1.0) + 1.0),
      &d_emlrtRTEI, (emlrtCTX)sp);
  if (0 <= static_cast<int32_T>((nt - 1.0) + 1.0) - 1) {
    b_loop_ub = d.size(0) * d.size(1);
    i1 = static_cast<int32_T>(Runge->s + -1.0);
    i2 = static_cast<int32_T>(Runge->s);
    b_y = Temp->Par.s_t / Temp->Par.dt;
  }
  if (0 <= i - 1) {
    q = 256.0 * exp_plus_omega.contents[0].re;
    im_tmp = 256.0 * exp_plus_omega.contents[0].im;
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
    c_loop_ub = d.size(1);
  }
  for (int32_T ni{0}; ni < i; ni++) {
    int32_T i3;
    int32_T i4;
    st.site = &b_emlrtRSI;
    c_d.set_size(&i_emlrtRTEI, &st, d.size(0), d.size(1));
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      c_d[i3].re = 0.0;
      c_d[i3].im = d[i3].im;
    }
    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    std::copy(&F_e[0], &F_e[512], &E_temp[0]);
    if (1 > d.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, d.size(0), &e_emlrtBCI, &st);
    }
    iv[0] = 1;
    iv[1] = d.size(1);
    iv1[0] = 1;
    iv1[1] = 512;
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &b_emlrtECI, &st);
    for (i3 = 0; i3 < 256; i3++) {
      r = F_e[i3].re;
      b_re_tmp = exp_minus_omega.contents[3 * i3].im;
      ind_s = F_e[i3].im;
      im_tmp = exp_minus_omega.contents[3 * i3].re;
      b_F_e[i3].re = r * im_tmp - ind_s * b_re_tmp;
      b_F_e[i3].im = r * b_re_tmp + ind_s * im_tmp;
    }
    coder::ifft(b_F_e, Psio);
    for (i3 = 0; i3 < 256; i3++) {
      i4 = 3 * (i3 + 256);
      r = F_e[i3 + 256].re;
      b_re_tmp = exp_minus_omega.contents[i4].im;
      ind_s = F_e[i3 + 256].im;
      im_tmp = exp_minus_omega.contents[i4].re;
      b_F_e[i3].re = r * im_tmp - ind_s * b_re_tmp;
      b_F_e[i3].im = r * b_re_tmp + ind_s * im_tmp;
    }
    coder::ifft(b_F_e, Psie);
    std::memset(&k_e[0], 0, 512U * sizeof(creal_T));
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
    coder::fft(b_F_e, dcv);
    for (i3 = 0; i3 < 256; i3++) {
      r = d_y[i3] + 2.0 * b[i3];
      b_F_e[i3].re = r * Psio[i3].re;
      b_F_e[i3].im = r * Psio[i3].im;
    }
    coder::fft(b_F_e, c_y);
    //
    for (loop_ub = 0; loop_ub < 256; loop_ub++) {
      re_tmp = exp_plus_omega.contents[3 * loop_ub].im;
      b_re_tmp = exp_plus_omega.contents[3 * loop_ub].re;
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
    coder::fft(c_y, dcv);
    for (i3 = 0; i3 < 256; i3++) {
      r = 2.0 * b[i3] + d_y[i3];
      Psie[i3].re *= r;
      Psie[i3].im *= r;
    }
    coder::fft(Psie, c_y);
    for (i3 = 0; i3 < 256; i3++) {
      b_i = 3 * (i3 + 256);
      re_tmp = exp_plus_omega.contents[b_i].im;
      b_re_tmp = exp_plus_omega.contents[b_i].re;
      re = 0.0 * b_re_tmp - re_tmp;
      im = 0.0 * re_tmp + b_re_tmp;
      r = Temp->Eq.gam2e[i3];
      b_re_tmp = Temp->Eq.gam3e[i3];
      re_tmp = r * dcv[i3].re + b_re_tmp * c_y[i3].re;
      q = r * dcv[i3].im + b_re_tmp * c_y[i3].im;
      k_e[i3 + 256].re = re * re_tmp - im * q;
      k_e[i3 + 256].im = re * q + im * re_tmp;
    }
    //
    k_e[0].re += Temp->Eq.ko * b_re * Temp->Eq.H_f;
    k_e[0].im += Temp->Eq.ko * b_im * Temp->Eq.H_f;
    for (i3 = 0; i3 < c_loop_ub; i3++) {
      c_d[c_d.size(0) * i3] = k_e[i3];
    }
    emlrtForLoopVectorCheckR2021a(2.0, 1.0, Runge->s, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(Runge->s + -1.0),
                                  &c_emlrtRTEI, &st);
    if (0 <= i1 - 1) {
      iv1[0] = 1;
      iv1[1] = 512;
    }
    if (0 <= i1 - 1) {
      i5 = static_cast<int32_T>(Runge->s - 1.0);
    }
    for (int32_T b_i2{0}; b_i2 < i1; b_i2++) {
      emlrtForLoopVectorCheckR2021a(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
                                    static_cast<int32_T>(Runge->s - 1.0),
                                    &b_emlrtRTEI, &st);
      for (b_i = 0; b_i < i5; b_i++) {
        if ((static_cast<int32_T>(b_i2 + 2U) < 1) ||
            (static_cast<int32_T>(b_i2 + 2U) > 3)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i2 + 2U), 1, 3,
                                        &l_emlrtBCI, &st);
        }
        if ((static_cast<int32_T>(b_i + 1U) < 1) ||
            (static_cast<int32_T>(b_i + 1U) > 3)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1, 3,
                                        &m_emlrtBCI, &st);
        }
        r = Runge->b[(b_i2 + 3 * b_i) + 1];
        if (r != 0.0) {
          q = dt_tmp_tmp * r;
          if ((static_cast<int32_T>(b_i + 1U) < 1) ||
              (static_cast<int32_T>(b_i + 1U) > c_d.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
                                          c_d.size(0), &d_emlrtBCI, &st);
          }
          for (i3 = 0; i3 < 512; i3++) {
            r = Temp->Eq.mode_range[i3];
            i4 = static_cast<int32_T>(muDoubleScalarFloor(r));
            if (r != i4) {
              emlrtIntegerCheckR2012b(r, &x_emlrtDCI, &st);
            }
            loop_ub = static_cast<int32_T>(r);
            if ((loop_ub < 1) || (loop_ub > 512)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 512, &q_emlrtBCI, &st);
            }
            if (loop_ub != i4) {
              emlrtIntegerCheckR2012b(r, &y_emlrtDCI, &st);
            }
            if (loop_ub > c_d.size(1)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_d.size(1),
                                            &r_emlrtBCI, &st);
            }
            k_e[i3].re = E_temp[loop_ub - 1].re +
                         q * c_d[b_i + c_d.size(0) * (loop_ub - 1)].re;
            if (loop_ub != i4) {
              emlrtIntegerCheckR2012b(r, &x_emlrtDCI, &st);
            }
            if (loop_ub > c_d.size(1)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_d.size(1),
                                            &r_emlrtBCI, &st);
            }
            k_e[i3].im = E_temp[loop_ub - 1].im +
                         q * c_d[b_i + c_d.size(0) * (loop_ub - 1)].im;
          }
          for (i3 = 0; i3 < 512; i3++) {
            r = Temp->Eq.mode_range[i3];
            i4 = static_cast<int32_T>(muDoubleScalarFloor(r));
            if (r != i4) {
              emlrtIntegerCheckR2012b(r, &bb_emlrtDCI, &st);
            }
            loop_ub = static_cast<int32_T>(r);
            if ((loop_ub < 1) || (loop_ub > 512)) {
              emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 512, &t_emlrtBCI, &st);
            }
            E_temp[loop_ub - 1].re = k_e[i3].re;
            if (loop_ub != i4) {
              emlrtIntegerCheckR2012b(r, &bb_emlrtDCI, &st);
            }
            E_temp[loop_ub - 1].im = k_e[i3].im;
          }
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      if ((b_i2 + 2 < 1) || (b_i2 + 2 > c_d.size(0))) {
        emlrtDynamicBoundsCheckR2012b(b_i2 + 2, 1, c_d.size(0), &b_emlrtBCI,
                                      &st);
      }
      iv[0] = 1;
      iv[1] = c_d.size(1);
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &iv1[0], 2, &emlrtECI, &st);
      b_st.site = &e_emlrtRSI;
      if ((b_i2 + 2 < 1) || (b_i2 + 2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(b_i2 + 2, 1, 3, &c_emlrtBCI, &b_st);
      }
      for (i3 = 0; i3 < 256; i3++) {
        i4 = (b_i2 + 3 * i3) + 1;
        r = E_temp[i3].re;
        b_re_tmp = exp_minus_omega.contents[i4].im;
        ind_s = E_temp[i3].im;
        im_tmp = exp_minus_omega.contents[i4].re;
        b_F_e[i3].re = r * im_tmp - ind_s * b_re_tmp;
        b_F_e[i3].im = r * b_re_tmp + ind_s * im_tmp;
      }
      coder::ifft(b_F_e, Psio);
      for (i3 = 0; i3 < 256; i3++) {
        i4 = (b_i2 + 3 * (i3 + 256)) + 1;
        r = E_temp[i3 + 256].re;
        b_re_tmp = exp_minus_omega.contents[i4].im;
        ind_s = E_temp[i3 + 256].im;
        im_tmp = exp_minus_omega.contents[i4].re;
        b_F_e[i3].re = r * im_tmp - ind_s * b_re_tmp;
        b_F_e[i3].im = r * b_re_tmp + ind_s * im_tmp;
      }
      coder::ifft(b_F_e, Psie);
      std::memset(&k_e[0], 0, 512U * sizeof(creal_T));
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
      coder::fft(b_F_e, dcv);
      for (i3 = 0; i3 < 256; i3++) {
        r = d_y[i3] + 2.0 * b[i3];
        b_F_e[i3].re = r * Psio[i3].re;
        b_F_e[i3].im = r * Psio[i3].im;
      }
      coder::fft(b_F_e, c_y);
      //
      for (loop_ub = 0; loop_ub < 256; loop_ub++) {
        b_i = (b_i2 + 3 * loop_ub) + 1;
        re_tmp = exp_plus_omega.contents[b_i].im;
        b_re_tmp = exp_plus_omega.contents[b_i].re;
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
      coder::fft(c_y, dcv);
      for (i3 = 0; i3 < 256; i3++) {
        r = 2.0 * b[i3] + d_y[i3];
        Psie[i3].re *= r;
        Psie[i3].im *= r;
      }
      coder::fft(Psie, c_y);
      for (i3 = 0; i3 < 256; i3++) {
        b_i = (b_i2 + 3 * (i3 + 256)) + 1;
        re_tmp = exp_plus_omega.contents[b_i].im;
        b_re_tmp = exp_plus_omega.contents[b_i].re;
        re = 0.0 * b_re_tmp - re_tmp;
        im = 0.0 * re_tmp + b_re_tmp;
        r = Temp->Eq.gam2e[i3];
        b_re_tmp = Temp->Eq.gam3e[i3];
        re_tmp = r * dcv[i3].re + b_re_tmp * c_y[i3].re;
        q = r * dcv[i3].im + b_re_tmp * c_y[i3].im;
        k_e[i3 + 256].re = re * re_tmp - im * q;
        k_e[i3 + 256].im = re * q + im * re_tmp;
      }
      //
      q = 256.0 * exp_plus_omega.contents[b_i2 + 1].re;
      im_tmp = 256.0 * exp_plus_omega.contents[b_i2 + 1].im;
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
      loop_ub = c_d.size(1);
      for (i3 = 0; i3 < loop_ub; i3++) {
        c_d[(b_i2 + c_d.size(0) * i3) + 1] = k_e[i3];
      }
      std::copy(&F_e[0], &F_e[512], &E_temp[0]);
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, Runge->s, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(Runge->s), &emlrtRTEI,
                                  &st);
    for (b_i = 0; b_i < i2; b_i++) {
      if ((static_cast<int32_T>(b_i + 1U) < 1) ||
          (static_cast<int32_T>(b_i + 1U) > 3)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1, 3,
                                      &k_emlrtBCI, &st);
      }
      r = Runge->c[b_i];
      if (r != 0.0) {
        q = dt_tmp_tmp * r;
        if ((static_cast<int32_T>(b_i + 1U) < 1) ||
            (static_cast<int32_T>(b_i + 1U) > c_d.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_i + 1U), 1,
                                        c_d.size(0), &emlrtBCI, &st);
        }
        for (i3 = 0; i3 < 512; i3++) {
          r = Temp->Eq.mode_range[i3];
          i4 = static_cast<int32_T>(muDoubleScalarFloor(r));
          if (r != i4) {
            emlrtIntegerCheckR2012b(r, &v_emlrtDCI, &st);
          }
          loop_ub = static_cast<int32_T>(r);
          if ((loop_ub < 1) || (loop_ub > 512)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 512, &o_emlrtBCI, &st);
          }
          if (loop_ub != i4) {
            emlrtIntegerCheckR2012b(r, &w_emlrtDCI, &st);
          }
          if (loop_ub > c_d.size(1)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_d.size(1), &p_emlrtBCI,
                                          &st);
          }
          k_e[i3].re = F_e[loop_ub - 1].re +
                       q * c_d[b_i + c_d.size(0) * (loop_ub - 1)].re;
          if (loop_ub != i4) {
            emlrtIntegerCheckR2012b(r, &v_emlrtDCI, &st);
          }
          if (loop_ub > c_d.size(1)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, c_d.size(1), &p_emlrtBCI,
                                          &st);
          }
          k_e[i3].im = F_e[loop_ub - 1].im +
                       q * c_d[b_i + c_d.size(0) * (loop_ub - 1)].im;
        }
        for (i3 = 0; i3 < 512; i3++) {
          r = Temp->Eq.mode_range[i3];
          i4 = static_cast<int32_T>(muDoubleScalarFloor(r));
          if (r != i4) {
            emlrtIntegerCheckR2012b(r, &ab_emlrtDCI, &st);
          }
          loop_ub = static_cast<int32_T>(r);
          if ((loop_ub < 1) || (loop_ub > 512)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 512, &s_emlrtBCI, &st);
          }
          F_e[loop_ub - 1].re = k_e[i3].re;
          if (loop_ub != i4) {
            emlrtIntegerCheckR2012b(r, &ab_emlrtDCI, &st);
          }
          F_e[loop_ub - 1].im = k_e[i3].im;
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }
    for (i3 = 0; i3 < 512; i3++) {
      r = Temp->Eq.mode_range[i3];
      i4 = static_cast<int32_T>(muDoubleScalarFloor(r));
      if (r != i4) {
        emlrtIntegerCheckR2012b(r, &db_emlrtDCI, &st);
      }
      loop_ub = static_cast<int32_T>(r);
      if ((loop_ub < 1) || (loop_ub > 512)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 512, &v_emlrtBCI, &st);
      }
      if (loop_ub != i4) {
        emlrtIntegerCheckR2012b(r, &db_emlrtDCI, &st);
      }
      b_re_tmp = y[loop_ub - 1].re;
      ind_s = F_e[loop_ub - 1].im;
      im_tmp = y[loop_ub - 1].im;
      q = F_e[loop_ub - 1].re;
      E_temp[i3].re = b_re_tmp * q - im_tmp * ind_s;
      if (loop_ub != i4) {
        emlrtIntegerCheckR2012b(r, &db_emlrtDCI, &st);
      }
      E_temp[i3].im = b_re_tmp * ind_s + im_tmp * q;
    }
    for (i3 = 0; i3 < 512; i3++) {
      r = Temp->Eq.mode_range[i3];
      i4 = static_cast<int32_T>(muDoubleScalarFloor(r));
      if (r != i4) {
        emlrtIntegerCheckR2012b(r, &u_emlrtDCI, &st);
      }
      loop_ub = static_cast<int32_T>(r);
      if ((loop_ub < 1) || (loop_ub > 512)) {
        emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 512, &n_emlrtBCI, &st);
      }
      F_e[loop_ub - 1].re = E_temp[i3].re;
      if (loop_ub != i4) {
        emlrtIntegerCheckR2012b(r, &u_emlrtDCI, &st);
      }
      F_e[loop_ub - 1].im = E_temp[i3].im;
    }
    // ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back
    r = ni;
    if (b_y == 0.0) {
      if (ni == 0) {
        r = b_y;
      }
    } else if (muDoubleScalarIsNaN(b_y)) {
      r = rtNaN;
    } else if (ni == 0) {
      r = 0.0 / b_y;
    } else if (muDoubleScalarIsInf(b_y)) {
      if (b_y < 0.0) {
        r = b_y;
      }
    } else {
      boolean_T rEQ0;
      r = muDoubleScalarRem(static_cast<real_T>(ni), b_y);
      rEQ0 = (r == 0.0);
      if ((!rEQ0) && (b_y > muDoubleScalarFloor(b_y))) {
        q = muDoubleScalarAbs(static_cast<real_T>(ni) / b_y);
        rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
                 2.2204460492503131E-16 * q);
      }
      if (rEQ0) {
        r = b_y * 0.0;
      } else if (b_y < 0.0) {
        r += b_y;
      }
    }
    if (r == 0.0) {
      // && (ni ~= 0)
      re_tmp = static_cast<real_T>(ni) * dt_tmp_tmp;
      ind_s = muDoubleScalarRound(re_tmp / Temp->Par.s_t);
      if (1.0 > Temp->Space.N) {
        loop_ub = 0;
      } else {
        if (Temp->Space.N != d2) {
          emlrtIntegerCheckR2012b(Temp->Space.N, &e_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(Temp->Space.N) < 1) ||
            (static_cast<int32_T>(Temp->Space.N) > 512)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(Temp->Space.N), 1,
                                        512, &j_emlrtBCI, (emlrtCTX)sp);
        }
        loop_ub = static_cast<int32_T>(Temp->Space.N);
      }
      if (ind_s + 1.0 != static_cast<int32_T>(ind_s + 1.0)) {
        emlrtIntegerCheckR2012b(ind_s + 1.0, &b_emlrtDCI, (emlrtCTX)sp);
      }
      if ((static_cast<int32_T>(ind_s + 1.0) < 1) ||
          (static_cast<int32_T>(ind_s + 1.0) > Sol->Psio.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind_s + 1.0), 1,
                                      Sol->Psio.size(0), &g_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      tmp_size[0] = 1;
      tmp_size[1] = loop_ub;
      for (i3 = 0; i3 < loop_ub; i3++) {
        q = F_e[i3].re;
        im_tmp = F_e[i3].im;
        if (im_tmp == 0.0) {
          E_temp[i3].re = q / Temp->Space.N;
          E_temp[i3].im = 0.0;
        } else if (q == 0.0) {
          E_temp[i3].re = 0.0;
          E_temp[i3].im = im_tmp / Temp->Space.N;
        } else {
          E_temp[i3].re = q / Temp->Space.N;
          E_temp[i3].im = im_tmp / Temp->Space.N;
        }
      }
      iv[0] = 1;
      iv[1] = Sol->Psio.size(1);
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &d_emlrtECI,
                                    (emlrtCTX)sp);
      for (i3 = 0; i3 < loop_ub; i3++) {
        Sol->Psio[(static_cast<int32_T>(ind_s + 1.0) + Sol->Psio.size(0) * i3) -
                  1] = E_temp[i3];
      }
      if (Temp->Space.N + 1.0 > b_d) {
        i3 = 0;
        i4 = 0;
      } else {
        if (Temp->Space.N + 1.0 !=
            static_cast<int32_T>(muDoubleScalarFloor(Temp->Space.N + 1.0))) {
          emlrtIntegerCheckR2012b(Temp->Space.N + 1.0, &d_emlrtDCI,
                                  (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(Temp->Space.N + 1.0) < 1) ||
            (static_cast<int32_T>(Temp->Space.N + 1.0) > 512)) {
          emlrtDynamicBoundsCheckR2012b(
              static_cast<int32_T>(Temp->Space.N + 1.0), 1, 512, &i_emlrtBCI,
              (emlrtCTX)sp);
        }
        i3 = static_cast<int32_T>(Temp->Space.N + 1.0) - 1;
        if (b_d != d1) {
          emlrtIntegerCheckR2012b(b_d, &c_emlrtDCI, (emlrtCTX)sp);
        }
        if ((static_cast<int32_T>(b_d) < 1) ||
            (static_cast<int32_T>(b_d) > 512)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_d), 1, 512,
                                        &h_emlrtBCI, (emlrtCTX)sp);
        }
        i4 = static_cast<int32_T>(b_d);
      }
      if (ind_s + 1.0 != static_cast<int32_T>(ind_s + 1.0)) {
        emlrtIntegerCheckR2012b(ind_s + 1.0, &emlrtDCI, (emlrtCTX)sp);
      }
      if ((static_cast<int32_T>(ind_s + 1.0) < 1) ||
          (static_cast<int32_T>(ind_s + 1.0) > Sol->Psie.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind_s + 1.0), 1,
                                      Sol->Psie.size(0), &f_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      tmp_size[0] = 1;
      loop_ub = i4 - i3;
      tmp_size[1] = loop_ub;
      for (i4 = 0; i4 < loop_ub; i4++) {
        b_i = i3 + i4;
        q = F_e[b_i].re;
        im_tmp = F_e[b_i].im;
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
      iv[1] = Sol->Psie.size(1);
      emlrtSubAssignSizeCheckR2012b(&iv[0], 2, &tmp_size[0], 2, &c_emlrtECI,
                                    (emlrtCTX)sp);
      for (i3 = 0; i3 < loop_ub; i3++) {
        Sol->Psie[(static_cast<int32_T>(ind_s + 1.0) + Sol->Psie.size(0) * i3) -
                  1] = E_temp[i3];
      }
      if (ind_s + 1.0 != static_cast<int32_T>(ind_s + 1.0)) {
        emlrtIntegerCheckR2012b(ind_s + 1.0, &cb_emlrtDCI, (emlrtCTX)sp);
      }
      if ((static_cast<int32_T>(ind_s + 1.0) < 1) ||
          (static_cast<int32_T>(ind_s + 1.0) > Sol->t.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind_s + 1.0), 1,
                                      Sol->t.size(1), &u_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      Sol->t[static_cast<int32_T>(ind_s + 1.0) - 1].re = re_tmp;
      if (ind_s + 1.0 != static_cast<int32_T>(ind_s + 1.0)) {
        emlrtIntegerCheckR2012b(ind_s + 1.0, &cb_emlrtDCI, (emlrtCTX)sp);
      }
      if ((static_cast<int32_T>(ind_s + 1.0) < 1) ||
          (static_cast<int32_T>(ind_s + 1.0) > Sol->t.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind_s + 1.0), 1,
                                      Sol->t.size(1), &u_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      Sol->t[static_cast<int32_T>(ind_s + 1.0) - 1].im = 0.0;
      //             if 10*log10(sum(abs(Sol.Psio(ind_s,2:end)).^2)) <= -100 &&
      //             (mod(ind_s,2) == 0)
      //                    Sol.Psio(ind_s+1:end,:) = [];
      //                   Sol.Psie(ind_s+1:end,:) = [];
      //                  Sol.t(ind_s+1:end)     = [];
      //                 break;
      //        end
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (Chi23_Runge_Kuarong.cpp)
