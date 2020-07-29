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
#include "rt_nonfinite.h"
#include "Split_chi_2.h"
#include "fft1.h"
#include "FFTWApi.h"

/* Function Definitions */
void b_fft(const creal_T x_data[], const int32_T x_size[1], int32_T n, creal_T
           y_data[], int32_T y_size[1])
{
  int32_T i13;
  cuint8_T b_y_data[256];
  if ((x_size[0] == 0) || (n == 0)) {
    if (n > x_size[0]) {
      for (i13 = 0; i13 < n; i13++) {
        b_y_data[i13].re = 0U;
        b_y_data[i13].im = 0U;
      }
    }

    y_size[0] = n;
    for (i13 = 0; i13 < n; i13++) {
      y_data[i13].re = 0.0;
      y_data[i13].im = b_y_data[i13].im;
    }
  } else {
    FFTWApi_fft1d(x_data, x_size, n, y_data, y_size);
  }
}

/* End of code generation (fft1.cpp) */
