/*
 * WDT.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Dell
 */

#include "WDT.h"


void WDT_Start(void){

	//set WDT to 1 sec:
	WDTCR |= 1<<WDP1 | 1<<WDP2 ;
	WDTCR &= ~(1<<WDP0);

	//enable watchdog timer
	WDTCR |= 1<<WDE ;
}

void WDT_Stop(void){

	//write 1 to both WDE and WDTOE
	WDTCR |= 1<<WDTOE | 1<<WDE ;
	WDTCR  =0x00;
}
