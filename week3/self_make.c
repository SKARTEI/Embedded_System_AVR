#include <mega128.h>
#include <delay.h>
flash unsigned char seg_pat[10]= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
void seg_calculate(int x);

void main(void)
{
    unsigned int num = 0;
    DDRB = 0xFF;
    DDRF = 0xF0;
    
    while(1)
    {
        seg_calculate(num);
        num++;
        if(num >9999)
            num = 0;  
    }
}

void seg_calculate(int x)
{
    int thou,hund,ten,one, p, pp, i;
    
    thou = x / (1000);
    p = x % (1000);
    
    hund = p / (100);
    pp = p % (100);
    
    ten = pp / (10);
    one = pp % (10);
            
    
    for(i = 0; i < 2 ; i++) {
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
    PORTB = seg_pat[thou];  
    delay_ms(5);   
    }
}
