/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATtiny13A I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __TINY13_BITS_INCLUDED__
#define __TINY13_BITS_INCLUDED__

/* ***** AD_CONVERTER ***************** */
/* ADMUX - The ADC multiplexer Selection Register */
#define    MUX0            0       // Analog Channel and Gain Selection Bits
#define    MUX1            1       // Analog Channel and Gain Selection Bits
#define    ADLAR           5       // Left Adjust Result
#define    REFS0           6       // Reference Selection Bit 0

/* ADCSRA - The ADC Control and Status register */
#define    ADPS0           0       // ADC  Prescaler Select Bits
#define    ADPS1           1       // ADC  Prescaler Select Bits
#define    ADPS2           2       // ADC  Prescaler Select Bits
#define    ADIE            3       // ADC Interrupt Enable
#define    ADIF            4       // ADC Interrupt Flag
#define    ADATE           5       // ADC Auto Trigger Enable
#define    ADSC            6       // ADC Start Conversion
#define    ADEN            7       // ADC Enable

/* ADCH - ADC Data Register High Byte */
#define    ADCH0           0       // ADC Data Register High Byte Bit 0
#define    ADCH1           1       // ADC Data Register High Byte Bit 1
#define    ADCH2           2       // ADC Data Register High Byte Bit 2
#define    ADCH3           3       // ADC Data Register High Byte Bit 3
#define    ADCH4           4       // ADC Data Register High Byte Bit 4
#define    ADCH5           5       // ADC Data Register High Byte Bit 5
#define    ADCH6           6       // ADC Data Register High Byte Bit 6
#define    ADCH7           7       // ADC Data Register High Byte Bit 7

/* ADCL - ADC Data Register Low Byte */
#define    ADCL0           0       // ADC Data Register Low Byte Bit 0
#define    ADCL1           1       // ADC Data Register Low Byte Bit 1
#define    ADCL2           2       // ADC Data Register Low Byte Bit 2
#define    ADCL3           3       // ADC Data Register Low Byte Bit 3
#define    ADCL4           4       // ADC Data Register Low Byte Bit 4
#define    ADCL5           5       // ADC Data Register Low Byte Bit 5
#define    ADCL6           6       // ADC Data Register Low Byte Bit 6
#define    ADCL7           7       // ADC Data Register Low Byte Bit 7

/* ADCSRB - ADC Control and Status Register B */
#define    ADTS0           0       // ADC Auto Trigger Source 0
#define    ADTS1           1       // ADC Auto Trigger Source 1
#define    ADTS2           2       // ADC Auto Trigger Source 2

/* DIDR0 - Digital Input Disable Register 0 */
#define    ADC1D           2       // ADC2 Digital input Disable
#define    ADC3D           3       // ADC3 Digital input Disable
#define    ADC2D           4       // ADC2 Digital input Disable
#define    ADC0D           5       // ADC0 Digital input Disable


/* ***** ANALOG_COMPARATOR ************ */
/* ADCSRB - ADC Control and Status Register B */
#define    ACME            6       // Analog Comparator Multiplexer Enable

/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Compare Output
#define    ACBG            6       // Analog Comparator Bandgap Select
#define    AINBG           ACBG    // For compatibility
#define    ACD             7       // Analog Comparator Disable

/* DIDR0 -  */
#define    AIN0D           0       // AIN0 Digital Input Disable
#define    AIN1D           1       // AIN1 Digital Input Disable


/* ***** EEPROM *********************** */
/* EEAR - EEPROM Read/Write Access */
#define    EEARL           EEAR    // For compatibility
#define    EEAR0           0       // EEPROM Read/Write Access bit 0
#define    EEAR1           1       // EEPROM Read/Write Access bit 1
#define    EEAR2           2       // EEPROM Read/Write Access bit 2
#define    EEAR3           3       // EEPROM Read/Write Access bit 3
#define    EEAR4           4       // EEPROM Read/Write Access bit 4
#define    EEAR5           5       // EEPROM Read/Write Access bit 5

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
#define    EEPE            EEWE    // For compatibility
#define    EEMWE           2       // EEPROM Master Write Enable
#define    EEMPE           EEMWE   // For compatibility
#define    EERIE           3       // EEProm Ready Interrupt Enable
#define    EEPM0           4       //
#define    EEPM1           5       //


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

