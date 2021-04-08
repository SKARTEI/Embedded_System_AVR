/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

AT90S4434, AT90S8535 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __90S8535_BITS_INCLUDED__
#define __90S8535_BITS_INCLUDED__

/* ***** TIMER_COUNTER_0 ************** */
/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TOIE0           0       // Timer/Counter0 Overflow Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag register */
#define    TOV0            0       // Timer/Counter0 Overflow Flag

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


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TOIE1           2       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1B          3       // Timer/Counter1 Output CompareB Match Interrupt Enable
#define    OCIE1A          4       // Timer/Counter1 Output CompareA Match Interrupt Enable
#define    TICIE1          5       // Timer/Counter1 Input Capture Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag register */
#define    TOV1            2       // Timer/Counter1 Overflow Flag
#define    OCF1B           3       // Output Compare Flag 1B
#define    OCF1A           4       // Output Compare Flag 1A
#define    ICF1            5       // Input Capture Flag 1

/* TCCR1A - Timer/Counter1 Control Register A */
#define    PWM10           0       // Pulse Width Modulator Select Bit 0
#define    PWM11           1       // Pulse Width Modulator Select Bit 1
#define    COM1B0          4       // Compare Output Mode 1B, bit 0
#define    COM1B1          5       // Compare Output Mode 1B, bit 1
#define    COM1A0          6       // Compare Ouput Mode 1A, bit 0
#define    COM1A1          7       // Compare Output Mode 1A, bit 1

/* TCCR1B - Timer/Counter1 Control Register B */
#define    CS10            0       // Clock Select1 bit 0
#define    CS11            1       // Clock Select1 bit 1
#define    CS12            2       // Clock Select1 bit 2
#define    CTC1            3       // Clear Timer/Counter1 on Compare Match
#define    ICES1           6       // Input Capture 1 Edge Select
#define    ICNC1           7       // Input Capture 1 Noise Canceler


/* ***** TIMER_COUNTER_2 ************** */
/* TCCR2 - Timer/Counter Control Register */
#define    CS20            0       // Clock Select
#define    CS21            1       // Clock Select
#define    CS22            2       // Clock Select
#define    CTC2            3       // Clear Timer/Counter Compare Match
#define    COM20           4       // Compare Match Output Mode
#define    COM21           5       // Compare Match Output Mode
#define    PWM2            6       // Pulse Width Modulator Enable

/* TCNT2 - Timer/Counter Register */
#define    TCNT2_0         0       // Timer/Counter Register Bit 0
#define    TCNT2_1         1       // Timer/Counter Register Bit 1
#define    TCNT2_2         2       // Timer/Counter Register Bit 2
#define    TCNT2_3         3       // Timer/Counter Register Bit 3
#define    TCNT2_4         4       // Timer/Counter Register Bit 4
#define    TCNT2_5         5       // Timer/Counter Register Bit 5
#define    TCNT2_6         6       // Timer/Counter Register Bit 6
#define    TCNT2_7         7       // Timer/Counter Register Bit 7

/* OCR2 - Output Compare Register */
#define    OCR2_0          0       // Output Compare Register Bit 0
#define    OCR2_1          1       // Output Compare Register Bit 1
#define    OCR2_2          2       // Output Compare Register Bit 2
#define    OCR2_3          3       // Output Compare Register Bit 3
#define    OCR2_4          4       // Output Compare Register Bit 4
#define    OCR2_5          5       // Output Compare Register Bit 5
#define    OCR2_6          6       // Output Compare Register Bit 6
#define    OCR2_7          7       // Output Compare Register Bit 7

/* ASSR - Asynchronous Status Register */
#define    TCR2UB          0       // Timer/Counter Control Register2 Update Busy
#define    OCR2UB          1       // Output Compare Register2 Update Busy
#define    TCN2UB          2       // Timer/Counter2 Update Busy
#define    AS2             3       // Asynchronous Timer 2

/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TOIE2           6       // Timer/Counter2 Overflow Interrupt Enable
#define    OCIE2           7       // Timer/Counter2 Output Compare Match Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag Register */
#define    TOV2            6       // Timer/Counter2 Overflow Flag
#define    OCF2            7       // Output Compare Flag 2


/* ***** UART ************************* */
/* UDR - UART I/O Data Register */
#define    UDR0            0       // UART I/O Data Register bit 0
#define    UDR1            1       // UART I/O Data Register bit 1
#define    UDR2            2       // UART I/O Data Register bit 2
#define    UDR3            3       // UART I/O Data Register bit 3
#define    UDR4            4       // UART I/O Data Register bit 4
#define    UDR5            5       // UART I/O Data Register bit 5
#define    UDR6            6       // UART I/O Data Register bit 6
#define    UDR7            7       // UART I/O Data Register bit 7

