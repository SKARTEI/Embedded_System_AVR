// CodeVisionAVR V2.0 C Compiler
// (C) 1998-2011 Pavel Haiduc, HP InfoTech S.R.L.

// I/O registers definitions for the ATtiny1634

#ifndef _TINY1634_INCLUDED_
#define _TINY1634_INCLUDED_

#pragma used+
sfrb ADCL=0x00;
sfrb ADCH=0x01;
sfrw ADCW=0x00; // 16 bit access

sfrb ADCSRB=0x02;
#define ADTS0   0
#define ADTS1   1
#define ADTS2   2
#define ADLAR   3

sfrb ADCSRA=0x03;
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

sfrb ADMUX=0x04;
#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define REFS0   6
#define REFS1   7

sfrb ACSRB=0x05;
#define ACME    2
#define HLEV    6
#define HSEL    7

sfrb ACSRA=0x06;
#define ACIS0   0
#define ACIS1   1
#define ACIC    2
#define ACIE    3
#define ACI     4
#define ACO     5
#define ACBG    6
#define ACD     7

sfrb PINC=0x07;
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

sfrb DDRC=0x08;
#define DDC5   5
#define DDC4   4
#define DDC3   3
#define DDC2   2
#define DDC1   1
#define DDC0   0

sfrb PORTC=0x09;
#define PORTC5  5
#define PORTC4  4
#define PORTC3  3
#define PORTC2  2
#define PORTC1  1
#define PORTC0  0

sfrb PUEC=0x0A;
#define PUEC0   0
#define PUEC1   1
#define PUEC2   2
#define PUEC3   3
#define PUEC4   4
#define PUEC5   5

sfrb USICR=0x0A;
#define USITC   0
#define USICLK  1
#define USICS0  2
#define USICS1  3
#define USIWM0  4
#define USIWM1  5
#define USIOIE  6
#define USISIE  7

sfrb PINB=0x0B;
#define PINB7   7
#define PINB6   6
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

sfrb USISR=0x0B;
#define USICNT0 0
#define USICNT1 1
#define USICNT2 2
#define USICNT3 3
#define USIDC   4
#define USIPF   5
#define USIOIF  6
#define USISIF  7

sfrb DDRB=0x0C;
#define DDB7   7
#define DDB6   6
#define DDB5   5
#define DDB4   4
#define DDB3   3
#define DDB2   2
#define DDB1   1
#define DDB0   0

sfrb USIDR=0x0C;

sfrb PORTB=0x0D;
#define PORTB7  7
#define PORTB6  6
#define PORTB5  5
#define PORTB4  4
#define PORTB3  3
#define PORTB2  2
#define PORTB1  1
#define PORTB0  0

sfrb USIBR=0x0D;

sfrb PUEB=0x0E;
#define PUEB0   0
#define PUEB1   1
#define PUEB2   2
#define PUEB3   3

sfrb PINA=0x0F;
#define PINA7   7
#define PINA6   6
#define PINA5   5
#define PINA4   4
#define PINA3   3
#define PINA2   2
#define PINA1   1
#define PINA0   0

sfrb DDRA=0x10;
#define DDA7   7
#define DDA6   6
#define DDA5   5
#define DDA4   4
#define DDA3   3
#define DDA2   2
#define DDA1   1
#define DDA0   0

sfrb PORTA=0x11;
#define PORTA7  7
#define PORTA6  6
#define PORTA5  5
#define PORTA4  4
#define PORTA3  3
#define PORTA2  2
#define PORTA1  1
#define PORTA0  0

sfrb PUEA=0x12;
#define PUEA0   0
#define PUEA1   1
#define PUEA2   2
#define PUEA3   3
#define PUEA4   4
#define PUEA5   5
#define PUEA6   6
#define PUEA7   7

sfrb PORTCR=0x13;
#define BBMB    1
#define BBMC    2
#define BBMA    0

sfrb GPIOR1=0x15;
sfrb GPIOR0=0x15;
sfrb GPIOR2=0x16;
sfrb OCR0B=0x17;
sfrb OCR0A=0x18;
sfrb TCNT0=0x19;

sfrb TCCR0B=0x1A;
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM02   3
#define FOC0B   6
#define FOC0A   7

sfrb TCCR0A=0x1B;
#define WGM00   0
#define WGM01   1
#define COM0B0  4
#define COM0B1  5
#define COM0A0  6
#define COM0A1  7

sfrb EECR=0x1C;
#define EERE    0
#define EEPE    1
#define EEMPE   2
#define EERIE   3
#define EEPM0   4
#define EEPM1   5

sfrb EEDR=0x1D;
sfrb EEAR=0x1E;
sfrb UDR0=0x20;
sfrw UBRR0=0x21; // Combine UBRR0L and UBRR0H
sfrb UBRR0L=0x21;
sfrb UBRR0H=0x22;

sfrb UCSR0D=0x23;
#define SFDE0   5
#define RXS0    6
#define RXSIE0  7

