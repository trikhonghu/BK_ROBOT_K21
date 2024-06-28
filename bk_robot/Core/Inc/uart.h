/*
 * uart.h
 *
 *  Created on: Jun 18, 2024
 *      Author: dell
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "usart.h"
#include <stdio.h>
#include <stdint.h>
#include "servo.h"
#include "step_motor.h"
#include "move.h"
#include "gpio.h"
#include "joystick.h"
#include "buzzer.h"

/*
 * DC MOTOR
 */
#define STOP		0
#define FORWARD		1
#define BACKWARD	2
#define LEFT		3
#define RIGHT		4
#define BUZZER		5
#define IDLE		6

/*
 * UART COMMAND
 */

#define DIGITAL_MODE 	0x01
#define JOYSTICK_MODE	0x02
#define ACCELE_MODE		0x03


#define STOP_DATA	0x00

#define FW_DATA		0x01
#define BW_DATA		0x02
#define LT_DATA		0x04
#define RT_DATA		0x08

#define BZ_DATA		0x01

/*
 * SERVO
 */

#define SERVO_OPEN		0
#define SERVO_CLOSE		1
#define SERVO_INACTIVE	2

/*
 * STEP MOTOR
 */

#define UP_SM		0
#define DOWN_SM		1
#define SM_INACTIVE 2

/*
 * UART state
 */

#define WAITING		0
#define RECEIVE		1
#define CHECK		2

extern uint8_t idx;
extern uint8_t buffer[8];
extern uint8_t move_state;
extern uint8_t uart_state;

extern uint8_t servo_state;
extern uint8_t sm_state;

void uart_init();
void move_process();
void servo_process();
void sm_process();

#endif /* INC_UART_H_ */
