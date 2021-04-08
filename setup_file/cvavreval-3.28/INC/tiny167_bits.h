/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATtiny167, ATtiny87 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __TINY167_BITS_INCLUDED__
#define __TINY167_BITS_INCLUDED__

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


/* ***** LINUART ********************** */
/* LINCR - LIN Control Register */
#define    LCMD0           0       // LIN Command and Mode bit 0
#define    LCMD1           1       // LIN Command and Mode bit 1
#define    LCMD2           2       // LIN Command and Mode bit 2
#define    LENA            3       // LIN or UART Enable
#define    LCONF0          4       // LIN Configuration bit 0
#define    LCONF1          5       // LIN Configuration bit 1
#define    LIN13           6       // LIN Standard
#define    LSWRES          7       // Software Reset

/* LINSIR - LIN Status and Interrupt Register */
#define    LRXOK           0       // Receive Performed Interrupt
#define    LTXOK           1       // Transmit Performed Interrupt
#define    LIDOK           2       // Identifier Interrupt
#define    LERR            3       // Error Interrupt
#define    LBUSY           4       // Busy Signal
#define    LIDST0          5       // Identifier Status bit 0
#define    LIDST1          6       // Identifier Status bit 1
#define    LIDST2          7       // Identifier Status bit 2

/* LINENIR - LIN Enable Interrupt Register */
#define    LENRXOK         0       // Enable Receive Performed Interrupt
#define    LENTXOK         1       // Enable Transmit Performed Interrupt
#define    LENIDOK         2       // Enable Identifier Interrupt
#define    LENERR          3       // Enable Error Interrupt

/* LINERR - LIN Error Register */
#define    LBERR           0       // Bit Error Flag
#define    LCERR           1       // Checksum Error Flag
#define    LPERR           2       // Parity Error Flag
#define    LSERR           3       // Synchronization Error Flag
#define    LFERR           4       // Framing Error Flag
#define    LOVERR          5       // Overrun Error Flag
#define    LTOERR          6       // Frame Time Out Error Flag
#define    LABORT          7       // Abort Flag

/* LINBTR - LIN Bit Timing Register */
#define    LBT0            0       // LIN Bit Timing bit 0
#define    LBT1            1       // LIN Bit Timing bit 1
#define    LBT2            2       // LIN Bit Timing bit 2
#define    LBT3            3       // LIN Bit Timing bit 3
#define    LBT4            4       // LIN Bit Timing bit 4
#define    LBT5            5       // LIN Bit Timing bit 5
#define    LDISR           7       // Disable Bit Timing Resynchronization

/* LINBRRL - LIN Baud Rate Low Register */
#define    LDIV0           0       //
#define    LDIV1           1       //
#define    LDIV2           2       //
#define    LDIV3           3       //
#define    LDIV4           4       //
#define    LDIV5           5       //
#define    LDIV6           6       //
#define    LDIV7           7       //

/* LINBRRH - LIN Baud Rate High Register */
#define    LDIV8           0       //
#define    LDIV9           1       //
#define    LDIV10          2       //
#define    LDIV11          3       //

/* LINDLR - LIN Data Length Register */
#define    LRXDL0          0       // LIN Receive Data Length bit 0
#define    LRXDL1          1       // LIN Receive Data Length bit 1
#define    LRXDL2          2       // LIN Receive Data Length bit 2
#define    LRXDL3          3       // LIN Receive Data Length bit 3
#define    LTXDL0          4       // LIN Transmit Data Length bit 0
#define    LTXDL1          5       // LIN Transmit Data Length bit 1
#define    LTXDL2          6       // LIN Transmit Data Length bit 2
#define    LTXDL3          7       // LIN Transmit Data Length bit 3

/* LINIDR - LIN Identifier Register */
#define    LID0            0       // Identifier bit 0
#define    LID1            1       // Identifier bit 1
#define    LID2            2       // Identifier bit 2
#define    LID3            3       // Identifier bit 3
#define    LID4            4       // Identifier bit 4 or Data Length bit 0
#define    LID5            5       // Identifier bit 5 or Data Length bit 1
#define    LP0             6       // Parity bit 0
#define    LP1             7       // Parity bit 1

/* LINSEL - LIN Data Buffer Selection Register */
#define    LINDX0          0       // FIFO LIN Data Buffer Index bit 0
#define    LINDX1          1       // FIFO LIN Data Buffer Index bit 1
#define    LINDX2          2       // FIFO LIN Data Buffer Index bit 2
#define    LAINC           3       // Auto Increment of Data Buffer Index (Active Low)

