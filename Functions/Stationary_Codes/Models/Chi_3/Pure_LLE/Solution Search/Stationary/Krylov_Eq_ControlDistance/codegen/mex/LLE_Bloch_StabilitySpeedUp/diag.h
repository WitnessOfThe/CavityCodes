/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * diag.h
 *
 * Code generation for function 'diag'
 *
 */

#pragma once

/* Include files */
#include "LLE_Bloch_StabilitySpeedUp_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_diag(const real_T v[512], real_T d[262144]);
void c_diag(const emlrtStack *sp, const emxArray_creal_T *v, emxArray_creal_T *d);
void diag(const creal_T v[512], creal_T d[262144]);

/* End of code generation (diag.h) */
