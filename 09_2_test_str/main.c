#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

// Replaces all spaces by underscore ('_').
void str_no_spaces(char *str) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (isspace(str[i])) {
            str[i] = '_';
        }
    }
}

bool check_str(const char *expected, const char *original) {
    char *str = strdup(original);
    str_no_spaces(str);
    bool res = (strcmp(str, expected) == 0);
    free(str);
    return res;
}

void test_str_no_spaces() {
    assert(check_str("", ""));
    assert(check_str("abc", "abc"));
    assert(check_str("a_c", "a c"));
    assert(check_str("a__c", "a  c"));
    assert(check_str("a_c", "a\tc"));
    assert(check_str("_a_c_", " a\tc "));
}


int main() {
    test_str_no_spaces();
    return 0;
}
