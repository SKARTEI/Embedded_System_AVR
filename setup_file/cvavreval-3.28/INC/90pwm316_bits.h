/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.

AT90PWM216, AT90PWM316 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __90PWM316_BITS_INCLUDED__
#define __90PWM316_BITS_INCLUDED__

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


/* ***** BOOT_LOAD ******************** */
/* SPMCSR - Store Program Memory Control Register */
#define    SPMCR           SPMCSR  // For compatibility
#define    SPMEN           0       // Store Program Memory Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    BLBSET          3       // Boot Lock Bit Set
#define    RWWSRE          4       // Read While Write section read enable
#define    ASRE            RWWSRE  // For compatibility
#define    RWWSB           6       // Read While Write Section Busy
#define    ASB             RWWSB   // For compatibility
#define    SPMIE           7       // SPM Interrupt Enable


/* ***** EUSART *********************** */
/* EUDR - EUSART I/O Data Register */
#define    EUDR0           0       // EUSART I/O Data Register bit 0
#define    EUDR1           1       // EUSART I/O Data Register bit 1
#define    EUDR2           2       // EUSART I/O Data Register bit 2
#define    EUDR3           3       // EUSART I/O Data Register bit 3
#define    EUDR4           4       // EUSART I/O Data Register bit 4
#define    EUDR5           5       // EUSART I/O Data Register bit 5
#define    EUDR6           6       // EUSART I/O Data Register bit 6
#define    EUDR7           7       // EUSART I/O Data Register bit 7

/* EUCSRA - EUSART Control and Status Register A */
#define    URxS0           0       // EUSART Control and Status Register A Bit 0
#define    URxS1           1       // EUSART Control and Status Register A Bit 1
#define    URxS2           2       // EUSART Control and Status Register A Bit 2
#define    URxS3           3       // EUSART Control and Status Register A Bit 3
#define    UTxS0           4       // EUSART Control and Status Register A Bit 4
#define    UTxS1           5       // EUSART Control and Status Register A Bit 5
#define    UTxS2           6       // EUSART Control and Status Register A Bit 6
#define    UTxS3           7       // EUSART Control and Status Register A Bit 7

/* EUCSRB - EUSART Control Register B */
#define    BODR            0       // Order Bit
#define    EMCH            1       // Manchester Mode Bit
#define    EUSBS           3       // EUSBS Enable Bit
#define    EUSART          4       // EUSART Enable Bit

/* EUCSRC - EUSART Status Register C */
#define    STP0            0       // Stop Bit 0
#define    STP1            1       // Stop Bit 1
#define    F1617           2       // F1617 Bit
#define    FEM             3       // Frame Error Manchester Bit

/* MUBRRH - Manchester Receiver Baud Rate Register High Byte */
#define    MUBRR8          0       // Manchester Receiver Baud Rate Register Bit 8
#define    MUBRR9          1       // Manchester Receiver Baud Rate Register Bit 9
#define    MUBRR10         2       // Manchester Receiver Baud Rate Register Bit 10
#define    MUBRR11         3       // Manchester Receiver Baud Rate Register Bit 11
#define    MUBRR12         4       // Manchester Receiver Baud Rate Register Bit 12
#define    MUBRR13         5       // Manchester Receiver Baud Rate Register Bit 13
#define    MUBRR14         6       // Manchester Receiver Baud Rate Register Bit 14
#define    MUBRR15         7       // Manchester Receiver Baud Rate Register Bit 15

/* MUBRRL - Manchester Receiver Baud Rate Register Low Byte */
#define    MUBRR0          0       // Manchester Receiver Baud Rate Register Bit 0
#define    MUBRR1          1       // Manchester Receiver Baud Rate Register Bit 1
#define    MUBRR2          2       // Manchester Receiver Baud Rate Register Bit 2
#define    MUBRR3          3       // Manchester Receiver Baud Rate Register Bit 3
#define    MUBRR4          4       // Manchester Receiver Baud Rate Register Bit 4
#define    MUBRR5          5       // Manchester Receiver Baud Rate Register Bit 5
#define    MUBRR6          6       // Manchester Receiver Baud Rate Register Bit 6
#define    MUBRR7          7       // Manchester Receiver Baud Rate Register Bit 7


/* ***** ANALOG_COMPARATOR ************ */
/* AC0CON - Analog Comparator 0 Control Register */
#define    AC0M0           0       // Analog Comparator 0 Multiplexer Register
#define    AC0M1           1       // Analog Comparator 0 Multiplexer Regsiter
#define    AC0M2           2       // Analog Comparator 0 Multiplexer Register
#define    AC0IS0          4       // Analog Comparator 0 Interrupt Select Bit
#define    AC0IS1          5       // Analog Comparator 0  Interrupt Select Bit
#define    AC0IE           6       // Analog Comparator 0 Interrupt Enable Bit
#define    AC0EN           7       // Analog Comparator 0 Enable Bit

