#include <mega128.h>
#include <delay.h>
flash unsigned char seg_pat[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
flash unsigned char seg_nice[4] = {0x54,0x06,0x39,0x79};
flash unsigned char seg_fail[4] = {0x71, 0x77, 0x06, 0x38};
unsigned int num = 99, timer_cnt, cal = 1, led = 0x0, cal_memo = 0;


void SEG_base3(void);
void SEG_nice3(void);
void SEG_fail3(void);

void main(void)
{
    DDRB = 0xFF;
    DDRF = 0xF0;
    DDRC = 0xFF;
    PORTC = 0xFF;
    
    EIMSK = 0b00010000;
    EICRB = 0b00000010;
        
    TIMSK = 0x01;
    TCCR0 = 0x04; //  1/16us * 64 *(256-6) = 1ms
    TCNT0 = 6;
    SREG = 0x80;
    
    while(1)
    {
        SEG_base3();
    }
}

void SEG_base3(void)
{
    PORTF = 0b01110000;
    PORTB = seg_pat[cal]; 
    delay_ms(5);
    
    PORTF = 0b10110000;
    PORTB = seg_pat[cal_memo];
    delay_ms(5);
       
    PORTF = 0b11100000;
    PORTB = seg_pat[num %10];
    delay_ms(5);
    
    PORTF = 0b11010000;
    PORTB = seg_pat[num / 10];
    delay_ms(5);
}

void SEG_nice3(void)
{
    int i;
    for(i = 1; i <= 250; i++)
    {
        PORTF = 0b01110000;
        PORTB = seg_nice[0];
        delay_ms(5);
    
        PORTF = 0b10110000;
        PORTB = seg_nice[1];
        delay_ms(5);
    
        PORTF = 0b11010000;
        PORTB = seg_nice[2];
        delay_ms(5);  
    
        PORTF = 0b11100000;
        PORTB = seg_nice[3];
        delay_ms(5);
    }
    num = 99;
    led = 0x0;
    PORTC = led ^ 0b11111111;
}

void SEG_fail3(void)
{
    int ii;
    for(ii = 1; ii <= 250; ii++)
    {
        PORTF = 0b01110000;
        PORTB = seg_fail[0];
        delay_ms(5);
    
        PORTF = 0b10110000;
        PORTB = seg_fail[1];
        delay_ms(5);
    
        PORTF = 0b11010000;
        PORTB = seg_fail[2];
        delay_ms(5);
    
        PORTF = 0b11100000;
        PORTB = seg_fail[3];
        delay_ms(5);
    }
    num = 99;
    led = 0x0;
    PORTC = led ^ 0b11111111;
}
interrupt [TIM0_OVF] void time0 (void)
{
    TCNT0 = 6;
    timer_cnt++;
    if(timer_cnt == 200)
    {
        timer_cnt = 0;       
        if(cal == 9)
            cal = 1;
        else
            cal++;
    }
     
 
}
         
interrupt [EXT_INT4] void sw1_on (void)
{   
    cal_memo = cal;
    
    if(num > cal)
       num = num - cal;
    else if(num == cal)
        SEG_nice3();
    else if(num < cal)
        {
            switch (led)
                   {
                   case 0b00000000:
                   led = 0b00000001;
                   PORTC = led ^ 0b11111111;
                   break;
                   case 0b00000001:
                   led = 0b00000011;
                   PORTC = led ^ 0b11111111;
                   break;
                   case 0b00000011:
                   SEG_fail3();
                   break;
                   }
        }
}