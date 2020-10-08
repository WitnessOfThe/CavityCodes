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
#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  real_T eta;
  real_T omega_p;
  real_T D[4];
  real_T gamma;
  real_T range;
  real_T kappa;
  real_T P;
  real_T delta;
  real_T omega[1024];
  real_T Finess;
  real_T Fin_D;
  creal_T Psi_Start[1024];
  real_T t_start;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  char_T Runge_Type[12];
  real_T dt;
  real_T s_t;
  real_T T;
  real_T CW_num;
  real_T dd;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T N;
  real_T lenght;
  real_T dphi;
  real_T phi[1024];
  real_T dk;
  real_T k[1024];
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct4_T
#define typedef_struct4_T

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
} struct4_T;

#endif                                 /*typedef_struct4_T*/

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  struct1_T In;
  struct2_T Par;
  struct3_T Space;
  struct4_T Eq;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_c_Chi_3_LLE_Runge_KuarongStackD
#define typedef_c_Chi_3_LLE_Runge_KuarongStackD

typedef struct {
  struct {
    creal_T exp_minus_omega_contents[3072];
    creal_T exp_plus_omega_contents[3072];
  } f0;

  struct {
    struct0_T Temp;
  } f1;
} c_Chi_3_LLE_Runge_KuarongStackD;

#endif                                 /*typedef_c_Chi_3_LLE_Runge_KuarongStackD*/

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

#ifndef typedef_struct5_T
#define typedef_struct5_T

typedef struct {
  real_T b[9];
  real_T a[3];
  real_T c[3];
  real_T s;
} struct5_T;

#endif                                 /*typedef_struct5_T*/

#ifndef typedef_struct6_T
#define typedef_struct6_T

typedef struct {
  emxArray_creal_T *Psi;
  emxArray_creal_T *t;
} struct6_T;

#endif                                 /*typedef_struct6_T*/
#endif

/* End of code generation (Chi_3_LLE_Runge_Kuarong_types.h) */
