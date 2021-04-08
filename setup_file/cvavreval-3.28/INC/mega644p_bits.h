/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATmega644P I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __MEGA644P_BITS_INCLUDED__
#define __MEGA644P_BITS_INCLUDED__

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
#define    ACD             7       // Analog Comparator Disable

/* DIDR1 - Digital Input Disable Register 1 */
#define    AIN0D           0       // AIN0 Digital Input Disable
#define    AIN1D           1       // AIN1 Digital Input Disable


/* ***** USART0 *********************** */
/* UDR0 - USART I/O Data Register */
#define    UDR0_0          0       // USART I/O Data Register bit 0
#define    UDR0_1          1       // USART I/O Data Register bit 1
#define    UDR0_2          2       // USART I/O Data Register bit 2
#define    UDR0_3          3       // USART I/O Data Register bit 3
#define    UDR0_4          4       // USART I/O Data Register bit 4
#define    UDR0_5          5       // USART I/O Data Register bit 5
#define    UDR0_6          6       // USART I/O Data Register bit 6
#define    UDR0_7          7       // USART I/O Data Register bit 7

/* UCSR0A - USART Control and Status Register A */
#define    MPCM0           0       // Multi-processor Communication Mode
#define    U2X0            1       // Double the USART transmission speed
#define    UPE0            2       // Parity Error
#define    DOR0            3       // Data overRun
#define    FE0             4       // Framing Error
#define    UDRE0           5       // USART Data Register Empty
#define    TXC0            6       // USART Transmitt Complete
#define    RXC0            7       // USART Receive Complete

/* UCSR0B - USART Control and Status Register B */
#define    TXB80           0       // Transmit Data Bit 8
#define    RXB80           1       // Receive Data Bit 8
#define    UCSZ02          2       // Character Size
#define    TXEN0           3       // Transmitter Enable
#define    RXEN0           4       // Receiver Enable
#define    UDRIE0          5       // USART Data register Empty Interrupt Enable
#define    TXCIE0          6       // TX Complete Interrupt Enable
#define    RXCIE0          7       // RX Complete Interrupt Enable

/* UCSR0C - USART Control and Status Register C */
#define    UCPOL0          0       // Clock Polarity
#define    UCSZ00          1       // Character Size
#define    UCPHA0          UCSZ00  // For compatibility
#define    UCSZ01          2       // Character Size
#define    UDORD0          UCSZ01  // For compatibility
#define    USBS0           3       // Stop Bit Select
#define    UPM00           4       // Parity Mode Bit 0
#define    UPM01           5       // Parity Mode Bit 1
#define    UMSEL00         6       // USART Mode Select
#define    UMSEL0          UMSEL00 // For compatibility
#define    UMSEL01         7       // USART Mode Select
#define    UMSEL1          UMSEL01 // For compatibility

/* UBRR0H - USART Baud Rate Register High Byte */
#define    UBRR8           0       // USART Baud Rate Register bit 8
#define    UBRR9           1       // USART Baud Rate Register bit 9
#define    UBRR10          2       // USART Baud Rate Register bit 10
#define    UBRR11          3       // USART Baud Rate Register bit 11

/* UBRR0L - USART Baud Rate Register Low Byte */
#define    UBRR0           0       // USART Baud Rate Register bit 0
#define    UBRR1           1       // USART Baud Rate Register bit 1
#define    UBRR2           2       // USART Baud Rate Register bit 2
#define    UBRR3           3       // USART Baud Rate Register bit 3
#define    UBRR4           4       // USART Baud Rate Register bit 4
#define    UBRR5           5       // USART Baud Rate Register bit 5
#define    UBRR6           6       // USART Baud Rate Register bit 6
#define    UBRR7           7       // USART Baud Rate Register bit 7


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


/* ***** TIMER_COUNTER_0 ************** */
/* TIMSK0 - Timer/Counter0 Interrupt Mask Register */
#define    TOIE0           0       // Timer/Counter0 Overflow Interrupt Enable
#define    OCIE0A          1       // Timer/Counter0 Output Compare Match A Interrupt Enable
#define    OCIE0B          2       // Timer/Counter0 Output Compare Match B Interrupt Enable

