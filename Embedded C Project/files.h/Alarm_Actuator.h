/*
 * Alarm_Actuator.h
 *
 *  Created on: Aug 1, 2023
 *      Author:  Radwa Mahmoud
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "states.h"
enum{
	alarm_waiting,
	Alarm_ON,
	Alarm_OFF
}alarm_state;
state_define(alarm_waiting);
state_define(Alarm_ON);
state_define(Alarm_OFF);
extern void (*alarm)();
void Alarm_init();
#endif /* ALARM_ACTUATOR_H_ */
