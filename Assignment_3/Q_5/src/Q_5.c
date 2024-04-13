/*
 ============================================================================
 Name        : Q_5.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function to return the index of FIRST occurrence of a
 number in a given array. Array index start from 0. If the item is not
 in the list return -1. (Linear Search Algorithm)
 Example:
 Array = {1,2,3,4,4,4}
 The required number is 4 it should return 3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int linearSearch(int size, int *arr, int num);
int main(void) {
	int arr[6] = { 1, 2, 3, 4, 4, 4 };
	int result = linearSearch(6, arr, 4);
	printf("result = %d", result);
	return EXIT_SUCCESS;
}
int linearSearch(int size, int *arr, int num) {
	for (int i = 0; i < size; i++) {
		if (*(arr + i) == num) {
			return i;
		}
	}
	return -1;
}
