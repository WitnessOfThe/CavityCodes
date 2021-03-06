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
#include "rt_nonfinite.h"
#include "Chi23OPO_Runge_Kuarong.h"
#include "fft.h"
#include "FFTWApi.h"

/* Function Definitions */
void c_fft(const creal_T x[256], creal_T y[256])
{
  FFTWApi_fft1d(x, false, y);
}

void fft(const creal_T x[256], creal_T y[256])
{
  FFTWApi_fft1d(x, true, y);
}

/* End of code generation (fft.c) */
