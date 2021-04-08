/*
CodeVisionAVR V2.05.9+ C Compiler
(C) 1998-2012 Pavel Haiduc, HP InfoTech s.r.l.

ATtiny40 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __TINY40_BITS_INCLUDED__
#define __TINY40_BITS_INCLUDED__

/* ***** WATCHDOG ********************* */
/* WDTCSR - Watchdog Timer Control and Status Register */
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDP3            5       // Watchdog Timer Prescaler Bit 3
#define    WDIE            6       // Watchdog Timer Interrupt Enable
#define    WDIF            7       // Watchdog Timer Interrupt Flag


/* ***** AD_CONVERTER ***************** */
/* ADMUX - The ADC multiplexer Selection Register */
#define    MUX0            0       // Analog Channel and Gain Selection Bits
#define    MUX1            1       // Analog Channel and Gain Selection Bits
#define    MUX2            2       // Analog Channel and Gain Selection Bits
#define    MUX3            3       // Analog Channel and Gain Selection Bits
#define    REFS            6       // Reference Selection Bit

/* ADCSRA - The ADC Control and Status register */
#define    ADPS0           0       // ADC Prescaler Select Bits
#define    ADPS1           1       // ADC Prescaler Select Bits
#define    ADPS2           2       // ADC Prescaler Select Bits
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
#define    ADLAR           3       // 

/* DIDR0 - Digital Input Disable Register 0 */
#define    ADC0D           0       // ADC0 Digital input Disable
#define    ADC1D           1       // ADC1 Digital input Disable
#define    ADC2D           2       // ADC2 Digital input Disable
#define    ADC3D           3       // AREF Digital Input Disable
#define    ADC4D           4       // ADC3 Digital input Disable
#define    ADC5D           5       // ADC4 Digital input Disable
#define    ADC6D           6       // ADC5 Digital input Disable
#define    ADC7D           7       // ADC6 Digital input Disable


/* ***** ANALOG_COMPARATOR ************ */
/* ACSRA - Analog Comparator Control And Status Register A */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIC            2       // Analog Comparator Input Capture Enable
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Compare Output
#define    ACBG            6       // Analog Comparator Bandgap Select
#define    ACD             7       // Analog Comparator Disable

/* ACSRB - Analog Comparator Control And Status Register B */
#define    ACME            2       // Analog Comparator Multiplexer Enable
#define    HLEV            6       // Hysteresis Level
#define    HSEL            7       // Hysteresis Select


/* ***** TWI ************************** */
/* TWSCRA - TWI Slave Control Register A */
#define    TWSME           0       // TWI Smart Mode Enable
#define    TWPME           1       // TWI Promiscuous Mode Enable
#define    TWSIE           2       // TWI Stop Interrupt Enable
#define    TWEN            3       // Two-Wire Interface Enable
#define    TWASIE          4       // TWI Address/Stop Interrupt Enable
#define    TWDIE           5       // TWI Data Interrupt Enable
#define    TWSHE           7       // TWI SDA Hold Time Enable

/* TWSCRB - TWI Slave Control Register B */
#define    TWCMD0          0       // 
#define    TWCMD1          1       // 
#define    TWAA            2       // TWI Acknowledge Action

/* TWSSRA - TWI Slave Status Register A */
#define    TWAS            0       // TWI Address or Stop
#define    TWDIR           1       // TWI Read/Write Direction
#define    TWBE            2       // TWI Bus Error
#define    TWC             3       // TWI Collision
#define    TWRA            4       // TWI Receive Acknowledge
#define    TWCH            5       // TWI Clock Hold
#define    TWASIF          6       // TWI Address/Stop Interrupt Flag
#define    TWDIF           7       // TWI Data Interrupt Flag.

