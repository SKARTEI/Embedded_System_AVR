/****************************************************
CodeVisionAVR V3.26+ C Compiler
(C) 1998-2016 Pavel Haiduc, HP InfoTech s.r.l.

I/O registers bit definitions for the ATtiny102
****************************************************/

#ifndef __TINY102_BITS_INCLUDED__
#define __TINY102_BITS_INCLUDED__


/* ***** AD_CONVERTER ***************** */
/* ADMUX - The ADC multiplexer Selection Register */
#define    MUX0            0       // Analog Channel Selection Bits
#define    MUX1            1       // Analog Channel Selection Bits
#define    MUX2            2       // Analog Channel Selection Bits
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
#define    ADLAR           7       // Left Adjust Result

/* ADCL - ADC Low Data Register */
#define    ADC0            0       // ADC Data Register Bit 0
#define    ADC1            1       // ADC Data Register Bit 1
#define    ADC2            2       // ADC Data Register Bit 2
#define    ADC3            3       // ADC Data Register Bit 3
#define    ADC4            4       // ADC Data Register Bit 4
#define    ADC5            5       // ADC Data Register Bit 5
#define    ADC6            6       // ADC Data Register Bit 6
#define    ADC7            7       // ADC Data Register Bit 7

/* ADCH - ADC High Data Register */
#define    ADC8            8       // ADC Data Register Bit 8
#define    ADC9            9       // ADC Data Register Bit 9

/* DIDR0 - Digital Input Disable Register */
#define    ADC0D           0       //
#define    ADC1D           1       //
#define    ADC5D           5       //
#define    ADC6D           6       //
#define    ADC7D           7       //


/* ***** ANALOG_COMPARATOR ************ */
/* ACSRA - Analog Comparator Control And Status Register A */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIC            2       // Analog Comparator Input Capture Enable
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Comparator Output
#define    ACBG            6       // Analog Comparator Bandgap Enable
#define    ACD             7       // Analog Comparator Disable

/* ACSRB - Analog Comparator Control And Status Register B */
#define    ACPMUX          0       // Analog Comparator Positive Input Multiplexer
#define    ACOE            1       // Analog Comparator Output Enable

/* DIDR0 -  */
#define    AIN0D           0       // AIN0 Digital Input Disable
#define    AIN1D           1       // AIN1 Digital Input Disable


/* ***** CPU ************************** */
/* CCP - Configuration Change Protection */
#define    CCP0            0       // Configuration Change Protection bit 0
#define    CCP1            1       // Configuration Change Protection bit 1
#define    CCP2            2       // Configuration Change Protection bit 2
#define    CCP3            3       // Configuration Change Protection bit 3
#define    CCP4            4       // Configuration Change Protection bit 4
#define    CCP5            5       // Configuration Change Protection bit 5
#define    CCP6            6       // Configuration Change Protection bit 6
#define    CCP7            7       // Configuration Change Protection bit 7

/* SREG - Status Register */
#define    SREG_C          0       // Carry Flag
#define    SREG_Z          1       // Zero Flag
#define    SREG_N          2       // Negative Flag
#define    SREG_V          3       // Two's Complement Overflow Flag
#define    SREG_S          4       // Sign Bit
#define    SREG_H          5       // Half Carry Flag
#define    SREG_T          6       // Bit Copy Storage
#define    SREG_I          7       // Global Interrupt Enable

/* CLKMSR - Clock Main Settings Register */
#define    CLKMS0          0       // Clock Main Select Bit 0
#define    CLKMS1          1       // Clock Main Select Bit 1

/* CLKPSR - Clock Prescale Register */
#define    CLKPS0          0       // Clock Prescaler Select Bit 0
#define    CLKPS1          1       // Clock Prescaler Select Bit 1
#define    CLKPS2          2       // Clock Prescaler Select Bit 2
#define    CLKPS3          3       // Clock Prescaler Select Bit 3

/* OSCCAL - Oscillator Calibration Value */
#define    CAL0            0       // Oscillator Calibration Value Bit0
#define    CAL1            1       // Oscillator Calibration Value Bit1
#define    CAL2            2       // Oscillator Calibration Value Bit2
#define    CAL3            3       // Oscillator Calibration Value Bit3
#define    CAL4            4       // Oscillator Calibration Value Bit4
#define    CAL5            5       // Oscillator Calibration Value Bit5
#define    CAL6            6       // Oscillator Calibration Value Bit6
#define    CAL7            7       // Oscillator Calibration Value Bit7

