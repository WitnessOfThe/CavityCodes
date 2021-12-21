/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeev.c
 *
 * Code generation for function 'xgeev'
 *
 */

/* Include files */
#include "xgeev.h"
#include "LLE_Bloch_StabilitySpeedUp_data.h"
#include "LLE_Bloch_StabilitySpeedUp_types.h"
#include "rt_nonfinite.h"
#include "lapacke.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo yb_emlrtRSI = { 36, /* lineNo */
  "xgeev",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeev.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 182,/* lineNo */
  "ceval_xgeev",                       /* fcnName */
  "C:\\Program Files\\MATLAB\\R2020b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeev.m"/* pathName */
};

/* Function Definitions */
void xgeev(c_LLE_Bloch_StabilitySpeedUpSta *SD, const emlrtStack *sp, const
           creal_T A[1048576], int32_T *info, creal_T W[1024], creal_T VR
           [1048576])
{
  static const char_T fname[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'z',
    'g', 'e', 'e', 'v', 'x' };

  ptrdiff_t ihi_t;
  ptrdiff_t ilo_t;
  ptrdiff_t info_t;
  emlrtStack b_st;
  emlrtStack st;
  creal_T vl;
  real_T scale[1024];
  real_T abnrm;
  real_T rconde;
  real_T rcondv;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  memcpy(&SD->u1.f0.A[0], &A[0], 1048576U * sizeof(creal_T));
  info_t = LAPACKE_zgeevx(102, 'B', 'N', 'V', 'N', (ptrdiff_t)1024,
    (lapack_complex_double *)&SD->u1.f0.A[0], (ptrdiff_t)1024,
    (lapack_complex_double *)&W[0], (lapack_complex_double *)&vl, (ptrdiff_t)1,
    (lapack_complex_double *)&VR[0], (ptrdiff_t)1024, &ilo_t, &ihi_t, &scale[0],
    &abnrm, &rconde, &rcondv);
  *info = (int32_T)info_t;
  b_st.site = &ac_emlrtRSI;
  if (*info < 0) {
    if (*info == -1010) {
      emlrtErrorWithMessageIdR2018a(&b_st, &d_emlrtRTEI, "MATLAB:nomem",
        "MATLAB:nomem", 0);
    } else {
      emlrtErrorWithMessageIdR2018a(&b_st, &e_emlrtRTEI,
        "Coder:toolbox:LAPACKCallErrorInfo", "Coder:toolbox:LAPACKCallErrorInfo",
        5, 4, 14, fname, 12, *info);
    }
  }
}

/* End of code generation (xgeev.c) */
