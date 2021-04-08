/*
CodeVisionAVR V2.0 C Compiler
(C) 1998-2009 Pavel Haiduc, HP InfoTech s.r.l.

ATmega32C1, ATmega64C1 I/O REGISTERS BIT DEFINITIONS
*/

#ifndef __MEGA64C1_BITS_INCLUDED__
#define __MEGA64C1_BITS_INCLUDED__

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


/* ***** CAN ************************** */
/* CANGCON - CAN General Control Register */
#define    SWRES           0       // Software Reset Request
#define    ENASTB          1       // Enable / Standby
#define    TEST            2       // Test Mode
#define    LISTEN          3       // Listening Mode
#define    SYNTTC          4       // Synchronization of TTC
#define    TTC             5       // Time Trigger Communication
#define    OVRQ            6       // Overload Frame Request
#define    ABRQ            7       // Abort Request

/* CANGSTA - CAN General Status Register */
#define    ERRP            0       // Error Passive Mode
#define    BOFF            1       // Bus Off Mode
#define    ENFG            2       // Enable Flag
#define    RXBSY           3       // Receiver Busy
#define    TXBSY           4       // Transmitter Busy
#define    OVFG            6       // Overload Frame Flag

/* CANGIT - CAN General Interrupt Register Flags */
#define    AERG            0       // Ackknowledgement Error General Flag
#define    FERG            1       // Form Error General Flag
#define    CERG            2       // CRC Error General Flag
#define    SERG            3       // Stuff Error General Flag
#define    BXOK            4       // Burst Receive Interrupt Flag
#define    OVRTIM          5       // Overrun CAN Timer Flag
#define    BOFFIT          6       // Bus Off Interrupt Flag
#define    CANIT           7       // General Interrupt Flag

/* CANGIE - CAN General Interrupt Enable Register */
#define    ENOVRT          0       // Enable CAN Timer Overrun Interrupt
#define    ENERG           1       // Enable General Error Interrupt
#define    ENBX            2       // Enable Burst Receive Interrupt
#define    ENERR           3       // Enable MOb Error Interrupt
#define    ENTX            4       // Enable Transmitt Interrupt
#define    ENRX            5       // Enable Receive Interrupt
#define    ENBOFF          6       // Enable Bus Off Interrupt
#define    ENIT            7       // Enable all Interrupts

/* CANEN2 - Enable MOb Register 2 */
#define    ENMOB0          0       // Enable MOb 0
#define    ENMOB1          1       // Enable MOb 1
#define    ENMOB2          2       // Enable MOb 2
#define    ENMOB3          3       // Enable MOb 3
#define    ENMOB4          4       // Enable MOb 4
#define    ENMOB5          5       // Enable MOb 5

/* CANEN1 - Enable MOb Register 1(empty) */

/* CANIE2 - Enable Interrupt MOb Register 2 */
#define    IEMOB0          0       // Interrupt Enable  MOb 0
#define    IEMOB1          1       // Interrupt Enable  MOb 1
#define    IEMOB2          2       // Interrupt Enable  MOb 2
#define    IEMOB3          3       // Interrupt Enable  MOb 3
#define    IEMOB4          4       // Interrupt Enable  MOb 4
#define    IEMOB5          5       // Interrupt Enable  MOb 5

/* CANIE1 - Enable Interrupt MOb Register 1 (empty) */

/* CANSIT2 - CAN Status Interrupt MOb Register 2 */
#define    SIT0            0       // Status of Interrupt MOb 0
#define    SIT1            1       // Status of Interrupt MOb 1
#define    SIT2            2       // Status of Interrupt MOb 2
#define    SIT3            3       // Status of Interrupt MOb 3
#define    SIT4            4       // Status of Interrupt MOb 4
#define    SIT5            5       // Status of Interrupt MOb 5

/* CANSIT1 - CAN Status Interrupt MOb Register 1 (empty) */

