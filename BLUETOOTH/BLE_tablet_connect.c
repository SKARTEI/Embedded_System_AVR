#include <mega128.h>        
#include <delay.h>

#define FUNCSET       0x28    // Function Set
#define ENTMODE          0x06    // Entry Mode Set
#define ALLCLR        0x01    // All Clear
#define DISPON        0x0c     // Display On
#define LINE2         0xC0    // 2nd Line Move

void LCD_init(void);
void LCD_String(char flash *);
void Busy(void);
void Command(unsigned char);
void Data(unsigned char);

void LCD_IDLE();

unsigned char R_num = 1, S_num;

void main(void)
{             
    //unsigned char O_SW, N_SW;
    LCD_IDLE();
    
    //DDRE = 0x0;    
    
    UCSR0A = 0x0;
    UCSR0B = 0b10011000;
    UCSR0C = 0b00000110;
    UBRR0H = 0;
    UBRR0L = 103;
    
    SREG = 0x80;
    
    while(1);
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
}

void LCD_IDLE()
{
    LCD_init();
    LCD_String("BLUETOOTH ON");
}

interrupt [USART0_RXC] void USART_recieve (void)
{
    R_num = UDR0;
    S_num = R_num;
    
    //if(R_num == '1')
    if(R_num == '1')
    {
        Command(LINE2);
    	LCD_String("NUMBER 1 RECIEVED");
        delay_ms(1000);
        delay_ms(1000);
        delay_ms(1000);
        LCD_IDLE();
    }
    else if(R_num == '2')
    {   
        Command(LINE2);
        LCD_String("NUMBER 2 RECIEVED");
        delay_ms(1000);
        LCD_IDLE();
    }
    else   // delete
    {           
        Command(LINE2);
        LCD_String("ERROR DETECTED");
        delay_ms(1000);
        LCD_IDLE();
    }      
    UDR0 = S_num;
}


//    ************   LCD code    ****************** 
void LCD_init(void)
{       
    DDRD = 0xFF;            // 포트 D 출력 설정
    PORTD &= 0xFB;            //E = 0;
                  
    delay_ms(15);
    Command(0x20);
    delay_ms(5);
    Command(0x20);
    delay_us(100);
    Command(0x20);
    Command(FUNCSET);
    Command(DISPON);
    Command(ALLCLR);
    Command(ENTMODE);
}


void LCD_String(char flash *str)
{
    char flash *pStr=0;
    
    pStr = str;    
    while(*pStr) Data(*pStr++);
}                                     


void Command(unsigned char byte)
{
    Busy();

    // 인스트럭션 상위 바이트
    PORTD = (byte & 0xF0);        // 데이터    
    PORTD &= 0xFE;            //RS = 0;           
    PORTD &= 0xFD;            //RW = 0;  
    delay_us(1);     
    PORTD |= 0x04;            //E = 1;
    delay_us(1);
    PORTD &= 0xFB;            //E = 0;

    // 인스트럭션 하위 바이트
        PORTD = ((byte<<4) & 0xF0);    // 데이터
    PORTD &= 0xFE;            //RS = 0;
    PORTD &= 0xFD;            //RW = 0;
    delay_us(1);         
    PORTD |= 0x04;            //E = 1;
    delay_us(1);
    PORTD &= 0xFB;            //E = 0;
}
                    

void Data(unsigned char byte)
{
    Busy();
        
    // 데이터 상위 바이트
    PORTD = (byte & 0xF0);        // 데이터
    PORTD |= 0x01;            //RS = 1;
    PORTD &= 0xFD;            //RW = 0;
    delay_us(1);         
    PORTD |= 0x04;            //E = 1;
    delay_us(1);
    PORTD &= 0xFB;            //E = 0;

    // 데이터 하위 바이트
    PORTD = ((byte<<4) & 0xF0);      // 데이터
    PORTD |= 0x01;            //RS = 1;
    PORTD &= 0xFD;            //RW = 0;     
    delay_us(1);         
    PORTD |= 0x04;            //E = 1;
    delay_us(1);
    PORTD &= 0xFB;            //E = 0;
}


void Busy(void)
{
    delay_ms(2);
}
