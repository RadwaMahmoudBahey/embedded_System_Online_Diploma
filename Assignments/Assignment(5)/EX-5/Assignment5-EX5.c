/*
 ============================================================================
 Name        : Assignment5-EX5.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct employee{
	char employee_name[15];
	int employee_id;
};
int main(void) {
	struct employee s = {"sam" , 45} , x = {"pam" , 56};
	struct employee *arr[2] ={&s ,&x};
	struct employee (*(*i)[2])= &arr;
	printf(" 1st employee name is %s\n" , (*(*i))->employee_name);
	printf(" 1st employee ID is %d\n" , (*(*i))->employee_id);
	printf("2nd employee name is %s \n" , (*(*i+1))->employee_name);
	printf(" 2nd employee ID is %d\n" , (*(*i+1))->employee_id);
return 0;
}
