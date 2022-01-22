#include "shell.h"

#include "compare.h"
#include "gaps.h"

#include <stdint.h>
#include <stdio.h>

//comparison is comparing two ELEMENTS OF ARRAY, like temp < array
void shell_sort(uint32_t *A, uint32_t n) {
    moves = 0;
    compares = 0;
    for (uint32_t gap = 0; gap < GAPS; gap++) {
        for (uint32_t range = gaps[gap]; range < n; range++) {
            uint32_t j = range;
            int64_t temp = A[range];
            int64_t temp2 = gaps[gap];
            moves += 2;
            while (j >= gaps[gap] && compare(temp, A[j - temp2])) {
                swap(A, j, j - temp2);
                //A[j] = A[j-temp2];
                j -= gaps[gap];
            }
            A[j] = temp;
        }
    }
}