/* SMCR - Sleep Mode Control Register */
#define    SE              0       // Sleep Enable
#define    SM0             1       // Sleep Mode Select Bit 0
#define    SM1             2       // Sleep Mode Select Bit 1
#define    SM2             3       // Sleep Mode Select Bit 2

/* PRR - Power Reduction Register */
#define    PRTIM0          0       // Power Reduction Timer/Counter0
#define    PRADC           1       // Power Reduction ADC
#define    PRUSART0        2       // Power Reduction USART

/* VLMCSR - Vcc Level Monitoring Control and Status Register */
#define    VLM0            0       // Trigger Level of Voltage Level Monitor bit 0
#define    VLM1            1       // Trigger Level of Voltage Level Monitor bit 1
#define    VLM2            2       // Trigger Level of Voltage Level Monitor bit 2
#define    VLMIE           6       // VLM Interrupt Enable
#define    VLMF            7       // VLM Flag

/* RSTFLR - Reset Flag Register */
#define    PORF            0       // Power-on Reset Flag
#define    EXTRF           1       // External Reset Flag
#define    WDRF            3       // Watchdog Reset Flag

/* NVMCSR - Non-Volatile Memory Control and Status Register */
#define    NVMBSY          7       // Non-Volatile Memory Busy

/* NVMCMD - Non-Volatile Memory Command */
#define    NVMCMD0         0       //
#define    NVMCMD1         1       //
#define    NVMCMD2         2       //
#define    NVMCMD3         3       //
#define    NVMCMD4         4       //
#define    NVMCMD5         5       //


/* ***** PORTA ************************ */
/* PORTCR - Port Control Register */
#define    BBMA            0       // Break-Before-Make Mode Enable

/* PUEA - Pull-up Enable Control Register */
#define    PUEA0           0       //
#define    PUEA1           1       //
#define    PUEA2           2       //

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

/* ***** PORTB ************************ */
/* PORTCR - Port Control Register */
#define    BBMB            1       // Break-Before-Make Mode Enable

/* PUEB - Pull-up Enable Control Register */
#define    PUEB0           0       //
#define    PUEB1           1       //
#define    PUEB2           2       //
#define    PUEB3           3       //

/* PORTB - Input Pins, Port B */
#define    PORTB0          0       //
#define    PORTB1          1       //
#define    PORTB2          2       //
#define    PORTB3          3       //

/* DDRB - Data Direction Register, Port B */
#define    DDB0            0       //
#define    DDB1            1       //
#define    DDB2            2       //
#define    DDB3            3       //

/* PINB - Port B Data register */
#define    PINB0           0       //
#define    PINB1           1       //
#define    PINB2           2       //
#define    PINB3           3       //


/* ***** EXTERNAL_INTERRUPT *********** */
/* EICRA - External Interrupt Control Register A */
#define    ISC00           0       // Interrupt Sense Control 0 Bit 0
#define    ISC01           1       // Interrupt Sense Control 0 Bit 1

/* EIMSK - External Interrupt Mask register */
#define    INT0            0       // External Interrupt Request 0 Enable

/* EIFR - External Interrupt Flag register */
#define    INTF0           0       // External Interrupt Flag 0

/* PCICR - Pin Change Interrupt Control Register */
#define    PCIE0           0       // Pin Change Interrupt Enable 0
#define    PCIE1           1       // Pin Change Interrupt Enable 1

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 0
#define    PCIF1           1       // Pin Change Interrupt Flag 1

/* PCMSK0 - Pin Change Mask Register 0 */
#define    PCINT0          0       // Pin Change Enable Mask 0
#define    PCINT1          1       // Pin Change Enable Mask 1
#define    PCINT2          2       // Pin Change Enable Mask 2

/* PCMSK1 - Pin Change Mask Register 1 */
#define    PCINT9          1       // Pin Change Enable Mask 9
#define    PCINT10         2       // Pin Change Enable Mask 10
#define    PCINT11         3       // Pin Change Enable Mask 11


