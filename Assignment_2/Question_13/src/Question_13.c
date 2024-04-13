/*
 ============================================================================
 Name        : Question_13.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : In this challenge write a function to add two floating numbers.
 Determine the integer floor of the sum. The floor is the truncated float
 value, anything after the decimal point is dropped. For instance
 floor(1.1+3.05)=floor(4.15)=4
 ============================================================================
 */

#include <stdio.h>
//#include <stdlib.h>
#include <math.h>

float addFloats(float num1, float num2);
int main(void) {
	float num1, num2;
	int result = 0;
	scanf(" %f %f", &num1, &num2);
	//to use floor add to command   -lm
	//result = floor(addFloats(num1, num2));

	// other solution to pass a float to integar diretctly
	result = (int)addFloats(num1, num2);
	printf("Result = %d", result);
	return 0;
}
float addFloats(float num1, float num2) {
	return num1 + num2;
}
