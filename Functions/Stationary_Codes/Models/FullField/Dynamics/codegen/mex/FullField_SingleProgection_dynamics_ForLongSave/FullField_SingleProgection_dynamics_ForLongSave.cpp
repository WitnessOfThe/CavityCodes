//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// FullField_SingleProgection_dynamics_ForLongSave.cpp
//
// Code generation for function
// 'FullField_SingleProgection_dynamics_ForLongSave'
//

// Include files
#include "FullField_SingleProgection_dynamics_ForLongSave.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_data.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_types.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_types1.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_types2.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_types3.h"
#include "abs.h"
#include "eml_int_forloop_overflow_check.h"
#include "exp.h"
#include "fft.h"
#include "find.h"
#include "mod.h"
#include "ref.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <algorithm>

// Variable Definitions
static emlrtRSInfo emlrtRSI{
    3,                                                 // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo b_emlrtRSI{
    16,                                                // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo c_emlrtRSI{
    18,                                                // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo d_emlrtRSI{
    20,                                                // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo e_emlrtRSI{
    33,                                                // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo f_emlrtRSI{
    36,                                                // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo g_emlrtRSI{
    59,                                                // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo h_emlrtRSI{
    60,                                                // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo i_emlrtRSI{
    94,                                                // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo j_emlrtRSI{
    96,                                                // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo k_emlrtRSI{
    7,                                                                // lineNo
    "ref/ref",                                                        // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/ref.m" // pathName
};

static emlrtRSInfo o_emlrtRSI{
    71,                                                           // lineNo
    "power",                                                      // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/ops/power.m" // pathName
};

static emlrtRSInfo r_emlrtRSI{
    15,                                                             // lineNo
    "max",                                                          // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/datafun/max.m" // pathName
};

static emlrtRSInfo s_emlrtRSI{
    44,         // lineNo
    "minOrMax", // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/minOrMax.m" // pathName
};

static emlrtRSInfo t_emlrtRSI{
    79,        // lineNo
    "maximum", // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/minOrMax.m" // pathName
};

static emlrtRSInfo
    u_emlrtRSI{
        186,             // lineNo
        "unaryMinOrMax", // fcnName
        "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" // pathName
    };

static emlrtRSInfo
    v_emlrtRSI{
        897,                    // lineNo
        "maxRealVectorOmitNaN", // fcnName
        "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" // pathName
    };

static emlrtRSInfo w_emlrtRSI{
    62,                      // lineNo
    "vectorMinOrMaxInPlace", // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" // pathName
};

static emlrtRSInfo x_emlrtRSI{
    54,                      // lineNo
    "vectorMinOrMaxInPlace", // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" // pathName
};

static emlrtRSInfo y_emlrtRSI{
    103,         // lineNo
    "findFirst", // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" // pathName
};

static emlrtRSInfo ab_emlrtRSI{
    120,                        // lineNo
    "minOrMaxRealVectorKernel", // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
    "vectorMinOrMaxInPlace.m" // pathName
};

static emlrtRSInfo bb_emlrtRSI{
    39,                                                            // lineNo
    "find",                                                        // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/elmat/find.m" // pathName
};