/* AC1CON - Analog Comparator 1 Control Register */
#define    AC1M0           0       // Analog Comparator 1 Multiplexer Register
#define    AC1M1           1       // Analog Comparator 1 Multiplexer Regsiter
#define    AC1M2           2       // Analog Comparator 1 Multiplexer Register
#define    AC1ICE          3       // Analog Comparator 1 Interrupt Capture Enable Bit
#define    AC1IS0          4       // Analog Comparator 1 Interrupt Select Bit
#define    AC1IS1          5       // Analog Comparator 1  Interrupt Select Bit
#define    AC1IE           6       // Analog Comparator 1 Interrupt Enable Bit
#define    AC1EN           7       // Analog Comparator 1 Enable Bit

/* AC2CON - Analog Comparator 2 Control Register */
#define    AC2M0           0       // Analog Comparator 2 Multiplexer Register
#define    AC2M1           1       // Analog Comparator 2 Multiplexer Regsiter
#define    AC2M2           2       // Analog Comparator 2 Multiplexer Register
#define    AC2IS0          4       // Analog Comparator 2 Interrupt Select Bit
#define    AC2IS1          5       // Analog Comparator 2  Interrupt Select Bit
#define    AC2IE           6       // Analog Comparator 2 Interrupt Enable Bit
#define    AC2EN           7       // Analog Comparator 2 Enable Bit

/* ACSR - Analog Comparator Status Register */
#define    AC0O            0       // Analog Comparator 0 Output Bit
#define    AC1O            1       // Analog Comparator 1 Output Bit
#define    AC2O            2       // Analog Comparator 2 Output Bit
#define    AC0IF           4       // Analog Comparator 0 Interrupt Flag Bit
#define    AC1IF           5       // Analog Comparator 1  Interrupt Flag Bit
#define    AC2IF           6       // Analog Comparator 2 Interrupt Flag Bit
#define    ACCKDIV         7       // Analog Comparator Clock Divider


/* ***** DA_CONVERTER ***************** */
/* DACH - DAC Data Register High Byte */
#define    DACH0           0       // DAC Data Register High Byte Bit 0
#define    DACH1           1       // DAC Data Register High Byte Bit 1
#define    DACH2           2       // DAC Data Register High Byte Bit 2
#define    DACH3           3       // DAC Data Register High Byte Bit 3
#define    DACH4           4       // DAC Data Register High Byte Bit 4
#define    DACH5           5       // DAC Data Register High Byte Bit 5
#define    DACH6           6       // DAC Data Register High Byte Bit 6
#define    DACH7           7       // DAC Data Register High Byte Bit 7

/* DACL - DAC Data Register Low Byte */
#define    DACL0           0       // DAC Data Register Low Byte Bit 0
#define    DACL1           1       // DAC Data Register Low Byte Bit 1
#define    DACL2           2       // DAC Data Register Low Byte Bit 2
#define    DACL3           3       // DAC Data Register Low Byte Bit 3
#define    DACL4           4       // DAC Data Register Low Byte Bit 4
#define    DACL5           5       // DAC Data Register Low Byte Bit 5
#define    DACL6           6       // DAC Data Register Low Byte Bit 6
#define    DACL7           7       // DAC Data Register Low Byte Bit 7

/* DACON - DAC Control Register */
#define    DAEN            0       // DAC Enable Bit
#define    DAOE            1       // DAC Digital to Analog Output Enable Bit
#define    DALA            2       // DAC Left Adjust
#define    DATS0           4       // DAC Trigger Selection Bit 0
#define    DATS1           5       // DAC Trigger Selection Bit 1
#define    DATS2           6       // DAC Trigger Selection Bit 2
#define    DAATE           7       // DAC Auto Trigger Enable Bit


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
#define    SPIPS           7       // SPI Pin Select

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

/* GPIOR3 - General Purpose IO Register 3 */
#define    GPIOR30         0       // General Purpose IO Register 3 bit 0
#define    GPIOR31         1       // General Purpose IO Register 3 bit 1
#define    GPIOR32         2       // General Purpose IO Register 3 bit 2
#define    GPIOR33         3       // General Purpose IO Register 3 bit 3
#define    GPIOR34         4       // General Purpose IO Register 3 bit 4
#define    GPIOR35         5       // General Purpose IO Register 3 bit 5
#define    GPIOR36         6       // General Purpose IO Register 3 bit 6
#define    GPIOR37         7       // General Purpose IO Register 3 bit 7

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

/* PLLCSR - PLL Control And Status Register */
#define    PLOCK           0       // PLL Lock Detector
#define    PLLE            1       // PLL Enable
#define    PLLF            2       // PLL Factor

/* PRR - Power Reduction Register */
#define    PRADC           0       // Power Reduction ADC
#define    PRUSART0        1       // Power Reduction USART
#define    PRSPI           2       // Power Reduction Serial Peripheral Interface
#define    PRTIM0          3       // Power Reduction Timer/Counter0
#define    PRTIM1          4       // Power Reduction Timer/Counter1
#define    PRPSC0          5       // Power Reduction PSC0
#define    PRPSC1          6       // Power Reduction PSC1
#define    PRPSC2          7       // Power Reduction PSC2


/* ***** PORTE ************************ */
/* PORTE - Port E Data Register */
#define    PORTE0          0       // 
#define    PORTE1          1       // 
#define    PORTE2          2       // 

