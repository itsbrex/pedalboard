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
/* Generated on Tue Sep 14 10:46:10 EDT 2021 */

#include "rdft/codelet-rdft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_r2cf.native -fma -compact -variables 4
 * -pipeline-latency 4 -n 15 -name r2cf_15 -include rdft/scalar/r2cf.h */

/*
 * This function contains 64 FP additions, 35 FP multiplications,
 * (or, 36 additions, 7 multiplications, 28 fused multiply/add),
 * 45 stack variables, 8 constants, and 30 memory accesses
 */
#include "rdft/scalar/r2cf.h"

static void r2cf_15(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr,
                    stride csi, INT v, INT ivs, INT ovs) {
  DK(KP910592997, +0.910592997310029334643087372129977886038870291);
  DK(KP951056516, +0.951056516295153572116439333379382143405698634);
  DK(KP823639103, +0.823639103546331925877420039278190003029660514);
  DK(KP559016994, +0.559016994374947424102293417182819058860154590);
  DK(KP250000000, +0.250000000000000000000000000000000000000000000);
  DK(KP618033988, +0.618033988749894848204586834365638117720309180);
  DK(KP866025403, +0.866025403784438646763723170752936183471402627);
  DK(KP500000000, +0.500000000000000000000000000000000000000000000);
  {
    INT i;
    for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs,
        Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(60, rs),
        MAKE_VOLATILE_STRIDE(60, csr), MAKE_VOLATILE_STRIDE(60, csi)) {
      E Ti, TR, TF, TM, TN, T7, Te, Tf, TV, TW, TX, Ts, Tv, TH, Tl;
      E To, TG, TS, TT, TU;
      {
        E TD, Tg, Th, TE;
        TD = R0[0];
        Tg = R0[WS(rs, 5)];
        Th = R1[WS(rs, 2)];
        TE = Th + Tg;
        Ti = Tg - Th;
        TR = TD + TE;
        TF = FNMS(KP500000000, TE, TD);
      }
      {
        E Tj, Tq, Tt, Tm, T3, Tk, Ta, Tr, Td, Tu, T6, Tn;
        Tj = R1[WS(rs, 1)];
        Tq = R0[WS(rs, 3)];
        Tt = R1[WS(rs, 4)];
        Tm = R0[WS(rs, 6)];
        {
          E T1, T2, T8, T9;
          T1 = R0[WS(rs, 4)];
          T2 = R1[WS(rs, 6)];
          T3 = T1 - T2;
          Tk = T1 + T2;
          T8 = R1[WS(rs, 5)];
          T9 = R1[0];
          Ta = T8 - T9;
          Tr = T8 + T9;
        }
        {
          E Tb, Tc, T4, T5;
          Tb = R0[WS(rs, 7)];
          Tc = R0[WS(rs, 2)];
          Td = Tb - Tc;
          Tu = Tb + Tc;
          T4 = R0[WS(rs, 1)];
          T5 = R1[WS(rs, 3)];
          T6 = T4 - T5;
          Tn = T4 + T5;
        }
        TM = T6 - T3;
        TN = Td - Ta;
        T7 = T3 + T6;
        Te = Ta + Td;
        Tf = T7 + Te;
        TV = Tq + Tr;
        TW = Tt + Tu;
        TX = TV + TW;
        Ts = FNMS(KP500000000, Tr, Tq);
        Tv = FNMS(KP500000000, Tu, Tt);
        TH = Ts + Tv;
        Tl = FNMS(KP500000000, Tk, Tj);
        To = FNMS(KP500000000, Tn, Tm);
        TG = Tl + To;
        TS = Tj + Tk;
        TT = Tm + Tn;
        TU = TS + TT;
      }
      Ci[WS(csi, 5)] = KP866025403 * (Tf - Ti);
      {
        E TK, TQ, TO, TI, TJ, TP, TL;
        TK = TG - TH;
        TQ = FNMS(KP618033988, TM, TN);
        TO = FMA(KP618033988, TN, TM);
        TI = TG + TH;
        TJ = FNMS(KP250000000, TI, TF);
        Cr[WS(csr, 5)] = TF + TI;
        TP = FNMS(KP559016994, TK, TJ);
        Cr[WS(csr, 2)] = FMA(KP823639103, TQ, TP);
        Cr[WS(csr, 7)] = FNMS(KP823639103, TQ, TP);
        TL = FMA(KP559016994, TK, TJ);
        Cr[WS(csr, 1)] = FMA(KP823639103, TO, TL);
        Cr[WS(csr, 4)] = FNMS(KP823639103, TO, TL);
      }
      {
        E T11, T12, T10, TY, TZ;
        T11 = TW - TV;
        T12 = TS - TT;
        Ci[WS(csi, 3)] = KP951056516 * (FMA(KP618033988, T12, T11));
        Ci[WS(csi, 6)] = -(KP951056516 * (FNMS(KP618033988, T11, T12)));
        T10 = TU - TX;
        TY = TU + TX;
        TZ = FNMS(KP250000000, TY, TR);
        Cr[WS(csr, 3)] = FNMS(KP559016994, T10, TZ);
        Cr[0] = TR + TY;
        Cr[WS(csr, 6)] = FMA(KP559016994, T10, TZ);
        {
          E Tx, TB, TA, TC;
          {
            E Tp, Tw, Ty, Tz;
            Tp = Tl - To;
            Tw = Ts - Tv;
            Tx = FMA(KP618033988, Tw, Tp);
            TB = FNMS(KP618033988, Tp, Tw);
            Ty = FMA(KP250000000, Tf, Ti);
            Tz = Te - T7;
            TA = FMA(KP559016994, Tz, Ty);
            TC = FNMS(KP559016994, Tz, Ty);
          }
          Ci[WS(csi, 1)] = -(KP951056516 * (FNMS(KP910592997, TA, Tx)));
          Ci[WS(csi, 7)] = KP951056516 * (FMA(KP910592997, TC, TB));
          Ci[WS(csi, 4)] = KP951056516 * (FMA(KP910592997, TA, Tx));
          Ci[WS(csi, 2)] = KP951056516 * (FNMS(KP910592997, TC, TB));
        }
      }
    }
  }
}

