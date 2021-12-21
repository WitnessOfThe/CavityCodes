/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgeev.h
 *
 * Code generation for function 'xgeev'
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
void xgeev(c_LLE_Bloch_StabilitySpeedUpSta *SD, const emlrtStack *sp, const
           creal_T A[1048576], int32_T *info, creal_T W[1024], creal_T VR
           [1048576]);

/* End of code generation (xgeev.h) */
