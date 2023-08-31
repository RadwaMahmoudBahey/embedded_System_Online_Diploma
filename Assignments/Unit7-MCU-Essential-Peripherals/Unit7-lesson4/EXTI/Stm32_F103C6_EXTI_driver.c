/*
 * Stm32_F103C6_EXTI_driver.c
 *
 *  Created on: Aug 31, 2023
 *      Author: Dell
 */


#include "Stm32_F103C6_EXTI_driver.h"


/*
 * =======================================================================================
 * 										GLOBAL VARIABLES
 * =======================================================================================
 */

void (* GP_IRQ_Callback[15])(void);

/*
 * =======================================================================================
 * 										GENERIC MACROS
 * =======================================================================================
 */




#define AFIO_GPIO_EXTI_Mapping(x)	((x==GPIOA)?0:\
		(x==GPIOB)?1:\
				(x==GPIOC)?2:\
						(x==GPIOD)?3:0)


/*
 * =======================================================================================
 * 										GENERIC FUNCTIONS
 * =======================================================================================
 */




void NVIC_ENABLE(uint16_t IRQ){
	switch(IRQ){
	case EXTI0:
		NVIC_IRQ6_EXTI0_Enable();
		break;
	case EXTI1:
		NVIC_IRQ7_EXTI1_Enable();
		break;
	case EXTI2:
		NVIC_IRQ8_EXTI2_Enable();
		break;
	case EXTI3:
		NVIC_IRQ9_EXTI3_Enable();
		break;
	case EXTI4:
		NVIC_IRQ10_EXTI4_Enable();
		break;
	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IRQ23_EXTI5_9_Enable();
		break;
	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IRQ40_EXTI10_15_Enable();
		break;
	}

}


void NVIC_DISABLE(uint16_t IRQ)
{
	switch(IRQ)
	{
	case EXTI0:
		NVIC_IRQ6_EXTI0_Disable();
		break;

	case EXTI1:
		NVIC_IRQ7_EXTI1_Disable();
		break;

	case EXTI2:
		NVIC_IRQ8_EXTI2_Disable();
		break;

	case EXTI3:
		NVIC_IRQ9_EXTI3_Disable();
		break;

	case EXTI4:
		NVIC_IRQ10_EXTI4_Disable();
		break;

	case EXTI5:
	case EXTI6:
	case EXTI7:
	case EXTI8:
	case EXTI9:
		NVIC_IRQ23_EXTI5_9_Disable();
		break;

	case EXTI10:
	case EXTI11:
	case EXTI12:
	case EXTI13:
	case EXTI14:
	case EXTI15:
		NVIC_IRQ40_EXTI10_15_Disable();
		break;
	}
}




/*
 * =======================================================================================
 * 							APIs Supported by "MCAL EXTI DRIVER"
 * =======================================================================================
 */



/*=====================================================================
 * @Fn				- MCAL_EXTI_GPIO_Init
 * @brief 			- this is used to Initializes the EXTI from specific GPIO PIN and specify the Mask/Trigger condition and IRQ CallBack
 * @param [in] 		- EXTI_Config set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @retval			- none
 * Note				- stm32F103c6 MCU has GPIO A,B,C,D,E Modules
 * 					- but LQFP48 package has only GPIO A,B,Part of C/D exported as external PINS from the MCU
 * 					- Also Mandatory to enable RCC clock for AFIO and corresponding GPIO
 */


void MCAL_EXTI_GPIO_Init(EXTI_PinConfig_t* EXTI_Config){
	MCAL_EXTI_GPIO_Update(EXTI_Config);
}
/*=====================================================================
 * @Fn				- MCAL_EXTI_GPIO_DeInit
 * @brief 			- this is used to reset all EXTI registersand disable all NVIC
 * @param [in] 		- none
 * @retval			- none
 * Note				-none
 */


void MCAL_EXTI_GPIO_DeInit(void){

	//reset values of each register:
	EXTI->IMR =   0x00000000 ;
	EXTI->EMR =   0x00000000 ;
	EXTI->RTSR =  0x00000000 ;
	EXTI->FTSR =  0x00000000 ;
	EXTI->SWIER = 0x00000000 ;

	//PR register cleared :w1c
	EXTI->PR =    0xFFFFFFFF ;

	//disabling NVIC IRQ :
	NVIC_IRQ6_EXTI0_Disable();
	NVIC_IRQ7_EXTI1_Disable();
	NVIC_IRQ8_EXTI2_Disable();
	NVIC_IRQ9_EXTI3_Disable();
	NVIC_IRQ10_EXTI4_Disable();
	NVIC_IRQ23_EXTI5_9_Disable();
	NVIC_IRQ40_EXTI10_15_Disable();




}

