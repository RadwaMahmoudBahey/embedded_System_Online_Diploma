#ifndef LCD_H_
#define LCD_H_

//for the control port and pins

#define LCD_CTRL_VALUE			PORTB
#define LCD_CTRL_DIRECTION		DDRB

#define RS_SWITCH 	1
#define RW_SWITCH 	2
#define EN_SWITCH 	3

//for the Data port and pins

#define LCD_DATA_VALUE			PORTA
#define LCD_DATA_DIRECTION		DDRA

// 8 bit
#define SHIFT_VALUE 0
#define EIGHT_BIT_MODE
//#define  FOUR_BIT_MODE
void LCD_Init(void);
void LCD_Command(unsigned char command);
void LCD_Char(unsigned char data);
void LCD_String(unsigned char* data);
void LCD_IsBusy(void);
void LCD_Kick(void);
void LCD_GoToXY(unsigned char line , unsigned char pin);
void LCD_ClearScreen(void);

#endif
