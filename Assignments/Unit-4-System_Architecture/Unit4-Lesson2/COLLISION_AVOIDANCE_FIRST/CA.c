/* CA.c by Radwa Mahmoud */
#include <stdio.h>
#include <stdlib.h>
#include "CA.h"
int random(int l , int r , int count);
int speed , distance , threshold =50;
void (*state) ();
State_define(waiting){
	state_id = waiting;
	speed =0;
	distance = random(45,55,1);
	(distance <= threshold )? (state = State(waiting)) : (state = State(driving)) ;
	printf(" waiting state: distance = %d , speed = %d \n" , distance , speed);
}
State_define(driving){
	state_id = driving;
	speed =30;
	distance = random(45,55,1);
	(distance <= threshold )? (state = State(waiting)) : (state = State(driving)) ;
	printf(" driving state: distance = %d , speed = %d \n" , distance , speed);
}
int random(int l , int r , int count){
	int i;
	for (i=0 ; i< count ; i++){
		int random = ( rand() % (r - l +1 )) + l;
		return random;
	}
}
