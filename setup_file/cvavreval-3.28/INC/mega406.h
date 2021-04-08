// CodeVisionAVR V3.0 C Compiler
// (C) 1998-2013 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATmega406

#ifndef _MEGA406_INCLUDED_
#define _MEGA406_INCLUDED_

#pragma used+
sfrb PINA=0;
sfrb DDRA=1;
sfrb PORTA=2;
sfrb PINB=3;
sfrb DDRB=4;
sfrb PORTB=5;
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
sfrb GPIOR1=0x2a;
sfrb GPIOR2=0x2b;
sfrb OCDR=0x31;
sfrb SMCR=0x33;
sfrb MCUSR=0x34;
sfrb MCUCR=0x35;
sfrb SPMCSR=0x37;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

#define WDTCSR (*(unsigned char *) 0x60)
#define WUTCSR (*(unsigned char *) 0x62)
#define PRR0 (*(unsigned char *) 0x64)
#define FOSCCAL (*(unsigned char *) 0x66)
#define PCICR (*(unsigned char *) 0x68)
#define EICRA (*(unsigned char *) 0x69)
#define PCMSK0 (*(unsigned char *) 0x6b)
#define PCMSK1 (*(unsigned char *) 0x6c)
#define TIMSK0 (*(unsigned char *) 0x6e)
#define TIMSK1 (*(unsigned char *) 0x6f)
#define VADCL (*(unsigned char *) 0x78)
#define VADCH (*(unsigned char *) 0x79)
#define VADCW (*(unsigned int *) 0x78) // 16 bit access
#define VADCSR (*(unsigned char *) 0x7a)
#define VADMUX (*(unsigned char *) 0x7c)
#define DIDR0 (*(unsigned char *) 0x7e)
#define TCCR1B (*(unsigned char *) 0x81)
#define TCNT1L (*(unsigned char *) 0x84)
#define TCNT1H (*(unsigned char *) 0x85)
#define OCR1AL (*(unsigned char *) 0x88)
#define OCR1AH (*(unsigned char *) 0x89)
#define TWBR (*(unsigned char *) 0xb8)
#define TWSR (*(unsigned char *) 0xb9)
#define TWAR (*(unsigned char *) 0xba)
#define TWCR (*(unsigned char *) 0xbc)
#define TWDR (*(unsigned char *) 0xbb)
#define TWAMR (*(unsigned char *) 0xbd)
#define TWBCSR (*(unsigned char *) 0xbe)
#define CCSR (*(unsigned char *) 0xc0) // 15012013_1
#define BGCCR (*(unsigned char *) 0xd0)
#define BGCRR (*(unsigned char *) 0xd1)
#define CADAC0 (*(unsigned char *) 0xe0)
#define CADAC1 (*(unsigned char *) 0xe1)
#define CADAC2 (*(unsigned char *) 0xe2)
#define CADAC3 (*(unsigned char *) 0xe3)
#define CADCSRA (*(unsigned char *) 0xe4)
#define CADCSRB (*(unsigned char *) 0xe5)
#define CADRCC (*(unsigned char *) 0xe6)
#define CADRDC (*(unsigned char *) 0xe7)
#define CADICL (*(unsigned char *) 0xe8)
#define CADICH (*(unsigned char *) 0xe9)
#define CADIC (*(unsigned int *) 0xe8)    // 16 bit access
#define FCSR (*(unsigned char *) 0xf0)
#define CBCR (*(unsigned char *) 0xf1)
#define BPIR (*(unsigned char *) 0xf2)
#define BPDUV (*(unsigned char *) 0xf3)
#define BPSCD (*(unsigned char *) 0xf4)
#define BPOCD (*(unsigned char *) 0xf5)
#define CBPTR (*(unsigned char *) 0xf6)
#define BPCR (*(unsigned char *) 0xf7)
#define BPPLR (*(unsigned char *) 0xf8)

// Interrupt vectors definitions

#define BPINT 2
#define EXT_INT0 3
#define EXT_INT1 4
#define EXT_INT2 5
#define EXT_INT3 6
#define PC_INT0 7
#define PC_INT1 8
#define WDT 9
#define WAKE_UP 10
#define TIM1_COMP 11
#define TIM1_OVF 12
#define TIM0_COMPA 13
#define TIM0_COMPB 14
#define TIM0_OVF 15
#define TWI_BUS_CD 16
#define TWI 17
#define VADC 18
#define CCADC_CONV 19
#define CCADC_REG_CUR 20
#define CCADC_ACC 21
#define EE_RDY 22
#define SPM_READY 23

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __POWERSAVE_SUPPORTED__
#define __POWEROFF_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x01
	.EQU __sm_mask=0x0E
	.EQU __sm_adc_noise_red=0x02
	.EQU __sm_powerdown=0x04
	.EQU __sm_powersave=0x06
	.EQU __sm_poweroff=0x08
	.SET power_ctrl_reg=smcr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <mega406_bits.h>
#endif

#endif