/* DDRE - Port E Data Direction Register */
#define    DDE0            0       // 
#define    DDE1            1       // 
#define    DDE2            2       // 

/* PINE - Port E Input Pins */
#define    PINE0           0       // 
#define    PINE1           1       // 
#define    PINE2           2       // 


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
#define    OCR0A_0         0       // 
#define    OCR0A_1         1       // 
#define    OCR0A_2         2       // 
#define    OCR0A_3         3       // 
#define    OCR0A_4         4       // 
#define    OCR0A_5         5       // 
#define    OCR0A_6         6       // 
#define    OCR0A_7         7       // 

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
#define    PSR10           0       // Prescaler Reset Timer/Counter1 and Timer/Counter0
#define    ICPSEL1         6       // Timer1 Input Capture Selection Bit
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK1 - Timer/Counter Interrupt Mask Register */
#define    TOIE1           0       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1A          1       // Timer/Counter1 Output CompareA Match Interrupt Enable
#define    OCIE1B          2       // Timer/Counter1 Output CompareB Match Interrupt Enable
#define    ICIE1           5       // Timer/Counter1 Input Capture Interrupt Enable

/* TIFR1 - Timer/Counter Interrupt Flag register */
#define    TOV1            0       // Timer/Counter1 Overflow Flag
#define    OCF1A           1       // Output Compare Flag 1A
#define    OCF1B           2       // Output Compare Flag 1B
#define    ICF1            5       // Input Capture Flag 1

/* TCCR1A - Timer/Counter1 Control Register A */
#define    WGM10           0       // Waveform Generation Mode
#define    WGM11           1       // Waveform Generation Mode
#define    COM1B0          4       // Compare Output Mode 1B, bit 0
#define    COM1B1          5       // Compare Output Mode 1B, bit 1
#define    COM1A0          6       // Comparet Ouput Mode 1A, bit 0
#define    COM1A1          7       // Compare Output Mode 1A, bit 1

/* TCCR1B - Timer/Counter1 Control Register B */
#define    CS10            0       // Prescaler source of Timer/Counter 1
#define    CS11            1       // Prescaler source of Timer/Counter 1
#define    CS12            2       // Prescaler source of Timer/Counter 1
#define    WGM12           3       // Waveform Generation Mode
#define    WGM13           4       // Waveform Generation Mode
#define    ICES1           6       // Input Capture 1 Edge Select
#define    ICNC1           7       // Input Capture 1 Noise Canceler

/* TCCR1C - Timer/Counter1 Control Register C */
#define    FOC1B           6       // 
#define    FOC1A           7       // 

/* GTCCR - General Timer/Counter Control Register */
#define    PSRSYNC         0       // Prescaler Reset Timer/Counter1 and Timer/Counter0
//#define  TSM             7       // Timer/Counter Synchronization Mode


/* ***** AD_CONVERTER ***************** */
/* ADMUX - The ADC multiplexer Selection Register */
#define    MUX0            0       // Analog Channel and Gain Selection Bits
#define    MUX1            1       // Analog Channel and Gain Selection Bits
#define    MUX2            2       // Analog Channel and Gain Selection Bits
#define    MUX3            3       // Analog Channel and Gain Selection Bits
#define    ADLAR           5       // Left Adjust Result
#define    REFS0           6       // Reference Selection Bit 0
#define    REFS1           7       // Reference Selection Bit 1

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
#define    ADTS3           3       // ADC Auto Trigger Source 3
#define    ADASCR          4       // ADC on Amplified Channel Start Conversion Request Bit
#define    ADHSM           7       // ADC High Speed Mode

/* DIDR0 - Digital Input Disable Register 0 */
#define    ADC0D           0       // ADC0 Digital input Disable
#define    ADC1D           1       // ADC1 Digital input Disable
#define    ADC2D           2       // ADC2 Digital input Disable
#define    ADC3D           3       // ADC3 Digital input Disable
#define    ADC4D           4       // ADC4 Digital input Disable
#define    ADC5D           5       // ADC5 Digital input Disable
#define    ADC6D           6       // ADC6 Digital input Disable
#define    ADC7D           7       // ADC7 Digital input Disable

/* DIDR1 - Digital Input Disable Register 0 */
#define    ADC8D           0       // 
#define    ADC9D           1       // 
#define    ADC10D          2       // 
#define    AMP0ND          3       // 
#define    AMP0PD          4       // 
#define    ACMP0D          5       // 

/* AMP0CSR -  */
#define    AMP0TS0         0       // 
#define    AMP0TS1         1       // 
#define    AMP0G0          4       // 
#define    AMP0G1          5       // 
#define    AMP0IS          6       // 
#define    AMP0EN          7       // 

/* AMP1CSR -  */
#define    AMP1TS0         0       // 
#define    AMP1TS1         1       // 
#define    AMP1G0          4       // 
#define    AMP1G1          5       // 
#define    AMP1IS          6       // 
#define    AMP1EN          7       // 


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

/* UCSRA - USART Control and Status register A */
#define    MPCM            0       // Multi-processor Communication Mode
#define    U2X             1       // Double USART Transmission Bit
#define    UPE             2       // USART Parity Error
#define    DOR             3       // Data Overrun
#define    FE              4       // Framing Error
#define    UDRE            5       // USART Data Register Empty
#define    TXC             6       // USART Transmitt Complete
#define    RXC             7       // USART Receive Complete

