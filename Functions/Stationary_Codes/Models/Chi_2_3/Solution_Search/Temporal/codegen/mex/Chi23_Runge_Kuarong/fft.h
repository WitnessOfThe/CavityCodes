/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fft.h
 *
 * Code generation for function 'fft'
 *
 */

#ifndef FFT_H
#define FFT_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "Chi23_Runge_Kuarong_types.h"

/* Function Declarations */
extern void c_fft(const creal_T x[256], creal_T y[256]);
extern void fft(const creal_T x[256], creal_T y[256]);

#endif

/* End of code generation (fft.h) */
