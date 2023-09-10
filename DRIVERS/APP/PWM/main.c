/*
 * main.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Dell
 */


#include "Timers.h"
#include "PWM.h"
#include "avr/io.h"



void main(){

	DDRB |=1<<3;

	PWM_Pinconfig_t confg = {FAST_PWM , Prescalar_8 ,NON_INVERTING };
	PWM_Init(&confg);

	while(1){
		//duty cycle as %
		PWM_Start(&confg , 80);
	}
}
