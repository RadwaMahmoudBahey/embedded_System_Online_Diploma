/*
 ============================================================================
 Name        : Assignment1-EX1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <math.h>
int main() {
	int x ;
printf(" Enter an Integer you want to check:");
fflush(stdin);
fflush(stdout);
scanf("%d", &x);
if ((x%2)==0){
	printf("%d is even" ,x);
}
else{
	printf("%d is odd" ,x);
}

}
