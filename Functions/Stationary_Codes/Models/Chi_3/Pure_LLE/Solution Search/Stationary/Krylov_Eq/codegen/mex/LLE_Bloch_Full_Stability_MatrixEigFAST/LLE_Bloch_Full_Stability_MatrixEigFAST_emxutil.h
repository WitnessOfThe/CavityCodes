/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LLE_Bloch_Full_Stability_MatrixEigFAST_emxutil.h
 *
 * Code generation for function 'LLE_Bloch_Full_Stability_MatrixEigFAST_emxutil'
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
void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
  int32_T oldNumel, const emlrtRTEInfo *srcLocation);
void emxFreeMatrix_struct8_T(struct8_T pMatrix[64]);
void emxFreeStruct_struct0_T(struct0_T *pStruct);
void emxFreeStruct_struct7_T(struct7_T *pStruct);
void emxFreeStruct_struct8_T(struct8_T *pStruct);
void emxFree_creal_T(emxArray_creal_T **pEmxArray);
void emxFree_real_T(emxArray_real_T **pEmxArray);
void emxInitMatrix_struct8_T(const emlrtStack *sp, struct8_T pMatrix[64], const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInitStruct_struct0_T(const emlrtStack *sp, struct0_T *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInitStruct_struct7_T(const emlrtStack *sp, struct7_T *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInitStruct_struct8_T(const emlrtStack *sp, struct8_T *pStruct, const
  emlrtRTEInfo *srcLocation, boolean_T doPush);
void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray, int32_T
                     numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                     doPush);
void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray, int32_T
                    numDimensions, const emlrtRTEInfo *srcLocation, boolean_T
                    doPush);

/* End of code generation (LLE_Bloch_Full_Stability_MatrixEigFAST_emxutil.h) */
