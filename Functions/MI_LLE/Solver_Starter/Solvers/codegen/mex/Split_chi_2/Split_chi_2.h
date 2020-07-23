/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Split_chi_2.h
 *
 * Code generation for function 'Split_chi_2'
 *
 */

#ifndef SPLIT_CHI_2_H
#define SPLIT_CHI_2_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "Split_chi_2_types.h"

/* Function Declarations */
extern void Split_chi_2(const emlrtStack *sp, const creal_T Psi_o_0[32], const
  creal_T Psi_e_0[32], real_T delta_o, real_T delta_e, real_T kappa_o, real_T
  kappa_e, real_T gamma_o, real_T gamma_e, real_T Pump, const creal_T L_o[32],
  const creal_T L_e[32], real_T dt, real_T nt, real_T NN, real_T Loops, real_T
  per_loop, real_T N, const struct0_T *Runge, const struct1_T *Probes, real_T
  t_start, struct2_T *Temporal);

#endif

/* End of code generation (Split_chi_2.h) */
