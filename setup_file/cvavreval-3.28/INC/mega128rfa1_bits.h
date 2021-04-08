/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.

ATmega128RFA1 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __MEGA128RFA1_BITS_INCLUDED__
#define __MEGA128RFA1_BITS_INCLUDED__

/* ***** ANALOG_COMPARATOR ************ */
/* ADCSRB - ADC Control and Status Register B */
#define    ACME            6       // Analog Comparator Multiplexer Enable

/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select
#define    ACIC            2       // Analog Comparator Input Capture Enable
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Compare Output
#define    ACBG            6       // Analog Comparator Bandgap Select
#define    ACD             7       // Analog Comparator Disable

/* DIDR1 - Digital Input Disable Register 1 */
#define    AIN0D           0       // AIN0 Digital Input Disable
#define    AIN1D           1       // AIN1 Digital Input Disable


/* ***** USART0 *********************** */
/* UDR0 - USART0 I/O Data Register */
#define    UDR00           0       // USART I/O Data Register
#define    UDR01           1       // USART I/O Data Register
#define    UDR02           2       // USART I/O Data Register
#define    UDR03           3       // USART I/O Data Register
#define    UDR04           4       // USART I/O Data Register
#define    UDR05           5       // USART I/O Data Register
#define    UDR06           6       // USART I/O Data Register
#define    UDR07           7       // USART I/O Data Register

/* UCSR0A - USART0 Control and Status Register A */
#define    MPCM0           0       // Multi-processor Communication Mode
#define    U2X0            1       // Double the USART Transmission Speed
#define    UPE0            2       // USART Parity Error
#define    DOR0            3       // Data OverRun
#define    FE0             4       // Frame Error
#define    UDRE0           5       // USART Data Register Empty
#define    TXC0            6       // USART Transmit Complete
#define    RXC0            7       // USART Receive Complete

/* UCSR0B - USART0 Control and Status Register B */
#define    TXB80           0       // Transmit Data Bit 8
#define    RXB80           1       // Receive Data Bit 8
#define    UCSZ02          2       // Character Size
#define    TXEN0           3       // Transmitter Enable
#define    RXEN0           4       // Receiver Enable
#define    UDRIE0          5       // USART Data Register Empty Interrupt Enable
#define    TXCIE0          6       // TX Complete Interrupt Enable
#define    RXCIE0          7       // RX Complete Interrupt Enable

/* UCSR0C - USART0 Control and Status Register C */
#define    UCPOL0          0       // Clock Polarity
#define    UCSZ00          1       // Character Size
#define    UCPHA0          UCSZ00  // For compatibility
#define    UCSZ01          2       // Character Size
#define    UDORD0          UCSZ01  // For compatibility
#define    USBS0           3       // Stop Bit Select
#define    UPM00           4       // Parity Mode
#define    UPM01           5       // Parity Mode
#define    UMSEL00         6       // USART Mode Select
#define    UMSEL0          UMSEL00 // For compatibility
#define    UMSEL01         7       // USART Mode Select
#define    UMSEL1          UMSEL01 // For compatibility

/* UBRR0H - USART0 Baud Rate Register High Byte */
#define    UBRR8           0       // USART Baud Rate Register
#define    UBRR9           1       // USART Baud Rate Register
#define    UBRR10          2       // USART Baud Rate Register
#define    UBRR11          3       // USART Baud Rate Register

/* UBRR0L - USART0 Baud Rate Register Low Byte */
#define    UBRR0           0       // USART Baud Rate Register
#define    UBRR1           1       // USART Baud Rate Register
#define    UBRR2           2       // USART Baud Rate Register
#define    UBRR3           3       // USART Baud Rate Register
#define    UBRR4           4       // USART Baud Rate Register
#define    UBRR5           5       // USART Baud Rate Register
#define    UBRR6           6       // USART Baud Rate Register
#define    UBRR7           7       // USART Baud Rate Register


/* ***** USART1 *********************** */
/* UDR1 - USART1 I/O Data Register */
#define    UDR10           0       // USART I/O Data Register
#define    UDR11           1       // USART I/O Data Register
#define    UDR12           2       // USART I/O Data Register
#define    UDR13           3       // USART I/O Data Register
#define    UDR14           4       // USART I/O Data Register
#define    UDR15           5       // USART I/O Data Register
#define    UDR16           6       // USART I/O Data Register
#define    UDR17           7       // USART I/O Data Register

/* UCSR1A - USART1 Control and Status Register A */
#define    MPCM1           0       // Multi-processor Communication Mode
#define    U2X1            1       // Double the USART Transmission Speed
#define    UPE1            2       // USART Parity Error
#define    DOR1            3       // Data OverRun
#define    FE1             4       // Frame Error
#define    UDRE1           5       // USART Data Register Empty
#define    TXC1            6       // USART Transmit Complete
#define    RXC1            7       // USART Receive Complete

/* UCSR1B - USART1 Control and Status Register B */
#define    TXB81           0       // Transmit Data Bit 8
#define    RXB81           1       // Receive Data Bit 8
#define    UCSZ12          2       // Character Size
#define    TXEN1           3       // Transmitter Enable
#define    RXEN1           4       // Receiver Enable
#define    UDRIE1          5       // USART Data Register Empty Interrupt Enable
#define    TXCIE1          6       // TX Complete Interrupt Enable
#define    RXCIE1          7       // RX Complete Interrupt Enable

/* UCSR1C - USART1 Control and Status Register C */
#define    UCPOL1          0       // Clock Polarity
#define    UCSZ10          1       // Character Size
#define    UCPHA1          UCSZ10  // For compatibility
#define    UCSZ11          2       // Character Size
#define    UDORD1          UCSZ11  // For compatibility
#define    USBS1           3       // Stop Bit Select
#define    UPM10           4       // Parity Mode
#define    UPM11           5       // Parity Mode
#define    UMSEL10         6       // USART Mode Select
#define    UMSEL11         7       // USART Mode Select

/* UBRR1H - USART1 Baud Rate Register High Byte */
//#define  UBRR8           0       // USART Baud Rate Register
//#define  UBRR9           1       // USART Baud Rate Register
//#define  UBRR10          2       // USART Baud Rate Register
//#define  UBRR11          3       // USART Baud Rate Register

/* UBRR1L - USART1 Baud Rate Register Low Byte */
//#define  UBRR0           0       // USART Baud Rate Register
//#define  UBRR1           1       // USART Baud Rate Register
//#define  UBRR2           2       // USART Baud Rate Register
//#define  UBRR3           3       // USART Baud Rate Register
//#define  UBRR4           4       // USART Baud Rate Register
//#define  UBRR5           5       // USART Baud Rate Register
//#define  UBRR6           6       // USART Baud Rate Register
//#define  UBRR7           7       // USART Baud Rate Register


/* ***** TWI ************************** */
/* TWAMR - TWI (Slave) Address Mask Register */
#define    TWAM0           1       // TWI Address Mask
#define    TWAMR0          TWAM0   // For compatibility
#define    TWAM1           2       // TWI Address Mask
#define    TWAMR1          TWAM1   // For compatibility
#define    TWAM2           3       // TWI Address Mask
#define    TWAMR2          TWAM2   // For compatibility
#define    TWAM3           4       // TWI Address Mask
#define    TWAMR3          TWAM3   // For compatibility
#define    TWAM4           5       // TWI Address Mask
#define    TWAMR4          TWAM4   // For compatibility
#define    TWAM5           6       // TWI Address Mask
#define    TWAMR5          TWAM5   // For compatibility
#define    TWAM6           7       // TWI Address Mask
#define    TWAMR6          TWAM6   // For compatibility

/* TWBR - TWI Bit Rate Register */
#define    TWBR0           0       // TWI Bit Rate Register Value
#define    TWBR1           1       // TWI Bit Rate Register Value
#define    TWBR2           2       // TWI Bit Rate Register Value
#define    TWBR3           3       // TWI Bit Rate Register Value
#define    TWBR4           4       // TWI Bit Rate Register Value
#define    TWBR5           5       // TWI Bit Rate Register Value
#define    TWBR6           6       // TWI Bit Rate Register Value
#define    TWBR7           7       // TWI Bit Rate Register Value

/* TWCR - TWI Control Register */
#define    TWIE            0       // TWI Interrupt Enable
#define    TWEN            2       // TWI Enable Bit
#define    TWWC            3       // TWI Write Collision Flag
#define    TWSTO           4       // TWI STOP Condition Bit
#define    TWSTA           5       // TWI START Condition Bit
#define    TWEA            6       // TWI Enable Acknowledge Bit
#define    TWINT           7       // TWI Interrupt Flag

/* TWSR - TWI Status Register */
#define    TWPS0           0       // TWI Prescaler Bits
#define    TWPS1           1       // TWI Prescaler Bits
#define    TWS3            3       // TWI Status
#define    TWS4            4       // TWI Status
#define    TWS5            5       // TWI Status
#define    TWS6            6       // TWI Status
#define    TWS7            7       // TWI Status

/* TWDR - TWI Data Register */
#define    TWD0            0       // TWI Data Register Byte
#define    TWD1            1       // TWI Data Register Byte
#define    TWD2            2       // TWI Data Register Byte
#define    TWD3            3       // TWI Data Register Byte
#define    TWD4            4       // TWI Data Register Byte
#define    TWD5            5       // TWI Data Register Byte
#define    TWD6            6       // TWI Data Register Byte
#define    TWD7            7       // TWI Data Register Byte

/* TWAR - TWI (Slave) Address Register */
#define    TWGCE           0       // TWI General Call Recognition Enable Bit
#define    TWA0            1       // TWI (Slave) Address
#define    TWA1            2       // TWI (Slave) Address
#define    TWA2            3       // TWI (Slave) Address
#define    TWA3            4       // TWI (Slave) Address
#define    TWA4            5       // TWI (Slave) Address
#define    TWA5            6       // TWI (Slave) Address
#define    TWA6            7       // TWI (Slave) Address


/* ***** SPI ************************** */
/* SPDR - SPI Data Register */
#define    SPDR0           0       // SPI Data Register
#define    SPDR1           1       // SPI Data Register
#define    SPDR2           2       // SPI Data Register
#define    SPDR3           3       // SPI Data Register
#define    SPDR4           4       // SPI Data Register
#define    SPDR5           5       // SPI Data Register
#define    SPDR6           6       // SPI Data Register
#define    SPDR7           7       // SPI Data Register

/* SPSR - SPI Status Register */
#define    SPI2X           0       // Double SPI Speed Bit
#define    WCOL            6       // Write Collision Flag
#define    SPIF            7       // SPI Interrupt Flag

/* SPCR - SPI Control Register */
#define    SPR0            0       // SPI Clock Rate Select 1 and 0
#define    SPR1            1       // SPI Clock Rate Select 1 and 0
#define    CPHA            2       // Clock Phase
#define    CPOL            3       // Clock polarity
#define    MSTR            4       // Master/Slave Select
#define    DORD            5       // Data Order
#define    SPE             6       // SPI Enable
#define    SPIE            7       // SPI Interrupt Enable


/* ***** PORTA ************************ */
/* PORTA - Port A Data Register */
#define    PORTA0          0       // Port A Data Register Value
#define    PORTA1          1       // Port A Data Register Value
#define    PORTA2          2       // Port A Data Register Value
#define    PORTA3          3       // Port A Data Register Value
#define    PORTA4          4       // Port A Data Register Value
#define    PORTA5          5       // Port A Data Register Value
#define    PORTA6          6       // Port A Data Register Value
#define    PORTA7          7       // Port A Data Register Value

/* DDRA - Port A Data Direction Register */
#define    DDA0            0       // Port A Data Direction Register Value
#define    DDA1            1       // Port A Data Direction Register Value
#define    DDA2            2       // Port A Data Direction Register Value
#define    DDA3            3       // Port A Data Direction Register Value
#define    DDA4            4       // Port A Data Direction Register Value
#define    DDA5            5       // Port A Data Direction Register Value
#define    DDA6            6       // Port A Data Direction Register Value
#define    DDA7            7       // Port A Data Direction Register Value

/* PINA - Port A Input Pins Address */
#define    PINA0           0       // Port A Input Pins
#define    PINA1           1       // Port A Input Pins
#define    PINA2           2       // Port A Input Pins
#define    PINA3           3       // Port A Input Pins
#define    PINA4           4       // Port A Input Pins
#define    PINA5           5       // Port A Input Pins
#define    PINA6           6       // Port A Input Pins
#define    PINA7           7       // Port A Input Pins


/* ***** PORTB ************************ */
/* PORTB - Port B Data Register */
#define    PORTB0          0       // Port B Data Register Value
#define    PORTB1          1       // Port B Data Register Value
#define    PORTB2          2       // Port B Data Register Value
#define    PORTB3          3       // Port B Data Register Value
#define    PORTB4          4       // Port B Data Register Value
#define    PORTB5          5       // Port B Data Register Value
#define    PORTB6          6       // Port B Data Register Value
#define    PORTB7          7       // Port B Data Register Value

/* DDRB - Port B Data Direction Register */
#define    DDB0            0       // Port B Data Direction Register Value
#define    DDB1            1       // Port B Data Direction Register Value
#define    DDB2            2       // Port B Data Direction Register Value
#define    DDB3            3       // Port B Data Direction Register Value
#define    DDB4            4       // Port B Data Direction Register Value
#define    DDB5            5       // Port B Data Direction Register Value
#define    DDB6            6       // Port B Data Direction Register Value
#define    DDB7            7       // Port B Data Direction Register Value

/* PINB - Port B Input Pins Address */
#define    PINB0           0       // Port B Input Pins Value
#define    PINB1           1       // Port B Input Pins Value
#define    PINB2           2       // Port B Input Pins Value
#define    PINB3           3       // Port B Input Pins Value
#define    PINB4           4       // Port B Input Pins Value
#define    PINB5           5       // Port B Input Pins Value
#define    PINB6           6       // Port B Input Pins Value
#define    PINB7           7       // Port B Input Pins Value


