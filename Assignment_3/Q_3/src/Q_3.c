/*
 ============================================================================
 Name        : Q_3.c
 Author      : Amir
 Description : Write a C function that use the bubble sort algorithm to sort
 an integer array in ascending order (search for the bubble sorting
 algorithm).
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bubbleSort(int size, int *arr);
int main(void) {
	int arr[6] = { 5, 2, 4, 3, 8, 1 };
	bubbleSort(6, arr);
	for (int i = 0; i < 6; i++) {
		printf("%d ", *(arr + i));
	}

	return EXIT_SUCCESS;
}
void bubbleSort(int size, int *arr) {
	//FIRST LOOP is just for repeat steps
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (*(arr + j) > *(arr + j + 1)) {
				//SWAPPING
				*(arr + j) = *(arr + j + 1) ^ *(arr + j);
				*(arr + j + 1) = *(arr + j + 1) ^ *(arr + j);
				*(arr + j) = *(arr + j + 1) ^ *(arr + j);
			}
		}
	}

}
