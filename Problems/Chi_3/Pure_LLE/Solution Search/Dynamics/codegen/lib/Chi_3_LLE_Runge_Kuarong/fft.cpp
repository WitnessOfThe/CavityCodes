//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fft.cpp
//
// MATLAB Coder version            : 4.1
// C/C++ source code generated on  : 16-Sep-2020 20:40:18
//

// Include Files
#include "rt_nonfinite.h"
#include "Chi_3_LLE_Runge_Kuarong.h"
#include "fft.h"

// Function Definitions

//
// Arguments    : const creal_T x[1024]
//                const double costab[513]
//                const double sintab[513]
//                creal_T y[1024]
// Return Type  : void
//
void r2br_r2dit_trig_impl(const creal_T x[1024], const double costab[513], const
  double sintab[513], creal_T y[1024])
{
  int ix;
  int ju;
  int iy;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double twid_re;
  int iheight;
  double twid_im;
  int istart;
  int temp_re_tmp;
  int j;
  int ihi;
  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 0; i < 1023; i++) {
    y[iy] = x[ix];
    iy = 1024;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  for (i = 0; i <= 1022; i += 2) {
    temp_re = y[i + 1].re;
    temp_im = y[i + 1].im;
    twid_re = y[i].re;
    twid_im = y[i].im;
    y[i + 1].re = y[i].re - y[i + 1].re;
    y[i + 1].im = y[i].im - y[i + 1].im;
    twid_re += temp_re;
    twid_im += temp_im;
    y[i].re = twid_re;
    y[i].im = twid_im;
  }

  iy = 2;
  ix = 4;
  ju = 256;
  iheight = 1021;
  while (ju > 0) {
    for (i = 0; i < iheight; i += ix) {
      temp_re_tmp = i + iy;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[i + iy].im;
      y[temp_re_tmp].re = y[i].re - y[temp_re_tmp].re;
      y[temp_re_tmp].im = y[i].im - temp_im;
      y[i].re += temp_re;
      y[i].im += temp_im;
    }

    istart = 1;
    for (j = ju; j < 512; j += ju) {
      twid_re = costab[j];
      twid_im = sintab[j];
      i = istart;
      ihi = istart + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y[temp_re_tmp].re - twid_im * y[i + iy].im;
        temp_im = twid_re * y[i + iy].im + twid_im * y[i + iy].re;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re += temp_re;
        y[i].im += temp_im;
        i += ix;
      }

      istart++;
    }

    ju /= 2;
    iy = ix;
    ix += ix;
    iheight -= iy;
  }
}

//
// File trailer for fft.cpp
//
// [EOF]
//
