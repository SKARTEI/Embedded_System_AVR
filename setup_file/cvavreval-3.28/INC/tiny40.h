// CodeVisionAVR V2.61+ C Compiler
// (C) 1998-2012 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATtiny40

#ifndef _TINY40_INCLUDED_
#define _TINY40_INCLUDED_

#pragma used+
sfrb PINA=0x00;
sfrb DDRA=0x01;
sfrb PORTA=0x02;
sfrb PUEA=0x03;
sfrb PINB=0x04;
sfrb DDRB=0x05;
sfrb PORTB=0x06;
sfrb PUEB=0x07;
sfrb PORTCR=0x08;
sfrb PCMSK0=0x09;
sfrb PCMSK1=0x0a;
sfrb GIFR=0x0b;
sfrb GIMSK=0x0c;
sfrb DIDR0=0x0d;
sfrb ADCL=0x0e;
sfrb ADCH=0x0f;
sfrw ADCW=0x0e; // 16bit access
sfrb ADMUX=0x10;
sfrb ADCSRB=0x11;
sfrb ADCSRA=0x12;
sfrb ACSRB=0x13;
sfrb ACSRA=0x14;
sfrb OCR0B=0x15;
sfrb OCR0A=0x16;
sfrb TCNT0=0x17;
sfrb TCCR0B=0x18;
sfrb TCCR0A=0x19;
sfrb PCMSK2=0x1a;
sfrb PINC=0x1b;
sfrb DDRC=0x1c;
sfrb PORTC=0x1d;
sfrb PUEC=0x1e;
sfrb RAMDR=0x1f;
sfrb RAMAR=0x20;
sfrb OCR1B=0x21;
sfrb OCR1A=0x22;
sfrb TCNT1L=0x23;
sfrb TCCR1A=0x24;
sfrb TIFR=0x25;
sfrb TIMSK=0x26;
sfrb TCNT1H=0x27;
sfrb TWSD=0x28;
sfrb TWSAM=0x29;
sfrb TWSA=0x2a;
sfrb TWSSRA=0x2b;
sfrb TWSCRB=0x2c;
sfrb TWSCRA=0x2d;
sfrb SPDR=0x2e;
sfrb SPSR=0x2f;
sfrb SPCR=0x30;
sfrb WDTCSR=0x31;
sfrb NVMCSR=0x32;
sfrb NVMCMD=0x33;
sfrb QTCSR=0x34;
sfrb PRR=0x35;
sfrb CLKPSR=0x36;
sfrb CLKMSR=0x37;
sfrb OSCCAL=0x39;
sfrb MCUCR=0x3a;
sfrb RSTFLR=0x3b;
sfrb CCP=0x3c;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

// Interrupt vectors definitions
#define EXT_INT0 2
#define PC_INT0 3
#define PC_INT1 4
#define PC_INT2 5
#define WDT 6
#define TIM1_CAPT 7
#define TIM1_COMPA 8
#define TIM1_COMPB 9
#define TIM1_OVF 10
#define TIM0_COMPA 11
#define TIM0_COMPB 12
#define TIM0_OVF 13
#define ANA_COMP 14
#define ADC_INT 15
#define TWI_SLAVE 16
#define SPI_STC 17
#define QTRIP 18

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __STANDBY_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x01
	.EQU __sm_mask=0x0E
	.EQU __sm_adc_noise_red=0x02
	.EQU __sm_powerdown=0x04
  .EQU __sm_standby=0x08
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <tiny40_bits.h>
#endif

#endif

