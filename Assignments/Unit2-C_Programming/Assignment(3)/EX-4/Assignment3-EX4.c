/*
 ============================================================================
 Name        : Assignment3-EX4.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int power(int x,int y , int z);
int main(void) {
	int x , y,z =1;
	printf("Enter base number:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&x);
	printf("Enter power number(positive integer):");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&y);
	z= power(x,y ,z);
	printf("%d^%d = %d" , x , y , z);
}
int power(int x,int y , int z){
	z *=x;
	y--;
	if(y>0){
		power(x,y,z);
	}
	else{
		return z;
	}
}
