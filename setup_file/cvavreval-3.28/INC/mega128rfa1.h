// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2012 Pavel Haiduc, HP InfoTech S.R.L.
// (C) 2010 Christian Erle, Ingenieurbuero Erle, added / changed to ATmega128RFA1

// I/O registers definitions for the ATmega128RFA1

#ifndef _MEGA128RFA1_INCLUDED_
#define _MEGA128RFA1_INCLUDED_

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

#define LLCR (*(unsigned char *) 0x12F)
#define LLDRL (*(unsigned char *) 0x130)
#define LLDRH (*(unsigned char *) 0x131)
#define DRTRAM3 (*(unsigned char *) 0x132)
#define DRTRAM2 (*(unsigned char *) 0x133)
#define DRTRAM1 (*(unsigned char *) 0x134)
#define DRTRAM0 (*(unsigned char *) 0x135)
#define DPDS0 (*(unsigned char *) 0x136)
#define DPDS1 (*(unsigned char *) 0x137)

#define TRXPR (*(unsigned char *) 0x139)

#define AES_CTRL (*(unsigned char *) 0x13C)
#define AES_STATUS (*(unsigned char *) 0x13D)
#define AES_STATE (*(unsigned char *) 0x13E)
#define AES_KEY (*(unsigned char *) 0x13F)

#define TRX_STATUS (*(unsigned char *) 0x141)
#define TRX_STATE (*(unsigned char *) 0x142)
#define TRX_CTRL_0 (*(unsigned char *) 0x143)
#define TRX_CTRL_1 (*(unsigned char *) 0x144)

#define PHY_TX_PWR (*(unsigned char *) 0x145)
#define PHY_RSSI (*(unsigned char *) 0x146)
#define PHY_ED_LEVEL (*(unsigned char *) 0x147)
#define PHY_CC_CCA (*(unsigned char *) 0x148)

#define CCA_THRES (*(unsigned char *) 0x149)
#define RX_CTRL (*(unsigned char *) 0x14A)
#define SFD_VALUE (*(unsigned char *) 0x14B)
#define TRX_CTRL_2 (*(unsigned char *) 0x14C)
#define ANT_DIV (*(unsigned char *) 0x14D)

#define IRQ_MASK (*(unsigned char *) 0x14E)
#define IRQ_STATUS (*(unsigned char *) 0x14F)
#define VREG_CTRL (*(unsigned char *) 0x150)
#define BATMON (*(unsigned char *) 0x151)
#define XOSC_CTRL (*(unsigned char *) 0x152)
#define RX_SYN (*(unsigned char *) 0x155)
#define XAH_CTRL_1 (*(unsigned char *) 0x157)
#define FTN_CTRL (*(unsigned char *) 0x158)
#define PLL_CF (*(unsigned char *) 0x15A)
#define PLL_DCU (*(unsigned char *) 0x15B)

#define PART_NUM (*(unsigned char *) 0x15C)
#define VERSION_NUM (*(unsigned char *) 0x15D)
#define MAN_ID_0 (*(unsigned char *) 0x15E)
#define MAN_ID_1 (*(unsigned char *) 0x15F)
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
#define IEEE_ADDR_6 (*(unsigned char *) 0x16A)
#define IEEE_ADDR_7 (*(unsigned char *) 0x16B)

#define XAH_CTRL_0 (*(unsigned char *) 0x16C)
#define CSMA_SEED_0 (*(unsigned char *) 0x16D)
#define CSMA_SEED_1 (*(unsigned char *) 0x16E)
#define CSMA_BE (*(unsigned char *) 0x16F)

#define TST_CTRL_DIGI (*(unsigned char *) 0x176)
#define TST_RX_LENGTH (*(unsigned char *) 0x17B)
#define TRXFBST (*(unsigned char *) 0x180)
#define TRXFBEND (*(unsigned char *) 0x1FF)


// Interrupt vectors definitions

#define EXT_INT0 		2
#define EXT_INT1 		3
#define EXT_INT2 		4
#define EXT_INT3 		5
#define EXT_INT4 		6
#define EXT_INT5 		7
#define EXT_INT6 		8
#define EXT_INT7 		9
#define PC_INT0 		10
#define PC_INT1 		11
#define WDT 			13
#define TIM2_COMPA 		14
#define TIM2_COMPB 		15
#define TIM2_OVF 		16
#define TIM1_CAPT 		17
#define TIM1_COMPA 		18
#define TIM1_COMPB 		19
#define TIM1_COMPC 		20
#define TIM1_OVF 		21
#define TIM0_COMPA 		22
#define TIM0_COMPB 		23
#define TIM0_OVF 		24
#define SPI_STC 		25
#define USART0_RXC 		26
#define USART0_UDRE 	27
#define USART0_TXC 		28
#define ANA_COMP 		29
#define ADC_INT 		30
#define EE_RDY 			31
#define TIM3_CAPT 		32
#define TIM3_COMPA 		33
#define TIM3_COMPB 		34
#define TIM3_COMPC 		35
#define TIM3_OVF 		36
#define USART1_RXC 		37
#define USART1_UDRE 	38
#define USART1_TXC 		39
#define TWI 			40
#define SPM_READY 		41
#define TIM4_CAPT 		42
#define TIM4_COMPA 		43
#define TIM4_COMPB 		44
#define TIM4_COMPC 		45
#define TIM4_OVF 		46
#define TIM5_CAPT 		47
#define TIM5_COMPA 		48
#define TIM5_COMPB 		49
#define TIM5_COMPC 		50
#define TIM5_OVF 		51

