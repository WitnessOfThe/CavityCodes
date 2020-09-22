//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Chi_3_LLE_Runge_Kuarong_emxutil.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 16-Sep-2020 20:40:18
//

// Include Files
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "Chi_3_LLE_Runge_Kuarong_emxutil.h"

// Function Definitions

//
// Arguments    : emxArray_creal_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(creal_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(creal_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (creal_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : emxArray_cuint8_T *emxArray
//                int oldNumel
// Return Type  : void
//
void emxEnsureCapacity_cuint8_T(emxArray_cuint8_T *emxArray, int oldNumel)
{
  int newNumel;
  int i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = calloc((unsigned int)i, sizeof(cuint8_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cuint8_T) * oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (cuint8_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

//
// Arguments    : struct6_T *pStruct
// Return Type  : void
//
void emxFreeStruct_struct6_T(struct6_T *pStruct)
{
  emxFree_creal_T(&pStruct->Psi);
  emxFree_creal_T(&pStruct->t);
}

//
// Arguments    : emxArray_creal_T **pEmxArray
// Return Type  : void
//
void emxFree_creal_T(emxArray_creal_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_creal_T *)NULL) {
    if (((*pEmxArray)->data != (creal_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_creal_T *)NULL;
  }
}

//
// Arguments    : emxArray_cuint8_T **pEmxArray
// Return Type  : void
//
void emxFree_cuint8_T(emxArray_cuint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_cuint8_T *)NULL) {
    if (((*pEmxArray)->data != (cuint8_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_cuint8_T *)NULL;
  }
}

//
// Arguments    : struct6_T *pStruct
// Return Type  : void
//
void emxInitStruct_struct6_T(struct6_T *pStruct)
{
  emxInit_creal_T(&pStruct->Psi, 2);
  emxInit_creal_T(&pStruct->t, 2);
}

//
// Arguments    : emxArray_creal_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_creal_T(emxArray_creal_T **pEmxArray, int numDimensions)
{
  emxArray_creal_T *emxArray;
  int i;
  *pEmxArray = (emxArray_creal_T *)malloc(sizeof(emxArray_creal_T));
  emxArray = *pEmxArray;
  emxArray->data = (creal_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// Arguments    : emxArray_cuint8_T **pEmxArray
//                int numDimensions
// Return Type  : void
//
void emxInit_cuint8_T(emxArray_cuint8_T **pEmxArray, int numDimensions)
{
  emxArray_cuint8_T *emxArray;
  int i;
  *pEmxArray = (emxArray_cuint8_T *)malloc(sizeof(emxArray_cuint8_T));
  emxArray = *pEmxArray;
  emxArray->data = (cuint8_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int *)malloc(sizeof(int) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

//
// File trailer for Chi_3_LLE_Runge_Kuarong_emxutil.cpp
//
// [EOF]
//