/* CANBT1 - CAN Bit Timing Register 1 */
#define    BRP0            1       // Baud Rate Prescaler bit 0
#define    BRP1            2       // Baud Rate Prescaler bit 1
#define    BRP2            3       // Baud Rate Prescaler bit 2
#define    BRP3            4       // Baud Rate Prescaler bit 3
#define    BRP4            5       // Baud Rate Prescaler bit 4
#define    BRP5            6       // Baud Rate Prescaler bit 5

/* CANBT2 - CAN Bit Timing Register 2 */
#define    PRS0            1       // Propagation Time Segment bit 0
#define    PRS1            2       // Propagation Time Segment bit 1
#define    PRS2            3       // Propagation Time Segment bit 2
#define    SJW0            5       // Re-Sync Jump Width bit 0
#define    SJW1            6       // Re-Sync Jump Width bit 1

/* CANBT3 - CAN Bit Timing Register 3 */
#define    SMP             0       // Sample Type
#define    PHS10           1       // Phase Segment 1 bit 0
#define    PHS11           2       // Phase Segment 1 bit 1
#define    PHS12           3       // Phase Segment 1 bit 2
#define    PHS20           4       // Phase Segment 2 bit 0
#define    PHS21           5       // Phase Segment 2 bit 1
#define    PHS22           6       // Phase Segment 2 bit 2

/* CANTCON - Timer Control Register */
#define    TPRSC0          0       // CAN Timer Prescaler bit 0
#define    TPRSC1          1       // CAN Timer Prescaler bit 1
#define    TPRSC2          2       // CAN Timer Prescaler bit 2
#define    TPRSC3          3       // CAN Timer Prescaler bit 3
#define    TPRSC4          4       // CAN Timer Prescaler bit 4
#define    TPRSC5          5       // CAN Timer Prescaler bit 5
#define    TPRSC6          6       // CAN Timer Prescaler bit 6
#define    TPRSC7          7       // CAN Timer Prescaler bit 7

/* CANTIML - Timer Register Low */
#define    CANTIM0         0       // CAN Timer Count bit 0
#define    CANTIM1         1       // CAN Timer Count bit 1
#define    CANTIM2         2       // CAN Timer Count bit 2
#define    CANTIM3         3       // CAN Timer Count bit 3
#define    CANTIM4         4       // CAN Timer Count bit 4
#define    CANTIM5         5       // CAN Timer Count bit 5
#define    CANTIM6         6       // CAN Timer Count bit 6
#define    CANTIM7         7       // CAN Timer Count bit 7

/* CANTIMH - Timer Register High */
#define    CANTIM8         0       // CAN Timer Count bit 8
#define    CANTIM9         1       // CAN Timer Count bit 9
#define    CANTIM10        2       // CAN Timer Count bit 10
#define    CANTIM11        3       // CAN Timer Count bit 11
#define    CANTIM12        4       // CAN Timer Count bit 12
#define    CANTIM13        5       // CAN Timer Count bit 13
#define    CANTIM14        6       // CAN Timer Count bit 14
#define    CANTIM15        7       // CAN Timer Count bit 15

/* CANTTCL - TTC Timer Register Low */
#define    TIMTCC0         0       // TTC Timer Count bit 0
#define    TIMTCC1         1       // TTC Timer Count bit 1
#define    TIMTCC2         2       // TTC Timer Count bit 2
#define    TIMTCC3         3       // TTC Timer Count bit 3
#define    TIMTCC4         4       // TTC Timer Count bit 4
#define    TIMTCC5         5       // TTC Timer Count bit 5
#define    TIMTCC6         6       // TTC Timer Count bit 6
#define    TIMTCC7         7       // TTC Timer Count bit 7

/* CANTTCH - TTC Timer Register High */
#define    TIMTCC8         0       // TTC Timer Count bit 8
#define    TIMTCC9         1       // TTC Timer Count bit 9
#define    TIMTCC10        2       // TTC Timer Count bit 10
#define    TIMTCC11        3       // TTC Timer Count bit 11
#define    TIMTCC12        4       // TTC Timer Count bit 12
#define    TIMTCC13        5       // TTC Timer Count bit 13
#define    TIMTCC14        6       // TTC Timer Count bit 14
#define    TIMTCC15        7       // TTC Timer Count bit 15

