/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2011 Pavel Haiduc, HP InfoTech s.r.l.

ATtiny2313(V) I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __TINY2313_BITS_INCLUDED__
#define __TINY2313_BITS_INCLUDED__

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


/* ***** TIMER_COUNTER_0 ************** */
/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    OCIE0A          0       // Timer/Counter0 Output Compare Match A Interrupt Enable
#define    TOIE0           1       // Timer/Counter0 Overflow Interrupt Enable
#define    OCIE0B          2       // Timer/Counter0 Output Compare Match B Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag register */
#define    OCF0A           0       // Timer/Counter0 Output Compare Flag 0A
#define    TOV0            1       // Timer/Counter0 Overflow Flag
#define    OCF0B           2       // Timer/Counter0 Output Compare Flag 0B

/* OCR0B - Timer/Counter0 Output Compare Register */
#define    OCR0_0          0       //
#define    OCR0_1          1       //
#define    OCR0_2          2       //
#define    OCR0_3          3       //
#define    OCR0_4          4       //
#define    OCR0_5          5       //
#define    OCR0_6          6       //
#define    OCR0_7          7       //

/* OCR0A - Timer/Counter0 Output Compare Register */
//#define  OCR0_0          0       //
//#define  OCR0_1          1       //
//#define  OCR0_2          2       //
//#define  OCR0_3          3       //
//#define  OCR0_4          4       //
//#define  OCR0_5          5       //
//#define  OCR0_6          6       //
//#define  OCR0_7          7       //

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
#define    TCCR0           TCCR0B  // For compatibility
#define    CS00            0       // Clock Select
#define    CS01            1       // Clock Select
#define    CS02            2       // Clock Select
#define    WGM02           3       //
#define    FOC0B           6       // Force Output Compare B
#define    FOC0A           7       // Force Output Compare B


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    ICIE1           3       // Timer/Counter1 Input Capture Interrupt Enable
#define    TICIE           ICIE1   // For compatibility
#define    OCIE1B          5       // Timer/Counter1 Output CompareB Match Interrupt Enable
#define    OCIE1A          6       // Timer/Counter1 Output CompareA Match Interrupt Enable
#define    TOIE1           7       // Timer/Counter1 Overflow Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag register */
#define    ICF1            3       // Input Capture Flag 1
#define    OCF1B           5       // Output Compare Flag 1B
#define    OCF1A           6       // Output Compare Flag 1A
#define    TOV1            7       // Timer/Counter1 Overflow Flag

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

/* OCR1BH - Timer/Counter1 Outbut Compare Register High Byte */
#define    OCR1AH0         0       // Timer/Counter1 Outbut Compare Register High Byte bit 0
#define    OCR1AH1         1       // Timer/Counter1 Outbut Compare Register High Byte bit 1
#define    OCR1AH2         2       // Timer/Counter1 Outbut Compare Register High Byte bit 2
#define    OCR1AH3         3       // Timer/Counter1 Outbut Compare Register High Byte bit 3
#define    OCR1AH4         4       // Timer/Counter1 Outbut Compare Register High Byte bit 4
#define    OCR1AH5         5       // Timer/Counter1 Outbut Compare Register High Byte bit 5
#define    OCR1AH6         6       // Timer/Counter1 Outbut Compare Register High Byte bit 6
#define    OCR1AH7         7       // Timer/Counter1 Outbut Compare Register High Byte bit 7

/* OCR1BL - Timer/Counter1 Output Compare Register Low Byte */
#define    OCR1AL0         0       // Timer/Counter1 Outbut Compare Register Low Byte Bit 0
#define    OCR1AL1         1       // Timer/Counter1 Outbut Compare Register Low Byte Bit 1
#define    OCR1AL2         2       // Timer/Counter1 Outbut Compare Register Low Byte Bit 2
#define    OCR1AL3         3       // Timer/Counter1 Outbut Compare Register Low Byte Bit 3
#define    OCR1AL4         4       // Timer/Counter1 Outbut Compare Register Low Byte Bit 4
#define    OCR1AL5         5       // Timer/Counter1 Outbut Compare Register Low Byte Bit 5
#define    OCR1AL6         6       // Timer/Counter1 Outbut Compare Register Low Byte Bit 6
#define    OCR1AL7         7       // Timer/Counter1 Outbut Compare Register Low Byte Bit 7


/* ***** WATCHDOG ********************* */
/* WDTCR - Watchdog Timer Control Register */
#define    WDTCSR          WDTCR   // For compatibility
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDCE            4       // Watchdog Change Enable
#define    WDTOE           WDCE    // For compatibility
#define    WDP3            5       // Watchdog Timer Prescaler Bit 3
#define    WDIE            6       // Watchdog Timeout Interrupt Enable
#define    WDIF            7       // Watchdog Timeout Interrupt Flag


