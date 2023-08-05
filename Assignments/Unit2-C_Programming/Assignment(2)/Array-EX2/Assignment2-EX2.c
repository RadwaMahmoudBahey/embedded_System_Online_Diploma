/*
 ============================================================================
 Name        : Assignment2-EX2.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i ,n ;
	float arr[n] , average , sum=0;
	printf("Enter the numbers of data:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &n);
	for (i=0 ; i< n; i++){
		printf("Enter number:");
		fflush(stdin);
		fflush(stdout);
		scanf("%f" , &arr[i]);
		sum += arr[i];
	}
	average = sum /n ;
	printf("average = %.2f" , average);
}