/* CANTEC - Transmit Error Counter Register */
#define    TEC0            0       // Transmit Error Count bit 0
#define    TEC1            1       // Transmit Error Count bit 1
#define    TEC2            2       // Transmit Error Count bit 2
#define    TEC3            3       // Transmit Error Count bit 3
#define    TEC4            4       // Transmit Error Count bit 4
#define    TEC5            5       // Transmit Error Count bit 5
#define    TEC6            6       // Transmit Error Count bit 6
#define    TEC7            7       // Transmit Error Count bit 7

/* CANREC - Receive Error Counter Register */
#define    REC0            0       // Receive Error Count bit 0
#define    REC1            1       // Receive Error Count bit 1
#define    REC2            2       // Receive Error Count bit 2
#define    REC3            3       // Receive Error Count bit 3
#define    REC4            4       // Receive Error Count bit 4
#define    REC5            5       // Receive Error Count bit 5
#define    REC6            6       // Receive Error Count bit 6
#define    REC7            7       // Receive Error Count bit 7

/* CANHPMOB - Highest Priority MOb Register */
#define    CGP0            0       // CAN General Purpose bit 0
#define    CGP1            1       // CAN General Purpose bit 1
#define    CGP2            2       // CAN General Purpose bit 2
#define    CGP3            3       // CAN General Purpose bit 3
#define    HPMOB0          4       // Highest Priority MOb Number bit 0
#define    HPMOB1          5       // Highest Priority MOb Number bit 1
#define    HPMOB2          6       // Highest Priority MOb Number bit 2
#define    HPMOB3          7       // Highest Priority MOb Number bit 3

/* CANPAGE - Page MOb Register */
#define    INDX0           0       // Data Buffer Index bit 0
#define    INDX1           1       // Data Buffer Index bit 1
#define    INDX2           2       // Data Buffer Index bit 2
#define    AINC            3       // MOb Data Buffer Auto Increment (Active Low)
#define    MOBNB0          4       // MOb Number bit 0
#define    MOBNB1          5       // MOb Number bit 1
#define    MOBNB2          6       // MOb Number bit 2
#define    MOBNB3          7       // MOb Number bit 3

/* CANSTMOB - MOb Status Register */
#define    AERR            0       // Ackknowledgement Error on MOb
#define    FERR            1       // Form Error on MOb
#define    CERR            2       // CRC Error on MOb
#define    SERR            3       // Stuff Error on MOb
#define    BERR            4       // Bit Error on MOb
#define    RXOK            5       // Receive OK on MOb
#define    TXOK            6       // Transmit OK on MOb
#define    DLCW            7       // Data Length Code Warning on MOb

/* CANCDMOB - MOb Control and DLC Register */
#define    DLC0            0       // Data Length Code bit 0
#define    DLC1            1       // Data Length Code bit 1
#define    DLC2            2       // Data Length Code bit 2
#define    DLC3            3       // Data Length Code bit 3
#define    IDE             4       // Identifier Extension
#define    RPLV            5       // Reply Valid
#define    CONMOB0         6       // MOb Config bit 0
#define    CONMOB1         7       // MOb Config bit 1

/* CANIDT4 - Identifier Tag Register 4 */
#define    RB0TAG          0       //
#define    RB1TAG          1       //
#define    RTRTAG          2       //
#define    IDT0            3       //
#define    IDT1            4       //
#define    IDT2            5       //
#define    IDT3            6       //
#define    IDT4            7       //

/* CANIDT3 - Identifier Tag Register 3 */
#define    IDT5            0       //
#define    IDT6            1       //
#define    IDT7            2       //
#define    IDT8            3       //
#define    IDT9            4       //
#define    IDT10           5       //
#define    IDT11           6       //
#define    IDT12           7       //

