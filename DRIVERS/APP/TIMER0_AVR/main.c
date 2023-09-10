/*
 * main.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Dell
 */


#include "Timers.h"
#include "avr/io.h"


void CM_callback(){
	PORTA = ~PORTA;
}
void main(){
	DDRA = 0xFF;
	sei();

	TIMER0_CALLBACK_CompareMatch_INTERRUPT(CM_callback);
	TIMER0_SetCompareValue(0xF0);
	Timer0_config_t confg = {CTC_mode , Prescalar_8 , OCIE_ENABLE , TOIE_DISABLE};
	Timer0_Init(&confg);

	while(1){

	}
}
