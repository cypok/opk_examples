#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/* Returns true if number is succesfully read else false. */
bool read_number(const char * request, int * num) {
    for (;;) {
        printf("%s: ", request);

        // C99
        int res = scanf("%d", num);
        if (res == EOF) {
            return false;
        } else if (res == 1) {
            return true;
        } else if (res == 0) {
            // skip all line
            for (;;) {
                int ch = getchar();
                if (ch == EOF) {
                    return false;
                } else if (ch == '\n') {
                    break;
                }
            }
        }
    }
}

int main() {
    int x;
    if (read_number("Enter number", &x)) {
        printf("Succesfully read %d\n", x);
    }
    return 0;
}

