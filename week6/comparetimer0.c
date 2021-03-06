#include <mega128.h>
#include <delay.h>
flash unsigned char seg1_tennum[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};


void SEG1_basic(void);

void main()
{
    DDRB = 
    DDRF = 
    DDRC = 
    
    EIMSK =
    EICRB = 
    
    TIMSK = 
    TCCR0 = 
    TCNT0 = 
    SREG = 0x80;
    
    while(1)
    {
        SEG1_basic();
    }
}

void SEG_basic(void)
{
    PORTF = 0b01110000; 
    PORTB = seg1_tennum[]; 
    delay_ms(5);
    
    PORTF = 0b10110000;
    PORTB = seg1_tennum[];
    delay_ms(5);
       
    PORTF = 0b11100000; 
    PORTB = seg1_tennum[];
    delay_ms(5);
    
    PORTF = 0b11010000; 
    PORTB = seg1_tennum[];
    delay_ms(5);    
}