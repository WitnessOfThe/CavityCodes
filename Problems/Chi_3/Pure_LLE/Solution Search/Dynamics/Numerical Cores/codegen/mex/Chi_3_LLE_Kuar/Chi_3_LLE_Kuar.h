/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi_3_LLE_Kuar.h
 *
 * Code generation for function 'Chi_3_LLE_Kuar'
 *
 */

#ifndef CHI_3_LLE_KUAR_H
#define CHI_3_LLE_KUAR_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "Chi_3_LLE_Kuar_types.h"

/* Function Declarations */
extern void Chi_3_LLE_Kuar(const emlrtStack *sp, const creal_T F_Psi[1024],
  const creal_T Fac_plus[1024], const creal_T Fac_minus[1024], real_T t, const
  struct0_T *Eq, creal_T k_e[1024]);

#endif

/* End of code generation (Chi_3_LLE_Kuar.h) */
