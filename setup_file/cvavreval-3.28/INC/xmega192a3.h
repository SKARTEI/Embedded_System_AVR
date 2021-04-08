// CodeVisionAVR C Compiler V3.0
// (C) 1998-2012 Pavel Haiduc, HP InfoTech S.R.L.

// Peripheral Modules and Interrupt Vector definitions for the ATxmega192A3

#ifndef __XMEGA192A3_INCLUDED__
#define __XMEGA192A3_INCLUDED__

#include <xmstruct.h> // definitions for the Peripheral Module structures
#include <xmbits_a3.h> // bit definitions for the Peripheral Modules registers

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

// Virtual Ports
#define VPORT0 (*(volatile VPORT_t *) 0x0010)
#define VPORT1 (*(volatile VPORT_t *) 0x0014)
#define VPORT2 (*(volatile VPORT_t *) 0x0018)
#define VPORT3 (*(volatile VPORT_t *) 0x001C)

#define OCD (*(volatile OCD_t *) 0x002E) // On Chip Debug System
#define CLK (*(volatile CLK_t *) 0x0040) // Clock System
#define SLEEP (*(volatile SLEEP_t *) 0x0048) // Sleep Controller
#define OSC (*(volatile OSC_t *) 0x0050) // Oscillator Control
#define DFLLRC32M (*(volatile DFLL_t *) 0x0060) // DFLL for 32MHz RC Oscillator
#define DFLLRC2M (*(volatile DFLL_t *) 0x0068) // DFLL for 2MHz RC Oscillator
#define PR (*(volatile PR_t *) 0x0070) // Power Reduction
#define RST (*(volatile RST_t *) 0x0078) // Reset Controller
#define WDT (*(volatile WDT_t *) 0x0080) // Watch Dog Timer
#define MCU (*(volatile MCU_t *) 0x0090) // MCU Control
#define PMIC (*(volatile PMIC_t *) 0x00A0) // Programmable Interrupt Controller
#define AES	(*(volatile AES_t *) 0x00C0)		// AES Crypto Module
#define DMA (*(volatile DMA_t *) 0x0100) // DMA Controller
#define EVSYS (*(volatile EVSYS_t *) 0x0180) // Event System
#define NVM (*(volatile NVM_t *) 0x01C0) // Non Volatile Memory Controller

// Analog Comparator
#define ACA (*(volatile AC_t *) 0x0380) // Analog Comparator A
#define ACB (*(volatile AC_t *) 0x0390) // Analog Comparator B

// ADC
#define ADCA (*(volatile ADC_t *) 0x0200) // ADC A
#define ADCB (*(volatile ADC_t *) 0x0240) // ADC B

// DAC
// 25112009_1
#define DACB (*(volatile DAC_t *) 0x0320) // DAC B

// RTC
#define RTC (*(volatile RTC_t *) 0x0400) // Real Time Counter

// TWI
#define TWIC (*(volatile TWI_t *) 0x0480) // Two Wire Interface C
#define TWIE (*(volatile TWI_t *) 0x04A0) // Two Wire Interface E

// I/O Ports
#define PORTCFG (*(volatile PORTCFG_t *) 0x00B0) // Port Configuration
#define PORTA (*(volatile PORT_t *) 0x0600)
#define PORTB (*(volatile PORT_t *) 0x0620)
#define PORTC (*(volatile PORT_t *) 0x0640)
#define PORTD (*(volatile PORT_t *) 0x0660)
#define PORTE (*(volatile PORT_t *) 0x0680)
#define PORTF (*(volatile PORT_t *) 0x06A0)
#define PORTR (*(volatile PORT_t *) 0x07E0)

// Timer/Counters
#define TCC0 (*(volatile TC0_t *) 0x0800) // Timer/Counter C0
#define TCC1 (*(volatile TC1_t *) 0x0840) // Timer/Counter C1
#define AWEXC (*(volatile AWEX_t *) 0x0880) // Advanced Waveform Extension C
#define HIRESC (*(volatile HIRES_t *) 0x0890) // High Resolution Extension C

#define TCD0 (*(volatile TC0_t *) 0x0900) // Timer/Counter D0
#define TCD1 (*(volatile TC1_t *) 0x0940) // Timer/Counter D1
#define HIRESD (*(volatile HIRES_t *) 0x0990) // High Resolution Extension D

