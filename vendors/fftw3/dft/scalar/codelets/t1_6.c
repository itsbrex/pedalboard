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
/* Generated on Tue Sep 14 10:44:27 EDT 2021 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle.native -fma -compact -variables 4
 * -pipeline-latency 4 -n 6 -name t1_6 -include dft/scalar/t.h */

/*
 * This function contains 46 FP additions, 32 FP multiplications,
 * (or, 24 additions, 10 multiplications, 22 fused multiply/add),
 * 31 stack variables, 2 constants, and 24 memory accesses
 */
#include "dft/scalar/t.h"

static void t1_6(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms) {
  DK(KP866025403, +0.866025403784438646763723170752936183471402627);
  DK(KP500000000, +0.500000000000000000000000000000000000000000000);
  {
    INT m;
    for (m = mb, W = W + (mb * 10); m < me; m = m + 1, ri = ri + ms,
        ii = ii + ms, W = W + 10, MAKE_VOLATILE_STRIDE(12, rs)) {
      E T1, TX, T7, TW, Tl, TR, TB, TJ, Ty, TS, TC, TO;
      T1 = ri[0];
      TX = ii[0];
      {
        E T3, T6, T4, TV, T2, T5;
        T3 = ri[WS(rs, 3)];
        T6 = ii[WS(rs, 3)];
        T2 = W[4];
        T4 = T2 * T3;
        TV = T2 * T6;
        T5 = W[5];
        T7 = FMA(T5, T6, T4);
        TW = FNMS(T5, T3, TV);
      }
      {
        E Ta, Td, Tb, TF, Tg, Tj, Th, TH, T9, Tf;
        Ta = ri[WS(rs, 2)];
        Td = ii[WS(rs, 2)];
        T9 = W[2];
        Tb = T9 * Ta;
        TF = T9 * Td;
        Tg = ri[WS(rs, 5)];
        Tj = ii[WS(rs, 5)];
        Tf = W[8];
        Th = Tf * Tg;
        TH = Tf * Tj;
        {
          E Te, TG, Tk, TI, Tc, Ti;
          Tc = W[3];
          Te = FMA(Tc, Td, Tb);
          TG = FNMS(Tc, Ta, TF);
          Ti = W[9];
          Tk = FMA(Ti, Tj, Th);
          TI = FNMS(Ti, Tg, TH);
          Tl = Te - Tk;
          TR = TG + TI;
          TB = Te + Tk;
          TJ = TG - TI;
        }
      }
      {
        E Tn, Tq, To, TK, Tt, Tw, Tu, TM, Tm, Ts;
        Tn = ri[WS(rs, 4)];
        Tq = ii[WS(rs, 4)];
        Tm = W[6];
        To = Tm * Tn;
        TK = Tm * Tq;
        Tt = ri[WS(rs, 1)];
        Tw = ii[WS(rs, 1)];
        Ts = W[0];
        Tu = Ts * Tt;
        TM = Ts * Tw;
        {
          E Tr, TL, Tx, TN, Tp, Tv;
          Tp = W[7];
          Tr = FMA(Tp, Tq, To);
          TL = FNMS(Tp, Tn, TK);
          Tv = W[1];
          Tx = FMA(Tv, Tw, Tu);
          TN = FNMS(Tv, Tt, TM);
          Ty = Tr - Tx;
          TS = TL + TN;
          TC = Tr + Tx;
          TO = TL - TN;
        }
      }
      {
        E TP, T8, Tz, TE;
        TP = TJ - TO;
        T8 = T1 - T7;
        Tz = Tl + Ty;
        TE = FNMS(KP500000000, Tz, T8);
        ri[WS(rs, 3)] = T8 + Tz;
        ri[WS(rs, 1)] = FMA(KP866025403, TP, TE);
        ri[WS(rs, 5)] = FNMS(KP866025403, TP, TE);
      }
      {
        E T14, T11, T12, T13;
        T14 = Ty - Tl;
        T11 = TX - TW;
        T12 = TJ + TO;
        T13 = FNMS(KP500000000, T12, T11);
        ii[WS(rs, 1)] = FMA(KP866025403, T14, T13);
        ii[WS(rs, 3)] = T12 + T11;
        ii[WS(rs, 5)] = FNMS(KP866025403, T14, T13);
      }
      {
        E TT, TA, TD, TQ;
        TT = TR - TS;
        TA = T1 + T7;
        TD = TB + TC;
        TQ = FNMS(KP500000000, TD, TA);
        ri[0] = TA + TD;
        ri[WS(rs, 4)] = FMA(KP866025403, TT, TQ);
        ri[WS(rs, 2)] = FNMS(KP866025403, TT, TQ);
      }
      {
        E T10, TU, TY, TZ;
        T10 = TC - TB;
        TU = TR + TS;
        TY = TW + TX;
        TZ = FNMS(KP500000000, TU, TY);
        ii[0] = TU + TY;
        ii[WS(rs, 4)] = FMA(KP866025403, T10, TZ);
        ii[WS(rs, 2)] = FNMS(KP866025403, T10, TZ);
      }
    }
  }
}

static const tw_instr twinstr[] = {{TW_FULL, 0, 6}, {TW_NEXT, 1, 0}};

