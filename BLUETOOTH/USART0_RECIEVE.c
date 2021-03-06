#include <mega128.h>

flash unsigned char seg_pat[16]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

void main(void)
{
    unsigned char rd, dd = 0;
    
    DDRB = 0xFF;
    DDRF = 0xF0;
    
    PORTF = 0b11100000;
    PORTB = seg_pat[dd];
    
    UCSR0A = 0x0;
    UCSR0B = 0b00010000;
    UCSR0C = 0b00000110;
    
    UBRR0H = 0;
    UBRR0L = 103;
    
    while(1)
    {
        while((UCSR0A & 0x80) == 0x0)
            PORTB = seg_pat[dd];                           
    
    rd = UDR0;
    
    if(rd >= '0' && rd <= '9')
        dd = rd - '0';
    else if(rd >= 'a' && rd <= 'f')
        dd = rd -'a' + 10;
    else if(rd >= 'A' && rd <= 'F')
        dd = rd - 'A' +10;
        
    }
}