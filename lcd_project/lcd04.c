// 파일명 : lcd04.c
// 설  명 : 문자 패턴 등록후 표시하기 
// 주  의 : 포트를 직접 제어하여 LCD를 사용한다.
//	    RS  - PD0
//	    R/W - PD1
//	    EN  - PD2
//          DB4  - PD4
//	    DB5  - PD5
//	    DB6  - PD6
//	    DB7  - PD7
             
#include <mega8515.h>        
#include <delay.h>

#define FUNCSET	0x28	// Function Set
#define ENTMODE	0x06	// Entry Mode Set
#define ALLCLR	0x01	// All Clear
#define DISPON	0x0c 	// Display On                       
#define LSHIFT	0x18	// Display Left Shift     
#define HOME	0x02	// Cursor Home

flash unsigned char cg_pat[24] =
            {0x1F, 0x04, 0x0A, 0x11, 0x04, 0x1F, 0x00, 0x00,   // '조'
             0x09, 0x17, 0x17, 0x09, 0x00, 0x06, 0x09, 0x06,   // '영'
             0x1F, 0x04, 0x0A, 0x11, 0x1F, 0x04, 0x10, 0x1F};  // '준'

void LCD_init(void);
void LCD_String(char flash *);
void Busy(void);
void Command(unsigned char);
void Data(unsigned char);

void main(void)
{                          
	int i;
	
	LCD_init();       
        
	// 첫 번째 라인에 출력
    	for(i = 0;i < 24;i++){
    	 	Command(0x40 + i);
    	 	Data(cg_pat[i]);
    	}
    	
    	Command(HOME);
    	LCD_String(" My Name is ");
	Data(0x00);	// '조' 또는 0x08
	Data(0x01);	// '영' 또는 0x09
	Data(0x02);	// '준' 또는 0x0A
}

// LCD 초기화  
void LCD_init(void)
{       
	DDRD = 0xFF;			// 포트 D 출력 설정
	PORTD &= 0xFB;			// E = 0;
	              
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
	PORTD = (byte & 0xF0);		// 데이터	
	PORTD &= 0xFE;			//RS = 0;           
	PORTD &= 0xFD;			//RW = 0;  
	delay_us(1);     
	PORTD |= 0x04;			//E = 1;
	delay_us(1);
	PORTD &= 0xFB;			//E = 0;

	// 인스트럭션 하위 바이트
        PORTD = ((byte<<4) & 0xF0);	// 데이터
	PORTD &= 0xFE;			//RS = 0;
	PORTD &= 0xFD;			//RW = 0;
	delay_us(1);     	
	PORTD |= 0x04;			//E = 1;
	delay_us(1);
	PORTD &= 0xFB;			//E = 0;
}

//데이터 쓰기 함수
void Data(unsigned char byte)
{
	Busy();
        
	// 데이터 상위 바이트
	PORTD = (byte & 0xF0);		// 데이터
	PORTD |= 0x01;			//RS = 1;
	PORTD &= 0xFD;			//RW = 0;
	delay_us(1);     	
	PORTD |= 0x04;			//E = 1;
	delay_us(1);
	PORTD &= 0xFB;			//E = 0;

	// 데이터 하위 바이트
	PORTD = ((byte<<4) & 0xF0);  	// 데이터
	PORTD |= 0x01;			//RS = 1;
	PORTD &= 0xFD;			//RW = 0;     
	delay_us(1);     	
	PORTD |= 0x04;			//E = 1;
	delay_us(1);
	PORTD &= 0xFB;			//E = 0;
}

// Busy Flag Check -> 일반적인 BF를 체크하는 것이 아니라
// 일정한 시간 지연을 이용한다.
void Busy(void)
{
	delay_ms(2);
}