sfrb UCSR0C=0x24;
#define UCPOL0  0
#define UCSZ00  1
#define UCSZ01  2
#define USBS0   3
#define UPM00   4
#define UPM01   5
#define UMSEL00 6
#define UMSEL01 7

sfrb UCSR0B=0x25;
#define TXB80   0
#define RXB80   1
#define UCSZ02  2
#define TXEN0   3
#define RXEN0   4
#define UDRIE0  5
#define TXCIE0  6
#define RXCIE0  7

sfrb UCSR0A=0x26;
#define MPCM0   0
#define U2X0    1
#define UPE0    2
#define DOR0    3
#define FE0     4
#define UDRE0   5
#define TXC0    6
#define RXC0    7

sfrb PCMSK0=0x27;
#define PCINT0  0
#define PCINT1  1
#define PCINT2  2
#define PCINT3  3
#define PCINT4  4
#define PCINT5  5
#define PCINT6  6
#define PCINT7  7

sfrb PCMSK1=0x28;
#define PCINT8  0
#define PCINT9  1
#define PCINT10 2
#define PCINT11 3

sfrb PCMSK2=0x29;
#define PCINT12 0
#define PCINT13 1
#define PCINT14 2
#define PCINT15 3
#define PCINT16 4
#define PCINT17 5

sfrb CCP=0x2F;

sfrb WDTCSR=0x30;
#define WDP0    0
#define WDP1    1
#define WDP2    2
#define WDE     3
#define WDP3    5
#define WDIE    6
#define WDIF    7

sfrb CLKSR=0x32;
#define CKSEL0  0
#define CKSEL1  1
#define CKSEL2  2
#define CKSEL3  3
#define SUT     4
#define CKOUT_IO 5
#define CSTR    6
#define OSCRDY  7

sfrb CLKPR=0x33;
#define CLKPS0  0
#define CLKPS1  1
#define CLKPS2  2
#define CLKPS3  3

sfrb PRR=0x34;
#define PRADC   0
#define PRUSART0 1
#define PRUSART1 2
#define PRUSI   3
#define PRTIM0  4
#define PRTIM1  5
#define PRTWI   6

sfrb MCUSR=0x35;
#define PORF    0
#define EXTRF   1
#define BORF    2
#define WDRF    3

sfrb MCUCR=0x36;
#define ISC00   0
#define ISC01   1
#define SE      4
#define SM0     5
#define SM1     6

sfrb SPMCSR=0x37;
#define SPMEN   0
#define PGERS   1
#define PGWRT   2
#define RFLB    3
#define CTPB    4
#define RSIG    5

sfrb TIFR=0x39;
#define ICF1    3
#define OCF1B   5
#define OCF1A   6
#define TOV1    7
#define OCF0A   0
#define TOV0    1
#define OCF0B   2

sfrb TIMSK=0x3A;
#define ICIE1   3
#define OCIE1B  5
#define OCIE1A  6
#define TOIE1   7
#define OCIE0A  0
#define TOIE0   1
#define OCIE0B  2

sfrb GIFR=0x3B;
#define PCIF0   3
#define PCIF1   4
#define PCIF2   5
#define INTF0   6

sfrb GIMSK=0x3C;
#define PCIE0   3
#define PCIE1   4
#define PCIE2   5
#define INT0    6

sfrb SPL=0x3D;
sfrb SPH=0x3E;
sfrb SREG=0x3F;
#pragma used-

#define DIDR0   (*(unsigned char *) 0x60)
#define AREFD   0
#define AIN0D   1
#define AIN1D   2
#define ADC0D   3
#define ADC1D   4
#define ADC2D   5
#define ADC3D   6
#define ADC4D   7

#define DIDR1   (*(unsigned char *) 0x61)
#define ADC5D   0
#define ADC6D   1
#define ADC7D   2
#define ADC8D   3

#define DIDR2   (*(unsigned char *) 0x62)
#define ADC9D   0
#define ADC10D  1
#define ADC11D  2

#define OSCCAL0 (*(unsigned char *) 0x63)
#define OSCTCAL0A (*(unsigned char *) 0x64)
#define OSCTCAL0B (*(unsigned char *) 0x65)
#define OSCCAL1 (*(unsigned char *) 0x66)
#define ICR1L   (*(unsigned char *) 0x68)
#define ICR1H   (*(unsigned char *) 0x69)
#define OCR1BL  (*(unsigned char *) 0x6A)
#define OCR1BH  (*(unsigned char *) 0x6B)
#define OCR1AL  (*(unsigned char *) 0x6C)
#define OCR1AH  (*(unsigned char *) 0x6D)
#define TCNT1L  (*(unsigned char *) 0x6E)
#define TCNT1H  (*(unsigned char *) 0x6F)

#define TCCR1C  (*(unsigned char *) 0x70)
#define FOC1B   6
#define FOC1A   7

#define TCCR1B  (*(unsigned char *) 0x71)
#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define TCCR1A  (*(unsigned char *) 0x72)
#define WGM10   0
#define WGM11   1
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define UDR1    (*(unsigned char *) 0x73)

