//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi23_Runge_Kuarong_types.h
//
// Code generation for function 'Chi23_Runge_Kuarong'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
struct struct3_T {
  real_T eta;
  real_T delta;
  real_T m_p;
  real_T f_off;
  real_T W;
  real_T N;
  real_T Nenv;
  real_T g;
};

struct struct2_T {
  real_T omega[1309];
  real_T m[1309];
  real_T D1[1309];
  real_T n_o[1309];
  real_T n_e[1309];
  real_T S[1309];
  real_T gamma2[1309];
  real_T gamma3[1309];
  real_T kappa[1309];
  struct3_T In;
};

struct struct4_T {
  char_T Runge_Type[12];
  real_T dt;
  real_T s_t;
  real_T T;
  real_T dd;
  real_T CW_num;
};

struct struct5_T {
  real_T N;
  real_T lenght;
  real_T dphi;
  real_T phi[256];
  real_T dk;
  real_T k[256];
};

struct struct7_T {
  real_T b[9];
  real_T a[3];
  real_T c[3];
  real_T s;
};

struct struct1_T {
  real_T eta;
  real_T delta_o;
  real_T W;
  real_T ko;
  real_T ke;
  real_T eps;
  real_T eps_2;
  real_T eps_3;
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
  struct2_T D;
  real_T N_mode;
  real_T N;
  real_T kMI[2];
  real_T mu_bl;
  real_T delta_e;
  real_T H_f;
  real_T H_s;
  creal_T Omega_f;
  creal_T Omega_s;
  creal_T Psi_Start[512];
  real_T t_start;
};

struct struct6_T {
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
};

struct struct8_T {
  coder::array<creal_T, 2U> Psio;
  coder::array<creal_T, 2U> Psie;
  coder::array<creal_T, 2U> t;
};

struct struct0_T {
  struct1_T In;
  struct4_T Par;
  struct5_T Space;
  struct6_T Eq;
};

struct Chi23_Runge_Kuarong_api {
  struct0_T Temp;
};

struct Chi23_Runge_KuarongStackData {
  Chi23_Runge_Kuarong_api f0;
};

// End of code generation (Chi23_Runge_Kuarong_types.h)
