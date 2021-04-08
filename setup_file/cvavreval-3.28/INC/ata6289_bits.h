/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATA6285, ATA6286, ATA6289 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __ATA6289_BITS_INCLUDED__
#define __ATA6289_BITS_INCLUDED__

/* ***** SENSOR_INTERFACE ************* */
/* SCR - Sensor Control Register */
#define    SMS             0       // Sensor Measurement Start Bit
#define    SEN0            1       // Sensor enable Bit 0
#define    SEN1            2       // Sensor enable Bit 1
#define    SMEN            3       // Sensor Motion Enable Bit

/* MSVCAL - Motion Sensor Voltage Calibration Register */
#define    VRCAL0          0       // Voltage Reference Calibration Bit 0
#define    VRCAL1          1       // Voltage Reference Calibration Bit 1
#define    VRCAL2          2       // Voltage Reference Calibration Bit 2
#define    VRCAL3          3       // Voltage Reference Calibration Bit 3
#define    VRCAL4          4       // Voltage Reference Calibration Bit 4
#define    VRCAL5          5       // Voltage Reference Calibration Bit 5
#define    VRCAL6          6       // Voltage Reference Calibration Bit 6
#define    VRCAL7          7       // Voltage Reference Calibration Bit 7

/* SCCR - Sensor Capacitor Control Register */
#define    SRCC0           0       // Sensor Reference Charge Current Bit0
#define    SRCC1           1       // Sensor Reference Charge Current Bit1
#define    SCCS0           2       // Sensor Capacitor Channel Select Bit0
#define    SCCS1           3       // Sensor Capacitor Channel Select Bit1
#define    SCCS2           4       // Sensor Capacitor Channel Select Bit2

/* SVCR - Sensor Voltage Control Register */
#define    SVCS0           0       // Sensor Voltage Channel Select Bit0
#define    SVCS1           1       // Sensor Voltage Channel Select Bit1
#define    SVCS2           2       // Sensor Voltage Channel Select Bit2
#define    SVCS3           3       // Sensor Voltage Channel Select Bit3
#define    SVCS4           4       // Sensor Voltage Channel Select Bit4

/* SIMSK - Sensor Interrupt Mask register */
#define    MSIE            0       // Motion Sensor Interrupt Enable Bit

/* SSFR - Sensor Status + Flag Register */
#define    MSENF           0       // Motion Sensor Flag
#define    MSENO           1       // Motion Sensor Output

/* TSCR - Temperature Sensor Control Register */
#define    TSSD            0       // Temperature Sensor Shutdown mode Disable


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


/* ***** CPU ************************** */
/* CLKPR - Clock Prescaler Register */
#define    CLKPS0          0       // Clock system Prescaler Select Bit 0
#define    CLKPS1          1       // Clock system Prescaler Select Bit 1
#define    CLKPS2          2       // Clock system Prescaler Select Bit 2
#define    CLTPS0          3       // Clock Timer Prescaler Select Bit 0
#define    CLTPS1          4       // Clock Timer Prescaler Select Bit 1
#define    CLTPS2          5       // Clock Timer Prescaler Select Bit 2
#define    CLPCE           7       // Clock Prescaler Change Enable Bit

/* CMCR - Clock Management Control Register */
#define    CMM0            0       // Clock Management Mode Bits 0
#define    CMM1            1       // Clock Management Mode Bits 1
#define    SRCD            2       // Slow RC-oscillator Disable Bit
#define    CMONEN          3       // Clock Monitoring Enable
#define    CCS             4       // Core Clock Select Bit
#define    ECINS           5       // External Clock Input Select Bit
#define    CMCCE           7       // Clock Management Control Change Enable Bit

/* CMSR - Clock Management Status Register */
#define    ECF             0       // External Clock input Flag Bit

/* CMIMR - Clock Management Interrupt Mask Register */
#define    ECIE            0       // External Clock input Interrupt Enable Bit

/* FRCCAL - FRC-Oscillator Calibration Register */
#define    FCAL0           0       // FRC-Oscillator Calibration Register Bit0
#define    FCAL1           1       // FRC-Oscillator Calibration Register Bit1
#define    FCAL2           2       // FRC-Oscillator Calibration Register Bit2
#define    FCAL3           3       // FRC-Oscillator Calibration Register Bit3
#define    FCAL4           4       // FRC-Oscillator Calibration Register Bit4
#define    FCAL5           5       // FRC-Oscillator Calibration Register Bit5
#define    FCAL6           6       // FRC-Oscillator Calibration Register Bit6
#define    FCAL7           7       // FRC-Oscillator Calibration Register Bit7

