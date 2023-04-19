/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fftw.c
 *
 * Code generation for function 'fftw'
 *
 */

/* Include files */
#include "fftw.h"
#include "FullField_SingleProgection_dynamics_data.h"
#include "FullField_SingleProgection_dynamics_emxutil.h"
#include "FullField_SingleProgection_dynamics_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo
    lb_emlrtRSI =
        {
            36,     /* lineNo */
            "fftw", /* fcnName */
            "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/+fft/"
            "fftw.m" /* pathName */
};

static emlrtRSInfo
    mb_emlrtRSI =
        {
            95,                         /* lineNo */
            "eml_fftw_set_plan_method", /* fcnName */
            "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/+fft/"
            "fftw.m" /* pathName */
};

static emlrtRSInfo
    nb_emlrtRSI =
        {
            78,                         /* lineNo */
            "eml_fftw_get_plan_method", /* fcnName */
            "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/+fft/"
            "fftw.m" /* pathName */
};

static emlrtRSInfo
    ob_emlrtRSI =
        {
            65,           /* lineNo */
            "copy_c_str", /* fcnName */
            "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/+fft/"
            "fftw.m" /* pathName */
};

static emlrtRSInfo gc_emlrtRSI = {
    19,     /* lineNo */
    "fftw", /* fcnName */
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/datafun/fftw.m" /* pathName
                                                                      */
};

static emlrtRSInfo
    hc_emlrtRSI =
        {
            40,     /* lineNo */
            "fftw", /* fcnName */
            "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/+fft/"
            "fftw.m" /* pathName */
};

static emlrtRSInfo
    ic_emlrtRSI =
        {
            120,                       /* lineNo */
            "eml_fftw_get_set_wisdom", /* fcnName */
            "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/+fft/"
            "fftw.m" /* pathName */
};

static emlrtRSInfo
    jc_emlrtRSI =
        {
            112,                   /* lineNo */
            "eml_fftw_get_wisdom", /* fcnName */
            "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/+fft/"
            "fftw.m" /* pathName */
};

static emlrtDCInfo y_emlrtDCI = {
    12,       /* lineNo */
    20,       /* colNo */
    "blanks", /* fName */
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/strfun/blanks.m", /* pName
                                                                        */
    4 /* checkKind */
};

static emlrtRTEInfo
    ac_emlrtRTEI =
        {
            65,     /* lineNo */
            29,     /* colNo */
            "fftw", /* fName */
            "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/+fft/"
            "fftw.m" /* pName */
};

static emlrtRTEInfo
    bc_emlrtRTEI =
        {
            74,     /* lineNo */
            10,     /* colNo */
            "fftw", /* fName */
            "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/+fft/"
            "fftw.m" /* pName */
};

static emlrtRTEInfo
    xc_emlrtRTEI =
        {
            132,    /* lineNo */
            13,     /* colNo */
            "fftw", /* fName */
            "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/+fft/"
            "fftw.m" /* pName */
};

/* Function Definitions */
void b_fftw(const emlrtStack *sp, emxArray_char_T *out)
{
  char *cWisdom;
  size_t cStrLength;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T i;
  char_T *out_data;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &hc_emlrtRSI;
  c_st.site = &ic_emlrtRSI;
  cWisdom = emlrtFFTWExportDoublePlan();
  d_st.site = &jc_emlrtRSI;
  cStrLength = emlrtStrlen(cWisdom);
  e_st.site = &ob_emlrtRSI;
  if ((int32_T)cStrLength < 0) {
    emlrtNonNegativeCheckR2012b((int32_T)cStrLength, &y_emlrtDCI, &e_st);
  }
  i = out->size[0] * out->size[1];
  out->size[0] = 1;
  out->size[1] = (int32_T)cStrLength;
  emxEnsureCapacity_char_T(&e_st, out, i, &ac_emlrtRTEI);
  out_data = out->data;
  if ((int32_T)cStrLength != 0) {
    memcpy((void *)&out_data[0], (void *)cWisdom, (uint32_T)cStrLength);
  }
  emlrtFFTWFree(cWisdom);
}

void c_fftw(const emlrtStack *sp, const emxArray_char_T *info)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_char_T *infoNullTerminate;
  int32_T i;
  int32_T loop_ub;
  const char_T *info_data;
  char_T *infoNullTerminate_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  info_data = info->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &jb_emlrtRSI;
  b_st.site = &kb_emlrtRSI;
  if (info->size[1] == 0) {
    emlrtFFTWForgetDoublePlan();
  } else {
    emxInit_char_T(&b_st, &infoNullTerminate, &xc_emlrtRTEI);
    i = infoNullTerminate->size[0] * infoNullTerminate->size[1];
    infoNullTerminate->size[0] = 1;
    infoNullTerminate->size[1] = info->size[1] + 1;
    emxEnsureCapacity_char_T(&b_st, infoNullTerminate, i, &xc_emlrtRTEI);
    infoNullTerminate_data = infoNullTerminate->data;
    loop_ub = info->size[1];
    for (i = 0; i < loop_ub; i++) {
      infoNullTerminate_data[i] = info_data[i];
    }
    infoNullTerminate_data[info->size[1]] = '\x00';
    emlrtFFTWImportDoublePlan(&infoNullTerminate_data[0]);
    emxFree_char_T(&b_st, &infoNullTerminate);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void fftw(const emlrtStack *sp)
{
  const char *cmethod;
  size_t cStrLength;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_char_T *method;
  int32_T i;
  char_T *method_data;
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
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &jb_emlrtRSI;
  b_st.site = &lb_emlrtRSI;
  c_st.site = &mb_emlrtRSI;
  cmethod = emlrtFFTWGetPlanMethod();
  d_st.site = &nb_emlrtRSI;
  cStrLength = emlrtStrlen(cmethod);
  e_st.site = &ob_emlrtRSI;
  if ((int32_T)cStrLength < 0) {
    emlrtNonNegativeCheckR2012b((int32_T)cStrLength, &y_emlrtDCI, &e_st);
  }
  emxInit_char_T(&e_st, &method, &bc_emlrtRTEI);
  i = method->size[0] * method->size[1];
  method->size[0] = 1;
  method->size[1] = (int32_T)cStrLength;
  emxEnsureCapacity_char_T(&e_st, method, i, &ac_emlrtRTEI);
  method_data = method->data;
  if ((int32_T)cStrLength != 0) {
    memcpy((void *)&method_data[0], (void *)cmethod, (uint32_T)cStrLength);
  }
  emxFree_char_T(&d_st, &method);
  emlrtFFTWSetPlanMethod("measure");
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (fftw.c) */