/* CANIDT2 - Identifier Tag Register 2 */
#define    IDT13           0       //
#define    IDT14           1       //
#define    IDT15           2       //
#define    IDT16           3       //
#define    IDT17           4       //
#define    IDT18           5       //
#define    IDT19           6       //
#define    IDT20           7       //

/* CANIDT1 - Identifier Tag Register 1 */
#define    IDT21           0       //
#define    IDT22           1       //
#define    IDT23           2       //
#define    IDT24           3       //
#define    IDT25           4       //
#define    IDT26           5       //
#define    IDT27           6       //
#define    IDT28           7       //

/* CANIDM4 - Identifier Mask Register 4 */
#define    IDEMSK          0       //
#define    RTRMSK          2       //
#define    IDMSK0          3       //
#define    IDMSK1          4       //
#define    IDMSK2          5       //
#define    IDMSK3          6       //
#define    IDMSK4          7       //

/* CANIDM3 - Identifier Mask Register 3 */
#define    IDMSK5          0       //
#define    IDMSK6          1       //
#define    IDMSK7          2       //
#define    IDMSK8          3       //
#define    IDMSK9          4       //
#define    IDMSK10         5       //
#define    IDMSK11         6       //
#define    IDMSK12         7       //

/* CANIDM2 - Identifier Mask Register 2 */
#define    IDMSK13         0       //
#define    IDMSK14         1       //
#define    IDMSK15         2       //
#define    IDMSK16         3       //
#define    IDMSK17         4       //
#define    IDMSK18         5       //
#define    IDMSK19         6       //
#define    IDMSK20         7       //

/* CANIDM1 - Identifier Mask Register 1 */
#define    IDMSK21         0       //
#define    IDMSK22         1       //
#define    IDMSK23         2       //
#define    IDMSK24         3       //
#define    IDMSK25         4       //
#define    IDMSK26         5       //
#define    IDMSK27         6       //
#define    IDMSK28         7       //

/* CANSTML - Time Stamp Register Low */
#define    TIMSTM0         0       // CAN Timer Count bit 0
#define    TIMSTM1         1       // CAN Timer Count bit 1
#define    TIMSTM2         2       // CAN Timer Count bit 2
#define    TIMSTM3         3       // CAN Timer Count bit 3
#define    TIMSTM4         4       // CAN Timer Count bit 4
#define    TIMSTM5         5       // CAN Timer Count bit 5
#define    TIMSTM6         6       // CAN Timer Count bit 6
#define    TIMSTM7         7       // CAN Timer Count bit 7

/* CANSTMH - Time Stamp Register High */
#define    TIMSTM8         0       // CAN Timer Count bit 0
#define    TIMSTM9         1       // CAN Timer Count bit 9
#define    TIMSTM10        2       // CAN Timer Count bit 10
#define    TIMSTM11        3       // CAN Timer Count bit 11
#define    TIMSTM12        4       // CAN Timer Count bit 12
#define    TIMSTM13        5       // CAN Timer Count bit 13
#define    TIMSTM14        6       // CAN Timer Count bit 14
#define    TIMSTM15        7       // CAN Timer Count bit 15

/* CANMSG - Message Data Register */
#define    MSG0            0       // Message Data bit 0
#define    MSG1            1       // Message Data bit 1
#define    MSG2            2       // Message Data bit 2
#define    MSG3            3       // Message Data bit 3
#define    MSG4            4       // Message Data bit 4
#define    MSG5            5       // Message Data bit 5
#define    MSG6            6       // Message Data bit 6
#define    MSG7            7       // Message Data bit 7


