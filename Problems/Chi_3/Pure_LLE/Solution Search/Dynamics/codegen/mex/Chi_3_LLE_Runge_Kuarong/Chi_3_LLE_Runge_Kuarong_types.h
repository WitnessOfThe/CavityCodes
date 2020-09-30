/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi_3_LLE_Runge_Kuarong_types.h
 *
 * Code generation for function 'Chi_3_LLE_Runge_Kuarong'
 *
 */

#ifndef CHI_3_LLE_RUNGE_KUARONG_TYPES_H
#define CHI_3_LLE_RUNGE_KUARONG_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  real_T eta;
  real_T omega_p;
  real_T D[4];
  real_T gamma;
  real_T range;
  real_T kappa;
  real_T P;
  real_T delta;
  real_T omega[2048];
  real_T Finess;
  real_T Fin_D;
  creal_T Psi_Start[2048];
  real_T t_start;
} struct1_T;

typedef struct {
  char_T Runge_Type[12];
  real_T dt;
  real_T s_t;
  real_T T;
  real_T CW_num;
  real_T dd;
} struct2_T;

typedef struct {
  real_T N;
  real_T lenght;
  real_T dphi;
  real_T phi[2048];
  real_T dk;
  real_T k[2048];
} struct3_T;

typedef struct {
  real_T delta;
  real_T kappa;
  real_T gamma_3;
  real_T D[4];
  real_T h;
  creal_T omega_j[2048];
  real_T gamma_Kerr[2048];
  real_T mask[2048];
  real_T kappa_vector[2048];
  real_T mode_range[700];
  creal_T L[2048];
  real_T norm;
} struct4_T;

typedef struct {
  struct1_T In;
  struct2_T Par;
  struct3_T Space;
  struct4_T Eq;
} struct0_T;

typedef struct {
  struct {
    creal_T exp_minus_omega_contents[6144];
    creal_T exp_plus_omega_contents[6144];
    creal_T y[2048];
    creal_T F_e[2048];
    creal_T E_temp[2048];
    creal_T b_exp_plus_omega_contents[2048];
    creal_T b_exp_minus_omega_contents[2048];
  } f0;

  struct {
    struct0_T Temp;
  } f1;
} c_Chi_3_LLE_Runge_KuarongStackD;

typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

typedef struct {
  cuint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cuint8_T;

typedef struct {
  real_T b[9];
  real_T a[3];
  real_T c[3];
  real_T s;
} struct5_T;

typedef struct {
  emxArray_creal_T *Psi;
  emxArray_creal_T *t;
} struct6_T;

#endif

/* End of code generation (Chi_3_LLE_Runge_Kuarong_types.h) */
