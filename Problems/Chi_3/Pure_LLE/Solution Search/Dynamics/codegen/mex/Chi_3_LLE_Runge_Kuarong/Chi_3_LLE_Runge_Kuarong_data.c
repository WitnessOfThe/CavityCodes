/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi_3_LLE_Runge_Kuarong_data.c
 *
 * Code generation for function 'Chi_3_LLE_Runge_Kuarong_data'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131467U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "Chi_3_LLE_Runge_Kuarong",           /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

emlrtRSInfo l_emlrtRSI = { 21,         /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

emlrtRSInfo o_emlrtRSI = { 90,         /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

emlrtRSInfo p_emlrtRSI = { 94,         /* lineNo */
  "Chi_3_LLE_Runge_Kuarong",           /* fcnName */
  "/u/p/dp710/Documents/MATLAB/Matlab_Repo/Problems/Cavity_Codes/Problems/Chi_3/Pure_LLE/Solution Search/Dynamics/Chi_3_LLE_Runge_K"
  "uarong.m"                           /* pathName */
};

emlrtRSInfo q_emlrtRSI = { 19,         /* lineNo */
  "ifft",                              /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/ifft.m"/* pathName */
};

emlrtRSInfo r_emlrtRSI = { 56,         /* lineNo */
  "fft",                               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/fft.m"/* pathName */
};

emlrtRSInfo s_emlrtRSI = { 89,         /* lineNo */
  "fft",                               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/fft.m"/* pathName */
};

emlrtRSInfo t_emlrtRSI = { 28,         /* lineNo */
  "FFTWApi",                           /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/+fftw/FFTWApi.m"/* pathName */
};

emlrtRSInfo u_emlrtRSI = { 31,         /* lineNo */
  "FFTWApi",                           /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/+fftw/FFTWApi.m"/* pathName */
};

emlrtRSInfo v_emlrtRSI = { 15,         /* lineNo */
  "MATLABFFTWCallback",                /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/+fftw/MATLABFFTWCallback.m"/* pathName */
};

emlrtRSInfo w_emlrtRSI = { 18,         /* lineNo */
  "fftw",                              /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/fftw.m"/* pathName */
};

emlrtRSInfo x_emlrtRSI = { 8,          /* lineNo */
  "fft",                               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/fft.m"/* pathName */
};

emlrtRSInfo y_emlrtRSI = { 65,         /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

emlrtRSInfo ab_emlrtRSI = { 189,       /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

emlrtRSInfo cb_emlrtRSI = { 74,        /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"/* pathName */
};

emlrtRTEInfo yb_emlrtRTEI = { 22,      /* lineNo */
  23,                                  /* colNo */
  "sumprod",                           /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pName */
};

/* End of code generation (Chi_3_LLE_Runge_Kuarong_data.c) */
