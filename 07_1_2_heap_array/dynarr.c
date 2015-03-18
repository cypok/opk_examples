#include <stdlib.h>
#include <assert.h>

#include "dynarr.h"

#define SIZE_INITIAL 10
#define SIZE_INCREMENT 5

void dynarr_create(DynArr *dynarr) {
    dynarr->length = 0;
    dynarr->data_size = SIZE_INITIAL;
    dynarr->data = (int *)malloc(sizeof(int) * dynarr->data_size);
}

void dynarr_destroy(DynArr *dynarr) {
    free(dynarr->data);
}

int dynarr_append(DynArr *dynarr, int elem) {
    assert(dynarr->length <= dynarr->data_size);

    if (dynarr->length == dynarr->data_size) {
        dynarr->data_size += SIZE_INCREMENT;
        dynarr->data = (int *)realloc(dynarr->data, sizeof(int) * dynarr->data_size);
        if (dynarr->data == NULL) {
            return 0;
        }
    }

    dynarr->data[dynarr->length] = elem;
    dynarr->length++;
    return 1;
}

int dynarr_length(DynArr *dynarr) {
    return dynarr->length;
}

int dynarr_get(DynArr *dynarr, int index) {
    assert(0 <= index && index < dynarr->length);

    return dynarr->data[index];
}