/* ***** EXTERNAL_INTERRUPT *********** */
/* GIMSK - General Interrupt Mask Register */
#define    PCIE            5       //
#define    INT0            6       // External Interrupt Request 0 Enable
#define    INT1            7       // External Interrupt Request 1 Enable

/* EIFR - Extended Interrupt Flag Register */
#define    GIFR            EIFR    // For compatibility
#define    PCIF            5       //
#define    INTF0           6       // External Interrupt Flag 0
#define    INTF1           7       // External Interrupt Flag 1


/* ***** USART ************************ */
/* UDR - USART I/O Data Register */
#define    UDR0            0       // USART I/O Data Register bit 0
#define    UDR1            1       // USART I/O Data Register bit 1
#define    UDR2            2       // USART I/O Data Register bit 2
#define    UDR3            3       // USART I/O Data Register bit 3
#define    UDR4            4       // USART I/O Data Register bit 4
#define    UDR5            5       // USART I/O Data Register bit 5
#define    UDR6            6       // USART I/O Data Register bit 6
#define    UDR7            7       // USART I/O Data Register bit 7

/* UCSRA - USART Control and Status Register A */
#define    USR             UCSRA   // For compatibility
#define    MPCM            0       // Multi-processor Communication Mode
#define    U2X             1       // Double the USART Transmission Speed
#define    UPE             2       // USART Parity Error
#define    PE              UPE     // For compatibility
#define    DOR             3       // Data overRun
#define    FE              4       // Framing Error
#define    UDRE            5       // USART Data Register Empty
#define    TXC             6       // USART Transmitt Complete
#define    RXC             7       // USART Receive Complete

/* UCSRB - USART Control and Status Register B */
#define    UCR             UCSRB   // For compatibility
#define    TXB8            0       // Transmit Data Bit 8
#define    RXB8            1       // Receive Data Bit 8
#define    UCSZ2           2       // Character Size
#define    CHR9            UCSZ2   // For compatibility
#define    TXEN            3       // Transmitter Enable
#define    RXEN            4       // Receiver Enable
#define    UDRIE           5       // USART Data register Empty Interrupt Enable
#define    TXCIE           6       // TX Complete Interrupt Enable
#define    RXCIE           7       // RX Complete Interrupt Enable

/* UCSRC - USART Control and Status Register C */
#define    UCPOL           0       // Clock Polarity
#define    UCSZ0           1       // Character Size Bit 0
#define    UCSZ1           2       // Character Size Bit 1
#define    USBS            3       // Stop Bit Select
#define    UPM0            4       // Parity Mode Bit 0
#define    UPM1            5       // Parity Mode Bit 1
#define    UMSEL           6       // USART Mode Select

#define    UBRR            UBRRL   // For compatibility

/* ***** ANALOG_COMPARATOR ************ */
/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIC            2       //
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Compare Output
#define    ACBG            6       // Analog Comparator Bandgap Select
#define    ACD             7       // Analog Comparator Disable

/* DIDR - Digital Input Disable Register 1 */
#define    AIN0D           0       // AIN0 Digital Input Disable
#define    AIN1D           1       // AIN1 Digital Input Disable


/* ***** PORTD ************************ */
/* PORTD - Data Register, Port D */
#define    PORTD0          0       //
#define    PORTD1          1       //
#define    PORTD2          2       //
#define    PORTD3          3       //
#define    PORTD4          4       //
#define    PORTD5          5       //
#define    PORTD6          6       //

/* DDRD - Data Direction Register, Port D */
#define    DDD0            0       //
#define    DDD1            1       //
#define    DDD2            2       //
#define    DDD3            3       //
#define    DDD4            4       //
#define    DDD5            5       //
#define    DDD6            6       //

/* PIND - Input Pins, Port D */
#define    PIND0           0       //
#define    PIND1           1       //
#define    PIND2           2       //
#define    PIND3           3       //
#define    PIND4           4       //
#define    PIND5           5       //
#define    PIND6           6       //


/* ***** EEPROM *********************** */
/* EEAR - EEPROM Read/Write Access */
#define    EEARL           EEAR    // For compatibility
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
#define    EEPE            1       // EEPROM Write Enable
#define    EEWE            EEPE    // For compatibility
#define    EEMPE           2       // EEPROM Master Write Enable
#define    EEMWE           EEMPE   // For compatibility
#define    EERIE           3       // EEProm Ready Interrupt Enable
#define    EEPM0           4       //
#define    EEPM1           5       //


