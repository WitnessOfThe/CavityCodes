/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Chi_3_LLE_Kuar.c
 *
 * Code generation for function 'Chi_3_LLE_Kuar'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Kuar.h"
#include "ifft.h"
#include "fft1.h"
#include "power.h"
#include "abs.h"

/* Function Definitions */
void Chi_3_LLE_Kuar(const emlrtStack *sp, const creal_T F_Psi[1024], const
                    creal_T Fac_plus[1024], const creal_T Fac_minus[1024],
                    real_T t, const struct0_T *Eq, creal_T k_e[1024])
{
  int32_T i0;
  creal_T b_F_Psi[1024];
  creal_T Psi[1024];
  real_T dv0[1024];
  real_T dv1[1024];
  real_T re;
  real_T im;
  real_T Eq_re;
  real_T Eq_im;
  (void)sp;
  (void)t;
  for (i0 = 0; i0 < 1024; i0++) {
    b_F_Psi[i0].re = F_Psi[i0].re * Fac_minus[i0].re - F_Psi[i0].im *
      Fac_minus[i0].im;
    b_F_Psi[i0].im = F_Psi[i0].re * Fac_minus[i0].im + F_Psi[i0].im *
      Fac_minus[i0].re;
  }

  ifft(b_F_Psi, Psi);
  b_abs(Psi, dv0);
  power(dv0, dv1);
  for (i0 = 0; i0 < 1024; i0++) {
    b_F_Psi[i0].re = dv1[i0] * Psi[i0].re;
    b_F_Psi[i0].im = dv1[i0] * Psi[i0].im;
  }

  b_fft(b_F_Psi, k_e);
  for (i0 = 0; i0 < 1024; i0++) {
    re = 0.0 * Fac_plus[i0].re - Fac_plus[i0].im;
    im = 0.0 * Fac_plus[i0].im + Fac_plus[i0].re;
    Eq_re = Eq->gamma_Kerr[i0] * k_e[i0].re;
    Eq_im = Eq->gamma_Kerr[i0] * k_e[i0].im;
    k_e[i0].re = re * Eq_re - im * Eq_im;
    k_e[i0].im = re * Eq_im + im * Eq_re;
  }

  re = 1024.0 * Eq->h;
  k_e[0].re += (0.0 * Fac_plus[0].re - Fac_plus[0].im) * re;
  k_e[0].im += (0.0 * Fac_plus[0].im + Fac_plus[0].re) * re;
}

/* End of code generation (Chi_3_LLE_Kuar.c) */
