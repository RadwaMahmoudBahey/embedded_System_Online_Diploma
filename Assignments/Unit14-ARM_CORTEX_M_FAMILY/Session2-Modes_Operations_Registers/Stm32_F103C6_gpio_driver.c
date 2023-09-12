/*
 * Stm32_F103C6_gpio_driver.c
 *
 *  Created on: Aug 22, 2023
 *      Author: RADWA
 */

#include "stm32f103x6.h"
#include "Stm32_F103C6_gpio_driver.h"
/*
 * =======================================================================================
 * 							APIs Supported by "MCAL GPIO DRIVER"
 * =======================================================================================
 */



uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	switch (PinNumber)
	{
	case PIN0:
		return 0 ;
		break ;
	case PIN1:
		return 4 ;
		break ;
	case PIN2:
		return 8 ;
		break ;
	case PIN3:
		return 12 ;
		break ;

	case PIN4:
		return 16 ;
		break ;


	case PIN5:
		return 20 ;
		break ;

	case PIN6:
		return 24 ;
		break ;

	case PIN7:
		return 28 ;
		break ;


	case PIN8:
		return 0 ;
		break ;
	case PIN9:
		return 4 ;
		break ;

	case PIN10:
		return 8 ;
		break ;

	case PIN11:
		return 12 ;
		break ;

	case PIN12:
		return 16 ;
		break ;


	case PIN13:
		return 20 ;
		break ;

	case PIN14:
		return 24 ;
		break ;

	case PIN15:
		return 28 ;
		break ;



	}

	return 0 ;
}


/**================================================================
 * @Fn					-MCAL_GPIO_INIT
 * @brief 				-Initialized a pin on the port according to configurations in PinConfig
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 *@param [in] 			-PinConfig:  specifies the configurations of the choosen pin. Set by @ref PINconfigurations
 * @retval 			-none
 * Note							-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 				 But LQFP48 Package has only GPIO A,B,PART of C/D exported as external PINS from the MCU
 */
void MCAL_GPIO_INIT(GPIO_Typedef* GPIOx , GPIO_PinConfig_t *PinConfig){

	volatile uint32_t *CONFIGURE_REG =NULL;
	volatile uint8_t PIN_config = Get_CRLH_Position(PinConfig->PinNo);
	CONFIGURE_REG = (PinConfig->PinNo)< PIN8 ? &GPIOx->CRL : &GPIOx->CRH;
	(*CONFIGURE_REG ) &= ~(0b1111 <<PIN_config);


	if((PinConfig->Mode==GPIO_MODE_OUTPUT_PP) ||(PinConfig->Mode==GPIO_MODE_OUTPUT_OD) ||(PinConfig->Mode==GPIO_MODE_OUTPUT_AF_PP) ||(PinConfig->Mode==GPIO_MODE_OUTPUT_AF_OD) ){
		(*CONFIGURE_REG) |= ((PinConfig->Mode -4)<<2 | PinConfig->speed)<<PIN_config;
	}
	else{
		if((PinConfig->Mode==GPIO_MODE_INPUT_FLO) ||(PinConfig->Mode==GPIO_MODE_ANALOG)){
			(*CONFIGURE_REG) |= (PinConfig->Mode <<2)<<PIN_config ;
		}
		else if( PinConfig->Mode==GPIO_MODE_INPUT_AF ){
			(*CONFIGURE_REG) |= (GPIO_MODE_INPUT_FLO <<2)<<PIN_config ;
		}
		else{
			(*CONFIGURE_REG) |= (GPIO_MODE_INPUT_PUR <<2)<<PIN_config ;
			if((PinConfig->Mode==GPIO_MODE_INPUT_PUR)){
				//PxODR = 1 Input pull-up :Table 20. Port bit configuration table
				GPIOx->ODR |=  PinConfig->PinNo ;
			}
			else{
				//PxODR = 0 Input pull-down :Table 20. Port bit configuration table
				GPIOx->ODR &= ~( PinConfig->PinNo) ;
			}
		}
	}
}








/**================================================================
 * @Fn					-MCAL_GPIO_DEINIT
 * @brief 				-resets the whole gpio
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 			-none
 * Note				-none
 */
