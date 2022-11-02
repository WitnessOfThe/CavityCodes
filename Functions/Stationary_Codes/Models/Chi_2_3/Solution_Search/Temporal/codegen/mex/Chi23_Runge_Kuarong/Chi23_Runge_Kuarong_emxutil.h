/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi23_Runge_Kuarong_emxutil.h
 *
 * Code generation for function 'Chi23_Runge_Kuarong_emxutil'
 *
 */

#pragma once

/* Include files */
#include "Chi23_Runge_Kuarong_types.h"
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

void emxFreeStruct_struct8_T(const emlrtStack *sp, struct8_T *pStruct);

void emxFree_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray);

void emxFree_cuint8_T(const emlrtStack *sp, emxArray_cuint8_T **pEmxArray);

void emxInitStruct_struct8_T(const emlrtStack *sp, struct8_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

void emxInit_cuint8_T(const emlrtStack *sp, emxArray_cuint8_T **pEmxArray,
                      const emlrtRTEInfo *srcLocation);

/* End of code generation (Chi23_Runge_Kuarong_emxutil.h) */
