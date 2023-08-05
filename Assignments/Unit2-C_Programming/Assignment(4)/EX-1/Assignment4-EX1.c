/*
 ============================================================================
 Name        : Assignment4-EX1.c
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
	float mark;
};

int main(void) {
	struct Student X;
	printf("Enter information of students:\n");
	printf("Enter name :");
	fflush(stdin);
	fflush(stdout);
	gets(X.name);
	printf("Enter roll number:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &(X.roll));
	printf("Enter marks:");
	fflush(stdin);
	fflush(stdout);
	scanf("%f" , &(X.mark));
	printf(" Displaying information:\n");
	printf("name: %s \nRoll: %d \nMarks: %.2f" , X.name , X.roll , X.mark);
}
