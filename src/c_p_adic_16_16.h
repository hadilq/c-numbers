#ifndef C_P_ADIC_16_16_H
#define C_P_ADIC_16_16_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_16_16 16
#define EXPONENT_BITS_P_16_16 06
#define BITS_P_16_16 SIGNIFICAND_BITS_P_16_16 + EXPONENT_BITS_P_16_16

#define C_P_ADIC_16_16_DEBUG true

typedef uint32_t p1616_t;

#define SIGNIFICAND_MASK_P_16_16 ((1ULL << SIGNIFICAND_BITS_P_16_16) - 1)
#define EXPONENT_MASK_P_16_16 (((1ULL << EXPONENT_BITS_P_16_16) - 1) << SIGNIFICAND_BITS_P_16_16)
#define SIGNIFICAND_SIGN_MASK_P_16_16 (1U << (SIGNIFICAND_BITS_P_16_16 - 1))
#define EXPONENT_SIGN_MASK_P_16_16 (1U << (EXPONENT_BITS_P_16_16 - 1))
#define BITS_SIGN_MASK_P_16_16 (1U << (BITS_P_16_16 - 1))

#define MAX_VALUE_P_16_16 (((1U << (EXPONENT_BITS_P_16_16 - 2)) - 1) << SIGNIFICAND_BITS_P_16_16) | ((1U << (SIGNIFICAND_BITS_P_16_16 - 2)) - 1)
#define MIN_VALUE_P_16_16 (((1U << (EXPONENT_BITS_P_16_16 - 2)) - 1) << SIGNIFICAND_BITS_P_16_16) | (SIGNIFICAND_SIGN_MASK_P_16_16)

// construct p-adic 1616
p1616_t new_p1616(int32_t exp, int32_t sig);
// exponent part of p-adic 1616
int32_t exp_p1616(p1616_t a);
// significand part of p-adic 1616
int32_t sig_p1616(p1616_t a);
// add p-adic 1616
p1616_t add_p1616(p1616_t a, p1616_t b);
// subtract p-adic 1616
p1616_t sub_p1616(p1616_t a, p1616_t b);
// negate p-adic 1616
p1616_t neg_p1616(p1616_t a);
// multiply p-adic 1616
p1616_t mul_p1616(p1616_t a, p1616_t b);
// divide p-adic 1616
p1616_t div_p1616(p1616_t a, p1616_t b);
// equals p-adic 1616
bool equ_p1616(p1616_t a, p1616_t b);
// compare p-adic 1616
int com_p1616(p1616_t a, p1616_t b);

#endif //C_P_ADIC_16_16_H

