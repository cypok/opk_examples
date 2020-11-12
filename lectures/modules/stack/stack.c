#include <stdlib.h>
#include <assert.h>
#include "stack.h"

// enough for demo ;)
#define MAX_SIZE 2

struct Stack {
    void *data[MAX_SIZE];
    size_t size;
};

Stack* stack_create() {
    Stack *s = malloc(sizeof(Stack));
    if (s != NULL) {
        s->size = 0;
    }
    return s;
}

void stack_destroy(Stack *s) {
    free(s);
}

size_t stack_size(Stack *s) {
    return s->size;
}

void stack_push(Stack *s, void *elem) {
    assert(s->size < MAX_SIZE);
    s->data[s->size++] = elem;
}

void* stack_pop(Stack *s) {
    assert(s->size > 0);
    return s->data[--s->size];
}
