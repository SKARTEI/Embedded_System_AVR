// CodeVisionAVR C Compiler
// (C) 1998-2012 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATtiny88(V)

#ifndef _TINY88_INCLUDED_
#define _TINY88_INCLUDED_

#pragma used+
sfrb PINB=0x03;
sfrb DDRB=0x04;
sfrb PORTB=0x05;
sfrb PINC=0x06;
sfrb DDRC=0x07;
sfrb PORTC=0x08;
sfrb PIND=0x09;
sfrb DDRD=0x0a;
sfrb PORTD=0x0b;
sfrb PINA=0x0c;
sfrb DDRA=0x0d;
sfrb PORTA=0x0e;
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
sfrb GTCCR=0x23;
sfrb TCCR0A=0x25;
sfrb TCNT0=0x26;
sfrb OCR0A=0x27;
sfrb OCR0B=0x28;
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
sfrb SREG=0x3f;
#pragma used-

#define WDTCSR (*(unsigned char *) 0x60)
#define CLKPR (*(unsigned char *) 0x61)
#define PRR (*(unsigned char *) 0x64)
#define OSCCAL (*(unsigned char *) 0x66)
#define PCICR (*(unsigned char *) 0x68)
#define EICRA (*(unsigned char *) 0x69)
#define PCMSK3 (*(unsigned char *) 0x6a)
#define PCMSK0 (*(unsigned char *) 0x6b)
#define PCMSK1 (*(unsigned char *) 0x6c)
#define PCMSK2 (*(unsigned char *) 0x6d)
#define TIMSK0 (*(unsigned char *) 0x6e)
#define TIMSK1 (*(unsigned char *) 0x6f)
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
#define TCNT1L (*(unsigned char *) 0x84)
#define TCNT1H (*(unsigned char *) 0x85)
#define ICR1L (*(unsigned char *) 0x86)
#define ICR1H (*(unsigned char *) 0x87)
#define OCR1AL (*(unsigned char *) 0x88)
#define OCR1AH (*(unsigned char *) 0x89)
#define OCR1BL (*(unsigned char *) 0x8a)
#define OCR1BH (*(unsigned char *) 0x8b)
#define TWBR (*(unsigned char *) 0xb8)
#define TWSR (*(unsigned char *) 0xb9)
#define TWAR (*(unsigned char *) 0xba)
#define TWCR (*(unsigned char *) 0xbc)
#define TWDR (*(unsigned char *) 0xbb)
#define TWAMR (*(unsigned char *) 0xbd)

// Interrupt vectors definitions
#define EXT_INT0 2
#define EXT_INT1 3
#define PC_INT0 4
#define PC_INT1 5
#define PC_INT2 6
#define PC_INT3 7
#define WDT 8
#define TIM1_CAPT 9
#define TIM1_COMPA 10
#define TIM1_COMPB 11
#define TIM1_OVF 12
#define TIM0_COMPA 13
#define TIM0_COMPB 14
#define TIM0_OVF 15
#define SPI_STC 16
#define ADC_INT 17
#define EE_RDY 18
#define ANA_COMP 19
#define TWI 20

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
#include <tiny88_bits.h>
#endif

#endif

