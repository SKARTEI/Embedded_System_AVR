#include <mega128.h>
#include <delay.h>
flash unsigned char seg_pat[11]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77};
flash unsigned char seg_end[3] = {0x79, 0x54,0x5E};
unsigned int num = 120,one, ten, hund, pit = 0, next = 2;
unsigned char led = 0xFF;
unsigned int  timer_count = 0, light_count;

void SEG_output(void);
void SEG_end2(void);
void led_output(void);

void main(void)
{
    DDRB = 0xFF;
    DDRF = 0xF0;
    DDRC = 0xFF;
    
    EIMSK = 0b00010000;
    EICRB = 0b00000010;
    
    TIMSK = 0x01;
    TCCR0 = 0x04; //  1/16us * 64 *(256-6) = 1ms
    TCNT0 = 6;
    
    SREG = 0x80;
    light_count = num / 8;
    
    while(1)
    {   
        SEG_output();
        led_output();
    }    
}

void SEG_output(void)
{ 
    hund = num / 100;
    pit = num % 100;
    ten = pit / 10;
    one = pit % 10;
    num = (100*hund) + (10*ten) + one;
    
    PORTF = 0b11100000;
    PORTB = seg_pat[one];
    delay_ms(5);
    
    PORTF = 0b11010000;
    PORTB = seg_pat[ten];
    delay_ms(5);
    
    PORTF = 0b10110000;
    PORTB = seg_pat[hund];
    delay_ms(5);
    
    PORTF = 0b01110000;
    PORTB = seg_pat[next];
    delay_ms(5);
}
 
void SEG_end2(void)
{
    int ii = 0;
    for(ii = 0; ii < 2 ; ii++)
    {
        int i = 0;
        for(i = 1 ; i <= 200; i++)
        {
            PORTF = 0b10110000;
            PORTB = seg_end[0];
            delay_ms(5);
    
            PORTF = 0b11010000;
            PORTB = seg_end[1];
            delay_ms(5);
    
            PORTF = 0b11100000;
            PORTB = seg_end[2];
            delay_ms(5);
            
            PORTC = 0xFF;
        }
    }
    one = 0;
    ten = 0;
    hund = 0;   
}

void led_output(void)
{          
    if(num <= (1*light_count))
            led = 0b10000000;
        else if (num <= (2*light_count))
            led = 0b11000000;
        else if (num <= (3*light_count))
            led = 0b11100000;
        else if (num <= (4*light_count))
            led = 0b11110000;
        else if (num <= (5*light_count))
            led = 0b11111000;
        else if (num <= (6*light_count))
            led = 0b11111100;
        else if (num <= (7*light_count))
            led = 0b11111110;
        else
            led = 0b11111111;
    
    PORTC = led ^ 0b11111111;    
}

interrupt [EXT_INT4] void sw1_on (void)
{
    if(next == 10)
        next = 2;
     else
        next = next +2;
        
    switch (next)
           {
           case 2 :
           num = 120;
           light_count = num / 8;
           break;
           case 4:
           num = 240;  
           light_count = num / 8;
           break;
           case 6:
           num = 360;            
           light_count = num / 8;
           break;
           case 8:
           num = 480;
           light_count = num / 8;
           break;
           case 10:
           num = 600;
           light_count = num / 8;
           break;
           }    
}

interrupt [TIM0_OVF] void time0 (void)
{
    TCNT0 = 6;
    timer_count++;
    if(timer_count == 1000)
    {
        timer_count = 0;
        num--;
    }
     
    if(num == 0)
        SEG_end2();
}