/* TWSA - TWI Slave Address Register */
#define    TWSA0           0       // TWI slave address bit
#define    TWSA1           1       // TWI slave address bit
#define    TWSA2           2       // TWI slave address bit
#define    TWSA3           3       // TWI slave address bit
#define    TWSA4           4       // TWI slave address bit
#define    TWSA5           5       // TWI slave address bit
#define    TWSA6           6       // TWI slave address bit
#define    TWSA7           7       // TWI slave address bit

/* TWSD - TWI Slave Data Register */
#define    TWSD0           0       // TWI slave data bit
#define    TWSD1           1       // TWI slave data bit
#define    TWSD2           2       // TWI slave data bit
#define    TWSD3           3       // TWI slave data bit
#define    TWSD4           4       // TWI slave data bit
#define    TWSD5           5       // TWI slave data bit
#define    TWSD6           6       // TWI slave data bit
#define    TWSD7           7       // TWI slave data bit

/* TWSAM - TWI Slave Address Mask Register */
#define    TWAE            0       // TWI Address Enable
#define    TWSAM1          1       // TWI Address Mask Bit 1
#define    TWSAM2          2       // TWI Address Mask Bit 2
#define    TWSAM3          3       // TWI Address Mask Bit 3
#define    TWSAM4          4       // TWI Address Mask Bit 4
#define    TWSAM5          5       // TWI Address Mask Bit 5
#define    TWSAM6          6       // TWI Address Mask Bit 6
#define    TWSAM7          7       // TWI Address Mask Bit 7


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

/* PRR - Power Reduction Register */
#define    PRADC           0       // Power Reduction ADC
#define    PRTIM0          1       // Power Reduction Timer/Counter0
#define    PRTIM1          2       // Power Reduction Timer/Counter1
#define    PRSPI           3       // Power Reduction Serial Peripheral Interface
#define    PRTWI           4       // Power Reduction TWI

/* RSTFLR - Reset Flag Register */
#define    PORF            0       // Power-on Reset Flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-Out Reset Flag
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

/* MCUCR - MCU Control Register */
#define    SE              0       // 
#define    SM0             1       // 
#define    SM1             2       // 
#define    SM2             3       // 
#define    BODS            4       // 
#define    ISC00           6       // 
#define    ISC01           7       // 

/* GIMSK - General Interrupt Mask Register */
#define    INT0            0       // 
#define    PCIE0           4       // 
#define    PCIE1           5       // 
#define    PCIE2           6       // 

/* GIFR - General Interrupt Flag Register */
#define    INTF0           0       // 
#define    PCIF0           4       // 
#define    PCIF1           5       // 
#define    PCIF2           6       // 

/* RAMAR - RAM Address Register */
#define    RAMAR0          0       // 
#define    RAMAR1          1       // 
#define    RAMAR2          2       // 
#define    RAMAR3          3       // 
#define    RAMAR4          4       // 
#define    RAMAR5          5       // 
#define    RAMAR6          6       // 
#define    RAMAR7          7       // 

/* RAMDR - RAM Data Register */
#define    RAMDR0          0       // 
#define    RAMDR1          1       // 
#define    RAMDR2          2       // 
#define    RAMDR3          3       // 
#define    RAMDR4          4       // 
#define    RAMDR5          5       // 
#define    RAMDR6          6       // 
#define    RAMDR7          7       // 


/* ***** EXTERNAL_INTERRUPT *********** */
/* PCMSK2 - Pin Change Mask Register 2 */
#define    PCINT12         0       // Pin Change Enable Mask 0
#define    PCINT13         1       // Pin Change Enable Mask 1
#define    PCINT14         2       // Pin Change Enable Mask 2
#define    PCINT15         3       // Pin Change Enable Mask 3
#define    PCINT16         4       // Pin Change Enable Mask 3
#define    PCINT17         5       // Pin Change Enable Mask 3

/* PCMSK1 - Pin Change Mask Register 1 */
#define    PCINT8          0       // Pin Change Enable Mask 0
#define    PCINT9          1       // Pin Change Enable Mask 1
#define    PCINT10         2       // Pin Change Enable Mask 2
#define    PCINT11         3       // Pin Change Enable Mask 3

