/*
 ============================================================================
 Name        : LIFO.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"
unsigned int LIFO_arr1[5];
int main(void) {
	unsigned int* LIFO_arr2 = (unsigned int*)malloc(5*sizeof(unsigned int));
	LIFO_T uart_lifo , i2c_lifo;
	LIFO_INIT(&uart_lifo , LIFO_arr1 , 5);
	unsigned int i , temp =0;
	for(i =0 ; i<7 ; i++){
		if(LIFO_PUSH(&uart_lifo , i) == LIFO_NoERROR)
			printf("Uart-lifo pushed: %u \n" ,i);
	}
	for(i =0 ; i<7 ; i++){
		if( LIFO_POP(&uart_lifo , &temp) == LIFO_NoERROR)
			printf("uart-poped: %u\n" , temp);
	}
	return 0;
}
