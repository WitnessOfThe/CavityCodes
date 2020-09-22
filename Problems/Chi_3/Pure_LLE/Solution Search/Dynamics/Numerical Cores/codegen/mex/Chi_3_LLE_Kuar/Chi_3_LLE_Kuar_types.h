/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi_3_LLE_Kuar_types.h
 *
 * Code generation for function 'Chi_3_LLE_Kuar'
 *
 */

#ifndef CHI_3_LLE_KUAR_TYPES_H
#define CHI_3_LLE_KUAR_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T delta;
  real_T kappa;
  real_T gamma_3;
  real_T D[4];
  real_T h;
  creal_T omega_j[1024];
  real_T gamma_Kerr[1024];
  real_T mask[1024];
  real_T kappa_vector[1024];
  real_T mode_range[600];
  creal_T L[1024];
  real_T norm;
} struct0_T;

#endif                                 /*typedef_struct0_T*/
#endif

/* End of code generation (Chi_3_LLE_Kuar_types.h) */
