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
#include "Chi_3_LLE_Runge_Kuarong_data.h"
#include "Chi_3_LLE_Runge_Kuarong_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo j_emlrtRSI = { 10,  /* lineNo */
  "exp",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elfun\\exp.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 33,  /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"/* pathName */
};

/* Function Definitions */
void b_exp(const emlrtStack *sp, emxArray_creal_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T d;
  real_T r;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &j_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[1];
  b_st.site = &k_emlrtRSI;
  if ((1 <= x->size[1]) && (x->size[1] > 2147483646)) {
    c_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k < nx; k++) {
    if (x->data[k].im == 0.0) {
      x->data[k].re = muDoubleScalarExp(x->data[k].re);
      x->data[k].im = 0.0;
    } else if (muDoubleScalarIsInf(x->data[k].im) && muDoubleScalarIsInf(x->
                data[k].re) && (x->data[k].re < 0.0)) {
      x->data[k].re = 0.0;
      x->data[k].im = 0.0;
    } else {
      r = muDoubleScalarExp(x->data[k].re / 2.0);
      d = x->data[k].im;
      x->data[k].re = r * (r * muDoubleScalarCos(x->data[k].im));
      x->data[k].im = r * (r * muDoubleScalarSin(d));
    }
  }
}

/* End of code generation (exp.c) */
