/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2012 Pavel Haiduc, HP InfoTech s.r.l.

ATmega329A, ATmega649A I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __MEGA649A_BITS_INCLUDED__
#define __MEGA649A_BITS_INCLUDED__

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

/* DIDR0 - Digital Input Disable Register 0 */
#define    ADC0D           0       // ADC0 Digital input Disable
#define    ADC1D           1       // ADC1 Digital input Disable
#define    ADC2D           2       // ADC2 Digital input Disable
#define    ADC3D           3       // ADC3 Digital input Disable
#define    ADC4D           4       // ADC4 Digital input Disable
#define    ADC5D           5       // ADC5 Digital input Disable
#define    ADC6D           6       // ADC6 Digital input Disable
#define    ADC7D           7       // ADC7 Digital input Disable


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


/* ***** USART0 *********************** */
/* UDR0 - USART I/O Data Register */
#define    UDR             UDR0    // For compatibility
#define    UDR00           0       // USART I/O Data Register bit 0
#define    UDR01           1       // USART I/O Data Register bit 1
#define    UDR02           2       // USART I/O Data Register bit 2
#define    UDR03           3       // USART I/O Data Register bit 3
#define    UDR04           4       // USART I/O Data Register bit 4
#define    UDR05           5       // USART I/O Data Register bit 5
#define    UDR06           6       // USART I/O Data Register bit 6
#define    UDR07           7       // USART I/O Data Register bit 7

/* UCSR0A - USART Control and Status Register A */
#define    UCSRA           UCSR0A  // For compatibility
#define    USR             UCSR0A  // For compatibility
#define    MPCM0           0       // Multi-processor Communication Mode
#define    MPCM            MPCM0   // For compatibility
#define    U2X0            1       // Double the USART Transmission Speed
#define    U2X             U2X0    // For compatibility
#define    UPE0            2       // USART Parity Error
#define    UPE             UPE0    // For compatibility
#define    DOR0            3       // Data OverRun
#define    DOR             DOR0    // For compatibility
#define    FE0             4       // Framing Error
#define    FE              FE0     // For compatibility
#define    UDRE0           5       // USART Data Register Empty
#define    UDRE            UDRE0   // For compatibility
#define    TXC0            6       // USART Transmit Complete
#define    TXC             TXC0    // For compatibility
#define    RXC0            7       // USART Receive Complete
#define    RXC             RXC0    // For compatibility

/* UCSR0B - USART Control and Status Register B */
#define    UCSRB           UCSR0B  // For compatibility
#define    UCR             UCSR0B  // For compatibility
#define    TXB80           0       // Transmit Data Bit 8
#define    TXB8            TXB80   // For compatibility
#define    RXB80           1       // Receive Data Bit 8
#define    RXB8            RXB80   // For compatibility
#define    UCSZ02          2       // Character Size
#define    UCSZ2           UCSZ02  // For compatibility
#define    TXEN0           3       // Transmitter Enable
#define    TXEN            TXEN0   // For compatibility
#define    RXEN0           4       // Receiver Enable
#define    RXEN            RXEN0   // For compatibility
#define    UDRIE0          5       // USART Data Register Empty Interrupt Enable
#define    UDRIE           UDRIE0  // For compatibility
#define    TXCIE0          6       // TX Complete Interrupt Enable
#define    TXCIE           TXCIE0  // For compatibility
#define    RXCIE0          7       // RX Complete Interrupt Enable
#define    RXCIE           RXCIE0  // For compatibility

/* UCSR0C - USART Control and Status Register C */
#define    UCSRC           UCSR0C  // For compatibility
#define    UCPOL0          0       // Clock Polarity
#define    UCPOL           UCPOL0  // For compatibility
#define    UCSZ00          1       // Character Size
#define    UCSZ0           UCSZ00  // For compatibility
#define    UCSZ01          2       // Character Size
#define    UCSZ1           UCSZ01  // For compatibility
#define    USBS0           3       // Stop Bit Select
#define    USBS            USBS0   // For compatibility
#define    UPM00           4       // Parity Mode Bit 0
#define    UPM0            UPM00   // For compatibility
#define    UPM01           5       // Parity Mode Bit 1
#define    UPM1            UPM01   // For compatibility
#define    UMSEL0          6       // USART Mode Select
#define    UMSEL           UMSEL0  // For compatibility

