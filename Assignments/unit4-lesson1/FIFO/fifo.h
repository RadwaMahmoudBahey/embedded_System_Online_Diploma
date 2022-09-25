#ifndef FIFO_H_
#define FIFO_H_

#define elementType unsigned char
#define width 5
elementType buffer[width];
typedef enum{
	FIFO_NoERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}Status;
typedef struct{
	elementType* base;
	elementType* head;
	elementType* tail;
	unsigned int count;
	unsigned int length;
}FIFO_T;
Status FIFO_INIT(FIFO_T* x , elementType* y , unsigned int length);
Status FIFO_enqueue(FIFO_T* x , elementType item_pushed);
Status FIFO_dequeue(FIFO_T* x , elementType* item_poped);
Status FIFO_IS_FULL(FIFO_T* x);
void FIFO_PRINT(FIFO_T* x);
#endif