/* ***** ANALOG_COMPARATOR ************ */
/* AC0CON - Analog Comparator 0 Control Register */
#define    AC0M0           0       // Analog Comparator 0 Multiplexer Register
#define    AC0M1           1       // Analog Comparator 0 Multiplexer Regsiter
#define    AC0M2           2       // Analog Comparator 0 Multiplexer Register
#define    ACCKSEL         3       // Analog Comparator Clock Select
#define    AC0IS0          4       // Analog Comparator 0 Interrupt Select Bit 0
#define    AC0IS1          5       // Analog Comparator 0  Interrupt Select Bit 1
#define    AC0IE           6       // Analog Comparator 0 Interrupt Enable Bit
#define    AC0EN           7       // Analog Comparator 0 Enable Bit

/* AC1CON - Analog Comparator 1 Control Register */
#define    AC1M0           0       // Analog Comparator 1 Multiplexer Register
#define    AC1M1           1       // Analog Comparator 1 Multiplexer Regsiter
#define    AC1M2           2       // Analog Comparator 1 Multiplexer Register
#define    AC1ICE          3       // Analog Comparator 1 Interrupt Capture Enable Bit
#define    AC1IS0          4       // Analog Comparator 1 Interrupt Select Bit
#define    AC1IS1          5       // Analog Comparator 1  Interrupt Select Bit
#define    AC1IE           6       // Analog Comparator 1 Interrupt Enable Bit
#define    AC1EN           7       // Analog Comparator 1 Enable Bit

/* AC2CON - Analog Comparator 2 Control Register */
#define    AC2M0           0       // Analog Comparator 2 Multiplexer Register
#define    AC2M1           1       // Analog Comparator 2 Multiplexer Regsiter
#define    AC2M2           2       // Analog Comparator 2 Multiplexer Register
#define    AC2IS0          4       // Analog Comparator 2 Interrupt Select Bit
#define    AC2IS1          5       // Analog Comparator 2  Interrupt Select Bit
#define    AC2IE           6       // Analog Comparator 2 Interrupt Enable Bit
#define    AC2EN           7       // Analog Comparator 2 Enable Bit

/* AC3CON - Analog Comparator 3 Control Register */
#define    AC3M0           0       // Analog Comparator 3 Multiplexer Register
#define    AC3M1           1       // Analog Comparator 3 Multiplexer Regsiter
#define    AC3M2           2       // Analog Comparator 3 Multiplexer Register
#define    AC3IS0          4       // Analog Comparator 3 Interrupt Select Bit
#define    AC3IS1          5       // Analog Comparator 3  Interrupt Select Bit
#define    AC3IE           6       // Analog Comparator 3 Interrupt Enable Bit
#define    AC3EN           7       // Analog Comparator 3 Enable Bit

/* ACSR - Analog Comparator Status Register */
#define    AC0O            0       // Analog Comparator 0 Output Bit
#define    AC1O            1       // Analog Comparator 1 Output Bit
#define    AC2O            2       // Analog Comparator 2 Output Bit
#define    AC3O            3       // Analog Comparator 3 Output Bit
#define    AC0IF           4       // Analog Comparator 0 Interrupt Flag Bit
#define    AC1IF           5       // Analog Comparator 1  Interrupt Flag Bit
#define    AC2IF           6       // Analog Comparator 2 Interrupt Flag Bit
#define    AC3IF           7       // Analog Comparator 3 Interrupt Flag Bit


/* ***** DA_CONVERTER ***************** */
/* DACH - DAC Data Register High Byte */
#define    DACH0           0       // DAC Data Register High Byte Bit 0
#define    DACH1           1       // DAC Data Register High Byte Bit 1
#define    DACH2           2       // DAC Data Register High Byte Bit 2
#define    DACH3           3       // DAC Data Register High Byte Bit 3
#define    DACH4           4       // DAC Data Register High Byte Bit 4
#define    DACH5           5       // DAC Data Register High Byte Bit 5
#define    DACH6           6       // DAC Data Register High Byte Bit 6
#define    DACH7           7       // DAC Data Register High Byte Bit 7

