/*
 ============================================================================
 Name        : Assignment1-.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main() {
	float x ,y ,z;
printf(" Enter three numbers:");
fflush(stdin);
fflush(stdout);
scanf("%f\n", &x);
scanf("%f\n", &y);
scanf("%f",&z);
printf("Largest number = %.2f" ,((x>y) ? ((x>z)? x: z ):((y>z) ? y:z)));
}
