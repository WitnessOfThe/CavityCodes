/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "power.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"
#include "Chi_3_LLE_Runge_Kuarong_emxutil.h"
#include "Chi_3_LLE_Runge_Kuarong_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo y_emlrtRSI = { 66,  /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 188,/* lineNo */
  "flatIter",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 70, /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 79, /* lineNo */
  "fltpower",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 46,/* lineNo */
  6,                                   /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"/* pName */
};

/* Function Definitions */
void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T d;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &db_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &eb_emlrtRSI;
  nx = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = a->size[1];
  emxEnsureCapacity_real_T(&b_st, y, nx, &mb_emlrtRTEI);
  c_st.site = &y_emlrtRSI;
  nx = a->size[1];
  d_st.site = &ab_emlrtRSI;
  if ((1 <= a->size[1]) && (a->size[1] > 2147483646)) {
    e_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (k = 0; k < nx; k++) {
    d = a->data[k];
    y->data[k] = d * d;
  }
}

/* End of code generation (power.c) */
