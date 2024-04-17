/*
 ============================================================================
 Name        : Q_4.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : C function to get the value of the smallest element in
 array using pointers.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int smallest(int *ptr);
int main(void) {
	int arr[5] = { 5, 4, 3, 8, 1 };
	int min = smallest(arr);
	printf("the smallest is %d ", min);
	return EXIT_SUCCESS;
}
int smallest(int *ptr) {
	int min = *ptr;
	for (int i = 0; i < 5; i++) {
		if (min > *(ptr + i)) {
			min = *(ptr + i);
		}
	}
	return min;
}