static const ct_desc desc = {6, "t1_6", twinstr, &GENUS, {24, 10, 22, 0},
                             0, 0,      0};

void X(codelet_t1_6)(planner *p) { X(kdft_dit_register)(p, t1_6, &desc); }
#else

/* Generated by: ../../../genfft/gen_twiddle.native -compact -variables 4
 * -pipeline-latency 4 -n 6 -name t1_6 -include dft/scalar/t.h */

/*
 * This function contains 46 FP additions, 28 FP multiplications,
 * (or, 32 additions, 14 multiplications, 14 fused multiply/add),
 * 23 stack variables, 2 constants, and 24 memory accesses
 */
#include "dft/scalar/t.h"

static void t1_6(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms) {
  DK(KP500000000, +0.500000000000000000000000000000000000000000000);
  DK(KP866025403, +0.866025403784438646763723170752936183471402627);
  {
    INT m;
    for (m = mb, W = W + (mb * 10); m < me; m = m + 1, ri = ri + ms,
        ii = ii + ms, W = W + 10, MAKE_VOLATILE_STRIDE(12, rs)) {
      E T7, TS, Tv, TO, Tt, TJ, Tx, TF, Ti, TI, Tw, TC;
      {
        E T1, TN, T6, TM;
        T1 = ri[0];
        TN = ii[0];
        {
          E T3, T5, T2, T4;
          T3 = ri[WS(rs, 3)];
          T5 = ii[WS(rs, 3)];
          T2 = W[4];
          T4 = W[5];
          T6 = FMA(T2, T3, T4 * T5);
          TM = FNMS(T4, T3, T2 * T5);
        }
        T7 = T1 - T6;
        TS = TN - TM;
        Tv = T1 + T6;
        TO = TM + TN;
      }
      {
        E Tn, TD, Ts, TE;
        {
          E Tk, Tm, Tj, Tl;
          Tk = ri[WS(rs, 4)];
          Tm = ii[WS(rs, 4)];
          Tj = W[6];
          Tl = W[7];
          Tn = FMA(Tj, Tk, Tl * Tm);
          TD = FNMS(Tl, Tk, Tj * Tm);
        }
        {
          E Tp, Tr, To, Tq;
          Tp = ri[WS(rs, 1)];
          Tr = ii[WS(rs, 1)];
          To = W[0];
          Tq = W[1];
          Ts = FMA(To, Tp, Tq * Tr);
          TE = FNMS(Tq, Tp, To * Tr);
        }
        Tt = Tn - Ts;
        TJ = TD + TE;
        Tx = Tn + Ts;
        TF = TD - TE;
      }
      {
        E Tc, TA, Th, TB;
        {
          E T9, Tb, T8, Ta;
          T9 = ri[WS(rs, 2)];
          Tb = ii[WS(rs, 2)];
          T8 = W[2];
          Ta = W[3];
          Tc = FMA(T8, T9, Ta * Tb);
          TA = FNMS(Ta, T9, T8 * Tb);
        }
        {
          E Te, Tg, Td, Tf;
          Te = ri[WS(rs, 5)];
          Tg = ii[WS(rs, 5)];
          Td = W[8];
          Tf = W[9];
          Th = FMA(Td, Te, Tf * Tg);
          TB = FNMS(Tf, Te, Td * Tg);
        }
        Ti = Tc - Th;
        TI = TA + TB;
        Tw = Tc + Th;
        TC = TA - TB;
      }
      {
        E TG, Tu, Tz, TR, TT, TU;
        TG = KP866025403 * (TC - TF);
        Tu = Ti + Tt;
        Tz = FNMS(KP500000000, Tu, T7);
        ri[WS(rs, 3)] = T7 + Tu;
        ri[WS(rs, 1)] = Tz + TG;
        ri[WS(rs, 5)] = Tz - TG;
        TR = KP866025403 * (Tt - Ti);
        TT = TC + TF;
        TU = FNMS(KP500000000, TT, TS);
        ii[WS(rs, 1)] = TR + TU;
        ii[WS(rs, 3)] = TT + TS;
        ii[WS(rs, 5)] = TU - TR;
      }
      {
        E TK, Ty, TH, TQ, TL, TP;
        TK = KP866025403 * (TI - TJ);
        Ty = Tw + Tx;
        TH = FNMS(KP500000000, Ty, Tv);
        ri[0] = Tv + Ty;
        ri[WS(rs, 4)] = TH + TK;
        ri[WS(rs, 2)] = TH - TK;
        TQ = KP866025403 * (Tx - Tw);
        TL = TI + TJ;
        TP = FNMS(KP500000000, TL, TO);
        ii[0] = TL + TO;
        ii[WS(rs, 4)] = TQ + TP;
        ii[WS(rs, 2)] = TP - TQ;
      }
    }
  }
}

static const tw_instr twinstr[] = {{TW_FULL, 0, 6}, {TW_NEXT, 1, 0}};

static const ct_desc desc = {6, "t1_6", twinstr, &GENUS, {32, 14, 14, 0},
                             0, 0,      0};

void X(codelet_t1_6)(planner *p) { X(kdft_dit_register)(p, t1_6, &desc); }
#endif
