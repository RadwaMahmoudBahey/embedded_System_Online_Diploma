/*
 ============================================================================
 Name        : Assignment2-EX8.c
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
	char s[100] , b[100] ;
	int i ,x;
		printf("enter a string:");
		fflush(stdin);
		fflush(stdout);
		gets(s);
		for(i=0 , x = strlen(s) -1; i<strlen(s) ; i++ , x--){
			b[i] = s[x];
		}
		b[i] = 0;
		printf("reverse string is: %s" , b);
}
