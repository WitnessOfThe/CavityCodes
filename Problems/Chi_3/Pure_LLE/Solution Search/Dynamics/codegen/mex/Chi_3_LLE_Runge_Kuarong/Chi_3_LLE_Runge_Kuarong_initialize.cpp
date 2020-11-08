//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  Chi_3_LLE_Runge_Kuarong_initialize.cpp
//
//  Code generation for function 'Chi_3_LLE_Runge_Kuarong_initialize'
//


// Include files
#include "Chi_3_LLE_Runge_Kuarong_initialize.h"
#include "Chi_3_LLE_Runge_Kuarong_data.h"
#include "_coder_Chi_3_LLE_Runge_Kuarong_mex.h"
#include "rt_nonfinite.h"

// Function Definitions
void Chi_3_LLE_Runge_Kuarong_initialize()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

// End of code generation (Chi_3_LLE_Runge_Kuarong_initialize.cpp)
