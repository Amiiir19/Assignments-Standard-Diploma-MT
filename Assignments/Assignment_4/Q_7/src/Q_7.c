/*
 ============================================================================
 Name        : Q_7.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : C function to swap two numbers using bitwise
 operation and call it using pointer to function.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void swapfunc(int *num1, int *num2);
int main(void) {
	int x = 1, y = 2;
	void (*ptrfunc)(int*, int*);
	ptrfunc = &swapfunc;
	ptrfunc(&x, &y);
	printf("x = %d   y = %d \n", x, y);
	return 0;
}
void swapfunc(int *num1, int *num2) {
	*num1 = *num2 ^ *num1;
	*num2 = *num2 ^ *num1;
	*num1 = *num2 ^ *num1;
}
