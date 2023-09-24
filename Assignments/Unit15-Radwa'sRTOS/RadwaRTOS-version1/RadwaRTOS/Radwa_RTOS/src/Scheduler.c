/*
 * Scheduler.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Dell
 */

#include "Scheduler.h"
#include "Circular_FIFO.h"

typedef enum{
	OS_Suspend,
	OS_Running
}OS_state;

//defined here so won't be seen by user
struct{
	Taskref * Task_table [100];
	uint32_t S_MSP_Task ;
	uint32_t E_MSP_Task ;
	uint32_t PSP_Locator;
	uint32_t ActiveTasks_Count ;
	Taskref* Current_task ;
	Taskref* Next_task ;
	OS_state OS_State ;
}OS_control;





FIFO_T ReadyQueue;
Taskref* Ready_table[100];
Taskref Idle_task;


void RadwaRTOS_CREATE_TASK_STACK(Taskref* task){
	//task frame
	/*xpsr
	 * PC
	 * LR
	 * r12
	 * r4
	 * r3
	 * r2
	 * r1
	 * r0
	 *  save from r5 >> r11 manually
	 */

	//initializing all:
	task->Current_PSP = task->S_PSP_Task ;
	//xpsr

	*(task->Current_PSP) = 0x01000000;
	task->Current_PSP-- ;

	//pc
	*(task->Current_PSP) = task->task_entry;
	task->Current_PSP-- ;

	//LR
	*(task->Current_PSP) = 0xFFFFFFFD;


	//rest of the 13 registers: all initialized to 0

	for (int i =0 ; i<13 ;i++){
		task->Current_PSP-- ;
		*(task->Current_PSP) = 0;
	}


}


RadwaRTOS_error RadwaRTOS_CREATE_TASK(Taskref* task){

	RadwaRTOS_error error = no_error;

	task->S_PSP_Task = OS_control.PSP_Locator;
	task->E_PSP_Task =task->S_PSP_Task - task->stack_size ;

	if ((task->E_PSP_Task) < &_eheap  ) {
		return Task_Exceeded_Stack_size;
	}
	OS_control.PSP_Locator = task->E_PSP_Task -8;

	//create task frame
	RadwaRTOS_CREATE_TASK_STACK(task);



	// task state >>> suspend:
	task->TaskState = Suspend;

	return error;
}




void RadwaRTOS_CREATE_MAIN_STACK(void){
	OS_control.S_MSP_Task = &_estack ;
	OS_control.E_MSP_Task  = OS_control.S_MSP_Task  - MainStack_Size ;
	OS_control.PSP_Locator = OS_control.E_MSP_Task -8;
}


void RadwaRTOS_IDLE_TASK(void){
	while(1){
		__asm("nop");
	}
}
RadwaRTOS_error RadwaRTOS_CREATE_IDLE_TASK(void){

	RadwaRTOS_error error = no_error;
	Idle_task.Priority = 255;
	strcpy(Idle_task.Task_name , "Idle_Task");
	Idle_task.task_entry = RadwaRTOS_IDLE_TASK;
	Idle_task.stack_size = 300;


	// create idle task
	error += RadwaRTOS_CREATE_TASK(&Idle_task);

	return error;
}


RadwaRTOS_error RadwaRTOS_Init(void){
	RadwaRTOS_error error = no_error;

	//1st : OS state >> suspend
	OS_control.OS_State = OS_Suspend ;

	//2nd : initialize the main stack
	RadwaRTOS_CREATE_MAIN_STACK();

	///3rd : Create Ready Queue
	if(FIFO_INIT(&ReadyQueue, Ready_table, 100) != FIFO_NoERROR){
		error += Ready_Queue_Init_error ;
	}

	//4th Create IDLE task
	error += RadwaRTOS_CREATE_IDLE_TASK();
	return error;
}






void OS_SVC(uint32_t *Stack_frame){
	uint8_t SVC_number = *((uint8_t *)(((uint8_t *)Stack_frame[6]) -2));
	switch(SVC_number){
	case SVC_Activatetask:
		break;
	case SVC_terminateTask:
		break;
	case SVC_TaskWaitingTime:
		break;
	}
}





int OS_SVC_SET(int choice){

	switch(choice){
	case SVC_Activatetask:
		__asm volatile("SVC #0x00");
		break;
	case SVC_terminateTask:
		__asm volatile("SVC #0x01");
		break;
	case SVC_TaskWaitingTime:
		__asm volatile("SVC #0x02");
		break;
	}


}
