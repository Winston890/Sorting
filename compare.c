#include "compare.h"

int64_t moves = 0;
int64_t compares = 0;

// Developed together with Tutor Mary
void swap(uint32_t *A, int64_t first, int64_t second) {
    // Swap items
    uint32_t temp = A[first];
    A[first] = A[second];
    A[second] = temp;
    // 3 moves total to swap
    moves += 3;
}

// Compares two things
bool compare(int64_t item_1, int64_t item_2) {
    compares += 1;
    return item_1 < item_2;
}

void zero(int64_t moves, int64_t compares) {
    moves = 0;
    compares = 0;
}
