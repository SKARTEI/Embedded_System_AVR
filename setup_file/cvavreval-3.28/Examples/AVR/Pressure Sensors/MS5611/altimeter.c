/****************************************************************
Demo program for the Measurement Specialties MS5611-01BA03
barometric presure sensor.

(C) Copyright 2014-2015 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

This demo is designed to run on an Arduino UNO
development board with an ATmega328P chip
clocked at 16 MHz.

The sensor output is transmitted serially at a
Baud rate of 9600, 8N1 and can be displayed using
the CodeVisionAVR IDE Tools|Terminal.

The MS5611-01BA03 is mounted on a GY-63 module that
contains a 3.3V voltage regulator and level translator
circuits from 3.3V (sensor) to 5V (ATmega328P) for
the SDA and SCL signals.

The connections between GY-63 and the Arduino UNO
are outlined below:

GY-63    Arduino UNO
PS    -  not connected (has a 2.2k pull-up resistor to +3.3V)
SDA   -  Analog In A4 (PORTC.4 SDA)
SCL   -  Analog In A5 (PORTC.5 SCL)
SDO   -  not connected
CSB   -  GND
GND   -  GND
VCC   -  +5V

The GY-63 module is available for sale on www.ebay.com
The schematic is available in the "GY63 Schematic.jpg" file.

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

Notes:
- In case the GY-63 module is not available and
  you wish to connect the sensor directly to the Arduino UNO,
  the SDA and SCL signals must use 3.3k pull-up resistors
  connected to +3.3V pin of the Arduino UNO.
  The PS signal must also be tied to +3.3V.
  The MS5611-01BA03 must be of course powered from +3.3V too.
- The MS5611-01BA03 sensor is light sensitive.
  Place some foam over it to avoid direct light exposure.
  
The program size exceeds the code size limit of the Evaluation
version.
In this case the pre-compiled executable from
\Examples\AVR\Pressure Sensors\MS5611\Release\Exe\altimeter.hex 
can be uploaded to the Arduino board.
****************************************************************/

// I/O registers definitions
#include <io.h>
// Standard I/O: printf
#include <stdio.h>
// Delay functions
#include <delay.h>
// MS5611 Pressure sensor functions
#include <ms5611_twi.h>
// Altitude calculation function
#include <altitude.h>

void main(void)
{
float temperature,pressure,altitude;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: Off
// USART Transmitter: On
// USART0 Mode: Asynchronous
// USART Baud Rate: 9600 @ 16 MHz
UCSR0A=(0<<RXC0) | (0<<TXC0) | (0<<UDRE0) | (0<<FE0) | (0<<DOR0) | (0<<UPE0) | (0<<U2X0) | (0<<MPCM0);
UCSR0B=(0<<RXCIE0) | (0<<TXCIE0) | (0<<UDRIE0) | (0<<RXEN0) | (1<<TXEN0) | (0<<UCSZ02) | (0<<RXB80) | (0<<TXB80);
UCSR0C=(0<<UMSEL01) | (0<<UMSEL00) | (0<<UPM01) | (0<<UPM00) | (0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00) | (0<<UCPOL0);
UBRR0H=0x00;
UBRR0L=0x67;

// TWI initialization
// Mode: TWI Master
// Bit Rate: 100 kHz
twi_master_init(100);

// Globally enable interrupts
#asm("sei")

printf("CodeVisionAVR MS5611-01BA03 Presure sensor demo\r\n");

// Initializes the MS5611 library variables, issues a Reset command
// and reads the calibration data from the device PROM,
// checking its CRC
switch (ms5611_init(MS5611_BUS_ADDR_CSB_LOW,MS5611_OSR_4096))
       {
       case MS5611_INIT_OK:
       // Display the device calibration data from the PROM
       printf("Calibration data read OK\r\n");
       break;
       
       case MS5611_CRC_ERROR:
       printf("Calibration data has failed the CRC check\r\n");
       goto halt;
       
       default:
       twi_comm_error:
       printf("TWI communication error\r\n");
       
       halt:
       while (1); // Stop here in case of error
       }

while (1)
      {
      // Measure the temperature in degrees [C]
      temperature=ms5611_temperature();
      // Check for any TWI communication errors with the sensor,
      // in order to ensure that we have a valid temperature value
      if (temperature==MS5611_COMM_ERROR) goto twi_comm_error;
      // Measure the absolute pressure in [Pa]
      pressure=ms5611_pressure();
      // Check for any TWI communication errors with the sensor,
      // in order to ensure that we have a valid pressure value
      if (pressure==MS5611_COMM_ERROR) goto twi_comm_error;
      // Calculate the absolute altitude above sea level [m]
      altitude=abs_altitude(pressure,PRESSURE_SEA_LEVEL_STD);
      // Display the results
      printf("t=%6.2fC P=%7.2fhPa Alt=%6.1fm\r\n",temperature,pressure/100.0,altitude);
      // 1 second delay between measurements
      delay_ms(1000);
      }
}
