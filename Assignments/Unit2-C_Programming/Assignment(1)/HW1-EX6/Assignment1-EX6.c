/*
 ============================================================================
 Name        : Assignment1-EX6.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
int main() {
	float a ,b , temp;
printf(" Enter value of a: ");
fflush(stdin);
fflush(stdout);
scanf("%f",&a);
printf(" Enter value of b: ");
fflush(stdin);
fflush(stdout);
scanf("%f",&b);
temp =a;
a=b;
b=temp;

printf("\n \n after swapping , value of a = %.2f \n" ,a);
printf("after swapping , value of b = %.1f" ,b);
}
