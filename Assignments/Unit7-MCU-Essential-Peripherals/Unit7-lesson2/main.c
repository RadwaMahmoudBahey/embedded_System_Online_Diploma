#define F_CPU 8000000ul

#include "BIT_MATH.h"
//2-mcal
#include "KPD.h"
#include "LCD.h"
//3-AVR
#include "avr/io.h"
#include "util/delay.h"
int main(void){
	LCD_Init();
	KPD_Init();
	while(1){
		char returned_value =KPD_Value();
		switch(returned_value){
		case 'A':
			break;
		case '?':
			LCD_ClearScreen();
			break;
		default:
			LCD_Char(returned_value);
			break;
		}
	}
}
