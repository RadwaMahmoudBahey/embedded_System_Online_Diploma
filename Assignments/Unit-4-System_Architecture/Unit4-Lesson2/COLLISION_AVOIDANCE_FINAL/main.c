/*
 ============================================================================
 Name        : CA.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "CA.h"
#include "DC_motor.h"
#include "US_sensor.h"
void setup(){
	US_INIT();
	DC_INIT();
	US_state = State(US_busy);
	state = State(waiting);
	DC_state =State(idle);
}
int main(void) {
	volatile int i ;
	setup();
	while(1){
	US_state();
	state();
	DC_state();
	for (i=0 ; i<1500 ; i++);
}
	return 0;
}
