#include <mega128.h>
#include <delay.h> 

#define FUNCSET       0x28    // Function Set
#define ENTMODE       0x06    // Entry Mode Set
#define ALLCLR        0x01    // All Clear
#define DISPON        0x0c     // Display On
#define LINE2         0xC0    // 2nd Line Move

typedef unsigned char u_char;

u_char mode = 0, mod = 0;       // mode 변수 선언 및 초기화
u_char cnt = 0, cnt1 = 0;        // cnt 변수 선언 및 초기화
u_char sec = 0, sec1 = 0;        // sec 변수 선언 및 초기화
float  fval;           // 적외선 센서 fval 변수 선언
int  ival;             // 적외선 센서 ival 변수 선언

void LCD_init(void);             // LCD 함수 선언
void LCD_String(char flash *);  
void Busy(void);
void Command(unsigned char);
void Data(unsigned char);

void DC_F();              // 장애물을 감지하지 못하였을 때 동작하는 함수 선언
void DC_B();              // 장애물을 감지하였을 때 동작하는 함수 선언
  
void  AD_disp(int);         // A/D 변환값 표시 함수 선언 

void main()               // 메인함수
{
    int   ad_val;

    DDRA = 0xFF;
    DDRF = 0xF0;                 //PF4-PF7 출력, PF0-PF3 입력
    DDRC = 0xFF;
    TIMSK = 0x01;               // TOIE0 = 1(타/카0 오버플로우 인터럽트 인에이블0
    TCCR0 = 0x07;               // 일반모드, 1024분주
    TCNT0 = 0x00;               // 타이머/카운터0 레지스터 초기값
     
    ADMUX = 0b01000000;        // ADC0 단극성 입력 선택 
    ADCSRA = 0x87;            // ADEN=1, ADFR=1, ADSC=1, 16MHz  256분주 -> 125kHz
           
    SREG=0x80;                //전역 인터럽트 인에이블 I 비트 셋  
        
    LCD_init();
    
    LCD_String("  CL ROBOT  ");    // 첫번째 라인에 출력
    Command(LINE2);
    LCD_String(" NOW START  ");    // 두번째 라인에 출력


    
    while(1){
             ADCSRA = 0xC7;                          // ADEN=1, ADSC = 1 변환 시작
             while((ADCSRA & 0x10) == 0);            // ADIF=1이 될떄까지      
             ad_val = (int)ADCL + ((int)ADCH << 8);  // A/D값 읽기
             AD_disp(ad_val);                        // A/D 변환값 표시
                if(ival>=100){
                  DC_B();                        // 적외선 센서가 장애물 감지할 때, ????약 13cm???
                             }                                
                else { 
                    DC_F();                      // 적외선 센서가 장애물을 감지하지 못했을 때   
                                   
                        }
    
            }

}


void AD_disp(int val)
{                
    fval = (float)val * 5.0 / 1023.0;       // 전압값으로 변환
    ival = (int)(fval  * 100.0 + 0.5);      // 반올림 후 정수화(소수 둘째자리까지) 
}     



void DC_F()              // 적외선 센서가 장애물을 감지하지 못했을 때 청소로봇 동작
{


    LCD_init();        // LCD 초기화
    
    LCD_String("    NOW    ");    // 첫번째 라인에 출력
    Command(LINE2);
    LCD_String("  CLEANING  ");            // 두번째 라인에 출력


 if(cnt1 >= 61){          // 시간값 갱신 16.384ms * 61 = 1초
                        cnt1 = 0;
                        sec1 = sec1 + 1;
                        if(sec1 == 2) {           //2초마다    
                                      sec1 = 0;
                                      mod = (mod + 1) % 4; //모드1, 2, 3,0  // 전진, 시계방향회전, 전진, 반시계방향회전 반복
                                       
                                      if(mod==1) {
                                                    PORTA = 0b00000101; // 청소로봇 2초간 직진 운행
                                                    PORTC = 0b11111100; // 정상 운행시 하얀 LED 점등 
                                      }
                                      
                                      else if( mod==2) {
                                                    PORTA = 0b00001100; // 청소로봇 2초간 시계방향으로 돌면서 청소
                                                    PORTC = 0b11111100; // 정상 운행시 하얀 LED 점등                                      
                                      }
                                      
                                      else if( mod==3) {
                                                    PORTA = 0b00000101; // 청소로봇 2초간 직진 운행    
                                                    PORTC = 0b11111100; // 정상 운행시 하얀 LED 점등                                                                                                                                                            
                                      }
                                      
                                      else if( mod==0) {
                                                    PORTA = 0b00000011; // 청소로봇 2초간 반시계방향으로 돌면서 청소    
                                                    PORTC = 0b11111100; // 정상 운행시 하얀 LED 점등                                                                                                                                                           
                                      }
                                   
                                        
                                } 
                        }
}

void DC_B()              // 적외선 센서가 장애물 감지할 때의 청소로봇 동작
{
    LCD_init();        // LCD 초기화
    
    LCD_String("   STOP    ");    // 첫번째 라인에 출력
    Command(LINE2);
    LCD_String("  CLEANING  ");            // 두번째 라인에 출력

if(cnt >= 61){          // 시간값 갱신 16.384ms * 61 = 1초
                        cnt = 0;
                        sec = sec + 1;
                        if(sec == 2) {           //2초마다    
                                      sec = 0;
                                      mode = (mode + 1) % 2; //모드1,0  // 후진, 시계방향으로 방향전환
                                       
                                      if(mode==1) {
                                                    PORTA = 0b00001111; // 청소로봇 2초간 후진 운행
                            PORTC = 0b11110011; // 장애물 발견하고 동작시 빨간 LED점등 
                                      }
                                      
                                      else if( mode==0) {
                                                    PORTA = 0b00001100; // 청소로봇 2초간 시계방향으로 방향전환
                            PORTC = 0b11110011; // 장애물 발견하고 동작시 빨간 LED점등                              
                                      }
                                } 
            }
}

// LCD 초기화  
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

// 문자열 출력 함수
void LCD_String(char flash *str)
{
    char flash *pStr=0;
    
    pStr = str;    
    while(*pStr) Data(*pStr++);
}                                     

// 인스트럭션 쓰기 함수
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
                    
//데이터 쓰기 함수
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

// Busy Flag Check -> 일반적인 BF를 체크하는 것이 아니라
// 일정한 시간 지연을 이용한다.
void Busy(void)
{
    delay_ms(2);
}



// 타이머/카운터0 오버플로우 인터럽트 처리, 주기 = 1/16 * 1024 * 256 = 16.384ms
interrupt [TIM0_OVF] void timer0_int(void) 
{
    TCNT0 = 0x0;            // 타이머/카운터0 초기값 재설정(생략가능)
    if(ival>=100) cnt++;                    // 인터럽트 회수 +1
    else cnt1++;
 }    