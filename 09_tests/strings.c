bool check_strtrim_one(char *original, char *expected) {
    char *str = _strdup(original);
    strtrim(str);
    return (strcmp(expected, str) == 0);
}

void test_strtrim() {
    assert(check_strtrim_one(" a b c  ", "~a~b~c~~"));
    assert(check_strtrim_one("abc", "abc"));
    assert(check_strtrim_one("   abc", "~~~ac"));
}
