#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int count_primes(int n) {
    if (n < 2) {
        return 0;
    } else {
        int count = 0;
        for (int i = 2; i <= n; i++) {
            bool is_prime = true;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    is_prime = false;
                    break;
                }
            }
            if (is_prime) {
                count++;
            }
        }
        return count;
    }
}

void measure(int n) {
    // start timer
    clock_t start = clock();

    // some calculation
    int count = count_primes(n);

    // end timer
    clock_t end = clock();
    double time = (double)(end - start)/CLOCKS_PER_SEC;

    printf("%6d: %6d primes in %.3lf\n", n, count, time);
}

int main() {
    for (int n = 1; ; n *= 2) {
        measure(n);
    }
}
