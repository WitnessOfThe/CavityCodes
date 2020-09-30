/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ifft.cpp
 *
 * Code generation for function 'ifft'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "ifft.h"
#include "fft.h"

/* Function Definitions */
void ifft(const creal_T x[2048], creal_T y[2048])
{
  creal_T dcv1[2048];
  fft(x, dcv1);
  memcpy(&y[0], &dcv1[0], sizeof(creal_T) << 11);
}

/* End of code generation (ifft.cpp) */
