/*
 ============================================================================
 Name        : Assignment4-EX2.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct Sdistance{
	int feet;
	float inch;
};
void sum (struct Sdistance x , struct Sdistance y){
	struct Sdistance z;
	z.feet = x.feet + y.feet ;
	z.inch = x.inch + y.inch;
	while (z.inch >=12){
		++z.feet;
		z.inch -=12;
	}
	printf("Sum of distances = %d'-%.1f\" " , z.feet , z.inch);
}

int main(void) {
	struct Sdistance x ,y;
	printf("Enter information of 1st distance:\n");
	printf("Enter feet:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &(x.feet));
	printf("Enter inches:");
	fflush(stdin);
	fflush(stdout);
	scanf("%f" , &(x.inch));
	printf("Enter information of 2nd distance:\n");
	printf("Enter feet:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &(y.feet));
	printf("Enter inches:");
	fflush(stdin);
	fflush(stdout);
	scanf("%f" , &(y.inch));
	sum(x,y);
}
