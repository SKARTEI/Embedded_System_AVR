/*
CodeVisionAVR V3.06+ C Compiler
(C) 1998-2013 Pavel Haiduc, HP InfoTech s.r.l.

ATtiny25, ATtiny45, ATtiny85 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __TINY85_BITS_INCLUDED__
#define __TINY85_BITS_INCLUDED__

/* ***** PORTB ************************ */
/* PORTB - Data Register, Port B */
#define    PORTB0          0       // 
#define    PORTB1          1       // 
#define    PORTB2          2       // 
#define    PORTB3          3       // 
#define    PORTB4          4       // 
#define    PORTB5          5       // 

/* DDRB - Data Direction Register, Port B */
#define    DDB0            0       // 
#define    DDB1            1       // 
#define    DDB2            2       // 
#define    DDB3            3       // 
#define    DDB4            4       // 
#define    DDB5            5       // 

/* PINB - Input Pins, Port B */
#define    PINB0           0       // 
#define    PINB1           1       // 
#define    PINB2           2       // 
#define    PINB3           3       // 
#define    PINB4           4       // 
#define    PINB5           5       // 


/* ***** ANALOG_COMPARATOR ************ */
/* ADCSRB - ADC Control and Status Register B */
#define    ACME            6       // Analog Comparator Multiplexer Enable

/* ACSR - Analog Comparator Control And Status Register */
#define    ACIS0           0       // Analog Comparator Interrupt Mode Select bit 0
#define    ACIS1           1       // Analog Comparator Interrupt Mode Select bit 1
#define    ACIE            3       // Analog Comparator Interrupt Enable
#define    ACI             4       // Analog Comparator Interrupt Flag
#define    ACO             5       // Analog Compare Output
#define    ACBG            6       // Analog Comparator Bandgap Select
#define    AINBG           ACBG    // For compatibility
#define    ACD             7       // Analog Comparator Disable

/* DIDR0 -  */
#define    AIN0D           0       // AIN0 Digital Input Disable
#define    AIN1D           1       // AIN1 Digital Input Disable


/* ***** AD_CONVERTER ***************** */
/* ADMUX - The ADC multiplexer Selection Register */
#define    MUX0            0       // Analog Channel and Gain Selection Bits
#define    MUX1            1       // Analog Channel and Gain Selection Bits
#define    MUX2            2       // Analog Channel and Gain Selection Bits
#define    MUX3            3       // Analog Channel and Gain Selection Bits
#define    REFS2           4       // Reference Selection Bit 2
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
#define    IPR             5       // Input Polarity Mode
#define    BIN             7       // Bipolar Input Mode

/* DIDR0 - Digital Input Disable Register 0 */
#define    ADC1D           2       // ADC1 Digital input Disable
#define    ADC3D           3       // ADC3 Digital input Disable
#define    ADC2D           4       // ADC2 Digital input Disable
#define    ADC0D           5       // ADC0 Digital input Disable


/* ***** USI ************************** */
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


/* ***** EXTERNAL_INTERRUPT *********** */
/* MCUCR - MCU Control Register */
#define    ISC00           0       // Interrupt Sense Control 0 Bit 0
#define    ISC01           1       // Interrupt Sense Control 0 Bit 1

/* GIMSK - General Interrupt Mask Register */
#define    GICR            GIMSK   // For compatibility
#define    PCIE            5       // Pin Change Interrupt Enable
#define    INT0            6       // External Interrupt Request 0 Enable

/* GIFR - General Interrupt Flag register */
#define    PCIF            5       // Pin Change Interrupt Flag
#define    INTF0           6       // External Interrupt Flag 0

/* PCMSK - Pin Change Enable Mask */
#define    PCINT0          0       // Pin Change Enable Mask Bit 0
#define    PCINT1          1       // Pin Change Enable Mask Bit 1
#define    PCINT2          2       // Pin Change Enable Mask Bit 2
#define    PCINT3          3       // Pin Change Enable Mask Bit 3
#define    PCINT4          4       // Pin Change Enable Mask Bit 4
#define    PCINT5          5       // Pin Change Enable Mask Bit 5


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


