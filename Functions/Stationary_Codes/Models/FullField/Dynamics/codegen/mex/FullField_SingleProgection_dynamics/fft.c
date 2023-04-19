/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.c
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "fft.h"
#include "FullField_SingleProgection_dynamics_data.h"
#include "FullField_SingleProgection_dynamics_emxutil.h"
#include "FullField_SingleProgection_dynamics_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo fc_emlrtRSI = {
    63,    /* lineNo */
    "fft", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/datafun/fft.m" /* pathName
                                                                     */
};

/* Function Definitions */
void fft(const emlrtStack *sp, const emxArray_creal_T *x, emxArray_creal_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  const creal_T *x_data;
  creal_T *y_data;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  x_data = x->data;
  st.site = &fc_emlrtRSI;
  if (x->size[1] == 0) {
    y->size[0] = 1;
    y->size[1] = 0;
  } else {
    b_st.site = &yb_emlrtRSI;
    c_st.site = &ac_emlrtRSI;
    d_st.site = &bc_emlrtRSI;
    e_st.site = &cc_emlrtRSI;
    emlrtFFTWSetNumThreads(36);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_creal_T(&e_st, y, i, &vc_emlrtRTEI);
    y_data = y->data;
    emlrtFFTW_1D_C2C((real_T *)&x_data[0], (real_T *)&y_data[0], 1, x->size[1],
                     x->size[1], 1, -1);
  }
}

/* End of code generation (fft.c) */
