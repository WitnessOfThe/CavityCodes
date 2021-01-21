//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: power.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 16-Sep-2020 20:40:18
//

// Include Files
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "power.h"

// Function Definitions

//
// Arguments    : const double a[1024]
//                double y[1024]
// Return Type  : void
//
void power(const double a[1024], double y[1024])
{
  int k;
  for (k = 0; k < 1024; k++) {
    y[k] = a[k] * a[k];
  }
}

//
// File trailer for power.cpp
//
// [EOF]
//