/* SRCCAL - SRC-Oscillator Calibration Register */
#define    SCAL0           0       // SRC-Oscillator Calibration Register Bit0
#define    SCAL1           1       // SRC-Oscillator Calibration Register Bit1
#define    SCAL2           2       // SRC-Oscillator Calibration Register Bit2
#define    SCAL3           3       // SRC-Oscillator Calibration Register Bit3
#define    SCAL4           4       // SRC-Oscillator Calibration Register Bit4
#define    SCAL5           5       // SRC-Oscillator Calibration Register Bit5
#define    SCAL6           6       // SRC-Oscillator Calibration Register Bit6
#define    SCAL7           7       // SRC-Oscillator Calibration Register Bit7

/* VMCSR - Voltage Monitor Control and Status Register */
#define    VMEN            0       // Voltage Monitor Enable Bit
#define    VMLS0           1       // Voltage Monitor Level Select Bit 0
#define    VMLS1           2       // Voltage Monitor Level Select Bit 1
#define    VMLS2           3       // Voltage Monitor Level Select Bit 2
#define    VMIM            4       // Voltage Monitor Interrupt Mask Bit
#define    VMF             5       // Voltage Monitor Flag
#define    BODPD           6       // Brown-Out Detection on Power-Down Bit
#define    BODLS           7       // Brown-Out Detection Level Select Bit

/* SREG - Status Register */
#define    SREG_C          0       // Carry Flag
#define    SREG_Z          1       // Zero Flag
#define    SREG_N          2       // Negative Flag
#define    SREG_V          3       // Two's Complement Overflow Flag
#define    SREG_S          4       // Sign Bit
#define    SREG_H          5       // Half Carry Flag
#define    SREG_T          6       // Bit Copy Storage
#define    SREG_I          7       // Global Interrupt Enable

/* SPMCSR - Store Program Memory Control Register */
#define    SELFPRGEN       0       // Self Programming Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    BLBSET          3       // Boot Lock Bit Set
#define    RWWSRE          4       // Read-While-Write section read enable
#define    RWWSB           6       // Read-While-Write Section Busy
#define    SPMIE           7       // SPM Interrupt Enable

/* MCUCR - MCU Control Register */
#define    IVCE            0       // Interrupt Vector Change Enable
#define    IVSEL           1       // Interrupt Vector Select
#define    PUD             4       // 

/* MCUSR - MCU Status Register */
#define    PORF            0       // Power-on reset flag
#define    EXTRF           1       // External Reset Flag
#define    EXTREF          EXTRF   // For compatibility
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag
#define    TSRF            5       // Temperature Shutdown Reset Flag

/* SMCR - Sleep Mode Control Register */
#define    SE              0       // 
#define    SM0             1       // 
#define    SM1             2       // 
#define    SM2             3       // 

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


/* ***** LFRX ************************* */
/* LFRCR - Low Frequency Receiver Control Register */
#define    LFEN            0       // LF receiver Enable Bit
#define    LFBM            1       // LF receiver Burst Mode enable Bit
#define    LFWM0           2       // LF receiver Wake-up Mode Bit 0
#define    LFWM1           3       // LF receiver Wake-up Mode Bit 1
#define    LFRSS           4       // LF Receiver Sensitivity Select Bit
#define    LFCS0           5       // LF receiver Capacitor Select Bit 0
#define    LFCS1           6       // LF receiver Capacitor Select Bit 1
#define    LFCS2           7       // LF receiver Capacitor Select Bit 2

/* LFCDR - LF receiver Control und Data Register */
#define    LFDO            0       // LF receiver Data Output Bit
#define    LFRST           6       // LF receiver Reset Bit
#define    LFSCE           7       // LF receiver RSSI Software Capture Enable Bit

/* LFRB - Low Frequency Receive data Buffer */
#define    LFRB0           0       // 
#define    LFRB1           1       // 
#define    LFRB2           2       // 
#define    LFRB3           3       // 
#define    LFRB4           4       // 
#define    LFRB5           5       // 
#define    LFRB6           6       // 
#define    LFRB7           7       // 

