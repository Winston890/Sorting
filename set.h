#ifndef __SET_H__
#define __SET_H__

#include <stdbool.h>
#include <stdint.h>
typedef uint32_t set;
set set_bit(set our_set, int on);
bool check_bit(set our_set, int on);
#endif
