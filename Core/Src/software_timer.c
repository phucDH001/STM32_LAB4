#include "software_timer.h"

int timer_counter[3] = {0};
int timer_flag[3] = {0};
int TIMER_CYCLE = 10;

void setTimer(int idx, int duration) {
	timer_counter[idx] = duration / TIMER_CYCLE;
	timer_flag[idx] = 0;
}

void timerRun() {
	for (int i = 0; i < 3; i++) {
		if (timer_counter[i] > 0) {
			timer_counter[i]--;
			if (timer_counter[i] == 0) timer_flag[i] = 1;
		}
	}
}

