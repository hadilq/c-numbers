#ifndef C_P_ADIC_03_29_H
#define C_P_ADIC_03_29_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_03_29 3
#define EXPONENT_BITS_P_03_29 06
#define BITS_P_03_29 SIGNIFICAND_BITS_P_03_29 + EXPONENT_BITS_P_03_29

#define C_P_ADIC_03_29_DEBUG true

typedef uint32_t p0329_t;

#define SIGNIFICAND_MASK_P_03_29 ((1ULL << SIGNIFICAND_BITS_P_03_29) - 1)
#define EXPONENT_MASK_P_03_29 (((1ULL << EXPONENT_BITS_P_03_29) - 1) << SIGNIFICAND_BITS_P_03_29)
#define SIGNIFICAND_SIGN_MASK_P_03_29 (1U << (SIGNIFICAND_BITS_P_03_29 - 1))
#define EXPONENT_SIGN_MASK_P_03_29 (1U << (EXPONENT_BITS_P_03_29 - 1))
#define BITS_SIGN_MASK_P_03_29 (1U << (BITS_P_03_29 - 1))

#define MAX_VALUE_P_03_29 (((1U << (EXPONENT_BITS_P_03_29 - 2)) - 1) << SIGNIFICAND_BITS_P_03_29) | ((1U << (SIGNIFICAND_BITS_P_03_29 - 2)) - 1)
#define MIN_VALUE_P_03_29 (((1U << (EXPONENT_BITS_P_03_29 - 2)) - 1) << SIGNIFICAND_BITS_P_03_29) | (SIGNIFICAND_SIGN_MASK_P_03_29)

// construct p-adic 0329
p0329_t new_p0329(int32_t exp, int32_t sig);
// exponent part of p-adic 0329
int32_t exp_p0329(p0329_t a);
// significand part of p-adic 0329
int32_t sig_p0329(p0329_t a);
// add p-adic 0329
p0329_t add_p0329(p0329_t a, p0329_t b);
// subtract p-adic 0329
p0329_t sub_p0329(p0329_t a, p0329_t b);
// negate p-adic 0329
p0329_t neg_p0329(p0329_t a);
// multiply p-adic 0329
p0329_t mul_p0329(p0329_t a, p0329_t b);
// divide p-adic 0329
p0329_t div_p0329(p0329_t a, p0329_t b);
// equals p-adic 0329
bool equ_p0329(p0329_t a, p0329_t b);
// compare p-adic 0329
int com_p0329(p0329_t a, p0329_t b);

#endif //C_P_ADIC_03_29_H