#define TCE0 (*(volatile TC0_t *) 0x0A00) // Timer/Counter E0
#define TCE1 (*(volatile TC1_t *) 0x0A40) // Timer/Counter E1
#define AWEXE (*(volatile AWEX_t *) 0x0A80) // Advanced Waveform Extension E
#define HIRESE (*(volatile HIRES_t *) 0x0A90) // High Resolution Extension E

#define TCF0 (*(volatile TC0_t *) 0x0B00) // Timer/Counter F0
#define HIRESF (*(volatile HIRES_t *) 0x0B90) // High Resolution Extension F

// USART
#define USARTC0 (*(volatile USART_t *) 0x08A0) // USART C0
#define USARTC1 (*(volatile USART_t *) 0x08B0) // USART C1
#define USARTD0 (*(volatile USART_t *) 0x09A0) // USART D0
#define USARTD1 (*(volatile USART_t *) 0x09B0) // USART D1
#define USARTE0 (*(volatile USART_t *) 0x0AA0) // USART E0
#define USARTE1 (*(volatile USART_t *) 0x0AB0) // USART E1
#define USARTF0 (*(volatile USART_t *) 0x0BA0) // USART F0

// SPI
// 30112009_1
#define SPIC (*(volatile SPI_t *) 0x08C0) // SPI C
#define SPID (*(volatile SPI_t *) 0x09C0) // SPI D
#define SPIE (*(volatile SPI_t *) 0x0AC0) // SPI E

// IRCOM
#define IRCOM (*(volatile IRCOM_t *) 0x08F8) // Infra Red Communication Module

// Interrupt Vectors
// Reset
#define RESET_vect 1

// OSC
#define OSC_XOSCF_vect 2 // External Oscillator Failure Interrupt

// PORTC
#define PORTC_INT0_vect 3 // External Interrupt 0
#define PORTC_INT1_vect 4 // External Interrupt 1

// PORTR
#define PORTR_INT0_vect 5 // External Interrupt 0
#define PORTR_INT1_vect 6 // External Interrupt 1

// DMA
#define DMA_CH0_vect 7 // Channel 0 Interrupt
#define DMA_CH1_vect 8 // Channel 1 Interrupt
#define DMA_CH2_vect 9 // Channel 2 Interrupt
#define DMA_CH3_vect 10 // Channel 3 Interrupt

// RTC
#define RTC_OVF_vect 11 // Overflow Interrupt
#define RTC_COMP_vect 12 // Compare Interrupt

// TWI C
#define TWIC_TWIS_vect 13 // TWI Slave Interrupt
#define TWIC_TWIM_vect 14 // TWI Master Interrupt

// Timer/Counter C0
#define TCC0_OVF_vect 15 // Overflow Interrupt
#define TCC0_ERR_vect 16 // Error Interrupt
#define TCC0_CCA_vect 17 // Compare or Capture A Interrupt
#define TCC0_CCB_vect 18 // Compare or Capture B Interrupt
#define TCC0_CCC_vect 19 // Compare or Capture C Interrupt
#define TCC0_CCD_vect 20 // Compare or Capture D Interrupt

// Timer/Counter C1
#define TCC1_OVF_vect 21 // Overflow Interrupt
#define TCC1_ERR_vect 22 // Error Interrupt
#define TCC1_CCA_vect 23 // Compare or Capture A Interrupt
#define TCC1_CCB_vect 24 // Compare or Capture B Interrupt

// SPI C
#define SPIC_INT_vect 25 // SPI Interrupt

// USART C0
#define USARTC0_RXC_vect 26 // Reception Complete Interrupt
#define USARTC0_DRE_vect 27 // Data Register Empty Interrupt
#define USARTC0_TXC_vect 28 // Transmission Complete Interrupt

// USART C1
#define USARTC1_RXC_vect 29 // Reception Complete Interrupt
#define USARTC1_DRE_vect 30 // Data Register Empty Interrupt
#define USARTC1_TXC_vect 31 // Transmission Complete Interrupt

// AES
#define AES_INT_vect 32 // AES Interrupt

// NVM
#define NVM_EE_vect 33 // EE Interrupt
#define NVM_SPM_vect 34 // SPM Interrupt

// PORTB
#define PORTB_INT0_vect 35 // External Interrupt 0
#define PORTB_INT1_vect 36 // External Interrupt 1

// Analog Comparator on PORTB
#define ACB_AC0_vect 37 // AC0 Interrupt
#define ACB_AC1_vect 38 // AC1 Interrupt
#define ACB_ACW_vect 39 // ACW Window Mode Interrupt

