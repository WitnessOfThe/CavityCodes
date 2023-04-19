//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi23_Runge_Kuarong_GPU_emxutil.cu
//
// Code generation for function 'Chi23_Runge_Kuarong_GPU_emxutil'
//

// Include files
#include "Chi23_Runge_Kuarong_GPU_emxutil.h"
#include "Chi23_Runge_Kuarong_GPU_data.h"
#include "Chi23_Runge_Kuarong_GPU_types.h"
#include "rt_nonfinite.h"
#include <algorithm>

// Function Definitions
void emxEnsureCapacity_creal_T(emxArray_creal_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(creal_T));
    if (emxArray->data != nullptr) {
      std::copy(emxArray->data,
                emxArray->data + static_cast<uint32_T>(oldNumel),
                (creal_T *)newData);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (creal_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_cuint8_T(emxArray_cuint8_T *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
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
        i *= 2;
      }
    }
    newData = emlrtCallocMex(static_cast<uint32_T>(i), sizeof(cuint8_T));
    if (emxArray->data != nullptr) {
      std::copy(emxArray->data,
                emxArray->data + static_cast<uint32_T>(oldNumel),
                (cuint8_T *)newData);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cuint8_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxFreeStruct_struct8_T(struct8_T *pStruct)
{
  emxFree_creal_T(&pStruct->Psio);
  emxFree_creal_T(&pStruct->Psie);
  emxFree_creal_T(&pStruct->t);
}

void emxFree_creal_T(emxArray_creal_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_creal_T *)nullptr) {
    if (((*pEmxArray)->data != (creal_T *)nullptr) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference(emlrtRootTLSGlobal, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_creal_T *)nullptr;
  }
}

void emxFree_cuint8_T(emxArray_cuint8_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_cuint8_T *)nullptr) {
    if (((*pEmxArray)->data != (cuint8_T *)nullptr) &&
        (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference(emlrtRootTLSGlobal, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cuint8_T *)nullptr;
  }
}

void emxInitStruct_struct8_T(struct8_T *pStruct, boolean_T doPush)
{
  emxInit_creal_T(&pStruct->Psio, 2, doPush);
  emxInit_creal_T(&pStruct->Psie, 2, doPush);
  emxInit_creal_T(&pStruct->t, 2, doPush);
}

void emxInit_creal_T(emxArray_creal_T **pEmxArray, int32_T numDimensions,
                     boolean_T doPush)
{
  emxArray_creal_T *emxArray;
  *pEmxArray =
      (emxArray_creal_T *)emlrtMallocEmxArray(sizeof(emxArray_creal_T));
  if (doPush) {
    emlrtPushHeapReferenceStackEmxArray(
        emlrtRootTLSGlobal, false, (void *)pEmxArray, (void *)&emxFree_creal_T,
        nullptr, nullptr, nullptr);
  }
  emxArray = *pEmxArray;
  emxArray->data = (creal_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i{0}; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_cuint8_T(emxArray_cuint8_T **pEmxArray, int32_T numDimensions,
                      boolean_T doPush)
{
  emxArray_cuint8_T *emxArray;
  *pEmxArray =
      (emxArray_cuint8_T *)emlrtMallocEmxArray(sizeof(emxArray_cuint8_T));
  if (doPush) {
    emlrtPushHeapReferenceStackEmxArray(
        emlrtRootTLSGlobal, false, (void *)pEmxArray, (void *)&emxFree_cuint8_T,
        nullptr, nullptr, nullptr);
  }
  emxArray = *pEmxArray;
  emxArray->data = (cuint8_T *)nullptr;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (int32_T i{0}; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

// End of code generation (Chi23_Runge_Kuarong_GPU_emxutil.cu)
