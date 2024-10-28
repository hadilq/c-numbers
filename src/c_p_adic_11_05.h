#ifndef C_P_ADIC_11_05_H
#define C_P_ADIC_11_05_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_11_05 11
#define EXPONENT_BITS_P_11_05 5
#define BITS_P_11_05 SIGNIFICAND_BITS_P_11_05 + EXPONENT_BITS_P_11_05

#define C_P_ADIC_11_05_DEBUG true

typedef uint16_t p1105_t;

#define SIGNIFICAND_MASK_P_11_05 ((1ULL << SIGNIFICAND_BITS_P_11_05) - 1)
#define EXPONENT_MASK_P_11_05 (((1ULL << EXPONENT_BITS_P_11_05) - 1) << SIGNIFICAND_BITS_P_11_05)
#define SIGNIFICAND_SIGN_MASK_P_11_05 (1U << (SIGNIFICAND_BITS_P_11_05 - 1))
#define EXPONENT_SIGN_MASK_P_11_05 (1U << (EXPONENT_BITS_P_11_05 - 1))
#define BITS_SIGN_MASK_P_11_05 (1U << (BITS_P_11_05 - 1))

// construct p-adic 1105
p1105_t new_p1105(uint16_t exp, uint16_t sig);
// exponent part of p-adic 1105
uint16_t exp_p1105(p1105_t a);
// significand part of p-adic 1105
uint16_t sig_p1105(p1105_t a);
// add p-adic 1105
p1105_t add_p1105(p1105_t a, p1105_t b);
// subtract p-adic 1105
p1105_t sub_p1105(p1105_t a, p1105_t b);
// negate p-adic 1105
p1105_t neg_p1105(p1105_t a);
// multiply p-adic 1105
p1105_t mul_p1105(p1105_t a, p1105_t b);
// divide p-adic 1105
p1105_t div_p1105(p1105_t a, p1105_t b);
// equals p-adic 1105
bool equ_p1105(p1105_t a, p1105_t b);
// compare p-adic 1105
int com_p1105(p1105_t a, p1105_t b);

#endif //C_P_ADIC_11_05_H

