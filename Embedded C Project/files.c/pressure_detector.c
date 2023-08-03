/*
 * pressure_detector.c
 *
 *  Created on: Aug 1, 2023
 *      Author: Radwa Mahmoud
 */

#include"pressure_detector.h"
void (*pressure_detector)();
int threshold =20 , recieved_pressure=0;
void set_pressure_val(int pressure){
	recieved_pressure =pressure;
	//printf("\nSensor============RECEIVED pressure value=%d=============Pressure detector\n" ,recieved_pressure);
	if(recieved_pressure > threshold){
		high_pressure_detected();
		pressure_detector =state(waiting_state);
	}
	else{
		//printf("\n==========Monitor Alert Sent===========\n");

		pressure_detector =state(waiting_state);
	}
}

state_define(waiting_state){
	pressure_detector_state = waiting_state;
	//printf("\n==========Pressure detector in waiting state===========\n");

}

