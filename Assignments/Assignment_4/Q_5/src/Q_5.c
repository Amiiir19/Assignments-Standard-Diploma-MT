/*
 ============================================================================
 Name        : Q_5.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : C function to copy all elements of an array into another
 array using pointers. The two arrays have the same length
 and types.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 5

void copyArrays(int *ptr1, int *ptr2);
int main(void) {
	int arr1[ARR_SIZE] = { 1, 2, 3, 4, 5 };
	int arr2[ARR_SIZE];
	printf("Before copy\n");
	printf(" arr1 : ");
	for (int i = 0; i < ARR_SIZE; i++) {
		printf(" %d ", arr1[i]);
	}
	printf("\n arr2 : ");
	for (int i = 0; i < ARR_SIZE; i++) {
		printf(" %d ", arr2[i]);
	}
	copyArrays(arr1, arr2);
	printf("\nAfter copy\n");
	printf(" arr1 : ");
	for (int i = 0; i < ARR_SIZE; i++) {
		printf(" %d ", arr1[i]);
	}
	printf("\n arr2 : ");
	for (int i = 0; i < ARR_SIZE; i++) {
		printf(" %d ", arr2[i]);
	}
	return 0;
}
void copyArrays(int *ptr1, int *ptr2) {
	for (int i = 0; i < ARR_SIZE; i++) {
		*(ptr2 + i) = *(ptr1 + i);
	}
}
