#include "set.h"
bool check_bit(set our_set, int on) {
    uint32_t mask = 1 << on;
    return our_set & mask;
}

set set_bit(set our_set, int on) {
    uint32_t mask = 1 << on;
    return our_set | mask;
}
