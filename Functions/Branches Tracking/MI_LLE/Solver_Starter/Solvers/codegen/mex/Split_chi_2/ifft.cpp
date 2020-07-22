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
#include "Split_chi_2.h"
#include "ifft.h"
#include "FFTWApi.h"

/* Function Definitions */
void ifft(const creal_T x_data[], const int32_T x_size[2], creal_T y_data[],
          int32_T y_size[2])
{
  int32_T x[1];
  creal_T y1_data[32];
  int32_T y1_size[1];
  if (x_size[1] == 0) {
  } else {
    x[0] = x_size[1];
    b_FFTWApi_fft1d(x_data, x, x_size[1], y1_data, y1_size);
  }

  y_size[0] = 1;
  y_size[1] = x_size[1];
  if (0 <= x_size[1] - 1) {
    memcpy(&y_data[0], &y1_data[0], (uint32_T)(x_size[1] * (int32_T)sizeof
            (creal_T)));
  }
}

/* End of code generation (ifft.cpp) */