/* TIFR0 - Timer/Counter0 Interrupt Flag register */
#define    TOV0            0       // Timer/Counter0 Overflow Flag
#define    OCF0A           1       // Timer/Counter0 Output Compare Flag 0A
#define    OCF0B           2       // Timer/Counter0 Output Compare Flag 0B

/* TCCR0A - Timer/Counter  Control Register A */
#define    WGM00           0       // Waveform Generation Mode
#define    WGM01           1       // Waveform Generation Mode
#define    COM0B0          4       // Compare Output Mode, Fast PWm
#define    COM0B1          5       // Compare Output Mode, Fast PWm
#define    COM0A0          6       // Compare Output Mode, Phase Correct PWM Mode
#define    COM0A1          7       // Compare Output Mode, Phase Correct PWM Mode

/* TCCR0B - Timer/Counter Control Register B */
#define    CS00            0       // Clock Select
#define    CS01            1       // Clock Select
#define    CS02            2       // Clock Select
#define    WGM02           3       // 
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

/* OCR0A - Timer/Counter0 Output Compare Register */
#define    OCROA_0         0       // 
#define    OCROA_1         1       // 
#define    OCROA_2         2       // 
#define    OCROA_3         3       // 
#define    OCROA_4         4       // 
#define    OCROA_5         5       // 
#define    OCROA_6         6       // 
#define    OCROA_7         7       // 

/* OCR0B - Timer/Counter0 Output Compare Register */
#define    OCR0B_0         0       // 
#define    OCR0B_1         1       // 
#define    OCR0B_2         2       // 
#define    OCR0B_3         3       // 
#define    OCR0B_4         4       // 
#define    OCR0B_5         5       // 
#define    OCR0B_6         6       // 
#define    OCR0B_7         7       // 

/* GTCCR - General Timer/Counter Control Register */
#define    PSRSYNC         0       // Prescaler Reset Timer/Counter1 and Timer/Counter0
#define    PSR10           PSRSYNC // For compatibility
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** TIMER_COUNTER_2 ************** */
/* TIMSK2 - Timer/Counter Interrupt Mask register */
#define    TOIE2           0       // Timer/Counter2 Overflow Interrupt Enable
#define    TOIE2A          TOIE2   // For compatibility
#define    OCIE2A          1       // Timer/Counter2 Output Compare Match A Interrupt Enable
#define    OCIE2B          2       // Timer/Counter2 Output Compare Match B Interrupt Enable

/* TIFR2 - Timer/Counter Interrupt Flag Register */
#define    TOV2            0       // Timer/Counter2 Overflow Flag
#define    OCF2A           1       // Output Compare Flag 2A
#define    OCF2B           2       // Output Compare Flag 2B

/* TCCR2A - Timer/Counter2 Control Register A */
#define    WGM20           0       // Waveform Genration Mode
#define    WGM21           1       // Waveform Genration Mode
#define    COM2B0          4       // Compare Output Mode bit 0
#define    COM2B1          5       // Compare Output Mode bit 1
#define    COM2A0          6       // Compare Output Mode bit 1
#define    COM2A1          7       // Compare Output Mode bit 1

/* TCCR2B - Timer/Counter2 Control Register B */
#define    CS20            0       // Clock Select bit 0
#define    CS21            1       // Clock Select bit 1
#define    CS22            2       // Clock Select bit 2
#define    WGM22           3       // Waveform Generation Mode
#define    FOC2B           6       // Force Output Compare B
#define    FOC2A           7       // Force Output Compare A

/* TCNT2 - Timer/Counter2 */
#define    TCNT2_0         0       // Timer/Counter 2 bit 0
#define    TCNT2_1         1       // Timer/Counter 2 bit 1
#define    TCNT2_2         2       // Timer/Counter 2 bit 2
#define    TCNT2_3         3       // Timer/Counter 2 bit 3
#define    TCNT2_4         4       // Timer/Counter 2 bit 4
#define    TCNT2_5         5       // Timer/Counter 2 bit 5
#define    TCNT2_6         6       // Timer/Counter 2 bit 6
#define    TCNT2_7         7       // Timer/Counter 2 bit 7

