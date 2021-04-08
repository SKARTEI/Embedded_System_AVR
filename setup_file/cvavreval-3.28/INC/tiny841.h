// CodeVisionAVR V3.0 C Compiler
// (C) 1998-2014 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATtiny841

#ifndef _TINY841_INCLUDED_
#define _TINY841_INCLUDED_

#pragma used+
sfrb ADCSRB=0x04;
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2
#define ADLAR   3

sfrb ADCSRA=0x05;
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

sfrw ADCW=0x06;
sfrb ADCL=0x06;
sfrb ADCH=0x07;

sfrb ADMUXB=0x08;
#define GSEL0   0
#define GSEL1   1
#define REFS0   5
#define REFS1   6
#define REFS2   7

sfrb ADMUXA=0x09;
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define MUX5    5

sfrb ACSR0A=0x0A;
#define ACIS00  0
#define ACIS01  1
#define ACIC0   2
#define ACIE0   3
#define ACI0    4
#define ACO0    5
#define ACPMUX2 6
#define ACD0    7

sfrb ACSR0B=0x0B;
#define ACPMUX0 0
#define ACPMUX1 1
#define ACNMUX0 2
#define ACNMUX1 3
#define ACOE0   4
#define HLEV0   6
#define HSEL0   7

sfrb ACSR1A=0x0C;
#define ACIS10  0
#define ACIS11  1
#define ACIC1   2
#define ACIE1   3
#define ACI1    4
#define ACO1    5
#define ACBG1   6
#define ACD1    7

sfrb ACSR1B=0x0D;
#define ACME1   2
#define ACOE1   4
#define HLEV1   6
#define HSEL1   7

sfrb TIFR1=0x0E;
#define TOV1    0
#define OCF1A   1
#define OCF1B   2
#define ICF1    5

sfrb TIMSK1=0x0F;
#define TOIE1   0
#define OCIE1A  1
#define OCIE1B  2
#define ICIE1   5

sfrb TIFR2=0x10;
#define TOV2    0
#define OCF2A   1
#define OCF2B   2
#define ICF2    5

sfrb TIMSK2=0x11;
#define TOIE2   0
#define OCIE2A  1
#define OCIE2B  2
#define ICIE2   5

sfrb PCMSK0=0x12;
#define PCINT7  7
#define PCINT6  6
#define PCINT5  5
#define PCINT4  4
#define PCINT3  3
#define PCINT2  2
#define PCINT1  1
#define PCINT0  0

sfrb GPIOR0=0x13;
sfrb GPIOR1=0x14;
sfrb GPIOR2=0x15;

sfrb PINB=0x16;
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

sfrb DDRB=0x17;
#define DDB3   3
#define DDB2   2
#define DDB1   1
#define DDB0   0

sfrb PORTB=0x18;
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

sfrb PINA=0x19;
#define PINA7   7
#define PINA6   6
#define PINA5   5
#define PINA4   4
#define PINA3   3
#define PINA2   2
#define PINA1   1
#define PINA0   0

sfrb DDRA=0x1A;
#define DDA7   7
#define DDA6   6
#define DDA5   5
#define DDA4   4
#define DDA3   3
#define DDA2   2
#define DDA1   1
#define DDA0   0

sfrb PORTA=0x1B;
#define PORTA7  7
#define PORTA6  6
#define PORTA5  5
#define PORTA4  4
#define PORTA3  3
#define PORTA2  2
#define PORTA1  1
#define PORTA0  0

sfrb EECR=0x1C;
#define EERE    0
#define EEPE    1
#define EEMPE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5

sfrb EEDR=0x1D;
sfrw EEAR=0x1E;
sfrb EEARL=0x1E;
sfrb EEARH=0x1F;

sfrb PCMSK1=0x20;
#define PCINT11 3
#define PCINT10 2
#define PCINT9  1
#define PCINT8  0

sfrb WDTCSR=0x21;
#define WDE     3
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDP3    5
#define WDIE    6
#define WDIF    7

sfrb TCCR1C=0x22;
#define FOC1B   6
#define FOC1A   7

