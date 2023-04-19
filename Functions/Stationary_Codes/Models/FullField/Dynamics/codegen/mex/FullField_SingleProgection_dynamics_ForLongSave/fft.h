//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// fft.h
//
// Code generation for function 'fft'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
namespace coder {
void fft(const emlrtStack *sp, const ::coder::array<creal_T, 2U> &x,
         ::coder::array<creal_T, 2U> &y);

}

// End of code generation (fft.h)
