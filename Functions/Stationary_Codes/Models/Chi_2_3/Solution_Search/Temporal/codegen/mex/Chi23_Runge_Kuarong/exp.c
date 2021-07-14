/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * exp.c
 *
 * Code generation for function 'exp'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Chi23_Runge_Kuarong.h"
#include "exp.h"

/* Function Definitions */
void b_exp(creal_T x[256])
{
  int32_T k;
  real_T r;
  real_T x_im;
  for (k = 0; k < 256; k++) {
    if (x[k].im == 0.0) {
      x[k].re = muDoubleScalarExp(x[k].re);
      x[k].im = 0.0;
    } else if (muDoubleScalarIsInf(x[k].im) && muDoubleScalarIsInf(x[k].re) &&
               (x[k].re < 0.0)) {
      x[k].re = 0.0;
      x[k].im = 0.0;
    } else {
      r = muDoubleScalarExp(x[k].re / 2.0);
      x_im = x[k].im;
      x[k].re = r * (r * muDoubleScalarCos(x[k].im));
      x[k].im = r * (r * muDoubleScalarSin(x_im));
    }
  }
}

/* End of code generation (exp.c) */
