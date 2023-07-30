/*
 * S_management.c
 *
 *  Created on: Jul 30, 2023
 *      Author: Radwa Mahmoud
 */

#include "S_management.h"
#include "stdio.h"



void Add_Student_Manually(FIFO_T *studentQueue){
	Sstudent  new;
	char temp[50];
	int i;
	if( ! studentQueue->base ){
		printf("fifo isn't initialized");
		return;
	}
	if(FIFO_IS_FULL(studentQueue) ==FIFO_FULL){
		printf("fifo is full can't add another item\n");
		return;
	}
	printf("enter the students unique roll number:\n");
	get(temp);
	new.ID =atoi(temp);
	if((findStudentwithID(studentQueue , new.ID))!=NULL){
		printf("ERROR , this ID is already used by another student\n");
		return;
	}

	printf("enter the first name of the student:\n");
	get(new.firstName);
	printf("enter the last name of the student:\n");
	get(new.lastName);
	printf("enter the gpa  of the student:\n");
	scan("%f" , &new.GPA);
	for(i=0;i<5;i++){
		printf("enter the course number of the student :\n%d) " , i+1);
		get(temp);
		new.course_ID[i] = atoi(temp);
	}
	if(FIFO_enqueue(studentQueue ,new) == FIFO_NoERROR){
		printf("\n[INFO]  ID number %d saved successfully \n" , new.ID);
	}
	Students_Count(studentQueue);
}

void Add_Student_From_File(FIFO_T *studentQueue){
	Sstudent  new;
	FILE * ptr;
	int i;
	if( ! studentQueue->base ){
		printf("fifo isn't initialized");
		return;
	}
	if(FIFO_IS_FULL(studentQueue) ==FIFO_FULL){
		printf("fifo is full can't add another item\n");
		return;
	}
	ptr = fopen("student.txt" ,"r");
	if(!ptr){
		printf("ERROR , cannot opening file\n");
		return;
	}
	while(!feof(ptr)){
		fscanf(ptr,"%d" , &new.ID);
		if((findStudentwithID(studentQueue , new.ID))!=NULL){
			printf("\nERROR , ID:%d is already used by another student\n" ,new.ID);
			fscanf(ptr, "%*[^\n]"); //to skip the whole line
			continue;
		}
		fscanf(ptr,"%s" , new.firstName);
		fscanf(ptr,"%s" , new.lastName);
		fscanf(ptr,"%f" , &new.GPA);
		for(i=0;i<5;i++){
			fscanf(ptr,"%d" , &new.course_ID[i]);
		}
		if(FIFO_enqueue(studentQueue ,new) == FIFO_NoERROR){
			printf("\n[INFO]  ID number %d saved successfully \n" , new.ID);
		}

	}
	Students_Count(studentQueue);
	fclose(ptr);

}


void Delete_A_Student(FIFO_T *studentQueue){
	int flag=0 , i , id;
	char temp[10];
	elementType *current , *prev=NULL;

	if(studentQueue->count ==0){
		printf("=====EMPTY QUEUE :NOTHING TO BE DELETED========\n");
		return;
	}
	current = studentQueue->tail;
	printf("please enter the ID of the student you want to delete:\n");
	get(temp);
	id=atoi(temp);
	for(i=0;i<studentQueue->count ;i++){
		if (current->ID == id){
			flag=1;
			while(current!=studentQueue->head){
				prev =current;
				current++;
				*prev = *current;
			}
			printf("\n=====Student with id:%d deleted successfully=====\n" , id);
			studentQueue->head--;
			studentQueue->count--;
			Students_Count(studentQueue);
			break;
		}
		current++;
	}
	if (!flag){
		printf("ERROR: no student with that id:%d\n" , id);
	}
}


void Find_The_Student_By_Roll_Number(FIFO_T *studentQueue){
	int i , id;
	char temp[10];
	elementType *current;

	if(studentQueue->count ==0){
		printf("=====EMPTY QUEUE :NO STUDENT TO SEARCH FOR========\n");
		return;
	}
	printf("please enter the ID of the student you want to search for:\n");
	get(temp);
	id=atoi(temp);
	current = findStudentwithID(studentQueue , id);
	if(!current){
		printf("ERROR: no student with that id:%d\n" , id);
	}
	else{
		printf("\n==============STUDENT'S INFO==============\n");
		printf("Student ID: %d \n" , current->ID);
		printf("Student First Name: %s \n" , current->firstName);
		printf("Student Last Name: %s \n" , current->lastName);
		printf("Student GPA Number: %0.2f \n" , current->GPA);
		for(i=0;i<5;i++)
		{
			printf("the course ID are: %d \n" , current->course_ID[i]);
		}
		printf("\n===================DONE====================\n");
	}
}

void Find_The_Student_By_First_Name(FIFO_T *studentQueue){
	int flag=0 , i ,j;
	char temp[10];
	elementType *current;

	if(studentQueue->count ==0){
		printf("=====EMPTY QUEUE :NO STUDENT TO SEARCH FOR========\n");
		return;
	}
	printf("please enter the name of the student you want to search for:\n");
	get(temp);

	current = studentQueue->tail;
	for(i=0;i<studentQueue->count ;i++){
		if(!(stricmp(current->firstName , temp))){
			flag++;
			if (flag==1){

				printf("\n==============STUDENT'S INFO==============\n");
			}
			else{

				printf("\n=======================================\n");
			}
			printf("Student ID: %d \n" , current->ID);
			printf("Student First Name: %s \n" , current->firstName);
			printf("Student Last Name: %s \n" , current->lastName);
			printf("Student GPA Number: %0.2f \n" , current->GPA);
			for(j=0;j<5;j++)
			{
				printf("the course ID are: %d \n" , current->course_ID[j]);
			}
		}
		current++;
	}
	if(!flag){
		printf("ERROR: no student with that name:%s\n" , temp);
	}
	else{
		printf("\n===================DONE====================\n");
	}

}

