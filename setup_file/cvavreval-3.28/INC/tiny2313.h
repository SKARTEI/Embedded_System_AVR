// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATtiny2313(V)

#ifndef _TINY2313_INCLUDED_
#define _TINY2313_INCLUDED_

#pragma used+
sfrb DIDR=1;
sfrb UBRRH=2;
sfrb UCSRC=3;
sfrb ACSR=8;
sfrb UBRRL=9;
sfrb UCSRB=0xa;
sfrb UCSRA=0xb;
sfrb UDR=0xc;
sfrb USICR=0xd;
sfrb USISR=0xe;
sfrb USIDR=0xf;
sfrb PIND=0x10;
sfrb DDRD=0x11;
sfrb PORTD=0x12;
sfrb GPIOR0=0x13;
sfrb GPIOR1=0x14;
sfrb GPIOR2=0x15;
sfrb PINB=0x16;
sfrb DDRB=0x17;
sfrb PORTB=0x18;
sfrb PINA=0x19;
sfrb DDRA=0x1a;
sfrb PORTA=0x1b;
sfrb EECR=0x1c;
sfrb EEDR=0x1d;
sfrb EEAR=0x1e;
sfrb PCMSK=0x20;
sfrb WDTCR=0x21;
sfrb TCCR1C=0x22;
sfrb GTCCR=0x23;
sfrb ICR1L=0x24;
sfrb ICR1H=0x25;
sfrw ICR1=0x24;   // 16 bit access
sfrb CLKPR=0x26;
sfrb OCR1BL=0x28;
sfrb OCR1BH=0x29;
sfrw OCR1B=0x28;   // 16 bit access
sfrb OCR1AL=0x2a;
sfrb OCR1AH=0x2b;
sfrw OCR1A=0x2a;   // 16 bit access
sfrb TCNT1L=0x2c;
sfrb TCNT1H=0x2d;
sfrw TCNT1=0x2c;  // 16 bit access
sfrb TCCR1B=0x2e;
sfrb TCCR1A=0x2f;
sfrb TCCR0A=0x30;
sfrb OSCCAL=0x31;
sfrb TCNT0=0x32;
sfrb TCCR0B=0x33;
sfrb MCUSR=0x34;
sfrb MCUCR=0x35;
sfrb OCR0A=0x36;
sfrb SPMCSR=0x37;
sfrb TIFR=0x38;
sfrb TIMSK=0x39;
sfrb EIFR=0x3a;
sfrb GIMSK=0x3b;
sfrb OCR0B=0x3c;
sfrb SPL=0x3d;
sfrb SREG=0x3f;
#pragma used-

// Interrupt vectors definitions

#define EXT_INT0 2
#define EXT_INT1 3
#define TIM1_CAPT 4
#define TIM1_COMPA 5
#define TIM1_OVF 6
#define TIM0_OVF 7
#define USART_RXC 8
#define USART_DRE 9
#define USART_TXC 10
#define ANA_COMP 11
#define PC_INT 12
#define TIM1_COMPB 13
#define TIM0_COMPA 14
#define TIM0_COMPB 15
#define USI_STRT 16
#define USI_OVF 17
#define EE_RDY 18
#define WDT 19

// for compatibility with the interrupt vector names from Atmel's datasheet
#define USART0_RXC USART_RXC
#define USART0_DRE USART_DRE
#define USART0_TXC USART_TXC
#define TIMER0_COMPA TIM0_COMPA
#define TIMER0_COMPB TIM0_COMPB
#define TIMER1_COMPB TIM1_COMPB
#define USI_START USI_STRT
#define USI_OVERFLOW USI_OVF
#define WDT_OVERFLOW WDT

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __STANDBY_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x20
	.EQU __sm_mask=0x50
	.EQU __sm_powerdown=0x10
	.EQU __sm_standby=0x40
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <tiny2313_bits.h>
#endif

#endif

