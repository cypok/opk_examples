#include <stdio.h>
#include <assert.h>
#include <limits.h>

/* Input integer number from standart input. */
int read_number(const char * request);

#define NUMBERS_COUNT 4

/* Calculate sum of numbers in array. */
int calc_sum(int arr[], int len) {
    int i;
    int sum = 0;
    for (i = 0; i < len; ++i) {
        sum += arr[i];
    }
    return sum;
}

/* Find maximum number in array. */
int find_max(int arr[], int len) {
    int i;
    int max = INT_MIN;
    for (i = 0; i < len; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main(void) {

    int i;
    int numbers[NUMBERS_COUNT] = {0};

    printf("Please enter %d numbers.\n", NUMBERS_COUNT);
    for (i = 0; i < NUMBERS_COUNT; ++i) {
        int num = read_number("Enter next number");
        numbers[i] = num;
    }

    printf("You have entered following numbers:");
    for (i = 0; i < NUMBERS_COUNT; ++i) {
        printf(" %d", numbers[i]);
    }
    printf("\n");

    printf("Sum of numbers is %d.\n", calc_sum(numbers, NUMBERS_COUNT));

    printf("Maximum of numbers is %d.\n", find_max(numbers, NUMBERS_COUNT));

    return 0;
}

/////////////////////////////////////////////////
// Implementation of previously defined functions

/* Input integer number from standart input. */
int read_number(const char * request) {
    for (;;) {
        int res;
        int num;

        printf("%s: ", request);
        res = scanf("%d", &num);

        assert(res != EOF);
        if (res == 1) {
            return num;
        } else {
            // skip all line
            int ch;
            assert(res == 0);
            do {
                ch = getchar();
                assert(ch != EOF);
            } while (ch != '\n');
        }
    }
}

