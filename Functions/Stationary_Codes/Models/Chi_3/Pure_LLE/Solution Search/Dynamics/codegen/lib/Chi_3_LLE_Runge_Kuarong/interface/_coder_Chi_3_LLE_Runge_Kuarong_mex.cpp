/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_Chi_3_LLE_Runge_Kuarong_mex.cpp
 *
 * MATLAB Coder version            : 4.1
 * C/C++ source code generated on  : 16-Sep-2020 20:40:18
 */

/* Include Files */
#include "_coder_Chi_3_LLE_Runge_Kuarong_api.h"
#include "_coder_Chi_3_LLE_Runge_Kuarong_mex.h"

/* Function Declarations */
static void c_Chi_3_LLE_Runge_Kuarong_mexFu(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
static void c_Chi_3_LLE_Runge_Kuarong_mexFu(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        23, "Chi_3_LLE_Runge_Kuarong");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 23,
                        "Chi_3_LLE_Runge_Kuarong");
  }

  /* Call the function. */
  Chi_3_LLE_Runge_Kuarong_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(Chi_3_LLE_Runge_Kuarong_atexit);

  /* Module initialization. */
  Chi_3_LLE_Runge_Kuarong_initialize();

  /* Dispatch the entry-point. */
  c_Chi_3_LLE_Runge_Kuarong_mexFu(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  Chi_3_LLE_Runge_Kuarong_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_Chi_3_LLE_Runge_Kuarong_mex.cpp
 *
 * [EOF]
 */
