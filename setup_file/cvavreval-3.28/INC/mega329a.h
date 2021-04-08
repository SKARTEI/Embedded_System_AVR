// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2012 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATmega329A/PA

#ifndef _MEGA329A_INCLUDED_
#define _MEGA329A_INCLUDED_

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
sfrb EIFR=0x1c;
sfrb EIMSK=0x1d;
sfrb GPIOR0=0x1e;
sfrb EECR=0x1f;
sfrb EEDR=0x20;
sfrb EEARL=0x21;
sfrb EEARH=0x22;
sfrw EEAR=0X21;   // 16 bit access
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
#define PRR (*(unsigned char *) 0x64)
#define OSCCAL (*(unsigned char *) 0x66)
#define EICRA (*(unsigned char *) 0x69)
#define PCMSK0 (*(unsigned char *) 0x6b)
#define PCMSK1 (*(unsigned char *) 0x6c)
#define TIMSK0 (*(unsigned char *) 0x6e)
#define TIMSK1 (*(unsigned char *) 0x6f)
#define TIMSK2 (*(unsigned char *) 0x70)
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
#define TCCR2A (*(unsigned char *) 0xb0)
#define TCNT2 (*(unsigned char *) 0xb2)
#define OCR2A (*(unsigned char *) 0xb3)
#define ASSR (*(unsigned char *) 0xb6)
#define USICR (*(unsigned char *) 0xb8)
#define USISR (*(unsigned char *) 0xb9)
#define USIDR (*(unsigned char *) 0xba)
#define UCSR0A (*(unsigned char *) 0xc0)
#define UCSR0B (*(unsigned char *) 0xc1)
#define UCSR0C (*(unsigned char *) 0xc2)
#define UBRR0L (*(unsigned char *) 0xc4)
#define UBRR0H (*(unsigned char *) 0xc5)
#define UDR0 (*(unsigned char *) 0xc6)
#define LCDCRA (*(unsigned char *) 0xe4)
#define LCDCRB (*(unsigned char *) 0xe5)
#define LCDFRR (*(unsigned char *) 0xe6)
#define LCDCCR (*(unsigned char *) 0xe7)
#define LCDDR00 (*(unsigned char *) 0xec)
#define LCDDR01 (*(unsigned char *) 0xed)
#define LCDDR02 (*(unsigned char *) 0xee)
#define LCDDR03 (*(unsigned char *) 0xef)
#define LCDDR05 (*(unsigned char *) 0xf1)
#define LCDDR06 (*(unsigned char *) 0xf2)
#define LCDDR07 (*(unsigned char *) 0xf3)
#define LCDDR08 (*(unsigned char *) 0xf4)
#define LCDDR10 (*(unsigned char *) 0xf6)
#define LCDDR11 (*(unsigned char *) 0xf7)
#define LCDDR12 (*(unsigned char *) 0xf8)
#define LCDDR13 (*(unsigned char *) 0xf9)
#define LCDDR15 (*(unsigned char *) 0xfb)
#define LCDDR16 (*(unsigned char *) 0xfc)
#define LCDDR17 (*(unsigned char *) 0xfd)
#define LCDDR18 (*(unsigned char *) 0xfe)

// Interrupt vectors definitions

#define EXT_INT0 2
#define PC_INT0 3
#define PC_INT1 4
#define TIM2_COMP 5
#define TIM2_OVF 6
#define TIM1_CAPT 7
#define TIM1_COMPA 8
#define TIM1_COMPB 9
#define TIM1_OVF 10
#define TIM0_COMP 11
#define TIM0_OVF 12
#define SPI_STC 13
#define USART_RXC 14
#define USART_DRE 15
#define USART_TXC 16
#define USI_STRT 17
#define USI_OVFL 18
#define ANA_COMP 19
#define ADC_INT 20
#define EE_RDY 21
#define SPM_READY 22
#define LCD_SOF 23

#define USART0_RXC USART_RXC
#define USART0_DRE USART_DRE
#define USART0_TXC USART_TXC

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
#include <mega649a_bits.h>
#endif

#endif

