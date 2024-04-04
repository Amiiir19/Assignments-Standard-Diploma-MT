/*
 ============================================================================
 Name        : Question_6.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write C Function that converts the any letter from lowercase to
 uppercase
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
char convertLowertoUpper(char c);
bool checkAlpha(char mychar);

int main(void) {
	char c;
	scanf("%c", &c);
	fflush(stdout);

	//first check if it is Alpha or not
	while (!checkAlpha(c)) {
		printf(" Not Alpha Letter Please Enter a Valid one: ");
		fflush(stdout);
		scanf("%c", &c);
	   // getchar();  // Consume the newline character from the input buffer

	}
	//Now convert
	c = convertLowertoUpper(c);
	printf("%c\n", c);

	return EXIT_SUCCESS;
}

char convertLowertoUpper(char c) {
	return c - 32;
}

bool checkAlpha(char mychar) {
	return ((mychar >= 65 && mychar <= 91) || (mychar >= 97 && mychar <= 122));
}
