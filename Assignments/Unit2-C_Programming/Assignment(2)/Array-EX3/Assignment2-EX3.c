/*
 ============================================================================
 Name        : Assignment2-EX3.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x,y  ,i ,j;
	printf("Enter rows and columns of the matrix:");
	fflush(stdin);
	fflush(stdout);
	scanf("%d\r\n" , &x);
	scanf("%d" , &y);
	int a[x][y] , b[y][x];
	printf("Enter elements of the matrix:\r\n");
	for(i=1; i<=x ; i++){
		for(j=1; j<=y ; j++){
			printf("Enter a%d%d :" , i , j);
			fflush(stdin);
			fflush(stdout);
			scanf("%d" , &a[i-1][j-1]);
		}
	}
	printf("Entered Matrix:\r\n");
	for(i=0; i<x ; i++){
		for(j=0; j<y ; j++){
			printf("%d    " , a[i][j]);
		}
		printf("\r\n");
	}
	printf("Transpose of Matrix:\r\n");
	for(i=0; i<x ; i++){
			for(j=0; j<y ; j++){
				b[j][i] = a[i][j];
			}
	}
			for(i=0; i<y ; i++){
				for(j=0; j<x ; j++){
					printf("%d    " , b[i][j]);
				}
				printf("\r\n");
			}

}
