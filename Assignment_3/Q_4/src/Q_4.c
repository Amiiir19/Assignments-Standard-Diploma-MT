/*
 ============================================================================
 Name        : Q_4.c
 Author      : Amir
 Description : selection sorting algorithm
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void selectionSort(int size, int *arr);
int main(void) {
	int arr[6] = { 5, 2, 4, 3, 8, 1 };
	selectionSort(6, arr);
	for (int i = 0; i < 6; i++) {
		printf("%d ", *(arr + i));
	}

	return EXIT_SUCCESS;
}
void selectionSort(int size, int *arr) {
	for (int i = 0; i < size; i++) {
		int min_index = i;
		for (int j = i + 1; j < size; j++) {
			if (*(arr + min_index) > *(arr + j)) {
				min_index = j;
			}
		}
		if (min_index != i) {
			*(arr + i) = *(arr + min_index) ^ *(arr + i);
			*(arr + min_index) = *(arr + min_index) ^ *(arr + i);
			*(arr + i) = *(arr + min_index) ^ *(arr + i);
		}
	}

}

