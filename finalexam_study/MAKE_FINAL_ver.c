#include <mega128.h>        
#include <delay.h>

#define FUNCSET       0x28    // Function Set
#define ENTMODE       0x06    // Entry Mode Set
#define ALLCLR        0x01    // All Clear
#define DISPON        0x0c     // Display On
#define LINE2         0xC0    // 2nd Line Move
#define HOME          0x02  //cursor home
void LCD_init(void);
void LCD_String(char flash *);                // LCD function
void Busy(void);
void Command(unsigned char);
void Data(unsigned char);

void AD_DS(int);
void LOAD_CHECK();                            // ADC function
void FRONTBACK_CHECK();
void NEGLECT();
void LCD_IDLE();
void LCD_mov();

void initial_go();                            // MOVING function
void initial_back();
void move_go(int);
void move_back(int);
void waiting();


void straight_1(int);
void left_1(int);
void right_1(int);
void backward_1(int);

float fval;
int ival;
unsigned int state_flag = 0, timer_counting = 0, First_desti = 0, Second_desti = 0; 
unsigned char R_num;

void main(void)
{      
    int ad_val, i;
    unsigned char SW;        
    
    DDRA = 0xFF;
    DDRE = 0x0;  
    PORTA = 0b00000000; // DC motor driver
    
    TIMSK = 0x04;
    TCCR1A = 0x0;
    TCCR1B = 0x05;
    TCCR1C = 0x0;
    TCNT1 = 49911; // 1s
    
    ADMUX = 0b01000010;   // PE2 초기 설정한다. 
    ADCSRA = 0x87;        // 단일 변환모드 
    
    UCSR0A = 0x0;
    UCSR0B = 0b10011000;
    UCSR0C = 0b00000110;
    UBRR0H = 0;
    UBRR0L = 103;
    SREG = 0x80;
    
    LCD_IDLE();
    for(i = 1 ; i <3 ; i++)
        delay_ms(1000);
        
    LCD_init();
    
    while(1)
    {   
        ADCSRA = ADCSRA | 0b01000000;
        while((ADCSRA & 0x10) == 0);
            ad_val = (int)ADCL + ((int)ADCH << 8);
        AD_DS(ad_val);
        SW = PINE & 0b00010000;
        
        if((state_flag >= 0) || (state_flag <= 2))  {
        if(ival >= 140)         
            LOAD_CHECK();
        else   
            NEGLECT();
        }
                        
        if(SW == 0)
        {
            if(state_flag == 3)     
                state_flag = 4; 
            else if(state_flag != 3);
                NEGLECT();
        } 
        
        if((First_desti !=0) && state_flag ==4 )
        {
            initial_go();
            move_go(First_desti);           //move to first destination
            state_flag = 6;
            waiting();                      // arrive & wait
            state_flag = 5;
            move_back(First_desti);         // back to the 분기점
                                            // 1차 왕복 완료   
                                            
            if(Second_desti == 5)   {       // 1개만 입력될 경우 2차 경유지 값이 5로 저장된다.
                initial_back();
                state_flag =0;
            }
            else
            {
                state_flag = 4;
                move_go(Second_desti);
                state_flag = 7;
                waiting();
                state_flag = 5;
                move_back(Second_desti);
                initial_back();
                state_flag = 0;
            }               
            First_desti = 0;
            Second_desti = 0;
            LCD_init();   
            
            LCD_String("Delivery End");
            Command(LINE2);
            LCD_String("Thank You");
            
            for(i = 0 ; i < 3 ; i++)
                delay_ms(1000);
            LCD_init();  
            ADMUX = 0b01000010;
        }      
    }
}

interrupt [TIM1_OVF] void IR_recheck (void)       // IR SENSOR(LOAD) 갱신 방법
{
    TCNT1 = 49911; 
    
    if(timer_counting ==3)
    {   
        timer_counting = 0;
        if(state_flag == 0 || state_flag > 2)
            NEGLECT();
        else if(state_flag == 1 || state_flag == 2){
            LCD_init();
            state_flag = 0;
            ADMUX = 0b01000010;                           
        }
    }
    else
        timer_counting++;
}

