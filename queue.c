#include "queue.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    uint32_t head;
    uint32_t tail;
    uint32_t size;
    uint32_t capacity;
    int64_t *items;
};

Queue *queue_create(uint32_t capacity) {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    if (q) {
        q->head = 0;
        q->tail = 0;
        q->size = 0;
        q->capacity = capacity;
        q->items = (int64_t *) calloc(capacity, sizeof(int64_t));
        if (!q->items) {
            free(q);
            q = NULL;
        }
    }
    return q;
}

void queue_delete(Queue **q) {
    if (*q && (*q)->items) {
        free((*q)->items);
        free(*q);
        *q = NULL;
    }
    return;
}

void queue_print(Queue *q) {
    for (uint32_t i = 0; i < queue_size(q); i++) {
        printf("%ld", q->items[i]);
    }
}

uint32_t queue_size(Queue *q) {
    if (q == NULL) {
        return 0;
    }
    return q->size;
}

bool queue_empty(Queue *q) {
    if (q->size == 0) {
        return true;
    }
    return false;
}

bool queue_full(Queue *q) {
    if (q->size == q->capacity) {
        return true;
    }
    return false;
}

bool enqueue(Queue *q, int64_t x) {
    if (q->size == q->capacity) {
        return false;
    }
    q->size += 1;
    q->items[q->tail] = x;
    q->tail = (q->tail + 1) % q->capacity;
    return true;
}

bool dequeue(Queue *q, int64_t *x) {
    if (q->size == 0) {
        return false;
    }
    q->size -= 1;
    *x = q->items[q->head];
    q->head = (q->head + 1) % q->capacity;
    return true;
}
