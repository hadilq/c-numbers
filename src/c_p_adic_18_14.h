#ifndef C_P_ADIC_18_14_H
#define C_P_ADIC_18_14_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_18_14 18
#define EXPONENT_BITS_P_18_14 06
#define BITS_P_18_14 SIGNIFICAND_BITS_P_18_14 + EXPONENT_BITS_P_18_14

#define C_P_ADIC_18_14_DEBUG true

typedef uint32_t p1814_t;

#define SIGNIFICAND_MASK_P_18_14 ((1ULL << SIGNIFICAND_BITS_P_18_14) - 1)
#define EXPONENT_MASK_P_18_14 (((1ULL << EXPONENT_BITS_P_18_14) - 1) << SIGNIFICAND_BITS_P_18_14)
#define SIGNIFICAND_SIGN_MASK_P_18_14 (1U << (SIGNIFICAND_BITS_P_18_14 - 1))
#define EXPONENT_SIGN_MASK_P_18_14 (1U << (EXPONENT_BITS_P_18_14 - 1))
#define BITS_SIGN_MASK_P_18_14 (1U << (BITS_P_18_14 - 1))

// construct p-adic 1814
p1814_t new_p1814(uint32_t exp, uint32_t sig);
// exponent part of p-adic 1814
uint32_t exp_p1814(p1814_t a);
// significand part of p-adic 1814
uint32_t sig_p1814(p1814_t a);
// add p-adic 1814
p1814_t add_p1814(p1814_t a, p1814_t b);
// subtract p-adic 1814
p1814_t sub_p1814(p1814_t a, p1814_t b);
// negate p-adic 1814
p1814_t neg_p1814(p1814_t a);
// multiply p-adic 1814
p1814_t mul_p1814(p1814_t a, p1814_t b);
// divide p-adic 1814
p1814_t div_p1814(p1814_t a, p1814_t b);
// equals p-adic 1814
bool equ_p1814(p1814_t a, p1814_t b);
// compare p-adic 1814
int com_p1814(p1814_t a, p1814_t b);

#endif //C_P_ADIC_18_14_H

