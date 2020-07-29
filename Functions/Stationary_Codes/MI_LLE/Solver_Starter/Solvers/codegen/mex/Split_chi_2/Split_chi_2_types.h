/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Split_chi_2_types.h
 *
 * Code generation for function 'Split_chi_2'
 *
 */

#ifndef SPLIT_CHI_2_TYPES_H
#define SPLIT_CHI_2_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

typedef struct {
  emxArray_creal_T *contents;
} coder_internal_ref_2;

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

typedef struct {
  real_T b[9];
  real_T a[3];
  real_T c[3];
} struct0_T;

typedef struct {
  real_T omega_probe_o_1;
  real_T omega_probe_o_3;
  real_T omega_probe_e_2;
  real_T omega_probe_e_4;
  real_T h_prob_o_1;
  real_T h_prob_o_3;
  real_T h_prob_e_2;
  real_T h_prob_e_4;
  real_T mu_p_o_1;
  real_T mu_p_e_2;
  real_T mu_p_o_3;
  real_T mu_p_e_4;
} struct1_T;

typedef struct {
  emxArray_real_T *t;
  emxArray_creal_T *Psi_o_k;
  emxArray_creal_T *Psi_e_k;
} struct2_T;

#endif

/* End of code generation (Split_chi_2_types.h) */
