/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATmega64, ATmega128 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __MEGA128_BITS_INCLUDED__
#define __MEGA128_BITS_INCLUDED__

/* ***** ANALOG_COMPARATOR ************ */
/* SFIOR - Special Function IO Register */
#define    ACME            3       // Analog Comparator Multiplexer Enable

/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIC            2       // Analog Comparator Input Capture Enable
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Compare Output
#define    ACBG            6       // Analog Comparator Bandgap Select
#define    ACD             7       // Analog Comparator Disable


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


/* ***** TWI ************************** */
/* TWBR - TWI Bit Rate register */
#define    I2BR            TWBR    // For compatibility
#define    TWBR0           0       // 
#define    TWBR1           1       // 
#define    TWBR2           2       // 
#define    TWBR3           3       // 
#define    TWBR4           4       // 
#define    TWBR5           5       // 
#define    TWBR6           6       // 
#define    TWBR7           7       // 

/* TWCR - TWI Control Register */
#define    I2CR            TWCR    // For compatibility
#define    TWIE            0       // TWI Interrupt Enable
#define    I2IE            TWIE    // For compatibility
#define    TWEN            2       // TWI Enable Bit
#define    I2EN            TWEN    // For compatibility
#define    ENI2C           TWEN    // For compatibility
#define    TWWC            3       // TWI Write Collition Flag
#define    I2WC            TWWC    // For compatibility
#define    TWSTO           4       // TWI Stop Condition Bit
#define    I2STO           TWSTO   // For compatibility
#define    TWSTA           5       // TWI Start Condition Bit
#define    I2STA           TWSTA   // For compatibility
#define    TWEA            6       // TWI Enable Acknowledge Bit
#define    I2EA            TWEA    // For compatibility
#define    TWINT           7       // TWI Interrupt Flag
#define    I2INT           TWINT   // For compatibility

/* TWSR - TWI Status Register */
#define    I2SR            TWSR    // For compatibility
#define    TWPS0           0       // TWI Prescaler
#define    TWS0            TWPS0   // For compatibility
#define    I2GCE           TWPS0   // For compatibility
#define    TWPS1           1       // TWI Prescaler
#define    TWS1            TWPS1   // For compatibility
#define    TWS3            3       // TWI Status
#define    I2S3            TWS3    // For compatibility
#define    TWS4            4       // TWI Status
#define    I2S4            TWS4    // For compatibility
#define    TWS5            5       // TWI Status
#define    I2S5            TWS5    // For compatibility
#define    TWS6            6       // TWI Status
#define    I2S6            TWS6    // For compatibility
#define    TWS7            7       // TWI Status
#define    I2S7            TWS7    // For compatibility

/* TWDR - TWI Data register */
#define    I2DR            TWDR    // For compatibility
#define    TWD0            0       // TWI Data Register Bit 0
#define    TWD1            1       // TWI Data Register Bit 1
#define    TWD2            2       // TWI Data Register Bit 2
#define    TWD3            3       // TWI Data Register Bit 3
#define    TWD4            4       // TWI Data Register Bit 4
#define    TWD5            5       // TWI Data Register Bit 5
#define    TWD6            6       // TWI Data Register Bit 6
#define    TWD7            7       // TWI Data Register Bit 7

/* TWAR - TWI (Slave) Address register */
#define    I2AR            TWAR    // For compatibility
#define    TWGCE           0       // TWI General Call Recognition Enable Bit
#define    TWA0            1       // TWI (Slave) Address register Bit 0
#define    TWA1            2       // TWI (Slave) Address register Bit 1
#define    TWA2            3       // TWI (Slave) Address register Bit 2
#define    TWA3            4       // TWI (Slave) Address register Bit 3
#define    TWA4            5       // TWI (Slave) Address register Bit 4
#define    TWA5            6       // TWI (Slave) Address register Bit 5
#define    TWA6            7       // TWI (Slave) Address register Bit 6


/* ***** USART0 *********************** */
/* UDR0 - USART I/O Data Register */
#define    UDR00           0       // USART I/O Data Register bit 0
#define    UDR01           1       // USART I/O Data Register bit 1
#define    UDR02           2       // USART I/O Data Register bit 2
#define    UDR03           3       // USART I/O Data Register bit 3
#define    UDR04           4       // USART I/O Data Register bit 4
#define    UDR05           5       // USART I/O Data Register bit 5
#define    UDR06           6       // USART I/O Data Register bit 6
#define    UDR07           7       // USART I/O Data Register bit 7

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
#define    UMSEL0          6       // USART Mode Select

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


