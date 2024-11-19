#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "main.h"

extern int timer_counter[3], timer_flag[3];

void setTimer(int, int);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
