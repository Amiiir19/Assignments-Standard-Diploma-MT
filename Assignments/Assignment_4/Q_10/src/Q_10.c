/*
 ============================================================================
 Name        : Q_10.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a c function two SWAP two pointers.
 Hint: use pointer to pointer as a function argument.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void swapPointers(int **ptr, int **ptr2);

int main(void) {
	int x = 5, y = 6;
	int *ptr1 = &x;
	int *ptr2 = &y;
	printf("ptr1 points to address : %p , its value = %d\n", ptr1, *ptr1);
	printf("ptr2 points to address : %p , its value = %d\n", ptr2, *ptr2);
	swapPointers(&ptr1, &ptr2);
	printf("ptr1 points to address : %p , its value = %d\n", ptr1, *ptr1);
	printf("ptr2 points to address : %p , its value = %d\n", ptr2, *ptr2);

	return EXIT_SUCCESS;
}
void swapPointers(int **ptr, int **ptr2) {
	int *temp = *ptr;
	*ptr = *ptr2;
	*ptr2 = temp;
}
