/*
 ============================================================================
 Name        : Q_6.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to print all the array elements and the
 maximum number in array using array of pointers.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[5] = { 1, 2, 3, 4, 5 };
	int *ptrarr[5];
	for (int i = 0; i < 5; i++) {
		ptrarr[i] = arr + i;
	}
	int max = *ptrarr[0];
	for (int i = 0; i < 5; i++) {
		if (max < *ptrarr[i]) {
			max = *ptrarr[i];
		}
	}
	printf("Maximum = %d\nArray : ", max);
	for (int i = 0; i < 5; i++) {
		printf("%d ", *(*(ptrarr + i)));
		//printf("%d ", *ptrarr[i]);
	}
	return 0;
}
