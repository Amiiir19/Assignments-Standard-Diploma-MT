/*
 ============================================================================
 Name        : Q_1.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to compute sum of the array elements using pointers.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[4] = { 1, 2, 3, 4 };
	int *ptr;
	ptr = arr;
	for (int i = 0; i < 4; i++) {
		//printf("%d ", *(arr + i));
		printf("%d ", *(ptr + i));
	}

	return 0;
}
