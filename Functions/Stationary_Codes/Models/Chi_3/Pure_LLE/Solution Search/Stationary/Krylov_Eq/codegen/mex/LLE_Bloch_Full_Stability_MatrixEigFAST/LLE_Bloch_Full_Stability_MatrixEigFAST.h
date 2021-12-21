/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LLE_Bloch_Full_Stability_MatrixEigFAST.h
 *
 * Code generation for function 'LLE_Bloch_Full_Stability_MatrixEigFAST'
 *
 */

#pragma once

/* Include files */
#include "LLE_Bloch_Full_Stability_MatrixEigFAST_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void LLE_Bloch_Full_Stability_MatrixEigFAST(d_LLE_Bloch_Full_Stability_Matr *SD,
  const emlrtStack *sp, const struct0_T *Stat, const creal_T FF[1048576], const
  creal_T FI[1048576], creal_T g[4194304]);

/* End of code generation (LLE_Bloch_Full_Stability_MatrixEigFAST.h) */
