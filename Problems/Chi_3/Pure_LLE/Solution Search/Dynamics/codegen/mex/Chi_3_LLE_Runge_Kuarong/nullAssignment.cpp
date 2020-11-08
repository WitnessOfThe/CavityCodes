//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  nullAssignment.cpp
//
//  Code generation for function 'nullAssignment'
//


// Include files
#include "nullAssignment.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Variable Definitions
static emlrtRSInfo s_emlrtRSI = { 22,  // lineNo
  "nullAssignment",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo t_emlrtRSI = { 26,  // lineNo
  "nullAssignment",                    // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo u_emlrtRSI = { 283, // lineNo
  "delete_rows",                       // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo v_emlrtRSI = { 285, // lineNo
  "delete_rows",                       // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo w_emlrtRSI = { 288, // lineNo
  "delete_rows",                       // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo x_emlrtRSI = { 259, // lineNo
  "make_bitarray",                     // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRSInfo ab_emlrtRSI = { 132,// lineNo
  "num_true",                          // fcnName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pathName 
};

static emlrtRTEInfo h_emlrtRTEI = { 297,// lineNo
  1,                                   // colNo
  "delete_rows",                       // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pName 
};

static emlrtRTEInfo i_emlrtRTEI = { 81,// lineNo
  27,                                  // colNo
  "validate_inputs",                   // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pName 
};

static emlrtRTEInfo q_emlrtRTEI = { 258,// lineNo
  1,                                   // colNo
  "nullAssignment",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pName 
};

static emlrtRTEInfo r_emlrtRTEI = { 298,// lineNo
  5,                                   // colNo
  "nullAssignment",                    // fName
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\nullAssignment.m"// pName 
};

// Function Definitions
namespace coder
{
  namespace internal
  {
    void make_bitarray(const emlrtStack *sp, int32_T n, const ::coder::array<
                       int32_T, 2U> &idx, ::coder::array<boolean_T, 2U> &b)
    {
      emlrtStack b_st;
      emlrtStack st;
      int32_T b_b;
      st.prev = sp;
      st.tls = sp->tls;
      b_st.prev = &st;
      b_st.tls = st.tls;
      b.set_size((&q_emlrtRTEI), sp, 1, n);
      for (b_b = 0; b_b < n; b_b++) {
        b[b_b] = false;
      }

      b_b = idx.size(1);
      st.site = &x_emlrtRSI;
      if ((1 <= idx.size(1)) && (idx.size(1) > 2147483646)) {
        b_st.site = &y_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (int32_T k = 0; k < b_b; k++) {
        b[idx[k] - 1] = true;
      }
    }

    void nullAssignment(const emlrtStack *sp, ::coder::array<creal_T, 2U> &x,
                        const ::coder::array<int32_T, 2U> &idx)
    {
      array<creal_T, 2U> b_x;
      array<boolean_T, 2U> b;
      emlrtStack b_st;
      emlrtStack c_st;
      emlrtStack d_st;
      emlrtStack st;
      int32_T i;
      int32_T k;
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
      d_st.prev = &c_st;
      d_st.tls = c_st.tls;
      emlrtHeapReferenceStackEnterFcnR2012b(sp);
      st.site = &s_emlrtRSI;
      p = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= idx.size(1) - 1)) {
        if (idx[k] > x.size(0)) {
          p = false;
          exitg1 = true;
        } else {
          k++;
        }
      }

      if (!p) {
        emlrtErrorWithMessageIdR2018a(&st, &i_emlrtRTEI,
          "MATLAB:subsdeldimmismatch", "MATLAB:subsdeldimmismatch", 0);
      }

      st.site = &t_emlrtRSI;
      nrowx = x.size(0);
      if (idx.size(1) == 1) {
        nrows = x.size(0) - 1;
        k = idx[0];
        for (int32_T j = 0; j < 600; j++) {
          for (i = k; i <= nrows; i++) {
            x[(i + x.size(0) * j) - 1] = x[i + x.size(0) * j];
          }
        }
      } else {
        b_st.site = &u_emlrtRSI;
        make_bitarray(&b_st, x.size(0), idx, b);
        b_st.site = &v_emlrtRSI;
        nrows = 0;
        i = b.size(1);
        c_st.site = &ab_emlrtRSI;
        if ((1 <= b.size(1)) && (b.size(1) > 2147483646)) {
          d_st.site = &y_emlrtRSI;
          check_forloop_overflow_error(&d_st);
        }

        for (k = 0; k < i; k++) {
          nrows += b[k];
        }

        nrows = x.size(0) - nrows;
        i = 0;
        b_st.site = &w_emlrtRSI;
        if ((1 <= x.size(0)) && (x.size(0) > 2147483646)) {
          c_st.site = &y_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (k = 0; k < nrowx; k++) {
          if ((k + 1 > b.size(1)) || (!b[k])) {
            for (int32_T j = 0; j < 600; j++) {
              x[i + x.size(0) * j] = x[k + x.size(0) * j];
            }

            i++;
          }
        }
      }

      if (nrows > nrowx) {
        emlrtErrorWithMessageIdR2018a(&st, &h_emlrtRTEI,
          "Coder:builtins:AssertionFailed", "Coder:builtins:AssertionFailed", 0);
      }

      if (1 > nrows) {
        nrows = 0;
      }

      b_x.set_size((&r_emlrtRTEI), (&st), nrows, 600);
      for (k = 0; k < 600; k++) {
        for (i = 0; i < nrows; i++) {
          b_x[i + b_x.size(0) * k] = x[i + x.size(0) * k];
        }
      }

      x.set_size((&r_emlrtRTEI), (&st), b_x.size(0), 600);
      nrows = b_x.size(0);
      for (k = 0; k < 600; k++) {
        for (i = 0; i < nrows; i++) {
          x[i + x.size(0) * k] = b_x[i + b_x.size(0) * k];
        }
      }

      emlrtHeapReferenceStackLeaveFcnR2012b(sp);
    }

    int32_T num_true(const emlrtStack *sp, const ::coder::array<boolean_T, 2U>
                     &b)
    {
      emlrtStack b_st;
      emlrtStack st;
      int32_T b_b;
      int32_T n;
      st.prev = sp;
      st.tls = sp->tls;
      b_st.prev = &st;
      b_st.tls = st.tls;
      n = 0;
      b_b = b.size(1);
      st.site = &ab_emlrtRSI;
      if ((1 <= b.size(1)) && (b.size(1) > 2147483646)) {
        b_st.site = &y_emlrtRSI;
        check_forloop_overflow_error(&b_st);
      }

      for (int32_T k = 0; k < b_b; k++) {
        n += b[k];
      }

      return n;
    }
  }
}

// End of code generation (nullAssignment.cpp)
