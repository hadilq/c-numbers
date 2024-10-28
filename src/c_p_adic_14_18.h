#ifndef C_P_ADIC_14_18_H
#define C_P_ADIC_14_18_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_14_18 14
#define EXPONENT_BITS_P_14_18 06
#define BITS_P_14_18 SIGNIFICAND_BITS_P_14_18 + EXPONENT_BITS_P_14_18

#define C_P_ADIC_14_18_DEBUG true

typedef uint32_t p1418_t;

#define SIGNIFICAND_MASK_P_14_18 ((1ULL << SIGNIFICAND_BITS_P_14_18) - 1)
#define EXPONENT_MASK_P_14_18 (((1ULL << EXPONENT_BITS_P_14_18) - 1) << SIGNIFICAND_BITS_P_14_18)
#define SIGNIFICAND_SIGN_MASK_P_14_18 (1U << (SIGNIFICAND_BITS_P_14_18 - 1))
#define EXPONENT_SIGN_MASK_P_14_18 (1U << (EXPONENT_BITS_P_14_18 - 1))
#define BITS_SIGN_MASK_P_14_18 (1U << (BITS_P_14_18 - 1))

// construct p-adic 1418
p1418_t new_p1418(uint32_t exp, uint32_t sig);
// exponent part of p-adic 1418
uint32_t exp_p1418(p1418_t a);
// significand part of p-adic 1418
uint32_t sig_p1418(p1418_t a);
// add p-adic 1418
p1418_t add_p1418(p1418_t a, p1418_t b);
// subtract p-adic 1418
p1418_t sub_p1418(p1418_t a, p1418_t b);
// negate p-adic 1418
p1418_t neg_p1418(p1418_t a);
// multiply p-adic 1418
p1418_t mul_p1418(p1418_t a, p1418_t b);
// divide p-adic 1418
p1418_t div_p1418(p1418_t a, p1418_t b);
// equals p-adic 1418
bool equ_p1418(p1418_t a, p1418_t b);
// compare p-adic 1418
int com_p1418(p1418_t a, p1418_t b);

#endif //C_P_ADIC_14_18_H

