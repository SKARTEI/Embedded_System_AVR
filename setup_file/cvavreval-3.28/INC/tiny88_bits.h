/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATtiny48, ATtiny88 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __TINY88_BITS_INCLUDED__
#define __TINY88_BITS_INCLUDED__

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
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** ANALOG_COMPARATOR ************ */
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
#define    EERIE           3       // EEPROM Ready Interrupt Enable
#define    EEPM0           4       // EEPROM Programming Mode Bit 0
#define    EEPM1           5       // EEPROM Programming Mode Bit 1


/* ***** TWI ************************** */
/* TWHSR - TWHSR */
#define    TWIHS           0       // 

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


/* ***** AD_CONVERTER ***************** */
/* ADMUX - The ADC multiplexer Selection Register */
#define    MUX0            0       // Analog Channel and Gain Selection Bits
#define    MUX1            1       // Analog Channel and Gain Selection Bits
#define    MUX2            2       // Analog Channel and Gain Selection Bits
#define    MUX3            3       // Analog Channel and Gain Selection Bits
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
#define    ACME            6       // 

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

/* DIDR1 - Digital Input Disable Register 1 */
//#define  AIN0D           0       // 
//#define  AIN1D           1       // 
#define    AREFD           2       // 

/* DIDR0 - Digital Input Disable Register 0 */
#define    ADC0D           0       // 
#define    ADC1D           1       // 
#define    ADC2D           2       // 
#define    ADC3D           3       // 
#define    ADC4D           4       // 
#define    ADC5D           5       // 
#define    ADC6D           6       // 
#define    ADC7D           7       // 


/* ***** EXTERNAL_INTERRUPT *********** */
/* EICRA - External Interrupt Control Register */
#define    ISC00           0       // External Interrupt Sense Control 0 Bit 0
#define    ISC01           1       // External Interrupt Sense Control 0 Bit 1
#define    ISC10           2       // External Interrupt Sense Control 1 Bit 0
#define    ISC11           3       // External Interrupt Sense Control 1 Bit 1

/* EIMSK - External Interrupt Mask Register */
#define    INT0            0       // External Interrupt Request 0 Enable
#define    INT1            1       // External Interrupt Request 1 Enable

/* EIFR - External Interrupt Flag Register */
#define    INTF0           0       // External Interrupt Flag 0
#define    INTF1           1       // External Interrupt Flag 1

/* PCICR -  */
#define    PCIE0           0       // 
#define    PCIE1           1       // 
#define    PCIE2           2       // 
#define    PCIE3           3       // 

/* PCMSK3 - Pin Change Mask Register 3 */
#define    PCINT24         0       // Pin Change Enable Mask 24
#define    PCINT25         1       // Pin Change Enable Mask 25
#define    PCINT26         2       // Pin Change Enable Mask 26
#define    PCINT27         3       // Pin Change Enable Mask 27

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

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 0
#define    PCIF1           1       // Pin Change Interrupt Flag 1
#define    PCIF2           2       // Pin Change Interrupt Flag 2
#define    PCIF3           3       // Pin Change Interrupt Flag 3


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


/* ***** PORTA ************************ */
/* PORTA - Port A Data Register */
#define    PORTA0          0       // Port A Data Register bit 0
#define    PORTA1          1       // Port A Data Register bit 1
#define    PORTA2          2       // Port A Data Register bit 2
#define    PORTA3          3       // Port A Data Register bit 3

/* DDRA - Port A Data Direction Register */
#define    DDA0            0       // Data Direction Register, Port A, bit 0
#define    DDA1            1       // Data Direction Register, Port A, bit 1
#define    DDA2            2       // Data Direction Register, Port A, bit 2
#define    DDA3            3       // Data Direction Register, Port A, bit 3

/* PINA - Port A Input Pins */
#define    PINA0           0       // Input Pins, Port A bit 0
#define    PINA1           1       // Input Pins, Port A bit 1
#define    PINA2           2       // Input Pins, Port A bit 2
#define    PINA3           3       // Input Pins, Port A bit 3


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
#define    CS00            0       // Clock Select
#define    CS01            1       // Clock Select
#define    CS02            2       // Clock Select
#define    CTC0            3       // Clear Timer on Compare Match

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
//#define  PSRSYNC         0       // Prescaler Reset Timer/Counter1 and Timer/Counter0
#define    PSR10           PSRSYNC // For compatibility
//#define  TSM             7       // Timer/Counter Synchronization Mode


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

/* SPH - Stack Pointe High */
#define    SP8             0       // Stack pointer bit 8
#define    SP9             1       // Stack pointer bit 9

/* SPL - Stack Pointe Low */
#define    SP0             0       // Stack pointer bit 0
#define    SP1             1       // Stack pointer bit 1
#define    SP2             2       // Stack pointer bit 2
#define    SP3             3       // Stack pointer bit 3
#define    SP4             4       // Stack pointer bit 4
#define    SP5             5       // Stack pointer bit 5
#define    SP6             6       // Stack pointer bit 6
#define    SP7             7       // Stack pointer bit 7

/* OSCCAL - Oscillator Calibration Value */
#define    CAL0            0       // Oscillator Calibration Value Bit0
#define    CAL1            1       // Oscillator Calibration Value Bit1
#define    CAL2            2       // Oscillator Calibration Value Bit2
#define    CAL3            3       // Oscillator Calibration Value Bit3
#define    CAL4            4       // Oscillator Calibration Value Bit4
#define    CAL5            5       // Oscillator Calibration Value Bit5
#define    CAL6            6       // Oscillator Calibration Value Bit6
#define    CAL7            7       // Oscillator Calibration Value Bit7

/* CLKPR - Clock Prescale Register */
#define    CLKPS0          0       // Clock Prescaler Select Bit 0
#define    CLKPS1          1       // Clock Prescaler Select Bit 1
#define    CLKPS2          2       // Clock Prescaler Select Bit 2
#define    CLKPS3          3       // Clock Prescaler Select Bit 3
#define    CLKPCE          7       // Clock Prescaler Change Enable

/* SPMCSR - Store Program Memory Control Register */
#define    SELFPRGEN       0       // Self Programming Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    RFLB            3       // Read Fuse and Lock Bits
#define    CTPB            4       // Clear Temporary Page Buffer
#define    RWWSB           6       // Read-While-Write Section Busy

/* MCUCR - MCU Control Register */
#define    PUD             4       // 
#define    BODSE           5       // BOD Sleep Enable
#define    BODS            6       // BOD Sleep

/* MCUSR - MCU Status Register */
#define    PORF            0       // Power-on reset flag
#define    EXTRF           1       // External Reset Flag
#define    EXTREF          EXTRF   // For compatibility
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag

/* SMCR -  */
#define    SE              0       // 
#define    SM0             1       // 
#define    SM1             2       // 

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
#define    PRSPI           2       // Power Reduction Serial Peripheral Interface
#define    PRTIM1          3       // Power Reduction Timer/Counter1
#define    PRTIM0          5       // Power Reduction Timer/Counter0
#define    PRTWI           7       // Power Reduction TWI

/* PORTCR - Port Configuration Register */
#define    PUDA            0       // 
#define    PUDB            1       // 
#define    PUDC            2       // 
#define    PUDD            3       // 
#define    BBMA            4       // 
#define    BBMB            5       // 
#define    BBMC            6       // 
#define    BBMD            7       // 

#endif

