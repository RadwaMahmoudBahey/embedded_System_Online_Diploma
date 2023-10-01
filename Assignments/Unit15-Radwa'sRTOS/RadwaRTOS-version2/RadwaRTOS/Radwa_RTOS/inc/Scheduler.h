/*
 * Scheduler.h
 *
 *  Created on: Sep 23, 2023
 *      Author: Dell
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_


#include "CortexMX_porting.h"

#include "string.h"
#include "stdio.h"


typedef enum{
	no_error,
	Ready_Queue_Init_error ,
	Task_Exceeded_Stack_size
}RadwaRTOS_error;


typedef enum{
	Suspend,
	Running,
	Waiting,
	Ready
}Task_state;


typedef struct{
	uint32_t stack_size;
	uint32_t S_PSP_Task ;
	uint32_t E_PSP_Task ;
	uint32_t* Current_PSP ;
	uint8_t  Priority;
	void (* task_entry)();
	char Task_name[50];
	Task_state TaskState ;

	struct{
		enum{
			enable,
			disable
		}blocking;
		uint32_t waiting_ticks;
	}Waiting_Time;
}Taskref;



/*
 * =======================================================================================
 * 										APIs
 * =======================================================================================
 */

RadwaRTOS_error RadwaRTOS_Init(void);
RadwaRTOS_error RadwaRTOS_CREATE_TASK(Taskref* task);
void RadwaRTOS_ACTIVATE_TASK(Taskref* task);
void RadwaRTOS_TERMINATE_TASK(Taskref* task);
void RadwaRTOS_Activate_OS();
#endif /* INC_SCHEDULER_H_ */
