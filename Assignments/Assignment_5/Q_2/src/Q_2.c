/*
 ============================================================================
 Name        : Q_2.c
 Author      : Amir
 Version     :
 Copyright   : Your copyright notice
 Description : C Program to add two distances (inch-feet) using
 structure and display the result.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct distance {
	int feet;
	int inch;
};

int main(void) {

	struct distance dist = { 10, 11 };
	struct distance dist2 = { 15, 6 };
	struct distance distsum;
	distsum.feet = dist.feet + dist2.feet;
	distsum.inch = dist.inch + dist2.inch;
	while (distsum.inch > 11) {
		distsum.feet++;
		distsum.inch -= 12;
	}
	printf("distance = %d  feet  and %d  inch \n", distsum.feet, distsum.inch);
	return 0;
}
