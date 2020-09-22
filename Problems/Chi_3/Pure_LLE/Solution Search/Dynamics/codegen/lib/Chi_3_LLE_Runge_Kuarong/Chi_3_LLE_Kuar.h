//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Chi_3_LLE_Kuar.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 16-Sep-2020 20:40:18
//
#ifndef CHI_3_LLE_KUAR_H
#define CHI_3_LLE_KUAR_H

// Include Files
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "Chi_3_LLE_Runge_Kuarong_types.h"

// Function Declarations
extern void Chi_3_LLE_Kuar(const creal_T F_Psi[1024], const creal_T Fac_plus
  [1024], const creal_T Fac_minus[1024], double Eq_h, const double
  Eq_gamma_Kerr[1024], creal_T k_e[1024]);

#endif

//
// File trailer for Chi_3_LLE_Kuar.h
//
// [EOF]
//
