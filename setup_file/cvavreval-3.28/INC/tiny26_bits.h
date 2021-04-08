/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATtiny26 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __TINY26_BITS_INCLUDED__
#define __TINY26_BITS_INCLUDED__

/* ***** AD_CONVERTER ***************** */
/* ADMUX - The ADC multiplexer Selection Register */
#define    MUX0            0       // Analog Channel and Gain Selection Bits
#define    MUX1            1       // Analog Channel and Gain Selection Bits
#define    MUX2            2       // Analog Channel and Gain Selection Bits
#define    MUX3            3       // Analog Channel and Gain Selection Bits
#define    MUX4            4       // Analog Channel and Gain Selection Bits
#define    ADLAR           5       // Left Adjust Result
#define    REFS0           6       // Reference Selection Bit 0
#define    REFS1           7       // Reference Selection Bit 1

/* ADCSR - The ADC Control and Status register */
#define    ADCSRA          ADCSR   // For compatibility
#define    ADPS0           0       // ADC  Prescaler Select Bits
#define    ADPS1           1       // ADC  Prescaler Select Bits
#define    ADPS2           2       // ADC  Prescaler Select Bits
#define    ADIE            3       // ADC Interrupt Enable
#define    ADIF            4       // ADC Interrupt Flag
#define    ADFR            5       // ADC  Free Running Select
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


/* ***** ANALOG_COMPARATOR ************ */
/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACME            2       // Analog Comparator Multiplexer Enable
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Compare Output
#define    ACBG            6       // Analog Comparator Bandgap Select
#define    ACD             7       // Analog Comparator Disable


/* ***** USI ************************** */
/* USIDR - USI Data Register */
#define    USIDR0          0       // USI Data Register bit 0
#define    USIDR1          1       // USI Data Register bit 1
#define    USIDR2          2       // USI Data Register bit 2
#define    USIDR3          3       // USI Data Register bit 3
#define    USIDR4          4       // USI Data Register bit 4
#define    USIDR5          5       // USI Data Register bit 5
#define    USIDR6          6       // USI Data Register bit 6
#define    USIDR7          7       // USI Data Register bit 7

/* USISR - USI Status Register */
#define    USICNT0         0       // USI Counter Value Bit 0
#define    USICNT1         1       // USI Counter Value Bit 1
#define    USICNT2         2       // USI Counter Value Bit 2
#define    USICNT3         3       // USI Counter Value Bit 3
#define    USIDC           4       // Data Output Collision
#define    USIPF           5       // Stop Condition Flag
#define    USIOIF          6       // Counter Overflow Interrupt Flag
#define    USISIF          7       // Start Condition Interrupt Flag

/* USICR - USI Control Register */
#define    USITC           0       // Toggle Clock Port Pin
#define    USICLK          1       // Clock Strobe
#define    USICS0          2       // USI Clock Source Select Bit 0
#define    USICS1          3       // USI Clock Source Select Bit 1
#define    USIWM0          4       // USI Wire Mode Bit 0
#define    USIWM1          5       // USI Wire Mode Bit 1
#define    USIOIE          6       // Counter Overflow Interrupt Enable
#define    USISIE          7       // Start Condition Interrupt Enable


/* ***** PORTA ************************ */
/* PORTA - Port A Data Register */
#define    PORTA0          0       // Port A Data Register bit 0
#define    PORTA1          1       // Port A Data Register bit 1
#define    PORTA2          2       // Port A Data Register bit 2
#define    PORTA3          3       // Port A Data Register bit 3
#define    PORTA4          4       // Port A Data Register bit 4
#define    PORTA5          5       // Port A Data Register bit 5
#define    PORTA6          6       // Port A Data Register bit 6
#define    PORTA7          7       // Port A Data Register bit 7

/* DDRA - Port A Data Direction Register */
#define    DDA0            0       // Data Direction Register, Port A, bit 0
#define    DDA1            1       // Data Direction Register, Port A, bit 1
#define    DDA2            2       // Data Direction Register, Port A, bit 2
#define    DDA3            3       // Data Direction Register, Port A, bit 3
#define    DDA4            4       // Data Direction Register, Port A, bit 4
#define    DDA5            5       // Data Direction Register, Port A, bit 5
#define    DDA6            6       // Data Direction Register, Port A, bit 6
#define    DDA7            7       // Data Direction Register, Port A, bit 7

