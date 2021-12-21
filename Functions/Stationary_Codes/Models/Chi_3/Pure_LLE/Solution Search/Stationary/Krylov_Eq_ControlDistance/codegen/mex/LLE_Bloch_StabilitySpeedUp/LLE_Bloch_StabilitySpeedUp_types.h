/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LLE_Bloch_StabilitySpeedUp_types.h
 *
 * Code generation for function 'LLE_Bloch_StabilitySpeedUp'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct3_T
#define typedef_struct3_T

typedef struct {
  real_T Rel_ampl;
} struct3_T;

#endif                                 /*typedef_struct3_T*/

#ifndef typedef_struct2_T
#define typedef_struct2_T

typedef struct {
  real_T CW_num;
  real_T i_max;
  char_T Equation_string[20];
  real_T Newton_tol;
  real_T Turning;
  char_T variable[5];
  real_T bot_boundary;
  real_T top_boundary;
  real_T Stability;
  real_T Newton_iter;
  real_T first_step;
  real_T max_step;
  real_T step_dec;
  real_T step_tol;
  real_T step_inc;
  struct3_T In;
} struct2_T;

#endif                                 /*typedef_struct2_T*/

#ifndef typedef_struct4_T
#define typedef_struct4_T

typedef struct {
  real_T N;
  real_T lenght;
  real_T dphi;
  real_T phi[512];
  real_T dk;
  real_T k[512];
} struct4_T;

#endif                                 /*typedef_struct4_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

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
  real_T k;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

#ifndef typedef_struct5_T
#define typedef_struct5_T

typedef struct {
  real_T Fin_Dlog;
  real_T delta;
  real_T kappa;
  real_T gamma_3;
  real_T D[3];
  real_T h;
  creal_T omega_j[512];
  real_T gamma_Kerr[512];
  real_T mask[512];
  real_T kappa_vector[512];
  creal_T L[512];
  real_T norm;
  real_T mode_range[240];
} struct5_T;

#endif                                 /*typedef_struct5_T*/

#ifndef typedef_struct6_T
#define typedef_struct6_T

typedef struct {
  real_T Exitflag;
  real_T eps_f;
  real_T V;
  creal_T Psi_k[512];
} struct6_T;

#endif                                 /*typedef_struct6_T*/

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

#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  struct1_T In;
  struct2_T Par;
  struct4_T Space;
  struct5_T Eq;
  struct6_T Sol;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_c_LLE_Bloch_StabilitySpeedUpSta
#define typedef_c_LLE_Bloch_StabilitySpeedUpSta

typedef struct {
  union
  {
    struct {
      creal_T A[1048576];
    } f0;

    struct {
      creal_T a_tmp[262144];
      creal_T dcv[262144];
      creal_T b_a_tmp[262144];
      creal_T y[262144];
      creal_T b_y[262144];
      creal_T FF[262144];
      real_T dv[262144];
    } f1;

    struct {
      creal_T reshapes_f1[262144];
      creal_T a_tmp[262144];
      creal_T b[262144];
      creal_T y[262144];
      creal_T b_y[262144];
      creal_T FF[262144];
      real_T b_b[262144];
    } f2;
  } u1;

  struct {
    creal_T dcv[1048576];
  } f3;

  struct {
    creal_T Vectors[1048576];
    creal_T Valuestemp[1048576];
    creal_T VectorsStar[1048576];
    creal_T ValuesStartemp[1048576];
    creal_T FF[262144];
    creal_T FI[262144];
  } f4;
} c_LLE_Bloch_StabilitySpeedUpSta;

#endif                                 /*typedef_c_LLE_Bloch_StabilitySpeedUpSta*/

/* End of code generation (LLE_Bloch_StabilitySpeedUp_types.h) */