/* UCSRB - USART Control an Status register B */
#define    TXB8            0       // Transmit Data Bit 8
#define    RXB8            1       // Receive Data Bit 8
#define    UCSZ2           2       // Character Size
#define    TXEN            3       // Transmitter Enable
#define    RXEN            4       // Receiver Enable
#define    UDRIE           5       // USART Data Register Empty Interrupt Enable
#define    TXCIE           6       // TX Complete Interrupt Enable
#define    RXCIE           7       // RX Complete Interrupt Enable

/* UCSRC - USART Control an Status register C */
#define    UCPOL           0       // Clock Polarity
#define    UCSZ0           1       // Character Size Bit 0
#define    UCSZ1           2       // Character Size Bit 1
#define    USBS            3       // Stop Bit Select
#define    UPM0            4       // Parity Mode Bit 0
#define    UPM1            5       // Parity Mode Bit 1
#define    UMSEL0          6       // USART Mode Select

/* UBRRH - USART Baud Rate Register High Byte */
#define    UBRR8           0       // USART Baud Rate Register Bit 8
#define    UBRR9           1       // USART Baud Rate Register Bit 9
#define    UBRR10          2       // USART Baud Rate Register Bit 10
#define    UBRR11          3       // USART Baud Rate Register Bit 11

/* UBRRL - USART Baud Rate Register Low Byte */
#define    UBRR0           0       // USART Baud Rate Register bit 0
#define    UBRR1           1       // USART Baud Rate Register bit 1
#define    UBRR2           2       // USART Baud Rate Register bit 2
#define    UBRR3           3       // USART Baud Rate Register bit 3
#define    UBRR4           4       // USART Baud Rate Register bit 4
#define    UBRR5           5       // USART Baud Rate Register bit 5
#define    UBRR6           6       // USART Baud Rate Register bit 6
#define    UBRR7           7       // USART Baud Rate Register bit 7


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


/* ***** EXTERNAL_INTERRUPT *********** */
/* EICRA - External Interrupt Control Register A */
#define    ISC00           0       // External Interrupt Sense Control Bit
#define    ISC01           1       // External Interrupt Sense Control Bit
#define    ISC10           2       // External Interrupt Sense Control Bit
#define    ISC11           3       // External Interrupt Sense Control Bit
#define    ISC20           4       // External Interrupt Sense Control Bit
#define    ISC21           5       // External Interrupt Sense Control Bit
#define    ISC30           6       // External Interrupt Sense Control Bit
#define    ISC31           7       // External Interrupt Sense Control Bit

/* EIMSK - External Interrupt Mask Register */
#define    INT0            0       // External Interrupt Request 0 Enable
#define    INT1            1       // External Interrupt Request 1 Enable
#define    INT2            2       // External Interrupt Request 2 Enable
#define    INT3            3       // External Interrupt Request 3 Enable

/* EIFR - External Interrupt Flag Register */
#define    INTF0           0       // External Interrupt Flag 0
#define    INTF1           1       // External Interrupt Flag 1
#define    INTF2           2       // External Interrupt Flag 2
#define    INTF3           3       // External Interrupt Flag 3


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
#define    EERIE           3       // EEPROM Ready Interrupt Enable


/* ***** PSC0 ************************* */
/* PICR0H - PSC 0 Input Capture Register High */
#define    PICR0_8         0       // 
#define    PICR0_9         1       // 
#define    PICR0_10        2       // 
#define    PICR0_11        3       // 
#define    PCST0           7       // PSC 0 Capture Software Trigger Bit

/* PICR0L - PSC 0 Input Capture Register Low */
#define    PICR0_0         0       // 
#define    PICR0_1         1       // 
#define    PICR0_2         2       // 
#define    PICR0_3         3       // 
#define    PICR0_4         4       // 
#define    PICR0_5         5       // 
#define    PICR0_6         6       // 
#define    PICR0_7         7       // 

/* PFRC0B - PSC 0 Input B Control */
#define    PRFM0B0         0       // PSC 0 Retrigger and Fault Mode for Part B
#define    PRFM0B1         1       // PSC 0 Retrigger and Fault Mode for Part B
#define    PRFM0B2         2       // PSC 0 Retrigger and Fault Mode for Part B
#define    PRFM0B3         3       // PSC 0 Retrigger and Fault Mode for Part B
#define    PFLTE0B         4       // PSC 0 Filter Enable on Input Part B
#define    PELEV0B         5       // PSC 0 Edge Level Selector on Input Part B
#define    PISEL0B         6       // PSC 0 Input Select for Part B
#define    PCAE0B          7       // PSC 0 Capture Enable Input Part B

