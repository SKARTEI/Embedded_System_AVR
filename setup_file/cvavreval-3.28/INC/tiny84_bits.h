/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATtiny44, ATtiny84 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __TINY84_BITS_INCLUDED__
#define __TINY84_BITS_INCLUDED__

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
/* PORTB - Data Register, Port B */
#define    PORTB0          0       //
#define    PORTB1          1       //
#define    PORTB2          2       //
#define    PORTB3          3       //

/* DDRB - Data Direction Register, Port B */
#define    DDB0            0       //
#define    DDB1            1       //
#define    DDB2            2       //
#define    DDB3            3       //

/* PINB - Input Pins, Port B */
#define    PINB0           0       //
#define    PINB1           1       //
#define    PINB2           2       //
#define    PINB3           3       //


/* ***** ANALOG_COMPARATOR ************ */
/* ADCSRB - ADC Control and Status Register B */
#define    ACME            6       // Analog Comparator Multiplexer Enable

/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIC            2       // Analog Comparator Input Capture Enable
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Compare Output
#define    ACBG            6       // Analog Comparator Bandgap Select
#define    AINBG           ACBG    // For compatibility
#define    ACD             7       // Analog Comparator Disable

/* DIDR0 -  */
#define    ADC0D           0       // ADC 0 Digital input buffer disable
#define    ADC1D           1       // ADC 1 Digital input buffer disable


/* ***** AD_CONVERTER ***************** */
/* ADMUX - ADC Multiplexer Selection Register */
#define    MUX0            0       // Analog Channel and Gain Selection Bit 0
#define    MUX1            1       // Analog Channel and Gain Selection Bit 1
#define    MUX2            2       // Analog Channel and Gain Selection Bit 2
#define    MUX3            3       // Analog Channel and Gain Selection Bit 3
#define    MUX4            4       // Analog Channel and Gain Selection Bit 4
#define    MUX5            5       // Analog Channel and Gain Selection Bit 5
#define    REFS0           6       // Reference Selection Bit 0
#define    REFS1           7       // Reference Selection Bit 1

/* ADCSRA - ADC Control and Status Register A */
#define    ADPS0           0       // ADC  Prescaler Select Bit 0
#define    ADPS1           1       // ADC  Prescaler Select Bit 1
#define    ADPS2           2       // ADC  Prescaler Select Bit 2
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
#define    ADTS0           0       // ADC Auto Trigger Source bit 0
#define    ADTS1           1       // ADC Auto Trigger Source bit 1
#define    ADTS2           2       // ADC Auto Trigger Source bit 2
#define    ADLAR           4       // ADC Left Adjust Result
#define    BIN             7       // Bipolar Input Mode

/* DIDR0 - Digital Input Disable Register 0 */
//#define  ADC0D           0       // ADC0 Digital Input Disable
//#define  ADC1D           1       // ADC1 Digital Input Disable
#define    ADC2D           2       // ADC2 Digital Input Disable
#define    ADC3D           3       // ADC3 Digital Input Disable
#define    ADC4D           4       // ADC4 Digital Input Disable
#define    ADC5D           5       // ADC5 Digital Input Disable
#define    ADC6D           6       // ADC6 Digital Input Disable
#define    ADC7D           7       // ADC7 Digital Input Disable


/* ***** USI ************************** */
/* USIBR - USI Buffer Register */
#define    USIBR0          0       // USI Buffer Register bit 0
#define    USIBR1          1       // USI Buffer Register bit 1
#define    USIBR2          2       // USI Buffer Register bit 2
#define    USIBR3          3       // USI Buffer Register bit 3
#define    USIBR4          4       // USI Buffer Register bit 4
#define    USIBR5          5       // USI Buffer Register bit 5
#define    USIBR6          6       // USI Buffer Register bit 6
#define    USIBR7          7       // USI Buffer Register bit 7

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


/* ***** EXTERNAL_INTERRUPT *********** */
/* MCUCR - MCU Control Register */
#define    ISC00           0       // Interrupt Sense Control 0 Bit 0
#define    ISC01           1       // Interrupt Sense Control 0 Bit 1