/* LFRR - LF RSSI Data Register */
#define    LFRR0           0       // 
#define    LFRR1           1       // 
#define    LFRR2           2       // 
#define    LFRR3           3       // 
#define    LFRR4           4       // 
#define    LFRR5           5       // 
#define    LFRR6           6       // 

/* LFHCR - LF Header Compare Register */
#define    LFHCR0          0       // 
#define    LFHCR1          1       // 
#define    LFHCR2          2       // 
#define    LFHCR3          3       // 
#define    LFHCR4          4       // 
#define    LFHCR5          5       // 
#define    LFHCR6          6       // 

/* LFIDCH - LF ID Compare Register High */
#define    LFIDCH_8        0       // 
#define    LFIDCH_9        1       // 
#define    LFIDCH_10       2       // 
#define    LFIDCH_11       3       // 
#define    LFIDCH_12       4       // 
#define    LFIDCH_13       5       // 
#define    LFIDCH_14       6       // 
#define    LFIDCH_15       7       // 

/* LFIDCL - LF ID Compare Register Low */
#define    LFIDCL_0        0       // 
#define    LFIDCL_1        1       // 
#define    LFIDCL_2        2       // 
#define    LFIDCL_3        3       // 
#define    LFIDCL_4        4       // 
#define    LFIDCL_5        5       // 
#define    LFIDCL_6        6       // 
#define    LFIDCL_7        7       // 

/* LFIMR - Low Frequency Interrupt Mask Register */
#define    LFWIM           0       // LF receiver Wake-up Interrupt Mask bit
#define    LFBIM           1       // LF receiver data Buffer Interrupt Mask bit
#define    LFEIM           2       // LF receiver End of data Interrupt Mask bit

/* LFFR - Low Frequency Flag Register */
#define    LFWPF           0       // LF receiver Wake-up Flag
#define    LFBF            1       // LF receiver data Buffer full Flag
#define    LFEDF           2       // LF receiver End of data Flag
#define    LFRF            3       // LF receiver Rssi data Flag

/* LFCALH - LF Calibration Register High Byte */
#define    LFCAL_08        0       // 
#define    LFCAL_09        1       // 
#define    LFCAL_10        2       // 
#define    LFCAL_11        3       // 
#define    LFCAL_12        4       // 
#define    LFCAL_13        5       // 
#define    LFCAL_14        6       // 
#define    LFCAL_15        7       // 

/* LFCALL - LF Calibration Register Low Byte */
#define    LFCAL_00        0       // 
#define    LFCAL_01        1       // 
#define    LFCAL_02        2       // 
#define    LFCAL_03        3       // 
#define    LFCAL_04        4       // 
#define    LFCAL_05        5       // 
#define    LFCAL_06        6       // 
#define    LFCAL_07        7       // 


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
#define    PCINT8          0       // Pin Change Enable Mask 8
#define    PCINT9          1       // Pin Change Enable Mask 9
#define    PCINT10         2       // Pin Change Enable Mask 10

/* PCMSK2 - Pin Change Mask Register 2 */
#define    PCINT16         0       // Pin Change Enable Mask 16
#define    PCINT17         1       // Pin Change Enable Mask 17
#define    PCINT18         2       // Pin Change Enable Mask 18
#define    PCINT19         3       // Pin Change Enable Mask 19
#define    PCINT20         4       // Pin Change Enable Mask 20
#define    PCINT21         5       // Pin Change Enable Mask 21
#define    PCINT22         6       // Pin Change Enable Mask 22
#define    PCINT23         7       // Pin Change Enable Mask 23

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 0
#define    PCIF1           1       // Pin Change Interrupt Flag 1
#define    PCIF2           2       // Pin Change Interrupt Flag 2

/* PCICR - Pin Change Interrupt Control Register */
#define    PCIE0           0       // Pin Change Interrupt Enable 0
#define    PCIE1           1       // Pin Change Interrupt Enable 1
#define    PCIE2           2       // Pin Change Interrupt Enable 2


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

/* PINC - Port C Input Pins */
#define    PINC0           0       // Port C Input pin 0
#define    PINC1           1       // Port C Input pin 1


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


