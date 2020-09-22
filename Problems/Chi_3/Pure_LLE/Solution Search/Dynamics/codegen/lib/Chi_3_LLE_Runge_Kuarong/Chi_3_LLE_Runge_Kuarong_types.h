//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Chi_3_LLE_Runge_Kuarong_types.h
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 16-Sep-2020 20:40:18
//
#ifndef CHI_3_LLE_RUNGE_KUARONG_TYPES_H
#define CHI_3_LLE_RUNGE_KUARONG_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
typedef struct {
  creal_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;

typedef struct {
  cuint8_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_cuint8_T;

typedef struct {
  double eta;
  double omega_p;
  double D[4];
  double gamma;
  double range;
  double kappa;
  double P;
  double delta;
  double omega[1024];
  double Finess;
  double Fin_D;
  creal_T Psi_Start[1024];
  double t_start;
} struct1_T;

typedef struct {
  char Runge_Type[12];
  double dt;
  double s_t;
  double T;
  double CW_num;
  double dd;
} struct2_T;

typedef struct {
  double N;
  double lenght;
  double dphi;
  double phi[1024];
  double dk;
  double k[1024];
} struct3_T;

typedef struct {
  double delta;
  double kappa;
  double gamma_3;
  double D[4];
  double h;
  creal_T omega_j[1024];
  double gamma_Kerr[1024];
  double mask[1024];
  double kappa_vector[1024];
  double mode_range[600];
  creal_T L[1024];
  double norm;
} struct4_T;

typedef struct {
  struct1_T In;
  struct2_T Par;
  struct3_T Space;
  struct4_T Eq;
} struct0_T;

typedef struct {
  double b[9];
  double a[3];
  double c[3];
  double s;
} struct5_T;

typedef struct {
  emxArray_creal_T *Psi;
  emxArray_creal_T *t;
} struct6_T;

#endif

//
// File trailer for Chi_3_LLE_Runge_Kuarong_types.h
//
// [EOF]
//
