/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2012 Pavel Haiduc, HP InfoTech s.r.l.

ATmega406 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __MEGA406_BITS_INCLUDED__
#define __MEGA406_BITS_INCLUDED__

/* ***** AD_CONVERTER ***************** */
/* VADMUX - The VADC multiplexer Selection Register */
#define    VADMUX0         0       // Analog Channel and Gain Selection Bits
#define    VADMUX1         1       // Analog Channel and Gain Selection Bits
#define    VADMUX2         2       // Analog Channel and Gain Selection Bits
#define    VADMUX3         3       // Analog Channel and Gain Selection Bits

/* VADCSR - The VADC Control and Status register */
#define    VADCCIE         0       // VADC Conversion Complete Interrupt Enable
#define    VADCCIF         1       // VADC Conversion Complete Interrupt Flag
#define    VADSC           2       // VADC Satrt Conversion
#define    VADEN           3       // VADC Enable


/* ***** EXTERNAL_INTERRUPT *********** */
/* EICRA - External Interrupt Control Register */
#define    ISC00           0       // External Interrupt Sense Control 0 Bit 0
#define    ISC01           1       // External Interrupt Sense Control 0 Bit 1
#define    ISC10           2       // External Interrupt Sense Control 1 Bit 0
#define    ISC11           3       // External Interrupt Sense Control 1 Bit 1
#define    ISC20           4       // External Interrupt Sense Control 2 Bit 0
#define    ISC21           5       // External Interrupt Sense Control 2 Bit 1
#define    ISC30           6       // External Interrupt Sense Control 3 Bit 0
#define    ISC31           7       // External Interrupt Sense Control 3 Bit 1

/* EIMSK - External Interrupt Mask Register */
#define    INT0            0       // External Interrupt Request 0 Enable
#define    INT1            1       // External Interrupt Request 1 Enable
#define    INT2            2       // External Interrupt Request 1 Enable
#define    INT3            3       // External Interrupt Request 1 Enable

/* EIFR - External Interrupt Flag Register */
#define    INTF0           0       // External Interrupt Flag 0
#define    INTF1           1       // External Interrupt Flag 1
#define    INTF2           2       // External Interrupt Flag 2
#define    INTF3           3       // External Interrupt Flag 3

/* PCICR - Pin Change Interrupt Control Register */
#define    PCIE0           0       // Pin Change Interrupt Enable 0
#define    PCIE1           1       // Pin Change Interrupt Enable 1

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 1
#define    PCIF1           1       // Pin Change Interrupt Flag 1

/* PCMSK1 - Pin Change Enable Mask Register 1 */
#define    PCINT8          0       // Pin Change Enable Mask 8
#define    PCINT9          1       // Pin Change Enable Mask 9
#define    PCINT10         2       // Pin Change Enable Mask 10
#define    PCINT11         3       // Pin Change Enable Mask 11
#define    PCINT12         4       // Pin Change Enable Mask 12
#define    PCINT13         5       // Pin Change Enable Mask 13
#define    PCINT14         6       // Pin Change Enable Mask 14
#define    PCINT15         7       // Pin Change Enable Mask 15

/* PCMSK0 - Pin Change Enable Mask Register 0 */
#define    PCINT0          0       // Pin Change Enable Mask 0
#define    PCINT1          1       // Pin Change Enable Mask 1
#define    PCINT2          2       // Pin Change Enable Mask 2
#define    PCINT3          3       // Pin Change Enable Mask 3
#define    PCINT4          4       // Pin Change Enable Mask 4
#define    PCINT5          5       // Pin Change Enable Mask 5
#define    PCINT6          6       // Pin Change Enable Mask 6
#define    PCINT7          7       // Pin Change Enable Mask 7


/* ***** TIMER_COUNTER_1 ************** */
/* TCCR1B - Timer/Counter1 Control Register B */
#define    CS10            0       // Clock Select1 bit 0
#define    CS11            1       // Clock Select1 bit 1
#define    CS12            2       // Clock Select1 bit 2
#define    CTC1            3       // Clear Timer/Counter on Compare Match

/* TIMSK1 - Timer/Counter Interrupt Mask Register */
#define    TOIE1           0       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1A          1       // Timer/Counter1 Output Compare Interrupt Enable

