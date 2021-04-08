// CodeVisionAVR V2.61+ C Compiler
// (C) 1998-2012 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATtiny4

#ifndef _TINY4_INCLUDED_
#define _TINY4_INCLUDED_

#pragma used+
sfrb PINB=0x00;
sfrb DDRB=0x01;
sfrb PORTB=0x02;
sfrb PUEB=0x03;
sfrb PORTCR=0x0c;
sfrb PCMSK=0x10;
sfrb PCIFR=0x11;
sfrb PCICR=0x12;
sfrb EIMSK=0x13;
sfrb EIFR=0x14;
sfrb EICRA=0x15;
sfrb DIDR0=0x17;
sfrb ACSR=0x1f;
sfrb ICR0L=0x22;
sfrb ICR0H=0x23;
sfrw ICR0=0x22; // 16bit access
sfrb OCR0BL=0x24;
sfrb OCR0BH=0x25;
sfrw OCR0B=0x24; // 16bit access
sfrb OCR0AL=0x26;
sfrb OCR0AH=0x27;
sfrw OCR0A=0x26; // 16bit access
sfrb TCNT0L=0x28;
sfrb TCNT0H=0x29;
sfrw TCNT0=0x28; // 16bit access
sfrb TIFR0=0x2a;
sfrb TIMSK0=0x2b;
sfrb TCCR0C=0x2c;
sfrb TCCR0B=0x2d;
sfrb TCCR0A=0x2e;
sfrb GTCCR=0x2f;
sfrb WDTCSR=0x31;
sfrb NVMCSR=0x32;
sfrb NVMCMD=0x33;
sfrb VLMCSR=0x34;
sfrb PRR=0x35;
sfrb CLKPSR=0x36;
sfrb CLKMSR=0x37;
sfrb OSCCAL=0x39;
sfrb SMCR=0x3a;
sfrb RSTFLR=0x3b;
sfrb CCP=0x3c;
sfrb SPL=0x3d;
sfrb SREG=0x3f;
#pragma used-

// Interrupt vectors definitions

#define EXT_INT0 2
#define PC_INT0 3
#define TIM0_CAPT 4
#define TIM0_OVF 5
#define TIM0_COMPA 6
#define TIM0_COMPB 7
#define ANA_COMP 8
#define WDT 9
#define VLM 10

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __STANDBY_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x01
	.EQU __sm_mask=0x0E
	.EQU __sm_powerdown=0x04
  .EQU __sm_standby=0x08
	.SET power_ctrl_reg=smcr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <tiny9_bits.h>
#endif

#endif

