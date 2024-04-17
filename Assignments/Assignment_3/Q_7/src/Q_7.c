/*
 ============================================================================
 Name        : Q_7.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a program that computes the nth term of the arithmetic
               series:
               1, 3, 5, 7, 9, …
               Run the program to compute the 100th term of the given series.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int main(void) {

	int num=0;
	printf("Enter the term : ");
	scanf("%d",&num);
	printf(" %d\n",1+(2*(num-1)));

	return EXIT_SUCCESS;
}
