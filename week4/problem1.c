#include <mega128.h>
#include <delay.h>
flash unsigned char seg_pat[10]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
flash unsigned char seg_alphabet[3] = {0x79, 0x54,0x5E}; // End
flash unsigned char seg_lose[4] = {0x38,0x3f,0x6d,0x79};

unsigned char num = 0,one = 0, ten = 0, minus =0;
unsigned char turn = 1;
unsigned char led = 0x01;

void SEG4_output(void);
void SEG_end(void);

void main(void)
{
    DDRB = 0xFF;
    DDRF = 0xF0;
    DDRC = 0xFF;
    PORTC = led ^ 0b11111111;
    
    EIMSK = 0b01110000;
    EICRB = 0b00101010;
    SREG = 0x80;
  
    while(1)
   {  
        num = one + (ten * 10);  
        SEG4_output();
   }
   
}

void SEG4_output(void)
{
    PORTF = 0b11100000;
    PORTB = seg_pat[one];
    delay_ms(5);
    
    PORTF = 0b11010000;
    PORTB = seg_pat[ten];
    delay_ms(5);
    
    PORTF = 0b01110000;
    PORTB = seg_pat[turn];
    delay_ms(5);
}

void SEG_end(void)
{
    int i = 0;
    
    for(i = 1 ; i <= 200; i++)
    {
        PORTF = 0b01110000;
        PORTB = seg_pat[turn];
        delay_ms(5);
    
        PORTF = 0b10110000;
        PORTB = seg_alphabet[0];
        delay_ms(5);
    
        PORTF = 0b11010000;
        PORTB = seg_alphabet[1];
        delay_ms(5);
    
        PORTF = 0b11100000;
        PORTB = seg_alphabet[2];
        delay_ms(5);
    }
    
    for(i = 1 ; i <= 200; i++)
    {
        PORTF = 0b01110000;
        PORTB = seg_lose[0];
        delay_ms(5);
    
        PORTF = 0b10110000;
        PORTB = seg_lose[1];
        delay_ms(5);
    
        PORTF = 0b11010000;
        PORTB = seg_lose[2];
        delay_ms(5);
    
        PORTF = 0b11100000;
        PORTB = seg_lose[3];
        delay_ms(5);
    }
    ten = 0;
    one = 0;    
}

interrupt [EXT_INT4] void sw1_on (void)
{
     if(led == 0b10000000)
        led = 0b00000001;
     else
        led = led << 1;
     PORTC = led ^ 0b11111111;
}

interrupt [EXT_INT5] void sw2_on (void)
{
     if(led <= 0b00000010)
        if(ten ==9)
            ten = 0;
        else
            ten++;
     else if(led <= 0b00001000)
        if(ten == 0)
            ten = 9;
        else
            ten--;
     else if(led <= 0b00100000)
        if(one == 9)
            one = 0;    
        else    
            one++;
     else if(led <= 0b10000000)
        if(one == 0)
            one = 9;
        else
            one--;
}

interrupt [EXT_INT6] void sw3_on (void) 
{   
     switch (led)
            {
            case 0b00000001:
            minus = 2;
            break;
            case 0b00000010:
            minus = 3;
            break;
            case 0b00000100:
            minus = 4;
            break;
            case 0b00001000:
            minus = 5;
            break;
            case 0b00010000:
            minus = 6;
            break;
            case 0b00100000:
            minus = 7;
            break;
            case 0b01000000:
            minus = 8;
            break;
            case 0b10000000:
            minus = 9;
            break;
            }
        
     if(num > minus)
     {
        num = num - minus;
        ten = num / 10;
        one = num % 10;
        SEG4_output();
     }
     else
        SEG_end();
        
     if(turn == 3)
        turn = 1;
     else
        turn++;
}