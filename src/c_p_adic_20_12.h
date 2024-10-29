#ifndef C_P_ADIC_20_12_H
#define C_P_ADIC_20_12_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_20_12 20
#define EXPONENT_BITS_P_20_12 06
#define BITS_P_20_12 SIGNIFICAND_BITS_P_20_12 + EXPONENT_BITS_P_20_12

#define C_P_ADIC_20_12_DEBUG true

typedef uint32_t p2012_t;

#define SIGNIFICAND_MASK_P_20_12 ((1ULL << SIGNIFICAND_BITS_P_20_12) - 1)
#define EXPONENT_MASK_P_20_12 (((1ULL << EXPONENT_BITS_P_20_12) - 1) << SIGNIFICAND_BITS_P_20_12)
#define SIGNIFICAND_SIGN_MASK_P_20_12 (1U << (SIGNIFICAND_BITS_P_20_12 - 1))
#define EXPONENT_SIGN_MASK_P_20_12 (1U << (EXPONENT_BITS_P_20_12 - 1))
#define BITS_SIGN_MASK_P_20_12 (1U << (BITS_P_20_12 - 1))

#define MAX_VALUE_P_20_12 (((1U << (EXPONENT_BITS_P_20_12 - 2)) - 1) << SIGNIFICAND_BITS_P_20_12) | ((1U << (SIGNIFICAND_BITS_P_20_12 - 2)) - 1)
#define MIN_VALUE_P_20_12 (((1U << (EXPONENT_BITS_P_20_12 - 2)) - 1) << SIGNIFICAND_BITS_P_20_12) | (SIGNIFICAND_SIGN_MASK_P_20_12)

// construct p-adic 2012
p2012_t new_p2012(int32_t exp, int32_t sig);
// exponent part of p-adic 2012
int32_t exp_p2012(p2012_t a);
// significand part of p-adic 2012
int32_t sig_p2012(p2012_t a);
// add p-adic 2012
p2012_t add_p2012(p2012_t a, p2012_t b);
// subtract p-adic 2012
p2012_t sub_p2012(p2012_t a, p2012_t b);
// negate p-adic 2012
p2012_t neg_p2012(p2012_t a);
// multiply p-adic 2012
p2012_t mul_p2012(p2012_t a, p2012_t b);
// divide p-adic 2012
p2012_t div_p2012(p2012_t a, p2012_t b);
// equals p-adic 2012
bool equ_p2012(p2012_t a, p2012_t b);
// compare p-adic 2012
int com_p2012(p2012_t a, p2012_t b);

#endif //C_P_ADIC_20_12_H