/* OCR2A - Timer/Counter2 Output Compare Register A */
#define    OCR2A_0         0       // Timer/Counter2 Output Compare Register Bit 0
#define    OCR2A_1         1       // Timer/Counter2 Output Compare Register Bit 1
#define    OCR2A_2         2       // Timer/Counter2 Output Compare Register Bit 2
#define    OCR2A_3         3       // Timer/Counter2 Output Compare Register Bit 3
#define    OCR2A_4         4       // Timer/Counter2 Output Compare Register Bit 4
#define    OCR2A_5         5       // Timer/Counter2 Output Compare Register Bit 5
#define    OCR2A_6         6       // Timer/Counter2 Output Compare Register Bit 6
#define    OCR2A_7         7       // Timer/Counter2 Output Compare Register Bit 7

/* OCR2B - Timer/Counter2 Output Compare Register B */
#define    OCR2B_0         0       // Timer/Counter2 Output Compare Register Bit 0
#define    OCR2B_1         1       // Timer/Counter2 Output Compare Register Bit 1
#define    OCR2B_2         2       // Timer/Counter2 Output Compare Register Bit 2
#define    OCR2B_3         3       // Timer/Counter2 Output Compare Register Bit 3
#define    OCR2B_4         4       // Timer/Counter2 Output Compare Register Bit 4
#define    OCR2B_5         5       // Timer/Counter2 Output Compare Register Bit 5
#define    OCR2B_6         6       // Timer/Counter2 Output Compare Register Bit 6
#define    OCR2B_7         7       // Timer/Counter2 Output Compare Register Bit 7

/* ASSR - Asynchronous Status Register */
#define    TCR2BUB         0       // Timer/Counter Control Register2 Update Busy
#define    TCR2AUB         1       // Timer/Counter Control Register2 Update Busy
#define    OCR2BUB         2       // Output Compare Register 2 Update Busy
#define    OCR2AUB         3       // Output Compare Register2 Update Busy
#define    TCN2UB          4       // Timer/Counter2 Update Busy
#define    AS2             5       // Asynchronous Timer/Counter2
#define    EXCLK           6       // Enable External Clock Input

/* GTCCR - General Timer Counter Control register */
#define    PSRASY          1       // Prescaler Reset Timer/Counter2
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


/* ***** JTAG ************************* */
/* OCDR - On-Chip Debug Related Register in I/O Memory */
#define    OCDR0           0       // On-Chip Debug Register Bit 0
#define    OCDR1           1       // On-Chip Debug Register Bit 1
#define    OCDR2           2       // On-Chip Debug Register Bit 2
#define    OCDR3           3       // On-Chip Debug Register Bit 3
#define    OCDR4           4       // On-Chip Debug Register Bit 4
#define    OCDR5           5       // On-Chip Debug Register Bit 5
#define    OCDR6           6       // On-Chip Debug Register Bit 6
#define    OCDR7           7       // On-Chip Debug Register Bit 7
#define    IDRD            OCDR7   // For compatibility

/* MCUCR - MCU Control Register */
#define    JTD             7       // JTAG Interface Disable

/* MCUSR - MCU Status Register */
#define    JTRF            4       // JTAG Reset Flag


/* ***** BOOT_LOAD ******************** */
/* SPMCSR - Store Program Memory Control Register */
#define    SPMEN           0       // Store Program Memory Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    BLBSET          3       // Boot Lock Bit Set
#define    RWWSRE          4       // Read While Write section read enable
#define    SIGRD           5       // Signature Row Read
#define    RWWSB           6       // Read While Write Section Busy
#define    SPMIE           7       // SPM Interrupt Enable


/* ***** EXTERNAL_INTERRUPT *********** */
/* EICRA - External Interrupt Control Register A */
#define    ISC00           0       // External Interrupt Sense Control Bit
#define    ISC01           1       // External Interrupt Sense Control Bit
#define    ISC10           2       // External Interrupt Sense Control Bit
#define    ISC11           3       // External Interrupt Sense Control Bit
#define    ISC20           4       // External Interrupt Sense Control Bit
#define    ISC21           5       // External Interrupt Sense Control Bit