/* UBRR0H - USART Baud Rate Register High Byte */
#define    UBRRH           UBRR0H  // For compatibility
#define    UBRR8           0       // USART Baud Rate Register bit 8
#define    UBRR9           1       // USART Baud Rate Register bit 9
#define    UBRR10          2       // USART Baud Rate Register bit 10
#define    UBRR11          3       // USART Baud Rate Register bit 11

/* UBRR0L - USART Baud Rate Register Low Byte */
#define    UBRRL           UBRR0L  // For compatibility
#define    UBRR            UBRR0L  // For compatibility
#define    UBRR0           0       // USART Baud Rate Register bit 0
#define    UBRR1           1       // USART Baud Rate Register bit 1
#define    UBRR2           2       // USART Baud Rate Register bit 2
#define    UBRR3           3       // USART Baud Rate Register bit 3
#define    UBRR4           4       // USART Baud Rate Register bit 4
#define    UBRR5           5       // USART Baud Rate Register bit 5
#define    UBRR6           6       // USART Baud Rate Register bit 6
#define    UBRR7           7       // USART Baud Rate Register bit 7


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

/* MCUSR - MCU Status Register */
#define    PORF            0       // Power-on reset flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag
#define    JTRF            4       // JTAG Reset Flag

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

/* PRR - Power Reduction Register */
#define    PRADC           0       // Power Reduction ADC
#define    PRUSART0        1       // Power Reduction USART
#define    PRSPI           2       // Power Reduction Serial Peripheral Interface
#define    PRTIM1          3       // Power Reduction Timer/Counter1
#define    PRLCD           4       // Power Reduction LCD

/* SMCR - Sleep Mode Control Register */
#define    SE              0       // Sleep Enable
#define    SM0             1       // Sleep Mode Select bit 0
#define    SM1             2       // Sleep Mode Select bit 1
#define    SM2             3       // Sleep Mode Select bit 2

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
//#define  JTRF            4       // JTAG Reset Flag


/* ***** LCD ************************** */
/* LCDCRA - LCD Control Register A */
#define    LCDBL           0       // LCD Blanking
#define    LCDCCD          1       // LCD Contrast Control Disable
#define    LCDBD           2       // LCD Buffer Disable
#define    LCDIE           3       // LCD Interrupt Enable
#define    LCDIF           4       // LCD Interrupt Flag
#define    LCDAB           6       // LCD A or B waveform
#define    LCDEN           7       // LCD Enable

/* LCDCRB - LCD Control and Status Register B */
#define    LCDPM0          0       // LCD Port Mask 0
#define    LCDPM1          1       // LCD Port Mask 1
#define    LCDPM2          2       // LCD Port Mask 2
#define    LCDPM3          3       // LCD Port Mask 3
#define    LCDMUX0         4       // LCD Mux Select 0
#define    LCDMUX1         5       // LCD Mux Select 1
#define    LCD2B           6       // LCD 1/2 Bias Select
#define    LCDCS           7       // LCD CLock Select

/* LCDFRR - LCD Frame Rate Register */
#define    LCDCD0          0       // LCD Clock Divider 0
#define    LCDCD1          1       // LCD Clock Divider 1
#define    LCDCD2          2       // LCD Clock Divider 2
#define    LCDPS0          4       // LCD Prescaler Select 0
#define    LCDPS1          5       // LCD Prescaler Select 1
#define    LCDPS2          6       // LCD Prescaler Select 2

/* LCDCCR - LCD Contrast Control Register */
#define    LCDCC0          0       // LCD Contrast Control 0
#define    LCDCC1          1       // LCD Contrast Control 1
#define    LCDCC2          2       // LCD Contrast Control 2
#define    LCDCC3          3       // LCD Contrast Control 3
#define    LCDMDT          4       // LCD Maximum Drive Time
#define    LCDDC0          5       // LCD Display Configuration 0
#define    LCDDC1          6       // LCD Display Configuration 1
#define    LCDDC2          7       // LCD Display Configuration 2

/* LCDDR18 - LCD Data Register 18 */
#define    SEG324          0       // 

/* LCDDR17 - LCD Data Register 17 */
#define    SEG316          0       // 
#define    SEG317          1       // 
#define    SEG318          2       // 
#define    SEG319          3       // 
#define    SEG320          4       // 
#define    SEG321          5       // 
#define    SEG322          6       // 
#define    SEG323          7       // 

/* LCDDR16 - LCD Data Register 16 */
#define    SEG308          0       // 
#define    SEG309          1       // 
#define    SEG310          2       // 
#define    SEG311          3       // 
#define    SEG312          4       // 
#define    SEG313          5       // 
#define    SEG314          6       // 
#define    SEG315          7       // 

