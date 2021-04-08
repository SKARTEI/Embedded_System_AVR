// CodeVisionAVR C Compiler V3.11+
// (C) 1998-2014 Pavel Haiduc, HP InfoTech S.R.L.

// Peripheral Modules and Interrupt Vector definitions for the ATxmega64A1U

#ifndef __XMEGA64A1U_INCLUDED__
#define __XMEGA64A1U_INCLUDED__

#define __CRC_EXISTS__
#define __USB_EXISTS__
#define __TC2_EXISTS__
#define __SEP_DACS__

#include <xmstruct.h> // definitions for the Peripheral Module structures
#include <xmbits_a1u.h> // bit definitions for the Peripheral Modules registers

// General Purpose I/O Registers
sfrb GPIO0=0x00;
sfrb GPIO1=0x01;
sfrb GPIO2=0x02;
sfrb GPIO3=0x03;
sfrb GPIO4=0x04;
sfrb GPIO5=0x05;
sfrb GPIO6=0x06;
sfrb GPIO7=0x07;
sfrb GPIO8=0x08;
sfrb GPIO9=0x09;
sfrb GPIOA=0x0A;
sfrb GPIOB=0x0B;
sfrb GPIOC=0x0C;
sfrb GPIOD=0x0D;
sfrb GPIOE=0x0E;
sfrb GPIOF=0x0F;
sfrb VPORT0_DIR=0x10;
sfrb VPORT0_OUT=0x11;
sfrb VPORT0_IN=0x12;
sfrb VPORT0_INTFLAGS=0x13;
sfrb VPORT1_DIR=0x14;
sfrb VPORT1_OUT=0x15;
sfrb VPORT1_IN=0x16;
sfrb VPORT1_INTFLAGS=0x17;
sfrb VPORT2_DIR=0x18;
sfrb VPORT2_OUT=0x19;
sfrb VPORT2_IN=0x1A;
sfrb VPORT2_INTFLAGS=0x1B;
sfrb VPORT3_DIR=0x1C;
sfrb VPORT3_OUT=0x1D;
sfrb VPORT3_IN=0x1E;
sfrb VPORT3_INTFLAGS=0x1F;
sfrb OCD_OCDR0=0x2E;
sfrb OCD_OCDR1=0x2F;
sfrb CCP=0x34;
sfrb RAMPD=0x38;
sfrb RAMPX=0x39;
sfrb RAMPY=0x3A;
sfrb RAMPZ=0x3B;
sfrb EIND=0x3C;
sfrb SPL=0x3D;
sfrb SPH=0x3E;
sfrb SREG=0x3F;

