#ifndef LIFO_H_
#define LIFO_H_
typedef struct{
	unsigned int* base;
	unsigned int* head;
	unsigned int count;
	unsigned int length;
}LIFO_T;
typedef enum {
	LIFO_NoERROR,
	LIFO_FULL,
	LIFO_EMPTY,
	LIFO_NULL
}Status;
Status LIFO_INIT(LIFO_T* x , unsigned int* y , unsigned int length);
Status LIFO_PUSH(LIFO_T* x  , unsigned int item_pushed);
Status LIFO_POP(LIFO_T* x  , unsigned int* item_poped);
#endif
