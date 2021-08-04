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
#include "Chi23OPO_Runge_Kuarong.h"
#include "exp.h"

/* Function Definitions */
void b_exp(creal_T *x)
{
  real_T r;
  real_T x_im;
  if (x->im == 0.0) {
    x->re = muDoubleScalarExp(x->re);
    x->im = 0.0;
  } else if (muDoubleScalarIsInf(x->im) && muDoubleScalarIsInf(x->re) && (x->re <
              0.0)) {
    x->re = 0.0;
    x->im = 0.0;
  } else {
    r = muDoubleScalarExp(x->re / 2.0);
    x_im = x->im;
    x->re = r * (r * muDoubleScalarCos(x->im));
    x->im = r * (r * muDoubleScalarSin(x_im));
  }
}

/* End of code generation (exp.c) */
