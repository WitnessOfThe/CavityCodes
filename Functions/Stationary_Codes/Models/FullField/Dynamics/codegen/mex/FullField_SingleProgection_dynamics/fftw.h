/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * fftw.h
 *
 * Code generation for function 'fftw'
 *
 */

#pragma once

/* Include files */
#include "FullField_SingleProgection_dynamics_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_fftw(const emlrtStack *sp, emxArray_char_T *out);

void c_fftw(const emlrtStack *sp, const emxArray_char_T *info);

void fftw(const emlrtStack *sp);

/* End of code generation (fftw.h) */