/* ***** TIMER_COUNTER_1 ************** */
/* T1CR - Timer 1 Control Register */
#define    T1PS0           0       // Timer 1 Prescaler Select Bit 0
#define    T1PS1           1       // Timer 1 Prescaler Select Bit 1
#define    T1PS2           2       // Timer 1 Prescaler Select Bit 2
#define    T1CS0           3       // Timer 1 Clock Select Bit 0
#define    T1CS1           4       // Timer 1 Clock Select Bit 1
#define    T1CS2           5       // Timer 1 Clock Select Bit 2
#define    T1IE            7       // Timer 1 Interrupt Enable Bit

/* T10IFR - Timer1/0 Interrupt Flag Register */
#define    T0F             0       // Timer 0 Flag Bit
#define    T1F             1       // Timer 1 Flag Bit


/* ***** TIMER_COUNTER_2 ************** */
/* T2CRA - Timer 2 Control Register A */
#define    T2OTM           0       // Timer 2 Overflow Toggle Mask Bit
#define    T2CTM           1       // Timer 2 Compare Toggle Mask Bit
#define    T2CR            2       // Timer2 Counter Reset
#define    T2CRM           3       // Timer 2 Compare Reset Mask Bit
#define    T2CPRM          4       // Timer 2 Capture Reset Mask bit
#define    T2ICS           5       // Timer Input Capture Select Bit
#define    T2TS            6       // Timer 2 Toggle with Start Bit
#define    T2E             7       // Timer 2 Enable Bit

/* T2CRB - Timer 2 Control Register B */
#define    T2SCE           0       // Timer 2 Software Capture Enable Bit

/* T2MDR - Timer 2 Modulator Data Register */
#define    T2MDR0          0       // Timer 2 Modulator Data Register Bit0
#define    T2MDR1          1       // Timer 2 Modulator Data Register Bit1
#define    T2MDR2          2       // Timer 2 Modulator Data Register Bit2
#define    T2MDR3          3       // Timer 2 Modulator Data Register Bit3
#define    T2MDR4          4       // Timer 2 Modulator Data Register Bit4
#define    T2MDR5          5       // Timer 2 Modulator Data Register Bit5
#define    T2MDR6          6       // Timer 2 Modulator Data Register Bit6
#define    T2MDR7          7       // Timer 2 Modulator Data Register Bit7

/* T2ICRH - Timer 2 Input Capture Register High Byte */
#define    T2ICRH0         0       // Timer 2 Input Capture Register High Byte Bit 0
#define    T2ICRH1         1       // Timer 2 Input Capture Register High Byte Bit 1
#define    T2ICRH2         2       // Timer 2 Input Capture Register High Byte Bit 2
#define    T2ICRH3         3       // Timer 2 Input Capture Register High Byte Bit 3
#define    T2ICRH4         4       // Timer 2 Input Capture Register High Byte Bit 4
#define    T2ICRH5         5       // Timer 2 Input Capture Register High Byte Bit 5
#define    T2ICRH6         6       // Timer 2 Input Capture Register High Byte Bit 6
#define    T2ICRH7         7       // Timer 2 Input Capture Register High Byte Bit 7

/* T2ICRL - Timer 2 Input Capture Register Low Byte */
#define    T2ICRL0         0       // Timer 2 Input Capture Register Low Byte Bit 0
#define    T2ICRL1         1       // Timer 2 Input Capture Register Low Byte Bit 1
#define    T2ICRL2         2       // Timer 2 Input Capture Register Low Byte Bit 2
#define    T2ICRL3         3       // Timer 2 Input Capture Register Low Byte Bit 3
#define    T2ICRL4         4       // Timer 2 Input Capture Register Low Byte Bit 4
#define    T2ICRL5         5       // Timer 2 Input Capture Register Low Byte Bit 5
#define    T2ICRL6         6       // Timer 2 Input Capture Register Low Byte Bit 6
#define    T2ICRL7         7       // Timer 2 Input Capture Register Low Byte Bit 7

/* T2CORH - Timer2 Compare Register High Byte */
#define    T2CORH0         0       // Timer2 Compare Register High Byte Bit 0
#define    T2CORH1         1       // Timer2 Compare Register High Byte Bit 1
#define    T2CORH2         2       // Timer2 Compare Register High Byte Bit 2
#define    T2CORH3         3       // Timer2 Compare Register High Byte Bit 3
#define    T2CORH4         4       // Timer2 Compare Register High Byte Bit 4
#define    T2CORH5         5       // Timer2 Compare Register High Byte Bit 5
#define    T2CORH6         6       // Timer2 Compare Register High Byte Bit 6
#define    T2CORH7         7       // Timer2 Compare Register High Byte Bit 7

