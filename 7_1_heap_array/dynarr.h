#pragma once

typedef struct _DynArr {
    // number of stored elements
    int length;

    // array for elements
    int *data;

    // physical size of array for elements
    int data_size;
} DynArr;

void dynarr_create(DynArr *dynarr);

void dynarr_destroy(DynArr *dynarr);

/** Returns whether elem was successfully added */
int dynarr_append(DynArr *dynarr, int elem);

int dynarr_length(DynArr *dynarr);

int dynarr_get(DynArr *dynarr, int index);