/* LCDDR15 - LCD Data Register 15 */
#define    SEG300          0       // 
#define    SEG301          1       // 
#define    SEG302          2       // 
#define    SEG303          3       // 
#define    SEG304          4       // 
#define    SEG305          5       // 
#define    SEG306          6       // 
#define    SEG307          7       // 

/* LCDDR13 - LCD Data Register 13 */
#define    SEG224          0       // 

/* LCDDR12 - LCD Data Register 12 */
#define    SEG216          0       // 
#define    SEG217          1       // 
#define    SEG218          2       // 
#define    SEG219          3       // 
#define    SEG220          4       // 
#define    SEG221          5       // 
#define    SEG222          6       // 
#define    SEG223          7       // 

/* LCDDR11 - LCD Data Register 11 */
#define    SEG208          0       // 
#define    SEG209          1       // 
#define    SEG210          2       // 
#define    SEG211          3       // 
#define    SEG212          4       // 
#define    SEG213          5       // 
#define    SEG214          6       // 
#define    SEG215          7       // 

/* LCDDR10 - LCD Data Register 10 */
#define    SEG200          0       // 
#define    SEG201          1       // 
#define    SEG202          2       // 
#define    SEG203          3       // 
#define    SEG204          4       // 
#define    SEG205          5       // 
#define    SEG206          6       // 
#define    SEG207          7       // 

/* LCDDR8 - LCD Data Register 8 */
#define    SEG124          0       // 

/* LCDDR7 - LCD Data Register 7 */
#define    SEG116          0       // 
#define    SEG117          1       // 
#define    SEG118          2       // 
#define    SEG119          3       // 
#define    SEG120          4       // 
#define    SEG121          5       // 
#define    SEG122          6       // 
#define    SEG123          7       // 

/* LCDDR6 - LCD Data Register 6 */
#define    SEG108          0       // 
#define    SEG109          1       // 
#define    SEG110          2       // 
#define    SEG111          3       // 
#define    SEG112          4       // 
#define    SEG113          5       // 
#define    SEG114          6       // 
#define    SEG115          7       // 

/* LCDDR5 - LCD Data Register 5 */
#define    SEG100          0       // 
#define    SEG101          1       // 
#define    SEG102          2       // 
#define    SEG103          3       // 
#define    SEG104          4       // 
#define    SEG105          5       // 
#define    SEG106          6       // 
#define    SEG107          7       // 

/* LCDDR3 - LCD Data Register 3 */
#define    SEG024          0       // 

/* LCDDR2 - LCD Data Register 2 */
#define    SEG016          0       // 
#define    SEG017          1       // 
#define    SEG018          2       // 
#define    SEG019          3       // 
#define    SEG020          4       // 
#define    SEG021          5       // 
#define    SEG022          6       // 
#define    SEG023          7       // 

/* LCDDR1 - LCD Data Register 1 */
#define    SEG008          0       // 
#define    SEG009          1       // 
#define    SEG010          2       // 
#define    SEG011          3       // 
#define    SEG012          4       // 
#define    SEG013          5       // 
#define    SEG014          6       // 
#define    SEG015          7       // 

/* LCDDR0 - LCD Data Register 0 */
#define    SEG000          0       // 
#define    SEG001          1       // 
#define    SEG002          2       // 
#define    SEG003          3       // 
#define    SEG004          4       // 
#define    SEG005          5       // 
#define    SEG006          6       // 
#define    SEG007          7       // 


/* ***** EXTERNAL_INTERRUPT *********** */
/* EICRA - External Interrupt Control Register A */
#define    ISC00           0       // External Interrupt Sense Control 0 Bit 0
#define    ISC01           1       // External Interrupt Sense Control 0 Bit 1

/* EIMSK - External Interrupt Mask Register */
#define    INT0            0       // External Interrupt Request 0 Enable
#define    PCIE0           4       // Pin Change Interrupt Enable 0
#define    PCIE1           5       // Pin Change Interrupt Enable 1
#define    PCIE2           6       // Pin Change Interrupt Enable 2
#define    PCIE3           7       // Pin Change Interrupt Enable 3

/* EIFR - External Interrupt Flag Register */
#define    INTF0           0       // External Interrupt Flag 0
#define    PCIF0           4       // Pin Change Interrupt Flag 0
#define    PCIF1           5       // Pin Change Interrupt Flag 1
#define    PCIF2           6       // Pin Change Interrupt Flag 2
#define    PCIF3           7       // Pin Change Interrupt Flag 3

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


