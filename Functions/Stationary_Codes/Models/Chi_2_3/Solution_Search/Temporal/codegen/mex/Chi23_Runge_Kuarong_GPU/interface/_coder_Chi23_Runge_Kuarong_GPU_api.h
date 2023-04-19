//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_Chi23_Runge_Kuarong_GPU_api.h
//
// Code generation for function '_coder_Chi23_Runge_Kuarong_GPU_api'
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
void Chi23_Runge_Kuarong_GPU_api(const mxArray *const prhs[2],
                                 const mxArray *plhs[1]);

// End of code generation (_coder_Chi23_Runge_Kuarong_GPU_api.h)
