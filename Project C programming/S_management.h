/*
 * S_management.h
 *
 *  Created on: Jul 30, 2023
 *      Author: Radwa Mahmoud
 */

#ifndef S_MANAGEMENT_H_
#define S_MANAGEMENT_H_
#define elementType Sstudent
#define get(...) \
	{                        \
		fflush(stdout);      \
		fflush(stdin);       \
		gets(__VA_ARGS__); \
		fflush(stdout);      \
		fflush(stdin);       \
	}
#define scan(...) \
	{                        \
		fflush(stdout);      \
		fflush(stdin);       \
		scanf(__VA_ARGS__); \
		fflush(stdout);      \
		fflush(stdin);       \
	}
#define width 50
#include "string.h"

typedef struct Sstudent_t
{
	char firstName[50];
	char lastName[50];
	int ID;
	float GPA;
	int course_ID[10];
}Sstudent;



typedef enum{
	FIFO_NoERROR,
	FIFO_FULL,
	FIFO_EMPTY,
	FIFO_NULL
}Status;

elementType buffer[width];

typedef struct{
	elementType* base;
	elementType* head;
	elementType* tail;
	unsigned int count;
	unsigned int length;
}FIFO_T;

void Add_Student_From_File(FIFO_T *studentQueue);
void Add_Student_Manually(FIFO_T *studentQueue);
void Find_The_Student_By_Roll_Number(FIFO_T *studentQueue);
void Find_The_Student_By_First_Name(FIFO_T *studentQueue);
void Find_The_Students_Registered_In_Course(FIFO_T *studentQueue);
void Students_Count(FIFO_T *studentQueue);
void Delete_A_Student(FIFO_T *studentQueue);
void Update_Student(FIFO_T *studentQueue);
void Show_Information(FIFO_T *studentQueue);
elementType* findStudentwithID(FIFO_T* fifo , int id);


Status FIFO_INIT(FIFO_T* x , elementType* y , unsigned int length);
Status FIFO_enqueue(FIFO_T* x , elementType item_pushed);
Status FIFO_dequeue(FIFO_T* x , elementType* item_poped);
Status FIFO_IS_FULL(FIFO_T* x);



#endif /* S_MANAGEMENT_H_ */
