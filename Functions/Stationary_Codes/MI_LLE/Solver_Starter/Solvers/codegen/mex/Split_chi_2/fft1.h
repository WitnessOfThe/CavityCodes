/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft1.h
 *
 * Code generation for function 'fft1'
 *
 */

#ifndef FFT1_H
#define FFT1_H

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
extern void b_fft(const creal_T x_data[], const int32_T x_size[1], int32_T n,
                  creal_T y_data[], int32_T y_size[1]);

#endif

/* End of code generation (fft1.h) */
