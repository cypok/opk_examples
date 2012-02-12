#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>

/* Returns 1 if number is succesfully read else 0. */
int read_number(const char * request, int * num) {
    for (;;) {
        int res;
        printf("%s: ", request);

        res = scanf("%d", num);
        if (res == EOF) {
            return 0;
        } else if (res == 1) {
            return 1;
        } else if (res == 0) {
            // skip all line
            for (;;) {
                int ch = getchar();
                if (ch == EOF) {
                    return 0;
                } else if (ch == '\n') {
                    break;
                }
            }
        }
    }
}

int main(void) {
    int x;
    if (read_number("Enter number", &x)) {
        printf("Succesfully read %d\n", x);
    }
    return 0;
}

