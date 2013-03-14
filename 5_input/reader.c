#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

/* Skip all remaining line. */
static void skip_garbage() {
    int ch;
    do {
        ch = getchar();
        assert(ch != EOF);
    } while (ch != '\n');
}

/* Input integer number from standart input. */
int read_int(const char * request) {
    for (;;) {
        int res;
        int num;

        printf("%s: ", request);
        res = scanf("%d", &num);
        assert(res != EOF);
        skip_garbage();
        if (res == 1) {
            return num;
        }
    }
}

/* Input double number from standart input. */
double read_double(const char * request) {
    for (;;) {
        int res;
        double num;

        printf("%s: ", request);
        res = scanf("%lg", &num);
        assert(res != EOF);
        skip_garbage();
        if (res == 1) {
            return num;
        }
    }
}

/* Input non-empty string from standart input.
 * Does not include '\n' character in the end. */
char * read_string(const char * request) {
#define MAX_STR_LEN 128
    for (;;) {
        char buf[MAX_STR_LEN + 1];

        printf("%s: ", request);
        if (fgets(buf, MAX_STR_LEN + 1, stdin) != NULL) {
            int len = strlen(buf);
            if (len == MAX_STR_LEN && buf[len - 1] != '\n') {
                skip_garbage();
            } else if (buf[len - 1] == '\n') {
                buf[len - 1] = '\0';
            }
            if (strlen(buf) == 0) {
                continue;
            }
            return strdup(buf);
        } else {
            return NULL;
        }
    }
#undef MAX_STR_LEN
}

int main(void) {
    int n;
    double x;
    char *str;

    n = read_int("Enter number");
    printf("Succesfully read %d\n", n);

    x = read_double("Enter another double");
    printf("Yeah! %g\n", x);

    str = read_string("Enter string");
    printf("Entered: <%s>\n", str);
    free(str);

    return 0;
}

