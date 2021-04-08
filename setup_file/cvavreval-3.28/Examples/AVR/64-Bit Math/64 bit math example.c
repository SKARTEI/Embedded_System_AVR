/****************************************************************
64-bit integer math library example.

(C) Copyright 2014-2015 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

This example is designed to run on an Arduino UNO
development board with an ATmega328P chip
clocked at 16 MHz.

The sensor output is transmitted serially at a
Baud rate of 9600, 8N1 and can be displayed using
the CodeVisionAVR IDE Tools|Terminal.
  
The program size exceeds the code size limit of the Evaluation
version.
In this case the pre-compiled executable from
\Examples\AVR\64-Bit Math\Release\Exe\64 bit math example.hex 
can be uploaded to the Arduino board.
****************************************************************/

// I/O registers definitions
#include <io.h>
// Standard I/O: printf
#include <stdio.h>
// 64-bit integer math functions
#include <math64.h>

char buf1[64];
char buf2[64];
char buf3[64];

void main(void)
{
// Initialize 64-bit variables during declaration
long64_t x=__INIT64(100000000000000LL);
long64_t y=__INIT64(2500);

long64_t z;
long q;

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

printf("64-bit integer math library example\r\n\r\n");

z=add64(x,y);

printf("Display result using 'printl64':\r\n");
printl64(x); // Output the 64-bit integer x in decimal format
printf(" + ");
printl64(y);
printf(" = ");
printl64(z);
printf("\r\n");

printf("Display result using 'ltoa64' and 'printf':\r\n");
ltoa64(x,buf1); // Convert the 64-bit integer x to decimal in buf1
ltoa64(y,buf2);
ltoa64(z,buf3);
printf("%s + %s = %s\r\n",buf1,buf2,buf3);

// The sqrt64 function returns an unsigned long
// so its result can be directly displayed by printf
printf("sqrt64(%s) = %lu\r\n",buf1,sqrt64(x));

// Assign a numeral to a long64_t variable
__EQU64(y,55); // y=55

// 64-bit multiplication
z=mul64(x,y);
ltoa64(x,buf1);
ltoa64(y,buf2);
ltoa64(z,buf3);
printf("%s * %s = %s\r\n",buf1,buf2,buf3);

__EQU64(y,5000000LL); // y=5000000LL

// 64-bit division
z=div64(x,y);
ltoa64(x,buf1);
ltoa64(y,buf2);
ltoa64(z,buf3);
printf("%s / %s = %s\r\n",buf1,buf2,buf3);

// 64-bit modulo
__EQU64(y,339); // y=339
z=mod64(x,y);
ltoa64(x,buf1);
ltoa64(y,buf2);
ltoa64(z,buf3);
printf("%s %% %s = %s\r\n",buf1,buf2,buf3);

// Assign a long64_t variable to another long64_t variable
y=z;

// 64-bit substraction
z=sub64(x,y);
ltoa64(x,buf1);
ltoa64(y,buf2);
ltoa64(z,buf3);
printf("%s - %s = %s\r\n",buf1,buf2,buf3);

// Display a hexadecimal number using
// ltox and printf
ltox64(z,buf1); // Convert the 64-bit integer x to hexadecimal in buf1
printf("%s = 0x%s\r\n",buf3,buf1);

// Display a hexadecimal number using printx64
printf("0x");
printx64(z); // Output the 64-bit integer z in hexadecimal format
printf(" = ");
printl64(z);
printf("\r\n");

// 64-bit arithmetic shift right
ltox64(z,buf1);
asr64(&z,16); // z=z>>16
ltox64(z,buf2);
printf("0x%s >> 16 = 0x%s\r\n",buf1,buf2);

// 64-bit logic negation
z=com64(z);
ltox64(z,buf1);
printf("~ 0x%s = 0x%s\r\n",buf2,buf1);

// 64-bit arithmetic negation
z=neg64(x);
ltoa64(x,buf1);
ltoa64(z,buf2);
printf("- (%s) = %s\r\n",buf1,buf2);

// 64-bit absolute value
x=abs64(z);
ltoa64(z,buf1);
ltoa64(x,buf2);
printf("abs64(%s) = %s\r\n",buf1,buf2);

// Assign 32-bit signed long to 64-bit long64_t
q=-1234567L;
x=tolong64(q);
ltoa64(x,buf1);
printf("Assign 32-bit signed long to 64-bit long64_t: %s\r\n",buf1);

// 64-bit increment
inc64(&x); // ++x
ltoa64(x,buf2);
printf("%s + 1= %s\r\n",buf1,buf2);

// Some complex calculations...
__EQU64(x,12345678900000LL); // x=12345678900000LL;
ltoa64(x,buf1);
__EQU64(y,55); // y=55;
ltoa64(y,buf2);
__EQU64(z,640000000000000000LL); // z=640000000000000000LL;
ltoa64(z,buf3);
printf("%s * %s + sqrt(%s) - 12345 = ",buf1,buf2,buf3);
// Note: sqrt64 returns a 32-bit long,
// so it must be converted to a 64-bit long64_t 
// expected by add64, using the tolong64 function
// The same applies to the 12345 16-bit integer that
// must be converted to 64-bit long64_t
// expected by the sub64 function
// z=x*y+sqrt(z)-12345
z=sub64(add64(mul64(x,y),tolong64(sqrt64(z))),tolong64(12345)); 
printl64(z);
printf("\r\n");

// Stop here
while (1);
}
