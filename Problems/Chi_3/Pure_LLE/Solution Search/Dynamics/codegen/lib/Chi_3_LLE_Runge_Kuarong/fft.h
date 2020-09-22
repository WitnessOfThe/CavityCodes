//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fft.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 16-Sep-2020 20:40:18
//
#ifndef FFT_H
#define FFT_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Chi_3_LLE_Runge_Kuarong_types.h"

// Function Declarations
extern void r2br_r2dit_trig_impl(const creal_T x[1024], const double costab[513],
  const double sintab[513], creal_T y[1024]);

#endif

//
// File trailer for fft.h
//
// [EOF]
//
