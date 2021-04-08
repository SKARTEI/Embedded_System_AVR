// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATmega8HVA

#ifndef _MEGA8HVA_INCLUDED_
#define _MEGA8HVA_INCLUDED_

#pragma used+
sfrb PINA=0;
sfrb DDRA=1;
sfrb PORTA=2;
sfrb PINB=3;
sfrb DDRB=4;
sfrb PORTB=5;
sfrb PINC=6;
sfrb PORTC=8;
sfrb TIFR0=0x15;
sfrb TIFR1=0x16;
sfrb OSICSR=0x17;
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
sfrb TCNT0L=0x26;
sfrb TCNT0H=0x27;
sfrw TCNT0=0x26;   // 16 bit access
sfrb OCR0A=0x28;
sfrb OCR0B=0x29;
sfrb GPIOR1=0x2a;
sfrb GPIOR2=0x2b;
sfrb SPCR=0x2c;
sfrb SPSR=0x2d;
sfrb SPDR=0x2e;
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
#define PRR0 (*(unsigned char *) 0x64)
#define FOSCCAL (*(unsigned char *) 0x66)
#define PCICR (*(unsigned char *) 0x68)
#define EICRA (*(unsigned char *) 0x69)
#define TIMSK0 (*(unsigned char *) 0x6e)
#define TIMSK1 (*(unsigned char *) 0x6f)
#define VADCL (*(unsigned char *) 0x78)
#define VADCH (*(unsigned char *) 0x79)
#define VADCSR (*(unsigned char *) 0x7a)
#define VADMUX (*(unsigned char *) 0x7c)
#define DIDR0 (*(unsigned char *) 0x7e)
#define TCCR1A (*(unsigned char *) 0x80)
#define TCCR1B (*(unsigned char *) 0x81)
#define TCNT1L (*(unsigned char *) 0x84)
#define TCNT1H (*(unsigned char *) 0x85)
#define OCR1A (*(unsigned char *) 0x88)
#define OCR1B (*(unsigned char *) 0x89)
#define ROCR (*(unsigned char *) 0xc8)
#define BGCCR (*(unsigned char *) 0xd0)
#define BGCRR (*(unsigned char *) 0xd1)
#define CADAC0 (*(unsigned char *) 0xe0)
#define CADAC1 (*(unsigned char *) 0xe1)
#define CADAC2 (*(unsigned char *) 0xe2)
#define CADAC3 (*(unsigned char *) 0xe3)
#define CADCSRA (*(unsigned char *) 0xe4)
#define CADCSRB (*(unsigned char *) 0xe5)
#define CADRC (*(unsigned char *) 0xe6)
#define CADICL (*(unsigned char *) 0xe8)
#define CADICH (*(unsigned char *) 0xe9)
#define FCSR (*(unsigned char *) 0xf0)
#define BPIMSK (*(unsigned char *) 0xf2)
#define BPIFR (*(unsigned char *) 0xf3)
#define BPSCD (*(unsigned char *) 0xf5)
#define BPDOCD (*(unsigned char *) 0xf6)
#define BPCOCD (*(unsigned char *) 0xf7)
#define BPDHCD (*(unsigned char *) 0xf8)
#define BPCHCD (*(unsigned char *) 0xf9)
#define BPSCTR (*(unsigned char *) 0xfa)
#define BPOCTR (*(unsigned char *) 0xfb)
#define BPHCTR (*(unsigned char *) 0xfc)
#define BPCR (*(unsigned char *) 0xfd)
#define BPPLR (*(unsigned char *) 0xfe)

// Interrupt vectors definitions
#define BPINT 2
#define VREGMON_INT 3
#define EXT_INT0 4
#define EXT_INT1 5
#define EXT_INT2 6
#define WDT 7
#define TIM1_IC 8
#define TIM1_COMPA 9
#define TIM1_COMPB 10
#define TIM1_OVF 11
#define TIM0_IC 12
#define TIM0_COMPA 13
#define TIM0_COMPB 14
#define TIM0_OVF 15
#define SPI_STC 16
#define VADC 17
#define CCADC_CONV 18
#define CCADC_REC_CUR 19
#define CCADC_ACC 20
#define EE_RDY 21

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERSAVE_SUPPORTED__
#define __POWEROFF_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x01
	.EQU __sm_mask=0x0E
	.EQU __sm_adc_noise_red=0x02
	.EQU __sm_powersave=0x06
	.EQU __sm_poweroff=0x08
	.SET power_ctrl_reg=smcr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <mega16hva_bits.h>
#endif

#endif

