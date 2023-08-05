/* DC_motor.h by Radwa Mahmoud */
#ifndef DC_MOTOR_
#define DC_MOTOR_
#include "states.h"
enum{
	idle,
	DC_busy
}DC_state_id;
void DC_INIT();
extern void (*DC_state) ();
State_define(idle);
State_define(DC_busy);
#endif