#define VPORT0    (*(volatile VPORT_t *) 0x0010)  // Virtual Port 
#define VPORT1    (*(volatile VPORT_t *) 0x0014)  // Virtual Port 
#define VPORT2    (*(volatile VPORT_t *) 0x0018)  // Virtual Port 
#define VPORT3    (*(volatile VPORT_t *) 0x001C)  // Virtual Port 
#define OCD    (*(volatile OCD_t *) 0x002E)  // On-Chip Debug System 
#define CLK    (*(volatile CLK_t *) 0x0040)  // Clock System 
#define SLEEP    (*(volatile SLEEP_t *) 0x0048)  // Sleep Controller 
#define OSC    (*(volatile OSC_t *) 0x0050)  // Oscillator 
#define DFLLRC32M    (*(volatile DFLL_t *) 0x0060)  // DFLL 
#define DFLLRC2M    (*(volatile DFLL_t *) 0x0068)  // DFLL 
#define PR    (*(volatile PR_t *) 0x0070)  // Power Reduction 
#define RST    (*(volatile RST_t *) 0x0078)  // Reset 
#define WDT    (*(volatile WDT_t *) 0x0080)  // Watch-Dog Timer 
#define MCU    (*(volatile MCU_t *) 0x0090)  // MCU Control 
#define PMIC    (*(volatile PMIC_t *) 0x00A0)  // Programmable Multi-level Interrupt Controller 
#define PORTCFG    (*(volatile PORTCFG_t *) 0x00B0)  // I/O port Configuration 
#define AES    (*(volatile AES_t *) 0x00C0)  // AES Module 
#define CRC    (*(volatile CRC_t *) 0x00D0)  // Cyclic Redundancy Checker 
#define DMA    (*(volatile DMA_t *) 0x0100)  // DMA Controller 
#define EVSYS    (*(volatile EVSYS_t *) 0x0180)  // Event System 
#define NVM    (*(volatile NVM_t *) 0x01C0)  // Non-volatile Memory Controller 
#define ADCA    (*(volatile ADC_t *) 0x0200)  // Analog-to-Digital Converter 
#define ADCB    (*(volatile ADC_t *) 0x0240)  // Analog-to-Digital Converter 
#define DACA    (*(volatile DAC_t *) 0x0300)  // Digital-to-Analog Converter 
#define DACB    (*(volatile DAC_t *) 0x0320)  // Digital-to-Analog Converter 
#define ACA    (*(volatile AC_t *) 0x0380)  // Analog Comparator 
#define ACB    (*(volatile AC_t *) 0x0390)  // Analog Comparator 
#define RTC    (*(volatile RTC_t *) 0x0400)  // Real-Time Counter 
#define EBI    (*(volatile EBI_t *) 0x0440)  // External Bus Interface 
#define TWIC    (*(volatile TWI_t *) 0x0480)  // Two-Wire Interface 
#define TWID    (*(volatile TWI_t *) 0x0490)  // Two-Wire Interface 
#define TWIE    (*(volatile TWI_t *) 0x04A0)  // Two-Wire Interface 
#define TWIF    (*(volatile TWI_t *) 0x04B0)  // Two-Wire Interface 
#define USB    (*(volatile USB_t *) 0x04C0)  // Universal Serial Bus 
#define PORTA    (*(volatile PORT_t *) 0x0600)  // I/O Ports 
#define PORTB    (*(volatile PORT_t *) 0x0620)  // I/O Ports 
#define PORTC    (*(volatile PORT_t *) 0x0640)  // I/O Ports 
#define PORTD    (*(volatile PORT_t *) 0x0660)  // I/O Ports 
#define PORTE    (*(volatile PORT_t *) 0x0680)  // I/O Ports 
#define PORTF    (*(volatile PORT_t *) 0x06A0)  // I/O Ports 
#define PORTH    (*(volatile PORT_t *) 0x06E0)  // I/O Ports 
#define PORTJ    (*(volatile PORT_t *) 0x0700)  // I/O Ports 
#define PORTK    (*(volatile PORT_t *) 0x0720)  // I/O Ports 
#define PORTQ    (*(volatile PORT_t *) 0x07C0)  // I/O Ports 
#define PORTR    (*(volatile PORT_t *) 0x07E0)  // I/O Ports 
#define TCC0    (*(volatile TC0_t *) 0x0800)  // 16-bit Timer/Counter 0 
#define TCC2    (*(volatile TC2_t *) 0x0800)  // 16-bit Timer/Counter type 2 
#define TCC1    (*(volatile TC1_t *) 0x0840)  // 16-bit Timer/Counter 1 
#define AWEXC    (*(volatile AWEX_t *) 0x0880)  // Advanced Waveform Extension 
#define HIRESC    (*(volatile HIRES_t *) 0x0890)  // High-Resolution Extension 
#define USARTC0    (*(volatile USART_t *) 0x08A0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define USARTC1    (*(volatile USART_t *) 0x08B0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define SPIC    (*(volatile SPI_t *) 0x08C0)  // Serial Peripheral Interface 
#define IRCOM    (*(volatile IRCOM_t *) 0x08F8)  // IR Communication Module 
#define TCD0    (*(volatile TC0_t *) 0x0900)  // 16-bit Timer/Counter 0 
#define TCD2    (*(volatile TC2_t *) 0x0900)  // 16-bit Timer/Counter type 2 
#define TCD1    (*(volatile TC1_t *) 0x0940)  // 16-bit Timer/Counter 1 
#define HIRESD    (*(volatile HIRES_t *) 0x0990)  // High-Resolution Extension 
#define USARTD0    (*(volatile USART_t *) 0x09A0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define USARTD1    (*(volatile USART_t *) 0x09B0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define SPID    (*(volatile SPI_t *) 0x09C0)  // Serial Peripheral Interface 
#define TCE0    (*(volatile TC0_t *) 0x0A00)  // 16-bit Timer/Counter 0 
#define TCE2    (*(volatile TC2_t *) 0x0A00)  // 16-bit Timer/Counter type 2 
#define TCE1    (*(volatile TC1_t *) 0x0A40)  // 16-bit Timer/Counter 1 
#define AWEXE    (*(volatile AWEX_t *) 0x0A80)  // Advanced Waveform Extension 
#define HIRESE    (*(volatile HIRES_t *) 0x0A90)  // High-Resolution Extension 
#define USARTE0    (*(volatile USART_t *) 0x0AA0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define USARTE1    (*(volatile USART_t *) 0x0AB0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define SPIE    (*(volatile SPI_t *) 0x0AC0)  // Serial Peripheral Interface 
#define TCF0    (*(volatile TC0_t *) 0x0B00)  // 16-bit Timer/Counter 0 
#define TCF2    (*(volatile TC2_t *) 0x0B00)  // 16-bit Timer/Counter type 2 
#define TCF1    (*(volatile TC1_t *) 0x0B40)  // 16-bit Timer/Counter 1 
#define HIRESF    (*(volatile HIRES_t *) 0x0B90)  // High-Resolution Extension 
#define USARTF0    (*(volatile USART_t *) 0x0BA0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define USARTF1    (*(volatile USART_t *) 0x0BB0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define SPIF    (*(volatile SPI_t *) 0x0BC0)  // Serial Peripheral Interface 

