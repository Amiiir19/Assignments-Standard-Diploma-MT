/*
 ============================================================================
 Name        : Q_11.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a c program that SWAP the value of the two 16-
 bits of 32-bits integer number.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x = 1;
	printf(" X = %d\n",x);
	short *ptr = &x;
	short temp = *ptr;
	*ptr = *(ptr + 1);
	*(ptr+1)=temp;
	printf(" X = %d",x);
	return EXIT_SUCCESS;
}