/* ***** USART1 *********************** */
/* UDR1 - USART I/O Data Register */
#define    UDR10           0       // USART I/O Data Register bit 0
#define    UDR11           1       // USART I/O Data Register bit 1
#define    UDR12           2       // USART I/O Data Register bit 2
#define    UDR13           3       // USART I/O Data Register bit 3
#define    UDR14           4       // USART I/O Data Register bit 4
#define    UDR15           5       // USART I/O Data Register bit 5
#define    UDR16           6       // USART I/O Data Register bit 6
#define    UDR17           7       // USART I/O Data Register bit 7

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
#define    UCSZ11          2       // Character Size
#define    USBS1           3       // Stop Bit Select
#define    UPM10           4       // Parity Mode Bit 0
#define    UPM11           5       // Parity Mode Bit 1
#define    UMSEL1          6       // USART Mode Select

/* UBRR1H - USART Baud Rate Register Hight Byte */
//#define  UBRR8           0       // USART Baud Rate Register bit 8
//#define  UBRR9           1       // USART Baud Rate Register bit 9
//#define  UBRR10          2       // USART Baud Rate Register bit 10
//#define  UBRR11          3       // USART Baud Rate Register bit 11

/* UBRR1L - USART Baud Rate Register Low Byte */
//#define  UBRR0           0       // USART Baud Rate Register bit 0
//#define  UBRR1           1       // USART Baud Rate Register bit 1
//#define  UBRR2           2       // USART Baud Rate Register bit 2
//#define  UBRR3           3       // USART Baud Rate Register bit 3
//#define  UBRR4           4       // USART Baud Rate Register bit 4
//#define  UBRR5           5       // USART Baud Rate Register bit 5
//#define  UBRR6           6       // USART Baud Rate Register bit 6
//#define  UBRR7           7       // USART Baud Rate Register bit 7


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
#define    SM2             2       // Sleep Mode Select
#define    SM0             3       // Sleep Mode Select
#define    SM1             4       // Sleep Mode Select
#define    SE              5       // Sleep Enable
#define    SRW10           6       // External SRAM Wait State Select
#define    SRE             7       // External SRAM Enable

/* XMCRA - External Memory Control Register A */
#define    SRW11           1       // Wait state select bit upper page
#define    SRW00           2       // Wait state select bit lower page
#define    SRW01           3       // Wait state select bit lower page
#define    SRL0            4       // Wait state page limit
#define    SRL1            5       // Wait state page limit
#define    SRL2            6       // Wait state page limit

/* XMCRB - External Memory Control Register B */
#define    XMM0            0       // External Memory High Mask
#define    XMM1            1       // External Memory High Mask
#define    XMM2            2       // External Memory High Mask
#define    XMBK            7       // External Memory Bus Keeper Enable

/* OSCCAL - Oscillator Calibration Value */
#define    CAL0            0       // Oscillator Calibration Value
#define    CAL1            1       // Oscillator Calibration Value
#define    CAL2            2       // Oscillator Calibration Value
#define    CAL3            3       // Oscillator Calibration Value
#define    CAL4            4       // Oscillator Calibration Value
#define    CAL5            5       // Oscillator Calibration Value
#define    CAL6            6       // Oscillator Calibration Value
#define    CAL7            7       // Oscillator Calibration Value

/* XDIV - XTAL Divide Control Register */
#define    XDIV0           0       // XTAl Divide Select Bit 0
#define    XDIV1           1       // XTAl Divide Select Bit 1
#define    XDIV2           2       // XTAl Divide Select Bit 2
#define    XDIV3           3       // XTAl Divide Select Bit 3
#define    XDIV4           4       // XTAl Divide Select Bit 4
#define    XDIV5           5       // XTAl Divide Select Bit 5
#define    XDIV6           6       // XTAl Divide Select Bit 6
#define    XDIVEN          7       // XTAL Divide Enable

/* MCUCSR - MCU Control And Status Register */
#define    PORF            0       // Power-on reset flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag
#define    JTRF            4       // JTAG Reset Flag
#define    JTD             7       // JTAG Interface Disable

/* RAMPZ - RAM Page Z Select Register */
#define    RAMPZ0          0       // RAM Page Z Select Register Bit 0


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

/* MCUCSR - MCU Control And Status Register */
//#define  JTRF            4       // JTAG Reset Flag
//#define  JTD             7       // JTAG Interface Disable


