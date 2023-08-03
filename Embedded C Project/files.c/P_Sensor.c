/*
 * P_Sensor.c
 *
 *  Created on: Aug 1, 2023
 *      Author: Radwa Mahmoud
 */
#include "P_Sensor.h"

int pressure =0;
 void (*Sensor)();
void Sensor_init(){
	//printf("\n==========Sensor INITIALIZED===========\n");
	Sensor = state(reading_values);

}
state_define(reading_values){
	Sensor_state =reading_values;
	//printf("\n==========Sensor in reading values state===========\n");
	pressure = getPressureVal();
	//printf("\nSensor============SENDING pressure value=%d=============Pressure detector\n" ,pressure);
	set_pressure_val(pressure);
	Delay(1000000);
	Sensor = state(reading_values);
}


