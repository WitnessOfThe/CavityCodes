//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Chi_3_LLE_Runge_Kuarong.cpp
//
//  Code generation for function 'Chi_3_LLE_Runge_Kuarong'
//


// Include files
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"
#include "Chi_3_LLE_Runge_Kuarong_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "fft.h"
#include "ifft.h"
#include "nullAssignment.h"
#include "ref.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo emlrtRSI = { 41,    // lineNo
  "Chi_3_LLE_Runge_Kuarong",           // fcnName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pathName 
};

static emlrtRSInfo b_emlrtRSI = { 40,  // lineNo
  "Chi_3_LLE_Runge_Kuarong",           // fcnName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pathName 
};

static emlrtRSInfo c_emlrtRSI = { 38,  // lineNo
  "Chi_3_LLE_Runge_Kuarong",           // fcnName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pathName 
};

static emlrtRSInfo d_emlrtRSI = { 31,  // lineNo
  "Chi_3_LLE_Runge_Kuarong",           // fcnName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pathName 
};

static emlrtRSInfo e_emlrtRSI = { 3,   // lineNo
  "Chi_3_LLE_Runge_Kuarong",           // fcnName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pathName 
};

static emlrtRSInfo f_emlrtRSI = { 7,   // lineNo
  "ref/ref",                           // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\ref.m"// pathName 
};

static emlrtRSInfo g_emlrtRSI = { 56,  // lineNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fcnName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pathName 
};

static emlrtRSInfo h_emlrtRSI = { 70,  // lineNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fcnName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pathName 
};

static emlrtRSInfo i_emlrtRSI = { 90,  // lineNo
  "Chi_3_LLE_Runge_Kuarong/Chi_3_LLE_Kuar_ins",// fcnName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pathName 
};

static emlrtRSInfo j_emlrtRSI = { 94,  // lineNo
  "Chi_3_LLE_Runge_Kuarong/Chi_3_LLE_Kuar_ins",// fcnName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pathName 
};

static emlrtRSInfo bb_emlrtRSI = { 13, // lineNo
  "nullAssignment",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo cb_emlrtRSI = { 17, // lineNo
  "nullAssignment",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo db_emlrtRSI = { 167,// lineNo
  "onearg_null_assignment",            // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo eb_emlrtRSI = { 169,// lineNo
  "onearg_null_assignment",            // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo fb_emlrtRSI = { 172,// lineNo
  "onearg_null_assignment",            // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRTEInfo emlrtRTEI = { 184, // lineNo
  9,                                   // colNo
  "onearg_null_assignment",            // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pName 
};

static emlrtRTEInfo b_emlrtRTEI = { 85,// lineNo
  27,                                  // colNo
  "validate_inputs",                   // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pName 
};

static emlrtBCInfo emlrtBCI = { -1,    // iFirst
  -1,                                  // iLast
  80,                                  // lineNo
  90,                                  // colNo
  "d",                                 // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo c_emlrtRTEI = { 76,// lineNo
  18,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pName 
};

static emlrtBCInfo b_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  70,                                  // lineNo
  15,                                  // colNo
  "d",                                 // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo c_emlrtBCI = { 1,   // iFirst
  3,                                   // iLast
  70,                                  // lineNo
  66,                                  // colNo
  "exp_plus_omega",                    // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo d_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  64,                                  // lineNo
  105,                                 // colNo
  "d",                                 // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo d_emlrtRTEI = { 60,// lineNo
  22,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pName 
};

static emlrtRTEInfo e_emlrtRTEI = { 58,// lineNo
  18,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pName 
};

static emlrtBCInfo e_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  56,                                  // lineNo
  11,                                  // colNo
  "d",                                 // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtRTEInfo f_emlrtRTEI = { 29,// lineNo
  14,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pName 
};