/* DACL - DAC Data Register Low Byte */
#define    DACL0           0       // DAC Data Register Low Byte Bit 0
#define    DACL1           1       // DAC Data Register Low Byte Bit 1
#define    DACL2           2       // DAC Data Register Low Byte Bit 2
#define    DACL3           3       // DAC Data Register Low Byte Bit 3
#define    DACL4           4       // DAC Data Register Low Byte Bit 4
#define    DACL5           5       // DAC Data Register Low Byte Bit 5
#define    DACL6           6       // DAC Data Register Low Byte Bit 6
#define    DACL7           7       // DAC Data Register Low Byte Bit 7

/* DACON - DAC Control Register */
#define    DAEN            0       // DAC Enable Bit
#define    DALA            2       // DAC Left Adjust
#define    DATS0           4       // DAC Trigger Selection Bit 0
#define    DATS1           5       // DAC Trigger Selection Bit 1
#define    DATS2           6       // DAC Trigger Selection Bit 2
#define    DAATE           7       // DAC Auto Trigger Enable Bit


/* ***** CPU ************************** */
/* SPMCSR - Store Program Memory Control Register */
#define    SPMCR           SPMCSR  // For compatibility
#define    SPMEN           0       // Store Program Memory Enable
#define    PGERS           1       // Page Erase
#define    PGWRT           2       // Page Write
#define    BLBSET          3       // Boot Lock Bit Set
#define    RWWSRE          4       // Read While Write section read enable
#define    ASRE            RWWSRE  // For compatibility
#define    SIGRD           5       // Signature Row Read
#define    RWWSB           6       // Read While Write Section Busy
#define    ASB             RWWSB   // For compatibility
#define    SPMIE           7       // SPM Interrupt Enable

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
#define    SPIPS           7       // SPI Pin Select

/* MCUSR - MCU Status Register */
#define    PORF            0       // Power-on reset flag
#define    EXTRF           1       // External Reset Flag
#define    BORF            2       // Brown-out Reset Flag
#define    WDRF            3       // Watchdog Reset Flag

/* OSCCAL - Oscillator Calibration Value */
#define    CAL0            0       // Oscillator Calibration Value Bit0
#define    CAL1            1       // Oscillator Calibration Value Bit1
#define    CAL2            2       // Oscillator Calibration Value Bit2
#define    CAL3            3       // Oscillator Calibration Value Bit3
#define    CAL4            4       // Oscillator Calibration Value Bit4
#define    CAL5            5       // Oscillator Calibration Value Bit5
#define    CAL6            6       // Oscillator Calibration Value Bit6

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

/* PLLCSR - PLL Control And Status Register */
#define    PLOCK           0       // PLL Lock Detector
#define    PLLE            1       // PLL Enable
#define    PLLF            2       // PLL Factor

/* PRR - Power Reduction Register */
#define    PRADC           0       // Power Reduction ADC
#define    PRLIN           1       // Power Reduction LIN UART
#define    PRSPI           2       // Power Reduction Serial Peripheral Interface
#define    PRTIM0          3       // Power Reduction Timer/Counter0
#define    PRTIM1          4       // Power Reduction Timer/Counter1
#define    PRPSC           5       // Power Reduction PSC
#define    PRCAN           6       // Power Reduction CAN


/* ***** PORTE ************************ */
/* PORTE - Port E Data Register */
#define    PORTE0          0       //
#define    PORTE1          1       //
#define    PORTE2          2       //

/* DDRE - Port E Data Direction Register */
#define    DDE0            0       //
#define    DDE1            1       //
#define    DDE2            2       //

/* PINE - Port E Input Pins */
#define    PINE0           0       //
#define    PINE1           1       //
#define    PINE2           2       //


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
#define    OCR0A_0         0       //
#define    OCR0A_1         1       //
#define    OCR0A_2         2       //
#define    OCR0A_3         3       //
#define    OCR0A_4         4       //
#define    OCR0A_5         5       //
#define    OCR0A_6         6       //
#define    OCR0A_7         7       //

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
#define    PSR10           0       // Prescaler Reset Timer/Counter1 and Timer/Counter0
#define    ICPSEL1         6       // Timer1 Input Capture Selection Bit
#define    TSM             7       // Timer/Counter Synchronization Mode


