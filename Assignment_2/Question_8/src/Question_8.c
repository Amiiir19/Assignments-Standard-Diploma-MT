/*
 ============================================================================
 Name        : Question_8.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C Function that display Prime Numbers between Intervals (two
 numbers) by Making Function.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void checkPrimeRange(int num1, int num2);
int main(void) {
	int num1 = 0, num2 = 0;
	scanf(" %d %d", &num1, &num2);
	checkPrimeRange(num1, num2);
	return EXIT_SUCCESS;
}
void checkPrimeRange(int num1, int num2) {
	int i = 0, flag = 0;
	if (num1 < 2) {
		num1 = 2;
	}
	for (i = num1; i <= num2; i++) {
		//check number i if prime or not >> if it is prime flag=1
		//divide by 2 because as example 6 / 4 will never be larger than 2
		for (int j = 2; j <= (i / 2); j++) {
			if (i % j == 0) {
				flag = 1;
			}
		}
		if (flag == 1) {
			flag = 0;
		} else {
			printf("%d ", i);
		}
	}
}