static emlrtBCInfo f_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  38,                                  // lineNo
  41,                                  // colNo
  "Sol.Psi",                           // aName
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo g_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  35,                                  // lineNo
  21,                                  // colNo
  "Sol.Psi",                           // aName
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo emlrtDCI = { 35,    // lineNo
  21,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo b_emlrtDCI = { 3,   // lineNo
  35,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo c_emlrtDCI = { 3,   // lineNo
  35,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo d_emlrtDCI = { 25,  // lineNo
  29,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo e_emlrtDCI = { 25,  // lineNo
  29,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  4                                    // checkKind
};

static emlrtDCInfo f_emlrtDCI = { 26,  // lineNo
  31,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo g_emlrtDCI = { 3,   // lineNo
  5,                                   // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo h_emlrtDCI = { 25,  // lineNo
  5,                                   // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo i_emlrtDCI = { 26,  // lineNo
  5,                                   // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo h_emlrtBCI = { 1,   // iFirst
  3,                                   // iLast
  78,                                  // lineNo
  17,                                  // colNo
  "Runge.c",                           // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo i_emlrtBCI = { 1,   // iFirst
  3,                                   // iLast
  62,                                  // lineNo
  20,                                  // colNo
  "Runge.b",                           // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo j_emlrtBCI = { 1,   // iFirst
  1024,                                // iLast
  86,                                  // lineNo
  12,                                  // colNo
  "E_f",                               // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  3                                    // checkKind
};

static emlrtDCInfo j_emlrtDCI = { 86,  // lineNo
  12,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo k_emlrtBCI = { 1,   // iFirst
  1024,                                // iLast
  80,                                  // lineNo
  50,                                  // colNo
  "E_f",                               // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo k_emlrtDCI = { 80,  // lineNo
  50,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo l_emlrtDCI = { 80,  // lineNo
  93,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo l_emlrtBCI = { 1,   // iFirst
  1024,                                // iLast
  64,                                  // lineNo
  62,                                  // colNo
  "E_temp",                            // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo m_emlrtDCI = { 64,  // lineNo
  62,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo n_emlrtDCI = { 64,  // lineNo
  108,                                 // colNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo m_emlrtBCI = { 1,   // iFirst
  1024,                                // iLast
  80,                                  // lineNo
  17,                                  // colNo
  "E_f",                               // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  3                                    // checkKind
};

static emlrtDCInfo o_emlrtDCI = { 80,  // lineNo
  17,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo n_emlrtBCI = { 1,   // iFirst
  1024,                                // iLast
  64,                                  // lineNo
  21,                                  // colNo
  "E_temp",                            // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  3                                    // checkKind
};

static emlrtDCInfo p_emlrtDCI = { 64,  // lineNo
  21,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtDCInfo q_emlrtDCI = { 35,  // lineNo
  37,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtBCInfo o_emlrtBCI = { 1,   // iFirst
  1024,                                // iLast
  35,                                  // lineNo
  37,                                  // colNo
  "F_e",                               // aName
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo p_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  36,                                  // lineNo
  13,                                  // colNo
  "Sol.t",                             // aName
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo q_emlrtBCI = { 1,   // iFirst
  1024,                                // iLast
  86,                                  // lineNo
  38,                                  // colNo
  "shift_back",                        // aName
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  0                                    // checkKind
};

static emlrtDCInfo r_emlrtDCI = { 86,  // lineNo
  38,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong/Runge_Kuarong_step",// fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m",// pName 
  1                                    // checkKind
};

static emlrtRTEInfo j_emlrtRTEI = { 3, // lineNo
  5,                                   // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pName 
};

static emlrtRTEInfo k_emlrtRTEI = { 25,// lineNo
  5,                                   // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pName 
};

static emlrtRTEInfo l_emlrtRTEI = { 26,// lineNo
  5,                                   // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pName 
};

static emlrtRTEInfo m_emlrtRTEI = { 31,// lineNo
  61,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pName 
};

static emlrtRTEInfo n_emlrtRTEI = { 40,// lineNo
  29,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pName 
};

static emlrtRTEInfo o_emlrtRTEI = { 41,// lineNo
  27,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pName 
};

static emlrtRTEInfo p_emlrtRTEI = { 41,// lineNo
  21,                                  // colNo
  "Chi_3_LLE_Runge_Kuarong",           // fName
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Problems\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_Runge_Kuarong.m"// pName 
};

// Function Definitions
void Chi_3_LLE_Runge_Kuarong(const emlrtStack *sp, const struct0_T *Temp, real_T,
  const struct5_T *Runge, struct6_T *Sol)
{
  coder::captured_var exp_minus_omega;
  coder::captured_var exp_plus_omega;
  coder::array<creal_T, 2U> c_d;
  coder::array<cuint8_T, 2U> b_d;
  coder::array<int32_T, 2U> idx;
  coder::array<boolean_T, 2U> b;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  creal_T E_temp[1024];
  creal_T F_e[1024];
  creal_T Psi[1024];
  creal_T b_F_e[1024];
  creal_T dcv[1024];
  creal_T b_E_temp[600];
  real_T z1[599];
  real_T Temp_re;
  real_T d;
  real_T d1;
  real_T dt;
  real_T im;
  real_T nt;
  real_T q;
  real_T r;
  real_T re;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T ni;
  int32_T nxout;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &e_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  st.site = &e_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  st.site = &e_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  st.site = &e_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  st.site = &e_emlrtRSI;
  b_st.site = &f_emlrtRSI;
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &c_emlrtDCI, sp);
  }

  d = static_cast<int32_T>(muDoubleScalarFloor(Runge->s));
  if (Runge->s != d) {
    emlrtIntegerCheckR2012b(Runge->s, &b_emlrtDCI, sp);
  }

  b_d.set_size((&j_emlrtRTEI), sp, (static_cast<int32_T>(Runge->s)), 1024);
  if (Runge->s != d) {
    emlrtIntegerCheckR2012b(Runge->s, &g_emlrtDCI, sp);
  }

  nxout = static_cast<int32_T>(Runge->s) << 10;
  for (i = 0; i < nxout; i++) {
    b_d[i].re = 0U;
    b_d[i].im = 0U;
  }

  dt = Temp->Par.dt;
  nt = Temp->Par.T / Temp->Par.dt;

  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  for (nxout = 0; nxout < 3; nxout++) {
    q = Runge->a[nxout];
    for (k = 0; k < 1024; k++) {
      d = Temp->Eq.L[k].re;
      d1 = Temp->Eq.L[k].im;
      re = dt * (q * (0.0 * d - (-d1)));
      im = dt * (q * (0.0 * d1 + -d));
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

      i = nxout + 3 * k;
      exp_minus_omega.contents[i].re = re;
      exp_minus_omega.contents[i].im = im;
      re = dt * (q * (0.0 * d - d1));
      im = dt * (q * (0.0 * d1 + d));
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

      exp_plus_omega.contents[i].re = re;
      exp_plus_omega.contents[i].im = im;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  for (k = 0; k < 1024; k++) {
    re = Temp->Par.dt * (0.0 * Temp->Eq.L[k].re - (-Temp->Eq.L[k].im));
    im = Temp->Par.dt * (0.0 * Temp->Eq.L[k].im + -Temp->Eq.L[k].re);
    dcv[k].re = re;
    dcv[k].im = im;
    if (im == 0.0) {
      dcv[k].re = muDoubleScalarExp(re);
      dcv[k].im = 0.0;
    } else if (muDoubleScalarIsInf(im) && muDoubleScalarIsInf(re) && (re < 0.0))
    {
      dcv[k].re = 0.0;
      dcv[k].im = 0.0;
    } else {
      r = muDoubleScalarExp(re / 2.0);
      dcv[k].re = r * (r * muDoubleScalarCos(im));
      dcv[k].im = r * (r * muDoubleScalarSin(im));
    }

    F_e[k] = Temp->In.Psi_Start[k];
  }

  if (!(Temp->Par.dd >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Temp->Par.dd, &e_emlrtDCI, sp);
  }

  d = static_cast<int32_T>(muDoubleScalarFloor(Temp->Par.dd));
  if (Temp->Par.dd != d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &d_emlrtDCI, sp);
  }

  Sol->Psi.set_size((&k_emlrtRTEI), sp, (static_cast<int32_T>(Temp->Par.dd)),
                    600);
  if (Temp->Par.dd != d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &h_emlrtDCI, sp);
  }

  nxout = static_cast<int32_T>(Temp->Par.dd) * 600;
  for (i = 0; i < nxout; i++) {
    Sol->Psi[i].re = 0.0;
    Sol->Psi[i].im = 0.0;
  }

  Sol->t.set_size((&l_emlrtRTEI), sp, 1, Sol->t.size(1));
  if (Temp->Par.dd != d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &f_emlrtDCI, sp);
  }

  Sol->t.set_size((&l_emlrtRTEI), sp, Sol->t.size(0), (static_cast<int32_T>
    (Temp->Par.dd)));
  if (Temp->Par.dd != d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &i_emlrtDCI, sp);
  }

  nxout = static_cast<int32_T>(Temp->Par.dd);
  for (i = 0; i < nxout; i++) {
    Sol->t[i].re = 0.0;
    Sol->t[i].im = 0.0;
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nt, mxDOUBLE_CLASS,
    static_cast<int32_T>(nt), &f_emlrtRTEI, sp);
  ni = 0;
  exitg1 = false;
  while ((!exitg1) && (ni <= static_cast<int32_T>(nt) - 1)) {
    int32_T k0;
    int32_T nxin;
    boolean_T guard1 = false;
    boolean_T rEQ0;
    st.site = &d_emlrtRSI;
    c_d.set_size((&m_emlrtRTEI), (&st), b_d.size(0), 1024);
    nxout = b_d.size(0) * b_d.size(1);
    for (i = 0; i < nxout; i++) {
      c_d[i].re = b_d[i].re;
      c_d[i].im = b_d[i].im;
    }

    // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% 
    memcpy(&E_temp[0], &F_e[0], 1024U * sizeof(creal_T));
    if (1 > b_d.size(0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, b_d.size(0), &e_emlrtBCI, &st);
    }

    b_st.site = &g_emlrtRSI;
    for (i = 0; i < 1024; i++) {
      d = F_e[i].re;
      d1 = F_e[i].im;
      Temp_re = exp_minus_omega.contents[3 * i].re;
      q = exp_minus_omega.contents[3 * i].im;
      b_F_e[i].re = d * Temp_re - d1 * q;
      b_F_e[i].im = d * q + d1 * Temp_re;
    }

    c_st.site = &i_emlrtRSI;
    coder::ifft(b_F_e, Psi);
    for (k = 0; k < 1024; k++) {
      d = Psi[k].re;
      d1 = Psi[k].im;
      Temp_re = muDoubleScalarHypot(d, d1);
      Temp_re *= Temp_re;
      b_F_e[k].re = Temp_re * d;
      b_F_e[k].im = Temp_re * d1;
    }

    c_st.site = &j_emlrtRSI;
    coder::fft(b_F_e, Psi);
    for (i = 0; i < 1024; i++) {
      d = exp_plus_omega.contents[3 * i].re;
      d1 = exp_plus_omega.contents[3 * i].im;
      re = 0.0 * d - d1;
      im = 0.0 * d1 + d;
      d = Temp->Eq.gamma_Kerr[i];
      Temp_re = d * Psi[i].re;
      q = d * Psi[i].im;
      Psi[i].re = re * Temp_re - im * q;
      Psi[i].im = re * q + im * Temp_re;
    }

    d = 1024.0 * Temp->Eq.h;
    Psi[0].re += (0.0 * exp_plus_omega.contents[0].re - exp_plus_omega.contents
                  [0].im) * d;
    Psi[0].im += (0.0 * exp_plus_omega.contents[0].im + exp_plus_omega.contents
                  [0].re) * d;
    for (i = 0; i < 1024; i++) {
      c_d[c_d.size(0) * i] = Psi[i];
    }

    i = static_cast<int32_T>(Runge->s + -1.0);
    emlrtForLoopVectorCheckR2012b(2.0, 1.0, Runge->s, mxDOUBLE_CLASS,
      static_cast<int32_T>(Runge->s + -1.0), &e_emlrtRTEI, &st);
    if (0 <= i - 1) {
      i1 = static_cast<int32_T>(Runge->s - 1.0);
    }

    for (int32_T i2 = 0; i2 < i; i2++) {
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
        static_cast<int32_T>(Runge->s - 1.0), &d_emlrtRTEI, &st);
      for (nxin = 0; nxin < i1; nxin++) {
        if ((static_cast<int32_T>(i2 + 2U) < 1) || (static_cast<int32_T>(i2 + 2U)
             > 3)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(i2 + 2U), 1, 3,
            &i_emlrtBCI, &st);
        }

        if ((static_cast<int32_T>(nxin + 1U) < 1) || (static_cast<int32_T>(nxin
              + 1U) > 3)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nxin + 1U), 1, 3,
            &i_emlrtBCI, &st);
        }

        d1 = Runge->b[(i2 + 3 * nxin) + 1];
        if (d1 != 0.0) {
          q = dt * d1;
          if ((static_cast<int32_T>(nxin + 1U) < 1) || (static_cast<int32_T>
               (nxin + 1U) > c_d.size(0))) {
            emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nxin + 1U), 1,
              c_d.size(0), &d_emlrtBCI, &st);
          }

          for (k = 0; k < 600; k++) {
            d1 = Temp->Eq.mode_range[k];
            nxout = static_cast<int32_T>(muDoubleScalarFloor(d1));
            if (d1 != nxout) {
              emlrtIntegerCheckR2012b(d1, &m_emlrtDCI, &st);
            }

            k0 = static_cast<int32_T>(d1);
            if ((k0 < 1) || (k0 > 1024)) {
              emlrtDynamicBoundsCheckR2012b(k0, 1, 1024, &l_emlrtBCI, &st);
            }

            if (k0 != nxout) {
              emlrtIntegerCheckR2012b(d1, &n_emlrtDCI, &st);
            }

            b_E_temp[k].re = E_temp[k0 - 1].re + q * c_d[nxin + c_d.size(0) *
              (k0 - 1)].re;
            if (k0 != nxout) {
              emlrtIntegerCheckR2012b(d1, &m_emlrtDCI, &st);
            }

            b_E_temp[k].im = E_temp[k0 - 1].im + q * c_d[nxin + c_d.size(0) *
              (k0 - 1)].im;
          }

          for (k = 0; k < 600; k++) {
            d1 = Temp->Eq.mode_range[k];
            nxout = static_cast<int32_T>(muDoubleScalarFloor(d1));
            if (d1 != nxout) {
              emlrtIntegerCheckR2012b(d1, &p_emlrtDCI, &st);
            }

            k0 = static_cast<int32_T>(d1);
            if ((k0 < 1) || (k0 > 1024)) {
              emlrtDynamicBoundsCheckR2012b(k0, 1, 1024, &n_emlrtBCI, &st);
            }

            E_temp[k0 - 1].re = b_E_temp[k].re;
            if (k0 != nxout) {
              emlrtIntegerCheckR2012b(d1, &p_emlrtDCI, &st);
            }

            E_temp[k0 - 1].im = b_E_temp[k].im;
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      b_st.site = &h_emlrtRSI;
      if ((i2 + 2 < 1) || (i2 + 2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(i2 + 2, 1, 3, &c_emlrtBCI, &b_st);
      }

      for (k = 0; k < 1024; k++) {
        nxout = (i2 + 3 * k) + 1;
        d1 = E_temp[k].re;
        Temp_re = E_temp[k].im;
        im = d1 * exp_minus_omega.contents[nxout].im + Temp_re *
          exp_minus_omega.contents[nxout].re;
        d1 = d1 * exp_minus_omega.contents[nxout].re - Temp_re *
          exp_minus_omega.contents[nxout].im;
        E_temp[k].re = d1;
        E_temp[k].im = im;
      }

      c_st.site = &i_emlrtRSI;
      coder::ifft(E_temp, Psi);
      for (k = 0; k < 1024; k++) {
        d1 = Psi[k].re;
        Temp_re = Psi[k].im;
        q = muDoubleScalarHypot(d1, Temp_re);
        q *= q;
        b_F_e[k].re = q * d1;
        b_F_e[k].im = q * Temp_re;
      }

      c_st.site = &j_emlrtRSI;
      coder::fft(b_F_e, Psi);
      for (k = 0; k < 1024; k++) {
        nxout = (i2 + 3 * k) + 1;
        re = 0.0 * exp_plus_omega.contents[nxout].re -
          exp_plus_omega.contents[nxout].im;
        im = 0.0 * exp_plus_omega.contents[nxout].im +
          exp_plus_omega.contents[nxout].re;
        d1 = Temp->Eq.gamma_Kerr[k];
        Temp_re = d1 * Psi[k].re;
        q = d1 * Psi[k].im;
        Psi[k].re = re * Temp_re - im * q;
        Psi[k].im = re * q + im * Temp_re;
      }

      d1 = exp_plus_omega.contents[i2 + 1].re;
      Temp_re = exp_plus_omega.contents[i2 + 1].im;
      Psi[0].re += (0.0 * d1 - Temp_re) * d;
      Psi[0].im += (0.0 * Temp_re + d1) * d;
      if ((static_cast<int32_T>(i2 + 2U) < 1) || (static_cast<int32_T>(i2 + 2U) >
           c_d.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(i2 + 2U), 1, c_d.size
          (0), &b_emlrtBCI, &st);
      }

      for (k = 0; k < 1024; k++) {
        c_d[(i2 + c_d.size(0) * k) + 1] = Psi[k];
        E_temp[k] = F_e[k];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    i = static_cast<int32_T>(Runge->s);
    emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s, mxDOUBLE_CLASS,
      static_cast<int32_T>(Runge->s), &c_emlrtRTEI, &st);
    for (nxin = 0; nxin < i; nxin++) {
      if ((static_cast<int32_T>(nxin + 1U) < 1) || (static_cast<int32_T>(nxin +
            1U) > 3)) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nxin + 1U), 1, 3,
          &h_emlrtBCI, &st);
      }

      d = Runge->c[nxin];
      if (d != 0.0) {
        q = dt * d;
        if ((static_cast<int32_T>(nxin + 1U) < 1) || (static_cast<int32_T>(nxin
              + 1U) > c_d.size(0))) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(nxin + 1U), 1,
            c_d.size(0), &emlrtBCI, &st);
        }

        for (k = 0; k < 600; k++) {
          d = Temp->Eq.mode_range[k];
          nxout = static_cast<int32_T>(muDoubleScalarFloor(d));
          if (d != nxout) {
            emlrtIntegerCheckR2012b(d, &k_emlrtDCI, &st);
          }

          k0 = static_cast<int32_T>(d);
          if ((k0 < 1) || (k0 > 1024)) {
            emlrtDynamicBoundsCheckR2012b(k0, 1, 1024, &k_emlrtBCI, &st);
          }

          if (k0 != nxout) {
            emlrtIntegerCheckR2012b(d, &l_emlrtDCI, &st);
          }

          b_E_temp[k].re = F_e[k0 - 1].re + q * c_d[nxin + c_d.size(0) * (k0 - 1)]
            .re;
          if (k0 != nxout) {
            emlrtIntegerCheckR2012b(d, &k_emlrtDCI, &st);
          }

          b_E_temp[k].im = F_e[k0 - 1].im + q * c_d[nxin + c_d.size(0) * (k0 - 1)]
            .im;
        }

        for (k = 0; k < 600; k++) {
          d = Temp->Eq.mode_range[k];
          nxout = static_cast<int32_T>(muDoubleScalarFloor(d));
          if (d != nxout) {
            emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
          }

          k0 = static_cast<int32_T>(d);
          if ((k0 < 1) || (k0 > 1024)) {
            emlrtDynamicBoundsCheckR2012b(k0, 1, 1024, &m_emlrtBCI, &st);
          }

          F_e[k0 - 1].re = b_E_temp[k].re;
          if (k0 != nxout) {
            emlrtIntegerCheckR2012b(d, &o_emlrtDCI, &st);
          }

          F_e[k0 - 1].im = b_E_temp[k].im;
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    for (i = 0; i < 600; i++) {
      d = Temp->Eq.mode_range[i];
      k = static_cast<int32_T>(muDoubleScalarFloor(d));
      if (d != k) {
        emlrtIntegerCheckR2012b(d, &r_emlrtDCI, &st);
      }

      nxout = static_cast<int32_T>(d);
      if ((nxout < 1) || (nxout > 1024)) {
        emlrtDynamicBoundsCheckR2012b(nxout, 1, 1024, &q_emlrtBCI, &st);
      }

      if (nxout != k) {
        emlrtIntegerCheckR2012b(d, &r_emlrtDCI, &st);
      }

      b_E_temp[i].re = dcv[nxout - 1].re * F_e[nxout - 1].re - dcv[nxout - 1].im
        * F_e[nxout - 1].im;
      if (nxout != k) {
        emlrtIntegerCheckR2012b(d, &r_emlrtDCI, &st);
      }

      b_E_temp[i].im = dcv[nxout - 1].re * F_e[nxout - 1].im + dcv[nxout - 1].im
        * F_e[nxout - 1].re;
    }

    for (i = 0; i < 600; i++) {
      d = Temp->Eq.mode_range[i];
      k = static_cast<int32_T>(muDoubleScalarFloor(d));
      if (d != k) {
        emlrtIntegerCheckR2012b(d, &j_emlrtDCI, &st);
      }

      nxout = static_cast<int32_T>(d);
      if ((nxout < 1) || (nxout > 1024)) {
        emlrtDynamicBoundsCheckR2012b(nxout, 1, 1024, &j_emlrtBCI, &st);
      }

      F_e[nxout - 1].re = b_E_temp[i].re;
      if (nxout != k) {
        emlrtIntegerCheckR2012b(d, &j_emlrtDCI, &st);
      }

      F_e[nxout - 1].im = b_E_temp[i].im;
    }

    // ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back
    Temp_re = Temp->Par.s_t / Temp->Par.dt;
    r = static_cast<real_T>(ni) + 1.0;
    if (!(Temp_re == 0.0)) {
      if (muDoubleScalarIsNaN(Temp_re)) {
        r = rtNaN;
      } else if (muDoubleScalarIsInf(Temp_re)) {
        if (Temp_re < 0.0) {
          r = Temp_re;
        }
      } else {
        r = muDoubleScalarRem(static_cast<real_T>(ni) + 1.0, Temp_re);
        rEQ0 = (r == 0.0);
        if ((!rEQ0) && (Temp_re > muDoubleScalarFloor(Temp_re))) {
          q = muDoubleScalarAbs((static_cast<real_T>(ni) + 1.0) / Temp_re);
          rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
                   2.2204460492503131E-16 * q);
        }

        if (rEQ0) {
          r = Temp_re * 0.0;
        } else {
          if (Temp_re < 0.0) {
            r += Temp_re;
          }
        }
      }
    }

    guard1 = false;
    if (r == 0.0) {
      re = (static_cast<real_T>(ni) + 1.0) * Temp->Par.dt;
      r = muDoubleScalarRound(re / Temp->Par.s_t);
      for (i = 0; i < 600; i++) {
        d = Temp->Eq.mode_range[i];
        if (d != static_cast<int32_T>(muDoubleScalarFloor(d))) {
          emlrtIntegerCheckR2012b(d, &q_emlrtDCI, sp);
        }

        if ((static_cast<int32_T>(d) < 1) || (static_cast<int32_T>(d) > 1024)) {
          emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(d), 1, 1024,
            &o_emlrtBCI, sp);
        }
      }

      if (r != static_cast<int32_T>(r)) {
        emlrtIntegerCheckR2012b(r, &emlrtDCI, sp);
      }

      if ((static_cast<int32_T>(r) < 1) || (static_cast<int32_T>(r) >
           Sol->Psi.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(r), 1, Sol->Psi.size
          (0), &g_emlrtBCI, sp);
      }

      for (i = 0; i < 600; i++) {
        nxout = static_cast<int32_T>(Temp->Eq.mode_range[i]) - 1;
        q = F_e[nxout].re;
        Temp_re = F_e[nxout].im;
        if (Temp_re == 0.0) {
          Sol->Psi[(static_cast<int32_T>(r) + Sol->Psi.size(0) * i) - 1].re = q /
            Temp->Space.N;
          Sol->Psi[(static_cast<int32_T>(r) + Sol->Psi.size(0) * i) - 1].im =
            0.0;
        } else if (q == 0.0) {
          Sol->Psi[(static_cast<int32_T>(r) + Sol->Psi.size(0) * i) - 1].re =
            0.0;
          Sol->Psi[(static_cast<int32_T>(r) + Sol->Psi.size(0) * i) - 1].im =
            Temp_re / Temp->Space.N;
        } else {
          Sol->Psi[(static_cast<int32_T>(r) + Sol->Psi.size(0) * i) - 1].re = q /
            Temp->Space.N;
          Sol->Psi[(static_cast<int32_T>(r) + Sol->Psi.size(0) * i) - 1].im =
            Temp_re / Temp->Space.N;
        }
      }

      if ((static_cast<int32_T>(r) < 1) || (static_cast<int32_T>(r) >
           Sol->t.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(r), 1, Sol->t.size(1),
          &p_emlrtBCI, sp);
      }

      Sol->t[static_cast<int32_T>(r) - 1].re = re;
      if ((static_cast<int32_T>(r) < 1) || (static_cast<int32_T>(r) >
           Sol->t.size(1))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(r), 1, Sol->t.size(1),
          &p_emlrtBCI, sp);
      }

      Sol->t[static_cast<int32_T>(r) - 1].im = 0.0;
      if ((static_cast<int32_T>(r) < 1) || (static_cast<int32_T>(r) >
           Sol->Psi.size(0))) {
        emlrtDynamicBoundsCheckR2012b(static_cast<int32_T>(r), 1, Sol->Psi.size
          (0), &f_emlrtBCI, sp);
      }

      for (k = 0; k < 599; k++) {
        d = muDoubleScalarHypot(Sol->Psi[(static_cast<int32_T>(r) +
          Sol->Psi.size(0) * (k + 1)) - 1].re, Sol->Psi[(static_cast<int32_T>(r)
          + Sol->Psi.size(0) * (k + 1)) - 1].im);
        z1[k] = d * d;
      }

      Temp_re = z1[0];
      for (k = 0; k < 598; k++) {
        Temp_re += z1[k + 1];
      }

      st.site = &c_emlrtRSI;
      if ((10.0 * muDoubleScalarLog10(Temp_re) <= -50.0) && (muDoubleScalarRem(r,
            2.0) == 1.0)) {
        boolean_T exitg2;
        idx.set_size((&n_emlrtRTEI), sp, 1, (Sol->Psi.size(0) -
          static_cast<int32_T>(r)));
        nxout = Sol->Psi.size(0) - static_cast<int32_T>(r);
        for (i = 0; i < nxout; i++) {
          idx[i] = (static_cast<int32_T>(r) + i) + 1;
        }

        st.site = &b_emlrtRSI;
        coder::internal::nullAssignment(&st, Sol->Psi, idx);
        st.site = &emlrtRSI;
        ni = Sol->t.size(1);
        idx.set_size((&o_emlrtRTEI), (&st), 1, (Sol->t.size(1) -
          static_cast<int32_T>(r)));
        nxout = Sol->t.size(1) - static_cast<int32_T>(r);
        for (i = 0; i < nxout; i++) {
          idx[i] = (static_cast<int32_T>(r) + i) + 1;
        }

        b_st.site = &bb_emlrtRSI;
        rEQ0 = true;
        k = 0;
        exitg2 = false;
        while ((!exitg2) && (k <= idx.size(1) - 1)) {
          if (idx[k] > Sol->t.size(1)) {
            rEQ0 = false;
            exitg2 = true;
          } else {
            k++;
          }
        }

        if (!rEQ0) {
          emlrtErrorWithMessageIdR2018a(&b_st, &b_emlrtRTEI,
            "MATLAB:subsdeldimmismatch", "MATLAB:subsdeldimmismatch", 0);
        }

        b_st.site = &cb_emlrtRSI;
        nxin = Sol->t.size(1);
        idx.set_size((&o_emlrtRTEI), (&b_st), 1, (Sol->t.size(1) -
          static_cast<int32_T>(r)));
        nxout = Sol->t.size(1) - static_cast<int32_T>(r);
        for (i = 0; i < nxout; i++) {
          idx[i] = (static_cast<int32_T>(r) + i) + 1;
        }

        c_st.site = &db_emlrtRSI;
        coder::internal::make_bitarray(&c_st, Sol->t.size(1), idx, b);
        c_st.site = &eb_emlrtRSI;
        nxout = Sol->t.size(1) - coder::internal::num_true(&c_st, b);
        k0 = -1;
        c_st.site = &fb_emlrtRSI;
        if ((1 <= Sol->t.size(1)) && (Sol->t.size(1) > 2147483646)) {
          d_st.site = &y_emlrtRSI;
          coder::check_forloop_overflow_error(&d_st);
        }

        for (k = 0; k < nxin; k++) {
          if ((k + 1 > b.size(1)) || (!b[k])) {
            k0++;
            Sol->t[k0] = Sol->t[k];
          }
        }

        if (nxout > ni) {
          emlrtErrorWithMessageIdR2018a(&b_st, &emlrtRTEI,
            "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed",
            0);
        }

        if (1 > nxout) {
          nxout = 0;
        }

        Sol->t.set_size((&p_emlrtRTEI), (&b_st), Sol->t.size(0), nxout);
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

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (Chi_3_LLE_Runge_Kuarong.cpp)
