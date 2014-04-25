#include <stdio.h>

#include "dynarr.h"

int main(void) {
    DynArr dynarr;
    int i;

    dynarr_create(&dynarr);

    printf("Enter numbers! Stop input by entering not a number.\n");
    for (;;) {
        int num;
        printf("Enter number: ");
        if (scanf("%d", &num) == 1) {
            if (dynarr_append(&dynarr, num) == 0) {
                printf("\n\nError!\n");
                return 1;
            }
        } else {
            break;
        }
    }

    printf("You have entered:");
    for (i = 0; i < dynarr_length(&dynarr); ++i) {
        printf(" %d", dynarr_get(&dynarr, i));
    }
    printf("\n");

    dynarr_destroy(&dynarr);

    return 0;
}

