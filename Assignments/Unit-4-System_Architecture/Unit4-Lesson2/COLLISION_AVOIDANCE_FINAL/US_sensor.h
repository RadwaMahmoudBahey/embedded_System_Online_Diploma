/* US_sensor.h by Radwa Mahmoud */
#ifndef US_SENSOR_
#define US_SENSOR_
#include "states.h"
enum{
	US_busy
}US_state_id;
void US_INIT();
extern void (*US_state) ();
State_define(US_busy);
#endif
