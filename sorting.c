#include "bubble.h"
#include "compare.h"
#include "quick.h"
#include "set.h"
#include "shell.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OPTIONS "absqQn:p:r:"
// q for quicksort stack, Q for quicksort queue

// Credits to Tutors/TA's Eugene, Mary, Tristan, Miles, Eric, and Sahiti for the inspirations/pseudocode/help debugging
typedef enum sorting_types { b, s, q, Q, n, p, c } sorting_types;
// Structure inspired by the asgn3.pdf
int main(int argc, char **argv) {
    int opt = 0;
    // Flags for each function
    set set_flags = 0;
    uint32_t n = 100;
    uint32_t p = 100;
    uint32_t r = 13371453;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        // Flag each program depending on what the program argument was
        case 'a':
            set_flags = set_bit(set_flags, b);
            set_flags = set_bit(set_flags, q);
            set_flags = set_bit(set_flags, Q);
            set_flags = set_bit(set_flags, s);
            break;
            // set variables npr to program arguments
        case 'b': set_flags = set_bit(set_flags, b); break;
        case 'q': set_flags = set_bit(set_flags, q); break;
        case 'Q': set_flags = set_bit(set_flags, Q); break;
        case 's': set_flags = set_bit(set_flags, s); break;
        case 'n': n = atoi(optarg); break;
        case 'p': p = atoi(optarg); break;
        case 'r': r = atoi(optarg); break;
        default: printf("whoops");
        }
    }
    // Set seed
    srandom(r);

    // Bounds p
    if (n < p) {
        p = n;
    }

    // Iterate through OPTIONS sorting_types
    for (int i = 0; i <= c; i++) {
        // If the bit corresponding to the sorting type has not been flagged (is 0)
        // Then skip it, else go to the switch case
        if (check_bit(set_flags, i) == false) {
            continue;
        }
        switch (i) {
        case b: {
            // All cases will follow the format of:
            // Allocate memory
            // Fill array with pseudorandom nums
            // Call the associated sort function
            // print moves/compares/elements
            // print sorted array
            // Free memory
            uint32_t *items_bubble = calloc(n, sizeof(uint32_t));

            for (uint32_t i = 0; i < n; i++) {
                items_bubble[i] = random();
            }

            bubble_sort(items_bubble, n);
            printf("Bubble Sort: \n");
            printf("%" PRIu32 " elements, "
                   "%" PRId64 " moves, "
                   "%" PRId64 " compares\n",
                n, moves, compares);
            for (uint32_t i = 0; i < p; i++) {
                printf("%13" PRIu32 "\n", items_bubble[i]);
            }

            free(items_bubble);
            break;
        }
        case q: {
            srandom(r);

            uint32_t *items_quick_stack = calloc(n, sizeof(uint32_t));
            for (uint32_t i = 0; i < n; i++) {
                items_quick_stack[i] = random();
            }

            quick_sort_stack(items_quick_stack, n);

            printf("Quick Stack Sort: \n");
            printf("%" PRIu32 " elements, "
                   "%" PRId64 " moves, "
                   "%" PRId64 " compares\n",
                n, moves, compares);
            for (uint32_t i = 0; i < p; i++) {
                printf("%13" PRIu32 "\n", items_quick_stack[i]);
            }

            free(items_quick_stack);
            break;
        }
        case Q:
            srandom(r);

            uint32_t *items_quick_queue = calloc(n, sizeof(uint32_t));
            for (uint32_t i = 0; i < n; i++) {
                items_quick_queue[i] = random();
            }

            quick_sort_queue(items_quick_queue, n);

            printf("Quick Queue Sort: \n");
            printf("%" PRIu32 " elements, "
                   "%" PRId64 " moves, "
                   "%" PRId64 " compares\n",
                n, moves, compares);
            for (uint32_t i = 0; i < p; i++) {
                printf("%13" PRIu32 "\n", items_quick_queue[i]);
            }

            free(items_quick_queue);
            break;
        case s:
            srandom(r);

            uint32_t *items_shell = calloc(n, sizeof(uint32_t));
            for (uint32_t i = 0; i < n; i++) {
                items_shell[i] = random();
            }

            shell_sort(items_shell, n);
            printf("Shell Sort: \n");
            printf("%" PRIu32 " elements, "
                   "%" PRId64 " moves, "
                   "%" PRId64 " compares\n",
                n, moves, compares);
            for (uint32_t i = 0; i < p; i++) {
                printf("%13" PRIu32 "\n", items_shell[i]);
            }

            free(items_shell);
            break;
        default: printf("Ooopsie whoopsies, sumtwing went vvvvwong uwu!");
        }
    }
    // If no arguments are given
    if (argc == 1) {
        printf(
            "Select at least one sort to perform.\nSYNOPSIS\n   A collection of comparison-based "
            "sorting algorithms.\n\nUSAGE\n   ./sorting [-habsqQo] [-n length] [-p elements] [-r "
            "seed]\n\nOPTIONS\n   -h              Display program help and usage.\n   -a           "
            "   Enable all sorts.\n   -b              Enable Bubble Sort.\n   -s              "
            "Enable Shell Sort.\n   -q              Enable Quick Sort (Stack).\n   -Q              "
            "Enable Quick Sort (Queue).\n   -n length       Specify number of array elements.\n   "
            "-p elements     Specify number of elements to print.\n   -r seed         Specify "
            "random seed.\n   -o              Use sorted arrays.");
    }
}
