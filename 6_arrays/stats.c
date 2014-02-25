#include <stdio.h>
#include <assert.h>
#include <limits.h>

/* Input integer number from standart input. */
int read_int(const char * request);

#define NUMBERS_COUNT 4

/* Calculate sum of numbers in array. */
int calc_sum(int arr[], int len) {
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += arr[i];
    }
    return sum;
}

/* Find maximum number in array. */
int find_max(int arr[], int len) {
    int max = INT_MIN;
    for (int i = 0; i < len; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main(void) {

    int numbers[NUMBERS_COUNT] = {0};

    printf("Please enter %d numbers.\n", NUMBERS_COUNT);
    for (int i = 0; i < NUMBERS_COUNT; ++i) {
        int num = read_int("Enter next number");
        numbers[i] = num;
    }

    printf("You have entered following numbers:");
    for (int i = 0; i < NUMBERS_COUNT; ++i) {
        printf(" %d", numbers[i]);
    }
    printf("\n");

    printf("Sum of numbers is %d.\n", calc_sum(numbers, NUMBERS_COUNT));

    printf("Maximum of numbers is %d.\n", find_max(numbers, NUMBERS_COUNT));

    return 0;
}

/////////////////////////////////////////////////
// Implementation of previously defined functions

/* Skip all remaining line. */
static void skip_garbage() {
    int ch;
    do {
        ch = getchar();
        assert(ch != EOF);
    } while (ch != '\n');
}

/* Input integer number from standart input. */
int read_int(const char * request) {
    for (;;) {
        printf("%s: ", request);
        int num;
        int res = scanf("%d", &num);
        assert(res != EOF);
        skip_garbage();
        if (res == 1) {
            return num;
        }
    }
}