/* ***** PORTA ************************ */
/* PORTA - Port A Data Register */
#define    PORTA0          0       // Port A Data Register bit 0
#define    PORTA1          1       // Port A Data Register bit 1
#define    PORTA2          2       // Port A Data Register bit 2

/* DDRA - Port A Data Direction Register */
#define    DDA0            0       // Data Direction Register, Port A, bit 0
#define    DDA1            1       // Data Direction Register, Port A, bit 1
#define    DDA2            2       // Data Direction Register, Port A, bit 2

/* PINA - Port A Input Pins */
#define    PINA0           0       // Input Pins, Port A bit 0
#define    PINA1           1       // Input Pins, Port A bit 1
#define    PINA2           2       // Input Pins, Port A bit 2


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

/* SPMCSR - Store Program Memory Control and Status register */
#define    SPMEN           0       // Store Program Memory Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    RFLB            3       // Read Fuse and Lock Bits
#define    CTPB            4       // Clear Temporary Page Buffer

/* MCUCR - MCU Control Register */
#define    ISC00           0       // Interrupt Sense Control 0 bit 0
#define    ISC01           1       // Interrupt Sense Control 0 bit 1
#define    ISC10           2       // Interrupt Sense Control 1 bit 0
#define    ISC11           3       // Interrupt Sense Control 1 bit 1
#define    SM0             4       // Sleep Mode Select Bit 0
#define    SM              SM0     // For compatibility
#define    SE              5       // Sleep Enable
#define    SM1             6       // Sleep Mode Select Bit 1
#define    PUD             7       // Pull-up Disable

/* CLKPR - Clock Prescale Register */
#define    CLKPS0          0       // Clock Prescaler Select Bit 0
#define    CLKPS1          1       // Clock Prescaler Select Bit 1
#define    CLKPS2          2       // Clock Prescaler Select Bit 2
#define    CLKPS3          3       // Clock Prescaler Select Bit 3
#define    CLKPCE          7       // Clock Prescaler Change Enable

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

/* GTCCR - General Timer Counter Control Register */
#define    SFIOR           GTCCR   // For compatibility
#define    PSR10           0       //

/* PCMSK - Pin-Change Mask register */
#define    PCINT0          0       // Pin-Change Interrupt 0
#define    PCINT1          1       // Pin-Change Interrupt 1
#define    PCINT2          2       // Pin-Change Interrupt 2
#define    PCINT3          3       // Pin-Change Interrupt 3
#define    PCINT4          4       // Pin-Change Interrupt 4
#define    PCINT5          5       // Pin-Change Interrupt 5
#define    PCINT6          6       // Pin-Change Interrupt 6
#define    PCINT7          7       // Pin-Change Interrupt 7

/* GPIOR2 - General Purpose I/O Register 2 */
#define    GPIOR20         0       // General Purpose I/O Register 2 bit 0
#define    GPIOR21         1       // General Purpose I/O Register 2 bit 1
#define    GPIOR22         2       // General Purpose I/O Register 2 bit 2
#define    GPIOR23         3       // General Purpose I/O Register 2 bit 3
#define    GPIOR24         4       // General Purpose I/O Register 2 bit 4
#define    GPIOR25         5       // General Purpose I/O Register 2 bit 5
#define    GPIOR26         6       // General Purpose I/O Register 2 bit 6
#define    GPIOR27         7       // General Purpose I/O Register 2 bit 7

/* GPIOR1 - General Purpose I/O Register 1 */
#define    GPIOR10         0       // General Purpose I/O Register 1 bit 0
#define    GPIOR11         1       // General Purpose I/O Register 1 bit 1
#define    GPIOR12         2       // General Purpose I/O Register 1 bit 2
#define    GPIOR13         3       // General Purpose I/O Register 1 bit 3
#define    GPIOR14         4       // General Purpose I/O Register 1 bit 4
#define    GPIOR15         5       // General Purpose I/O Register 1 bit 5
#define    GPIOR16         6       // General Purpose I/O Register 1 bit 6
#define    GPIOR17         7       // General Purpose I/O Register 1 bit 7

/* GPIOR0 - General Purpose I/O Register 0 */
#define    GPIOR00         0       // General Purpose I/O Register 0 bit 0
#define    GPIOR01         1       // General Purpose I/O Register 0 bit 1
#define    GPIOR02         2       // General Purpose I/O Register 0 bit 2
#define    GPIOR03         3       // General Purpose I/O Register 0 bit 3
#define    GPIOR04         4       // General Purpose I/O Register 0 bit 4
#define    GPIOR05         5       // General Purpose I/O Register 0 bit 5
#define    GPIOR06         6       // General Purpose I/O Register 0 bit 6
#define    GPIOR07         7       // General Purpose I/O Register 0 bit 7


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

#endif
