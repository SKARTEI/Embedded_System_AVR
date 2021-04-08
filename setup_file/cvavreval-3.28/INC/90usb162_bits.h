/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

AT90USB82, AT90USB162 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __90USB162_BITS_INCLUDED__
#define __90USB162_BITS_INCLUDED__

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


/* ***** PLL ************************** */
/* PLLCSR - PLL Status and Control register */
#define    PLOCK           0       // PLL Lock Status Bit
#define    PLLE            1       // PLL Enable Bit
#define    PLLP0           2       // PLL prescaler Bit 0
#define    PLLP1           3       // PLL prescaler Bit 1
#define    PLLP2           4       // PLL prescaler Bit 2


/* ***** USB_DEVICE ******************* */
/* USBCON - USB General Control Register */
#define    FRZCLK          5       // 
#define    USBE            7       // 

/* UDCON -  */
#define    DETACH          0       // 
#define    RMWKUP          1       // 
#define    RSTCPU          2       // 

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
#define    EPNUM0          0       // 
#define    EPNUM1          1       // 
#define    EPNUM2          2       // 

/* UERST -  */
#define    EPRST0          0       // 
#define    EPRST1          1       // 
#define    EPRST2          2       // 
#define    EPRST3          3       // 
#define    EPRST4          4       // 

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

/* REGCR - Regulator Control Register */
#define    REGDIS          0       // 


/* ***** PS2 ************************** */
/* UPOE -  */
#define    DMI             0       // 
#define    DPI             1       // 
#define    DATAI           2       // 
#define    SCKI            3       // 
#define    UPDRV0          4       // 
#define    UPDRV1          5       // 
#define    UPWE0           6       // 
#define    UPWE1           7       // 

/* PS2CON - PS2 Pad Enable register */
#define    PS2EN           0       // Enable


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
#define    USBRF           5       // USB reset flag

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
#define    PRUSB           7       // Power Reduction USB

/* PRR0 - Power Reduction Register0 */
#define    PRSPI           2       // Power Reduction Serial Peripheral Interface
#define    PRTIM1          3       // Power Reduction Timer/Counter1
#define    PRTIM0          5       // Power Reduction Timer/Counter0

/* CLKSTA -  */
#define    EXTON           0       // 
#define    RCON            1       // 

/* CLKSEL1 -  */
#define    EXCKSEL0        0       // 
#define    EXCKSEL1        1       // 
#define    EXCKSEL2        2       // 
#define    EXCKSEL3        3       // 
#define    RCCKSEL0        4       // 
#define    RCCKSEL1        5       // 
#define    RCCKSEL2        6       // 
#define    RCCKSEL3        7       // 

/* CLKSEL0 -  */
#define    CLKS            0       // 
#define    EXTE            2       // 
#define    RCE             3       // 
#define    EXSUT0          4       // 
#define    EXSUT1          5       // 
#define    RCSUT0          6       // 
#define    RCSUT1          7       // 

/* DWDR - debugWire communication register */
#define    DWDR0           0       // 
#define    DWDR1           1       // 
#define    DWDR2           2       // 
#define    DWDR3           3       // 
#define    DWDR4           4       // 
#define    DWDR5           5       // 
#define    DWDR6           6       // 
#define    DWDR7           7       // 


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
#define    PCIE1           1       // Pin Change Interrupt Enable 1

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 0
#define    PCIF1           1       // Pin Change Interrupt Flag 1

/* PCMSK0 - Pin Change Mask Register 0 */
#define    PCINT0          0       // Pin Change Enable Mask 0
#define    PCINT1          1       // Pin Change Enable Mask 1
#define    PCINT2          2       // Pin Change Enable Mask 2
#define    PCINT3          3       // Pin Change Enable Mask 3
#define    PCINT4          4       // Pin Change Enable Mask 4
#define    PCINT5          5       // Pin Change Enable Mask 5
#define    PCINT6          6       // Pin Change Enable Mask 6
#define    PCINT7          7       // Pin Change Enable Mask 7

/* PCMSK1 - Pin Change Mask Register 1 */
#define    PCINT8          0       // 
#define    PCINT9          1       // 
#define    PCINT10         2       // 
#define    PCINT11         3       // 
#define    PCINT12         4       // 


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
#define    UCSZ11          2       // Character Size
#define    USBS1           3       // Stop Bit Select
#define    UPM10           4       // Parity Mode Bit 0
#define    UPM11           5       // Parity Mode Bit 1
#define    UMSEL10         6       // USART Mode Select
#define    UMSEL11         7       // USART Mode Select

/* UCSR1D - USART Control and Status Register D */
#define    RTSEN           0       // RTS Enable
#define    CTSEN           1       // CTS Enable


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

/* WDTCKD - Watchdog Timer Clock Divider */
#define    WCLKD0          0       // Watchdog Timer Clock Divider 0
#define    WCLKD1          1       // Watchdog Timer Clock Divider 1
#define    WDEWIE          2       // Watchdog Early Warning Interrupt Enable
#define    WDEWIF          3       // Watchdog Early Warning Interrupt Flag


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

/* DIDR1 -  */
#define    AIN0D           0       // AIN0 Digital Input Disable
#define    AIN1D           1       // AIN1 Digital Input Disable


/* ***** PORTC ************************ */
/* PORTC - Port C Data Register */
#define    PORTC0          0       // Port C Data Register bit 0
#define    PORTC1          1       // Port C Data Register bit 1
#define    PORTC2          2       // Port C Data Register bit 2
#define    PORTC4          4       // Port C Data Register bit 4
#define    PORTC5          5       // Port C Data Register bit 5
#define    PORTC6          6       // Port C Data Register bit 6
#define    PORTC7          7       // Port C Data Register bit 7

/* DDRC - Port C Data Direction Register */
#define    DDC0            0       // Port C Data Direction Register bit 0
#define    DDC1            1       // Port C Data Direction Register bit 1
#define    DDC2            2       // Port C Data Direction Register bit 2
#define    DDC4            4       // Port C Data Direction Register bit 4
#define    DDC5            5       // Port C Data Direction Register bit 5
#define    DDC6            6       // Port C Data Direction Register bit 6
#define    DDC7            7       // Port C Data Direction Register bit 7

/* PINC - Port C Input Pins */
#define    PINC0           0       // Port C Input Pins bit 0
#define    PINC1           1       // Port C Input Pins bit 1
#define    PINC2           2       // Port C Input Pins bit 2
#define    PINC4           4       // Port C Input Pins bit 4
#define    PINC5           5       // Port C Input Pins bit 5
#define    PINC6           6       // Port C Input Pins bit 6
#define    PINC7           7       // Port C Input Pins bit 7

#endif

