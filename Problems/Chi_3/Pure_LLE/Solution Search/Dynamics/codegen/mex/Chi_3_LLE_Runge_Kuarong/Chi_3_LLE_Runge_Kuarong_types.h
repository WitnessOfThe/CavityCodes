//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Chi_3_LLE_Runge_Kuarong_types.h
//
//  Code generation for function 'Chi_3_LLE_Runge_Kuarong'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
struct struct2_T
{
  char_T Runge_Type[12];
  real_T dt;
  real_T s_t;
  real_T T;
  real_T dd;
  real_T CW_num;
};

struct struct3_T
{
  real_T N;
  real_T lenght;
  real_T dphi;
  real_T phi[1024];
  real_T dk;
  real_T k[1024];
};

struct struct5_T
{
  real_T b[9];
  real_T a[3];
  real_T c[3];
  real_T s;
};

struct struct1_T
{
  real_T eta;
  real_T omega_p;
  real_T D[6];
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
};

struct struct4_T
{
  real_T delta;
  real_T kappa;
  real_T gamma_3;
  real_T D[6];
  real_T h;
  creal_T omega_j[1024];
  real_T gamma_Kerr[1024];
  real_T mask[1024];
  real_T kappa_vector[1024];
  real_T mode_range[600];
  creal_T L[1024];
  real_T norm;
};

struct struct6_T
{
  coder::array<creal_T, 2U> Psi;
  coder::array<creal_T, 2U> t;
};

struct struct0_T
{
  struct1_T In;
  struct2_T Par;
  struct3_T Space;
  struct4_T Eq;
};

struct c_Chi_3_LLE_Runge_KuarongStackD
{
  struct {
    struct0_T Temp;
  } f0;
};

// End of code generation (Chi_3_LLE_Runge_Kuarong_types.h)
