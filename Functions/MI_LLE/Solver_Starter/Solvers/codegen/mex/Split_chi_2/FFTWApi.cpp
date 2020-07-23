/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FFTWApi.cpp
 *
 * Code generation for function 'FFTWApi'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Split_chi_2.h"
#include "FFTWApi.h"
#include "emlrt.h"

/* Function Definitions */
void FFTWApi_fft1d(const creal_T data_data[], const int32_T data_size[1],
                   int32_T fftlen, creal_T y_data[], int32_T y_size[1])
{
  int32_T i14;
  cuint8_T b_y_data[256];
  emlrtFFTWSetNumThreads(36);
  if (fftlen > data_size[0]) {
    for (i14 = 0; i14 < fftlen; i14++) {
      b_y_data[i14].re = 0U;
      b_y_data[i14].im = 0U;
    }
  }

  y_size[0] = fftlen;
  for (i14 = 0; i14 < fftlen; i14++) {
    y_data[i14].re = 0.0;
    y_data[i14].im = b_y_data[i14].im;
  }

  emlrtFFTW_1D_C2C((real_T *)&data_data[0], (real_T *)&y_data[0], 1, fftlen,
                   data_size[0], 1, -1);
}

void b_FFTWApi_fft1d(const creal_T data_data[], const int32_T data_size[1],
                     int32_T fftlen, creal_T y_data[], int32_T y_size[1])
{
  int32_T i15;
  cuint8_T b_y_data[256];
  emlrtFFTWSetNumThreads(36);
  if (fftlen > data_size[0]) {
    for (i15 = 0; i15 < fftlen; i15++) {
      b_y_data[i15].re = 0U;
      b_y_data[i15].im = 0U;
    }
  }

  y_size[0] = fftlen;
  for (i15 = 0; i15 < fftlen; i15++) {
    y_data[i15].re = 0.0;
    y_data[i15].im = b_y_data[i15].im;
  }

  emlrtFFTW_1D_C2C((real_T *)&data_data[0], (real_T *)&y_data[0], 1, fftlen,
                   data_size[0], 1, 1);
}

/* End of code generation (FFTWApi.cpp) */
