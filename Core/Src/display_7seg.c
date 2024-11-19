#include "display_7seg.h"

int led_buffer[4] = {0};

void display7SEG(int num) {
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOA, SEG_0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_4_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, SEG_5_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, SEG_6_Pin, RESET);
			break;
		default:
			break;
	}
}

void update7SEG(int index) {
	switch (index % 4) {
		case 0:
			HAL_GPIO_WritePin(GPIOA, EN_0_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN_2_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN_3_Pin, SET);
			display7SEG(led_buffer[0]);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, EN_1_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN_0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN_2_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN_3_Pin, SET);
			display7SEG(led_buffer[1]);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, EN_2_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN_0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN_3_Pin, SET);
			display7SEG(led_buffer[2]);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, EN_3_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, EN_0_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN_1_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, EN_2_Pin, SET);
			display7SEG(led_buffer[3]);
			break;
		default:
			break;
	}
}

void updateLedBuffer() {
	led_buffer[0] = timer / 10;
	led_buffer[1] = timer % 10;
	led_buffer[2] = timer1 / 10;
	led_buffer[3] = timer1 % 10;
}

void display_7seg_run() {
	updateLedBuffer();
	if (timer_flag[1] == 1 && mode) {
		timer--;
		timer1--;
		setTimer(1, 1000);
	}
	if (timer_flag[2] == 1) {
		update7SEG(index_led++);
		setTimer(2, 250);
	}
}
