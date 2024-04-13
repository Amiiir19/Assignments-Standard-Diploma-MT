/*
 ============================================================================
 Name        : Q_2.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a function which, given a string, return TRUE if all
 characters are distinct and FALSE if any character is repeated.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int duplicate(int size, char *arr);
int main(void) {
	char str[100];
	scanf(" %s", str);
	int result = duplicate(strlen(str), str);
	printf("result = %d\n", result);
	return EXIT_SUCCESS;
}
int duplicate(int size, char *arr) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			//remember the *
			if (*(arr + i) == *(arr + j)) {
				return 0;
			}
		}
	}
	return 1;
}
