/* CA.h by Radwa Mahmoud */
#ifndef CA_H_
#define CA_H_
#include "states.h"
enum{
	waiting,
	driving
}state_id;
extern void (*state) ();
State_define(waiting);
State_define(driving);
#endif
