#ifndef LCD_H_
#define LCD_H_

#include "Stm32_F103C6_gpio_driver.h"
//for the control port and pins

#define LCD_CTRL_PORT			GPIOA

#define RS_SWITCH 	PIN8
#define RW_SWITCH 	PIN9
#define EN_SWITCH 	PIN10

//for the Data port and pins

#define LCD_DATA_PORT			GPIOA


// 8 bit
#define SHIFT_VALUE 0
#define EIGHT_BIT_MODE
//#define  FOUR_BIT_MODE
void LCD_DATA_PORT_OUTPUT(void);
void LCD_Init(void);
void LCD_Command(unsigned char command);
void LCD_Char(unsigned char data);
void LCD_String(unsigned char* data);
void LCD_IsBusy(void);
void LCD_Kick(void);
void LCD_GoToXY(unsigned char line , unsigned char pin);
void LCD_ClearScreen(void);

#endif