/* PFRC0A - PSC 0 Input A Control */
#define    PRFM0A0         0       // PSC 0 Retrigger and Fault Mode for Part A
#define    PRFM0A1         1       // PSC 0 Retrigger and Fault Mode for Part A
#define    PRFM0A2         2       // PSC 0 Retrigger and Fault Mode for Part A
#define    PRFM0A3         3       // PSC 0 Retrigger and Fault Mode for Part A
#define    PFLTE0A         4       // PSC 0 Filter Enable on Input Part A
#define    PELEV0A         5       // PSC 0 Edge Level Selector on Input Part A
#define    PISEL0A         6       // PSC 0 Input Select for Part A
#define    PCAE0A          7       // PSC 0 Capture Enable Input Part A

/* PCTL0 - PSC 0 Control Register */
#define    PRUN0           0       // PSC 0 Run
#define    PCCYC0          1       // PSC0 Complete Cycle
#define    PARUN0          2       // PSC0 Auto Run
#define    PAOC0A          3       // PSC 0 Asynchronous Output Control A
#define    PAOC0B          4       // PSC 0 Asynchronous Output Control B
#define    PBFM0           5       // PSC 0 Balance Flank Width Modulation
#define    PPRE00          6       // PSC 0 Prescaler Select 0
#define    PPRE01          7       // PSC 0 Prescaler Select 1

/* PCNF0 - PSC 0 Configuration Register */
#define    PCLKSEL0        1       // PSC 0 Input Clock Select
#define    POP0            2       // PSC 0 Output Polarity
#define    PMODE00         3       // PSC 0 Mode
#define    PMODE01         4       // PSC 0 Mode
#define    PLOCK0          5       // PSC 0 Lock
#define    PALOCK0         6       // PSC 0 Autolock
#define    PFIFTY0         7       // PSC 0 Fifty

/* OCR0RBH - Output Compare RB Register High */
#define    OCR0RB_8        0       // 
#define    OCR0RB_9        1       // 
#define    OCR0RB_00       2       // 
#define    OCR0RB_01       3       // 
#define    OCR0RB_02       4       // 
#define    OCR0RB_03       5       // 
#define    OCR0RB_04       6       // 
#define    OCR0RB_05       7       // 

/* OCR0RBL - Output Compare RB Register Low */
#define    OCR0RB_0        0       // 
#define    OCR0RB_1        1       // 
#define    OCR0RB_2        2       // 
#define    OCR0RB_3        3       // 
#define    OCR0RB_4        4       // 
#define    OCR0RB_5        5       // 
#define    OCR0RB_6        6       // 
#define    OCR0RB_7        7       // 

/* OCR0SBH - Output Compare SB Register High */
#define    OCR0SB_8        0       // 
#define    OCR0SB_9        1       // 
#define    OCR0SB_00       2       // 
#define    OCR0SB_01       3       // 

/* OCR0SBL - Output Compare SB Register Low */
#define    OCR0SB_0        0       // 
#define    OCR0SB_1        1       // 
#define    OCR0SB_2        2       // 
#define    OCR0SB_3        3       // 
#define    OCR0SB_4        4       // 
#define    OCR0SB_5        5       // 
#define    OCR0SB_6        6       // 
#define    OCR0SB_7        7       // 

/* OCR0RAH - Output Compare RA Register High */
#define    OCR0RA_8        0       // 
#define    OCR0RA_9        1       // 
#define    OCR0RA_00       2       // 
#define    OCR0RA_01       3       // 

/* OCR0RAL - Output Compare RA Register Low */
#define    OCR0RA_0        0       // 
#define    OCR0RA_1        1       // 
#define    OCR0RA_2        2       // 
#define    OCR0RA_3        3       // 
#define    OCR0RA_4        4       // 
#define    OCR0RA_5        5       // 
#define    OCR0RA_6        6       // 
#define    OCR0RA_7        7       // 

/* OCR0SAH - Output Compare SA Register High */
#define    OCR0SA_8        0       // 
#define    OCR0SA_9        1       // 
#define    OCR0SA_00       2       // 
#define    OCR0SA_01       3       // 

/* OCR0SAL - Output Compare SA Register Low */
#define    OCR0SA_0        0       // 
#define    OCR0SA_1        1       // 
#define    OCR0SA_2        2       // 
#define    OCR0SA_3        3       // 
#define    OCR0SA_4        4       // 
#define    OCR0SA_5        5       // 
#define    OCR0SA_6        6       // 
#define    OCR0SA_7        7       // 

/* PSOC0 - PSC0 Synchro and Output Configuration */
#define    POEN0A          0       // PSCOUT00 Output Enable
#define    POEN0B          2       // PSCOUT01 Output Enable
#define    PSYNC00         4       // Synchronization Out for ADC Selection
#define    PSYNC01         5       // Synchronization Out for ADC Selection

/* PIM0 - PSC0 Interrupt Mask Register */
#define    PEOPE0          0       // End of Cycle Interrupt Enable
#define    PEVE0A          3       // External Event A Interrupt Enable
#define    PEVE0B          4       // External Event B Interrupt Enable
#define    PSEIE0          5       // PSC 0 Synchro Error Interrupt Enable

/* PIFR0 - PSC0 Interrupt Flag Register */
#define    PEOP0           0       // End of PSC0 Interrupt
#define    PRN00           1       // Ramp Number
#define    PRN01           2       // Ramp Number
#define    PEV0A           3       // External Event A Interrupt
#define    PEV0B           4       // External Event B Interrupt
#define    PSEI0           5       // PSC 0 Synchro Error Interrupt
#define    POAC0A          6       // PSC 0 Output A Activity
#define    POAC0B          7       // PSC 0 Output A Activity


