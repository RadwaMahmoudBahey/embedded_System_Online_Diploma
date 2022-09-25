/*
 ============================================================================
 Name        : FIFO.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "fifo.h"

int main(void) {
	FIFO_T UART;
	elementType i , temp;
	if(FIFO_INIT(&UART , buffer , width) == FIFO_NoERROR)
		printf("\n ==== initialization done ==== \n");
	for(i=0 ;i<7 ;i++){
		printf("fifo enqueue(%x) " , i);
		if(FIFO_enqueue(&UART , i) == FIFO_NoERROR)
			printf(" \t was successful\n");
		else
			printf("\t failed!\n");
	}
	FIFO_PRINT(&UART);
	if(FIFO_dequeue(&UART , &temp)== FIFO_NoERROR)
		printf("fifo dequeue was successful : %x \n" , temp);
	if(FIFO_dequeue(&UART , &temp)== FIFO_NoERROR)
		printf("fifo dequeue was successful : %x \n" , temp);
	FIFO_PRINT(&UART);
	return 0;
}
