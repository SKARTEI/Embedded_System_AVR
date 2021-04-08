// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATmega128

#ifndef _MEGA128_INCLUDED_
#define _MEGA128_INCLUDED_

#pragma used+
sfrb PINF=0;
sfrb PINE=1;
sfrb DDRE=2;
sfrb PORTE=3;
sfrb ADCL=4;
sfrb ADCH=5;
sfrw ADCW=4;      // 16 bit access
sfrb ADCSRA=6;
sfrb ADMUX=7;
sfrb ACSR=8;
sfrb UBRR0L=9;
sfrb UCSR0B=0xa;
sfrb UCSR0A=0xb;
sfrb UDR0=0xc;
sfrb SPCR=0xd;
sfrb SPSR=0xe;
sfrb SPDR=0xf;
sfrb PIND=0x10;
sfrb DDRD=0x11;
sfrb PORTD=0x12;
sfrb PINC=0x13;
sfrb DDRC=0x14;
sfrb PORTC=0x15;
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
sfrw EEAR=0x1e;   // 16 bit access
sfrb SFIOR=0x20;
sfrb WDTCR=0x21;
sfrb OCDR=0x22;
sfrb OCR2=0x23;
sfrb TCNT2=0x24;
sfrb TCCR2=0x25;
sfrb ICR1L=0x26;
sfrb ICR1H=0x27;
sfrw ICR1=0x26;   // 16 bit access
sfrb OCR1BL=0x28;
sfrb OCR1BH=0x29;
sfrw OCR1B=0x28;  // 16 bit access
sfrb OCR1AL=0x2a;
sfrb OCR1AH=0x2b;
sfrw OCR1A=0x2a;  // 16 bit access
sfrb TCNT1L=0x2c;
sfrb TCNT1H=0x2d;
sfrw TCNT1=0x2c;  // 16 bit access
sfrb TCCR1B=0x2e;
sfrb TCCR1A=0x2f;
sfrb ASSR=0x30;
sfrb OCR0=0x31;
sfrb TCNT0=0x32;
sfrb TCCR0=0x33;
sfrb MCUCSR=0x34;
sfrb MCUCR=0x35;
sfrb TIFR=0x36;
sfrb TIMSK=0x37;
sfrb EIFR=0x38;
sfrb EIMSK=0x39;
sfrb EICRB=0x3a;
sfrb RAMPZ=0x3b;
sfrb XDIV=0x3c;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

#define DDRF (*(unsigned char *) 0x61)
#define PORTF (*(unsigned char *) 0x62)
#define PING (*(unsigned char *) 0x63)
#define DDRG (*(unsigned char *) 0x64)
#define PORTG (*(unsigned char *) 0x65)
#define SPMCSR (*(unsigned char *) 0x68)
#define EICRA (*(unsigned char *) 0x6a)
#define XMCRB (*(unsigned char *) 0x6c)
#define XMCRA (*(unsigned char *) 0x6d)
#define OSCCAL (*(unsigned char *) 0x6f)
#define TWBR (*(unsigned char *) 0x70)
#define TWSR (*(unsigned char *) 0x71)
#define TWAR (*(unsigned char *) 0x72)
#define TWDR (*(unsigned char *) 0x73)
#define TWCR (*(unsigned char *) 0x74)
#define OCR1CL (*(unsigned char *) 0x78)
#define OCR1CH (*(unsigned char *) 0x79)
#define TCCR1C (*(unsigned char *) 0x7a)
#define ETIFR (*(unsigned char *) 0x7c)
#define ETIMSK (*(unsigned char *) 0x7d)
#define ICR3L (*(unsigned char *) 0x80)
#define ICR3H (*(unsigned char *) 0x81)
#define OCR3CL (*(unsigned char *) 0x82)
#define OCR3CH (*(unsigned char *) 0x83)
#define OCR3BL (*(unsigned char *) 0x84)
#define OCR3BH (*(unsigned char *) 0x85)
#define OCR3AL (*(unsigned char *) 0x86)
#define OCR3AH (*(unsigned char *) 0x87)
#define TCNT3L (*(unsigned char *) 0x88)
#define TCNT3H (*(unsigned char *) 0x89)
#define TCCR3B (*(unsigned char *) 0x8a)
#define TCCR3A (*(unsigned char *) 0x8b)
#define TCCR3C (*(unsigned char *) 0x8c)
#define UBRR0H (*(unsigned char *) 0x90)
#define UCSR0C (*(unsigned char *) 0x95)
#define UBRR1H (*(unsigned char *) 0x98)
#define UBRR1L (*(unsigned char *) 0x99)
#define UCSR1B (*(unsigned char *) 0x9a)
#define UCSR1A (*(unsigned char *) 0x9b)
#define UDR1 (*(unsigned char *) 0x9c)
#define UCSR1C (*(unsigned char *) 0x9d)

// Interrupt vectors definitions

#define EXT_INT0 2
#define EXT_INT1 3
#define EXT_INT2 4
#define EXT_INT3 5
#define EXT_INT4 6
#define EXT_INT5 7
#define EXT_INT6 8
#define EXT_INT7 9
#define TIM2_COMP 10
#define TIM2_OVF 11
#define TIM1_CAPT 12
#define TIM1_COMPA 13
#define TIM1_COMPB 14
#define TIM1_OVF 15
#define TIM0_COMP 16
#define TIM0_OVF 17
#define SPI_STC 18
#define USART0_RXC 19
#define USART0_DRE 20
#define USART0_TXC 21
#define ADC_INT 22
#define EE_RDY 23
#define ANA_COMP 24
#define TIM1_COMPC 25
#define TIM3_CAPT 26
#define TIM3_COMPA 27
#define TIM3_COMPB 28
#define TIM3_COMPC 29
#define TIM3_OVF 30
#define USART1_RXC 31
#define USART1_DRE 32
#define USART1_TXC 33
#define TWI 34
#define SPM_RDY 35

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __POWERSAVE_SUPPORTED__
#define __STANDBY_SUPPORTED__
#define __EXTENDED_STANDBY_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x20
	.EQU __sm_mask=0x1C
	.EQU __sm_powerdown=0x10
	.EQU __sm_powersave=0x18
	.EQU __sm_standby=0x14
	.EQU __sm_ext_standby=0x1C
	.EQU __sm_adc_noise_red=0x08
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <mega128_bits.h>
#endif

#endif

