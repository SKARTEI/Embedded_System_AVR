#include <mega128.h>
#include <delay.h>
flash unsigned char seg1_ten[10]= {0x3f,0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
flash unsigned char pi50[50] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1,9,7,1,6,9,3,9,9,3,7,5,1};
int seg4 = 0, seg3 = 1, seg2= 2, seg1= 3;
void SEG1_basic(void);
void left(void);
void right(void);

unsigned int check=0;
void main()
{
    DDRB = 0xFF;
    DDRF = 0xF0;
    
    EIMSK = 0b00010000;
    EICRB = 0b00000010;
    SREG = 0x80;
    
    while(1)
    {
        SEG1_basic();
        if(check == 0)
            left();
        else if(check == 1)
            right();
    }
}

void SEG1_basic(void)
{
    int i;
    for(i = 0; i < 50; i++)
    {
        PORTF = 0b01110000; 
        PORTB = seg1_ten[pi50[seg4]]; 
        delay_ms(5);
    
        PORTF = 0b10110000;
        PORTB = seg1_ten[pi50[seg3]];
        delay_ms(5);
       
        PORTF = 0b11010000; 
        PORTB = seg1_ten[pi50[seg2]];
        delay_ms(5);
    
        PORTF = 0b11100000; 
        PORTB = seg1_ten[pi50[seg1]];
        delay_ms(5);
    }
         
}

void left(void)
{
    seg4++;
    if(seg4 == 50)
        seg4 = 0;
        
    seg3++;
    if(seg3 == 50)
        seg3 = 0;
    
    seg2++;
    if(seg2 == 50)
        seg2 = 0;
        
    seg1++;
    if(seg1 == 50)
        seg1 = 0;
}

void right(void)
{   
        seg4--;
        if(seg4 == -1)
            seg4 = 49;
        
        seg3--;
        if(seg3 == -1)
            seg3 = 49;
    
        seg2--;
        if(seg2 == -1)
            seg2 = 49;
        
        seg1--;
        if(seg1 == -1)
            seg1 = 49;    
}


interrupt [EXT_INT4] void click (void)
{
    switch (check)
           {
           case 0:
           check = 1;
           break;

           case 1:
           check = 0;
           break;
           }               
}