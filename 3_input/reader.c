#include <stdio.h>
#include <assert.h>

int read_number(const char * request) {
    for (;;) {
        int num;
        int res;

        printf("%s: ", request);
        res = scanf("%d", &num);
        if (res == 1) {
            return num;
        } else {
            assert(res == 0);
            int ch;
            do {
                ch = getchar();
                assert(ch != EOF);
            } while (ch != '\n');
        }
    }
}

int main() {
    int x = read_number("Enter number");
    printf("Succesfully read %d\n", x);
    return 0;
}

