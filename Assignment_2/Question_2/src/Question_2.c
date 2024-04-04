/*
 ============================================================================
 Name        : Question_2.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a C Function that takes one character and checks if it alphabet
or not.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

bool check(char mychar);

int main(void) {
	char c;
	scanf(" %c", &c);
	if (check(c)) {
		printf("Alpha\n");
	} else {
		printf("Not Alpha\n");
	}
	return EXIT_SUCCESS;
}

bool check(char mychar) {
	return ((mychar >= 65 && mychar <= 91) || (mychar >= 97 && mychar <= 122));
}