/* USR - UART Status Register */
#define    DOR             3       // Data overRun
#define    FE              4       // Framing Error
#define    UDRE            5       // UART Data Register Empty
#define    TXC             6       // UART Transmit Complete
#define    RXC             7       // UART Receive Complete

/* UCR - UART Control Register */
#define    TXB8            0       // Transmit Data Bit 8
#define    RXB8            1       // Receive Data Bit 8
#define    CHR9            2       // 9-bit Characters
#define    TXEN            3       // Transmitter Enable
#define    RXEN            4       // Receiver Enable
#define    UDRIE           5       // UART Data Register Empty Interrupt Enable
#define    TXCIE           6       // TX Complete Interrupt Enable
#define    RXCIE           7       // RX Complete Interrupt Enable

/* UBRR - UART BAUD Rate Register */
#define    UBRR0           0       // UART Baud Rate Register bit 0
#define    UBRR1           1       // UART Baud Rate Register bit 1
#define    UBRR2           2       // UART Baud Rate Register bit 2
#define    UBRR3           3       // UART Baud Rate Register bit 3
#define    UBRR4           4       // UART Baud Rate Register bit 4
#define    UBRR5           5       // UART Baud Rate Register bit 5
#define    UBRR6           6       // UART Baud Rate Register bit 6
#define    UBRR7           7       // UART Baud Rate Register bit 7


/* ***** SPI ************************** */
/* SPDR - SPI Data Register */
#define    SPDR0           0       // SPI Data Register bit 0
#define    SPDR1           1       // SPI Data Register bit 1
#define    SPDR2           2       // SPI Data Register bit 2
#define    SPDR3           3       // SPI Data Register bit 3
#define    SPDR4           4       // SPI Data Register bit 4
#define    SPDR5           5       // SPI Data Register bit 5
#define    SPDR6           6       // SPI Data Register bit 6
#define    SPDR7           7       // SPI Data Register bit 7

/* SPSR - SPI Status Register */
#define    WCOL            6       // Write Collision Flag
#define    SPIF            7       // SPI Interrupt Flag

/* SPCR - SPI Control Register */
#define    SPR0            0       // SPI Clock Rate Select 0
#define    SPR1            1       // SPI Clock Rate Select 1
#define    CPHA            2       // Clock Phase
#define    CPOL            3       // Clock polarity
#define    MSTR            4       // Master/Slave Select
#define    DORD            5       // Data Order
#define    SPE             6       // SPI Enable
#define    SPIE            7       // SPI Interrupt Enable


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


/* ***** PORTC ************************ */
/* PORTC - Port C Data Register */
#define    PORTC0          0       // Port C Data Register bit 0
#define    PORTC1          1       // Port C Data Register bit 1
#define    PORTC2          2       // Port C Data Register bit 2
#define    PORTC3          3       // Port C Data Register bit 3
#define    PORTC4          4       // Port C Data Register bit 4
#define    PORTC5          5       // Port C Data Register bit 5
#define    PORTC6          6       // Port C Data Register bit 6
#define    PORTC7          7       // Port C Data Register bit 7

/* DDRC - Port C Data Direction Register */
#define    DDC0            0       // Port C Data Direction Register bit 0
#define    DDC1            1       // Port C Data Direction Register bit 1
#define    DDC2            2       // Port C Data Direction Register bit 2
#define    DDC3            3       // Port C Data Direction Register bit 3
#define    DDC4            4       // Port C Data Direction Register bit 4
#define    DDC5            5       // Port C Data Direction Register bit 5
#define    DDC6            6       // Port C Data Direction Register bit 6
#define    DDC7            7       // Port C Data Direction Register bit 7

/* PINC - Port C Input Pins */
#define    PINC0           0       // Port C Input Pins bit 0
#define    PINC1           1       // Port C Input Pins bit 1
#define    PINC2           2       // Port C Input Pins bit 2
#define    PINC3           3       // Port C Input Pins bit 3
#define    PINC4           4       // Port C Input Pins bit 4
#define    PINC5           5       // Port C Input Pins bit 5
#define    PINC6           6       // Port C Input Pins bit 6
#define    PINC7           7       // Port C Input Pins bit 7


