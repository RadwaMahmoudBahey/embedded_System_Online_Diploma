/*
 ============================================================================
 Name        : Assignment1-EX5.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main() {
	char x ;
printf(" Enter a character:");
fflush(stdin);
fflush(stdout);
scanf("%c", &x);
if ((x>64 && x<91) ||(x>96 && x<123)){
	printf("%c is an alphabet" ,x );
}
else{
	printf("%c is not an alphabet" ,x );
}
}