/* ***** TIMER_COUNTER_1 ************** */
/* TIMSK1 - Timer/Counter Interrupt Mask Register */
#define    TOIE1           0       // Timer/Counter1 Overflow Interrupt Enable
#define    OCIE1A          1       // Timer/Counter1 Output CompareA Match Interrupt Enable
#define    OCIE1B          2       // Timer/Counter1 Output CompareB Match Interrupt Enable
#define    ICIE1           5       // Timer/Counter1 Input Capture Interrupt Enable

/* TIFR1 - Timer/Counter Interrupt Flag register */
#define    TOV1            0       // Timer/Counter1 Overflow Flag
#define    OCF1A           1       // Output Compare Flag 1A
#define    OCF1B           2       // Output Compare Flag 1B
#define    ICF1            5       // Input Capture Flag 1

/* TCCR1A - Timer/Counter1 Control Register A */
#define    WGM10           0       // Waveform Generation Mode
#define    WGM11           1       // Waveform Generation Mode
#define    COM1B0          4       // Compare Output Mode 1B, bit 0
#define    COM1B1          5       // Compare Output Mode 1B, bit 1
#define    COM1A0          6       // Comparet Ouput Mode 1A, bit 0
#define    COM1A1          7       // Compare Output Mode 1A, bit 1

/* TCCR1B - Timer/Counter1 Control Register B */
#define    CS10            0       // Prescaler source of Timer/Counter 1
#define    CS11            1       // Prescaler source of Timer/Counter 1
#define    CS12            2       // Prescaler source of Timer/Counter 1
#define    WGM12           3       // Waveform Generation Mode
#define    WGM13           4       // Waveform Generation Mode
#define    ICES1           6       // Input Capture 1 Edge Select
#define    ICNC1           7       // Input Capture 1 Noise Canceler

/* TCCR1C - Timer/Counter1 Control Register C */
#define    FOC1B           6       //
#define    FOC1A           7       //

/* GTCCR - General Timer/Counter Control Register */
#define    PSRSYNC         0       // Prescaler Reset Timer/Counter1 and Timer/Counter0
//#define  TSM             7       // Timer/Counter Synchronization Mode


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
#define    ADTS3           3       // ADC Auto Trigger Source 3
#define    AREFEN          5       // Analog Reference pin Enable
#define    ISRCEN          6       // Current Source Enable
#define    ADHSM           7       // ADC High Speed Mode

/* DIDR0 - Digital Input Disable Register 0 */
#define    ADC0D           0       // ADC0 Digital input Disable
#define    ADC1D           1       // ADC1 Digital input Disable
#define    ADC2D           2       // ADC2 Digital input Disable
#define    ADC3D           3       // ADC3 Digital input Disable
#define    ADC4D           4       // ADC4 Digital input Disable
#define    ADC5D           5       // ADC5 Digital input Disable
#define    ADC6D           6       // ADC6 Digital input Disable
#define    ADC7D           7       // ADC7 Digital input Disable

/* DIDR1 - Digital Input Disable Register 0 */
#define    ADC8D           0       // ADC8 Pin Digital input Disable
#define    ADC9D           1       // ADC9 Pin Digital input Disable
#define    ADC10D          2       // ADC10 Pin Digital input Disable
#define    AMP0ND          3       // AMP0N Pin Digital input Disable
#define    AMP0PD          4       // AMP0P Pin Digital input Disable
#define    ACMP0D          5       // ACMP0 Pin Digital input Disable
#define    AMP2PD          6       // AMP2P Pin Digital input Disable

/* AMP0CSR -  */
#define    AMP0TS0         0       //
#define    AMP0TS1         1       //
#define    AMP0TS2         2       //
#define    AMPCMP0         3       // Amplifier 0 - Comparator 0 Connection
#define    AMP0G0          4       //
#define    AMP0G1          5       //
#define    AMP0IS          6       //
#define    AMP0EN          7       //

