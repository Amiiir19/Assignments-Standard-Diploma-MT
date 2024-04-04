/*
 ============================================================================
 Name        : Question_7.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C Function that reads two integers and checks if the
 first is multiple of the second.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
bool checkMultiple(int num1, int num2);
int main(void) {
	int num1 = 0, num2 = 0;
	scanf(" %d", &num1);
	scanf(" %d", &num2);
	if (checkMultiple(num1, num2)) {
		printf("They are Multiple");
	} else {
		printf("They are not a Multiple");
	}
	return EXIT_SUCCESS;
}
bool checkMultiple(int num1, int num2) {
	return !(num2 % num1);
}
