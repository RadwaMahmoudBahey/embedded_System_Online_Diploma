/*
 ============================================================================
 Name        : Assignment2-EX6.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int i , sum=0;
	char x;
	printf("enter a string:");
	fflush(stdin);
	fflush(stdout);
	char s[100] ;
	gets(s);
	printf("enter a character to find frequency:");
	fflush(stdin);
	fflush(stdout);
	scanf("%c" , &x);
	for(i=0 ; i<strlen(s) ; i++){
		if(s[i] == x){
			sum++;
		}
	}
	printf("frequency of %c = %d" , x , sum);
}