/* AMP1CSR -  */
#define    AMP1TS0         0       //
#define    AMP1TS1         1       //
#define    AMP1TS2         2       //
#define    AMPCMP1         3       // Amplifier 1 - Comparator 1 Connection
#define    AMP1G0          4       //
#define    AMP1G1          5       //
#define    AMP1IS          6       //
#define    AMP1EN          7       //

/* AMP2CSR -  */
#define    AMP2TS0         0       //
#define    AMP2TS1         1       //
#define    AMP2TS2         2       //
#define    AMPCMP2         3       // Amplifier 2 - Comparator 2 Connection
#define    AMP2G0          4       //
#define    AMP2G1          5       //
#define    AMP2IS          6       //
#define    AMP2EN          7       //


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


/* ***** EXTERNAL_INTERRUPT *********** */
/* EICRA - External Interrupt Control Register */
#define    ISC00           0       // External Interrupt Sense Control 0 Bit 0
#define    ISC01           1       // External Interrupt Sense Control 0 Bit 1
#define    ISC10           2       // External Interrupt Sense Control 1 Bit 0
#define    ISC11           3       // External Interrupt Sense Control 1 Bit 1
#define    ISC20           4       // External Interrupt Sense Control Bit
#define    ISC21           5       // External Interrupt Sense Control Bit
#define    ISC30           6       // External Interrupt Sense Control Bit
#define    ISC31           7       // External Interrupt Sense Control Bit

/* EIMSK - External Interrupt Mask Register */
#define    INT0            0       // External Interrupt Request 0 Enable
#define    INT1            1       // External Interrupt Request 1 Enable
#define    INT2            2       // External Interrupt Request 2 Enable
#define    INT3            3       // External Interrupt Request 3 Enable

/* EIFR - External Interrupt Flag Register */
#define    INTF0           0       // External Interrupt Flag 0
#define    INTF1           1       // External Interrupt Flag 1
#define    INTF2           2       // External Interrupt Flag 2
#define    INTF3           3       // External Interrupt Flag 3

/* PCICR - Pin Change Interrupt Control Register */
#define    PCIE0           0       // Pin Change Interrupt Enable 0
#define    PCIE1           1       // Pin Change Interrupt Enable 1
#define    PCIE2           2       // Pin Change Interrupt Enable 2
#define    PCIE3           3       // Pin Change Interrupt Enable 3

/* PCMSK3 - Pin Change Mask Register 3 */
#define    PCINT24         0       // Pin Change Enable Mask 24
#define    PCINT25         1       // Pin Change Enable Mask 25
#define    PCINT26         2       // Pin Change Enable Mask 26

/* PCMSK2 - Pin Change Mask Register 2 */
#define    PCINT16         0       // Pin Change Enable Mask 16
#define    PCINT17         1       // Pin Change Enable Mask 17
#define    PCINT18         2       // Pin Change Enable Mask 18
#define    PCINT19         3       // Pin Change Enable Mask 19
#define    PCINT20         4       // Pin Change Enable Mask 20
#define    PCINT21         5       // Pin Change Enable Mask 21
#define    PCINT22         6       // Pin Change Enable Mask 22
#define    PCINT23         7       // Pin Change Enable Mask 23

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

/* PCIFR - Pin Change Interrupt Flag Register */
#define    PCIF0           0       // Pin Change Interrupt Flag 0
#define    PCIF1           1       // Pin Change Interrupt Flag 1
#define    PCIF2           2       // Pin Change Interrupt Flag 2
#define    PCIF3           3       // Pin Change Interrupt Flag 3


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
#define    EEPE            EEWE    // For compatibility
#define    EEMWE           2       // EEPROM Master Write Enable
#define    EEMPE           EEMWE   // For compatibility
#define    EERIE           3       // EEProm Ready Interrupt Enable
#define    EEPM0           4       //
#define    EEPM1           5       //

#endif
