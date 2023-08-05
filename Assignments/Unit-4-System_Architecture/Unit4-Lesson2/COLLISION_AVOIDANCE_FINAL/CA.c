/* CA.c by Radwa Mahmoud */
#include <stdio.h>
#include <stdlib.h>
#include "CA.h"
int speed , CA_distance , threshold =50;
void (*state) ();

void US_SEND_DISTANCE(int distance){
	CA_distance = distance;
	printf(" US_sensor -> -> ->  CA : distance = %d \n" , CA_distance);
	(CA_distance <= threshold )? (state = State(waiting)) : (state = State(driving)) ;
}
State_define(waiting){
	state_id = waiting;
	speed =0;
	printf(" waiting state: distance = %d , speed = %d \n" , CA_distance , speed);
	DC_GET_SPEED(speed);
}
State_define(driving){
	state_id = driving;
	speed =30;
	printf(" driving state: distance = %d , speed = %d \n" , CA_distance , speed);
	DC_GET_SPEED(speed);
}
