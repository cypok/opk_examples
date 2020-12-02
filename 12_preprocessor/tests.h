#ifndef _TESTS_H_
#define _TESTS_H_

#define CHECK_INT(expected, actual)                                                        \
    do {                                                                                   \
        int actual_value = (actual);                                                       \
        int expected_value = (expected);                                                   \
        if (expected_value != actual_value) {                                              \
            fprintf(stderr, "FAILED TEST @ %s:%d: (%s) is expected to be %d but is %d.\n", \
                    __FILE__, __LINE__, #actual, expected_value, actual_value);            \
        }                                                                                  \
    } while (0)

#endif
