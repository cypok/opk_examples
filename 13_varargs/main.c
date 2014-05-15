#include <stdio.h>
#include <assert.h>
#include <stdarg.h>
#include <string.h>

// variable arguments

int myprintf(char *format, ...) {
    int res;
    va_list args;
    va_start(args, format);

    {
        char *modified = (char*)malloc((strlen("Yo-yo! ") + strlen(format) + 1)*sizeof(char));
        assert(modified != NULL);
        *modified = '\0';
        strcat(modified, "Yo-yo! ");
        strcat(modified, format);
printf
        res = vprintf(modified, args);
        free(modified);
    }
    
    va_end(args);
    return res;
}

void reverse(int size, int *arr) {
    int i;
    for (i = 0; i < size/2; ++i) {
        int tmp = arr[size - i - 1];
        arr[size - i - 1] = arr[i];
        arr[i] = tmp;
    }
}

void check(int size, int *arr1, int *arr2) {
    int i;
    for (i = 0; i < size; ++i) {
        assert(arr1[i] == arr2[i]);
    }
}

void check_smart(int size, .../* 2*size args */) {
    int i;
    int *actual = (int*)malloc(size * sizeof(int));
    int *expected = (int*)malloc(size * sizeof(int));

    va_list args;
    va_start(args, size);

    assert(actual != NULL && expected != NULL);

    for (i = 0; i < size; ++i) {
        int arg = va_arg(args, int);
        actual[i] = arg;
    }

    for (i = 0; i < size; ++i) {
        int arg = va_arg(args, int);
        expected[i] = arg;
    }

    reverse(size, actual);
    check(size, expected, actual);

    va_end(args);
    free(actual);
    free(expected);
}

void pairs(int count, .../* pairs (int, char*) */) {
    int i;
    va_list args;
    va_start(args, count);

    for (i = 0; i < count; ++i) {
        double id = va_arg(args, double);
        char *name = va_arg(args, char*);
        myprintf("%g: %s\n", id, name);
    }

    va_end(args);
}

int main() {

    {
        int expected[] = {3, 2, 1};
        int arr[] = {1, 2, 3};
        int sz = 3;
        reverse(sz, arr);
        check(sz, expected, arr);
    }

    {
        int expected[] = {4, 3, 2, 1};
        int arr[] = {1, 2, 3, 4};
        int sz = 4;
        reverse(sz, arr);
        check(sz, expected, arr);
    }

    check_smart(0
                );

    check_smart(1,
                37,
                37);

    check_smart(2,
                1, 2,
                2, 1);

    check_smart(3,
                1, 2, 3,
                3, 2, 1);

    check_smart(4,
                1, 2, 3, 4,
                4, 3, 2, 1);

    pairs(3,
          37.0, "Ivan",
          42.5, "John",
          666.0, "Anna");

    pairs(3,
          37.0, "Ivan",
          42.0, "John",
          666.0, "Anna");

    myprintf("%d + %d = %d\n", 2, 2, 4);

    return 0;
}
