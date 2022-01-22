#include "quick.h"

#include "compare.h"
#include "queue.h"
#include "stack.h"

#include <assert.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

//uint32_t max_stack_size = UINT32_MAX;
//uint32_t max_queue_size = UINT32_MAX;

// All Code credited to Eugene Chou's python pseudocode
int64_t partition(uint32_t *A, int64_t low, uint32_t high) {
    int64_t pivot = A[low + ((high - low) / 2)]; // Pick a pivot
    int64_t i = low - 1; // Set lower/upper bound index values
    int64_t j = high + 1;
    while (i < j) {
        do {
            compares += 1;
            i += 1;
        } while (A[i] < pivot);

        do {
            compares += 1;
            j -= 1;
        } while (A[j] > pivot);

        if (i < j) {
            swap(A, i, j);
            // Swap em
            //int64_t temp = 0;
            //temp = A[i];
            //A[i] = A[j];
            //A[j] = temp;
        }
    }
    return j;
}

void quick_sort_stack(uint32_t *A, uint32_t n) {
    moves = 0;
    compares = 0;
    // Low and High are the min/max indexes ([1,3,4] has min 0 max 2)
    int64_t low = 0;
    int64_t high = n - 1;

    // Make stack
    Stack *s = stack_create(n);
    assert(s != NULL);

    // Make sure it was created successfully
    stack_push(s, low);
    stack_push(s, high);

    // Put min/max indexes on stack
    // while loop iteratively implement a recursive like function where you repeat the same concept
    while (stack_empty(s) == false) {
        // order reveresed bc stack is FILO
        stack_pop(s, &high);
        stack_pop(s, &low);
        // Find pivot
        int64_t pivot = partition(A, low, high);
        if (low < pivot) {
            // Create new substack with the lower values
            // Low is normal low (because low of lower values = entire low)
            // Pivot is the "high"
            stack_push(s, low);
            stack_push(s, pivot);
        }
        // Same concept as above, except new substack for higher values
        if (high > pivot + 1) {
            stack_push(s, pivot + 1);
            stack_push(s, high);
        }
    }
    stack_delete(&s);
}

// Very similar to stack
void quick_sort_queue(uint32_t *A, uint32_t n) {
    moves = 0;
    compares = 0;
    int64_t low = 0;
    int64_t high = n - 1;
    Queue *q = queue_create(n);
    assert(q);
    enqueue(q, low);
    enqueue(q, high);
    while (queue_empty(q) == false) {
        // Normal, because queue is FIFO
        dequeue(q, &low);
        dequeue(q, &high);
        int64_t pivot = partition(A, low, high);
        // Same as stack, divide into two subarrays with smaller elements and larger elements
        if (low < pivot) {
            enqueue(q, low);
            enqueue(q, pivot);
        }
        if (high > pivot + 1) {
            enqueue(q, pivot + 1);
            enqueue(q, high);
        }
    }
    queue_delete(&q);
}
