#include <mega128.h>
#include <delay.h>
#include <stdlib.h>

flash unsigned char seg3_number[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
flash unsigned char seg3_success[4]= {0x6D ,0x3E,0x39,0x39};
flash unsigned char seg3_failup[2] = {0x3E, 0x73};
flash unsigned char seg3_faildown[2] = {0x5E, 0x54}; 

unsigned int tennum = 0, onenum = 0;
unsigned int ansnum, sum;

void SEG3_output(void);
void success(void);
void fail_up(void);
void fail_down(void);

void main()
{
    DDRB = 0xFF;
    DDRF = 0xF0;
    
    EIMSK = 0b00110000;
    EICRB = 0b00001010;
    
    ETIMSK = 0b00000100;
    TCCR3A = 0x0;
    TCCR3B = 0x06;
    TCCR3C = 0x0;
    TCNT3H = 0xFF;
    TCNT3L = 0xFF;
    
    SREG = 0x80;
    
    ansnum = rand() % 100;
    
    while(1)
        SEG3_output();
}

interrupt [EXT_INT4] void ten_class (void)
{
    if(tennum == 9)
        tennum = 0;
    else
        tennum++;      
}

interrupt [EXT_INT5] void one_class (void)
{
    if(onenum == 9)
        onenum = 0;
    else
        onenum++;  
}

interrupt [TIM3_OVF] void check (void)
{
    TCNT3H = 0xFF;
    TCNT3L = 0xFF;
    
    sum = (tennum*10) + onenum;
    
    if(ansnum == sum)
        success();
    else if(ansnum > sum)
        fail_up();
    else if(ansnum < sum)
        fail_down();
}

void SEG3_output(void)
{
    PORTF = 0b11100000;
    PORTB = seg3_number[onenum];
    delay_ms(5);
    
    PORTF = 0b11010000;
    PORTB = seg3_number[tennum];
    delay_ms(5);
}

void success(void)
{
    int i;
    for(i = 0; i<200; i++)
    {
        PORTF = 0b11100000;
        PORTB = seg3_success[3];
        delay_ms(5);
    
        PORTF = 0b11010000;
        PORTB = seg3_success[2];
        delay_ms(5);
        
        PORTF = 0b10110000;
        PORTB = seg3_success[1];
        delay_ms(5);
    
        PORTF = 0b01110000;
        PORTB = seg3_success[0];
        delay_ms(5);    
    }
    ansnum = rand() % 100;
    tennum = 0;
    onenum = 0;
}

void fail_up(void)
{
    int i;
    for(i = 0; i< 50; i++)
    {
        PORTF = 0b11100000;
        PORTB = seg3_number[onenum];
        delay_ms(5);
    
        PORTF = 0b11010000;
        PORTB = seg3_number[tennum];
        delay_ms(5);
    
        PORTF = 0b10110000;
        PORTB = seg3_failup[1];
        delay_ms(5);
    
        PORTF = 0b01110000;
        PORTB = seg3_failup[0];
        delay_ms(5); 
    }
}

void fail_down(void)
{
    int i;
    for(i = 0; i< 50; i++)
    {
        PORTF = 0b11100000;
        PORTB = seg3_number[onenum];
        delay_ms(5);
    
        PORTF = 0b11010000;
        PORTB = seg3_number[tennum];
        delay_ms(5);
    
        PORTF = 0b10110000;
        PORTB = seg3_faildown[0];
        delay_ms(5);
    
        PORTF = 0b01110000;
        PORTB = seg3_faildown[1];
        delay_ms(5); 
    }
}