interrupt [USART0_RXC] void destination_recieve (void)
{
    R_num = UDR0;   // recieve
    
    if(R_num == 'w')    {  
        straight_1(100);
    }
    else if(R_num == 'x')   {              
        backward_1(100); 
    }
    else if(R_num == 'y')   {          
        left_1(40);
        
    }
    else if(R_num == 'z')   {         
        right_1(33);
    } 
    else if(R_num == 'o'){
        PORTA = 0b10101010; 
    }
    else if(R_num == 'p'){
        PORTA = 0b01010101;
    }
    else if(R_num == 'q'){
        PORTA = 0b10100101;
    }
    else if(R_num == 'r'){
        PORTA = 0b01011010;
    }
    else if(R_num == 's'){     //정지
        PORTA = 0b00000000;
    }
    
    
        
    if((state_flag == 2))   {
        state_flag = 3;   
        if(R_num == 'a')    {
            LCD_mov();
            LCD_String("1st: 1    2nd: 2");
            First_desti = 1;
            Second_desti = 2;
        }
        else if(R_num == 'b')   {              
            LCD_mov();
            LCD_String("1st: 1    2nd: 3");
            First_desti = 1;
            Second_desti = 3;
        }
        else if(R_num == 'c')   {          
            LCD_mov();
            LCD_String("1st: 1    2nd: 4");     // 1 to 2 3 4       
            First_desti = 1;
            Second_desti = 4;
        }
        else if(R_num == 'd')   {          
            LCD_mov();
            LCD_String("1st: 2    2nd: 1");
            First_desti = 2;
            Second_desti = 1;
        }
        else if(R_num == 'e')   {              
            LCD_mov();
            LCD_String("1st: 2    2nd: 3");
            First_desti = 2;
            Second_desti = 3;
        }
        else if(R_num == 'f')   {         
            LCD_mov();
            LCD_String("1st: 2    2nd: 4");   // 2 to 1 3 4       
            First_desti = 2;
            Second_desti = 4;
        }
        else if(R_num == 'g')   {               
            LCD_mov();
            LCD_String("1st: 3    2nd: 1");  
            First_desti = 3;
            Second_desti = 1;
        }
        else if(R_num == 'h')   {              
            LCD_mov();
            LCD_String("1st: 3    2nd: 2");  
            First_desti = 3;
            Second_desti = 2;
        }
        else if(R_num == 'i')   {               
            LCD_mov();
            LCD_String("1st: 3    2nd: 4");    // 3 to 124          
            First_desti = 3;
            Second_desti = 4;
        }
        else if(R_num == 'j')   {             
            LCD_mov();
            LCD_String("1st: 4    2nd: 1"); 
            First_desti = 4;
            Second_desti = 1;
        }
        else if(R_num == 'k')   {            
            LCD_mov();
            LCD_String("1st: 4    2nd: 2");      
            First_desti = 4;
            Second_desti = 2;
        }
        else if(R_num == 'l')   {                 
            LCD_mov();
            LCD_String("1st: 4    2nd: 3");     // 4 to 123       
            First_desti = 4;
            Second_desti = 3;
        }
        else
            NEGLECT();      
    } 
    else if((state_flag == 1))  { 
        state_flag = 3;
         if(R_num == '1')    {
            LCD_mov();
            LCD_String("1st: 1"); 
            First_desti = 1;
            Second_desti = 5;
        }
        else if(R_num == '2')   {              
            LCD_mov();
            LCD_String("1st: 2");  
            First_desti = 2;
            Second_desti = 5;
        }
        else if(R_num == '3')   {          
            LCD_mov();
            LCD_String("1st: 3");  
            First_desti = 3;
            Second_desti = 5;
        }
        else if(R_num == '4')   {          
            LCD_mov();
            LCD_String("1st: 4"); 
            First_desti = 4;
            Second_desti = 5;
        }
        else
            NEGLECT();                  
    }
    else
        NEGLECT(); 
       
}

void AD_DS(int val)
{ 
    fval = (float)val * 5.0 / 1023.0;
    ival = (int)(fval * 100.0 + 0.5);    
}

void LOAD_CHECK()
{
    if(state_flag == 0) // PE0
    {   
       LCD_init();
       LCD_String("1st Load OK"); 
       state_flag = 1;                        
       ADMUX = 0b01000011;
    }
    else if(state_flag == 1) //PE1
    {
        Command(LINE2);
        LCD_String("2nd Load OK");
        state_flag = 2;
        ADMUX = 0b01000010;
    }
    else
        NEGLECT();  
}
void FRONTBACK_CHECK()
{
    int ad_val;
    ADCSRA = ADCSRA | 0b01000000;
        while((ADCSRA & 0x10) == 0);
            ad_val = (int)ADCL + ((int)ADCH << 8);
        AD_DS(ad_val);
        
        if(ival >= 150) 
        {         
            PORTA = 0b00000000;
            delay_ms(3000);
            if (state_flag == 4)
                PORTA = 0b10101010;
            else if(state_flag == 5)
                PORTA = 0b01010101;   
            ival = 0;
        }    
        else   
            delay_us(1);
           
}

