//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Chi_3_LLE_Runge_Kuarong_emxutil.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 16-Sep-2020 20:40:18
//
#ifndef CHI_3_LLE_RUNGE_KUARONG_EMXUTIL_H
#define CHI_3_LLE_RUNGE_KUARONG_EMXUTIL_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Chi_3_LLE_Runge_Kuarong_types.h"

// Function Declarations
extern void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int oldNumel);
extern void emxEnsureCapacity_cuint8_T(emxArray_cuint8_T *emxArray, int oldNumel);
extern void emxFreeStruct_struct6_T(struct6_T *pStruct);
extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);
extern void emxFree_cuint8_T(emxArray_cuint8_T **pEmxArray);
extern void emxInitStruct_struct6_T(struct6_T *pStruct);
extern void emxInit_creal_T(emxArray_creal_T **pEmxArray, int numDimensions);
extern void emxInit_cuint8_T(emxArray_cuint8_T **pEmxArray, int numDimensions);

#endif

//
// File trailer for Chi_3_LLE_Runge_Kuarong_emxutil.h
//
// [EOF]
//
