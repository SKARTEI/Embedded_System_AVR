#include <mega128.h>

void Putch(char);

void main(void)
{
    char string[] = "this is usart0 control program";
    char *pstr;
    
    UCSR0A = 0x0;
    UCSR0B = 0b00001100;
    UCSR0C = 0b00000110;
    
    UBRR0H = 0;
    UBRR0L = 103;
    
    pstr = string;
    while(*pstr)
        Putch(*pstr++);
        
    while(1);
}

void Putch(char data)
{
    while ((UCSR0A & 0x20) == 0x0);
    UDR0 = data;
}

 /*
void main(void)
{
    char i, data;
    
    DDRC = 0xFF;
    PORTC = 0xFF;
    
    //USART SETTINGS
    
    UCSR0A = 0x0;
    UCSR0B = 0b00001100;
    UCSR0C = 0b00000000;
    
    UBRR0H = 0;
    UBRR0L = 103;
    
    while(1)
    {
        data = rx_char();
        tx_char(data);
        
        if(data=='0')
            PORTC = 0xF0;
        if (data == '1')
            PORTC = 0x0F;   
    }
   
     
}   */
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    while(1)
    {
        PORTC = 0b11110010;     //RED
        delay_ms(1000);
        delay_ms(1000);
        
        PORTC = 0b11110100;   // GREEN
        delay_ms(1000);
        delay_ms(1000);
        
        PORTC = 0b11111000;   // BLUE
        delay_ms(1000);
        delay_ms(1000);
    }
    */
