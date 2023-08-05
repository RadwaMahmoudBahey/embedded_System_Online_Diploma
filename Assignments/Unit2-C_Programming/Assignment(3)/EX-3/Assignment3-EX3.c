/*
 ============================================================================
 Name        : Assignment3-EX3.c
 Author      : radwaamahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void reverse(char s[] ,char k[] , int i ,int j);
int main(void) {
	char s[50] , k[50];
	printf("Enter a sentence: ");
	fflush(stdin);
	fflush(stdout);
	gets(s);
	int j=0 , i= (strlen(s)-1);
	reverse(s,k,i,j);
}
void reverse(char s[] ,char k[] , int i ,int j){
		k[j] =s[i];
		i--;
		j++;
		if (i>=0){
			reverse(s,k,i,j);
		}
		else{
			k[j] ='\0';
		printf("%s" , k);
		}
}
