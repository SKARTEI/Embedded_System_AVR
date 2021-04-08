// CodeVisionAVR C Compiler V3.11+
// (C) 1998-2014 Pavel Haiduc, HP InfoTech S.R.L.

// Peripheral Modules and Interrupt Vector definitions for the ATxmega128B3

#ifndef __XMEGA128B3_INCLUDED__
#define __XMEGA128B3_INCLUDED__

#define __CRC_EXISTS__
#define __USB_EXISTS__

#include <xmstruct.h> // definitions for the Peripheral Module structures
#include <xmbits_b3.h> // bit definitions for the Peripheral Modules registers

// General Purpose I/O Registers
sfrb GPIO0=0x00;
sfrb GPIO1=0x01;
sfrb GPIO2=0x02;
sfrb GPIO3=0x03;

sfrb GPIOR0=0x00;
sfrb GPIOR1=0x01;
sfrb GPIOR2=0x02;
sfrb GPIOR3=0x03;

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
#define ADCB    (*(volatile ADC_t *) 0x0240)  // Analog-to-Digital Converter 
#define ACB    (*(volatile AC_t *) 0x0390)  // Analog Comparator 
#define RTC    (*(volatile RTC_t *) 0x0400)  // Real-Time Counter 
#define TWIC    (*(volatile TWI_t *) 0x0480)  // Two-Wire Interface 
#define USB    (*(volatile USB_t *) 0x04C0)  // Universal Serial Bus 
#define PORTB    (*(volatile PORT_t *) 0x0620)  // I/O Ports 
#define PORTC    (*(volatile PORT_t *) 0x0640)  // I/O Ports 
#define PORTD    (*(volatile PORT_t *) 0x0660)  // I/O Ports 
#define PORTG    (*(volatile PORT_t *) 0x06C0)  // I/O Ports 
#define PORTM    (*(volatile PORT_t *) 0x0760)  // I/O Ports 
#define PORTR    (*(volatile PORT_t *) 0x07E0)  // I/O Ports 
#define TCC0    (*(volatile TC0_t *) 0x0800)  // 16-bit Timer/Counter 0 
#define TCC1    (*(volatile TC1_t *) 0x0840)  // 16-bit Timer/Counter 1 
#define AWEXC    (*(volatile AWEX_t *) 0x0880)  // Advanced Waveform Extension 
#define HIRESC    (*(volatile HIRES_t *) 0x0890)  // High-Resolution Extension 
#define USARTC0    (*(volatile USART_t *) 0x08A0)  // Universal Synchronous/Asynchronous Receiver/Transmitter 
#define SPIC    (*(volatile SPI_t *) 0x08C0)  // Serial Peripheral Interface 
#define IRCOM    (*(volatile IRCOM_t *) 0x08F8)  // IR Communication Module 
#define LCD    (*(volatile LCD_t *) 0x0D00)  // LCD Controller 

// ========== Interrupt Vector Definitions ========== 
// Reset
#define RESET_vect (0+1)

// OSC interrupt vectors 
#define OSC_OSCF_vect      (1+1)  // Oscillator Failure Interrupt (NMI+1) 

// PORTC interrupt vectors 
#define PORTC_INT0_vect      (2+1)  // External Interrupt 0 
#define PORTC_INT1_vect      (3+1)  // External Interrupt 1 

// PORTR interrupt vectors 
#define PORTR_INT0_vect      (4+1)  // External Interrupt 0 
#define PORTR_INT1_vect      (5+1)  // External Interrupt 1 

// DMA interrupt vectors 
#define DMA_CH0_vect      (6+1)  // Channel 0 Interrupt 
#define DMA_CH1_vect      (7+1)  // Channel 1 Interrupt 

// RTC interrupt vectors 
#define RTC_OVF_vect      (10+1)  // Overflow Interrupt 
#define RTC_COMP_vect      (11+1)  // Compare Interrupt 

// TWIC interrupt vectors 
#define TWIC_TWIS_vect      (12+1)  // TWI Slave Interrupt 
#define TWIC_TWIM_vect      (13+1)  // TWI Master Interrupt 

// TCC0 interrupt vectors 
#define TCC0_OVF_vect      (14+1)  // Overflow Interrupt 
#define TCC0_ERR_vect      (15+1)  // Error Interrupt 
#define TCC0_CCA_vect      (16+1)  // Compare or Capture A Interrupt 
#define TCC0_CCB_vect      (17+1)  // Compare or Capture B Interrupt 
#define TCC0_CCC_vect      (18+1)  // Compare or Capture C Interrupt 
#define TCC0_CCD_vect      (19+1)  // Compare or Capture D Interrupt 

