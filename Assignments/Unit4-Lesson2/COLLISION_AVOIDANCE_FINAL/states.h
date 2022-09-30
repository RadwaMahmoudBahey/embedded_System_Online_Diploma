/* states.h by Radwa Mahmoud */
#ifndef STATES_H_
#define STATES_H_
#define State_define(state_name) void St_##state_name()
#define State(state_name) St_##state_name
//connections
void DC_GET_SPEED(int speed);
void US_SEND_DISTANCE(int distance);
#endif
