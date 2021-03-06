/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_Chi23OPO_Runge_Kuarong_mex.c
 *
 * Code generation for function '_coder_Chi23OPO_Runge_Kuarong_mex'
 *
 */

/* Include files */
#include "Chi23OPO_Runge_Kuarong.h"
#include "_coder_Chi23OPO_Runge_Kuarong_mex.h"
#include "Chi23OPO_Runge_Kuarong_terminate.h"
#include "_coder_Chi23OPO_Runge_Kuarong_api.h"
#include "Chi23OPO_Runge_Kuarong_initialize.h"
#include "Chi23OPO_Runge_Kuarong_data.h"

/* Function Declarations */
static void c_Chi23OPO_Runge_Kuarong_mexFun(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
static void c_Chi23OPO_Runge_Kuarong_mexFun(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        22, "Chi23OPO_Runge_Kuarong");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 22,
                        "Chi23OPO_Runge_Kuarong");
  }

  /* Call the function. */
  Chi23OPO_Runge_Kuarong_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(Chi23OPO_Runge_Kuarong_atexit);

  /* Module initialization. */
  Chi23OPO_Runge_Kuarong_initialize();

  /* Dispatch the entry-point. */
  c_Chi23OPO_Runge_Kuarong_mexFun(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Chi23OPO_Runge_Kuarong_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_Chi23OPO_Runge_Kuarong_mex.c) */
