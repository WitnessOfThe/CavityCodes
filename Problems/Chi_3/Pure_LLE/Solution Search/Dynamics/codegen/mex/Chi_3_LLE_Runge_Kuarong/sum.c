/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"

/* Variable Definitions */
static emlrtRSInfo fb_emlrtRSI = { 9,  /* lineNo */
  "sum",                               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/sum.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 64, /* lineNo */
  "sumprod",                           /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/private/sumprod.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 134,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 193,/* lineNo */
  "combineVectorElements",             /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

/* Function Definitions */
real_T sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  real_T y;
  int32_T vlen;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &fb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &gb_emlrtRSI;
  vlen = x->size[1];
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    c_st.site = &hb_emlrtRSI;
    y = x->data[0];
    d_st.site = &ib_emlrtRSI;
    overflow = ((2 <= x->size[1]) && (x->size[1] > 2147483646));
    if (overflow) {
      e_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }

    for (k = 2; k <= vlen; k++) {
      y += x->data[k - 1];
    }
  }

  return y;
}

/* End of code generation (sum.c) */
