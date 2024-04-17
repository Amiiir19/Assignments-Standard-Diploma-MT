/*
 * main.c
 *
 *  Created on: Mar 3, 2024
 *      Author: amir
 */
#include <stdio.h>
#define PI 3.141592653589793
int main() {
	float radius = 0, circ = 0, area = 0;
	scanf(" %f", &radius);
	circ = 2 * radius * PI;
	area = radius * radius * PI;
	printf("Circumefernce = %0.2f  \nArea = %0.2f", circ, area);
	return 0;
}

