/*
 * pressure_detector.h
 *
 *  Created on: Aug 1, 2023
 *      Author: Dell
 */

#ifndef PRESSURE_DETECTOR_H_
#define PRESSURE_DETECTOR_H_
#include "states.h"
enum{
	waiting_state
}pressure_detector_state;
state_define(waiting_state);
extern void (*pressure_detector)();


#endif /* PRESSURE_DETECTOR_H_ */
