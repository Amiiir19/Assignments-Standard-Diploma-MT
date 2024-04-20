/*
 ============================================================================
 Name        : Q_3.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : C function to add two complex numbers by passing
 two structure to a function and display the results.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct complex {
	int real;
	int img;
} complex;

complex addcomplex(complex *num1, complex *num2);

int main(void) {
	complex num1 = { 1, 2 };
	complex num2 = { 2, 3 };
	complex sum = addcomplex(&num1, &num2);
	printf("Num = %d + i%d ", sum.real, sum.img);
	return 0;
}
complex addcomplex(complex *num1, complex *num2) {
	complex sum;
	sum.real = num1->real + num2->real;
	sum.img = num1->img + num2->img;
	return sum;
}
