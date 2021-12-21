/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_LLE_Bloch_StabilitySpeedUp_mex.c
 *
 * Code generation for function '_coder_LLE_Bloch_StabilitySpeedUp_mex'
 *
 */

/* Include files */
#include "_coder_LLE_Bloch_StabilitySpeedUp_mex.h"
#include "LLE_Bloch_StabilitySpeedUp_data.h"
#include "LLE_Bloch_StabilitySpeedUp_initialize.h"
#include "LLE_Bloch_StabilitySpeedUp_terminate.h"
#include "LLE_Bloch_StabilitySpeedUp_types.h"
#include "_coder_LLE_Bloch_StabilitySpeedUp_api.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void LLE_Bloch_StabilitySpeedUp_mexFunction(c_LLE_Bloch_StabilitySpeedUpSta *SD,
  int32_T nlhs, mxArray *plhs[4], int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  const mxArray *outputs[4];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        26, "LLE_Bloch_StabilitySpeedUp");
  }

  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 26,
                        "LLE_Bloch_StabilitySpeedUp");
  }

  /* Call the function. */
  LLE_Bloch_StabilitySpeedUp_api(SD, prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  c_LLE_Bloch_StabilitySpeedUpSta *d_LLE_Bloch_StabilitySpeedUpSta = NULL;
  d_LLE_Bloch_StabilitySpeedUpSta = (c_LLE_Bloch_StabilitySpeedUpSta *)
    emlrtMxCalloc(1, (size_t)1U * sizeof(c_LLE_Bloch_StabilitySpeedUpSta));
  mexAtExit(&LLE_Bloch_StabilitySpeedUp_atexit);

  /* Module initialization. */
  LLE_Bloch_StabilitySpeedUp_initialize();

  /* Dispatch the entry-point. */
  LLE_Bloch_StabilitySpeedUp_mexFunction(d_LLE_Bloch_StabilitySpeedUpSta, nlhs,
    plhs, nrhs, prhs);

  /* Module termination. */
  LLE_Bloch_StabilitySpeedUp_terminate();
  emlrtMxFree(d_LLE_Bloch_StabilitySpeedUpSta);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_LLE_Bloch_StabilitySpeedUp_mex.c) */
