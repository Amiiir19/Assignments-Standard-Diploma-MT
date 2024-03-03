#include <stdio.h>
int main() {
int height = 0;
	scanf(" %d", &height);
	int width = 0;
	for (int i = 0; i < height; i++) {
		width++;
		for (int j = 0; j < width; j++) {
			printf("* ");
		}
		printf("\n");
	}

	return 0;
}

