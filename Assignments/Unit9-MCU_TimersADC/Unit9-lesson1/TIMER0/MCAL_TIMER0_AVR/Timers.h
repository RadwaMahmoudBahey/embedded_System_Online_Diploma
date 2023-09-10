/*
 * Timers.h
 *
 *  Created on: Sep 3, 2023
 *      Author: Dell
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include <avr/interrupt.h>


/******************************************************************************
*									ENUMS	                				  *
*******************************************************************************/



typedef enum{
	Normal_mode,
	CTC_mode = 0x08
}Timer_mode_t;

typedef enum{
	No_clk,
	No_prescaler,
	Prescalar_8,
	Prescalar_64,
	Prescalar_256,
	Prescalar_1024,
	EXT_CLK_FALLING,
	EXT_CLK_RISING,

}Timer_prescalar_t;


typedef enum{
	OCIE_DISABLE,
	OCIE_ENABLE = 0x02
}OCMIE0_t;

typedef enum{
	TOIE_DISABLE,
	TOIE_ENABLE = 0x01
}TOVFIE0_t;



/******************************************************************************
*									STRUCT	                				  *
*******************************************************************************/

typedef struct{
	Timer_mode_t mode;
	Timer_prescalar_t clock;
	OCMIE0_t ocmInterrupt;
	TOVFIE0_t ovfInterrupt;
}Timer0_config_t;

/******************************************************************************
*									APIS	                				  *
*******************************************************************************/

STATUS_t	Timer0_Init(Timer0_config_t* confg);
void	Timer0_Stop();


STATUS_t TIMER0_GetCompareValue(ptr_uint8_t pu8_TicksNumber);
STATUS_t TIMER0_SetCompareValue(uint8_t u8_TicksNumber);

STATUS_t TIMER0_GetCounterValue(ptr_uint8_t pu8_TicksNumber);
STATUS_t TIMER0_SetCounterValue(uint8_t u8_TicksNumber);

STATUS_t TIMER0_GetOverflowValue(ptr_uint8_t pu8_TicksNumber);
STATUS_t TIMER0_SetOverflowValue(uint8_t u8_TicksNumber);

void TIMER0_CALLBACK_Overflow_INTERRUPT(ptr_func callback);
void TIMER0_CALLBACK_CompareMatch_INTERRUPT(ptr_func callback);







#endif /* TIMERS_H_ */
