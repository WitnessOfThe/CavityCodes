//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Chi_3_LLE_Runge_Kuarong.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 16-Sep-2020 20:40:18
//

// Include Files
#include <cmath>
#include <string.h>
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "Chi_3_LLE_Runge_Kuarong_emxutil.h"
#include "Chi_3_LLE_Kuar.h"

// Function Declarations
static double rt_roundd_snf(double u);

// Function Definitions

//
// Arguments    : double u
// Return Type  : double
//
static double rt_roundd_snf(double u)
{
  double y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// Arguments    : const struct0_T *Temp
//                double N_modes
//                const struct5_T *Runge
//                struct6_T *Sol
// Return Type  : void
//
void Chi_3_LLE_Runge_Kuarong(const struct0_T *Temp, double, const struct5_T
  *Runge, struct6_T *Sol)
{
  emxArray_cuint8_T *d;
  int i0;
  int i1;
  int loop_ub;
  double dt;
  int i;
  double b_Runge;
  int k;
  double re;
  double q;
  double im;
  double im_tmp;
  creal_T shift_back[1024];
  double r;
  creal_T F_e[1024];
  static creal_T exp_minus_omega[3072];
  emxArray_creal_T *b_d;
  int ni;
  int i2;
  static creal_T exp_plus_omega[3072];
  creal_T E_temp[1024];
  creal_T b_exp_plus_omega[1024];
  creal_T b_exp_minus_omega[1024];
  creal_T dcv0[1024];
  int b_i2;
  int i3;
  creal_T b_E_temp[600];
  boolean_T rEQ0;
  emxInit_cuint8_T(&d, 2);
  i0 = d->size[0] * d->size[1];
  i1 = (int)Runge->s;
  d->size[0] = i1;
  d->size[1] = 1024;
  emxEnsureCapacity_cuint8_T(d, i0);
  loop_ub = i1 << 10;
  for (i0 = 0; i0 < loop_ub; i0++) {
    d->data[i0].re = 0U;
    d->data[i0].im = 0U;
  }

  dt = Temp->Par.dt;

  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  for (i = 0; i < 3; i++) {
    b_Runge = Runge->a[i];
    for (k = 0; k < 1024; k++) {
      q = 0.0 * Temp->Eq.L[k].re;
      im_tmp = 0.0 * Temp->Eq.L[k].im;
      re = dt * (b_Runge * (q - (-Temp->Eq.L[k].im)));
      im = dt * (b_Runge * (im_tmp + -Temp->Eq.L[k].re));
      if (im == 0.0) {
        re = std::exp(re);
        im = 0.0;
      } else if (rtIsInf(im) && rtIsInf(re) && (re < 0.0)) {
        re = 0.0;
        im = 0.0;
      } else {
        r = std::exp(re / 2.0);
        re = r * (r * std::cos(im));
        im = r * (r * std::sin(im));
      }

      i0 = i + 3 * k;
      exp_minus_omega[i0].re = re;
      exp_minus_omega[i0].im = im;
      re = dt * (b_Runge * (q - Temp->Eq.L[k].im));
      im = dt * (b_Runge * (im_tmp + Temp->Eq.L[k].re));
      shift_back[k].re = re;
      shift_back[k].im = im;
      if (im == 0.0) {
        re = std::exp(re);
        im = 0.0;
        shift_back[k].re = re;
        shift_back[k].im = 0.0;
      } else if (rtIsInf(im) && rtIsInf(re) && (re < 0.0)) {
        re = 0.0;
        im = 0.0;
        shift_back[k].re = 0.0;
        shift_back[k].im = 0.0;
      } else {
        r = std::exp(re / 2.0);
        re = r * (r * std::cos(im));
        im = r * (r * std::sin(im));
        shift_back[k].re = re;
        shift_back[k].im = im;
      }

      exp_plus_omega[i0].re = re;
      exp_plus_omega[i0].im = im;
    }
  }

  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  for (k = 0; k < 1024; k++) {
    re = Temp->Par.dt * (0.0 * Temp->Eq.L[k].re - (-Temp->Eq.L[k].im));
    im = Temp->Par.dt * (0.0 * Temp->Eq.L[k].im + -Temp->Eq.L[k].re);
    shift_back[k].re = re;
    shift_back[k].im = im;
    if (im == 0.0) {
      re = std::exp(re);
      shift_back[k].re = re;
      shift_back[k].im = 0.0;
    } else if (rtIsInf(im) && rtIsInf(re) && (re < 0.0)) {
      shift_back[k].re = 0.0;
      shift_back[k].im = 0.0;
    } else {
      r = std::exp(re / 2.0);
      re = r * (r * std::cos(im));
      im = r * (r * std::sin(im));
      shift_back[k].re = re;
      shift_back[k].im = im;
    }

    F_e[k] = Temp->In.Psi_Start[k];
  }

  i0 = Sol->Psi->size[0] * Sol->Psi->size[1];
  loop_ub = (int)Temp->Par.dd;
  Sol->Psi->size[0] = loop_ub;
  Sol->Psi->size[1] = 600;
  emxEnsureCapacity_creal_T(Sol->Psi, i0);
  i = loop_ub * 600;
  for (i0 = 0; i0 < i; i0++) {
    Sol->Psi->data[i0].re = 0.0;
    Sol->Psi->data[i0].im = 0.0;
  }

  i0 = Sol->t->size[0] * Sol->t->size[1];
  Sol->t->size[0] = 1;
  Sol->t->size[1] = loop_ub;
  emxEnsureCapacity_creal_T(Sol->t, i0);
  for (i0 = 0; i0 < loop_ub; i0++) {
    Sol->t->data[i0].re = 0.0;
    Sol->t->data[i0].im = 0.0;
  }

  i0 = (int)(Temp->Par.T / Temp->Par.dt);
  emxInit_creal_T(&b_d, 2);
  for (ni = 0; ni < i0; ni++) {
    i2 = b_d->size[0] * b_d->size[1];
    b_d->size[0] = d->size[0];
    b_d->size[1] = 1024;
    emxEnsureCapacity_creal_T(b_d, i2);
    loop_ub = d->size[0] * d->size[1];
    for (i2 = 0; i2 < loop_ub; i2++) {
      i = d->data[i2].re;
      k = d->data[i2].im;
      b_d->data[i2].re = i;
      b_d->data[i2].im = k;
    }

    memcpy(&E_temp[0], &F_e[0], sizeof(creal_T) << 10);
    for (i2 = 0; i2 < 1024; i2++) {
      b_exp_plus_omega[i2] = exp_plus_omega[3 * i2];
      b_exp_minus_omega[i2] = exp_minus_omega[3 * i2];
    }

    Chi_3_LLE_Kuar(F_e, b_exp_plus_omega, b_exp_minus_omega, Temp->Eq.h,
                   Temp->Eq.gamma_Kerr, dcv0);
    for (i2 = 0; i2 < 1024; i2++) {
      b_d->data[b_d->size[0] * i2] = dcv0[i2];
    }

    i2 = (int)(Runge->s + -1.0);
    for (b_i2 = 0; b_i2 < i2; b_i2++) {
      i3 = (int)(Runge->s - 1.0);
      for (i = 0; i < i3; i++) {
        b_Runge = Runge->b[(b_i2 + 3 * i) + 1];
        if (b_Runge != 0.0) {
          b_Runge *= dt;
          for (k = 0; k < 600; k++) {
            loop_ub = (int)Temp->Eq.mode_range[k] - 1;
            b_E_temp[k].re = E_temp[loop_ub].re + b_Runge * b_d->data[i +
              b_d->size[0] * loop_ub].re;
            b_E_temp[k].im = E_temp[(int)Temp->Eq.mode_range[k] - 1].im +
              b_Runge * b_d->data[i + b_d->size[0] * ((int)Temp->Eq.mode_range[k]
              - 1)].im;
          }

          for (k = 0; k < 600; k++) {
            E_temp[(int)Temp->Eq.mode_range[k] - 1] = b_E_temp[k];
          }
        }
      }

      for (i3 = 0; i3 < 1024; i3++) {
        i = (b_i2 + 3 * i3) + 1;
        b_exp_plus_omega[i3] = exp_plus_omega[i];
        b_exp_minus_omega[i3] = exp_minus_omega[i];
      }

      Chi_3_LLE_Kuar(E_temp, b_exp_plus_omega, b_exp_minus_omega, Temp->Eq.h,
                     Temp->Eq.gamma_Kerr, dcv0);
      for (i3 = 0; i3 < 1024; i3++) {
        b_d->data[(b_i2 + b_d->size[0] * i3) + 1] = dcv0[i3];
        E_temp[i3] = F_e[i3];
      }
    }

    for (i = 0; i < i1; i++) {
      if (Runge->c[i] != 0.0) {
        b_Runge = dt * Runge->c[i];
        for (i2 = 0; i2 < 600; i2++) {
          i3 = (int)Temp->Eq.mode_range[i2] - 1;
          b_E_temp[i2].re = F_e[i3].re + b_Runge * b_d->data[i + b_d->size[0] *
            i3].re;
          b_E_temp[i2].im = F_e[(int)Temp->Eq.mode_range[i2] - 1].im + b_Runge *
            b_d->data[i + b_d->size[0] * ((int)Temp->Eq.mode_range[i2] - 1)].im;
        }

        for (i2 = 0; i2 < 600; i2++) {
          F_e[(int)Temp->Eq.mode_range[i2] - 1] = b_E_temp[i2];
        }
      }
    }

    for (i2 = 0; i2 < 600; i2++) {
      i3 = (int)Temp->Eq.mode_range[i2] - 1;
      b_E_temp[i2].re = shift_back[i3].re * F_e[i3].re - shift_back[(int)
        Temp->Eq.mode_range[i2] - 1].im * F_e[(int)Temp->Eq.mode_range[i2] - 1].
        im;
      b_E_temp[i2].im = shift_back[(int)Temp->Eq.mode_range[i2] - 1].re * F_e
        [(int)Temp->Eq.mode_range[i2] - 1].im + shift_back[(int)
        Temp->Eq.mode_range[i2] - 1].im * F_e[(int)Temp->Eq.mode_range[i2] - 1].
        re;
    }

    for (i2 = 0; i2 < 600; i2++) {
      F_e[(int)Temp->Eq.mode_range[i2] - 1] = b_E_temp[i2];
    }

    //      Temp      =   Temp.Met.Ev_Save(F_e,Temp,ni);
    b_Runge = Temp->Par.s_t / Temp->Par.dt;
    r = 1.0 + (double)ni;
    if ((!rtIsInf(b_Runge)) && (!rtIsNaN(b_Runge))) {
      if (b_Runge != 0.0) {
        r = std::fmod(1.0 + (double)ni, b_Runge);
        rEQ0 = (r == 0.0);
        if ((!rEQ0) && (b_Runge > std::floor(b_Runge))) {
          q = std::abs((1.0 + (double)ni) / b_Runge);
          rEQ0 = (std::abs(q - std::floor(q + 0.5)) <= 2.2204460492503131E-16 *
                  q);
        }

        if (rEQ0) {
          r = b_Runge * 0.0;
        } else {
          if (b_Runge < 0.0) {
            r += b_Runge;
          }
        }
      }
    } else {
      if (b_Runge != 0.0) {
        r = rtNaN;
      }
    }

    if (r == 0.0) {
      //    toc
      b_Runge = (1.0 + (double)ni) * Temp->Par.dt;
      i2 = (int)rt_roundd_snf(b_Runge / Temp->Par.s_t);
      for (i3 = 0; i3 < 600; i3++) {
        q = F_e[(int)Temp->Eq.mode_range[i3] - 1].re;
        im_tmp = F_e[(int)Temp->Eq.mode_range[i3] - 1].im;
        if (im_tmp == 0.0) {
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i3) - 1].re = q /
            Temp->Space.N;
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i3) - 1].im = 0.0;
        } else if (q == 0.0) {
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i3) - 1].re = 0.0;
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i3) - 1].im = im_tmp /
            Temp->Space.N;
        } else {
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i3) - 1].re = q /
            Temp->Space.N;
          Sol->Psi->data[(i2 + Sol->Psi->size[0] * i3) - 1].im = im_tmp /
            Temp->Space.N;
        }
      }

      i2 = (int)rt_roundd_snf(b_Runge / Temp->Par.s_t) - 1;
      Sol->t->data[i2].re = Temp->Par.dt * (1.0 + (double)ni);
      Sol->t->data[i2].im = 0.0;

      //     tic
    }
  }

  emxFree_creal_T(&b_d);
  emxFree_cuint8_T(&d);

  // %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
}

//
// File trailer for Chi_3_LLE_Runge_Kuarong.cpp
//
// [EOF]
//