/* ***** PSC1 ************************* */
/* PICR1H - PSC 1 Input Capture Register High */
#define    PICR1_8         0       // 
#define    PICR1_9         1       // 
#define    PICR1_10        2       // 
#define    PICR1_11        3       // 
#define    PCST1           7       // PSC 1 Capture Software Trigger Bit

/* PICR1L - PSC 1 Input Capture Register Low */
#define    PICR1_0         0       // 
#define    PICR1_1         1       // 
#define    PICR1_2         2       // 
#define    PICR1_3         3       // 
#define    PICR1_4         4       // 
#define    PICR1_5         5       // 
#define    PICR1_6         6       // 
#define    PICR1_7         7       // 

/* PFRC1B - PSC 1 Input B Control */
#define    PRFM1B0         0       // PSC 1 Retrigger and Fault Mode for Part B
#define    PRFM1B1         1       // PSC 1 Retrigger and Fault Mode for Part B
#define    PRFM1B2         2       // PSC 1 Retrigger and Fault Mode for Part B
#define    PRFM1B3         3       // PSC 1 Retrigger and Fault Mode for Part B
#define    PFLTE1B         4       // PSC 1 Filter Enable on Input Part B
#define    PELEV1B         5       // PSC 1 Edge Level Selector on Input Part B
#define    PISEL1B         6       // PSC 1 Input Select for Part B
#define    PCAE1B          7       // PSC 1 Capture Enable Input Part B

/* PFRC1A - PSC 1 Input B Control */
#define    PRFM1A0         0       // PSC 1 Retrigger and Fault Mode for Part A
#define    PRFM1A1         1       // PSC 1 Retrigger and Fault Mode for Part A
#define    PRFM1A2         2       // PSC 1 Retrigger and Fault Mode for Part A
#define    PRFM1A3         3       // PSC 1 Retrigger and Fault Mode for Part A
#define    PFLTE1A         4       // PSC 1 Filter Enable on Input Part A
#define    PELEV1A         5       // PSC 1 Edge Level Selector on Input Part A
#define    PISEL1A         6       // PSC 1 Input Select for Part A
#define    PCAE1A          7       // PSC 1 Capture Enable Input Part A

/* PCTL1 - PSC 1 Control Register */
#define    PRUN1           0       // PSC 1 Run
#define    PCCYC1          1       // PSC1 Complete Cycle
#define    PARUN1          2       // PSC1 Auto Run
#define    PAOC1A          3       // PSC 1 Asynchronous Output Control A
#define    PAOC1B          4       // PSC 1 Asynchronous Output Control B
#define    PBFM1           5       // Balance Flank Width Modulation
#define    PPRE10          6       // PSC 1 Prescaler Select 0
#define    PPRE11          7       // PSC 1 Prescaler Select 1

/* PCNF1 - PSC 1 Configuration Register */
#define    PCLKSEL1        1       // PSC 1 Input Clock Select
#define    POP1            2       // PSC 1 Output Polarity
#define    PMODE10         3       // PSC 1 Mode
#define    PMODE11         4       // PSC 1 Mode
#define    PLOCK1          5       // PSC 1 Lock
#define    PALOCK1         6       // PSC 1 Autolock
#define    PFIFTY1         7       // PSC 1 Fifty

/* OCR1RBH - Output Compare RB Register High */
#define    OCR1RB_8        0       // 
#define    OCR1RB_9        1       // 
#define    OCR1RB_10       2       // 
#define    OCR1RB_11       3       // 
#define    OCR1RB_12       4       // 
#define    OCR1RB_13       5       // 
#define    OCR1RB_14       6       // 
#define    OCR1RB_15       7       // 

/* OCR1RBL - Output Compare RB Register Low */
#define    OCR1RB_0        0       // 
#define    OCR1RB_1        1       // 
#define    OCR1RB_2        2       // 
#define    OCR1RB_3        3       // 
#define    OCR1RB_4        4       // 
#define    OCR1RB_5        5       // 
#define    OCR1RB_6        6       // 
#define    OCR1RB_7        7       // 

/* OCR1SBH - Output Compare SB Register High */
#define    OCR1SB_8        0       // 
#define    OCR1SB_9        1       // 
#define    OCR1SB_10       2       // 
#define    OCR1SB_11       3       // 

/* OCR1SBL - Output Compare SB Register Low */
#define    OCR1SB_0        0       // 
#define    OCR1SB_1        1       // 
#define    OCR1SB_2        2       // 
#define    OCR1SB_3        3       // 
#define    OCR1SB_4        4       // 
#define    OCR1SB_5        5       // 
#define    OCR1SB_6        6       // 
#define    OCR1SB_7        7       // 

/* OCR1RAH - Output Compare RA Register High */
#define    OCR1RA_8        0       // 
#define    OCR1RA_9        1       // 
#define    OCR1RA_10       2       // 
#define    OCR1RA_11       3       // 

