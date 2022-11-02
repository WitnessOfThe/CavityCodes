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
#ifndef typedef_struct4_T
#define typedef_struct4_T
typedef struct {
  real_T eta;
  real_T delta;
  real_T m_p;
  real_T W;
  real_T N;
  real_T Nenv;
  real_T g;
} struct4_T;
#endif /* typedef_struct4_T */

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
#endif /* typedef_struct1_T */

#ifndef typedef_struct3_T
#define typedef_struct3_T
typedef struct {
  real_T omega[656];
  real_T m[656];
  real_T D1[656];
  real_T n_o[1032];
  real_T n_e[1032];
  real_T gamma2[656];
  real_T gamma3[656];
  real_T S[1032];
  real_T gamma2_SH[1032];
  real_T gamma2_OPO[1032];
  real_T kappa[656];
  struct4_T In;
} struct3_T;
#endif /* typedef_struct3_T */

#ifndef typedef_struct5_T
#define typedef_struct5_T
typedef struct {
  real_T N;
  real_T lenght;
  real_T dphi;
  real_T phi[256];
  real_T dk;
  real_T k[256];
} struct5_T;
#endif /* typedef_struct5_T */

#ifndef typedef_struct7_T
#define typedef_struct7_T
typedef struct {
  real_T b[9];
  real_T a[3];
  real_T c[3];
  real_T s;
} struct7_T;
#endif /* typedef_struct7_T */

#ifndef typedef_struct2_T
#define typedef_struct2_T
typedef struct {
  real_T eta;
  real_T delta_o;
  real_T W;
  real_T ko;
  real_T ke;
  real_T eps;
  real_T eps_2;
  real_T Do;
  real_T De;
  real_T gam2o;
  real_T gam2e;
  real_T gam3o;
  real_T gam3e;
  real_T Finess;
  real_T Finess_e;
  real_T H_Star;
  real_T Wf_Star;
  real_T Ws_Star;
  real_T Omega_Star;
  struct3_T D;
  real_T N_mode;
  real_T N;
  real_T kMI[2];
  real_T mu_bl;
  real_T delta;
  real_T delta_e;
  real_T H_f;
  real_T H_s;
  creal_T Omega_f;
  creal_T Omega_s;
  real_T d;
  creal_T Psi_Start[512];
  real_T t_start;
} struct2_T;
#endif /* typedef_struct2_T */

#ifndef typedef_struct6_T
#define typedef_struct6_T
typedef struct {
  real_T H_f;
  real_T H_s;
  real_T delta_o;
  real_T delta_e;
  real_T eps;
  real_T ko;
  real_T ke;
  real_T gam2o[256];
  real_T gam2e[256];
  real_T gam3o[256];
  real_T gam3e[256];
  real_T Do;
  real_T De;
  real_T d;
  real_T norm;
  real_T mode_range[512];
  creal_T Lo[256];
  creal_T Le[256];
  creal_T L[512];
} struct6_T;
#endif /* typedef_struct6_T */

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

#ifndef typedef_struct8_T
#define typedef_struct8_T
typedef struct {
  emxArray_creal_T *Psio;
  emxArray_creal_T *Psie;
  emxArray_creal_T *t;
} struct8_T;
#endif /* typedef_struct8_T */

#ifndef typedef_emxArray_cuint8_T
#define typedef_emxArray_cuint8_T
typedef struct {
  cuint8_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cuint8_T;
#endif /* typedef_emxArray_cuint8_T */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  struct1_T Par;
  struct2_T In;
  struct5_T Space;
  struct6_T Eq;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_b_Chi23_Runge_Kuarong_api
#define typedef_b_Chi23_Runge_Kuarong_api
typedef struct {
  struct0_T Temp;
} b_Chi23_Runge_Kuarong_api;
#endif /* typedef_b_Chi23_Runge_Kuarong_api */

#ifndef typedef_Chi23_Runge_KuarongStackData
#define typedef_Chi23_Runge_KuarongStackData
typedef struct {
  b_Chi23_Runge_Kuarong_api f0;
} Chi23_Runge_KuarongStackData;
#endif /* typedef_Chi23_Runge_KuarongStackData */

/* End of code generation (Chi23_Runge_Kuarong_types.h) */
