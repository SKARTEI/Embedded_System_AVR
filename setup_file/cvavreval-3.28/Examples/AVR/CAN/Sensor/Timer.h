
#ifndef TIMER_H_
#define TIMER_H_

#include <inttypes.h>

extern volatile uint8_t CTC_flag;

void timer_init(void);
void delay_usec(uint16_t us);
void delay_msec(uint16_t ms);

#endif /* TIMER_H_ */