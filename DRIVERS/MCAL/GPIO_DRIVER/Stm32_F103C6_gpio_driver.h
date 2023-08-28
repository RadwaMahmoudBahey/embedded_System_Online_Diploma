/*
 * Stm32_F103C6_gpio_driver.h
 *
 *  Created on: Aug 22, 2023
 *      Author: RADWA
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_



#include "stm32f103x6.h"



//======pin configurations======

//@ref GPIO_PIN_configurations
typedef struct{
	volatile uint16_t PinNo;
	volatile uint8_t Mode;
	volatile uint8_t speed;
}GPIO_PinConfig_t;



//================MACROS================

//@ref GPIO_PIN_DEFINE
#define PIN0													(uint16_t)0x0001
#define PIN1													(uint16_t)0x0002
#define PIN2													(uint16_t)0x0004
#define PIN3													(uint16_t)0x0008
#define PIN4													(uint16_t)0x0010
#define PIN5													(uint16_t)0x0020
#define PIN6													(uint16_t)0x0040
#define PIN7													(uint16_t)0x0080
#define PIN8													(uint16_t)0x0100
#define PIN9													(uint16_t)0x0200
#define PIN10													(uint16_t)0x0400
#define PIN11													(uint16_t)0x0800
#define PIN12													(uint16_t)0x1000
#define PIN13													(uint16_t)0x2000
#define PIN14													(uint16_t)0x4000
#define PIN15													(uint16_t)0x8000

#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

#define GPIO_PIN_MASK              0x0000FFFFu /* PIN mask for assert test */


//@ref GPIO_PIN_state
#define PIN_SET																(uint8_t)0x01
#define PIN_RESET																(uint8_t)0x00


//@ref GPIO_RETURN_LOCK
#define LOCK_ENABLED														(uint8_t)0x01
#define LOCK_ERROR															(uint8_t)0x00



//@ref GPIO_MODES
#define GPIO_MODE_ANALOG															0x0000u
#define GPIO_MODE_INPUT_FLO															0x0001u
#define GPIO_MODE_INPUT_PUR															0x0002u
#define GPIO_MODE_INPUT_PDR															0x0003u
#define GPIO_MODE_OUTPUT_PP															0x0004u
#define GPIO_MODE_OUTPUT_OD															0x0005u
#define GPIO_MODE_OUTPUT_AF_PP														0x0006u
#define GPIO_MODE_OUTPUT_AF_OD														0x0007u
#define GPIO_MODE_INPUT_AF															0x0008u



//@ref GPIO_SPEED


#define OUTPUT_SPEED_10M															0x0001u
#define OUTPUT_SPEED_2M																0x0002u
#define OUTPUT_SPEED_50M															0x0003u


/*
 * =======================================================================================
 * 							APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */

void MCAL_GPIO_INIT(GPIO_Typedef* GPIOx , GPIO_PinConfig_t *PinConfig);
void MCAL_GPIO_DEINIT(GPIO_Typedef* GPIOx );

uint8_t MCAL_GPIO_READ_PIN(GPIO_Typedef* GPIOx , uint16_t PinNo);
uint16_t MCAL_GPIO_READ_PORT(GPIO_Typedef* GPIOx );

void MCAL_GPIO_WRITE_PIN(GPIO_Typedef* GPIOx , uint16_t PinNo ,uint8_t PinValue );
void MCAL_GPIO_WRITE_PORT(GPIO_Typedef* GPIOx , uint16_t PortValue);

void MCAL_GPIO_TOGGLE_PIN(GPIO_Typedef* GPIOx , uint16_t PinNo );

uint8_t MCAL_GPIO_LOCK_PIN(GPIO_Typedef* GPIOx , uint16_t PinNo);







#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */
