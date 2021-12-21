/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eig.c
 *
 * Code generation for function 'eig'
 *
 */

/* Include files */
#include "eig.h"
#include "LLE_Bloch_StabilitySpeedUp_types.h"
#include "anyNonFinite.h"
#include "rt_nonfinite.h"
#include "schur.h"
#include "warning.h"
#include "xgeev.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = { 93, /* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 137,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 145,/* lineNo */
  "eig",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\eig.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 32, /* lineNo */
  "eigHermitianStandard",              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigHermitianStandard.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 59, /* lineNo */
  "eigStandard",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigStandard.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 31, /* lineNo */
  "eigStandard",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\matfun\\private\\eigStandard.m"/* pathName */
};

/* Function Definitions */
void eig(c_LLE_Bloch_StabilitySpeedUpSta *SD, const emlrtStack *sp, const
         creal_T A[1048576], creal_T V[1048576], creal_T D[1048576])
{
  emlrtStack b_st;
  emlrtStack st;
  creal_T dt[1024];
  int32_T A_re_tmp;
  int32_T A_tmp;
  int32_T b_i;
  int32_T exitg1;
  int32_T i;
  int32_T j;
  boolean_T exitg2;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  if (anyNonFinite(A)) {
    for (i = 0; i < 1048576; i++) {
      V[i].re = rtNaN;
      V[i].im = 0.0;
      D[i].re = 0.0;
      D[i].im = 0.0;
    }

    for (A_tmp = 0; A_tmp < 1024; A_tmp++) {
      i = A_tmp + (A_tmp << 10);
      D[i].re = rtNaN;
      D[i].im = 0.0;
    }
  } else {
    p = true;
    j = 0;
    exitg2 = false;
    while ((!exitg2) && (j < 1024)) {
      b_i = 0;
      do {
        exitg1 = 0;
        if (b_i <= j) {
          A_re_tmp = j + (b_i << 10);
          A_tmp = b_i + (j << 10);
          if ((!(A[A_tmp].re == A[A_re_tmp].re)) || (!(A[A_tmp].im ==
                -A[A_re_tmp].im))) {
            p = false;
            exitg1 = 1;
          } else {
            b_i++;
          }
        } else {
          j++;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    if (p) {
      st.site = &fb_emlrtRSI;
      b_st.site = &ib_emlrtRSI;
      schur(&b_st, A, V, D);
      D[0].im = 0.0;
      for (j = 0; j < 1023; j++) {
        i = (j + 1) << 10;
        D[(j + i) + 1].im = 0.0;
        A_re_tmp = (j + (j << 10)) + 1;
        D[A_re_tmp].re = 0.0;
        D[A_re_tmp].im = 0.0;
        for (b_i = 0; b_i <= j; b_i++) {
          A_re_tmp = b_i + i;
          D[A_re_tmp].re = 0.0;
          D[A_re_tmp].im = 0.0;
        }
      }
    } else {
      st.site = &gb_emlrtRSI;
      b_st.site = &xb_emlrtRSI;
      xgeev(SD, &b_st, A, &A_re_tmp, dt, V);
      memset(&D[0], 0, 1048576U * sizeof(creal_T));
      for (A_tmp = 0; A_tmp < 1024; A_tmp++) {
        D[A_tmp + (A_tmp << 10)] = dt[A_tmp];
      }

      if (A_re_tmp != 0) {
        b_st.site = &wb_emlrtRSI;
        b_warning(&b_st);
      }
    }
  }
}

/* End of code generation (eig.c) */
