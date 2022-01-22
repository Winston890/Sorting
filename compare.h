#ifndef __COMPARE_H__
#define __COMPARE_H__
#include <stdbool.h>
#include <stdint.h>
extern int64_t moves;
extern int64_t compares;
// Swap and compare developed together with Tutor Mary
void swap(uint32_t *A, int64_t first, int64_t second);
bool compare(int64_t item_1, int64_t item_2);
void zero(int64_t moves, int64_t compares);
#endif

// graph on x number of elements
// y time