/* ***** PORTE ************************ */
/* PORTE - Data Register, Port E */
#define    PORTE0          0       // 
#define    PORTE1          1       // 
#define    PORTE2          2       // 
#define    PORTE3          3       // 
#define    PORTE4          4       // 
#define    PORTE5          5       // 
#define    PORTE6          6       // 
#define    PORTE7          7       // 

/* DDRE - Data Direction Register, Port E */
#define    DDE0            0       // 
#define    DDE1            1       // 
#define    DDE2            2       // 
#define    DDE3            3       // 
#define    DDE4            4       // 
#define    DDE5            5       // 
#define    DDE6            6       // 
#define    DDE7            7       // 

/* PINE - Input Pins, Port E */
#define    PINE0           0       // 
#define    PINE1           1       // 
#define    PINE2           2       // 
#define    PINE3           3       // 
#define    PINE4           4       // 
#define    PINE5           5       // 
#define    PINE6           6       // 
#define    PINE7           7       // 


/* ***** PORTF ************************ */
/* PORTF - Data Register, Port F */
#define    PORTF0          0       // 
#define    PORTF1          1       // 
#define    PORTF2          2       // 
#define    PORTF3          3       // 
#define    PORTF4          4       // 
#define    PORTF5          5       // 
#define    PORTF6          6       // 
#define    PORTF7          7       // 

/* DDRF - Data Direction Register, Port F */
#define    DDF0            0       // 
#define    DDF1            1       // 
#define    DDF2            2       // 
#define    DDF3            3       // 
#define    DDF4            4       // 
#define    DDF5            5       // 
#define    DDF6            6       // 
#define    DDF7            7       // 

/* PINF - Input Pins, Port F */
#define    PINF0           0       // 
#define    PINF1           1       // 
#define    PINF2           2       // 
#define    PINF3           3       // 
#define    PINF4           4       // 
#define    PINF5           5       // 
#define    PINF6           6       // 
#define    PINF7           7       // 


/* ***** PORTG ************************ */
/* PORTG - Port G Data Register */
#define    PORTG0          0       // 
#define    PORTG1          1       // 
#define    PORTG2          2       // 
#define    PORTG3          3       // 
#define    PORTG4          4       // 

/* DDRG - Port G Data Direction Register */
#define    DDG0            0       // 
#define    DDG1            1       // 
#define    DDG2            2       // 
#define    DDG3            3       // 
#define    DDG4            4       // 

/* PING - Port G Input Pins */
#define    PING0           0       // 
#define    PING1           1       // 
#define    PING2           2       // 
#define    PING3           3       // 
#define    PING4           4       // 
#define    PING5           5       // 


/* ***** TIMER_COUNTER_0 ************** */
/* TCCR0A - Timer/Counter0 Control Register */
#define    CS00            0       // Clock Select 0
#define    CS01            1       // Clock Select 1
#define    CS02            2       // Clock Select 2
#define    WGM01           3       // Waveform Generation Mode 1
#define    COM0A0          4       // Compare match Output Mode 0
#define    COM0A1          5       // Compare Match Output Mode 1
#define    WGM00           6       // Waveform Generation Mode 0
#define    FOC0A           7       // Force Output Compare

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
#define    OCR0A0          0       // 
#define    OCR0A1          1       // 
#define    OCR0A2          2       // 
#define    OCR0A3          3       // 
#define    OCR0A4          4       // 
#define    OCR0A5          5       // 
#define    OCR0A6          6       // 
#define    OCR0A7          7       // 

/* TIMSK0 - Timer/Counter0 Interrupt Mask Register */
#define    TOIE0           0       // Timer/Counter0 Overflow Interrupt Enable
#define    OCIE0A          1       // Timer/Counter0 Output Compare Match Interrupt Enable

/* TIFR0 - Timer/Counter0 Interrupt Flag register */
#define    TOV0            0       // Timer/Counter0 Overflow Flag
#define    OCF0A           1       // Timer/Counter0 Output Compare Flag 0

