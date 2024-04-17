/*
 ============================================================================
 Name        : Question_1.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C Function that prints the cube of any number.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int cube(int num);
int main(void) {
	int num = 0, result = 0;

	scanf(" %d", &num);
	result = cube(num);

	printf("the cube of %d equals %d \n", num, result);
	return EXIT_SUCCESS;

}
int cube(int num) {
	return num * num * num;
}
