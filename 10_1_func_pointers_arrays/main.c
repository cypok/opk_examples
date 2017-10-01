#include <stdio.h>
#include <stdlib.h>

void *maximum(void *arr, size_t elem_size, size_t elems_count,
              int (*cmp)(void*, void*)) {

    if (elems_count == 0) {
        return NULL;
    }

    void *max = arr;
    for (size_t i = 1; i < elems_count; i++) {
        void *elem = (char*)arr + elem_size * i;
        int cmp_res = cmp(elem, max);
        if (cmp_res == 1) { // elem > max
            max = elem;
        }
    }

    return max;
}

int int_cmp(void *x, void *y) {
    int x_value = *(int*)x;
    int y_value = *(int*)y;

    if (x_value == y_value) {
        return 0;
    } else if (x_value < y_value) {
        return -1;
    } else {
        return 1;
    }
}

int double_cmp(void *x, void *y) {
    double x_value = *(double*)x;
    double y_value = *(double*)y;

    if (x_value == y_value) { // not very good
        return 0;
    } else if (x_value < y_value) {
        return -1;
    } else {
        return 1;
    }
}

int main(){
    int ns[] = { 1, 2, 3, 2, 1, 5, 4 };
    size_t n_size = sizeof(ns) / sizeof(ns[0]);
    int *n_max = maximum(ns, sizeof(ns[0]), n_size, int_cmp);
    printf("maximum in ns: %d\n", *n_max);

    double ds[] = { 3.7, 4.2, -100, 2 };
    size_t d_size = sizeof(ds) / sizeof(ds[0]);
    double *d_max = maximum(ds, sizeof(ds[0]), d_size, double_cmp);
    printf("maximum in ds: %g\n", *d_max);

    return 0;
}
