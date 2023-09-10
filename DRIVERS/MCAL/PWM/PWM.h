/*
 * PWM.h
 *
 *  Created on: Sep 4, 2023
 *      Author: Dell
 */

#ifndef PWM_H_
#define PWM_H_


#include "STD_TYPES.h"
#include "Timers.h"
#include "avr/io.h"
#include "avr/interrupt.h"



/******************************************************************************
 *									ENUMS	                				  *
 *******************************************************************************/



typedef enum{
	PHASE_CORRECT_PWM =0x40 ,
	FAST_PWM =0x48
}PWM_mode_t;



typedef enum{
	INVERTING =0x30,
	NON_INVERTING =0x20
}OUTPUT_COMPARE_MODE_t;


/******************************************************************************
 *									STRUCT	                				  *
 *******************************************************************************/
typedef struct{
	PWM_mode_t mode;
	Timer_prescalar_t clk;
	OUTPUT_COMPARE_MODE_t compare_mode;
}PWM_Pinconfig_t;





/******************************************************************************
 *									APIS	                				  *
 *******************************************************************************/

STATUS_t PWM_Init(PWM_Pinconfig_t* confg);
//duty cycle as %
void PWM_Start(PWM_Pinconfig_t* confg ,uint8_t duty_cycle);


#endif /* PWM_H_ */
