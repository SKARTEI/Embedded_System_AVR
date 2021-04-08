
#include <io.h>
#include <interrupt.h>
#include "Timer.h"

ISR(TIM1_COMPA) {
	CTC_flag = 1;
}

// This function initializes a 16-bit timer used for delays.
void timer_init(void) {
	
	TIMSK1 = 0x00; //Disable timer interrupts
	TCCR1A = 0x00; //Timer not connected to any pins
	TCCR1B = 0x0A; //CTC mode; Timer_Rate = System_CLK/8 = 1MHz
	// 1 tick = 1 us (assume system clock = 8MHz)
}

// This is a blocking function that sets the timer value
// and waits until the value is reached. Waits for interrupt
// to execute.  Parameter "us" is truly 1 micro-second only
// if timer rate is set to 1MHz frequency. For example, this 
// project uses a system clock of 8MHz. Timer1 rate is set to
// System Clock divided by 8 which is 1MHz (in timer_init). 
// Therefore the "us" parameter truly is 1us.
void delay_usec(uint16_t us) {
	CTC_flag = 0; //Clear CTC Interrupt flag
	TCNT1H = 0x00; //Clear timer
    TCNT1L = 0x00;
	OCR1AH = ((uint8_t *) &us)[1]; //Load compare value with desired delay in us
    OCR1AL = ((uint8_t *) &us)[0];
	TIMSK1 = 0x02; //Enable OCIE1A Interrupt
	while(!CTC_flag); //wait for the designated number of us
}

void delay_msec(uint16_t ms) {
uint16_t i;
	for(i=0; i<ms; i++) {
		delay_usec(1000);
	}
}