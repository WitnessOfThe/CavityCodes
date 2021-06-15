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
#include "nullAssignment.h"
#include "Chi23OPO_Runge_Kuarong_data.h"
#include "Chi23OPO_Runge_Kuarong_emxutil.h"
#include "Chi23OPO_Runge_Kuarong_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo hb_emlrtRSI = { 22, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 26, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 274,/* lineNo */
  "delete_rows",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 283,/* lineNo */
  "delete_rows",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 285,/* lineNo */
  "delete_rows",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 288,/* lineNo */
  "delete_rows",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 290,/* lineNo */
  "delete_rows",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 259,/* lineNo */
  "make_bitarray",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 132,/* lineNo */
  "num_true",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 13, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 17, /* lineNo */
  "nullAssignment",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 167,/* lineNo */
  "onearg_null_assignment",            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 169,/* lineNo */
  "onearg_null_assignment",            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 172,/* lineNo */
  "onearg_null_assignment",            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pathName */
};

static emlrtRTEInfo g_emlrtRTEI = { 297,/* lineNo */
  1,                                   /* colNo */
  "delete_rows",                       /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 81,/* lineNo */
  27,                                  /* colNo */
  "validate_inputs",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 184,/* lineNo */
  9,                                   /* colNo */
  "onearg_null_assignment",            /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 85,/* lineNo */
  27,                                  /* colNo */
  "validate_inputs",                   /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 258,/* lineNo */
  1,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo y_emlrtRTEI = { 298,/* lineNo */
  5,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 281,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 165,/* lineNo */
  9,                                   /* colNo */
  "nullAssignment",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"/* pName */
};

/* Function Declarations */
static void make_bitarray(const emlrtStack *sp, int32_T n, const
  emxArray_int32_T *idx, emxArray_boolean_T *b);
static int32_T num_true(const emlrtStack *sp, const emxArray_boolean_T *b);

/* Function Definitions */
static void make_bitarray(const emlrtStack *sp, int32_T n, const
  emxArray_int32_T *idx, emxArray_boolean_T *b)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_b;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  b_b = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = n;
  emxEnsureCapacity_boolean_T(sp, b, b_b, &w_emlrtRTEI);
  for (b_b = 0; b_b < n; b_b++) {
    b->data[b_b] = false;
  }

  b_b = idx->size[1];
  st.site = &ob_emlrtRSI;
  if ((1 <= idx->size[1]) && (idx->size[1] > 2147483646)) {
    b_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (k = 0; k < b_b; k++) {
    b->data[idx->data[k] - 1] = true;
  }
}

static int32_T num_true(const emlrtStack *sp, const emxArray_boolean_T *b)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_b;
  int32_T k;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  n = 0;
  b_b = b->size[1];
  st.site = &pb_emlrtRSI;
  if ((1 <= b->size[1]) && (b->size[1] > 2147483646)) {
    b_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }

  for (k = 0; k < b_b; k++) {
    n += b->data[k];
  }

  return n;
}

void b_nullAssignment(const emlrtStack *sp, emxArray_creal_T *x, const
                      emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *b;
  int32_T k;
  int32_T k0;
  int32_T nxin;
  int32_T nxout;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &qb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx->size[1] - 1)) {
    if (idx->data[k] > x->size[1]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&st, &j_emlrtRTEI, "MATLAB:subsdeldimmismatch",
      "MATLAB:subsdeldimmismatch", 0);
  }

  emxInit_boolean_T(&st, &b, 2, &cb_emlrtRTEI, true);
  st.site = &rb_emlrtRSI;
  nxin = x->size[1];
  b_st.site = &sb_emlrtRSI;
  make_bitarray(&b_st, x->size[1], idx, b);
  b_st.site = &tb_emlrtRSI;
  nxout = x->size[1] - num_true(&b_st, b);
  k0 = -1;
  b_st.site = &ub_emlrtRSI;
  if ((1 <= x->size[1]) && (x->size[1] > 2147483646)) {
    c_st.site = &x_emlrtRSI;
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
    emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  nxin = x->size[0] * x->size[1];
  if (1 > nxout) {
    x->size[1] = 0;
  } else {
    x->size[1] = nxout;
  }

  emxEnsureCapacity_creal_T(&st, x, nxin, &bb_emlrtRTEI);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void nullAssignment(const emlrtStack *sp, emxArray_creal_T *x, const
                    emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *b;
  emxArray_creal_T *b_x;
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ncolx;
  int32_T nrows;
  int32_T nrowx;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  st.site = &hb_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= idx->size[1] - 1)) {
    if (idx->data[k] > x->size[0]) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!p) {
    emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI, "MATLAB:subsdeldimmismatch",
      "MATLAB:subsdeldimmismatch", 0);
  }

  st.site = &ib_emlrtRSI;
  nrowx = x->size[0];
  ncolx = x->size[1];
  if (idx->size[1] == 1) {
    nrows = x->size[0] - 1;
    b_st.site = &jb_emlrtRSI;
    if ((1 <= x->size[1]) && (x->size[1] > 2147483646)) {
      c_st.site = &x_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (j = 0; j < ncolx; j++) {
      k = idx->data[0];
      for (i = k; i <= nrows; i++) {
        x->data[(i + x->size[0] * j) - 1] = x->data[i + x->size[0] * j];
      }
    }
  } else {
    emxInit_boolean_T(&st, &b, 2, &ab_emlrtRTEI, true);
    b_st.site = &kb_emlrtRSI;
    make_bitarray(&b_st, x->size[0], idx, b);
    b_st.site = &lb_emlrtRSI;
    nrows = x->size[0] - num_true(&b_st, b);
    i = 0;
    b_st.site = &mb_emlrtRSI;
    if ((1 <= x->size[0]) && (x->size[0] > 2147483646)) {
      c_st.site = &x_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    for (k = 0; k < nrowx; k++) {
      if ((k + 1 > b->size[1]) || (!b->data[k])) {
        b_st.site = &nb_emlrtRSI;
        if ((1 <= ncolx) && (ncolx > 2147483646)) {
          c_st.site = &x_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (j = 0; j < ncolx; j++) {
          x->data[i + x->size[0] * j] = x->data[k + x->size[0] * j];
        }

        i++;
      }
    }

    emxFree_boolean_T(&b);
  }

  if (nrows > nrowx) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
      "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
  }

  emxInit_creal_T(&st, &b_x, 2, &y_emlrtRTEI, true);
  if (1 > nrows) {
    ncolx = 0;
  } else {
    ncolx = nrows;
  }

  nrowx = x->size[1] - 1;
  k = b_x->size[0] * b_x->size[1];
  b_x->size[0] = ncolx;
  b_x->size[1] = nrowx + 1;
  emxEnsureCapacity_creal_T(&st, b_x, k, &y_emlrtRTEI);
  for (k = 0; k <= nrowx; k++) {
    for (nrows = 0; nrows < ncolx; nrows++) {
      b_x->data[nrows + b_x->size[0] * k] = x->data[nrows + x->size[0] * k];
    }
  }

  k = x->size[0] * x->size[1];
  x->size[0] = b_x->size[0];
  x->size[1] = b_x->size[1];
  emxEnsureCapacity_creal_T(&st, x, k, &y_emlrtRTEI);
  ncolx = b_x->size[1];
  for (k = 0; k < ncolx; k++) {
    nrowx = b_x->size[0];
    for (nrows = 0; nrows < nrowx; nrows++) {
      x->data[nrows + x->size[0] * k] = b_x->data[nrows + b_x->size[0] * k];
    }
  }

  emxFree_creal_T(&b_x);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (nullAssignment.c) */
