/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * exp.cpp
 *
 * Code generation for function 'exp'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Split_chi_2.h"
#include "exp.h"
#include "eml_int_forloop_overflow_check.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 9,   /* lineNo */
  "exp",                               /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/elfun/exp.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 31,  /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

/* Function Definitions */
void b_exp(const emlrtStack *sp, emxArray_creal_T *x)
{
  int32_T nx;
  boolean_T overflow;
  int32_T k;
  real_T r;
  real_T x_im;
  real_T b_x_im;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &n_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[1];
  b_st.site = &o_emlrtRSI;
  overflow = ((1 <= x->size[1]) && (x->size[1] > 2147483646));
  if (overflow) {
    c_st.site = &p_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k < nx; k++) {
    if (x->data[k].im == 0.0) {
      r = x->data[k].re;
      x->data[k].re = muDoubleScalarExp(r);
      x->data[k].im = 0.0;
    } else if (muDoubleScalarIsInf(x->data[k].im) && muDoubleScalarIsInf(x->
                data[k].re) && (x->data[k].re < 0.0)) {
      x->data[k].re = 0.0;
      x->data[k].im = 0.0;
    } else {
      r = muDoubleScalarExp(x->data[k].re / 2.0);
      x_im = x->data[k].im;
      b_x_im = x->data[k].im;
      x->data[k].re = r * (r * muDoubleScalarCos(x_im));
      x->data[k].im = r * (r * muDoubleScalarSin(b_x_im));
    }
  }
}

/* End of code generation (exp.cpp) */
