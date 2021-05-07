#include <mega128.h>

void main(void)
{
    UCSR0A = 0x0;
    UCSR0B = 0b10011000;
    UCSR0C = 0b00000110;
    
    UBRR0H = 0;
    UBRR0L = 103;
    
    SREG = 0x80;
    
    while(1);
}

interrupt [USART0_RXC] void yeah (void)
{
    // USART0_RXC 
    // USART1_DRE
    
    unsigned char ch;
    // 인터럽트 발생은 UCSR & 0X80을 할 필요가 없다!!!.
    ch = UD0;                                          
    
    
    while(UCSR0A & 0x20 == 0x0)
        UDR0 = ch; // 재전송    
}
