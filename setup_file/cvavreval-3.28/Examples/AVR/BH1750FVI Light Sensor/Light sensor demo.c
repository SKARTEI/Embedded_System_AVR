/*******************************************************************
ROHM Semiconductor BH1750FVI Ambient Light Sensor Example
® Copyright 2014-2016 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

CodeVisionAVR Compiler version 3.26 or later
is required.

The program is designed to be executed on an
Arduino UNO development board, using
an ATmega328P chip running at 16 MHz.

The sensor output is transmitted serially at a
Baud rate of 9600, 8N1 and can be displayed using
the CodeVisionAVR IDE Tools|Terminal.

A GY30 breakout board with a BH1750FVI light sensor is
used for the purpose of the demo.

The connections are:
GY30 - Arduino UNO
SDA  - A4 (SDA)
SCL  - A5 (SCL)
ADDR - GND
GND  - GND
VCC  - Arduino Power 5V

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
*******************************************************************/

// I/O registers definitions
#include <io.h>
// Standard I/O: printf
#include <stdio.h>
// Delay functions
#include <delay.h>
// BH1750FVI Light sensor functions
#include <bh1750_twi.h>

void check_result(signed char n)
{
switch (n)
       {
       case BH1750_COMM_ERROR:
       printf("TWI communication error\r\n");
       goto halt;
       
       case BH1750_INIT_ERROR:
       printf("Device not properly initialized\r\n");

       halt:
       while(1);
       }
}

void main(void)
{
float illuminance;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: Off
// USART Transmitter: On
// USART0 Mode: Asynchronous
// USART Baud Rate: 9600 (Double Speed Mode) @ 16MHz
UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (1<<U2X0) | (0<<MPCM0);
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (0<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
UCSR0C=(0<<UMSEL01) | (0<<UMSEL00) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
UBRR0H=0x00;
UBRR0L=0xCF;

// TWI initialization
// Mode: TWI Master
// Bit Rate: 100 kHz
twi_master_init(100);

#asm("sei")

printf("BH1750FVI Light sensor demo\r\n");

// Initialize the BH1750FVI light sensor with ADDR pin=0
check_result(bh1750_init(BH1750_I2C_ADDR0,BH1750_MT_REG_DEFAULT));

while (1)
    {
    // Start a single measurement for device with ADDR pin=0
    // and high resolution mode
    check_result(bh1750_start(BH1750_I2C_ADDR0,BH1750_SINGLE_CONV_HIGH_RES));
    // Wait for the measurement to complete
    delay_ms(120);
    // Measure the light level
    illuminance=bh1750_rdlight(BH1750_I2C_ADDR0);
    // Check for errors
    check_result(illuminance);
    // Display the measurement result
    printf("Illuminance=%7.1flx\r\n",illuminance);
    // 0.5 second delay between measurements
    delay_ms(500);
    }
}
