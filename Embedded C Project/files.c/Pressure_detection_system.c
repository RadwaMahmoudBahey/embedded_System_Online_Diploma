/*
 ============================================================================
 Name        : Pressure_detection_system.c
 Author      : Radwa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdint.h>
#include <stdio.h>
#include "P_Sensor.h"
#include "Alarm_Monitor.h"
#include"pressure_detector.h"
#include "Alarm_Actuator.h"
#include "states.h"
void setup(){
	GPIO_INITIALIZATION();
	Sensor_init();
	Alarm_init();
	pressure_detector =state(waiting_state);
	monitor =state(monitor_waiting);
	alarm = state(alarm_waiting);
}
int main (){
	setup();
	while (1)
	{
		Sensor();
		pressure_detector();
		monitor();
		alarm();
		Delay(500000);
	}

}

