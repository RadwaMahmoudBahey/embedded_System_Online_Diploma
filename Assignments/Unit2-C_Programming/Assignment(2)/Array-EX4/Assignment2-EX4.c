/*
 ============================================================================
 Name        : Assignment2-EX4.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n ,i ,j,x, arr[100];
	printf("enter no of elements:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &n);
	for (i=1 ; i<= n ;i++){
		arr[i-1] = i;
		printf("%d " , arr[i-1]);
	}
	printf("\r\n enter the element to be inserted:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &x);
	printf("enter the location:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &j);
	for(i=n; i>= j ;i--){
		arr[i] = arr[i-1];
	}
	n++;
	arr[j-1]= x;
	for(i=0 ; i<n ;i++){
		printf("%d " , arr[i]);
	}
}