/* EIMSK - External Interrupt Mask Register */
#define    INT0            0       // External Interrupt Request 0 Enable
#define    INT1            1       // External Interrupt Request 1 Enable
#define    INT2            2       // External Interrupt Request 2 Enable

/* EIFR - External Interrupt Flag Register */
#define    INTF0           0       // External Interrupt Flag 0
#define    INTF1           1       // External Interrupt Flag 1
#define    INTF2           2       // External Interrupt Flag 2

/* PCICR - Pin Change Interrupt Control Register */
#define    PCIE0           0       // Pin Change Interrupt Enable 0
#define    PCIE1           1       // Pin Change Interrupt Enable 1
#define    PCIE2           2       // Pin Change Interrupt Enable 2
#define    PCIE3           3       // Pin Change Interrupt Enable 3

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 0
#define    PCIF1           1       // Pin Change Interrupt Flag 1
#define    PCIF2           2       // Pin Change Interrupt Flag 2
#define    PCIF3           3       // Pin Change Interrupt Flag 3

/* PCMSK3 - Pin Change Mask Register 3 */
#define    PCINT24         0       // Pin Change Enable Mask 24
#define    PCINT25         1       // Pin Change Enable Mask 25
#define    PCINT26         2       // Pin Change Enable Mask 26
#define    PCINT27         3       // Pin Change Enable Mask 27
#define    PCINT28         4       // Pin Change Enable Mask 28
#define    PCINT29         5       // Pin Change Enable Mask 29
#define    PCINT30         6       // Pin Change Enable Mask 30
#define    PCINT31         7       // Pin Change Enable Mask 31

/* PCMSK2 - Pin Change Mask Register 2 */
#define    PCINT16         0       // Pin Change Enable Mask 16
#define    PCINT17         1       // Pin Change Enable Mask 17
#define    PCINT18         2       // Pin Change Enable Mask 18
#define    PCINT19         3       // Pin Change Enable Mask 19
#define    PCINT20         4       // Pin Change Enable Mask 20
#define    PCINT21         5       // Pin Change Enable Mask 21
#define    PCINT22         6       // Pin Change Enable Mask 22
#define    PCINT23         7       // Pin Change Enable Mask 23

/* PCMSK1 - Pin Change Mask Register 1 */
#define    PCINT8          0       // Pin Change Enable Mask 8
#define    PCINT9          1       // Pin Change Enable Mask 9
#define    PCINT10         2       // Pin Change Enable Mask 10
#define    PCINT11         3       // Pin Change Enable Mask 11
#define    PCINT12         4       // Pin Change Enable Mask 12
#define    PCINT13         5       // Pin Change Enable Mask 13
#define    PCINT14         6       // Pin Change Enable Mask 14
#define    PCINT15         7       // Pin Change Enable Mask 15

/* PCMSK0 - Pin Change Mask Register 0 */
#define    PCINT0          0       // Pin Change Enable Mask 0
#define    PCINT1          1       // Pin Change Enable Mask 1
#define    PCINT2          2       // Pin Change Enable Mask 2
#define    PCINT3          3       // Pin Change Enable Mask 3
#define    PCINT4          4       // Pin Change Enable Mask 4
#define    PCINT5          5       // Pin Change Enable Mask 5
#define    PCINT6          6       // Pin Change Enable Mask 6
#define    PCINT7          7       // Pin Change Enable Mask 7


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

/* ADCSRA - The ADC Control and Status register A */
#define    ADPS0           0       // ADC  Prescaler Select Bits
#define    ADPS1           1       // ADC  Prescaler Select Bits
#define    ADPS2           2       // ADC  Prescaler Select Bits
#define    ADIE            3       // ADC Interrupt Enable
#define    ADIF            4       // ADC Interrupt Flag
#define    ADATE           5       // ADC  Auto Trigger Enable
#define    ADSC            6       // ADC Start Conversion
#define    ADEN            7       // ADC Enable