/* ***** PORTD ************************ */
/* PORTD - Port D Data Register */
#define    PORTD0          0       // Port D Data Register bit 0
#define    PORTD1          1       // Port D Data Register bit 1
#define    PORTD2          2       // Port D Data Register bit 2
#define    PORTD3          3       // Port D Data Register bit 3
#define    PORTD4          4       // Port D Data Register bit 4
#define    PORTD5          5       // Port D Data Register bit 5
#define    PORTD6          6       // Port D Data Register bit 6
#define    PORTD7          7       // Port D Data Register bit 7

/* DDRD - Port D Data Direction Register */
#define    DDD0            0       // Port D Data Direction Register bit 0
#define    DDD1            1       // Port D Data Direction Register bit 1
#define    DDD2            2       // Port D Data Direction Register bit 2
#define    DDD3            3       // Port D Data Direction Register bit 3
#define    DDD4            4       // Port D Data Direction Register bit 4
#define    DDD5            5       // Port D Data Direction Register bit 5
#define    DDD6            6       // Port D Data Direction Register bit 6
#define    DDD7            7       // Port D Data Direction Register bit 7

/* PIND - Port D Input Pins */
#define    PIND0           0       // Port D Input Pins bit 0
#define    PIND1           1       // Port D Input Pins bit 1
#define    PIND2           2       // Port D Input Pins bit 2
#define    PIND3           3       // Port D Input Pins bit 3
#define    PIND4           4       // Port D Input Pins bit 4
#define    PIND5           5       // Port D Input Pins bit 5
#define    PIND6           6       // Port D Input Pins bit 6
#define    PIND7           7       // Port D Input Pins bit 7


/* ***** ANALOG_COMPARATOR ************ */
/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIC            2       // Analog Comparator Input Capture Enable
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Comparator Output
#define    ACD             7       // Analog Comparator Disable


/* ***** AD_CONVERTER ***************** */
/* ADMUX - The ADC multiplexer Selection Register */
#define    MUX0            0       // Analog Channel and Gain Selection Bits
#define    MUX1            1       // Analog Channel and Gain Selection Bits
#define    MUX2            2       // Analog Channel and Gain Selection Bits

/* ADCSR - The ADC Control and Status register */
#define    ADPS0           0       // ADC  Prescaler Select Bits
#define    ADPS1           1       // ADC  Prescaler Select Bits
#define    ADPS2           2       // ADC  Prescaler Select Bits
#define    ADIE            3       // ADC Interrupt Enable
#define    ADIF            4       // ADC Interrupt Flag
#define    ADFR            5       // ADC  Free Running Select
#define    ADSC            6       // ADC Start Conversion
#define    ADEN            7       // ADC Enable

/* ADCH - ADC Data Register High Byte */
#define    ADC8            0       // ADC Data Register High Byte Bit 0
#define    ADC9            1       // ADC Data Register High Byte Bit 1

/* ADCL - ADC Data Register Low Byte */
#define    ADC0            0       // ADC Data Register Low Byte Bit 0
#define    ADC1            1       // ADC Data Register Low Byte Bit 1
#define    ADC2            2       // ADC Data Register Low Byte Bit 2
#define    ADC3            3       // ADC Data Register Low Byte Bit 3
#define    ADC4            4       // ADC Data Register Low Byte Bit 4
#define    ADC5            5       // ADC Data Register Low Byte Bit 5
#define    ADC6            6       // ADC Data Register Low Byte Bit 6
#define    ADC7            7       // ADC Data Register Low Byte Bit 7


/* ***** WATCHDOG ********************* */
/* WDTCR - Watchdog Timer Control Register */
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDTOE           4       // RW
#define    WDDE            WDTOE   // For compatibility


/* ***** EEPROM *********************** */
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
#define    EEWEE           EEMWE   // For compatibility
#define    EERIE           3       // EEPROM Ready Interrupt Enable


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
#define    ISC00           0       // Interrupt Sense Control 0 bit 0
#define    ISC01           1       // Interrupt Sense Control 0 bit 1
#define    ISC10           2       // Interrupt Sense Control 1 bit 0
#define    ISC11           3       // Interrupt Sense Control 1 bit 1
#define    SM0             4       // Sleep Mode Select 0
#define    SM1             5       // Sleep Mode Select 1
#define    SE              6       // Sleep Enable

/* MCUSR -  */
#define    PORF            0       // Power-on Reset Flag
#define    EXTRF           1       // External Reset Flag


/* ***** EXTERNAL_INTERRUPT *********** */
/* GIMSK - General Interrupt Mask Register */
#define    INT0            6       // External Interrupt Request 0 Enable
#define    INT1            7       // External Interrupt Request 1 Enable

/* GIFR - General Interrupt Flag register */
#define    INTF0           6       // External Interrupt Flag 0
#define    INTF1           7       // External Interrupt Flag 1

#endif

