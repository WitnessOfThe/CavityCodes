//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Chi_3_LLE_Runge_Kuarong_emxAPI.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 16-Sep-2020 20:40:18
//

// Include Files
#include <stdlib.h>
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "Chi_3_LLE_Runge_Kuarong_emxAPI.h"
#include "Chi_3_LLE_Runge_Kuarong_emxutil.h"

// Function Definitions

//
// Arguments    : int numDimensions
//                int *size
// Return Type  : emxArray_creal_T *
//
emxArray_creal_T *emxCreateND_creal_T(int numDimensions, int *size)
{
  emxArray_creal_T *emx;
  int numEl;
  int i;
  emxInit_creal_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = (creal_T *)calloc((unsigned int)numEl, sizeof(creal_T));
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  return emx;
}

//
// Arguments    : creal_T *data
//                int numDimensions
//                int *size
// Return Type  : emxArray_creal_T *
//
emxArray_creal_T *emxCreateWrapperND_creal_T(creal_T *data, int numDimensions,
  int *size)
{
  emxArray_creal_T *emx;
  int numEl;
  int i;
  emxInit_creal_T(&emx, numDimensions);
  numEl = 1;
  for (i = 0; i < numDimensions; i++) {
    numEl *= size[i];
    emx->size[i] = size[i];
  }

  emx->data = data;
  emx->numDimensions = numDimensions;
  emx->allocatedSize = numEl;
  emx->canFreeData = false;
  return emx;
}

//
// Arguments    : creal_T *data
//                int rows
//                int cols
// Return Type  : emxArray_creal_T *
//
emxArray_creal_T *emxCreateWrapper_creal_T(creal_T *data, int rows, int cols)
{
  emxArray_creal_T *emx;
  emxInit_creal_T(&emx, 2);
  emx->size[0] = rows;
  emx->size[1] = cols;
  emx->data = data;
  emx->numDimensions = 2;
  emx->allocatedSize = rows * cols;
  emx->canFreeData = false;
  return emx;
}

//
// Arguments    : int rows
//                int cols
// Return Type  : emxArray_creal_T *
//
emxArray_creal_T *emxCreate_creal_T(int rows, int cols)
{
  emxArray_creal_T *emx;
  int numEl;
  emxInit_creal_T(&emx, 2);
  emx->size[0] = rows;
  numEl = rows * cols;
  emx->size[1] = cols;
  emx->data = (creal_T *)calloc((unsigned int)numEl, sizeof(creal_T));
  emx->numDimensions = 2;
  emx->allocatedSize = numEl;
  return emx;
}

//
// Arguments    : emxArray_creal_T *emxArray
// Return Type  : void
//
void emxDestroyArray_creal_T(emxArray_creal_T *emxArray)
{
  emxFree_creal_T(&emxArray);
}

//
// Arguments    : struct6_T emxArray
// Return Type  : void
//
void emxDestroy_struct6_T(struct6_T emxArray)
{
  emxFreeStruct_struct6_T(&emxArray);
}

//
// Arguments    : struct6_T *pStruct
// Return Type  : void
//
void emxInit_struct6_T(struct6_T *pStruct)
{
  emxInitStruct_struct6_T(pStruct);
}

//
// File trailer for Chi_3_LLE_Runge_Kuarong_emxAPI.cpp
//
// [EOF]
//
