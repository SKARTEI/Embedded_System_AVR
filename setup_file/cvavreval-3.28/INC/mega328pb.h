// CodeVisionAVR V3.26+ C Compiler
// (C) 1998-2016 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATmega328PB

#ifndef _MEGA328PB_INCLUDED_
#define _MEGA328PB_INCLUDED_

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
sfrb TIFR2=0x17;
sfrb TIFR3=0x18;
sfrb TIFR4=0x19;
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
sfrb GPIOR1=0x2a;
sfrb GPIOR2=0x2b;
sfrb SPCR0=0x2c;
sfrb SPSR0=0x2d;
sfrb SPDR0=0x2e;
// for compatibility with SPI library
sfrb SPCR=0x2c;
sfrb SPSR=0x2d;
sfrb SPDR=0x2e;

sfrb ACSRB=0x2f;
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
#define XFDCSR (*(unsigned char *) 0x62)
#define PRR0 (*(unsigned char *) 0x64)
#define OSCCAL (*(unsigned char *) 0x66)
#define PCICR (*(unsigned char *) 0x68)
#define EICRA (*(unsigned char *) 0x69)
#define PCMSK0 (*(unsigned char *) 0x6b)
#define PCMSK1 (*(unsigned char *) 0x6c)
#define PCMSK2 (*(unsigned char *) 0x6d)
#define TIMSK0 (*(unsigned char *) 0x6e)
#define TIMSK1 (*(unsigned char *) 0x6f)
#define TIMSK2 (*(unsigned char *) 0x70)
#define TIMSK3 (*(unsigned char *) 0x71)
#define TIMSK4 (*(unsigned char *) 0x72)
#define PCMSK3 (*(unsigned char *) 0x73)
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
#define TCCR4A (*(unsigned char *) 0xa0)
#define TCCR4B (*(unsigned char *) 0xa1)
#define TCCR4C (*(unsigned char *) 0xa2)
#define TCNT4L (*(unsigned char *) 0xa4)
#define TCNT4H (*(unsigned char *) 0xa5)
#define ICR4L (*(unsigned char *) 0xa6)
#define ICR4H (*(unsigned char *) 0xa7)
#define OCR4AL (*(unsigned char *) 0xa8)
#define OCR4AH (*(unsigned char *) 0xa9)
#define OCR4BL (*(unsigned char *) 0xaa)
#define OCR4BH (*(unsigned char *) 0xab)
#define SPCR1 (*(unsigned char *) 0xac)
#define SPSR1 (*(unsigned char *) 0xad)
#define SPDR1 (*(unsigned char *) 0xae)
#define TCCR2A (*(unsigned char *) 0xb0)
#define TCCR2B (*(unsigned char *) 0xb1)
#define TCNT2 (*(unsigned char *) 0xb2)
#define OCR2A (*(unsigned char *) 0xb3)
#define OCR2B (*(unsigned char *) 0xb4)
#define ASSR (*(unsigned char *) 0xb6)
#define TWBR0 (*(unsigned char *) 0xb8)
#define TWSR0 (*(unsigned char *) 0xb9)
#define TWAR0 (*(unsigned char *) 0xba)
#define TWDR0 (*(unsigned char *) 0xbb)
#define TWCR0 (*(unsigned char *) 0xbc)
#define TWAMR0 (*(unsigned char *) 0xbd)
// for compatibility with TWI library
#define TWBR (*(unsigned char *) 0xb8)
#define TWSR (*(unsigned char *) 0xb9)
#define TWAR (*(unsigned char *) 0xba)
#define TWDR (*(unsigned char *) 0xbb)
#define TWCR (*(unsigned char *) 0xbc)
#define TWAMR (*(unsigned char *) 0xbd)

#define UCSR0A (*(unsigned char *) 0xc0)
#define UCSR0B (*(unsigned char *) 0xc1)
#define UCSR0C (*(unsigned char *) 0xc2)
#define UCSR0D (*(unsigned char *) 0xc3)
#define UBRR0L (*(unsigned char *) 0xc4)
#define UBRR0H (*(unsigned char *) 0xc5)
#define UDR0 (*(unsigned char *) 0xc6)
#define UCSR1A (*(unsigned char *) 0xc8)
#define UCSR1B (*(unsigned char *) 0xc9)
#define UCSR1C (*(unsigned char *) 0xca)
#define UCSR1D (*(unsigned char *) 0xcb)
#define UBRR1L (*(unsigned char *) 0xcc)
#define UBRR1H (*(unsigned char *) 0xcd)
#define UDR1 (*(unsigned char *) 0xce)
#define TWBR1 (*(unsigned char *) 0xd8)
#define TWSR1 (*(unsigned char *) 0xd9)
#define TWAR1 (*(unsigned char *) 0xda)
#define TWDR1 (*(unsigned char *) 0xdb)
#define TWCR1 (*(unsigned char *) 0xdc)
#define TWAMR1 (*(unsigned char *) 0xdd)

// Interrupt vectors definitions

#define EXT_INT0 2
#define EXT_INT1 3
#define PC_INT0 4
#define PC_INT1 5
#define PC_INT2 6
#define WDT 7
#define TIM2_COMPA 8
#define TIM2_COMPB 9
#define TIM2_OVF 10
#define TIM1_CAPT 11
#define TIM1_COMPA 12
#define TIM1_COMPB 13
#define TIM1_OVF 14
#define TIM0_COMPA 15
#define TIM0_COMPB 16
#define TIM0_OVF 17
#define SPI0_STC 18
#define USART0_RXC 19
#define USART0_DRE 20
#define USART0_TXC 21
#define ADC_INT 22
#define EE_RDY 23
#define ANA_COMP 24
#define TWI 25
#define SPM_READY 26
#define USART0_START 27
#define PC_INT3 28
#define USART1_RXC 29
#define USART1_DRE 30
#define USART1_TXC 31
#define USART1_START 32
#define TIM3_CAPT 33
#define TIM3_COMPA 34
#define TIM3_COMPB 35
#define TIM3_OVF 36
#define CFD 37
#define PTC_EOC 38
#define PTC_WCOMP 39
#define SPI1_STC 40
#define TWI1 41
#define TIM4_CAPT 42
#define TIM4_COMPA 43
#define TIM4_COMPB 44
#define TIM4_OVF 45

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
	.EQU __sm_adc_noise_red=0x02
	.EQU __sm_powerdown=0x04
	.EQU __sm_powersave=0x06
	.EQU __sm_standby=0x0C
	.EQU __sm_ext_standby=0x0E
	.SET power_ctrl_reg=smcr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <mega328pb_bits.h>
#endif

#endif

