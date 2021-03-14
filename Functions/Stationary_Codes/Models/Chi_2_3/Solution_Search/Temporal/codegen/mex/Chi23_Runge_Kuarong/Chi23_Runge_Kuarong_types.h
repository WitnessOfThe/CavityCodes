/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi23_Runge_Kuarong_types.h
 *
 * Code generation for function 'Chi23_Runge_Kuarong'
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
  real_T phi[256];
  real_T dk;
  real_T k[256];
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
  real_T ko;
  real_T ke;
  real_T gam2o;
  real_T gam2e;
  real_T gam3o;
  real_T gam3e;
  real_T Do[2];
  real_T De[2];
  real_T Finess;
  real_T H_Star;
  real_T W_Star;
  real_T Omega_Star;
  real_T eps;
  real_T delta_o;
  real_T N;
  real_T W;
  real_T mu_bl;
  real_T delta;
  real_T delta_e;
  real_T H;
  creal_T Omega_f;
  creal_T Omega_s;
  creal_T Psi_Start[512];
  real_T t_start;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct4_T
#define typedef_struct4_T

typedef struct {
  real_T H;
  real_T delta_o;
  real_T delta_e;
  real_T eps;
  real_T ko;
  real_T ke;
  real_T gam2o;
  real_T gam2e;
  real_T gam3o;
  real_T gam3e;
  real_T Do[2];
  real_T De[2];
  real_T d;
  real_T norm;
  real_T mode_range[512];
  creal_T Lo[256];
  creal_T Le[256];
  creal_T L[512];
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
  emxArray_creal_T *Psio;
  emxArray_creal_T *Psie;
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

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T

struct emxArray_boolean_T
{
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_boolean_T*/

#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T

typedef struct emxArray_boolean_T emxArray_boolean_T;

#endif                                 /*typedef_emxArray_boolean_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  struct1_T Par;
  struct2_T In;
  struct3_T Space;
  struct4_T Eq;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* End of code generation (Chi23_Runge_Kuarong_types.h) */
