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
	int a ,i , sum =0 ;
printf(" Enter an Integer: ");
fflush(stdin);
fflush(stdout);
scanf("%d",&a);
for (i=1 ; i<=a ; i++){
	sum+= i;
}
printf("sum: %d" , sum);
}
