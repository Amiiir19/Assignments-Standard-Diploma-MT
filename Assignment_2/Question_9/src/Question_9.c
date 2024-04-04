/*
 ============================================================================
 Name        : Question_9.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C Function that swaps the value of two integer numbers.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void swap(int *num1, int *num2);
int main(void) {
	int x = 1, y = 2;
	printf("Before swap -- x = %d , y = %d \n", x, y);
	swap(&x, &y);
	printf("After swap -- x = %d , y = %d \n", x, y);

	return EXIT_SUCCESS;
}
void swap(int *num1, int *num2) {
	*num1 = *num2 ^ *num1;
	*num2 = *num2 ^ *num1;
	*num1 = *num2 ^ *num1;
}
