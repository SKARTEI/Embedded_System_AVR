// CodeVisionAVR C Compiler
// (C) 1998-2003 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the AT76C711

#ifndef _76C711_INCLUDED_
#define _76C711_INCLUDED_

#pragma used+
sfrb SPCR=0xd;
sfrb SPSR=0xe;
sfrb SPDR=0xf;
sfrb PIND=0x10;
sfrb DDRD=0x11;
sfrb PORTD=0x12;
sfrb PERIPHEN=0x13;
sfrb CLK_CNTR=0x14;
sfrb PORTC=0x15;
sfrb PINB=0x16;
sfrb DDRB=0x17;
sfrb PORTB=0x18;
sfrb PINA=0x19;
sfrb DDRA=0x1a;
sfrb PORTA=0x1b;
sfrb IRDAMOD=0x20;
sfrb WDTCR=0x21;
sfrb ICR1L=0x26;
sfrb ICR1H=0x27;
sfrw ICR1=0x26;   // 16 bit access
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
sfrb PRELD=0x31;
sfrb TCNT0=0x32;
sfrb TCCR0=0x33;
sfrb MCUSR=0x34;
sfrb MCUCR=0x35;
sfrb TIFR=0x36;
sfrb TIMSK=0x37;
sfrb EIMSK=0x39;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb SREG=0x3f;
#pragma used-

// USB registers definitions

#define FBYTE_CNT7_H *(unsigned char *) 0x10A8
#define FBYTE_CNT6_H *(unsigned char *) 0x10A9
#define FBYTE_CNT5_H *(unsigned char *) 0x10AA
#define FBYTE_CNT4_H *(unsigned char *) 0x10AB
#define FBYTE_CNT3_H *(unsigned char *) 0x10AC
#define FBYTE_CNT2_H *(unsigned char *) 0x10AD
#define FBYTE_CNT1_H *(unsigned char *) 0x10AE
#define FBYTE_CNT0_H *(unsigned char *) 0x10AF
#define FBYTE_CNT7_L *(unsigned char *) 0x10B8
#define FBYTE_CNT6_L *(unsigned char *) 0x10B9
#define FBYTE_CNT5_L *(unsigned char *) 0x10BA
#define FBYTE_CNT4_L *(unsigned char *) 0x10BB
#define FBYTE_CNT3_L *(unsigned char *) 0x10BC
#define FBYTE_CNT2_L *(unsigned char *) 0x10BD
#define FBYTE_CNT1_L *(unsigned char *) 0x10BE
#define FBYTE_CNT0_L *(unsigned char *) 0x10BF
#define FDR7         *(unsigned char *) 0x10C8
#define FDR6         *(unsigned char *) 0x10C9
#define FDR5         *(unsigned char *) 0x10CA
#define FDR4         *(unsigned char *) 0x10CB
#define FDR3         *(unsigned char *) 0x10CC
#define FDR2         *(unsigned char *) 0x10CD
#define FDR1         *(unsigned char *) 0x10CE
#define FDR0         *(unsigned char *) 0x10CF
#define CSR7         *(unsigned char *) 0x10D8
#define CSR6         *(unsigned char *) 0x10D9
#define CSR5         *(unsigned char *) 0x10DA
#define CSR4         *(unsigned char *) 0x10DB
#define CSR3         *(unsigned char *) 0x10DC
#define CSR2         *(unsigned char *) 0x10DD
#define CSR1         *(unsigned char *) 0x10DE
#define CSR0         *(unsigned char *) 0x10DF
#define ECR7         *(unsigned char *) 0x10E8
#define ECR6         *(unsigned char *) 0x10E9
#define ECR5         *(unsigned char *) 0x10EA
#define ECR4         *(unsigned char *) 0x10EB
#define ECR3         *(unsigned char *) 0x10EC
#define ECR2         *(unsigned char *) 0x10ED
#define ECR1         *(unsigned char *) 0x10EE
#define ECR0         *(unsigned char *) 0x10EF
#define ENDPPGPG     *(unsigned char *) 0x10F1
#define FADDR        *(unsigned char *) 0x10F2
#define UIAR         *(unsigned char *) 0x10F5
#define UISR         *(unsigned char *) 0x10F6
#define SPRSIE       *(unsigned char *) 0x10F9
#define SPRSR        *(unsigned char *) 0x10FA
#define GLB_STATE    *(unsigned char *) 0x10FB
#define FR_NUM_L     *(unsigned char *) 0x10FC
#define FR_NUM_H     *(unsigned char *) 0x10FD
#define SLP_MD_EN    *(unsigned char *) 0x1100
#define IRQ_EN       *(unsigned char *) 0x1101
#define IRQ_STAT     *(unsigned char *) 0x1102
#define SUSP_WUP     *(unsigned char *) 0x1103
#define PA_EN        *(unsigned char *) 0x1104
#define USB_DMA_ADL  *(unsigned char *) 0x1105
#define USB_DMA_ADH  *(unsigned char *) 0x1106
#define USB_DMA_PLR  *(unsigned char *) 0x1107
#define USB_DMA_EAD  *(unsigned char *) 0x1108
#define USB_DMA_PLT  *(unsigned char *) 0x1109
#define USB_DMA_EN   *(unsigned char *) 0x110A

