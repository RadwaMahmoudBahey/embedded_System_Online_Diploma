/*
 ============================================================================
 Name        : Assignment4-EX5.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14
#define AREA(radius) (radius*radius*PI)
int main(void) {
	float radius ,area;
	printf("Enter the radius:");
	fflush(stdout);
	scanf("%f" , &radius);
	area =AREA(radius);
	printf("Area is %.2f ", area);
}
