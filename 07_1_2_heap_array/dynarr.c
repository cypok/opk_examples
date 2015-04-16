#include <stdlib.h>
#include <assert.h>

#include "dynarr.h"

#define SIZE_INITIAL 10
#define SIZE_INCREMENT 5

void dynarr_create(DynArr *dynarr) {
    dynarr->length = 0;
    dynarr->data_size = 0;
    dynarr->data = NULL;
}

void dynarr_destroy(DynArr *dynarr) {
    free(dynarr->data);
}

int dynarr_append(DynArr *dynarr, int elem) {
    assert(dynarr->length <= dynarr->data_size);

    if (dynarr->data_size == 0) {
        assert(dynarr->data == NULL);
        size_t new_size = SIZE_INITIAL;
        dynarr->data = malloc(sizeof(int) * new_size);
        if (dynarr->data == NULL) {
            return 0;
        }
        dynarr->data_size = new_size;
    } else if (dynarr->length == dynarr->data_size) {
        size_t new_size = dynarr->data_size + SIZE_INCREMENT;
        int *new_data = realloc(dynarr->data, sizeof(int) * new_size);
        if (new_data == NULL) {
            return 0;
        }
        dynarr->data = new_data;
        dynarr->data_size = new_size;
    }

    assert(dynarr->length < dynarr->data_size);
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

