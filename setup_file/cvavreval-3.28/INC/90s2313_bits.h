/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2012 Pavel Haiduc, HP InfoTech s.r.l.

AT90S2313 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __90S2313_BITS_INCLUDED__
#define __90S2313_BITS_INCLUDED__

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


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TICIE1          3       // Timer/Counter1 Input Capture Interrupt Enable
#define    OCIE1A          6       // Timer/Counter1 Output CompareA Match Interrupt Enable
#define    TOIE1           7       // Timer/Counter1 Overflow Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag register */
#define    ICF1            3       // Input Capture Flag 1
#define    OCF1A           6       // Output Compare Flag 1A
#define    TOV1            7       // Timer/Counter1 Overflow Flag

/* TCCR1A - Timer/Counter1 Control Register A */
#define    PWM10           0       // Pulse Width Modulator Select Bit 0
#define    PWM11           1       // Pulse Width Modulator Select Bit 1
#define    COM1A0          6       // Comparet Ouput Mode 1A, bit 0
#define    COM1A1          7       // Compare Output Mode 1A, bit 1

/* TCCR1B - Timer/Counter1 Control Register B */
#define    CS10            0       // Clock Select bit 0
#define    CS11            1       // Clock Select 1 bit 1
#define    CS12            2       // Clock Select1 bit 2
#define    CTC1            3       // Clear Timer/Counter1 on Compare Match
#define    ICES1           6       // Input Capture 1 Edge Select
#define    ICNC1           7       // Input Capture 1 Noise Canceler


/* ***** WATCHDOG ********************* */
/* WDTCR - Watchdog Timer Control Register */
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDTOE           4       // RW
#define    WDDE            WDTOE   // For compatibility


/* ***** EXTERNAL_INTERRUPT *********** */
/* GIMSK - General Interrupt Mask Register */
#define    INT0            6       // External Interrupt Request 0 Enable
#define    INT1            7       // External Interrupt Request 1 Enable

/* GIFR - General Interrupt Flag register */
#define    INTF0           6       // External Interrupt Flag 0
#define    INTF1           7       // External Interrupt Flag 1


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
#define    OR              3       // Data overRun
#define    DOR             OR      // Data overRun
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


/* ***** ANALOG_COMPARATOR ************ */
/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIC            2       // Analog Comparator Input Capture Enable
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Comparator Output
#define    ACD             7       // Analog Comparator Disable


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
#define    ISC10           2       // Interrupt Sense Control 1 bit 0
#define    ISC11           3       // Interrupt Sense Control 1 bit 1
#define    SM              4       // Sleep Mode
#define    SE              5       // Sleep Enable


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
#define    EEWE            1       // EEPROM Write Enable
#define    EEMWE           2       // EEPROM Master Write Enable

#endif

