// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the AT90USB162

#ifndef _90USB162_INCLUDED_
#define _90USB162_INCLUDED_

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
sfrb TIFR0=0x15;
sfrb TIFR1=0x16;
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

#define WDTCSR (*(unsigned char *) 0x60)
#define CLKPR (*(unsigned char *) 0x61)
#define WDTCKD (*(unsigned char *) 0x62)
#define REGCR (*(unsigned char *) 0x63)
#define PRR0 (*(unsigned char *) 0x64)
#define PRR1 (*(unsigned char *) 0x65)
#define OSCCAL (*(unsigned char *) 0x66)
#define PCICR (*(unsigned char *) 0x68)
#define EICRA (*(unsigned char *) 0x69)
#define EICRB (*(unsigned char *) 0x6a)
#define PCMSK0 (*(unsigned char *) 0x6b)
#define PCMSK1 (*(unsigned char *) 0x6c)
#define TIMSK0 (*(unsigned char *) 0x6e)
#define TIMSK1 (*(unsigned char *) 0x6f)
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
#define UCSR1A (*(unsigned char *) 0xc8)
#define UCSR1B (*(unsigned char *) 0xc9)
#define UCSR1C (*(unsigned char *) 0xca)
#define UCSR1D (*(unsigned char *) 0xcb)
#define UBRR1L (*(unsigned char *) 0xcc)
#define UBRR1H (*(unsigned char *) 0xcd)
#define UDR1 (*(unsigned char *) 0xce)
#define CKSEL0 (*(unsigned char *) 0xd0)
#define CKSEL1 (*(unsigned char *) 0xd1)
#define CKSTA (*(unsigned char *) 0xd2)
#define USBCON (*(unsigned char *) 0xd8)
#define UDPADDL (*(unsigned char *) 0xdb)
#define UDPADDH (*(unsigned char *) 0xdc)
#define UDCON (*(unsigned char *) 0xe0)
#define UDINT (*(unsigned char *) 0xe1)
#define UDIEN (*(unsigned char *) 0xe2)
#define UDADDR (*(unsigned char *) 0xe3)
#define UDFNUML (*(unsigned char *) 0xe4)
#define UDFNUMH (*(unsigned char *) 0xe5)
#define UDMFN (*(unsigned char *) 0xe6)
#define UEINTX (*(unsigned char *) 0xe8)
#define UENUM (*(unsigned char *) 0xe9)
#define UERST (*(unsigned char *) 0xea)
#define UECONX (*(unsigned char *) 0xeb)
#define UECFG0X (*(unsigned char *) 0xec)
#define UECFG1X (*(unsigned char *) 0xed)
#define UESTA0X (*(unsigned char *) 0xee)
#define UESTA1X (*(unsigned char *) 0xef)
#define UEIENX (*(unsigned char *) 0xf0)
#define UEDATX (*(unsigned char *) 0xf1)
#define UEBCLX (*(unsigned char *) 0xf2)
#define UEINT (*(unsigned char *) 0xf4)
#define PS2CON (*(unsigned char *) 0xfa)
#define UPOE (*(unsigned char *) 0xfb)

// Interrupt vectors definitions

#define EXT_INT0 2
#define EXT_INT1 3
#define EXT_INT2 4
#define EXT_INT3 5
#define EXT_INT4 6
#define EXT_INT5 7
#define EXT_INT6 8
#define EXT_INT7 9
#define PC_INT0 10
#define PC_INT1 11
#define USB_GENERAL 12
#define USB_ENDPOINT 13
#define WDT 14
#define TIM1_CAPT 15
#define TIM1_COMPA 16
#define TIM1_COMPB 17
#define TIM1_COMPC 18
#define TIM1_OVF 19
#define TIM0_COMPA 20
#define TIM0_COMPB 21
#define TIM0_OVF 22
#define SPI_STC 23
#define USART1_RXC 24
#define USART1_DRE 25
#define USART1_TXC 26
#define ANA_COMP 27
#define EE_RDY 28
#define SPM_RDY 29

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __POWERSAVE_SUPPORTED__
#define __STANDBY_SUPPORTED__
#define __EXTENDED_STANDBY_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x01
	.EQU __sm_mask=0x0E
	.EQU __sm_powerdown=0x04
	.EQU __sm_powersave=0x06
	.EQU __sm_standby=0x0C
	.EQU __sm_ext_standby=0x0E
	.SET power_ctrl_reg=smcr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <90usb162_bits.h>
#endif

#endif

