#ifndef C_P_ADIC_10_06_H
#define C_P_ADIC_10_06_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_10_06 10
#define EXPONENT_BITS_P_10_06 6
#define BITS_P_10_06 SIGNIFICAND_BITS_P_10_06 + EXPONENT_BITS_P_10_06

#define C_P_ADIC_10_06_DEBUG true

typedef uint16_t p1006_t;

#define SIGNIFICAND_MASK_P_10_06 ((1ULL << SIGNIFICAND_BITS_P_10_06) - 1)
#define EXPONENT_MASK_P_10_06 (((1ULL << EXPONENT_BITS_P_10_06) - 1) << SIGNIFICAND_BITS_P_10_06)
#define SIGNIFICAND_SIGN_MASK_P_10_06 (1U << (SIGNIFICAND_BITS_P_10_06 - 1))
#define EXPONENT_SIGN_MASK_P_10_06 (1U << (EXPONENT_BITS_P_10_06 - 1))
#define BITS_SIGN_MASK_P_10_06 (1U << (BITS_P_10_06 - 1))

// construct p-adic 1006
p1006_t new_p1006(uint16_t exp, uint16_t sig);
// exponent part of p-adic 1006
uint16_t exp_p1006(p1006_t a);
// significand part of p-adic 1006
uint16_t sig_p1006(p1006_t a);
// add p-adic 1006
p1006_t add_p1006(p1006_t a, p1006_t b);
// subtract p-adic 1006
p1006_t sub_p1006(p1006_t a, p1006_t b);
// negate p-adic 1006
p1006_t neg_p1006(p1006_t a);
// multiply p-adic 1006
p1006_t mul_p1006(p1006_t a, p1006_t b);
// divide p-adic 1006
p1006_t div_p1006(p1006_t a, p1006_t b);
// equals p-adic 1006
bool equ_p1006(p1006_t a, p1006_t b);
// compare p-adic 1006
int com_p1006(p1006_t a, p1006_t b);

#endif //C_P_ADIC_10_06_H

