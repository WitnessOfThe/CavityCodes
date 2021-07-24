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
#include "Chi23OPO_Runge_Kuarong.h"
#include "ifft.h"
#include "FFTWApi.h"

/* Function Definitions */
void ifft(const creal_T x[32], creal_T y[32])
{
  creal_T dcv0[32];
  FFTWApi_fft1d(x, true, dcv0);
  memcpy(&y[0], &dcv0[0], sizeof(creal_T) << 5);
}

/* End of code generation (ifft.c) */
