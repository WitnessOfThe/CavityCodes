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
#include "fft.h"

/* Function Definitions */
void ifft(const creal_T x[256], creal_T y[256])
{
  creal_T dcv1[256];
  fft(x, dcv1);
  memcpy(&y[0], &dcv1[0], sizeof(creal_T) << 8);
}

/* End of code generation (ifft.c) */
