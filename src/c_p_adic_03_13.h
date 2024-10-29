#ifndef C_P_ADIC_03_13_H
#define C_P_ADIC_03_13_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_03_13 3
#define EXPONENT_BITS_P_03_13 13
#define BITS_P_03_13 SIGNIFICAND_BITS_P_03_13 + EXPONENT_BITS_P_03_13

#define C_P_ADIC_03_13_DEBUG true

typedef uint16_t p0313_t;

#define SIGNIFICAND_MASK_P_03_13 ((1ULL << SIGNIFICAND_BITS_P_03_13) - 1)
#define EXPONENT_MASK_P_03_13 (((1ULL << EXPONENT_BITS_P_03_13) - 1) << SIGNIFICAND_BITS_P_03_13)
#define SIGNIFICAND_SIGN_MASK_P_03_13 (1U << (SIGNIFICAND_BITS_P_03_13 - 1))
#define EXPONENT_SIGN_MASK_P_03_13 (1U << (EXPONENT_BITS_P_03_13 - 1))
#define BITS_SIGN_MASK_P_03_13 (1U << (BITS_P_03_13 - 1))

#define MAX_VALUE_P_03_13 (((1U << (EXPONENT_BITS_P_03_13 - 2)) - 1) << SIGNIFICAND_BITS_P_03_13) | ((1U << (SIGNIFICAND_BITS_P_03_13 - 2)) - 1)
#define MIN_VALUE_P_03_13 (((1U << (EXPONENT_BITS_P_03_13 - 2)) - 1) << SIGNIFICAND_BITS_P_03_13) | (SIGNIFICAND_SIGN_MASK_P_03_13)

// construct p-adic 0313
p0313_t new_p0313(int16_t exp, int16_t sig);
// exponent part of p-adic 0313
int16_t exp_p0313(p0313_t a);
// significand part of p-adic 0313
int16_t sig_p0313(p0313_t a);
// add p-adic 0313
p0313_t add_p0313(p0313_t a, p0313_t b);
// subtract p-adic 0313
p0313_t sub_p0313(p0313_t a, p0313_t b);
// negate p-adic 0313
p0313_t neg_p0313(p0313_t a);
// multiply p-adic 0313
p0313_t mul_p0313(p0313_t a, p0313_t b);
// divide p-adic 0313
p0313_t div_p0313(p0313_t a, p0313_t b);
// equals p-adic 0313
bool equ_p0313(p0313_t a, p0313_t b);
// compare p-adic 0313
int com_p0313(p0313_t a, p0313_t b);

#endif //C_P_ADIC_03_13_H

