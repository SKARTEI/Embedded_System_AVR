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

void AD_DS(int);
void COMPLETE();
void FAIL();
void LCD_IDLE();
void LCD_standby();

float fval;
int ival;
unsigned int flag = 0; 

void main(void)
{      
    int ad_val;
    unsigned char SW;     
        LCD_IDLE();
        /* 
        주석처리한게 LCD_IDLE() 내용
        LCD_init();
        LCD_String(" Sensor inactive");    // 첫번째 라인에 출력
        Command(LINE2);
        LCD_String("   Intial Mode");    // 두번째 라인에 출력
        */
    DDRE = 0x0;
    ADMUX = 0b01000000;
    ADCSRA = 0x87;
    
    delay_ms(10);
    
    while(1)
    {   
        
        ADCSRA = ADCSRA | 0b01000000;  //ADSC SET
        while((ADCSRA & 0x10) == 0);
            ad_val = (int)ADCL + ((int)ADCH << 8);
        AD_DS(ad_val);
        
        SW = PINE & 0b00010000;
        if(SW == 0)
        {
            LCD_IDLE();
            flag = 0;
            delay_ms(500);
        }
        delay_ms(1000);
        delay_ms(1000);
        
        LCD_standby();
        
        if(ival >= 100 )               
            FAIL();   
        else
            COMPLETE(); 
    }
}

void AD_DS(int val)
{ 
    fval = (float)val * 5.0 / 1023.0;
    ival = (int)(fval * 100.0 + 0.5);    
}

void LCD_standby()
{
     flag = 1;
     LCD_init();
     LCD_String(" Sensor Active ");
     Command(LINE2);
     LCD_String("Wating for 3 sec"); 
     delay_ms(1000);
     
     Command(LINE2);
     LCD_String("Wating for 2 sec"); 
     delay_ms(1000);
     
     Command(LINE2);
     LCD_String("Wating for 1 sec"); 
     delay_ms(1000);
       
}
void COMPLETE()
{
    delay_ms(5);
    LCD_init();
    LCD_String("Recieve complete");
}

void FAIL()
{
    delay_ms(5);
    LCD_init();
    LCD_String("Recieve FAIL");    
}

void LCD_IDLE()
{
    LCD_init();
    LCD_String(" Sensor Inactive"); 
    Command(LINE2);
    LCD_String("   Intial Mode");    
}

 
void LCD_init(void)
{       
    DDRD = 0xFF;  
    PORTD &= 0xFB;  
                  
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

    PORTD = (byte & 0xF0);        // 데이터    
    PORTD &= 0xFE;            //RS = 0;           
    PORTD &= 0xFD;            //RW = 0;  
    delay_us(1);     
    PORTD |= 0x04;            //E = 1;
    delay_us(1);
    PORTD &= 0xFB;            //E = 0;

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
        
    PORTD = (byte & 0xF0);        // 데이터
    PORTD |= 0x01;            //RS = 1;
    PORTD &= 0xFD;            //RW = 0;
    delay_us(1);         
    PORTD |= 0x04;            //E = 1;
    delay_us(1);
    PORTD &= 0xFB;            //E = 0;

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