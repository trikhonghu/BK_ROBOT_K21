/*
 * servo.c
 *
 *  Created on: Jun 14, 2024
 *      Author: Windows
 */


#include "servo.h"

uint16_t duty_cycle = 0;

/*
 * servo3 : channel 3
 * servo2 : channel 2
 * servo1 : channel 1
 * Dung hoi tai sao tai schematic no nhu the
 *
 * servo3 : pick. 0 degree is open, 60 degree is completely close
 */
uint32_t servo_channel[3] = {TIM_CHANNEL_3, TIM_CHANNEL_2, TIM_CHANNEL_1};

void servo3_init(){
	HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
}

void servo3_set_duty_cycle(uint16_t _duty_cycle){
	duty_cycle = _duty_cycle;
	__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1,duty_cycle);
}

void servo_init(uint8_t id){
	HAL_TIM_PWM_Start(&htim4, servo_channel[id]);
}

/*
 * the range is from 20 to 130 (0 to 180 degree)
 * id 1,2,3
 */
void servo_set_angle(uint8_t id, uint16_t angle){
	if(angle < 0 || angle > 180) return;
	uint16_t duty_cycle_ = (angle*110)/180 + 20;
	__HAL_TIM_SET_COMPARE(&htim4, servo_channel[id-1], duty_cycle_);
}

