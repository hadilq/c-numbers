#ifndef C_P_ADIC_09_07_H
#define C_P_ADIC_09_07_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_09_07 9
#define EXPONENT_BITS_P_09_07 7
#define BITS_P_09_07 SIGNIFICAND_BITS_P_09_07 + EXPONENT_BITS_P_09_07

#define C_P_ADIC_09_07_DEBUG true

typedef uint16_t p0907_t;

#define SIGNIFICAND_MASK_P_09_07 ((1ULL << SIGNIFICAND_BITS_P_09_07) - 1)
#define EXPONENT_MASK_P_09_07 (((1ULL << EXPONENT_BITS_P_09_07) - 1) << SIGNIFICAND_BITS_P_09_07)
#define SIGNIFICAND_SIGN_MASK_P_09_07 (1U << (SIGNIFICAND_BITS_P_09_07 - 1))
#define EXPONENT_SIGN_MASK_P_09_07 (1U << (EXPONENT_BITS_P_09_07 - 1))
#define BITS_SIGN_MASK_P_09_07 (1U << (BITS_P_09_07 - 1))

#define MAX_VALUE_P_09_07 (((1U << (EXPONENT_BITS_P_09_07 - 2)) - 1) << SIGNIFICAND_BITS_P_09_07) | ((1U << (SIGNIFICAND_BITS_P_09_07 - 2)) - 1)
#define MIN_VALUE_P_09_07 (((1U << (EXPONENT_BITS_P_09_07 - 2)) - 1) << SIGNIFICAND_BITS_P_09_07) | (SIGNIFICAND_SIGN_MASK_P_09_07)

// construct p-adic 0907
p0907_t new_p0907(int16_t exp, int16_t sig);
// exponent part of p-adic 0907
int16_t exp_p0907(p0907_t a);
// significand part of p-adic 0907
int16_t sig_p0907(p0907_t a);
// add p-adic 0907
p0907_t add_p0907(p0907_t a, p0907_t b);
// subtract p-adic 0907
p0907_t sub_p0907(p0907_t a, p0907_t b);
// negate p-adic 0907
p0907_t neg_p0907(p0907_t a);
// multiply p-adic 0907
p0907_t mul_p0907(p0907_t a, p0907_t b);
// divide p-adic 0907
p0907_t div_p0907(p0907_t a, p0907_t b);
// equals p-adic 0907
bool equ_p0907(p0907_t a, p0907_t b);
// compare p-adic 0907
int com_p0907(p0907_t a, p0907_t b);

#endif //C_P_ADIC_09_07_H

