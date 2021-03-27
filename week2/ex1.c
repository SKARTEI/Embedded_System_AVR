#include <mega128.h>

void main()
{
    DDRC = 0xFF;
    
    PORTC = 0x55;
    while(1);
}