/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi_3_LLE_Runge_Kuarong_with_Scan.c
 *
 * Code generation for function 'Chi_3_LLE_Runge_Kuarong_with_Scan'
 *
 */

/* Include files */
#include "Chi_3_LLE_Runge_Kuarong_with_Scan.h"
#include "Chi_3_LLE_Runge_Kuarong_with_Scan_data.h"
#include "Chi_3_LLE_Runge_Kuarong_with_Scan_emxutil.h"
#include "Chi_3_LLE_Runge_Kuarong_with_Scan_types.h"
#include "fft.h"
#include "ifft.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 31,    /* lineNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m"          /* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 3,   /* lineNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m"          /* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 70,  /* lineNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fcnName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m"          /* pathName */
};

static emlrtDCInfo emlrtDCI = { 35,    /* lineNo */
  21,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  35,                                  /* lineNo */
  21,                                  /* colNo */
  "Sol.Psi",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  80,                                  /* lineNo */
  90,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo emlrtRTEI = { 76,  /* lineNo */
  18,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m"          /* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  70,                                  /* lineNo */
  15,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  70,                                  /* lineNo */
  66,                                  /* colNo */
  "exp_plus_omega",                    /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  64,                                  /* lineNo */
  105,                                 /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo b_emlrtRTEI = { 60,/* lineNo */
  22,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m"          /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 58,/* lineNo */
  18,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m"          /* pName */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  56,                                  /* lineNo */
  11,                                  /* colNo */
  "d",                                 /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = { 29,/* lineNo */
  14,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m"          /* pName */
};

static emlrtDCInfo b_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = { 3,   /* lineNo */
  35,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = { 25,  /* lineNo */
  29,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = { 25,  /* lineNo */
  29,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  4                                    /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = { 26,  /* lineNo */
  31,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = { 3,   /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo h_emlrtDCI = { 25,  /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo i_emlrtDCI = { 26,  /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  78,                                  /* lineNo */
  17,                                  /* colNo */
  "Runge.c",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = { 1,   /* iFirst */
  3,                                   /* iLast */
  62,                                  /* lineNo */
  20,                                  /* colNo */
  "Runge.b",                           /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo i_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  86,                                  /* lineNo */
  12,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo j_emlrtDCI = { 86,  /* lineNo */
  12,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo j_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  80,                                  /* lineNo */
  50,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo k_emlrtDCI = { 80,  /* lineNo */
  50,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo l_emlrtDCI = { 80,  /* lineNo */
  93,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  64,                                  /* lineNo */
  62,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo m_emlrtDCI = { 64,  /* lineNo */
  62,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo n_emlrtDCI = { 64,  /* lineNo */
  108,                                 /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  80,                                  /* lineNo */
  17,                                  /* colNo */
  "E_f",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo o_emlrtDCI = { 80,  /* lineNo */
  17,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  64,                                  /* lineNo */
  21,                                  /* colNo */
  "E_temp",                            /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  3                                    /* checkKind */
};

static emlrtDCInfo p_emlrtDCI = { 64,  /* lineNo */
  21,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo q_emlrtDCI = { 35,  /* lineNo */
  37,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo n_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  35,                                  /* lineNo */
  37,                                  /* colNo */
  "F_e",                               /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo o_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  36,                                  /* lineNo */
  13,                                  /* colNo */
  "Sol.t",                             /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo p_emlrtBCI = { 1,   /* iFirst */
  512,                                 /* iLast */
  86,                                  /* lineNo */
  38,                                  /* colNo */
  "shift_back",                        /* aName */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo r_emlrtDCI = { 86,  /* lineNo */
  38,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan/Runge_Kuarong_step",/* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m",         /* pName */
  1                                    /* checkKind */
};

static emlrtRTEInfo e_emlrtRTEI = { 3, /* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m"          /* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 25,/* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m"          /* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 26,/* lineNo */
  5,                                   /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m"          /* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 31,/* lineNo */
  61,                                  /* colNo */
  "Chi_3_LLE_Runge_Kuarong_with_Scan", /* fName */
  "C:\\Users\\dp710\\Documents\\GitHub\\CavityCodes\\Functions\\Stationary_Codes\\Models\\Chi_3\\Pure_LLE\\Solution Search\\Dynamics\\Chi_3_LLE_"
  "Runge_Kuarong_with_Scan.m"          /* pName */
};

/* Function Definitions */
void Chi_3_LLE_Runge_Kuarong_with_Scan(const emlrtStack *sp, const struct0_T
  *Temp, const struct5_T *Runge, struct6_T *Sol)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_creal_T *c_d;
  emxArray_cuint8_T *d;
  creal_T exp_minus_omega_contents[1536];
  creal_T exp_plus_omega_contents[1536];
  creal_T E_temp[512];
  creal_T F_e[512];
  creal_T Psi[512];
  creal_T b_F_e[512];
  creal_T dcv[512];
  real_T b_Runge;
  real_T b_d;
  real_T b_im;
  real_T b_re;
  real_T b_re_tmp;
  real_T dt;
  real_T im;
  real_T ind_s;
  real_T q;
  real_T r;
  real_T re;
  real_T re_tmp;
  real_T t;
  real_T y;
  int32_T b_i2;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T ii;
  int32_T k;
  int32_T loop_ub;
  int32_T ni;
  boolean_T rEQ0;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_cuint8_T(sp, &d, 2, &e_emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  st.site = &b_emlrtRSI;
  if (!(Runge->s >= 0.0)) {
    emlrtNonNegativeCheckR2012b(Runge->s, &c_emlrtDCI, sp);
  }

  b_d = (int32_T)muDoubleScalarFloor(Runge->s);
  if (Runge->s != b_d) {
    emlrtIntegerCheckR2012b(Runge->s, &b_emlrtDCI, sp);
  }

  i = d->size[0] * d->size[1];
  d->size[0] = (int32_T)Runge->s;
  d->size[1] = 512;
  emxEnsureCapacity_cuint8_T(sp, d, i, &e_emlrtRTEI);
  if (Runge->s != b_d) {
    emlrtIntegerCheckR2012b(Runge->s, &g_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Runge->s << 9;
  for (i = 0; i < loop_ub; i++) {
    d->data[i].re = 0U;
    d->data[i].im = 0U;
  }

  dt = Temp->Par.dt;
  q = Temp->Par.T / Temp->Par.dt;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (loop_ub = 0; loop_ub < 3; loop_ub++) {
    b_Runge = Runge->a[loop_ub];
    for (k = 0; k < 512; k++) {
      b_d = Temp->Eq.L[k].re;
      ind_s = Temp->Eq.L[k].im;
      re = dt * (b_Runge * (0.0 * b_d - (-ind_s)));
      im = dt * (b_Runge * (0.0 * ind_s + -b_d));
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

      i = loop_ub + 3 * k;
      exp_minus_omega_contents[i].re = re;
      exp_minus_omega_contents[i].im = im;
      re = dt * (b_Runge * (0.0 * b_d - ind_s));
      im = dt * (b_Runge * (0.0 * ind_s + b_d));
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

      exp_plus_omega_contents[i].re = re;
      exp_plus_omega_contents[i].im = im;
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  for (k = 0; k < 512; k++) {
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

  b_d = (int32_T)muDoubleScalarFloor(Temp->Par.dd);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &d_emlrtDCI, sp);
  }

  i = Sol->Psi->size[0] * Sol->Psi->size[1];
  Sol->Psi->size[0] = (int32_T)Temp->Par.dd;
  Sol->Psi->size[1] = 512;
  emxEnsureCapacity_creal_T(sp, Sol->Psi, i, &f_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &h_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd << 9;
  for (i = 0; i < loop_ub; i++) {
    Sol->Psi->data[i].re = 0.0;
    Sol->Psi->data[i].im = 0.0;
  }

  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[0] = 1;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &g_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &f_emlrtDCI, sp);
  }

  i = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[1] = (int32_T)Temp->Par.dd;
  emxEnsureCapacity_creal_T(sp, Sol->t, i, &g_emlrtRTEI);
  if (Temp->Par.dd != b_d) {
    emlrtIntegerCheckR2012b(Temp->Par.dd, &i_emlrtDCI, sp);
  }

  loop_ub = (int32_T)Temp->Par.dd;
  for (i = 0; i < loop_ub; i++) {
    Sol->t->data[i].re = 0.0;
    Sol->t->data[i].im = 0.0;
  }

  i = (int32_T)q;
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, q, mxDOUBLE_CLASS, (int32_T)q,
    &d_emlrtRTEI, sp);
  emxInit_creal_T(sp, &c_d, 2, &h_emlrtRTEI, true);
  if (0 <= i - 1) {
    b_loop_ub = d->size[0] * d->size[1];
    re_tmp = 512.0 * Temp->Eq.h;
    b_re_tmp = re_tmp * 1.0E-6;
    i1 = (int32_T)(Runge->s + -1.0);
    i2 = (int32_T)Runge->s;
    y = Temp->Par.s_t / Temp->Par.dt;
  }

  for (ni = 0; ni < i; ni++) {
    st.site = &emlrtRSI;
    t = Temp->In.t_start + ((real_T)ni + 1.0) * dt;
    i3 = c_d->size[0] * c_d->size[1];
    c_d->size[0] = d->size[0];
    c_d->size[1] = 512;
    emxEnsureCapacity_creal_T(&st, c_d, i3, &h_emlrtRTEI);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      c_d->data[i3].re = d->data[i3].re;
      c_d->data[i3].im = d->data[i3].im;
    }

    /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
    memcpy(&E_temp[0], &F_e[0], 512U * sizeof(creal_T));
    if (1 > d->size[0]) {
      emlrtDynamicBoundsCheckR2012b(1, 1, d->size[0], &f_emlrtBCI, &st);
    }

    for (i3 = 0; i3 < 512; i3++) {
      b_d = F_e[i3].re;
      ind_s = F_e[i3].im;
      q = exp_minus_omega_contents[3 * i3].re;
      r = exp_minus_omega_contents[3 * i3].im;
      b_F_e[i3].re = b_d * q - ind_s * r;
      b_F_e[i3].im = b_d * r + ind_s * q;
    }

    ifft(b_F_e, Psi);
    for (k = 0; k < 512; k++) {
      b_d = Psi[k].re;
      ind_s = Psi[k].im;
      q = muDoubleScalarHypot(b_d, ind_s);
      q *= q;
      b_F_e[k].re = q * b_d;
      b_F_e[k].im = q * ind_s;
    }

    fft(b_F_e, Psi);
    for (i3 = 0; i3 < 512; i3++) {
      b_d = exp_plus_omega_contents[3 * i3].re;
      ind_s = exp_plus_omega_contents[3 * i3].im;
      re = 0.0 * b_d - ind_s;
      im = 0.0 * ind_s + b_d;
      b_d = Temp->Eq.gamma_Kerr[i3];
      r = b_d * Psi[i3].re;
      q = b_d * Psi[i3].im;
      Psi[i3].re = re * r - im * q;
      Psi[i3].im = re * q + im * r;
    }

    b_Runge = t * (Temp->Par.freq_probe * 0.0);
    ind_s = t * -Temp->Par.freq_probe;
    if (ind_s == 0.0) {
      q = muDoubleScalarExp(b_Runge);
      r = 0.0;
    } else {
      r = muDoubleScalarExp(b_Runge / 2.0);
      q = r * (r * muDoubleScalarCos(ind_s));
      r *= r * muDoubleScalarSin(ind_s);
    }

    re = re_tmp + b_re_tmp * q;
    im = b_re_tmp * r;
    Psi[0].re += exp_plus_omega_contents[0].re * re - exp_plus_omega_contents[0]
      .im * im;
    Psi[0].im += exp_plus_omega_contents[0].re * im + exp_plus_omega_contents[0]
      .im * re;
    for (i3 = 0; i3 < 512; i3++) {
      c_d->data[c_d->size[0] * i3] = Psi[i3];
    }

    emlrtForLoopVectorCheckR2012b(2.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      (Runge->s + -1.0), &c_emlrtRTEI, &st);
    if (0 <= i1 - 1) {
      i4 = (int32_T)(Runge->s - 1.0);
      if (ind_s == 0.0) {
        q = muDoubleScalarExp(b_Runge);
        r = 0.0;
      } else {
        r = muDoubleScalarExp(b_Runge / 2.0);
        q = r * (r * muDoubleScalarCos(ind_s));
        r *= r * muDoubleScalarSin(ind_s);
      }

      b_re = re_tmp + b_re_tmp * q;
      b_im = b_re_tmp * r;
    }

    for (b_i2 = 0; b_i2 < i1; b_i2++) {
      emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s - 1.0, mxDOUBLE_CLASS,
        (int32_T)(Runge->s - 1.0), &b_emlrtRTEI, &st);
      for (ii = 0; ii < i4; ii++) {
        if (((int32_T)(b_i2 + 2U) < 1) || ((int32_T)(b_i2 + 2U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(b_i2 + 2U), 1, 3, &h_emlrtBCI,
            &st);
        }

        if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > 3)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, 3, &h_emlrtBCI,
            &st);
        }

        b_d = Runge->b[(b_i2 + 3 * ii) + 1];
        if (b_d != 0.0) {
          q = dt * b_d;
          if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > c_d->size[0])) {
            emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, c_d->size[0],
              &e_emlrtBCI, &st);
          }

          for (i3 = 0; i3 < 512; i3++) {
            b_d = Temp->Eq.mode_range[i3];
            loop_ub = (int32_T)muDoubleScalarFloor(b_d);
            if (b_d != loop_ub) {
              emlrtIntegerCheckR2012b(b_d, &m_emlrtDCI, &st);
            }

            k = (int32_T)b_d;
            if ((k < 1) || (k > 512)) {
              emlrtDynamicBoundsCheckR2012b(k, 1, 512, &k_emlrtBCI, &st);
            }

            if (k != loop_ub) {
              emlrtIntegerCheckR2012b(b_d, &n_emlrtDCI, &st);
            }

            b_F_e[i3].re = E_temp[k - 1].re + q * c_d->data[ii + c_d->size[0] *
              (k - 1)].re;
            if (k != loop_ub) {
              emlrtIntegerCheckR2012b(b_d, &m_emlrtDCI, &st);
            }

            b_F_e[i3].im = E_temp[k - 1].im + q * c_d->data[ii + c_d->size[0] *
              (k - 1)].im;
          }

          for (i3 = 0; i3 < 512; i3++) {
            b_d = Temp->Eq.mode_range[i3];
            loop_ub = (int32_T)muDoubleScalarFloor(b_d);
            if (b_d != loop_ub) {
              emlrtIntegerCheckR2012b(b_d, &p_emlrtDCI, &st);
            }

            k = (int32_T)b_d;
            if ((k < 1) || (k > 512)) {
              emlrtDynamicBoundsCheckR2012b(k, 1, 512, &m_emlrtBCI, &st);
            }

            E_temp[k - 1].re = b_F_e[i3].re;
            if (k != loop_ub) {
              emlrtIntegerCheckR2012b(b_d, &p_emlrtDCI, &st);
            }

            E_temp[k - 1].im = b_F_e[i3].im;
          }
        }

        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }

      b_st.site = &e_emlrtRSI;
      if ((b_i2 + 2 < 1) || (b_i2 + 2 > 3)) {
        emlrtDynamicBoundsCheckR2012b(b_i2 + 2, 1, 3, &d_emlrtBCI, &b_st);
      }

      for (i3 = 0; i3 < 512; i3++) {
        loop_ub = (b_i2 + 3 * i3) + 1;
        b_d = E_temp[i3].re;
        ind_s = E_temp[i3].im;
        im = b_d * exp_minus_omega_contents[loop_ub].im + ind_s *
          exp_minus_omega_contents[loop_ub].re;
        b_d = b_d * exp_minus_omega_contents[loop_ub].re - ind_s *
          exp_minus_omega_contents[loop_ub].im;
        E_temp[i3].re = b_d;
        E_temp[i3].im = im;
      }

      ifft(E_temp, Psi);
      for (k = 0; k < 512; k++) {
        b_d = Psi[k].re;
        ind_s = Psi[k].im;
        q = muDoubleScalarHypot(b_d, ind_s);
        q *= q;
        b_F_e[k].re = q * b_d;
        b_F_e[k].im = q * ind_s;
      }

      fft(b_F_e, Psi);
      for (i3 = 0; i3 < 512; i3++) {
        loop_ub = (b_i2 + 3 * i3) + 1;
        re = 0.0 * exp_plus_omega_contents[loop_ub].re -
          exp_plus_omega_contents[loop_ub].im;
        im = 0.0 * exp_plus_omega_contents[loop_ub].im +
          exp_plus_omega_contents[loop_ub].re;
        b_d = Temp->Eq.gamma_Kerr[i3];
        r = b_d * Psi[i3].re;
        q = b_d * Psi[i3].im;
        Psi[i3].re = re * r - im * q;
        Psi[i3].im = re * q + im * r;
      }

      b_d = exp_plus_omega_contents[b_i2 + 1].re;
      ind_s = exp_plus_omega_contents[b_i2 + 1].im;
      Psi[0].re += b_d * b_re - ind_s * b_im;
      Psi[0].im += b_d * b_im + ind_s * b_re;
      if (((int32_T)(b_i2 + 2U) < 1) || ((int32_T)(b_i2 + 2U) > c_d->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(b_i2 + 2U), 1, c_d->size[0],
          &c_emlrtBCI, &st);
      }

      for (i3 = 0; i3 < 512; i3++) {
        c_d->data[(b_i2 + c_d->size[0] * i3) + 1] = Psi[i3];
        E_temp[i3] = F_e[i3];
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    emlrtForLoopVectorCheckR2012b(1.0, 1.0, Runge->s, mxDOUBLE_CLASS, (int32_T)
      Runge->s, &emlrtRTEI, &st);
    for (ii = 0; ii < i2; ii++) {
      if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > 3)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, 3, &g_emlrtBCI, &st);
      }

      b_d = Runge->c[ii];
      if (b_d != 0.0) {
        q = dt * b_d;
        if (((int32_T)(ii + 1U) < 1) || ((int32_T)(ii + 1U) > c_d->size[0])) {
          emlrtDynamicBoundsCheckR2012b((int32_T)(ii + 1U), 1, c_d->size[0],
            &b_emlrtBCI, &st);
        }

        for (i3 = 0; i3 < 512; i3++) {
          b_d = Temp->Eq.mode_range[i3];
          loop_ub = (int32_T)muDoubleScalarFloor(b_d);
          if (b_d != loop_ub) {
            emlrtIntegerCheckR2012b(b_d, &k_emlrtDCI, &st);
          }

          k = (int32_T)b_d;
          if ((k < 1) || (k > 512)) {
            emlrtDynamicBoundsCheckR2012b(k, 1, 512, &j_emlrtBCI, &st);
          }

          if (k != loop_ub) {
            emlrtIntegerCheckR2012b(b_d, &l_emlrtDCI, &st);
          }

          b_F_e[i3].re = F_e[k - 1].re + q * c_d->data[ii + c_d->size[0] * (k -
            1)].re;
          if (k != loop_ub) {
            emlrtIntegerCheckR2012b(b_d, &k_emlrtDCI, &st);
          }

          b_F_e[i3].im = F_e[k - 1].im + q * c_d->data[ii + c_d->size[0] * (k -
            1)].im;
        }

        for (i3 = 0; i3 < 512; i3++) {
          b_d = Temp->Eq.mode_range[i3];
          loop_ub = (int32_T)muDoubleScalarFloor(b_d);
          if (b_d != loop_ub) {
            emlrtIntegerCheckR2012b(b_d, &o_emlrtDCI, &st);
          }

          k = (int32_T)b_d;
          if ((k < 1) || (k > 512)) {
            emlrtDynamicBoundsCheckR2012b(k, 1, 512, &l_emlrtBCI, &st);
          }

          F_e[k - 1].re = b_F_e[i3].re;
          if (k != loop_ub) {
            emlrtIntegerCheckR2012b(b_d, &o_emlrtDCI, &st);
          }

          F_e[k - 1].im = b_F_e[i3].im;
        }
      }

      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(&st);
      }
    }

    for (i3 = 0; i3 < 512; i3++) {
      b_d = Temp->Eq.mode_range[i3];
      loop_ub = (int32_T)muDoubleScalarFloor(b_d);
      if (b_d != loop_ub) {
        emlrtIntegerCheckR2012b(b_d, &r_emlrtDCI, &st);
      }

      k = (int32_T)b_d;
      if ((k < 1) || (k > 512)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, 512, &p_emlrtBCI, &st);
      }

      if (k != loop_ub) {
        emlrtIntegerCheckR2012b(b_d, &r_emlrtDCI, &st);
      }

      Psi[i3].re = dcv[k - 1].re * F_e[k - 1].re - dcv[k - 1].im * F_e[k - 1].im;
      if (k != loop_ub) {
        emlrtIntegerCheckR2012b(b_d, &r_emlrtDCI, &st);
      }

      Psi[i3].im = dcv[k - 1].re * F_e[k - 1].im + dcv[k - 1].im * F_e[k - 1].re;
    }

    for (i3 = 0; i3 < 512; i3++) {
      b_d = Temp->Eq.mode_range[i3];
      loop_ub = (int32_T)muDoubleScalarFloor(b_d);
      if (b_d != loop_ub) {
        emlrtIntegerCheckR2012b(b_d, &j_emlrtDCI, &st);
      }

      k = (int32_T)b_d;
      if ((k < 1) || (k > 512)) {
        emlrtDynamicBoundsCheckR2012b(k, 1, 512, &i_emlrtBCI, &st);
      }

      F_e[k - 1].re = Psi[i3].re;
      if (k != loop_ub) {
        emlrtIntegerCheckR2012b(b_d, &j_emlrtDCI, &st);
      }

      F_e[k - 1].im = Psi[i3].im;
    }

    /* ,Runge,exp_plus_omega,exp_minus_omega,Temp,shift_back */
    r = (real_T)ni + 1.0;
    if (!(y == 0.0)) {
      if (muDoubleScalarIsNaN(y)) {
        r = rtNaN;
      } else if (muDoubleScalarIsInf(y)) {
        if (y < 0.0) {
          r = y;
        }
      } else {
        r = muDoubleScalarRem((real_T)ni + 1.0, y);
        rEQ0 = (r == 0.0);
        if ((!rEQ0) && (y > muDoubleScalarFloor(y))) {
          q = muDoubleScalarAbs(((real_T)ni + 1.0) / y);
          rEQ0 = !(muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) >
                   2.2204460492503131E-16 * q);
        }

        if (rEQ0) {
          r = y * 0.0;
        } else {
          if (y < 0.0) {
            r += y;
          }
        }
      }
    }

    if (r == 0.0) {
      b_Runge = ((real_T)ni + 1.0) * Temp->Par.dt;
      ind_s = muDoubleScalarRound(b_Runge / Temp->Par.s_t);
      for (i3 = 0; i3 < 512; i3++) {
        b_d = Temp->Eq.mode_range[i3];
        if (b_d != (int32_T)muDoubleScalarFloor(b_d)) {
          emlrtIntegerCheckR2012b(b_d, &q_emlrtDCI, sp);
        }

        if (((int32_T)b_d < 1) || ((int32_T)b_d > 512)) {
          emlrtDynamicBoundsCheckR2012b((int32_T)b_d, 1, 512, &n_emlrtBCI, sp);
        }
      }

      if (ind_s != (int32_T)ind_s) {
        emlrtIntegerCheckR2012b(ind_s, &emlrtDCI, sp);
      }

      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->Psi->size[0])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->Psi->size[0],
          &emlrtBCI, sp);
      }

      for (i3 = 0; i3 < 512; i3++) {
        loop_ub = (int32_T)Temp->Eq.mode_range[i3] - 1;
        q = F_e[loop_ub].re;
        r = F_e[loop_ub].im;
        if (r == 0.0) {
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].re = q /
            Temp->Space.N;
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].im = 0.0;
        } else if (q == 0.0) {
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].re = 0.0;
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].im = r /
            Temp->Space.N;
        } else {
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].re = q /
            Temp->Space.N;
          Sol->Psi->data[((int32_T)ind_s + Sol->Psi->size[0] * i3) - 1].im = r /
            Temp->Space.N;
        }
      }

      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->t->size[1],
          &o_emlrtBCI, sp);
      }

      Sol->t->data[(int32_T)ind_s - 1].re = b_Runge;
      if (((int32_T)ind_s < 1) || ((int32_T)ind_s > Sol->t->size[1])) {
        emlrtDynamicBoundsCheckR2012b((int32_T)ind_s, 1, Sol->t->size[1],
          &o_emlrtBCI, sp);
      }

      Sol->t->data[(int32_T)ind_s - 1].im = 0.0;

      /*              if 10*log10(sum(abs(Sol.Psi(ind_s,2:end)).^2)) <= -70 && (mod(ind_s,2) ==0) */
      /*   */
      /*                      Sol.Psi(ind_s+1:end,:) = []; */
      /*                      Sol.t(ind_s+1:end)     = [];                 */
      /*                      break; */
      /*   */
      /*              end */
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_creal_T(&c_d);
  emxFree_cuint8_T(&d);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (Chi_3_LLE_Runge_Kuarong_with_Scan.c) */
