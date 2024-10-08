/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Tue Sep 14 10:47:07 EDT 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_hc2c.native -fma -compact -variables 4
 * -pipeline-latency 4 -sign 1 -n 4 -dif -name hc2cb_4 -include
 * rdft/scalar/hc2cb.h */

/*
 * This function contains 22 FP additions, 12 FP multiplications,
 * (or, 16 additions, 6 multiplications, 6 fused multiply/add),
 * 22 stack variables, 0 constants, and 16 memory accesses
 */
#include "rdft/scalar/hc2cb.h"

static void hc2cb_4(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb,
                    INT me, INT ms) {
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * 6); m < me; m = m + 1, Rp = Rp + ms,
        Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 6,
        MAKE_VOLATILE_STRIDE(16, rs)) {
      E T3, T6, T8, Td, Tx, Tu, Tm, Tg, Tr;
      {
        E Tb, Tc, Tq, Tk, Te, Tf, Tl, Tp;
        {
          E T1, T2, T4, T5;
          Tb = Ip[0];
          Tc = Im[WS(rs, 1)];
          Tq = Tb + Tc;
          T1 = Rp[0];
          T2 = Rm[WS(rs, 1)];
          T3 = T1 + T2;
          Tk = T1 - T2;
          Te = Ip[WS(rs, 1)];
          Tf = Im[0];
          Tl = Te + Tf;
          T4 = Rp[WS(rs, 1)];
          T5 = Rm[0];
          T6 = T4 + T5;
          Tp = T4 - T5;
        }
        T8 = T3 - T6;
        Td = Tb - Tc;
        Tx = Tq - Tp;
        Tu = Tk + Tl;
        Tm = Tk - Tl;
        Tg = Te - Tf;
        Tr = Tp + Tq;
      }
      Rp[0] = T3 + T6;
      Rm[0] = Td + Tg;
      {
        E Tn, Ts, Tj, To;
        Tj = W[0];
        Tn = Tj * Tm;
        Ts = Tj * Tr;
        To = W[1];
        Ip[0] = FNMS(To, Tr, Tn);
        Im[0] = FMA(To, Tm, Ts);
      }
      {
        E Tv, Ty, Tt, Tw;
        Tt = W[4];
        Tv = Tt * Tu;
        Ty = Tt * Tx;
        Tw = W[5];
        Ip[WS(rs, 1)] = FNMS(Tw, Tx, Tv);
        Im[WS(rs, 1)] = FMA(Tw, Tu, Ty);
      }
      {
        E Th, Ta, Ti, T7, T9;
        Th = Td - Tg;
        Ta = W[3];
        Ti = Ta * T8;
        T7 = W[2];
        T9 = T7 * T8;
        Rp[WS(rs, 1)] = FNMS(Ta, Th, T9);
        Rm[WS(rs, 1)] = FMA(T7, Th, Ti);
      }
    }
  }
}

static const tw_instr twinstr[] = {{TW_FULL, 1, 4}, {TW_NEXT, 1, 0}};

static const hc2c_desc desc = {4, "hc2cb_4", twinstr, &GENUS, {16, 6, 6, 0}};

void X(codelet_hc2cb_4)(planner *p) {
  X(khc2c_register)(p, hc2cb_4, &desc, HC2C_VIA_RDFT);
}
#else

/* Generated by: ../../../genfft/gen_hc2c.native -compact -variables 4
 * -pipeline-latency 4 -sign 1 -n 4 -dif -name hc2cb_4 -include
 * rdft/scalar/hc2cb.h */

/*
 * This function contains 22 FP additions, 12 FP multiplications,
 * (or, 16 additions, 6 multiplications, 6 fused multiply/add),
 * 13 stack variables, 0 constants, and 16 memory accesses
 */
#include "rdft/scalar/hc2cb.h"

static void hc2cb_4(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb,
                    INT me, INT ms) {
  {
    INT m;
    for (m = mb, W = W + ((mb - 1) * 6); m < me; m = m + 1, Rp = Rp + ms,
        Ip = Ip + ms, Rm = Rm - ms, Im = Im - ms, W = W + 6,
        MAKE_VOLATILE_STRIDE(16, rs)) {
      E T3, Ti, Tc, Tn, T6, Tm, Tf, Tj;
      {
        E T1, T2, Ta, Tb;
        T1 = Rp[0];
        T2 = Rm[WS(rs, 1)];
        T3 = T1 + T2;
        Ti = T1 - T2;
        Ta = Ip[0];
        Tb = Im[WS(rs, 1)];
        Tc = Ta - Tb;
        Tn = Ta + Tb;
      }
      {
        E T4, T5, Td, Te;
        T4 = Rp[WS(rs, 1)];
        T5 = Rm[0];
        T6 = T4 + T5;
        Tm = T4 - T5;
        Td = Ip[WS(rs, 1)];
        Te = Im[0];
        Tf = Td - Te;
        Tj = Td + Te;
      }
      Rp[0] = T3 + T6;
      Rm[0] = Tc + Tf;
      {
        E T8, Tg, T7, T9;
        T8 = T3 - T6;
        Tg = Tc - Tf;
        T7 = W[2];
        T9 = W[3];
        Rp[WS(rs, 1)] = FNMS(T9, Tg, T7 * T8);
        Rm[WS(rs, 1)] = FMA(T9, T8, T7 * Tg);
      }
      {
        E Tk, To, Th, Tl;
        Tk = Ti - Tj;
        To = Tm + Tn;
        Th = W[0];
        Tl = W[1];
        Ip[0] = FNMS(Tl, To, Th * Tk);
        Im[0] = FMA(Th, To, Tl * Tk);
      }
      {
        E Tq, Ts, Tp, Tr;
        Tq = Ti + Tj;
        Ts = Tn - Tm;
        Tp = W[4];
        Tr = W[5];
        Ip[WS(rs, 1)] = FNMS(Tr, Ts, Tp * Tq);
        Im[WS(rs, 1)] = FMA(Tp, Ts, Tr * Tq);
      }
    }
  }
}

static const tw_instr twinstr[] = {{TW_FULL, 1, 4}, {TW_NEXT, 1, 0}};

static const hc2c_desc desc = {4, "hc2cb_4", twinstr, &GENUS, {16, 6, 6, 0}};

void X(codelet_hc2cb_4)(planner *p) {
  X(khc2c_register)(p, hc2cb_4, &desc, HC2C_VIA_RDFT);
}
#endif