#define TRX24_PLL_LOCK 		58
#define TRX24_PLL_UNLOCK 	59
#define TRX24_RX_START 		60
#define TRX24_RX_END 		61
#define TRX24_CCA_ED_DONE 	62
#define TRX24_XAH_AMI 		63
#define TRX24_TX_END 		64
#define TRX24_AWAKE 		65

#define SCNT_CMP1 		66
#define SCNT_CMP2 		67
#define SCNT_CMP3 		68
#define SCNT_OVFL 		69
#define SCNT_BACKOFF 	70
#define AES_READY 		71
#define BAT_LOW_INT 	72


#define USART_RXC USART0_RXC
#define USART_DRE USART0_UDRE
#define USART_TXC USART0_TXC

//+++++++++++++++++
// TRXPR masks
#define TRXRST_MASK		0x01
#define SLPTR_MASK		0x02

//+++++++++++++++++
// FCF Frame Control Field values
#define FCS_LSB_ACK_NOSEC_DATA			0x21
#define FCS_MSB_DESTSRCSHORT_COMP2006	0x98

// FCF masks and values
#define FCF_FRAME_TYPE_MASK		0x07
#define FCF_SEC_EN_MASK			0x08
#define FCF_FRM_PEND_MASK		0x10
#define FCF_ACK_REQ_MASK		0x20
#define FCF_INTRA_PAN_MASK		0x40
#define FCF_DEST_ADR_MASK		0x0C
#define FCF_FRM_VERS_MASK		0x30
#define FCF_SRC_ADR_MASK		0xC0

#define FCF_FRAME_TYPE_BEACON	0
#define FCF_FRAME_TYPE_DATA		1
#define FCF_FRAME_TYPE_ACK		2
#define FCF_FRAME_TYPE_MACC		3

#define FCF_ADDR_MODE_NOADDR	0
#define FCF_ADDR_MODE_SHORT16	2
#define FCF_ADDR_MODE_IEEE64	3

#define FCF_FRAME_COMP_2003		0
#define FCF_FRAME_COMP_2006		1


//+++++++++++++++++
// TRX_STATUS - Transceiver Status Register
// READ only

// TRX_STATUS7:6
#define CCA_DONE_MASK	0x80
#define CCA_STATUS_MASK	0x40

// TRX states = TRX_STATUS4:0
#define TRX_STATE_MASK		0x1F
// states:
#define TRX_ST_RESET		0x00
#define TRX_ST_BUSY_RX		0x01
#define TRX_ST_BUSY_TX		0x02
#define TRX_ST_RX_ON		0x06
#define TRX_ST_TRX_OFF		0x08
#define TRX_ST_PLL_ON		0x09
#define TRX_ST_SLEEP		0x0F
#define TRX_ST_BUSY_RX_AACK	0x11
#define TRX_ST_BUSY_TX_ARET	0x12
#define TRX_ST_RX_AACK_ON	0x16
#define TRX_ST_TX_ARET_ON	0x19
#define TRX_ST_TRANSITION	0x1F

//+++++++++++++++++
// TRX_STATE - Transceiver State Control Register

// TRX_STATE7:5 = TRAC_STATUS2:0 - Transaction Status
// READ only
#define TRAC_STATUS_MASK	0xE0
// status:
#define TRAC_SUCCESS					0	// RX_AACK, TX_ARET
#define TRAC_SUCCESS_DATA_PENDING		1	// TX_ARET
#define TRAC_SUCCESS_WAIT_FOR_ACK		2	// RX_AACK
#define TRAC_CHANNEL_ACCESS_FAILURE		3	// TX_ARET
#define TRAC_NO_ACK						5	// TX_ARET
#define TRAC_INVALID					7	// RX_AACK, TX_ARET

// TRX_STATE4:0 = TRX_CMD4:0 - State Control Command
#define TRX_CMD_MASK	0x1F
// commands:
#define TRX_CMD_NOP				0x00
#define TRX_CMD_TX_START		0x02
#define TRX_CMD_FORCE_TRX_OFF	0x03
#define TRX_CMD_FORCE_PLL_ON	0x04
#define TRX_CMD_RX_ON			0x06
#define TRX_CMD_TRX_OFF			0x08
#define TRX_CMD_PLL_ON			0x09
#define TRX_CMD_RX_AACK_ON		0x16
#define TRX_CMD_TX_ARET_ON		0x19

#define RX_CRC_VALID_MASK	0x80

// CHANNEL number in PHY_CC_CCA:
#define PHY_CC_CCA_CHANNEL_MASK	0x1F
#define TRX24_BASE_FREQ		2405

// AUTO_CRC_ON number in TRX_CTRL_1:
#define TX_AUTO_CRC_ON_MASK 	0x20

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
#include <mega128rfa1_bits.h>
#endif

#endif