void Find_The_Students_Registered_In_Course(FIFO_T *studentQueue){
	int flag=0 , i ,j ,t ,k;
	char temp[10];
	elementType *current;

	if(studentQueue->count ==0){
		printf("=====EMPTY QUEUE :NO COURSES TO SEARCH FOR========\n");
		return;
	}
	printf("please enter the course number you want to search for:\n");
	get(temp);
	t = atoi(temp);
	current = studentQueue->tail;
	for(i=0;i<studentQueue->count ;i++){
		for(j=0;j<5;j++){
			if( t== current->course_ID[j] ){
				flag++;
				if (flag==1){

					printf("\n==============STUDENT'S INFO==============\n");
				}
				else{

					printf("\n=======================================\n");
				}
				printf("Student ID: %d \n" , current->ID);
				printf("Student First Name: %s \n" , current->firstName);
				printf("Student Last Name: %s \n" , current->lastName);
				printf("Student GPA Number: %0.2f \n" , current->GPA);
				for(k=0;k<5;k++)
				{
					printf("the course ID are: %d \n" , current->course_ID[k]);
				}
			}

		}
		current++;
	}
	if(!flag){
		printf("ERROR: no students registered in that course:%d\n" , t);
	}
	else{
		printf("\n===================DONE====================\n");
	}
}

void Students_Count(FIFO_T *studentQueue){
	//	int count=0 ,i;
	//	elementType *current = studentQueue->tail;
	//	for(i=0;i<studentQueue->count ;i++){
	//		count++;
	//		current++;
	//	}
	//	// or much easier way: int count=studentQueue->count;
	//	printf("\n***************=====================COUNT OF STUDENTS = %d =====================***************\n" , count);

	printf("------------------------------------------------------- \n");
	printf("\t the total number of Student is %d \n" , studentQueue->count);
	printf("\t you can add up to %d Students \n" , studentQueue->length);
	printf("\t you can add %d more Students \n" , studentQueue->length - studentQueue->count);
	printf("------------------------------------------------------- \n");
}

void Update_Student(FIFO_T *studentQueue){
	int i ,id ,j , flag =0;
	char temp[20];
	elementType *current ;

	if(studentQueue->count ==0){
		printf("=====EMPTY QUEUE :NO STUDENT TO SEARCH FOR========\n");
		return;
	}


	printf("please enter the ID of the student you want to search for:\n");
	get(temp);
	id=atoi(temp);
	current = findStudentwithID(studentQueue , id);
	if(!current){
		printf("ERROR: no student with that id:%d\n" , id);
	}
	else{
		printf("choose one of the following options:\n");
		printf("1) Update First name\n2) Update Last name \n3) Update GPA \n4) Update course ID\n");
		get(temp);
		i=atoi(temp);
		switch(i){
		case 1:
			printf("please enter the new first name:\n");
			get(temp);
			strcpy(current->firstName , temp);
			printf("new first name is set: %s\n",current->firstName);
			break;
		case 2:
			printf("please enter the new last name:\n");
			get(temp);
			strcpy(current->lastName , temp);
			printf("new last Name is set: %s\n",current->lastName);
			break;
		case 3:
			printf("please enter the new GPA:\n");
			scan("%f" , &current->GPA);
			printf("new GPA  is set: %0.2f \n", current->GPA);
			break;
		case 4:
			printf("please enter the course number you want to replace :\n");
			get(temp);
			for(j=0;j<5;j++){
				if(current->course_ID[j] == atoi(temp)){
					flag=1;
					printf("please enter the new course number  :\n");
					get(temp);
					current->course_ID[j] =atoi(temp);
					printf("new course number  is set: %d\n",current->course_ID[j]);
					break;
				}
			}
			if (!flag){
				printf("Error , wrong course number :%d\n" , atoi(temp));
			}
			break;
		default:
			printf("\nError , wrong choice!!!\n");
			break;
		}
	}
}

void Show_Information(FIFO_T *studentQueue){
	int i , flag=0 ,j;
	elementType *current = studentQueue->tail;

	if(studentQueue->count ==0){
			printf("=====EMPTY QUEUE :NO STUDENT TO SEARCH FOR========\n");
			return;
		}
	printf("\n==============STUDENT'S INFO==============\n");
	for(i=0;i<studentQueue->count ;i++){
		flag++;
		if (flag>1){
			printf("\n=======================================\n");
		}
		printf("Student's first name: %s\n" , current->firstName);
		printf("Student's Last name: %s\n" , current->lastName);
		printf("Student's roll number: %d\n" , current->ID);
		printf("Student's GPA : %0.2f\n" , current->GPA);
		for(j=0;j<5;j++){
			printf("The course ID are: %d\n" , current->course_ID[j]);
		}
		current++;
	}

	printf("\n===================DONE====================\n");
	Students_Count(studentQueue);
}




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

elementType* findStudentwithID(FIFO_T* fifo , int id){
	elementType* temp = fifo->tail;
	int i;
	for(i=0;i< fifo->count ; i++){
		if (temp->ID == id){
			return temp;
		}
		temp++;
	}
	temp = NULL;
	return temp;
}