/* OCR1RAL - Output Compare RA Register Low */
#define    OCR1RA_0        0       // 
#define    OCR1RA_1        1       // 
#define    OCR1RA_2        2       // 
#define    OCR1RA_3        3       // 
#define    OCR1RA_4        4       // 
#define    OCR1RA_5        5       // 
#define    OCR1RA_6        6       // 
#define    OCR1RA_7        7       // 

/* OCR1SAH - Output Compare SA Register High */
#define    OCR1SA_8        0       // 
#define    OCR1SA_9        1       // 
#define    OCR1SA_10       2       // 
#define    OCR1SA_11       3       // 

/* OCR1SAL - Output Compare SA Register Low */
#define    OCR1SA_0        0       // 
#define    OCR1SA_1        1       // 
#define    OCR1SA_2        2       // 
#define    OCR1SA_3        3       // 
#define    OCR1SA_4        4       // 
#define    OCR1SA_5        5       // 
#define    OCR1SA_6        6       // 
#define    OCR1SA_7        7       // 

/* PSOC1 - PSC1 Synchro and Output Configuration */
#define    POEN1A          0       // PSCOUT10 Output Enable
#define    POEN1B          2       // PSCOUT11 Output Enable
#define    PSYNC1_0        4       // Synchronization Out for ADC Selection
#define    PSYNC1_1        5       // Synchronization Out for ADC Selection

/* PIM1 - PSC1 Interrupt Mask Register */
#define    PEOPE1          0       // End of Cycle Interrupt Enable
#define    PEVE1A          3       // External Event A Interrupt Enable
#define    PEVE1B          4       // External Event B Interrupt Enable
#define    PSEIE1          5       // PSC 1 Synchro Error Interrupt Enable

/* PIFR1 - PSC1 Interrupt Flag Register */
#define    PEOP1           0       // End of PSC1 Interrupt
#define    PRN10           1       // Ramp Number
#define    PRN11           2       // Ramp Number
#define    PEV1A           3       // External Event A Interrupt
#define    PEV1B           4       // External Event B Interrupt
#define    PSEI1           5       // PSC 1 Synchro Error Interrupt
#define    POAC1A          6       // PSC 1 Output A Activity
#define    POAC1B          7       // PSC 1 Output B Activity


/* ***** PSC2 ************************* */
/* PICR2H - PSC 2 Input Capture Register High */
#define    PICR2_8         0       // 
#define    PICR2_9         1       // 
#define    PICR2_10        2       // 
#define    PICR2_11        3       // 
#define    PCST2           7       // PSC 2 Capture Software Trigger Bit

/* PICR2L - PSC 2 Input Capture Register Low */
#define    PICR2_0         0       // 
#define    PICR2_1         1       // 
#define    PICR2_2         2       // 
#define    PICR2_3         3       // 
#define    PICR2_4         4       // 
#define    PICR2_5         5       // 
#define    PICR2_6         6       // 
#define    PICR2_7         7       // 

/* PFRC2B - PSC 2 Input B Control */
#define    PRFM2B0         0       // PSC 2 Retrigger and Fault Mode for Part B
#define    PRFM2B1         1       // PSC 2 Retrigger and Fault Mode for Part B
#define    PRFM2B2         2       // PSC 2 Retrigger and Fault Mode for Part B
#define    PRFM2B3         3       // PSC 2 Retrigger and Fault Mode for Part B
#define    PFLTE2B         4       // PSC 2 Filter Enable on Input Part B
#define    PELEV2B         5       // PSC 2 Edge Level Selector on Input Part B
#define    PISEL2B         6       // PSC 2 Input Select for Part B
#define    PCAE2B          7       // PSC 2 Capture Enable Input Part B

/* PFRC2A - PSC 2 Input B Control */
#define    PRFM2A0         0       // PSC 2 Retrigger and Fault Mode for Part A
#define    PRFM2A1         1       // PSC 2 Retrigger and Fault Mode for Part A
#define    PRFM2A2         2       // PSC 2 Retrigger and Fault Mode for Part A
#define    PRFM2A3         3       // PSC 2 Retrigger and Fault Mode for Part A
#define    PFLTE2A         4       // PSC 2 Filter Enable on Input Part A
#define    PELEV2A         5       // PSC 2 Edge Level Selector on Input Part A
#define    PISEL2A         6       // PSC 2 Input Select for Part A
#define    PCAE2A          7       // PSC 2 Capture Enable Input Part A

/* PCTL2 - PSC 2 Control Register */
#define    PRUN2           0       // PSC 2 Run
#define    PCCYC2          1       // PSC2 Complete Cycle
#define    PARUN2          2       // PSC2 Auto Run
#define    PAOC2A          3       // PSC 2 Asynchronous Output Control A
#define    PAOC2B          4       // PSC 2 Asynchronous Output Control B
#define    PBFM2           5       // Balance Flank Width Modulation
#define    PPRE20          6       // PSC 2 Prescaler Select 0
#define    PPRE21          7       // PSC 2 Prescaler Select 1

