/*******************************************************************
Bosch BMP280 Pressure Sensor Example
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

The connections are:
BMP280 shield - Arduino UNO
SDA           - A4 (SDA) --- 3.3k..10k resistor --- Arduino Power 3.3V
SCL           - A5 (SCL) --- 3.3k..10k resistor --- Arduino Power 3.3V
CSB           - Arduino Power 3.3V 
SDO           - GND
GND           - GND
+3.3V         - Arduino Power 3.3V

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

Note: The BMP280 sensor is sensitive to light.
In order to obtain correct measurements,
please place it under a piece of black foam.

The program size exceeds the code size limit of the Evaluation
version.
In this case the pre-compiled executable from
\Examples\AVR\Pressure Sensors\BMP280\Release\Exe\altimeter.hex 
can be uploaded to the Arduino board.
*******************************************************************/

// I/O registers definitions
#include <io.h>
// Standard I/O: printf
#include <stdio.h>
// Delay functions
#include <delay.h>
// BMP280 Pressure sensor functions
#include <bmp280_twi.h>
// Altitude calculation function
#include <altitude.h>

void check_result(short n)
{
switch (n)
       {
       case BMP280_COMM_ERROR:
       printf("TWI communication error\r\n");
       goto halt;
       
       case BMP280_INIT_ERROR:
       printf("Initialization parameters are not correct\r\n");
       goto halt;
       
       case BMP280_MEAS_ERROR:
       printf("Measurement error\r\n");

       halt:
       while(1);
       }
}

void main(void)
{
float temperature,pressure,altitude;

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

printf("BMP280 Pressure sensor demo\r\n");

// Initialize the BMP280 pressure sensor
// Use the Ultra High Resolution Mode
check_result(bmp280_init(BMP280_I2C_ADDR_SDO_LOW,BMP280_ULTRA_HI_RES_MODE,BMP280_FILTER_COEFF_8));
printf("BMP280 initialized OK\r\n\r\n");

while (1)
    {
    // Measure the temperature in degrees [C]
    temperature=bmp280_temperature();
    // Check for errors
    check_result(temperature);
    // Measure the absolute pressure in [Pa]
    pressure=bmp280_pressure();
    // Check for errors
    check_result(pressure);
    // Calculate the absolute altitude above sea level [m]
    altitude=abs_altitude(pressure,PRESSURE_SEA_LEVEL_STD);
    // Display the results
    printf("t=%5.1fC P=%7.2fhPa Alt=%6.1fm\r\n",temperature,pressure/100.0,altitude);
    // 1 second delay between measurements
    delay_ms(1000);
    }
}
