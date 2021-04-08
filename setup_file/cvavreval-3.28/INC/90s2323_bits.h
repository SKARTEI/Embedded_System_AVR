/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

AT90S2323 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __90S2323_BITS_INCLUDED__
#define __90S2323_BITS_INCLUDED__

/* ***** CPU ************************** */
/* SREG - Status Register */
#define    SREG_C          0       // Carry Flag
#define    SREG_Z          1       // Zero Flag
#define    SREG_N          2       // Negative Flag
#define    SREG_V          3       // Two's Complement Overflow Flag
#define    SREG_S          4       // Sign Bit
#define    SREG_H          5       // Half Carry Flag
#define    SREG_T          6       // Bit Copy Storage
#define    SREG_I          7       // Global Interrupt Enable

/* SPL - Stack Pointer Low */
#define    SP0             0       // Stack pointer bit 0
#define    SP1             1       // Stack pointer bit 1
#define    SP2             2       // Stack pointer bit 2
#define    SP3             3       // Stack pointer bit 3
#define    SP4             4       // Stack pointer bit 4
#define    SP5             5       // Stack pointer bit 5
#define    SP6             6       // Stack pointer bit 6
#define    SP7             7       // Stack pointer bit 7

/* MCUCR - MCU Control Register */
#define    ISC00           0       // Interrupt Sense Control 0 bit 0
#define    ISC01           1       // Interrupt Sense Control 0 bit 1
#define    SM              4       // Sleep Mode
#define    SE              5       // Sleep Enable

/* MCUSR -  */
#define    PORF            0       // Power On Reset Flag
#define    EXTRF           1       // Externl Reset Flag

/* GIMSK - General Interrupt Mask Register */
#define    INT0            6       // External Interrupt Request 0 Enable

/* GIFR - General Interrupt Flag Register */
#define    INTF0           6       // External Interrupt Flag 0


/* ***** EEPROM *********************** */
/* EEAR - EEPROM Read/Write Access */
#define    EEAR0           0       // EEPROM Read/Write Access bit 0
#define    EEAR1           1       // EEPROM Read/Write Access bit 1
#define    EEAR2           2       // EEPROM Read/Write Access bit 2
#define    EEAR3           3       // EEPROM Read/Write Access bit 3
#define    EEAR4           4       // EEPROM Read/Write Access bit 4
#define    EEAR5           5       // EEPROM Read/Write Access bit 5
#define    EEAR6           6       // EEPROM Read/Write Access bit 6

/* EEDR - EEPROM Data Register */
#define    EEDR0           0       // EEPROM Data Register bit 0
#define    EEDR1           1       // EEPROM Data Register bit 1
#define    EEDR2           2       // EEPROM Data Register bit 2
#define    EEDR3           3       // EEPROM Data Register bit 3
#define    EEDR4           4       // EEPROM Data Register bit 4
#define    EEDR5           5       // EEPROM Data Register bit 5
#define    EEDR6           6       // EEPROM Data Register bit 6
#define    EEDR7           7       // EEPROM Data Register bit 7

/* EECR - EEPROM Control Register */
#define    EERE            0       // EEPROM Read Enable
#define    EEWE            1       // EEPROM Write Enable
#define    EEMWE           2       // EEPROM Master Write Enable


/* ***** WATCHDOG ********************* */
/* WDTCR - Watchdog Timer Control Register */
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDTOE           4       // RW
#define    WDDE            WDTOE   // For compatibility


/* ***** TIMER_COUNTER_0 ************** */
/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TOIE0           1       // Timer/Counter0 Overflow Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag register */
#define    TOV0            1       // Timer/Counter0 Overflow Flag

/* TCCR0 - Timer/Counter0 Control Register */
#define    CS00            0       // Clock Select0 bit 0
#define    CS01            1       // Clock Select0 bit 1
#define    CS02            2       // Clock Select0 bit 2

/* TCNT0 - Timer Counter 0 */
#define    TCNT00          0       // Timer Counter 0 bit 0
#define    TCNT01          1       // Timer Counter 0 bit 1
#define    TCNT02          2       // Timer Counter 0 bit 2
#define    TCNT03          3       // Timer Counter 0 bit 3
#define    TCNT04          4       // Timer Counter 0 bit 4
#define    TCNT05          5       // Timer Counter 0 bit 5
#define    TCNT06          6       // Timer Counter 0 bit 6
#define    TCNT07          7       // Timer Counter 0 bit 7


/* ***** PORTB ************************ */
/* PORTB - Data Register, Port B */
#define    PORTB0          0       // 
#define    PORTB1          1       // 
#define    PORTB2          2       // 

/* DDRB - Data Direction Register, Port B */
#define    DDB0            0       // 
#define    DDB1            1       // 
#define    DDB2            2       // 

/* PINB - Input Pins, Port B */
#define    PINB0           0       // 
#define    PINB1           1       // 
#define    PINB2           2       // 

#endif

