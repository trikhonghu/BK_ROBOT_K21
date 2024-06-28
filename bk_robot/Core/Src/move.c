/*
 * move.c
 *
 *  Created on: Jun 18, 2024
 *      Author: Windows
 */

#include "move.h"

#define		UP			1
#define 	DOWN 		0

uint32_t dc_channel[4] = {TIM_CHANNEL_4, TIM_CHANNEL_3, TIM_CHANNEL_1, TIM_CHANNEL_2};

void dc_init(){
	for(int i=0;i<4;i++){
		HAL_TIM_PWM_Start(&htim8, dc_channel[i]);
	}
}

void setSpeed(uint8_t dc, uint8_t duty_cycle) {
	__HAL_TIM_SET_COMPARE(&htim8, dc_channel[dc-1], duty_cycle);
}

void dc1Move(int duty_cycle){
	if(duty_cycle >= 0){
		HAL_GPIO_WritePin(M1_DIR_GPIO_Port, M1_DIR_Pin, UP);
		setSpeed(1, duty_cycle);
	}
	if(duty_cycle < 0){
		HAL_GPIO_WritePin(M1_DIR_GPIO_Port, M1_DIR_Pin, DOWN);
		setSpeed(1, duty_cycle*-1);
	}
}

void dc2Move(int duty_cycle){
	if(duty_cycle >= 0){
		HAL_GPIO_WritePin(M2_DIR_GPIO_Port, M2_DIR_Pin, UP);
		setSpeed(2, duty_cycle);
	}
	if(duty_cycle < 0){
		HAL_GPIO_WritePin(M2_DIR_GPIO_Port, M2_DIR_Pin, DOWN);
		setSpeed(2, duty_cycle*-1);
	}
}

void dc3Move(int duty_cycle){
	if(duty_cycle >= 0){
		HAL_GPIO_WritePin(M3_DIR_GPIO_Port, M3_DIR_Pin, DOWN);
		setSpeed(3, duty_cycle);
	}
	if(duty_cycle < 0){
		HAL_GPIO_WritePin(M3_DIR_GPIO_Port, M3_DIR_Pin, UP);
		setSpeed(3, duty_cycle*-1);
	}
}

void dc4Move(int duty_cycle){
	if(duty_cycle >= 0){
		HAL_GPIO_WritePin(M4_DIR_GPIO_Port, M4_DIR_Pin, DOWN);
		setSpeed(4, duty_cycle);
	}
	if(duty_cycle < 0){
		HAL_GPIO_WritePin(M4_DIR_GPIO_Port, M4_DIR_Pin, UP);
		setSpeed(4, duty_cycle*-1);
	}
}


void stop(){
	dc1Move(0);
	dc2Move(0);
	dc3Move(0);
	dc4Move(0);
}

//                   forward
//           frontLeft   |  frontRight          ↺: rotateLeft
//         left		  ---+----     right		↻: rotateRight
//           backLeft    |  backRight
//                  backwards
//

void forward(int speed){
	dc1Move(speed);
	dc2Move(speed);
	dc3Move(speed);
	dc4Move(speed);
}

void backwards(int speed){
	dc1Move(-speed);
	dc2Move(-speed);
	dc3Move(-speed);
	dc4Move(-speed);
}

void frontLeft(int speed){
	dc1Move(0); //stop
	dc2Move(speed);
	dc3Move(speed);
	dc4Move(0); //stop
}

void frontRight(int speed){
	dc1Move(speed);
	dc2Move(0); //stop
	dc3Move(0); //stop
	dc4Move(speed);
}
void backRight(int speed){
	dc1Move(0); //stop
	dc2Move(-speed);
	dc3Move(-speed);
	dc4Move(0); //stop
}

void backLeft(int speed){
	dc1Move(-speed);
	dc2Move(0); //stop
	dc3Move(0); //stop
	dc4Move(-speed);

}

void right(int speed){
	dc1Move(speed);
	dc2Move(-speed);
	dc3Move(-speed);
	dc4Move(speed);
}

void left(int speed){
	dc1Move(-speed);
	dc2Move(speed);
	dc3Move(speed);
	dc4Move(-speed);
}

void rotateLeft(int speed){
	dc1Move(-speed);
	dc2Move(-speed);
	dc3Move(speed);
	dc4Move(speed);
}

void rotateRight(int speed){
	dc1Move(speed);
	dc2Move(speed);
	dc3Move(-speed);
	dc4Move(-speed);
}

uint8_t count_test = 10;
void testDc(){
	count_test--;
	if(count_test >= 7)
		forward(MAX_SPEED);
	else if(count_test >= 5)
		backwards(MAX_SPEED);
	else if(count_test >= 3)
		right(MAX_SPEED);
	else if (count_test >=1)
		left(MAX_SPEED);
	else
		count_test = 10;

}

void runDir(int dir, int speed){
	switch (dir) {
		case ROBOT_DIR_FW:
			forward(speed);
			break;
		case ROBOT_DIR_SR:
			right(speed);
			break;
		case ROBOT_DIR_SL:
			left(speed);
			break;
		case ROBOT_DIR_L:
			rotateLeft(speed);
			break;
		case ROBOT_DIR_R:
			rotateRight(speed);
			break;
		case ROBOT_DIR_LB:
			backLeft(speed);
			break;
		case ROBOT_DIR_RB:
			backRight(speed);
			break;
		case ROBOT_DIR_LF:
			frontLeft(speed);
			break;
		case ROBOT_DIR_RF:
			frontRight(speed);
			break;
		case ROBOT_DIR_BW:
			backwards(speed);
			break;
		default:
			stop();
			break;
	}
}

void runSpeed(int left, int right){
	dc3Move(left);
	dc4Move(left);
	dc1Move(right);
	dc2Move(right);
}

void followLine(){
//	static int last_line_state = 0;
//	uint8_t line_state = SensorGetLine();
//	switch(line_state){
//	case LINE_CENTER:
//		if(last_line_state == LINE_CENTER){
//			forward(MAX_SPEED);
//		} else {
//			forward(MIN_SPEED);
//		}
//		break;
//	case LINE_LEFT1:
//		runSpeed(MIN_SPEED, MIN_SPEED*1.25);
//		break;
//	case LINE_LEFT2:
//		runSpeed(0, MIN_SPEED);
//		break;
//	case LINE_LEFT3:
//		runSpeed(-MIN_SPEED, MIN_SPEED);
//		break;
//	case LINE_RIGHT1:
//		runSpeed(MIN_SPEED*1.25, MIN_SPEED);
//		break;
//	case LINE_RIGHT2:
//		runSpeed(MIN_SPEED, 0);
//		break;
//	case LINE_RIGHT3:
//		runSpeed(MIN_SPEED, -MIN_SPEED);
//		break;
//	default:
//		stop();
//		break;
//	}
}

int followLineUntilCross(){
//	static int status = 0;
//	uint8_t line_state = SensorGetLine();
//	if(status == 0){
//		if(line_state != LINE_CROSS) status = 1;
//	} else if(status == 1){
//		if(line_state == LINE_CROSS) {
//			stop();
////			status = 0;
//			return 1;
//		}
//	}
//	followLine();
	return 0;
}
