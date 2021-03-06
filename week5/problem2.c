#include <mega128.h>
#include <delay.h>

flash unsigned char seg2_number[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
flash unsigned char seg2_end[3] = {0x79, 0x54,0x5E};  
unsigned int speed1 = 1, num1, one1, ten1, hund1, thou1;
void SEG2_output(void);
void end_9999(void);
void speed_control(void);

void main(void)
{
    DDRB = 0xFF;
    DDRF = 0xF0;
    DDRC = 0xFF;
    PORTC = 0b01111111;
        
    TIMSK = 0x10;
    TCCR1A = 0x0;
    TCCR1B = 0x0D;
    TCCR1C = 0x0;
    TCNT1 = 0;
    OCR1A = 23436;
    
    ETIMSK = 0b00100000;
    TCCR3A = 0x0;
    TCCR3B = 0x05;
    TCCR3C = 0x0;
    TCNT3H = 0x0;
    TCNT3L = 0x0;
    
    SREG = 0x80;
    
    while(1)
        SEG2_output();
}

interrupt [TIM1_COMPA] void timer_11 (void)
{   
    int piu, piu2;
    
    if(num1 == 9999)
        end_9999();
    else
        num1++;
    
    thou1 = num1 / 1000;
    piu = num1 % 1000;
    
    hund1 = piu / 100;
    piu2 = piu % 100;
    
    ten1 = piu2 / 10;
    one1 = piu2 % 10;
}

interrupt [TIM3_CAPT] void counter_33 (void)
{
    
    //speed up
    if(speed1 == 8)
        speed1 = 1;
    else
        speed1++;
        
    speed_control();   
}

void speed_control(void)
{
    switch (speed1)
           {
           case 1:
           OCR1A = 23436;    // 1.5s
           PORTC = 0b01111111;
           break;
           case 2:
           OCR1A = 20311;        // 1.3s
           PORTC = 0b00111111;
           break;
           case 3:
           OCR1A = 17186;     //1.1s
           PORTC = 0b00011111;
           break;
           case 4:
           OCR1A = 14061;     //0.9s     
           PORTC = 0b00001111;
           break;
           case 5:
           OCR1A = 10936;       //0.7s     
           PORTC = 0b00000111;
           break;
           case 6:
           OCR1A = 7811;         //  0.5s     
           PORTC = 0b00000011;
           break;
           case 7:
           OCR1A = 4686;         //0.3s
           PORTC = 0b00000001;
           break;
           case 8:
           OCR1A = 2343;           // 0.15s     
           PORTC = 0b00000000;
           break;
           }
}

void SEG2_output(void)
{
    PORTF = 0b11100000;
    PORTB = seg2_number[one1];
    delay_ms(5);
    
    PORTF = 0b11010000;
    PORTB = seg2_number[ten1];
    delay_ms(5);
    
    PORTF = 0b10110000;
    PORTB = seg2_number[hund1];
    delay_ms(5);
    
    PORTF = 0b01110000;
    PORTB = seg2_number[thou1];
    delay_ms(5);
}

void end_9999(void)
{
    int i;
    for(i = 0; i < 200; i++)
    {
        PORTF = 0b11100000;
        PORTB = seg2_end[0];
        delay_ms(5);
    
        PORTF = 0b11010000;
        PORTB = seg2_end[1];
        delay_ms(5);
    
        PORTF = 0b10110000;
        PORTB = seg2_end[2];
        delay_ms(5);
    }
    num1 = 0;   
}