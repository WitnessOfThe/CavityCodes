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
#include "Chi23OPO_Runge_Kuarong_types.h"

/* Function Declarations */
extern void FFTWApi_fft1d(const creal_T data[256], boolean_T isInverse, creal_T
  y[256]);

#endif

/* End of code generation (FFTWApi.h) */