// ADC B
#define ADCB_CH0_vect 40 // Interrupt 0
#define ADCB_CH1_vect 41 // Interrupt 1
#define ADCB_CH2_vect 42 // Interrupt 2
#define ADCB_CH3_vect 43 // Interrupt 3

// PORTE
#define PORTE_INT0_vect 44 // External Interrupt 0
#define PORTE_INT1_vect 45 // External Interrupt 1

// TWI E
#define TWIE_TWIS_vect 46 // TWI Slave Interrupt
#define TWIE_TWIM_vect 47 // TWI Master Interrupt

// Timer/Counter E0
#define TCE0_OVF_vect 48 // Overflow Interrupt
#define TCE0_ERR_vect 49 // Error Interrupt
#define TCE0_CCA_vect 50 // Compare or Capture A Interrupt
#define TCE0_CCB_vect 51 // Compare or Capture B Interrupt
#define TCE0_CCC_vect 52 // Compare or Capture C Interrupt
#define TCE0_CCD_vect 53 // Compare or Capture D Interrupt

// Timer/Counter E1
#define TCE1_OVF_vect 54 // Overflow Interrupt
#define TCE1_ERR_vect 55 // Error Interrupt
#define TCE1_CCA_vect 56 // Compare or Capture A Interrupt
#define TCE1_CCB_vect 57 // Compare or Capture B Interrupt

// SPI E
#define SPIE_INT_vect 58 // SPI Interrupt

// USART E0
#define USARTE0_RXC_vect 59 // Reception Complete Interrupt
#define USARTE0_DRE_vect 60 // Data Register Empty Interrupt
#define USARTE0_TXC_vect 61 // Transmission Complete Interrupt

// USART E1
#define USARTE1_RXC_vect 62 // Reception Complete Interrupt
#define USARTE1_DRE_vect 63 // Data Register Empty Interrupt
#define USARTE1_TXC_vect 64 // Transmission Complete Interrupt

// PORTD
#define PORTD_INT0_vect 65 // External Interrupt 0
#define PORTD_INT1_vect 66 // External Interrupt 1

// PORTA
#define PORTA_INT0_vect 67 // External Interrupt 0
#define PORTA_INT1_vect 68 // External Interrupt 1

// Analog Comparator on PORTA
#define ACA_AC0_vect 69 // AC0 Interrupt
#define ACA_AC1_vect 70 // AC1 Interrupt
#define ACA_ACW_vect 71 // ACW Window Mode Interrupt

// ADC A
#define ADCA_CH0_vect 72 // Interrupt 0
#define ADCA_CH1_vect 73 // Interrupt 1
#define ADCA_CH2_vect 74 // Interrupt 2
#define ADCA_CH3_vect 75 // Interrupt 3

// Timer/Counter D0
#define TCD0_OVF_vect 78 // Overflow Interrupt
#define TCD0_ERR_vect 79 // Error Interrupt
#define TCD0_CCA_vect 80 // Compare or Capture A Interrupt
#define TCD0_CCB_vect 81 // Compare or Capture B Interrupt
#define TCD0_CCC_vect 82 // Compare or Capture C Interrupt
#define TCD0_CCD_vect 83 // Compare or Capture D Interrupt

// Timer/Counter D1
#define TCD1_OVF_vect 84 // Overflow Interrupt
#define TCD1_ERR_vect 85 // Error Interrupt
#define TCD1_CCA_vect 86 // Compare or Capture A Interrupt
#define TCD1_CCB_vect 87 // Compare or Capture B Interrupt

// SPI D
#define SPID_INT_vect 88 // SPI Interrupt

// USART D0
#define USARTD0_RXC_vect 89 // Reception Complete Interrupt
#define USARTD0_DRE_vect 90 // Data Register Empty Interrupt
#define USARTD0_TXC_vect 91 // Transmission Complete Interrupt

// USART D1
#define USARTD1_RXC_vect 92 // Reception Complete Interrupt
#define USARTD1_DRE_vect 93 // Data Register Empty Interrupt
#define USARTD1_TXC_vect 94 // Transmission Complete Interrupt

// PORTF
#define PORTF_INT0_vect 105 // External Interrupt 0
#define PORTF_INT1_vect 106 // External Interrupt 1