/* ***** PORTC ************************ */
/* PORTC - Port C Data Register */
#define    PORTC0          0       // Port C Data Register Value
#define    PORTC1          1       // Port C Data Register Value
#define    PORTC2          2       // Port C Data Register Value
#define    PORTC3          3       // Port C Data Register Value
#define    PORTC4          4       // Port C Data Register Value
#define    PORTC5          5       // Port C Data Register Value
#define    PORTC6          6       // Port C Data Register Value
#define    PORTC7          7       // Port C Data Register Value

/* DDRC - Port C Data Direction Register */
#define    DDC0            0       // Port C Data Direction Register Value
#define    DDC1            1       // Port C Data Direction Register Value
#define    DDC2            2       // Port C Data Direction Register Value
#define    DDC3            3       // Port C Data Direction Register Value
#define    DDC4            4       // Port C Data Direction Register Value
#define    DDC5            5       // Port C Data Direction Register Value
#define    DDC6            6       // Port C Data Direction Register Value
#define    DDC7            7       // Port C Data Direction Register Value

/* PINC - Port C Input Pins Address */
#define    PINC0           0       // Port C Input Pins
#define    PINC1           1       // Port C Input Pins
#define    PINC2           2       // Port C Input Pins
#define    PINC3           3       // Port C Input Pins
#define    PINC4           4       // Port C Input Pins
#define    PINC5           5       // Port C Input Pins
#define    PINC6           6       // Port C Input Pins
#define    PINC7           7       // Port C Input Pins


/* ***** PORTD ************************ */
/* PORTD - Port D Data Register */
#define    PORTD0          0       // Port D Data Register Value
#define    PORTD1          1       // Port D Data Register Value
#define    PORTD2          2       // Port D Data Register Value
#define    PORTD3          3       // Port D Data Register Value
#define    PORTD4          4       // Port D Data Register Value
#define    PORTD5          5       // Port D Data Register Value
#define    PORTD6          6       // Port D Data Register Value
#define    PORTD7          7       // Port D Data Register Value

/* DDRD - Port D Data Direction Register */
#define    DDD0            0       // Port D Data Direction Register Value
#define    DDD1            1       // Port D Data Direction Register Value
#define    DDD2            2       // Port D Data Direction Register Value
#define    DDD3            3       // Port D Data Direction Register Value
#define    DDD4            4       // Port D Data Direction Register Value
#define    DDD5            5       // Port D Data Direction Register Value
#define    DDD6            6       // Port D Data Direction Register Value
#define    DDD7            7       // Port D Data Direction Register Value

/* PIND - Port D Input Pins Address */
#define    PIND0           0       // Port D Input Pins Value
#define    PIND1           1       // Port D Input Pins Value
#define    PIND2           2       // Port D Input Pins Value
#define    PIND3           3       // Port D Input Pins Value
#define    PIND4           4       // Port D Input Pins Value
#define    PIND5           5       // Port D Input Pins Value
#define    PIND6           6       // Port D Input Pins Value
#define    PIND7           7       // Port D Input Pins Value


/* ***** PORTE ************************ */
/* PORTE - Port E Data Register */
#define    PORTE0          0       // Port E Data Register Value
#define    PORTE1          1       // Port E Data Register Value
#define    PORTE2          2       // Port E Data Register Value
#define    PORTE3          3       // Port E Data Register Value
#define    PORTE4          4       // Port E Data Register Value
#define    PORTE5          5       // Port E Data Register Value
#define    PORTE6          6       // Port E Data Register Value
#define    PORTE7          7       // Port E Data Register Value

/* DDRE - Port E Data Direction Register */
#define    DDE0            0       // Port E Data Direction Register Value
#define    DDE1            1       // Port E Data Direction Register Value
#define    DDE2            2       // Port E Data Direction Register Value
#define    DDE3            3       // Port E Data Direction Register Value
#define    DDE4            4       // Port E Data Direction Register Value
#define    DDE5            5       // Port E Data Direction Register Value
#define    DDE6            6       // Port E Data Direction Register Value
#define    DDE7            7       // Port E Data Direction Register Value

/* PINE - Port E Input Pins Address */
#define    PINE0           0       // Port E Input Pins Value
#define    PINE1           1       // Port E Input Pins Value
#define    PINE2           2       // Port E Input Pins Value
#define    PINE3           3       // Port E Input Pins Value
#define    PINE4           4       // Port E Input Pins Value
#define    PINE5           5       // Port E Input Pins Value
#define    PINE6           6       // Port E Input Pins Value
#define    PINE7           7       // Port E Input Pins Value


/* ***** PORTF ************************ */
/* PORTF - Port F Data Register */
#define    PORTF0          0       // Port F Data Register Value
#define    PORTF1          1       // Port F Data Register Value
#define    PORTF2          2       // Port F Data Register Value
#define    PORTF3          3       // Port F Data Register Value
#define    PORTF4          4       // Port F Data Register Value
#define    PORTF5          5       // Port F Data Register Value
#define    PORTF6          6       // Port F Data Register Value
#define    PORTF7          7       // Port F Data Register Value

/* DDRF - Port F Data Direction Register */
#define    DDF0            0       // Port F Data Direction Register Value
#define    DDF1            1       // Port F Data Direction Register Value
#define    DDF2            2       // Port F Data Direction Register Value
#define    DDF3            3       // Port F Data Direction Register Value
#define    DDF4            4       // Port F Data Direction Register Value
#define    DDF5            5       // Port F Data Direction Register Value
#define    DDF6            6       // Port F Data Direction Register Value
#define    DDF7            7       // Port F Data Direction Register Value

/* PINF - Port F Input Pins Address */
#define    PINF0           0       // Port F Input Pins Value
#define    PINF1           1       // Port F Input Pins Value
#define    PINF2           2       // Port F Input Pins Value
#define    PINF3           3       // Port F Input Pins Value
#define    PINF4           4       // Port F Input Pins Value
#define    PINF5           5       // Port F Input Pins Value
#define    PINF6           6       // Port F Input Pins Value
#define    PINF7           7       // Port F Input Pins Value


/* ***** PORTG ************************ */
/* PORTG - Port G Data Register */
#define    PORTG0          0       // Port G Data Register Value
#define    PORTG1          1       // Port G Data Register Value
#define    PORTG2          2       // Port G Data Register Value
#define    PORTG3          3       // Port G Data Register Value
#define    PORTG4          4       // Port G Data Register Value
#define    PORTG5          5       // Port G Data Register Value

/* DDRG - Port G Data Direction Register */
#define    DDG0            0       // Port G Data Direction Register Value
#define    DDG1            1       // Port G Data Direction Register Value
#define    DDG2            2       // Port G Data Direction Register Value
#define    DDG3            3       // Port G Data Direction Register Value
#define    DDG4            4       // Port G Data Direction Register Value
#define    DDG5            5       // Port G Data Direction Register Value

/* PING - Port G Input Pins Address */
#define    PING0           0       // Port G Input Pins Value
#define    PING1           1       // Port G Input Pins Value
#define    PING2           2       // Port G Input Pins Value
#define    PING3           3       // Port G Input Pins Value
#define    PING4           4       // Port G Input Pins Value
#define    PING5           5       // Port G Input Pins Value


/* ***** TIMER_COUNTER_0 ************** */
/* TIMSK0 - Timer/Counter0 Interrupt Mask Register */
#define    TOIE0           0       // Timer/Counter0 Overflow Interrupt Enable
#define    OCIE0A          1       // Timer/Counter0 Output Compare Match A Interrupt Enable
#define    OCIE0B          2       // Timer/Counter0 Output Compare Match B Interrupt Enable

/* TIFR0 - Timer/Counter0 Interrupt Flag Register */
#define    TOV0            0       // Timer/Counter0 Overflow Flag
#define    OCF0A           1       // Timer/Counter0 Output Compare A Match Flag
#define    OCF0B           2       // Timer/Counter0 Output Compare B Match Flag

/* TCCR0A - Timer/Counter0 Control Register A */
#define    WGM00           0       // Waveform Generation Mode
#define    WGM01           1       // Waveform Generation Mode
#define    COM0B0          4       // Compare Match Output B Mode
#define    COM0B1          5       // Compare Match Output B Mode
#define    COM0A0          6       // Compare Match Output A Mode
#define    COM0A1          7       // Compare Match Output A Mode

/* TCCR0B - Timer/Counter0 Control Register B */
#define    CS00            0       // Clock Select
#define    CS01            1       // Clock Select
#define    CS02            2       // Clock Select
#define    WGM02           3       //
#define    FOC0B           6       // Force Output Compare B
#define    FOC0A           7       // Force Output Compare A

/* TCNT0 - Timer/Counter0 Register */
#define    TCNT0_0         0       // Timer/Counter0 Byte
#define    TCNT0_1         1       // Timer/Counter0 Byte
#define    TCNT0_2         2       // Timer/Counter0 Byte
#define    TCNT0_3         3       // Timer/Counter0 Byte
#define    TCNT0_4         4       // Timer/Counter0 Byte
#define    TCNT0_5         5       // Timer/Counter0 Byte
#define    TCNT0_6         6       // Timer/Counter0 Byte
#define    TCNT0_7         7       // Timer/Counter0 Byte

/* OCR0A - Timer/Counter0 Output Compare Register */
#define    OCR0A_0         0       // Output Compare Register
#define    OCR0A_1         1       // Output Compare Register
#define    OCR0A_2         2       // Output Compare Register
#define    OCR0A_3         3       // Output Compare Register
#define    OCR0A_4         4       // Output Compare Register
#define    OCR0A_5         5       // Output Compare Register
#define    OCR0A_6         6       // Output Compare Register
#define    OCR0A_7         7       // Output Compare Register

/* OCR0B - Timer/Counter0 Output Compare Register B */
#define    OCR0B_0         0       // Output Compare Register
#define    OCR0B_1         1       // Output Compare Register
#define    OCR0B_2         2       // Output Compare Register
#define    OCR0B_3         3       // Output Compare Register
#define    OCR0B_4         4       // Output Compare Register
#define    OCR0B_5         5       // Output Compare Register
#define    OCR0B_6         6       // Output Compare Register
#define    OCR0B_7         7       // Output Compare Register

/* GTCCR - General Timer/Counter Control Register */
#define    PSRSYNC         0       // Prescaler Reset for Synchronous Timer/Counters
#define    PSR10           PSRSYNC // For compatibility
#define    PSRASY          1       // Prescaler Reset Timer/Counter2
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** TIMER_COUNTER_2 ************** */
/* TIMSK2 - Timer/Counter Interrupt Mask register */
#define    TOIE2           0       // Timer/Counter2 Overflow Interrupt Enable
#define    TOIE2A          TOIE2   // For compatibility
#define    OCIE2A          1       // Timer/Counter2 Output Compare Match A Interrupt Enable
#define    OCIE2B          2       // Timer/Counter2 Output Compare Match B Interrupt Enable

/* TIFR2 - Timer/Counter Interrupt Flag Register */
#define    TOV2            0       // Timer/Counter2 Overflow Flag
#define    OCF2A           1       // Output Compare Flag 2 A
#define    OCF2B           2       // Output Compare Flag 2 B

/* TCCR2A - Timer/Counter2 Control Register A */
#define    WGM20           0       // Waveform Generation Mode
#define    WGM21           1       // Waveform Generation Mode
#define    COM2B0          4       // Compare Match Output B Mode
#define    COM2B1          5       // Compare Match Output B Mode
#define    COM2A0          6       // Compare Match Output A Mode
#define    COM2A1          7       // Compare Match Output A Mode

/* TCCR2B - Timer/Counter2 Control Register B */
#define    CS20            0       // Clock Select
#define    CS21            1       // Clock Select
#define    CS22            2       // Clock Select
#define    WGM22           3       // Waveform Generation Mode
#define    FOC2B           6       // Force Output Compare B
#define    FOC2A           7       // Force Output Compare A

/* TCNT2 - Timer/Counter2 */
#define    TCNT20          0       // Timer/Counter2 Byte
#define    TCNT21          1       // Timer/Counter2 Byte
#define    TCNT22          2       // Timer/Counter2 Byte
#define    TCNT23          3       // Timer/Counter2 Byte
#define    TCNT24          4       // Timer/Counter2 Byte
#define    TCNT25          5       // Timer/Counter2 Byte
#define    TCNT26          6       // Timer/Counter2 Byte
#define    TCNT27          7       // Timer/Counter2 Byte

/* OCR2A - Timer/Counter2 Output Compare Register A */
#define    OCR2A0          0       // Output Compare Register
#define    OCR2A1          1       // Output Compare Register
#define    OCR2A2          2       // Output Compare Register
#define    OCR2A3          3       // Output Compare Register
#define    OCR2A4          4       // Output Compare Register
#define    OCR2A5          5       // Output Compare Register
#define    OCR2A6          6       // Output Compare Register
#define    OCR2A7          7       // Output Compare Register

/* OCR2B - Timer/Counter2 Output Compare Register B */
#define    OCR2B0          0       // Output Compare Register
#define    OCR2B1          1       // Output Compare Register
#define    OCR2B2          2       // Output Compare Register
#define    OCR2B3          3       // Output Compare Register
#define    OCR2B4          4       // Output Compare Register
#define    OCR2B5          5       // Output Compare Register
#define    OCR2B6          6       // Output Compare Register
#define    OCR2B7          7       // Output Compare Register

