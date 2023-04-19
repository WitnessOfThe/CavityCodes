//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi23_Runge_Kuarong_GPU_emxutil.h
//
// Code generation for function 'Chi23_Runge_Kuarong_GPU_emxutil'
//

#pragma once

// Include files
#include "Chi23_Runge_Kuarong_GPU_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Custom Header Code

#ifdef __CUDA_ARCH__
#undef printf
#endif

// Function Declarations
void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int32_T oldNumel);

void emxEnsureCapacity_cuint8_T(emxArray_cuint8_T *emxArray, int32_T oldNumel);

void emxFreeStruct_struct8_T(struct8_T *pStruct);

void emxFree_creal_T(emxArray_creal_T **pEmxArray);

void emxFree_cuint8_T(emxArray_cuint8_T **pEmxArray);

void emxInitStruct_struct8_T(struct8_T *pStruct, boolean_T doPush);

void emxInit_creal_T(emxArray_creal_T **pEmxArray, int32_T numDimensions,
                     boolean_T doPush);

void emxInit_cuint8_T(emxArray_cuint8_T **pEmxArray, int32_T numDimensions,
                      boolean_T doPush);

// End of code generation (Chi23_Runge_Kuarong_GPU_emxutil.h)
