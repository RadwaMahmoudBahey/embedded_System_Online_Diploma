#ifndef KPD_H_
#define KPD_H_

#include "Stm32_F103C6_gpio_driver.h"

#define R0 PIN0
#define R1 PIN1
#define R2 PIN3
#define R3 PIN4
#define C0 PIN5
#define C1 PIN6
#define C2 PIN7
#define C3 PIN8

#define KPD_PORT 		GPIOB

#define COLUMNS_SIZE 4
#define ROWS_SIZE 4
#define ArrValues {{'7','8','9','%'},\
		{'4','5','6','X'},\
		{'1','2','3','-'},\
		{'?','0','=','+'}}
void KPD_Init(void);
char KPD_Value(void);

#endif
