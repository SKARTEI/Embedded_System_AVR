#include <mega128.h>
#include <delay.h>

void AD_DS(int);
void CHECK();
void NEGLECT();

float fval;
int ival;

void main(void)
{
    int ad_val;
    
    DDRC = 0xFF;
    PORTC = 0b00000000;    

    ADMUX = 0b01000000;
    ADCSRA = 0x87;
    
    SREG = 0X80;
    
    delay_ms(10);
    
    while(1)
    {
        ADCSRA = 0xC7;
        while((ADCSRA & 0x10) == 0);
            ad_val = (int)ADCL + ((int)ADCH << 8);
        AD_DS(ad_val);
        if(ival >= 100 )
            CHECK();
        else
            NEGLECT();    
            
    }
}

void AD_DS(int val)
{ 
    fval = (float)val * 5.0 / 1023.0;
    ival = (int)(fval * 100.0 + 0.5);    
}
void CHECK()
{
    PORTC = 0b10000000;
    delay_ms(1000);
    delay_ms(1000);
    delay_ms(1000);    
}

void NEGLECT()
{
    PORTC = 0x0;
    delay_ms(5);
}