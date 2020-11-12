#ifndef _STACK_H_
#define _STACK_H_

typedef struct Stack Stack;

Stack* stack_create();
void stack_destroy(Stack *s);
size_t stack_size(Stack *s);
void stack_push(Stack *s, void *elem);
void* stack_pop(Stack *s);

#endif
