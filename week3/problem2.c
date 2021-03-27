#include <mega128.h>
#include <delay.h>
flash unsigned char seg_pat[16]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};


void main(void)
{
    unsigned int SEG2_output, SEG1_output;
    unsigned char stay_sw1, push_sw1, stay_sw2, push_sw2, led_output;
    unsigned char led = 0x49;
    
    DDRB = 0xFF;
    DDRF = 0xF0;
    
    SEG2_output = led / 16;
    SEG1_output = led % 16;
    
    DDRC = 0xFF;
    DDRE = 0x0;   
      
    led_output = led ^ 0b11111111;
    PORTC = led_output; 
    
    stay_sw1 = PINE & 0b00010000;
    stay_sw2 = PINE & 0b00100000;
        
    while(1)
    {
       push_sw1 = PINE & 0b00010000;
       push_sw2 = PINE & 0b00100000;
        
       PORTF = 0b11100000;
       PORTB = seg_pat[SEG1_output];
       delay_ms(5);    
       PORTF = 0b11010000;
       PORTB = seg_pat[SEG2_output];   
       delay_ms(5);
     
       if((stay_sw1 != 0) && (push_sw1 == 0))
        {
            led++;
            SEG2_output = led / 16;
            SEG1_output = led % 16;
            led_output = led ^ 0b11111111;
            PORTC = led_output;
        }
        else if((stay_sw2 != 0) && (push_sw2 == 0))
        {
            led--;
            SEG2_output = led / 16;
            SEG1_output = led % 16;
            led_output = led ^ 0b11111111;
            PORTC = led_output; 
        } 
        stay_sw1 = push_sw1;
        stay_sw2 = push_sw2;
    }      
}
    
