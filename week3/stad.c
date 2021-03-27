#include <mega128.h>
#include <delay.h>

void main()
{
    DDRC = 0xFF;
    
    while(1){
        PORTC = 0x55;
        delay_ms(200);
        PORTC = 0xAA;
        delay_ms(200);  
        }
}