/* ADCSRB - The ADC Control and Status register B */
#define    ADTS0           0       // ADC Auto Trigger Source bit 0
#define    ADTS1           1       // ADC Auto Trigger Source bit 1
#define    ADTS2           2       // ADC Auto Trigger Source bit 2
//#define  ACME            6       // 

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

/* DIDR0 - Digital Input Disable Register */
#define    ADC0D           0       // 
#define    ADC1D           1       // 
#define    ADC2D           2       // 
#define    ADC3D           3       // 
#define    ADC4D           4       // 
#define    ADC5D           5       // 
#define    ADC6D           6       // 
#define    ADC7D           7       // 


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


/* ***** EEPROM *********************** */
/* EEARH - EEPROM Address Register Low Byte */
#define    EEAR8           0       // EEPROM Read/Write Access Bit 8
#define    EEAR9           1       // EEPROM Read/Write Access Bit 9
#define    EEAR10          2       // EEPROM Read/Write Access Bit 10
#define    EEAR11          3       // EEPROM Read/Write Access Bit 11

/* EEARL - EEPROM Address Register Low Byte */
#define    EEAR0           0       // EEPROM Read/Write Access Bit 0
#define    EEAR1           1       // EEPROM Read/Write Access Bit 1
#define    EEAR2           2       // EEPROM Read/Write Access Bit 2
#define    EEAR3           3       // EEPROM Read/Write Access Bit 3
#define    EEAR4           4       // EEPROM Read/Write Access Bit 4
#define    EEAR5           5       // EEPROM Read/Write Access Bit 5
#define    EEAR6           6       // EEPROM Read/Write Access Bit 6
#define    EEAR7           7       // EEPROM Read/Write Access Bit 7

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


/* ***** TWI ************************** */
/* TWAMR - TWI (Slave) Address Mask Register */
#define    TWAM0           1       // 
#define    TWAMR0          TWAM0   // For compatibility
#define    TWAM1           2       // 
#define    TWAMR1          TWAM1   // For compatibility
#define    TWAM2           3       // 
#define    TWAMR2          TWAM2   // For compatibility
#define    TWAM3           4       // 
#define    TWAMR3          TWAM3   // For compatibility
#define    TWAM4           5       // 
#define    TWAMR4          TWAM4   // For compatibility
#define    TWAM5           6       // 
#define    TWAMR5          TWAM5   // For compatibility
#define    TWAM6           7       // 
#define    TWAMR6          TWAM6   // For compatibility

/* TWBR - TWI Bit Rate register */
#define    TWBR0           0       // 
#define    TWBR1           1       // 
#define    TWBR2           2       // 
#define    TWBR3           3       // 
#define    TWBR4           4       // 
#define    TWBR5           5       // 
#define    TWBR6           6       // 
#define    TWBR7           7       // 

/* TWCR - TWI Control Register */
#define    TWIE            0       // TWI Interrupt Enable
#define    TWEN            2       // TWI Enable Bit
#define    TWWC            3       // TWI Write Collition Flag
#define    TWSTO           4       // TWI Stop Condition Bit
#define    TWSTA           5       // TWI Start Condition Bit
#define    TWEA            6       // TWI Enable Acknowledge Bit
#define    TWINT           7       // TWI Interrupt Flag

/* TWSR - TWI Status Register */
#define    TWPS0           0       // TWI Prescaler
#define    TWPS1           1       // TWI Prescaler
#define    TWS3            3       // TWI Status
#define    TWS4            4       // TWI Status
#define    TWS5            5       // TWI Status
#define    TWS6            6       // TWI Status
#define    TWS7            7       // TWI Status

/* TWDR - TWI Data register */
#define    TWD0            0       // TWI Data Register Bit 0
#define    TWD1            1       // TWI Data Register Bit 1
#define    TWD2            2       // TWI Data Register Bit 2
#define    TWD3            3       // TWI Data Register Bit 3
#define    TWD4            4       // TWI Data Register Bit 4
#define    TWD5            5       // TWI Data Register Bit 5
#define    TWD6            6       // TWI Data Register Bit 6
#define    TWD7            7       // TWI Data Register Bit 7

