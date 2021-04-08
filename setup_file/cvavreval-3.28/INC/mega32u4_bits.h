/*
CodeVisionAVR V2.05.9+ C Compiler
(C) 1998-2012 Pavel Haiduc, HP InfoTech s.r.l.

ATmega16U4, ATmega32U4 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __MEGA32U4_BITS_INCLUDED__
#define __MEGA32U4_BITS_INCLUDED__

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


/* ***** TIMER_COUNTER_3 ************** */
/* TIMSK3 - Timer/Counter3 Interrupt Mask Register */
#define    TOIE3           0       // Timer/Counter3 Overflow Interrupt Enable
#define    OCIE3A          1       // Timer/Counter3 Output Compare A Match Interrupt Enable
#define    OCIE3B          2       // Timer/Counter3 Output Compare B Match Interrupt Enable
#define    OCIE3C          3       // Timer/Counter3 Output Compare C Match Interrupt Enable
#define    ICIE3           5       // Timer/Counter3 Input Capture Interrupt Enable

/* TIFR3 - Timer/Counter3 Interrupt Flag register */
#define    TOV3            0       // Timer/Counter3 Overflow Flag
#define    OCF3A           1       // Output Compare Flag 3A
#define    OCF3B           2       // Output Compare Flag 3B
#define    OCF3C           3       // Output Compare Flag 3C
#define    ICF3            5       // Input Capture Flag 3

/* TCCR3A - Timer/Counter3 Control Register A */
#define    WGM30           0       // Waveform Generation Mode
#define    WGM31           1       // Waveform Generation Mode
#define    COM3C0          2       // Compare Output Mode 3C, bit 0
#define    COM3C1          3       // Compare Output Mode 3C, bit 1
#define    COM3B0          4       // Compare Output Mode 3B, bit 0
#define    COM3B1          5       // Compare Output Mode 3B, bit 1
#define    COM3A0          6       // Compare Output Mode 3A, bit 0
#define    COM3A1          7       // Compare Output Mode 1A, bit 1

/* TCCR3B - Timer/Counter3 Control Register B */
#define    CS30            0       // Prescaler source of Timer/Counter 3
#define    CS31            1       // Prescaler source of Timer/Counter 3
#define    CS32            2       // Prescaler source of Timer/Counter 3
#define    WGM32           3       // Waveform Generation Mode
#define    WGM33           4       // Waveform Generation Mode
#define    ICES3           6       // Input Capture 3 Edge Select
#define    ICNC3           7       // Input Capture 3 Noise Canceler

/* TCCR3C - Timer/Counter 3 Control Register C */
#define    FOC3C           5       // Force Output Compare 3C
#define    FOC3B           6       // Force Output Compare 3B
#define    FOC3A           7       // Force Output Compare 3A


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK1 - Timer/Counter1 Interrupt Mask Register */
#define    TOIE1           0       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1A          1       // Timer/Counter1 Output Compare A Match Interrupt Enable
#define    OCIE1B          2       // Timer/Counter1 Output Compare B Match Interrupt Enable
#define    OCIE1C          3       // Timer/Counter1 Output Compare C Match Interrupt Enable
#define    ICIE1           5       // Timer/Counter1 Input Capture Interrupt Enable

/* TIFR1 - Timer/Counter1 Interrupt Flag register */
#define    TOV1            0       // Timer/Counter1 Overflow Flag
#define    OCF1A           1       // Output Compare Flag 1A
#define    OCF1B           2       // Output Compare Flag 1B
#define    OCF1C           3       // Output Compare Flag 1C
#define    ICF1            5       // Input Capture Flag 1

/* TCCR1A - Timer/Counter1 Control Register A */
#define    WGM10           0       // Waveform Generation Mode
#define    WGM11           1       // Waveform Generation Mode
#define    COM1C0          2       // Compare Output Mode 1C, bit 0
#define    COM1C1          3       // Compare Output Mode 1C, bit 1
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
#define    FOC1C           5       // Force Output Compare 1C
#define    FOC1B           6       // Force Output Compare 1B
#define    FOC1A           7       // Force Output Compare 1A


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

// 07022012_3
/* ***** TWI ************************** */
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

