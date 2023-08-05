/* US_sensor.c by Radwa Mahmoud */
#include <stdio.h>
#include <stdlib.h>
#include "US_sensor.h"
int random(int l , int r , int count);
int US_distance ;
void (*US_state) ();
void US_INIT(){
	printf("US INIT \n");
}
State_define(US_busy){
	US_state_id = US_busy;
	US_distance = random(45,55,1);
	printf(" US_busy state: distance = %d \n" , US_distance);

	US_SEND_DISTANCE(US_distance );
	US_state = State(US_busy);
}

int random(int l , int r , int count){
	int i;
	for (i=0 ; i< count ; i++){
		int random = ( rand() % (r - l +1 )) + l;
		return random;
	}
}