/* SPL - Stack Pointer Low Byte */
#define    SP0             0       // Stack Pointer Bit 0
#define    SP1             1       // Stack Pointer Bit 1
#define    SP2             2       // Stack Pointer Bit 2
#define    SP3             3       // Stack Pointer Bit 3
#define    SP4             4       // Stack Pointer Bit 4
#define    SP5             5       // Stack Pointer Bit 5
#define    SP6             6       // Stack Pointer Bit 6
#define    SP7             7       // Stack Pointer Bit 7

/* MCUCR - MCU Control Register */
#define    ISC00           0       // Interrupt Sense Control 0 bit 0
#define    ISC01           1       // Interrupt Sense Control 0 bit 1
#define    SM0             3       // Sleep Mode Select Bit 0
#define    SM1             4       // Sleep Mode Select Bit 1
#define    SE              5       // Sleep Enable
#define    PUD             6       // Pull-up Disable

/* MCUSR - MCU Status register */
#define    PORF            0       // Power-On Reset Flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag

/* OSCCAL - Oscillator Calibration Register */
#define    CAL0            0       // Oscillatro Calibration Value Bit 0
#define    CAL1            1       // Oscillatro Calibration Value Bit 1
#define    CAL2            2       // Oscillatro Calibration Value Bit 2
#define    CAL3            3       // Oscillatro Calibration Value Bit 3
#define    CAL4            4       // Oscillatro Calibration Value Bit 4
#define    CAL5            5       // Oscillatro Calibration Value Bit 5
#define    CAL6            6       // Oscillatro Calibration Value Bit 6

/* CLKPR - Clock Prescale Register */
#define    CLKPS0          0       // Clock Prescaler Select Bit 0
#define    CLKPS1          1       // Clock Prescaler Select Bit 1
#define    CLKPS2          2       // Clock Prescaler Select Bit 2
#define    CLKPS3          3       // Clock Prescaler Select Bit 3
#define    CLKPCE          7       // Clock Prescaler Change Enable

/* DWDR - Debug Wire Data Register */
#define    DWDR0           0       // Debug Wire Data Register Bit 0
#define    DWDR1           1       // Debug Wire Data Register Bit 1
#define    DWDR2           2       // Debug Wire Data Register Bit 2
#define    DWDR3           3       // Debug Wire Data Register Bit 3
#define    DWDR4           4       // Debug Wire Data Register Bit 4
#define    DWDR5           5       // Debug Wire Data Register Bit 5
#define    DWDR6           6       // Debug Wire Data Register Bit 6
#define    DWDR7           7       // Debug Wire Data Register Bit 7

/* SPMCSR - Store Program Memory Control and Status Register */
#define    SPMEN           0       // Store program Memory Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    RFLB            3       // Read Fuse and Lock Bits
#define    CTPB            4       // Clear Temporary Page Buffer


/* ***** PORTB ************************ */
/* PORTB - Data Register, Port B */
#define    PORTB0          0       //
#define    PORTB1          1       //
#define    PORTB2          2       //
#define    PORTB3          3       //
#define    PORTB4          4       //
#define    PORTB5          5       //

/* DDRB - Data Direction Register, Port B */
#define    DDB0            0       //
#define    DDB1            1       //
#define    DDB2            2       //
#define    DDB3            3       //
#define    DDB4            4       //
#define    DDB5            5       //

/* PINB - Input Pins, Port B */
#define    PINB0           0       //
#define    PINB1           1       //
#define    PINB2           2       //
#define    PINB3           3       //
#define    PINB4           4       //
#define    PINB5           5       //


/* ***** EXTERNAL_INTERRUPT *********** */
/* MCUCR - MCU Control Register */
//#define  ISC00           0       // Interrupt Sense Control 0 Bit 0
//#define  ISC01           1       // Interrupt Sense Control 0 Bit 1

