// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATmega162

#ifndef _MEGA162_INCLUDED_
#define _MEGA162_INCLUDED_

#pragma used+
sfrb UBRR1L=0;
sfrb UCSR1B=1;
sfrb UCSR1A=2;
sfrb UDR1=3;
sfrb OSCCAL=4;
sfrb OCDR=4;
sfrb PINE=5;
sfrb DDRE=6;
sfrb PORTE=7;
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
sfrb UBRR0H=0x20;
sfrb UCSR0C=0x20;
sfrb WDTCR=0x21;
sfrb OCR2=0x22;
sfrb TCNT2=0x23;
sfrb ICR1L=0x24;
sfrb ICR1H=0x25;
sfrb ASSR=0x26;
sfrb TCCR2=0x27;
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
sfrb SFIOR=0x30;
sfrb OCR0=0x31;
sfrb TCNT0=0x32;
sfrb TCCR0=0x33;
sfrb MCUCSR=0x34;
sfrb MCUCR=0x35;
sfrb EMCUCR=0x36;
sfrb SPMCR=0x37;
sfrb TIFR=0x38;
sfrb TIMSK=0x39;
sfrb GIFR=0x3a;
sfrb GICR=0x3b;
sfrb UBRR1H=0x3c;
sfrb UCSR1C=0x3c;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

#define CLKPR  (*(unsigned char *) 0x61)
#define PCMSK0 (*(unsigned char *) 0x6b)
#define PCMSK1 (*(unsigned char *) 0x6c)
#define ETIFR  (*(unsigned char *) 0x7c)
#define ETIMSK (*(unsigned char *) 0x7d)
#define ICR3L  (*(unsigned char *) 0x80)
#define ICR3H  (*(unsigned char *) 0x81)
#define OCR3BL (*(unsigned char *) 0x84)
#define OCR3BH (*(unsigned char *) 0x85)
#define OCR3AL (*(unsigned char *) 0x86)
#define OCR3AH (*(unsigned char *) 0x87)
#define TCNT3L (*(unsigned char *) 0x88)
#define TCNT3H (*(unsigned char *) 0x89)
#define TCCR3B (*(unsigned char *) 0x8a)
#define TCCR3A (*(unsigned char *) 0x8b)

// Interrupt vectors definitions

#define EXT_INT0 2
#define EXT_INT1 3
#define EXT_INT2 4
#define PC_INT0 5
#define PC_INT1 6
#define TIM3_CAPT 7
#define TIM3_COMPA 8
#define TIM3_COMPB 9
#define TIM3_OVF 10

#define TIM2_COMP 11
#define TIM2_OVF 12
#define TIM1_CAPT 13
#define TIM1_COMPA 14
#define TIM1_COMPB 15
#define TIM1_OVF 16
#define TIM0_COMP 17
#define TIM0_OVF 18
#define SPI_STC 19
#define USART0_RXC 20
#define USART1_RXC 21
#define USART0_DRE 22
#define USART1_DRE 23
#define USART0_TXC 24
#define USART1_TXC 25
#define EE_RDY 26
#define ANA_COMP 27
#define SPM_RDY 28

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
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <mega162_bits.h>
#endif

#endif

