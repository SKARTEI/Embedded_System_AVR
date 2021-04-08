// CodeVisionAVR V3.0 C Compiler
// (C) 1998-2013 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATtiny828

#ifndef _TINY828_INCLUDED_
#define _TINY828_INCLUDED_

#pragma used+
sfrb PINA    =0x00;
#define PINA7   7
#define PINA6   6
#define PINA5   5
#define PINA4   4
#define PINA3   3
#define PINA2   2
#define PINA1   1
#define PINA0   0

sfrb DDRA    =0x01;
#define DDA7   7
#define DDA6   6
#define DDA5   5
#define DDA4   4
#define DDA3   3
#define DDA2   2
#define DDA1   1
#define DDA0   0

sfrb PORTA   =0x02;
#define PORTA7  7
#define PORTA6  6
#define PORTA5  5
#define PORTA4  4
#define PORTA3  3
#define PORTA2  2
#define PORTA1  1
#define PORTA0  0

sfrb PUEA    =0x03;
#define PUEA7   7
#define PUEA6   6
#define PUEA5   5
#define PUEA4   4
#define PUEA3   3
#define PUEA2   2
#define PUEA1   1
#define PUEA0   0

sfrb PINB    =0x04;
#define PINB7   7
#define PINB6   6
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

sfrb DDRB    =0x05;
#define DDB7   7
#define DDB6   6
#define DDB5   5
#define DDB4   4
#define DDB3   3
#define DDB2   2
#define DDB1   1
#define DDB0   0

sfrb PORTB   =0x06;
#define PORTB7  7
#define PORTB6  6
#define PORTB5  5
#define PORTB4  4
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

sfrb PUEB    =0x07;
#define PUEB7   7
#define PUEB6   6
#define PUEB5   5
#define PUEB4   4
#define PUEB3   3
#define PUEB2   2
#define PUEB1   1
#define PUEB0   0

sfrb PINC    =0x08;
#define PINC7   7
#define PINC6   6
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

sfrb DDRC    =0x09;
#define DDC7   7
#define DDC6   6
#define DDC5   5
#define DDC4   4
#define DDC3   3
#define DDC2   2
#define DDC1   1
#define DDC0   0

sfrb PORTC   =0x0A;
#define PORTC7  7
#define PORTC6  6
#define PORTC5  5
#define PORTC4  4
#define PORTC3  3
#define PORTC2  2
#define PORTC1  1
#define PORTC0  0

sfrb PUEC    =0x0B;
#define PUEC7   7
#define PUEC6   6
#define PUEC5   5
#define PUEC4   4
#define PUEC3   3
#define PUEC2   2
#define PUEC1   1
#define PUEC0   0

sfrb PIND    =0x0C;
#define PIND3   3
#define PIND2   2
#define PIND1   1
#define PIND0   0

sfrb DDRD    =0x0D;
#define DDD3   3
#define DDD2   2
#define DDD1   1
#define DDD0   0

sfrb PORTD   =0x0E;
#define PORTD3  3
#define PORTD2  2
#define PORTD1  1
#define PORTD0  0

sfrb PUED    =0x0F;
#define PUED3   3
#define PUED2   2
#define PUED1   1
#define PUED0   0

sfrb PHDE    =0x14;
#define PHDEC   2

sfrb TIFR0   =0x15;
#define TOV0    0
#define OCF0A   1
#define OCF0B   2

sfrb TIFR1   =0x16;
#define TOV1    0
#define OCF1A   1
#define OCF1B   2
#define ICF1    5

sfrb PCIFR   =0x1B;
#define PCIF0   0
#define PCIF1   1
#define PCIF2   2
#define PCIF3   3

sfrb EIFR    =0x1C;
#define INTF0   0
#define INTF1   1

sfrb EIMSK   =0x1D;
#define INT0    0
#define INT1    1

sfrb GPIOR0  =0x1E;

