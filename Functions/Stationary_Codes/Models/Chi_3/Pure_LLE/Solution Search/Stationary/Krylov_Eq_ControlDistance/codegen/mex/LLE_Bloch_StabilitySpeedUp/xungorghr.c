/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xungorghr.c
 *
 * Code generation for function 'xungorghr'
 *
 */

/* Include files */
#include "xungorghr.h"
#include "LLE_Bloch_StabilitySpeedUp_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo rb_emlrtRSI = { 11, /* lineNo */
  "xungorghr",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 69, /* lineNo */
  "ceval_xungorghr",                   /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xungorghr.m"/* pathName */
};

/* Function Definitions */
void xungorghr(const emlrtStack *sp, creal_T A[1048576], const creal_T tau[1023])
{
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z',
    'u', 'n', 'g', 'h', 'r' };

  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack st;
  int32_T info;
  boolean_T b_p;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  info_t = LAPACKE_zunghr(102, (ptrdiff_t)1024, (ptrdiff_t)1, (ptrdiff_t)1024,
    (lapack_complex_double *)&A[0], (ptrdiff_t)1024, (lapack_complex_double *)
    &tau[0]);
  info = (int32_T)info_t;
  b_st.site = &sb_emlrtRSI;
  if (info != 0) {
    p = true;
    b_p = false;
    if (info == -5) {
      b_p = true;
    } else {
      if (info == -7) {
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
    for (info = 0; info < 1048576; info++) {
      A[info].re = rtNaN;
      A[info].im = 0.0;
    }
  }
}

/* End of code generation (xungorghr.c) */
