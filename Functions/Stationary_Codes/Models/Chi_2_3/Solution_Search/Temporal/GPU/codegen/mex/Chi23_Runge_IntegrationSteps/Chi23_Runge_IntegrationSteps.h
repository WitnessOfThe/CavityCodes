//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi23_Runge_IntegrationSteps.h
//
// Code generation for function 'Chi23_Runge_IntegrationSteps'
//

#pragma once

// Include files
#include "Chi23_Runge_IntegrationSteps_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Custom Header Code

#ifdef __CUDA_ARCH__
#undef printf
#endif

// Function Declarations
void Chi23_Runge_IntegrationSteps(
    real_T nt, real_T dt, const creal_T d[1536], creal_T F_e[512],
    const creal_T exp_plus_omega[1536], const creal_T exp_minus_omega[1536],
    const struct0_T *Runge, const creal_T shift_back[512],
    const real_T gam2o[256], const real_T gam2e[256], const real_T gam3o[256],
    const real_T gam3e[256], const real_T H_f[512],
    const real_T mode_range[512]);

// End of code generation (Chi23_Runge_IntegrationSteps.h)
