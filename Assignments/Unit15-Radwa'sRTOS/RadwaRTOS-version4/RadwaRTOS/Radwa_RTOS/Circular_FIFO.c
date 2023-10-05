/*
 * Cirular_FIFO.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Dell
 */

#include "Circular_FIFO.h"



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



/* *********************************** */
Status FIFO_INIT (FIFO_T* fifo,elementType* buff , unsigned int length){

	if(!buff )
		return FIFO_NULL;

	fifo->base = buff ;
	fifo->head = fifo->base ;
	fifo->tail = fifo->base ;
	fifo->length = length;
	fifo->count=0;

	return FIFO_NoERROR;

}

/* *********************************** */






Status FIFO_enqueue (FIFO_T* fifo,elementType item){

	/* fifo null*/

	if (!fifo->base || !fifo->length)
		return FIFO_NULL;
	/*fifo is full*/

	/* fifo full */
	if ((fifo->head == fifo->tail) && (fifo->count == fifo->length))
		return FIFO_FULL;

	*(fifo->tail)=item;
	fifo->count++;

	/*for circular fifo again */

	/* circular enqueue */
	if (fifo->tail == (((unsigned int)fifo->base + (4*fifo->length )) - 4 ))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	return FIFO_NoERROR;


}

/* *********************************** */




Status FIFO_dequeue (FIFO_T* fifo, elementType* item){
	/* check fifo valid */
	if (!fifo->base || !fifo->length)
		return FIFO_NULL;

	/* fifo empty */
	if (fifo->head == fifo->tail)
		return FIFO_EMPTY;



	*item = *(fifo->head);
	fifo->count--;

	/* circular dequeue */
	if (fifo->head == (((unsigned int)fifo->base + (4*fifo->length )) - 4 ))
		fifo->head = fifo->base;
	else
		fifo->head++;

	return FIFO_NoERROR;
}




/* *********************************** */



Status FIFO_IS_FULL (FIFO_T* fifo){

	if(!fifo->head || !fifo->base || !fifo->tail)
		return FIFO_NULL;
	if(fifo->count == fifo->length)
		return FIFO_FULL;

	return FIFO_NoERROR;
}
