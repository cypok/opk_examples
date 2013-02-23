#include <stdio.h>
#include <assert.h>

#define ARR_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

int sum(size_t size, int *arr) {
    size_t i = 0;
    int res = 0;
    for (i = 0; i < size; ++i) {
        res += arr[i];
    }
    return res;
}

int main() {

#define SUM(arr) (sum(ARR_SIZE(arr), arr))
    {
        int empty[] = {};
        assert(0 == SUM(empty));
    }
    {
        int one[] = {37};
        assert(37 == SUM(one));
    }
    {
        int few[] = {1, 2, 3};
        assert(6 == SUM(few));
    }
    {
        int negatives[] = {-5, 0, 5};
        assert(0 == SUM(negatives));
    }
    {
        int i;
        int huge[100];
        size_t size = ARR_SIZE(huge);
        for (i = 0; i < size; ++i) {
            huge[i] = i;
        }
        assert((size - 1)*size / 2 == SUM(huge));
    }
    {
        // example of how test will fail:
        // Assertion failed: (5 == SUM(fail)), function main, file main.c, line 47.
        int fail[] = {2, 2};
        assert(5 == SUM(fail));
    }
#undef SUM

    return 0;
}
