#include "reader.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>

static void skip_garbage() {
    int ch;
    do {
        ch = getchar();
        assert(ch != EOF);
    } while (ch != '\n');
}

int read_int(const char * request) {
    for (;;) {
		int num, res;
        printf("%s: ", request);
        res = scanf("%d", &num);
        assert(res != EOF);
        skip_garbage();
        if (res == 1) {
            return num;
        }
    }
}

double read_double(const char * request) {
    for (;;) {
		double num;
		int res;
        printf("%s: ", request);
        res = scanf("%lg", &num);
        assert(res != EOF);
        skip_garbage();
        if (res == 1) {
            return num;
        }
    }
}

char * read_string(const char * request) {
#define MAX_STR_LEN 128
    for (;;) {
        char buf[MAX_STR_LEN + 1];

        printf("%s: ", request);
        if (fgets(buf, MAX_STR_LEN + 1, stdin) != NULL) {
            int len = strlen(buf);
            if (len == MAX_STR_LEN && buf[len - 1] != '\n') {
                skip_garbage();
            } else if (len > 0) {
                if (buf[len - 1] == '\n') {
                    buf[len - 1] = '\0';
                }
                if (len > 1) {
                    return strdup(buf);
                }
            }
        } else {
            return NULL;
        }
    }
#undef MAX_STR_LEN
}
