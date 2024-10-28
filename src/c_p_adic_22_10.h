#ifndef C_P_ADIC_22_10_H
#define C_P_ADIC_22_10_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_22_10 22
#define EXPONENT_BITS_P_22_10 06
#define BITS_P_22_10 SIGNIFICAND_BITS_P_22_10 + EXPONENT_BITS_P_22_10

#define C_P_ADIC_22_10_DEBUG true

typedef uint32_t p2210_t;

#define SIGNIFICAND_MASK_P_22_10 ((1ULL << SIGNIFICAND_BITS_P_22_10) - 1)
#define EXPONENT_MASK_P_22_10 (((1ULL << EXPONENT_BITS_P_22_10) - 1) << SIGNIFICAND_BITS_P_22_10)
#define SIGNIFICAND_SIGN_MASK_P_22_10 (1U << (SIGNIFICAND_BITS_P_22_10 - 1))
#define EXPONENT_SIGN_MASK_P_22_10 (1U << (EXPONENT_BITS_P_22_10 - 1))
#define BITS_SIGN_MASK_P_22_10 (1U << (BITS_P_22_10 - 1))

// construct p-adic 2210
p2210_t new_p2210(uint32_t exp, uint32_t sig);
// exponent part of p-adic 2210
uint32_t exp_p2210(p2210_t a);
// significand part of p-adic 2210
uint32_t sig_p2210(p2210_t a);
// add p-adic 2210
p2210_t add_p2210(p2210_t a, p2210_t b);
// subtract p-adic 2210
p2210_t sub_p2210(p2210_t a, p2210_t b);
// negate p-adic 2210
p2210_t neg_p2210(p2210_t a);
// multiply p-adic 2210
p2210_t mul_p2210(p2210_t a, p2210_t b);
// divide p-adic 2210
p2210_t div_p2210(p2210_t a, p2210_t b);
// equals p-adic 2210
bool equ_p2210(p2210_t a, p2210_t b);
// compare p-adic 2210
int com_p2210(p2210_t a, p2210_t b);

#endif //C_P_ADIC_22_10_H

