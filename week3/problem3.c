#include <mega128.h>
#include <delay.h>
flash unsigned char seg_pat[16]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};


void main(void)
{
    unsigned int SEG2_output, SEG1_output;
    unsigned char stay_sw1, push_sw1, stay_sw2, push_sw2, sw3, sw4;
    unsigned char number = 0x49;
    
    DDRB = 0xFF;
    DDRF = 0xF0;
    DDRE = 0x0;  
    
    SEG2_output = number / 16;
    SEG1_output = number % 16;  
    
    stay_sw1 = PINE & 0b00010000;
    stay_sw2 = PINE & 0b00100000;
        
    while(1)
    {
       push_sw1 = PINE & 0b00010000;
       push_sw2 = PINE & 0b00100000;
       
       sw3 = PINE & 0b01000000;
       sw4 = PINE & 0b10000000; 
       
       PORTF = 0b11100000;
       PORTB = seg_pat[SEG1_output];
       delay_ms(5);    
       PORTF = 0b11010000;
       PORTB = seg_pat[SEG2_output];   
       delay_ms(5);
     
       if((stay_sw1 != 0) && (push_sw1 == 0))
        {
            number++;
            SEG2_output = number / 16;
            SEG1_output = number % 16;
        }
        else if((stay_sw2 != 0) && (push_sw2 == 0))
        {
            number--;
            SEG2_output = number / 16;
            SEG1_output = number % 16; 
        }
        else if(sw3 == 0)
        {
            PORTF = 0b10110000;
            PORTB = seg_pat[(SEG2_output + SEG1_output) % 16];
            delay_ms(5);
            PORTF = 0b01110000;
            PORTB = seg_pat[(SEG2_output + SEG1_output) / 16];
            delay_ms(5);
        }
        else if(sw4 == 0) 
        {
            PORTF = 0b10110000;
            PORTB = seg_pat[(SEG2_output - SEG1_output) % 16];
            delay_ms(5);
            PORTF = 0b01110000;
            PORTB = seg_pat[(SEG2_output - SEG1_output) / 16];
            delay_ms(5);
        }
        stay_sw1 = push_sw1;
        stay_sw2 = push_sw2;
    }      
}
    
