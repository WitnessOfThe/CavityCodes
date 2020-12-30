/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nullAssignment.c
 *
 * Code generation for function 'nullAssignment'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "nullAssignment.h"
#include "Chi_3_LLE_Runge_Kuarong_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"

/* Variable Definitions */
static emlrtRSInfo jb_emlrtRSI = { 21, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 25, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 273,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 282,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 284,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 287,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 289,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 258,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 131,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 12, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 16, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 166,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 168,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 171,/* lineNo */
  "nullAssignment",                    /* fcnName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pathName */
};

static emlrtRTEInfo mb_emlrtRTEI = { 282,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo nb_emlrtRTEI = { 297,/* lineNo */
  5,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = { 25,/* lineNo */
  13,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = { 280,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo qb_emlrtRTEI = { 166,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo rb_emlrtRTEI = { 16,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo sb_emlrtRTEI = { 164,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = { 296,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = { 80,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = { 183,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = { 84,/* lineNo */
  27,                                  /* colNo */
  "nullAssignment",                    /* fName */
  "/usr/local/matlab/r2018b/toolbox/eml/eml/+coder/+internal/nullAssignment.m"/* pName */
};

/* Function Definitions */
void b_nullAssignment(const emlrtStack *sp, emxArray_creal_T *x, const
                      emxArray_int32_T *idx)
{
  boolean_T overflow;
  int32_T k;
  boolean_T exitg1;
  emxArray_boolean_T *b;
  int32_T nxin;
  int32_T n;
  int32_T k0;
  int32_T nxout;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &sb_emlrtRSI;
  overflow = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx->size[1] - 1)) {
    if (idx->data[k] > x->size[1]) {
      overflow = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &dc_emlrtRTEI,
      "MATLAB:subsdeldimmismatch", "MATLAB:subsdeldimmismatch", 0);
  }

  emxInit_boolean_T(&st, &b, 2, &sb_emlrtRTEI, true);
  st.site = &tb_emlrtRSI;
  nxin = x->size[1];
  b_st.site = &ub_emlrtRSI;
  n = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = x->size[1];
  emxEnsureCapacity_boolean_T(&b_st, b, n, &qb_emlrtRTEI);
  k0 = x->size[1];
  for (n = 0; n < k0; n++) {
    b->data[n] = false;
  }

  k0 = idx->size[1];
  c_st.site = &qb_emlrtRSI;
  overflow = ((1 <= idx->size[1]) && (idx->size[1] > 2147483646));
  if (overflow) {
    d_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k < k0; k++) {
    b->data[idx->data[k] - 1] = true;
  }

  b_st.site = &vb_emlrtRSI;
  n = 0;
  k0 = b->size[1];
  c_st.site = &rb_emlrtRSI;
  overflow = ((1 <= b->size[1]) && (b->size[1] > 2147483646));
  if (overflow) {
    d_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k < k0; k++) {
    n += b->data[k];
  }

  nxout = x->size[1] - n;
  k0 = -1;
  b_st.site = &wb_emlrtRSI;
  overflow = ((1 <= x->size[1]) && (x->size[1] > 2147483646));
  if (overflow) {
    c_st.site = &l_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k < nxin; k++) {
    if ((k + 1 > b->size[1]) || (!b->data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  emxFree_boolean_T(&b);
  if (nxout > nxin) {
    emlrtErrorWithMessageIdR2018a(&st, &cc_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > nxout) {
    x->size[1] = 0;
  } else {
    n = x->size[0] * x->size[1];
    x->size[1] = nxout;
    emxEnsureCapacity_creal_T(&st, x, n, &rb_emlrtRTEI);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void nullAssignment(const emlrtStack *sp, emxArray_creal_T *x, const
                    emxArray_int32_T *idx)
{
  boolean_T overflow;
  int32_T k;
  boolean_T exitg1;
  int32_T nrowx;
  int32_T ncolx;
  emxArray_boolean_T *b;
  int32_T nrows;
  int32_T loop_ub;
  int32_T i;
  emxArray_creal_T *b_x;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &jb_emlrtRSI;
  overflow = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx->size[1] - 1)) {
    if (idx->data[k] > x->size[0]) {
      overflow = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &bc_emlrtRTEI,
      "MATLAB:subsdeldimmismatch", "MATLAB:subsdeldimmismatch", 0);
  }

  st.site = &kb_emlrtRSI;
  nrowx = x->size[0];
  ncolx = x->size[1];
  if (idx->size[1] == 1) {
    nrows = x->size[0] - 1;
    b_st.site = &lb_emlrtRSI;
    overflow = ((1 <= x->size[1]) && (x->size[1] > 2147483646));
    if (overflow) {
      c_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (loop_ub = 0; loop_ub < ncolx; loop_ub++) {
      k = idx->data[0];
      for (i = k; i <= nrows; i++) {
        x->data[(i + x->size[0] * loop_ub) - 1] = x->data[i + x->size[0] *
          loop_ub];
      }
    }
  } else {
    emxInit_boolean_T(&st, &b, 2, &pb_emlrtRTEI, true);
    b_st.site = &mb_emlrtRSI;
    k = b->size[0] * b->size[1];
    b->size[0] = 1;
    b->size[1] = x->size[0];
    emxEnsureCapacity_boolean_T(&b_st, b, k, &mb_emlrtRTEI);
    loop_ub = x->size[0];
    for (k = 0; k < loop_ub; k++) {
      b->data[k] = false;
    }

    nrows = idx->size[1];
    c_st.site = &qb_emlrtRSI;
    overflow = ((1 <= idx->size[1]) && (idx->size[1] > 2147483646));
    if (overflow) {
      d_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 0; k < nrows; k++) {
      b->data[idx->data[k] - 1] = true;
    }

    b_st.site = &nb_emlrtRSI;
    i = 0;
    nrows = b->size[1];
    c_st.site = &rb_emlrtRSI;
    overflow = ((1 <= b->size[1]) && (b->size[1] > 2147483646));
    if (overflow) {
      d_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }

    for (k = 0; k < nrows; k++) {
      i += b->data[k];
    }

    nrows = x->size[0] - i;
    i = 0;
    b_st.site = &ob_emlrtRSI;
    overflow = ((1 <= x->size[0]) && (x->size[0] > 2147483646));
    if (overflow) {
      c_st.site = &l_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 0; k < nrowx; k++) {
      if ((k + 1 > b->size[1]) || (!b->data[k])) {
        b_st.site = &pb_emlrtRSI;
        if ((1 <= ncolx) && (ncolx > 2147483646)) {
          c_st.site = &l_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (loop_ub = 0; loop_ub < ncolx; loop_ub++) {
          x->data[i + x->size[0] * loop_ub] = x->data[k + x->size[0] * loop_ub];
        }

        i++;
      }
    }

    emxFree_boolean_T(&b);
  }

  if (nrows > nrowx) {
    emlrtErrorWithMessageIdR2018a(&st, &ac_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  if (1 > nrows) {
    loop_ub = 0;
  } else {
    loop_ub = nrows;
  }

  emxInit_creal_T(&st, &b_x, 2, &nb_emlrtRTEI, true);
  nrows = x->size[1];
  k = b_x->size[0] * b_x->size[1];
  b_x->size[0] = loop_ub;
  b_x->size[1] = nrows;
  emxEnsureCapacity_creal_T(&st, b_x, k, &nb_emlrtRTEI);
  for (k = 0; k < nrows; k++) {
    for (i = 0; i < loop_ub; i++) {
      b_x->data[i + b_x->size[0] * k] = x->data[i + x->size[0] * k];
    }
  }

  k = x->size[0] * x->size[1];
  x->size[0] = b_x->size[0];
  x->size[1] = b_x->size[1];
  emxEnsureCapacity_creal_T(&st, x, k, &ob_emlrtRTEI);
  loop_ub = b_x->size[1];
  for (k = 0; k < loop_ub; k++) {
    nrows = b_x->size[0];
    for (i = 0; i < nrows; i++) {
      x->data[i + x->size[0] * k] = b_x->data[i + b_x->size[0] * k];
    }
  }

  emxFree_creal_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (nullAssignment.c) */