/* TWAMR - TWI (Slave) Address Mask Register */
#define    TWAM0           1       //
#define    TWAM1           2       //
#define    TWAM2           3       //
#define    TWAM3           4       //
#define    TWAM4           5       //
#define    TWAM5           6       //
#define    TWAM6           7       //

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
#define    INT0            0       // External Interrupt Request 0 Enable
#define    INT1            1       // External Interrupt Request 1 Enable
#define    INT2            2       // External Interrupt Request 2 Enable
#define    INT3            3       // External Interrupt Request 3 Enable
#define    INT4            4       // External Interrupt Request 4 Enable
#define    INT5            5       // External Interrupt Request 5 Enable
#define    INT6            6       // External Interrupt Request 6 Enable
#define    INT7            7       // External Interrupt Request 7 Enable

/* EIFR - External Interrupt Flag Register */
#define    INTF0           0       // External Interrupt Flag 0
#define    INTF1           1       // External Interrupt Flag 1
#define    INTF2           2       // External Interrupt Flag 2
#define    INTF3           3       // External Interrupt Flag 3
#define    INTF4           4       // External Interrupt Flag 4
#define    INTF5           5       // External Interrupt Flag 5
#define    INTF6           6       // External Interrupt Flag 6
#define    INTF7           7       // External Interrupt Flag 7

/* PCICR - Pin Change Interrupt Control Register */
#define    PCIE0           0       // Pin Change Interrupt Enable 0

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 0

/* PCMSK0 - Pin Change Mask Register 0 */
#define    PCINT0          0       // Pin Change Enable Mask 0
#define    PCINT1          1       // Pin Change Enable Mask 1
#define    PCINT2          2       // Pin Change Enable Mask 2
#define    PCINT3          3       // Pin Change Enable Mask 3
#define    PCINT4          4       // Pin Change Enable Mask 4
#define    PCINT5          5       // Pin Change Enable Mask 5
#define    PCINT6          6       // Pin Change Enable Mask 6
#define    PCINT7          7       // Pin Change Enable Mask 7


/* ***** TIMER_COUNTER_4 ************** */
/* DT4 - Timer/Counter 4 Dead Time Value */
#define    DT4L0           0       // Timer/Counter 4 Dead Time Value Bit 0
#define    DT4L1           1       // Timer/Counter 4 Dead Time Value Bit 1
#define    DT4L2           2       // Timer/Counter 4 Dead Time Value Bit 2
#define    DT4L3           3       // Timer/Counter 4 Dead Time Value Bit 3
#define    DT4L4           4       // Timer/Counter 4 Dead Time Value Bit 4
#define    DT4L5           5       // Timer/Counter 4 Dead Time Value Bit 5
#define    DT4L6           6       // Timer/Counter 4 Dead Time Value Bit 6
#define    DT4L7           7       // Timer/Counter 4 Dead Time Value Bit 7

/* TIFR4 - Timer/Counter4 Interrupt Flag register */
#define    TOV4            2       // Timer/Counter4 Overflow Flag
#define    OCF4B           5       // Output Compare Flag 4B
#define    OCF4A           6       // Output Compare Flag 4A
#define    OCF4D           7       // Output Compare Flag 4D

/* TIMSK4 - Timer/Counter4 Interrupt Mask Register */
#define    TOIE4           2       // Timer/Counter4 Overflow Interrupt Enable
#define    OCIE4B          5       // Timer/Counter4 Output Compare B Match Interrupt Enable
#define    OCIE4A          6       // Timer/Counter4 Output Compare A Match Interrupt Enable
#define    OCIE4D          7       // Timer/Counter4 Output Compare D Match Interrupt Enable

/* OCR4D - Timer/Counter4 Output Compare Register D */
#define    OCR4D0          0       // Timer/Counter4 Output Compare Register Low Byte bit 0
#define    OCR4D1          1       // Timer/Counter4 Output Compare Register Low Byte bit 1
#define    OCR4D2          2       // Timer/Counter4 Output Compare Register Low Byte bit 2
#define    OCR4D3          3       // Timer/Counter4 Output Compare Register Low Byte bit 3
#define    OCR4D4          4       // Timer/Counter4 Output Compare Register Low Byte bit 4
#define    OCR4D5          5       // Timer/Counter4 Output Compare Register Low Byte bit 5
#define    OCR4D6          6       // Timer/Counter4 Output Compare Register Low Byte bit 6
#define    OCR4D7          7       // Timer/Counter4 Output Compare Register Low Byte bit 7

