#include <mega128.h>
#include <delay.h>


void main(void)
{
    DDRC = 0xFF;
    PORTC = 0xFF;
    
    
    
    while(1)
    {
        PORTC = 0b10000000;
        delay_ms(1000);
        
        PORTC = 0b01000000;
        delay_ms(1000);
        
        PORTC = 0b00100000;
        delay_ms(1000);
    }
}