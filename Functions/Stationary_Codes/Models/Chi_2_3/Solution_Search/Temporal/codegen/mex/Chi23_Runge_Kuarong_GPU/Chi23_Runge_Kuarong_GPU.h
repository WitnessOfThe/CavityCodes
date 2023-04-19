//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Chi23_Runge_Kuarong_GPU.h
//
// Code generation for function 'Chi23_Runge_Kuarong_GPU'
//

#pragma once

// Include files
#include "Chi23_Runge_Kuarong_GPU_types.h"
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
void Chi23_Runge_Kuarong_GPU(const struct0_T *Temp, const struct7_T *Runge,
                             struct8_T *Sol);

// End of code generation (Chi23_Runge_Kuarong_GPU.h)
