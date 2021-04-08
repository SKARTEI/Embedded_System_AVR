/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2012 Pavel Haiduc, HP InfoTech s.r.l.

AT86RF401 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __86RF401_BITS_INCLUDED__
#define __86RF401_BITS_INCLUDED__

/* ***** RF_CONTROL ******************* */
/* LOCKDET1 - Lock Detector Configuration Register 1 */
#define    CS0             0       // Cycle Slip Counter bit 0
#define    CS1             1       // Cycle Slip Counter bit 1
#define    BOD             2       // Black Out Disable
#define    ENKO            3       // Enable Key On Bit
#define    UPOK            4       // Unlock Conuter Control

/* LOCKDET2 - Lock Detector Configuration register 2 */
#define    LC0             0       // Lock Count bit 0
#define    LC1             1       // Lock Count bit 1
#define    LC2             2       // Lock Count bit 2
#define    ULC0            3       // Unlock Count bit 0
#define    ULC1            4       // Unlock Count bit 1
#define    ULC2            5       // Unlock Count bit 2
#define    LAT             6       // Lock Always True
#define    EUD             7       // Enable Unlock Detect

/* TX_CNTL - Transmit Control Register */
#define    LOC             2       // PLL Lock
#define    TXK             4       // Transmitter Key
#define    TXE             5       // Transmitter Enable
#define    FSK             6       // FSK Mode

/* PWR_ATTEN - Power Attenuation Control Register */
#define    PCF0            0       // Power Control Fine bit 0
#define    PCF1            1       // Power Control Fine bit 1
#define    PCF2            2       // Power Control Fine bit 2
#define    PCC0            3       // Power Control Coarse bit 0
#define    PCC1            4       // Power Control Coarse bit 1
#define    PCC2            5       // Power Control Coarse bit 2

/* VCOTUNE - VCO Tuning Register */
#define    VCOTUNE0        0       // VCO Tuning Register bit 0
#define    VCOTUNE1        1       // VCO Tuning Register bit 1
#define    VCOTUNE2        2       // VCO Tuning Register bit 2
#define    VCOTUNE3        3       // VCO Tuning Register bit 3
#define    VCOTUNE4        4       // VCO Tuning Register bit 4
#define    VCOVDET0        6       // VCO Voltage Detector bit 0
#define    VCOVDET1        7       // VCO Voltage Detector bit 1


/* ***** EEPROM *********************** */
/* DEEAR - EERPOM Address Register */
#define    BA0             0       // EEPROM Byte Address bit 0
#define    BA1             1       // EEPROM Byte Address bit 1
#define    BA2             2       // EEPROM Byte Address bit 2
#define    PA3             3       // EEPROM Page Address bit 3
#define    PA4             4       // EEPROM Page Address bit 4
#define    PA5             5       // EEPROM Page Address bit 5
#define    PA6             6       // EEPROM Page Address bit 6

/* DEEDR - EEPROM Data Register */
#define    ED0             0       // EEPROM Data Register bit 0
#define    ED1             1       // EEPROM Data Register bit 1
#define    ED2             2       // EEPROM Data Register bit 2
#define    ED3             3       // EEPROM Data Register bit 3
#define    ED4             4       // EEPROM Data Register bit 4
#define    ED5             5       // EEPROM Data Register bit 5
#define    ED6             6       // EEPROM Data Register bit 6
#define    ED7             7       // EEPROM Data Register bit 7

/* DEECR - EEPROM Control Register */
#define    EER             0       // EEPROM Read Bit
#define    EEL             1       // EEPROM Load Bit
#define    EEU             2       // EEPROM Unlock Bit
#define    BSY             3       // EERPOM Busy Bit


/* ***** WATCHDOG ********************* */
/* WDTCR - Watchdog Timer Control Register */
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDTOE           4       // RW
#define    WDDE            WDTOE   // For compatibility


/* ***** TIMER_COUNTER_0 ************** */
/* BTCNT - Timer Count register */
#define    C0              0       // Timer Count Register bit 7
#define    C1              1       // Timer Count Register bit 7
#define    C2              2       // Timer Count Register bit 7
#define    C3              3       // Timer Count Register bit 7
#define    C4              4       // Timer Count Register bit 7
#define    C5              5       // Timer Count Register bit 7
#define    C6              6       // Timer Count Register bit 7
#define    C7              7       // Timer Count Register bit 7

/* BTCR - Bit Timer Counter Control Register */
#define    F0              0       // Flag 0
#define    DATA            1       // Data Bit
#define    F2              2       // Flag 2
#define    IE              3       // Interrupt Enable
#define    M0              4       // Bit Timer Mode bit 0
#define    M1              5       // Bit Timer Mode bit 1
#define    C8              6       // Timer Count Register bit 8
#define    C9              7       // Timer Count Register bit 9


/* ***** PORT ************************* */
/* IO_ENAB - I/O Enable Register */
#define    IOE0            0       // I/O Enable bit 0
#define    IOE1            1       // I/O Enable bit 1
#define    IOE2            2       // I/O Enable bit 2
#define    IOE3            3       // I/O Enable bit 3
#define    IOE4            4       // I/O Enable bit 4
#define    IOE5            5       // I/O Enable bit 5
#define    BOHYST          6       // Additional Hysterezis for Brown-Out

/* IO_DATOUT - I/O Data Out Register */
#define    IOO0            0       // I/O Data Out Register bit 0
#define    IOO1            1       // I/O Data Out Register bit 1
#define    IOO2            2       // I/O Data Out Register bit 2
#define    IOO3            3       // I/O Data Out Register bit 3
#define    IOO4            4       // I/O Data Out Register bit 4
#define    IOO5            5       // I/O Data Out Register bit 5

/* IO_DATIN - I/O Data In register */
#define    IOI0            0       // I/O Data In Register bit 0
#define    IOI1            1       // I/O Data In Register bit 1
#define    IOI2            2       // I/O Data In Register bit 2
#define    IOI3            3       // I/O Data In Register bit 3
#define    IOI4            4       // I/O Data In Register bit 4
#define    IOI5            5       // I/O Data In Register bit 5


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

/* AVR_CONFIG - AVR Configuration Register */
#define    BBM             0       // Button Boot Mode
#define    SLEEP           1       // Sleep Bit
#define    BLI             2       // Battery Low Indicator
#define    BD              3       // Battery Dead
#define    TM              4       // Test Mode
#define    ACS0            5       // AVR System Clock Select bit 0
#define    ACS1            6       // AVR System Clock Select bit 1

/* B_DET - Button Detect Register */
#define    BD0             0       // Button Detect bit 0
#define    BD1             1       // Button Detect bit 1
#define    BD2             2       // Button Detect bit 2
#define    BD3             3       // Button Detect bit 3
#define    BD4             4       // Button Detect bit 4
#define    BD5             5       // Button Detect bit 5

/* BL_CONFIG - Battery Low Configuration Register */
#define    BL0             0       // Battery Low Detection Level bit 0
#define    BL1             1       // Battery Low Detection Level bit 1
#define    BL2             2       // Battery Low Detection Level bit 2
#define    BL3             3       // Battery Low Detection Level bit 3
#define    BL4             4       // Battery Low Detection Level bit 4
#define    BL5             5       // Battery Low Detection Level bit 5
#define    BLV             6       // Battery Low Valid
#define    BL              7       // Battery Low

#endif

