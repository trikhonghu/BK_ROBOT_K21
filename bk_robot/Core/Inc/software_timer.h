/*
 * software_timer.h
 *
 *  Created on: Jun 14, 2024
 *      Author: Windows
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "tim.h"
#include <stdint.h>
#include "encoder.h"

#define TIMER_CYCLE_2	1

extern uint16_t flag_timer2;

void timer_init();
void set_timer2(uint16_t duration);

#endif /* INC_SOFTWARE_TIMER_H_ */