void waiting()
{
    int ad_val, i;
    for(i = 1; i <= 10; i++)
        delay_ms(1000);
        
    if (state_flag == 6)
        ADMUX = 0b01000010;    //PF2 
    else if(state_flag == 7)
        ADMUX = 0b01000011;    //PF3 
        
    ADCSRA = ADCSRA | 0b01000000;
        while((ADCSRA & 0x10) == 0);
            ad_val = (int)ADCL + ((int)ADCH << 8);
        AD_DS(ad_val);
        
        if(ADMUX == 0b01000010)
        {
            if(ival < 130)
            {         
                Command(HOME);
                LCD_String("1stDelivery SUCC");
            }
            else   
            {
                Command(HOME);
                LCD_String("1stDelivery FAIL");
            }  
        }
        else if(ADMUX == 0b01000011)
        {
            if(ival < 130)
            {         
                Command(LINE2);
                LCD_String("2ndDelivery SUCC");
            }
            else   
            {
                Command(LINE2);
                LCD_String("2ndDelivery FAIL");
            }
        }
}

void initial_go()
{
    straight_1(200);   
}
void initial_back()
{
     backward_1(200);  
} 
void move_go(int a)
{
     if(a == 1)
     {
        straight_1(20);
        left_1(33);
        straight_1(180);   
     }           
     else if(a == 2) 
     {  
        straight_1(20);
        left_1(33);
        straight_1(80);
        right_1(37);
        straight_1(80);
     }
     else if(a == 3)
     {  
        right_1(40);
        straight_1(230);
        right_1(37);
        straight_1(115);
     }
     else if(a == 4)
     {
        left_1(33);
        straight_1(80);
        left_1(35);
        straight_1(80);
     }   
}
void move_back(int a)
{
    if(a == 1)
     {  
        backward_1(180);   
        right_1(36);
        backward_1(20);
     }           
     else if(a == 2) 
     {  
        backward_1(80); 
        left_1(37); 
        backward_1(100);
        right_1(34);   
        backward_1(10);
     }
     else if(a == 3)
     {          
        backward_1(115);  
        left_1(38);
        backward_1(230);
        left_1(38);
        backward_1(20);
     }
     else if(a == 4)
     {
        backward_1(80);
        right_1(37);
        backward_1(80);
        right_1(38);
     } 
}

void straight_1(int act_time)
{
    int i;
    int act_num = 100 * act_time;     
    ADMUX = 0b01000000;
    for(i = 1; i <= act_num; i++)
    {   
        FRONTBACK_CHECK(); 
        PORTA = 0b10101010; 
        delay_ms(1);
    }                
    PORTA = 0b00000000;
}
void left_1(int act_time)
{
    int i;
    ADCSRA = ADCSRA & 0b10111111;            //시계 반대 방향 선회중 전후방 적외선 센서 OFF
    for(i = 1; i <= act_time; i++)
    {
        PORTA = 0b10100101;
        delay_ms(100);
    }                 
    PORTA = 0b00000000;
    ADCSRA = ADCSRA | 0b01000000;            // 선회 완료시 적외선 센서 재작동 
}
void right_1(int act_time)
{
    int i;
    ADCSRA = ADCSRA & 0b10111111;            //시계 방향 선회중 전후방 적외선 센서 OFF
    for(i = 1; i <= act_time; i++)
    {
        PORTA = 0b01011010;
        delay_ms(100);
    } 
    PORTA = 0b00000000;  
    ADCSRA = ADCSRA | 0b01000000;             // 선회 완료시 적외선 센서 재작동 
}
void backward_1(int act_time)
{
    int i;
    int act_num = 100 * act_time;
    ADMUX = 0b01000001;  
    for(i = 1; i <= act_num; i++)
    {   
        FRONTBACK_CHECK();
         
        PORTA = 0b01010101;
        delay_ms(1);
    }                
    PORTA = 0b00000000;
}
void NEGLECT()
{
    delay_us(500);
}
//-----------------LCD-------------------
                    
void LCD_IDLE()
{
    LCD_init();
    LCD_String("2017161041"); 
    Command(LINE2);
    LCD_String("Serving Robot");    
}

void LCD_mov()
{
    LCD_init();
    LCD_String("MOVING POINT");
    Command(LINE2);
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
