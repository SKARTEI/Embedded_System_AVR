// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the AT90CAN64

#ifndef _90CAN64_INCLUDED_
#define _90CAN64_INCLUDED_

#pragma used+
sfrb PINA=0;
sfrb DDRA=1;
sfrb PORTA=2;
sfrb PINB=3;
sfrb DDRB=4;
sfrb PORTB=5;
sfrb PINC=6;
sfrb DDRC=7;
sfrb PORTC=8;
sfrb PIND=9;
sfrb DDRD=0xa;
sfrb PORTD=0xb;
sfrb PINE=0xc;
sfrb DDRE=0xd;
sfrb PORTE=0xe;
sfrb PINF=0xf;
sfrb DDRF=0x10;
sfrb PORTF=0x11;
sfrb PING=0x12;
sfrb DDRG=0x13;
sfrb PORTG=0x14;
sfrb TIFR0=0x15;
sfrb TIFR1=0x16;
sfrb TIFR2=0x17;
sfrb TIFR3=0x18;
sfrb EIFR=0x1c;
sfrb EIMSK=0x1d;
sfrb GPIOR0=0x1e;
sfrb EECR=0x1f;
sfrb EEDR=0x20;
sfrb EEARL=0x21;
sfrb EEARH=0x22;
sfrw EEAR=0x21;   // 16 bit access
sfrb GTCCR=0x23;
sfrb TCCR0A=0x24;
sfrb TCNT0=0x26;
sfrb OCR0A=0x27;
sfrb GPIOR1=0x2a;
sfrb GPIOR2=0x2b;
sfrb SPCR=0x2c;
sfrb SPSR=0x2d;
sfrb SPDR=0x2e;
sfrb ACSR=0x30;
sfrb OCDR=0x31;
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
#define OSCCAL (*(unsigned char *) 0x66)
#define EICRA (*(unsigned char *) 0x69)
#define EICRB (*(unsigned char *) 0x6a)
#define TIMSK0 (*(unsigned char *) 0x6e)
#define TIMSK1 (*(unsigned char *) 0x6f)
#define TIMSK2 (*(unsigned char *) 0x70)
#define TIMSK3 (*(unsigned char *) 0x71)
#define XMCRA (*(unsigned char *) 0x74)
#define XMCRB (*(unsigned char *) 0x75)
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
#define OCR1CL (*(unsigned char *) 0x8c)
#define OCR1CH (*(unsigned char *) 0x8d)
#define TCCR3A (*(unsigned char *) 0x90)
#define TCCR3B (*(unsigned char *) 0x91)
#define TCCR3C (*(unsigned char *) 0x92)
#define TCNT3L (*(unsigned char *) 0x94)
#define TCNT3H (*(unsigned char *) 0x95)
#define ICR3L (*(unsigned char *) 0x96)
#define ICR3H (*(unsigned char *) 0x97)
#define OCR3AL (*(unsigned char *) 0x98)
#define OCR3AH (*(unsigned char *) 0x99)
#define OCR3BL (*(unsigned char *) 0x9a)
#define OCR3BH (*(unsigned char *) 0x9b)
#define OCR3CL (*(unsigned char *) 0x9c)
#define OCR3CH (*(unsigned char *) 0x9d)
#define TCCR2A (*(unsigned char *) 0xb0)
#define TCNT2 (*(unsigned char *) 0xb2)
#define OCR2A (*(unsigned char *) 0xb3)
#define ASSR (*(unsigned char *) 0xb6)
#define TWBR (*(unsigned char *) 0xb8)
#define TWSR (*(unsigned char *) 0xb9)
#define TWAR (*(unsigned char *) 0xba)
#define TWDR (*(unsigned char *) 0xbb)
#define TWCR (*(unsigned char *) 0xbc)
#define UCSR0A (*(unsigned char *) 0xc0)
#define UCSR0B (*(unsigned char *) 0xc1)
#define UCSR0C (*(unsigned char *) 0xc2)
#define UBRR0L (*(unsigned char *) 0xc4)
#define UBRR0H (*(unsigned char *) 0xc5)
#define UDR0 (*(unsigned char *) 0xc6)
#define UCSR1A (*(unsigned char *) 0xc8)
#define UCSR1B (*(unsigned char *) 0xc9)
#define UCSR1C (*(unsigned char *) 0xca)
#define UBRR1L (*(unsigned char *) 0xcc)
#define UBRR1H (*(unsigned char *) 0xcd)
#define UDR1 (*(unsigned char *) 0xce)
#define CANGCON (*(unsigned char *) 0xd8)
#define CANGSTA (*(unsigned char *) 0xd9)
#define CANGIT (*(unsigned char *) 0xda)
#define CANGIE (*(unsigned char *) 0xdb)
#define CANEN2 (*(unsigned char *) 0xdc)
#define CANEN1 (*(unsigned char *) 0xdd)
#define CANIE2 (*(unsigned char *) 0xde)
#define CANIE1 (*(unsigned char *) 0xdf)
#define CANSIT2 (*(unsigned char *) 0xe0)
#define CANSIT1 (*(unsigned char *) 0xe1)
#define CANBT1 (*(unsigned char *) 0xe2)
#define CANBT2 (*(unsigned char *) 0xe3)
#define CANBT3 (*(unsigned char *) 0xe4)
#define CANTCON (*(unsigned char *) 0xe5)
#define CANTIML (*(unsigned char *) 0xe6)
#define CANTIMH (*(unsigned char *) 0xe7)
#define CANTTCL (*(unsigned char *) 0xe8)
#define CANTTCH (*(unsigned char *) 0xe9)
#define CANTEC (*(unsigned char *) 0xea)
#define CANREC (*(unsigned char *) 0xeb)
#define CANHPMOB (*(unsigned char *) 0xec)
#define CANPAGE (*(unsigned char *) 0xed)
#define CANSTMOB (*(unsigned char *) 0xee)
#define CANCDMOB (*(unsigned char *) 0xef)
#define CANIDT4 (*(unsigned char *) 0xf0)
#define CANIDT3 (*(unsigned char *) 0xf1)
#define CANIDT2 (*(unsigned char *) 0xf2)
#define CANIDT1 (*(unsigned char *) 0xf3)
#define CANIDM4 (*(unsigned char *) 0xf4)
#define CANIDM3 (*(unsigned char *) 0xf5)
#define CANIDM2 (*(unsigned char *) 0xf6)
#define CANIDM1 (*(unsigned char *) 0xf7)
#define CANSTML (*(unsigned char *) 0xf8)
#define CANSTMH (*(unsigned char *) 0xf9)
#define CANMSG (*(unsigned char *) 0xfa)

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
#define TIM1_COMPC 15
#define TIM1_OVF 16
#define TIM0_COMP 17
#define TIM0_OVF 18
#define CAN_IT 19
#define CTIM_OVF 20
#define SPI_STC 21
#define USART0_RXC 22
#define USART0_DRE 23
#define USART0_TXC 24
#define ANA_COMP 25
#define ADC_INT 26
#define EE_RDY 27
#define TIM3_CAPT 28
#define TIM3_COMPA 29
#define TIM3_COMPB 30
#define TIM3_COMPC 31
#define TIM3_OVF 32
#define USART1_RXC 33
#define USART1_DRE 34
#define USART1_TXC 35
#define TWI 36
#define SPM_RDY 37

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __POWERSAVE_SUPPORTED__
#define __STANDBY_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x01
	.EQU __sm_mask=0x0E
	.EQU __sm_adc_noise_red=0x02
	.EQU __sm_powerdown=0x04
	.EQU __sm_powersave=0x06
	.EQU __sm_standby=0x0C
	.SET power_ctrl_reg=smcr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <90can128_bits.h>
#endif

#endif