// Interrupt Vectors
// Reset
#define RESET_vect 1

// OSC interrupt vectors 
#define OSC_OSCF_vect      (1+1)  // Oscillator Failure Interrupt (NMI) 

// PORTC interrupt vectors 
#define PORTC_INT0_vect      (1+2)  // External Interrupt 0 
#define PORTC_INT1_vect      (1+3)  // External Interrupt 1 

// PORTR interrupt vectors 
#define PORTR_INT0_vect      (1+4)  // External Interrupt 0 
#define PORTR_INT1_vect      (1+5)  // External Interrupt 1 

// DMA interrupt vectors 
#define DMA_CH0_vect      (1+6)  // Channel 0 Interrupt 
#define DMA_CH1_vect      (1+7)  // Channel 1 Interrupt 
#define DMA_CH2_vect      (1+8)  // Channel 2 Interrupt 
#define DMA_CH3_vect      (1+9)  // Channel 3 Interrupt 

// RTC interrupt vectors 
#define RTC_OVF_vect      (1+10)  // Overflow Interrupt 
#define RTC_COMP_vect      (1+11)  // Compare Interrupt 

// TWIC interrupt vectors 
#define TWIC_TWIS_vect      (1+12)  // TWI Slave Interrupt 
#define TWIC_TWIM_vect      (1+13)  // TWI Master Interrupt 

// TCC0 interrupt vectors 
#define TCC0_OVF_vect      (1+14)  // Overflow Interrupt 

// TCC2 interrupt vectors 
#define TCC2_LUNF_vect      (1+14)  // Low Byte Underflow Interrupt 

// TCC0 interrupt vectors 
#define TCC0_ERR_vect      (1+15)  // Error Interrupt 

// TCC2 interrupt vectors 
#define TCC2_HUNF_vect      (1+15)  // High Byte Underflow Interrupt 

// TCC0 interrupt vectors 
#define TCC0_CCA_vect      (1+16)  // Compare or Capture A Interrupt 

// TCC2 interrupt vectors 
#define TCC2_LCMPA_vect      (1+16)  // Low Byte Compare A Interrupt 

// TCC0 interrupt vectors 
#define TCC0_CCB_vect      (1+17)  // Compare or Capture B Interrupt 

// TCC2 interrupt vectors 
#define TCC2_LCMPB_vect      (1+17)  // Low Byte Compare B Interrupt 

// TCC0 interrupt vectors 
#define TCC0_CCC_vect      (1+18)  // Compare or Capture C Interrupt 

// TCC2 interrupt vectors 
#define TCC2_LCMPC_vect      (1+18)  // Low Byte Compare C Interrupt 

// TCC0 interrupt vectors 
#define TCC0_CCD_vect      (1+19)  // Compare or Capture D Interrupt 