/* PINA - Port A Input Pins */
#define    PINA0           0       // Input Pins, Port A bit 0
#define    PINA1           1       // Input Pins, Port A bit 1
#define    PINA2           2       // Input Pins, Port A bit 2
#define    PINA3           3       // Input Pins, Port A bit 3
#define    PINA4           4       // Input Pins, Port A bit 4
#define    PINA5           5       // Input Pins, Port A bit 5
#define    PINA6           6       // Input Pins, Port A bit 6
#define    PINA7           7       // Input Pins, Port A bit 7


/* ***** PORTB ************************ */
/* PORTB - Port B Data Register */
#define    PORTB0          0       // Port B Data Register bit 0
#define    PORTB1          1       // Port B Data Register bit 1
#define    PORTB2          2       // Port B Data Register bit 2
#define    PORTB3          3       // Port B Data Register bit 3
#define    PORTB4          4       // Port B Data Register bit 4
#define    PORTB5          5       // Port B Data Register bit 5
#define    PORTB6          6       // Port B Data Register bit 6
#define    PORTB7          7       // Port B Data Register bit 7

/* DDRB - Port B Data Direction Register */
#define    DDB0            0       // Port B Data Direction Register bit 0
#define    DDB1            1       // Port B Data Direction Register bit 1
#define    DDB2            2       // Port B Data Direction Register bit 2
#define    DDB3            3       // Port B Data Direction Register bit 3
#define    DDB4            4       // Port B Data Direction Register bit 4
#define    DDB5            5       // Port B Data Direction Register bit 5
#define    DDB6            6       // Port B Data Direction Register bit 6
#define    DDB7            7       // Port B Data Direction Register bit 7

/* PINB - Port B Input Pins */
#define    PINB0           0       // Port B Input Pins bit 0
#define    PINB1           1       // Port B Input Pins bit 1
#define    PINB2           2       // Port B Input Pins bit 2
#define    PINB3           3       // Port B Input Pins bit 3
#define    PINB4           4       // Port B Input Pins bit 4
#define    PINB5           5       // Port B Input Pins bit 5
#define    PINB6           6       // Port B Input Pins bit 6
#define    PINB7           7       // Port B Input Pins bit 7


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
#define    EERIE           3       // EEProm Ready Interrupt Enable


/* ***** WATCHDOG ********************* */
/* WDTCR - Watchdog Timer Control Register */
#define    WDTCSR          WDTCR   // For compatibility
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDCE            4       // Watchdog Change Enable
#define    WDTOE           WDCE    // For compatibility


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

/* SP - Stack Pointer */
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

/* OSCCAL - Status Register */
#define    CAL0            0       // Oscillator Calibration Value Bit 0
#define    OSCCAL0         CAL0    // For compatibility
#define    CAL1            1       // Oscillator Calibration Value Bit 1
#define    OSCCAL1         CAL1    // For compatibility
#define    CAL2            2       // Oscillator Calibration Value Bit 2
#define    OSCCAL2         CAL2    // For compatibility
#define    CAL3            3       // Oscillator Calibration Value Bit 3
#define    OSCCAL3         CAL3    // For compatibility
#define    CAL4            4       // Oscillator Calibration Value Bit 4
#define    OSCCAL4         CAL4    // For compatibility
#define    CAL5            5       // Oscillator Calibration Value Bit 5
#define    CAL6            6       // Oscillator Calibration Value Bit 6
#define    CAL7            7       // Oscillator Calibration Value Bit 7


/* ***** TIMER_COUNTER_0 ************** */
/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TOIE0           1       // Timer/Counter0 Overflow Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag register */
#define    TOV0            1       // Timer/Counter0 Overflow Flag

/* TCCR0 - Timer/Counter0 Control Register */
#define    CS00            0       // Clock Select0 bit 0
#define    CS01            1       // Clock Select0 bit 1
#define    CS02            2       // Clock Select0 bit 2
#define    PSR0            3       // Prescaler Reset Timer/Counter0

/* TCNT0 - Timer Counter 0 */
#define    TCNT00          0       // Timer Counter 0 bit 0
#define    TCNT01          1       // Timer Counter 0 bit 1
#define    TCNT02          2       // Timer Counter 0 bit 2
#define    TCNT03          3       // Timer Counter 0 bit 3
#define    TCNT04          4       // Timer Counter 0 bit 4
#define    TCNT05          5       // Timer Counter 0 bit 5
#define    TCNT06          6       // Timer Counter 0 bit 6
#define    TCNT07          7       // Timer Counter 0 bit 7


