/*
 * Stm32_F103C6_EXTI_driver.h
 *
 *  Created on: Aug 31, 2023
 *      Author: Dell
 */

#ifndef INC_STM32_F103C6_EXTI_DRIVER_H_
#define INC_STM32_F103C6_EXTI_DRIVER_H_


#include "stm32f103x6.h"
#include "Stm32_F103C6_gpio_driver.h"


typedef struct{
	uint16_t	EXTI_InputLineNumber;
	GPIO_Typedef * GPIO_Port;
	uint16_t	PIN_No;
	uint8_t IVT_IRQ_No ;

}EXTI_GPIO_Mapping_t;


typedef struct{
	EXTI_GPIO_Mapping_t  EXTI_PIN;
	uint8_t Trigger_case; //falling / rising or both
	uint8_t IRQ_EN; //IMR enable/disable
	void (*P_IRQ_Callback)(void); //callback function for the ISR implemented in the application layer


}EXTI_PinConfig_t;


//===========================EXTI INTERRUPT LINE NUMBERS===============
#define EXTI0				0
#define EXTI1				1
#define EXTI2				2
#define EXTI3				3
#define EXTI4				4
#define EXTI5				5
#define EXTI6				6
#define EXTI7				7
#define EXTI8				8
#define EXTI9				9
#define EXTI10				10
#define EXTI11				11
#define EXTI12				12
#define EXTI13				13
#define EXTI14				14
#define EXTI15				15

//==============================EXTI GPIO PIN MAPPING==========================


// @ref EXTI_define
//EXTI0
#define EXTI0PA0			(EXTI_GPIO_Mapping_t){EXTI0, GPIOA ,PIN0, EXTI0_IRQ}
#define EXTI0PB0			(EXTI_GPIO_Mapping_t){EXTI0, GPIOB ,PIN0, EXTI0_IRQ}
#define EXTI0PC0			(EXTI_GPIO_Mapping_t){EXTI0, GPIOC ,PIN0, EXTI0_IRQ}
#define EXTI0PD0			(EXTI_GPIO_Mapping_t){EXTI0, GPIOD ,PIN0, EXTI0_IRQ}


// EXTI1
#define EXTI1PA1			(EXTI_GPIO_Mapping_t){EXTI1, GPIOA, PIN1, EXTI1_IRQ}
#define EXTI1PB1			(EXTI_GPIO_Mapping_t){EXTI1, GPIOB, PIN1, EXTI1_IRQ}
#define EXTI1PC1			(EXTI_GPIO_Mapping_t){EXTI1, GPIOC, PIN1, EXTI1_IRQ}
#define EXTI1PD1			(EXTI_GPIO_Mapping_t){EXTI1, GPIOD, PIN1, EXTI1_IRQ}


// EXTI2
#define EXTI2PA2			(EXTI_GPIO_Mapping_t){EXTI2, GPIOA, PIN2, EXTI2_IRQ}
#define EXTI2PB2			(EXTI_GPIO_Mapping_t){EXTI2, GPIOB, PIN2, EXTI2_IRQ}
#define EXTI2PC2			(EXTI_GPIO_Mapping_t){EXTI2, GPIOC, PIN2, EXTI2_IRQ}
#define EXTI2PD2			(EXTI_GPIO_Mapping_t){EXTI2, GPIOD, PIN2, EXTI2_IRQ}


// EXTI3
#define EXTI3PA3			(EXTI_GPIO_Mapping_t){EXTI3, GPIOA, PIN3, EXTI3_IRQ}
#define EXTI3PB3			(EXTI_GPIO_Mapping_t){EXTI3, GPIOB, PIN3, EXTI3_IRQ}
#define EXTI3PC3			(EXTI_GPIO_Mapping_t){EXTI3, GPIOC, PIN3, EXTI3_IRQ}
#define EXTI3PD3			(EXTI_GPIO_Mapping_t){EXTI3, GPIOD, PIN3, EXTI3_IRQ}


