//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// FullField_SingleProgection_dynamics_ForLongSave_types.h
//
// Code generation for function
// 'FullField_SingleProgection_dynamics_ForLongSave'
//

#pragma once

// Include files
#include "FullField_SingleProgection_dynamics_ForLongSave_types1.h"
#include "ref.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
struct emxArray_real_T_1x6545 {
  real_T data[6545];
  int32_T size[2];
};

struct struct8_T {
  coder::array<creal_T, 2U> Psi;
  coder::array<creal_T, 2U> t;
  coder::array<creal_T, 2U> PsiResolved;
  emxArray_real_T_1x6545 mSaved;
  coder::array<real_T, 2U> G;
};

struct c_FullField_SingleProgection_dy {
  struct0_T Temp;
  struct8_T Sol;
};

struct d_FullField_SingleProgection_dy {
  coder::captured_var Temp;
  creal_T F_e[2048];
};

struct e_FullField_SingleProgection_dy {
  d_FullField_SingleProgection_dy f0;
  c_FullField_SingleProgection_dy f1;
};

// End of code generation
// (FullField_SingleProgection_dynamics_ForLongSave_types.h)
