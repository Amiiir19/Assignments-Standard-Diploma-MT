#include <stdio.h>
int main() {
	int num1 = 0;
	scanf(" %d", &num1);
	if (num1 > 100 || num1 < 0) {
		printf("Error > Wrong Entry \n");
	} else if (num1 >= 85) {
		printf("Excellent \n");
	} else if (num1 >= 75) {
		printf("Very Good \n");
	} else if (num1 >= 65) {
		printf("Good \n");
	} else if (num1 >= 50) {
		printf("Fair \n");
	} else {
		printf("Fail \n");
	}

	return 0;
}