/* ASSR - Asynchronous Status Register */
#define    TCR2BUB         0       // Timer/Counter2 Control Register B Update Busy
#define    TCR2AUB         1       // Timer/Counter2 Control Register A Update Busy
#define    OCR2BUB         2       // Timer/Counter2 Output Compare Register B Update Busy
#define    OCR2AUB         3       // Timer/Counter2 Output Compare Register A Update Busy
#define    TCN2UB          4       // Timer/Counter2 Update Busy
#define    AS2             5       // Timer/Counter2 Asynchronous Mode
#define    EXCLK           6       // Enable External Clock Input
#define    EXCLKAMR        7       // Enable External Clock Input for AMR

/* GTCCR - General Timer Counter Control register */
//#define  PSRASY          1       // Prescaler Reset Timer/Counter2
#define    PSR2            PSRASY  // For compatibility
//#define  TSM             7       // Timer/Counter Synchronization Mode


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


/* ***** TIMER_COUNTER_5 ************** */
/* TIMSK5 - Timer/Counter5 Interrupt Mask Register */
#define    TOIE5           0       // Timer/Counter5 Overflow Interrupt Enable
#define    OCIE5A          1       // Timer/Counter5 Output Compare A Match Interrupt Enable
#define    OCIE5B          2       // Timer/Counter5 Output Compare B Match Interrupt Enable
#define    OCIE5C          3       // Timer/Counter5 Output Compare C Match Interrupt Enable
#define    ICIE5           5       // Timer/Counter5 Input Capture Interrupt Enable

/* TIFR5 - Timer/Counter5 Interrupt Flag Register */
#define    TOV5            0       // Timer/Counter5 Overflow Flag
#define    OCF5A           1       // Timer/Counter5 Output Compare A Match Flag
#define    OCF5B           2       // Timer/Counter5 Output Compare B Match Flag
#define    OCF5C           3       // Timer/Counter5 Output Compare C Match Flag
#define    ICF5            5       // Timer/Counter5 Input Capture Flag

/* TCCR5A - Timer/Counter5 Control Register A */
#define    WGM50           0       // Waveform Generation Mode
#define    WGM51           1       // Waveform Generation Mode
#define    COM5C0          2       // Compare Output Mode for Channel C
#define    COM5C1          3       // Compare Output Mode for Channel C
#define    COM5B0          4       // Compare Output Mode for Channel B
#define    COM5B1          5       // Compare Output Mode for Channel B
#define    COM5A0          6       // Compare Output Mode for Channel A
#define    COM5A1          7       // Compare Output Mode for Channel A

/* TCCR5B - Timer/Counter5 Control Register B */
#define    CS50            0       // Clock Select
#define    CS51            1       // Clock Select
#define    CS52            2       // Clock Select
#define    WGM52           3       // Waveform Generation Mode
#define    WGM53           4       // Waveform Generation Mode
#define    ICES5           6       // Input Capture 5 Edge Select
#define    ICNC5           7       // Input Capture 5 Noise Canceller

/* TCCR5C - Timer/Counter5 Control Register C */
#define    FOC5C           5       // Force Output Compare for Channel C
#define    FOC5B           6       // Force Output Compare for Channel B
#define    FOC5A           7       // Force Output Compare for Channel A

/* ICR5H - Timer/Counter5 Input Capture Register High Byte */
#define    ICR5H0          0       // Timer/Counter5 Input Capture Register High Byte
#define    ICR5H1          1       // Timer/Counter5 Input Capture Register High Byte
#define    ICR5H2          2       // Timer/Counter5 Input Capture Register High Byte
#define    ICR5H3          3       // Timer/Counter5 Input Capture Register High Byte
#define    ICR5H4          4       // Timer/Counter5 Input Capture Register High Byte
#define    ICR5H5          5       // Timer/Counter5 Input Capture Register High Byte
#define    ICR5H6          6       // Timer/Counter5 Input Capture Register High Byte
#define    ICR5H7          7       // Timer/Counter5 Input Capture Register High Byte

/* ICR5L - Timer/Counter5 Input Capture Register Low Byte */
#define    ICR5L0          0       // Timer/Counter5 Input Capture Register Low Byte
#define    ICR5L1          1       // Timer/Counter5 Input Capture Register Low Byte
#define    ICR5L2          2       // Timer/Counter5 Input Capture Register Low Byte
#define    ICR5L3          3       // Timer/Counter5 Input Capture Register Low Byte
#define    ICR5L4          4       // Timer/Counter5 Input Capture Register Low Byte
#define    ICR5L5          5       // Timer/Counter5 Input Capture Register Low Byte
#define    ICR5L6          6       // Timer/Counter5 Input Capture Register Low Byte
#define    ICR5L7          7       // Timer/Counter5 Input Capture Register Low Byte


/* ***** TIMER_COUNTER_4 ************** */
/* TIMSK4 - Timer/Counter4 Interrupt Mask Register */
#define    TOIE4           0       // Timer/Counter4 Overflow Interrupt Enable
#define    OCIE4A          1       // Timer/Counter4 Output Compare A Match Interrupt Enable
#define    OCIE4B          2       // Timer/Counter4 Output Compare B Match Interrupt Enable
#define    OCIE4C          3       // Timer/Counter4 Output Compare C Match Interrupt Enable
#define    ICIE4           5       // Timer/Counter4 Input Capture Interrupt Enable

/* TIFR4 - Timer/Counter4 Interrupt Flag Register */
#define    TOV4            0       // Timer/Counter4 Overflow Flag
#define    OCF4A           1       // Timer/Counter4 Output Compare A Match Flag
#define    OCF4B           2       // Timer/Counter4 Output Compare B Match Flag
#define    OCF4C           3       // Timer/Counter4 Output Compare C Match Flag
#define    ICF4            5       // Timer/Counter4 Input Capture Flag

/* TCCR4A - Timer/Counter4 Control Register A */
#define    WGM40           0       // Waveform Generation Mode
#define    WGM41           1       // Waveform Generation Mode
#define    COM4C0          2       // Compare Output Mode for Channel C
#define    COM4C1          3       // Compare Output Mode for Channel C
#define    COM4B0          4       // Compare Output Mode for Channel B
#define    COM4B1          5       // Compare Output Mode for Channel B
#define    COM4A0          6       // Compare Output Mode for Channel A
#define    COM4A1          7       // Compare Output Mode for Channel A

/* TCCR4B - Timer/Counter4 Control Register B */
#define    CS40            0       // Clock Select
#define    CS41            1       // Clock Select
#define    CS42            2       // Clock Select
#define    WGM42           3       // Waveform Generation Mode
#define    WGM43           4       // Waveform Generation Mode
#define    ICES4           6       // Input Capture 4 Edge Select
#define    ICNC4           7       // Input Capture 4 Noise Canceller

/* TCCR4C - Timer/Counter4 Control Register C */
#define    FOC4C           5       // Force Output Compare for Channel C
#define    FOC4B           6       // Force Output Compare for Channel B
#define    FOC4A           7       // Force Output Compare for Channel A


/* ***** TIMER_COUNTER_3 ************** */
/* TIMSK3 - Timer/Counter3 Interrupt Mask Register */
#define    TOIE3           0       // Timer/Counter3 Overflow Interrupt Enable
#define    OCIE3A          1       // Timer/Counter3 Output Compare A Match Interrupt Enable
#define    OCIE3B          2       // Timer/Counter3 Output Compare B Match Interrupt Enable
#define    OCIE3C          3       // Timer/Counter3 Output Compare C Match Interrupt Enable
#define    ICIE3           5       // Timer/Counter3 Input Capture Interrupt Enable

/* TIFR3 - Timer/Counter3 Interrupt Flag Register */
#define    TOV3            0       // Timer/Counter3 Overflow Flag
#define    OCF3A           1       // Timer/Counter3 Output Compare A Match Flag
#define    OCF3B           2       // Timer/Counter3 Output Compare B Match Flag
#define    OCF3C           3       // Timer/Counter3 Output Compare C Match Flag
#define    ICF3            5       // Timer/Counter3 Input Capture Flag

/* TCCR3A - Timer/Counter3 Control Register A */
#define    WGM30           0       // Waveform Generation Mode
#define    WGM31           1       // Waveform Generation Mode
#define    COM3C0          2       // Compare Output Mode for Channel C
#define    COM3C1          3       // Compare Output Mode for Channel C
#define    COM3B0          4       // Compare Output Mode for Channel B
#define    COM3B1          5       // Compare Output Mode for Channel B
#define    COM3A0          6       // Compare Output Mode for Channel A
#define    COM3A1          7       // Compare Output Mode for Channel A

/* TCCR3B - Timer/Counter3 Control Register B */
#define    CS30            0       // Clock Select
#define    CS31            1       // Clock Select
#define    CS32            2       // Clock Select
#define    WGM32           3       // Waveform Generation Mode
#define    WGM33           4       // Waveform Generation Mode
#define    ICES3           6       // Input Capture 3 Edge Select
#define    ICNC3           7       // Input Capture 3 Noise Canceller

/* TCCR3C - Timer/Counter3 Control Register C */
#define    FOC3C           5       // Force Output Compare for Channel C
#define    FOC3B           6       // Force Output Compare for Channel B
#define    FOC3A           7       // Force Output Compare for Channel A


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK1 - Timer/Counter1 Interrupt Mask Register */
#define    TOIE1           0       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1A          1       // Timer/Counter1 Output Compare A Match Interrupt Enable
#define    OCIE1B          2       // Timer/Counter1 Output Compare B Match Interrupt Enable
#define    OCIE1C          3       // Timer/Counter1 Output Compare C Match Interrupt Enable
#define    ICIE1           5       // Timer/Counter1 Input Capture Interrupt Enable

/* TIFR1 - Timer/Counter1 Interrupt Flag Register */
#define    TOV1            0       // Timer/Counter1 Overflow Flag
#define    OCF1A           1       // Timer/Counter1 Output Compare A Match Flag
#define    OCF1B           2       // Timer/Counter1 Output Compare B Match Flag
#define    OCF1C           3       // Timer/Counter1 Output Compare C Match Flag
#define    ICF1            5       // Timer/Counter1 Input Capture Flag

/* TCCR1A - Timer/Counter1 Control Register A */
#define    WGM10           0       // Waveform Generation Mode
#define    WGM11           1       // Waveform Generation Mode
#define    COM1C0          2       // Compare Output Mode for Channel C
#define    COM1C1          3       // Compare Output Mode for Channel C
#define    COM1B0          4       // Compare Output Mode for Channel B
#define    COM1B1          5       // Compare Output Mode for Channel B
#define    COM1A0          6       // Compare Output Mode for Channel A
#define    COM1A1          7       // Compare Output Mode for Channel A

/* TCCR1B - Timer/Counter1 Control Register B */
#define    CS10            0       // Clock Select
#define    CS11            1       // Clock Select
#define    CS12            2       // Clock Select
#define    WGM12           3       // Waveform Generation Mode
#define    WGM13           4       // Waveform Generation Mode
#define    ICES1           6       // Input Capture 1 Edge Select
#define    ICNC1           7       // Input Capture 1 Noise Canceller

/* TCCR1C - Timer/Counter1 Control Register C */
#define    FOC1C           5       // Force Output Compare for Channel C
#define    FOC1B           6       // Force Output Compare for Channel B
#define    FOC1A           7       // Force Output Compare for Channel A


/* ***** TRX24 ************************ */
/* AES_CTRL - AES Control Register */
#define    AES_IM          2       // AES Interrupt Enable
#define    AES_DIR         3       // Set AES Operation Direction
#define    AES_MODE        5       // Set AES Operation Mode
#define    AES_REQUEST     7       // Request AES Operation.

/* AES_STATUS - AES Status Register */
#define    AES_DONE        0       // AES Operation Finished with Success
#define    AES_ER          7       // AES Operation Finished with Error

/* AES_STATE - AES Plain and Cipher Text Buffer Register */
#define    AES_STATE0      0       // AES Plain and Cipher Text Buffer
#define    AES_STATE1      1       // AES Plain and Cipher Text Buffer
#define    AES_STATE2      2       // AES Plain and Cipher Text Buffer
#define    AES_STATE3      3       // AES Plain and Cipher Text Buffer
#define    AES_STATE4      4       // AES Plain and Cipher Text Buffer
#define    AES_STATE5      5       // AES Plain and Cipher Text Buffer
#define    AES_STATE6      6       // AES Plain and Cipher Text Buffer
#define    AES_STATE7      7       // AES Plain and Cipher Text Buffer

/* AES_KEY - AES Encryption and Decryption Key Buffer Register */
#define    AES_KEY0        0       // AES Encryption/Decryption Key Buffer
#define    AES_KEY1        1       // AES Encryption/Decryption Key Buffer
#define    AES_KEY2        2       // AES Encryption/Decryption Key Buffer
#define    AES_KEY3        3       // AES Encryption/Decryption Key Buffer
#define    AES_KEY4        4       // AES Encryption/Decryption Key Buffer
#define    AES_KEY5        5       // AES Encryption/Decryption Key Buffer
#define    AES_KEY6        6       // AES Encryption/Decryption Key Buffer
#define    AES_KEY7        7       // AES Encryption/Decryption Key Buffer

/* TRX_STATUS - Transceiver Status Register */
#define    TRX_STATUS0     0       // Transceiver Main Status
#define    TRX_STATUS1     1       // Transceiver Main Status
#define    TRX_STATUS2     2       // Transceiver Main Status
#define    TRX_STATUS3     3       // Transceiver Main Status
#define    TRX_STATUS4     4       // Transceiver Main Status
#define    TST_STATUS      5       // Test mode status
#define    CCA_STATUS      6       // CCA Status Result
#define    CCA_DONE        7       // CCA Algorithm Status

/* TRX_STATE - Transceiver State Control Register */
#define    TRX_CMD0        0       // State Control Command
#define    TRX_CMD1        1       // State Control Command
#define    TRX_CMD2        2       // State Control Command
#define    TRX_CMD3        3       // State Control Command
#define    TRX_CMD4        4       // State Control Command
#define    TRAC_STATUS0    5       // Transaction Status
#define    TRAC_STATUS1    6       // Transaction Status
#define    TRAC_STATUS2    7       // Transaction Status