/* TIFR1 - Timer/Counter Interrupt Flag register */
#define    TOV1            0       // Timer/Counter1 Overflow Flag
#define    OCF1A           1       // Timer/Counter1 Output Compare Flag A

/* GTCCR - General Timer/Counter Control Register */
#define    PSRSYNC         0       // Prescaler Reset
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** WAKEUP_TIMER ***************** */
/* WUTCSR - Wake-up Timer Control Register */
#define    WUTP0           0       // Wake-up Timer Prescaler Bit 0
#define    WUTP1           1       // Wake-up Timer Prescaler Bit 1
#define    WUTP2           2       // Wake-up Timer Prescaler Bit 2
#define    WUTE            3       // Wake-up Timer Enable
#define    WUTR            4       // Wake-up Timer Reset
#define    WUTCF           5       // Wake-up timer Calibration Flag
#define    WUTIE           6       // Wake-up Timer Interrupt Enable
#define    WUTIF           7       // Wake-up Timer Interrupt Flag


/* ***** BATTERY_PROTECTION *********** */
/* BPPLR - Battery Protection Parameter Lock Register */
#define    BPPL            0       // Battery Protection Parameter Lock
#define    BPPLE           1       // Battery Protection Parameter Lock Enable

/* BPCR - Battery Protection Control Register */
#define    CCD             0       // 
#define    DCD             1       // 
#define    SCD             2       // 
#define    DUVD            3       // 

/* CBPTR - Current Battery Protection Timing Register */
#define    OCPT0           0       // 
#define    OCPT1           1       // 
#define    OCPT2           2       // 
#define    OCPT3           3       // 
#define    SCPT0           4       // 
#define    SCPT1           5       // 
#define    SCPT2           6       // 
#define    SCPT3           7       // 

/* BPOCD - Battery Protection OverCurrent Detection Level Register */
#define    CCDL0           0       // 
#define    CCDL1           1       // 
#define    CCDL2           2       // 
#define    CCDL3           3       // 
#define    DCDL0           4       // 
#define    DCDL1           5       // 
#define    DCDL2           6       // 
#define    DCDL3           7       // 

/* BPSCD - Battery Protection Short-Circuit Detection Level Register */
#define    SCDL0           0       // 
#define    SCDL1           1       // 
#define    SCDL2           2       // 
#define    SCDL3           3       // 

/* BPDUV - Battery Protection Deep Under Voltage Register */
#define    DUDL0           0       // 
#define    DUDL1           1       // 
#define    DUDL2           2       // 
#define    DUDL3           3       // 
#define    DUVT0           4       // 
#define    DUVT1           5       // 

/* BPIR - Battery Protection Interrupt Register */
#define    SCIE            0       // 
#define    DOCIE           1       // 
#define    COCIE           2       // 
#define    DUVIE           3       // Deep Under-voltage Early Warning Interrupt Enable
#define    SCIF            4       // 
#define    DOCIF           5       // 
#define    COCIF           6       // Charge Over-current Protection Activated Interrupt Flag
#define    DUVIF           7       // Deep Under-voltage Early Warning Interrupt Flag


/* ***** FET ************************** */
/* FCSR -  */
#define    PFD             0       // Precharge FET disable
#define    CFE             1       // Charge FET Enable
#define    DFE             2       // Discharge FET Enable
#define    CPS             3       // Current Protection Status
#define    PWMOPC          4       // Pulse Width Modulation Modulation of OPC output
#define    PWMOC           5       // Pulse Width Modulation of OC output


/* ***** COULOMB_COUNTER ************** */
/* CADCSRA - CC-ADC Control and Status Register A */
#define    CADSE           0       // When the CADSE bit is written to one, the ongoing CC-ADC conversion is aborted, and the CC-ADC enters Regular Current detection mode.
#define    CADSI0          1       // The CADSI bits determine the current sampling interval for the Regular Current detection in Power-down mode. The actual settings remain to be determined.
#define    CADSI1          2       // The CADSI bits determine the current sampling interval for the Regular Current detection in Power-down mode. The actual settings remain to be determined.
#define    CADAS0          3       // CC_ADC Accumulate Current Select Bit 0
#define    CADAS1          4       // CC_ADC Accumulate Current Select Bit 1
#define    CADUB           5       // CC_ADC Update Busy
#define    CADEN           7       // When the CADEN bit is cleared (zero), the CC-ADC is disabled. When the CADEN bit is set (one), the CC-ADC will continuously measure the voltage drop over the external sense resistor RSENSE. In Power-down, only the Regular Current detection is active. In Power-off, the CC-ADC is always disabled.

