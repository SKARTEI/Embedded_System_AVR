/*
CodeVisionAVR V2.04.5 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATtiny5, ATtiny10 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __TINY10_BITS_INCLUDED__
#define __TINY10_BITS_INCLUDED__


/* ***** AD_CONVERTER ***************** */
/* ADMUX - The ADC multiplexer Selection Register */
#define    MUX0            0       // Analog Channel Selection Bits
#define    MUX1            1       // Analog Channel Selection Bits

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

/* ADCL - ADC Data Register */
#define    ADC0            0       // ADC Data Register Bit 0
#define    ADC1            1       // ADC Data Register Bit 1
#define    ADC2            2       // ADC Data Register Bit 2
#define    ADC3            3       // ADC Data Register Bit 3
#define    ADC4            4       // ADC Data Register Bit 4
#define    ADC5            5       // ADC Data Register Bit 5
#define    ADC6            6       // ADC Data Register Bit 6
#define    ADC7            7       // ADC Data Register Bit 7

/* DIDR0 - Digital Input Disable Register */
#define    ADC0D           0       //
#define    ADC1D           1       //
#define    ADC2D           2       //
#define    ADC3D           3       //


/* ***** ANALOG_COMPARATOR ************ */
/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIC            2       // Analog Comparator Input Capture  Enable
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Compare Output
#define    ACD             7       // Analog Comparator Disable

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

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 0

/* PCMSK - Pin Change Mask Register */
#define    PCINT0          0       // Pin Change Enable Mask 0
#define    PCINT1          1       // Pin Change Enable Mask 1
#define    PCINT2          2       // Pin Change Enable Mask 2
#define    PCINT3          3       // Pin Change Enable Mask 3


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

