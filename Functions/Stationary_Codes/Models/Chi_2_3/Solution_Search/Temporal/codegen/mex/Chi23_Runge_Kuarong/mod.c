/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mod.c
 *
 * Code generation for function 'mod'
 *
 */

/* Include files */
#include "mwmathutil.h"
#include "rt_nonfinite.h"
#include "Chi23_Runge_Kuarong.h"
#include "mod.h"

/* Function Definitions */
real_T b_mod(real_T x, real_T y)
{
  real_T r;
  boolean_T rEQ0;
  real_T q;
  r = x;
  if ((!muDoubleScalarIsInf(x)) && (!muDoubleScalarIsNaN(x)) &&
      ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y)))) {
    if (y != 0.0) {
      r = muDoubleScalarRem(x, y);
      rEQ0 = (r == 0.0);
      if ((!rEQ0) && (y > muDoubleScalarFloor(y))) {
        q = muDoubleScalarAbs(x / y);
        rEQ0 = (muDoubleScalarAbs(q - muDoubleScalarFloor(q + 0.5)) <=
                2.2204460492503131E-16 * q);
      }

      if (rEQ0) {
        r = y * 0.0;
      } else {
        if (y < 0.0) {
          r += y;
        }
      }
    }
  } else {
    if (y != 0.0) {
      r = rtNaN;
    }
  }

  return r;
}

real_T c_mod(real_T x)
{
  real_T r;
  if ((!muDoubleScalarIsInf(x)) && (!muDoubleScalarIsNaN(x))) {
    r = muDoubleScalarRem(x, 2.0);
    if (r == 0.0) {
      r = 0.0;
    }
  } else {
    r = rtNaN;
  }

  return r;
}

/* End of code generation (mod.c) */