/* TRX_CTRL_0 - Reserved */

/* TRX_CTRL_1 - Transceiver Control Register 1 */
#define    TX_AUTO_CRC_ON  5       // Enable Automatic CRC Calculation
#define    IRQ_2_EXT_EN    6       // Connect Frame Start IRQ to TC1
#define    PA_EXT_EN       7       // External PA support enable

/* PHY_TX_PWR - Transceiver Transmit Power Control Register */
#define    TX_PWR0         0       // Transmit Power Setting
#define    TX_PWR1         1       // Transmit Power Setting
#define    TX_PWR2         2       // Transmit Power Setting
#define    TX_PWR3         3       // Transmit Power Setting
#define    PA_LT0          4       // Power Amplifier Lead Time
#define    PA_LT1          5       // Power Amplifier Lead Time
#define    PA_BUF_LT0      6       // Power Amplifier Buffer Lead Time
#define    PA_BUF_LT1      7       // Power Amplifier Buffer Lead Time

/* PHY_RSSI - Receiver Signal Strength Indicator Register */
#define    RSSI0           0       // Receiver Signal Strength Indicator
#define    RSSI1           1       // Receiver Signal Strength Indicator
#define    RSSI2           2       // Receiver Signal Strength Indicator
#define    RSSI3           3       // Receiver Signal Strength Indicator
#define    RSSI4           4       // Receiver Signal Strength Indicator
#define    RND_VALUE0      5       // Random Value
#define    RND_VALUE1      6       // Random Value
#define    RX_CRC_VALID    7       // Received Frame CRC Status

/* PHY_ED_LEVEL - Transceiver Energy Detection Level Register */
#define    ED_LEVEL0       0       // Energy Detection Level
#define    ED_LEVEL1       1       // Energy Detection Level
#define    ED_LEVEL2       2       // Energy Detection Level
#define    ED_LEVEL3       3       // Energy Detection Level
#define    ED_LEVEL4       4       // Energy Detection Level
#define    ED_LEVEL5       5       // Energy Detection Level
#define    ED_LEVEL6       6       // Energy Detection Level
#define    ED_LEVEL7       7       // Energy Detection Level

/* PHY_CC_CCA - Transceiver Clear Channel Assessment (CCA) Control Register */
#define    CHANNEL0        0       // RX/TX Channel Selection
#define    CHANNEL1        1       // RX/TX Channel Selection
#define    CHANNEL2        2       // RX/TX Channel Selection
#define    CHANNEL3        3       // RX/TX Channel Selection
#define    CHANNEL4        4       // RX/TX Channel Selection
#define    CCA_MODE0       5       // Select CCA Measurement Mode
#define    CCA_MODE1       6       // Select CCA Measurement Mode
#define    CCA_REQUEST     7       // Manual CCA Measurement Request

/* CCA_THRES - Transceiver CCA Threshold Setting Register */
#define    CCA_ED_THRES0   0       // ED Threshold Level for CCA Measurement
#define    CCA_ED_THRES1   1       // ED Threshold Level for CCA Measurement
#define    CCA_ED_THRES2   2       // ED Threshold Level for CCA Measurement
#define    CCA_ED_THRES3   3       // ED Threshold Level for CCA Measurement
#define    CCA_CS_THRES0   4       // CS Threshold Level for CCA Measurement
#define    CCA_CS_THRES1   5       // CS Threshold Level for CCA Measurement
#define    CCA_CS_THRES2   6       // CS Threshold Level for CCA Measurement
#define    CCA_CS_THRES3   7       // CS Threshold Level for CCA Measurement

/* RX_CTRL - Transceiver Receive Control Register */
#define    PDT_THRES0      0       // Receiver Sensitivity Control
#define    PDT_THRES1      1       // Receiver Sensitivity Control
#define    PDT_THRES2      2       // Receiver Sensitivity Control
#define    PDT_THRES3      3       // Receiver Sensitivity Control

/* SFD_VALUE - Start of Frame Delimiter Value Register */
#define    SFD_VALUE0      0       // Start of Frame Delimiter Value
#define    SFD_VALUE1      1       // Start of Frame Delimiter Value
#define    SFD_VALUE2      2       // Start of Frame Delimiter Value
#define    SFD_VALUE3      3       // Start of Frame Delimiter Value
#define    SFD_VALUE4      4       // Start of Frame Delimiter Value
#define    SFD_VALUE5      5       // Start of Frame Delimiter Value
#define    SFD_VALUE6      6       // Start of Frame Delimiter Value
#define    SFD_VALUE7      7       // Start of Frame Delimiter Value

/* TRX_CTRL_2 - Transceiver Control Register 2 */
#define    OQPSK_DATA_RATE0 0       // Data Rate Selection
#define    OQPSK_DATA_RATE1 1       // Data Rate Selection
#define    RX_SAFE_MODE    7       // RX Safe Mode

/* ANT_DIV - Antenna Diversity Control Register */
#define    ANT_CTRL0       0       // Static Antenna Diversity Switch Control
#define    ANT_CTRL1       1       // Static Antenna Diversity Switch Control
#define    ANT_EXT_SW_EN   2       // Enable External Antenna Switch Control
#define    ANT_DIV_EN      3       // Enable Antenna Diversity
#define    ANT_SEL         7       // Antenna Diversity Antenna Status

/* IRQ_MASK - Transceiver Interrupt Enable Register */
#define    PLL_LOCK_EN     0       // PLL Lock Interrupt Enable
#define    PLL_UNLOCK_EN   1       // PLL Unlock Interrupt Enable
#define    RX_START_EN     2       // RX_START Interrupt Enable
#define    RX_END_EN       3       // RX_END Interrupt Enable
#define    CCA_ED_DONE_EN  4       // End of ED Measurement Interrupt Enable
#define    AMI_EN          5       // Address Match Interrupt Enable
#define    TX_END_EN       6       // TX_END Interrupt Enable
#define    AWAKE_EN        7       // Awake Interrupt Enable

/* IRQ_STATUS - Transceiver Interrupt Status Register */
#define    PLL_LOCK        0       // PLL Lock Interrupt Status
#define    PLL_UNLOCK      1       // PLL Unlock Interrupt Status
#define    RX_START        2       // RX_START Interrupt Status
#define    RX_END          3       // RX_END Interrupt Status
#define    CCA_ED_DONE     4       // End of ED Measurement Interrupt Status
#define    AMI             5       // Address Match Interrupt Status
#define    TX_END          6       // TX_END Interrupt Status
#define    AWAKE           7       // Awake Interrupt Status

/* VREG_CTRL - Voltage Regulator Control and Status Register */
#define    DVDD_OK         2       // DVDD Supply Voltage Valid
#define    DVREG_EXT       3       // Use External DVDD Regulator
#define    AVDD_OK         6       // AVDD Supply Voltage Valid
#define    AVREG_EXT       7       // Use External AVDD Regulator

/* BATMON - Battery Monitor Control and Status Register */
#define    BATMON_VTH0     0       // Battery Monitor Threshold Voltage
#define    BATMON_VTH1     1       // Battery Monitor Threshold Voltage
#define    BATMON_VTH2     2       // Battery Monitor Threshold Voltage
#define    BATMON_VTH3     3       // Battery Monitor Threshold Voltage
#define    BATMON_HR       4       // Battery Monitor Voltage Range
#define    BATMON_OK       5       // Battery Monitor Status
#define    BAT_LOW_EN      6       // Battery Monitor Interrupt Enable
#define    BAT_LOW         7       // Battery Monitor Interrupt Status

/* XOSC_CTRL - Crystal Oscillator Control Register */
#define    XTAL_TRIM0      0       // Crystal Oscillator Load Capacitance Trimming
#define    XTAL_TRIM1      1       // Crystal Oscillator Load Capacitance Trimming
#define    XTAL_TRIM2      2       // Crystal Oscillator Load Capacitance Trimming
#define    XTAL_TRIM3      3       // Crystal Oscillator Load Capacitance Trimming
#define    XTAL_MODE0      4       // Crystal Oscillator Operating Mode
#define    XTAL_MODE1      5       // Crystal Oscillator Operating Mode
#define    XTAL_MODE2      6       // Crystal Oscillator Operating Mode
#define    XTAL_MODE3      7       // Crystal Oscillator Operating Mode

/* RX_SYN - Transceiver Receiver Sensitivity Control Register */
#define    RX_PDT_LEVEL0   0       // Reduce Receiver Sensitivity
#define    RX_PDT_LEVEL1   1       // Reduce Receiver Sensitivity
#define    RX_PDT_LEVEL2   2       // Reduce Receiver Sensitivity
#define    RX_PDT_LEVEL3   3       // Reduce Receiver Sensitivity
#define    RX_PDT_DIS      7       // Prevent Frame Reception

/* XAH_CTRL_1 - Transceiver Acknowledgment Frame Control Register 1 */
#define    AACK_PROM_MODE  1       // Enable Promiscuous Mode
#define    AACK_ACK_TIME   2       // Reduce Acknowledgment Time
#define    AACK_UPLD_RES_FT 4       // Process Reserved Frames
#define    AACK_FLTR_RES_FT 5       // Filter Reserved Frames

/* FTN_CTRL - Transceiver Filter Tuning Control Register */
#define    FTN_START       7       // Start Calibration Loop of Filter Tuning Network

/* PLL_CF - Transceiver Center Frequency Calibration Control Register */
#define    PLL_CF_START    7       // Start Center Frequency Calibration

/* PLL_DCU - Transceiver Delay Cell Calibration Control Register */
#define    PLL_DCU_START   7       // Start Delay Cell Calibration

/* PART_NUM - Device Identification Register (Part Number) */
#define    PART_NUM0       0       // Part Number
#define    PART_NUM1       1       // Part Number
#define    PART_NUM2       2       // Part Number
#define    PART_NUM3       3       // Part Number
#define    PART_NUM4       4       // Part Number
#define    PART_NUM5       5       // Part Number
#define    PART_NUM6       6       // Part Number
#define    PART_NUM7       7       // Part Number

/* VERSION_NUM - Device Identification Register (Version Number) */
#define    VERSION_NUM0    0       // Version Number
#define    VERSION_NUM1    1       // Version Number
#define    VERSION_NUM2    2       // Version Number
#define    VERSION_NUM3    3       // Version Number
#define    VERSION_NUM4    4       // Version Number
#define    VERSION_NUM5    5       // Version Number
#define    VERSION_NUM6    6       // Version Number
#define    VERSION_NUM7    7       // Version Number

/* MAN_ID_0 - Device Identification Register (Manufacture ID Low Byte) */
#define    MAN_ID_00       0       // Manufacturer ID (Low Byte)
#define    MAN_ID_01       1       // Manufacturer ID (Low Byte)
#define    MAN_ID_02       2       // Manufacturer ID (Low Byte)
#define    MAN_ID_03       3       // Manufacturer ID (Low Byte)
#define    MAN_ID_04       4       // Manufacturer ID (Low Byte)
#define    MAN_ID_05       5       // Manufacturer ID (Low Byte)
#define    MAN_ID_06       6       // Manufacturer ID (Low Byte)
#define    MAN_ID_07       7       // Manufacturer ID (Low Byte)

/* MAN_ID_1 - Device Identification Register (Manufacture ID High Byte) */
#define    MAN_ID_10       0       // Manufacturer ID (High Byte)
#define    MAN_ID_11       1       // Manufacturer ID (High Byte)
#define    MAN_ID_12       2       // Manufacturer ID (High Byte)
#define    MAN_ID_13       3       // Manufacturer ID (High Byte)
#define    MAN_ID_14       4       // Manufacturer ID (High Byte)
#define    MAN_ID_15       5       // Manufacturer ID (High Byte)
#define    MAN_ID_16       6       // Manufacturer ID (High Byte)
#define    MAN_ID_17       7       // Manufacturer ID (High Byte)

/* SHORT_ADDR_0 - Transceiver MAC Short Address Register (Low Byte) */
#define    SHORT_ADDR_00   0       // MAC Short Address
#define    SHORT_ADDR_01   1       // MAC Short Address
#define    SHORT_ADDR_02   2       // MAC Short Address
#define    SHORT_ADDR_03   3       // MAC Short Address
#define    SHORT_ADDR_04   4       // MAC Short Address
#define    SHORT_ADDR_05   5       // MAC Short Address
#define    SHORT_ADDR_06   6       // MAC Short Address
#define    SHORT_ADDR_07   7       // MAC Short Address

/* SHORT_ADDR_1 - Transceiver MAC Short Address Register (High Byte) */
#define    SHORT_ADDR_10   0       // MAC Short Address
#define    SHORT_ADDR_11   1       // MAC Short Address
#define    SHORT_ADDR_12   2       // MAC Short Address
#define    SHORT_ADDR_13   3       // MAC Short Address
#define    SHORT_ADDR_14   4       // MAC Short Address
#define    SHORT_ADDR_15   5       // MAC Short Address
#define    SHORT_ADDR_16   6       // MAC Short Address
#define    SHORT_ADDR_17   7       // MAC Short Address

/* PAN_ID_0 - Transceiver Personal Area Network ID Register (Low Byte) */
#define    PAN_ID_00       0       // MAC Personal Area Network ID
#define    PAN_ID_01       1       // MAC Personal Area Network ID
#define    PAN_ID_02       2       // MAC Personal Area Network ID
#define    PAN_ID_03       3       // MAC Personal Area Network ID
#define    PAN_ID_04       4       // MAC Personal Area Network ID
#define    PAN_ID_05       5       // MAC Personal Area Network ID
#define    PAN_ID_06       6       // MAC Personal Area Network ID
#define    PAN_ID_07       7       // MAC Personal Area Network ID

