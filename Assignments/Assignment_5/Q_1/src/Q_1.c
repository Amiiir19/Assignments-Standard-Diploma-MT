/*
 ============================================================================
 Name        : Q_1.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to store information (name, roll and
				marks) for a student using structure and display it.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
	char name[20];
	int roll;
	int marks;
};
int main(void) {
	struct student amir;
	strcpy(amir.name,"amir");
	amir.roll=5;
	amir.marks=97;
	printf("Name: %s\n",amir.name);
	printf("Roll: %d\n",amir.roll);
	printf("Marks: %d\n",amir.marks);
	return 0;
}