// TCC2 interrupt vectors 
#define TCC2_LCMPD_vect      (1+19)  // Low Byte Compare D Interrupt 

// TCC1 interrupt vectors 
#define TCC1_OVF_vect      (1+20)  // Overflow Interrupt 
#define TCC1_ERR_vect      (1+21)  // Error Interrupt 
#define TCC1_CCA_vect      (1+22)  // Compare or Capture A Interrupt 
#define TCC1_CCB_vect      (1+23)  // Compare or Capture B Interrupt 

// SPIC interrupt vectors 
#define SPIC_INT_vect      (1+24)  // SPI Interrupt 

// USARTC0 interrupt vectors 
#define USARTC0_RXC_vect      (1+25)  // Reception Complete Interrupt 
#define USARTC0_DRE_vect      (1+26)  // Data Register Empty Interrupt 
#define USARTC0_TXC_vect      (1+27)  // Transmission Complete Interrupt 

// USARTC1 interrupt vectors 
#define USARTC1_RXC_vect      (1+28)  // Reception Complete Interrupt 
#define USARTC1_DRE_vect      (1+29)  // Data Register Empty Interrupt 
#define USARTC1_TXC_vect      (1+30)  // Transmission Complete Interrupt 

// AES interrupt vectors 
#define AES_INT_vect      (1+31)  // AES Interrupt 

// NVM interrupt vectors 
#define NVM_EE_vect      (1+32)  // EE Interrupt 
#define NVM_SPM_vect      (1+33)  // SPM Interrupt 

// PORTB interrupt vectors 
#define PORTB_INT0_vect      (1+34)  // External Interrupt 0 
#define PORTB_INT1_vect      (1+35)  // External Interrupt 1 

// ACB interrupt vectors 
#define ACB_AC0_vect      (1+36)  // AC0 Interrupt 
#define ACB_AC1_vect      (1+37)  // AC1 Interrupt 
#define ACB_ACW_vect      (1+38)  // ACW Window Mode Interrupt 

// ADCB interrupt vectors 
#define ADCB_CH0_vect      (1+39)  // Interrupt 0 
#define ADCB_CH1_vect      (1+40)  // Interrupt 1 
#define ADCB_CH2_vect      (1+41)  // Interrupt 2 
#define ADCB_CH3_vect      (1+42)  // Interrupt 3 

// PORTE interrupt vectors 
#define PORTE_INT0_vect      (1+43)  // External Interrupt 0 
#define PORTE_INT1_vect      (1+44)  // External Interrupt 1 

// TWIE interrupt vectors 
#define TWIE_TWIS_vect      (1+45)  // TWI Slave Interrupt 
#define TWIE_TWIM_vect      (1+46)  // TWI Master Interrupt 

// TCE0 interrupt vectors 
#define TCE0_OVF_vect      (1+47)  // Overflow Interrupt 

// TCE2 interrupt vectors 
#define TCE2_LUNF_vect      (1+47)  // Low Byte Underflow Interrupt 

// TCE0 interrupt vectors 
#define TCE0_ERR_vect      (1+48)  // Error Interrupt 

// TCE2 interrupt vectors 
#define TCE2_HUNF_vect      (1+48)  // High Byte Underflow Interrupt 

// TCE0 interrupt vectors 
#define TCE0_CCA_vect      (1+49)  // Compare or Capture A Interrupt 

// TCE2 interrupt vectors 
#define TCE2_LCMPA_vect      (1+49)  // Low Byte Compare A Interrupt 

// TCE0 interrupt vectors 
#define TCE0_CCB_vect      (1+50)  // Compare or Capture B Interrupt 

// TCE2 interrupt vectors 
#define TCE2_LCMPB_vect      (1+50)  // Low Byte Compare B Interrupt 

// TCE0 interrupt vectors 
#define TCE0_CCC_vect      (1+51)  // Compare or Capture C Interrupt 

// TCE2 interrupt vectors 
#define TCE2_LCMPC_vect      (1+51)  // Low Byte Compare C Interrupt 

// TCE0 interrupt vectors 
#define TCE0_CCD_vect      (1+52)  // Compare or Capture D Interrupt 

// TCE2 interrupt vectors 
#define TCE2_LCMPD_vect      (1+52)  // Low Byte Compare D Interrupt 

