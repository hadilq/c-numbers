#ifndef C_P_ADIC_03_05_H
#define C_P_ADIC_03_05_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_03_05 04
#define EXPONENT_BITS_P_03_05 04
#define BITS_P_03_05 SIGNIFICAND_BITS_P_03_05 + EXPONENT_BITS_P_03_05

#define C_P_ADIC_03_05_DEBUG true

typedef uint8_t p0305_t;

#define SIGNIFICAND_MASK_P_03_05 ((1ULL << SIGNIFICAND_BITS_P_03_05) - 1)
#define EXPONENT_MASK_P_03_05 (((1ULL << EXPONENT_BITS_P_03_05) - 1) << SIGNIFICAND_BITS_P_03_05)
#define SIGNIFICAND_SIGN_MASK_P_03_05 (1U << (SIGNIFICAND_BITS_P_03_05 - 1))
#define EXPONENT_SIGN_MASK_P_03_05 (1U << (EXPONENT_BITS_P_03_05 - 1))
#define BITS_SIGN_MASK_P_03_05 (1U << (BITS_P_03_05 - 1))

#define MAX_VALUE_P_03_05 (((1U << (EXPONENT_BITS_P_03_05 - 2)) - 1) << SIGNIFICAND_BITS_P_03_05) | ((1U << (SIGNIFICAND_BITS_P_03_05 - 2)) - 1)
#define MIN_VALUE_P_03_05 (((1U << (EXPONENT_BITS_P_03_05 - 2)) - 1) << SIGNIFICAND_BITS_P_03_05) | (SIGNIFICAND_SIGN_MASK_P_03_05)

// construct p-adic 0305
p0305_t new_p0305(int8_t exp, int8_t sig);
// exponent part of p-adic 0305
int8_t exp_p0305(p0305_t a);
// significand part of p-adic 0305
int8_t sig_p0305(p0305_t a);
// add p-adic 0305
p0305_t add_p0305(p0305_t a, p0305_t b);
// subtract p-adic 0305
p0305_t sub_p0305(p0305_t a, p0305_t b);
// negate p-adic 0305
p0305_t neg_p0305(p0305_t a);
// multiply p-adic 0305
p0305_t mul_p0305(p0305_t a, p0305_t b);
// divide p-adic 0305
p0305_t div_p0305(p0305_t a, p0305_t b);
// equals p-adic 0305
bool equ_p0305(p0305_t a, p0305_t b);
// compare p-adic 0305
int com_p0305(p0305_t a, p0305_t b);

#endif //C_P_ADIC_03_05_H

