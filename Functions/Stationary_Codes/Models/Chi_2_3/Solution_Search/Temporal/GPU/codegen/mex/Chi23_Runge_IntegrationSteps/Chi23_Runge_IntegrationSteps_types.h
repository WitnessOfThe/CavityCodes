//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi23_Runge_IntegrationSteps_types.h
//
// Code generation for function 'Chi23_Runge_IntegrationSteps'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"

// Custom Header Code

#ifdef __CUDA_ARCH__
#undef printf
#endif

// Type Definitions
struct struct0_T {
  real_T b[9];
  real_T a[3];
  real_T c[3];
  real_T s;
};

// End of code generation (Chi23_Runge_IntegrationSteps_types.h)