/* ***** MISC ************************* */
/* SFIOR - Special Function IO Register */
#define    PSR321          0       // Prescaler Reset Timer/Counter3, Timer/Counter2, and Timer/Counter1
#define    PSR1            PSR321  // For compatibility
#define    PSR2            PSR321  // For compatibility
#define    PSR3            PSR321  // For compatibility
#define    PSR0            1       // Prescaler Reset Timer/Counter0
#define    PUD             2       // Pull Up Disable
//#define  ACME            3       // Analog Comparator Multiplexer Enable
#define    TSM             7       // Timer/Counter Synchronization Mode


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

/* EICRB - External Interrupt Control Register B */
#define    ISC40           0       // External Interrupt 7-4 Sense Control Bit
#define    ISC41           1       // External Interrupt 7-4 Sense Control Bit
#define    ISC50           2       // External Interrupt 7-4 Sense Control Bit
#define    ISC51           3       // External Interrupt 7-4 Sense Control Bit
#define    ISC60           4       // External Interrupt 7-4 Sense Control Bit
#define    ISC61           5       // External Interrupt 7-4 Sense Control Bit
#define    ISC70           6       // External Interrupt 7-4 Sense Control Bit
#define    ISC71           7       // External Interrupt 7-4 Sense Control Bit

/* EIMSK - External Interrupt Mask Register */
#define    GICR            EIMSK   // For compatibility
#define    GIMSK           EIMSK   // For compatibility
#define    INT0            0       // External Interrupt Request 0 Enable
#define    INT1            1       // External Interrupt Request 1 Enable
#define    INT2            2       // External Interrupt Request 2 Enable
#define    INT3            3       // External Interrupt Request 3 Enable
#define    INT4            4       // External Interrupt Request 4 Enable
#define    INT5            5       // External Interrupt Request 5 Enable
#define    INT6            6       // External Interrupt Request 6 Enable
#define    INT7            7       // External Interrupt Request 7 Enable

/* EIFR - External Interrupt Flag Register */
#define    GIFR            EIFR    // For compatibility
#define    INTF0           0       // External Interrupt Flag 0
#define    INTF1           1       // External Interrupt Flag 1
#define    INTF2           2       // External Interrupt Flag 2
#define    INTF3           3       // External Interrupt Flag 3
#define    INTF4           4       // External Interrupt Flag 4
#define    INTF5           5       // External Interrupt Flag 5
#define    INTF6           6       // External Interrupt Flag 6
#define    INTF7           7       // External Interrupt Flag 7


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
/* PORTG - Data Register, Port G */
#define    PORTG0          0       // 
#define    PORTG1          1       // 
#define    PORTG2          2       // 
#define    PORTG3          3       // 
#define    PORTG4          4       // 

/* DDRG - Data Direction Register, Port G */
#define    DDG0            0       // 
#define    DDG1            1       // 
#define    DDG2            2       // 
#define    DDG3            3       // 
#define    DDG4            4       // 

/* PING - Input Pins, Port G */
#define    PING0           0       // 
#define    PING1           1       // 
#define    PING2           2       // 
#define    PING3           3       // 
#define    PING4           4       // 


/* ***** TIMER_COUNTER_0 ************** */
/* TCCR0 - Timer/Counter Control Register */
#define    CS00            0       // Clock Select 0
#define    CS01            1       // Clock Select 1
#define    CS02            2       // Clock Select 2
#define    WGM01           3       // Waveform Generation Mode 1
#define    CTC0            WGM01   // For compatibility
#define    COM00           4       // Compare match Output Mode 0
#define    COM01           5       // Compare Match Output Mode 1
#define    WGM00           6       // Waveform Generation Mode 0
#define    PWM0            WGM00   // For compatibility
#define    FOC0            7       // Force Output Compare

/* TCNT0 - Timer/Counter Register */
#define    TCNT0_0         0       // 
#define    TCNT0_1         1       // 
#define    TCNT0_2         2       // 
#define    TCNT0_3         3       // 
#define    TCNT0_4         4       // 
#define    TCNT0_5         5       // 
#define    TCNT0_6         6       // 
#define    TCNT0_7         7       // 

/* OCR0 - Output Compare Register */
#define    OCR0_0          0       // 
#define    OCR0_1          1       // 
#define    OCR0_2          2       // 
#define    OCR0_3          3       // 
#define    OCR0_4          4       // 
#define    OCR0_5          5       // 
#define    OCR0_6          6       // 
#define    OCR0_7          7       // 

