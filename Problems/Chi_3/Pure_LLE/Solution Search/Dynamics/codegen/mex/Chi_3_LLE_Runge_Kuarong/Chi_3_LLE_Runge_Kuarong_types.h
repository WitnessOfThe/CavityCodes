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

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  char_T Runge_Type[12];
  real_T dt;
  real_T s_t;
  real_T T;
  real_T dd;
  real_T CW_num;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct5_T
#define typedef_struct5_T

typedef struct {
  real_T b[9];
  real_T a[3];
  real_T c[3];
  real_T s;
} struct5_T;

#endif                                 /*typedef_struct5_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T eta;
  real_T omega[256];
  real_T omega_p;
  real_T D[2];
  real_T omega_int[256];
  real_T gamma;
  real_T range;
  real_T kappa;
  real_T delta;
  real_T P;
  real_T Finess;
  real_T Fin_D;
  creal_T Psi_Start[256];
  real_T t_start;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef struct_emxArray_real_T_1x1024
#define struct_emxArray_real_T_1x1024

struct emxArray_real_T_1x1024
{
  real_T data[1024];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1x1024*/

#ifndef typedef_emxArray_real_T_1x1024
#define typedef_emxArray_real_T_1x1024

typedef struct emxArray_real_T_1x1024 emxArray_real_T_1x1024;

#endif                                 /*typedef_emxArray_real_T_1x1024*/

#ifndef struct_emxArray_real_T_1x6
#define struct_emxArray_real_T_1x6

struct emxArray_real_T_1x6
{
  real_T data[6];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1x6*/

#ifndef typedef_emxArray_real_T_1x6
#define typedef_emxArray_real_T_1x6

typedef struct emxArray_real_T_1x6 emxArray_real_T_1x6;

#endif                                 /*typedef_emxArray_real_T_1x6*/

#ifndef typedef_emxArray_creal_T_1x1024
#define typedef_emxArray_creal_T_1x1024

typedef struct {
  creal_T data[1024];
  int32_T size[2];
} emxArray_creal_T_1x1024;

#endif                                 /*typedef_emxArray_creal_T_1x1024*/

#ifndef struct_emxArray_real_T_1x600
#define struct_emxArray_real_T_1x600

struct emxArray_real_T_1x600
{
  real_T data[600];
  int32_T size[2];
};

#endif                                 /*struct_emxArray_real_T_1x600*/

#ifndef typedef_emxArray_real_T_1x600
#define typedef_emxArray_real_T_1x600

typedef struct emxArray_real_T_1x600 emxArray_real_T_1x600;

#endif                                 /*typedef_emxArray_real_T_1x600*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T N;
  real_T lenght;
  real_T dphi;
  emxArray_real_T_1x1024 phi;
  real_T dk;
  emxArray_real_T_1x1024 k;
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct4_T
#define typedef_struct4_T

typedef struct {
  real_T delta;
  real_T kappa;
  real_T gamma_3;
  emxArray_real_T_1x6 D;
  real_T h;
  emxArray_creal_T_1x1024 omega_j;
  emxArray_real_T_1x1024 gamma_Kerr;
  emxArray_real_T_1x1024 mask;
  emxArray_real_T_1x1024 kappa_vector;
  emxArray_real_T_1x600 mode_range;
  emxArray_creal_T_1x1024 L;
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
  struct1_T In;
  struct2_T Par;
  struct3_T Space;
  struct4_T Eq;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

/* End of code generation (Chi_3_LLE_Runge_Kuarong_types.h) */
