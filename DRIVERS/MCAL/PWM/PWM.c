/*
 * PWM.c
 *
 *  Created on: Sep 4, 2023
 *      Author: Dell
 */

#include "PWM.h"


/******************************************************************************
 *									APIS	                				  *
 *******************************************************************************/

STATUS_t PWM_Init(PWM_Pinconfig_t* confg){

	STATUS_t ReturnVal = NOK;
	if(NULL_PTR == confg ){
		ReturnVal = NOK;
	}
	else{

		if ((PHASE_CORRECT_PWM == confg->mode) || (FAST_PWM  == confg->mode)){

			TCCR0 |= confg->mode;
			ReturnVal = OK;
		}
		else{
			ReturnVal = NOK;
		}
		if ((No_clk <= confg->clk) && EXT_CLK_RISING  >= confg->clk){
			TCCR0 |= confg->clk;
			ReturnVal = OK;
		}
		else{
			ReturnVal = NOK;
		}
		if( (INVERTING == confg->compare_mode ) ||(NON_INVERTING == confg->compare_mode ) ){

			TCCR0 |= confg->compare_mode;
			ReturnVal = OK;
		}
		else{
			ReturnVal = NOK;
		}
	}
	return ReturnVal;
}


void PWM_Start(PWM_Pinconfig_t* confg ,uint8_t duty_cycle){
	//duty cycle as %

	if( (INVERTING == confg->compare_mode )){
		OCR0 = 255 - (255*duty_cycle/100);
	}
	else if(NON_INVERTING == confg->compare_mode){
		OCR0 =(255*duty_cycle/100);
	}
}
