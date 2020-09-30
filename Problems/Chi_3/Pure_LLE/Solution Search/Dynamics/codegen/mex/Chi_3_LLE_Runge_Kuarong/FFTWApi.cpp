/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FFTWApi.cpp
 *
 * Code generation for function 'FFTWApi'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "FFTWApi.h"
#include "emlrt.h"

/* Function Definitions */
void FFTWApi_fft1d(const creal_T data[2048], boolean_T isInverse, creal_T y[2048])
{
  int32_T b_isInverse;
  emlrtFFTWSetNumThreads(36);
  if (isInverse) {
    b_isInverse = 1;
  } else {
    b_isInverse = -1;
  }

  emlrtFFTW_1D_C2C((real_T *)&data[0], (real_T *)&y[0], 1, 2048, 2048, 1,
                   b_isInverse);
}

/* End of code generation (FFTWApi.cpp) */
