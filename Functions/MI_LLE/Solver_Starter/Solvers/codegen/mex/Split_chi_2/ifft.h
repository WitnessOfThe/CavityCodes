/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ifft.h
 *
 * Code generation for function 'ifft'
 *
 */

#ifndef IFFT_H
#define IFFT_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "Split_chi_2_types.h"

/* Function Declarations */
extern void ifft(const creal_T x_data[], const int32_T x_size[2], creal_T
                 y_data[], int32_T y_size[2]);

#endif

/* End of code generation (ifft.h) */
