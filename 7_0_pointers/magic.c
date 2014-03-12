#include <stdio.h>

void basic() {
    int x = 11;
    int y = 22;
    int *px = &x;

    printf("x = %d, y = %d, px = %p, *px = %d\n", x, y, px, *px);
    *px = 33;
    printf("x = %d, y = %d, px = %p, *px = %d\n", x, y, px, *px);
    px = &y;
    printf("x = %d, y = %d, px = %p, *px = %d\n", x, y, px, *px);
    *px = 44;
    printf("x = %d, y = %d, px = %p, *px = %d\n", x, y, px, *px);
}

// Using pointers you can return more than one value
// as a function result
void div_rem(int a, int b, int *div, int *rem) {
    *div = a / b;
    *rem = a % b;
}

void div_rem_sample() {
    int a = 123;
    int b = 10;
    int div, rem;
    div_rem(a, b, &div, &rem);
    printf("%d = %d * %d + %d\n", a, b, div, rem);
}

void arrays_as_pointers() {
    short arr[] = {1, 2, 3, 4, 5, 6};
    size_t size = sizeof(arr)/sizeof(arr[0]);

    // arr is just a pointer to short
    // may be considered as: short *arr

    for (int i = 0; i < size; i++) {
        // equivalent to arr[i]
        short elem = *(arr + i);
        printf("%d ", elem);
    }
    printf("\n");
}

char * str_shift(char *str) {
    if (*str == '\0') {
        return str;
    } else {
        return str + 1;
    }
}

void strings_sample() {
    char *str = "Hello world!";
    char *p = str;
    while (*p != '\0') {
        printf("<%s>\n", p);
        p = str_shift(p);
    }
}


int main(void) {
    basic();
    div_rem_sample();
    arrays_as_pointers();
    strings_sample();

    return 0;
}