// TCE1 interrupt vectors 
#define TCE1_OVF_vect      (1+53)  // Overflow Interrupt 
#define TCE1_ERR_vect      (1+54)  // Error Interrupt 
#define TCE1_CCA_vect      (1+55)  // Compare or Capture A Interrupt 
#define TCE1_CCB_vect      (1+56)  // Compare or Capture B Interrupt 

// SPIE interrupt vectors 
#define SPIE_INT_vect      (1+57)  // SPI Interrupt 

// USARTE0 interrupt vectors 
#define USARTE0_RXC_vect      (1+58)  // Reception Complete Interrupt 
#define USARTE0_DRE_vect      (1+59)  // Data Register Empty Interrupt 
#define USARTE0_TXC_vect      (1+60)  // Transmission Complete Interrupt 

// USARTE1 interrupt vectors 
#define USARTE1_RXC_vect      (1+61)  // Reception Complete Interrupt 
#define USARTE1_DRE_vect      (1+62)  // Data Register Empty Interrupt 
#define USARTE1_TXC_vect      (1+63)  // Transmission Complete Interrupt 

// PORTD interrupt vectors 
#define PORTD_INT0_vect      (1+64)  // External Interrupt 0 
#define PORTD_INT1_vect      (1+65)  // External Interrupt 1 

// PORTA interrupt vectors 
#define PORTA_INT0_vect      (1+66)  // External Interrupt 0 
#define PORTA_INT1_vect      (1+67)  // External Interrupt 1 

// ACA interrupt vectors 
#define ACA_AC0_vect      (1+68)  // AC0 Interrupt 
#define ACA_AC1_vect      (1+69)  // AC1 Interrupt 
#define ACA_ACW_vect      (1+70)  // ACW Window Mode Interrupt 

// ADCA interrupt vectors 
#define ADCA_CH0_vect      (1+71)  // Interrupt 0 
#define ADCA_CH1_vect      (1+72)  // Interrupt 1 
#define ADCA_CH2_vect      (1+73)  // Interrupt 2 
#define ADCA_CH3_vect      (1+74)  // Interrupt 3 

// TWID interrupt vectors 
#define TWID_TWIS_vect      (1+75)  // TWI Slave Interrupt 
#define TWID_TWIM_vect      (1+76)  // TWI Master Interrupt 

// TCD0 interrupt vectors 
#define TCD0_OVF_vect      (1+77)  // Overflow Interrupt 

// TCD2 interrupt vectors 
#define TCD2_LUNF_vect      (1+77)  // Low Byte Underflow Interrupt 

// TCD0 interrupt vectors 
#define TCD0_ERR_vect      (1+78)  // Error Interrupt 

// TCD2 interrupt vectors 
#define TCD2_HUNF_vect      (1+78)  // High Byte Underflow Interrupt 

// TCD0 interrupt vectors 
#define TCD0_CCA_vect      (1+79)  // Compare or Capture A Interrupt 

// TCD2 interrupt vectors 
#define TCD2_LCMPA_vect      (1+79)  // Low Byte Compare A Interrupt 

// TCD0 interrupt vectors 
#define TCD0_CCB_vect      (1+80)  // Compare or Capture B Interrupt 

// TCD2 interrupt vectors 
#define TCD2_LCMPB_vect      (1+80)  // Low Byte Compare B Interrupt 

// TCD0 interrupt vectors 
#define TCD0_CCC_vect      (1+81)  // Compare or Capture C Interrupt 

// TCD2 interrupt vectors 
#define TCD2_LCMPC_vect      (1+81)  // Low Byte Compare C Interrupt 

// TCD0 interrupt vectors 
#define TCD0_CCD_vect      (1+82)  // Compare or Capture D Interrupt 

// TCD2 interrupt vectors 
#define TCD2_LCMPD_vect      (1+82)  // Low Byte Compare D Interrupt 

// TCD1 interrupt vectors 
#define TCD1_OVF_vect      (1+83)  // Overflow Interrupt 
#define TCD1_ERR_vect      (1+84)  // Error Interrupt 
#define TCD1_CCA_vect      (1+85)  // Compare or Capture A Interrupt 
#define TCD1_CCB_vect      (1+86)  // Compare or Capture B Interrupt 

