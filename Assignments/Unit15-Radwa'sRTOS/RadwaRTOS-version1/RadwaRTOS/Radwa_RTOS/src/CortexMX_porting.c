/*
 * CortexMX_porting.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Dell
 */


#include "CortexMX_porting.h"



void HW_init()
{
	//Initialize Clock Tree (RCC -> SysTick Timer & CPU) 8MHZ
	//init HW
	//Clock tree
	//RCC Default Values makes CPU Clock & SySTick Timer clock = 8 M HZ

	//	8 MHZ
	//	1 count -> 0.125 us
	//	X count -> 1 ms
	//	X = 8000 Count

}


__attribute ((naked))void SVC_Handler (void)
{
	__asm volatile("tst lr ,#0x4 \n\t"
			"ITE EQ \n\t"
			"mrseq r0, MSP \n\t"
			"mrsne r0 , PSP \n\t"
			"B OS_SVC");
}






  void BusFault_Handler(){
  	while(1);
  }


void MemManage_Handler(){
	while(1);
}


void UsageFault_Handler(){
	while(1);
}


void HardFault_Handler(){
	while(1);
}
