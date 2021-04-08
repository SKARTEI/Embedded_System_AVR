// CodeVisionAVR V3.06+ C Compiler
// (C) 1998-2013 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATtiny87

#ifndef _TINY87_INCLUDED_
#define _TINY87_INCLUDED_

#pragma used+
sfrb PINA=0x00;
sfrb DDRA=0x01;
sfrb PORTA=0x02;
sfrb PINB=0x03;
sfrb DDRB=0x04;
sfrb PORTB=0x05;
sfrb PORTCR=0x12;
sfrb TIFR0=0x15;
sfrb TIFR1=0x16;
sfrb PCIFR=0x1b;
sfrb EIFR=0x1c;
sfrb EIMSK=0x1d;
sfrb GPIOR0=0x1e;
sfrb EECR=0x1f;
sfrb EEDR=0x20;
sfrb EEARL=0x21;
sfrb EEARH=0x22; // 16112009_1
sfrb GTCCR=0x23;
sfrb TCCR0A=0x25;
sfrb TCCR0B=0x26;
sfrb TCNT0=0x27;
sfrb OCR0A=0x28;
sfrb GPIOR1=0x2a;
sfrb GPIOR2=0x2b;
sfrb SPCR=0x2c;
sfrb SPSR=0x2d;
sfrb SPDR=0x2e;
sfrb ACSR=0x30;
sfrb DWDR=0x31;
sfrb SMCR=0x33;
sfrb MCUSR=0x34;
sfrb MCUCR=0x35;
sfrb SPMCSR=0x37;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

#define WDTCR (*(unsigned char *) 0x60)
#define CLKPR (*(unsigned char *) 0x61)
#define CLKCSR (*(unsigned char *) 0x62) // 25072013_1
#define CLKSELR (*(unsigned char *) 0x63) // 25072013_1
#define PRR (*(unsigned char *) 0x64)
#define OSCCAL (*(unsigned char *) 0x66)
#define PCICR (*(unsigned char *) 0x68)
#define EICRA (*(unsigned char *) 0x69)
#define PCMSK0 (*(unsigned char *) 0x6b)
#define PCMSK1 (*(unsigned char *) 0x6c)
#define TIMSK0 (*(unsigned char *) 0x6e)
#define TIMSK1 (*(unsigned char *) 0x6f)
#define AMISCR (*(unsigned char *) 0x77) // 07062011_1
#define ADCL (*(unsigned char *) 0x78)
#define ADCH (*(unsigned char *) 0x79)
#define ADCW (*(unsigned int *) 0x78) // 16 bit access
#define ADCSRA (*(unsigned char *) 0x7a)
#define ADCSRB (*(unsigned char *) 0x7b)
#define ADMUX (*(unsigned char *) 0x7c)
#define DIDR0 (*(unsigned char *) 0x7e)
#define DIDR1 (*(unsigned char *) 0x7f)
#define TCCR1A (*(unsigned char *) 0x80)
#define TCCR1B (*(unsigned char *) 0x81)
#define TCCR1C (*(unsigned char *) 0x82)
#define TCCR1D (*(unsigned char *) 0x83)
#define TCNT1L (*(unsigned char *) 0x84)
#define TCNT1H (*(unsigned char *) 0x85)
#define ICR1L (*(unsigned char *) 0x86)
#define ICR1H (*(unsigned char *) 0x87)
#define OCR1AL (*(unsigned char *) 0x88)
#define OCR1AH (*(unsigned char *) 0x89)
#define OCR1BL (*(unsigned char *) 0x8a)
#define OCR1BH (*(unsigned char *) 0x8b)
#define ASSR (*(unsigned char *) 0xb6)
#define USICR (*(unsigned char *) 0xb8)
#define USISR (*(unsigned char *) 0xb9)
#define USIDR (*(unsigned char *) 0xba)
#define USIBR (*(unsigned char *) 0xbb)
#define USIPP (*(unsigned char *) 0xbc)
#define LINCR (*(unsigned char *) 0xc8)
#define LINSIR (*(unsigned char *) 0xc9)
#define LINENIR (*(unsigned char *) 0xca)
#define LINERR (*(unsigned char *) 0xcb)
#define LINBTR (*(unsigned char *) 0xcc)
#define LINBRRL (*(unsigned char *) 0xcd)
#define LINBRRH (*(unsigned char *) 0xce)
#define LINDLR (*(unsigned char *) 0xcf)
#define LINIDR (*(unsigned char *) 0xd0)
#define LINSEL (*(unsigned char *) 0xd1)
#define LINDAT (*(unsigned char *) 0xd2)

// Interrupt vectors definitions
#define EXT_INT0 2
#define EXT_INT1 3
#define PC_INT0 4
#define PC_INT1 5
#define WDT 6
#define TIM1_CAPT 7
#define TIM1_COMPA 8
#define TIM1_COMPB 9
#define TIM1_OVF 10
#define TIM0_COMPA 11
#define TIM0_OVF 12
#define LIN_TC 13
#define LIN_ERR 14
#define SPI_STC 15
#define ADC_INT 16
#define EE_RDY 17
#define ANA_COMP 18
#define USI_START 19
#define USI_OVF 20

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x01
	.EQU __sm_mask=0x06
	.EQU __sm_adc_noise_red=0x02
	.EQU __sm_powerdown=0x04
	.SET power_ctrl_reg=smcr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <tiny167_bits.h>
#endif

#endif