// Timer/Counter F0
#define TCF0_OVF_vect 109 // Overflow Interrupt
#define TCF0_ERR_vect 110 // Error Interrupt
#define TCF0_CCA_vect 111 // Compare or Capture A Interrupt
#define TCF0_CCB_vect 112 // Compare or Capture B Interrupt
#define TCF0_CCC_vect 113 // Compare or Capture C Interrupt
#define TCF0_CCD_vect 114 // Compare or Capture D Interrupt

// USART F0
#define USARTF0_RXC_vect 120 // Reception Complete Interrupt
#define USARTF0_DRE_vect 121 // Data Register Empty Interrupt
#define USARTF0_TXC_vect 122 // Transmission Complete Interrupt

#define _VECTOR_SIZE 4 /* Size of individual vector. */
#define _VECTORS_SIZE (122 * _VECTOR_SIZE)


/* ========== Constants ========== */

#define PROGMEM_START     (0x0000)
#define PROGMEM_SIZE      (204800)
#define PROGMEM_PAGE_SIZE (512)
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#define APP_SECTION_START     (0x0000)
#define APP_SECTION_SIZE      (196608)
#define APP_SECTION_PAGE_SIZE (512)
#define APP_SECTION_END       (APP_SECTION_START + APP_SECTION_SIZE - 1)

#define APPTABLE_SECTION_START     (0x2E000)
#define APPTABLE_SECTION_SIZE      (8192)
#define APPTABLE_SECTION_PAGE_SIZE (512)
#define APPTABLE_SECTION_END       (APPTABLE_SECTION_START + APPTABLE_SECTION_SIZE - 1)

#define BOOT_SECTION_START     (0x30000)
#define BOOT_SECTION_SIZE      (8192)
#define BOOT_SECTION_PAGE_SIZE (512)
#define BOOT_SECTION_END       (BOOT_SECTION_START + BOOT_SECTION_SIZE - 1)

#define DATAMEM_START     (0x0000)
#define DATAMEM_SIZE      (16777216)
#define DATAMEM_PAGE_SIZE (0)
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
#define INTERNAL_SRAM_SIZE      (16384)
#define INTERNAL_SRAM_PAGE_SIZE (0)
#define INTERNAL_SRAM_END       (INTERNAL_SRAM_START + INTERNAL_SRAM_SIZE - 1)

#define EEPROM_START     (0x0000)
#define EEPROM_SIZE      (2048)
#define EEPROM_PAGE_SIZE (32)
#define EEPROM_END       (EEPROM_START + EEPROM_SIZE - 1)

#define FUSE_START     (0x0000)
#define FUSE_SIZE      (6)
#define FUSE_PAGE_SIZE (0)
#define FUSE_END       (FUSE_START + FUSE_SIZE - 1)

#define LOCKBIT_START     (0x0000)
#define LOCKBIT_SIZE      (1)
#define LOCKBIT_PAGE_SIZE (0)
#define LOCKBIT_END       (LOCKBIT_START + LOCKBIT_SIZE - 1)

#define SIGNATURES_START     (0x0000)
#define SIGNATURES_SIZE      (3)
#define SIGNATURES_PAGE_SIZE (0)
#define SIGNATURES_END       (SIGNATURES_START + SIGNATURES_SIZE - 1)

#define USER_SIGNATURES_START     (0x0000)
#define USER_SIGNATURES_SIZE      (512)
#define USER_SIGNATURES_PAGE_SIZE (0)
#define USER_SIGNATURES_END       (USER_SIGNATURES_START + USER_SIGNATURES_SIZE - 1)

#define PROD_SIGNATURES_START     (0x0000)
#define PROD_SIGNATURES_SIZE      (52)
#define PROD_SIGNATURES_PAGE_SIZE (0)
#define PROD_SIGNATURES_END       (PROD_SIGNATURES_START + PROD_SIGNATURES_SIZE - 1)

#define FLASHEND     PROGMEM_END
#define SPM_PAGESIZE PROGMEM_PAGE_SIZE
#define RAMSTART     INTERNAL_SRAM_START
#define RAMSIZE      INTERNAL_SRAM_SIZE
#define RAMEND       INTERNAL_SRAM_END
#define XRAMSTART    EXTERNAL_SRAM_START
#define XRAMSIZE     EXTERNAL_SRAM_SIZE
#define XRAMEND      INTERNAL_SRAM_END
#define E2END        EEPROM_END
#define E2PAGESIZE   EEPROM_PAGE_SIZE

/* ========== Signature ========== */
#define SIGNATURE_0 0x1E
#define SIGNATURE_1 0x97
#define SIGNATURE_2 0x44

#endif
