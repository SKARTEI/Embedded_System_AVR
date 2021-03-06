#include <mega128.h>



void main()
{
    DDRB = 0xFF;
     
    EIMSK = 0b00110000;
    EICRB = 0b00001010;
    
    TCCR2 = 0b11111101;
    TCNT2 = 0x0;
    OCR2 = 128; 
    SREG = 0x80;
    
    while(1);
}

interrupt [EXT_INT4] void SW1click (void)
{
    if(OCR2 <= 32)
        OCR2 = 0;
    else
        OCR2-= 32;
}
interrupt [EXT_INT5] void SW2click (void)
{    
    if(OCR2 >= (255 - 32))
        OCR2 = 0xFF;
    else
        OCR2+= 32;
}