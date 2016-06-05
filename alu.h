#ifndef _DANA_ALU_
#define _DANA_ALU_

#include <stddef.h>

typedef unsigned char uint8;

void hw_add(uint8 *x, size_t xs, uint8 *y, size_t ys);
void hw_sub(uint8 *x, size_t xs, uint8 *y, size_t ys);
void hw_mul(uint8 *x, size_t xs, uint8 *y, size_t ys);
void hw_div(uint8 *x, size_t xs, uint8 *y, size_t ys);
void hw_mod(uint8 *x, size_t xs, uint8 *y, size_t ys);
void hw_not(uint8 *x, size_t xs);

void hw_and(uint8 *x, size_t xs, uint8 *y, size_t ys);
void hw_or(uint8 *x, size_t xs, uint8 *y, size_t ys);

void hw_lshift(uint8 *b, size_t sz, size_t amt);
void hw_rshift(uint8 *b, size_t sz, size_t amt);

#endif