/* ***** TIMER_COUNTER_0 ************** */
/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TOIE0           1       // Timer/Counter0 Overflow Interrupt Enable
#define    OCIE0B          3       // Timer/Counter0 Output Compare Match B Interrupt Enable
#define    OCIE0A          4       // Timer/Counter0 Output Compare Match A Interrupt Enable

/* TIFR - Timer/Counter0 Interrupt Flag register */
#define    TOV0            1       // Timer/Counter0 Overflow Flag
#define    OCF0B           3       // Timer/Counter0 Output Compare Flag 0B
#define    OCF0A           4       // Timer/Counter0 Output Compare Flag 0A

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
#define    OCR0_0          0       // 
#define    OCR0_1          1       // 
#define    OCR0_2          2       // 
#define    OCR0_3          3       // 
#define    OCR0_4          4       // 
#define    OCR0_5          5       // 
#define    OCR0_6          6       // 
#define    OCR0_7          7       // 

/* OCR0B - Timer/Counter0 Output Compare Register */
//#define  OCR0_0          0       // 
//#define  OCR0_1          1       // 
//#define  OCR0_2          2       // 
//#define  OCR0_3          3       // 
//#define  OCR0_4          4       // 
//#define  OCR0_5          5       // 
//#define  OCR0_6          6       // 
//#define  OCR0_7          7       // 

/* GTCCR - General Timer/Counter Control Register */
#define    PSR0            0       // Prescaler Reset Timer/Counter1 and Timer/Counter0
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** TIMER_COUNTER_1 ************** */
/* TCCR1 - Timer/Counter Control Register */
#define    CS10            0       // Clock Select Bits
#define    CS11            1       // Clock Select Bits
#define    CS12            2       // Clock Select Bits
#define    CS13            3       // Clock Select Bits
#define    COM1A0          4       // Compare Output Mode, Bit 1
#define    COM1A1          5       // Compare Output Mode, Bit 0
#define    PWM1A           6       // Pulse Width Modulator Enable
#define    CTC1            7       // Clear Timer/Counter on Compare Match

/* TCNT1 - Timer/Counter Register */
#define    TCNT1_0         0       // Timer/Counter Register Bit 0
#define    TCNT1_1         1       // Timer/Counter Register Bit 1
#define    TCNT1_2         2       // Timer/Counter Register Bit 2
#define    TCNT1_3         3       // Timer/Counter Register Bit 3
#define    TCNT1_4         4       // Timer/Counter Register Bit 4
#define    TCNT1_5         5       // Timer/Counter Register Bit 5
#define    TCNT1_6         6       // Timer/Counter Register Bit 6
#define    TCNT1_7         7       // Timer/Counter Register Bit 7

/* OCR1A - Output Compare Register */
#define    OCR1A0          0       // Output Compare Register A Bit 0
#define    OCR1A1          1       // Output Compare Register A Bit 1
#define    OCR1A2          2       // Output Compare Register A Bit 2
#define    OCR1A3          3       // Output Compare Register A Bit 3
#define    OCR1A4          4       // Output Compare Register A Bit 4
#define    OCR1A5          5       // Output Compare Register A Bit 5
#define    OCR1A6          6       // Output Compare Register A Bit 6
#define    OCR1A7          7       // Output Compare Register A Bit 7

/* OCR1B - Output Compare Register */
#define    OCR1B0          0       // Output Compare Register B Bit 0
#define    OCR1B1          1       // Output Compare Register B Bit 1
#define    OCR1B2          2       // Output Compare Register B Bit 2
#define    OCR1B3          3       // Output Compare Register B Bit 3
#define    OCR1B4          4       // Output Compare Register B Bit 4
#define    OCR1B5          5       // Output Compare Register B Bit 5
#define    OCR1B6          6       // Output Compare Register B Bit 6
#define    OCR1B7          7       // Output Compare Register B Bit 7

/* OCR1C - Output compare register */
#define    OCR1C0          0       // 
#define    OCR1C1          1       // 
#define    OCR1C2          2       // 
#define    OCR1C3          3       // 
#define    OCR1C4          4       // 
#define    OCR1C5          5       // 
#define    OCR1C6          6       // 
#define    OCR1C7          7       // 

