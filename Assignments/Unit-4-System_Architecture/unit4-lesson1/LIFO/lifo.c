#include "lifo.h"
Status LIFO_INIT(LIFO_T* x , unsigned int* y , unsigned int length){
	if (y == 0)
		return LIFO_NULL;
	x->length = length;
	x->base = y;
	x->head = y;
	x->count =0;
	return LIFO_NoERROR;
}
Status LIFO_PUSH(LIFO_T* x  , unsigned int item_pushed){
	if (!x->base|| !x->head)
		return LIFO_NULL;
	if(x->count >= x->length)
		return LIFO_FULL;
	*(x->head) = item_pushed;
	x->head++;
	x->count++;
	return LIFO_NoERROR;
}
Status LIFO_POP(LIFO_T* x  , unsigned int* item_poped){
	if (!x->base|| !x->head)
		return LIFO_NULL;
	if(x->count ==0)
		return LIFO_EMPTY;
	x->head--;
	*(item_poped) = *(x->head);
	x->count--;
	return LIFO_NoERROR;
}
