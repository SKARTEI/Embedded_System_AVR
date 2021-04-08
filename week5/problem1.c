#include <mega128.h>
#include <delay.h>
#include <stdlib.h>

flash unsigned char seg_number[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
flash unsigned char seg_upwin[4] = {0x40, 0x3E, 0x73,0x40};
flash unsigned char seg_downwin[4] = {0x40, 0x5E, 0x54,0x40};
unsigned int led = 0, up_num, down_num, up_one, up_ten, down_one, down_ten;

void SEG_output(void);
void up_win(void);
void down_win(void);
void up_end(void);
void down_end(void);


void main(void)
{
    DDRB = 0xFF;
    DDRF = 0xF0;
    DDRC = 0xFF;
    PORTC = 0xFF;
        
    TIMSK = 0x04;
    TCCR1A = 0x0;
    TCCR1B = 0x04; // 256
    TCCR1C = 0x0;
    TCNT1 = 59277;
    
    ETIMSK = 0b00000100;
    TCCR3A = 0x0;
    TCCR3B = 0x06;
    TCCR3C = 0x0;
    TCNT3H = 0xFF;
    TCNT3L = 0xFF;
    
    SREG = 0x80;
    
    while(1)
        SEG_output();
}

interrupt [TIM1_OVF] void timer_1 (void)
{
    TCNT1 = 59277;
    // random number
    up_num = rand() % 100;
    down_num = rand() % 100;
    
    up_ten = up_num / 10;
    up_one = up_num % 10;
    down_ten = down_num / 10;
    down_one = down_num % 10;
}

interrupt [TIM3_OVF] void count_3 (void)
{
    TCNT3H = 0xFF;
    TCNT3L = 0xFF;
    
    if(up_num > down_num)
        up_win();
    else if(up_num < down_num)
        down_win();    
}

void SEG_output(void)
{
    PORTF = 0b11100000;
    PORTB = seg_number[down_one];
    delay_ms(5);
    
    PORTF = 0b11010000;
    PORTB = seg_number[down_ten];
    delay_ms(5);
    
    PORTF = 0b10110000;
    PORTB = seg_number[up_one];
    delay_ms(5);
    
    PORTF = 0b01110000;
    PORTB = seg_number[up_ten];
    delay_ms(5);
}

void up_win(void)
{
    int win_count;
    win_count = led & 0b00001111;
    switch (win_count)
           {
           case 0b00000000:
           win_count = 0b00000001;
           led = led | win_count;
           break;
           case 0b00000001:
           win_count = 0b00000011;
           led = led | win_count;
           break;
           case 0b00000011:
           win_count = 0b00000111;
           led = led | win_count;
           break;
           case 0b00000111:
           win_count = 0b00001111;
           led = led | win_count;
           break;
           case 0b00001111:
           led = led & win_count;
           up_end();
           break;
           }
    PORTC = led ^ 0b11111111;
}

void down_win(void)
{
    int win_count;
    win_count = led & 0b11110000;
    switch (win_count)
           {
           case 0b00000000:
           win_count = 0b10000000;
           led = led | win_count;
           break;
           case 0b10000000:
           win_count = 0b11000000;
           led = led | win_count;
           break;
           case 0b11000000:
           win_count = 0b11100000;
           led = led | win_count;
           break;
           case 0b11100000:
           win_count = 0b11110000;
           led = led | win_count;
           break;
           case 0b11110000:
           led = led & win_count;
           down_end();
           break;
           }
    
    PORTC = led ^ 0b11111111;
}

void up_end(void)
{
    int i;
    
    for(i = 0; i < 200; i++)
    {
        PORTF = 0b01110000;
        PORTB = seg_upwin[0];
        delay_ms(5);
    
        PORTF = 0b10110000;
        PORTB = seg_upwin[1];
        delay_ms(5);
    
        PORTF = 0b11010000;
        PORTB = seg_upwin[2];
        delay_ms(5);
    
        PORTF = 0b11100000;
        PORTB = seg_upwin[3];
        delay_ms(5);
    }
    
    led = 0b00000000;
    PORTC = led ^ 0b11111111;    
}

void down_end(void)
{
    int i;
    
    for(i = 0; i < 200; i++)
    {
        PORTF = 0b01110000;
        PORTB = seg_downwin[0];
        delay_ms(5);
    
        PORTF = 0b10110000;
        PORTB = seg_downwin[1];
        delay_ms(5);
    
        PORTF = 0b11010000;
        PORTB = seg_downwin[2];
        delay_ms(5);
    
        PORTF = 0b11100000;
        PORTB = seg_downwin[3];
        delay_ms(5);
    }
    
    led = 0b00000000;
    PORTC = led ^ 0b11111111;
}
