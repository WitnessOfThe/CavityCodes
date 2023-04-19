//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// exp.cpp
//
// Code generation for function 'exp'
//

// Include files
#include "exp.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include "mwmathutil.h"

// Variable Definitions
static emlrtRSInfo p_emlrtRSI{
    10,                                                           // lineNo
    "exp",                                                        // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/elfun/exp.m" // pathName
};

static emlrtRSInfo q_emlrtRSI{
    33,                           // lineNo
    "applyScalarFunctionInPlace", // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/eml/+coder/+internal/"
    "applyScalarFunctionInPlace.m" // pathName
};

// Function Definitions
namespace coder {
void b_exp(const emlrtStack *sp, ::coder::array<creal_T, 2U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x.size(1);
  b_st.site = &q_emlrtRSI;
  if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
    c_st.site = &n_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    if (x[k].im == 0.0) {
      x[k].re = muDoubleScalarExp(x[k].re);
      x[k].im = 0.0;
    } else if (muDoubleScalarIsInf(x[k].im) && muDoubleScalarIsInf(x[k].re) &&
               (x[k].re < 0.0)) {
      x[k].re = 0.0;
      x[k].im = 0.0;
    } else {
      real_T d;
      real_T r;
      r = muDoubleScalarExp(x[k].re / 2.0);
      d = x[k].im;
      x[k].re = r * (r * muDoubleScalarCos(x[k].im));
      x[k].im = r * (r * muDoubleScalarSin(d));
    }
  }
}

void b_exp(const emlrtStack *sp, ::coder::array<real_T, 2U> &x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &p_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x.size(1);
  b_st.site = &q_emlrtRSI;
  if ((1 <= x.size(1)) && (x.size(1) > 2147483646)) {
    c_st.site = &n_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (int32_T k{0}; k < nx; k++) {
    x[k] = muDoubleScalarExp(x[k]);
  }
}

} // namespace coder

// End of code generation (exp.cpp)
