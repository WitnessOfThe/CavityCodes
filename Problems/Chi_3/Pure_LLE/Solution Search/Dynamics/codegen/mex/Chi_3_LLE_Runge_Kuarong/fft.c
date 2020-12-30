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
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "fft.h"
#include "FFTWApi.h"

/* Function Definitions */
void b_fft(const creal_T x[512], creal_T y[512])
{
  FFTWApi_fft1d(x, false, y);
}

void fft(const creal_T x[512], creal_T y[512])
{
  FFTWApi_fft1d(x, true, y);
}

/* End of code generation (fft.c) */
