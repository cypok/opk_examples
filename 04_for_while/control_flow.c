#include <stdio.h>

int main(void) {

    printf("Numbers from 9 to 0:\n");
    for (int i = 9; i >= 0; i--) {
        printf("%d\n", i);
    }

    printf("Odd numbers from 0 to 9:\n");
    for (int i = 0; i < 10; i += 2) {
        printf("%d\n", i);
    }

    printf("Odd numbers from 0 to 9 not divided by 3:\n");
    for (int i = 0; i < 10; i++) {
        if ((i % 2 == 0) && (i % 3 != 0)) {
            printf("%d\n", i);
        }
    }

    int i;
    printf("Numbers from 0 to 9:\n");
    i = 0;
    while (i < 10) {
        printf("%d\n", i);
        i++;
    }

    printf("Numbers from 9 to 0:\n");
    i = 9;
    do {
        printf("%d\n", i);
        i--;
    } while (i >= 0);

    return 0;
}
