#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

// Parantheses are required! Try to remove them.
#define MUL(a, b) ((a) * (b))


#define LOG_VAR(var, fmt) fprintf(stderr, "LOG: %s = " fmt "\n", #var, var)


#define DECLARE_POINT(name) \
        int name##_x; \
        int name##_y; \

#define PRINT_POINT(name) \
        printf("%s: %dx%d\n", #name, GET_X(name), GET_Y(name)) \

#define GET_X(name) name##_x
#define GET_Y(name) name##_y

#define SET_X(name, value) name##_x = (value)
#define SET_Y(name, value) name##_y = (value)


// Do while is require! Try to remove it.
#define TWICE(smth) do { smth; smth; } while (0)


// Tests can be turned on/off by this define. Try to remove it.
#define TESTS_ENABLE
#include "tests.h"


// Try to uncomment this. :)
//#include "bad.h"

static double sqr(double x) {
    return x*x;
}

int main(int argc, char *argv[]) {
    int foo = 123;
    double bar = 3.14;
    char *baz = "Baaaz!";

    //////////// simple macros

    printf("(2+3)*(4+5) = %d\n", MUL(2+3, 4+5));

    double max = MAX(foo, bar);
    printf("max(%d, %g) = %g\n", foo, bar, max);

    //////////// nice logging, use of #

    LOG_VAR(foo, "%d");
    LOG_VAR(bar, "%g");
    LOG_VAR(baz, "%s");

    LOG_VAR(max, "%g");
    LOG_VAR(MAX(foo, bar), "%g");
    LOG_VAR(sqr(bar), "%g");

    //////////// custom data structures, use of ##

    DECLARE_POINT(car);

    SET_X(car, 37);
    SET_Y(car, 42);

    PRINT_POINT(car);

    printf("max coordinate: %d\n", MAX(GET_X(car), GET_Y(car)));

    //////////// function like macros, use of do {} while (0)

    TWICE(printf("Hello world!\n"));

    // note that there is no braces
    if (argc < 3)
        TWICE(printf("Boring...\n"));
    else
        TWICE(printf("Wow, such args!\n"));

    //////////// complex macros

    CHECK_INT(4, 2*2);
    CHECK_INT(100, 200/2);

    CHECK_INT(5, 2+2);
    CHECK_INT(3, 2+2);

    return 0;
}
