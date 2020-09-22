/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi_3_LLE_Kuar_terminate.c
 *
 * Code generation for function 'Chi_3_LLE_Kuar_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Kuar.h"
#include "Chi_3_LLE_Kuar_terminate.h"
#include "_coder_Chi_3_LLE_Kuar_mex.h"
#include "Chi_3_LLE_Kuar_data.h"

/* Function Definitions */
void Chi_3_LLE_Kuar_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void Chi_3_LLE_Kuar_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (Chi_3_LLE_Kuar_terminate.c) */
