/*
 ============================================================================
 Name        : Assignment1-EX8.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main() {
	char x;
	float y , z;
printf(" Enter operator either + or - or * or divide:");
fflush(stdin);
fflush(stdout);
scanf("%c", &x);
printf(" Enter two operands:");
fflush(stdin);
fflush(stdout);
scanf("%f\n", &y);
scanf("%f", &z);
switch(x){
case '+':
	printf("%.1f + %.1f = %.1f" , y , z , (y+z));
	break;
case '-':
	printf("%.1f - %.1f = %.1f" , y , z , (y-z));
	break;
case '*':
	printf("%.1f * %.1f = %.1f" , y , z , (y*z));
	break;
case '/':
	printf("%.1f / %.1f = %.1f" , y , z , (y/z));
	break;
}
}