/* GTCCR - General Timer/Control Register */
#define    PSR310          0       // Prescaler Reset Timer/Counter1 and Timer/Counter0
#define    PSR10           PSR310  // For compatibility
#define    PSR0            PSR310  // For compatibility
#define    PSR1            PSR310  // For compatibility
#define    PSR3            PSR310  // For compatibility
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK1 - Timer/Counter1 Interrupt Mask Register */
#define    TOIE1           0       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1A          1       // Timer/Counter1 Output Compare A Match Interrupt Enable
#define    OCIE1B          2       // Timer/Counter1 Output Compare B Match Interrupt Enable
#define    ICIE1           5       // Timer/Counter1 Input Capture Interrupt Enable

/* TIFR1 - Timer/Counter1 Interrupt Flag register */
#define    TOV1            0       // Timer/Counter1 Overflow Flag
#define    OCF1A           1       // Output Compare Flag 1A
#define    OCF1B           2       // Output Compare Flag 1B
#define    ICF1            5       // Input Capture Flag 1

/* TCCR1A - Timer/Counter1 Control Register A */
#define    WGM10           0       // Waveform Generation Mode
#define    WGM11           1       // Waveform Generation Mode
#define    COM1B0          4       // Compare Output Mode 1B, bit 0
#define    COM1B1          5       // Compare Output Mode 1B, bit 1
#define    COM1A0          6       // Compare Output Mode 1A, bit 0
#define    COM1A1          7       // Compare Output Mode 1A, bit 1

/* TCCR1B - Timer/Counter1 Control Register B */
#define    CS10            0       // Prescaler source of Timer/Counter 1
#define    CS11            1       // Prescaler source of Timer/Counter 1
#define    CS12            2       // Prescaler source of Timer/Counter 1
#define    WGM12           3       // Waveform Generation Mode
#define    WGM13           4       // Waveform Generation Mode
#define    ICES1           6       // Input Capture 1 Edge Select
#define    ICNC1           7       // Input Capture 1 Noise Canceler

/* TCCR1C - Timer/Counter 1 Control Register C */
#define    FOC1B           6       // Force Output Compare 1B
#define    FOC1A           7       // Force Output Compare 1A


/* ***** TIMER_COUNTER_2 ************** */
/* TIMSK2 - Timer/Counter2 Interrupt Mask register */
#define    TOIE2           0       // Timer/Counter2 Overflow Interrupt Enable
#define    OCIE2A          1       // Timer/Counter2 Output Compare Match Interrupt Enable

/* TIFR2 - Timer/Counter2 Interrupt Flag Register */
#define    TOV2            0       // Timer/Counter2 Overflow Flag
#define    OCF2A           1       // Timer/Counter2 Output Compare Flag 2

/* TCCR2A - Timer/Counter2 Control Register */
#define    CS20            0       // Clock Select bit 0
#define    CS21            1       // Clock Select bit 1
#define    CS22            2       // Clock Select bit 2
#define    WGM21           3       // Waveform Generation Mode
#define    COM2A0          4       // Compare Output Mode bit 0
#define    COM2A1          5       // Compare Output Mode bit 1
#define    WGM20           6       // Waveform Generation Mode
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

/* OCR2A - Timer/Counter2 Output Compare Register */
#define    OCR2A0          0       // Timer/Counter2 Output Compare Register Bit 0
#define    OCR2A1          1       // Timer/Counter2 Output Compare Register Bit 1
#define    OCR2A2          2       // Timer/Counter2 Output Compare Register Bit 2
#define    OCR2A3          3       // Timer/Counter2 Output Compare Register Bit 3
#define    OCR2A4          4       // Timer/Counter2 Output Compare Register Bit 4
#define    OCR2A5          5       // Timer/Counter2 Output Compare Register Bit 5
#define    OCR2A6          6       // Timer/Counter2 Output Compare Register Bit 6
#define    OCR2A7          7       // Timer/Counter2 Output Compare Register Bit 7

/* GTCCR - General Timer/Counter Control Register */
#define    PSR2            1       // Prescaler Reset Timer/Counter2

/* ASSR - Asynchronous Status Register */
#define    TCR2UB          0       // TCR2UB: Timer/Counter Control Register2 Update Busy
#define    OCR2UB          1       // Output Compare Register2 Update Busy
#define    TCN2UB          2       // TCN2UB: Timer/Counter2 Update Busy
#define    AS2             3       // AS2: Asynchronous Timer/Counter2
#define    EXCLK           4       // Enable External Clock Interrupt


/* ***** WATCHDOG ********************* */
/* WDTCR - Watchdog Timer Control Register */
#define    WDTCSR          WDTCR   // For compatibility
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDCE            4       // Watchdog Change Enable
#define    WDTOE           WDCE    // For compatibility


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

#endif

