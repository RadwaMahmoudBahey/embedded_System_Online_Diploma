/*
 ============================================================================
 Name        : Assignment1-EX4.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main() {
	float x ;
printf(" Enter a number:");
fflush(stdin);
fflush(stdout);
scanf("%f", &x);
if(x>0){
	printf("%.2f is positive" ,x);
}
else if (x==0){
	printf("You Entered Zero");
}
else{
	printf("%.2f is negative" ,x);
}
}
