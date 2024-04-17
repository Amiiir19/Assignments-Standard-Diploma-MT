#include <stdio.h>
int main() {
	int base = 0;
	scanf(" %d", &base);
	int height = (base + 1) / 2;
	int center = (base - 1) / 2;
	int centerhigh = center;
	int centerlow = center;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < base; j++) {
			if (j <= centerhigh && j >= centerlow) {
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
		centerhigh++;
		centerlow--;
	}

	return 0;
}