/* PCMSK0 - Pin Change Mask Register 0 */
#define    PCINT0          0       // Pin Change Enable Mask 0
#define    PCINT1          1       // Pin Change Enable Mask 1
#define    PCINT2          2       // Pin Change Enable Mask 2
#define    PCINT3          3       // Pin Change Enable Mask 3
#define    PCINT4          4       // Pin Change Enable Mask 3
#define    PCINT5          5       // Pin Change Enable Mask 3
#define    PCINT6          6       // Pin Change Enable Mask 3
#define    PCINT7          7       // Pin Change Enable Mask 3


/* ***** PORTB ************************ */
/* PORTCR - Port Control Register */
#define    BBMA            0       // Break-Before-Make Mode Enable
#define    BBMB            1       // Break-Before-Make Mode Enable
#define    BBMC            2       // Break-Before-Make Mode Enable
#define    ADC8D           4       // 
#define    ADC9D           5       // 
#define    ADC10D          6       // 
#define    ADC11D          7       // 

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


/* ***** PORTC ************************ */
/* PUEC - Pull-up Enable Control Register */
#define    PUEC0           0       // 
#define    PUEC1           1       // 
#define    PUEC2           2       // 
#define    PUEC3           3       // 
#define    PUEC4           4       // 
#define    PUEC5           5       // 

/* PORTC - Port C Data Register */
#define    PORTC0          0       // 
#define    PORTC1          1       // 
#define    PORTC2          2       // 
#define    PORTC3          3       // 
#define    PORTC4          4       // 
#define    PORTC5          5       // 

/* DDRC - Data Direction Register, Port C */
#define    DDC0            0       // 
#define    DDC1            1       // 
#define    DDC2            2       // 
#define    DDC3            3       // 
#define    DDC4            4       // 
#define    DDC5            5       // 

/* PINC - Port C Input Pins */
#define    PINC0           0       // 
#define    PINC1           1       // 
#define    PINC2           2       // 
#define    PINC3           3       // 
#define    PINC4           4       // 
#define    PINC5           5       // 


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
#define    PSR             4       // Prescaler Reset Timer/Counter
#define    TSM             5       // Timer/Counter Synchronization Mode
#define    FOC0B           6       // Force Output Compare B
#define    FOC0A           7       // Force Output Compare A

/* TCCR1A - Timer/Counter1 Control Register A */
#define    CS10            0       // The Clock Select1 bits 2, 1, and 0 define the prescaling source of Timer1.
#define    PWM10           CS10    // For compatibility
#define    CS11            1       // The Clock Select1 bits 2, 1, and 0 define the prescaling source of Timer1.
#define    PWM11           CS11    // For compatibility
#define    CS12            2       // The Clock Select1 bits 2, 1, and 0 define the prescaling source of Timer1.
#define    CTC1            3       // Waveform Generation Mode
#define    ICES1           4       // Input Capture Edge Select
#define    ICNC1           5       // : Input Capture Noise Canceler
#define    ICEN1           6       // Input Capture Mode Enable
#define    TCW1            7       // Timer/Counter1 Width

/* TCNT1H - Timer/Counter1 High */
#define    TCNT1_8         0       // 
#define    TCNT1_9         1       // 
#define    TCNT1_10        2       // 
#define    TCNT1_11        3       // 
#define    TCNT1_12        4       // 
#define    TCNT1_13        5       // 
#define    TCNT1_14        6       // 
#define    TCNT1_15        7       // 

/* TCNT1L - Timer/Counter1 Low */
#define    TCNT1_0         0       // 
#define    TCNT1_1         1       // 
#define    TCNT1_2         2       // 
#define    TCNT1_3         3       // 
#define    TCNT1_4         4       // 
#define    TCNT1_5         5       // 
#define    TCNT1_6         6       // 
#define    TCNT1_7         7       // 

