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
#include "Chi_3_LLE_Kuar.h"
#include "fft.h"
#include "FFTWApi.h"

/* Function Definitions */
void c_fft(const creal_T x[1024], creal_T y[1024])
{
  FFTWApi_fft1d(x, 1, false, y);
}

void fft(const creal_T x[1024], creal_T y[1024])
{
  FFTWApi_fft1d(x, 1, true, y);
}

/* End of code generation (fft.c) */
