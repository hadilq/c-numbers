#ifndef C_P_ADIC_02_06_H
#define C_P_ADIC_02_06_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_02_06 04
#define EXPONENT_BITS_P_02_06 04
#define BITS_P_02_06 SIGNIFICAND_BITS_P_02_06 + EXPONENT_BITS_P_02_06

#define C_P_ADIC_02_06_DEBUG true

typedef uint8_t p0206_t;

#define SIGNIFICAND_MASK_P_02_06 ((1ULL << SIGNIFICAND_BITS_P_02_06) - 1)
#define EXPONENT_MASK_P_02_06 (((1ULL << EXPONENT_BITS_P_02_06) - 1) << SIGNIFICAND_BITS_P_02_06)
#define SIGNIFICAND_SIGN_MASK_P_02_06 (1U << (SIGNIFICAND_BITS_P_02_06 - 1))
#define EXPONENT_SIGN_MASK_P_02_06 (1U << (EXPONENT_BITS_P_02_06 - 1))
#define BITS_SIGN_MASK_P_02_06 (1U << (BITS_P_02_06 - 1))

#define MAX_VALUE_P_02_06 (((1U << (EXPONENT_BITS_P_02_06 - 2)) - 1) << SIGNIFICAND_BITS_P_02_06) | ((1U << (SIGNIFICAND_BITS_P_02_06 - 2)) - 1)
#define MIN_VALUE_P_02_06 (((1U << (EXPONENT_BITS_P_02_06 - 2)) - 1) << SIGNIFICAND_BITS_P_02_06) | (SIGNIFICAND_SIGN_MASK_P_02_06)

// construct p-adic 0206
p0206_t new_p0206(int8_t exp, int8_t sig);
// exponent part of p-adic 0206
int8_t exp_p0206(p0206_t a);
// significand part of p-adic 0206
int8_t sig_p0206(p0206_t a);
// add p-adic 0206
p0206_t add_p0206(p0206_t a, p0206_t b);
// subtract p-adic 0206
p0206_t sub_p0206(p0206_t a, p0206_t b);
// negate p-adic 0206
p0206_t neg_p0206(p0206_t a);
// multiply p-adic 0206
p0206_t mul_p0206(p0206_t a, p0206_t b);
// divide p-adic 0206
p0206_t div_p0206(p0206_t a, p0206_t b);
// equals p-adic 0206
bool equ_p0206(p0206_t a, p0206_t b);
// compare p-adic 0206
int com_p0206(p0206_t a, p0206_t b);

#endif //C_P_ADIC_02_06_H