// TCC1 interrupt vectors 
#define TCC1_OVF_vect      (20+1)  // Overflow Interrupt 
#define TCC1_ERR_vect      (21+1)  // Error Interrupt 
#define TCC1_CCA_vect      (22+1)  // Compare or Capture A Interrupt 
#define TCC1_CCB_vect      (23+1)  // Compare or Capture B Interrupt 

// SPIC interrupt vectors 
#define SPIC_INT_vect      (24+1)  // SPI Interrupt 

// USARTC0 interrupt vectors 
#define USARTC0_RXC_vect      (25+1)  // Reception Complete Interrupt 
#define USARTC0_DRE_vect      (26+1)  // Data Register Empty Interrupt 
#define USARTC0_TXC_vect      (27+1)  // Transmission Complete Interrupt 

// USB interrupt vectors 
#define USB_BUSEVENT_vect      (31+1)  // SOF, suspend, resume, reset bus event interrupts, crc, underflow, overflow and stall error interrupts 
#define USB_TRNCOMPL_vect      (32+1)  // Transaction complete interrupt 

// LCD interrupt vectors 
#define LCD_INT_vect      (35+1)  // LCD Interrupt 

// AES interrupt vectors 
#define AES_INT_vect      (36+1)  // AES Interrupt 

// NVM interrupt vectors 
#define NVM_EE_vect      (37+1)  // EE Interrupt 
#define NVM_SPM_vect      (38+1)  // SPM Interrupt 

// PORTB interrupt vectors 
#define PORTB_INT0_vect      (39+1)  // External Interrupt 0 
#define PORTB_INT1_vect      (40+1)  // External Interrupt 1 

// ACB interrupt vectors 
#define ACB_AC0_vect      (41+1)  // AC0 Interrupt 
#define ACB_AC1_vect      (42+1)  // AC1 Interrupt 
#define ACB_ACW_vect      (43+1)  // ACW Window Mode Interrupt 

// ADCB interrupt vectors 
#define ADCB_CH0_vect      (44+1)  // Interrupt 0 

// PORTD interrupt vectors 
#define PORTD_INT0_vect      (48+1)  // External Interrupt 0 
#define PORTD_INT1_vect      (49+1)  // External Interrupt 1 

// PORTG interrupt vectors 
#define PORTG_INT0_vect      (50+1)  // External Interrupt 0 
#define PORTG_INT1_vect      (51+1)  // External Interrupt 1 

// PORTM interrupt vectors 
#define PORTM_INT0_vect      (52+1)  // External Interrupt 0 
#define PORTM_INT1_vect      (53+1)  // External Interrupt 1 

#define _VECTOR_SIZE 4 // Size of individual vector. 
#define _VECTORS_SIZE (54 * _VECTOR_SIZE)


// ========== Constants ========== 

#define PROGMEM_START     (0x0000)
#define PROGMEM_SIZE      (139264)
#define PROGMEM_END       (PROGMEM_START + PROGMEM_SIZE - 1)

#define APP_SECTION_START     (0x0000)
#define APP_SECTION_SIZE      (131072)
#define APP_SECTION_PAGE_SIZE (256)
#define APP_SECTION_END       (APP_SECTION_START + APP_SECTION_SIZE - 1)

#define APPTABLE_SECTION_START     (0x1E000)
#define APPTABLE_SECTION_SIZE      (8192)
#define APPTABLE_SECTION_PAGE_SIZE (256)
#define APPTABLE_SECTION_END       (APPTABLE_SECTION_START + APPTABLE_SECTION_SIZE - 1)

#define BOOT_SECTION_START     (0x20000)
#define BOOT_SECTION_SIZE      (8192)
#define BOOT_SECTION_PAGE_SIZE (256)
#define BOOT_SECTION_END       (BOOT_SECTION_START + BOOT_SECTION_SIZE - 1)

#define DATAMEM_START     (0x0000)
#define DATAMEM_SIZE      (16384)
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
#define INTERNAL_SRAM_SIZE      (8192)
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
#define PROD_SIGNATURES_SIZE      (52)
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
#define SIGNATURE_1 0x97
#define SIGNATURE_2 0x4B

#endif