/* PCNF2 - PSC 2 Configuration Register */
#define    POME2           0       // PSC 2 Output Matrix Enable
#define    PCLKSEL2        1       // PSC 2 Input Clock Select
#define    POP2            2       // PSC 2 Output Polarity
#define    PMODE20         3       // PSC 2 Mode
#define    PMODE21         4       // PSC 2 Mode
#define    PLOCK2          5       // PSC 2 Lock
#define    PALOCK2         6       // PSC 2 Autolock
#define    PFIFTY2         7       // PSC 2 Fifty

/* OCR2RBH - Output Compare RB Register High */
#define    OCR2RB_8        0       // 
#define    OCR2RB_9        1       // 
#define    OCR2RB_10       2       // 
#define    OCR2RB_11       3       // 
#define    OCR2RB_12       4       // 
#define    OCR2RB_13       5       // 
#define    OCR2RB_14       6       // 
#define    OCR2RB_15       7       // 

/* OCR2RBL - Output Compare RB Register Low */
#define    OCR2RB_0        0       // 
#define    OCR2RB_1        1       // 
#define    OCR2RB_2        2       // 
#define    OCR2RB_3        3       // 
#define    OCR2RB_4        4       // 
#define    OCR2RB_5        5       // 
#define    OCR2RB_6        6       // 
#define    OCR2RB_7        7       // 

/* OCR2SBH - Output Compare SB Register High */
#define    OCR2SB_8        0       // 
#define    OCR2SB_9        1       // 
#define    OCR2SB_10       2       // 
#define    OCR2SB_11       3       // 

/* OCR2SBL - Output Compare SB Register Low */
#define    OCR2SB_0        0       // 
#define    OCR2SB_1        1       // 
#define    OCR2SB_2        2       // 
#define    OCR2SB_3        3       // 
#define    OCR2SB_4        4       // 
#define    OCR2SB_5        5       // 
#define    OCR2SB_6        6       // 
#define    OCR2SB_7        7       // 

/* OCR2RAH - Output Compare RA Register High */
#define    OCR2RA_8        0       // 
#define    OCR2RA_9        1       // 
#define    OCR2RA_10       2       // 
#define    OCR2RA_11       3       // 

/* OCR2RAL - Output Compare RA Register Low */
#define    OCR2RA_0        0       // 
#define    OCR2RA_1        1       // 
#define    OCR2RA_2        2       // 
#define    OCR2RA_3        3       // 
#define    OCR2RA_4        4       // 
#define    OCR2RA_5        5       // 
#define    OCR2RA_6        6       // 
#define    OCR2RA_7        7       // 

/* OCR2SAH - Output Compare SA Register High */
#define    OCR2SA_8        0       // 
#define    OCR2SA_9        1       // 
#define    OCR2SA_10       2       // 
#define    OCR2SA_11       3       // 

/* OCR2SAL - Output Compare SA Register Low */
#define    OCR2SA_0        0       // 
#define    OCR2SA_1        1       // 
#define    OCR2SA_2        2       // 
#define    OCR2SA_3        3       // 
#define    OCR2SA_4        4       // 
#define    OCR2SA_5        5       // 
#define    OCR2SA_6        6       // 
#define    OCR2SA_7        7       // 

/* POM2 - PSC 2 Output Matrix */
#define    POMV2A0         0       // Output Matrix Output A Ramp 0
#define    POMV2A1         1       // Output Matrix Output A Ramp 1
#define    POMV2A2         2       // Output Matrix Output A Ramp 2
#define    POMV2A3         3       // Output Matrix Output A Ramp 3
#define    POMV2B0         4       // Output Matrix Output B Ramp 0
#define    POMV2B1         5       // Output Matrix Output B Ramp 2
#define    POMV2B2         6       // Output Matrix Output B Ramp 2
#define    POMV2B3         7       // Output Matrix Output B Ramp 3

/* PSOC2 - PSC2 Synchro and Output Configuration */
#define    POEN2A          0       // PSCOUT20 Output Enable
#define    POEN2C          1       // PSCOUT22 Output Enable
#define    POEN2B          2       // PSCOUT21 Output Enable
#define    POEN2D          3       // PSCOUT23 Output Enable
#define    PSYNC2_0        4       // Synchronization Out for ADC Selection
#define    PSYNC2_1        5       // Synchronization Out for ADC Selection
#define    POS22           6       // PSC 2 Output 22 Select
#define    POS23           7       // PSC 2 Output 23 Select

/* PIM2 - PSC2 Interrupt Mask Register */
#define    PEOPE2          0       // End of Cycle Interrupt Enable
#define    PEVE2A          3       // External Event A Interrupt Enable
#define    PEVE2B          4       // External Event B Interrupt Enable
#define    PSEIE2          5       // PSC 2 Synchro Error Interrupt Enable

/* PIFR2 - PSC2 Interrupt Flag Register */
#define    PEOP2           0       // End of PSC2 Interrupt
#define    PRN20           1       // Ramp Number
#define    PRN21           2       // Ramp Number
#define    PEV2A           3       // External Event A Interrupt
#define    PEV2B           4       // External Event B Interrupt
#define    PSEI2           5       // PSC 2 Synchro Error Interrupt
#define    POAC2A          6       // PSC 2 Output A Activity
#define    POAC2B          7       // PSC 2 Output A Activity

#endif

