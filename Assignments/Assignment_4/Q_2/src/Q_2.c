/*
 ============================================================================
 Name        : Q_2.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to find length of a given string using pointer.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char str[50];
	//only one word without spaces
	scanf(" %s",str);
	char *ptr;
	ptr = str;
	int count = 0;
	while (*ptr != '\0') {
		count++;
		ptr++;
	}
	printf("Count = %d ",count);
	return 0;
}