sfrb EECR    =0x1F;
#define EERE    0
#define EEPE    1
#define EEMPE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5

sfrb EEDR    =0x20;
sfrb EEAR    =0x21;

sfrb GTCCR   =0x23;
#define PSRSYNC 0
#define TSM     7

sfrb TCCR0A  =0x24;
#define WGM00   0
#define WGM01   1
#define COM0B0  4
#define COM0B1  5
#define COM0A0  6
#define COM0A1  7

sfrb TCCR0B  =0x25;
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM02   3
#define FOC0B   6
#define FOC0A   7

sfrb TCNT0   =0x26;
sfrb OCR0A   =0x27;
sfrb OCR0B   =0x28;
sfrb GPIOR1  =0x2A;
sfrb GPIOR2  =0x2B;

sfrb SPCR    =0x2C;
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

sfrb SPSR    =0x2D;
#define SPI2X   0
#define WCOL    6
#define SPIF    7

sfrb SPDR    =0x2E;

sfrb ACSRB   =0x2F;
#define ACPMUX0 0
#define ACPMUX1 1
#define ACNMUX0 2
#define ACNMUX1 3
#define HLEV    6
#define HSEL    7

sfrb ACSRA   =0x30;
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACPMUX2 6
#define ACD     7

sfrb SMCR    =0x33;
#define SE      0
#define SM0     1
#define SM1     2

sfrb MCUSR   =0x34;
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3

sfrb MCUCR   =0x35;
#define IVSEL   1

sfrb CCP     =0x36;

sfrb SPMCSR  =0x37;
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define RWFLB   3
#define RWWSRE  4
#define RSIG    5
#define RWWSB   6
#define SPMIE   7

sfrb SPL=0x3D;
sfrb SPH=0x3E;
sfrb SREG=0x3F;
#pragma used-

#define WDTCSR  (*(unsigned char *) 0x60)
#define WDE     3
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDP3    5
#define WDIE    6
#define WDIF    7

#define CLKPR   (*(unsigned char *) 0x61)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLKPS3  3

#define PRR     (*(unsigned char *) 0x64)
#define PRADC   0
#define PRUSART0 1
#define PRSPI   2
#define PRTIM1  3
#define PRTIM0  5
#define PRTWI   7

#define OSCCAL0 (*(unsigned char *) 0x66)
#define OSCCAL1 (*(unsigned char *) 0x67)

#define PCICR   (*(unsigned char *) 0x68)
#define PCIE0   0
#define PCIE1   1
#define PCIE2   2
#define PCIE3   3

#define EICRA   (*(unsigned char *) 0x69)
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

#define PCMSK0  (*(unsigned char *) 0x6B)
#define PCINT0  0
#define PCINT1  1
#define PCINT2  2
#define PCINT3  3
#define PCINT4  4
#define PCINT5  5
#define PCINT6  6
#define PCINT7  7

#define PCMSK1  (*(unsigned char *) 0x6C)
#define PCINT8  0
#define PCINT9  1
#define PCINT10 2
#define PCINT11 3
#define PCINT12 4
#define PCINT13 5
#define PCINT14 6
#define PCINT15 7

#define PCMSK2  (*(unsigned char *) 0x6D)
#define PCINT16 0
#define PCINT17 1
#define PCINT18 2
#define PCINT19 3
#define PCINT20 4
#define PCINT21 5
#define PCINT22 6
#define PCINT23 7

#define TIMSK0  (*(unsigned char *) 0x6E)
#define TOIE0   0
#define OCIE0A  1
#define OCIE0B  2

#define TIMSK1  (*(unsigned char *) 0x6F)
#define TOIE1   0
#define OCIE1A  1
#define OCIE1B  2
#define ICIE1   5

#define PCMSK3  (*(unsigned char *) 0x73)
#define PCINT24 0
#define PCINT25 1
#define PCINT26 2
#define PCINT27 3

