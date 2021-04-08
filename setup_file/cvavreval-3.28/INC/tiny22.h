// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATtiny22

#ifndef _TINY22_INCLUDED_
#define _TINY22_INCLUDED_

#pragma used+
sfrb PINB=0x16;
sfrb DDRB=0x17;
sfrb PORTB=0x18;
sfrb EECR=0x1c;
sfrb EEDR=0x1d;
sfrb EEAR=0x1e;
sfrb WDTCR=0x21;
sfrb TCNT0=0x32;
sfrb TCCR0=0x33;
sfrb MCUSR=0x34;
sfrb MCUCR=0x35;
sfrb TIFR=0x38;
sfrb TIMSK=0x39;
sfrb GIFR=0x3a;
sfrb GIMSK=0x3b;
sfrb SPL=0x3d;
sfrb SREG=0x3f;
#pragma used-

// Interrupt vectors definitions

#define EXT_INT0 2
#define TIM0_OVF 3

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x20
	.EQU __sm_mask=0x10
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <tiny22_bits.h>
#endif

#endif

