/*
 ============================================================================
 Name        : Question_15.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function to count the number of
 1’s in an unsigned 32-bit integer.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int countBitsOnes(unsigned int num);
int main(void) {
	unsigned int num = 0;
	scanf(" %d", &num);
	int result = countBitsOnes(num);
	printf("result equal = %d", result);
	return EXIT_SUCCESS;
}
int countBitsOnes(unsigned int num) {
	int count = 0;
	unsigned int mask = 1;
	mask <<= 31;
	for (int i = 0; i <= 31; i++) {
		if (mask & num << i) {
			count++;
		}
	}
	return count;

}
