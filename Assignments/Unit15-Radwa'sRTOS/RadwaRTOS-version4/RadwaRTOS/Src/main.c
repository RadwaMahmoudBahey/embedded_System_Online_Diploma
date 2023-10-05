///**
// ******************************************************************************
// * @file           : main.c
// * @author         : Auto-generated by STM32CubeIDE
// * @brief          : Main program body
// ******************************************************************************
// * @attention
// *
// * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
// * All rights reserved.</center></h2>
// *
// * This software component is licensed by ST under BSD 3-Clause license,
// * the "License"; You may not use this file except in compliance with the
// * License. You may obtain a copy of the License at:
// *                        opensource.org/licenses/BSD-3-Clause
// *
// ******************************************************************************
// */



#include "Scheduler.h"

uint8_t TaskA_LED , TaskB_LED ,TaskC_LED ,TaskD_LED;

Mutexref mutex1 ,mutex2;
Taskref TaskA , TaskB , TaskD ,TaskC;
void Task_A(void){
	static uint8_t count=0;
	while(1){
		TaskA_LED ^= 1;
		count++;
		if(count == 100){
			RadwaRTOS_ACQUIRE_MUTEX(&mutex1, &TaskA);
			RadwaRTOS_ACTIVATE_TASK(&TaskB);
		}
		if(count == 200){
			count =0;
			RadwaRTOS_RELEASE_MUTEX(&mutex1);
		}
	}
}

void Task_B(void){
	static uint8_t count=0;
	while(1){
		TaskB_LED ^= 1;
		count++;
		if(count == 100){
			RadwaRTOS_ACTIVATE_TASK(&TaskC);
		}
		if(count == 200){
			count =0;
			RadwaRTOS_TERMINATE_TASK(&TaskB);
		}
	}
}



void Task_C(void){
	static uint8_t count=0;
	while(1){
		TaskC_LED ^= 1;
		count++;
		if(count == 100){
			RadwaRTOS_ACTIVATE_TASK(&TaskD);
		}
		if(count == 200){
			count =0;
			RadwaRTOS_TERMINATE_TASK(&TaskC);
		}
	}
}

void Task_D(void){

	static uint32_t count=0;
	while(1){
		TaskD_LED ^= 1;
		count++;
		if(count == 3){
			RadwaRTOS_ACQUIRE_MUTEX(&mutex1, &TaskD);
		}
		if(count == 200){
			count =0;
			RadwaRTOS_RELEASE_MUTEX(&mutex1);
			RadwaRTOS_TERMINATE_TASK(&TaskD);

		}
	}
}
uint8_t payload[3] = {1,2,3} ;
uint8_t payload2[3] = {1,2,3} ;

int main(void)
{
	RadwaRTOS_error error;
	HW_init();
	if (RadwaRTOS_Init() != no_error){
		while(1);
	}

	//mutex 1
	mutex1.Payload_size = 3;
	mutex1.Payload =payload ;
	strcpy(mutex1.Mutex_name , "mutex1");

	//mutex 2
	mutex2.Payload_size = 3;
	mutex2.Payload =payload2 ;
	strcpy(mutex2.Mutex_name , "mutex2");


	TaskA.stack_size = 1024;
	TaskA.Priority = 4;
	TaskA.task_entry = Task_A;
	strcpy(TaskA.Task_name , "Task_A");

	TaskB.stack_size = 1024;
	TaskB.Priority = 3;
	TaskB.task_entry = Task_B;
	strcpy(TaskB.Task_name , "Task_B");

	TaskC.stack_size = 1024;
	TaskC.Priority = 2;
	TaskC.task_entry = Task_C;
	strcpy(TaskC.Task_name , "Task_C");

	TaskD.stack_size = 1024;
	TaskD.Priority = 1;
	TaskD.task_entry = Task_D;
	strcpy(TaskD.Task_name , "Task_D");

	error += RadwaRTOS_CREATE_TASK(&TaskA);
	error += RadwaRTOS_CREATE_TASK(&TaskB);
	error += RadwaRTOS_CREATE_TASK(&TaskC);
	error += RadwaRTOS_CREATE_TASK(&TaskD);

	RadwaRTOS_ACTIVATE_TASK(&TaskA);


	RadwaRTOS_Activate_OS();
	while(1){

	}
	return 0;
}