/* ASSR - Asynchronus Status Register */
#define    TCR0UB          0       // Timer/Counter Control Register 0 Update Busy
#define    OCR0UB          1       // Output Compare register 0 Busy
#define    TCN0UB          2       // Timer/Counter0 Update Busy
#define    AS0             3       // Asynchronus Timer/Counter 0

/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TOIE0           0       // Timer/Counter0 Overflow Interrupt Enable
#define    OCIE0           1       // Timer/Counter0 Output Compare Match Interrupt register

/* TIFR - Timer/Counter Interrupt Flag register */
#define    TOV0            0       // Timer/Counter0 Overflow Flag
#define    OCF0            1       // Output Compare Flag 0

/* SFIOR - Special Function IO Register */
//#define  PSR0            1       // Prescaler Reset Timer/Counter0
//#define  TSM             7       // Timer/Counter Synchronization Mode


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TOIE1           2       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1B          3       // Timer/Counter1 Output CompareB Match Interrupt Enable
#define    OCIE1A          4       // Timer/Counter1 Output CompareA Match Interrupt Enable
#define    TICIE1          5       // Timer/Counter1 Input Capture Interrupt Enable

/* ETIMSK - Extended Timer/Counter Interrupt Mask Register */
#define    OCIE1C          0       // Timer/Counter 1, Output Compare Match C Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag register */
#define    TOV1            2       // Timer/Counter1 Overflow Flag
#define    OCF1B           3       // Output Compare Flag 1B
#define    OCF1A           4       // Output Compare Flag 1A
#define    ICF1            5       // Input Capture Flag 1

/* ETIFR - Extended Timer/Counter Interrupt Flag register */
#define    OCF1C           0       // Timer/Counter 1, Output Compare C Match Flag

/* SFIOR - Special Function IO Register */
//#define  PSR321          0       // Prescaler Reset, T/C3, T/C2, T/C1
//#define  TSM             7       // Timer/Counter Synchronization Mode

/* TCCR1A - Timer/Counter1 Control Register A */
#define    WGM10           0       // Waveform Generation Mode Bit 0
#define    PWM10           WGM10   // For compatibility
#define    WGM11           1       // Waveform Generation Mode Bit 1
#define    PWM11           WGM11   // For compatibility
#define    COM1C0          2       // Compare Output Mode 1C, bit 0
#define    COM1C1          3       // Compare Output Mode 1C, bit 1
#define    COM1B0          4       // Compare Output Mode 1B, bit 0
#define    COM1B1          5       // Compare Output Mode 1B, bit 1
#define    COM1A0          6       // Compare Ouput Mode 1A, bit 0
#define    COM1A1          7       // Compare Output Mode 1A, bit 1

/* TCCR1B - Timer/Counter1 Control Register B */
#define    CS10            0       // Clock Select bit 0
#define    CS11            1       // Clock Select 1 bit 1
#define    CS12            2       // Clock Select1 bit 2
#define    WGM12           3       // Waveform Generation Mode
#define    CTC10           WGM12   // For compatibility
#define    WGM13           4       // Waveform Generation Mode
#define    CTC11           WGM13   // For compatibility
#define    ICES1           6       // Input Capture 1 Edge Select
#define    ICNC1           7       // Input Capture 1 Noise Canceler

/* TCCR1C - Timer/Counter1 Control Register C */
#define    FOC1C           5       // Force Output Compare for channel C
#define    FOC1B           6       // Force Output Compare for channel B
#define    FOC1A           7       // Force Output Compare for channel A


/* ***** TIMER_COUNTER_2 ************** */
/* TCCR2 - Timer/Counter Control Register */
#define    CS20            0       // Clock Select
#define    CS21            1       // Clock Select
#define    CS22            2       // Clock Select
#define    WGM21           3       // Waveform Generation Mode
#define    CTC2            WGM21   // For compatibility
#define    COM20           4       // Compare Match Output Mode
#define    COM21           5       // Compare Match Output Mode
#define    WGM20           6       // Wafeform Generation Mode
#define    PWM2            WGM20   // For compatibility
#define    FOC2            7       // Force Output Compare

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

/* TIMSK -  */
#define    TOIE2           6       // 
#define    OCIE2           7       // 

/* TIFR - Timer/Counter Interrupt Flag Register */
#define    TOV2            6       // Timer/Counter2 Overflow Flag
#define    OCF2            7       // Output Compare Flag 2


