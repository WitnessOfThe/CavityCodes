/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgehrd.c
 *
 * Code generation for function 'xgehrd'
 *
 */

/* Include files */
#include "xgehrd.h"
#include "LLE_Bloch_StabilitySpeedUp_data.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = { 15, /* lineNo */
  "xgehrd",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgehrd.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 85, /* lineNo */
  "ceval_xgehrd",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgehrd.m"/* pathName */
};

/* Function Definitions */
void xgehrd(const emlrtStack *sp, creal_T a[1048576], creal_T tau[1023])
{
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z',
    'g', 'e', 'h', 'r', 'd' };

  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  info_t = LAPACKE_zgehrd(102, (ptrdiff_t)1024, (ptrdiff_t)1, (ptrdiff_t)1024,
    (lapack_complex_double *)&a[0], (ptrdiff_t)1024, (lapack_complex_double *)
    &tau[0]);
  b_st.site = &qb_emlrtRSI;
  i = (int32_T)info_t;
  if (i != 0) {
    p = true;
    if (i != -5) {
      if (i == -1010) {
        emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI, "MATLAB:nomem",
          "MATLAB:nomem", 0);
      } else {
        emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
          "Coder:toolbox:LAPACKCallErrorInfo",
          "Coder:toolbox:LAPACKCallErrorInfo", 5, 4, 14, fname, 12, i);
      }
    }
  } else {
    p = false;
  }

  if (p) {
    for (i = 0; i < 1048576; i++) {
      a[i].re = rtNaN;
      a[i].im = 0.0;
    }

    for (i = 0; i < 1023; i++) {
      tau[i].re = rtNaN;
      tau[i].im = 0.0;
    }
  }
}

/* End of code generation (xgehrd.c) */