/*=====================================================================
 * @Fn				- MCAL_EXTI_GPIO_Update
 * @brief 			- this is used to Initializes the EXTI from specific GPIO PIN and specify the Mask/Trigger condition and IRQ CallBack
 * @param [in] 		- EXTI_Config set by @ref EXTI_define, EXTI_Trigger_define and EXTI_IRQ_define
 * @retval			- none
 * Note				- stm32F103c6 MCU has GPIO A,B,C,D,E Modules
 * 					- but LQFP48 package has only GPIO A,B,Part of C/D exported as external PINS from the MCU
 * 					- Also Mandatory to enable RCC clock for AFIO and corresponding GPIO
 */
void MCAL_EXTI_GPIO_Update(EXTI_PinConfig_t* EXTI_Config){

	//FIRST set pin to input floating
	GPIO_PinConfig_t PinCfg;
	PinCfg.PinNo = EXTI_Config->EXTI_PIN.PIN_No;
	PinCfg.Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(EXTI_Config->EXTI_PIN.GPIO_Port, &PinCfg);


	//SECOND updating the AFIO

	//EXTICR index
	uint8_t AFIO_Index = ((EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) /4 );
	uint8_t AFIO_Position =((EXTI_Config->EXTI_PIN.EXTI_InputLineNumber) %4 )*4 ;

	// clearing the four bits
	AFIO->EXTICR[AFIO_Index] &= ~((0xF)<<AFIO_Position);

	//setting the 4 bits to the gpio:
	AFIO->EXTICR[AFIO_Index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_Config->EXTI_PIN.GPIO_Port) &0xF)<<AFIO_Position);


	//THIRD setting the triggering edge(/s)
	//clearing both rising and falling edges first
	EXTI->RTSR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	EXTI->FTSR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);


	if(EXTI_Config->Trigger_case == EXTI_TRIGGER_RISING){
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if(EXTI_Config->Trigger_case == EXTI_TRIGGER_FALLING){
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if(EXTI_Config->Trigger_case == EXTI_TRIGGER_RISINGandFALLING){
		EXTI->FTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		EXTI->RTSR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}

	//FORTH updating IRQ callback

	GP_IRQ_Callback[EXTI_Config->EXTI_PIN.EXTI_InputLineNumber] =EXTI_Config->P_IRQ_Callback;

	//FIFTH enabling/disabling the interrupt

	if(EXTI_Config->IRQ_EN == EXTI_IRQ_ENABLE){
		EXTI->IMR |= (1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		NVIC_ENABLE(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}
	else if(EXTI_Config->IRQ_EN ==EXTI_IRQ_DISABLE){
		EXTI->IMR &= ~(1<<EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
		NVIC_DISABLE(EXTI_Config->EXTI_PIN.EXTI_InputLineNumber);
	}


}




/*
 * =======================================================================================
 * 										ISR FUNCTIONS
 * =======================================================================================
 */





void EXTI0_IRQHandler(void){
	//clear the corresponding pending bit
	EXTI->PR = 1<<0;
	//callback funtion
	GP_IRQ_Callback[0]();
}


void EXTI1_IRQHandler(void){
	//clear the corresponding pending bit
	EXTI->PR = 1<<1;
	//callback funtion
	GP_IRQ_Callback[1]();
}

void EXTI2_IRQHandler(void){
	//clear the corresponding pending bit
	EXTI->PR = 1<<2;
	//callback funtion
	GP_IRQ_Callback[2]();
}

void EXTI3_IRQHandler(void){
	//clear the corresponding pending bit
	EXTI->PR = 1<<3;
	//callback funtion
	GP_IRQ_Callback[3]();
}



void EXTI4_IRQHandler(void){
	//clear the corresponding pending bit
	EXTI->PR = 1<<4;
	//callback funtion
	GP_IRQ_Callback[4]();
}



void EXTI9_5_IRQHandler(void){

	if(EXTI->PR & 1<<5) { EXTI->PR  = 1<<5;   GP_IRQ_Callback[5](); }
	if(EXTI->PR & 1<<6) { EXTI->PR  = 1<<6;   GP_IRQ_Callback[6](); }
	if(EXTI->PR & 1<<7) { EXTI->PR  = 1<<7;   GP_IRQ_Callback[7](); }
	if(EXTI->PR & 1<<8) { EXTI->PR  = 1<<8;   GP_IRQ_Callback[8](); }
	if(EXTI->PR & 1<<9) { EXTI->PR  = 1<<9;   GP_IRQ_Callback[9](); }
}



void EXTI15_10_IRQHandler(void){

	if( EXTI->PR & 1<<10 ) { EXTI->PR |= 1<<10; GP_IRQ_Callback[10](); }
	if( EXTI->PR & 1<<11 ) { EXTI->PR |= 1<<11; GP_IRQ_Callback[11](); }
	if( EXTI->PR & 1<<12 ) { EXTI->PR |= 1<<12; GP_IRQ_Callback[12](); }
	if( EXTI->PR & 1<<13 ) { EXTI->PR |= 1<<13; GP_IRQ_Callback[13](); }
	if( EXTI->PR & 1<<14 ) { EXTI->PR |= 1<<14; GP_IRQ_Callback[14](); }
	if( EXTI->PR & 1<<14 ) { EXTI->PR |= 1<<15; GP_IRQ_Callback[15](); }
}
