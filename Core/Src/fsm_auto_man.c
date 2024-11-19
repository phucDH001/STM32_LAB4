#include "fsm_auto_man.h"

void clearAllLed() {
	HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, SET);
	HAL_GPIO_WritePin(GPIOA, LED_AMBER_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, LED_RED_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, LED_GREEN_1_Pin, SET);
	HAL_GPIO_WritePin(GPIOB, LED_AMBER_1_Pin, SET);
}

void fsm_auto_man_run() {
	switch (status) {
		case INIT:
			clearAllLed();
			status = RED_GREEN;
			timer = red;
			timer1 = green;
			setTimer(0, timer1 * 1000);
			break;
		//TODO AUTOMATIC
		case RED_GREEN:
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, LED_RED_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, LED_AMBER_1_Pin, SET);
			if (timer_flag[0] == 1) {
				status = RED_AMBER;
				timer1 = amber;
				setTimer(0, timer1 * 1000);
			}
			if (isButtonPressed(0) == 1) {
				clearAllLed();
				status = MAN_RED;
				timer = red;
				timer1 = 2;
				mode = 1 - mode;
				setTimer(0, 250);
			}
			break;
		case RED_AMBER:
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, LED_RED_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, LED_AMBER_1_Pin, RESET);
			if (timer_flag[0] == 1) {
				status = GREEN_RED;
				timer = green;
				timer1 = red;
				setTimer(0, timer * 1000);
			}
			if (isButtonPressed(0) == 1) {
				clearAllLed();
				status = MAN_RED;
				timer = red;
				timer1 = 2;
				mode = 1 - mode;
				setTimer(0, 250);
			}
			break;
		case GREEN_RED:
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, LED_RED_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, LED_AMBER_1_Pin, SET);
			if (timer_flag[0] == 1) {
				status = AMBER_RED;
				timer = amber;
				setTimer(0, timer * 1000);
			}
			if (isButtonPressed(0) == 1) {
				clearAllLed();
				status = MAN_RED;
				timer = red;
				timer1 = 2;
				mode = 1 - mode;
				setTimer(0, 250);
			}
			break;
		case AMBER_RED:
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, LED_RED_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOB, LED_GREEN_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOB, LED_AMBER_1_Pin, SET);
			if (timer_flag[0] == 1) {
				status = RED_GREEN;
				timer = red;
				timer1 = green;
				setTimer(0, timer1 * 1000);
			}
			if (isButtonPressed(0) == 1) {
				clearAllLed();
				status = MAN_RED;
				timer = red;
				timer1 = 2;
				mode = 1 - mode;
				setTimer(0, 250);
			}
			break;
		//TODO MANUAL
		case MAN_RED:
			if (timer_flag[0] == 1) {
				HAL_GPIO_TogglePin(GPIOA, LED_RED_Pin);
				HAL_GPIO_TogglePin(GPIOB, LED_RED_1_Pin);
				setTimer(0, 250);
			}
			if (isButtonPressed(0) == 1) {
				clearAllLed();
				status = MAN_AMBER;
				timer = amber;
				timer1 = 3;
				setTimer(0, 250);
			}
			if (isButtonPressed(1) == 1) {
				timer = timer < 99 ? timer + 1 : 1;
			}
			if (isButtonPressed(2) == 1) {
				red = timer;
			}
			break;
		case MAN_AMBER:
			if (timer_flag[0] == 1) {
				HAL_GPIO_TogglePin(GPIOA, LED_AMBER_Pin);
				HAL_GPIO_TogglePin(GPIOB, LED_AMBER_1_Pin);
				setTimer(0, 250);
			}
			if (isButtonPressed(0) == 1) {
				clearAllLed();
				status = MAN_GREEN;
				timer = green;
				timer1 = 4;
				setTimer(0, 250);
			}
			if (isButtonPressed(1) == 1) {
				timer = timer < 99 ? timer + 1 : 1;
			}
			if (isButtonPressed(2) == 1) {
				amber = timer;
			}
			break;
		case MAN_GREEN:
			if (timer_flag[0] == 1) {
				HAL_GPIO_TogglePin(GPIOA, LED_GREEN_Pin);
				HAL_GPIO_TogglePin(GPIOB, LED_GREEN_1_Pin);
				setTimer(0, 250);
			}
			if (isButtonPressed(0) == 1) {
				if (red == amber + green) {
					mode = 1 - mode;
					status = INIT;
					index_led = 0;
					setTimer(1, 10);
					setTimer(2, 20);
				}
				else {
					clearAllLed();
					status = MAN_RED;
					timer = red;
					timer1 = 2;
					setTimer(0, 250);
				}
			}
			if (isButtonPressed(1) == 1) {
				timer = timer < 99 ? timer + 1 : 1;
			}
			if (isButtonPressed(2) == 1) {
				green = timer;
			}
			break;
		default:
			break;
	}
}