// EXTI4
#define EXTI4PA4			(EXTI_GPIO_Mapping_t){EXTI4, GPIOA, PIN4, EXTI4_IRQ}
#define EXTI4PB4			(EXTI_GPIO_Mapping_t){EXTI4, GPIOB, PIN4, EXTI4_IRQ}
#define EXTI4PC4			(EXTI_GPIO_Mapping_t){EXTI4, GPIOC, PIN4, EXTI4_IRQ}
#define EXTI4PD4			(EXTI_GPIO_Mapping_t){EXTI4, GPIOD, PIN4, EXTI4_IRQ}


// EXTI5
#define EXTI5PA5			(EXTI_GPIO_Mapping_t){EXTI5, GPIOA, PIN5, EXTI5_IRQ}
#define EXTI5PB5			(EXTI_GPIO_Mapping_t){EXTI5, GPIOB, PIN5, EXTI5_IRQ}
#define EXTI5PC5			(EXTI_GPIO_Mapping_t){EXTI5, GPIOC, PIN5, EXTI5_IRQ}
#define EXTI5PD5			(EXTI_GPIO_Mapping_t){EXTI5, GPIOD, PIN5, EXTI5_IRQ}


// EXTI6
#define EXTI6PA6			(EXTI_GPIO_Mapping_t){EXTI6, GPIOA, PIN6, EXTI6_IRQ}
#define EXTI6PB6			(EXTI_GPIO_Mapping_t){EXTI6, GPIOB, PIN6, EXTI6_IRQ}
#define EXTI6PC6			(EXTI_GPIO_Mapping_t){EXTI6, GPIOC, PIN6, EXTI6_IRQ}
#define EXTI6PD6			(EXTI_GPIO_Mapping_t){EXTI6, GPIOD, PIN6, EXTI6_IRQ}


// EXTI7
#define EXTI7PA7			(EXTI_GPIO_Mapping_t){EXTI7, GPIOA, PIN7, EXTI7_IRQ}
#define EXTI7PB7			(EXTI_GPIO_Mapping_t){EXTI7, GPIOB, PIN7, EXTI7_IRQ}
#define EXTI7PC7			(EXTI_GPIO_Mapping_t){EXTI7, GPIOC, PIN7, EXTI7_IRQ}
#define EXTI7PD7			(EXTI_GPIO_Mapping_t){EXTI7, GPIOD, PIN7, EXTI7_IRQ}


// EXTI8
#define EXTI8PA8			(EXTI_GPIO_Mapping_t){EXTI8, GPIOA, PIN8, EXTI8_IRQ}
#define EXTI8PB8			(EXTI_GPIO_Mapping_t){EXTI8, GPIOB, PIN8, EXTI8_IRQ}
#define EXTI8PC8			(EXTI_GPIO_Mapping_t){EXTI8, GPIOC, PIN8, EXTI8_IRQ}
#define EXTI8PD8			(EXTI_GPIO_Mapping_t){EXTI8, GPIOD, PIN8, EXTI8_IRQ}


// EXTI9
#define EXTI9PA9			(EXTI_GPIO_Mapping_t){EXTI9, GPIOA, PIN9, EXTI9_IRQ}
#define EXTI9PB9			(EXTI_GPIO_Mapping_t){EXTI9, GPIOB, PIN9, EXTI9_IRQ}
#define EXTI9PC9			(EXTI_GPIO_Mapping_t){EXTI9, GPIOC, PIN9, EXTI9_IRQ}
#define EXTI9PD9			(EXTI_GPIO_Mapping_t){EXTI9, GPIOD, PIN9, EXTI9_IRQ}


// EXTI10
#define EXTI10PA10			(EXTI_GPIO_Mapping_t){EXTI10, GPIOA, PIN10, EXTI10_IRQ}
#define EXTI10PB10			(EXTI_GPIO_Mapping_t){EXTI10, GPIOB, PIN10, EXTI10_IRQ}
#define EXTI10PC10			(EXTI_GPIO_Mapping_t){EXTI10, GPIOC, PIN10, EXTI10_IRQ}
#define EXTI10PD10			(EXTI_GPIO_Mapping_t){EXTI10, GPIOD, PIN10, EXTI10_IRQ}


