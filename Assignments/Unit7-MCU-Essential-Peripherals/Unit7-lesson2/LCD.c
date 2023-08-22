#include "BIT_MATH.h"
#include "LCD.h"
#include "avr/io.h"
#include "util/delay.h"
void LCD_Init(void){
	_delay_ms(50);
	LCD_CTRL_DIRECTION |= (1<<EN_SWITCH |1<<RW_SWITCH |1<<RS_SWITCH ) ;
	LCD_CTRL_VALUE &= ~(1<<EN_SWITCH |1<<RW_SWITCH |1<<RS_SWITCH ) ;
	_delay_ms(50);
	LCD_ClearScreen();
#ifdef EIGHT_BIT_MODE
	LCD_Command(0x38); //8 bits 2 lines
#endif
#ifdef FOUR_BIT_MODE
	LCD_Command(0x02);
	LCD_Command(0x28); //4 bits 2 lines
#endif
	_delay_ms(2);
	LCD_Command(0x0F); // display on cursor blink
	_delay_ms(2);
	LCD_ClearScreen();
	_delay_ms(10);
	LCD_Command(0b00000110); //entry mode
}



void LCD_Command(unsigned char command){
	LCD_IsBusy();
	LCD_CTRL_DIRECTION |= (1<<EN_SWITCH |1<<RW_SWITCH |1<<RS_SWITCH ) ;
	LCD_DATA_DIRECTION |= 0xFF<< SHIFT_VALUE;
	LCD_CTRL_VALUE &= ~( 1<<RW_SWITCH);
	LCD_CTRL_VALUE &= ~(1<<RS_SWITCH);
#ifdef EIGHT_BIT_MODE
	LCD_DATA_VALUE = command;
	LCD_Kick();
#endif
#ifdef FOUR_BIT_MODE
	LCD_DATA_VALUE = (LCD_DATA_VALUE & 0x0F ) |(command & 0xF0);
	LCD_Kick();
	LCD_DATA_VALUE = (LCD_DATA_VALUE & 0x0F ) |(command <<4);
	LCD_Kick();
#endif
}



void LCD_Char(unsigned char data){
	LCD_IsBusy();
	LCD_CTRL_DIRECTION|= (1<<EN_SWITCH |1<<RW_SWITCH |1<<RS_SWITCH ) ;
	LCD_DATA_DIRECTION |= 0xFF<< SHIFT_VALUE;
	LCD_CTRL_VALUE &= ~( 1<<RW_SWITCH);
	LCD_CTRL_VALUE |= 1<<RS_SWITCH;
#ifdef EIGHT_BIT_MODE
	LCD_DATA_VALUE = data;
	LCD_Kick();
#endif
#ifdef FOUR_BIT_MODE
	LCD_DATA_VALUE = (LCD_DATA_VALUE & 0x0F ) |(data & 0xF0);
	LCD_Kick();
	LCD_DATA_VALUE = (LCD_DATA_VALUE & 0x0F ) |(data <<4);
	LCD_Kick();
#endif

}
void LCD_String(unsigned char* data){
	volatile unsigned char count=0;
	while(*data){
		count++;
		LCD_Char(*data++);
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
void LCD_IsBusy(void){
	LCD_DATA_DIRECTION &= ~(0xFF<< SHIFT_VALUE);
	LCD_CTRL_VALUE |= 1<<RW_SWITCH;
	LCD_CTRL_VALUE &= ~(1<<RS_SWITCH);
	LCD_Kick();
	LCD_DATA_DIRECTION |= 0xFF<< SHIFT_VALUE;
	LCD_CTRL_VALUE &= ~( 1<<RW_SWITCH);
}
void LCD_Kick(void){

	LCD_CTRL_VALUE |= 1<<EN_SWITCH;
	_delay_ms(50);
	LCD_CTRL_VALUE &= ~(1<<EN_SWITCH);

}
void LCD_GoToXY(unsigned char line , unsigned char pin){
	if(pin<16 && pin>=0){
		if(line==0){
			LCD_Command(0x80+pin);
		}
		else if (line==1){
			LCD_Command(0xC0+pin);
		}
	}
}

void LCD_ClearScreen(void){
	LCD_Command(0x01);
}