/* ***** TIMER_COUNTER_0 ************** */
/* TCCR0A - Timer/Counter 0 Control Register A */
#define    WGM00           0       // Waveform Generation Mode
#define    WGM01           1       // Waveform Generation Mode
#define    COM0B0          4       // Compare Output Mode for Channel B bit 0
#define    COM0B1          5       // Compare Output Mode for Channel B bit 1
#define    COM0A0          6       // Compare Output Mode for Channel A bit 0
#define    COM0A1          7       // Compare Output Mode for Channel A bit 1

/* TCCR0B - Timer/Counter 0 Control Register B */
#define    CS00            0       // Clock Select
#define    CS01            1       // Clock Select
#define    CS02            2       // Clock Select
#define    WGM02           3       // Waveform Generation Mode
#define    WGM03           4       // Waveform Generation Mode
#define    ICES0           6       // Input Capture Edge Select
#define    ICNC0           7       // Input Capture Noise Canceler

/* TCCR0C - Timer/Counter 0 Control Register C */
#define    FOC0B           6       // Force Output Compare for Channel B
#define    FOC0A           7       // Force Output Compare for Channel A

/* TIMSK0 - Timer Interrupt Mask Register 0 */
#define    TOIE0           0       // Overflow Interrupt Enable
#define    OCIE0A          1       // Output Compare A Match Interrupt Enable
#define    OCIE0B          2       // Output Compare B Match Interrupt Enable
#define    ICIE0           5       // Input Capture Interrupt Enable

/* TIFR0 - Overflow Interrupt Enable */
#define    TOV0            0       // Timer Overflow Flag
#define    OCF0A           1       // Timer Output Compare Flag 0A
#define    OCF0B           2       // Timer Output Compare Flag 0B
#define    ICF0            5       // Input Capture Flag

/* GTCCR - General Timer/Counter Control Register */
#define    PSR             0       // Prescaler Reset
#define    TSM             7       // Timer Synchronization Mode

/* ***** USART0 *********************** */
/* UDR0 - USART I/O Data Register */
#define    TXB0           0        // USART I/O Data Register bit 0
#define    TXB1           1        // USART I/O Data Register bit 1
#define    TXB2           2        // USART I/O Data Register bit 2
#define    TXB3           3        // USART I/O Data Register bit 3
#define    TXB4           4        // USART I/O Data Register bit 4
#define    TXB5           5        // USART I/O Data Register bit 5
#define    TXB6           6        // USART I/O Data Register bit 6
#define    TXB7           7        // USART I/O Data Register bit 7

#define    RXB0           0        // USART I/O Data Register bit 0
#define    RXB1           1        // USART I/O Data Register bit 1
#define    RXB2           2        // USART I/O Data Register bit 2
#define    RXB3           3        // USART I/O Data Register bit 3
#define    RXB4           4        // USART I/O Data Register bit 4
#define    RXB5           5        // USART I/O Data Register bit 5
#define    RXB6           6        // USART I/O Data Register bit 6
#define    RXB7           7        // USART I/O Data Register bit 7

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
#define    UCSZ2           UCSZ02  // For compatibility
#define    TXEN0           3       // Transmitter Enable
#define    RXEN0           4       // Receiver Enable
#define    UDRIE0          5       // USART Data register Empty Interrupt Enable
#define    TXCIE0          6       // TX Complete Interrupt Enable
#define    RXCIE0          7       // RX Complete Interrupt Enable

/* UCSR0C - USART Control and Status Register C */
#define    UCPOL0          0       // Clock Polarity
#define    UCSZ00          1       // Character Size
#define    UCSZ01          2       // Character Size
#define    USBS0           3       // Stop Bit Select
#define    UPM00           4       // Parity Mode Bit 0
#define    UPM01           5       // Parity Mode Bit 1
#define    UMSEL00         6       // USART Mode Select 0
#define    UMSEL01         7       // USART Mode Select 1

/* UCSR0D - USART Control and Status Register D */
#define    RXS             6       // RX Start
#define    RXIE            7       // RX Start Interrupt Enable 

/* UBRR0H - USART Baud Rate Register Hight Byte */
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

/* ***** WATCHDOG ********************* */
/* WDTCSR - Watchdog Timer Control and Status Register */
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDP3            5       // Watchdog Timer Prescaler Bit 3
#define    WDIE            6       // Watchdog Timer Interrupt Enable
#define    WDIF            7       // Watchdog Timer Interrupt Flag

#endif