/* PAN_ID_1 - Transceiver Personal Area Network ID Register (High Byte) */
#define    PAN_ID_10       0       // MAC Personal Area Network ID
#define    PAN_ID_11       1       // MAC Personal Area Network ID
#define    PAN_ID_12       2       // MAC Personal Area Network ID
#define    PAN_ID_13       3       // MAC Personal Area Network ID
#define    PAN_ID_14       4       // MAC Personal Area Network ID
#define    PAN_ID_15       5       // MAC Personal Area Network ID
#define    PAN_ID_16       6       // MAC Personal Area Network ID
#define    PAN_ID_17       7       // MAC Personal Area Network ID

/* IEEE_ADDR_0 - Transceiver MAC IEEE Address Register 0 */
#define    IEEE_ADDR_00    0       // MAC IEEE Address
#define    IEEE_ADDR_01    1       // MAC IEEE Address
#define    IEEE_ADDR_02    2       // MAC IEEE Address
#define    IEEE_ADDR_03    3       // MAC IEEE Address
#define    IEEE_ADDR_04    4       // MAC IEEE Address
#define    IEEE_ADDR_05    5       // MAC IEEE Address
#define    IEEE_ADDR_06    6       // MAC IEEE Address
#define    IEEE_ADDR_07    7       // MAC IEEE Address

/* IEEE_ADDR_1 - Transceiver MAC IEEE Address Register 1 */
#define    IEEE_ADDR_10    0       // MAC IEEE Address
#define    IEEE_ADDR_11    1       // MAC IEEE Address
#define    IEEE_ADDR_12    2       // MAC IEEE Address
#define    IEEE_ADDR_13    3       // MAC IEEE Address
#define    IEEE_ADDR_14    4       // MAC IEEE Address
#define    IEEE_ADDR_15    5       // MAC IEEE Address
#define    IEEE_ADDR_16    6       // MAC IEEE Address
#define    IEEE_ADDR_17    7       // MAC IEEE Address

/* IEEE_ADDR_2 - Transceiver MAC IEEE Address Register 2 */
#define    IEEE_ADDR_20    0       // MAC IEEE Address
#define    IEEE_ADDR_21    1       // MAC IEEE Address
#define    IEEE_ADDR_22    2       // MAC IEEE Address
#define    IEEE_ADDR_23    3       // MAC IEEE Address
#define    IEEE_ADDR_24    4       // MAC IEEE Address
#define    IEEE_ADDR_25    5       // MAC IEEE Address
#define    IEEE_ADDR_26    6       // MAC IEEE Address
#define    IEEE_ADDR_27    7       // MAC IEEE Address

/* IEEE_ADDR_3 - Transceiver MAC IEEE Address Register 3 */
#define    IEEE_ADDR_30    0       // MAC IEEE Address
#define    IEEE_ADDR_31    1       // MAC IEEE Address
#define    IEEE_ADDR_32    2       // MAC IEEE Address
#define    IEEE_ADDR_33    3       // MAC IEEE Address
#define    IEEE_ADDR_34    4       // MAC IEEE Address
#define    IEEE_ADDR_35    5       // MAC IEEE Address
#define    IEEE_ADDR_36    6       // MAC IEEE Address
#define    IEEE_ADDR_37    7       // MAC IEEE Address

/* IEEE_ADDR_4 - Transceiver MAC IEEE Address Register 4 */
#define    IEEE_ADDR_40    0       // MAC IEEE Address
#define    IEEE_ADDR_41    1       // MAC IEEE Address
#define    IEEE_ADDR_42    2       // MAC IEEE Address
#define    IEEE_ADDR_43    3       // MAC IEEE Address
#define    IEEE_ADDR_44    4       // MAC IEEE Address
#define    IEEE_ADDR_45    5       // MAC IEEE Address
#define    IEEE_ADDR_46    6       // MAC IEEE Address
#define    IEEE_ADDR_47    7       // MAC IEEE Address

/* IEEE_ADDR_5 - Transceiver MAC IEEE Address Register 5 */
#define    IEEE_ADDR_50    0       // MAC IEEE Address
#define    IEEE_ADDR_51    1       // MAC IEEE Address
#define    IEEE_ADDR_52    2       // MAC IEEE Address
#define    IEEE_ADDR_53    3       // MAC IEEE Address
#define    IEEE_ADDR_54    4       // MAC IEEE Address
#define    IEEE_ADDR_55    5       // MAC IEEE Address
#define    IEEE_ADDR_56    6       // MAC IEEE Address
#define    IEEE_ADDR_57    7       // MAC IEEE Address

/* IEEE_ADDR_6 - Transceiver MAC IEEE Address Register 6 */
#define    IEEE_ADDR_60    0       // MAC IEEE Address
#define    IEEE_ADDR_61    1       // MAC IEEE Address
#define    IEEE_ADDR_62    2       // MAC IEEE Address
#define    IEEE_ADDR_63    3       // MAC IEEE Address
#define    IEEE_ADDR_64    4       // MAC IEEE Address
#define    IEEE_ADDR_65    5       // MAC IEEE Address
#define    IEEE_ADDR_66    6       // MAC IEEE Address
#define    IEEE_ADDR_67    7       // MAC IEEE Address

/* IEEE_ADDR_7 - Transceiver MAC IEEE Address Register 7 */
#define    IEEE_ADDR_70    0       // MAC IEEE Address
#define    IEEE_ADDR_71    1       // MAC IEEE Address
#define    IEEE_ADDR_72    2       // MAC IEEE Address
#define    IEEE_ADDR_73    3       // MAC IEEE Address
#define    IEEE_ADDR_74    4       // MAC IEEE Address
#define    IEEE_ADDR_75    5       // MAC IEEE Address
#define    IEEE_ADDR_76    6       // MAC IEEE Address
#define    IEEE_ADDR_77    7       // MAC IEEE Address

/* XAH_CTRL_0 - Transceiver Extended Operating Mode Control Register */
#define    SLOTTED_OPERATION 0       // Set Slotted Acknowledgment
#define    MAX_CSMA_RETRIES0 1       // Maximum Number of CSMA-CA Procedure Repetition Attempts
#define    MAX_CSMA_RETRIES1 2       // Maximum Number of CSMA-CA Procedure Repetition Attempts
#define    MAX_CSMA_RETRIES2 3       // Maximum Number of CSMA-CA Procedure Repetition Attempts
#define    MAX_FRAME_RETRIES0 4       // Maximum Number of Frame Re-transmission Attempts
#define    MAX_FRAME_RETRIES1 5       // Maximum Number of Frame Re-transmission Attempts
#define    MAX_FRAME_RETRIES2 6       // Maximum Number of Frame Re-transmission Attempts
#define    MAX_FRAME_RETRIES3 7       // Maximum Number of Frame Re-transmission Attempts

/* CSMA_SEED_0 - Transceiver CSMA-CA Random Number Generator Seed Register */
#define    CSMA_SEED_00    0       // Seed Value for CSMA Random Number Generator
#define    CSMA_SEED_01    1       // Seed Value for CSMA Random Number Generator
#define    CSMA_SEED_02    2       // Seed Value for CSMA Random Number Generator
#define    CSMA_SEED_03    3       // Seed Value for CSMA Random Number Generator
#define    CSMA_SEED_04    4       // Seed Value for CSMA Random Number Generator
#define    CSMA_SEED_05    5       // Seed Value for CSMA Random Number Generator
#define    CSMA_SEED_06    6       // Seed Value for CSMA Random Number Generator
#define    CSMA_SEED_07    7       // Seed Value for CSMA Random Number Generator

/* CSMA_SEED_1 - Transceiver Acknowledgment Frame Control Register 2 */
#define    CSMA_SEED_10    0       // Seed Value for CSMA Random Number Generator
#define    CSMA_SEED_11    1       // Seed Value for CSMA Random Number Generator
#define    CSMA_SEED_12    2       // Seed Value for CSMA Random Number Generator
#define    AACK_I_AM_COORD 3       // Set Personal Area Network Coordinator
#define    AACK_DIS_ACK    4       // Disable Acknowledgment Frame Transmission
#define    AACK_SET_PD     5       // Set Frame Pending Sub-field
#define    AACK_FVN_MODE0  6       // Acknowledgment Frame Filter Mode
#define    AACK_FVN_MODE1  7       // Acknowledgment Frame Filter Mode

/* CSMA_BE - Transceiver CSMA-CA Back-off Exponent Control Register */
#define    MIN_BE0         0       // Minimum Back-off Exponent
#define    MIN_BE1         1       // Minimum Back-off Exponent
#define    MIN_BE2         2       // Minimum Back-off Exponent
#define    MIN_BE3         3       // Minimum Back-off Exponent
#define    MAX_BE0         4       // Maximum Back-off Exponent
#define    MAX_BE1         5       // Maximum Back-off Exponent
#define    MAX_BE2         6       // Maximum Back-off Exponent
#define    MAX_BE3         7       // Maximum Back-off Exponent

/* TST_CTRL_DIGI - Transceiver Digital Test Control Register */
#define    TST_CTRL_DIG0   0       // Digital Test Controller Register
#define    TST_CTRL_DIG1   1       // Digital Test Controller Register
#define    TST_CTRL_DIG2   2       // Digital Test Controller Register
#define    TST_CTRL_DIG3   3       // Digital Test Controller Register

/* TST_RX_LENGTH - Transceiver Received Frame Length Register */
#define    RX_LENGTH0      0       // Received Frame Length
#define    RX_LENGTH1      1       // Received Frame Length
#define    RX_LENGTH2      2       // Received Frame Length
#define    RX_LENGTH3      3       // Received Frame Length
#define    RX_LENGTH4      4       // Received Frame Length
#define    RX_LENGTH5      5       // Received Frame Length
#define    RX_LENGTH6      6       // Received Frame Length
#define    RX_LENGTH7      7       // Received Frame Length

/* TRXFBST - Start of frame buffer */
#define    TRXFBST0        0       // Frame Buffer Start Byte
#define    TRXFBST1        1       // Frame Buffer Start Byte
#define    TRXFBST2        2       // Frame Buffer Start Byte
#define    TRXFBST3        3       // Frame Buffer Start Byte
#define    TRXFBST4        4       // Frame Buffer Start Byte
#define    TRXFBST5        5       // Frame Buffer Start Byte
#define    TRXFBST6        6       // Frame Buffer Start Byte
#define    TRXFBST7        7       // Frame Buffer Start Byte

/* TRXFBEND - End of frame buffer */
#define    TRXFBEND0       0       // Frame Buffer End Byte
#define    TRXFBEND1       1       // Frame Buffer End Byte
#define    TRXFBEND2       2       // Frame Buffer End Byte
#define    TRXFBEND3       3       // Frame Buffer End Byte
#define    TRXFBEND4       4       // Frame Buffer End Byte
#define    TRXFBEND5       5       // Frame Buffer End Byte
#define    TRXFBEND6       6       // Frame Buffer End Byte
#define    TRXFBEND7       7       // Frame Buffer End Byte


/* ***** SYMCNT *********************** */
/* SCOCR1HH - Symbol Counter Output Compare Register 1 HH-Byte */
#define    SCOCR1HH0       0       // Symbol Counter Output Compare Register 1 HH-Byte
#define    SCOCR1HH1       1       // Symbol Counter Output Compare Register 1 HH-Byte
#define    SCOCR1HH2       2       // Symbol Counter Output Compare Register 1 HH-Byte
#define    SCOCR1HH3       3       // Symbol Counter Output Compare Register 1 HH-Byte
#define    SCOCR1HH4       4       // Symbol Counter Output Compare Register 1 HH-Byte
#define    SCOCR1HH5       5       // Symbol Counter Output Compare Register 1 HH-Byte
#define    SCOCR1HH6       6       // Symbol Counter Output Compare Register 1 HH-Byte
#define    SCOCR1HH7       7       // Symbol Counter Output Compare Register 1 HH-Byte

/* SCOCR1HL - Symbol Counter Output Compare Register 1 HL-Byte */
#define    SCOCR1HL0       0       // Symbol Counter Output Compare Register 1 HL-Byte
#define    SCOCR1HL1       1       // Symbol Counter Output Compare Register 1 HL-Byte
#define    SCOCR1HL2       2       // Symbol Counter Output Compare Register 1 HL-Byte
#define    SCOCR1HL3       3       // Symbol Counter Output Compare Register 1 HL-Byte
#define    SCOCR1HL4       4       // Symbol Counter Output Compare Register 1 HL-Byte
#define    SCOCR1HL5       5       // Symbol Counter Output Compare Register 1 HL-Byte
#define    SCOCR1HL6       6       // Symbol Counter Output Compare Register 1 HL-Byte
#define    SCOCR1HL7       7       // Symbol Counter Output Compare Register 1 HL-Byte

/* SCOCR1LH - Symbol Counter Output Compare Register 1 LH-Byte */
#define    SCOCR1LH0       0       // Symbol Counter Output Compare Register 1 LH-Byte
#define    SCOCR1LH1       1       // Symbol Counter Output Compare Register 1 LH-Byte
#define    SCOCR1LH2       2       // Symbol Counter Output Compare Register 1 LH-Byte
#define    SCOCR1LH3       3       // Symbol Counter Output Compare Register 1 LH-Byte
#define    SCOCR1LH4       4       // Symbol Counter Output Compare Register 1 LH-Byte
#define    SCOCR1LH5       5       // Symbol Counter Output Compare Register 1 LH-Byte
#define    SCOCR1LH6       6       // Symbol Counter Output Compare Register 1 LH-Byte
#define    SCOCR1LH7       7       // Symbol Counter Output Compare Register 1 LH-Byte

