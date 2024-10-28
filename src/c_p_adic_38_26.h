#ifndef C_P_ADIC_38_26_H
#define C_P_ADIC_38_26_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_38_26 38
#define EXPONENT_BITS_P_38_26 26
#define BITS_P_38_26 SIGNIFICAND_BITS_P_38_26 + EXPONENT_BITS_P_38_26

#define C_P_ADIC_38_26_DEBUG true

typedef uint64_t p3826_t;

#define SIGNIFICAND_MASK_P_38_26 ((1ULL << SIGNIFICAND_BITS_P_38_26) - 1)
#define EXPONENT_MASK_P_38_26 (((1ULL << EXPONENT_BITS_P_38_26) - 1) << SIGNIFICAND_BITS_P_38_26)
#define SIGNIFICAND_SIGN_MASK_P_38_26 (1ULL << (SIGNIFICAND_BITS_P_38_26 - 1))
#define EXPONENT_SIGN_MASK_P_38_26 (1ULL << (EXPONENT_BITS_P_38_26 - 1))
#define BITS_SIGN_MASK_P_38_26 (1ULL << (BITS_P_38_26 - 1))

// construct p-adic 3826
p3826_t new_p3826(uint64_t exp, uint64_t sig);
// exponent part of p-adic 3826
uint64_t exp_p3826(p3826_t a);
// significand part of p-adic 3826
uint64_t sig_p3826(p3826_t a);
// add p-adic 3826
p3826_t add_p3826(p3826_t a, p3826_t b);
// subtract p-adic 3826
p3826_t sub_p3826(p3826_t a, p3826_t b);
// negate p-adic 3826
p3826_t neg_p3826(p3826_t a);
// multiply p-adic 3826
p3826_t mul_p3826(p3826_t a, p3826_t b);
// divide p-adic 3826
p3826_t div_p3826(p3826_t a, p3826_t b);
// equals p-adic 3826
bool equ_p3826(p3826_t a, p3826_t b);
// compare p-adic 3826
int com_p3826(p3826_t a, p3826_t b);

#endif //C_P_ADIC_38_26_H

