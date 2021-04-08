// CodeVisionAVR C Compiler
// (C) 1998-2001 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the AT43USB355

#ifndef _43USB355_INCLUDED_
#define _43USB355_INCLUDED_

#pragma used+
sfrb ADCL=2;
sfrb ADCH=3;
sfrw ADC=2;       // 16 bit access
sfrb PINF=4;
sfrb DDRF=5;
sfrb PORTF=6;
sfrb ADCSR=7;
sfrb ADMUX=8;
sfrb SPCR=0xd;
sfrb SPSR=0xe;
sfrb SPDR=0xf;
sfrb PIND=0x10;
sfrb DDRD=0x11;
sfrb PORTD=0x12;
sfrb PINB=0x16;
sfrb DDRB=0x17;
sfrb PORTB=0x18;
sfrb PINA=0x19;
sfrb DDRA=0x1a;
sfrb PORTA=0x1b;
sfrb WDTCR=0x21;
sfrw ICR1=0x24;   // 16 bit access
sfrb ICR1L=0x24;
sfrb ICR1H=0x25;
sfrw OCR1B=0x28;  // 16 bit access
sfrb OCR1BL=0x28;
sfrb OCR1BH=0x29;
sfrw OCR1A=0x2a;  // 16 bit access
sfrb OCR1AL=0x2a;
sfrb OCR1AH=0x2b;
sfrw TCNT1=0x2c;  // 16 bit access
sfrb TCNT1L=0x2c;
sfrb TCNT1H=0x2d;
sfrb TCCR1B=0x2e;
sfrb TCCR1A=0x2f;
sfrb TCNT0=0x32;
sfrb TCCR0=0x33;
sfrb MCUCR=0x35;
sfrb TIFR=0x38;
sfrb TIMSK=0x39;
sfrb GIFR=0x3a;
sfrb GIMSK=0x3b;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

// Interrupt vectors definitions

#define INT0 2
#define INT1 3
#define TIM1_CAPT 4
#define TIM1_COMPA 5
#define TIM1_COMPB 6
#define TIM1_OVF 7
#define TIM0_OVF 8
#define SPI_STC 9
#define ADC_INT	12
#define USB_HW 13

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

#endif