// EXTI11
#define EXTI11PA11			(EXTI_GPIO_Mapping_t){EXTI11, GPIOA, PIN11, EXTI11_IRQ}
#define EXTI11PB11			(EXTI_GPIO_Mapping_t){EXTI11, GPIOB, PIN11, EXTI11_IRQ}
#define EXTI11PC11			(EXTI_GPIO_Mapping_t){EXTI11, GPIOC, PIN11, EXTI11_IRQ}
#define EXTI11PD11			(EXTI_GPIO_Mapping_t){EXTI11, GPIOD, PIN11, EXTI11_IRQ}


// EXTI12
#define EXTI12PA12			(EXTI_GPIO_Mapping_t){EXTI12, GPIOA, PIN12, EXTI12_IRQ}
#define EXTI12PB12			(EXTI_GPIO_Mapping_t){EXTI12, GPIOB, PIN12, EXTI12_IRQ}
#define EXTI12PC12			(EXTI_GPIO_Mapping_t){EXTI12, GPIOC, PIN12, EXTI12_IRQ}
#define EXTI12PD12			(EXTI_GPIO_Mapping_t){EXTI12, GPIOD, PIN12, EXTI12_IRQ}


// EXTI13
#define EXTI13PA13			(EXTI_GPIO_Mapping_t){EXTI13, GPIOA, PIN13, EXTI13_IRQ}
#define EXTI13PB13			(EXTI_GPIO_Mapping_t){EXTI13, GPIOB, PIN13, EXTI13_IRQ}
#define EXTI13PC13			(EXTI_GPIO_Mapping_t){EXTI13, GPIOC, PIN13, EXTI13_IRQ}
#define EXTI13PD13			(EXTI_GPIO_Mapping_t){EXTI13, GPIOD, PIN13, EXTI13_IRQ}


// EXTI14
#define EXTI14PA14			(EXTI_GPIO_Mapping_t){EXTI14, GPIOA, PIN14, EXTI14_IRQ}
#define EXTI14PB14			(EXTI_GPIO_Mapping_t){EXTI14, GPIOB, PIN14, EXTI14_IRQ}
#define EXTI14PC14			(EXTI_GPIO_Mapping_t){EXTI14, GPIOC, PIN14, EXTI14_IRQ}
#define EXTI14PD14			(EXTI_GPIO_Mapping_t){EXTI14, GPIOD, PIN14, EXTI14_IRQ}


// EXTI15
#define EXTI15PA15			(EXTI_GPIO_Mapping_t){EXTI15, GPIOA, PIN15, EXTI15_IRQ}
#define EXTI15PB15			(EXTI_GPIO_Mapping_t){EXTI15, GPIOB, PIN15, EXTI15_IRQ}
#define EXTI15PC15			(EXTI_GPIO_Mapping_t){EXTI15, GPIOC, PIN15, EXTI15_IRQ}
#define EXTI15PD15			(EXTI_GPIO_Mapping_t){EXTI15, GPIOD, PIN15, EXTI15_IRQ}


// @ref EXTI_TRIGGER_define
#define EXTI_TRIGGER_RISING					0
#define EXTI_TRIGGER_FALLING				1
#define EXTI_TRIGGER_RISINGandFALLING		2


// @ref EXTI_INTERRUPT_ENABLE/DISABLEdefine
#define EXTI_IRQ_ENABLE				0
#define EXTI_IRQ_DISABLE			1

/*
 * =======================================================================================
 * 							APIs Supported by "MCAL EXTI DRIVER"
 * =======================================================================================
 */



void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config);
void MCAL_EXTI_GPIO_DeInit(void);
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config);

#endif /* INC_STM32_F103C6_EXTI_DRIVER_H_ */
