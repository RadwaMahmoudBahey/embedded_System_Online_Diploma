/*
 ============================================================================
 Name        : Assignment2-EX5.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n ,i ,j, arr[100];
	printf("enter no of elements:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &n);
	for(i=0 ;i<n ;i++){
		scanf("%d",&arr[i]);
	}
	printf("enter the elements to be searched:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &j);
	for(i=0;i<n;i++){
		if(arr[i] == j){
			printf("Number found at the location=%d", i+1);
			break;
		}
	}
	if (i==n){
		printf("Number doesn't exist in the array");
	}
}