/* CADCSRB - CC-ADC Control and Status Register B */
#define    CADICIF         0       // CC-ADC Instantaneous Current Interrupt Flag
#define    CADRCIF         1       // CC-ADC Accumulate Current Interrupt Flag
#define    CADACIF         2       // CC-ADC Accumulate Current Interrupt Flag
#define    CADICIE         4       // CAD Instantenous Current Interrupt Enable
#define    CADRCIE         5       // Regular Current Interrupt Enable
#define    CADACIE         6       // 

/* CADAC3 - ADC Accumulate Current */
#define    CADAC24         0       // 
#define    CADAC25         1       // 
#define    CADAC26         2       // 
#define    CADAC27         3       // 
#define    CADAC28         4       // 
#define    CADAC29         5       // 
#define    CADAC30         6       // 
#define    CADAC31         7       // 

/* CADAC2 - ADC Accumulate Current */
#define    CADAC16         0       // 
#define    CADAC17         1       // 
#define    CADAC18         2       // 
#define    CADAC19         3       // 
#define    CADAC20         4       // 
#define    CADAC21         5       // 
#define    CADAC22         6       // 
#define    CADAC23         7       // 

/* CADAC1 - ADC Accumulate Current */
#define    CADAC08         0       // 
#define    CADAC09         1       // 
#define    CADAC10         2       // 
#define    CADAC11         3       // 
#define    CADAC12         4       // 
#define    CADAC13         5       // 
#define    CADAC14         6       // 
#define    CADAC15         7       // 

/* CADAC0 - ADC Accumulate Current */
#define    CADAC00         0       // 
#define    CADAC01         1       // 
#define    CADAC02         2       // 
#define    CADAC03         3       // 
#define    CADAC04         4       // 
#define    CADAC05         5       // 
#define    CADAC06         6       // 
#define    CADAC07         7       // 

/* CADRCC - CC-ADC Regular Charge Current */
#define    CADRCC0         0       // When the CADSE bit is written to one, the ongoing CC-ADC conversion is aborted, and the CC-ADC enters Regular Current detection mode.
#define    CADRCC1         1       // The CADSI bits determine the current sampling interval for the Regular Current detection in Power-down mode. The actual settings remain to be determined.
#define    CADRCC2         2       // The CADSI bits determine the current sampling interval for the Regular Current detection in Power-down mode. The actual settings remain to be determined.
#define    CADRCC3         3       // The CADACT bits determine the conversion time for the Accumulate Current output as shown in Table 43.
#define    CADRCC4         4       // The CADACT bits determine the conversion time for the Accumulate Current output as shown in Table 43.
#define    CADRCC5         5       // 
#define    CADRCC6         6       // 
#define    CADRCC7         7       // When the CADEN bit is cleared (zero), the CC-ADC is disabled. When the CADEN bit is set (one), the CC-ADC will continuously measure the voltage drop over the external sense resistor RSENSE. In Power-down, only the Regular Current detection is active. In Power-off, the CC-ADC is always disabled.

/* CADRDC - CC-ADC Regular Discharge Current */
#define    CADRDC0         0       // When the CADSE bit is written to one, the ongoing CC-ADC conversion is aborted, and the CC-ADC enters Regular Current detection mode.
#define    CADRDC1         1       // The CADSI bits determine the current sampling interval for the Regular Current detection in Power-down mode. The actual settings remain to be determined.
#define    CADRDC2         2       // The CADSI bits determine the current sampling interval for the Regular Current detection in Power-down mode. The actual settings remain to be determined.
#define    CADRDC3         3       // The CADACT bits determine the conversion time for the Accumulate Current output as shown in Table 43.
#define    CADRDC4         4       // The CADACT bits determine the conversion time for the Accumulate Current output as shown in Table 43.
#define    CADRDC5         5       // 
#define    CADRDC6         6       // 
#define    CADRDC7         7       // When the CADEN bit is cleared (zero), the CC-ADC is disabled. When the CADEN bit is set (one), the CC-ADC will continuously measure the voltage drop over the external sense resistor RSENSE. In Power-down, only the Regular Current detection is active. In Power-off, the CC-ADC is always disabled.