static emlrtRSInfo eb_emlrtRSI{
    137, // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo fb_emlrtRSI{
    151, // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo gb_emlrtRSI{
    176, // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo hb_emlrtRSI{
    181, // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo ib_emlrtRSI{
    189, // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo jb_emlrtRSI{
    211,                                                         // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave/Get_Field", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo kb_emlrtRSI{
    213,                                                         // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave/Get_Field", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

static emlrtRSInfo lb_emlrtRSI{
    37,                                                            // lineNo
    "flip",                                                        // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/elmat/flip.m" // pathName
};

static emlrtRSInfo mb_emlrtRSI{
    80,                                                              // lineNo
    "ifft",                                                          // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/datafun/ifft.m" // pathName
};

static emlrtRTEInfo
    emlrtRTEI{
        130,             // lineNo
        27,              // colNo
        "unaryMinOrMax", // fName
        "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
        "unaryMinOrMax.m" // pName
    };

static emlrtBCInfo emlrtBCI{
    -1,                                                // iFirst
    -1,                                                // iLast
    111,                                               // lineNo
    21,                                                // colNo
    "Sol.Psi",                                         // aName
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo emlrtDCI{
    111,                                               // lineNo
    21,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtECInfo emlrtECI{
    -1,                                                // nDims
    96,                                                // lineNo
    9,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtBCInfo b_emlrtBCI{
    -1,                                                // iFirst
    -1,                                                // iLast
    96,                                                // lineNo
    25,                                                // colNo
    "Sol.PsiResolved",                                 // aName
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtECInfo b_emlrtECI{
    2,                                                 // nDims
    96,                                                // lineNo
    39,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo c_emlrtRTEI{
    89,                                                // lineNo
    14,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtECInfo c_emlrtECI{
    -1,                                                // nDims
    60,                                                // lineNo
    9,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtECInfo d_emlrtECI{
    -1,                                                // nDims
    59,                                                // lineNo
    9,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtDCInfo b_emlrtDCI{
    43,                                                // lineNo
    26,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtECInfo e_emlrtECI{
    2,                                                 // nDims
    18,                                                // lineNo
    13,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtECInfo f_emlrtECI{
    2,                                                 // nDims
    16,                                                // lineNo
    13,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo d_emlrtRTEI{
    14,                                                // lineNo
    13,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtDCInfo c_emlrtDCI{
    3,                                                 // lineNo
    35,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo d_emlrtDCI{
    3,                                                 // lineNo
    35,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    4              // checkKind
};

static emlrtDCInfo e_emlrtDCI{
    3,                                                 // lineNo
    43,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo f_emlrtDCI{
    3,                                                 // lineNo
    43,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    4              // checkKind
};

static emlrtDCInfo g_emlrtDCI{
    13,                                                // lineNo
    19,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo h_emlrtDCI{
    24,                                                // lineNo
    59,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo i_emlrtDCI{
    30,                                                // lineNo
    59,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo j_emlrtDCI{
    47,                                                // lineNo
    29,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo k_emlrtDCI{
    47,                                                // lineNo
    29,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    4              // checkKind
};

static emlrtDCInfo l_emlrtDCI{
    50,                                                // lineNo
    43,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo m_emlrtDCI{
    51,                                                // lineNo
    41,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo n_emlrtDCI{
    51,                                                // lineNo
    41,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    4              // checkKind
};

static emlrtDCInfo o_emlrtDCI{
    3,                                                 // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo p_emlrtDCI{
    13,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo q_emlrtDCI{
    24,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo c_emlrtBCI{
    -1,                                                // iFirst
    -1,                                                // iLast
    25,                                                // lineNo
    5,                                                 // colNo
    "Eq.L",                                            // aName
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo r_emlrtDCI{
    25,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo s_emlrtDCI{
    30,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo t_emlrtDCI{
    47,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo u_emlrtDCI{
    50,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo v_emlrtDCI{
    51,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo d_emlrtBCI{
    1,                                                 // iFirst
    2048,                                              // iLast
    96,                                                // lineNo
    43,                                                // colNo
    "F_e",                                             // aName
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo w_emlrtDCI{
    96,                                                // lineNo
    43,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo e_emlrtBCI{
    1,                                                 // iFirst
    2048,                                              // iLast
    111,                                               // lineNo
    37,                                                // colNo
    "F_e",                                             // aName
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo x_emlrtDCI{
    111,                                               // lineNo
    37,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo f_emlrtBCI{
    -1,                                                // iFirst
    -1,                                                // iLast
    114,                                               // lineNo
    21,                                                // colNo
    "Sol.t",                                           // aName
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtECInfo g_emlrtECI{
    2,   // nDims
    181, // lineNo
    29,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtECInfo h_emlrtECI{
    -1,  // nDims
    181, // lineNo
    9,   // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtECInfo i_emlrtECI{
    -1,  // nDims
    189, // lineNo
    9,   // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtDCInfo y_emlrtDCI{
    198, // lineNo
    76,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo g_emlrtBCI{
    1,          // iFirst
    1309,       // iLast
    198,        // lineNo
    76,         // colNo
    "Eq.kappa", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtECInfo j_emlrtECI{
    2,   // nDims
    198, // lineNo
    28,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtECInfo k_emlrtECI{
    -1,  // nDims
    198, // lineNo
    9,   // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtBCInfo h_emlrtBCI{
    1,                                                           // iFirst
    2048,                                                        // iLast
    211,                                                         // lineNo
    44,                                                          // colNo
    "F_e",                                                       // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Get_Field", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo i_emlrtBCI{
    -1,                                                          // iFirst
    -1,                                                          // iLast
    211,                                                         // lineNo
    16,                                                          // colNo
    "F_e_shifted",                                               // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Get_Field", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo j_emlrtBCI{
    -1,                                                          // iFirst
    -1,                                                          // iLast
    211,                                                         // lineNo
    18,                                                          // colNo
    "F_e_shifted",                                               // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Get_Field", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtECInfo l_emlrtECI{
    -1,                                                          // nDims
    211,                                                         // lineNo
    4,                                                           // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Get_Field", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtDCInfo ab_emlrtDCI{
    172, // lineNo
    47,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo bb_emlrtDCI{
    172, // lineNo
    47,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    4              // checkKind
};

static emlrtDCInfo cb_emlrtDCI{
    209,                                                         // lineNo
    44,                                                          // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Get_Field", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo db_emlrtDCI{
    209,                                                         // lineNo
    44,                                                          // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Get_Field", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    4              // checkKind
};

static emlrtDCInfo eb_emlrtDCI{
    172, // lineNo
    9,   // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo fb_emlrtDCI{
    172, // lineNo
    9,   // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    4              // checkKind
};

static emlrtDCInfo gb_emlrtDCI{
    209,                                                         // lineNo
    4,                                                           // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Get_Field", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo k_emlrtBCI{
    -1,    // iFirst
    -1,    // iLast
    192,   // lineNo
    36,    // colNo
    "k_e", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo l_emlrtBCI{
    -1,    // iFirst
    -1,    // iLast
    192,   // lineNo
    9,     // colNo
    "k_e", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo m_emlrtBCI{
    -1,    // iFirst
    -1,    // iLast
    198,   // lineNo
    32,    // colNo
    "k_e", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo hb_emlrtDCI{
    198, // lineNo
    32,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo n_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    198,        // lineNo
    52,         // colNo
    "Fac_plus", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo ib_emlrtDCI{
    198, // lineNo
    52,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtDCInfo jb_emlrtDCI{
    198, // lineNo
    13,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo o_emlrtBCI{
    -1,    // iFirst
    -1,    // iLast
    198,   // lineNo
    13,    // colNo
    "k_e", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo p_emlrtBCI{
    1,       // iFirst
    2048,    // iLast
    173,     // lineNo
    9,       // colNo
    "B_Psi", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo q_emlrtBCI{
    -1,    // iFirst
    -1,    // iLast
    173,   // lineNo
    9,     // colNo
    "k_e", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo kb_emlrtDCI{
    173, // lineNo
    9,   // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo r_emlrtBCI{
    -1,          // iFirst
    -1,          // iLast
    174,         // lineNo
    31,          // colNo
    "Fac_minus", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo s_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    193,      // lineNo
    14,       // colNo
    "k_zero", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo t_emlrtBCI{
    -1,       // iFirst
    -1,       // iLast
    193,      // lineNo
    53,       // colNo
    "k_zero", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo u_emlrtBCI{
    -1,         // iFirst
    -1,         // iLast
    192,        // lineNo
    51,         // colNo
    "Fac_plus", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo v_emlrtBCI{
    -1,  // iFirst
    -1,  // iLast
    137, // lineNo
    11,  // colNo
    "d", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtECInfo m_emlrtECI{
    -1,  // nDims
    137, // lineNo
    9,   // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo h_emlrtRTEI{
    139, // lineNo
    18,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo i_emlrtRTEI{
    141, // lineNo
    22,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtBCInfo w_emlrtBCI{
    -1,  // iFirst
    -1,  // iLast
    145, // lineNo
    105, // colNo
    "d", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo x_emlrtBCI{
    1,                // iFirst
    3,                // iLast
    151,              // lineNo
    66,               // colNo
    "exp_plus_omega", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo y_emlrtBCI{
    -1,  // iFirst
    -1,  // iLast
    151, // lineNo
    15,  // colNo
    "d", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtECInfo n_emlrtECI{
    -1,  // nDims
    151, // lineNo
    13,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo j_emlrtRTEI{
    157, // lineNo
    18,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtBCInfo ab_emlrtBCI{
    -1,  // iFirst
    -1,  // iLast
    161, // lineNo
    90,  // colNo
    "d", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo bb_emlrtBCI{
    1,         // iFirst
    3,         // iLast
    159,       // lineNo
    25,        // colNo
    "Runge.c", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo cb_emlrtBCI{
    1,         // iFirst
    3,         // iLast
    143,       // lineNo
    28,        // colNo
    "Runge.b", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo db_emlrtBCI{
    1,         // iFirst
    3,         // iLast
    143,       // lineNo
    31,        // colNo
    "Runge.b", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtBCInfo eb_emlrtBCI{
    1,     // iFirst
    2048,  // iLast
    167,   // lineNo
    12,    // colNo
    "E_f", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    3              // checkKind
};

static emlrtDCInfo lb_emlrtDCI{
    167, // lineNo
    12,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo fb_emlrtBCI{
    1,     // iFirst
    2048,  // iLast
    161,   // lineNo
    50,    // colNo
    "E_f", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo mb_emlrtDCI{
    161, // lineNo
    50,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo gb_emlrtBCI{
    -1,  // iFirst
    -1,  // iLast
    161, // lineNo
    93,  // colNo
    "d", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo nb_emlrtDCI{
    161, // lineNo
    93,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo hb_emlrtBCI{
    1,        // iFirst
    2048,     // iLast
    145,      // lineNo
    62,       // colNo
    "E_temp", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo ob_emlrtDCI{
    145, // lineNo
    62,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo ib_emlrtBCI{
    -1,  // iFirst
    -1,  // iLast
    145, // lineNo
    108, // colNo
    "d", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo pb_emlrtDCI{
    145, // lineNo
    108, // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo jb_emlrtBCI{
    1,     // iFirst
    2048,  // iLast
    161,   // lineNo
    17,    // colNo
    "E_f", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    3              // checkKind
};

static emlrtDCInfo qb_emlrtDCI{
    161, // lineNo
    17,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo kb_emlrtBCI{
    1,        // iFirst
    2048,     // iLast
    145,      // lineNo
    21,       // colNo
    "E_temp", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    3              // checkKind
};

static emlrtDCInfo rb_emlrtDCI{
    145, // lineNo
    21,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo lb_emlrtBCI{
    1,     // iFirst
    2048,  // iLast
    167,   // lineNo
    38,    // colNo
    "E_f", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtDCInfo sb_emlrtDCI{
    167, // lineNo
    38,  // colNo
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    1              // checkKind
};

static emlrtBCInfo mb_emlrtBCI{
    -1,           // iFirst
    -1,           // iLast
    167,          // lineNo
    38,           // colNo
    "shift_back", // aName
    "FullField_SingleProgection_dynamics_ForLongSave/Runge_Kuarong_step", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m", // pName
    0              // checkKind
};

static emlrtRTEInfo k_emlrtRTEI{
    3,                                                 // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo l_emlrtRTEI{
    28,                                                           // lineNo
    9,                                                            // colNo
    "colon",                                                      // fName
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/ops/colon.m" // pName
};

static emlrtRTEInfo m_emlrtRTEI{
    10,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo n_emlrtRTEI{
    13,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo o_emlrtRTEI{
    16,                                                // lineNo
    57,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo p_emlrtRTEI{
    16,                                                // lineNo
    53,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo q_emlrtRTEI{
    16,                                                // lineNo
    47,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo r_emlrtRTEI{
    16,                                                // lineNo
    17,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo s_emlrtRTEI{
    16,                                                // lineNo
    9,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo t_emlrtRTEI{
    18,                                                // lineNo
    57,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo u_emlrtRTEI{
    18,                                                // lineNo
    53,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo v_emlrtRTEI{
    18,                                                // lineNo
    47,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo w_emlrtRTEI{
    18,                                                // lineNo
    17,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo x_emlrtRTEI{
    18,                                                // lineNo
    9,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo y_emlrtRTEI{
    20,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo ab_emlrtRTEI{
    24,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo bb_emlrtRTEI{
    27,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo cb_emlrtRTEI{
    28,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo db_emlrtRTEI{
    30,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo eb_emlrtRTEI{
    32,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo fb_emlrtRTEI{
    33,                                                // lineNo
    21,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo gb_emlrtRTEI{
    33,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo hb_emlrtRTEI{
    36,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo ib_emlrtRTEI{
    43,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo jb_emlrtRTEI{
    47,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo kb_emlrtRTEI{
    50,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo lb_emlrtRTEI{
    51,                                                // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo mb_emlrtRTEI{
    59,                                                // lineNo
    35,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo nb_emlrtRTEI{
    60,                                                // lineNo
    35,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo ob_emlrtRTEI{
    94,                                                // lineNo
    65,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo pb_emlrtRTEI{
    96,                                                // lineNo
    39,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo qb_emlrtRTEI{
    96,                                                // lineNo
    74,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo rb_emlrtRTEI{
    128,                                               // lineNo
    5,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo tb_emlrtRTEI{
    71,                                                           // lineNo
    5,                                                            // colNo
    "power",                                                      // fName
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/ops/power.m" // pName
};

static emlrtRTEInfo wb_emlrtRTEI{
    172,                                               // lineNo
    9,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo xb_emlrtRTEI{
    209,                                               // lineNo
    4,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo
    yb_emlrtRTEI{
        76,                  // lineNo
        9,                   // colNo
        "eml_mtimes_helper", // fName
        "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/ops/"
        "eml_mtimes_helper.m" // pName
    };

static emlrtRTEInfo bc_emlrtRTEI{
    176,                                               // lineNo
    9,                                                 // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo cc_emlrtRTEI{
    181,                                               // lineNo
    38,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo dc_emlrtRTEI{
    181,                                               // lineNo
    29,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo ec_emlrtRTEI{
    181,                                               // lineNo
    25,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo
    fc_emlrtRTEI{
        31,            // lineNo
        30,            // colNo
        "unsafeSxfun", // fName
        "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
        "unsafeSxfun.m" // pName
    };

static emlrtRTEInfo gc_emlrtRTEI{
    189,                                               // lineNo
    25,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo hc_emlrtRTEI{
    198,                                               // lineNo
    28,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo ic_emlrtRTEI{
    198,                                               // lineNo
    43,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo jc_emlrtRTEI{
    198,                                               // lineNo
    13,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo lc_emlrtRTEI{
    137,                                               // lineNo
    46,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo mc_emlrtRTEI{
    137,                                               // lineNo
    66,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo nc_emlrtRTEI{
    137,                                               // lineNo
    119,                                               // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo oc_emlrtRTEI{
    151,                                               // lineNo
    51,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo pc_emlrtRTEI{
    151,                                               // lineNo
    72,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo qc_emlrtRTEI{
    151,                                               // lineNo
    127,                                               // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo rc_emlrtRTEI{
    18,                                                // lineNo
    13,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRTEInfo sc_emlrtRTEI{
    16,                                                // lineNo
    13,                                                // colNo
    "FullField_SingleProgection_dynamics_ForLongSave", // fName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pName
};

static emlrtRSInfo ub_emlrtRSI{
    198, // lineNo
    "FullField_SingleProgection_dynamics_ForLongSave/Chi_3_LLE_Kuar_ins", // fcnName
    "/home/dp710/NewGitFolder/CavityCodes/Functions/Stationary_Codes/Models/"
    "FullField/Dynamics/FullField_SingleProgection_dynamics_Fo"
    "rLongSave.m" // pathName
};

// Function Declarations
static void Chi_3_LLE_Kuar_ins(
    const emlrtStack *sp, const coder::c_captured_var *N,
    const coder::captured_var *Temp, coder::e_captured_var *Field,
    const coder::d_captured_var *G_theta, const coder::d_captured_var *ind_pump,
    creal_T B_Psi[2048], const coder::array<creal_T, 2U> &Fac_plus,
    const coder::array<creal_T, 2U> &Fac_minus,
    const creal_T pump_phase_substep, const real_T Eq_mode_range[1309],
    real_T Eq_Pump_ind_pump, real_T Eq_Pump_H, const real_T Eq_kappa[1309],
    const real_T Eq_gamma2[1309], const real_T Eq_gamma3[1309],
    coder::array<creal_T, 2U> &k_zero, const creal_T pump_phase,
    coder::array<creal_T, 2U> &k_e);

static void Runge_Kuarong_step(
    const emlrtStack *sp, const coder::c_captured_var *N,
    const coder::captured_var *Temp, coder::e_captured_var *Field,
    const coder::d_captured_var *G_theta, const coder::d_captured_var *ind_pump,
    const coder::e_captured_var *exp_plus_omega,
    const coder::e_captured_var *exp_minus_omega,
    const coder::f_captured_var *pump_phase_substep,
    const coder::b_captured_var *Runge, const coder::e_captured_var *shift_back,
    creal_T B_E[2048], real_T dt, const creal_T pump_phase,
    coder::array<creal_T, 2U> &d, const coder::array<creal_T, 2U> &k_zero);

static void binary_expand_op(const emlrtStack *sp, coder::array<creal_T, 2U> &y,
                             emlrtRSInfo vb_emlrtRSI,
                             const coder::d_captured_var *G_theta,
                             const coder::array<creal_T, 2U> &r);

static void minus(const emlrtStack *sp, coder::array<real_T, 2U> &G,
                  const coder::array<real_T, 2U> &r);

static void plus(const emlrtStack *sp, coder::array<creal_T, 2U> &r1,
                 const coder::array<creal_T, 2U> &y);

static void plus(const emlrtStack *sp, coder::array<real_T, 2U> &G,
                 const coder::array<real_T, 2U> &r);

static void times(const emlrtStack *sp, coder::array<creal_T, 2U> &r1,
                  const coder::array<creal_T, 2U> &r2);

// Function Definitions
static void Chi_3_LLE_Kuar_ins(
    const emlrtStack *sp, const coder::c_captured_var *N,
    const coder::captured_var *Temp, coder::e_captured_var *Field,
    const coder::d_captured_var *G_theta, const coder::d_captured_var *ind_pump,
    creal_T B_Psi[2048], const coder::array<creal_T, 2U> &Fac_plus,
    const coder::array<creal_T, 2U> &Fac_minus,
    const creal_T pump_phase_substep, const real_T Eq_mode_range[1309],
    real_T Eq_Pump_ind_pump, real_T Eq_Pump_H, const real_T Eq_kappa[1309],
    const real_T Eq_gamma2[1309], const real_T Eq_gamma3[1309],
    coder::array<creal_T, 2U> &k_zero, const creal_T pump_phase,
    coder::array<creal_T, 2U> &k_e)
{
  coder::array<creal_T, 2U> b_G_theta;
  coder::array<creal_T, 2U> r;
  coder::array<creal_T, 2U> y;
  coder::array<int32_T, 2U> r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  creal_T tmp_data[2048];
  creal_T b_Fac_minus[1309];
  creal_T varargin_1;
  creal_T varargout_1;
  real_T b_N;
  real_T b_im;
  real_T d;
  real_T im;
  real_T re;
  real_T tmp_im;
  real_T tmp_re;
  int32_T iv[2];
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
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  k_e.set_size(&wb_emlrtRTEI, sp, 1, k_e.size(1));
  if (!(N->contents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N->contents, &bb_emlrtDCI, (emlrtCTX)sp);
  }
  d = N->contents;
  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
    emlrtIntegerCheckR2012b(d, &ab_emlrtDCI, (emlrtCTX)sp);
  }
  k_e.set_size(&wb_emlrtRTEI, sp, k_e.size(0), static_cast<int32_T>(d));
  if (!(N->contents >= 0.0)) {
    emlrtNonNegativeCheckR2012b(N->contents, &fb_emlrtDCI, (emlrtCTX)sp);
  }
  d = N->contents;
  if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
    emlrtIntegerCheckR2012b(d, &eb_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(d);
  for (i = 0; i < loop_ub; i++) {
    k_e[i].re = 0.0;
    k_e[i].im = 0.0;
  }
  nd2 = k_e.size(1);
  for (i = 0; i < 1309; i++) {
    d = Eq_mode_range[i];
    if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) > 2048)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, 2048,
                                    &p_emlrtBCI, (emlrtCTX)sp);
    }
    k = static_cast<int32_T>(muDoubleScalarFloor(d));
    if (d != k) {
      emlrtIntegerCheckR2012b(d, &kb_emlrtDCI, (emlrtCTX)sp);
    }
    if (static_cast<int32_T>(d) > nd2) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, nd2,
                                    &q_emlrtBCI, (emlrtCTX)sp);
    }
    k_e[static_cast<int32_T>(d) - 1].re = -0.5 * Temp->contents.Eq.kappa[i] *
                                          B_Psi[static_cast<int32_T>(d) - 1].re;
    if (static_cast<int32_T>(d) != k) {
      emlrtIntegerCheckR2012b(d, &kb_emlrtDCI, (emlrtCTX)sp);
    }
    if (static_cast<int32_T>(d) > nd2) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, nd2,
                                    &q_emlrtBCI, (emlrtCTX)sp);
    }
    k_e[static_cast<int32_T>(d) - 1].im = -0.5 * Temp->contents.Eq.kappa[i] *
                                          B_Psi[static_cast<int32_T>(d) - 1].im;
  }
  for (i = 0; i < 1309; i++) {
    d = Eq_mode_range[i];
    if ((static_cast<int32_T>(d) < 1) ||
        (static_cast<int32_T>(d) > Fac_minus.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                    Fac_minus.size(1), &r_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    im = Fac_minus[static_cast<int32_T>(d) - 1].re;
    tmp_re = B_Psi[static_cast<int32_T>(d) - 1].im;
    tmp_im = Fac_minus[static_cast<int32_T>(d) - 1].im;
    b_N = B_Psi[static_cast<int32_T>(d) - 1].re;
    b_Fac_minus[i].re = im * b_N - tmp_im * tmp_re;
    if (static_cast<int32_T>(d) > Fac_minus.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                    Fac_minus.size(1), &r_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_Fac_minus[i].im = im * tmp_re + tmp_im * b_N;
  }
  for (i = 0; i < 1309; i++) {
    B_Psi[static_cast<int32_T>(Eq_mode_range[i]) - 1] = b_Fac_minus[i];
  }
  st.site = &gb_emlrtRSI;
  b_N = N->contents / 2.0;
  Field->contents.set_size(&xb_emlrtRTEI, &st, 1, Field->contents.size(1));
  if (!(b_N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(b_N, &db_emlrtDCI, &st);
  }
  d = static_cast<int32_T>(muDoubleScalarFloor(b_N));
  if (b_N != d) {
    emlrtIntegerCheckR2012b(b_N, &cb_emlrtDCI, &st);
  }
  Field->contents.set_size(&xb_emlrtRTEI, &st, Field->contents.size(0),
                           static_cast<int32_T>(b_N));
  if (b_N != d) {
    emlrtIntegerCheckR2012b(b_N, &gb_emlrtDCI, &st);
  }
  loop_ub = static_cast<int32_T>(b_N);
  for (i = 0; i < loop_ub; i++) {
    Field->contents[i].re = 0.0;
    Field->contents[i].im = 0.0;
  }
  //    F_e_shifted(2:N)    =   conj(F_e(N:-1:2));
  if (2.0 > b_N) {
    i = 0;
    k = 0;
    i1 = 0;
    i2 = 0;
  } else {
    i = 1;
    if ((static_cast<int32_T>(b_N) < 1) || (static_cast<int32_T>(b_N) > 2048)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_N), 1, 2048,
                                    &h_emlrtBCI, &st);
    }
    k = static_cast<int32_T>(b_N);
    i1 = Field->contents.size(1);
    if (2 > i1) {
      emlrtDynamicBoundsCheckR2012b(2, 1, i1, &i_emlrtBCI, &st);
    }
    i1 = 1;
    i2 = Field->contents.size(1);
    if ((static_cast<int32_T>(b_N) < 1) || (static_cast<int32_T>(b_N) > i2)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(b_N), 1, i2,
                                    &j_emlrtBCI, &st);
    }
    i2 = static_cast<int32_T>(b_N);
  }
  b_st.site = &jb_emlrtRSI;
  loop_ub = k - i;
  for (k = 0; k < loop_ub; k++) {
    nd2 = i + k;
    tmp_data[k].re = B_Psi[nd2].re;
    tmp_data[k].im = -B_Psi[nd2].im;
  }
  if ((loop_ub != 0) && (loop_ub > 1)) {
    nd2 = loop_ub >> 1;
    c_st.site = &lb_emlrtRSI;
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
    emlrtSubAssignSizeCheck1dR2017a(i, loop_ub, &l_emlrtECI, &st);
  }
  for (i = 0; i < loop_ub; i++) {
    Field->contents[i1 + i] = tmp_data[i];
  }
  y.set_size(&yb_emlrtRTEI, &st, 1, Field->contents.size(1) + 2048);
  for (i = 0; i < 2048; i++) {
    y[i].re = b_N * (2.0 * B_Psi[i].re);
    y[i].im = b_N * (2.0 * B_Psi[i].im);
  }
  loop_ub = Field->contents.size(1);
  for (i = 0; i < loop_ub; i++) {
    y[i + 2048].re = b_N * (2.0 * Field->contents[i].re);
    y[i + 2048].im = b_N * (2.0 * Field->contents[i].im);
  }
  b_st.site = &kb_emlrtRSI;
  c_st.site = &mb_emlrtRSI;
  d_st.site = &nb_emlrtRSI;
  e_st.site = &ob_emlrtRSI;
  f_st.site = &pb_emlrtRSI;
  g_st.site = &qb_emlrtRSI;
  emlrtFFTWSetNumThreads(36);
  r.set_size(&ac_emlrtRTEI, &g_st, 1, y.size(1));
  emlrtFFTW_1D_C2C((real_T *)&y[0], (real_T *)&r[0], 1, y.size(1), y.size(1), 1,
                   1);
  Field->contents.set_size(&bc_emlrtRTEI, sp, 1, r.size(1));
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    Field->contents[i] = r[i];
  }
  //     GField        = ifft(B_Psi)*N/2;
  //     B_Psi
  //     E_1  = B_Psi(185).*exp(1i*Temp.Space.phi*m(185));
  //     E_2  = B_Psi(185).*exp(1i*Temp.Space.phi*m(185));
  r.set_size(&cc_emlrtRTEI, sp, 1, Field->contents.size(1));
  loop_ub = Field->contents.size(1);
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = Field->contents[i];
    varargout_1.re =
        varargin_1.re * varargin_1.re - varargin_1.im * varargin_1.im;
    tmp_re = varargin_1.re * varargin_1.im;
    varargout_1.im = tmp_re + tmp_re;
    r[i] = varargout_1;
  }
  i = G_theta->contents.size(1);
  if ((i != r.size(1)) && ((i != 1) && (r.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(i, r.size(1), &g_emlrtECI, (emlrtCTX)sp);
  }
  if (G_theta->contents.size(1) == r.size(1)) {
    b_G_theta.set_size(&dc_emlrtRTEI, sp, 1, G_theta->contents.size(1));
    loop_ub = G_theta->contents.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_G_theta[i].re = G_theta->contents[i] * r[i].re;
      b_G_theta[i].im = G_theta->contents[i] * r[i].im;
    }
    st.site = &hb_emlrtRSI;
    coder::fft(&st, b_G_theta, y);
  } else {
    st.site = &hb_emlrtRSI;
    binary_expand_op(&st, y, hb_emlrtRSI, G_theta, r);
  }
  tmp_im = N->contents;
  y.set_size(&ec_emlrtRTEI, sp, 1, y.size(1));
  loop_ub = y.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    tmp_re = y[i].re;
    b_N = y[i].im;
    if (b_N == 0.0) {
      re = tmp_re / tmp_im;
      b_im = 0.0;
    } else if (tmp_re == 0.0) {
      re = 0.0;
      b_im = b_N / tmp_im;
    } else {
      re = tmp_re / tmp_im;
      b_im = b_N / tmp_im;
    }
    y[i].re = re;
    y[i].im = b_im;
  }
  iv[0] = 1;
  iv[1] = k_zero.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, y.size(), 2, &h_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    k_zero[2 * i] = y[i];
  }
  //     exp(1i*Temp.Space.phi*411)*B_Psi(412) +
  //     exp(1i*Temp.Space.phi*411)*B_Psi(412) k_zero(1,:)   =
  //     fft(G_theta.*(E_1.^2+E_2.*E_1)/N;%Field.^2
  //    k_zero(1,1:2048)   = fft(GG_theta.*( GField.^2 +
  //    GField.*conj(GField)))/N*2;
  //     k_zero(1,185) =
  //     1/2*B_Psi(412).*conj(B_Psi(185))+1/2*B_Psi(326).*conj(B_Psi(185));
  //    k_zero(1,326) = 1/2*B_Psi(185).^2;
  //   k_zero(1,412) = 1/2*B_Psi(185).^2;
  //   mode_cut(Eq.mode_range).*
  r.set_size(&fc_emlrtRTEI, sp, 1, Field->contents.size(1));
  loop_ub = Field->contents.size(1);
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = Field->contents[i];
    if ((varargin_1.im == 0.0) && (varargin_1.re >= 0.0)) {
      varargout_1.re = muDoubleScalarPower(varargin_1.re, 3.0);
      varargout_1.im = 0.0;
    } else if (varargin_1.re == 0.0) {
      varargout_1.re = 0.0;
      varargout_1.im = -muDoubleScalarPower(varargin_1.im, 3.0);
    } else {
      if (varargin_1.im == 0.0) {
        if (varargin_1.re < 0.0) {
          tmp_re = muDoubleScalarLog(muDoubleScalarAbs(varargin_1.re));
          tmp_im = 3.1415926535897931;
        } else {
          tmp_re = muDoubleScalarLog(varargin_1.re);
          tmp_im = 0.0;
        }
      } else if ((muDoubleScalarAbs(varargin_1.re) > 8.9884656743115785E+307) ||
                 (muDoubleScalarAbs(varargin_1.im) > 8.9884656743115785E+307)) {
        tmp_re = muDoubleScalarLog(muDoubleScalarHypot(varargin_1.re / 2.0,
                                                       varargin_1.im / 2.0)) +
                 0.69314718055994529;
        tmp_im = muDoubleScalarAtan2(varargin_1.im, varargin_1.re);
      } else {
        tmp_re = muDoubleScalarLog(
            muDoubleScalarHypot(varargin_1.re, varargin_1.im));
        tmp_im = muDoubleScalarAtan2(varargin_1.im, varargin_1.re);
      }
      varargout_1.re = 3.0 * tmp_re;
      varargout_1.im = 3.0 * tmp_im;
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
        tmp_re = muDoubleScalarExp(varargout_1.re / 2.0);
        d = varargout_1.im;
        im = varargout_1.im;
        varargout_1.re = tmp_re * (tmp_re * muDoubleScalarCos(d));
        varargout_1.im = tmp_re * (tmp_re * muDoubleScalarSin(im));
      }
    }
    r[i] = varargout_1;
  }
  st.site = &ib_emlrtRSI;
  coder::fft(&st, r, y);
  tmp_im = N->contents;
  y.set_size(&gc_emlrtRTEI, sp, 1, y.size(1));
  loop_ub = y.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    tmp_re = y[i].re;
    b_N = y[i].im;
    if (b_N == 0.0) {
      re = tmp_re / tmp_im;
      b_im = 0.0;
    } else if (tmp_re == 0.0) {
      re = 0.0;
      b_im = b_N / tmp_im;
    } else {
      re = tmp_re / tmp_im;
      b_im = b_N / tmp_im;
    }
    y[i].re = re;
    y[i].im = b_im;
  }
  iv[0] = 1;
  iv[1] = k_zero.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, y.size(), 2, &i_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    k_zero[2 * i + 1] = y[i];
  }
  // mode_cut(Eq.mode_range).*
  nd2 = k_e.size(1);
  for (i = 0; i < 1309; i++) {
    real_T b_re;
    real_T b_re_tmp;
    real_T re_tmp;
    b_im = Eq_gamma2[i];
    re = b_im * 0.0;
    d = Eq_mode_range[i];
    if ((static_cast<int32_T>(d) < 1) ||
        (static_cast<int32_T>(d) > k_zero.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, k_zero.size(1),
                                    &s_emlrtBCI, (emlrtCTX)sp);
    }
    if (static_cast<int32_T>(d) > k_zero.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, k_zero.size(1),
                                    &s_emlrtBCI, (emlrtCTX)sp);
    }
    tmp_im = k_zero[2 * (static_cast<int32_T>(d) - 1)].im;
    b_N = k_zero[2 * (static_cast<int32_T>(d) - 1)].re;
    if (static_cast<int32_T>(d) > k_zero.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, k_zero.size(1),
                                    &s_emlrtBCI, (emlrtCTX)sp);
    }
    if (static_cast<int32_T>(d) > k_zero.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, k_zero.size(1),
                                    &s_emlrtBCI, (emlrtCTX)sp);
    }
    im = Eq_gamma3[i];
    tmp_re = im * 0.0;
    if (static_cast<int32_T>(d) > k_zero.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, k_zero.size(1),
                                    &t_emlrtBCI, (emlrtCTX)sp);
    }
    if (static_cast<int32_T>(d) > k_zero.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, k_zero.size(1),
                                    &t_emlrtBCI, (emlrtCTX)sp);
    }
    re_tmp = k_zero[2 * (static_cast<int32_T>(d) - 1) + 1].im;
    b_re_tmp = k_zero[2 * (static_cast<int32_T>(d) - 1) + 1].re;
    if (static_cast<int32_T>(d) > k_zero.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, k_zero.size(1),
                                    &t_emlrtBCI, (emlrtCTX)sp);
    }
    if (static_cast<int32_T>(d) > k_zero.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, k_zero.size(1),
                                    &t_emlrtBCI, (emlrtCTX)sp);
    }
    b_re = (re * b_N - b_im * tmp_im) + (tmp_re * b_re_tmp - im * re_tmp);
    b_im = (re * tmp_im + b_im * b_N) + (tmp_re * re_tmp + im * b_re_tmp);
    if (static_cast<int32_T>(d) > Fac_plus.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                    Fac_plus.size(1), &u_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    tmp_re = Fac_plus[static_cast<int32_T>(d) - 1].re;
    tmp_im = Fac_plus[static_cast<int32_T>(d) - 1].im;
    if (static_cast<int32_T>(d) > Fac_plus.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1,
                                    Fac_plus.size(1), &u_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (static_cast<int32_T>(d) > k_e.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, k_e.size(1),
                                    &k_emlrtBCI, (emlrtCTX)sp);
    }
    b_Fac_minus[i].re =
        k_e[static_cast<int32_T>(d) - 1].re + (tmp_re * b_re - tmp_im * b_im);
    if (static_cast<int32_T>(d) > k_e.size(1)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, k_e.size(1),
                                    &k_emlrtBCI, (emlrtCTX)sp);
    }
    b_Fac_minus[i].im =
        k_e[static_cast<int32_T>(d) - 1].im + (tmp_re * b_im + tmp_im * b_re);
  }
  for (i = 0; i < 1309; i++) {
    d = Eq_mode_range[i];
    if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) > nd2)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, nd2,
                                    &l_emlrtBCI, (emlrtCTX)sp);
    }
    k_e[static_cast<int32_T>(d) - 1].re = b_Fac_minus[i].re;
    if (static_cast<int32_T>(d) > nd2) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, nd2,
                                    &l_emlrtBCI, (emlrtCTX)sp);
    }
    k_e[static_cast<int32_T>(d) - 1].im = b_Fac_minus[i].im;
  }
  //     k_e                = k_e - 1/2*Eq.kappa.*B_Psi;
  //  Fac_plus(Eq.Pump.ind_pump).*
  // -Fac_minus(Eq.Pump.ind_pump).*1/2*Eq.kappa(Eq.Pump.ind_pump).*B_Psi(Eq.Pump.ind_pump)
  r.set_size(&hc_emlrtRTEI, sp, 1, ind_pump->contents.size(1));
  loop_ub = ind_pump->contents.size(1);
  for (i = 0; i < loop_ub; i++) {
    k = static_cast<int32_T>(muDoubleScalarFloor(ind_pump->contents[i]));
    if (ind_pump->contents[i] != k) {
      emlrtIntegerCheckR2012b(ind_pump->contents[i], &hb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    i1 = static_cast<int32_T>(ind_pump->contents[i]);
    if ((i1 < 1) || (i1 > k_e.size(1))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, k_e.size(1), &m_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    r[i].re = k_e[i1 - 1].re;
    if (ind_pump->contents[i] != k) {
      emlrtIntegerCheckR2012b(ind_pump->contents[i], &hb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (i1 > k_e.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, k_e.size(1), &m_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    r[i].im = k_e[i1 - 1].im;
  }
  y.set_size(&ic_emlrtRTEI, sp, 1, ind_pump->contents.size(1));
  loop_ub = ind_pump->contents.size(1);
  for (i = 0; i < loop_ub; i++) {
    k = static_cast<int32_T>(muDoubleScalarFloor(ind_pump->contents[i]));
    if (ind_pump->contents[i] != k) {
      emlrtIntegerCheckR2012b(ind_pump->contents[i], &ib_emlrtDCI,
                              (emlrtCTX)sp);
    }
    i1 = static_cast<int32_T>(ind_pump->contents[i]);
    if ((i1 < 1) || (i1 > Fac_plus.size(1))) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, Fac_plus.size(1), &n_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    y[i].re = Fac_plus[i1 - 1].re;
    if (ind_pump->contents[i] != k) {
      emlrtIntegerCheckR2012b(ind_pump->contents[i], &ib_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (i1 > Fac_plus.size(1)) {
      emlrtDynamicBoundsCheckR2012b(i1, 1, Fac_plus.size(1), &n_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    y[i].im = Fac_plus[i1 - 1].im;
  }
  if (Eq_Pump_ind_pump !=
      static_cast<int32_T>(muDoubleScalarFloor(Eq_Pump_ind_pump))) {
    emlrtIntegerCheckR2012b(Eq_Pump_ind_pump, &y_emlrtDCI, (emlrtCTX)sp);
  }
  if ((static_cast<int32_T>(Eq_Pump_ind_pump) < 1) ||
      (static_cast<int32_T>(Eq_Pump_ind_pump) > 1309)) {
    emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(Eq_Pump_ind_pump), 1,
                                  1309, &g_emlrtBCI, (emlrtCTX)sp);
  }
  y.set_size(&ic_emlrtRTEI, sp, 1, y.size(1));
  loop_ub = y.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    tmp_re = y[i].re;
    b_N = y[i].im;
    if (b_N == 0.0) {
      im = tmp_re / 2.0;
      tmp_im = 0.0;
    } else if (tmp_re == 0.0) {
      im = 0.0;
      tmp_im = b_N / 2.0;
    } else {
      im = tmp_re / 2.0;
      tmp_im = b_N / 2.0;
    }
    tmp_re = Eq_kappa[static_cast<int32_T>(Eq_Pump_ind_pump) - 1];
    im = Eq_Pump_H * (tmp_re * im);
    tmp_im = Eq_Pump_H * (tmp_re * tmp_im);
    tmp_re = im * pump_phase_substep.re - tmp_im * pump_phase_substep.im;
    tmp_im = im * pump_phase_substep.im + tmp_im * pump_phase_substep.re;
    y[i].re = tmp_re * pump_phase.re - tmp_im * pump_phase.im;
    y[i].im = tmp_re * pump_phase.im + tmp_im * pump_phase.re;
  }
  i = ind_pump->contents.size(1);
  if ((i != y.size(1)) && ((i != 1) && (y.size(1) != 1))) {
    emlrtDimSizeImpxCheckR2021b(i, y.size(1), &j_emlrtECI, (emlrtCTX)sp);
  }
  r1.set_size(&jc_emlrtRTEI, sp, 1, ind_pump->contents.size(1));
  loop_ub = ind_pump->contents.size(1);
  for (i = 0; i < loop_ub; i++) {
    if (ind_pump->contents[i] !=
        static_cast<int32_T>(muDoubleScalarFloor(ind_pump->contents[i]))) {
      emlrtIntegerCheckR2012b(ind_pump->contents[i], &jb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    k = static_cast<int32_T>(ind_pump->contents[i]);
    if ((k < 1) || (k > k_e.size(1))) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ind_pump->contents[i]),
                                    1, k_e.size(1), &o_emlrtBCI, (emlrtCTX)sp);
    }
    r1[i] = k;
  }
  if (r.size(1) == y.size(1)) {
    loop_ub = r.size(1) - 1;
    r.set_size(&hc_emlrtRTEI, sp, 1, r.size(1));
    for (i = 0; i <= loop_ub; i++) {
      r[i].re = r[i].re + y[i].re;
      r[i].im = r[i].im + y[i].im;
    }
  } else {
    st.site = &ub_emlrtRSI;
    plus(&st, r, y);
  }
  if (r1.size(1) != r.size(1)) {
    emlrtSubAssignSizeCheck1dR2017a(r1.size(1), r.size(1), &k_emlrtECI,
                                    (emlrtCTX)sp);
  }
  loop_ub = r.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    k_e[r1[i] - 1] = r[i];
  }
  //     k_e(ind_pump)    = k_e(ind_pump) +
  //     1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1).*pump_phase_substep*pump_phase;
  //     k_e(ind_pump)    = k_e(ind_pump) +
  //     Fac_plus(ind_pump).*1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1).*pump_phase_substep*pump_phase;
  //     k_e(ind_pump)    = k_e(ind_pump)+
  //     1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1).*exp(1i*Temp.Eq.Pump.delta*t);
  //     k_e(ind_pump)    = k_e(ind_pump)+
  //     1/2*Eq.kappa(Eq.Pump.ind_pump)*Eq.Pump.H(1)*pump_phase_substep*pump_phase;
  // Fac_plus(Eq.Pump.ind_pump).*Fac_plus(Eq.Pump.ind_pump).*
  // Fac_minus(Eq.Pump.ind_pump).*
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void Runge_Kuarong_step(
    const emlrtStack *sp, const coder::c_captured_var *N,
    const coder::captured_var *Temp, coder::e_captured_var *Field,
    const coder::d_captured_var *G_theta, const coder::d_captured_var *ind_pump,
    const coder::e_captured_var *exp_plus_omega,
    const coder::e_captured_var *exp_minus_omega,
    const coder::f_captured_var *pump_phase_substep,
    const coder::b_captured_var *Runge, const coder::e_captured_var *shift_back,
    creal_T B_E[2048], real_T dt, const creal_T pump_phase,
    coder::array<creal_T, 2U> &d, const coder::array<creal_T, 2U> &k_zero)
{
  coder::array<creal_T, 2U> b_exp_minus_omega;
  coder::array<creal_T, 2U> b_exp_plus_omega;
  coder::array<creal_T, 2U> b_k_zero;
  coder::array<creal_T, 2U> r;
  emlrtStack st;
  creal_T E_temp[2048];
  creal_T b_B_E[2048];
  creal_T b_E_temp[1309];
  real_T b_d;
  real_T b_dt;
  real_T d1;
  int32_T iv[2];
  int32_T b_i2;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i3;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  //     Sol.Pric = F_Intermid;
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  std::copy(&B_E[0], &B_E[2048], &E_temp[0]);
  if (1 > d.size(0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, d.size(0), &v_emlrtBCI, (emlrtCTX)sp);
  }
  loop_ub = exp_plus_omega->contents.size(1);
  b_exp_plus_omega.set_size(&lc_emlrtRTEI, sp, 1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_exp_plus_omega[i] = exp_plus_omega->contents[3 * i];
  }
  loop_ub = exp_minus_omega->contents.size(1);
  b_exp_minus_omega.set_size(&mc_emlrtRTEI, sp, 1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_exp_minus_omega[i] = exp_minus_omega->contents[3 * i];
  }
  b_k_zero.set_size(&nc_emlrtRTEI, sp, 2, k_zero.size(1));
  loop_ub = k_zero.size(0) * k_zero.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    b_k_zero[i] = k_zero[i];
  }
  std::copy(&B_E[0], &B_E[2048], &b_B_E[0]);
  st.site = &eb_emlrtRSI;
  Chi_3_LLE_Kuar_ins(&st, N, Temp, Field, G_theta, ind_pump, b_B_E,
                     b_exp_plus_omega, b_exp_minus_omega,
                     pump_phase_substep->contents[0],
                     Temp->contents.Eq.mode_range,
                     Temp->contents.Eq.Pump.ind_pump, Temp->contents.Eq.Pump.H,
                     Temp->contents.Eq.kappa, Temp->contents.Eq.gamma2,
                     Temp->contents.Eq.gamma3, b_k_zero, pump_phase, r);
  iv[0] = 1;
  iv[1] = d.size(1);
  emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r.size(), 2, &m_emlrtECI,
                                (emlrtCTX)sp);
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    d[d.size(0) * i] = r[i];
  }
  b_d = Runge->contents.s;
  i = static_cast<int32_T>(b_d + -1.0);
  emlrtForLoopVectorCheckR2021a(2.0, 1.0, b_d, mxDOUBLE_CLASS,
                                static_cast<int32_T>(b_d + -1.0), &h_emlrtRTEI,
                                (emlrtCTX)sp);
  if (0 <= static_cast<int32_T>(b_d + -1.0) - 1) {
    d1 = b_d - 1.0;
    i1 = static_cast<int32_T>(b_d - 1.0);
    b_loop_ub = exp_plus_omega->contents.size(1);
    c_loop_ub = exp_minus_omega->contents.size(1);
    iv[0] = 1;
  }
  for (int32_T i2{0}; i2 < i; i2++) {
    emlrtForLoopVectorCheckR2021a(1.0, 1.0, d1, mxDOUBLE_CLASS,
                                  static_cast<int32_T>(d1), &i_emlrtRTEI,
                                  (emlrtCTX)sp);
    for (int32_T ii{0}; ii < i1; ii++) {
      if ((static_cast<int32_T>(i2 + 2U) < 1) ||
          (static_cast<int32_T>(i2 + 2U) > 3)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(i2 + 2U), 1, 3,
                                      &cb_emlrtBCI, (emlrtCTX)sp);
      }
      if ((static_cast<int32_T>(ii + 1U) < 1) ||
          (static_cast<int32_T>(ii + 1U) > 3)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ii + 1U), 1, 3,
                                      &db_emlrtBCI, (emlrtCTX)sp);
      }
      b_dt = Runge->contents.b[(i2 + 3 * ii) + 1];
      if (b_dt != 0.0) {
        b_dt *= dt;
        if ((static_cast<int32_T>(ii + 1U) < 1) ||
            (static_cast<int32_T>(ii + 1U) > d.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(ii + 1U), 1,
                                        d.size(0), &w_emlrtBCI, (emlrtCTX)sp);
        }
        for (b_i2 = 0; b_i2 < 1309; b_i2++) {
          i3 = static_cast<int32_T>(
              muDoubleScalarFloor(Temp->contents.Eq.mode_range[b_i2]));
          if (Temp->contents.Eq.mode_range[b_i2] != i3) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &ob_emlrtDCI, (emlrtCTX)sp);
          }
          loop_ub = static_cast<int32_T>(Temp->contents.Eq.mode_range[b_i2]);
          if ((loop_ub < 1) || (loop_ub > 2048)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 2048, &hb_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (Temp->contents.Eq.mode_range[b_i2] != i3) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &pb_emlrtDCI, (emlrtCTX)sp);
          }
          if (loop_ub > d.size(1)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, d.size(1), &ib_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          b_E_temp[b_i2].re = E_temp[loop_ub - 1].re +
                              b_dt * d[ii + d.size(0) * (loop_ub - 1)].re;
          if (Temp->contents.Eq.mode_range[b_i2] != i3) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &ob_emlrtDCI, (emlrtCTX)sp);
          }
          if (loop_ub > d.size(1)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, d.size(1), &ib_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          b_E_temp[b_i2].im = E_temp[loop_ub - 1].im +
                              b_dt * d[ii + d.size(0) * (loop_ub - 1)].im;
        }
        for (b_i2 = 0; b_i2 < 1309; b_i2++) {
          i3 = static_cast<int32_T>(
              muDoubleScalarFloor(Temp->contents.Eq.mode_range[b_i2]));
          if (Temp->contents.Eq.mode_range[b_i2] != i3) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &rb_emlrtDCI, (emlrtCTX)sp);
          }
          loop_ub = static_cast<int32_T>(Temp->contents.Eq.mode_range[b_i2]);
          if ((loop_ub < 1) || (loop_ub > 2048)) {
            emlrtDynamicBoundsCheckR2012b(loop_ub, 1, 2048, &kb_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          E_temp[loop_ub - 1].re = b_E_temp[b_i2].re;
          if (Temp->contents.Eq.mode_range[b_i2] != i3) {
            emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[b_i2],
                                    &rb_emlrtDCI, (emlrtCTX)sp);
          }
          E_temp[loop_ub - 1].im = b_E_temp[b_i2].im;
        }
      }
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    if ((i2 + 2 < 1) || (i2 + 2 > d.size(0))) {
      emlrtDynamicBoundsCheckR2012b(i2 + 2, 1, d.size(0), &y_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if ((static_cast<int32_T>(i2 + 2U) < 1) ||
        (static_cast<int32_T>(i2 + 2U) > 3)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(i2 + 2U), 1, 3,
                                    &x_emlrtBCI, (emlrtCTX)sp);
    }
    b_exp_plus_omega.set_size(&oc_emlrtRTEI, sp, 1, b_loop_ub);
    for (b_i2 = 0; b_i2 < b_loop_ub; b_i2++) {
      b_exp_plus_omega[b_i2] = exp_plus_omega->contents[(i2 + 3 * b_i2) + 1];
    }
    b_exp_minus_omega.set_size(&pc_emlrtRTEI, sp, 1, c_loop_ub);
    for (b_i2 = 0; b_i2 < c_loop_ub; b_i2++) {
      b_exp_minus_omega[b_i2] = exp_minus_omega->contents[(i2 + 3 * b_i2) + 1];
    }
    b_k_zero.set_size(&qc_emlrtRTEI, sp, 2, k_zero.size(1));
    loop_ub = k_zero.size(0) * k_zero.size(1) - 1;
    for (b_i2 = 0; b_i2 <= loop_ub; b_i2++) {
      b_k_zero[b_i2] = k_zero[b_i2];
    }
    st.site = &fb_emlrtRSI;
    Chi_3_LLE_Kuar_ins(
        &st, N, Temp, Field, G_theta, ind_pump, E_temp, b_exp_plus_omega,
        b_exp_minus_omega, pump_phase_substep->contents[i2 + 1],
        Temp->contents.Eq.mode_range, Temp->contents.Eq.Pump.ind_pump,
        Temp->contents.Eq.Pump.H, Temp->contents.Eq.kappa,
        Temp->contents.Eq.gamma2, Temp->contents.Eq.gamma3, b_k_zero,
        pump_phase, r);
    iv[1] = d.size(1);
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r.size(), 2, &n_emlrtECI,
                                  (emlrtCTX)sp);
    loop_ub = r.size(1);
    for (b_i2 = 0; b_i2 < loop_ub; b_i2++) {
      d[(i2 + d.size(0) * b_i2) + 1] = r[b_i2];
    }
    std::copy(&B_E[0], &B_E[2048], &E_temp[0]);
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  i = static_cast<int32_T>(b_d);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, b_d, mxDOUBLE_CLASS,
                                static_cast<int32_T>(b_d), &j_emlrtRTEI,
                                (emlrtCTX)sp);
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    if ((static_cast<int32_T>(loop_ub + 1U) < 1) ||
        (static_cast<int32_T>(loop_ub + 1U) > 3)) {
      emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(loop_ub + 1U), 1, 3,
                                    &bb_emlrtBCI, (emlrtCTX)sp);
    }
    if (Runge->contents.c[loop_ub] != 0.0) {
      b_dt = dt * Runge->contents.c[loop_ub];
      if ((static_cast<int32_T>(loop_ub + 1U) < 1) ||
          (static_cast<int32_T>(loop_ub + 1U) > d.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(loop_ub + 1U), 1,
                                      d.size(0), &ab_emlrtBCI, (emlrtCTX)sp);
      }
      for (i1 = 0; i1 < 1309; i1++) {
        b_i2 = static_cast<int32_T>(
            muDoubleScalarFloor(Temp->contents.Eq.mode_range[i1]));
        if (Temp->contents.Eq.mode_range[i1] != b_i2) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &mb_emlrtDCI, (emlrtCTX)sp);
        }
        i3 = static_cast<int32_T>(Temp->contents.Eq.mode_range[i1]);
        if ((i3 < 1) || (i3 > 2048)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 2048, &fb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (Temp->contents.Eq.mode_range[i1] != b_i2) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &nb_emlrtDCI, (emlrtCTX)sp);
        }
        if (i3 > d.size(1)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, d.size(1), &gb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_E_temp[i1].re =
            B_E[i3 - 1].re + b_dt * d[loop_ub + d.size(0) * (i3 - 1)].re;
        if (Temp->contents.Eq.mode_range[i1] != b_i2) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &mb_emlrtDCI, (emlrtCTX)sp);
        }
        if (i3 > d.size(1)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, d.size(1), &gb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_E_temp[i1].im =
            B_E[i3 - 1].im + b_dt * d[loop_ub + d.size(0) * (i3 - 1)].im;
      }
      for (i1 = 0; i1 < 1309; i1++) {
        b_i2 = static_cast<int32_T>(
            muDoubleScalarFloor(Temp->contents.Eq.mode_range[i1]));
        if (Temp->contents.Eq.mode_range[i1] != b_i2) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &qb_emlrtDCI, (emlrtCTX)sp);
        }
        i3 = static_cast<int32_T>(Temp->contents.Eq.mode_range[i1]);
        if ((i3 < 1) || (i3 > 2048)) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, 2048, &jb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        B_E[i3 - 1].re = b_E_temp[i1].re;
        if (Temp->contents.Eq.mode_range[i1] != b_i2) {
          emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i1],
                                  &qb_emlrtDCI, (emlrtCTX)sp);
        }
        B_E[i3 - 1].im = b_E_temp[i1].im;
      }
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  loop_ub = shift_back->contents.size(1);
  for (i = 0; i < 1309; i++) {
    i1 = static_cast<int32_T>(
        muDoubleScalarFloor(Temp->contents.Eq.mode_range[i]));
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &sb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    b_i2 = static_cast<int32_T>(Temp->contents.Eq.mode_range[i]);
    if ((b_i2 < 1) || (b_i2 > 2048)) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, 2048, &lb_emlrtBCI, (emlrtCTX)sp);
    }
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &sb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (b_i2 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, loop_ub, &mb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &sb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (b_i2 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, loop_ub, &mb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_d = B_E[b_i2 - 1].re;
    d1 = B_E[b_i2 - 1].im;
    b_E_temp[i].re = b_d * shift_back->contents[b_i2 - 1].re -
                     d1 * shift_back->contents[b_i2 - 1].im;
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &sb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (b_i2 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, loop_ub, &mb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &sb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    if (b_i2 > loop_ub) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, loop_ub, &mb_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    b_E_temp[i].im = b_d * shift_back->contents[b_i2 - 1].im +
                     d1 * shift_back->contents[b_i2 - 1].re;
  }
  for (i = 0; i < 1309; i++) {
    i1 = static_cast<int32_T>(
        muDoubleScalarFloor(Temp->contents.Eq.mode_range[i]));
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &lb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    b_i2 = static_cast<int32_T>(Temp->contents.Eq.mode_range[i]);
    if ((b_i2 < 1) || (b_i2 > 2048)) {
      emlrtDynamicBoundsCheckR2012b(b_i2, 1, 2048, &eb_emlrtBCI, (emlrtCTX)sp);
    }
    B_E[b_i2 - 1].re = b_E_temp[i].re;
    if (Temp->contents.Eq.mode_range[i] != i1) {
      emlrtIntegerCheckR2012b(Temp->contents.Eq.mode_range[i], &lb_emlrtDCI,
                              (emlrtCTX)sp);
    }
    B_E[b_i2 - 1].im = b_E_temp[i].im;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void binary_expand_op(const emlrtStack *sp, coder::array<creal_T, 2U> &y,
                             emlrtRSInfo vb_emlrtRSI,
                             const coder::d_captured_var *G_theta,
                             const coder::array<creal_T, 2U> &r)
{
  coder::array<creal_T, 2U> b_G_theta;
  emlrtStack st;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (r.size(1) == 1) {
    i = G_theta->contents.size(1);
  } else {
    i = r.size(1);
  }
  b_G_theta.set_size(&dc_emlrtRTEI, sp, 1, i);
  stride_0_1 = (G_theta->contents.size(1) != 1);
  stride_1_1 = (r.size(1) != 1);
  if (r.size(1) == 1) {
    loop_ub = G_theta->contents.size(1);
  } else {
    loop_ub = r.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    int32_T i1;
    i1 = i * stride_1_1;
    b_G_theta[i].re = G_theta->contents[i * stride_0_1] * r[i1].re;
    b_G_theta[i].im = G_theta->contents[i * stride_0_1] * r[i1].im;
  }
  st.site = &vb_emlrtRSI;
  coder::fft(&st, b_G_theta, y);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void minus(const emlrtStack *sp, coder::array<real_T, 2U> &G,
                  const coder::array<real_T, 2U> &r)
{
  coder::array<real_T, 2U> b_G;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (r.size(1) == 1) {
    i = G.size(1);
  } else {
    i = r.size(1);
  }
  b_G.set_size(&rc_emlrtRTEI, sp, 1, i);
  stride_0_1 = (G.size(1) != 1);
  stride_1_1 = (r.size(1) != 1);
  if (r.size(1) == 1) {
    loop_ub = G.size(1);
  } else {
    loop_ub = r.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_G[i] = G[i * stride_0_1] - r[i * stride_1_1];
  }
  G.set_size(&rc_emlrtRTEI, sp, 1, b_G.size(1));
  loop_ub = b_G.size(1);
  for (i = 0; i < loop_ub; i++) {
    G[i] = b_G[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void plus(const emlrtStack *sp, coder::array<creal_T, 2U> &r1,
                 const coder::array<creal_T, 2U> &y)
{
  coder::array<creal_T, 2U> r;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (y.size(1) == 1) {
    i = r1.size(1);
  } else {
    i = y.size(1);
  }
  r.set_size(&hc_emlrtRTEI, sp, 1, i);
  stride_0_1 = (r1.size(1) != 1);
  stride_1_1 = (y.size(1) != 1);
  if (y.size(1) == 1) {
    loop_ub = r1.size(1);
  } else {
    loop_ub = y.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    int32_T i1;
    i1 = i * stride_1_1;
    r[i].re = r1[i * stride_0_1].re + y[i1].re;
    r[i].im = r1[i * stride_0_1].im + y[i1].im;
  }
  r1.set_size(&hc_emlrtRTEI, sp, 1, r.size(1));
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = r[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void plus(const emlrtStack *sp, coder::array<real_T, 2U> &G,
                 const coder::array<real_T, 2U> &r)
{
  coder::array<real_T, 2U> b_G;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (r.size(1) == 1) {
    i = G.size(1);
  } else {
    i = r.size(1);
  }
  b_G.set_size(&sc_emlrtRTEI, sp, 1, i);
  stride_0_1 = (G.size(1) != 1);
  stride_1_1 = (r.size(1) != 1);
  if (r.size(1) == 1) {
    loop_ub = G.size(1);
  } else {
    loop_ub = r.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_G[i] = G[i * stride_0_1] + r[i * stride_1_1];
  }
  G.set_size(&sc_emlrtRTEI, sp, 1, b_G.size(1));
  loop_ub = b_G.size(1);
  for (i = 0; i < loop_ub; i++) {
    G[i] = b_G[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void times(const emlrtStack *sp, coder::array<creal_T, 2U> &r1,
                  const coder::array<creal_T, 2U> &r2)
{
  coder::array<creal_T, 2U> r;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_1;
  int32_T stride_1_1;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (r1.size(1) == 1) {
    i = r2.size(1);
  } else {
    i = r1.size(1);
  }
  r.set_size(&pb_emlrtRTEI, sp, 1, i);
  stride_0_1 = (r2.size(1) != 1);
  stride_1_1 = (r1.size(1) != 1);
  if (r1.size(1) == 1) {
    loop_ub = r2.size(1);
  } else {
    loop_ub = r1.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    real_T d;
    real_T d1;
    int32_T i1;
    i1 = i * stride_1_1;
    d = r1[i1].im;
    d1 = r1[i1].re;
    r[i].re = r2[i * stride_0_1].re * d1 - r2[i * stride_0_1].im * d;
    r[i].im = r2[i * stride_0_1].re * d + r2[i * stride_0_1].im * d1;
  }
  r1.set_size(&pb_emlrtRTEI, sp, 1, r.size(1));
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    r1[i] = r[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void FullField_SingleProgection_dynamics_ForLongSave(
    e_FullField_SingleProgection_dy *SD, const emlrtStack *sp,
    const struct0_T *Temp, const struct7_T *Runge, struct8_T *Sol)
{
  static const real_T p[8]{-1.716185138865495,  24.76565080557592,
                           -379.80425647094563, 629.3311553128184,
                           866.96620279041326,  -31451.272968848367,
                           -36144.413418691176, 66456.143820240541};
  static const real_T q[8]{-30.840230011973897, 315.35062697960416,
                           -1015.1563674902192, -3107.7716715723109,
                           22538.11842098015,   4755.8462775278813,
                           -134659.95986496931, -115132.25967555349};
  coder::b_captured_var b_Runge;
  coder::c_captured_var N;
  coder::d_captured_var G_theta;
  coder::d_captured_var ind_pump;
  coder::e_captured_var Field;
  coder::e_captured_var exp_minus_omega;
  coder::e_captured_var exp_plus_omega;
  coder::e_captured_var shift_back;
  coder::f_captured_var pump_phase_substep;
  coder::array<creal_T, 2U> Eq_L;
  coder::array<creal_T, 2U> c_d;
  coder::array<creal_T, 2U> d;
  coder::array<creal_T, 2U> k_zero;
  coder::array<creal_T, 2U> r1;
  coder::array<creal_T, 2U> r2;
  coder::array<real_T, 2U> G;
  coder::array<real_T, 2U> b_phi;
  coder::array<real_T, 2U> phi;
  coder::array<real_T, 2U> r;
  coder::array<int32_T, 2U> ii;
  coder::array<boolean_T, 2U> c_phi;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  creal_T phase_pump;
  real_T alpha;
  real_T b_d;
  real_T dt_tmp_tmp;
  real_T g;
  real_T mu;
  real_T nt;
  real_T varargin_1;
  real_T xden;
  real_T xnum;
  int32_T ind_Save_data[6545];
  int32_T b_tmp_data[1309];
  int32_T c_tmp_data[1309];
  int32_T d_tmp_data[1309];
  int32_T e_tmp_data[1309];
  int32_T tmp_data[1309];
  int32_T b_tmp_size[2];
  int32_T c_tmp_size[2];
  int32_T d_tmp_size[2];
  int32_T e_tmp_size[2];
  int32_T iv[2];
  int32_T tmp_size[2];
  int32_T b_i;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T last;
  int32_T loop_ub;
  boolean_T b_Temp[1309];
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
  st.site = &emlrtRSI;
  b_st.site = &k_emlrtRSI;
  SD->f0.Temp.contents = *Temp;
  st.site = &emlrtRSI;
  b_st.site = &k_emlrtRSI;
  b_Runge.contents = *Runge;
  st.site = &emlrtRSI;
  b_st.site = &k_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &k_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &k_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &k_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &k_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &k_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &k_emlrtRSI;
  st.site = &emlrtRSI;
  b_st.site = &k_emlrtRSI;
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &d_emlrtDCI, (emlrtCTX)sp);
  }
  varargin_1 = static_cast<int32_T>(muDoubleScalarFloor(Runge->s));
  if (Runge->s != varargin_1) {
    emlrtIntegerCheckR2012b(Runge->s, &c_emlrtDCI, (emlrtCTX)sp);
  }
  d.set_size(&k_emlrtRTEI, sp, static_cast<int32_T>(Runge->s), d.size(1));
  if (!(Temp->Space.N >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Space.N, &f_emlrtDCI, (emlrtCTX)sp);
  }
  b_d = static_cast<int32_T>(muDoubleScalarFloor(Temp->Space.N));
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &e_emlrtDCI, (emlrtCTX)sp);
  }
  d.set_size(&k_emlrtRTEI, sp, d.size(0), static_cast<int32_T>(Temp->Space.N));
  if (Runge->s != varargin_1) {
    emlrtIntegerCheckR2012b(Runge->s, &o_emlrtDCI, (emlrtCTX)sp);
  }
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &o_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub =
      static_cast<int32_T>(Runge->s) * static_cast<int32_T>(Temp->Space.N);
  for (i = 0; i < loop_ub; i++) {
    d[i].re = 0.0;
    d[i].im = 0.0;
  }
  dt_tmp_tmp = Temp->Par.dt;
  nt = muDoubleScalarRound(Temp->Par.T / Temp->Par.dt);
  N.contents = Temp->Space.N;
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  // +exp(-1i*Temp.Space.phi*Temp.Eq.g);
  g = muDoubleScalarAbs(Temp->Eq.g);
  if (Temp->Space.N - 1.0 < 0.0) {
    phi.set_size(&l_emlrtRTEI, sp, phi.size(0), 0);
  } else if (muDoubleScalarIsInf(Temp->Space.N - 1.0) &&
             (0.0 == Temp->Space.N - 1.0)) {
    phi.set_size(&l_emlrtRTEI, sp, 1, 1);
    phi[0] = rtNaN;
  } else {
    loop_ub = static_cast<int32_T>(muDoubleScalarFloor(Temp->Space.N - 1.0));
    phi.set_size(&l_emlrtRTEI, sp, 1, loop_ub + 1);
    for (i = 0; i <= loop_ub; i++) {
      phi[i] = i;
    }
  }
  mu = 6.2831853071795862 / Temp->Space.N;
  phi.set_size(&m_emlrtRTEI, sp, 1, phi.size(1));
  loop_ub = phi.size(1) - 1;
  for (i = 0; i <= loop_ub; i++) {
    phi[i] = mu * phi[i];
  }
  alpha = 3.1415926535897931 / g / 2.0;
  G.set_size(&n_emlrtRTEI, sp, 1, G.size(1));
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &g_emlrtDCI, (emlrtCTX)sp);
  }
  G.set_size(&n_emlrtRTEI, sp, G.size(0), static_cast<int32_T>(Temp->Space.N));
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &p_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(Temp->Space.N);
  for (i = 0; i < loop_ub; i++) {
    G[i] = 0.0;
  }
  i = static_cast<int32_T>(g + 1.0);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, g + 1.0, mxDOUBLE_CLASS,
                                static_cast<int32_T>(g + 1.0), &d_emlrtRTEI,
                                (emlrtCTX)sp);
  for (b_i = 0; b_i < i; b_i++) {
    mu = 6.2831853071795862 / g * ((static_cast<real_T>(b_i) + 1.0) - 1.0);
    xnum = 0.0;
    xden = 1.0;
    for (last = 0; last < 8; last++) {
      xnum = (xnum + p[last]) * 0.25;
      xden = xden * 0.25 + q[last];
    }
    b_phi.set_size(&o_emlrtRTEI, sp, 1, phi.size(1));
    loop_ub = phi.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_phi[i1] = phi[i1] - mu;
    }
    st.site = &b_emlrtRSI;
    coder::b_abs(&st, b_phi, r);
    b_phi.set_size(&p_emlrtRTEI, sp, 1, r.size(1));
    loop_ub = r.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_phi[i1] = r[i1] / alpha;
    }
    st.site = &b_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    r.set_size(&tb_emlrtRTEI, &b_st, 1, b_phi.size(1));
    loop_ub = b_phi.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1 = b_phi[i1];
      r[i1] = muDoubleScalarPower(varargin_1, 4.0);
    }
    r.set_size(&q_emlrtRTEI, sp, 1, r.size(1));
    loop_ub = r.size(1) - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
      r[i1] = -r[i1];
    }
    st.site = &b_emlrtRSI;
    coder::b_exp(&st, r);
    r.set_size(&r_emlrtRTEI, sp, 1, r.size(1));
    varargin_1 = 4.0 / (2.0 * alpha * ((xnum / xden + 1.0) / 0.25));
    loop_ub = r.size(1) - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
      r[i1] = varargin_1 * r[i1];
    }
    if ((G.size(1) != r.size(1)) && ((G.size(1) != 1) && (r.size(1) != 1))) {
      emlrtDimSizeImpxCheckR2021b(G.size(1), r.size(1), &f_emlrtECI,
                                  (emlrtCTX)sp);
    }
    if (G.size(1) == r.size(1)) {
      loop_ub = G.size(1) - 1;
      G.set_size(&s_emlrtRTEI, sp, 1, G.size(1));
      for (i1 = 0; i1 <= loop_ub; i1++) {
        G[i1] = G[i1] + r[i1];
      }
    } else {
      st.site = &b_emlrtRSI;
      plus(&st, G, r);
    }
    mu += 3.1415926535897931 / g;
    xnum = 0.0;
    xden = 1.0;
    for (last = 0; last < 8; last++) {
      xnum = (xnum + p[last]) * 0.25;
      xden = xden * 0.25 + q[last];
    }
    b_phi.set_size(&t_emlrtRTEI, sp, 1, phi.size(1));
    loop_ub = phi.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_phi[i1] = phi[i1] - mu;
    }
    st.site = &c_emlrtRSI;
    coder::b_abs(&st, b_phi, r);
    b_phi.set_size(&u_emlrtRTEI, sp, 1, r.size(1));
    loop_ub = r.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_phi[i1] = r[i1] / alpha;
    }
    st.site = &c_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    r.set_size(&tb_emlrtRTEI, &b_st, 1, b_phi.size(1));
    loop_ub = b_phi.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargin_1 = b_phi[i1];
      r[i1] = muDoubleScalarPower(varargin_1, 4.0);
    }
    r.set_size(&v_emlrtRTEI, sp, 1, r.size(1));
    loop_ub = r.size(1) - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
      r[i1] = -r[i1];
    }
    st.site = &c_emlrtRSI;
    coder::b_exp(&st, r);
    r.set_size(&w_emlrtRTEI, sp, 1, r.size(1));
    varargin_1 = 4.0 / (2.0 * alpha * ((xnum / xden + 1.0) / 0.25));
    loop_ub = r.size(1) - 1;
    for (i1 = 0; i1 <= loop_ub; i1++) {
      r[i1] = varargin_1 * r[i1];
    }
    if ((G.size(1) != r.size(1)) && ((G.size(1) != 1) && (r.size(1) != 1))) {
      emlrtDimSizeImpxCheckR2021b(G.size(1), r.size(1), &e_emlrtECI,
                                  (emlrtCTX)sp);
    }
    if (G.size(1) == r.size(1)) {
      loop_ub = G.size(1) - 1;
      G.set_size(&x_emlrtRTEI, sp, 1, G.size(1));
      for (i1 = 0; i1 <= loop_ub; i1++) {
        G[i1] = G[i1] - r[i1];
      }
    } else {
      st.site = &c_emlrtRSI;
      minus(&st, G, r);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  st.site = &d_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  coder::b_abs(&b_st, G, phi);
  b_st.site = &r_emlrtRSI;
  c_st.site = &s_emlrtRSI;
  d_st.site = &t_emlrtRSI;
  if (phi.size(1) < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &u_emlrtRSI;
  f_st.site = &v_emlrtRSI;
  last = phi.size(1);
  if (phi.size(1) <= 2) {
    if (phi.size(1) == 1) {
      mu = phi[0];
    } else if ((phi[0] < phi[1]) || (muDoubleScalarIsNaN(phi[0]) &&
                                     (!muDoubleScalarIsNaN(phi[1])))) {
      mu = phi[1];
    } else {
      mu = phi[0];
    }
  } else {
    g_st.site = &x_emlrtRSI;
    if (!muDoubleScalarIsNaN(phi[0])) {
      idx = 1;
    } else {
      boolean_T exitg1;
      idx = 0;
      h_st.site = &y_emlrtRSI;
      if (phi.size(1) > 2147483646) {
        i_st.site = &n_emlrtRSI;
        coder::check_forloop_overflow_error(&i_st);
      }
      loop_ub = 2;
      exitg1 = false;
      while ((!exitg1) && (loop_ub <= last)) {
        if (!muDoubleScalarIsNaN(phi[loop_ub - 1])) {
          idx = loop_ub;
          exitg1 = true;
        } else {
          loop_ub++;
        }
      }
    }
    if (idx == 0) {
      mu = phi[0];
    } else {
      g_st.site = &w_emlrtRSI;
      mu = phi[idx - 1];
      b_i = idx + 1;
      h_st.site = &ab_emlrtRSI;
      if ((idx + 1 <= phi.size(1)) && (phi.size(1) > 2147483646)) {
        i_st.site = &n_emlrtRSI;
        coder::check_forloop_overflow_error(&i_st);
      }
      for (loop_ub = b_i; loop_ub <= last; loop_ub++) {
        varargin_1 = phi[loop_ub - 1];
        if (mu < varargin_1) {
          mu = varargin_1;
        }
      }
    }
  }
  G_theta.contents.set_size(&y_emlrtRTEI, sp, 1, G.size(1));
  loop_ub = G.size(1);
  for (i = 0; i < loop_ub; i++) {
    G_theta.contents[i] = G[i] / mu;
  }
  //     G_theta                             =
  //     cos(Temp.Space.phi*Temp.Eq.g);%+exp(-1i*Temp.Space.phi*Temp.Eq.g);
  // +exp(-1i*Temp.Space.phi*Temp.Eq.g);
  Eq_L.set_size(&ab_emlrtRTEI, sp, 1, Eq_L.size(1));
  varargin_1 = Temp->Space.N / 2.0;
  mu = static_cast<int32_T>(muDoubleScalarFloor(varargin_1));
  if (varargin_1 != mu) {
    emlrtIntegerCheckR2012b(varargin_1, &h_emlrtDCI, (emlrtCTX)sp);
  }
  Eq_L.set_size(&ab_emlrtRTEI, sp, Eq_L.size(0),
                static_cast<int32_T>(varargin_1));
  if (varargin_1 != mu) {
    emlrtIntegerCheckR2012b(varargin_1, &q_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(varargin_1);
  for (i = 0; i < loop_ub; i++) {
    Eq_L[i].re = 0.0;
    Eq_L[i].im = 0.0;
  }
  last = Eq_L.size(1);
  for (i = 0; i < 1309; i++) {
    varargin_1 = Temp->Eq.mode_range[i];
    i1 = static_cast<int32_T>(muDoubleScalarFloor(varargin_1));
    if (varargin_1 != i1) {
      emlrtIntegerCheckR2012b(varargin_1, &r_emlrtDCI, (emlrtCTX)sp);
    }
    idx = static_cast<int32_T>(varargin_1);
    if ((idx < 1) || (idx > last)) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, last, &c_emlrtBCI, (emlrtCTX)sp);
    }
    Eq_L[idx - 1].re = Temp->Eq.omega[i];
    if (idx != i1) {
      emlrtIntegerCheckR2012b(varargin_1, &r_emlrtDCI, (emlrtCTX)sp);
    }
    if (idx > last) {
      emlrtDynamicBoundsCheckR2012b(idx, 1, last, &c_emlrtBCI, (emlrtCTX)sp);
    }
    Eq_L[idx - 1].im = 0.0;
  }
  // -1i*1/2*Temp.Eq.kappa;
  exp_minus_omega.contents.set_size(&bb_emlrtRTEI, sp, 3, Eq_L.size(1));
  loop_ub = 3 * Eq_L.size(1);
  for (i = 0; i < loop_ub; i++) {
    exp_minus_omega.contents[i].re = 0.0;
    exp_minus_omega.contents[i].im = 0.0;
  }
  exp_plus_omega.contents.set_size(&cb_emlrtRTEI, sp, 3, Eq_L.size(1));
  loop_ub = 3 * Eq_L.size(1);
  for (i = 0; i < loop_ub; i++) {
    exp_plus_omega.contents[i].re = 0.0;
    exp_plus_omega.contents[i].im = 0.0;
  }
  k_zero.set_size(&db_emlrtRTEI, sp, 2, k_zero.size(1));
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &i_emlrtDCI, (emlrtCTX)sp);
  }
  k_zero.set_size(&db_emlrtRTEI, sp, k_zero.size(0),
                  static_cast<int32_T>(Temp->Space.N));
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &s_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(Temp->Space.N) << 1;
  for (i = 0; i < loop_ub; i++) {
    k_zero[i].re = 0.0;
    k_zero[i].im = 0.0;
  }
  if (muDoubleScalarIsNaN(Temp->In.N - 1.0)) {
    phi.set_size(&eb_emlrtRTEI, sp, 1, 1);
    phi[0] = rtNaN;
  } else if (Temp->In.N - 1.0 < 0.0) {
    phi.set_size(&eb_emlrtRTEI, sp, 1, 0);
  } else if (muDoubleScalarIsInf(Temp->In.N - 1.0) &&
             (0.0 == Temp->In.N - 1.0)) {
    phi.set_size(&eb_emlrtRTEI, sp, 1, 1);
    phi[0] = rtNaN;
  } else {
    loop_ub = static_cast<int32_T>(muDoubleScalarFloor(Temp->In.N - 1.0));
    phi.set_size(&eb_emlrtRTEI, sp, 1, loop_ub + 1);
    for (i = 0; i <= loop_ub; i++) {
      phi[i] = i;
    }
  }
  st.site = &e_emlrtRSI;
  c_phi.set_size(&fb_emlrtRTEI, &st, 1, phi.size(1));
  loop_ub = phi.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_phi[i] = (phi[i] == Temp->In.Pump.m_p);
  }
  b_st.site = &bb_emlrtRSI;
  coder::eml_find(&b_st, c_phi, ii);
  ind_pump.contents.set_size(&gb_emlrtRTEI, &st, 1, ii.size(1));
  loop_ub = ii.size(1);
  for (i = 0; i < loop_ub; i++) {
    ind_pump.contents[i] = ii[i];
  }
  shift_back.contents.set_size(&hb_emlrtRTEI, sp, 1, Eq_L.size(1));
  loop_ub = Eq_L.size(1);
  for (i = 0; i < loop_ub; i++) {
    xnum = Eq_L[i].im;
    xden = Eq_L[i].re;
    shift_back.contents[i].re = dt_tmp_tmp * (0.0 * xden - (-xnum));
    shift_back.contents[i].im = dt_tmp_tmp * (0.0 * xnum + -xden);
  }
  st.site = &f_emlrtRSI;
  coder::b_exp(&st, shift_back.contents);
  //     mask  = zeros(1,N);
  //    mask(m == Temp.In.Pump.m_p) = 1;
  //   mask(m == 2*Temp.In.Pump.m_p) = 1;
  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  std::copy(&Temp->In.Psi_Start[0], &Temp->In.Psi_Start[2048], &SD->f0.F_e[0]);
  if (Temp->Space.N != b_d) {
    emlrtIntegerCheckR2012b(Temp->Space.N, &b_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(Temp->Space.N);
  Field.contents.set_size(&ib_emlrtRTEI, sp, 1,
                          static_cast<int32_T>(Temp->Space.N));
  for (i = 0; i < loop_ub; i++) {
    Field.contents[i].re = 0.0;
    Field.contents[i].im = 0.0;
  }
  alpha = Temp->In.t_start;
  if (!(Temp->Par.dd >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Par.dd, &k_emlrtDCI, (emlrtCTX)sp);
  }
  varargin_1 = static_cast<int32_T>(muDoubleScalarFloor(Temp->Par.dd));
  if (Temp->Par.dd != varargin_1) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &j_emlrtDCI, (emlrtCTX)sp);
  }
  Sol->Psi.set_size(&jb_emlrtRTEI, sp, static_cast<int32_T>(Temp->Par.dd),
                    1309);
  if (Temp->Par.dd != varargin_1) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &t_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(Temp->Par.dd) * 1309;
  for (i = 0; i < loop_ub; i++) {
    Sol->Psi[i].re = 0.0;
    Sol->Psi[i].im = 0.0;
  }
  //     Sol.Psie = complex(zeros(Temp.Par.dd,Temp.Space.N));
  Sol->t.set_size(&kb_emlrtRTEI, sp, 1, Sol->t.size(1));
  if (Temp->Par.dd != varargin_1) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &l_emlrtDCI, (emlrtCTX)sp);
  }
  Sol->t.set_size(&kb_emlrtRTEI, sp, Sol->t.size(0),
                  static_cast<int32_T>(Temp->Par.dd));
  if (Temp->Par.dd != varargin_1) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &u_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(Temp->Par.dd);
  for (i = 0; i < loop_ub; i++) {
    Sol->t[i].re = 0.0;
    Sol->t[i].im = 0.0;
  }
  if (!(nt >= 0.0)) {
    emlrtNonNegativeCheckR2012b(nt, &n_emlrtDCI, (emlrtCTX)sp);
  }
  if (nt != static_cast<int32_T>(nt)) {
    emlrtIntegerCheckR2012b(nt, &m_emlrtDCI, (emlrtCTX)sp);
  }
  Sol->PsiResolved.set_size(&lb_emlrtRTEI, sp, static_cast<int32_T>(nt), 5);
  if (nt != static_cast<int32_T>(nt)) {
    emlrtIntegerCheckR2012b(nt, &v_emlrtDCI, (emlrtCTX)sp);
  }
  loop_ub = static_cast<int32_T>(nt) * 5;
  for (i = 0; i < loop_ub; i++) {
    Sol->PsiResolved[i].re = 0.0;
    Sol->PsiResolved[i].im = 0.0;
  }
  //     NRF        = round(1/dt/10);
  //     F_Intermid = complex(zeros(NRF,size(Temp.Eq.mode_range,2)));
  //     nii = 0;
  //    phase_pump       = complex(0);
  loop_ub = Eq_L.size(1);
  last = Eq_L.size(1);
  for (b_i = 0; b_i < 3; b_i++) {
    mu = Runge->a[b_i] * dt_tmp_tmp;
    r1.set_size(&mb_emlrtRTEI, sp, 1, Eq_L.size(1));
    for (i = 0; i < loop_ub; i++) {
      xnum = Eq_L[i].im;
      xden = Eq_L[i].re;
      r1[i].re = mu * (0.0 * xden - (-xnum));
      r1[i].im = mu * (0.0 * xnum + -xden);
    }
    st.site = &g_emlrtRSI;
    coder::b_exp(&st, r1);
    iv[0] = 1;
    iv[1] = exp_minus_omega.contents.size(1);
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r1.size(), 2, &d_emlrtECI,
                                  (emlrtCTX)sp);
    idx = r1.size(1);
    for (i = 0; i < idx; i++) {
      exp_minus_omega.contents[b_i + 3 * i] = r1[i];
    }
    r1.set_size(&nb_emlrtRTEI, sp, 1, Eq_L.size(1));
    for (i = 0; i < last; i++) {
      xnum = Eq_L[i].im;
      xden = Eq_L[i].re;
      r1[i].re = mu * (0.0 * xden - xnum);
      r1[i].im = mu * (0.0 * xnum + xden);
    }
    st.site = &h_emlrtRSI;
    coder::b_exp(&st, r1);
    iv[0] = 1;
    iv[1] = exp_plus_omega.contents.size(1);
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r1.size(), 2, &c_emlrtECI,
                                  (emlrtCTX)sp);
    idx = r1.size(1);
    for (i = 0; i < idx; i++) {
      exp_plus_omega.contents[b_i + 3 * i] = r1[i];
    }
    mu += alpha;
    phase_pump.re = mu * (Temp->Eq.Pump.omega_p * 0.0);
    phase_pump.im = mu * -Temp->Eq.Pump.omega_p;
    if (phase_pump.im == 0.0) {
      pump_phase_substep.contents[b_i].re = muDoubleScalarExp(phase_pump.re);
      pump_phase_substep.contents[b_i].im = 0.0;
    } else {
      mu = muDoubleScalarExp(phase_pump.re / 2.0);
      pump_phase_substep.contents[b_i].re =
          mu * (mu * muDoubleScalarCos(phase_pump.im));
      pump_phase_substep.contents[b_i].im =
          mu * (mu * muDoubleScalarSin(phase_pump.im));
    }
    //      pump_phase_substep (i)    = exp(  1i*Eq.L(ind_pump)*(t_zero
    //      +Runge.a(i)*dt)).*exp( -1i*Temp.Eq.Pump.omega_p*(t_zero
    //      +Runge.a(i)*dt));
    //       pump_phase_substep(i)   = exp( 1i*Temp.Eq.Pump.delta*(t_zero
    //       +Runge.a(i)*dt));
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  for (i = 0; i < 1309; i++) {
    b_Temp[i] = (Temp->In.m[i] == Temp->In.Pump.m_p);
  }
  coder::b_eml_find(b_Temp, tmp_data, tmp_size);
  varargin_1 = 2.0 * Temp->In.Pump.m_p;
  b_d = varargin_1 - Temp->In.g;
  for (i = 0; i < 1309; i++) {
    b_Temp[i] = (Temp->In.m[i] == b_d);
  }
  coder::b_eml_find(b_Temp, b_tmp_data, b_tmp_size);
  b_d = varargin_1 + Temp->In.g;
  for (i = 0; i < 1309; i++) {
    b_Temp[i] = (Temp->In.m[i] == b_d);
  }
  coder::b_eml_find(b_Temp, c_tmp_data, c_tmp_size);
  b_d = 3.0 * Temp->In.g;
  mu = varargin_1 - b_d;
  for (i = 0; i < 1309; i++) {
    b_Temp[i] = (Temp->In.m[i] == mu);
  }
  coder::b_eml_find(b_Temp, d_tmp_data, d_tmp_size);
  varargin_1 += b_d;
  for (i = 0; i < 1309; i++) {
    b_Temp[i] = (Temp->In.m[i] == varargin_1);
  }
  coder::b_eml_find(b_Temp, e_tmp_data, e_tmp_size);
  b_i = (((tmp_size[1] + b_tmp_size[1]) + c_tmp_size[1]) + d_tmp_size[1]) +
        e_tmp_size[1];
  loop_ub = tmp_size[1];
  if (0 <= loop_ub - 1) {
    std::copy(&tmp_data[0], &tmp_data[loop_ub], &ind_Save_data[0]);
  }
  loop_ub = b_tmp_size[1];
  for (i = 0; i < loop_ub; i++) {
    ind_Save_data[i + tmp_size[1]] = b_tmp_data[i];
  }
  loop_ub = c_tmp_size[1];
  for (i = 0; i < loop_ub; i++) {
    ind_Save_data[(i + tmp_size[1]) + b_tmp_size[1]] = c_tmp_data[i];
  }
  loop_ub = d_tmp_size[1];
  for (i = 0; i < loop_ub; i++) {
    ind_Save_data[((i + tmp_size[1]) + b_tmp_size[1]) + c_tmp_size[1]] =
        d_tmp_data[i];
  }
  loop_ub = e_tmp_size[1];
  for (i = 0; i < loop_ub; i++) {
    ind_Save_data[(((i + tmp_size[1]) + b_tmp_size[1]) + c_tmp_size[1]) +
                  d_tmp_size[1]] = e_tmp_data[i];
  }
  Sol->mSaved.size[0] = 1;
  Sol->mSaved.size[1] = b_i;
  for (i = 0; i < b_i; i++) {
    Sol->mSaved.data[i] = Temp->In.m[ind_Save_data[i] - 1];
  }
  // 2*tt.Temp.In.Pump.m_p - tt.Temp.In.g);
  //     fftw('dwisdom',[]);
  //     fftw('planner','measure');
  //     Runge_Kuarong_step(F_e,dt,
  //     exp(-1i*Temp.Eq.Pump.omega_p*(t_zero)),d,k_zero); fftinfo =
  //     fftw('dwisdom'); fftw('dwisdom',fftinfo); mode_cut  = zeros(1,1024);
  //     mode_cut(185)  =  1;
  //   mode_cut(326)  =  1;
  //     mode_cut(412)  =  1;
  i = static_cast<int32_T>((nt - 1.0) + 1.0);
  emlrtForLoopVectorCheckR2021a(0.0, 1.0, nt - 1.0, mxDOUBLE_CLASS,
                                static_cast<int32_T>((nt - 1.0) + 1.0),
                                &c_emlrtRTEI, (emlrtCTX)sp);
  if (0 <= static_cast<int32_T>((nt - 1.0) + 1.0) - 1) {
    iv[0] = 1;
    iv[1] = 5;
  }
  if (0 <= i - 1) {
    b_loop_ub = d.size(0) * d.size(1) - 1;
  }
  for (int32_T ni{0}; ni < i; ni++) {
    mu = static_cast<real_T>(ni) * dt_tmp_tmp;
    phase_pump.re = mu * (Temp->Eq.Pump.omega_p * 0.0);
    phase_pump.im = mu * -Temp->Eq.Pump.omega_p;
    if (phase_pump.im == 0.0) {
      varargin_1 = phase_pump.re;
      phase_pump.re = muDoubleScalarExp(varargin_1);
      phase_pump.im = 0.0;
    } else {
      mu = muDoubleScalarExp(phase_pump.re / 2.0);
      varargin_1 = phase_pump.im;
      b_d = phase_pump.im;
      phase_pump.re = mu * (mu * muDoubleScalarCos(varargin_1));
      phase_pump.im = mu * (mu * muDoubleScalarSin(b_d));
    }
    //        phase_pump       = exp(1i*Temp.Eq.Pump.delta*( ni*dt));
    c_d.set_size(&ob_emlrtRTEI, sp, d.size(0), d.size(1));
    for (i1 = 0; i1 <= b_loop_ub; i1++) {
      c_d[i1] = d[i1];
    }
    st.site = &i_emlrtRSI;
    Runge_Kuarong_step(&st, &N, &SD->f0.Temp, &Field, &G_theta, &ind_pump,
                       &exp_plus_omega, &exp_minus_omega, &pump_phase_substep,
                       &b_Runge, &shift_back, SD->f0.F_e, dt_tmp_tmp,
                       phase_pump, c_d, k_zero);
    // ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back
    //         Field =  Get_Field(N/2,F_e);
    r2.set_size(&pb_emlrtRTEI, sp, 1, b_i);
    for (i1 = 0; i1 < b_i; i1++) {
      varargin_1 = Temp->Eq.mode_range[ind_Save_data[i1] - 1];
      b_d = static_cast<int32_T>(muDoubleScalarFloor(varargin_1));
      if (varargin_1 != b_d) {
        emlrtIntegerCheckR2012b(varargin_1, &w_emlrtDCI, (emlrtCTX)sp);
      }
      if ((static_cast<int32_T>(varargin_1) < 1) ||
          (static_cast<int32_T>(varargin_1) > 2048)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(varargin_1), 1, 2048,
                                      &d_emlrtBCI, (emlrtCTX)sp);
      }
      r2[i1].re = SD->f0.F_e[static_cast<int32_T>(varargin_1) - 1].re;
      if (varargin_1 != b_d) {
        emlrtIntegerCheckR2012b(varargin_1, &w_emlrtDCI, (emlrtCTX)sp);
      }
      if ((static_cast<int32_T>(varargin_1) < 1) ||
          (static_cast<int32_T>(varargin_1) > 2048)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(varargin_1), 1, 2048,
                                      &d_emlrtBCI, (emlrtCTX)sp);
      }
      r2[i1].im = SD->f0.F_e[static_cast<int32_T>(varargin_1) - 1].im;
    }
    r1.set_size(&qb_emlrtRTEI, sp, 1, b_i);
    for (i1 = 0; i1 < b_i; i1++) {
      xnum = Temp->Eq.omega[ind_Save_data[i1] - 1];
      r1[i1].re = dt_tmp_tmp * (static_cast<real_T>(ni) * (xnum * 0.0));
      r1[i1].im = dt_tmp_tmp * (static_cast<real_T>(ni) * xnum);
    }
    st.site = &j_emlrtRSI;
    coder::b_exp(&st, r1);
    if ((b_i != r1.size(1)) && ((b_i != 1) && (r1.size(1) != 1))) {
      emlrtDimSizeImpxCheckR2021b(b_i, r1.size(1), &b_emlrtECI, (emlrtCTX)sp);
    }
    if ((ni + 1 < 1) || (ni + 1 > Sol->PsiResolved.size(0))) {
      emlrtDynamicBoundsCheckR2012b(ni + 1, 1, Sol->PsiResolved.size(0),
                                    &b_emlrtBCI, (emlrtCTX)sp);
    }
    if (r2.size(1) == r1.size(1)) {
      loop_ub = r2.size(1) - 1;
      r1.set_size(&pb_emlrtRTEI, sp, 1, r2.size(1));
      for (i1 = 0; i1 <= loop_ub; i1++) {
        xnum = r2[i1].re;
        xden = r1[i1].im;
        mu = r2[i1].im;
        varargin_1 = r1[i1].re;
        r1[i1].re = xnum * varargin_1 - mu * xden;
        r1[i1].im = xnum * xden + mu * varargin_1;
      }
    } else {
      st.site = &j_emlrtRSI;
      times(&st, r1, r2);
    }
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r1.size(), 2, &emlrtECI,
                                  (emlrtCTX)sp);
    for (i1 = 0; i1 < 5; i1++) {
      Sol->PsiResolved[ni + Sol->PsiResolved.size(0) * i1] = r1[i1];
    }
    //         nii = nii +1;
    //         F_Intermid(nii,:) = F_e(Temp.Eq.mode_range);
    //         if mod(ni,NRF) == 0
    //             nii = 0;
    //         end
    if (coder::b_mod(static_cast<real_T>(ni), Temp->Par.s_t / Temp->Par.dt) ==
        0.0) {
      mu = muDoubleScalarRound(static_cast<real_T>(ni) * Temp->Par.dt /
                               Temp->Par.s_t);
      if (mu + 1.0 != static_cast<int32_T>(mu + 1.0)) {
        emlrtIntegerCheckR2012b(mu + 1.0, &emlrtDCI, (emlrtCTX)sp);
      }
      if ((static_cast<int32_T>(mu + 1.0) < 1) ||
          (static_cast<int32_T>(mu + 1.0) > Sol->Psi.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(mu + 1.0), 1,
                                      Sol->Psi.size(0), &emlrtBCI,
                                      (emlrtCTX)sp);
      }
      for (i1 = 0; i1 < 1309; i1++) {
        varargin_1 = Temp->Eq.mode_range[i1];
        idx = static_cast<int32_T>(muDoubleScalarFloor(varargin_1));
        if (varargin_1 != idx) {
          emlrtIntegerCheckR2012b(varargin_1, &x_emlrtDCI, (emlrtCTX)sp);
        }
        last = static_cast<int32_T>(varargin_1);
        if ((last < 1) || (last > 2048)) {
          emlrtDynamicBoundsCheckR2012b(last, 1, 2048, &e_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        Sol->Psi[(static_cast<int32_T>(mu + 1.0) + Sol->Psi.size(0) * i1) - 1]
            .re = SD->f0.F_e[last - 1].re;
        if (last != idx) {
          emlrtIntegerCheckR2012b(varargin_1, &x_emlrtDCI, (emlrtCTX)sp);
        }
        Sol->Psi[(static_cast<int32_T>(mu + 1.0) + Sol->Psi.size(0) * i1) - 1]
            .im = SD->f0.F_e[last - 1].im;
      }
      //             Sol.Psie(ind_s ,:) =
      //             F_e(Temp.Space.N+1:2*Temp.Space.N)/Temp.Space.N;
      if ((static_cast<int32_T>(mu + 1.0) < 1) ||
          (static_cast<int32_T>(mu + 1.0) > Sol->t.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(mu + 1.0), 1,
                                      Sol->t.size(1), &f_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      Sol->t[static_cast<int32_T>(mu + 1.0) - 1].re =
          alpha + dt_tmp_tmp * (static_cast<real_T>(ni) + 1.0);
      if ((static_cast<int32_T>(mu + 1.0) < 1) ||
          (static_cast<int32_T>(mu + 1.0) > Sol->t.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(mu + 1.0), 1,
                                      Sol->t.size(1), &f_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      Sol->t[static_cast<int32_T>(mu + 1.0) - 1].im = 0.0;
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
  Sol->G.set_size(&rb_emlrtRTEI, sp, 1, G_theta.contents.size(1));
  loop_ub = G_theta.contents.size(1);
  for (i = 0; i < loop_ub; i++) {
    Sol->G[i] = G_theta.contents[i];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

// End of code generation (FullField_SingleProgection_dynamics_ForLongSave.cpp)
