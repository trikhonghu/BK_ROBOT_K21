/*
 * move.h
 *
 *  Created on: Jun 18, 2024
 *      Author: Windows
 */

#ifndef INC_MOVE_H_
#define INC_MOVE_H_

#include <stdint.h>
#include "tim.h"
#include "main.h"
#include "button.h"

#define ROBOT_DIR_R			1
#define ROBOT_DIR_RF		2
#define ROBOT_DIR_FW		3
#define ROBOT_DIR_LF		4
#define ROBOT_DIR_LB		5
#define ROBOT_DIR_RB		6
#define ROBOT_DIR_SL		7
#define ROBOT_DIR_SR		8
#define ROBOT_DIR_BW		9
#define ROBOT_DIR_L			10

#define 	MIN_SPEED		20
#define 	MAX_SPEED		30

void dc_init();

void dc1Move(int duty_cycle);
void dc2Move(int duty_cycle);
void dc3Move(int duty_cycle);
void dc4Move(int duty_cycle);

//                   forward
//           frontLeft   |  frontRight          ↺: rotateLeft
//         left		  ---+----     right		↻: rotateRight
//           backLeft    |  backRight
//                  backwards
//

void stop();
void forward(int speed);
void backwards(int speed);
void frontLeft(int speed);
void frontRight(int speed);
void backLeft(int speed);
void backRight(int speed);
void right(int speed);
void left(int speed);
void rotateLeft(int speed);
void rotateRight(int speed);
void testDc();
void runDir(int dir, int speed);
void followLine();
int followLineUntilCross();

#endif /* INC_MOVE_H_ */
