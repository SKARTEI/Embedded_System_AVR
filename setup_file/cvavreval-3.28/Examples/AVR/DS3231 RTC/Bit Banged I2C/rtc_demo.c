/*******************************************************************
Maxim DS3231 Real Time Clock Example
(C) Copyright 2014-2015 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

CodeVisionAVR Compiler version 3.23 or later
is required.

The program is designed to be executed on an
Arduino UNO development board, using
an ATmega328P chip running at 16 MHz.

The bit-banged I2C functions are used for communication
with the DS3231 RTC. 

The RTC output is transmitted serially at a
Baud rate of 9600, 8N1 and can be displayed using
the CodeVisionAVR IDE Tools|Terminal.

The connections are:
DS3231 shield - Arduino UNO
SDA           - Digital 3 (PORTD bit 3)
SCL           - Digital 4 (PORTD bit 4)
SQW           - Digital 2 (PORTD bit 2)
GND           - GND
VCC           - Arduino Power 5V

Note: The bit-banged I2C signal allocation is specified in
the Project|Configure|C Compiler|Libraries|I2C menu.

- Arduino's USB must be connected to one of the PC's USB ports.
- The Arduino Virtual Serial Port will be now listed in the
  Device Manager window under Ports (COM & LPT)
- Retain the COMn number of the serial port and go to
  the CodeVisionAVR IDE "Settings|Terminal" menu and set
  the Terminal to use this COM port
- In the Terminal settings specify the Baud rate: 9600
  and disable the "Append On Reception" options
- Start the CodeVisionAVR Terminal using the "Tools|Terminal"
  menu and click on the "Connect" button
- Go to "Project|Configure|After Build" and make sure that
  the Arduino Upload COM port matches the one listed in the
  Windows Device Manager for the Arduino UNO board
- Do Project|Build All.

The program size exceeds the code size limit of the Evaluation
version.
In this case the pre-compiled executable from
\Examples\AVR\DS3231 RTC\Bit Banged I2C\Release\Exe\rtc_demo.hex 
can be uploaded to the Arduino board.
*******************************************************************/

/* I/O registers definitions */
#include <io.h>
/* DS3231 functions for bit-banged I2C */
#include <ds3231.h>
/* Standard I/O: printf */
#include <stdio.h>
/* Delay functions */
#include <delay.h>
/* bool */
#include <stdbool.h>

flash char *week_days[]=
{
"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"
};

/* External Interrupt 0 service routine
   triggered by a falling edge on the
   DS3231 ~INT/SQW output */
interrupt [EXT_INT0] void ext_int0_isr(void)
{
bool update_status=0;
/* Read the DS3231 status register in order
   to identify which alarm has triggered
   the external interrupt */
unsigned char status=ds3231_read_status();
if (status & (1<<DS3231_STS_A1F))
   {
   /* Alarm 1 was triggered */
   printf("***** Alarm 1 was triggered *****\r\n\r\n");
   /* Prepare to clear the alarm 1 interrupt flag */
   status&= ~(1<<DS3231_STS_A1F);
   update_status=1;
   }
if (status & (1<<DS3231_STS_A2F))
   {
   /* Alarm 2 was triggered */
   printf("***** Alarm 2 was triggered *****\r\n\r\n");
   /* Prepare to clear the alarm 2 interrupt flag */
   status&= ~(1<<DS3231_STS_A2F);
   update_status=1;
   }
if (update_status)
   /* Clear the alarm interrupt flag(s) */ 
   ds3231_write(DS3231_STS_REG,status);
}

void main(void)
{
DS3231_ALARM_t alarm;
unsigned char hour,min,sec,week_day,day,month,year;
float temp;

/* Ensure that PORTD bit 2 (INT0) is configured
   as an input with pull-up */
DDRD.2=0;
PORTD.2=1;

/* External Interrupt(s) initialization
   INT0: On
   INT0 Mode: Falling Edge
   INT1: Off */
EICRA=(0<<ISC11) | (0<<ISC10) | (1<<ISC01) | (0<<ISC00);
EIMSK=(0<<INT1) | (1<<INT0);
EIFR=(0<<INTF1) | (1<<INTF0);

/* USART initialization
   Communication Parameters: 8 Data, 1 Stop, No Parity
   USART Receiver: Off
   USART Transmitter: On
   USART0 Mode: Asynchronous
   USART Baud Rate: 9600 (Double Speed Mode) @ 16MHz */ 
UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (1<<U2X0) | (0<<MPCM0);
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (0<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
UCSR0C=(0<<UMSEL01) | (0<<UMSEL00) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
UBRR0H=0x00;
UBRR0L=0xCF;

/* Enable interrupts so that INT0 can be used */
#asm("sei")

/* Initialize the DS3231 RTC:
   - use the ~INT/SQW pin to trigger an 
     interrupt when an alarm occurs
   - the 32kHz output is disabled
   - alarms are initially disabled */
rtc_init(DS3231_INT_ON,false);

/* Set time 12:00:00 */
rtc_set_time(12,0,0); 

/* Set date Monday 24/08/2015 */
rtc_set_date(1,24,8,15); 

/* Set alarm 1 to be triggered at 12:00:15 on day 24,
   each day at the same time */
alarm.sec=15;
alarm.min=0;
alarm.hour=12;
alarm.day=24;
alarm.use_sec=1;
alarm.use_min=1;
alarm.use_hour=1;
alarm.use_day=1; 
alarm.enabled=1;
rtc_set_alarm1(&alarm);

/* Set alarm 2 to be triggered at 12:01:00,
   each day at the same time
   Note: only the modified values of 
   the alarm structure are re-assigned */
alarm.sec=0;
alarm.min=1;
/* seconds are not implemented for alarm 2,
   see the DS3231 datasheet */
alarm.use_sec=0; 
/* Don't use the day, the alarm will be 
   triggered each day at the same time */
alarm.use_day=0; 
rtc_set_alarm2(&alarm);

/* Continuously display the time, date and temperature */
while (1)
      {
      /* Read the time from the RTC */
      rtc_get_time(&hour,&min,&sec);
      
      /* Read the date from the RTC */
      rtc_get_date(&week_day,&day,&month,&year);
      
      /* Read the temperature */
      temp=ds3231_get_temp();
      
      /* Prevent the alarm triggered INT0 to occur during printf,
         because printf, used also in ext_int0_isr, is not reentrant */
      #asm("cli")
      
      /* Output the time & date using the USART */
      printf("%2d:%02d:%02d, %p, %2d/%02d/%d\r\n",
             hour,min,sec,week_days[week_day-1],day,month,2000+year);
      
      /* Output the temperature using the USART */
      printf("t=%.2fC\r\n\r\n",temp);
      
      /* Alarm triggered INT0 can be processed now */
      #asm("sei")

      /* 0.5 second delay */
      delay_ms(500);
      }
}
