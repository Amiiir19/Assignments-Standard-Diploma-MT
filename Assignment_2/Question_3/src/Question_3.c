/*
 ============================================================================
 Name        : Question_3.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description :Write a C Function that check if the number if positive or negative.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkPostive(int num);
int main(void) {
	int num = 0;
	scanf(" %d", &num);
	if (checkPostive(num)) {
		printf("Positive");
	} else {
		printf("Negative");
	}
return EXIT_SUCCESS;
}
bool checkPostive(int num) {
return num >= 0;
}
