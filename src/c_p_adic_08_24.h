#ifndef C_P_ADIC_08_24_H
#define C_P_ADIC_08_24_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_08_24 8
#define EXPONENT_BITS_P_08_24 06
#define BITS_P_08_24 SIGNIFICAND_BITS_P_08_24 + EXPONENT_BITS_P_08_24

#define C_P_ADIC_08_24_DEBUG true

typedef uint32_t p0824_t;

#define SIGNIFICAND_MASK_P_08_24 ((1ULL << SIGNIFICAND_BITS_P_08_24) - 1)
#define EXPONENT_MASK_P_08_24 (((1ULL << EXPONENT_BITS_P_08_24) - 1) << SIGNIFICAND_BITS_P_08_24)
#define SIGNIFICAND_SIGN_MASK_P_08_24 (1U << (SIGNIFICAND_BITS_P_08_24 - 1))
#define EXPONENT_SIGN_MASK_P_08_24 (1U << (EXPONENT_BITS_P_08_24 - 1))
#define BITS_SIGN_MASK_P_08_24 (1U << (BITS_P_08_24 - 1))

#define MAX_VALUE_P_08_24 (((1U << (EXPONENT_BITS_P_08_24 - 2)) - 1) << SIGNIFICAND_BITS_P_08_24) | ((1U << (SIGNIFICAND_BITS_P_08_24 - 2)) - 1)
#define MIN_VALUE_P_08_24 (((1U << (EXPONENT_BITS_P_08_24 - 2)) - 1) << SIGNIFICAND_BITS_P_08_24) | (SIGNIFICAND_SIGN_MASK_P_08_24)

// construct p-adic 0824
p0824_t new_p0824(int32_t exp, int32_t sig);
// exponent part of p-adic 0824
int32_t exp_p0824(p0824_t a);
// significand part of p-adic 0824
int32_t sig_p0824(p0824_t a);
// add p-adic 0824
p0824_t add_p0824(p0824_t a, p0824_t b);
// subtract p-adic 0824
p0824_t sub_p0824(p0824_t a, p0824_t b);
// negate p-adic 0824
p0824_t neg_p0824(p0824_t a);
// multiply p-adic 0824
p0824_t mul_p0824(p0824_t a, p0824_t b);
// divide p-adic 0824
p0824_t div_p0824(p0824_t a, p0824_t b);
// equals p-adic 0824
bool equ_p0824(p0824_t a, p0824_t b);
// compare p-adic 0824
int com_p0824(p0824_t a, p0824_t b);

#endif //C_P_ADIC_08_24_H

