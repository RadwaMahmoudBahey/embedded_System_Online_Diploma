
/*
 * main.c
 *
 *  Created on: Aug 12, 2023
 *      Author: Dell
 */
#define F_CPU 8000000ul
#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
//#define IO_Base 0x20
//#define MCUCR		*(volatile uint32_t*)(IO_Base + 0x35)
//#define MCUCSR		*(volatile uint32_t*)(IO_Base + 0x34)
//#define GIFR		*(volatile uint32_t*)(IO_Base + 0x3A)
//#define GICR		*(volatile uint32_t*)(IO_Base + 0x3B)
//#define SREG		*(volatile uint32_t*)(IO_Base + 0x3F)

void gpio_init(){
	//setting direction as an output for the leds for pins 5,6,7
	DDRD |= 1<<5 ;
	DDRD |= 1<<6 ;
	DDRD |= 1<<7 ;
}
void EXT_interrupt_init(){
	MCUCR  |= 1<<0 ;
	MCUCR  |= 1<<2 ;
	MCUCR  |= 1<<3 ;
	MCUCR &= ~(1<<1);
	MCUCSR &= ~(1 <<6) ;
	//global interrupt unmasked
	SREG |= 1 <<7 ;
	//setting GIC for INT0,1,2
	GICR |= 1<<5 ;
	GICR |= 1<<6 ;
	GICR |= 1<<7 ;
}

int main(){
	EXT_interrupt_init();
	gpio_init();
	while(1){
		PORTD &= ~(1 <<5) ;
		PORTD &= ~(1 <<6) ;
		PORTD &= ~(1 <<7) ;
	}

	return 0;
}

ISR(INT0_vect)
{
	PORTD |= 1<<5 ;
	_delay_ms(1000);
	//INT0 pending request
	GIFR |= 1 <<6;
}
ISR(INT1_vect)
{
	PORTD |= 1<<6 ;
	_delay_ms(1000);
	//INT1 pending request
	GIFR |= 1 <<7;
}
ISR(INT2_vect)
{
	PORTD |= 1<<7 ;
	_delay_ms(1000);
//INT2 pending request
	GIFR |= 1 <<5;
}


