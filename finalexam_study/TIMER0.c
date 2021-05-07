#include <mega128.h>
#include <delay.h>

void main(void)
{
    unsigned char SW;
    DDRE = 0x0;      
    DDRA = 0xFF;
    PORTA = 0b00000000;

    while(1)
    {                  
        SW = PINE & 0b10000000;  
        PORTA = 0b00000000;
        
        if(SW == 0)
        {
            PORTA = 0b10101010;
            delay_ms(200);
            
        }  
    }
}