/* OCR4C - Timer/Counter4 Output Compare Register C */
#define    OCR4C0          0       // Timer/Counter4 Output Compare Register bit 0
#define    OCR4C1          1       // Timer/Counter4 Output Compare Register bit 1
#define    OCR4C2          2       // Timer/Counter4 Output Compare Register bit 2
#define    OCR4C3          3       // Timer/Counter4 Output Compare Register bit 3
#define    OCR4C4          4       // Timer/Counter4 Output Compare Register bit 4
#define    OCR4C5          5       // Timer/Counter4 Output Compare Register bit 5
#define    OCR4C6          6       // Timer/Counter4 Output Compare Register 6
#define    OCR4C7          7       // Timer/Counter4 Output Compare Register bit 7

/* OCR4B - Timer/Counter4 Output Compare Register B */
#define    OCR4B0          0       // Timer/Counter4 Output Compare Register bit 0
#define    OCR4B1          1       // Timer/Counter4 Output Compare Register bit 1
#define    OCR4B2          2       // Timer/Counter4 Output Compare Register bit 2
#define    OCR4B3          3       // Timer/Counter4 Output Compare Register bit 3
#define    OCR4B4          4       // Timer/Counter4 Output Compare Register bit 4
#define    OCR4B5          5       // Timer/Counter4 Output Compare Register bit 5
#define    OCR4B6          6       // Timer/Counter4 Output Compare Register bit 6
#define    OCR4B7          7       // Timer/Counter4 Output Compare Register bit 7

/* OCR4A - Timer/Counter4 Outbut Compare Register A */
#define    OCR4A0          0       // Timer/Counter4 Outbut Compare Register Bit 0
#define    OCR4A1          1       // Timer/Counter4 Outbut Compare Register Bit 1
#define    OCR4A2          2       // Timer/Counter4 Outbut Compare Register Low Byte Bit 2
#define    OCR4A3          3       // Timer/Counter4 Outbut Compare Register Low Byte Bit 3
#define    OCR4A4          4       // Timer/Counter4 Outbut Compare Register Bit 4
#define    OCR4A5          5       // Timer/Counter4 Outbut Compare Register Bit 5
#define    OCR4A6          6       // Timer/Counter4 Outbut Compare Register Bit 6
#define    OCR4A7          7       // Timer/Counter4 Outbut Compare Register Bit 7

/* TC4H - Timer/Counter4 */
#define    TC48            0       // Timer/Counter4 bit 8
#define    TC49            1       // Timer/Counter4 bit 9
#define    TC410           2       // Timer/Counter4 bit 10

/* TCNT4 - Timer/Counter4 Low Bytes */
#define    TC40            0       // Timer/Counter4 bit 0
#define    TC41            1       // Timer/Counter4 bit 1
#define    TC42            2       // Timer/Counter4 bit 2
#define    TC43            3       // Timer/Counter4  bit 3
#define    TC44            4       // Timer/Counter4 bit 4
#define    TC45            5       // Timer/Counter4 bit 5
#define    TC46            6       // Timer/Counter4 bit 6
#define    TC47            7       // Timer/Counter4 bit 7

/* TCCR4E - Timer/Counter 4 Control Register E */
#define    OC4OE0          0       // Output Compare Override Enable bit
#define    OC4OE1          1       // Output Compare Override Enable bit
#define    OC4OE2          2       // Output Compare Override Enable bit
#define    OC4OE3          3       // Output Compare Override Enable bit
#define    OC4OE4          4       // Output Compare Override Enable bit
#define    OC4OE5          5       // Output Compare Override Enable bit
#define    ENHC4           6       // Enhanced Compare/PWM Mode
#define    TLOCK4          7       // Register Update Lock

