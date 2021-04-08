// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the AT90USB1287

#ifndef _90USB1287_INCLUDED_
#define _90USB1287_INCLUDED_

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
sfrb TIFR0=0x15;
sfrb TIFR1=0x16;
sfrb TIFR2=0x17;
sfrb TIFR3=0x18;
sfrb TIFR4=0x19;
sfrb TIFR5=0x1a;
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
sfrb OCDR=0x31;
sfrb SMCR=0x33;
sfrb MCUSR=0x34;
sfrb MCUCR=0x35;
sfrb SPMCSR=0x37;
sfrb RAMPZ=0x3b;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

#define WDTCSR (*(unsigned char *) 0x60)
#define CLKPR (*(unsigned char *) 0x61)
#define PRR0 (*(unsigned char *) 0x64)
#define PRR1 (*(unsigned char *) 0x65)
#define OSCCAL (*(unsigned char *) 0x66)
#define PCICR (*(unsigned char *) 0x68)
#define EICRA (*(unsigned char *) 0x69)
#define EICRB (*(unsigned char *) 0x6a)
#define PCMSK0 (*(unsigned char *) 0x6b)
#define TIMSK0 (*(unsigned char *) 0x6e)
#define TIMSK1 (*(unsigned char *) 0x6f)
#define TIMSK2 (*(unsigned char *) 0x70)
#define TIMSK3 (*(unsigned char *) 0x71)
#define TIMSK4 (*(unsigned char *) 0x72)
#define TIMSK5 (*(unsigned char *) 0x73)
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
#define UHCON (*(unsigned char *) 0x9e)
#define UHINT (*(unsigned char *) 0x9f)
#define UHIEN (*(unsigned char *) 0xa0)
#define UHADDR (*(unsigned char *) 0xa1)
#define UHFNUML (*(unsigned char *) 0xa2)
#define UHFNUMH (*(unsigned char *) 0xa3)
#define UHFLEN (*(unsigned char *) 0xa4)
#define UPINRQX (*(unsigned char *) 0xa5)
#define UPINTX (*(unsigned char *) 0xa6)
#define UPNUM (*(unsigned char *) 0xa7)
#define UPRST (*(unsigned char *) 0xa8)
#define UPCONX (*(unsigned char *) 0xa9)
#define UPCFG0X (*(unsigned char *) 0xaa)
#define UPCFG1X (*(unsigned char *) 0xab)
#define UPSTAX (*(unsigned char *) 0xac)
#define UPCFG2X (*(unsigned char *) 0xad)
#define UPIENX (*(unsigned char *) 0xae)
#define UPDATX (*(unsigned char *) 0xaf)
#define TCCR2A (*(unsigned char *) 0xb0)
#define TCCR2B (*(unsigned char *) 0xb1)
#define TCNT2 (*(unsigned char *) 0xb2)
#define OCR2A (*(unsigned char *) 0xb3)
#define OCR2B (*(unsigned char *) 0xb4)
#define ASSR (*(unsigned char *) 0xb6)
#define TWBR (*(unsigned char *) 0xb8)
#define TWSR (*(unsigned char *) 0xb9)
#define TWAR (*(unsigned char *) 0xba)
#define TWDR (*(unsigned char *) 0xbb)
#define TWCR (*(unsigned char *) 0xbc)
#define TWAMR (*(unsigned char *) 0xbd)
#define UCSR1A (*(unsigned char *) 0xc8)
#define UCSR1B (*(unsigned char *) 0xc9)
#define UCSR1C (*(unsigned char *) 0xca)
#define UBRR1L (*(unsigned char *) 0xcc)
#define UBRR1H (*(unsigned char *) 0xcd)
#define UDR1 (*(unsigned char *) 0xce)
#define UHWCON (*(unsigned char *) 0xd7)
#define USBCON (*(unsigned char *) 0xd8)
#define USBSTA (*(unsigned char *) 0xd9)
#define USBINT (*(unsigned char *) 0xda)
#define UDPADDL (*(unsigned char *) 0xdb)
#define UDPADDH (*(unsigned char *) 0xdc)
#define OTGCON (*(unsigned char *) 0xdd)
#define OTGIEN (*(unsigned char *) 0xde)
#define OTGINT (*(unsigned char *) 0xdf)
#define UDCON (*(unsigned char *) 0xe0)
#define UDINT (*(unsigned char *) 0xe1)
#define UDIEN (*(unsigned char *) 0xe2)
#define UDADDR (*(unsigned char *) 0xe3)
#define UDFNUML (*(unsigned char *) 0xe4)
#define UDFNUMH (*(unsigned char *) 0xe5)
#define UDMFN (*(unsigned char *) 0xe6)
#define UDTST (*(unsigned char *) 0xe7)
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
#define UEBCHX (*(unsigned char *) 0xf3)
#define UEINT (*(unsigned char *) 0xf4)
#define UPERRX (*(unsigned char *) 0xf5)
#define UPBCLX (*(unsigned char *) 0xf6)
#define UPBCHX (*(unsigned char *) 0xf7)
#define UPINT (*(unsigned char *) 0xf8)
#define OTGTCON (*(unsigned char *) 0xf9)

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
#define USB_GENERAL 11
#define USB_ENDPOINT_PIPE 12
#define WDT 13
#define TIM2_COMPA 14
#define TIM2_COMPB 15
#define TIM2_OVF 16
#define TIM1_CAPT 17
#define TIM1_COMPA 18
#define TIM1_COMPB 19
#define TIM1_COMPC 20
#define TIM1_OVF 21
#define TIM0_COMPA 22
#define TIM0_COMPB 23
#define TIM0_OVF 24
#define SPI_STC 25
#define USART1_RXC 26
#define USART1_DRE 27
#define USART1_TXC 28
#define ANA_COMP 29
#define ADC_INT 30
#define EE_RDY 31
#define TIM3_CAPT 32
#define TIM3_COMPA 33
#define TIM3_COMPB 34
#define TIM3_COMPC 35
#define TIM3_OVF 36
#define TWI 37
#define SPM_RDY 38

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
	.EQU __sm_adc_noise_red=0x02
	.SET power_ctrl_reg=smcr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <90usb128x_bits.h>
#endif

#endif

