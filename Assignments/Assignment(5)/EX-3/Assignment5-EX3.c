/*
 ============================================================================
 Name        : Assignment5-EX3.c
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
	char s[50];
	int i;
printf("enter an input:");
fflush(stdin);
fflush(stdout);
gets(s);
char *p = s + strlen(s) -1 ;
printf("reverse of the string is :");
for (i =0; i< strlen(s) ; p-- ,i++){
	printf("%c" , *p);
}
}
