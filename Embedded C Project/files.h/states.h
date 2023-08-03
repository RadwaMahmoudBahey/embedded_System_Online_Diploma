/*
 * states.h
 *
 *  Created on: Jul 28, 2023
 *      Author: Radwa Mahmoud
 */

#ifndef STATES_H_
#define STATES_H_
#include "driver.h"
#define state_define(x) void st_##x()
#define state(x) st_##x

void set_pressure_val(int pressure);
void high_pressure_detected();
void start_alarm();
void stop_alarm();
#endif /* STATES_H_ */
