/*
 ============================================================================
 Name        : Q_20.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function to return an array containing the values
 between two 8-bits unsigned integers IN DESCENDING ORDER
 EXCLUSIVE. The function takes 2 values (LowerValue and
 UpperValue), it shall determine the values in between, and then
 arrange the sequence in descending order excluding the upper
 and lower values.
 If the LowerValue is greater than or equal the UpperValue, return
 an array of 2 elements, both containing value = 0xFF
 Example:
 Input: LowerValue=2 and UpperValue=5
 Output:
 Output Array=4,3
 Output Array Size=2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int globalArray[100];
int* func(int lower, int higher);

int main(void) {

	unsigned int x = 0, y = 0;
	scanf(" %d %d", &x, &y);
	int *ptr;
	ptr = func(x, y);
	for (int i = 0; i < (y - x - 1); i++) {
		printf("%d ", *(ptr + i));
	}
	return 0;
}

int* func(int lower, int higher) {
	if (lower >= higher) {
		globalArray[0] = 0xff;
		globalArray[1] = 0xff;
		return globalArray;
	} else {
		for (int i = 0; i < (higher - lower); i++) {
			globalArray[i] = higher - i - 1;
		}
		return globalArray;
	}
}
