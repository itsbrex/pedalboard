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
/* Generated on Tue Sep 14 10:45:13 EDT 2021 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_notw_c.native -fma -simd -compact
 * -variables 4 -pipeline-latency 8 -n 16 -name n2fv_16 -with-ostride 2 -include
 * dft/simd/n2f.h -store-multiple 2 */

/*
 * This function contains 72 FP additions, 34 FP multiplications,
 * (or, 38 additions, 0 multiplications, 34 fused multiply/add),
 * 38 stack variables, 3 constants, and 40 memory accesses
 */
#include "dft/simd/n2f.h"

static void n2fv_16(const R *ri, const R *ii, R *ro, R *io, stride is,
                    stride os, INT v, INT ivs, INT ovs) {
  DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
  DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
  DVK(KP414213562, +0.414213562373095048801688724209698078569671875);
  {
    INT i;
    const R *xi;
    R *xo;
    xi = ri;
    xo = ro;
    for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs),
        MAKE_VOLATILE_STRIDE(32, is), MAKE_VOLATILE_STRIDE(32, os)) {
      V T7, TU, Tz, TH, Tu, TV, TA, TK, Te, TX, TC, TO, Tl, TY, TD;
      V TR;
      {
        V T1, T2, T3, T4, T5, T6;
        T1 = LD(&(xi[0]), ivs, &(xi[0]));
        T2 = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
        T3 = VADD(T1, T2);
        T4 = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
        T5 = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
        T6 = VADD(T4, T5);
        T7 = VSUB(T3, T6);
        TU = VSUB(T4, T5);
        Tz = VADD(T3, T6);
        TH = VSUB(T1, T2);
      }
      {
        V Tq, TJ, Tt, TI;
        {
          V To, Tp, Tr, Ts;
          To = LD(&(xi[WS(is, 14)]), ivs, &(xi[0]));
          Tp = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
          Tq = VADD(To, Tp);
          TJ = VSUB(To, Tp);
          Tr = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
          Ts = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
          Tt = VADD(Tr, Ts);
          TI = VSUB(Tr, Ts);
        }
        Tu = VSUB(Tq, Tt);
        TV = VSUB(TJ, TI);
        TA = VADD(Tt, Tq);
        TK = VADD(TI, TJ);
      }
      {
        V Ta, TM, Td, TN;
        {
          V T8, T9, Tb, Tc;
          T8 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
          T9 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
          Ta = VADD(T8, T9);
          TM = VSUB(T8, T9);
          Tb = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
          Tc = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
          Td = VADD(Tb, Tc);
          TN = VSUB(Tb, Tc);
        }
        Te = VSUB(Ta, Td);
        TX = VFMA(LDK(KP414213562), TM, TN);
        TC = VADD(Ta, Td);
        TO = VFNMS(LDK(KP414213562), TN, TM);
      }
      {
        V Th, TP, Tk, TQ;
        {
          V Tf, Tg, Ti, Tj;
          Tf = LD(&(xi[WS(is, 15)]), ivs, &(xi[WS(is, 1)]));
          Tg = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
          Th = VADD(Tf, Tg);
          TP = VSUB(Tf, Tg);
          Ti = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
          Tj = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
          Tk = VADD(Ti, Tj);
          TQ = VSUB(Tj, Ti);
        }
        Tl = VSUB(Th, Tk);
        TY = VFMA(LDK(KP414213562), TP, TQ);
        TD = VADD(Th, Tk);
        TR = VFNMS(LDK(KP414213562), TQ, TP);
      }
      {
        V T1b, T1c, T1d, T1e;
        {
          V TB, TE, TF, TG;
          TB = VADD(Tz, TA);
          TE = VADD(TC, TD);
          T1b = VSUB(TB, TE);
          STM2(&(xo[16]), T1b, ovs, &(xo[0]));
          T1c = VADD(TB, TE);
          STM2(&(xo[0]), T1c, ovs, &(xo[0]));
          TF = VSUB(Tz, TA);
          TG = VSUB(TD, TC);
          T1d = VFNMSI(TG, TF);
          STM2(&(xo[24]), T1d, ovs, &(xo[0]));
          T1e = VFMAI(TG, TF);
          STM2(&(xo[8]), T1e, ovs, &(xo[0]));
        }
        {
          V T1f, T1g, T1h, T1i;
          {
            V Tn, Tx, Tw, Ty, Tm, Tv;
            Tm = VADD(Te, Tl);
            Tn = VFNMS(LDK(KP707106781), Tm, T7);
            Tx = VFMA(LDK(KP707106781), Tm, T7);
            Tv = VSUB(Tl, Te);
            Tw = VFNMS(LDK(KP707106781), Tv, Tu);
            Ty = VFMA(LDK(KP707106781), Tv, Tu);
            T1f = VFNMSI(Tw, Tn);
            STM2(&(xo[12]), T1f, ovs, &(xo[0]));
            T1g = VFMAI(Ty, Tx);
            STM2(&(xo[4]), T1g, ovs, &(xo[0]));
            T1h = VFMAI(Tw, Tn);
            STM2(&(xo[20]), T1h, ovs, &(xo[0]));
            T1i = VFNMSI(Ty, Tx);
            STM2(&(xo[28]), T1i, ovs, &(xo[0]));
          }
          {
            V TT, T11, T10, T12;
            {
              V TL, TS, TW, TZ;
              TL = VFMA(LDK(KP707106781), TK, TH);
              TS = VADD(TO, TR);
              TT = VFNMS(LDK(KP923879532), TS, TL);
              T11 = VFMA(LDK(KP923879532), TS, TL);
              TW = VFNMS(LDK(KP707106781), TV, TU);
              TZ = VSUB(TX, TY);
              T10 = VFNMS(LDK(KP923879532), TZ, TW);
              T12 = VFMA(LDK(KP923879532), TZ, TW);
            }
            {
              V T1j, T1k, T1l, T1m;
              T1j = VFNMSI(T10, TT);
              STM2(&(xo[18]), T1j, ovs, &(xo[2]));
              STN2(&(xo[16]), T1b, T1j, ovs);
              T1k = VFMAI(T12, T11);
              STM2(&(xo[30]), T1k, ovs, &(xo[2]));
              STN2(&(xo[28]), T1i, T1k, ovs);
              T1l = VFMAI(T10, TT);
              STM2(&(xo[14]), T1l, ovs, &(xo[2]));
              STN2(&(xo[12]), T1f, T1l, ovs);
              T1m = VFNMSI(T12, T11);
              STM2(&(xo[2]), T1m, ovs, &(xo[2]));
              STN2(&(xo[0]), T1c, T1m, ovs);
            }
          }
          {
            V T15, T19, T18, T1a;
            {
              V T13, T14, T16, T17;
              T13 = VFNMS(LDK(KP707106781), TK, TH);
              T14 = VADD(TX, TY);
              T15 = VFNMS(LDK(KP923879532), T14, T13);
              T19 = VFMA(LDK(KP923879532), T14, T13);
              T16 = VFMA(LDK(KP707106781), TV, TU);
              T17 = VSUB(TR, TO);
              T18 = VFNMS(LDK(KP923879532), T17, T16);
              T1a = VFMA(LDK(KP923879532), T17, T16);
            }
            {
              V T1n, T1o, T1p, T1q;
              T1n = VFNMSI(T18, T15);
              STM2(&(xo[10]), T1n, ovs, &(xo[2]));
              STN2(&(xo[8]), T1e, T1n, ovs);
              T1o = VFNMSI(T1a, T19);
              STM2(&(xo[26]), T1o, ovs, &(xo[2]));
              STN2(&(xo[24]), T1d, T1o, ovs);
              T1p = VFMAI(T18, T15);
              STM2(&(xo[22]), T1p, ovs, &(xo[2]));
              STN2(&(xo[20]), T1h, T1p, ovs);
              T1q = VFMAI(T1a, T19);
              STM2(&(xo[6]), T1q, ovs, &(xo[2]));
              STN2(&(xo[4]), T1g, T1q, ovs);
            }
          }
        }
      }
    }
  }
  VLEAVE();
}