/* TIMSK - Timer/Counter Interrupt Mask Register */
#define    TOIE1           2       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1B          5       // OCIE1A: Timer/Counter1 Output Compare B Interrupt Enable
#define    OCIE1A          6       // OCIE1A: Timer/Counter1 Output Compare Interrupt Enable

/* TIFR - Timer/Counter Interrupt Flag Register */
#define    TOV1            2       // Timer/Counter1 Overflow Flag
#define    OCF1B           5       // Timer/Counter1 Output Compare Flag 1B
#define    OCF1A           6       // Timer/Counter1 Output Compare Flag 1A

/* GTCCR - Timer counter control register */
#define    PSR1            1       // Prescaler Reset Timer/Counter1
#define    FOC1A           2       // Force Output Compare 1A
#define    FOC1B           3       // Force Output Compare Match 1B
#define    COM1B0          4       // Comparator B Output Mode
#define    COM1B1          5       // Comparator B Output Mode
#define    PWM1B           6       // Pulse Width Modulator B Enable

/* DTPS1 - Dead time prescaler register */
#define    DTPS10          0        
#define    DTPS11          1        

/* DT1A - Dead time value register */
#define    DT1AL0          0        
#define    DT1AL1          1        
#define    DT1AL2          2        
#define    DT1AL3          3        
#define    DT1AH0          4        
#define    DT1AH1          5        
#define    DT1AH2          6        
#define    DT1AH3          7        

/* DT1B - Dead time value B */
#define    DT1BL0          0        
#define    DT1BL1          1        
#define    DT1BL2          2        
#define    DT1BL3          3        
#define    DT1BH0          4        
#define    DT1BH1          5        
#define    DT1BH2          6        
#define    DT1BH3          7        


/* ***** BOOT_LOAD ******************** */
/* SPMCSR - Store Program Memory Control Register */
#define    SPMEN           0       // Store Program Memory Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    RFLB            3       // Read fuse and lock bits
#define    CTPB            4       // Clear temporary page buffer


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
//#define  ISC00           0       // Interrupt Sense Control 0 bit 0
//#define  ISC01           1       // Interrupt Sense Control 0 bit 1
#define    SM0             3       // Sleep Mode Select Bit 0
#define    SM1             4       // Sleep Mode Select Bit 1
#define    SE              5       // Sleep Enable
#define    PUD             6       // Pull-up Disable

/* MCUSR - MCU Status register */
#define    PORF            0       // Power-On Reset Flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag

/* PRR - Power Reduction Register */
#define    PRADC           0       // Power Reduction ADC
#define    PRUSI           1       // Power Reduction USI
#define    PRTIM0          2       // Power Reduction Timer/Counter0
#define    PRTIM1          3       // Power Reduction Timer/Counter1

/* OSCCAL - Oscillator Calibration Register */
#define    CAL0            0       // Oscillatro Calibration Value Bit 0
#define    CAL1            1       // Oscillatro Calibration Value Bit 1
#define    CAL2            2       // Oscillatro Calibration Value Bit 2
#define    CAL3            3       // Oscillatro Calibration Value Bit 3
#define    CAL4            4       // Oscillatro Calibration Value Bit 4
#define    CAL5            5       // Oscillatro Calibration Value Bit 5
#define    CAL6            6       // Oscillatro Calibration Value Bit 6
#define    CAL7            7       // Oscillatro Calibration Value Bit 7

/* PLLCSR - PLL Control and status register */
#define    PLOCK           0       // PLL Lock detector
#define    PLLE            1       // PLL Enable
#define    PCKE            2       // PCK Enable
#define    LSM             7       // Low speed mode

/* CLKPR - Clock Prescale Register */
#define    CLKPS0          0       // Clock Prescaler Select Bit 0
#define    CLKPS1          1       // Clock Prescaler Select Bit 1
#define    CLKPS2          2       // Clock Prescaler Select Bit 2
#define    CLKPS3          3       // Clock Prescaler Select Bit 3
#define    CLKPCE          7       // Clock Prescaler Change Enable

/* DWDR - debugWire data register */
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

#endif

