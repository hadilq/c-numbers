#ifndef C_P_ADIC_21_11_H
#define C_P_ADIC_21_11_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_21_11 21
#define EXPONENT_BITS_P_21_11 06
#define BITS_P_21_11 SIGNIFICAND_BITS_P_21_11 + EXPONENT_BITS_P_21_11

#define C_P_ADIC_21_11_DEBUG true

typedef uint32_t p2111_t;

#define SIGNIFICAND_MASK_P_21_11 ((1ULL << SIGNIFICAND_BITS_P_21_11) - 1)
#define EXPONENT_MASK_P_21_11 (((1ULL << EXPONENT_BITS_P_21_11) - 1) << SIGNIFICAND_BITS_P_21_11)
#define SIGNIFICAND_SIGN_MASK_P_21_11 (1U << (SIGNIFICAND_BITS_P_21_11 - 1))
#define EXPONENT_SIGN_MASK_P_21_11 (1U << (EXPONENT_BITS_P_21_11 - 1))
#define BITS_SIGN_MASK_P_21_11 (1U << (BITS_P_21_11 - 1))

// construct p-adic 2111
p2111_t new_p2111(uint32_t exp, uint32_t sig);
// exponent part of p-adic 2111
uint32_t exp_p2111(p2111_t a);
// significand part of p-adic 2111
uint32_t sig_p2111(p2111_t a);
// add p-adic 2111
p2111_t add_p2111(p2111_t a, p2111_t b);
// subtract p-adic 2111
p2111_t sub_p2111(p2111_t a, p2111_t b);
// negate p-adic 2111
p2111_t neg_p2111(p2111_t a);
// multiply p-adic 2111
p2111_t mul_p2111(p2111_t a, p2111_t b);
// divide p-adic 2111
p2111_t div_p2111(p2111_t a, p2111_t b);
// equals p-adic 2111
bool equ_p2111(p2111_t a, p2111_t b);
// compare p-adic 2111
int com_p2111(p2111_t a, p2111_t b);

#endif //C_P_ADIC_21_11_H

