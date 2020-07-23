/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Split_chi_2_emxutil.h
 *
 * Code generation for function 'Split_chi_2_emxutil'
 *
 */

#ifndef SPLIT_CHI_2_EMXUTIL_H
#define SPLIT_CHI_2_EMXUTIL_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "Split_chi_2_types.h"

/* Function Declarations */
extern void c_emxFreeStruct_coder_internal_(coder_internal_ref_2 *pStruct);
extern void c_emxInitStruct_coder_internal_(const emlrtStack *sp,
  coder_internal_ref_2 *pStruct, const emlrtRTEInfo *srcLocation, boolean_T
  doPush);
extern void emxEnsureCapacity_creal_T(const emlrtStack *sp, emxArray_creal_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T
  *emxArray, int32_T oldNumel, const emlrtRTEInfo *srcLocation);
extern void emxFreeStruct_struct2_T(struct2_T *pStruct);
extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);
extern void emxFree_int32_T(emxArray_int32_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInitStruct_struct2_T(const emlrtStack *sp, struct2_T *pStruct,
  const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_creal_T(const emlrtStack *sp, emxArray_creal_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);
extern void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, const emlrtRTEInfo *srcLocation, boolean_T doPush);

#endif

/* End of code generation (Split_chi_2_emxutil.h) */
