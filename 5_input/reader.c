#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <assert.h>

/* Input integer number from standart input. */
int read_number(const char * request) {
    for (;;) {
        int res;
        int num;

        printf("%s: ", request);
        res = scanf("%d", &num);

        assert(res != EOF);
        if (res == 1) {
            return num;
        } else {
            // skip all line
            int ch;
            assert(res == 0);
            do {
                ch = getchar();
                assert(ch != EOF);
            } while (ch != '\n');
        }
    }
}

int main(void) {
    int x = read_number("Enter number");
    printf("Succesfully read %d\n", x);
    return 0;
}

