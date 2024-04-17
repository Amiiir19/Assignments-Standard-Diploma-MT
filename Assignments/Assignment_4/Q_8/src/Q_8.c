/*
 ============================================================================
 Name        : Q_8.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function to swap the contents of two arrays
 with the same length using pointers.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 5
void swapArrays(int *ptr1, int *ptr2);
int main(void) {
	int arr1[ARR_SIZE] = { 1, 2, 3, 4, 5 };
	int arr2[ARR_SIZE] = { 6, 7, 8, 9, 10 };
	printf("Before copy\n");
		printf(" arr1 : ");
		for (int i = 0; i < ARR_SIZE; i++) {
			printf(" %d ", arr1[i]);
		}
		printf("\n arr2 : ");
		for (int i = 0; i < ARR_SIZE; i++) {
			printf(" %d ", arr2[i]);
		}
		swapArrays(arr1, arr2);
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
void swapArrays(int *ptr1, int *ptr2) {
	int temp = 0;
	for (int i = 0; i < ARR_SIZE; i++) {
		temp = *(ptr1 + i);
		*(ptr1 + i) = *(ptr2 + i);
		*(ptr2 + i) = temp;
	}
}
