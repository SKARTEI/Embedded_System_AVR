// 파일명 : lcd02.c
// 설  명 : LCD에 임의의 문자열을 출력한다. 
//	   표시된 문자열을 한번 깜박 거린 후에 우측으로 이동한다.
//	   전체가 이동하면 다시 처음부터 반복 
// 주  의 : 포트를 직접 제어하여 LCD를 사용한다.
//	    RS  - PD0
//	    R/W - PD1
//	    EN  - PD2
//          DB4  - PD4
//	    DB5  - PD5
//	    DB6  - PD6
//	    DB7  - PD7

#include <mega128.h>        
#include <delay.h>

#define FUNCSET	0x28	// Function Set
#define ENTMODE	0x06	// Entry Mode Set
#define ALLCLR	0x01	// All Clear
#define DISPON	0x0c 	// Display On                       
#define DISPOFF	0x08	// Display Off
#define LINE2	0xC0	// 2nd Line Move              
#define HOME	0x02	// Cursor Home
#define RSHIFT	0x1C	// Display Right Shift

void LCD_init(void);
void LCD_String(char flash *);
void Busy(void);
void Command(unsigned char);
void Data(unsigned char);

void main(void)
{                          
	int i;
	
	LCD_init();       
        
        while(1){                     
		Command(HOME); 
	    	LCD_String("Hello!! KUT-128");  // 첫 번째 라인에 출력
	    	Command(LINE2);
	    	LCD_String("Atmel ATmega128");	// 두 번째 라인에 출력
		                           
		delay_ms(500);		// 0.5초 시간 지연
		Command(DISPOFF);	// Display Off
		delay_ms(500);		// 0.5초 시간 지연
		Command(DISPON);
		delay_ms(1000);		// 1초 시간 지연
		
		// 16번 오른쪽으로 쉬프트
		for(i=0;i<16;i++) {
			Command(RSHIFT); 
			delay_ms(500);
		}
	}
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
