/*
 ============================================================================
 Name        : Question_5.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C function to check if the input is an even number or
 an odd number, if even number return 0 if odd number return 1.
 Example:
 Input 7, Output = 1 (Odd)
 Input 6, Output = 0 (Even)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int checkoddnum(int num);
int main(void) {
	int num;
	scanf(" %d", &num);
	if (checkoddnum(num)) {
		printf("It is Odd Number");
	} else {
		printf("It is Even Number");
	}
	return EXIT_SUCCESS;
}
int checkoddnum(int num) {
	return num % 2;
}