/* GIMSK - General Interrupt Mask Register */
#define    GICR            GIMSK   // For compatibility
#define    PCIE0           4       // Pin Change Interrupt Enable 0
#define    PCIE1           5       // Pin Change Interrupt Enable 1
#define    INT0            6       // External Interrupt Request 0 Enable

/* GIFR - General Interrupt Flag register */
#define    PCIF0           4       // Pin Change Interrupt Flag 0
#define    PCIF1           5       // Pin Change Interrupt Flag 1
#define    INTF0           6       // External Interrupt Flag 0

/* PCMSK1 - Pin Change Enable Mask 1 */
#define    PCINT8          0       // Pin Change Enable Mask Bit 8
#define    PCINT9          1       // Pin Change Enable Mask Bit 9
#define    PCINT10         2       // Pin Change Enable Mask Bit 10
#define    PCINT11         3       // Pin Change Enable Mask Bit 11

/* PCMSK0 - Pin Change Enable Mask 0 */
#define    PCINT0          0       // Pin Change Enable Mask Bit 0
#define    PCINT1          1       // Pin Change Enable Mask Bit 1
#define    PCINT2          2       // Pin Change Enable Mask Bit 2
#define    PCINT3          3       // Pin Change Enable Mask Bit 3
#define    PCINT4          4       // Pin Change Enable Mask Bit 4
#define    PCINT5          5       // Pin Change Enable Mask Bit 5
#define    PCINT6          6       // Pin Change Enable Mask Bit 6
#define    PCINT7          7       // Pin Change Enable Mask Bit 7


/* ***** EEPROM *********************** */
/* EEARL - EEPROM Address Register Low Byte */
#define    EEAR0           0       // EEPROM Read/Write Access Bit 0
#define    EEAR1           1       // EEPROM Read/Write Access Bit 1
#define    EEAR2           2       // EEPROM Read/Write Access Bit 2
#define    EEAR3           3       // EEPROM Read/Write Access Bit 3
#define    EEAR4           4       // EEPROM Read/Write Access Bit 4
#define    EEAR5           5       // EEPROM Read/Write Access Bit 5
#define    EEAR6           6       // EEPROM Read/Write Access Bit 6
#define    EEAR7           7       // EEPROM Read/Write Access Bit 7

/* EEARH - EEPROM Address Register High Byte */
#define    EEAR8           0       // EEPROM Read/Write Access Bit 0

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
#define    EEPE            1       // EEPROM Write Enable
#define    EEMPE           2       // EEPROM Master Write Enable
#define    EERIE           3       // EEPROM Ready Interrupt Enable
#define    EEPM0           4       // EEPROM Programming Mode Bit 0
#define    EEPM1           5       // EEPROM Programming Mode Bit 1


/* ***** WATCHDOG ********************* */
/* WDTCSR - Watchdog Timer Control Register */
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDCE            4       // Watchdog Change Enable
#define    WDP3            5       // Watchdog Timer Prescaler Bit 3
#define    WDIE            6       // Watchdog Timeout Interrupt Enable
#define    WDIF            7       // Watchdog Timeout Interrupt Flag


/* ***** TIMER_COUNTER_0 ************** */
/* TIMSK0 - Timer/Counter Interrupt Mask Register */
#define    TOIE0           0       // Timer/Counter0 Overflow Interrupt Enable
#define    OCIE0A          1       // Timer/Counter0 Output Compare Match A Interrupt Enable
#define    OCIE0B          2       // Timer/Counter0 Output Compare Match B Interrupt Enable

/* TIFR0 - Timer/Counter0 Interrupt Flag Register */
#define    TOV0            0       // Timer/Counter0 Overflow Flag
#define    OCF0A           1       // Timer/Counter0 Output Compare Flag A
#define    OCF0B           2       // Timer/Counter0 Output Compare Flag B

/* TCCR0A - Timer/Counter  Control Register A */
#define    WGM00           0       // Waveform Generation Mode bit 0
#define    WGM01           1       // Waveform Generation Mode bit 1
#define    COM0B0          4       // Compare Match Output B Mode bit 0
#define    COM0B1          5       // Compare Match Output B Mode bit 1
#define    COM0A0          6       // Compare Match Output A Mode bit 0
#define    COM0A1          7       // Compare Match Output A Mode bit 1

