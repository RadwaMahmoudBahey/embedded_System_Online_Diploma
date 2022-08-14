/*
 ============================================================================
 Name        : Assignment4-EX4.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct Student{
	char name [50];
	int roll;
	int mark;
};
int main(void) {
	struct Student x[10];
	int i;
	printf("enter info of students\n");
	for(i=0; i<10 ;i++){
		x[i].roll =i+1;
		printf("for roll number %d\n" ,x[i].roll );
		printf("Enter name :");
			fflush(stdin);
			fflush(stdout);
			gets(x[i].name);
			printf("Enter marks:");
			fflush(stdin);
			fflush(stdout);
			scanf("%d" , &(x[i].mark));
	}
	printf("displaying info of students\n");
	for(i=0;i<10;i++){
		printf("information for roll number %d \nName : %s \nMarks: %d\n" ,x[i].roll , x[i].name , x[i].mark);
	}
}