#define ADCL    (*(unsigned char *) 0x78)
#define ADCH    (*(unsigned char *) 0x79)
#define ADCW    (*(unsigned short *) 0x78) // 16 bit access

#define ADCSRA  (*(unsigned char *) 0x7A)
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADCSRB  (*(unsigned char *) 0x7B)
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2
#define ADLAR   3

#define ADMUXA  (*(unsigned char *) 0x7C)
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4

#define ADMUXB  (*(unsigned char *) 0x7D)
#define MUX5    0
#define REFS    5

#define DIDR0   (*(unsigned char *) 0x7E)
#define ADC0D   0
#define ADC1D   1
#define ADC2D   2
#define ADC3D   3
#define ADC4D   4
#define ADC5D   5
#define ADC6D   6
#define ADC7D   7

#define DIDR1   (*(unsigned char *) 0x7F)
#define ADC8D   0
#define ADC9D   1
#define ADC10D  2
#define ADC11D  3
#define ADC12D  4
#define ADC13D  5
#define ADC14D  6
#define ADC15D  7

#define TCCR1A  (*(unsigned char *) 0x80)
#define WGM10   0
#define WGM11   1
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define TCCR1B  (*(unsigned char *) 0x81)
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define TCCR1C  (*(unsigned char *) 0x82)
#define FOC1B   6
#define FOC1A   7

#define TCNT1L  (*(unsigned char *) 0x84)
#define TCNT1H  (*(unsigned char *) 0x85)

#define ICR1L   (*(unsigned char *) 0x86)
#define ICR1H   (*(unsigned char *) 0x87)

#define OCR1AL  (*(unsigned char *) 0x88)
#define OCR1AH  (*(unsigned char *) 0x89)

#define OCR1BL  (*(unsigned char *) 0x8A)
#define OCR1BH  (*(unsigned char *) 0x8B)

#define TWSCRA  (*(unsigned char *) 0xB8)
#define TWSME   0
#define TWPME   1
#define TWSIE   2
#define TWEN    3
#define TWASIE  4
#define TWDIE   5
#define TWSHE   7

#define TWSCRB  (*(unsigned char *) 0xB9)
#define TWCMD0  0
#define TWCMD1  1
#define TWAA    2
#define TWHNM   3

#define TWSSRA  (*(unsigned char *) 0xBA)
#define TWAS    0
#define TWDIR   1
#define TWBE    2
#define TWC     3
#define TWRA    4
#define TWCH    5
#define TWASIF  6
#define TWDIF   7

#define TWSAM   (*(unsigned char *) 0xBB)
#define TWAE    0
#define TWSAM1  1
#define TWSAM2  2
#define TWSAM3  3
#define TWSAM4  4
#define TWSAM5  5
#define TWSAM6  6
#define TWSAM7  7

#define TWSA    (*(unsigned char *) 0xBC)
#define TWSA0   0
#define TWSA1   1
#define TWSA2   2
#define TWSA3   3
#define TWSA4   4
#define TWSA5   5
#define TWSA6   6
#define TWSA7   7

#define TWSD    (*(unsigned char *) 0xBD)
#define TWSD0   0
#define TWSD1   1
#define TWSD2   2
#define TWSD3   3
#define TWSD4   4
#define TWSD5   5
#define TWSD6   6
#define TWSD7   7

#define UCSRA   (*(unsigned char *) 0xC0)
#define MPCM    0
#define U2X     1
#define UPE     2
#define DOR     3
#define FE      4
#define UDRE    5
#define TXC     6
#define RXC     7

#define UCSRB   (*(unsigned char *) 0xC1)
#define TXB8    0
#define RXB8    1
#define UCSZ2   2
#define TXEN    3
#define RXEN    4
#define UDRIE   5
#define TXCIE   6
#define RXCIE   7

#define UCSRC   (*(unsigned char *) 0xC2)
#define UCPOL   0
#define UCSZ0   1
#define UCSZ1   2
#define USBS    3
#define UPM0    4
#define UPM1    5
#define UMSEL0  6
#define UMSEL1  7

