/*
 * main.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Dell
 */
#define F_CPU 8000000UL

#include "Timers.h"
#include "PWM.h"
#include "WDT.h"
#include "avr/io.h"
#include "util/delay.h"

#define TOGGLE_BIT(PORT, BIT)			PORT ^= (1<<BIT)


void main(){

	DDRA |= 1<<0;
	_delay_ms(1000);
	TOGGLE_BIT(PORTA ,0);
	WDT_Start();
	_delay_ms(2000);
	WDT_Stop();
	while(1){
	}
}