/* T2CORL - Timer2 Compare Register Low Byte */
#define    T2CORL0         0       // Timer2 Compare Register Low Byte Bit 0
#define    T2CORL1         1       // Timer2 Compare Register Low Byte Bit 1
#define    T2CORL2         2       // Timer2 Compare Register Low Byte Bit 2
#define    T2CORL3         3       // Timer2 Compare Register Low Byte Bit 3
#define    T2CORL4         4       // Timer2 Compare Register Low Byte Bit 4
#define    T2CORL5         5       // Timer2 Compare Register Low Byte Bit 5
#define    T2CORL6         6       // Timer2 Compare Register Low Byte Bit 6
#define    T2CORL7         7       // Timer2 Compare Register Low Byte Bit 7

/* T2IFR - Timer2 Interrupt Flag Register */
#define    T2OFF           0       // Timer 2 Overflow Flag Bit
#define    T2COF           1       // Timer 2 Compare Flag Bit
#define    T2ICF           2       // Timer2 Input Capture Flag Bit
#define    T2RXF           3       // Timer2 SSI Receive Flag Bit
#define    T2TXF           4       // Timer2 SSI Transmit Flag Bit
#define    T2TCF           5       // Timer2 SSI Transmit Complete Flag Bit

/* T2IMR - Timer 2 Interrupt Mask Register */
#define    T2OIM           0       // Timer 2 Overflow Interrupt Mask Bit
#define    T2CIM           1       // Timer 2 Compare Interrupt Mask Bit
#define    T2CPIM          2       // Timer 2 Capture Interrupt Mask Bit
#define    T2RXIM          3       // Timer2 SSI Receive Interrupt Mask Bit
#define    T2TXIM          4       // Timer2 SSI Transmit Interrupt Mask Bit
#define    T2TCIM          5       // Timer2 SSI Transmit Complete Interrupt Mask Bit

/* T2MRA - Timer 2 Mode Register A */
#define    T2CS0           0       // Timer 2 Clock Select Bit 0
#define    T2CS1           1       // Timer 2 Clock Select Bit 1
#define    T2CS2           2       // Timer 2 Clock Select Bit 2
#define    T2CE0           3       // Timer 2 Capture Edge Select Bit 0
#define    T2CE1           4       // Timer 2 Capture Edge Select Bit 1
#define    T2CNC           5       // Timer 2 Input Capture Noise Canceler Bit
#define    T2TP0           6       // Timer 2 Top select Bit 0
#define    T2TP1           7       // Timer 2 Top select Bit 1

/* T2MRB - Timer 2 Mode Register B */
#define    T2M0            0       // Timer 2 Mode Bit 0
#define    T2M1            1       // Timer 2 Mode Bit 1
#define    T2M2            2       // Timer 2 Mode Bit 2
#define    T2M3            3       // Timer 2 Mode Bit 3
#define    T2TOP           4       // Timer 2 Toggle Output Preset Bit
#define    T2CPOL          6       // Timer2 Clock Polarity for SSI shift clock
#define    T2SSIE          7       // Timer 2 SSI Enable Bit


/* ***** TIMER_COUNTER_3 ************** */
/* T3CRA - Timer 3 Control Register A */
#define    T3AC            0       // Timer 3 Alternate Compare register sequence bit
#define    T3SCE           1       // Timer 3 Software Capture Enable Bit
#define    T3CR            2       // Timer3 Counter Reset
#define    T3TS            6       // Timer 3 Toggle with Start Bit
#define    T3E             7       // Timer 3 Enable Bit

/* T3CRB - Timer 3 Control Register B */
#define    T3CTMA          0       // Timer 3 Compare Toggle Mask bit A
#define    T3SAMA          1       // Timer 3 Single Action Mask bit A
#define    T3CRMA          2       // Timer 3 Compare Reset Mask bit A
#define    T3CTMB          3       // Timer 3 Compare Toggle Mask bit B
#define    T3SAMB          4       // Timer 3 Single Action Mask bit B
#define    T3CRMB          5       // Timer 3 Compare Reset Mask bit B
#define    T3CPRM          6       // Timer 3 CaPture Reset Mask bit