void MCAL_GPIO_DEINIT(GPIO_Typedef* GPIOx ){

	//APB2 peripheral reset register (RCC_APB2RSTR)
	// for reseting any gpio peripheral :RCC_APB2RSTR has to be set then cleared

	if(GPIOx == GPIOA){
		RCC->APB2RSTR |= (1<<2);  //Bit 2 IOPARST: IO port A reset
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB){
		RCC->APB2RSTR |= (1<<3) ;
		RCC->APB2RSTR &= ~(1<<3);
	}
	else if(GPIOx == GPIOC){
		RCC->APB2RSTR |= (1<<4) ;
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD){
		RCC->APB2RSTR |= (1<<5) ;
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE){
		RCC->APB2RSTR |= (1<<6) ;
		RCC->APB2RSTR &= ~(1<<6);
	}

}





/**================================================================
 * @Fn					-MCAL_GPIO_READ_PIN
 * @brief 				-reads the pin value
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 *@param [in] 			-PinNumber:  specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 			-returns the pin value
 * Note				-none
 */

uint8_t MCAL_GPIO_READ_PIN(GPIO_Typedef* GPIOx , uint16_t PinNo){

	uint8_t PinVal ;
	if (((GPIOx->IDR) & (PinNo)) != (uint32_t)PIN_RESET){
		PinVal = PIN_SET;
	}
	else{
		PinVal = PIN_RESET;
	}
	return PinVal;
}







/**================================================================
 * @Fn					-MCAL_GPIO_READ_PORT
 * @brief 				-Reads the port value
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 * @retval 			-returns the port value
 * Note				-none
 */



uint16_t MCAL_GPIO_READ_PORT(GPIO_Typedef* GPIOx ){

	uint16_t PortVal = (uint16_t)GPIOx->IDR ;

	return PortVal;

}




/**================================================================
 * @Fn					-MCAL_GPIO_WRITE_PIN
 * @brief 				-write on specific input pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 *@param [in] 			-PinNumber:  specifies the port bit to read. Set by @ref GPIO_PINS_define
 *@param [in] 			-Value: Pin Value
 * @retval 			-none
 * Note				-none
 */

void MCAL_GPIO_WRITE_PIN(GPIO_Typedef* GPIOx , uint16_t PinNo ,uint8_t PinValue) {
	if (PinValue != PIN_RESET){
		GPIOx->BSRR =(uint32_t) PinNo;
	}
	else{
		GPIOx->BRR =(uint32_t) PinNo;
	}
}





/**================================================================
 * @Fn					-MCAL_GPIO_WRITE_PORT
 * @brief 				-write on the port
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 *@param [in] 			-Value: Port Value
 * @retval 			-none
 * Note				-none
 */
void MCAL_GPIO_WRITE_PORT(GPIO_Typedef* GPIOx , uint16_t PortValue){
	GPIOx->ODR = (uint32_t) PortValue;
}

/**================================================================
 * @Fn					-MCAL_GPIO_PARTIAL_WRITE_PORT
 * @brief 				-add to written  port without overriding
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 *@param [in] 			-Value: Port Value
 * @retval 			-none
 * Note				-none
 */
void MCAL_GPIO_PARTIAL_WRITE_PORT(GPIO_Typedef* GPIOx , uint16_t PortValue){
	GPIOx->ODR |= (uint32_t) PortValue;
}




/**================================================================
 * @Fn					-MCAL_GPIO_TOGGLE_PIN
 * @brief 				-toggles a specific input pin
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 *@param [in] 			-PinNumber:  specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 			-none
 * Note				-none
 */

void MCAL_GPIO_TOGGLE_PIN(GPIO_Typedef* GPIOx , uint16_t PinNo ){

	GPIOx->ODR ^= PinNo;
}











/**================================================================
 * @Fn					-MCAL_GPIO_LOCK_PIN
 * @brief 				-locks the configuration of a specific pin until next reset
 * @param [in] 			-GPIOx: where x can be (A..G depending on device used) to select the GPIO peripheral
 *@param [in] 			-PinNumber:  specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 			-returns LOCK_ENABLED if it's done , LOCK_ERROR if error occured with the locking @ref GPIO_RETURN_LOCK
 * Note				-none
 */

uint8_t MCAL_GPIO_LOCK_PIN(GPIO_Typedef* GPIOx , uint16_t PinNo){

	uint32_t temp = 1<<16 ;
	temp |= PinNo;
	GPIOx->LCKR = temp; //write 1
	GPIOx->LCKR =PinNo; //write 0
	GPIOx->LCKR = temp;//write 1
	temp = GPIOx->LCKR ; //read 0
	if( (uint32_t) (GPIOx->LCKR & (1<<16)) ){
		return LOCK_ENABLED;
	}
	else{
		return LOCK_ERROR;
	}
}





