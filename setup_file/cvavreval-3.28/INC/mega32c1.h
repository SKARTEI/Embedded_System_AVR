// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATmega32C1

#ifndef _MEGA32C1_INCLUDED_
#define _MEGA32C1_INCLUDED_

#pragma used+
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
sfrb TIFR0=0x15;
sfrb TIFR1=0x16;
sfrb GPIOR1=0x19;
sfrb GPIOR2=0x1a;
sfrb PCIFR=0x1b;
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
sfrb TCCR0B=0x25;
sfrb TCNT0=0x26;
sfrb OCR0A=0x27;
sfrb OCR0B=0x28;
sfrb PLLCSR=0x29;
sfrb SPCR=0x2c;
sfrb SPSR=0x2d;
sfrb SPDR=0x2e;
sfrb ACSR=0x30;
sfrb MONDR=0x31;
sfrb MSMCR=0x32;
sfrb SMCR=0x33;
sfrb MCUSR=0x34;
sfrb MCUCR=0x35;
sfrb SPMCSR=0x37;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

#define WDTCSR (*(unsigned char *) 0x60)
#define CLKPR (*(unsigned char *) 0x61)
#define PRR (*(unsigned char *) 0x64)
#define OSCCAL (*(unsigned char *) 0x66)
#define PCICR (*(unsigned char *) 0x68)
#define EICRA (*(unsigned char *) 0x69)
#define PCMSK0 (*(unsigned char *) 0x6a)
#define PCMSK1 (*(unsigned char *) 0x6b)
#define PCMSK2 (*(unsigned char *) 0x6c)
#define PCMSK3 (*(unsigned char *) 0x6d)
#define TIMSK0 (*(unsigned char *) 0x6e)
#define TIMSK1 (*(unsigned char *) 0x6f)
#define AMP0CSR (*(unsigned char *) 0x75)
#define AMP1CSR (*(unsigned char *) 0x76)
#define AMP2CSR (*(unsigned char *) 0x77)
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
#define DACON (*(unsigned char *) 0x90)
#define DACL (*(unsigned char *) 0x91)
#define DACH (*(unsigned char *) 0x92)
#define AC0CON (*(unsigned char *) 0x94)
#define AC1CON (*(unsigned char *) 0x95)
#define AC2CON (*(unsigned char *) 0x96)
#define AC3CON (*(unsigned char *) 0x97)
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
#define ANA_COMP_0 2
#define ANA_COMP_1 3
#define ANA_COMP_2 4
#define ANA_COMP_3 5
#define EXT_INT0 8
#define EXT_INT1 9
#define EXT_INT2 10
#define EXT_INT3 11
#define TIM1_CAPT 12
#define TIM1_COMPA 13
#define TIM1_COMPB 14
#define TIM1_OVF 15
#define TIM0_COMPA 16
#define TIM0_COMPB 17
#define TIM0_OVF 18
#define CAN_INT 19
#define CAN_TOVF 20
#define LIN_TC 21
#define LIN_ERR 22
#define PC_INT0 23
#define PC_INT1 24
#define PC_INT2 25
#define PC_INT3 26
#define SPI_STC 27
#define ADC_INT 28
#define WDT 29
#define EE_RDY 30
#define SPM_READY 31

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
	.EQU __sm_standby=0x0C
	.SET power_ctrl_reg=smcr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <mega64c1_bits.h>
#endif

#endif