/* SCOCR1LL - Symbol Counter Output Compare Register 1 LL-Byte */
#define    SCOCR1LL0       0       // Symbol Counter Output Compare Register 1 LL-Byte
#define    SCOCR1LL1       1       // Symbol Counter Output Compare Register 1 LL-Byte
#define    SCOCR1LL2       2       // Symbol Counter Output Compare Register 1 LL-Byte
#define    SCOCR1LL3       3       // Symbol Counter Output Compare Register 1 LL-Byte
#define    SCOCR1LL4       4       // Symbol Counter Output Compare Register 1 LL-Byte
#define    SCOCR1LL5       5       // Symbol Counter Output Compare Register 1 LL-Byte
#define    SCOCR1LL6       6       // Symbol Counter Output Compare Register 1 LL-Byte
#define    SCOCR1LL7       7       // Symbol Counter Output Compare Register 1 LL-Byte

/* SCOCR2HH - Symbol Counter Output Compare Register 2 HH-Byte */
#define    SCOCR2HH0       0       // Symbol Counter Output Compare Register 2 HH-Byte
#define    SCOCR2HH1       1       // Symbol Counter Output Compare Register 2 HH-Byte
#define    SCOCR2HH2       2       // Symbol Counter Output Compare Register 2 HH-Byte
#define    SCOCR2HH3       3       // Symbol Counter Output Compare Register 2 HH-Byte
#define    SCOCR2HH4       4       // Symbol Counter Output Compare Register 2 HH-Byte
#define    SCOCR2HH5       5       // Symbol Counter Output Compare Register 2 HH-Byte
#define    SCOCR2HH6       6       // Symbol Counter Output Compare Register 2 HH-Byte
#define    SCOCR2HH7       7       // Symbol Counter Output Compare Register 2 HH-Byte

/* SCOCR2HL - Symbol Counter Output Compare Register 2 HL-Byte */
#define    SCOCR2HL0       0       // Symbol Counter Output Compare Register 2 HL-Byte
#define    SCOCR2HL1       1       // Symbol Counter Output Compare Register 2 HL-Byte
#define    SCOCR2HL2       2       // Symbol Counter Output Compare Register 2 HL-Byte
#define    SCOCR2HL3       3       // Symbol Counter Output Compare Register 2 HL-Byte
#define    SCOCR2HL4       4       // Symbol Counter Output Compare Register 2 HL-Byte
#define    SCOCR2HL5       5       // Symbol Counter Output Compare Register 2 HL-Byte
#define    SCOCR2HL6       6       // Symbol Counter Output Compare Register 2 HL-Byte
#define    SCOCR2HL7       7       // Symbol Counter Output Compare Register 2 HL-Byte

/* SCOCR2LH - Symbol Counter Output Compare Register 2 LH-Byte */
#define    SCOCR2LH0       0       // Symbol Counter Output Compare Register 2 LH-Byte
#define    SCOCR2LH1       1       // Symbol Counter Output Compare Register 2 LH-Byte
#define    SCOCR2LH2       2       // Symbol Counter Output Compare Register 2 LH-Byte
#define    SCOCR2LH3       3       // Symbol Counter Output Compare Register 2 LH-Byte
#define    SCOCR2LH4       4       // Symbol Counter Output Compare Register 2 LH-Byte
#define    SCOCR2LH5       5       // Symbol Counter Output Compare Register 2 LH-Byte
#define    SCOCR2LH6       6       // Symbol Counter Output Compare Register 2 LH-Byte
#define    SCOCR2LH7       7       // Symbol Counter Output Compare Register 2 LH-Byte

/* SCOCR2LL - Symbol Counter Output Compare Register 2 LL-Byte */
#define    SCOCR2LL0       0       // Symbol Counter Output Compare Register 2 LL-Byte
#define    SCOCR2LL1       1       // Symbol Counter Output Compare Register 2 LL-Byte
#define    SCOCR2LL2       2       // Symbol Counter Output Compare Register 2 LL-Byte
#define    SCOCR2LL3       3       // Symbol Counter Output Compare Register 2 LL-Byte
#define    SCOCR2LL4       4       // Symbol Counter Output Compare Register 2 LL-Byte
#define    SCOCR2LL5       5       // Symbol Counter Output Compare Register 2 LL-Byte
#define    SCOCR2LL6       6       // Symbol Counter Output Compare Register 2 LL-Byte
#define    SCOCR2LL7       7       // Symbol Counter Output Compare Register 2 LL-Byte

/* SCOCR3HH - Symbol Counter Output Compare Register 3 HH-Byte */
#define    SCOCR3HH0       0       // Symbol Counter Output Compare Register 3 HH-Byte
#define    SCOCR3HH1       1       // Symbol Counter Output Compare Register 3 HH-Byte
#define    SCOCR3HH2       2       // Symbol Counter Output Compare Register 3 HH-Byte
#define    SCOCR3HH3       3       // Symbol Counter Output Compare Register 3 HH-Byte
#define    SCOCR3HH4       4       // Symbol Counter Output Compare Register 3 HH-Byte
#define    SCOCR3HH5       5       // Symbol Counter Output Compare Register 3 HH-Byte
#define    SCOCR3HH6       6       // Symbol Counter Output Compare Register 3 HH-Byte
#define    SCOCR3HH7       7       // Symbol Counter Output Compare Register 3 HH-Byte

/* SCOCR3HL - Symbol Counter Output Compare Register 3 HL-Byte */
#define    SCOCR3HL0       0       // Symbol Counter Output Compare Register 3 HL-Byte
#define    SCOCR3HL1       1       // Symbol Counter Output Compare Register 3 HL-Byte
#define    SCOCR3HL2       2       // Symbol Counter Output Compare Register 3 HL-Byte
#define    SCOCR3HL3       3       // Symbol Counter Output Compare Register 3 HL-Byte
#define    SCOCR3HL4       4       // Symbol Counter Output Compare Register 3 HL-Byte
#define    SCOCR3HL5       5       // Symbol Counter Output Compare Register 3 HL-Byte
#define    SCOCR3HL6       6       // Symbol Counter Output Compare Register 3 HL-Byte
#define    SCOCR3HL7       7       // Symbol Counter Output Compare Register 3 HL-Byte

/* SCOCR3LH - Symbol Counter Output Compare Register 3 LH-Byte */
#define    SCOCR3LH0       0       // Symbol Counter Output Compare Register 3 LH-Byte
#define    SCOCR3LH1       1       // Symbol Counter Output Compare Register 3 LH-Byte
#define    SCOCR3LH2       2       // Symbol Counter Output Compare Register 3 LH-Byte
#define    SCOCR3LH3       3       // Symbol Counter Output Compare Register 3 LH-Byte
#define    SCOCR3LH4       4       // Symbol Counter Output Compare Register 3 LH-Byte
#define    SCOCR3LH5       5       // Symbol Counter Output Compare Register 3 LH-Byte
#define    SCOCR3LH6       6       // Symbol Counter Output Compare Register 3 LH-Byte
#define    SCOCR3LH7       7       // Symbol Counter Output Compare Register 3 LH-Byte

/* SCOCR3LL - Symbol Counter Output Compare Register 3 LL-Byte */
#define    SCOCR3LL0       0       // Symbol Counter Output Compare Register 3 LL-Byte
#define    SCOCR3LL1       1       // Symbol Counter Output Compare Register 3 LL-Byte
#define    SCOCR3LL2       2       // Symbol Counter Output Compare Register 3 LL-Byte
#define    SCOCR3LL3       3       // Symbol Counter Output Compare Register 3 LL-Byte
#define    SCOCR3LL4       4       // Symbol Counter Output Compare Register 3 LL-Byte
#define    SCOCR3LL5       5       // Symbol Counter Output Compare Register 3 LL-Byte
#define    SCOCR3LL6       6       // Symbol Counter Output Compare Register 3 LL-Byte
#define    SCOCR3LL7       7       // Symbol Counter Output Compare Register 3 LL-Byte

/* SCTSRHH - Symbol Counter Frame Timestamp Register HH-Byte */
#define    SCTSRHH0        0       // Symbol Counter Frame Timestamp Register HH-Byte
#define    SCTSRHH1        1       // Symbol Counter Frame Timestamp Register HH-Byte
#define    SCTSRHH2        2       // Symbol Counter Frame Timestamp Register HH-Byte
#define    SCTSRHH3        3       // Symbol Counter Frame Timestamp Register HH-Byte
#define    SCTSRHH4        4       // Symbol Counter Frame Timestamp Register HH-Byte
#define    SCTSRHH5        5       // Symbol Counter Frame Timestamp Register HH-Byte
#define    SCTSRHH6        6       // Symbol Counter Frame Timestamp Register HH-Byte
#define    SCTSRHH7        7       // Symbol Counter Frame Timestamp Register HH-Byte

/* SCTSRHL - Symbol Counter Frame Timestamp Register HL-Byte */
#define    SCTSRHL0        0       // Symbol Counter Frame Timestamp Register HL-Byte
#define    SCTSRHL1        1       // Symbol Counter Frame Timestamp Register HL-Byte
#define    SCTSRHL2        2       // Symbol Counter Frame Timestamp Register HL-Byte
#define    SCTSRHL3        3       // Symbol Counter Frame Timestamp Register HL-Byte
#define    SCTSRHL4        4       // Symbol Counter Frame Timestamp Register HL-Byte
#define    SCTSRHL5        5       // Symbol Counter Frame Timestamp Register HL-Byte
#define    SCTSRHL6        6       // Symbol Counter Frame Timestamp Register HL-Byte
#define    SCTSRHL7        7       // Symbol Counter Frame Timestamp Register HL-Byte

/* SCTSRLH - Symbol Counter Frame Timestamp Register LH-Byte */
#define    SCTSRLH0        0       // Symbol Counter Frame Timestamp Register LH-Byte
#define    SCTSRLH1        1       // Symbol Counter Frame Timestamp Register LH-Byte
#define    SCTSRLH2        2       // Symbol Counter Frame Timestamp Register LH-Byte
#define    SCTSRLH3        3       // Symbol Counter Frame Timestamp Register LH-Byte
#define    SCTSRLH4        4       // Symbol Counter Frame Timestamp Register LH-Byte
#define    SCTSRLH5        5       // Symbol Counter Frame Timestamp Register LH-Byte
#define    SCTSRLH6        6       // Symbol Counter Frame Timestamp Register LH-Byte
#define    SCTSRLH7        7       // Symbol Counter Frame Timestamp Register LH-Byte

/* SCTSRLL - Symbol Counter Frame Timestamp Register LL-Byte */
#define    SCTSRLL0        0       // Symbol Counter Frame Timestamp Register LL-Byte
#define    SCTSRLL1        1       // Symbol Counter Frame Timestamp Register LL-Byte
#define    SCTSRLL2        2       // Symbol Counter Frame Timestamp Register LL-Byte
#define    SCTSRLL3        3       // Symbol Counter Frame Timestamp Register LL-Byte
#define    SCTSRLL4        4       // Symbol Counter Frame Timestamp Register LL-Byte
#define    SCTSRLL5        5       // Symbol Counter Frame Timestamp Register LL-Byte
#define    SCTSRLL6        6       // Symbol Counter Frame Timestamp Register LL-Byte
#define    SCTSRLL7        7       // Symbol Counter Frame Timestamp Register LL-Byte

/* SCBTSRHH - Symbol Counter Beacon Timestamp Register HH-Byte */
#define    SCBTSRHH0       0       // Symbol Counter Beacon Timestamp Register HH-Byte
#define    SCBTSRHH1       1       // Symbol Counter Beacon Timestamp Register HH-Byte
#define    SCBTSRHH2       2       // Symbol Counter Beacon Timestamp Register HH-Byte
#define    SCBTSRHH3       3       // Symbol Counter Beacon Timestamp Register HH-Byte
#define    SCBTSRHH4       4       // Symbol Counter Beacon Timestamp Register HH-Byte
#define    SCBTSRHH5       5       // Symbol Counter Beacon Timestamp Register HH-Byte
#define    SCBTSRHH6       6       // Symbol Counter Beacon Timestamp Register HH-Byte
#define    SCBTSRHH7       7       // Symbol Counter Beacon Timestamp Register HH-Byte

/* SCBTSRHL - Symbol Counter Beacon Timestamp Register HL-Byte */
#define    SCBTSRHL0       0       // Symbol Counter Beacon Timestamp Register HL-Byte
#define    SCBTSRHL1       1       // Symbol Counter Beacon Timestamp Register HL-Byte
#define    SCBTSRHL2       2       // Symbol Counter Beacon Timestamp Register HL-Byte
#define    SCBTSRHL3       3       // Symbol Counter Beacon Timestamp Register HL-Byte
#define    SCBTSRHL4       4       // Symbol Counter Beacon Timestamp Register HL-Byte
#define    SCBTSRHL5       5       // Symbol Counter Beacon Timestamp Register HL-Byte
#define    SCBTSRHL6       6       // Symbol Counter Beacon Timestamp Register HL-Byte
#define    SCBTSRHL7       7       // Symbol Counter Beacon Timestamp Register HL-Byte

/* SCBTSRLH - Symbol Counter Beacon Timestamp Register LH-Byte */
#define    SCBTSRLH0       0       // Symbol Counter Beacon Timestamp Register LH-Byte
#define    SCBTSRLH1       1       // Symbol Counter Beacon Timestamp Register LH-Byte
#define    SCBTSRLH2       2       // Symbol Counter Beacon Timestamp Register LH-Byte
#define    SCBTSRLH3       3       // Symbol Counter Beacon Timestamp Register LH-Byte
#define    SCBTSRLH4       4       // Symbol Counter Beacon Timestamp Register LH-Byte
#define    SCBTSRLH5       5       // Symbol Counter Beacon Timestamp Register LH-Byte
#define    SCBTSRLH6       6       // Symbol Counter Beacon Timestamp Register LH-Byte
#define    SCBTSRLH7       7       // Symbol Counter Beacon Timestamp Register LH-Byte

