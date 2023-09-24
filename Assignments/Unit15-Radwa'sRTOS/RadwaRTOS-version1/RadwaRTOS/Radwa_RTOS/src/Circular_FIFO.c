/*
 * Cirular_FIFO.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Dell
 */

#include "Circular_FIFO.h"


Status FIFO_INIT(FIFO_T* x , elementType* y , unsigned int length){
	if (y == 0)
		return FIFO_NULL;
	x->length = length;
	x->base = y;
	x->head = y;
	x->tail = y;
	x->count =0;
	return FIFO_NoERROR;
}
Status FIFO_enqueue(FIFO_T* x , elementType item_pushed){
	if (!x->base|| !x->head || !x->tail)
		return FIFO_NULL;
	if(FIFO_IS_FULL(x) ==FIFO_FULL)
		return FIFO_FULL;
	*(x->head) = item_pushed;
	x->count++;
	if(x->head == (x->base + x->length * sizeof(elementType)))
		x->head = x->base;
	else
			x->head++;
	return FIFO_NoERROR;
}
Status FIFO_dequeue(FIFO_T* x , elementType* item_poped){
	if (!x->base|| !x->head || !x->tail)
		return FIFO_NULL;
	if(x->count ==0)
		return FIFO_EMPTY;
	*(item_poped) = *(x->tail);
	x->count--;
	if(x->tail == (x->base + x->length * sizeof(elementType)))
		x->tail = x->base;
	else
			x->tail++;
	return FIFO_NoERROR;
}
Status FIFO_IS_FULL(FIFO_T* x){
	if (!x->base|| !x->head || !x->tail)
		return FIFO_NULL;
	if(x->count >= x->length)
			return FIFO_FULL;
	return FIFO_NoERROR;
}
void FIFO_PRINT(FIFO_T* x){
	if(x->count ==0)
		printf("FIFO is empty");
	else{
		elementType* temp = x->tail;
		int i;
		printf("\n ====FIFO PRINT===== \n");
		for(i=0 ; i< x->count ; i++){
			printf(" %x \n" , *temp);
			temp++;
		}
		printf("\n ==DONE== \n");
	}
}
