#ifndef C_P_ADIC_07_09_H
#define C_P_ADIC_07_09_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_07_09 7
#define EXPONENT_BITS_P_07_09 9
#define BITS_P_07_09 SIGNIFICAND_BITS_P_07_09 + EXPONENT_BITS_P_07_09

#define C_P_ADIC_07_09_DEBUG true

typedef uint16_t p0709_t;

#define SIGNIFICAND_MASK_P_07_09 ((1ULL << SIGNIFICAND_BITS_P_07_09) - 1)
#define EXPONENT_MASK_P_07_09 (((1ULL << EXPONENT_BITS_P_07_09) - 1) << SIGNIFICAND_BITS_P_07_09)
#define SIGNIFICAND_SIGN_MASK_P_07_09 (1U << (SIGNIFICAND_BITS_P_07_09 - 1))
#define EXPONENT_SIGN_MASK_P_07_09 (1U << (EXPONENT_BITS_P_07_09 - 1))
#define BITS_SIGN_MASK_P_07_09 (1U << (BITS_P_07_09 - 1))

#define MAX_VALUE_P_07_09 (((1U << (EXPONENT_BITS_P_07_09 - 2)) - 1) << SIGNIFICAND_BITS_P_07_09) | ((1U << (SIGNIFICAND_BITS_P_07_09 - 2)) - 1)
#define MIN_VALUE_P_07_09 (((1U << (EXPONENT_BITS_P_07_09 - 2)) - 1) << SIGNIFICAND_BITS_P_07_09) | (SIGNIFICAND_SIGN_MASK_P_07_09)

// construct p-adic 0709
p0709_t new_p0709(int16_t exp, int16_t sig);
// exponent part of p-adic 0709
int16_t exp_p0709(p0709_t a);
// significand part of p-adic 0709
int16_t sig_p0709(p0709_t a);
// add p-adic 0709
p0709_t add_p0709(p0709_t a, p0709_t b);
// subtract p-adic 0709
p0709_t sub_p0709(p0709_t a, p0709_t b);
// negate p-adic 0709
p0709_t neg_p0709(p0709_t a);
// multiply p-adic 0709
p0709_t mul_p0709(p0709_t a, p0709_t b);
// divide p-adic 0709
p0709_t div_p0709(p0709_t a, p0709_t b);
// equals p-adic 0709
bool equ_p0709(p0709_t a, p0709_t b);
// compare p-adic 0709
int com_p0709(p0709_t a, p0709_t b);

#endif //C_P_ADIC_07_09_H

