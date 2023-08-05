/*
 ============================================================================
 Name        : Assignment2-EX1.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float a[2][2] , b[2][2] ;
	int i,j;
	printf("Enter the elements of the 1st matrix\r\n");
	for(i=1; i<=2 ; i++){
		for(j=1; j<=2 ; j++){
			printf("Enter a%d%d :" , i , j);
			fflush(stdin);
			fflush(stdout);
			scanf("%f" , &a[i-1][j-1]);
		}
	}
	printf("Enter the elements of the 2nd matrix \r\n");
	for(i=1; i<=2 ; i++){
		for(j=1; j<=2 ; j++){
			printf("Enter b%d%d :" , i , j);
			fflush(stdin);
			fflush(stdout);
			scanf("%f" , &b[i-1][j-1]);
		}
	}
	printf("Sum Of Matrix: \r\n");
	for(i=0; i<2 ; i++){
		for(j=0; j<2 ; j++){
			printf("%.1f     " , a[i][j] + b[i][j]);
		}
		printf("\r\n");
	}
}