static const kdft_desc desc = {
    16, XSIMD_STRING("n2fv_16"), {38, 0, 34, 0}, &GENUS, 0, 2, 0, 0};

void XSIMD(codelet_n2fv_16)(planner *p) { X(kdft_register)(p, n2fv_16, &desc); }

#else

/* Generated by: ../../../genfft/gen_notw_c.native -simd -compact -variables 4
 * -pipeline-latency 8 -n 16 -name n2fv_16 -with-ostride 2 -include
 * dft/simd/n2f.h -store-multiple 2 */

/*
 * This function contains 72 FP additions, 12 FP multiplications,
 * (or, 68 additions, 8 multiplications, 4 fused multiply/add),
 * 38 stack variables, 3 constants, and 40 memory accesses
 */
#include "dft/simd/n2f.h"

static void n2fv_16(const R *ri, const R *ii, R *ro, R *io, stride is,
                    stride os, INT v, INT ivs, INT ovs) {
  DVK(KP923879532, +0.923879532511286756128183189396788286822416626);
  DVK(KP382683432, +0.382683432365089771728459984030398866761344562);
  DVK(KP707106781, +0.707106781186547524400844362104849039284835938);
  {
    INT i;
    const R *xi;
    R *xo;
    xi = ri;
    xo = ro;
    for (i = v; i > 0; i = i - VL, xi = xi + (VL * ivs), xo = xo + (VL * ovs),
        MAKE_VOLATILE_STRIDE(32, is), MAKE_VOLATILE_STRIDE(32, os)) {
      V Tp, T13, Tu, TN, Tm, T14, Tv, TY, T7, T17, Ty, TT, Te, T16, Tx;
      V TQ;
      {
        V Tn, To, TM, Ts, Tt, TL;
        Tn = LD(&(xi[WS(is, 4)]), ivs, &(xi[0]));
        To = LD(&(xi[WS(is, 12)]), ivs, &(xi[0]));
        TM = VADD(Tn, To);
        Ts = LD(&(xi[0]), ivs, &(xi[0]));
        Tt = LD(&(xi[WS(is, 8)]), ivs, &(xi[0]));
        TL = VADD(Ts, Tt);
        Tp = VSUB(Tn, To);
        T13 = VADD(TL, TM);
        Tu = VSUB(Ts, Tt);
        TN = VSUB(TL, TM);
      }
      {
        V Ti, TW, Tl, TX;
        {
          V Tg, Th, Tj, Tk;
          Tg = LD(&(xi[WS(is, 14)]), ivs, &(xi[0]));
          Th = LD(&(xi[WS(is, 6)]), ivs, &(xi[0]));
          Ti = VSUB(Tg, Th);
          TW = VADD(Tg, Th);
          Tj = LD(&(xi[WS(is, 2)]), ivs, &(xi[0]));
          Tk = LD(&(xi[WS(is, 10)]), ivs, &(xi[0]));
          Tl = VSUB(Tj, Tk);
          TX = VADD(Tj, Tk);
        }
        Tm = VMUL(LDK(KP707106781), VSUB(Ti, Tl));
        T14 = VADD(TX, TW);
        Tv = VMUL(LDK(KP707106781), VADD(Tl, Ti));
        TY = VSUB(TW, TX);
      }
      {
        V T3, TR, T6, TS;
        {
          V T1, T2, T4, T5;
          T1 = LD(&(xi[WS(is, 15)]), ivs, &(xi[WS(is, 1)]));
          T2 = LD(&(xi[WS(is, 7)]), ivs, &(xi[WS(is, 1)]));
          T3 = VSUB(T1, T2);
          TR = VADD(T1, T2);
          T4 = LD(&(xi[WS(is, 3)]), ivs, &(xi[WS(is, 1)]));
          T5 = LD(&(xi[WS(is, 11)]), ivs, &(xi[WS(is, 1)]));
          T6 = VSUB(T4, T5);
          TS = VADD(T4, T5);
        }
        T7 = VFNMS(LDK(KP923879532), T6, VMUL(LDK(KP382683432), T3));
        T17 = VADD(TR, TS);
        Ty = VFMA(LDK(KP923879532), T3, VMUL(LDK(KP382683432), T6));
        TT = VSUB(TR, TS);
      }
      {
        V Ta, TO, Td, TP;
        {
          V T8, T9, Tb, Tc;
          T8 = LD(&(xi[WS(is, 1)]), ivs, &(xi[WS(is, 1)]));
          T9 = LD(&(xi[WS(is, 9)]), ivs, &(xi[WS(is, 1)]));
          Ta = VSUB(T8, T9);
          TO = VADD(T8, T9);
          Tb = LD(&(xi[WS(is, 5)]), ivs, &(xi[WS(is, 1)]));
          Tc = LD(&(xi[WS(is, 13)]), ivs, &(xi[WS(is, 1)]));
          Td = VSUB(Tb, Tc);
          TP = VADD(Tb, Tc);
        }
        Te = VFMA(LDK(KP382683432), Ta, VMUL(LDK(KP923879532), Td));
        T16 = VADD(TO, TP);
        Tx = VFNMS(LDK(KP382683432), Td, VMUL(LDK(KP923879532), Ta));
        TQ = VSUB(TO, TP);
      }
      {
        V T1b, T1c, T1d, T1e;
        {
          V T15, T18, T19, T1a;
          T15 = VADD(T13, T14);
          T18 = VADD(T16, T17);
          T1b = VSUB(T15, T18);
          STM2(&(xo[16]), T1b, ovs, &(xo[0]));
          T1c = VADD(T15, T18);
          STM2(&(xo[0]), T1c, ovs, &(xo[0]));
          T19 = VSUB(T13, T14);
          T1a = VBYI(VSUB(T17, T16));
          T1d = VSUB(T19, T1a);
          STM2(&(xo[24]), T1d, ovs, &(xo[0]));
          T1e = VADD(T19, T1a);
          STM2(&(xo[8]), T1e, ovs, &(xo[0]));
        }
        {
          V T1f, T1g, T1h, T1i;
          {
            V TV, T11, T10, T12, TU, TZ;
            TU = VMUL(LDK(KP707106781), VADD(TQ, TT));
            TV = VADD(TN, TU);
            T11 = VSUB(TN, TU);
            TZ = VMUL(LDK(KP707106781), VSUB(TT, TQ));
            T10 = VBYI(VADD(TY, TZ));
            T12 = VBYI(VSUB(TZ, TY));
            T1f = VSUB(TV, T10);
            STM2(&(xo[28]), T1f, ovs, &(xo[0]));
            T1g = VADD(T11, T12);
            STM2(&(xo[12]), T1g, ovs, &(xo[0]));
            T1h = VADD(TV, T10);
            STM2(&(xo[4]), T1h, ovs, &(xo[0]));
            T1i = VSUB(T11, T12);
            STM2(&(xo[20]), T1i, ovs, &(xo[0]));
          }
          {
            V Tr, TB, TA, TC;
            {
              V Tf, Tq, Tw, Tz;
              Tf = VSUB(T7, Te);
              Tq = VSUB(Tm, Tp);
              Tr = VBYI(VSUB(Tf, Tq));
              TB = VBYI(VADD(Tq, Tf));
              Tw = VADD(Tu, Tv);
              Tz = VADD(Tx, Ty);
              TA = VSUB(Tw, Tz);
              TC = VADD(Tw, Tz);
            }
            {
              V T1j, T1k, T1l, T1m;
              T1j = VADD(Tr, TA);
              STM2(&(xo[14]), T1j, ovs, &(xo[2]));
              STN2(&(xo[12]), T1g, T1j, ovs);
              T1k = VSUB(TC, TB);
              STM2(&(xo[30]), T1k, ovs, &(xo[2]));
              STN2(&(xo[28]), T1f, T1k, ovs);
              T1l = VSUB(TA, Tr);
              STM2(&(xo[18]), T1l, ovs, &(xo[2]));
              STN2(&(xo[16]), T1b, T1l, ovs);
              T1m = VADD(TB, TC);
              STM2(&(xo[2]), T1m, ovs, &(xo[2]));
              STN2(&(xo[0]), T1c, T1m, ovs);
            }
          }
          {
            V TF, TJ, TI, TK;
            {
              V TD, TE, TG, TH;
              TD = VSUB(Tu, Tv);
              TE = VADD(Te, T7);
              TF = VADD(TD, TE);
              TJ = VSUB(TD, TE);
              TG = VADD(Tp, Tm);
              TH = VSUB(Ty, Tx);
              TI = VBYI(VADD(TG, TH));
              TK = VBYI(VSUB(TH, TG));
            }
            {
              V T1n, T1o, T1p, T1q;
              T1n = VSUB(TF, TI);
              STM2(&(xo[26]), T1n, ovs, &(xo[2]));
              STN2(&(xo[24]), T1d, T1n, ovs);
              T1o = VADD(TJ, TK);
              STM2(&(xo[10]), T1o, ovs, &(xo[2]));
              STN2(&(xo[8]), T1e, T1o, ovs);
              T1p = VADD(TF, TI);
              STM2(&(xo[6]), T1p, ovs, &(xo[2]));
              STN2(&(xo[4]), T1h, T1p, ovs);
              T1q = VSUB(TJ, TK);
              STM2(&(xo[22]), T1q, ovs, &(xo[2]));
              STN2(&(xo[20]), T1i, T1q, ovs);
            }
          }
        }
      }
    }
  }
  VLEAVE();
}

static const kdft_desc desc = {
    16, XSIMD_STRING("n2fv_16"), {68, 8, 4, 0}, &GENUS, 0, 2, 0, 0};

void XSIMD(codelet_n2fv_16)(planner *p) { X(kdft_register)(p, n2fv_16, &desc); }

#endif
