/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.cpp
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include <string.h>
#include "rt_nonfinite.h"
#include "Split_chi_2.h"
#include "fft.h"
#include "fft1.h"

/* Function Definitions */
void fft(const creal_T x_data[], const int32_T x_size[2], creal_T y_data[],
         int32_T y_size[2])
{
  int32_T x[1];
  creal_T y1_data[64];
  int32_T y1_size[1];
  x[0] = x_size[1];
  b_fft(x_data, x, x_size[1], y1_data, y1_size);
  y_size[0] = 1;
  y_size[1] = x_size[1];
  if (0 <= x_size[1] - 1) {
    memcpy(&y_data[0], &y1_data[0], (uint32_T)(x_size[1] * (int32_T)sizeof
            (creal_T)));
  }
}

/* End of code generation (fft.cpp) */
