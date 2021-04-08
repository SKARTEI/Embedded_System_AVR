// CodeVisionAVR C Compiler
// (C) 2000 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the AT94K10, AT94K20, AT94K40 FPSLIC

#ifndef _94K_INCLUDED_
#define _94K_INCLUDED_

#pragma used+
sfrb UBRR1=0;
sfrb UCSR1B=1;
sfrb UCSR1A=2;
sfrb UDR1=3;
sfrb PINE=5;
sfrb DDRE=6;
sfrb PORTE=7;
sfrb UBRR0=9;
sfrb UCSR0B=0xa;
sfrb UCSR0A=0xb;
sfrb UDR0=0xc;
sfrb PIND=0x10;
sfrb DDRD=0x11;
sfrb PORTD=0x12;
sfrb FISCR=0x13;
sfrb FISUA=0x14;
sfrb FISUB=0x15;
sfrb FISUC=0x16;
sfrb FISUD=0x17;
sfrb FPGAX=0x18;
sfrb FPGAY=0x19;
sfrb FPGAZ=0x1a;
sfrb FPGAD=0x1b;
sfrb TWBR=0x1c;
sfrb TWSR=0x1d;
sfrb TWAR=0x1e;
sfrb TWDR=0x1f;
sfrb UBRRHI=0x20;
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
sfrb MCUSR=0x34;
sfrb MCUR=0x35;
sfrb TWCR=0x36;
sfrb TIFR=0x38;
sfrb TIMSK=0x39;
sfrb SFTCR=0x3a;
sfrb EIMF=0x3b;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

// Interrupt vectors definitions

#define FPGA_INT0 2
#define EXT_INT0 3
#define FPGA_INT1 4
#define EXT_INT1 5
#define FPGA_INT2 6
#define EXT_INT2 7
#define FPGA_INT3 8
#define EXT_INT3 9
#define TIM2_COMP 10
#define TIM2_OVF 11
#define TIM1_CAPT 12
#define TIM1_COMPA 13
#define TIM1_COMPB 14
#define TIM1_OVF 15
#define TIM0_COMP 16
#define TIM0_OVF 17
#define FPGA_INT4 18
#define FPGA_INT5 19
#define FPGA_INT6 20
#define FPGA_INT7 21
#define UART0_RXC 22
#define UART0_DRE 23
#define UART0_TXC 24
#define FPGA_INT8 25
#define FPGA_INT9 26
#define FPGA_INT10 27
#define FPGA_INT11 28
#define UART1_RXC 29
#define UART1_DRE 30
#define UART1_TXC 31
#define FPGA_INT12 32
#define FPGA_INT13 33
#define FPGA_INT14 34
#define FPGA_INT15 35
#define TWS_INT 36

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __POWERSAVE_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x20
	.EQU __sm_mask=0x18
	.EQU __sm_powerdown=0x10
	.EQU __sm_powersave=0x18
	.SET power_ctrl_reg=mcur
	#endif
#endasm

#endif