// SPID interrupt vectors 
#define SPID_INT_vect      (1+87)  // SPI Interrupt 

// USARTD0 interrupt vectors 
#define USARTD0_RXC_vect      (1+88)  // Reception Complete Interrupt 
#define USARTD0_DRE_vect      (1+89)  // Data Register Empty Interrupt 
#define USARTD0_TXC_vect      (1+90)  // Transmission Complete Interrupt 

// USARTD1 interrupt vectors 
#define USARTD1_RXC_vect      (1+91)  // Reception Complete Interrupt 
#define USARTD1_DRE_vect      (1+92)  // Data Register Empty Interrupt 
#define USARTD1_TXC_vect      (1+93)  // Transmission Complete Interrupt 

// PORTQ interrupt vectors 
#define PORTQ_INT0_vect      (1+94)  // External Interrupt 0 
#define PORTQ_INT1_vect      (1+95)  // External Interrupt 1 

// PORTH interrupt vectors 
#define PORTH_INT0_vect      (1+96)  // External Interrupt 0 
#define PORTH_INT1_vect      (1+97)  // External Interrupt 1 

// PORTJ interrupt vectors 
#define PORTJ_INT0_vect      (1+98)  // External Interrupt 0 
#define PORTJ_INT1_vect      (1+99)  // External Interrupt 1 

// PORTK interrupt vectors 
#define PORTK_INT0_vect      (1+100)  // External Interrupt 0 
#define PORTK_INT1_vect      (1+101)  // External Interrupt 1 

// PORTF interrupt vectors 
#define PORTF_INT0_vect      (1+104)  // External Interrupt 0 
#define PORTF_INT1_vect      (1+105)  // External Interrupt 1 

// TWIF interrupt vectors 
#define TWIF_TWIS_vect      (1+106)  // TWI Slave Interrupt 
#define TWIF_TWIM_vect      (1+107)  // TWI Master Interrupt 

// TCF0 interrupt vectors 
#define TCF0_OVF_vect      (1+108)  // Overflow Interrupt 

// TCF2 interrupt vectors 
#define TCF2_LUNF_vect      (1+108)  // Low Byte Underflow Interrupt 

// TCF0 interrupt vectors 
#define TCF0_ERR_vect      (1+109)  // Error Interrupt 

// TCF2 interrupt vectors 
#define TCF2_HUNF_vect      (1+109)  // High Byte Underflow Interrupt 

// TCF0 interrupt vectors 
#define TCF0_CCA_vect      (1+110)  // Compare or Capture A Interrupt 

// TCF2 interrupt vectors 
#define TCF2_LCMPA_vect      (1+110)  // Low Byte Compare A Interrupt 

// TCF0 interrupt vectors 
#define TCF0_CCB_vect      (1+111)  // Compare or Capture B Interrupt 

// TCF2 interrupt vectors 
#define TCF2_LCMPB_vect      (1+111)  // Low Byte Compare B Interrupt 

// TCF0 interrupt vectors 
#define TCF0_CCC_vect      (1+112)  // Compare or Capture C Interrupt 

// TCF2 interrupt vectors 
#define TCF2_LCMPC_vect      (1+112)  // Low Byte Compare C Interrupt 

// TCF0 interrupt vectors 
#define TCF0_CCD_vect      (1+113)  // Compare or Capture D Interrupt 

// TCF2 interrupt vectors 
#define TCF2_LCMPD_vect      (1+113)  // Low Byte Compare D Interrupt 

// TCF1 interrupt vectors 
#define TCF1_OVF_vect      (1+114)  // Overflow Interrupt 
#define TCF1_ERR_vect      (1+115)  // Error Interrupt 
#define TCF1_CCA_vect      (1+116)  // Compare or Capture A Interrupt 
#define TCF1_CCB_vect      (1+117)  // Compare or Capture B Interrupt 

// SPIF interrupt vectors 
#define SPIF_INT_vect      (1+118)  // SPI Interrupt 

// USARTF0 interrupt vectors 
#define USARTF0_RXC_vect      (1+119)  // Reception Complete Interrupt 
#define USARTF0_DRE_vect      (1+120)  // Data Register Empty Interrupt 
#define USARTF0_TXC_vect      (1+121)  // Transmission Complete Interrupt 