/* ***** CELL_BALANCING *************** */
/* CBCR - Cell Balancing Control Register */
#define    CBE1            0       // Battery Protection Parameter Lock
#define    CBE2            1       // Cell Balancing Enable 2
#define    CBE3            2       // Cell Balancing Enable 4
#define    CBE4            3       // Cell Balancing Enable 4


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
#define    JTD             7       // JTAG Disable

/* MCUSR - MCU Status Register */
#define    PORF            0       // Power-on reset flag
#define    EXTRF           1       // External Reset Flag
#define    BODRF           2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag
#define    JTRF            4       // JTAG Reset Flag

/* FOSCCAL - Fast Oscillator Calibration Value */
#define    FCAL0           0       // Oscillator Calibration Value Bit0
#define    FCAL1           1       // Oscillator Calibration Value Bit1
#define    FCAL2           2       // Oscillator Calibration Value Bit2
#define    FCAL3           3       // Oscillator Calibration Value Bit3
#define    FCAL4           4       // Oscillator Calibration Value Bit4
#define    FCAL5           5       // Oscillator Calibration Value Bit5
#define    FCAL6           6       // Oscillator Calibration Value Bit6
#define    FCAL7           7       // Oscillator Calibration Value Bit7

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

/* CCSR - Clock Control and Status Register */
#define    ACS             0       // Asynchronous Clock Select
#define    XOE             1       // 32 kHz Crystal Oscillator Enable

/* DIDR0 - Digital Input Disable Register */
#define    VADC0D          0       // When this bit is written logic one, the digital input buffer of the corresponding V_ADC pin is disabled.
#define    VADC1D          1       // When this bit is written logic one, the digital input buffer of the corresponding V_ADC pin is disabled.
#define    VADC2D          2       // When this bit is written logic one, the digital input buffer of the corresponding V_ADC pin is disabled.
#define    VADC3D          3       // When this bit is written logic one, the digital input buffer of the corresponding V_ADC pin is disabled.

/* PRR0 - Power Reduction Register 0 */
#define    PRVADC          0       // Power Reduction V-ADC
#define    PRTIM0          1       // Power Reduction Timer/Counter0
#define    PRTIM1          2       // Power Reduction Timer/Counter1
#define    PRTWI           3       // Power Reduction TWI


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


/* ***** TIMER_COUNTER_0 ************** */
/* TCCR0A - Timer/Counter0 Control Register */
#define    WGM00           0       // Clock Select0 bit 0
#define    WGM01           1       // Clock Select0 bit 1
#define    COM0B0          4       // 
#define    COM0B1          5       // 
#define    COM0A0          6       // Waveform Generation Mode
#define    COM0A1          7       // Force Output Compare

/* TCCR0B - Timer/Counter0 Control Register */
#define    CS00            0       // Clock Select0 bit 0
#define    CS01            1       // Clock Select0 bit 1
#define    CS02            2       // Clock Select0 bit 2
#define    WGM02           3       // 
#define    FOC0B           6       // Waveform Generation Mode
#define    FOC0A           7       // Force Output Compare

/* TCNT0 - Timer Counter 0 */
#define    TCNT00          0       // Timer Counter 0 bit 0
#define    TCNT01          1       // Timer Counter 0 bit 1
#define    TCNT02          2       // Timer Counter 0 bit 2
#define    TCNT03          3       // Timer Counter 0 bit 3
#define    TCNT04          4       // Timer Counter 0 bit 4
#define    TCNT05          5       // Timer Counter 0 bit 5
#define    TCNT06          6       // Timer Counter 0 bit 6
#define    TCNT07          7       // Timer Counter 0 bit 7

/* OCR0A - Output compare Register A */
#define    OCR0A0          0       // 
#define    OCR0A1          1       // 
#define    OCR0A2          2       // 
#define    OCR0A3          3       // 
#define    OCR0A4          4       // 
#define    OCR0A5          5       // 
#define    OCR0A6          6       // 
#define    OCR0A7          7       // 

