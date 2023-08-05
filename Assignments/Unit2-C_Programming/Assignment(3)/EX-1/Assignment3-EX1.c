/*
 ============================================================================
 Name        : Assignment3-EX1.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, x ;
	printf("Enter two numbers(intervals):");
	fflush(stdin);
	fflush(stdout);
	scanf("%d\r\n",&n);
	scanf("%d",&x);
	int j , k[30] , z=0 , i;
	for(j=n; j<x ;j++){
		int  m=j/2 , flag=0 ;
		for(i=2;i<m;i++)
		{
			if(j%i==0)
			{
				flag =1;
				break;
			}
		}
		if(flag==0){
			k[z++] =j;
		}
	}
	printf("prime numbers between %d and %d are: " , n , x );
	for (i=0 ; i<z ; i++){
		printf("%d " ,k[i]);
	}
}
