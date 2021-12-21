/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi_3_LLE_Runge_Kuarong_with_Scan_types.h
 *
 * Code generation for function 'Chi_3_LLE_Runge_Kuarong_with_Scan'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  char_T Runge_Type[12];
  real_T dt;
  real_T s_t;
  real_T T;
  real_T freq_probe;
  real_T dd;
  real_T CW_num;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T N;
  real_T lenght;
  real_T dphi;
  real_T phi[512];
  real_T dk;
  real_T k[512];
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct5_T
#define typedef_struct5_T

typedef struct {
  real_T b[9];
  real_T a[3];
  real_T c[3];
  real_T s;
} struct5_T;

#endif                                 /*typedef_struct5_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  real_T eta;
  real_T omega_p;
  real_T D[3];
  real_T gamma;
  real_T range;
  real_T kappa;
  real_T P;
  real_T N_mode;
  real_T delta;
  real_T mu_bl;
  real_T omega[512];
  real_T omega_int[512];
  real_T Finess;
  real_T Fin_D;
  real_T H;
  real_T W;
  real_T W_Star;
  real_T W_WStar;
  real_T omega_int_pl[512];
  real_T omega_int_mn[512];
  creal_T Psi_Start[512];
  real_T t_start;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct4_T
#define typedef_struct4_T

typedef struct {
  real_T Fin_Dlog;
  real_T delta;
  real_T kappa;
  real_T gamma_3;
  real_T D[3];
  real_T h;
  creal_T omega_j[512];
  real_T gamma_Kerr[512];
  real_T mask;
  real_T kappa_vector[512];
  real_T mode_range[512];
  creal_T L[512];
  real_T norm;
} struct4_T;

#endif                                 /*typedef_struct4_T*/

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T

typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

#endif                                 /*typedef_emxArray_creal_T*/

#ifndef typedef_struct6_T
#define typedef_struct6_T

typedef struct {
  emxArray_creal_T *Psi;
  emxArray_creal_T *t;
} struct6_T;

#endif                                 /*typedef_struct6_T*/

#ifndef typedef_emxArray_cuint8_T
#define typedef_emxArray_cuint8_T

typedef struct {
  cuint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cuint8_T;

#endif                                 /*typedef_emxArray_cuint8_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  struct1_T Par;
  struct2_T In;
  struct3_T Space;
  struct4_T Eq;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* End of code generation (Chi_3_LLE_Runge_Kuarong_with_Scan_types.h) */
