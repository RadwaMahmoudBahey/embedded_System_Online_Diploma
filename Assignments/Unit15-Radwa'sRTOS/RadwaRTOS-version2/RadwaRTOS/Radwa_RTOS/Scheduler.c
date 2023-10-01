/*
 * Scheduler.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Dell
 */

#include "Scheduler.h"
#include "Circular_FIFO.h"



uint8_t Idle_LED , Systick_LED ;




typedef enum{
	OS_Suspend,
	OS_Running
}OS_state;

typedef enum{
	SVC_ActivateTask,
	SVC_TerminateTask ,
	SVC_TaskWaitingTime
}SVC_ID;




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



void bubble_sort();

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


	//update the tasks table , active tasks:
	OS_control.Task_table[OS_control.ActiveTasks_Count] = task;
	OS_control.ActiveTasks_Count++;

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
		Idle_LED ^= 1;
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

int OS_SVC_SET(int SVC_ID){

	switch(SVC_ID){
	case SVC_ActivateTask:
		__asm volatile("SVC #0x00");
		break;
	case SVC_TerminateTask:
		__asm volatile("SVC #0x01");
		break;
	case SVC_TaskWaitingTime:
		__asm volatile("SVC #0x02");
		break;
	}


}

void RadwaRTOS_UpdateTask_table(){

	Taskref *temp , *current , *next;
	int i=0;
	//sort the tasks table
	bubble_sort();


	// free the ready queue
	while(FIFO_dequeue(&ReadyQueue, &temp) != FIFO_EMPTY);


	//update the ready queue
	while(i< OS_control.ActiveTasks_Count){
		current = OS_control.Task_table[i];
		next = OS_control.Task_table[i+1];
		if(current->TaskState != Suspend){
			if(next->TaskState == Suspend){
				FIFO_enqueue(&ReadyQueue, current);
				current->TaskState = Ready;
				break;
			}
			if(next->Priority > current->Priority  ){
				FIFO_enqueue(&ReadyQueue, current);
				current->TaskState = Ready;
				break;
			}
			else if(next->Priority == current->Priority  ){
				FIFO_enqueue(&ReadyQueue, current);
				current->TaskState = Ready;
			}
			else if(next->Priority < current->Priority ){
				//error in sorting
				break;
			}
		}

		i++;
	}

}


void RadwaRTOS_ACTIVATE_TASK(Taskref* task){

	task->TaskState = Waiting;
	OS_SVC_SET(SVC_ActivateTask);
}


void RadwaRTOS_TERMINATE_TASK(Taskref* task){

	task->TaskState = Suspend;
	OS_SVC_SET(SVC_TerminateTask);
}
void Dispatch_Next_Task(){
	if((ReadyQueue.count ==0) &( OS_control.Current_task->TaskState != Suspend) ){
		OS_control.Current_task->TaskState = Running;
		FIFO_enqueue(&ReadyQueue, OS_control.Current_task);
		OS_control.Next_task = OS_control.Current_task ;
	}
	else{
		FIFO_dequeue(&ReadyQueue, &OS_control.Next_task);
		OS_control.Next_task->TaskState = Running;
		if((OS_control.Current_task->TaskState != Suspend ) && (OS_control.Current_task->Priority == OS_control.Next_task->Priority)){
			FIFO_enqueue(&ReadyQueue, OS_control.Current_task);
			OS_control.Current_task->TaskState = Ready;
		}
	}
}

void OS_SVC(uint32_t *Stack_frame){
	uint8_t SVC_number = *((uint8_t *)(((uint8_t *)Stack_frame[6]) -2));
	switch(SVC_number){
	case SVC_ActivateTask:
	case SVC_TerminateTask:
		RadwaRTOS_UpdateTask_table();
		if(OS_control.OS_State != OS_Suspend){
			if (strcmp(OS_control.Current_task->Task_name,"Idle_Task") != 0){
				Dispatch_Next_Task();
				// context switching :: pendsv
				trigger_OS_PendSV();
			}
		}
		break;
	case SVC_TaskWaitingTime:
		break;
	}
}