sfrb GTCCR=0x23;
#define PSR     0
#define TSM     7

sfrw ICR1=0x24;
sfrb ICR1L=0x24;
sfrb ICR1H=0x25;
sfrw OCR1B=0x28;
sfrb OCR1BL=0x28;
sfrb OCR1BH=0x29;
sfrw OCR1A=0x2A;
sfrb OCR1AL=0x2A;
sfrb OCR1AH=0x2B;
sfrw TCNT1=0x2C;
sfrb TCNT1L=0x2C;
sfrb TCNT1H=0x2D;

sfrb TCCR1B=0x2E;
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

sfrb TCCR1A=0x2F;
#define WGM10   0
#define WGM11   1
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

sfrb TCCR0A=0x30;
#define WGM00   0
#define WGM01   1
#define COM0B0  4
#define COM0B1  5
#define COM0A0  6
#define COM0A1  7

sfrb TCNT0=0x32;

sfrb TCCR0B=0x33;
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM02   3
#define FOC0B   6
#define FOC0A   7

sfrb MCUSR=0x34;
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3

sfrb MCUCR=0x35;
#define ISC00   0
#define ISC01   1
#define SM0     3
#define SM1     4
#define SE      5

sfrb OCR0A=0x36;

sfrb SPMCSR=0x37;
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define RFLB    3
#define CTPB    4
#define RSIG    5

sfrb TIFR0=0x38;
#define TOV0    0
#define OCF0A   1
#define OCF0B   2

sfrb TIMSK0=0x39;
#define TOIE0   0
#define OCIE0A  1
#define OCIE0B  2

sfrb GIFR=0x3A;
#define PCIF0   4
#define PCIF1   5
#define INTF0   6

sfrb GIMSK=0x3B;
#define PCIE0   4
#define PCIE1   5
#define INT0    6

sfrb OCR0B=0x3C;
sfrb SPL=0x3D;
sfrb SPH=0x3E;
sfrb SREG=0x3F;
#pragma used-

#define DIDR0   (*(unsigned char *) 0x60)
#define ADC0D   0
#define ADC1D   1
#define ADC2D   2
#define ADC3D   3
#define ADC4D   4
#define ADC5D   5
#define ADC6D   6
#define ADC7D   7

#define DIDR1   (*(unsigned char *) 0x61)
#define ADC11D  0
#define ADC10D  1
#define ADC8D   2
#define ADC9D   3

#define PUEB    (*(unsigned char *) 0x62)
#define PUEB0   0
#define PUEB1   1
#define PUEB2   2
#define PUEB3   3

#define PUEA    (*(unsigned char *) 0x63)
#define PUEA0   0
#define PUEA1   1
#define PUEA2   2
#define PUEA3   3
#define PUEA4   4
#define PUEA5   5
#define PUEA6   6
#define PUEA7   7

#define PORTCR  (*(unsigned char *) 0x64)
#define BBMB    1
#define BBMA    0

#define REMAP   (*(unsigned char *) 0x65)
#define U0MAP   0 // 01082014_1
#define SPIMAP  1 // 01082014_1

#define TOCPMCOE (*(unsigned char *) 0x66)
#define TOCC0OE 0
#define TOCC1OE 1
#define TOCC2OE 2
#define TOCC3OE 3
#define TOCC4OE 4
#define TOCC5OE 5
#define TOCC6OE 6
#define TOCC7OE 7

#define TOCPMSA0 (*(unsigned char *) 0x67)
#define TOCC0S0 0
#define TOCC0S1 1
#define TOCC1S0 2
#define TOCC1S1 3
#define TOCC2S0 4
#define TOCC2S1 5
#define TOCC3S0 6
#define TOCC3S1 7

#define TOCPMSA1 (*(unsigned char *) 0x68)
#define TOCC4S0 0
#define TOCC4S1 1
#define TOCC5S0 2
#define TOCC5S1 3
#define TOCC6S0 4
#define TOCC6S1 5
#define TOCC7S0 6
#define TOCC7S1 7

#define PHDE    (*(unsigned char *) 0x6A)
#define PHDEA0  0
#define PHDEA1  1

