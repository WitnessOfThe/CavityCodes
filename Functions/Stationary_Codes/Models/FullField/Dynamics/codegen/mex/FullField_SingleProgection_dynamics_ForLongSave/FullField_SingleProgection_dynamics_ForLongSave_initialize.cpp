//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// FullField_SingleProgection_dynamics_ForLongSave_initialize.cpp
//
// Code generation for function
// 'FullField_SingleProgection_dynamics_ForLongSave_initialize'
//

// Include files
#include "FullField_SingleProgection_dynamics_ForLongSave_initialize.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_data.h"
#include "_coder_FullField_SingleProgection_dynamics_ForLongSave_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void FullField_SingleProgection_dynamics_ForLongSave_initialize()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, nullptr);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

// End of code generation
// (FullField_SingleProgection_dynamics_ForLongSave_initialize.cpp)
