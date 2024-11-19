#ifndef INC_DISPLAY_7SEG_H_
#define INC_DISPLAY_7SEG_H_

#include "global.h"

extern int led_buffer[4];

void display7SEG(int);
void update7SEG(int);
void updateLedBuffer();
void display_7seg_run();

#endif /* INC_DISPLAY_7SEG_H_ */
