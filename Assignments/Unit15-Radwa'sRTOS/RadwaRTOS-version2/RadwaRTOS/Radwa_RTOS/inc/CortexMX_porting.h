/*
 * CortexMX_porting.h
 *
 *  Created on: Sep 23, 2023
 *      Author: Dell
 */

#ifndef INC_CORTEXMX_PORTING_H_
#define INC_CORTEXMX_PORTING_H_

#include "core_cm3.h"

extern int _estack;
extern int _eheap;



/*
 * =======================================================================================
 * 										MACROS
 * =======================================================================================
 */


#define MainStack_Size										3072


#define Switch_CPU_Access_TO_PRIVILIGED			__asm volatile("mrs r0 , CONTROL \n\t" \
		"lsr r0,r0 , #1 \n\t" \
		"lsl r0,r0 , #1  \n\t" \
		"msr CONTROL , r0")



#define Switch_CPU_Access_TO_UNPRIVILIGED		__asm volatile("mrs r0 , CONTROL \n\t" \
		"orr r0,r0 , #0x01 \n\t" \
		"msr CONTROL , r0")


#define Switch_OS_TO_PSP		__asm volatile("mrs r0 , CONTROL \n\t" \
		"orr r0,r0 , #0x02 \n\t" \
		"msr CONTROL , r0")

#define Switch_OS_TO_MSP	__asm volatile("mrs r0 , CONTROL \n\t" \
		"and r0,r0 , #0x05 \n\t" \
		"msr CONTROL , r0")

#define SET_PSP(task_psp)	__asm volatile(" mov r0 ,%[in1] \n\t msr PSP , r0 " \
		: \
		  :[in1] "r" (task_psp))



#define GET_PSP(task_psp)	__asm volatile(" mrs r0 ,PSP \n\t  mov %[out] ,  r0  " \
		  :[out] "=r" (task_psp))



/*
 * =======================================================================================
 * 										APIs
 * =======================================================================================
 */




void HW_init();
void trigger_OS_PendSV();
void Start_Ticker();


#endif /* INC_CORTEXMX_PORTING_H_ */
