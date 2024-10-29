#ifndef C_P_ADIC_15_17_H
#define C_P_ADIC_15_17_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_15_17 15
#define EXPONENT_BITS_P_15_17 06
#define BITS_P_15_17 SIGNIFICAND_BITS_P_15_17 + EXPONENT_BITS_P_15_17

#define C_P_ADIC_15_17_DEBUG true

typedef uint32_t p1517_t;

#define SIGNIFICAND_MASK_P_15_17 ((1ULL << SIGNIFICAND_BITS_P_15_17) - 1)
#define EXPONENT_MASK_P_15_17 (((1ULL << EXPONENT_BITS_P_15_17) - 1) << SIGNIFICAND_BITS_P_15_17)
#define SIGNIFICAND_SIGN_MASK_P_15_17 (1U << (SIGNIFICAND_BITS_P_15_17 - 1))
#define EXPONENT_SIGN_MASK_P_15_17 (1U << (EXPONENT_BITS_P_15_17 - 1))
#define BITS_SIGN_MASK_P_15_17 (1U << (BITS_P_15_17 - 1))

#define MAX_VALUE_P_15_17 (((1U << (EXPONENT_BITS_P_15_17 - 2)) - 1) << SIGNIFICAND_BITS_P_15_17) | ((1U << (SIGNIFICAND_BITS_P_15_17 - 2)) - 1)
#define MIN_VALUE_P_15_17 (((1U << (EXPONENT_BITS_P_15_17 - 2)) - 1) << SIGNIFICAND_BITS_P_15_17) | (SIGNIFICAND_SIGN_MASK_P_15_17)

// construct p-adic 1517
p1517_t new_p1517(int32_t exp, int32_t sig);
// exponent part of p-adic 1517
int32_t exp_p1517(p1517_t a);
// significand part of p-adic 1517
int32_t sig_p1517(p1517_t a);
// add p-adic 1517
p1517_t add_p1517(p1517_t a, p1517_t b);
// subtract p-adic 1517
p1517_t sub_p1517(p1517_t a, p1517_t b);
// negate p-adic 1517
p1517_t neg_p1517(p1517_t a);
// multiply p-adic 1517
p1517_t mul_p1517(p1517_t a, p1517_t b);
// divide p-adic 1517
p1517_t div_p1517(p1517_t a, p1517_t b);
// equals p-adic 1517
bool equ_p1517(p1517_t a, p1517_t b);
// compare p-adic 1517
int com_p1517(p1517_t a, p1517_t b);

#endif //C_P_ADIC_15_17_H

