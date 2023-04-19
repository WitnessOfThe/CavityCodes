//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi_3_LLE_Kuar_ins.h
//
// Code generation for function 'Chi_3_LLE_Kuar_ins'
//

#pragma once

// Include files
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
void Chi_3_LLE_Kuar_ins(const creal_T F_Psi[512], const creal_T Fac_plus[512],
                        const creal_T Fac_minus[512], const real_T gam2o[256],
                        const real_T gam2e[256], const real_T gam3o[256],
                        const real_T gam3e[256], const real_T H_f[512],
                        creal_T k_e[512]);

// End of code generation (Chi_3_LLE_Kuar_ins.h)