/* LINDAT - LIN Data Register */
#define    LDATA0          0       //
#define    LDATA1          1       //
#define    LDATA2          2       //
#define    LDATA3          3       //
#define    LDATA4          4       //
#define    LDATA5          5       //
#define    LDATA6          6       //
#define    LDATA7          7       //


/* ***** USI ************************** */
/* USIPP - USI Pin Position */
#define    USIPOS          0       // USI Pin Position

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


/* ***** TIMER_COUNTER_0 ************** */
/* TIMSK0 - Timer/Counter0 Interrupt Mask register */
#define    TOIE0           0       // Timer/Counter0 Overflow Interrupt Enable
#define    OCIE0A          1       // Timer/Counter0 Output Compare Match A Interrupt Enable

/* TIFR0 - Timer/Counter0 Interrupt Flag Register */
#define    TOV0            0       // Timer/Counter0 Overflow Flag
#define    OCF0A           1       // Output Compare Flag 0A

/* TCCR0A - Timer/Counter0 Control Register A */
#define    WGM00           0       // Waveform Genration Mode bit 0
#define    WGM01           1       // Waveform Genration Mode bit 1
#define    COM0A0          6       // Compare Output Mode bit 0
#define    COM0A1          7       // Compare Output Mode bit 1

/* TCCR0B - Timer/Counter0 Control Register B */
#define    CS00            0       // Clock Select bit 0
#define    CS01            1       // Clock Select bit 1
#define    CS02            2       // Clock Select bit 2
#define    FOC0A           7       // Force Output Compare A

/* TCNT0 - Timer/Counter0 */
#define    TCNT00          0       // Timer/Counter 0 bit 0
#define    TCNT01          1       // Timer/Counter 0 bit 1
#define    TCNT02          2       // Timer/Counter 0 bit 2
#define    TCNT03          3       // Timer/Counter 0 bit 3
#define    TCNT04          4       // Timer/Counter 0 bit 4
#define    TCNT05          5       // Timer/Counter 0 bit 5
#define    TCNT06          6       // Timer/Counter 0 bit 6
#define    TCNT07          7       // Timer/Counter 0 bit 7

/* OCR0A - Timer/Counter0 Output Compare Register A */
#define    OCR00           0       // Timer/Counter0 Output Compare Register Bit 0
#define    OCR01           1       // Timer/Counter0 Output Compare Register Bit 1
#define    OCR02           2       // Timer/Counter0 Output Compare Register Bit 2
#define    OCR03           3       // Timer/Counter0 Output Compare Register Bit 3
#define    OCR04           4       // Timer/Counter0 Output Compare Register Bit 4
#define    OCR05           5       // Timer/Counter0 Output Compare Register Bit 5
#define    OCR06           6       // Timer/Counter0 Output Compare Register Bit 6
#define    OCR07           7       // Timer/Counter0 Output Compare Register Bit 7

/* ASSR - Asynchronous Status Register */
#define    TCR0BUB         0       // Timer/Counter0 Control Register B Update Busy
#define    TCR0AUB         1       // Timer/Counter0 Control Register A Update Busy
#define    OCR0AUB         3       // Output Compare Register 0A  Update Busy
#define    TCN0UB          4       // Timer/Counter0 Update Busy
#define    AS0             5       // Asynchronous Timer/Counter0
#define    EXCLK           6       // Enable External Clock Input

/* GTCCR - General Timer Counter Control register */
#define    PSR1            0       // Prescaler Reset Synchronous 16-bit Timer/Counter1
#define    PSR0            1       // Prescaler Reset Asynchronous 8-bit Timer/Counter0
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK1 - Timer/Counter1 Interrupt Mask Register */
#define    TOIE1           0       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1A          1       // Timer/Counter1 Output Compare A Match Interrupt Enable
#define    OCIE1B          2       // Timer/Counter1 Output Compare B Match Interrupt Enable
#define    ICIE1           5       // Timer/Counter1 Input Capture Interrupt Enable

/* TIFR1 - Timer/Counter1 Interrupt Flag register */
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
#define    CS10            0       // Timer/Counter1 Clock Select bit 0
#define    CS11            1       // Timer/Counter1 Clock Select bit 1
#define    CS12            2       // Timer/Counter1 Clock Select bit 2
#define    WGM12           3       // Waveform Generation Mode Bit 2
#define    WGM13           4       // Waveform Generation Mode Bit 3
#define    ICES1           6       // Input Capture 1 Edge Select
#define    ICNC1           7       // Input Capture 1 Noise Canceler

