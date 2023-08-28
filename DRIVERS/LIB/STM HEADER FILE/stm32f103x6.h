/*
 * stm32f103x6.h
 *
 *  Created on: Aug 22, 2023
 *      Author: RADWA
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

#include "stdio.h"
#include "stdlib.h"


//=================================MEMORY BASE===================================


#define FLASH_Memory_BASE								0x08000000UL
#define System_Memory_BASE								0x1FFFF000UL
#define SRAM_Memory_BASE								0x20000000UL

//=======================PERIPHERALS BASE========================
#define PERIPHERAL_BASE									0x40000000UL
#define CORTEXM3_PERIPHERAL_BASE						0xE0000000UL


//=================================PERIPHERALS===================================


//===============================================
//Base addresses for AHB Peripherals
//===============================================

//=======================CLOCK BASE========================
#define RCC_BASE										0x40021000UL


//===============================================
//Base addresses for APB2 Peripherals
//===============================================

//=======================GPIO BASE========================
#define GPIOA_BASE										0x40010800UL//Fully  included in LQFP48
#define GPIOB_BASE										0x40010C00UL//Fully  included in LQFP48
#define GPIOC_BASE										0x40011000UL//Partially  included in LQFP48
#define GPIOD_BASE										0x40011400UL //Partially  included in LQFP48
#define GPIOE_BASE										0x40011800UL //not used in LQFP48


//=======================ALTERNATIVE FUNCTIONS BASE========================
#define AFIO_BASE										0x40010000UL

//=======================EXTERNAL INTERRUPT BASE========================
#define EXTI_BASE										0x40010400UL


//=================================REGISTERS===================================



//===GPIO===

typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_Typedef;


//===AFIO===

typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED;
	volatile uint32_t MAPR2;
}AFIO_Typedef;



//===EXTI===

typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_Typedef;



//===RCC===

typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_Typedef;


//====================PERIPHERALS MACROS=================

#define GPIOA 										 ((GPIO_Typedef *) GPIOA_BASE)
#define GPIOB 										 ((GPIO_Typedef *) GPIOB_BASE)
#define GPIOC 										 ((GPIO_Typedef *) GPIOC_BASE)
#define GPIOD 										 ((GPIO_Typedef *) GPIOD_BASE)
#define GPIOE 										 ((GPIO_Typedef *) GPIOE_BASE)



#define RCC											((RCC_Typedef *)RCC_BASE)
#define EXTI										((EXTI_Typedef *)EXTI_BASE)
#define AFIO										((AFIO_Typedef *)AFIO_BASE)



//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define RCC_AFIO_CLK_EN()							(RCC->APB2ENR |= 1<<0)
#define RCC_GPIOA_CLK_EN()							(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()							(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()							(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()							(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()							(RCC->APB2ENR |= 1<<6)



#endif /* INC_STM32F103X6_H_ */
