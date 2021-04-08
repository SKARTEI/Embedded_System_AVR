// CodeVisionAVR C Compiler V2
// (C) 1998-2009 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATA6285 chip

#ifndef _ATA6285_INCLUDED_
#define _ATA6285_INCLUDED_

/* ***** I/O REGISTER DEFINITIONS ***************************************** */
#define    LFCALH          (*(unsigned char *) 0x87)
#define    LFCALL          (*(unsigned char *) 0x86)
#define    LFIDCH          (*(unsigned char *) 0x85)
#define    LFIDCL          (*(unsigned char *) 0x84)
#define    LFHCR           (*(unsigned char *) 0x83)
#define    LFRCR           (*(unsigned char *) 0x82)
#define    LFIMR           (*(unsigned char *) 0x81)
#define    T3IMR           (*(unsigned char *) 0x7f)
#define    T3CRB           (*(unsigned char *) 0x7e)
#define    T3MRB           (*(unsigned char *) 0x7d)
#define    T3MRA           (*(unsigned char *) 0x7c)
#define    T3CORBH         (*(unsigned char *) 0x7b)
#define    T3CORBL         (*(unsigned char *) 0x7a)
#define    T3CORAH         (*(unsigned char *) 0x79)
#define    T3CORAL         (*(unsigned char *) 0x78)
#define    T3ICRH          (*(unsigned char *) 0x77)
#define    T3ICRL          (*(unsigned char *) 0x76)
#define    T2IMR           (*(unsigned char *) 0x74)
#define    T2MRB           (*(unsigned char *) 0x73)
#define    T2MRA           (*(unsigned char *) 0x72)
#define    T2CORH          (*(unsigned char *) 0x71)
#define    T2CORL          (*(unsigned char *) 0x70)
#define    T2ICRH          (*(unsigned char *) 0x6f)
#define    T2ICRL          (*(unsigned char *) 0x6e)
#define    PCMSK2          (*(unsigned char *) 0x6c)
#define    PCMSK1          (*(unsigned char *) 0x6b)
#define    PCMSK0          (*(unsigned char *) 0x6a)
#define    EICRA           (*(unsigned char *) 0x69)
#define    BGCAL           (*(unsigned char *) 0x68)
#define    MSVCAL          (*(unsigned char *) 0x67)
#define    FRCCAL          (*(unsigned char *) 0x66)
#define    SRCCAL          (*(unsigned char *) 0x65)
#define    TSCR            (*(unsigned char *) 0x64)
#define    SIMSK           (*(unsigned char *) 0x61)
#define    WDTCR           (*(unsigned char *) 0x60)

sfrb SREG=0x3f;
sfrb SPL=0x3d;
sfrb SPH=0x3e;
sfrb CLKPR=0x3c;
sfrb CMIMR=0x3b;
sfrb T0CR=0x39;
sfrb T1CR=0x38;
sfrb SPMCSR=0x37;
sfrb LFRB=0x36;
sfrb MCUCR=0x35;
sfrb MCUSR=0x34;
sfrb SMCR=0x33;
sfrb LFCDR=0x32;
sfrb LFRR=0x30;
sfrb T2MDR=0x2f;
sfrb SPDR=0x2e;
sfrb SPSR=0x2d;
sfrb SPCR=0x2c;
sfrb GPIOR2=0x2b;
sfrb GPIOR1=0x2a;
sfrb SCCR=0x29;
sfrb SCR=0x28;
sfrb SVCR=0x27;
sfrb EIMSK=0x24;
sfrb PCICR=0x23;
sfrb EEARH=0x22;
sfrb EEARL=0x21;
sfrb EEDR=0x20;
sfrb EECR=0x1f;
sfrb GPIOR0=0x1e;
sfrb EIFR=0x1d;
sfrb T3IFR=0x1c;
sfrb T2IFR=0x1b;
sfrb T10IFR=0x1a;
sfrb SSFR=0x19;
sfrb LFFR=0x18;
sfrb PCIFR=0x17;
sfrb VMCSR=0x16;
sfrb T3CRA=0x14;
sfrb T2CRB=0x12;
sfrb T2CRA=0x11;
sfrb CMSR=0x10;
sfrb CMCR=0x0f;
sfrb PORTD=0x0b;
sfrb DDRD=0x0a;
sfrb PIND=0x09;
sfrb PORTC=0x08;
sfrb DDRC=0x07;
sfrb PINC=0x06;
sfrb PORTB=0x05;
sfrb DDRB=0x04;
sfrb PINB=0x03;

/* ***** INTERRUPT VECTORS ************************************************ */
#define    INT_ExtInterrupt0    2  // External Interrupt Request 0
#define    INT_ExtInterrupt1    3  // External Interrupt Request 1
#define    INT_PinChange0       4  // Pin Change Interrupt Request 0
#define    INT_PinChange1       5  // Pin Change Interrupt Request 1
#define    INT_PinChange2       6  // Pin Change Interrupt Request 2
#define    INT_ExtInterrupt     7  // Voltage Monitor Interrupt
#define    INT_SENINT           8  // Sensor Interface Interrupt
#define    INT_T0               9  // Timer0 Interval Interrupt
#define    INT_LFWP             10  // LF-Receiver Wake-up Interrupt
#define    INT_T3CAP            11  // Timer/Counter3 Capture Event
#define    INT_T3COMA           12  // Timer/Counter3 Compare Match A
#define    INT_T3COMB           13  // Timer/Counter3 Compare Match B
#define    INT_T3OVF            14  // Timer/Counter3 Overflow
#define    INT_T2CAP            15  // Timer/Counter2 Capture Event
#define    INT_T2COM            16  // Timer/Counter2 Compare Match
#define    INT_T2OVF            17  // Timer/Counter2 Overflow
#define    INT_SPI_STC          18  // SPI Serial Transfer Complete
#define    INT_LFRXB            19  // LF Receive Buffer Interrupt
#define    INT_T1               20  // Timer1 Interval Interrupt
#define    INT_T2RXB            21  // Timer2 SSI Receive Buffer Interrupt
#define    INT_T2TXB            22  // Timer2 SSI Transmit Buffer Interrupt
#define    INT_T2TXC            23  // Timer2 SSI Transmit Complete Interrupt
#define    INT_LFREOB           24  // LF-Receiver End of Burst Interrupt
#define    INT_EXCM             25  // External Input Clock break down Interrupt
#define    INT_EEPROMready      26  // EEPROM Ready Interrupt
#define    INT_SPMready         27  // Store Program Memory Ready

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x01
	.EQU __sm_mask=0x0E
	.EQU __sm_powerdown=0x04
	.SET power_ctrl_reg=smcr
	#endif
#endasm

#ifdef _IO_BITS_DEFINITIONS_
#include <ata6289_bits.h>
#endif

#endif