/* TCCR1C - Timer/Counter1 Control Register C */
#define    FOC1B           6       // Timer/Counter1 Force Output Compare for Channel B
#define    FOC1A           7       // Timer/Counter1 Force Output Compare for Channel A

/* TCCR1D - Timer/Counter1 Control Register D */
#define    OC1AU           0       // Timer/Counter1 Output Compare U-pin Enable for Channel A
#define    OC1AV           1       // Timer/Counter1 Output Compare V-pin Enable for Channel A
#define    OC1AW           2       // Timer/Counter1 Output Compare W-pin Enable for Channel A
#define    OC1AX           3       // Timer/Counter1 Output Compare X-pin Enable for Channel A
#define    OC1BU           4       // Timer/Counter1 Output Compare U-pin Enable for Channel B
#define    OC1BV           5       // Timer/Counter1 Output Compare V-pin Enable for Channel B
#define    OC1BW           6       // Timer/Counter1 Output Compare W-pin Enable for Channel B
#define    OC1BX           7       // Timer/Counter1 Output Compare X-pin Enable for Channel B


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

/* ADCSRB - The ADC Control and Status register B (Shared with ANALOG_COMPARATOR IO_MODULE) */
#define    ADTS0           0       // ADC Auto Trigger Source bit 0
#define    ADTS1           1       // ADC Auto Trigger Source bit 1
#define    ADTS2           2       // ADC Auto Trigger Source bit 2
#define    BIN             7       // Bipolar Input Mode

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

/* AMISCR - Analog Miscellaneous Control Register (Shared with CURRENT_SOURCE IO_MODULE) */
#define    XREFEN          1       // Internal Voltage Reference Output Enable
#define    AREFEN          2       // External Voltage Reference Input Enable

/* DIDR1 - Digital Input Disable Register 1 */
#define    ADC8D           0       //
#define    ADC9D           1       //
#define    ADC10D          2       //

/* DIDR0 - Digital Input Disable Register 0 */
#define    ADC0D           0       //
#define    ADC1D           1       //
#define    ADC2D           2       //
#define    ADC3D           3       //
#define    ADC4D           4       //
#define    ADC5D           5       //
#define    ADC6D           6       //
#define    AIN0D           ADC6D   // For compatibility
#define    ADC7D           7       //
#define    AIN1D           ADC7D   // For compatibility


/* ***** CURRENT_SOURCE *************** */
/* AMISCR - Analog Miscellaneous Control Register (Shared with AD_CONVERTER IO_MODULE) */
#define    ISRCEN          0       // Current Source Enable


/* ***** ANALOG_COMPARATOR ************ */
/* ADCSRB - Analog Comparator & ADC Control and Status Register B (Shared with AD_CONVERTER IO_MODULE) */
#define    ACIR0           4       // Analog Comparator Internal Voltage Reference Select Bit 0
#define    ACIR1           5       // Analog Comparator Internal Voltage Reference Select Bit 1
#define    ACME            6       // Analog Comparator Multiplexer Enable

/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIC            2       // Analog Comparator Input Capture Enable
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Compare Output
#define    ACIRS           6       // Analog Comparator Internal Reference Select
#define    ACD             7       // Analog Comparator Disable


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

/* PCICR - Pin Change Interrupt Control Register */
#define    PCIE0           0       // Pin Change Interrupt Enable on any PCINT7..0 pin
#define    PCIE1           1       // Pin Change Interrupt Enable  on any PCINT14..8 pin

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 0
#define    PCIF1           1       // Pin Change Interrupt Flag 1

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


/* ***** BOOT_LOAD ******************** */
/* SPMCSR - Store Program Memory Control Register */
#define    SPMEN           0       // Store Program Memory Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    RFLB            3       // Read Fuse and Lock Bits
#define    CTPB            4       // Clear Temporary Page Buffer
#define    SIGRD           5       // Signature Row Read
#define    RWWSB           6       // Read While Write Section Busy


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
#define    PUD             4       // Pull-up Disable
#define    BODS            5       // BOD Sleep
#define    BODSE           6       // BOD Sleep Enable

/* MCUSR - MCU Status register */
#define    PORF            0       // Power-On Reset Flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag

/* SMCR - Sleep Mode Control Register */
#define    SE              0       // Sleep Enable
#define    SM0             1       // Sleep Mode Select Bit 0
#define    SM1             2       // Sleep Mode Select Bit 1

/* PRR - Power Reduction Register */
#define    PRADC           0       // Power Reduction ADC
#define    PRUSI           1       // Power Reduction USI
#define    PRTIM0          2       // Power Reduction Timer/Counter0
#define    PRTIM1          3       // Power Reduction Timer/Counter1
#define    PRSPI           4       // Power Reduction SPI
#define    PRLIN           5       // Power Reduction LINUART

/* OSCCAL - Oscillator Calibration Register */
#define    CAL0            0       // Oscillatro Calibration Value Bit 0
#define    CAL1            1       // Oscillatro Calibration Value Bit 1
#define    CAL2            2       // Oscillatro Calibration Value Bit 2
#define    CAL3            3       // Oscillatro Calibration Value Bit 3
#define    CAL4            4       // Oscillatro Calibration Value Bit 4
#define    CAL5            5       // Oscillatro Calibration Value Bit 5
#define    CAL6            6       // Oscillatro Calibration Value Bit 6
#define    CAL7            7       // Oscillatro Calibration Value Bit 7

/* CLKPR - Clock Prescale Register */
#define    CLKPS0          0       // Clock Prescaler Select Bit 0
#define    CLKPS1          1       // Clock Prescaler Select Bit 1
#define    CLKPS2          2       // Clock Prescaler Select Bit 2
#define    CLKPS3          3       // Clock Prescaler Select Bit 3
#define    CLKPCE          7       // Clock Prescaler Change Enable

/* CLKSELR - Clock Selection Register */
#define    CSEL0           0       // Clock Source Select bit 0 - CKSEL0 fuse substitution
#define    CSEL1           1       // Clock Source Select bit 1 - CKSEL1 fuse substitution
#define    CSEL2           2       // Clock Source Select bit 2 - CKSEL2 fuse substitution
#define    CSEL3           3       // Clock Source Select bit 3 - CKSEL3 fuse substitution
#define    CSUT0           4       // Clock Start-up Time bit 0 - SUT0 fuse substitution
#define    CSUT1           5       // Clock Start-up Time bit 1 - SUT1 fuse substitution
#define    COUT            6       // Clock Out - CKOUT fuse substitution

/* CLKCSR - Clock Control & Status Register */
#define    CLKC0           0       // Clock Control bit 0
#define    CLKC1           1       // Clock Control bit 1
#define    CLKC2           2       // Clock Control bit 2
#define    CLKC3           3       // Clock Control bit 3
#define    CLKRDY          4       // Clock Ready Flag
#define    CLKCCE          7       // Clock Control Change Enable

/* DWDR - DebugWire data register */
#define    DWDR0           0       //
#define    DWDR1           1       //
#define    DWDR2           2       //
#define    DWDR3           3       //
#define    DWDR4           4       //
#define    DWDR5           5       //
#define    DWDR6           6       //
#define    DWDR7           7       //

/* GPIOR2 - General Purpose IO register 2 */
#define    GPIOR20         0       //
#define    GPIOR21         1       //
#define    GPIOR22         2       //
#define    GPIOR23         3       //
#define    GPIOR24         4       //
#define    GPIOR25         5       //
#define    GPIOR26         6       //
#define    GPIOR27         7       //

/* GPIOR1 - General Purpose register 1 */
#define    GPIOR10         0       //
#define    GPIOR11         1       //
#define    GPIOR12         2       //
#define    GPIOR13         3       //
#define    GPIOR14         4       //
#define    GPIOR15         5       //
#define    GPIOR16         6       //
#define    GPIOR17         7       //

/* GPIOR0 - General purpose register 0 */
#define    GPIOR00         0       //
#define    GPIOR01         1       //
#define    GPIOR02         2       //
#define    GPIOR03         3       //
#define    GPIOR04         4       //
#define    GPIOR05         5       //
#define    GPIOR06         6       //
#define    GPIOR07         7       //

/* PORTCR - General purpose register 0 */
#define    PUDA            0       // Port-Wise Pull-up Disable Port A
#define    PUDB            2       // Port-Wise Pull-up Disable Port B
#define    BBMA            4       // Break-Before-Make Mode Enable Port A
#define    BBMB            5       // Break-Before-Make Mode Enable Port B

#endif
