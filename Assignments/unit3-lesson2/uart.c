//uart -radwa
#include "uart.h"
#define UARTDR *((volatile unsigned int* const)((unsigned int*) 0x0101f1000))
	void UART_TRANSMIT(unsigned  char* x){
		while(*x !=0){
			UARTDR = *x;
			x++;
		}
	}