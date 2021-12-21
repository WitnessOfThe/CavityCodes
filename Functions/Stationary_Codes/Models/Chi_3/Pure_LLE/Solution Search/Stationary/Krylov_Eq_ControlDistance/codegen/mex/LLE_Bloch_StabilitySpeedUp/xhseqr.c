/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xhseqr.c
 *
 * Code generation for function 'xhseqr'
 *
 */

/* Include files */
#include "xhseqr.h"
#include "LLE_Bloch_StabilitySpeedUp_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo tb_emlrtRSI = { 17, /* lineNo */
  "xhseqr",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xhseqr.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 128,/* lineNo */
  "ceval_xhseqr",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xhseqr.m"/* pathName */
};

/* Function Definitions */
int32_T xhseqr(const emlrtStack *sp, creal_T h[1048576], creal_T z[1048576])
{
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z',
    'h', 's', 'e', 'q', 'r' };

  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack st;
  creal_T w[1024];
  int32_T i;
  int32_T info;
  boolean_T b_p;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n_t = (ptrdiff_t)1024;
  n_t = LAPACKE_zhseqr(102, 'S', 'V', n_t, (ptrdiff_t)1, (ptrdiff_t)1024,
                       (lapack_complex_double *)&h[0], n_t,
                       (lapack_complex_double *)&w[0], (lapack_complex_double *)
                       &z[0], (ptrdiff_t)1024);
  info = (int32_T)n_t;
  b_st.site = &ub_emlrtRSI;
  if (info < 0) {
    p = true;
    b_p = false;
    if (info == -7) {
      b_p = true;
    } else {
      if (info == -10) {
        b_p = true;
      }
    }

    if (!b_p) {
      if (info == -1010) {
        emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI, "MATLAB:nomem",
          "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
          "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, info);
      }
    }
  } else {
    p = false;
  }

  if (p) {
    for (i = 0; i < 1048576; i++) {
      h[i].re = rtNaN;
      h[i].im = 0.0;
      z[i].re = rtNaN;
      z[i].im = 0.0;
    }
  }

  return info;
}

/* End of code generation (xhseqr.c) */
