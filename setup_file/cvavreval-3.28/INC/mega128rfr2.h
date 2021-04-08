/*************************************************************************
CodeVisionAVR C Compiler V3.06+
(C) 1998-2013 Pavel Haiduc, HP InfoTech S.R.L.

I/O registers definitions for the ATmega128RFR2
*************************************************************************/

#ifndef _MEGA128RFR2_INCLUDED_
#define _MEGA128RFR2_INCLUDED_

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
#define PRR2 (*(unsigned char *) 0x63)
#define PRR0 (*(unsigned char *) 0x64)
#define PRR1 (*(unsigned char *) 0x65)
#define OSCCAL (*(unsigned char *) 0x66)
#define BGCR (*(unsigned char *) 0x67)
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
#define NEMCR (*(unsigned char *) 0x75)
#define ADCSRC (*(unsigned char *) 0x77)
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
#define IRQ_MASK1 (*(unsigned char *) 0xbe)
#define IRQ_STATUS1 (*(unsigned char *) 0xbf)
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

#define SCRSTRLL (*(unsigned char *) 0xd7)
#define SCRSTRLH (*(unsigned char *) 0xd8)
#define SCRSTRHL (*(unsigned char *) 0xd9)
#define SCRSTRHH (*(unsigned char *) 0xda)
#define SCCSR (*(unsigned char *) 0xdb)
#define SCCR0 (*(unsigned char *) 0xdc)
#define SCCR1 (*(unsigned char *) 0xdd)
#define SCSR (*(unsigned char *) 0xde)
#define SCIRQM (*(unsigned char *) 0xdf)
#define SCIRQS (*(unsigned char *) 0xe0)
#define SCCNTLL (*(unsigned char *) 0xe1)
#define SCCNTLH (*(unsigned char *) 0xe2)
#define SCCNTHL (*(unsigned char *) 0xe3)
#define SCCNTHH (*(unsigned char *) 0xe4)
#define SCBTSRLL (*(unsigned char *) 0xe5)
#define SCBTSRLH (*(unsigned char *) 0xe6)
#define SCBTSRHL (*(unsigned char *) 0xe7)
#define SCBTSRHH (*(unsigned char *) 0xe8)
#define SCTSRLL (*(unsigned char *) 0xe9)
#define SCTSRLH (*(unsigned char *) 0xea)
#define SCTSRHL (*(unsigned char *) 0xeb)
#define SCTSRHH (*(unsigned char *) 0xec)
#define SCOCR3LL (*(unsigned char *) 0xed)
#define SCOCR3LH (*(unsigned char *) 0xee)
#define SCOCR3HL (*(unsigned char *) 0xef)
#define SCOCR3HH (*(unsigned char *) 0xf0)
#define SCOCR2LL (*(unsigned char *) 0xf1)
#define SCOCR2LH (*(unsigned char *) 0xf2)
#define SCOCR2HL (*(unsigned char *) 0xf3)
#define SCOCR2HH (*(unsigned char *) 0xf4)
#define SCOCR1LL (*(unsigned char *) 0xf5)
#define SCOCR1LH (*(unsigned char *) 0xf6)
#define SCOCR1HL (*(unsigned char *) 0xf7)
#define SCOCR1HH (*(unsigned char *) 0xf8)
#define SCTSTRLL (*(unsigned char *) 0xf9)
#define SCTSTRLH (*(unsigned char *) 0xfa)
#define SCTSTRHL (*(unsigned char *) 0xfb)
#define SCTSTRHH (*(unsigned char *) 0xfc)

#define MAFCR0 (*(unsigned char *) 0x10c)
#define MAFCR1 (*(unsigned char *) 0x10d)
#define MAFSA0L (*(unsigned char *) 0x10e)
#define MAFSA0H (*(unsigned char *) 0x10f)
#define MAFPA0L (*(unsigned char *) 0x110)
#define MAFPA0H (*(unsigned char *) 0x111)
#define MAFSA1L (*(unsigned char *) 0x112)
#define MAFSA1H (*(unsigned char *) 0x113)
#define MAFPA1L (*(unsigned char *) 0x114)
#define MAFPA1H (*(unsigned char *) 0x115)
#define MAFSA2L (*(unsigned char *) 0x116)
#define MAFSA2H (*(unsigned char *) 0x117)
#define MAFPA2L (*(unsigned char *) 0x118)
#define MAFPA2H (*(unsigned char *) 0x119)
#define MAFSA3L (*(unsigned char *) 0x11a)
#define MAFSA3H (*(unsigned char *) 0x11b)
#define MAFPA3L (*(unsigned char *) 0x11c)
#define MAFPA3H (*(unsigned char *) 0x11d)

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

#define LLCR (*(unsigned char *) 0x12f)
#define LLDRL (*(unsigned char *) 0x130)
#define LLDRH (*(unsigned char *) 0x131)
#define DRTRAM3 (*(unsigned char *) 0x132)
#define DRTRAM2 (*(unsigned char *) 0x133)
#define DRTRAM1 (*(unsigned char *) 0x134)
#define DRTRAM0 (*(unsigned char *) 0x135)
#define DPDS0 (*(unsigned char *) 0x136)
#define DPDS1 (*(unsigned char *) 0x137)
#define PARCR (*(unsigned char *) 0x138)
#define TRXPR (*(unsigned char *) 0x139)