/* SCBTSRLL - Symbol Counter Beacon Timestamp Register LL-Byte */
#define    SCBTSRLL0       0       // Symbol Counter Beacon Timestamp Register LL-Byte
#define    SCBTSRLL1       1       // Symbol Counter Beacon Timestamp Register LL-Byte
#define    SCBTSRLL2       2       // Symbol Counter Beacon Timestamp Register LL-Byte
#define    SCBTSRLL3       3       // Symbol Counter Beacon Timestamp Register LL-Byte
#define    SCBTSRLL4       4       // Symbol Counter Beacon Timestamp Register LL-Byte
#define    SCBTSRLL5       5       // Symbol Counter Beacon Timestamp Register LL-Byte
#define    SCBTSRLL6       6       // Symbol Counter Beacon Timestamp Register LL-Byte
#define    SCBTSRLL7       7       // Symbol Counter Beacon Timestamp Register LL-Byte

/* SCCNTHH - Symbol Counter Register HH-Byte */
#define    SCCNTHH0        0       // Symbol Counter Register HH-Byte
#define    SCCNTHH1        1       // Symbol Counter Register HH-Byte
#define    SCCNTHH2        2       // Symbol Counter Register HH-Byte
#define    SCCNTHH3        3       // Symbol Counter Register HH-Byte
#define    SCCNTHH4        4       // Symbol Counter Register HH-Byte
#define    SCCNTHH5        5       // Symbol Counter Register HH-Byte
#define    SCCNTHH6        6       // Symbol Counter Register HH-Byte
#define    SCCNTHH7        7       // Symbol Counter Register HH-Byte

/* SCCNTHL - Symbol Counter Register HL-Byte */
#define    SCCNTHL0        0       // Symbol Counter Register HL-Byte
#define    SCCNTHL1        1       // Symbol Counter Register HL-Byte
#define    SCCNTHL2        2       // Symbol Counter Register HL-Byte
#define    SCCNTHL3        3       // Symbol Counter Register HL-Byte
#define    SCCNTHL4        4       // Symbol Counter Register HL-Byte
#define    SCCNTHL5        5       // Symbol Counter Register HL-Byte
#define    SCCNTHL6        6       // Symbol Counter Register HL-Byte
#define    SCCNTHL7        7       // Symbol Counter Register HL-Byte

/* SCCNTLH - Symbol Counter Register LH-Byte */
#define    SCCNTLH0        0       // Symbol Counter Register LH-Byte
#define    SCCNTLH1        1       // Symbol Counter Register LH-Byte
#define    SCCNTLH2        2       // Symbol Counter Register LH-Byte
#define    SCCNTLH3        3       // Symbol Counter Register LH-Byte
#define    SCCNTLH4        4       // Symbol Counter Register LH-Byte
#define    SCCNTLH5        5       // Symbol Counter Register LH-Byte
#define    SCCNTLH6        6       // Symbol Counter Register LH-Byte
#define    SCCNTLH7        7       // Symbol Counter Register LH-Byte

/* SCCNTLL - Symbol Counter Register LL-Byte */
#define    SCCNTLL0        0       // Symbol Counter Register LL-Byte
#define    SCCNTLL1        1       // Symbol Counter Register LL-Byte
#define    SCCNTLL2        2       // Symbol Counter Register LL-Byte
#define    SCCNTLL3        3       // Symbol Counter Register LL-Byte
#define    SCCNTLL4        4       // Symbol Counter Register LL-Byte
#define    SCCNTLL5        5       // Symbol Counter Register LL-Byte
#define    SCCNTLL6        6       // Symbol Counter Register LL-Byte
#define    SCCNTLL7        7       // Symbol Counter Register LL-Byte

/* SCCR0 - Symbol Counter Control Register 0 */
#define    SCCMP1          0       // Symbol Counter Compare Unit 1 Mode select
#define    SCCMP2          1       // Symbol Counter Compare Unit 2 Mode select
#define    SCCMP3          2       // Symbol Counter Compare Unit 3 Mode select
#define    SCTSE           3       // Symbol Counter Automatic Timestamping enable
#define    SCCKSEL         4       // Symbol Counter Clock Source select
#define    SCEN            5       // Symbol Counter enable
#define    SCMBTS          6       // Manual Beacon Timestamp
#define    SCRES           7       // Symbol Counter Synchronization

/* SCCR1 - Symbol Counter Control Register 1 */
#define    SCENBO          0       // Backoff Slot Counter enable

/* SCSR - Symbol Counter Status Register */
#define    SCBSY           0       // Symbol Counter busy

/* SCIRQS - Symbol Counter Interrupt Status Register */
#define    IRQSCP1         0       // Compare Unit 1 Compare Match IRQ
#define    IRQSCP2         1       // Compare Unit 2 Compare Match IRQ
#define    IRQSCP3         2       // Compare Unit 3 Compare Match IRQ
#define    IRQSOF          3       // Symbol Counter Overflow IRQ
#define    IRQSBO          4       // Backoff Slot Counter IRQ

/* SCIRQM - Symbol Counter Interrupt Mask Register */
#define    IRQMCP1         0       // Symbol Counter Compare Match 1 IRQ enable
#define    IRQMCP2         1       // Symbol Counter Compare Match 2 IRQ enable
#define    IRQMCP3         2       // Symbol Counter Compare Match 3 IRQ enable
#define    IRQMOF          3       // Symbol Counter Overflow IRQ enable
#define    IRQMBO          4       // Backoff Slot Counter IRQ enable

/* ***** EEPROM *********************** */
/* EEARH - EEPROM Address Register High Byte */
#define    EEAR8           0       // EEPROM Address
#define    EEAR9           1       // EEPROM Address
#define    EEAR10          2       // EEPROM Address
#define    EEAR11          3       // EEPROM Address

/* EEARL - EEPROM Address Register Low Byte */
#define    EEAR0           0       // EEPROM Address
#define    EEAR1           1       // EEPROM Address
#define    EEAR2           2       // EEPROM Address
#define    EEAR3           3       // EEPROM Address
#define    EEAR4           4       // EEPROM Address
#define    EEAR5           5       // EEPROM Address
#define    EEAR6           6       // EEPROM Address
#define    EEAR7           7       // EEPROM Address

/* EEDR - EEPROM Data Register */
#define    EEDR0           0       // EEPROM Data
#define    EEDR1           1       // EEPROM Data
#define    EEDR2           2       // EEPROM Data
#define    EEDR3           3       // EEPROM Data
#define    EEDR4           4       // EEPROM Data
#define    EEDR5           5       // EEPROM Data
#define    EEDR6           6       // EEPROM Data
#define    EEDR7           7       // EEPROM Data

/* EECR - EEPROM Control Register */
#define    EERE            0       // EEPROM Read Enable
#define    EEPE            1       // EEPROM Programming Enable
#define    EEMPE           2       // EEPROM Master Write Enable
#define    EERIE           3       // EEPROM Ready Interrupt Enable
#define    EEPM0           4       // EEPROM Programming Mode
#define    EEPM1           5       // EEPROM Programming Mode


/* ***** JTAG ************************* */
/* OCDR - On-Chip Debug Register */
#define    OCDR0           0       // On-Chip Debug Register Data
#define    OCDR1           1       // On-Chip Debug Register Data
#define    OCDR2           2       // On-Chip Debug Register Data
#define    OCDR3           3       // On-Chip Debug Register Data
#define    OCDR4           4       // On-Chip Debug Register Data
#define    OCDR5           5       // On-Chip Debug Register Data
#define    OCDR6           6       // On-Chip Debug Register Data
#define    OCDR7           7       // On-Chip Debug Register Data
#define    IDRD            OCDR7   // For compatibility

/* MCUCR - MCU Control Register */
#define    JTD             7       // JTAG Interface Disable

/* MCUSR - MCU Status Register */
#define    JTRF            4       // JTAG Reset Flag


/* ***** EXTERNAL_INTERRUPT *********** */
/* EICRA - External Interrupt Control Register A */
#define    ISC00           0       // External Interrupt 0 Sense Control Bit
#define    ISC01           1       // External Interrupt 0 Sense Control Bit
#define    ISC10           2       // External Interrupt 1 Sense Control Bit
#define    ISC11           3       // External Interrupt 1 Sense Control Bit
#define    ISC20           4       // External Interrupt 2 Sense Control Bit
#define    ISC21           5       // External Interrupt 2 Sense Control Bit
#define    ISC30           6       // External Interrupt 3 Sense Control Bit
#define    ISC31           7       // External Interrupt 3 Sense Control Bit

/* EICRB - External Interrupt Control Register B */
#define    ISC40           0       // External Interrupt 4 Sense Control Bit
#define    ISC41           1       // External Interrupt 4 Sense Control Bit
#define    ISC50           2       // External Interrupt 5 Sense Control Bit
#define    ISC51           3       // External Interrupt 5 Sense Control Bit
#define    ISC60           4       // External Interrupt 6 Sense Control Bit
#define    ISC61           5       // External Interrupt 6 Sense Control Bit
#define    ISC70           6       // External Interrupt 7 Sense Control Bit
#define    ISC71           7       // External Interrupt 7 Sense Control Bit

/* EIMSK - External Interrupt Mask Register */
#define    INT0            0       // External Interrupt Request Enable
#define    INT1            1       // External Interrupt Request Enable
#define    INT2            2       // External Interrupt Request Enable
#define    INT3            3       // External Interrupt Request Enable
#define    INT4            4       // External Interrupt Request Enable
#define    INT5            5       // External Interrupt Request Enable
#define    INT6            6       // External Interrupt Request Enable
#define    INT7            7       // External Interrupt Request Enable

/* EIFR - External Interrupt Flag Register */
#define    INTF0           0       // External Interrupt Flag
#define    INTF1           1       // External Interrupt Flag
#define    INTF2           2       // External Interrupt Flag
#define    INTF3           3       // External Interrupt Flag
#define    INTF4           4       // External Interrupt Flag
#define    INTF5           5       // External Interrupt Flag
#define    INTF6           6       // External Interrupt Flag
#define    INTF7           7       // External Interrupt Flag

/* PCICR - Pin Change Interrupt Control Register */
#define    PCIE0           0       // Pin Change Interrupt Enable 0
#define    PCIE1           1       // Pin Change Interrupt Enable 1
#define    PCIE2           2       // Pin Change Interrupt Enable 2

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 0
#define    PCIF1           1       // Pin Change Interrupt Flag 1
#define    PCIF2           2       // Pin Change Interrupt Flag 2

/* PCMSK2 - Pin Change Mask Register 2 */
#define    PCINT16         0       // Pin Change Enable Mask
#define    PCINT17         1       // Pin Change Enable Mask
#define    PCINT18         2       // Pin Change Enable Mask
#define    PCINT19         3       // Pin Change Enable Mask
#define    PCINT20         4       // Pin Change Enable Mask
#define    PCINT21         5       // Pin Change Enable Mask
#define    PCINT22         6       // Pin Change Enable Mask
#define    PCINT23         7       // Pin Change Enable Mask

/* PCMSK1 - Pin Change Mask Register 1 */
#define    PCINT8          0       // Pin Change Enable Mask 8
#define    PCINT9          1       // Pin Change Enable Mask
#define    PCINT10         2       // Pin Change Enable Mask
#define    PCINT11         3       // Pin Change Enable Mask
#define    PCINT12         4       // Pin Change Enable Mask
#define    PCINT13         5       // Pin Change Enable Mask
#define    PCINT14         6       // Pin Change Enable Mask
#define    PCINT15         7       // Pin Change Enable Mask

/* PCMSK0 - Pin Change Mask Register 0 */
#define    PCINT0          0       // Pin Change Enable Mask
#define    PCINT1          1       // Pin Change Enable Mask
#define    PCINT2          2       // Pin Change Enable Mask
#define    PCINT3          3       // Pin Change Enable Mask
#define    PCINT4          4       // Pin Change Enable Mask
#define    PCINT5          5       // Pin Change Enable Mask
#define    PCINT6          6       // Pin Change Enable Mask
#define    PCINT7          7       // Pin Change Enable Mask


/* ***** AD_CONVERTER ***************** */
/* ADMUX - The ADC Multiplexer Selection Register */
#define    MUX0            0       // Analog Channel and Gain Selection Bits
#define    MUX1            1       // Analog Channel and Gain Selection Bits
#define    MUX2            2       // Analog Channel and Gain Selection Bits
#define    MUX3            3       // Analog Channel and Gain Selection Bits
#define    MUX4            4       // Analog Channel and Gain Selection Bits
#define    ADLAR           5       // ADC Left Adjust Result
#define    REFS0           6       // Reference Selection Bits
#define    REFS1           7       // Reference Selection Bits

/* ADCSRA - The ADC Control and Status Register A */
#define    ADPS0           0       // ADC  Prescaler Select Bits
#define    ADPS1           1       // ADC  Prescaler Select Bits
#define    ADPS2           2       // ADC  Prescaler Select Bits
#define    ADIE            3       // ADC Interrupt Enable
#define    ADIF            4       // ADC Interrupt Flag
#define    ADATE           5       // ADC Auto Trigger Enable
#define    ADSC            6       // ADC Start Conversion
#define    ADEN            7       // ADC Enable

/* ADCSRB - The ADC Control and Status Register B */
#define    ADTS0           0       // ADC Auto Trigger Source
#define    ADTS1           1       // ADC Auto Trigger Source
#define    ADTS2           2       // ADC Auto Trigger Source
#define    MUX5            3       // Analog Channel and Gain Selection Bits
#define    ACCH            4       // Analog Channel Change
#define    REFOK           5       // Reference Voltage OK
//#define  ACME            6       // Analog Comparator Multiplexer Enable
#define    AVDDOK          7       // AVDD Supply Voltage OK

