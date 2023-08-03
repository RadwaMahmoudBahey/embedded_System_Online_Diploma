/*
 * Alarm_Monitor.h
 *
 *  Created on: Aug 1, 2023
 *      Author:  Radwa Mahmoud
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "states.h"
enum{
	monitor_waiting,
	Alarm_Activated
}monitor_state;
state_define(monitor_waiting);
state_define(Alarm_Activated);
extern void (*monitor)();

#endif /* ALARM_MONITOR_H_ */
