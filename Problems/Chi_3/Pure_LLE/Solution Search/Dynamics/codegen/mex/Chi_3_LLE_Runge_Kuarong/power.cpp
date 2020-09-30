/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.cpp
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "power.h"

/* Function Definitions */
void power(const real_T a[2048], real_T y[2048])
{
  int32_T k;
  for (k = 0; k < 2048; k++) {
    y[k] = a[k] * a[k];
  }
}

/* End of code generation (power.cpp) */
