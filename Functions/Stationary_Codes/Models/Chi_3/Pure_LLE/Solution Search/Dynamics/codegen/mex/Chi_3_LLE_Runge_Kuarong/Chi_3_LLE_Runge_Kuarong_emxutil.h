/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi_3_LLE_Runge_Kuarong_emxutil.h
 *
 * Code generation for function 'Chi_3_LLE_Runge_Kuarong_emxutil'
 *
 */

#pragma once

/* Include files */
#include "Chi_3_LLE_Runge_Kuarong_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cuint8_T(const emlrtStack *sp,
                                emxArray_cuint8_T *emxArray, int32_T oldNumel,
                                const emlrtRTEInfo *srcLocation);

void emxFreeStruct_struct6_T(const emlrtStack *sp, struct6_T *pStruct);

void emxFree_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray);

void emxFree_cuint8_T(const emlrtStack *sp, emxArray_cuint8_T **pEmxArray);

void emxInitStruct_struct6_T(const emlrtStack *sp, struct6_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

void emxInit_cuint8_T(const emlrtStack *sp, emxArray_cuint8_T **pEmxArray,
                      const emlrtRTEInfo *srcLocation);

/* End of code generation (Chi_3_LLE_Runge_Kuarong_emxutil.h) */