/* ***** TIMER_COUNTER_1 ************** */
/* TCCR1A - Timer/Counter Control Register A */
#define    PWM1B           0       // Pulse Width Modulator B Enable
#define    PWM1A           1       // Pulse Width Modulator A Enable
#define    FOC1B           2       // Force Output Compare Match 1B
#define    FOC1A           3       // Force Output Compare Match 1A
#define    COM1B0          4       // Comparator B Output Mode Bit 0
#define    COM1B1          5       // Comparator B Output Mode Bit 1
#define    COM1A0          6       // Comparator A Output Mode Bit 0
#define    COM1A1          7       // Comparator A Output Mode Bit 1

/* TCCR1B - Timer/Counter Control Register B */
#define    CS10            0       // Clock Select Bits
#define    CS11            1       // Clock Select Bits
#define    CS12            2       // Clock Select Bits
#define    CS13            3       // Clock Select Bits
#define    PSR1            6       // Prescaler Reset Timer/Counter1
#define    CTC1            7       // Clear Timer/Counter on Compare Match

/* TCNT1 - Timer/Counter Register */
#define    TCNT1_0         0       // Timer/Counter Register Bit 0
#define    TCNT1_1         1       // Timer/Counter Register Bit 1
#define    TCNT1_2         2       // Timer/Counter Register Bit 2
#define    TCNT1_3         3       // Timer/Counter Register Bit 3
#define    TCNT1_4         4       // Timer/Counter Register Bit 4
#define    TCNT1_5         5       // Timer/Counter Register Bit 5
#define    TCNT1_6         6       // Timer/Counter Register Bit 6
#define    TCNT1_7         7       // Timer/Counter Register Bit 7

/* OCR1A - Output Compare Register */
#define    OCR1A0          0       // Output Compare Register A Bit 0
#define    OCR1A1          1       // Output Compare Register A Bit 1
#define    OCR1A2          2       // Output Compare Register A Bit 2
#define    OCR1A3          3       // Output Compare Register A Bit 3
#define    OCR1A4          4       // Output Compare Register A Bit 4
#define    OCR1A5          5       // Output Compare Register A Bit 5
#define    OCR1A6          6       // Output Compare Register A Bit 6
#define    OCR1A7          7       // Output Compare Register A Bit 7

/* OCR1B - Output Compare Register */
#define    OCR1B0          0       // Output Compare Register B Bit 0
#define    OCR1B1          1       // Output Compare Register B Bit 1
#define    OCR1B2          2       // Output Compare Register B Bit 2
#define    OCR1B3          3       // Output Compare Register B Bit 3
#define    OCR1B4          4       // Output Compare Register B Bit 4
#define    OCR1B5          5       // Output Compare Register B Bit 5
#define    OCR1B6          6       // Output Compare Register B Bit 6
#define    OCR1B7          7       // Output Compare Register B Bit 7

/* OCR1C - Output Compare Register */
#define    OCR1C0          0       // Output Compare Register C Bit 0
#define    OCR1C1          1       // Output Compare Register C Bit 1
#define    OCR1C2          2       // Output Compare Register C Bit 2
#define    OCR1C3          3       // Output Compare Register C Bit 3
#define    OCR1C4          4       // Output Compare Register C Bit 4
#define    OCR1C5          5       // Output Compare Register C Bit 5
#define    OCR1C6          6       // Output Compare Register C Bit 6
#define    OCR1C7          7       // Output Compare Register C Bit 7

/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TOIE1           2       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1B          5       // Timer/Counter1 Output Compare Interrupt Enable
#define    OCIE1A          6       // Timer/Counter1 Output Compare Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag Register */
#define    TOV1            2       // Timer/Counter1 Overflow Flag
#define    OCF1B           5       // Timer/Counter1 Output Compare Flag 1B
#define    OCF1A           6       // Timer/Counter1 Output Compare Flag 1A

/* PLLCSR - PLL Control and Status Register */
#define    PLOCK           0       // PLL Lock Detector
#define    PLLE            1       // PLL Enable
#define    PCKE            2       // PCK Enable


/* ***** EXTERNAL_INTERRUPT *********** */
/* GIMSK - General Interrupt Mask Register */
#define    PCIE0           4       // Pin Change Interrupt Enable 0
#define    PCIE1           5       // Pin Change Interrupt Enable 1
#define    INT0            6       // External Interrupt Request 0 Enable

/* GIFR - General Interrupt Flag register */
#define    PCIF            5       // Pin Change Interrupt Flag
#define    INTF0           6       // External Interrupt Flag 0

#endif

