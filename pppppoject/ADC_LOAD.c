#include <mega128.h>
#include <delay.h>

void AD_DS(int);
void CHECK1();
void CHECK2();
void NEGLECT1();
void NEGLECT2();

float fval;
int ival, second = 0, i;

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
       /*
        if(ival >= 100  && second == 0)
            CHECK1(); 
        else if(ival < 100  && second == 0)
            NEGLECT1(); 
        else if(ival >= 100  && second == 1)
            CHECK2();
        else if(ival < 100  && second == 1)
            NEGLECT2();
        */    
        if(ival >= 100)
        {
            if (ADMUX == 0b01000000)
                CHECK1();
            else
                CHECK2();
        }
        
        else
        {
            if (ADMUX == 0b01000000)
                NEGLECT1();    
            else
                NEGLECT2();
        }   
            
    }
}

void AD_DS(int val)
{ 
    fval = (float)val * 5.0 / 1023.0;
    ival = (int)(fval * 100.0 + 0.5);    
}
void CHECK1()
{
    
    PORTC = 0b10000000;   //b
    second = 1;
    for (i = 0; i < 3; i++)
        delay_ms(1000);
    ADMUX = 0b01000011;
        
}

void CHECK2()
{
    PORTC = 0b01000000;    //g
    second = 0;
    for (i = 0; i < 3; i++)
        delay_ms(1000);
   ADMUX = 0b01000000;    
}

void NEGLECT1()
{
    PORTC = 0b00000000;    // x
    delay_ms(5);
    second = second;
}

void NEGLECT2()
{
    PORTC = 0b00100000;    //r
    delay_ms(5);
    second = second;
}