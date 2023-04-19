/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FullField_SingleProgection_dynamics_types.h
 *
 * Code generation for function 'FullField_SingleProgection_dynamics'
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
  real_T m_p;
  real_T ind_pump;
  real_T D1;
  real_T Finesse;
  real_T omega_p;
  real_T delta;
  real_T H;
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef typedef_struct4_T
#define typedef_struct4_T
typedef struct {
  real_T m_p;
  real_T ind_pump;
  real_T D1;
  real_T omega_p;
  real_T delta;
  real_T H;
} struct4_T;
#endif /* typedef_struct4_T */

#ifndef typedef_struct3_T
#define typedef_struct3_T
typedef struct {
  real_T mode_range[1309];
  real_T norm;
  struct4_T Pump;
  real_T omega[1309];
  real_T kappa[1309];
  real_T gamma2[1309];
  real_T gamma3[1309];
  real_T m[1309];
  real_T g;
} struct3_T;
#endif /* typedef_struct3_T */

#ifndef typedef_struct5_T
#define typedef_struct5_T
typedef struct {
  real_T N;
  real_T lenght;
  real_T dphi;
  real_T phi[4096];
  real_T dk;
  real_T k[4096];
} struct5_T;
#endif /* typedef_struct5_T */

#ifndef typedef_struct6_T
#define typedef_struct6_T
typedef struct {
  char_T Runge_Type[12];
  real_T dt;
  real_T s_t;
  real_T T;
  real_T dd;
  real_T CW_num;
} struct6_T;
#endif /* typedef_struct6_T */

#ifndef typedef_struct7_T
#define typedef_struct7_T
typedef struct {
  real_T b[9];
  real_T a[3];
  real_T c[3];
  real_T s;
} struct7_T;
#endif /* typedef_struct7_T */

#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T N;
  struct2_T Pump;
  real_T omega[1309];
  real_T kappa[1309];
  real_T gamma2[1309];
  real_T gamma3[1309];
  real_T f_off;
  real_T W;
  real_T m[1309];
  real_T g;
  creal_T Psi_Start[2048];
  real_T t_start;
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  struct1_T In;
  struct3_T Eq;
  struct5_T Space;
  struct6_T Par;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_c_captured_var
#define typedef_c_captured_var
typedef struct {
  struct0_T contents;
} c_captured_var;
#endif /* typedef_c_captured_var */

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T
typedef struct {
  creal_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;
#endif /* typedef_emxArray_creal_T */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef typedef_struct8_T
#define typedef_struct8_T
typedef struct {
  emxArray_creal_T *Psi;
  emxArray_creal_T *t;
  emxArray_creal_T *PsiReal;
  emxArray_real_T *G;
} struct8_T;
#endif /* typedef_struct8_T */

#ifndef typedef_e_captured_var
#define typedef_e_captured_var
typedef struct {
  emxArray_creal_T *contents;
} e_captured_var;
#endif /* typedef_e_captured_var */

#ifndef typedef_f_captured_var
#define typedef_f_captured_var
typedef struct {
  emxArray_real_T *contents;
} f_captured_var;
#endif /* typedef_f_captured_var */

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
struct emxArray_char_T {
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_char_T */
#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T
typedef struct emxArray_char_T emxArray_char_T;
#endif /* typedef_emxArray_char_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

#ifndef typedef_d_FullField_SingleProgection_dy
#define typedef_d_FullField_SingleProgection_dy
typedef struct {
  c_captured_var Temp;
} d_FullField_SingleProgection_dy;
#endif /* typedef_d_FullField_SingleProgection_dy */

#ifndef typedef_e_FullField_SingleProgection_dy
#define typedef_e_FullField_SingleProgection_dy
typedef struct {
  struct0_T Temp;
} e_FullField_SingleProgection_dy;
#endif /* typedef_e_FullField_SingleProgection_dy */

#ifndef typedef_f_FullField_SingleProgection_dy
#define typedef_f_FullField_SingleProgection_dy
typedef struct {
  d_FullField_SingleProgection_dy f0;
  e_FullField_SingleProgection_dy f1;
} f_FullField_SingleProgection_dy;
#endif /* typedef_f_FullField_SingleProgection_dy */

/* End of code generation (FullField_SingleProgection_dynamics_types.h) */
