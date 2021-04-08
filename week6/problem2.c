#include <mega128.h>
#include <delay.h>
#include <stdlib.h>

flash unsigned char seg2_ten[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
flash unsigned char seg_2end[3] = {0x79,0x5E, 0x54}; // End
unsigned int led = 0, number;

void SEG2_basic(void);
void SEG2_end(void);

void main()
{
    unsigned char o_sw, n_sw;
    DDRB = 0xFF;
    DDRF = 0xF0;
    DDRC = 0xFF;
    PORTC = led ^ 0xFF; 
    DDRE = 0x0;
    
    o_sw = PINE & 0b01110000;   
    number = (rand() % 9000) + 1000; // 1000~ 9999
    
    while(1)
    {
        SEG2_basic();
        n_sw = PINE & 0b01110000;
        
        if(o_sw == 0b01110000 && n_sw == 0b01100000)  // SW1
        {
            number = (number + 9999)/2;
            led++;
            PORTC = led ^ 0xFF;
        }
        else if(o_sw == 0b01110000 && n_sw == 0b01010000)  // SW2
        {
            number =  (number - 1000) / 2;
            led++;
            PORTC = led ^ 0xFF;
        }
        else if(o_sw == 0b01110000 && n_sw == 0b00110000)  // sw3
        {
            SEG2_end();
            number = (rand() % 9000) + 1000; // 1000~ 9999        
            led = 0;
            PORTC = led ^ 0xFF;
        }
            
        o_sw = n_sw;
    }
}

void SEG2_basic(void)
{
    PORTF = 0b01110000; 
    PORTB = seg2_ten[number / 1000]; 
    delay_ms(5);
    
    PORTF = 0b10110000;
    PORTB = seg2_ten[(number % 1000) / 100];
    delay_ms(5);
       
    PORTF = 0b11100000; 
    PORTB = seg2_ten[(number % 100) / 10];
    delay_ms(5);
    
    PORTF = 0b11010000; 
    PORTB = seg2_ten[number % 10];
    delay_ms(5);    
}

void SEG2_end(void)
{
    int i = 0;
    for(i = 0; i < 200 ; i++)
    {
    PORTF = 0b10110000;
    PORTB = seg_2end[0];
    delay_ms(5);
       
    PORTF = 0b11100000; 
    PORTB = seg_2end[1];
    delay_ms(5);
    
    PORTF = 0b11010000; 
    PORTB = seg_2end[2];
    delay_ms(10);
    }
     
}