/* TWAR - TWI (Slave) Address register */
#define    TWGCE           0       // TWI General Call Recognition Enable Bit
#define    TWA0            1       // TWI (Slave) Address register Bit 0
#define    TWA1            2       // TWI (Slave) Address register Bit 1
#define    TWA2            3       // TWI (Slave) Address register Bit 2
#define    TWA3            4       // TWI (Slave) Address register Bit 3
#define    TWA4            5       // TWI (Slave) Address register Bit 4
#define    TWA5            6       // TWI (Slave) Address register Bit 5
#define    TWA6            7       // TWI (Slave) Address register Bit 6


/* ***** USART1 *********************** */
/* UDR1 - USART I/O Data Register */
#define    UDR1_0          0       // USART I/O Data Register bit 0
#define    UDR1_1          1       // USART I/O Data Register bit 1
#define    UDR1_2          2       // USART I/O Data Register bit 2
#define    UDR1_3          3       // USART I/O Data Register bit 3
#define    UDR1_4          4       // USART I/O Data Register bit 4
#define    UDR1_5          5       // USART I/O Data Register bit 5
#define    UDR1_6          6       // USART I/O Data Register bit 6
#define    UDR1_7          7       // USART I/O Data Register bit 7

/* UCSR1A - USART Control and Status Register A */
#define    MPCM1           0       // Multi-processor Communication Mode
#define    U2X1            1       // Double the USART transmission speed
#define    UPE1            2       // Parity Error
#define    DOR1            3       // Data overRun
#define    FE1             4       // Framing Error
#define    UDRE1           5       // USART Data Register Empty
#define    TXC1            6       // USART Transmitt Complete
#define    RXC1            7       // USART Receive Complete

/* UCSR1B - USART Control and Status Register B */
#define    TXB81           0       // Transmit Data Bit 8
#define    RXB81           1       // Receive Data Bit 8
#define    UCSZ12          2       // Character Size
#define    TXEN1           3       // Transmitter Enable
#define    RXEN1           4       // Receiver Enable
#define    UDRIE1          5       // USART Data register Empty Interrupt Enable
#define    TXCIE1          6       // TX Complete Interrupt Enable
#define    RXCIE1          7       // RX Complete Interrupt Enable

/* UCSR1C - USART Control and Status Register C */
#define    UCPOL1          0       // Clock Polarity
#define    UCSZ10          1       // Character Size
#define    UCPHA1          UCSZ10  // For compatibility
#define    UCSZ11          2       // Character Size
#define    UDORD1          UCSZ11  // For compatibility
#define    USBS1           3       // Stop Bit Select
#define    UPM10           4       // Parity Mode Bit 0
#define    UPM11           5       // Parity Mode Bit 1
#define    UMSEL10         6       // USART Mode Select
#define    UMSEL11         7       // USART Mode Select

/* UBRR1H - USART Baud Rate Register High Byte */
#define    UBRR_8          0       // USART Baud Rate Register bit 8
#define    UBRR_9          1       // USART Baud Rate Register bit 9
#define    UBRR_10         2       // USART Baud Rate Register bit 10
#define    UBRR_11         3       // USART Baud Rate Register bit 11

/* UBRR1L - USART Baud Rate Register Low Byte */
#define    UBRR_0          0       // USART Baud Rate Register bit 0
#define    UBRR_1          1       // USART Baud Rate Register bit 1
#define    UBRR_2          2       // USART Baud Rate Register bit 2
#define    UBRR_3          3       // USART Baud Rate Register bit 3
#define    UBRR_4          4       // USART Baud Rate Register bit 4
#define    UBRR_5          5       // USART Baud Rate Register bit 5
#define    UBRR_6          6       // USART Baud Rate Register bit 6
#define    UBRR_7          7       // USART Baud Rate Register bit 7


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
#define    PUD             4       // Pull-up disable
#define    BODSE           5       // BOD Power Down in Sleep Enable
#define    BODS            6       // BOD Power Down in Sleep
//#define  JTD             7       // JTAG Interface Disable

