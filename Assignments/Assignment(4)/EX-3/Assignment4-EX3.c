/*
 ============================================================================
 Name        : Assignment4-EX3.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct Scomplex{
	float real;
	float imaginary;
};
void sum (struct Scomplex x , struct Scomplex y){
	struct Scomplex z;
	z.real = x.real + y.real;
	z.imaginary = x.imaginary + y.imaginary;
	printf("Sum = %.1f + %.1fj " , z.real , z.imaginary);
}

int main(void) {
	struct Scomplex x ,y;
	printf("for 1st complex no \nEnter real and imaginary respectively:");
	fflush(stdin);
	fflush(stdout);
	fflush(stdin);
	fflush(stdout);
	scanf("%f\n" , &(x.real));
	scanf("%f" , &(x.imaginary));
	printf("for 2nd complex no \nEnter real and imaginary respectively:");
	fflush(stdin);
	fflush(stdout);
	scanf("%f\n" , &(y.real));
	scanf("%f" , &(y.imaginary));
	sum(x,y);
}
