#include <stdio.h>
int main() {
	int base = 0;
	scanf(" %d", &base);
	int left_astric = 0;
	int right_astric = base - 1;
	for (int row = 0; row < base ; row++) {
		for (int column = 0; column < base ; column++) {
			if (column == left_astric || column == right_astric) {
				printf("* ");
			} else {
				printf(" ");
			}
		}
		left_astric++;
		right_astric--;
		printf("\n");
	}

	return 0;
}
