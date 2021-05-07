#include <mega128.h>        
#include <delay.h>



void LCD_IDLE();

unsigned char R_num, S_num;
void main(void)
{             
    //unsigned char O_SW, N_SW;
    
    //DDRE = 0x0;    
    
    DDRC = 0xFF;
    PORTC = 0x0;
    
    UCSR1A = 0x0;
    UCSR1B = 0b10011000;
    UCSR1C = 0b00000110;
    UBRR1H = 0;
    UBRR1L = 103;
    
    SREG = 0x80;
  /*  
   O_SW = PINE & 0b10000000; 
    while(1)
    {
        N_SW = PINE & 0b10000000;
        if((O_SW != 0) && (N_SW == 0))
        {   
            Command(LINE2);
            LCD_String("CLEAR   LCD");   
            delay_ms(1000);
            delay_ms(1000);
            LCD_IDLE();
        }
        
      O_SW = N_SW;  
    }  */
    while(1);       
}



interrupt [USART0_RXC] void USART_recieve (void)
{
    R_num = UDR1;
    S_num = R_num;
    
    if(R_num == '1')
    {        
        PORTC = 0b10000000;
        /*
        Command(LINE2);
        LCD_String("NUMBER 1 RECIEVED");
        delay_ms(1000);
        delay_ms(500);
        LCD_IDLE();  
        */
    }
    else if(R_num == '2')
    {   
        PORTC = 0b01000000;
        /*
        Command(LINE2);
        LCD_String("NUMBER 2 RECIEVED");
        delay_ms(1000);
        delay_ms(500);
        LCD_IDLE();
        */
    }
    else
    { 
        PORTC = 0b00100000;   
    /*       
        Command(LINE2);
        LCD_String("ERROR DETECTED");
        delay_ms(1000);
        delay_ms(500);
        LCD_IDLE();
        */
    }
    UDR1 = S_num;
}