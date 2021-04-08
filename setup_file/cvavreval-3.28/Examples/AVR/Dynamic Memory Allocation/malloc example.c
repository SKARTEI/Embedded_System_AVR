/****************************************************************
Demo program for the dynamic memory allocation functions.

(C) Copyright 2014-2015 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

This demo is designed to run on an Arduino UNO
development board with an ATmega328P chip
clocked at 16 MHz.

The board output is transmitted serially at a
Baud rate of 9600, 8N1 and can be displayed using
the CodeVisionAVR IDE Tools|Terminal.

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
****************************************************************/

// I/O registers definitions
#include <io.h>
// printf
#include <stdio.h>
// malloc, free
#include <stdlib.h>
// strcpyf
#include <string.h>

void main(void)
{
char *text; // pointer to the char string located in Heap

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

printf("Dynamic memory allocation example\r\n");

// Allocate in the Heap a block of 16 bytes to be used 
// Note: The space occupied in Heap by a block will be 
// block_size+4 bytes
// In our case it will be 16+4=20 bytes
// Also an additional 4 bytes from Heap are always used 
// by the dynamic allocation functions.
// So for our example a minimum value of 24 bytes must be specified
// in Project|Configure|C Compiler|Code Generation -> Heap Size
text=malloc(16);
if (text!=NULL) 
   {
   printf("A block of 16 bytes was allocated in the Heap\r\n");
   // Copy a char string from FLASH to Heap
   // Note: The string length, including the NULL terminator,
   // must not exceed 16 characters
   strcpyf(text,"Hello world!");
   // Display the string from the Heap
   printf("String from Heap: \"%s\" \r\n",text);
   // Free Heap memory
   free(text);
   printf("Heap memory was freed\r\n");
   }
else
   printf("Error allocating memory\r\n");
// Stop here
while (1);
}
