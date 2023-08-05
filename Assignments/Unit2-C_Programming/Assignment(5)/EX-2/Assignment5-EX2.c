/*
 ============================================================================
 Name        : Assignment5-EX2.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
char arr[26];
int i ,j;
for (i=65 ,j=0 ; i<=90 ; j++ ,i++){
	arr[j] = (char)i;
}
char *p = arr;
printf("The alphabets are:\n");
for(i=0 ; i<26 ; i++){
	printf("%c  " , *(p+i));
}
return 0;
}
