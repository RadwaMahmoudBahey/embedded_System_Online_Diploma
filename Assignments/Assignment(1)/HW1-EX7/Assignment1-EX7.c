/*
 ============================================================================
 Name        : Assignment1-EX7.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main() {
	int a ,b ;
printf(" Enter value of a: ");
fflush(stdin);
fflush(stdout);
scanf("%d",&a);
printf(" Enter value of b: ");
fflush(stdin);
fflush(stdout);
scanf("%d",&b);
a = a+b;
b= a-b;
a = a-b;

printf("\n \n after swapping , value of a = %d \n" ,a);
printf("after swapping , value of b = %d" ,b);
}
