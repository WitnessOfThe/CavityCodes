/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FFTWApi.h
 *
 * Code generation for function 'FFTWApi'
 *
 */

#ifndef FFTWAPI_H
#define FFTWAPI_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "Split_chi_2_types.h"

/* Function Declarations */
extern void FFTWApi_fft1d(const creal_T data_data[], const int32_T data_size[1],
  int32_T fftlen, creal_T y_data[], int32_T y_size[1]);
extern void b_FFTWApi_fft1d(const creal_T data_data[], const int32_T data_size[1],
  int32_T fftlen, creal_T y_data[], int32_T y_size[1]);

#endif

/* End of code generation (FFTWApi.h) */
