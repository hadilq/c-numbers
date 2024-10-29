#ifndef C_P_ADIC_25_07_H
#define C_P_ADIC_25_07_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_25_07 25
#define EXPONENT_BITS_P_25_07 06
#define BITS_P_25_07 SIGNIFICAND_BITS_P_25_07 + EXPONENT_BITS_P_25_07

#define C_P_ADIC_25_07_DEBUG true

typedef uint32_t p2507_t;

#define SIGNIFICAND_MASK_P_25_07 ((1ULL << SIGNIFICAND_BITS_P_25_07) - 1)
#define EXPONENT_MASK_P_25_07 (((1ULL << EXPONENT_BITS_P_25_07) - 1) << SIGNIFICAND_BITS_P_25_07)
#define SIGNIFICAND_SIGN_MASK_P_25_07 (1U << (SIGNIFICAND_BITS_P_25_07 - 1))
#define EXPONENT_SIGN_MASK_P_25_07 (1U << (EXPONENT_BITS_P_25_07 - 1))
#define BITS_SIGN_MASK_P_25_07 (1U << (BITS_P_25_07 - 1))

#define MAX_VALUE_P_25_07 (((1U << (EXPONENT_BITS_P_25_07 - 2)) - 1) << SIGNIFICAND_BITS_P_25_07) | ((1U << (SIGNIFICAND_BITS_P_25_07 - 2)) - 1)
#define MIN_VALUE_P_25_07 (((1U << (EXPONENT_BITS_P_25_07 - 2)) - 1) << SIGNIFICAND_BITS_P_25_07) | (SIGNIFICAND_SIGN_MASK_P_25_07)

// construct p-adic 2507
p2507_t new_p2507(int32_t exp, int32_t sig);
// exponent part of p-adic 2507
int32_t exp_p2507(p2507_t a);
// significand part of p-adic 2507
int32_t sig_p2507(p2507_t a);
// add p-adic 2507
p2507_t add_p2507(p2507_t a, p2507_t b);
// subtract p-adic 2507
p2507_t sub_p2507(p2507_t a, p2507_t b);
// negate p-adic 2507
p2507_t neg_p2507(p2507_t a);
// multiply p-adic 2507
p2507_t mul_p2507(p2507_t a, p2507_t b);
// divide p-adic 2507
p2507_t div_p2507(p2507_t a, p2507_t b);
// equals p-adic 2507
bool equ_p2507(p2507_t a, p2507_t b);
// compare p-adic 2507
int com_p2507(p2507_t a, p2507_t b);

#endif //C_P_ADIC_25_07_H

