//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 16-Sep-2020 20:40:18
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include <string.h>
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "main.h"
#include "Chi_3_LLE_Runge_Kuarong_terminate.h"
#include "Chi_3_LLE_Runge_Kuarong_emxAPI.h"
#include "Chi_3_LLE_Runge_Kuarong_initialize.h"

// Function Declarations
static void argInit_1x1024_creal_T(creal_T result[1024]);
static void argInit_1x1024_real_T(double result[1024]);
static void argInit_1x12_char_T(char result[12]);
static void argInit_1x3_real_T(double result[3]);
static void argInit_1x4_real_T(double result[4]);
static void argInit_1x600_real_T(double result[600]);
static void argInit_3x3_real_T(double result[9]);
static char argInit_char_T();
static creal_T argInit_creal_T();
static double argInit_real_T();
static void argInit_struct0_T(struct0_T *result);
static void argInit_struct1_T(struct1_T *result);
static struct2_T argInit_struct2_T();
static void argInit_struct3_T(struct3_T *result);
static void argInit_struct4_T(struct4_T *result);
static void argInit_struct5_T(struct5_T *result);
static void main_Chi_3_LLE_Runge_Kuarong();

// Function Definitions

//
// Arguments    : creal_T result[1024]
// Return Type  : void
//
static void argInit_1x1024_creal_T(creal_T result[1024])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 1024; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_creal_T();
  }
}

//
// Arguments    : double result[1024]
// Return Type  : void
//
static void argInit_1x1024_real_T(double result[1024])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 1024; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : char result[12]
// Return Type  : void
//
static void argInit_1x12_char_T(char result[12])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 12; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_char_T();
  }
}

//
// Arguments    : double result[3]
// Return Type  : void
//
static void argInit_1x3_real_T(double result[3])
{
  double result_tmp;

  // Loop over the array to initialize each element.
  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result[0] = result_tmp;

  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result[1] = result_tmp;

  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result[2] = argInit_real_T();
}

//
// Arguments    : double result[4]
// Return Type  : void
//
static void argInit_1x4_real_T(double result[4])
{
  double result_tmp;

  // Loop over the array to initialize each element.
  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result[0] = result_tmp;

  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result[1] = result_tmp;

  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result[2] = argInit_real_T();

  // Set the value of the array element.
  // Change this value to the value that the application requires.
  result[3] = argInit_real_T();
}

//
// Arguments    : double result[600]
// Return Type  : void
//
static void argInit_1x600_real_T(double result[600])
{
  int idx1;

  // Loop over the array to initialize each element.
  for (idx1 = 0; idx1 < 600; idx1++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx1] = argInit_real_T();
  }
}

//
// Arguments    : double result[9]
// Return Type  : void
//
static void argInit_3x3_real_T(double result[9])
{
  int idx0;
  double result_tmp;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 3; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result_tmp = argInit_real_T();
    result[idx0] = result_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 3] = result_tmp;

    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0 + 6] = argInit_real_T();
  }
}

//
// Arguments    : void
// Return Type  : char
//
static char argInit_char_T()
{
  return '?';
}

//
// Arguments    : void
// Return Type  : creal_T
//
static creal_T argInit_creal_T()
{
  creal_T result;
  double result_tmp;

  // Set the value of the complex variable.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result.re = result_tmp;
  result.im = result_tmp;
  return result;
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : struct0_T *result
// Return Type  : void
//
static void argInit_struct0_T(struct0_T *result)
{
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_struct1_T(&result->In);
  result->Par = argInit_struct2_T();
  argInit_struct3_T(&result->Space);
  argInit_struct4_T(&result->Eq);
}

//
// Arguments    : struct1_T *result
// Return Type  : void
//
static void argInit_struct1_T(struct1_T *result)
{
  double result_tmp;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result->eta = result_tmp;
  result->omega_p = result_tmp;
  argInit_1x4_real_T(result->D);
  result->gamma = argInit_real_T();
  result->range = argInit_real_T();
  result->kappa = argInit_real_T();
  result->P = argInit_real_T();
  result->delta = argInit_real_T();
  argInit_1x1024_real_T(result->omega);
  result->Finess = argInit_real_T();
  result->Fin_D = argInit_real_T();
  argInit_1x1024_creal_T(result->Psi_Start);
  result->t_start = argInit_real_T();
}

//
// Arguments    : void
// Return Type  : struct2_T
//
static struct2_T argInit_struct2_T()
{
  struct2_T result;
  double result_tmp;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_1x12_char_T(result.Runge_Type);
  result_tmp = argInit_real_T();
  result.dt = result_tmp;
  result.s_t = result_tmp;
  result.T = argInit_real_T();
  result.CW_num = argInit_real_T();
  result.dd = argInit_real_T();
  return result;
}

//
// Arguments    : struct3_T *result
// Return Type  : void
//
static void argInit_struct3_T(struct3_T *result)
{
  double result_tmp;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result->N = result_tmp;
  result->lenght = result_tmp;
  result->dphi = argInit_real_T();
  argInit_1x1024_real_T(result->phi);
  result->dk = argInit_real_T();
  argInit_1x1024_real_T(result->k);
}

//
// Arguments    : struct4_T *result
// Return Type  : void
//
static void argInit_struct4_T(struct4_T *result)
{
  double result_tmp;
  double result_tmp_tmp[1024];

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result_tmp = argInit_real_T();
  result->delta = result_tmp;
  result->kappa = result_tmp;
  result->gamma_3 = argInit_real_T();
  argInit_1x4_real_T(result->D);
  result->h = argInit_real_T();
  argInit_1x1024_creal_T(result->omega_j);
  argInit_1x1024_real_T(result_tmp_tmp);
  memcpy(&result->gamma_Kerr[0], &result_tmp_tmp[0], sizeof(double) << 10);
  memcpy(&result->mask[0], &result_tmp_tmp[0], sizeof(double) << 10);
  memcpy(&result->kappa_vector[0], &result_tmp_tmp[0], sizeof(double) << 10);
  argInit_1x600_real_T(result->mode_range);
  argInit_1x1024_creal_T(result->L);
  result->norm = argInit_real_T();
}

//
// Arguments    : struct5_T *result
// Return Type  : void
//
static void argInit_struct5_T(struct5_T *result)
{
  double result_tmp[3];

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  argInit_3x3_real_T(result->b);
  argInit_1x3_real_T(result_tmp);
  result->a[0] = result_tmp[0];
  result->c[0] = result_tmp[0];
  result->a[1] = result_tmp[1];
  result->c[1] = result_tmp[1];
  result->a[2] = result_tmp[2];
  result->c[2] = result_tmp[2];
  result->s = argInit_real_T();
}

//
// Arguments    : void
// Return Type  : void
//
static void main_Chi_3_LLE_Runge_Kuarong()
{
  struct6_T Sol;
  static struct0_T r0;
  struct5_T r1;
  emxInit_struct6_T(&Sol);

  // Initialize function 'Chi_3_LLE_Runge_Kuarong' input arguments.
  // Initialize function input argument 'Temp'.
  // Initialize function input argument 'Runge'.
  // Call the entry-point 'Chi_3_LLE_Runge_Kuarong'.
  argInit_struct0_T(&r0);
  argInit_struct5_T(&r1);
  Chi_3_LLE_Runge_Kuarong(&r0, argInit_real_T(), &r1, &Sol);
  emxDestroy_struct6_T(Sol);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  Chi_3_LLE_Runge_Kuarong_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_Chi_3_LLE_Runge_Kuarong();

  // Terminate the application.
  // You do not need to do this more than one time.
  Chi_3_LLE_Runge_Kuarong_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
