/*
 ============================================================================
 Name        : Q_1.c
 Author      : Amir
 Description : The sum of an array is the sum of its individual elements. For
 example, if an array is numbers = {1, 2, 3, 4}, the sum of the array
 is 1+2+3+4 = 10.
 Function Description: Complete the function summation. The
 function must return the integer sum of the numbers array.
 int summation(int numbers_size, int* numbers)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int summation(int numbers_size, int *numbers);

int main(void) {
	int arr[5] = { 1, 2, 3, 4, 5 };
	int result = summation(5, arr);
	printf("result = %d", result);
	return EXIT_SUCCESS;
}
int summation(int numbers_size, int *numbers) {
	int sum = 0;
	for (int i = 0; i < numbers_size; i++) {
		sum += *numbers + i;
	}
	return sum;
}
