#ifndef C_P_ADIC_26_06_H
#define C_P_ADIC_26_06_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_26_06 26
#define EXPONENT_BITS_P_26_06 06
#define BITS_P_26_06 SIGNIFICAND_BITS_P_26_06 + EXPONENT_BITS_P_26_06

#define C_P_ADIC_26_06_DEBUG true

typedef uint32_t p2606_t;

#define SIGNIFICAND_MASK_P_26_06 ((1ULL << SIGNIFICAND_BITS_P_26_06) - 1)
#define EXPONENT_MASK_P_26_06 (((1ULL << EXPONENT_BITS_P_26_06) - 1) << SIGNIFICAND_BITS_P_26_06)
#define SIGNIFICAND_SIGN_MASK_P_26_06 (1U << (SIGNIFICAND_BITS_P_26_06 - 1))
#define EXPONENT_SIGN_MASK_P_26_06 (1U << (EXPONENT_BITS_P_26_06 - 1))

// construct p-adic 2606
p2606_t new_p2606(uint32_t exp, uint32_t sig);
// exponent part of p-adic 2606
uint32_t exp_p2606(p2606_t a);
// significand part of p-adic 2606
uint32_t sig_p2606(p2606_t a);
// add p-adic 2606
p2606_t add_p2606(p2606_t a, p2606_t b);
// subtract p-adic 2606
p2606_t sub_p2606(p2606_t a, p2606_t b);
// negate p-adic 2606
p2606_t neg_p2606(p2606_t a);
// multiply p-adic 2606
p2606_t mul_p2606(p2606_t a, p2606_t b);
// divide p-adic 2606
p2606_t div_p2606(p2606_t a, p2606_t b);
// equals p-adic 2606
bool equ_p2606(p2606_t a, p2606_t b);
// compare p-adic 2606
int com_p2606(p2606_t a, p2606_t b);

#endif //C_P_ADIC_26_06_H

