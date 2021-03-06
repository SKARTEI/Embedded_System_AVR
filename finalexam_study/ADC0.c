#include <mega128.h>
#include <delay.h>

flash unsigned char seg_pat[16]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

typedef unsigned char u_char;

void AD_disp(int);

void main(void)
{
    int adval;
    
    DDRB = 0xFF;
    DDRF = 0xF0;              ㄴ
    
    ADMUX = 0x0;
    ADSCRA = 0x87;                         // 단일 변환
    
    delay_ms(5);
    
    while(1)
    {
        ADCSRA = ADCSRA | 0b01000000;              // ADSC 를 1로 만든다.
        while(ADCSRA & 0x10 == 0)                  // ADIF가 1이 되면
            adval = (int) ADCL + ((int) ADCH << 8);// AD 변환값을 읽어 adval에 저장한다.
            AD_disp(adval);
    
    }
    
}



//---------------------------------------------------------------------------------

#include <mega128.h>
#include <delay.h>

typedef unsigned cahr u_char;

flash unsigned char seg_pat[16]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

void AD_disp(int);

void main(void)
{
    int adval;
    
    DDRB = 0xFF;
    DDRF = 0xF0;
    
    ADMUX = 0x0;
    ADCSRA = 0xE7;
    
    delay_ms(5);
    
    while(1)
        {
            adval = (int) ADCL + ((int) ADCH << 8);
            AD_disp(adval);
            delay_ms(2);
        }
}


// -----------------------------------------------------------------------

#include <mega128.h>
#include <delay.h>

void main(void)
{
    int adval;
    
    DDRB = 0xFF;
    DDRF = 0xF0;
    
    ADMUX = 0x10;
    ADCSRA = 0x87;                                 
    delay_ms(5);
    
    while(1)
    {
        ADCSRA = ADCSRA | 0b01000000;
        while(ADCSRA & 0x10 == 0)
            adval = (int)ADCL +((int)ADCH << 8);
    }
}