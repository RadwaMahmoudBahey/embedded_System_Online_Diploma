/*
 *
 *  Created on: Jul 22, 2022
 *      Author: Dell
 */

#include <stdio.h>
#include <stdlib.h>
int Factorial(int n, int f);
int main(void) {
	int n , f=1;
	printf("Enter a positive integer:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&n);
	int x = Factorial(n , f);
	printf("Factorial of %d = %d",n ,x);
	return 0;
}

int Factorial(int n, int f){
	f*=n;
	n--;
	if(n>0){
		Factorial(n , f);
	}else{
	return f;
}
}
