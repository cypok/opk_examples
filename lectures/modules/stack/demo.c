#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    Stack *s = stack_create();
    if (s == NULL) { return 1; }

    stack_push(s, "first");
    stack_push(s, "second");
    printf("%s\n", stack_pop(s));
    printf("%s\n", stack_pop(s));

    stack_destroy(s);
    return 0;
}