/* TCCR0B - Timer/Counter Control Register B */
#define    CS00            0       // Clock Select bit 0
#define    CS01            1       // Clock Select bit 1
#define    CS02            2       // Clock Select bit 2
#define    WGM02           3       // Waveform Generation Mode bit 2
#define    FOC0B           6       // Force Output Compare B
#define    FOC0A           7       // Force Output Compare A

/* TCNT0 - Timer/Counter0 */
#define    TCNT0_0         0       //
#define    TCNT0_1         1       //
#define    TCNT0_2         2       //
#define    TCNT0_3         3       //
#define    TCNT0_4         4       //
#define    TCNT0_5         5       //
#define    TCNT0_6         6       //
#define    TCNT0_7         7       //

/* OCR0A - Timer/Counter0 Output Compare Register A */
#define    OCR0_0          0       //
#define    OCR0_1          1       //
#define    OCR0_2          2       //
#define    OCR0_3          3       //
#define    OCR0_4          4       //
#define    OCR0_5          5       //
#define    OCR0_6          6       //
#define    OCR0_7          7       //

/* OCR0B - Timer/Counter0 Output Compare Register B */
//#define  OCR0_0          0       //
//#define  OCR0_1          1       //
//#define  OCR0_2          2       //
//#define  OCR0_3          3       //
//#define  OCR0_4          4       //
//#define  OCR0_5          5       //
//#define  OCR0_6          6       //
//#define  OCR0_7          7       //

/* GTCCR - General Timer/Counter Control Register */
#define    PSR10           0       // Prescaler Reset Timer/CounterN
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK1 - Timer/Counter1 Interrupt Mask Register */
#define    TOIE1           0       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1A          1       // Timer/Counter1 Output Compare A Match Interrupt Enable
#define    OCIE1B          2       // Timer/Counter1 Output Compare B Match Interrupt Enable
#define    ICIE1           5       // Timer/Counter1 Input Capture Interrupt Enable

/* TIFR1 - Timer/Counter Interrupt Flag register */
#define    TOV1            0       // Timer/Counter1 Overflow Flag
#define    OCF1A           1       // Timer/Counter1 Output Compare A Match Flag
#define    OCF1B           2       // Timer/Counter1 Output Compare B Match Flag
#define    ICF1            5       // Timer/Counter1 Input Capture Flag

/* TCCR1A - Timer/Counter1 Control Register A */
#define    WGM10           0       // Pulse Width Modulator Select Bit 0
#define    PWM10           WGM10   // For compatibility
#define    WGM11           1       // Pulse Width Modulator Select Bit 1
#define    PWM11           WGM11   // For compatibility
#define    COM1B0          4       // Comparet Ouput Mode 1B, bit 0
#define    COM1B1          5       // Compare Output Mode 1B, bit 1
#define    COM1A0          6       // Comparet Ouput Mode 1A, bit 0
#define    COM1A1          7       // Compare Output Mode 1A, bit 1

/* TCCR1B - Timer/Counter1 Control Register B */
#define    CS10            0       // Clock Select bit 0
#define    CS11            1       // Clock Select 1 bit 1
#define    CS12            2       // Clock Select1 bit 2
#define    WGM12           3       // Waveform Generation Mode Bit 2
#define    CTC1            WGM12   // For compatibility
#define    WGM13           4       // Waveform Generation Mode Bit 3
#define    ICES1           6       // Input Capture 1 Edge Select
#define    ICNC1           7       // Input Capture 1 Noise Canceler

/* TCCR1C - Timer/Counter1 Control Register C */
#define    FOC1B           6       // Force Output Compare for Channel B
#define    FOC1A           7       // Force Output Compare for Channel A

/* OCR1BH - Timer/Counter1 Output Compare Register B High Byte */
#define    OCR1AH0         0       // Timer/Counter1 Output Compare Register High Byte bit 0
#define    OCR1AH1         1       // Timer/Counter1 Output Compare Register High Byte bit 1
#define    OCR1AH2         2       // Timer/Counter1 Output Compare Register High Byte bit 2
#define    OCR1AH3         3       // Timer/Counter1 Output Compare Register High Byte bit 3
#define    OCR1AH4         4       // Timer/Counter1 Output Compare Register High Byte bit 4
#define    OCR1AH5         5       // Timer/Counter1 Output Compare Register High Byte bit 5
#define    OCR1AH6         6       // Timer/Counter1 Output Compare Register High Byte bit 6
#define    OCR1AH7         7       // Timer/Counter1 Output Compare Register High Byte bit 7