/* OCR1A - Timer/Counter 1 Output Compare Register A */
#define    OCR1A0          0       // 
#define    OCR1A1          1       // 
#define    OCR1A2          2       // 
#define    OCR1A3          3       // 
#define    OCR1A4          4       // 
#define    OCR1A5          5       // 
#define    OCR1A6          6       // 
#define    OCR1A7          7       // 

/* OCR1B - Timer/Counter 1 Output Compare Register B */
#define    OCR1B0          0       // 
#define    OCR1B1          1       // 
#define    OCR1B2          2       // 
#define    OCR1B3          3       // 
#define    OCR1B4          4       // 
#define    OCR1B5          5       // 
#define    OCR1B6          6       // 
#define    OCR1B7          7       // 

/* TIMSK - Timer Interrupt Mask Register */
#define    TOIE0           0       // Timer/Counter0 Overflow Interrupt Enable
#define    OCIE0A          1       // Timer/Counter0 Output Compare Match A Interrupt Enable
#define    OCIE0B          2       // Timer/Counter Output Compare Match B Interrupt Enable
#define    TOIE1           3       // Overflow Interrupt Enable
#define    OCIE1A          4       // Output Compare A Match Interrupt Enable
#define    OCIE1B          5       // Output Compare B Match Interrupt Enable
#define    ICIE1           7       // Input Capture Interrupt Enable

/* TIFR - Overflow Interrupt Enable */
#define    TOV0            0       // Timer/Counter0 Overflow Flag
#define    OCF0A           1       // Output Compare Flag 0 A
#define    OCF0B           2       // Output Compare Flag 0 B
#define    TOV1            3       // Timer Overflow Flag
#define    OCF1A           4       // Timer Output Compare Flag 1A
#define    OCF1B           5       // Timer Output Compare Flag 1B
#define    ICF1            7       // Input Capture Flag

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
#define    OCR0_0          0       // 
#define    OCR0_1          1       // 
#define    OCR0_2          2       // 
#define    OCR0_3          3       // 
#define    OCR0_4          4       // 
#define    OCR0_5          5       // 
#define    OCR0_6          6       // 
#define    OCR0_7          7       // 

/* OCR0B - Timer/Counter0 Output Compare Register */
#define    OCR0B_0         0       // 
#define    OCR0B_1         1       // 
#define    OCR0B_2         2       // 
#define    OCR0B_3         3       // 
#define    OCR0B_4         4       // 
#define    OCR0B_5         5       // 
#define    OCR0B_6         6       // 
#define    OCR0B_7         7       // 

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

/* ***** PORTA ************************ */
/* PUEA - Pull-up Enable Control Register */
#define    PUEA0           0       // 
#define    PUEA1           1       // 
#define    PUEA2           2       // 
#define    PUEA3           3       // 
#define    PUEA4           4       // 
#define    PUEA5           5       // 
#define    PUEA6           6       // 
#define    PUEA7           7       // 

/* PORTA - Port A Data Register */
#define    PORTA0          0       // 
#define    PORTA1          1       // 
#define    PORTA2          2       // 
#define    PORTA3          3       // 
#define    PORTA4          4       // 
#define    PORTA5          5       // 
#define    PORTA6          6       // 
#define    PORTA7          7       // 

/* DDRA - Data Direction Register, Port A */
#define    DDA0            0       // 
#define    DDA1            1       // 
#define    DDA2            2       // 
#define    DDA3            3       // 
#define    DDA4            4       // 
#define    DDA5            5       // 
#define    DDA6            6       // 
#define    DDA7            7       // 

/* PINA - Port A Input Pins */
#define    PINA0           0       // 
#define    PINA1           1       // 
#define    PINA2           2       // 
#define    PINA3           3       // 
#define    PINA4           4       // 
#define    PINA5           5       // 
#define    PINA6           6       // 
#define    PINA7           7       // 

#endif
