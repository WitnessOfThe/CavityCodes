//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_FullField_SingleProgection_dynamics_ForLongSave_mex.h
//
// Code generation for function
// '_coder_FullField_SingleProgection_dynamics_ForLongSave_mex'
//

#pragma once

// Include files
#include "FullField_SingleProgection_dynamics_ForLongSave_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void FullField_SingleProgection_dynamics_ForLongSave_mexFunction(
    e_FullField_SingleProgection_dy *SD, int32_T nlhs, mxArray *plhs[1],
    int32_T nrhs, const mxArray *prhs[2]);

MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

// End of code generation
// (_coder_FullField_SingleProgection_dynamics_ForLongSave_mex.h)
