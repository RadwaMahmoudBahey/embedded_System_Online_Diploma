
#include <stdio.h>
#include <stdint.h>

#define RCC_BASE 	0x40021000
#define PORTA_BASE 	0x40010800
#define vuint32_t     volatile uint32_t
#define RCC_APB2ENR 	*(volatile uint32_t*)(RCC_BASE + 0x18)
#define GPIOA_CRH		*(volatile uint32_t*)(PORTA_BASE + 0x04)
#define GPIOA_ODR		*((volatile uint32_t*)(PORTA_BASE + 0x0c))

typedef union {
	vuint32_t allpins ;
	struct{
		vuint32_t reserved:13;
		vuint32_t pin13:1;
	}pin;
} port;
volatile port* p = (volatile port*)(PORTA_BASE + 0x0c);
int main(void)
{
	RCC_APB2ENR |= 1<<2;
	GPIOA_CRH   &= 0xFF0FFFFF;
	GPIOA_CRH   |= 0x00200000;
	while(1){
		p->pin.pin13 =1;
		for(int i =0 ; i<3000 ; i++);
		p->pin.pin13 =0;
		for(int i =0 ; i<3000 ; i++);
	}
	return 0;
}