// USARTF1 interrupt vectors 
#define USARTF1_RXC_vect      (1+122)  // Reception Complete Interrupt 
#define USARTF1_DRE_vect      (1+123)  // Data Register Empty Interrupt 
#define USARTF1_TXC_vect      (1+124)  // Transmission Complete Interrupt 

// USB interrupt vectors 
#define USB_BUSEVENT_vect      (1+125)  // SOF, suspend, resume, reset bus event interrupts, crc, underflow, overflow and stall error interrupts 
#define USB_TRNCOMPL_vect      (1+126)  // Transaction complete interrupt 

#define _VECTOR_SIZE 4 // Size of individual vector. 
#define _VECTORS_SIZE (127 * _VECTOR_SIZE)


// ========== Constants ========== 

#define PROGMEM_START     (0x0000)
#define PROGMEM_SIZE      (69632)
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#define APP_SECTION_START     (0x0000)
#define APP_SECTION_SIZE      (65536)
#define APP_SECTION_PAGE_SIZE (256)
#define APP_SECTION_END       (APP_SECTION_START + APP_SECTION_SIZE - 1)

#define APPTABLE_SECTION_START     (0xF000)
#define APPTABLE_SECTION_SIZE      (4096)
#define APPTABLE_SECTION_PAGE_SIZE (256)
#define APPTABLE_SECTION_END       (APPTABLE_SECTION_START + APPTABLE_SECTION_SIZE - 1)

#define BOOT_SECTION_START     (0x10000)
#define BOOT_SECTION_SIZE      (4096)
#define BOOT_SECTION_PAGE_SIZE (256)
#define BOOT_SECTION_END       (BOOT_SECTION_START + BOOT_SECTION_SIZE - 1)

#define DATAMEM_START     (0x0000)
#define DATAMEM_SIZE      (16777216)
#define DATAMEM_END       (DATAMEM_START + DATAMEM_SIZE - 1)

#define IO_START     (0x0000)
#define IO_SIZE      (4096)
#define IO_PAGE_SIZE (0)
#define IO_END       (IO_START + IO_SIZE - 1)

#define MAPPED_EEPROM_START     (0x1000)
#define MAPPED_EEPROM_SIZE      (2048)
#define MAPPED_EEPROM_PAGE_SIZE (0)
#define MAPPED_EEPROM_END       (MAPPED_EEPROM_START + MAPPED_EEPROM_SIZE - 1)

#define INTERNAL_SRAM_START     (0x2000)
#define INTERNAL_SRAM_SIZE      (4096)
#define INTERNAL_SRAM_PAGE_SIZE (0)
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#define EEPROM_START     (0x0000)
#define EEPROM_SIZE      (2048)
#define EEPROM_PAGE_SIZE (32)
#define EEPROM_END       (EEPROM_START + EEPROM_SIZE - 1)

#define SIGNATURES_START     (0x0000)
#define SIGNATURES_SIZE      (3)
#define SIGNATURES_PAGE_SIZE (0)
#define SIGNATURES_END       (SIGNATURES_START + SIGNATURES_SIZE - 1)

#define FUSES_START     (0x0000)
#define FUSES_SIZE      (6)
#define FUSES_PAGE_SIZE (0)
#define FUSES_END       (FUSES_START + FUSES_SIZE - 1)

#define LOCKBITS_START     (0x0000)
#define LOCKBITS_SIZE      (1)
#define LOCKBITS_PAGE_SIZE (0)
#define LOCKBITS_END       (LOCKBITS_START + LOCKBITS_SIZE - 1)

#define USER_SIGNATURES_START     (0x0000)
#define USER_SIGNATURES_SIZE      (256)
#define USER_SIGNATURES_PAGE_SIZE (256)
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#define PROD_SIGNATURES_START     (0x0000)
#define PROD_SIGNATURES_SIZE      (64)
#define PROD_SIGNATURES_PAGE_SIZE (256)
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

#define FLASHSTART   PROGMEM_START
#define FLASHEND     PROGMEM_END
#define SPM_PAGESIZE 256
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END
#define E2END        EEPROM_END
#define E2PAGESIZE   EEPROM_PAGE_SIZE

// ========== Signature ========== 
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x96
#define SIGNATURE_2 0x4E

#endif

