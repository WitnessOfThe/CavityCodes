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
#include "Chi_3_LLE_Kuar.h"
#include "fft1.h"
#include "fft.h"

/* Function Definitions */
void b_fft(const creal_T x[1024], creal_T y[1024])
{
  creal_T dcv1[1024];
  c_fft(x, dcv1);
  memcpy(&y[0], &dcv1[0], sizeof(creal_T) << 10);
}

/* End of code generation (fft1.c) */
