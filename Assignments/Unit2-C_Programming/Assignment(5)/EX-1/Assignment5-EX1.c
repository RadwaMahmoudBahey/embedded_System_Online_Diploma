/*
 ============================================================================
 Name        : Assignment5-EX1.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
int m =29;
int* ab;
printf("address of m: %p \n" , &m);
printf("value of m is %d \n \n" ,m);
ab = &m;
printf("now ab is assigned with the address of m\n\n");
printf("address of pointer ab is %p\n" , ab);
printf("content of pointer ab is %d\n\n" , *ab);
m=34;
printf("the value of m is assigned to 34 now\n\n");
printf("address of pointer ab is %p\n" , ab);
printf("content of pointer ab is %d\n\n" , *ab);
*ab =7;
printf("the pointer variable is assigned to 7 now\n\n");
printf("address of m: %p \n" , &m);
printf("value of m is %d \n " ,m);
return 0;
}
