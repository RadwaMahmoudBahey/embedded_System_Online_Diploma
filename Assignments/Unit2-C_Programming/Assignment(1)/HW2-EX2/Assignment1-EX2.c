/*
 ============================================================================
 Name        : Assignment1-EX2.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>

int main(void) {
	char x;
printf(" Enter an alphabet:");
fflush(stdin);
fflush(stdout);
scanf("%c", &x);
if (x=='a' || x=='i' ||x=='e' || x=='o' ||x=='u'||x=='A' || x=='I' ||x=='E' || x=='O' ||x=='U'){
	printf("%c is a vowel" ,x);
}
else{
	printf("%c is a consonant" ,x);
}
}
