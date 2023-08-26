
//#include "BIT_MATH.h"
//2-mcal
#include "KPD.h"

#include "Stm32_F103C6_gpio_driver.h"



void delay_ms(uint32_t time){
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}
void GPIO_init(){

	GPIO_PinConfig_t  pinConfig;



	//ROWS
	pinConfig.PinNo = R0;
	pinConfig.Mode = GPIO_MODE_INPUT_PUR;
	MCAL_GPIO_INIT(KPD_PORT, &pinConfig);


	pinConfig.PinNo = R1;
	pinConfig.Mode = GPIO_MODE_INPUT_PUR;
	MCAL_GPIO_INIT(KPD_PORT, &pinConfig);

	pinConfig.PinNo = R2;
	pinConfig.Mode = GPIO_MODE_INPUT_PUR;
	MCAL_GPIO_INIT(KPD_PORT, &pinConfig);

	pinConfig.PinNo = R3;
	pinConfig.Mode = GPIO_MODE_INPUT_PUR;
	MCAL_GPIO_INIT(KPD_PORT, &pinConfig);
	//COLUMNS
	pinConfig.PinNo = C0;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_2M;
	MCAL_GPIO_INIT(KPD_PORT, &pinConfig);


	pinConfig.PinNo = C1;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_2M;
	MCAL_GPIO_INIT(KPD_PORT, &pinConfig);


	pinConfig.PinNo = C2;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_2M;
	MCAL_GPIO_INIT(KPD_PORT, &pinConfig);


	pinConfig.PinNo = C3;
	pinConfig.Mode = GPIO_MODE_OUTPUT_PP;
	pinConfig.speed =OUTPUT_SPEED_2M;
	MCAL_GPIO_INIT(KPD_PORT, &pinConfig);

	MCAL_GPIO_WRITE_PORT(KPD_PORT, 0xFF);
	MCAL_GPIO_WRITE_PIN(KPD_PORT , C3 , PIN_SET);

}
void KPD_Init(void){
	GPIO_init();
}
char KPD_Value(void){
	volatile char i,j;
	uint16_t KPD_ColumnPin[COLUMNS_SIZE]={C0 ,C1 ,C2 ,C3};
	uint16_t KPD_RowPin[ROWS_SIZE]={R0,R1 ,R2 , R3};
	for(i=0;i<COLUMNS_SIZE;i++){
		MCAL_GPIO_WRITE_PIN(KPD_PORT, KPD_ColumnPin[i], PIN_RESET);
		for (j=0 ; j <ROWS_SIZE ;j++){
			uint8_t value = MCAL_GPIO_READ_PIN(KPD_PORT, KPD_RowPin[j]);
			if(PIN_RESET == value ){
				//for debouncing:
				delay_ms(10);
				value = MCAL_GPIO_READ_PIN(KPD_PORT, KPD_RowPin[j]);
				if(PIN_RESET == value){
					//for polling
					while(PIN_RESET == value)
						value = MCAL_GPIO_READ_PIN(KPD_PORT, KPD_RowPin[j]);
					char KPD_Arr[COLUMNS_SIZE][ROWS_SIZE] =ArrValues;
					return KPD_Arr[j][i];
				}
			}
		}
		delay_ms(10);
		MCAL_GPIO_WRITE_PIN(KPD_PORT, KPD_ColumnPin[i], PIN_SET);

	}
	return 'A';
}
