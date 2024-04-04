/*
 ============================================================================
 Name        : Question_20.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function to count the maximum number of consecutive 1’s
 in an unsigned 16 bits integer.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int countMaxConsOnes(unsigned short num);
int main(void) {
	int result = 0;
	unsigned short num = 0;
	scanf("%d", &num);
	result = countMaxConsOnes(num);
	printf("result = %d", result);
	return EXIT_SUCCESS;
}
int countMaxConsOnes(unsigned short num) {
	unsigned short mask = 1;
	mask <<= 15;
	int count = 0;
	int max = 0;
	for (int i = 0; i <= 15; i++) {
		if (mask & num << i) {
			count++;
			max=count;
		} else {
			max = count;
			count = 0;
		}
	}
	return max;
}
