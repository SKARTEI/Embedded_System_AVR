// CodeVisionAVR C Compiler V3.11+
// (C) 1998-2014 Pavel Haiduc, HP InfoTech S.R.L.

// Peripheral Modules and Interrupt Vector definitions for the ATxmega32E5

#ifndef __XMEGA32E5_INCLUDED__
#define __XMEGA32E5_INCLUDED__

#include <xmstruct.h> // definitions for the Peripheral Module structures
#include <xmbits_e5.h> // bit definitions for the Peripheral Modules registers

// General Purpose I/O Registers
sfrb GPIO0=0x00;
sfrb GPIO1=0x01;
sfrb GPIO2=0x02;
sfrb GPIO3=0x03;
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
#define PR    (*(volatile PR_t *) 0x0070)  // Power Reduction 
#define RST    (*(volatile RST_t *) 0x0078)  // Reset 
#define WDT    (*(volatile WDT_t *) 0x0080)  // Watch-Dog Timer 
#define MCU    (*(volatile MCU_t *) 0x0090)  // MCU Control 
#define PMIC    (*(volatile PMIC_t *) 0x00A0)  // Programmable Multi-level Interrupt Controller 
#define PORTCFG    (*(volatile PORTCFG_t *) 0x00B0)  // I/O port Configuration 
#define CRC    (*(volatile CRC_t *) 0x00D0)  // Cyclic Redundancy Checker 
#define EDMA    (*(volatile EDMA_t *) 0x0100)  // Enhanced DMA Controller 
#define EVSYS    (*(volatile EVSYS_t *) 0x0180)  // Event System 
#define NVM    (*(volatile NVM_t *) 0x01C0)  // Non-volatile Memory Controller 
#define ADCA    (*(volatile ADC_t *) 0x0200)  // Analog-to-Digital Converter 
#define DACA    (*(volatile DAC_t *) 0x0300)  // Digital-to-Analog Converter 
#define ACA    (*(volatile AC_t *) 0x0380)  // Analog Comparator 
#define RTC    (*(volatile RTC_t *) 0x0400)  // Real-Time Counter 
#define XCL    (*(volatile XCL_t *) 0x0460)  // XMEGA Custom Logic 
#define TWIC    (*(volatile TWI_t *) 0x0480)  // Two-Wire Interface 
#define PORTA    (*(volatile PORT_t *) 0x0600)  // I/O Ports 
#define PORTC    (*(volatile PORT_t *) 0x0640)  // I/O Ports 
#define PORTD    (*(volatile PORT_t *) 0x0660)  // I/O Ports 
#define PORTR    (*(volatile PORT_t *) 0x07E0)  // I/O Ports 
#define TCC4    (*(volatile TC4_t *) 0x0800)  // 16-bit Timer/Counter 4 
#define TCC5    (*(volatile TC5_t *) 0x0840)  // 16-bit Timer/Counter 5 
#define FAULTC4    (*(volatile FAULT_t *) 0x0880)  // Fault Extension 
#define FAULTC5    (*(volatile FAULT_t *) 0x0890)  // Fault Extension 
#define WEXC    (*(volatile WEX_t *) 0x08A0)  // Waveform Extension 
#define HIRESC    (*(volatile HIRES_t *) 0x08B0)  // High-Resolution Extension 
#define USARTC0    (*(volatile USART_t *) 0x08C0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define SPIC    (*(volatile SPI_t *) 0x08E0)  // Serial Peripheral Interface with Buffer Modes 
#define IRCOM    (*(volatile IRCOM_t *) 0x08F8)  // IR Communication Module 
#define TCD5    (*(volatile TC5_t *) 0x0940)  // 16-bit Timer/Counter 5 
#define USARTD0    (*(volatile USART_t *) 0x09C0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 

// ========== Interrupt Vector Definitions ========== 
// Reset
#define RESET_vect (0+1)

// OSC interrupt vectors 
#define OSC_OSCF_vect      (1+1)  // Oscillator Failure Interrupt (NMI+1) 