/* ADCSRC - The ADC Control and Status Register C */
#define    ADSUT0          0       // ADC Start-up Time
#define    ADSUT1          1       // ADC Start-up Time
#define    ADSUT2          2       // ADC Start-up Time
#define    ADSUT3          3       // ADC Start-up Time
#define    ADSUT4          4       // ADC Start-up Time
#define    ADTHT0          6       // ADC Track-and-Hold Time
#define    ADTHT1          7       // ADC Track-and-Hold Time

/* ADCH - ADC Data Register High Byte */
#define    ADCH0           0       // ADC Data Register High Byte
#define    ADCH1           1       // ADC Data Register High Byte
#define    ADCH2           2       // ADC Data Register High Byte
#define    ADCH3           3       // ADC Data Register High Byte
#define    ADCH4           4       // ADC Data Register High Byte
#define    ADCH5           5       // ADC Data Register High Byte
#define    ADCH6           6       // ADC Data Register High Byte
#define    ADCH7           7       // ADC Data Register High Byte

/* ADCL - ADC Data Register Low Byte */
#define    ADCL0           0       // ADC Data Register Low Byte
#define    ADCL1           1       // ADC Data Register Low Byte
#define    ADCL2           2       // ADC Data Register Low Byte
#define    ADCL3           3       // ADC Data Register Low Byte
#define    ADCL4           4       // ADC Data Register Low Byte
#define    ADCL5           5       // ADC Data Register Low Byte
#define    ADCL6           6       // ADC Data Register Low Byte
#define    ADCL7           7       // ADC Data Register Low Byte

/* DIDR0 - Digital Input Disable Register 0 */
#define    ADC0D           0       // Disable ADC7:0 Digital Input
#define    ADC1D           1       // Disable ADC7:0 Digital Input
#define    ADC2D           2       // Disable ADC7:0 Digital Input
#define    ADC3D           3       // Disable ADC7:0 Digital Input
#define    ADC4D           4       // Disable ADC7:0 Digital Input
#define    ADC5D           5       // Disable ADC7:0 Digital Input
#define    ADC6D           6       // Disable ADC7:0 Digital Input
#define    ADC7D           7       // Disable ADC7:0 Digital Input

/* DIDR2 - Digital Input Disable Register 2 */
#define    ADC8D           0       // Reserved Bits
#define    ADC9D           1       // Reserved Bits
#define    ADC10D          2       // Reserved Bits
#define    ADC11D          3       // Reserved Bits
#define    ADC12D          4       // Reserved Bits
#define    ADC13D          5       // Reserved Bits
#define    ADC14D          6       // Reserved Bits
#define    ADC15D          7       // Reserved Bits


/* ***** BOOT_LOAD ******************** */
/* SPMCSR - Store Program Memory Control Register */
#define    SPMEN           0       // Store Program Memory Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    BLBSET          3       // Boot Lock Bit Set
#define    RWWSRE          4       // Read While Write Section Read Enable
#define    SIGRD           5       // Signature Row Read
#define    RWWSB           6       // Read While Write Section Busy
#define    SPMIE           7       // SPM Interrupt Enable


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
#define    IVCE            0       // Interrupt Vector Change Enable
#define    IVSEL           1       // Interrupt Vector Select
#define    PUD             4       // Pull-up Disable
//#define  JTD             7       // JTAG Interface Disable

/* MCUSR - MCU Status Register */
#define    PORF            0       // Power-on Reset Flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag
//#define  JTRF            4       // JTAG Reset Flag

/* OSCCAL - Oscillator Calibration Value */
#define    CAL0            0       // Oscillator Calibration Tuning Value
#define    CAL1            1       // Oscillator Calibration Tuning Value
#define    CAL2            2       // Oscillator Calibration Tuning Value
#define    CAL3            3       // Oscillator Calibration Tuning Value
#define    CAL4            4       // Oscillator Calibration Tuning Value
#define    CAL5            5       // Oscillator Calibration Tuning Value
#define    CAL6            6       // Oscillator Calibration Tuning Value
#define    CAL7            7       // Oscillator Calibration Tuning Value

/* CLKPR - Clock Prescale Register */
#define    CLKPS0          0       // Clock Prescaler Select Bits
#define    CLKPS1          1       // Clock Prescaler Select Bits
#define    CLKPS2          2       // Clock Prescaler Select Bits
#define    CLKPS3          3       // Clock Prescaler Select Bits
#define    CLKPCE          7       // Clock Prescaler Change Enable

/* SMCR - Sleep Mode Control Register */
#define    SE              0       // Sleep Enable
#define    SM0             1       // Sleep Mode Select bit 0
#define    SM1             2       // Sleep Mode Select bit 1
#define    SM2             3       // Sleep Mode Select bit 2

/* RAMPZ - Extended Z-pointer Register for ELPM/SPM */
#define    RAMPZ0          0       // Extended Z-Pointer Value
#define    RAMPZ1          1       // Extended Z-Pointer Value

/* GPIOR2 - General Purpose I/O Register 2 */
#define    GPIOR20         0       // General Purpose I/O Register 2 Value
#define    GPIOR21         1       // General Purpose I/O Register 2 Value
#define    GPIOR22         2       // General Purpose I/O Register 2 Value
#define    GPIOR23         3       // General Purpose I/O Register 2 Value
#define    GPIOR24         4       // General Purpose I/O Register 2 Value
#define    GPIOR25         5       // General Purpose I/O Register 2 Value
#define    GPIOR26         6       // General Purpose I/O Register 2 Value
#define    GPIOR27         7       // General Purpose I/O Register 2 Value

/* GPIOR1 - General Purpose IO Register 1 */
#define    GPIOR10         0       // General Purpose I/O Register 1 Value
#define    GPIOR11         1       // General Purpose I/O Register 1 Value
#define    GPIOR12         2       // General Purpose I/O Register 1 Value
#define    GPIOR13         3       // General Purpose I/O Register 1 Value
#define    GPIOR14         4       // General Purpose I/O Register 1 Value
#define    GPIOR15         5       // General Purpose I/O Register 1 Value
#define    GPIOR16         6       // General Purpose I/O Register 1 Value
#define    GPIOR17         7       // General Purpose I/O Register 1 Value

/* GPIOR0 - General Purpose IO Register 0 */
#define    GPIOR00         0       // General Purpose I/O Register 0 Value
#define    GPIOR01         1       // General Purpose I/O Register 0 Value
#define    GPIOR02         2       // General Purpose I/O Register 0 Value
#define    GPIOR03         3       // General Purpose I/O Register 0 Value
#define    GPIOR04         4       // General Purpose I/O Register 0 Value
#define    GPIOR05         5       // General Purpose I/O Register 0 Value
#define    GPIOR06         6       // General Purpose I/O Register 0 Value
#define    GPIOR07         7       // General Purpose I/O Register 0 Value

/* PRR2 - Power Reduction Register 2 */
#define    PRRAM0          0       // Power Reduction SRAM 0
#define    PRRAM1          1       // Power Reduction SRAM 1
#define    PRRAM2          2       // Power Reduction SRAM 2
#define    PRRAM3          3       // Power Reduction SRAM 3

/* PRR1 - Power Reduction Register 1 */
#define    PRUSART1        0       // Power Reduction USART1
#define    PRUSART2        1       // Reserved
#define    PRUSART3        2       // Reserved
#define    PRTIM3          3       // Power Reduction Timer/Counter3
#define    PRTIM4          4       // Power Reduction Timer/Counter4
#define    PRTIM5          5       // Power Reduction Timer/Counter5
#define    PRTRX24         6       // Power Reduction Transceiver

/* PRR0 - Power Reduction Register0 */
#define    PRADC           0       // Power Reduction ADC
#define    PRUSART0        1       // Power Reduction USART
#define    PRSPI           2       // Power Reduction Serial Peripheral Interface
#define    PRTIM1          3       // Power Reduction Timer/Counter1
#define    PRPGA           4       // Power Reduction PGA
#define    PRTIM0          5       // Power Reduction Timer/Counter0
#define    PRTIM2          6       // Power Reduction Timer/Counter2
#define    PRTWI           7       // Power Reduction TWI


/* ***** FLASH ************************ */
/* NEMCR - Flash Extended-Mode Control-Register */
#define    AEAM0           4       // Address for Extended Address Mode of Extra Rows
#define    AEAM1           5       // Address for Extended Address Mode of Extra Rows
#define    ENEAM           6       // Enable Extended Address Mode for Extra Rows

/* BGCR - Reference Voltage Calibration Register */
#define    BGCAL0          0       // Coarse Calibration Bits
#define    BGCAL1          1       // Coarse Calibration Bits
#define    BGCAL2          2       // Coarse Calibration Bits
#define    BGCAL_FINE0     3       // Fine Calibration Bits
#define    BGCAL_FINE1     4       // Fine Calibration Bits
#define    BGCAL_FINE2     5       // Fine Calibration Bits
#define    BGCAL_FINE3     6       // Fine Calibration Bits


/* ***** PWRCTRL ********************** */
/* TRXPR - Transceiver Pin Register */
#define    TRXRST          0       // Force Transceiver Reset
#define    SLPTR           1       // Multi-purpose Transceiver Control Bit

/* DRTRAM0 - Data Retention Configuration Register of SRAM 0 */
#define    ENDRT           4       // Enable SRAM Data Retention
#define    DRTSWOK         5       // DRT Switch OK

/* DRTRAM1 - Data Retention Configuration Register of SRAM 1 */
//#define  ENDRT           4       // Enable SRAM Data Retention
//#define  DRTSWOK         5       // DRT Switch OK

/* DRTRAM2 - Data Retention Configuration Register of SRAM 2 */
//#define  ENDRT           4       // Enable SRAM Data Retention
//#define  DRTSWOK         5       // DRT Switch OK

/* DRTRAM3 - Data Retention Configuration Register of SRAM 3 */
//#define  ENDRT           4       // Enable SRAM Data Retention
//#define  DRTSWOK         5       // DRT Switch OK

/* LLDRL - Low Leakage Voltage Regulator Data Register (Low-Byte) */
#define    LLDRL0          0       // Low-Byte Data Register Bits
#define    LLDRL1          1       // Low-Byte Data Register Bits
#define    LLDRL2          2       // Low-Byte Data Register Bits
#define    LLDRL3          3       // Low-Byte Data Register Bits

/* LLDRH - Low Leakage Voltage Regulator Data Register (High-Byte) */
#define    LLDRH0          0       // High-Byte Data Register Bits
#define    LLDRH1          1       // High-Byte Data Register Bits
#define    LLDRH2          2       // High-Byte Data Register Bits
#define    LLDRH3          3       // High-Byte Data Register Bits
#define    LLDRH4          4       // High-Byte Data Register Bits

/* LLCR - Low Leakage Voltage Regulator Control Register */
#define    LLENCAL         0       // Enable Automatic Calibration
#define    LLSHORT         1       // Short Lower Calibration Circuit
#define    LLTCO           2       // Temperature Coefficient of Current Source
#define    LLCAL           3       // Calibration Active
#define    LLCOMP          4       // Comparator Output
#define    LLDONE          5       // Calibration Done

/* DPDS0 - Port Driver Strength Register 0 */
#define    PBDRV0          0       // Driver Strength Port B
#define    PBDRV1          1       // Driver Strength Port B
#define    PDDRV0          2       // Driver Strength Port D
#define    PDDRV1          3       // Driver Strength Port D
#define    PEDRV0          4       // Driver Strength Port E
#define    PEDRV1          5       // Driver Strength Port E
#define    PFDRV0          6       // Driver Strength Port F
#define    PFDRV1          7       // Driver Strength Port F

/* DPDS1 - Port Driver Strength Register 1 */
#define    PGDRV0          0       // Driver Strength Port G
#define    PGDRV1          1       // Driver Strength Port G

/* MCUCR - MCU Control Register */
//#define  PUD             4       // Pull-up Disable


/* ***** USART0_SPI ******************* */
/* UCSR0A - USART0 MSPIM Control and Status Register A */
//#define  UDRE0           5       // USART Data Register Empty
//#define  TXC0            6       // USART Transmit Complete
//#define  RXC0            7       // USART Receive Complete

/* UCSR0B - USART0 MSPIM Control and Status Register B */
//#define  TXEN0           3       // Transmitter Enable
//#define  RXEN0           4       // Receiver Enable
//#define  UDRIE0          5       // USART Data Register Empty Interrupt Enable
//#define  TXCIE0          6       // TX Complete Interrupt Enable
//#define  RXCIE0          7       // RX Complete Interrupt Enable

/* UCSR0C - USART0 MSPIM Control and Status Register C */
//#define  UCPOL0          0       // Clock Polarity
//#define  UCPHA0          1       // Clock Phase
//#define  UCSZ00          UCPHA0  // For compatibility
//#define  UDORD0          2       // Data Order
//#define  UCSZ01          UDORD0  // For compatibility


/* ***** USART1_SPI ******************* */
/* UCSR1A - USART1 MSPIM Control and Status Register A */
//#define  UDRE1           5       // USART Data Register Empty
//#define  TXC1            6       // USART Transmit Complete
//#define  RXC1            7       // USART Receive Complete

/* UCSR1B - USART1 MSPIM Control and Status Register B */
//#define  TXEN1           3       // Transmitter Enable
//#define  RXEN1           4       // Receiver Enable
//#define  UDRIE1          5       // USART Data Register Empty Interrupt Enable
//#define  TXCIE1          6       // TX Complete Interrupt Enable
//#define  RXCIE1          7       // RX Complete Interrupt Enable

/* UCSR1C - USART1 MSPIM Control and Status Register C */
//#define  UCPOL1          0       // Clock Polarity
//#define  UCPHA1          1       // Clock Phase
//#define  UCSZ10          UCPHA1  // For compatibility
//#define  UDORD1          2       // Data Order
//#define  UCSZ11          UDORD1  // For compatibility

#endif