// Combine UBRR1L and UBRR1H
#define UBRR1   (*(unsigned short *) 0x74)
#define UBRR1L  (*(unsigned char *) 0x74)
#define UBRR1H  (*(unsigned char *) 0x75)

#define UCSR1D  (*(unsigned char *) 0x76)
#define SFDE1   5
#define RXS1    6
#define RXSIE1  7

#define UCSR1C  (*(unsigned char *) 0x77)
#define UCPOL1  0
#define UCSZ10  1
#define UCSZ11  2
#define USBS1   3
#define UPM10   4
#define UPM11   5
#define UMSEL10 6
#define UMSEL11 7

#define UCSR1B  (*(unsigned char *) 0x78)
#define TXB81   0
#define RXB81   1
#define UCSZ12  2
#define TXEN1   3
#define RXEN1   4
#define UDRIE1  5
#define TXCIE1  6
#define RXCIE1  7

#define UCSR1A  (*(unsigned char *) 0x79)
#define MPCM1   0
#define U2X1    1
#define UPE1    2
#define DOR1    3
#define FE1     4
#define UDRE1   5
#define TXC1    6
#define RXC1    7

#define TWSD    (*(unsigned char *) 0x7A)
#define TWSD0   0
#define TWSD1   1
#define TWSD2   2
#define TWSD3   3
#define TWSD4   4
#define TWSD5   5
#define TWSD6   6
#define TWSD7   7

#define TWSAM   (*(unsigned char *) 0x7B)
#define TWAE    0
#define TWSAM1  1
#define TWSAM2  2
#define TWSAM3  3
#define TWSAM4  4
#define TWSAM5  5
#define TWSAM6  6
#define TWSAM7  7

#define TWSA    (*(unsigned char *) 0x7C)
#define TWSA0   0
#define TWSA1   1
#define TWSA2   2
#define TWSA3   3
#define TWSA4   4
#define TWSA5   5
#define TWSA6   6
#define TWSA7   7

#define TWSSRA  (*(unsigned char *) 0x7D)
#define TWAS    0       
#define TWDIR   1       
#define TWBE    2       
#define TWC     3       
#define TWRA    4       
#define TWCH    5       
#define TWASIF  6       
#define TWDIF   7       

#define TWSCRB  (*(unsigned char *) 0x7E)
#define TWCMD0  0
#define TWCMD1  1
#define TWAA    2

#define TWSCRA  (*(unsigned char *) 0x7F)
#define TWSME   0
#define TWPME   1
#define TWSIE   2
#define TWEN    3
#define TWASIE  4
#define TWDIE   5
#define TWSHE   7

// Interrupt vectors definitions

// External Interrupt Request 0 
#define EXT_INT0 2
// Pin Change Interrupt Request 0 
#define PC_INT0 3
// Pin Change Interrupt Request 1 
#define PC_INT1 4
// Pin Change Interrupt Request 2 
#define PC_INT2 5
// Watchdog Time-out Interrupt 
#define WDT 6
// Timer/Counter1 Capture Event 
#define TIM1_CAPT 7
// Timer/Counter1 Compare Match A 
#define TIM1_COMPA 8
// Timer/Counter1 Compare Match B 
#define TIM1_COMPB 9
// Timer/Counter1 Overflow 
#define TIM1_OVF 10
// TimerCounter0 Compare Match A 
#define TIM0_COMPA 11
// TimerCounter0 Compare Match B 
#define TIM0_COMPB 12
// Timer/Couner0 Overflow 
#define TIM0_OVF 13
// Analog Comparator 
#define ANA_COMP 14
// ADC Conversion Complete 
#define ADC_INT 15
// USART0 Start 
#define USART0_START 16
// USART0 Rx Complete 
#define USART0_RXC 17
// USART0 Data Register Empty 
#define USART0_DRE 18
// USART0 Tx Complete 
#define USART0_TXC 19
// USART1 Start 
#define USART1_START 20
// USART1 Rx Complete 
#define USART1_RXC 21
// USART1 Data Register Empty 
#define USART1_DRE 22
// USART1 Tx Complete 
#define USART1_TXC 23
// USI Start Condition 
#define USI_STRT 24
// USI Overflow 
#define USI_OVF 25
// Two-wire Serial Interface 
#define TWI 26
#define TWI_SLAVE 26
// EEPROM Ready 
#define EE_RDY 27
// Touch Sensing 
#define QTRIP 28

// Needed by the power management functions (sleep.h)
#define __SLEEP_SUPPORTED__
#define __POWERDOWN_SUPPORTED__
#define __STANDBY_SUPPORTED__
#asm
	#ifndef __SLEEP_DEFINED__
	#define __SLEEP_DEFINED__
	.EQU __se_bit=0x10
	.EQU __sm_mask=0x60
	.EQU __sm_adc_noise_red=0x20
	.EQU __sm_powerdown=0x40
	.EQU __sm_standby=0x60
	.SET power_ctrl_reg=mcucr
	#endif
#endasm

#endif

