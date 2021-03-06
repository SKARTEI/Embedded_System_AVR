#include <mega128.h>

void main(void)
{
    unsigned char stay_sw1, push_sw1,stay_sw3, push_sw3, led_output;
    unsigned char led = 0xFF;
    
    DDRC = 0xFF;
    DDRE = 0x0;
    PORTC = led; // LED all off
    
    stay_sw1 = PINE & 0b00010000;
    stay_sw3 = PINE & 0b01000000;
        
    while(1)
    {
       push_sw1 = PINE & 0b00010000;
       push_sw3 = PINE & 0b01000000;
       
        if((stay_sw1 != 0) && (push_sw1 == 0))
        {
            led = 0xFF;
            PORTC = led;
        }
        else if((stay_sw3 != 0) && (push_sw3 == 0))
        {
            led++;
            led_output = led ^ 0b11111111;
            PORTC = led_output;
        }
        else if((stay_sw3 == 0) && (push_sw3 != 0))
        {
            led = led + 0x10;
            led_output = led ^ 0b11111111;
            PORTC = led_output; 
        }
        
        stay_sw1 = push_sw1;
        stay_sw3 = push_sw3;
    }
    
}


