/*
 * timers.c
 *
 *  Created on: Sep 3, 2023
 *      Author: Dell
 */

#include "Timers.h"
#include "avr/io.h"




uint8_t u8_TOVNumber;
ptr_func CALLBACK_OV;
ptr_func CALLBACK_CM;
/******************************************************************************
 *									APIS	                				  *
 *******************************************************************************/

STATUS_t	Timer0_Init(Timer0_config_t* confg){
	STATUS_t ReturnVal = NOK;
	if(NULL_PTR == confg ){
		ReturnVal = NOK;
	}
	else{

		if ((Normal_mode == confg->mode) || (CTC_mode  == confg->mode)){
			TCCR0 |= confg->mode;
			ReturnVal = OK;
		}
		else{
			ReturnVal = NOK;
		}
		if ((No_clk <= confg->clock) && EXT_CLK_RISING  >= confg->clock){
			TCCR0 |= confg->clock;
			ReturnVal = OK;
		}
		else{
			ReturnVal = NOK;
		}
		if(( OCIE_DISABLE == confg->ocmInterrupt) || ( OCIE_ENABLE == confg->ocmInterrupt)){
			TIMSK |= confg->ocmInterrupt;
			ReturnVal = OK;
		}
		else{
			ReturnVal = NOK;
		}
		if(( TOIE_DISABLE == confg->ovfInterrupt) || ( TOIE_ENABLE == confg->ovfInterrupt)){
			TIMSK |= confg->ovfInterrupt;
			ReturnVal = OK;
		}
		else{
			ReturnVal = NOK;
		}
	}
	return ReturnVal;
}





void	Timer0_Stop(){

	TCCR0 = No_clk;
}


STATUS_t TIMER0_GetCompareValue(ptr_uint8_t pu8_TicksNumber){
	*pu8_TicksNumber = OCR0 ;
	return OK;
}


STATUS_t TIMER0_SetCompareValue(uint8_t u8_TicksNumber){
	OCR0 = u8_TicksNumber;
	return OK;
}

STATUS_t TIMER0_GetCounterValue(ptr_uint8_t pu8_TicksNumber){
	*pu8_TicksNumber = TCNT0 ;
	return OK;
}
STATUS_t TIMER0_SetCounterValue(uint8_t u8_TicksNumber){
	TCNT0 = u8_TicksNumber;
	return OK;
}

STATUS_t TIMER0_GetOverflowValue(ptr_uint8_t pu8_TicksNumber){
	*pu8_TicksNumber = u8_TOVNumber ;
	return OK;
}
STATUS_t TIMER0_SetOverflowValue(uint8_t u8_TicksNumber){
	u8_TOVNumber = u8_TicksNumber;
	return OK;
}

void TIMER0_CALLBACK_Overflow_INTERRUPT(ptr_func callback){
	CALLBACK_OV = callback;
}
void TIMER0_CALLBACK_CompareMatch_INTERRUPT(ptr_func callback){
	CALLBACK_CM = callback;
}

ISR(TIMER0_OVF_vect){
	u8_TOVNumber++;
	CALLBACK_OV();
}

ISR(TIMER0_COMP_vect){
	CALLBACK_CM();
}