/* GIMSK - General Interrupt Mask Register */
#define    GICR            GIMSK   // For compatibility
#define    PCIE            5       // Pin Change Interrupt Enable
#define    INT0            6       // External Interrupt Request 0 Enable

/* GIFR - General Interrupt Flag register */
#define    PCIF            5       // Pin Change Interrupt Flag
#define    INTF0           6       // External Interrupt Flag 0

/* PCMSK - Pin Change Enable Mask */
#define    PCINT0          0       // Pin Change Enable Mask Bit 0
#define    PCINT1          1       // Pin Change Enable Mask Bit 1
#define    PCINT2          2       // Pin Change Enable Mask Bit 2
#define    PCINT3          3       // Pin Change Enable Mask Bit 3
#define    PCINT4          4       // Pin Change Enable Mask Bit 4
#define    PCINT5          5       // Pin Change Enable Mask Bit 5


/* ***** TIMER_COUNTER_0 ************** */
/* TIMSK0 - Timer/Counter0 Interrupt Mask Register */
#define    TOIE0           1       // Timer/Counter0 Overflow Interrupt Enable
#define    OCIE0A          2       // Timer/Counter0 Output Compare Match A Interrupt Enable
#define    OCIE0B          3       // Timer/Counter0 Output Compare Match B Interrupt Enable

/* TIFR0 - Timer/Counter0 Interrupt Flag register */
#define    TOV0            1       // Timer/Counter0 Overflow Flag
#define    OCF0A           2       // Timer/Counter0 Output Compare Flag 0A
#define    OCF0B           3       // Timer/Counter0 Output Compare Flag 0B

/* OCR0A - Timer/Counter0 Output Compare Register */
#define    OCR0A_0         0       //
#define    OCR0A_1         1       //
#define    OCR0A_2         2       //
#define    OCR0A_3         3       //
#define    OCR0A_4         4       //
#define    OCR0A_5         5       //
#define    OCR0A_6         6       //
#define    OCR0A_7         7       //

/* TCCR0A - Timer/Counter  Control Register A */
#define    WGM00           0       // Waveform Generation Mode
#define    WGM01           1       // Waveform Generation Mode
#define    COM0B0          4       // Compare Match Output B Mode
#define    COM0B1          5       // Compare Match Output B Mode
#define    COM0A0          6       // Compare Match Output A Mode
#define    COM0A1          7       // Compare Match Output A Mode

/* TCNT0 - Timer/Counter0 */
#define    TCNT0_0         0       //
#define    TCNT0_1         1       //
#define    TCNT0_2         2       //
#define    TCNT0_3         3       //
#define    TCNT0_4         4       //
#define    TCNT0_5         5       //
#define    TCNT0_6         6       //
#define    TCNT0_7         7       //

/* TCCR0B - Timer/Counter Control Register B */
#define    CS00            0       // Clock Select
#define    CS01            1       // Clock Select
#define    CS02            2       // Clock Select
#define    WGM02           3       // Waveform Generation Mode
#define    FOC0B           6       // Force Output Compare B
#define    FOC0A           7       // Force Output Compare A

/* OCR0B - Timer/Counter0 Output Compare Register */
#define    OCR0B_0         0       //
#define    OCR0B_1         1       //
#define    OCR0B_2         2       //
#define    OCR0B_3         3       //
#define    OCR0B_4         4       //
#define    OCR0B_5         5       //
#define    OCR0B_6         6       //
#define    OCR0B_7         7       //

/* GTCCR - General Timer Conuter Register */
#define    PSR10           0       // Prescaler Reset Timer/Counter0
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** WATCHDOG ********************* */
/* WDTCR - Watchdog Timer Control Register */
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDCE            4       // Watchdog Change Enable
#define    WDP3            5       // Watchdog Timer Prescaler Bit 3
#define    WDTIE           6       // Watchdog Timeout Interrupt Enable
#define    WDTIF           7       // Watchdog Timeout Interrupt Flag

/* PRR - Power Reduction Register */
#define PRADC 0
#define PRTIM0 1

/* BODCR - Drown-Out Detector Control Register */
#define BODSE 0
#define BODS 1

#endif

