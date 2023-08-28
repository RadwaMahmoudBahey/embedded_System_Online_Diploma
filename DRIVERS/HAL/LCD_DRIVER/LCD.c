//#include "BIT_MATH.h"
#include "LCD.h"

#include "Stm32_F103C6_gpio_driver.h"

void wait_ms(uint32_t time){
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}

void LCD_DATA_PORT_OUTPUT(){

	GPIO_PinConfig_t  pinConfig;

	//initializing control pins to output
	//EN_SWITCH
	pinConfig.PinNo = EN_SWITCH;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL_PORT, &pinConfig);

	//RW_SWITCH
	pinConfig.PinNo = RW_SWITCH;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL_PORT, &pinConfig);

	//RS_SWITCH
	pinConfig.PinNo = RS_SWITCH;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(LCD_CTRL_PORT, &pinConfig);
	//initializing all data pins to output
	//PIN0
	pinConfig.PinNo = PIN0;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &pinConfig);
	//PIN1
	pinConfig.PinNo = PIN1;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &pinConfig);
	//PIN2
	pinConfig.PinNo = PIN2;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &pinConfig);
	//PIN3
	pinConfig.PinNo = PIN3;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &pinConfig);
	//PIN4
	pinConfig.PinNo = PIN4;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &pinConfig);
	//PIN5
	pinConfig.PinNo = PIN5;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &pinConfig);
	//PIN6
	pinConfig.PinNo = PIN6;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &pinConfig);
	//PIN7
	pinConfig.PinNo = PIN7;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_10M;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &pinConfig);
}

void LCD_Init(void){
	wait_ms(50);
	LCD_DATA_PORT_OUTPUT();
	//setting control pins to 0

	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RW_SWITCH, PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RS_SWITCH, PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, EN_SWITCH, PIN_RESET);
	wait_ms(50);
	LCD_ClearScreen();
#ifdef EIGHT_BIT_MODE
	LCD_Command(0x38); //8 bits 2 lines
#endif
#ifdef FOUR_BIT_MODE
	LCD_Command(0x02);
	LCD_Command(0x28); //4 bits 2 lines
#endif
	wait_ms(2);
	LCD_Command(0x0F); // display on cursor blink
	wait_ms(2);
	LCD_ClearScreen();
	wait_ms(10);
	LCD_Command(0b00000110); //entry mode
}





void LCD_Command(unsigned char command){
	//LCD_IsBusy();


#ifdef EIGHT_BIT_MODE
	MCAL_GPIO_WRITE_PORT(LCD_DATA_PORT,command);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RW_SWITCH, PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RS_SWITCH, PIN_RESET);
	LCD_Kick();
#endif
#ifdef FOUR_BIT_MODE
	MCAL_GPIO_WRITE_PORT(LCD_DATA_PORT, (uint8_t )(command& 0xF0));
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RW_SWITCH, PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RS_SWITCH, PIN_RESET);
	LCD_Kick();
	MCAL_GPIO_WRITE_PORT(LCD_DATA_PORT, (uint8_t )(command <<4));
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RW_SWITCH, PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RS_SWITCH, PIN_RESET);
	LCD_Kick();
#endif
}



void LCD_Char(unsigned char data){
//	LCD_IsBusy();


#ifdef EIGHT_BIT_MODE
	MCAL_GPIO_WRITE_PORT(LCD_DATA_PORT, data);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RW_SWITCH, PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RS_SWITCH, PIN_SET);
	LCD_Kick();
#endif
#ifdef FOUR_BIT_MODE
	MCAL_GPIO_WRITE_PORT(LCD_DATA_PORT, (uint8_t )(data& 0xF0));
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RW_SWITCH, PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RS_SWITCH, PIN_SET);
	LCD_Kick();
	MCAL_GPIO_WRITE_PORT(LCD_DATA_PORT, (uint8_t )(data <<4));
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RW_SWITCH, PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RS_SWITCH, PIN_SET);
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
	GPIO_PinConfig_t PinCfg;
	//	DataDir_LCD_PORT &= ~(0xFF << DATA_shift);
	PinCfg.PinNo = PIN0;
	PinCfg.Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &PinCfg);

	PinCfg.PinNo = PIN1;
	PinCfg.Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &PinCfg);

	PinCfg.PinNo = PIN2;
	PinCfg.Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &PinCfg);

	PinCfg.PinNo = PIN3;
	PinCfg.Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &PinCfg);

	PinCfg.PinNo = PIN4;
	PinCfg.Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &PinCfg);

	PinCfg.PinNo = PIN5;
	PinCfg.Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &PinCfg);

	PinCfg.PinNo = PIN6;
	PinCfg.Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &PinCfg);

	PinCfg.PinNo = PIN7;
	PinCfg.Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(LCD_DATA_PORT, &PinCfg);


	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RS_SWITCH, PIN_RESET);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RW_SWITCH, PIN_SET);

	LCD_Kick();

	//initializing all data pins to output
	LCD_DATA_PORT_OUTPUT();
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, RW_SWITCH, PIN_RESET);

}
void LCD_Kick(void){

	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, EN_SWITCH, PIN_SET);
	wait_ms(50);
	MCAL_GPIO_WRITE_PIN(LCD_CTRL_PORT, EN_SWITCH, PIN_RESET);

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
