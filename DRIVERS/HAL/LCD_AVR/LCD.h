#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"


#define CLDC_DATA_PORT    DIO_PORTA
#define CLDC_CTRL_PORT    DIO_PORTB




//ctrl pins
#define CLDC_RS_PIN  DIO_PIN1
#define CLDC_RW_PIN  DIO_PIN2
#define CLDC_E_PIN   DIO_PIN3

// send command
void CLDC_SendCommand(u8 u8CommandCopy);
//send data
void CLDC_SendData(u8 u8DataCopy);

//clcd init

void CLDC_Init(void);

void LCD_GoToXY(u8 line , u8 pin);
void LCD_String(u8* data);

#endif
