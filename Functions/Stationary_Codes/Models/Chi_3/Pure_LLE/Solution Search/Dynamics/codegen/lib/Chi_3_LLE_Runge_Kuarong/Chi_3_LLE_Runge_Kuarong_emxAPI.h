//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Chi_3_LLE_Runge_Kuarong_emxAPI.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 16-Sep-2020 20:40:18
//
#ifndef CHI_3_LLE_RUNGE_KUARONG_EMXAPI_H
#define CHI_3_LLE_RUNGE_KUARONG_EMXAPI_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Chi_3_LLE_Runge_Kuarong_types.h"

// Function Declarations
extern emxArray_creal_T *emxCreateND_creal_T(int numDimensions, int *size);
extern emxArray_creal_T *emxCreateWrapperND_creal_T(creal_T *data, int
  numDimensions, int *size);
extern emxArray_creal_T *emxCreateWrapper_creal_T(creal_T *data, int rows, int
  cols);
extern emxArray_creal_T *emxCreate_creal_T(int rows, int cols);
extern void emxDestroyArray_creal_T(emxArray_creal_T *emxArray);
extern void emxDestroy_struct6_T(struct6_T emxArray);
extern void emxInit_struct6_T(struct6_T *pStruct);

#endif

//
// File trailer for Chi_3_LLE_Runge_Kuarong_emxAPI.h
//
// [EOF]
//
