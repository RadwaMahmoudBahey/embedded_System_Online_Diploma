/*
 * Alarm_Monitor.c
 *
 *  Created on: Aug 1, 2023
 *      Author:  Radwa Mahmoud
 */
#include "Alarm_Monitor.h"
 void (*monitor)();
void high_pressure_detected(){
	//printf("\n==========Monitor Alert Received===========\n");
	start_alarm();
	monitor =state(Alarm_Activated);
}
state_define(monitor_waiting){
	monitor_state = monitor_waiting;
	//printf("\n==========Alarm Monitor in waiting state state===========\n");
}

state_define(Alarm_Activated){
	monitor_state = Alarm_Activated;
	//printf("\n==========Alarm Monitor in Alarm Activated state===========\n");
	Delay(600000);
	stop_alarm();
	monitor =state(monitor_waiting);
}
