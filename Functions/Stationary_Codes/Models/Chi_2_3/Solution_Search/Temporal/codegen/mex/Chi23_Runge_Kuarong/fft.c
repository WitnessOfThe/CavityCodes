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
#include "rt_nonfinite.h"

/* Function Definitions */
void fft(const creal_T x[256], creal_T y[256])
{
  emlrtFFTWSetNumThreads(6);
  emlrtFFTW_1D_C2C((real_T *)&x[0], (real_T *)&y[0], 1, 256, 256, 1, -1);
}

/* End of code generation (fft.c) */