/* OCR1BL - Timer/Counter1 Output Compare Register B Low Byte */
#define    OCR1AL0         0       // Timer/Counter1 Output Compare Register Low Byte Bit 0
#define    OCR1AL1         1       // Timer/Counter1 Output Compare Register Low Byte Bit 1
#define    OCR1AL2         2       // Timer/Counter1 Output Compare Register Low Byte Bit 2
#define    OCR1AL3         3       // Timer/Counter1 Output Compare Register Low Byte Bit 3
#define    OCR1AL4         4       // Timer/Counter1 Output Compare Register Low Byte Bit 4
#define    OCR1AL5         5       // Timer/Counter1 Output Compare Register Low Byte Bit 5
#define    OCR1AL6         6       // Timer/Counter1 Output Compare Register Low Byte Bit 6
#define    OCR1AL7         7       // Timer/Counter1 Output Compare Register Low Byte Bit 7


/* ***** BOOT_LOAD ******************** */
/* SPMCSR - Store Program Memory Control Register */
#define    SPMEN           0       // Store Program Memory Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    RFLB            3       // Read fuse and lock bits
#define    CTPB            4       // Clear temporary page buffer


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

/* MCUCR - MCU Control Register */
#define    SM0             3       // Sleep Mode Select Bit 0
#define    SM1             4       // Sleep Mode Select Bit 1
#define    SE              5       // Sleep Enable
#define    PUD             6       //

/* MCUSR - MCU Status Register */
#define    PORF            0       // Power-on reset flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag

/* OSCCAL - Oscillator Calibration Value */
#define    CAL0            0       // Oscillator Calibration Value Bit0
#define    CAL1            1       // Oscillator Calibration Value Bit1
#define    CAL2            2       // Oscillator Calibration Value Bit2
#define    CAL3            3       // Oscillator Calibration Value Bit3
#define    CAL4            4       // Oscillator Calibration Value Bit4
#define    CAL5            5       // Oscillator Calibration Value Bit5
#define    CAL6            6       // Oscillator Calibration Value Bit6
#define    CAL7            7       // Oscillator Calibration Value Bit7

/* GPIOR2 - General Purpose I/O Register 2 */
#define    GPIOR20         0       //
#define    GPIOR21         1       //
#define    GPIOR22         2       //
#define    GPIOR23         3       //
#define    GPIOR24         4       //
#define    GPIOR25         5       //
#define    GPIOR26         6       //
#define    GPIOR27         7       //

/* GPIOR1 - General Purpose I/O Register 1 */
#define    GPIOR10         0       //
#define    GPIOR11         1       //
#define    GPIOR12         2       //
#define    GPIOR13         3       //
#define    GPIOR14         4       //
#define    GPIOR15         5       //
#define    GPIOR16         6       //
#define    GPIOR17         7       //

/* GPIOR0 - General Purpose I/O Register 0 */
#define    GPIOR00         0       //
#define    GPIOR01         1       //
#define    GPIOR02         2       //
#define    GPIOR03         3       //
#define    GPIOR04         4       //
#define    GPIOR05         5       //
#define    GPIOR06         6       //
#define    GPIOR07         7       //

/* PRR - Power Reduction Register */
#define    PRADC           0       // Power Reduction ADC
#define    PRUSI           1       // Power Reduction USI
#define    PRTIM0          2       // Power Reduction Timer/Counter0
#define    PRTIM1          3       // Power Reduction Timer/Counter1

/* CLKPR - Clock Prescale Register */
#define    CLKPS0          0       // Clock Prescaler Select Bit 0
#define    CLKPS1          1       // Clock Prescaler Select Bit 1
#define    CLKPS2          2       // Clock Prescaler Select Bit 2
#define    CLKPS3          3       // Clock Prescaler Select Bit 3
#define    CLKPCE          7       // Clock Prescaler Change Enable

#endif

