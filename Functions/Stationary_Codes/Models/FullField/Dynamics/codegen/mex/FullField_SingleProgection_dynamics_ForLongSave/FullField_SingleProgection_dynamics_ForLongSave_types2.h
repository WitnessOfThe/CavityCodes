//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// FullField_SingleProgection_dynamics_ForLongSave_types2.h
//
// Code generation for function
// 'FullField_SingleProgection_dynamics_ForLongSave_types2'
//

#pragma once

// Include files
#include "FullField_SingleProgection_dynamics_ForLongSave_types3.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
struct struct3_T {
  real_T mode_range[1309];
  real_T norm;
  struct4_T Pump;
  real_T omega[1309];
  real_T kappa[1309];
  real_T gamma2[1309];
  real_T gamma3[1309];
  real_T m[1309];
  real_T g;
};

struct struct5_T {
  real_T N;
  real_T lenght;
  real_T dphi;
  real_T phi[4096];
  real_T dk;
  real_T k[4096];
};

struct struct6_T {
  char_T Runge_Type[12];
  real_T dt;
  real_T s_t;
  real_T T;
  real_T dd;
  real_T CW_num;
};

struct struct1_T {
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
};

// End of code generation
// (FullField_SingleProgection_dynamics_ForLongSave_types2.h)