/* MCUSR - MCU Status Register */
#define    PORF            0       // Power-on reset flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag
//#define  JTRF            4       // JTAG Reset Flag

/* OSCCAL - Oscillator Calibration Value */
#define    CAL0            0       // Oscillator Calibration Value Bit0
#define    CAL1            1       // Oscillator Calibration Value Bit1
#define    CAL2            2       // Oscillator Calibration Value Bit2
#define    CAL3            3       // Oscillator Calibration Value Bit3
#define    CAL4            4       // Oscillator Calibration Value Bit4
#define    CAL5            5       // Oscillator Calibration Value Bit5
#define    CAL6            6       // Oscillator Calibration Value Bit6
#define    CAL7            7       // Oscillator Calibration Value Bit7

/* CLKPR -  */
#define    CLKPS0          0       // 
#define    CLKPS1          1       // 
#define    CLKPS2          2       // 
#define    CLKPS3          3       // 
#define    CLKPCE          7       // 

/* SMCR - Sleep Mode Control Register */
#define    SE              0       // Sleep Enable
#define    SM0             1       // Sleep Mode Select bit 0
#define    SM1             2       // Sleep Mode Select bit 1
#define    SM2             3       // Sleep Mode Select bit 2

/* RAMPZ - RAM Page Z Select Register */
#define    RAMPZ0          0       // RAM Page Z Select Register Bit 0

/* GPIOR2 - General Purpose IO Register 2 */
#define    GPIOR20         0       // General Purpose IO Register 2 bit 0
#define    GPIOR21         1       // General Purpose IO Register 2 bit 1
#define    GPIOR22         2       // General Purpose IO Register 2 bit 2
#define    GPIOR23         3       // General Purpose IO Register 2 bit 3
#define    GPIOR24         4       // General Purpose IO Register 2 bit 4
#define    GPIOR25         5       // General Purpose IO Register 2 bit 5
#define    GPIOR26         6       // General Purpose IO Register 2 bit 6
#define    GPIOR27         7       // General Purpose IO Register 2 bit 7

/* GPIOR1 - General Purpose IO Register 1 */
#define    GPIOR10         0       // General Purpose IO Register 1 bit 0
#define    GPIOR11         1       // General Purpose IO Register 1 bit 1
#define    GPIOR12         2       // General Purpose IO Register 1 bit 2
#define    GPIOR13         3       // General Purpose IO Register 1 bit 3
#define    GPIOR14         4       // General Purpose IO Register 1 bit 4
#define    GPIOR15         5       // General Purpose IO Register 1 bit 5
#define    GPIOR16         6       // General Purpose IO Register 1 bit 6
#define    GPIOR17         7       // General Purpose IO Register 1 bit 7

/* GPIOR0 - General Purpose IO Register 0 */
#define    GPIOR00         0       // General Purpose IO Register 0 bit 0
#define    GPIOR01         1       // General Purpose IO Register 0 bit 1
#define    GPIOR02         2       // General Purpose IO Register 0 bit 2
#define    GPIOR03         3       // General Purpose IO Register 0 bit 3
#define    GPIOR04         4       // General Purpose IO Register 0 bit 4
#define    GPIOR05         5       // General Purpose IO Register 0 bit 5
#define    GPIOR06         6       // General Purpose IO Register 0 bit 6
#define    GPIOR07         7       // General Purpose IO Register 0 bit 7

/* PRR0 - Power Reduction Register0 */
#define    PRADC           0       // Power Reduction ADC
#define    PRUSART0        1       // Power Reduction USART 0
#define    PRSPI           2       // Power Reduction Serial Peripheral Interface
#define    PRTIM1          3       // Power Reduction Timer/Counter1
#define    PRUSART1        4       // Power Reduction USART 1
#define    PRTIM0          5       // Power Reduction Timer/Counter0
#define    PRTIM2          6       // Power Reduction Timer/Counter2
#define    PRTWI           7       // Power Reduction TWI


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
#define    SPI2X           0       // Double SPI Speed Bit
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

#endif

