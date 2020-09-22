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
#include "Chi_3_LLE_Kuar.h"
#include "ifft.h"
#include "fft.h"

/* Function Definitions */
void ifft(const creal_T x[1024], creal_T y[1024])
{
  creal_T dcv0[1024];
  fft(x, dcv0);
  memcpy(&y[0], &dcv0[0], sizeof(creal_T) << 10);
}

/* End of code generation (ifft.c) */
