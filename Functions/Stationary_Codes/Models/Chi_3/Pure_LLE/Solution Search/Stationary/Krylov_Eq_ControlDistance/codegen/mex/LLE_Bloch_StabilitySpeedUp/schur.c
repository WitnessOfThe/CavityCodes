/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * schur.c
 *
 * Code generation for function 'schur'
 *
 */

/* Include files */
#include "schur.h"
#include "anyNonFinite.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "xgehrd.h"
#include "xhseqr.h"
#include "xungorghr.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo lb_emlrtRSI = { 66, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 77, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 78, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 83, /* lineNo */
  "schur",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\schur.m"/* pathName */
};

/* Function Definitions */
void schur(const emlrtStack *sp, const creal_T A[1048576], creal_T V[1048576],
           creal_T T[1048576])
{
  emlrtStack st;
  creal_T tau[1023];
  int32_T istart;
  int32_T j;
  st.prev = sp;
  st.tls = sp->tls;
  if (anyNonFinite(A)) {
    for (istart = 0; istart < 1048576; istart++) {
      V[istart].re = rtNaN;
      V[istart].im = 0.0;
    }

    istart = 2;
    for (j = 0; j < 1023; j++) {
      if (istart <= 1024) {
        memset(&V[(j * 1024 + istart) + -1], 0, (1025 - istart) * sizeof(creal_T));
      }

      istart++;
    }

    for (istart = 0; istart < 1048576; istart++) {
      T[istart].re = rtNaN;
      T[istart].im = 0.0;
    }
  } else {
    memcpy(&T[0], &A[0], 1048576U * sizeof(creal_T));
    st.site = &lb_emlrtRSI;
    xgehrd(&st, T, tau);
    memcpy(&V[0], &T[0], 1048576U * sizeof(creal_T));
    st.site = &mb_emlrtRSI;
    xungorghr(&st, V, tau);
    st.site = &nb_emlrtRSI;
    istart = xhseqr(&st, T, V);
    if (istart != 0) {
      st.site = &ob_emlrtRSI;
      warning(&st);
    }
  }
}

/* End of code generation (schur.c) */
