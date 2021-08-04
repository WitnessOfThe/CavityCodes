/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Chi23OPO_Runge_Kuarong.h"
#include "power.h"

/* Function Definitions */
void b_power(const creal_T a[128], creal_T y[128])
{
  int32_T k;
  for (k = 0; k < 128; k++) {
    y[k].re = a[k].re * a[k].re - a[k].im * a[k].im;
    y[k].im = a[k].re * a[k].im + a[k].im * a[k].re;
  }
}

void power(const real_T a[128], real_T y[128])
{
  int32_T k;
  for (k = 0; k < 128; k++) {
    y[k] = a[k] * a[k];
  }
}

/* End of code generation (power.c) */
