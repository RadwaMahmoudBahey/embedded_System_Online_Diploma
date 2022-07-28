/*
 ============================================================================
 Name        : Assignment2-EX7.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, sum=0;
	char s[100] ;
	printf("enter a string:");
	fflush(stdin);
	fflush(stdout);
	gets(s);
	for(i=0 ;s[i]!=0 ; i++){
		sum++;
	}
	printf("length of string: %d" , sum);
}
