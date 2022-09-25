/*
 ============================================================================
 Name        : DataBase.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define PRINT(...) {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}
struct properties{
	int ID;
	float height;
	char name[40];
};
struct node{
	struct properties student ;
	struct node* next;
};
struct node* head = NULL;

int AddStudent(){
	struct node* new = (struct node* )malloc(sizeof(struct node));
	char text[50];
	if(new == NULL){
		printf("full heap");
		return 1;
	}
	if(head == NULL){
		head = new;
	}
	else{
		struct node* temp =head;
		while(temp->next);
		temp->next = new;
	}
	PRINT("ENTER the ID: \n");
	gets(text);
	new->student.ID = atoi(text);

	PRINT("ENTER the name: \n");
	gets(new->student.name);


	PRINT("ENTER the height: \n");
	gets(text);
	new->student.height = atof(text);

	new->next = NULL;
	return 0;
}

int DeleteStudent(){
	char text[40];
	int id;
	PRINT("ENTER the ID you want to delete : \n");
	gets(text);
	id = atoi(text);
	if(head){
		struct node* temp = head;
		struct node* prev = NULL;
		while(temp){
			if(temp->student.ID == id){
				if(prev){
					prev->next = temp->next ;
				}
				else{
					head = temp->next;
				}
				free(temp);
				printf("deleting student with id :%d is done successfully !\n" , id);
				return 0;
			}
			prev = temp;
			temp = temp->next ;
		}
	}
	printf("error , can't find someone with this ID \n");
	return 1;
}

void ViewStudents(){
	int count =1;
	if(!head){
		printf("EMPTY LIST\n");
	}
	struct node* temp = head;
	while(temp){
		printf("record number: %i \n" , count);
		printf("Student's ID: %i \n" , temp->student.ID);
		printf("Student's name: %s \n" , temp->student.name);
		printf("Student's height: %.2f \n" , temp->student.height);
		temp = temp->next ;
		count++;
	}
}
void DeleteAll(){
	if(!head){
		printf("EMPTY LIST\n");
	}
	struct node* temp = head;
	struct node* prev = NULL;
	while(temp){
		prev = temp;
		temp = temp->next ;
		free(prev);
	}
	head = NULL;
	printf("DELETING ALL STUDENTS DONE SUCCESSFULLY\n");
}

int getValue(){
	char text[50];
	struct node* temp = head;
	PRINT(" enter the index you want for it's value in the linked list\n");
	gets(text);
	int count=0;
	if(!head){
		printf("EMPTY LIST\n");
		return 1;
	}
	while(temp){
		if(count == atoi(text)){
			printf("Student with index=%d ID: %i \n" , atoi(text) ,temp->student.ID);
			printf("Student with index=%d name: %s \n" ,  atoi(text) ,temp->student.name);
			printf("Student with index=%d height: %.2f \n" , atoi(text) , temp->student.height);
			return 0;

		}
		count++;
		temp = temp->next ;
	}
	printf("index not found\n");
	return 1;
}

int length(){
	int count =1;
	struct node* temp = head;
	if(!head){
		PRINT("length of the linked list =0\n");
		return 1;
	}
	while(temp->next){
		count++;
		temp = temp->next ;
	}
	PRINT("length of the linked list =%d\n" , count);
	return count;
}
int getValueFromEnd(){
	if(!head){
		printf("EMPTY LIST\n");
		return 1;
	}
	struct node* temp = head;
	struct node* prev = head;
	char text[50];
	PRINT(" enter the index from the end which you want for it's value in the linked list\n");
	gets(text);
	int i, count= atoi(text);
	if(count>length()){
		printf("the index is bigger than the length of the linked list\n");
		return 1;
	}
	for(i=0 ; i<count ;i++){
		temp=temp->next;
	}
while(temp){
	temp=temp->next;
	prev = prev->next;
}
	printf("Student with index=%d from the end ID: %i \n" , count ,prev->student.ID);
	printf("Student with index=%d from the end name: %s \n" ,  count ,prev->student.name);
	printf("Student with index=%d from the end height: %.2f \n" , count , prev->student.height);
	return 0;
}

int middle(){
	struct node* temp = head;
	struct node* prev = head;
	if(!head){
		printf("EMPTY LIST\n");
		return 1;
	}
	while(temp){
		temp = temp->next->next;
		prev = prev->next;
	}
	printf("info of the middle element of the list is:\n");
	printf("Student's ID: %i \n" ,prev->student.ID);
	printf("Student's name: %s \n" ,prev->student.name);
	printf("Student's height: %.2f \n" ,  prev->student.height);
	return 0;
}
int detectLoop(){
	struct node* temp = head;
	struct node* prev = head;

	while(temp && prev &&temp->next){
		temp = temp->next->next;
		prev = prev->next;
		if(temp == prev){
			printf("Loop Found!!\n");
			return 0;
		}
	}
	printf("Loop not Found \n");
	return 1;
}

int main(void) {
	char text[50];
	while(1){
		PRINT("\n");
		PRINT("Select one of the following options: \n1:Add Student \n2:Delete Student \n3:View Students \n4:Delete all Students \n5:get Value from index \n6:length of the linked list \n7: the value from index from the end\n8:values of the middle element of the list \n9: check if there's a loop \n");
		gets(text);
		switch(atoi(text)){
		case 1:
			AddStudent();
			break;
		case 2:
			DeleteStudent();
			break;
		case 3:
			ViewStudents();
			break;
		case 4:
			DeleteAll();
			break;
		case 5:
			getValue();
			break;
		case 6:
			length();
			break;
		case 7:
			getValueFromEnd();
			break;
		case 8:
			middle();
			break;
		case 9:
			detectLoop();
			break;
		default :
			PRINT("\n Wrong Choice \n");
		}

	}


	return 0;
}
