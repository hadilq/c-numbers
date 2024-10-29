#ifndef C_P_ADIC_06_10_H
#define C_P_ADIC_06_10_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_06_10 6
#define EXPONENT_BITS_P_06_10 10
#define BITS_P_06_10 SIGNIFICAND_BITS_P_06_10 + EXPONENT_BITS_P_06_10

#define C_P_ADIC_06_10_DEBUG true

typedef uint16_t p0610_t;

#define SIGNIFICAND_MASK_P_06_10 ((1ULL << SIGNIFICAND_BITS_P_06_10) - 1)
#define EXPONENT_MASK_P_06_10 (((1ULL << EXPONENT_BITS_P_06_10) - 1) << SIGNIFICAND_BITS_P_06_10)
#define SIGNIFICAND_SIGN_MASK_P_06_10 (1U << (SIGNIFICAND_BITS_P_06_10 - 1))
#define EXPONENT_SIGN_MASK_P_06_10 (1U << (EXPONENT_BITS_P_06_10 - 1))
#define BITS_SIGN_MASK_P_06_10 (1U << (BITS_P_06_10 - 1))

#define MAX_VALUE_P_06_10 (((1U << (EXPONENT_BITS_P_06_10 - 2)) - 1) << SIGNIFICAND_BITS_P_06_10) | ((1U << (SIGNIFICAND_BITS_P_06_10 - 2)) - 1)
#define MIN_VALUE_P_06_10 (((1U << (EXPONENT_BITS_P_06_10 - 2)) - 1) << SIGNIFICAND_BITS_P_06_10) | (SIGNIFICAND_SIGN_MASK_P_06_10)

// construct p-adic 0610
p0610_t new_p0610(int16_t exp, int16_t sig);
// exponent part of p-adic 0610
int16_t exp_p0610(p0610_t a);
// significand part of p-adic 0610
int16_t sig_p0610(p0610_t a);
// add p-adic 0610
p0610_t add_p0610(p0610_t a, p0610_t b);
// subtract p-adic 0610
p0610_t sub_p0610(p0610_t a, p0610_t b);
// negate p-adic 0610
p0610_t neg_p0610(p0610_t a);
// multiply p-adic 0610
p0610_t mul_p0610(p0610_t a, p0610_t b);
// divide p-adic 0610
p0610_t div_p0610(p0610_t a, p0610_t b);
// equals p-adic 0610
bool equ_p0610(p0610_t a, p0610_t b);
// compare p-adic 0610
int com_p0610(p0610_t a, p0610_t b);

#endif //C_P_ADIC_06_10_H

