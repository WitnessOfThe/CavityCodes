/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FullField_SingleProgection_dynamics_emxutil.h
 *
 * Code generation for function 'FullField_SingleProgection_dynamics_emxutil'
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
void emxEnsureCapacity_boolean_T(const emlrtStack *sp,
                                 emxArray_boolean_T *emxArray, int32_T oldNumel,
                                 const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_char_T(const emlrtStack *sp, emxArray_char_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxFreeStruct_captured_var(const emlrtStack *sp, e_captured_var *pStruct);

void emxFreeStruct_captured_var1(const emlrtStack *sp, f_captured_var *pStruct);

void emxFreeStruct_struct8_T(const emlrtStack *sp, struct8_T *pStruct);

void emxFree_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray);

void emxFree_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray);

void emxFree_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray);

void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxInitStruct_captured_var(const emlrtStack *sp, e_captured_var *pStruct,
                                const emlrtRTEInfo *srcLocation);

void emxInitStruct_captured_var1(const emlrtStack *sp, f_captured_var *pStruct,
                                 const emlrtRTEInfo *srcLocation);

void emxInitStruct_struct8_T(const emlrtStack *sp, struct8_T *pStruct,
                             const emlrtRTEInfo *srcLocation);

void emxInit_boolean_T(const emlrtStack *sp, emxArray_boolean_T **pEmxArray,
                       const emlrtRTEInfo *srcLocation);

void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation);

void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                     const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation);

/* End of code generation (FullField_SingleProgection_dynamics_emxutil.h) */
