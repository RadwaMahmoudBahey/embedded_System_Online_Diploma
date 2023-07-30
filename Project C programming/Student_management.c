/*
 ============================================================================
 Name        : Student_management.c
 Author      : Radwa Mahmoud
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "S_management.h"

#include <stdio.h>
#include <stdlib.h>


int main(void) {
	FIFO_T fifo;
	FIFO_INIT(&fifo , buffer , width);
	char temp[10];
	printf("\n===================FIFO INITIALIZED==================\n");
	while(1){
		printf("Welcome to the Student Management System:\n");
		printf("Choose the task that you want to perform:\n");
		printf("\n 1. Add Student Details Manually.");
		printf("\n 2. Add Student Details From File.");
		printf("\n 3. Find the student by the given Roll Number.");
		printf("\n 4. Find the student by the given First Name.");
		printf("\n 5. Find the students registered in a course ID.");
		printf("\n 6. Find the Total Number of Students");
		printf("\n 7. Delete the Student Details by Roll Number.");
		printf("\n 8. Update the Student Details by Roll Number.");
		printf("\n 9. Show all Information.");
		printf("\n 10.To Exit.\n");
		printf("Enter your choice to perform the task:\n");
		get(temp);
		switch(atoi(temp)){
		case 1:
			Add_Student_Manually(&fifo);
			break;
		case 2:
			Add_Student_From_File(&fifo);
			break;
		case 3:
			Find_The_Student_By_Roll_Number(&fifo);
			break;
		case 4:
			Find_The_Student_By_First_Name(&fifo);
			break;
		case 5:
			Find_The_Students_Registered_In_Course(&fifo);
			break;
		case 6:
			Students_Count(&fifo);
			break;
		case 7:
			Delete_A_Student(&fifo);
			break;
		case 8:
			Update_Student(&fifo);
			break;
		case 9:
			Show_Information(&fifo);
			break;
		case 10:
			return 0;
			break;
		default:
			printf("ERROR, Wrong choice!!\n");
			break;
		}
	}


	return 0;
}
