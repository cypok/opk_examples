#include <stdio.h>


#include "guarded.h"
#include "guarded.h"


// Try to uncomment this. :)
// #include "bad.h"


#include "tests.h"


static double sqr(double x) {
    printf("Long-long calculation of %g^2...\n", x);
    return x*x;
}


// Parantheses are required! Try to remove them.
#define MUL(a, b) ((a) * (b))

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static void simple_macros(int foo, double bar) {
    printf("(2+3)*(4+5) = %d\n", MUL(2+3, 4+5));

    double max = MAX(foo, bar);
    printf("max(%d, %g) = %g\n", foo, bar, max);
    double max2 = MAX(sqr(foo), sqr(bar));
    printf("max^2 = %g\n", max2);
}

#undef MAX


static void statement_like(int foo) {

// Do while is required! Try to remove it.
#define TWICE(smth) do { smth; smth; } while (0)

    TWICE(printf("Hello world!\n"));

    // note that there is no braces
    if (foo == 37)
        TWICE(printf("Boring...\n"));
    else
        TWICE(printf("Wow, such args!\n"));

#undef TWICE

}


void tests() {
    CHECK_INT(4, 2*2);
    CHECK_INT(100, 200/2);

    CHECK_INT(5, 2+2);
    CHECK_INT(3, 2+2);
}


#ifndef NDEBUG
#define LOG_VAR(var, fmt) fprintf(stderr, "LOG: %s = " fmt "\n", #var, var)
#define DBG_PRINT(fmt, ...) fprintf(stderr, "DEBUG @ %s(%u): " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
#define LOG_VAR(var, fmt) do {} while (0)
#define DBG_PRINT(fmt, ...) do {} while (0)
#endif

void logging(int foo, double bar, char *baz) {
    LOG_VAR(foo, "%d");
    LOG_VAR(bar, "%g");
    LOG_VAR(baz, "%s");

    LOG_VAR(MUL(foo, bar), "%g");
    LOG_VAR(sqr(bar), "%g");

    DBG_PRINT("we were here");
    DBG_PRINT("and some variable was equal to %g", bar);
}

#undef LOG_VAR
#undef DBG_PRINT


#define DECLARE_POINT(name) \
        int name##_x; \
        int name##_y;

#define PRINT_POINT(name) \
        printf("%s: %dx%d\n", #name, GET_X(name), GET_Y(name))

#define GET_X(name) name##_x
#define GET_Y(name) name##_y

#define SET_X(name, value) name##_x = (value)
#define SET_Y(name, value) name##_y = (value)

void custom_data_structures() {
    DECLARE_POINT(car);

    SET_X(car, 15);
    SET_Y(car, 20);

    PRINT_POINT(car);

    printf("coordinate multiplication: %d\n", MUL(GET_X(car), GET_Y(car)));
}

#undef DECLARE_POINT
#undef PRINT_POINT
#undef GET_X
#undef GET_Y
#undef SET_X
#undef SET_Y


int main(int argc, char *argv[]) {
    int foo = 123;
    double bar = 3.14;
    char *baz = "Baaaz!";

    simple_macros(foo, bar);
    statement_like(foo);
    tests();
    logging(foo, bar, baz);
    custom_data_structures();

    return 0;
}

