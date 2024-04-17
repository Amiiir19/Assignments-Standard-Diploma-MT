/*
 ============================================================================
 Name        : Q_12.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Array that contains integer values, some of these
 values are repeated with an even number of repetitions,
 and only one value is repeated with an odd number of
 repetitions. Write a C function that’s take the array as
 input and the array size and return the number which has
 odd numbers of repetitions.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 7

int func(int *ptr, int size);
int main(void) {
	int arr[ARR_SIZE] = { 2, 2, 4, 6, 4, 1,1 };
	int num = func(arr, ARR_SIZE);
	printf(" the number is %d \n", num);
	return EXIT_SUCCESS;
}

int func(int *ptr, int size) {
	int arr[100] = { 0 };
	for (int i = 0; i < size; i++) {
		arr[*(ptr + i)]++;
	}
	for (int i = 0; i < 100; i++) {
		if ((arr[*(ptr + i)] % 2)) {
			return *(ptr + i);
		}
	}
}