/* TCCR4D - Timer/Counter 4 Control Register D */
#define    WGM40           0       // Waveform Generation Mode bits
#define    WGM41           1       // Waveform Generation Mode bits
#define    FPF4            2       // Fault Protection Interrupt Flag
#define    FPAC4           3       // Fault Protection Analog Comparator Enable
#define    FPES4           4       // Fault Protection Edge Select
#define    FPNC4           5       // Fault Protection Noise Canceler
#define    FPEN4           6       // Fault Protection Mode Enable
#define    FPIE4           7       // Fault Protection Interrupt Enable

/* TCCR4C - Timer/Counter 4 Control Register C */
#define    PWM4D           0       // Pulse Width Modulator D Enable
#define    FOC4D           1       // Force Output Compare Match 4D
#define    COM4D0          2       // Comparator D Output Mode
#define    COM4D1          3       // Comparator D Output Mode
#define    COM4B0S         4       // Comparator B Output Mode
#define    COM4B1S         5       // Comparator B Output Mode
#define    COM4A0S         6       // Comparator A Output Mode
#define    COM4A1S         7       // Comparator A Output Mode

/* TCCR4B - Timer/Counter4 Control Register B */
#define    CS40            0       // Clock Select Bit 0
#define    CS41            1       // Clock Select Bit 1
#define    CS42            2       // Clock Select Bit 2
#define    CS43            3       // Clock Select Bit 3
#define    DTPS40          4       // Dead Time Prescaler Bit 0
#define    DTPS41          5       // Dead Time Prescaler Bit 1
#define    PSR4            6       // Prescaler Reset Timer/Counter 4
#define    PWM4X           7       // PWM Inversion Mode

/* TCCR4A - Timer/Counter4 Control Register A */
#define    PWM4B           0       //
#define    PWM4A           1       //
#define    FOC4B           2       // Force Output Compare Match 4B
#define    FOC4A           3       // Force Output Compare Match 4A
#define    COM4B0          4       // Compare Output Mode 4B, bit 0
#define    COM4B1          5       // Compare Output Mode 4B, bit 1
#define    COM4A0          6       // Compare Output Mode 4A, bit 0
#define    COM4A1          7       // Compare Output Mode 1A, bit 1


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
#define    PORTC6          6       // Port C Data Register bit 6
#define    PORTC7          7       // Port C Data Register bit 7

/* DDRC - Port C Data Direction Register */
#define    DDC6            6       // Port C Data Direction Register bit 6
#define    DDC7            7       // Port C Data Direction Register bit 7

/* PINC - Port C Input Pins */
#define    PINC6           6       // Port C Input Pins bit 6
#define    PINC7           7       // Port C Input Pins bit 7


/* ***** PORTE ************************ */
/* PORTE - Data Register, Port E */
#define    PORTE2          2       //
#define    PORTE6          6       //

/* DDRE - Data Direction Register, Port E */
#define    DDE2            2       //
#define    DDE6            6       //

/* PINE - Input Pins, Port E */
#define    PINE2           2       //
#define    PINE6           6       //


/* ***** PORTF ************************ */
/* PORTF - Data Register, Port F */
#define    PORTF0          0       //
#define    PORTF1          1       //
#define    PORTF4          4       //
#define    PORTF5          5       //
#define    PORTF6          6       //
#define    PORTF7          7       //

/* DDRF - Data Direction Register, Port F */
#define    DDF0            0       //
#define    DDF1            1       //
#define    DDF4            4       //
#define    DDF5            5       //
#define    DDF6            6       //
#define    DDF7            7       //

/* PINF - Input Pins, Port F */
#define    PINF0           0       //
#define    PINF1           1       //
#define    PINF4           4       //
#define    PINF5           5       //
#define    PINF6           6       //
#define    PINF7           7       //


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
#define    ADTS3           4       // ADC Auto Trigger Source 3
#define    MUX5            5       // Analog Channel and Gain Selection Bits
#define    ADHSM           7       // ADC High Speed Mode

/* DIDR0 - Digital Input Disable Register 1 */
#define    ADC0D           0       // ADC0 Digital input Disable
#define    ADC1D           1       // ADC1 Digital input Disable
#define    ADC2D           2       // ADC2 Digital input Disable
#define    ADC3D           3       // ADC3 Digital input Disable
#define    ADC4D           4       // ADC4 Digital input Disable
#define    ADC5D           5       // ADC5 Digital input Disable
#define    ADC6D           6       // ADC6 Digital input Disable
#define    ADC7D           7       // ADC7 Digital input Disable

