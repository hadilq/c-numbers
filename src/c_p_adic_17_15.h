#ifndef C_P_ADIC_17_15_H
#define C_P_ADIC_17_15_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_17_15 17
#define EXPONENT_BITS_P_17_15 06
#define BITS_P_17_15 SIGNIFICAND_BITS_P_17_15 + EXPONENT_BITS_P_17_15

#define C_P_ADIC_17_15_DEBUG true

typedef uint32_t p1715_t;

#define SIGNIFICAND_MASK_P_17_15 ((1ULL << SIGNIFICAND_BITS_P_17_15) - 1)
#define EXPONENT_MASK_P_17_15 (((1ULL << EXPONENT_BITS_P_17_15) - 1) << SIGNIFICAND_BITS_P_17_15)
#define SIGNIFICAND_SIGN_MASK_P_17_15 (1U << (SIGNIFICAND_BITS_P_17_15 - 1))
#define EXPONENT_SIGN_MASK_P_17_15 (1U << (EXPONENT_BITS_P_17_15 - 1))
#define BITS_SIGN_MASK_P_17_15 (1U << (BITS_P_17_15 - 1))

#define MAX_VALUE_P_17_15 (((1U << (EXPONENT_BITS_P_17_15 - 2)) - 1) << SIGNIFICAND_BITS_P_17_15) | ((1U << (SIGNIFICAND_BITS_P_17_15 - 2)) - 1)
#define MIN_VALUE_P_17_15 (((1U << (EXPONENT_BITS_P_17_15 - 2)) - 1) << SIGNIFICAND_BITS_P_17_15) | (SIGNIFICAND_SIGN_MASK_P_17_15)

// construct p-adic 1715
p1715_t new_p1715(int32_t exp, int32_t sig);
// exponent part of p-adic 1715
int32_t exp_p1715(p1715_t a);
// significand part of p-adic 1715
int32_t sig_p1715(p1715_t a);
// add p-adic 1715
p1715_t add_p1715(p1715_t a, p1715_t b);
// subtract p-adic 1715
p1715_t sub_p1715(p1715_t a, p1715_t b);
// negate p-adic 1715
p1715_t neg_p1715(p1715_t a);
// multiply p-adic 1715
p1715_t mul_p1715(p1715_t a, p1715_t b);
// divide p-adic 1715
p1715_t div_p1715(p1715_t a, p1715_t b);
// equals p-adic 1715
bool equ_p1715(p1715_t a, p1715_t b);
// compare p-adic 1715
int com_p1715(p1715_t a, p1715_t b);

#endif //C_P_ADIC_17_15_H

