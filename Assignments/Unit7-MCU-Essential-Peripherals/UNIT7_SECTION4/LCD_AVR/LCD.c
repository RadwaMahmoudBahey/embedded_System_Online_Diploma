


//1-lib
#include "LCD.h"

#include "STD_TYPES.h"
#include "BIT_MATH.h"
//2-mcal
#include "DIO.h"
//3-AVR
#include "avr/io.h"
#include "util/delay.h"
//4-Hal


// send command
void CLDC_SendCommand(u8 u8CommandCopy){

	//step: rs=0 rw=0
	DIO_SetPinValue(CLDC_CTRL_PORT,CLDC_RS_PIN,DIO_LOW);
	DIO_SetPinValue(CLDC_CTRL_PORT,CLDC_RW_PIN,DIO_LOW);


	//send command through data port
	DIO_SetPortValue(CLDC_DATA_PORT,u8CommandCopy);

	//activate enable pin : set then delay then reset
	DIO_SetPinValue(CLDC_CTRL_PORT,CLDC_E_PIN,DIO_HIGH);
	_delay_ms(2);// another 1 milli for the  delay in initializiation
	DIO_SetPinValue(CLDC_CTRL_PORT,CLDC_E_PIN,DIO_LOW);
}
//send data
void CLDC_SendData(u8 u8DataCopy){
	//rs=1 , rw=0
	DIO_SetPinValue(CLDC_CTRL_PORT,CLDC_RS_PIN,DIO_HIGH);
	DIO_SetPinValue(CLDC_CTRL_PORT,CLDC_RW_PIN,DIO_LOW);
	//send data through data port
	DIO_SetPortValue(CLDC_DATA_PORT,u8DataCopy);

	//activate enable pin : set then delay then reset
	DIO_SetPinValue(CLDC_CTRL_PORT,CLDC_E_PIN,DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLDC_CTRL_PORT,CLDC_E_PIN,DIO_LOW);

}

//clcd init
void CLDC_Init(void){
	_delay_ms(50);
	//N->1 : 2 lines on,F->1 font size: 5x11
	CLDC_SendCommand(0b00111100);
	//D: display enable:1 , C:cursor enable:0"disable" ,B:cursor blink:0"disable"
	CLDC_SendCommand(0b00001100);
	//display clear
	CLDC_SendCommand(0b00000001);
}

void LCD_String(u8* data){
	volatile u8 count=0;
	while(*data){
		count++;
		CLDC_SendData(*data++);
		if(count==16){
			LCD_GoToXY(1,0);
		}
		else if(count==32){
			LCD_ClearScreen();
			LCD_GoToXY(0,0);
			count=0;
		}

	}
}
void LCD_ClearScreen(void){
	CLDC_SendCommand(0x01);
}


void LCD_GoToXY(u8 line , u8 pin){
	if(pin<16 && pin>=0){
		if(line==0){
			CLDC_SendCommand(0x80+pin);
		}
		else if (line==1){
			CLDC_SendCommand(0xC0+pin);
		}
	}
}
