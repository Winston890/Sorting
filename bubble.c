#include "compare.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
// Inspired by the python pseudocode on the assign doc (by Eugene?)
void bubble_sort(uint32_t *A, uint32_t n) {
    bool end = false;
    moves = 0;
    compares = 0;
    while (end == false) {
        end = true;
        for (uint32_t i = 1; i < n; i++) {
            if (compare(A[i], A[i - 1])) {
                swap(A, i, i - 1);
                //uint32_t temp = A[i];
                //A[i] = A[i-1];
                //A[i-1] = temp;
                end = false;
            }
        }
        n -= 1;
    }
}