/* DIDR2 - Digital Input Disable Register 1 */
#define    ADC8D           0       // ADC8 Digital input Disable
#define    ADC9D           1       // ADC9 Digital input Disable
#define    ADC10D          2       // ADC10 Digital input Disable
#define    ADC11D          3       // ADC11 Digital input Disable
#define    ADC12D          4       // ADC12 Digital input Disable
#define    ADC13D          5       // ADC13 Digital input Disable


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

/* DIDR1 -  */
#define    AIN0D           0       // AIN0 Digital Input Disable
#define    AIN1D           1       // AIN1 Digital Input Disable


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
//#define  JTD             7       // JTAG Interface Disable

/* MCUSR - MCU Status Register */
#define    PORF            0       // Power-on reset flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag
#define    JTRF            4       // JTAG Reset Flag
#define    USBRF           5       // USB Reset Flag

/* OSCCAL - Oscillator Calibration Value */
#define    CAL0            0       // Oscillator Calibration Value Bit0
#define    CAL1            1       // Oscillator Calibration Value Bit1
#define    CAL2            2       // Oscillator Calibration Value Bit2
#define    CAL3            3       // Oscillator Calibration Value Bit3
#define    CAL4            4       // Oscillator Calibration Value Bit4
#define    CAL5            5       // Oscillator Calibration Value Bit5
#define    CAL6            6       // Oscillator Calibration Value Bit6
#define    CAL7            7       // Oscillator Calibration Value Bit7

/* RCCTRL - Oscillator Control Register */
#define    RCFREQ          0       //

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

/* EIND - Extended Indirect Register */
#define    EIND0           0       // Bit 0

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

/* PRR1 - Power Reduction Register1 */
#define    PRUSART1        0       // Power Reduction USART1
#define    PRTIM3          3       // Power Reduction Timer/Counter3
#define    PRUSB           7       // Power Reduction USB

/* PRR0 - Power Reduction Register0 */
#define    PRADC           0       // Power Reduction ADC
#define    PRUSART0        1       // Power Reduction USART
#define    PRSPI           2       // Power Reduction Serial Peripheral Interface
#define    PRTIM1          3       // Power Reduction Timer/Counter1
#define    PRTIM0          5       // Power Reduction Timer/Counter0
#define    PRTIM2          6       // Power Reduction Timer/Counter2
#define    PRTWI           7       // Power Reduction TWI

/* CLKSTA -  */
#define    EXTON           0       //
#define    RCON            1       //

/* CLKSEL0 -  */
#define    CLKS            0       //
#define    EXTE            2       //
#define    RCE             3       //
#define    EXSUT0          4       //
#define    EXSUT1          5       //
#define    RCSUT0          6       //
#define    RCSUT1          7       //

/* CLKSEL1 -  */
#define    EXCKSEL0        0       //
#define    EXCKSEL1        1       //
#define    EXCKSEL2        2       //
#define    EXCKSEL3        3       //
#define    RCCKSEL0        4       //
#define    RCCKSEL1        5       //
#define    RCCKSEL2        6       //
#define    RCCKSEL3        7       //


/* ***** PLL ************************** */
/* PLLCSR - PLL Status and Control register */
#define    PLOCK           0       // PLL Lock Status Bit
#define    PLLE            1       // PLL Enable Bit
#define    PINDIV          4       // PLL prescaler Bit 2

/* PLLFRQ - PLL Frequency Control Register */
#define    PDIV0           0       //
#define    PDIV1           1       //
#define    PDIV2           2       //
#define    PDIV3           3       //
#define    PLLTM0          4       //
#define    PLLTM1          5       //
#define    PLLUSB          6       //
#define    PINMUX          7       //


/* ***** USB_DEVICE ******************* */
/* USBCON - USB General Control Register */
#define    VBUSTE          0       //
#define    OTGPADE         4       //
#define    FRZCLK          5       //
#define    USBE            7       //

/* UDCON -  */
#define    DETACH          0       //
#define    RMWKUP          1       //
#define    LSM             2       // USB low speed mode
#define    RSTCPU          3       //

