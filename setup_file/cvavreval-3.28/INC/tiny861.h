// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2012 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATtiny861(V)

#ifndef _TINY861_INCLUDED_
#define _TINY861_INCLUDED_

#pragma used+
sfrb TCCR1E=0;
sfrb DIDR0=1;
sfrb DIDR1=2;
sfrb ADCSRB=3;
sfrb ADCL=4;
sfrb ADCH=5;
sfrw ADCW=4;      // 16 bit access
sfrb ADCSRA=6;
sfrb ADMUX=7;
sfrb ACSRA=8;
sfrb ACSRB=9;
sfrb GPIOR0=0xa;
sfrb GPIOR1=0xb;
sfrb GPIOR2=0xc;
sfrb USICR=0xd;
sfrb USISR=0xe;
sfrb USIDR=0xf;
sfrb USIBR=0x10;
sfrb USIPP=0x11;
sfrb OCR0B=0x12;
sfrb OCR0A=0x13;
sfrb TCNT0H=0x14;
sfrb TCCR0A=0x15;
sfrb PINB=0x16;
sfrb DDRB=0x17;
sfrb PORTB=0x18;
sfrb PINA=0x19;
sfrb DDRA=0x1a;
sfrb PORTA=0x1b;
sfrb EECR=0x1c;
sfrb EEDR=0x1d;
sfrb EEARL=0x1e;
sfrb EEARH=0x1f;
sfrb DWDR=0x20;
sfrb WDTCR=0x21;
sfrb PCMSK1=0x22;
sfrb PCMSK0=0x23;
sfrb DT1=0x24;
sfrb TC1H=0x25;
sfrb TCCR1D=0x26;
sfrb TCCR1C=0x27;
sfrb CLKPR=0x28;
sfrb PLLCSR=0x29;
sfrb OCR1D=0x2a;
sfrb OCR1C=0x2b;
sfrb OCR1B=0x2c;
sfrb OCR1A=0x2d;
sfrb TCNT1=0x2e;
sfrb TCCR1B=0x2f;
sfrb TCCR1A=0x30;
sfrb OSCCAL=0x31;
sfrb TCNT0L=0x32;
sfrb TCCR0B=0x33;
sfrb MCUSR=0x34;
sfrb MCUCR=0x35;
sfrb PRR=0x36;
sfrb SPMCSR=0x37;
sfrb TIFR=0x38;
sfrb TIMSK=0x39;
sfrb GIFR=0x3a;
sfrb GIMSK=0x3b;
sfrb SP=0x3d;
sfrb SREG=0x3f;
#pragma used-

// Interrupt vectors definitions

#define EXT_INT0 2
#define PC_INT 3
#define TIM1_COMPA 4
#define TIM1_COMPB 5
#define TIM1_OVF 6
#define TIM0_OVF 7
#define USI_START 8
#define USI_STRT 8
#define USI_OVF 9
#define EE_RDY 10
#define ANA_COMP 11
#define ADC_INT 12
#define WDT 13
#define EXT_INT1 14
#define TIM0_COMPA 15
#define TIM0_COMPB 16
#define TIM0_CAPT 17
#define TIM1_COMPD 18
#define FAULT_PROTECTION 19

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __STANDBY_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x20
	.EQU __sm_adc_noise_red=0x08
	.EQU __sm_mask=0x18
	.EQU __sm_powerdown=0x10
	.EQU __sm_standby=0x18
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <tiny861_bits.h>
#endif

#endif

