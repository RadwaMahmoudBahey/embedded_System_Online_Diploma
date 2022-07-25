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
	int x , i ,factorial =1;
printf(" Enter an integer:");
fflush(stdin);
fflush(stdout);
scanf("%d", &x);
if(x>0){
	for(i=1 ; i<=x ; i++){
		factorial*=i;
	}
	printf("factorial = %d" ,factorial);
}
else if (x==0){
	printf("factorial = 0");
}
else{
	printf("Error!!! factorial of a negative number doesn't exist");
}
}
