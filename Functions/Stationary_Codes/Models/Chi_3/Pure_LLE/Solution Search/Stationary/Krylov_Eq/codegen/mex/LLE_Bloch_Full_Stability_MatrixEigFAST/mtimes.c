/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mtimes.c
 *
 * Code generation for function 'mtimes'
 *
 */

/* Include files */
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <stddef.h>

/* Function Definitions */
void mtimes(const creal_T A[1048576], const creal_T B[1048576], creal_T C
            [1048576])
{
  static const creal_T alpha1 = { 1.0, /* re */
    0.0                                /* im */
  };

  static const creal_T beta1 = { 0.0,  /* re */
    0.0                                /* im */
  };

  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  char_T TRANSA1;
  char_T TRANSB1;
  TRANSB1 = 'N';
  TRANSA1 = 'N';
  m_t = (ptrdiff_t)1024;
  n_t = (ptrdiff_t)1024;
  k_t = (ptrdiff_t)1024;
  lda_t = (ptrdiff_t)1024;
  ldb_t = (ptrdiff_t)1024;
  ldc_t = (ptrdiff_t)1024;
  zgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, (real_T *)&alpha1, (real_T *)&A[0],
        &lda_t, (real_T *)&B[0], &ldb_t, (real_T *)&beta1, (real_T *)&C[0],
        &ldc_t);
}

/* End of code generation (mtimes.c) */
