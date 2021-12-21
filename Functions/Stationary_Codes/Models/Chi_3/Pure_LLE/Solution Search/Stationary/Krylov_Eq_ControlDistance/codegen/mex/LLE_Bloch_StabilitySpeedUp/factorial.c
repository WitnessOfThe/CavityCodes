/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * factorial.c
 *
 * Code generation for function 'factorial'
 *
 */

/* Include files */
#include "factorial.h"
#include "LLE_Bloch_StabilitySpeedUp_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo x_emlrtRSI = { 17,  /* lineNo */
  "applyScalarFunctionInPlace",        /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"/* pathName */
};

static emlrtRTEInfo f_emlrtRTEI = { 21,/* lineNo */
  5,                                   /* colNo */
  "scalar_factorial",                  /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\specfun\\factorial.m"/* pName */
};

/* Function Definitions */
void factorial(const emlrtStack *sp, real_T *n)
{
  emlrtStack b_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &w_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_st.site = &x_emlrtRSI;
  if (*n != *n) {
    emlrtErrorWithMessageIdR2018a(&b_st, &f_emlrtRTEI,
      "MATLAB:factorial:NNegativeInt", "MATLAB:factorial:NNegativeInt", 0);
  } else {
    *n = dv[(int32_T)*n - 1];
  }
}

/* End of code generation (factorial.c) */
