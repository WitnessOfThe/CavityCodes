/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diag.c
 *
 * Code generation for function 'diag'
 *
 */

/* Include files */
#include "diag.h"
#include "LLE_Bloch_StabilitySpeedUp_emxutil.h"
#include "LLE_Bloch_StabilitySpeedUp_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo v_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 90, /* lineNo */
  "diag",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\diag.m"/* pathName */
};

static emlrtRTEInfo hb_emlrtRTEI = { 82,/* lineNo */
  5,                                   /* colNo */
  "diag",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\lib\\matlab\\elmat\\diag.m"/* pName */
};

/* Function Definitions */
void b_diag(const real_T v[512], real_T d[262144])
{
  int32_T j;
  memset(&d[0], 0, 262144U * sizeof(real_T));
  for (j = 0; j < 512; j++) {
    d[j + (j << 9)] = v[j];
  }
}

void c_diag(const emlrtStack *sp, const emxArray_creal_T *v, emxArray_creal_T *d)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T i;
  int32_T loop_ub;
  int32_T nv;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  nv = v->size[1];
  i = d->size[0] * d->size[1];
  d->size[0] = v->size[1];
  d->size[1] = v->size[1];
  emxEnsureCapacity_creal_T(sp, d, i, &hb_emlrtRTEI);
  loop_ub = v->size[1] * v->size[1];
  for (i = 0; i < loop_ub; i++) {
    d->data[i].re = 0.0;
    d->data[i].im = 0.0;
  }

  st.site = &ic_emlrtRSI;
  if ((1 <= v->size[1]) && (v->size[1] > 2147483646)) {
    b_st.site = &v_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (loop_ub = 0; loop_ub < nv; loop_ub++) {
    d->data[loop_ub + d->size[0] * loop_ub] = v->data[loop_ub];
  }
}

void diag(const creal_T v[512], creal_T d[262144])
{
  int32_T j;
  memset(&d[0], 0, 262144U * sizeof(creal_T));
  for (j = 0; j < 512; j++) {
    d[j + (j << 9)] = v[j];
  }
}

/* End of code generation (diag.c) */