/* OCR0B - Output compare Register B */
#define    OCR0B0          0       // 
#define    OCR0B1          1       // 
#define    OCR0B2          2       // 
#define    OCR0B3          3       // 
#define    OCR0B4          4       // 
#define    OCR0B5          5       // 
#define    OCR0B6          6       // 
#define    OCR0B7          7       // 

/* TIMSK0 - Timer/Counter Interrupt Mask Register */
#define    TOIE0           0       // Overflow Interrupt Enable
#define    OCIE0A          1       // Output Compare Interrupt Enable
#define    OCIE0B          2       // Output Compare Interrupt Enable

/* TIFR0 - Timer/Counter Interrupt Flag register */
#define    TOV0            0       // Overflow Flag
#define    OCF0A           1       // Output Compare Flag
#define    OCF0B           2       // Output Compare Flag


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


/* ***** PORTD ************************ */
/* PORTD - Data Register, Port D */
#define    PORTD0          0       // 
#define    PORTD1          1       // 

/* DDRD - Data Direction Register, Port D */
#define    DDD0            0       // 
#define    DDD1            1       // 

/* PIND - Input Pins, Port D */
#define    PIND0           0       // 
#define    PIND1           1       // 


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


/* ***** TWI ************************** */
/* TWBCSR - TWI Bus Control and Status Register */
#define    TWBCIP          0       // TWI Bus Connect/Disconnect Interrupt Polarity
#define    TWBDT0          1       // TWI Bus Disconnect Time-out Period
#define    TWBDT1          2       // TWI Bus Disconnect Time-out Period
#define    TWBCIE          6       // TWI Bus Connect/Disconnect Interrupt Enable
#define    TWBCIF          7       // TWI Bus Connect/Disconnect Interrupt Flag

/* TWAMR - TWI (Slave) Address Mask Register */
#define    TWAM0           1       // 
#define    TWAM1           2       // 
#define    TWAM2           3       // 
#define    TWAM3           4       // 
#define    TWAM4           5       // 
#define    TWAM5           6       // 
#define    TWAM6           7       // 

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


/* ***** BANDGAP ********************** */
/* BGCRR - Bandgap Calibration of Resistor Ladder */
#define    BGCR0           0       // Bandgap Calibration of Resistor Ladder Bit 0
#define    BGCR1           1       // Bandgap Calibration of Resistor Ladder Bit 1
#define    BGCR2           2       // Bandgap Calibration of Resistor Ladder Bit 2
#define    BGCR3           3       // Bandgap Calibration of Resistor Ladder Bit 3
#define    BGCR4           4       // Bandgap Calibration of Resistor Ladder Bit 4
#define    BGCR5           5       // Bandgap Calibration of Resistor Ladder Bit 5
#define    BGCR6           6       // Bandgap Calibration of Resistor Ladder Bit 6
#define    BGCR7           7       // Bandgap Calibration of Resistor Ladder Bit 7

/* BGCCR - Bandgap Calibration Register */
#define    BGCC0           0       // BG Calibration of PTAT Current Bit 0
#define    BGCC1           1       // BG Calibration of PTAT Current Bit 1
#define    BGCC2           2       // BG Calibration of PTAT Current Bit 2
#define    BGCC3           3       // BG Calibration of PTAT Current Bit 3
#define    BGCC4           4       // BG Calibration of PTAT Current Bit 4
#define    BGCC5           5       // BG Calibration of PTAT Current Bit 5
#define    BGD             7       // Setting the BGD bit to one will disable the bandgap voltage reference. This bit must be cleared before enabling CC-ADC or V-ADC, and must remain unset while either ADC is enabled.
#define    BGEN            BGD

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
#define    EEPE            1       // EEPROM Programming Enable
#define    EEWE            EEPE    // For compatibility
#define    EEMPE           2       // EEPROM Master Programming Enable
#define    EEMWE           EEMPE   // For compatibility
#define    EERIE           3       // EEPROM Ready Interrupt Enable
#define    EEPM0           4       // EEPROM Programming Mode Bits
#define    EEPM1           5       // EEPROM Programming Mode Bits

#endif

