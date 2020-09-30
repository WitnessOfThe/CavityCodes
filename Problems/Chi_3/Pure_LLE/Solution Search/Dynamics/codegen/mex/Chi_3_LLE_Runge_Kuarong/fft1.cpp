/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft1.cpp
 *
 * Code generation for function 'fft1'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "fft1.h"
#include "fft.h"

/* Function Definitions */
void b_fft(const creal_T x[2048], creal_T y[2048])
{
  creal_T dcv2[2048];
  c_fft(x, dcv2);
  memcpy(&y[0], &dcv2[0], sizeof(creal_T) << 11);
}

/* End of code generation (fft1.cpp) */