#define PRR     (*(unsigned char *) 0x70)
#define PRADC   0
#define PRTIM0  1
#define PRTIM1  2
#define PRTIM2  3
#define PRSPI   4
#define PRUSART0 5
#define PRUSART1 6
#define PRTWI   7

#define CCP     (*(unsigned char *) 0x71)

#define CLKCR   (*(unsigned char *) 0x72)
#define CKSEL0  0
#define CKSEL1  1
#define CKSEL2  2
#define CKSEL3  3
#define SUT     4
#define CKOUTC  5
#define CSTR    6
#define OSCRDY  7

#define CLKPR   (*(unsigned char *) 0x73)
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLKPS3  3

#define OSCCAL0 (*(unsigned char *) 0x74)
#define OSCTCAL0A (*(unsigned char *) 0x75)
#define OSCTCAL0B (*(unsigned char *) 0x76)
#define OSCCAL1 (*(unsigned char *) 0x77)
#define UDR0    (*(unsigned char *) 0x80)
#define UBRR0L  (*(unsigned char *) 0x81)
#define UBRR0H  (*(unsigned char *) 0x82)

#define UCSR0D  (*(unsigned char *) 0x83)
#define SFDE0   5
#define RXS0    6
#define RXSIE0  7

#define UCSR0C  (*(unsigned char *) 0x84)
#define UCPOL0  0
#define UCSZ00  1
#define UCSZ01  2
#define USBS0   3
#define UPM00   4
#define UPM01   5
#define UMSEL00 6
#define UMSEL01 7

#define UCSR0B  (*(unsigned char *) 0x85)
#define TXB80   0
#define RXB80   1
#define UCSZ02  2
#define TXEN0   3
#define RXEN0   4
#define UDRIE0  5
#define TXCIE0  6
#define RXCIE0  7

#define UCSR0A  (*(unsigned char *) 0x86)
#define MPCM0   0
#define U2X0    1
#define UPE0    2
#define DOR0    3
#define FE0     4
#define UDRE0   5
#define TXC0    6
#define RXC0    7

#define UDR1    (*(unsigned char *) 0x90)
#define UBRR1L  (*(unsigned char *) 0x91)
#define UBRR1H  (*(unsigned char *) 0x92)

#define UCSR1D  (*(unsigned char *) 0x93)
#define SFDE1   5
#define RXS1    6
#define RXSIE1  7

#define UCSR1C  (*(unsigned char *) 0x94)
#define UCPOL1  0
#define UCSZ10  1
#define UCSZ11  2
#define USBS1   3
#define UPM10   4
#define UPM11   5
#define UMSEL10 6
#define UMSEL11 7

#define UCSR1B  (*(unsigned char *) 0x95)
#define TXB81   0
#define RXB81   1
#define UCSZ12  2
#define TXEN1   3
#define RXEN1   4
#define UDRIE1  5
#define TXCIE1  6
#define RXCIE1  7

#define UCSR1A  (*(unsigned char *) 0x96)
#define MPCM1   0
#define U2X1    1
#define UPE1    2
#define DOR1    3
#define FE1     4
#define UDRE1   5
#define TXC1    6
#define RXC1    7

#define TWSD    (*(unsigned char *) 0xA0)
#define TWSD0   0
#define TWSD1   1
#define TWSD2   2
#define TWSD3   3
#define TWSD4   4
#define TWSD5   5
#define TWSD6   6
#define TWSD7   7

#define TWSAM   (*(unsigned char *) 0xA1)
#define TWAE    0
#define TWSAM1  1
#define TWSAM2  2
#define TWSAM3  3
#define TWSAM4  4
#define TWSAM5  5
#define TWSAM6  6
#define TWSAM7  7

#define TWSA    (*(unsigned char *) 0xA2)
#define TWSA7   7
#define TWSA6   6
#define TWSA5   5
#define TWSA4   4
#define TWSA3   3
#define TWSA2   2
#define TWSA1   1
#define TWSA0   0

#define TWSSRA  (*(unsigned char *) 0xA3)
#define TWAS    0
#define TWDIR   1
#define TWBE    2
#define TWC     3
#define TWRA    4
#define TWCH    5
#define TWASIF  6
#define TWDIF   7

