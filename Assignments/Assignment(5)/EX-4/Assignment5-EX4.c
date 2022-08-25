/*
 ============================================================================
 Name        : Assignment5-EX4.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n , i;
	printf("input the number of elements to store in the array (max 15):");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &n);
	printf("input %d number of elements in the array:\n" , n);
	int c [n];
	int *p =c;
	for(i=1 ; i<= n ;i++){
		printf("element-%d :" , i);
		fflush(stdin);
		fflush(stdout);
		scanf("%d" , p++);
	}
	p--;
	printf("the elements in reverse order are:\n");
	for (i=n ; i>0 ; i--){
		printf("element-%d : %d \n" , i , *p--);
	}
	return 0;
}
