/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft1.c
 *
 * Code generation for function 'fft1'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Chi23OPO_Runge_Kuarong.h"
#include "fft1.h"
#include "FFTWApi.h"

/* Function Definitions */
void fft(const creal_T x[128], creal_T y[128])
{
  creal_T dcv2[128];
  FFTWApi_fft1d(x, false, dcv2);
  memcpy(&y[0], &dcv2[0], sizeof(creal_T) << 7);
}

/* End of code generation (fft1.c) */
