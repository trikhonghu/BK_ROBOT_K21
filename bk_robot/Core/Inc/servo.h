/*
 * servo.h
 *
 *  Created on: Jun 14, 2024
 *      Author: Windows
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "tim.h"

#define SERVO1	0
#define SERVO2	1
#define SERVO3	2

void servo3_init();
void servo3_set_duty_cycle(uint16_t _duty_cycle);

void servo_init(uint8_t id);
void servo_set_angle(uint8_t id, uint16_t angle);

#endif /* INC_SERVO_H_ */
