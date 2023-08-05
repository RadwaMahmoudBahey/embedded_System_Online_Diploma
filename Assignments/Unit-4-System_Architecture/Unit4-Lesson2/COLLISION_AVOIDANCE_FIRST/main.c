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
void setup(){
	state = State(waiting);
}
int main(void) {
	volatile int i;
	setup();
while(1){
	state();
	for (i=0 ; i<1500 ; i++);
}
	return 0;
}
