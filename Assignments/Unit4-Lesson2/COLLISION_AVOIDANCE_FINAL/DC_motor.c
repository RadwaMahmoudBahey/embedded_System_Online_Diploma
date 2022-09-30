/* DC_motor.c by Radwa Mahmoud */
#include <stdio.h>
#include <stdlib.h>
#include "DC_motor.h"
int DC_speed ;
void (*DC_state) ();
void DC_INIT(){
	printf("DC INIT \n");
}
void DC_GET_SPEED(int speed){
	DC_speed = speed;
	DC_state =State(DC_busy);
	printf("CA -> -> ->  DC_motor : speed = %d \n" , DC_speed );
}

State_define(idle){
	DC_state_id = idle;
	printf(" idle state: speed = %d \n" , DC_speed);
}
State_define(DC_busy){
	DC_state_id = DC_busy;
	printf(" DC_busy state: speed = %d \n" , DC_speed);
	DC_state =State(idle);
}
