/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * exp.h
 *
 * Code generation for function 'exp'
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
void b_exp(const emlrtStack *sp, emxArray_real_T *x);

void c_exp(const emlrtStack *sp, emxArray_creal_T *x);

/* End of code generation (exp.h) */