static const kr2c_desc desc = {15, "r2cf_15", {36, 7, 28, 0}, &GENUS};

void X(codelet_r2cf_15)(planner *p) { X(kr2c_register)(p, r2cf_15, &desc); }

#else

/* Generated by: ../../../genfft/gen_r2cf.native -compact -variables 4
 * -pipeline-latency 4 -n 15 -name r2cf_15 -include rdft/scalar/r2cf.h */

/*
 * This function contains 64 FP additions, 25 FP multiplications,
 * (or, 50 additions, 11 multiplications, 14 fused multiply/add),
 * 47 stack variables, 10 constants, and 30 memory accesses
 */
#include "rdft/scalar/r2cf.h"

static void r2cf_15(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr,
                    stride csi, INT v, INT ivs, INT ovs) {
  DK(KP484122918, +0.484122918275927110647408174972799951354115213);
  DK(KP216506350, +0.216506350946109661690930792688234045867850657);
  DK(KP951056516, +0.951056516295153572116439333379382143405698634);
  DK(KP587785252, +0.587785252292473129168705954639072768597652438);
  DK(KP250000000, +0.250000000000000000000000000000000000000000000);
  DK(KP559016994, +0.559016994374947424102293417182819058860154590);
  DK(KP509036960, +0.509036960455127183450980863393907648510733164);
  DK(KP823639103, +0.823639103546331925877420039278190003029660514);
  DK(KP866025403, +0.866025403784438646763723170752936183471402627);
  DK(KP500000000, +0.500000000000000000000000000000000000000000000);
  {
    INT i;
    for (i = v; i > 0; i = i - 1, R0 = R0 + ivs, R1 = R1 + ivs, Cr = Cr + ovs,
        Ci = Ci + ovs, MAKE_VOLATILE_STRIDE(60, rs),
        MAKE_VOLATILE_STRIDE(60, csr), MAKE_VOLATILE_STRIDE(60, csi)) {
      E Ti, TR, TL, TD, TE, T7, Te, Tf, TV, TW, TX, Tv, Ty, TH, To;
      E Tr, TG, TS, TT, TU;
      {
        E TJ, Tg, Th, TK;
        TJ = R0[0];
        Tg = R0[WS(rs, 5)];
        Th = R1[WS(rs, 2)];
        TK = Th + Tg;
        Ti = Tg - Th;
        TR = TJ + TK;
        TL = FNMS(KP500000000, TK, TJ);
      }
      {
        E Tm, Tt, Tw, Tp, T3, Tx, Ta, Tn, Td, Tq, T6, Tu;
        Tm = R1[WS(rs, 1)];
        Tt = R0[WS(rs, 3)];
        Tw = R1[WS(rs, 4)];
        Tp = R0[WS(rs, 6)];
        {
          E T1, T2, T8, T9;
          T1 = R0[WS(rs, 7)];
          T2 = R0[WS(rs, 2)];
          T3 = T1 - T2;
          Tx = T1 + T2;
          T8 = R1[WS(rs, 6)];
          T9 = R0[WS(rs, 4)];
          Ta = T8 - T9;
          Tn = T9 + T8;
        }
        {
          E Tb, Tc, T4, T5;
          Tb = R1[WS(rs, 3)];
          Tc = R0[WS(rs, 1)];
          Td = Tb - Tc;
          Tq = Tc + Tb;
          T4 = R1[0];
          T5 = R1[WS(rs, 5)];
          T6 = T4 - T5;
          Tu = T5 + T4;
        }
        TD = Ta - Td;
        TE = T6 + T3;
        T7 = T3 - T6;
        Te = Ta + Td;
        Tf = T7 - Te;
        TV = Tt + Tu;
        TW = Tw + Tx;
        TX = TV + TW;
        Tv = FNMS(KP500000000, Tu, Tt);
        Ty = FNMS(KP500000000, Tx, Tw);
        TH = Tv + Ty;
        To = FNMS(KP500000000, Tn, Tm);
        Tr = FNMS(KP500000000, Tq, Tp);
        TG = To + Tr;
        TS = Tm + Tn;
        TT = Tp + Tq;
        TU = TS + TT;
      }
      Ci[WS(csi, 5)] = KP866025403 * (Tf - Ti);
      {
        E TF, TP, TI, TM, TN, TQ, TO;
        TF = FMA(KP823639103, TD, KP509036960 * TE);
        TP = FNMS(KP509036960, TD, KP823639103 * TE);
        TI = KP559016994 * (TG - TH);
        TM = TG + TH;
        TN = FNMS(KP250000000, TM, TL);
        Cr[WS(csr, 5)] = TL + TM;
        TQ = TN - TI;
        Cr[WS(csr, 2)] = TP + TQ;
        Cr[WS(csr, 7)] = TQ - TP;
        TO = TI + TN;
        Cr[WS(csr, 1)] = TF + TO;
        Cr[WS(csr, 4)] = TO - TF;
      }
      {
        E T11, T12, T10, TY, TZ;
        T11 = TS - TT;
        T12 = TW - TV;
        Ci[WS(csi, 3)] = FMA(KP587785252, T11, KP951056516 * T12);
        Ci[WS(csi, 6)] = FNMS(KP951056516, T11, KP587785252 * T12);
        T10 = KP559016994 * (TU - TX);
        TY = TU + TX;
        TZ = FNMS(KP250000000, TY, TR);
        Cr[WS(csr, 3)] = TZ - T10;
        Cr[0] = TR + TY;
        Cr[WS(csr, 6)] = T10 + TZ;
        {
          E Tl, TB, TA, TC;
          {
            E Tj, Tk, Ts, Tz;
            Tj = FMA(KP866025403, Ti, KP216506350 * Tf);
            Tk = KP484122918 * (Te + T7);
            Tl = Tj + Tk;
            TB = Tk - Tj;
            Ts = To - Tr;
            Tz = Tv - Ty;
            TA = FMA(KP951056516, Ts, KP587785252 * Tz);
            TC = FNMS(KP587785252, Ts, KP951056516 * Tz);
          }
          Ci[WS(csi, 1)] = Tl - TA;
          Ci[WS(csi, 7)] = TC - TB;
          Ci[WS(csi, 4)] = Tl + TA;
          Ci[WS(csi, 2)] = TB + TC;
        }
      }
    }
  }
}

static const kr2c_desc desc = {15, "r2cf_15", {50, 11, 14, 0}, &GENUS};

void X(codelet_r2cf_15)(planner *p) { X(kr2c_register)(p, r2cf_15, &desc); }

#endif
