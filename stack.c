#include "stack.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Credits to Eugene and Sahiti Vallamreddy
struct Stack {
    uint32_t top;
    uint32_t capacity;
    int64_t *items;
};

Stack *stack_create(uint32_t capacity) {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = 0;
    s->capacity = capacity;

    s->items = (int64_t *) malloc(capacity * sizeof(int64_t));
    if (s->items == NULL) {
        free(s);
        //s = NULL;
        return NULL;
    }
    assert(s);
    return s;
}

void stack_delete(Stack **s) {
    free((*s)->items);
    free(*s);
    *s = NULL;
}

bool stack_push(Stack *s, int64_t x) {
    assert(s);
    if (s->top == s->capacity) {
        return false;
    }
    s->items[s->top] = x;
    s->top += 1;
    return true;
}

uint32_t stack_size(Stack *s) {
    return s->top;
}

bool stack_empty(Stack *s) {
    return (s->top == 0);
}

bool stack_pop(Stack *s, int64_t *x) {
    if (s->top == 0) {
        return false;
    }
    s->top -= 1;
    *x = s->items[s->top];
    return true;
}

// Credits to Eugene Chou for stack_print and stack full
void stack_print(Stack *s) {
    for (uint32_t i = 0; i < s->top; i++) {
        //printf("%" PRId64, s->items[i]);
        if (i + 1 != s->top) {
            printf(", ");
        }
    }
}

bool stack_full(Stack *s) {
    return s->top == s->capacity;
}