// PORTR interrupt vectors 
#define PORTR_INT_vect      (2+1)  // External Interrupt 

// EDMA interrupt vectors 
#define EDMA_CH0_vect      (3+1)  // EDMA Channel 0 Interrupt 
#define EDMA_CH1_vect      (4+1)  // EDMA Channel 1 Interrupt 
#define EDMA_CH2_vect      (5+1)  // EDMA Channel 2 Interrupt 
#define EDMA_CH3_vect      (6+1)  // EDMA Channel 3 Interrupt 

// RTC interrupt vectors 
#define RTC_OVF_vect      (7+1)  // Overflow Interrupt 
#define RTC_COMP_vect      (8+1)  // Compare Interrupt 

// PORTC interrupt vectors 
#define PORTC_INT_vect      (9+1)  // External Interrupt 

// TWIC interrupt vectors 
#define TWIC_TWIS_vect      (10+1)  // TWI Slave Interrupt 
#define TWIC_TWIM_vect      (11+1)  // TWI Master Interrupt 

// TCC4 interrupt vectors 
#define TCC4_OVF_vect      (12+1)  // Overflow Interrupt 
#define TCC4_ERR_vect      (13+1)  // Error Interrupt 
#define TCC4_CCA_vect      (14+1)  // Channel A Compare or Capture Interrupt 
#define TCC4_CCB_vect      (15+1)  // Channel B Compare or Capture Interrupt 
#define TCC4_CCC_vect      (16+1)  // Channel C Compare or Capture Interrupt 
#define TCC4_CCD_vect      (17+1)  // Channel D Compare or Capture Interrupt 

// TCC5 interrupt vectors 
#define TCC5_OVF_vect      (18+1)  // Overflow Interrupt 
#define TCC5_ERR_vect      (19+1)  // Error Interrupt 
#define TCC5_CCA_vect      (20+1)  // Channel A Compare or Capture Interrupt 
#define TCC5_CCB_vect      (21+1)  // Channel B Compare or Capture Interrupt 

// SPIC interrupt vectors 
#define SPIC_INT_vect      (22+1)  // SPI Interrupt 

// USARTC0 interrupt vectors 
#define USARTC0_RXC_vect      (23+1)  // Reception Complete Interrupt 
#define USARTC0_DRE_vect      (24+1)  // Data Register Empty Interrupt 
#define USARTC0_TXC_vect      (25+1)  // Transmission Complete Interrupt 

// NVM interrupt vectors 
#define NVM_EE_vect      (26+1)  // EE Interrupt 
#define NVM_SPM_vect      (27+1)  // SPM Interrupt 

// XCL interrupt vectors 
#define XCL_UNF_vect      (28+1)  // Timer/Counter Underflow Interrupt 
#define XCL_CC_vect      (29+1)  // Timer/Counter Compare or Capture Interrupt 

// PORTA interrupt vectors 
#define PORTA_INT_vect      (30+1)  // External Interrupt 

// ACA interrupt vectors 
#define ACA_AC0_vect      (31+1)  // AC0 Interrupt 
#define ACA_AC1_vect      (32+1)  // AC1 Interrupt 
#define ACA_ACW_vect      (33+1)  // ACW Window Mode Interrupt 

// ADCA interrupt vectors 
#define ADCA_CH0_vect      (34+1)  // ADC Channel Interrupt 

// PORTD interrupt vectors 
#define PORTD_INT_vect      (35+1)  // External Interrupt 

// TCD5 interrupt vectors 
#define TCD5_OVF_vect      (36+1)  // Overflow Interrupt 
#define TCD5_ERR_vect      (37+1)  // Error Interrupt 
#define TCD5_CCA_vect      (38+1)  // Channel A Compare or Capture Interrupt 
#define TCD5_CCB_vect      (39+1)  // Channel B Compare or Capture Interrupt 

