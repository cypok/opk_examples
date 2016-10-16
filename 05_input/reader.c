#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Input primitive value from standart input line. */
bool read_value(const char *request, const char *fmt, void *value) {
    for (;;) {
        if (request != NULL) {
            printf("%s: ", request);
        }
        int res = scanf(fmt, value);
        if (res == EOF) {
            // end of input
            return false;
        }
        // unconditionally skip everything until the end of line
        for (;;) {
            int ch = getchar();
            if (ch == EOF || ch == '\n') {
                break;
            }
        }
        if (res == 1) {
            return true;
        }
    }
}

/* Input non-empty string line from standart input.
 * Does not include '\n' character in the end. */
char * read_line(const char * request) {
    size_t str_len = 0;
    size_t buf_size = 16; // some initial size
    char *buf = malloc(buf_size * sizeof(char));
    if (buf == NULL) {
        return NULL;
    }

    if (request != NULL) {
        printf("%s: ", request);
    }

    for (;;) {
        // read next part
        if (fgets(buf + str_len, buf_size - str_len, stdin) == NULL) {
            if (feof(stdin) && str_len > 0) {
                // read all given input
                break;
            } else {
                // no input at all or some error
                free(buf);
                return NULL;
            }
        }

        size_t added_len = strlen(buf + str_len);
        str_len += added_len;
        assert(str_len + 1 <= buf_size);
        assert(buf[str_len] == '\0');

        // check if we finished with reading
        if ((str_len + 1 < buf_size) ||     // read less than maximum
            (buf[str_len - 1] == '\n')) {   // read '\n' as last character
            break;
        }

        // otherwise resize buffer for reading next part
        size_t new_buf_size = buf_size * 2;
        char *new_buf = realloc(buf, new_buf_size);
        if (new_buf == NULL) {
            free(buf);
            return NULL;
        }
        buf_size = new_buf_size;
        buf = new_buf;
    }

    assert(str_len > 0);

    // trim trailing '\n' if any
    if (buf[str_len - 1] == '\n') {
        buf[str_len - 1] = '\0';
    }

    // cut buffer to actual length
    char *result = realloc(buf, str_len + 1);
    if (result == NULL) {
        free(buf);
        return NULL;
    }
    return result;
}

int main(void) {
    int n;
    if (!read_value("Enter number", "%d", &n)) {
        fprintf(stderr, "ERROR: cannot read input\n");
        return 1;
    }
    printf("Succesfully read %d\n", n);

    double x;
    if (!read_value("Enter another double", "%lg", &x)) {
        fprintf(stderr, "ERROR: cannot read input\n");
        return 1;
    }
    printf("Yeah! %g\n", x);

    char *str = read_line("Enter string");
    if (str == NULL) {
        fprintf(stderr, "ERROR: cannot read input\n");
        return 1;
    }
    printf("Entered: <%s>\n", str);
    free(str);

    return 0;
}

