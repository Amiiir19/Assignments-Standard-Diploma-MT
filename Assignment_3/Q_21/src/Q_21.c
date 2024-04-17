/*
 ============================================================================
 Name        : Q_21.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function to return an array containing the values
			between two 8-bits unsigned integers IN DESCENDING ORDER
			INCLUSIZE. The function takes 2 values (LowerValue and
			UpperValue), it shall determine the values in between, and then
			arrange the sequence in descending order including the upper
			and lower values.
			If the LowerValue is greater than the UpperValue, return an array
			of 2 elements, both containing value = 0xFF
Example:
Input: LowerValue=2 and UpperValue=5
Output:
Output Array=5,4,3,2
Output Array Size=4
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
	int size = y-x+1;
	if (x>=y)
		size=2;
	for (int i = 0; i < size ; i++) {
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
		for (int i = higher; i >= lower; i--) {
			globalArray[higher-i] =  i;
		}
		return globalArray;
	}
}
