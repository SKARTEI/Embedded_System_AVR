// CodeVisionAVR v2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the AT90PWM316

#ifndef _90PWM316_INCLUDED_
#define _90PWM316_INCLUDED_

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
sfrb GPIOR3=0x1b;
sfrb EIFR=0x1c;
sfrb EIMSK=0x1d;
sfrb GPIOR0=0x1e;
sfrb EECR=0x1f;
sfrb EEDR=0x20;
sfrb EEARL=0x21;
sfrb EEARH=0x22;
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
sfrb MONCR=0x32;
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
#define EICRA (*(unsigned char *) 0x69)
#define TIMSK0 (*(unsigned char *) 0x6e)
#define TIMSK1 (*(unsigned char *) 0x6f)
#define AMP0CSR (*(unsigned char *) 0x76)
#define AMP1CSR (*(unsigned char *) 0x77)
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
#define PIFR0 (*(unsigned char *) 0xa0)
#define PIM0 (*(unsigned char *) 0xa1)
#define PIFR1 (*(unsigned char *) 0xa2)
#define PIM1 (*(unsigned char *) 0xa3)
#define PIFR2 (*(unsigned char *) 0xa4)
#define PIM2 (*(unsigned char *) 0xa5)
#define DACON (*(unsigned char *) 0xaa)
#define DACL (*(unsigned char *) 0xab)
#define DACH (*(unsigned char *) 0xac)
#define AC0CON (*(unsigned char *) 0xad)
#define AC1CON (*(unsigned char *) 0xae)
#define AC2CON (*(unsigned char *) 0xaf)
#define UCSRA (*(unsigned char *) 0xc0)
#define UCSRB (*(unsigned char *) 0xc1)
#define UCSRC (*(unsigned char *) 0xc2)
#define UBRRL (*(unsigned char *) 0xc4)
#define UBRRH (*(unsigned char *) 0xc5)
#define UDR (*(unsigned char *) 0xc6)
#define EUCSRA (*(unsigned char *) 0xc8)
#define EUCSRB (*(unsigned char *) 0xc9)
#define EUCSRC (*(unsigned char *) 0xca)
#define MUBRRL (*(unsigned char *) 0xcc)
#define MUBRRH (*(unsigned char *) 0xcd)
#define EUDR (*(unsigned char *) 0xce)
#define PSOC0 (*(unsigned char *) 0xd0)
#define OCR0SAL (*(unsigned char *) 0xd2)
#define OCR0SAH (*(unsigned char *) 0xd3)
#define OCR0RAL (*(unsigned char *) 0xd4)
#define OCR0RAH (*(unsigned char *) 0xd5)
#define OCR0SBL (*(unsigned char *) 0xd6)
#define OCR0SBH (*(unsigned char *) 0xd7)
#define OCR0RBL (*(unsigned char *) 0xd8)
#define OCR0RBH (*(unsigned char *) 0xd9)
#define PCNF0 (*(unsigned char *) 0xda)
#define PCTL0 (*(unsigned char *) 0xdb)
#define PFRC0A (*(unsigned char *) 0xdc)
#define PFRC0B (*(unsigned char *) 0xdd)
#define PICR0L (*(unsigned char *) 0xde)
#define PICR0H (*(unsigned char *) 0xdf)
#define PSOC1 (*(unsigned char *) 0xe0)
#define OCR1SAL (*(unsigned char *) 0xe2)
#define OCR1SAH (*(unsigned char *) 0xe3)
#define OCR1RAL (*(unsigned char *) 0xe4)
#define OCR1RAH (*(unsigned char *) 0xe5)
#define OCR1SBL (*(unsigned char *) 0xe6)
#define OCR1SBH (*(unsigned char *) 0xe7)
#define OCR1RBL (*(unsigned char *) 0xe8)
#define OCR1RBH (*(unsigned char *) 0xe9)
#define PCNF1 (*(unsigned char *) 0xea)
#define PCTL1 (*(unsigned char *) 0xeb)
#define PFRC1A (*(unsigned char *) 0xec)
#define PFRC1B (*(unsigned char *) 0xed)
#define PICR1L (*(unsigned char *) 0xee)
#define PICR1H (*(unsigned char *) 0xef)
#define PSOC2 (*(unsigned char *) 0xf0)
#define POM2 (*(unsigned char *) 0xf1)
#define OCR2SAL (*(unsigned char *) 0xf2)
#define OCR2SAH (*(unsigned char *) 0xf3)
#define OCR2RAL (*(unsigned char *) 0xf4)
#define OCR2RAH (*(unsigned char *) 0xf5)
#define OCR2SBL (*(unsigned char *) 0xf6)
#define OCR2SBH (*(unsigned char *) 0xf7)
#define OCR2RBL (*(unsigned char *) 0xf8)
#define OCR2RBH (*(unsigned char *) 0xf9)
#define PCNF2 (*(unsigned char *) 0xfa)
#define PCTL2 (*(unsigned char *) 0xfb)
#define PFRC2A (*(unsigned char *) 0xfc)
#define PFRC2B (*(unsigned char *) 0xfd)
#define PICR2L (*(unsigned char *) 0xfe)
#define PICR2H (*(unsigned char *) 0xff)

// Interrupt vectors definitions

#define PSC2_CAPT 2
#define PSC2_EC 3
#define PSC1_CAPT 4
#define PSC1_EC 5
#define PSC0_CAPT 6
#define PSC0_EC 7
#define ANA_COMP0 8
#define ANA_COMP1 9
#define ANA_COMP2 10
#define EXT_INT0 11
#define TIM1_CAPT 12
#define TIM1_COMPA 13
#define TIM1_COMPB 14
#define TIM1_OVF 16
#define TIM0_COMPA 17
#define TIM0_OVF 18
#define ADC_INT 19
#define EXT_INT1 20
#define SPI_STC 21
#define USART_RXC 22
#define USART_UDRE 23
#define USART_TXC 24
#define EXT_INT2 25
#define WDT 26
#define EE_RDY 27
#define TIM0_COMPB 28
#define EXT_INT3 29
#define SPM_READY 32

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
#include <90pwm316_bits.h>
#endif

#endif