#define AES_CTRL (*(unsigned char *) 0x13c)
#define AES_STATUS (*(unsigned char *) 0x13d)
#define AES_STATE (*(unsigned char *) 0x13e)
#define AES_KEY (*(unsigned char *) 0x13f)

#define TRX_STATUS (*(unsigned char *) 0x141)
#define TRX_STATE (*(unsigned char *) 0x142)
#define TRX_CTRL_0 (*(unsigned char *) 0x143)
#define TRX_CTRL_1 (*(unsigned char *) 0x144)
#define PHY_TX_PWR (*(unsigned char *) 0x145)
#define PHY_RSSI (*(unsigned char *) 0x146)
#define PHY_ED_LEVEL (*(unsigned char *) 0x147)
#define PHY_CC_CCA (*(unsigned char *) 0x148)
#define CCA_THRES (*(unsigned char *) 0x149)
#define RX_CTRL (*(unsigned char *) 0x14a)
#define SFD_VALUE (*(unsigned char *) 0x14b)
#define TRX_CTRL_2 (*(unsigned char *) 0x14c)
#define ANT_DIV (*(unsigned char *) 0x14d)
#define IRQ_MASK (*(unsigned char *) 0x14e)
#define IRQ_STATUS (*(unsigned char *) 0x14f)
#define VREG_CTRL (*(unsigned char *) 0x150)
#define BATMON (*(unsigned char *) 0x151)
#define XOSC_CTRL (*(unsigned char *) 0x152)
#define CC_CTRL_0 (*(unsigned char *) 0x153)
#define CC_CTRL_1 (*(unsigned char *) 0x154)
#define RX_SYN (*(unsigned char *) 0x155)
#define TRX_RPC (*(unsigned char *) 0x156)
#define XAH_CTRL_1 (*(unsigned char *) 0x157)
#define FTN_CTRL (*(unsigned char *) 0x158)

#define PLL_CF (*(unsigned char *) 0x15a)
#define PLL_DCU (*(unsigned char *) 0x15b)
#define PART_NUM (*(unsigned char *) 0x15c)
#define VERSION_NUM (*(unsigned char *) 0x15d)
#define MAN_ID_0 (*(unsigned char *) 0x15e)
#define MAN_ID_1 (*(unsigned char *) 0x15f)
#define SHORT_ADDR_0 (*(unsigned char *) 0x160)
#define SHORT_ADDR_1 (*(unsigned char *) 0x161)
#define PAN_ID_0 (*(unsigned char *) 0x162)
#define PAN_ID_1 (*(unsigned char *) 0x163)
#define IEEE_ADDR_0 (*(unsigned char *) 0x164)
#define IEEE_ADDR_1 (*(unsigned char *) 0x165)
#define IEEE_ADDR_2 (*(unsigned char *) 0x166)
#define IEEE_ADDR_3 (*(unsigned char *) 0x167)
#define IEEE_ADDR_4 (*(unsigned char *) 0x168)
#define IEEE_ADDR_5 (*(unsigned char *) 0x169)
#define IEEE_ADDR_6 (*(unsigned char *) 0x16a)
#define IEEE_ADDR_7 (*(unsigned char *) 0x16b)
#define XAH_CTRL_0 (*(unsigned char *) 0x16c)
#define CSMA_SEED_0 (*(unsigned char *) 0x16d)
#define CSMA_SEED_1 (*(unsigned char *) 0x16e)
#define CSMA_BE (*(unsigned char *) 0x16f)

#define TST_CTRL_DIGI (*(unsigned char *) 0x176)
#define TST_RX_LENGTH (*(unsigned char *) 0x17b)

#define TRXFBST (*(unsigned char *) 0x180)
#define TRXFBEND (*(unsigned char *) 0x1ff)

// Interrupt vectors definitions
#define RESET_VECTOR 1
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

#define TRX24_PLL_LOCK 58
#define TRX24_PLL_UNLOCK 59
#define TRX24_RX_START 60
#define TRX24_RX_END 61
#define TRX24_CCA_ED_DONE 62
#define TRX24_XAH_AMI 63
#define TRX24_TX_END 64
#define TRX24_AWAKE 65
#define SCNT_CMP1 66
#define SCNT_CMP2 67
#define SCNT_CMP3 68
#define SCNT_OVFL 69
#define SCNT_BACKOFF 70
#define AES_READY 71
#define BAT_LOW_INT 72
#define TRX24_TX_START 73
#define TRX24_AMI0 74
#define TRX24_AMI1 75
#define TRX24_AMI2 76
#define TRX24_AMI3 77

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

#define SPM_PAGESIZE 256
#define FLASHSTART   0x0000
#define FLASHEND     0x1FFFF
#define RAMSTART     0x0200
#define RAMSIZE      16384
#define RAMEND       0x41FF
#define E2START     0
#define E2SIZE      4096
#define E2PAGESIZE  8
#define E2END       0x0FFF
#define XRAMEND      RAMEND

// Signature
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0xA7
#define SIGNATURE_2 0x02

#ifdef _IO_BITS_DEFINITIONS_
#include <mega256rfr2_bits.h>
#endif

#endif

