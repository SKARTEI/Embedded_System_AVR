#include <mega128.h>
#include <delay.h>
#include <stdio.h>

//----------------------------------------------------

void uart_ini() { // 시리얼 초기화 함수입니다.

   UCSR0A=0;         // 0x0
   UCSR0B=0x98;      // 0b10011000
   UCSR0C=6;         // 0b00000110
   UBRR0H=0;         // 0x0            0
   UBRR0L=0x67;      // 0b01100111     103
    // 9600 bps, 16MHz

/*

... UBRR1L=0x67; // 9600 bps

... UBRR1L=0x44; // 14400 bps

... UBRR1L=0x33; // 19200 bps

... UBRR1L=0x19; // 38400 bps

... UBRR1L=0x10; // 57600 bps

... UBRR1L=0x08; // 115200 bps

*/

}

//----------------------------------------------------

void main() { // 프로그램 시작 함수입니다.

   uart_ini(); // 시리얼 초기화 함수를 호출합니다.

   while (1) { // 무한반복을 수행합니다.

      delay_ms(500); // 500밀리초 지연을 수행합니다.

      UDR0 = 'a';  // 0x61 데이타를 버퍼에 삽입합니다.

      // printf ==> for UDR0

   }

}
//[출처] ATmega128, Serial Bluetooth terminal 앱 테스트... 성미시리얼|작성자 성미아빠

