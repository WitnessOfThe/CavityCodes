/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LLE_Bloch_StabilitySpeedUp.h
 *
 * Code generation for function 'LLE_Bloch_StabilitySpeedUp'
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
void LLE_Bloch_StabilitySpeedUp(c_LLE_Bloch_StabilitySpeedUpSta *SD, const
  emlrtStack *sp, const struct0_T *Stat, const creal_T FF[262144], const creal_T
  FI[262144], creal_T Vectors[1048576], creal_T Valuestemp[1048576], creal_T
  VectorsStar[1048576], creal_T ValuesStartemp[1048576]);

/* End of code generation (LLE_Bloch_StabilitySpeedUp.h) */
