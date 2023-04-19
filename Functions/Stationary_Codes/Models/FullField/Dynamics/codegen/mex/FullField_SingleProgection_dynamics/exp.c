/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * exp.c
 *
 * Code generation for function 'exp'
 *
 */

/* Include files */
#include "exp.h"
#include "FullField_SingleProgection_dynamics_data.h"
#include "FullField_SingleProgection_dynamics_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo u_emlrtRSI = {
    10,                                                           /* lineNo */
    "exp",                                                        /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/elfun/exp.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    33,                           /* lineNo */
    "applyScalarFunctionInPlace", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" /* pathName */
};

/* Function Definitions */
void b_exp(const emlrtStack *sp, emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T *x_data;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &u_emlrtRSI;
  nx = x->size[1];
  b_st.site = &v_emlrtRSI;
  if ((1 <= x->size[1]) && (x->size[1] > 2147483646)) {
    c_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k < nx; k++) {
    x_data[k] = muDoubleScalarExp(x_data[k]);
  }
}

void c_exp(const emlrtStack *sp, emxArray_creal_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  creal_T *x_data;
  real_T d;
  real_T r;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &u_emlrtRSI;
  nx = x->size[1];
  b_st.site = &v_emlrtRSI;
  if ((1 <= x->size[1]) && (x->size[1] > 2147483646)) {
    c_st.site = &s_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k < nx; k++) {
    if (x_data[k].im == 0.0) {
      x_data[k].re = muDoubleScalarExp(x_data[k].re);
      x_data[k].im = 0.0;
    } else if (muDoubleScalarIsInf(x_data[k].im) &&
               muDoubleScalarIsInf(x_data[k].re) && (x_data[k].re < 0.0)) {
      x_data[k].re = 0.0;
      x_data[k].im = 0.0;
    } else {
      r = muDoubleScalarExp(x_data[k].re / 2.0);
      d = x_data[k].im;
      x_data[k].re = r * (r * muDoubleScalarCos(x_data[k].im));
      x_data[k].im = r * (r * muDoubleScalarSin(d));
    }
  }
}

/* End of code generation (exp.c) */
