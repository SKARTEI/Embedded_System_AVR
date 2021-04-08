// CodeVisionAVR V3.06+ C Compiler
// (C) 1998-2013 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATtiny25

#ifndef _TINY25_INCLUDED_
#define _TINY25_INCLUDED_

#pragma used+
sfrb ADCSRB=0x03;
sfrb ADCL=0x04;
sfrb ADCH=0x05;
sfrw ADCW=0x04; // 16 bit access
sfrb ADCSRA=0x06;
sfrb ADMUX=0x07;
sfrb ACSR=0x08;
sfrb USICR=0x0d;
sfrb USISR=0x0e;
sfrb USIDR=0x0f;
sfrb USIBR=0x10;
sfrb GPIOR0=0x11;
sfrb GPIOR1=0x12;
sfrb GPIOR2=0x13;
sfrb DIDR0=0x14;
sfrb PCMSK=0x15;
sfrb PINB=0x16;
sfrb DDRB=0x17;
sfrb PORTB=0x18;
sfrb EECR=0x1c;
sfrb EEDR=0x1d;
sfrb EEARL=0x1e;
sfrb PRR=0x20;
sfrb WDTCR=0x21;
sfrb DWDR=0x22;
sfrb DTPS1=0x23; // 19082013_1
sfrb DT1B=0x24;  // 19082013_1
sfrb DT1A=0x25;  // 19082013_1
sfrb CLKPR=0x26;
sfrb PLLCSR=0x27;
sfrb OCR0B=0x28;
sfrb OCR0A=0x29;
sfrb TCCR0A=0x2a;
sfrb OCR1B=0x2b;
sfrb GTCCR=0x2c;
sfrb OCR1C=0x2d;
sfrb OCR1A=0x2e;
sfrb TCNT1=0x2f;
sfrb TCCR1=0x30;
sfrb OSCCAL=0x31;
sfrb TCNT0=0x32;
sfrb TCCR0B=0x33;
sfrb MCUSR=0x34;
sfrb MCUCR=0x35;
sfrb SPMCSR=0x37;
sfrb TIFR=0x38;
sfrb TIMSK=0x39;
sfrb GIFR=0x3a;
sfrb GIMSK=0x3b;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

// Interrupt vectors definitions

#define EXT_INT0 2
#define PC_INT0 3
#define TIM1_COMPA 4
#define TIM1_OVF 5
#define TIM0_OVF 6
#define EE_RDY 7
#define ANA_COMP 8
#define ADC_INT 9
#define TIM1_COMPB 10
#define TIM0_COMPA 11
#define TIM0_COMPB 12
#define WDT 13
#define USI_START 14
#define USI_OVF 15

#define USI_STRT USI_START

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __STANDBY_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x20
	.EQU __sm_mask=0x18
	.EQU __sm_adc_noise_red=0x08
	.EQU __sm_powerdown=0x10
	.EQU __sm_standby=0x18
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <tiny85_bits.h>
#endif

#endif

