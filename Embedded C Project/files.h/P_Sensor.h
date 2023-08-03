/*
 * P_Sensor.h
 *
 *  Created on: Aug 1, 2023
 *      Author:  Radwa Mahmoud
 */

#ifndef P_SENSOR_H_
#define P_SENSOR_H_
#include "states.h"
enum{
	Sensor_waiting,
	reading_values
}Sensor_state;
//state_define(Sensor_waiting);
state_define(reading_values);
extern void (*Sensor)();
void Sensor_init();

#endif /* P_SENSOR_H_ */
