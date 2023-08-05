#include "uart.h"
unsigned char send[100]  = "learn-in-depth:<radwa>";
unsigned int const x =585;
void main(void){
	UART_TRANSMIT(send);
}