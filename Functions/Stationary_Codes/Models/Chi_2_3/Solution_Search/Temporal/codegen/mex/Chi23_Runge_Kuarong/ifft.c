/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ifft.c
 *
 * Code generation for function 'ifft'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Chi23_Runge_Kuarong.h"
#include "ifft.h"
#include "FFTWApi.h"

/* Function Definitions */
void ifft(const creal_T x[128], creal_T y[128])
{
  creal_T dcv1[128];
  FFTWApi_fft1d(x, true, dcv1);
  memcpy(&y[0], &dcv1[0], sizeof(creal_T) << 7);
}

/* End of code generation (ifft.c) */