#define TWSCRB  (*(unsigned char *) 0xA4)
#define TWCMD0  0
#define TWCMD1  1
#define TWAA    2
#define TWHNM   3

#define TWSCRA  (*(unsigned char *) 0xA5)
#define TWSME   0
#define TWPME   1
#define TWSIE   2
#define TWEN    3
#define TWASIE  4
#define TWDIE   5
#define TWSHE   7

#define SPDR    (*(unsigned char *) 0xB0)

#define SPSR    (*(unsigned char *) 0xB1)
#define SPI2X   0
#define WCOL    6
#define SPIF    7

#define SPCR    (*(unsigned char *) 0xB2)
#define SPR0    0
#define SPR1    1
#define CPHA    2
#define CPOL    3
#define MSTR    4
#define DORD    5
#define SPE     6
#define SPIE    7

#define ICR2L   (*(unsigned char *) 0xC0)
#define ICR2H   (*(unsigned char *) 0xC1)
#define OCR2BL  (*(unsigned char *) 0xC2)
#define OCR2BH  (*(unsigned char *) 0xC3)
#define OCR2AL  (*(unsigned char *) 0xC4)
#define OCR2AH  (*(unsigned char *) 0xC5)
#define TCNT2L  (*(unsigned char *) 0xC6)
#define TCNT2H  (*(unsigned char *) 0xC7)

#define TCCR2C  (*(unsigned char *) 0xC8)
#define FOC2B   6
#define FOC2A   7

#define TCCR2B  (*(unsigned char *) 0xC9)
#define CS20    0
#define CS21    1
#define CS22    2
#define WGM22   3
#define WGM23   4
#define ICES2   6
#define ICNC2   7

#define TCCR2A  (*(unsigned char *) 0xCA)
#define WGM20   0
#define WGM21   1
#define COM2B0  4
#define COM2B1  5
#define COM2A0  6
#define COM2A1  7

// Interrupt vectors definitions

// External Interrupt Request 0
#define EXT_INT0 2
// Pin Change Interrupt Request 0
#define PC_INT0 3
// Pin Change Interrupt Request 1
#define PC_INT1 4
// Watchdog Time-out Interrupt
#define WDT 5
// Timer/Counter1 Capture Event
#define TIM1_CAPT 6
// Timer/Counter1 Compare Match A
#define TIM1_COMPA 7
// Timer/Counter1 Compare Match B
#define TIM1_COMPB 8
// Timer/Counter1 Overflow
#define TIM1_OVF 9
// TimerCounter0 Compare Match A
#define TIM0_COMPA 10
// TimerCounter0 Compare Match B
#define TIM0_COMPB 11
// Timer/Counter0 Overflow
#define TIM0_OVF 12
// Analog Comparator 0
#define ANA_COMP0 13
// ADC Conversion Complete
#define ADC_INT 14
// EEPROM Ready
#define EE_READY 15
// Analog Comparator 1
#define ANA_COMP1 16
// Timer/Counter2 Capture Event
#define TIM2_CAPT 17
// Timer/Counter2 Compare Match A
#define TIM2_COMPA 18
// Timer/Counter2 Compare Match B
#define TIM2_COMPB 19
// Timer/Counter2 Overflow
#define TIM2_OVF 20
// SPI Serial Transfer Complete
#define SPI_STC 21
// USART0 Start
#define USART0_START 22
// USART0 Rx Complete
#define USART0_RXC 23
// USART0 Data Register Empty
#define USART0_DRE 24
// USART0 Tx Complete
#define USART0_TXC 25
// USART1 Start
#define USART1_START 26
// USART1 Rx Complete
#define USART1_RXC 27
// USART1 Data Register Empty
#define USART1_DRE 28
// USART1 Tx Complete
#define USART1_TXC 29
// Two-wire Serial Interface
#define TWI_SLAVE 30

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x20
	.EQU __sm_mask=0x18
	.EQU __sm_adc_noise_red=0x08
	.EQU __sm_powerdown=0x10
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#endif