/* UDINT -  */
#define    SUSPI           0       //
#define    SOFI            2       //
#define    EORSTI          3       //
#define    WAKEUPI         4       //
#define    EORSMI          5       //
#define    UPRSMI          6       //

/* UDIEN -  */
#define    SUSPE           0       //
#define    SOFE            2       //
#define    EORSTE          3       //
#define    WAKEUPE         4       //
#define    EORSME          5       //
#define    UPRSME          6       //

/* UDADDR -  */
#define    UADD0           0       //
#define    UADD1           1       //
#define    UADD2           2       //
#define    UADD3           3       //
#define    UADD4           4       //
#define    UADD5           5       //
#define    UADD6           6       //
#define    ADDEN           7       //

/* UDFNUML -  */
#define    FNUM0           0       //
#define    FNUM1           1       //
#define    FNUM2           2       //
#define    FNUM3           3       //
#define    FNUM4           4       //
#define    FNUM5           5       //
#define    FNUM6           6       //
#define    FNUM7           7       //

/* UDFNUMH -  */
#define    FNUM8           0       //
#define    FNUM9           1       //
#define    FNUM10          2       //

/* UDMFN -  */
#define    FNCERR          4       //

/* UEINTX -  */
#define    TXINI           0       //
#define    STALLEDI        1       //
#define    RXOUTI          2       //
#define    RXSTPI          3       //
#define    NAKOUTI         4       //
#define    RWAL            5       //
#define    NAKINI          6       //
#define    FIFOCON         7       //

/* UENUM -  */
#define    UENUM_0         0       //
#define    UENUM_1         1       //
#define    UENUM_2         2       //

/* UERST -  */
#define    EPRST0          0       //
#define    EPRST1          1       //
#define    EPRST2          2       //
#define    EPRST3          3       //
#define    EPRST4          4       //
#define    EPRST5          5       //
#define    EPRST6          6       //

/* UECONX -  */
#define    EPEN            0       //
#define    RSTDT           3       //
#define    STALLRQC        4       //
#define    STALLRQ         5       //

/* UECFG0X -  */
#define    EPDIR           0       //
#define    EPTYPE0         6       //
#define    EPTYPE1         7       //

/* UECFG1X -  */
#define    ALLOC           1       //
#define    EPBK0           2       //
#define    EPBK1           3       //
#define    EPSIZE0         4       //
#define    EPSIZE1         5       //
#define    EPSIZE2         6       //

/* UESTA0X -  */
#define    NBUSYBK0        0       //
#define    NBUSYBK1        1       //
#define    DTSEQ0          2       //
#define    DTSEQ1          3       //
#define    UNDERFI         5       //
#define    OVERFI          6       //
#define    CFGOK           7       //

/* UESTA1X -  */
#define    CURRBK0         0       //
#define    CURRBK1         1       //
#define    CTRLDIR         2       //

/* UEIENX -  */
#define    TXINE           0       //
#define    STALLEDE        1       //
#define    RXOUTE          2       //
#define    RXSTPE          3       //
#define    NAKOUTE         4       //
#define    NAKINE          6       //
#define    FLERRE          7       //

/* UEDATX -  */
#define    DAT0            0       //
#define    DAT1            1       //
#define    DAT2            2       //
#define    DAT3            3       //
#define    DAT4            4       //
#define    DAT5            5       //
#define    DAT6            6       //
#define    DAT7            7       //

/* UEBCLX -  */
#define    BYCT0           0       //
#define    BYCT1           1       //
#define    BYCT2           2       //
#define    BYCT3           3       //
#define    BYCT4           4       //
#define    BYCT5           5       //
#define    BYCT6           6       //
#define    BYCT7           7       //

/* UEINT -  */
#define    EPINT0          0       //
#define    EPINT1          1       //
#define    EPINT2          2       //
#define    EPINT3          3       //
#define    EPINT4          4       //
#define    EPINT5          5       //
#define    EPINT6          6       //

/* USBINT -  */
#define    VBUSTI          0       //

/* USBSTA -  */
#define    VBUS            0       //
#define    SPEED           3       //

/* UHWCON -  */
#define    UVREGE          0       //

#endif

