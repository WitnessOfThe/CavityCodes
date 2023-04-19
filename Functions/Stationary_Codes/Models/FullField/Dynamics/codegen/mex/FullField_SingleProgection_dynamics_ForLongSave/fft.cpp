//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fft.cpp
//
// Code generation for function 'fft'
//

// Include files
#include "fft.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo tb_emlrtRSI{
    63,                                                             // lineNo
    "fft",                                                          // fcnName
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/datafun/fft.m" // pathName
};

static emlrtRTEInfo kc_emlrtRTEI{
    63,                                                             // lineNo
    5,                                                              // colNo
    "fft",                                                          // fName
    "/usr/local/matlab/r2021b/toolbox/eml/lib/matlab/datafun/fft.m" // pName
};

// Function Definitions
namespace coder {
void fft(const emlrtStack *sp, const ::coder::array<creal_T, 2U> &x,
         ::coder::array<creal_T, 2U> &y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (x.size(1) == 0) {
    y.set_size(&kc_emlrtRTEI, &st, 1, 0);
  } else {
    b_st.site = &nb_emlrtRSI;
    c_st.site = &ob_emlrtRSI;
    d_st.site = &pb_emlrtRSI;
    e_st.site = &qb_emlrtRSI;
    emlrtFFTWSetNumThreads(36);
    y.set_size(&ac_emlrtRTEI, &e_st, 1, x.size(1));
    emlrtFFTW_1D_C2C((real_T *)&x[0], (real_T *)&y[0], 1, x.size(1), x.size(1),
                     1, -1);
  }
}

} // namespace coder

// End of code generation (fft.cpp)