void bubble_sort(){
	Taskref *temp = NULL;
	uint8_t count = (uint8_t)OS_control.ActiveTasks_Count ;
	for(uint8_t i=0 ; i< (count -1);i++){
		for(uint8_t j=0 ; j< (count -i -1);j++){
			if(OS_control.Task_table[j]->Priority > OS_control.Task_table[j+1]->Priority){
				temp =OS_control.Task_table[j];
				OS_control.Task_table[j] = OS_control.Task_table[j+1];
				OS_control.Task_table[j+1] = temp;
			}
		}
	}
}


__attribute ((naked)) void PendSV_Handler()
{
	if(OS_control.Current_task != OS_control.Next_task){
		// xpsr , r1 , r0-r3 , pc , lr saved automatically
		//save r4 -r11 manually
		GET_PSP(OS_control.Current_task->Current_PSP);



		OS_control.Current_task->Current_PSP-- ;
		__asm volatile("mov %0 , r4" : "=r" (*(OS_control.Current_task->Current_PSP)));

		OS_control.Current_task->Current_PSP-- ;
		__asm volatile("mov %0 , r5" : "=r" (*(OS_control.Current_task->Current_PSP)));

		OS_control.Current_task->Current_PSP-- ;
		__asm volatile("mov %0 , r6" : "=r" (*(OS_control.Current_task->Current_PSP)));

		OS_control.Current_task->Current_PSP-- ;
		__asm volatile("mov %0 , r7" : "=r" (*(OS_control.Current_task->Current_PSP)));

		OS_control.Current_task->Current_PSP-- ;
		__asm volatile("mov %0 , r8" : "=r" (*(OS_control.Current_task->Current_PSP)));

		OS_control.Current_task->Current_PSP-- ;
		__asm volatile("mov %0 , r9" : "=r" (*(OS_control.Current_task->Current_PSP)));

		OS_control.Current_task->Current_PSP-- ;
		__asm volatile("mov %0 , r10" : "=r" (*(OS_control.Current_task->Current_PSP)));

		OS_control.Current_task->Current_PSP-- ;
		__asm volatile("mov %0 , r11" : "=r" (*(OS_control.Current_task->Current_PSP)));




		//check if next task != null

		if(OS_control.Next_task != NULL){
			OS_control.Current_task = OS_control.Next_task;
			OS_control.Next_task = NULL;
		}


		// xpsr , r1 , r0-r3 , pc , lr restored automatically
		//restore r4 -r11 manually


		__asm volatile("mov r11, %0" : : "r" (*(OS_control.Current_task->Current_PSP)));
		OS_control.Current_task->Current_PSP++ ;


		__asm volatile("mov r10, %0" : : "r" (*(OS_control.Current_task->Current_PSP)));
		OS_control.Current_task->Current_PSP++ ;


		__asm volatile("mov r9, %0" : : "r" (*(OS_control.Current_task->Current_PSP)));
		OS_control.Current_task->Current_PSP++ ;


		__asm volatile("mov r8, %0" : : "r" (*(OS_control.Current_task->Current_PSP)));
		OS_control.Current_task->Current_PSP++ ;


		__asm volatile("mov r7, %0" : : "r" (*(OS_control.Current_task->Current_PSP)));
		OS_control.Current_task->Current_PSP++ ;


		__asm volatile("mov r6, %0" : : "r" (*(OS_control.Current_task->Current_PSP)));
		OS_control.Current_task->Current_PSP++ ;


		__asm volatile("mov r5, %0" : : "r" (*(OS_control.Current_task->Current_PSP)));
		OS_control.Current_task->Current_PSP++ ;


		__asm volatile("mov r4, %0" : : "r" (*(OS_control.Current_task->Current_PSP)));
		OS_control.Current_task->Current_PSP++ ;



		//update the psp to the new task

		SET_PSP(OS_control.Current_task->Current_PSP);
		//exit:

		__asm volatile("BX LR");
	}
}


void RadwaRTOS_Activate_OS(){
	OS_control.OS_State = OS_Running;
	OS_control.Current_task = &Idle_task ;
	RadwaRTOS_ACTIVATE_TASK(&Idle_task);
	Start_Ticker();
	SET_PSP(OS_control.Current_task->Current_PSP);
	Switch_OS_TO_PSP;
	Switch_CPU_Access_TO_UNPRIVILIGED;

	//activate idle task:
	OS_control.Current_task->task_entry();
}


void SysTick_Handler(){

	Systick_LED ^= 1;

	Dispatch_Next_Task();
	trigger_OS_PendSV();
}


