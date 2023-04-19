//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// FullField_SingleProgection_dynamics_ForLongSave_terminate.cpp
//
// Code generation for function
// 'FullField_SingleProgection_dynamics_ForLongSave_terminate'
//

// Include files
#include "FullField_SingleProgection_dynamics_ForLongSave_terminate.h"
#include "FullField_SingleProgection_dynamics_ForLongSave_data.h"
#include "_coder_FullField_SingleProgection_dynamics_ForLongSave_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void FullField_SingleProgection_dynamics_ForLongSave_atexit()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void FullField_SingleProgection_dynamics_ForLongSave_terminate()
{
  emlrtStack st{
      nullptr, // site
      nullptr, // tls
      nullptr  // prev
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation
// (FullField_SingleProgection_dynamics_ForLongSave_terminate.cpp)
