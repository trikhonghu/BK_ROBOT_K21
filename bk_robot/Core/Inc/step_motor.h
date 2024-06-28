/*
 * step_motor.h
 *
 *  Created on: Jun 17, 2024
 *      Author: Windows
 */

#ifndef INC_STEP_MOTOR_H_
#define INC_STEP_MOTOR_H_

#include "tim.h"
#include "main.h"

void move_step_motor(uint8_t directtion, uint16_t cycle);

#endif /* INC_STEP_MOTOR_H_ */
