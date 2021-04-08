// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATmega1280

#ifndef _MEGA1280_INCLUDED_
#define _MEGA1280_INCLUDED_

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
sfrw EEAR=0X21;   // 16 bit access
sfrb GTCCR=0x23;
sfrb TCCR0A=0x24;
sfrb TCCR0B=0x25;
sfrb TCNT0=0x26;
sfrb OCR0A=0x27;
sfrb OCR0B=0x28;
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
sfrb EIND=0x3c;
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
#define PCMSK1 (*(unsigned char *) 0x6c)
#define PCMSK2 (*(unsigned char *) 0x6d)
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
#define DIDR2 (*(unsigned char *) 0x7d)
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
#define OCR4CL (*(unsigned char *) 0xac)
#define OCR4CH (*(unsigned char *) 0xad)
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
#define UCSR2A (*(unsigned char *) 0xd0)
#define UCSR2B (*(unsigned char *) 0xd1)
#define UCSR2C (*(unsigned char *) 0xd2)
#define UBRR2L (*(unsigned char *) 0xd4)
#define UBRR2H (*(unsigned char *) 0xd5)
#define UDR2 (*(unsigned char *) 0xd6)
#define PINH (*(unsigned char *) 0x100)
#define DDRH (*(unsigned char *) 0x101)
#define PORTH (*(unsigned char *) 0x102)
#define PINJ (*(unsigned char *) 0x103)
#define DDRJ (*(unsigned char *) 0x104)
#define PORTJ (*(unsigned char *) 0x105)
#define PINK (*(unsigned char *) 0x106)
#define DDRK (*(unsigned char *) 0x107)
#define PORTK (*(unsigned char *) 0x108)
#define PINL (*(unsigned char *) 0x109)
#define DDRL (*(unsigned char *) 0x10a)
#define PORTL (*(unsigned char *) 0x10b)
#define TCCR5A (*(unsigned char *) 0x120)
#define TCCR5B (*(unsigned char *) 0x121)
#define TCCR5C (*(unsigned char *) 0x122)
#define TCNT5L (*(unsigned char *) 0x124)
#define TCNT5H (*(unsigned char *) 0x125)
#define ICR5L (*(unsigned char *) 0x126)
#define ICR5H (*(unsigned char *) 0x127)
#define OCR5AL (*(unsigned char *) 0x128)
#define OCR5AH (*(unsigned char *) 0x129)
#define OCR5BL (*(unsigned char *) 0x12a)
#define OCR5BH (*(unsigned char *) 0x12b)
#define OCR5CL (*(unsigned char *) 0x12c)
#define OCR5CH (*(unsigned char *) 0x12d)
#define UCSR3A (*(unsigned char *) 0x130)
#define UCSR3B (*(unsigned char *) 0x131)
#define UCSR3C (*(unsigned char *) 0x132)
#define UBRR3L (*(unsigned char *) 0x134)
#define UBRR3H (*(unsigned char *) 0x135)
#define UDR3 (*(unsigned char *) 0x136)

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
#define PC_INT2 12
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
#define USART0_RXC 26
#define USART0_UDRE 27
#define USART0_TXC 28
#define ANA_COMP 29
#define ADC_INT 30
#define EE_RDY 31
#define TIM3_CAPT 32
#define TIM3_COMPA 33
#define TIM3_COMPB 34
#define TIM3_COMPC 35
#define TIM3_OVF 36
#define USART1_RXC 37
#define USART1_UDRE 38
#define USART1_TXC 39
#define TWI 40
#define SPM_READY 41
#define TIM4_CAPT 42
#define TIM4_COMPA 43
#define TIM4_COMPB 44
#define TIM4_COMPC 45
#define TIM4_OVF 46
#define TIM5_CAPT 47
#define TIM5_COMPA 48
#define TIM5_COMPB 49
#define TIM5_COMPC 50
#define TIM5_OVF 51
#define USART2_RXC 52
#define USART2_UDRE 53
#define USART2_TXC 54
#define USART3_RXC 55
#define USART3_UDRE 56
#define USART3_TXC 57

#define USART_RXC USART0_RXC
#define USART_DRE USART0_UDRE
#define USART_TXC USART0_TXC

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
#include <mega2560_bits.h>
#endif

#endif

