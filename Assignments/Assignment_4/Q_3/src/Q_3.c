/*
 ============================================================================
 Name        : Q_3.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to read 10 integers into an array from user
 and print them in reversing order using pointers.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[10];
	int *ptr;
	ptr = arr;
	for (int i = 0; i < 10; i++) {
		scanf(" %d", &arr[i]);
	}
	for (int i = 9; i >= 0; i--) {
		printf(" %d", *(ptr+i));
	}

	return 0;
}
