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
#include "Split_chi_2.h"
#include "power.h"

/* Function Definitions */
void power(const creal_T a_data[], const int32_T a_size[2], creal_T y_data[],
           int32_T y_size[2])
{
  int32_T nx;
  int32_T k;
  y_size[0] = 1;
  y_size[1] = (int8_T)a_size[1];
  nx = (int8_T)a_size[1];
  for (k = 0; k < nx; k++) {
    y_data[k].re = a_data[k].re * a_data[k].re - a_data[k].im * a_data[k].im;
    y_data[k].im = a_data[k].re * a_data[k].im + a_data[k].im * a_data[k].re;
  }
}

/* End of code generation (power.cpp) */