/* ***** TIMER_COUNTER_3 ************** */
/* ETIMSK - Extended Timer/Counter Interrupt Mask Register */
#define    OCIE3C          1       // Timer/Counter3, Output Compare Match Interrupt Enable
#define    TOIE3           2       // Timer/Counter3 Overflow Interrupt Enable
#define    OCIE3B          3       // Timer/Counter3 Output CompareB Match Interrupt Enable
#define    OCIE3A          4       // Timer/Counter3 Output CompareA Match Interrupt Enable
#define    TICIE3          5       // Timer/Counter3 Input Capture Interrupt Enable

/* ETIFR - Extended Timer/Counter Interrupt Flag register */
#define    OCF3C           1       // Timer/Counter3 Output Compare C Match Flag
#define    TOV3            2       // Timer/Counter3 Overflow Flag
#define    OCF3B           3       // Output Compare Flag 1B
#define    OCF3A           4       // Output Compare Flag 1A
#define    ICF3            5       // Input Capture Flag 1

/* SFIOR - Special Function IO Register */
//#define  PSR321          0       // Prescaler Reset, T/C3, T/C2, T/C1
//#define  PSR1            PSR321  // For compatibility
//#define  PSR2            PSR321  // For compatibility
//#define  TSM             7       // Timer/Counter Synchronization Mode

/* TCCR3A - Timer/Counter3 Control Register A */
#define    WGM30           0       // Waveform Generation Mode Bit 0
#define    PWM30           WGM30   // For compatibility
#define    WGM31           1       // Waveform Generation Mode Bit 1
#define    PWM31           WGM31   // For compatibility
#define    COM3C0          2       // Compare Output Mode 3C, bit 0
#define    COM3C1          3       // Compare Output Mode 3C, bit 1
#define    COM3B0          4       // Compare Output Mode 3B, bit 0
#define    COM3B1          5       // Compare Output Mode 3B, bit 1
#define    COM3A0          6       // Comparet Ouput Mode 3A, bit 0
#define    COM3A1          7       // Compare Output Mode 3A, bit 1

/* TCCR3B - Timer/Counter3 Control Register B */
#define    CS30            0       // Clock Select 3 bit 0
#define    CS31            1       // Clock Select 3 bit 1
#define    CS32            2       // Clock Select3 bit 2
#define    WGM32           3       // Waveform Generation Mode
#define    CTC30           WGM32   // For compatibility
#define    WGM33           4       // Waveform Generation Mode
#define    CTC31           WGM33   // For compatibility
#define    ICES3           6       // Input Capture 3 Edge Select
#define    ICNC3           7       // Input Capture 3  Noise Canceler

/* TCCR3C - Timer/Counter3 Control Register C */
#define    FOC3C           5       // Force Output Compare for channel C
#define    FOC3B           6       // Force Output Compare for channel B
#define    FOC3A           7       // Force Output Compare for channel A

/* TCNT3L - Timer/Counter3 Low Byte */
#define    TCN3L0          0       // Timer/Counter 3 bit 0
#define    TCN3L1          1       // Timer/Counter 3 bit 1
#define    TCN3L2          2       // Timer/Counter 3 bit 2
#define    TCN3L3          3       // Timer/Counter 3 bit 3
#define    TCN3L4          4       // Timer/Counter 3 bit 4
#define    TCN3L5          5       // Timer/Counter 3 bit 5
#define    TCN3L6          6       // Timer/Counter 3 bit 6
#define    TCN3L7          7       // Timer/Counter 3 bit 7


/* ***** WATCHDOG ********************* */
/* WDTCR - Watchdog Timer Control Register */
#define    WDTCSR          WDTCR   // For compatibility
#define    WDP0            0       // Watch Dog Timer Prescaler bit 0
#define    WDP1            1       // Watch Dog Timer Prescaler bit 1
#define    WDP2            2       // Watch Dog Timer Prescaler bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDCE            4       // Watchdog Change Enable
#define    WDTOE           WDCE    // For compatibility


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
#define    ADCSR           ADCSRA  // For compatibility
#define    ADPS0           0       // ADC  Prescaler Select Bits
#define    ADPS1           1       // ADC  Prescaler Select Bits
#define    ADPS2           2       // ADC  Prescaler Select Bits
#define    ADIE            3       // ADC Interrupt Enable
#define    ADIF            4       // ADC Interrupt Flag
#define    ADFR            5       // ADC  Free Running Select
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

#endif

