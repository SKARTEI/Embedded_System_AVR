// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the AT86RF401

#ifndef _86RF401_INCLUDED_
#define _86RF401_INCLUDED_

#pragma used+
sfrb LOCKDET1=0x10;
sfrb TX_CNTL=0x12;
sfrb PWR_ATTEN=0x14;
sfrb VCOTUNE =0x16;
sfrb LOCKDET2=0x17;
sfrb DEECR=0x1c;
sfrb DEEDR=0x1d;
sfrb DEEAR=0x1e;
sfrb BTCNT=0x20;
sfrb BTCR=0x21;
sfrb WDTCR=0x22;
sfrb IO_ENAB=0x30;
sfrb IO_DATOUT=0x31;
sfrb IO_DATIN=0x32;
sfrb AVR_CONFIG=0x33;
sfrb B_DET=0x34;
sfrb BL_CONFIG=0x35;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

// Interrupt vectors definitions

#define RESET 1
#define BT_F2_ISR 2
#define BT_F0_ISR 3

#ifdef _IO_BITS_DEFINITIONS_
#include <86rf401_bits.h>
#endif

#endif