/* T3MRA - Timer 3 Mode Register A */
#define    T3CS0           0       // Timer 3 Clock Select Bit 0
#define    T3CS1           1       // Timer 3 Clock Select Bit 1
#define    T3CS2           2       // Timer 3 Clock Select Bit 2
#define    T3CE0           3       // Timer 3 Capture Edge select Bit 0
#define    T3CE1           4       // Timer 3 Capture Edge select Bit 1
#define    T3CNC           5       // Timer 3 input Capture Noise Canceler Bit
#define    T3ICS0          6       // Timer 3 Input Capture Select Bit 0
#define    T3ICS1          7       // Timer 3 Input Capture Select Bit 1

/* T3IFR - Timer3 Interrupt Flag Register */
#define    T3OFF           0       // Timer3 OverFlow Flag bit
#define    T3COAF          1       // Timer3 Compare A Flag bit
#define    T3COBF          2       // Timer3 Compare B Flag bit
#define    T3ICF           3       // Timer3 Input Capture Flag bit

/* T3IMR - Timer3 Interrupt Mask Register */
#define    T3OIM           0       // Timer3 Overflow Interrupt Mask bit
#define    T3CAIM          1       // Timer3 Compare A Interrupt Mask bit
#define    T3CBIM          2       // Timer3 Compare B Interrupt Mask bit
#define    T3CPIM          3       // Timer3 Capture Interrupt Mask bit

/* T3MRB - Timer 3 Mode Register B */
#define    T3M0            0       // Timer 3 Mode Bit 0
#define    T3M1            1       // Timer 3 Mode Bit 1
#define    T3M2            2       // Timer 3 Mode Bit 2
#define    T3TOP           4       // Timer 3 Toggle Output Preset Bit

/* T3ICRH - Timer3 Input Capture Register High Byte */
#define    T3ICRH0         0       // Timer3 Input Capture Register High Byte Bit 0
#define    T3ICRH1         1       // Timer3 Input Capture Register High Byte Bit 1
#define    T3ICRH2         2       // Timer3 Input Capture Register High Byte Bit 2
#define    T3ICRH3         3       // Timer3 Input Capture Register High Byte Bit 3
#define    T3ICRH4         4       // Timer3 Input Capture Register High Byte Bit 4
#define    T3ICRH5         5       // Timer3 Input Capture Register High Byte Bit 5
#define    T3ICRH6         6       // Timer3 Input Capture Register High Byte Bit 6
#define    T3ICRH7         7       // Timer3 Input Capture Register High Byte Bit 7

/* T3ICRL - Timer3 Input Capture Register Low Byte */
#define    T3ICRL0         0       // Timer3 Input Capture Register Low Byte Bit 0
#define    T3ICRL1         1       // Timer3 Input Capture Register Low Byte Bit 1
#define    T3ICRL2         2       // Timer3 Input Capture Register Low Byte Bit 2
#define    T3ICRL3         3       // Timer3 Input Capture Register Low Byte Bit 3
#define    T3ICRL4         4       // Timer3 Input Capture Register Low Byte Bit 4
#define    T3ICRL5         5       // Timer3 Input Capture Register Low Byte Bit 5
#define    T3ICRL6         6       // Timer3 Input Capture Register Low Byte Bit 6
#define    T3ICRL7         7       // Timer3 Input Capture Register Low Byte Bit 7

/* T3CORAH - Timer3 COmpare Register A High Byte */
#define    T3CORAH0        0       // Timer3 COmpare Register A High Byte Bit 0
#define    T3CORAH1        1       // Timer3 COmpare Register A High Byte Bit 1
#define    T3CORAH2        2       // Timer3 COmpare Register A High Byte Bit 2
#define    T3CORAH3        3       // Timer3 COmpare Register A High Byte Bit 3
#define    T3CORAH4        4       // Timer3 COmpare Register A High Byte Bit 4
#define    T3CORAH5        5       // Timer3 COmpare Register A High Byte Bit 5
#define    T3CORAH6        6       // Timer3 COmpare Register A High Byte Bit 6
#define    T3CORAH7        7       // Timer3 COmpare Register A High Byte Bit 7

/* T3CORAL - Timer3 COmpare Register A Low Byte */
#define    T3CORAL0        0       // Timer3 COmpare Register A Low Byte Bit 0
#define    T3CORAL1        1       // Timer3 COmpare Register A Low Byte Bit 1
#define    T3CORAL2        2       // Timer3 COmpare Register A Low Byte Bit 2
#define    T3CORAL3        3       // Timer3 COmpare Register A Low Byte Bit 3
#define    T3CORAL4        4       // Timer3 COmpare Register A Low Byte Bit 4
#define    T3CORAL5        5       // Timer3 COmpare Register A Low Byte Bit 5
#define    T3CORAL6        6       // Timer3 COmpare Register A Low Byte Bit 6
#define    T3CORAL7        7       // Timer3 COmpare Register A Low Byte Bit 7

