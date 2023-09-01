/*
 * main.c
 *
 *  Created on: Sep 1, 2023
 *      Author: Dell
 */



#define F_CPU 8000000ul
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//2-mcal
#include "DIO.h"
#include "LCD.h"
#include "avr/io.h"
#include "util/delay.h"


int main(){

	DIO_SetPortDirection(DIO_PORTA,0xFF);
	DIO_SetPinDirection(DIO_PORTB , CLDC_RS_PIN , DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, CLDC_RW_PIN , DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, CLDC_E_PIN , DIO_OUTPUT);

	CLDC_Init();
	LCD_String("LEARN IN DEPTH -RADWA");
	return 0;
}
