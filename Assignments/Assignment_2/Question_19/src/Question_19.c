/*
 ============================================================================
 Name        : Question_19.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function that return 0 if a given number is a power of 3,
 otherwise return 1 (except 3 to the power of 0).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int checkpowerof3(int num);
int main(void) {
	int num = 0;
	scanf(" %d", &num);
	if (!checkpowerof3(num)) {
		printf("IS POWER");
	} else {
		printf("IS NOT POWER");
	}
	return EXIT_SUCCESS;
}
int checkpowerof3(int num) {
	if (!(num % 3) && num != 3) {
		return checkpowerof3(num / 3);
	} else if (num == 3) {
		return 0;
	} else {
		return 1;
	}
}
