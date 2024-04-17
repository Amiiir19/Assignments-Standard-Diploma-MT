#include <stdio.h>
#include <math.h>

int main() {
        int num1 = 0;
        scanf(" %d", &num1);
        int check=0;
        check = sqrt(num1);
        if ((check * check) == num1) {
                printf("It is Perfect Square \n");
        } else {
                printf("It is NOT Perfect Square \n");
        }
        return 0;
}

