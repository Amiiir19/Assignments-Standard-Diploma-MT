/*
 ============================================================================
 Name        : Q_8.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : Write a program that computes the nth term of the geometric
				series:
				1, 3, 9, 27, …
Run the program to compute the 10th term of the given series.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num=0,sum=1;
	printf("Enter the term : ");
	scanf(" %d",&num);
	for(int i=0 ; i <(num-1); i++)
		sum*=3;
	printf(" %d",sum);

	return EXIT_SUCCESS;
}