// USARTD0 interrupt vectors 
#define USARTD0_RXC_vect      (40+1)  // Reception Complete Interrupt 
#define USARTD0_DRE_vect      (41+1)  // Data Register Empty Interrupt 
#define USARTD0_TXC_vect      (42+1)  // Transmission Complete Interrupt 

#define _VECTOR_SIZE 4 // Size of individual vector. 
#define _VECTORS_SIZE (43 * _VECTOR_SIZE)


// ========== Constants ========== 

#define PROGMEM_START     (0x0000)
#define PROGMEM_SIZE      (36864)
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#define APP_SECTION_START     (0x0000)
#define APP_SECTION_SIZE      (32768)
#define APP_SECTION_PAGE_SIZE (128)
#define APP_SECTION_END       (APP_SECTION_START + APP_SECTION_SIZE - 1)

#define APPTABLE_SECTION_START     (0x7000)
#define APPTABLE_SECTION_SIZE      (4096)
#define APPTABLE_SECTION_PAGE_SIZE (128)
#define APPTABLE_SECTION_END       (APPTABLE_SECTION_START + APPTABLE_SECTION_SIZE - 1)

#define BOOT_SECTION_START     (0x8000)
#define BOOT_SECTION_SIZE      (4096)
#define BOOT_SECTION_PAGE_SIZE (128)
#define BOOT_SECTION_END       (BOOT_SECTION_START + BOOT_SECTION_SIZE - 1)

#define DATAMEM_START     (0x0000)
#define DATAMEM_SIZE      (12288)
#define DATAMEM_END       (DATAMEM_START + DATAMEM_SIZE - 1)

#define IO_START     (0x0000)
#define IO_SIZE      (4096)
#define IO_PAGE_SIZE (0)
#define IO_END       (IO_START + IO_SIZE - 1)

#define MAPPED_EEPROM_START     (0x1000)
#define MAPPED_EEPROM_SIZE      (1024)
#define MAPPED_EEPROM_PAGE_SIZE (0)
#define MAPPED_EEPROM_END       (MAPPED_EEPROM_START + MAPPED_EEPROM_SIZE - 1)

#define INTERNAL_SRAM_START     (0x2000)
#define INTERNAL_SRAM_SIZE      (4096)
#define INTERNAL_SRAM_PAGE_SIZE (0)
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#define EEPROM_START     (0x0000)
#define EEPROM_SIZE      (1024)
#define EEPROM_PAGE_SIZE (32)
#define EEPROM_END       (EEPROM_START + EEPROM_SIZE - 1)

#define SIGNATURES_START     (0x0000)
#define SIGNATURES_SIZE      (3)
#define SIGNATURES_PAGE_SIZE (0)
#define SIGNATURES_END       (SIGNATURES_START + SIGNATURES_SIZE - 1)

#define FUSES_START     (0x0000)
#define FUSES_SIZE      (7)
#define FUSES_PAGE_SIZE (0)
#define FUSES_END       (FUSES_START + FUSES_SIZE - 1)

#define LOCKBITS_START     (0x0000)
#define LOCKBITS_SIZE      (1)
#define LOCKBITS_PAGE_SIZE (0)
#define LOCKBITS_END       (LOCKBITS_START + LOCKBITS_SIZE - 1)

#define USER_SIGNATURES_START     (0x0000)
#define USER_SIGNATURES_SIZE      (128)
#define USER_SIGNATURES_PAGE_SIZE (128)
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#define PROD_SIGNATURES_START     (0x0000)
#define PROD_SIGNATURES_SIZE      (52)
#define PROD_SIGNATURES_PAGE_SIZE (128)
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

#define FLASHSTART   PROGMEM_START
#define FLASHEND     PROGMEM_END
#define SPM_PAGESIZE 128
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END
#define E2END        EEPROM_END
#define E2PAGESIZE   EEPROM_PAGE_SIZE

// ========== Signature ========== 
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x95
#define SIGNATURE_2 0x4C

#endif