/* T3CORBH - Timer3 COmpare Register B High Byte */
#define    T3CORBH0        0       // Timer3 COmpare Register B High Byte Bit 0
#define    T3CORBH1        1       // Timer3 COmpare Register B High Byte Bit 1
#define    T3CORBH2        2       // Timer3 COmpare Register B High Byte Bit 2
#define    T3CORBH3        3       // Timer3 COmpare Register B High Byte Bit 3
#define    T3CORBH4        4       // Timer3 COmpare Register B High Byte Bit 4
#define    T3CORBH5        5       // Timer3 COmpare Register B High Byte Bit 5
#define    T3CORBH6        6       // Timer3 COmpare Register B High Byte Bit 6
#define    T3CORBH7        7       // Timer3 COmpare Register B High Byte Bit 7

/* T3CORBL - Timer3 COmpare Register B Low Byte */
#define    T3CORBL0        0       // Timer3 COmpare Register B Low Byte Bit 0
#define    T3CORBL1        1       // Timer3 COmpare Register B Low Byte Bit 1
#define    T3CORBL2        2       // Timer3 COmpare Register B Low Byte Bit 2
#define    T3CORBL3        3       // Timer3 COmpare Register B Low Byte Bit 3
#define    T3CORBL4        4       // Timer3 COmpare Register B Low Byte Bit 4
#define    T3CORBL5        5       // Timer3 COmpare Register B Low Byte Bit 5
#define    T3CORBL6        6       // Timer3 COmpare Register B Low Byte Bit 6
#define    T3CORBL7        7       // Timer3 COmpare Register B Low Byte Bit 7


/* ***** WATCHDOG ********************* */
/* WDTCR - Watchdog Timer Control Register */
#define    WDPS0           0       // Watch Dog Timer Prescaler Select bit 0
#define    WDPS1           1       // Watch Dog Timer Prescaler Select bit 1
#define    WDPS2           2       // Watch Dog Timer Prescaler Select bit 2
#define    WDE             3       // Watch Dog Enable
#define    WDCE            4       // Watchdog Change Enable


/* ***** BANDGAP ********************** */
/* BGCAL - Bandgap Calibration Register */
#define    BGCAL0          0       // Bandgap Calibration Bit 0
#define    BGCAL1          1       // Bandgap Calibration Bit 1
#define    BGCAL2          2       // Bandgap Calibration Bit 2
#define    BGCAL3          3       // Bandgap Calibration Bit 3
#define    BGCAL4          4       // Bandgap Calibration Bit 4
#define    BGCAL5          5       // Bandgap Calibration Bit 5
#define    BGCAL6          6       // Bandgap Calibration Bit 6
#define    BGCAL7          7       // Bandgap Calibration Bit 7


/* ***** TIMER_COUNTER_0 ************** */
/* T0CR - Timer 0 Control Register */
#define    T0PAS0          0       // Timer 0 Prescaler A Select Bit 0
#define    T0PAS1          1       // Timer 0 Prescaler A Select Bit 1
#define    T0PAS2          2       // Timer 0 Prescaler A Select Bit 2
#define    T0IE            3       // Timer 0 Interrupt Enable Bit
#define    T0PR            4       // Timer 0 Prescaler Reset Bit
#define    T0PBS0          5       // Timer 0 Prescaler B Select Bit 0
#define    T0PBS1          6       // Timer 0 Prescaler B Select Bit 1
#define    T0PBS2          7       // Timer 0 Prescaler B Select Bit 2

/* T10IFR - Timer1/0 Interrupt Flag Register */
//#define  T0F             0       // Timer 0 Flag Bit
//#define  T1F             1       // Timer 1 Flag Bit


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
#define    EEWE            1       // EEPROM Write Enable
#define    EEMWE           2       // EEPROM Master Write Enable
#define    EERIE           3       // EEPROM Ready Interrupt Enable
#define    EEPM0           4       // EEPROM Programming Mode Bit 0
#define    EEPM1           5       // EEPROM Programming Mode Bit 1

#endif