#define UCSRD   (*(unsigned char *) 0xC3)
#define SFDE    5
#define RXS     6
#define RXSIE   7

#define UBRRL   (*(unsigned char *) 0xC4)
#define UBRRH   (*(unsigned char *) 0xC5)
// Combine UBRRL and UBRRH
#define UBRR    (*(unsigned short *) 0xC4)

#define UDR     (*(unsigned char *) 0xC6)

#define DIDR2   (*(unsigned char *) 0xDE)
#define ADC16D  0
#define ADC17D  1
#define ADC18D  2
#define ADC19D  3
#define ADC20D  4
#define ADC21D  5
#define ADC22D  6
#define ADC23D  7

#define DIDR3   (*(unsigned char *) 0xDF)
#define ADC24D  0
#define ADC25D  1
#define ADC26D  2
#define ADC27D  3

#define TOCPMCOE (*(unsigned char *) 0xE2)
#define TOCC0OE 0
#define TOCC1OE 1
#define TOCC2OE 2
#define TOCC3OE 3
#define TOCC4OE 4
#define TOCC5OE 5
#define TOCC6OE 6
#define TOCC7OE 7

#define TOCPMSA0 (*(unsigned char *) 0xE8)
#define TOCC0S0 0
#define TOCC0S1 1
#define TOCC1S0 2
#define TOCC1S1 3
#define TOCC2S0 4
#define TOCC2S1 5
#define TOCC3S0 6
#define TOCC3S1 7

#define TOCPMSA1 (*(unsigned char *) 0xE9)
#define TOCC4S0 0
#define TOCC4S1 1
#define TOCC5S0 2
#define TOCC5S1 3
#define TOCC6S0 4
#define TOCC6S1 5
#define TOCC7S0 6
#define TOCC7S1 7

#define OSCTCAL0A (*(unsigned char *) 0xF0)
#define OSCTCAL0B (*(unsigned char *) 0xF1)

// Interrupt vectors definitions

// External Interrupt Request 0 
#define EXT_INT0 2
// External Interrupt Request 1 
#define EXT_INT1 3
// Pin Change Interrupt Request 0 
#define PC_INT0 4
// Pin Change Interrupt Request 1 
#define PC_INT1 5
// Pin Change Interrupt Request 2 
#define PC_INT2 6
// Pin Change Interrupt Request 3 
#define PC_INT3 7
// Watchdog Time-out Interrupt 
#define WDT 8
// Timer/Counter1 Capture Event 
#define TIM1_CAPT 9
// Timer/Counter1 Compare Match A 
#define TIM1_COMPA 10
// Timer/Counter1 Compare Match B 
#define TIM1_COMPB 11
// Timer/Counter1 Overflow 
#define TIM1_OVF 12
// Timer/Counter0 Compare Match A 
#define TIM0_COMPA 13
// Timer/Counter0 Compare Match B 
#define TIM0_COMPB 14
// Timer/Counter0 Overflow 
#define TIM0_OVF 15
// SPI Serial Transfer Complete 
#define SPI_STC 16
// USART Start 
#define USART_START 17
// USART Rx Complete 
#define USART_RXC 18
// USART Data Register Empty 
#define USART_DRE 19
// USART Tx Complete 
#define USART_TXC 20
// ADC Conversion Complete 
#define ADC_INT 21
// EEPROM Ready 
#define EE_READY 22
// Analog Comparator 
#define ANA_COMP 23
// Two-wire Serial Interface 
#define TWI_SLAVE 24
// Store Program Memory Read 
#define SPM_READY 25
// Touch Sensing 
#define QTRIP 26

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x01
	.EQU __sm_mask=0x06
	.EQU __sm_adc_noise_red=0x02
	.EQU __sm_powerdown=0x04
	.SET power_ctrl_reg=smcr
	#endif
#endasm

#endif