// DMA registers definitions

#define TXTADL *(unsigned char *) 0x2001
#define TXPLL  *(unsigned char *) 0x2003
#define TXPLM  *(unsigned char *) 0x2004
#define TXTPLL *(unsigned char *) 0x2005
#define TXTPLM *(unsigned char *) 0x2006
#define RXTADL *(unsigned char *) 0x2007
#define RXTADMEN *(unsigned char *) 0x2008
#define RSPLL  *(unsigned char *) 0x2009
#define RXPLM  *(unsigned char *) 0x200A
#define RXTPLL *(unsigned char *) 0x200B
#define RXTPLM *(unsigned char *) 0x200C
#define INTCST *(unsigned char *) 0x200D

// UART0 registers definitions

#define US0_RHR *(unsigned char *) 0x2020
#define US0_THR *(unsigned char *) 0x2020
#define US0_IER *(unsigned char *) 0x2021
#define US0_FCR *(unsigned char *) 0x2022
#define US0_PMR *(unsigned char *) 0x2023
#define US0_MR  *(unsigned char *) 0x2024
#define US0_CSR *(unsigned char *) 0x2025
#define US0_CR  *(unsigned char *) 0x2026
#define US0_BL  *(unsigned char *) 0x2027
#define US0_BM  *(unsigned char *) 0x2028
#define US0_RTO *(unsigned char *) 0x2029
#define US0_TTG *(unsigned char *) 0x202A

// UART1 registers definitions

#define US1_RHR *(unsigned char *) 0x2030
#define US1_THR *(unsigned char *) 0x2030
#define US1_IER *(unsigned char *) 0x2031
#define US1_FCR *(unsigned char *) 0x2032
#define US1_PMR *(unsigned char *) 0x2033
#define US1_MR  *(unsigned char *) 0x2034
#define US1_CSR *(unsigned char *) 0x2035
#define US1_CR  *(unsigned char *) 0x2036
#define US1_BL  *(unsigned char *) 0x2037
#define US1_BM  *(unsigned char *) 0x2038
#define US1_RTO *(unsigned char *) 0x2039
#define US1_TTG *(unsigned char *) 0x203A

// Interrupt vectors definitions

#define SUSP_RESM 2
#define EXT_INT0 3
#define TIM1_CAPT 4
#define TIM1_COMPA 5
#define TIM1_COMPB 6
#define TIM1_OVF 7
#define TIM0_OVF 8
#define SPI_STC 9
#define TDMAC 10
#define UART0_INT 11
#define RDMAC 12
#define USB_HARDWARE 13
#define UART1_INT 14
#define EXT_INT1 15

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
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#endif

