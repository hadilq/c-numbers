#ifndef C_P_ADIC_10_54_H
#define C_P_ADIC_10_54_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_10_54 10
#define EXPONENT_BITS_P_10_54 54
#define BITS_P_10_54 SIGNIFICAND_BITS_P_10_54 + EXPONENT_BITS_P_10_54

#define C_P_ADIC_10_54_DEBUG true

typedef uint64_t p1054_t;

#define SIGNIFICAND_MASK_P_10_54 ((1ULL << SIGNIFICAND_BITS_P_10_54) - 1)
#define EXPONENT_MASK_P_10_54 (((1ULL << EXPONENT_BITS_P_10_54) - 1) << SIGNIFICAND_BITS_P_10_54)
#define SIGNIFICAND_SIGN_MASK_P_10_54 (1ULL << (SIGNIFICAND_BITS_P_10_54 - 1))
#define EXPONENT_SIGN_MASK_P_10_54 (1ULL << (EXPONENT_BITS_P_10_54 - 1))
#define BITS_SIGN_MASK_P_10_54 (1ULL << (BITS_P_10_54 - 1))

// construct p-adic 1054
p1054_t new_p1054(uint64_t exp, uint64_t sig);
// exponent part of p-adic 1054
uint64_t exp_p1054(p1054_t a);
// significand part of p-adic 1054
uint64_t sig_p1054(p1054_t a);
// add p-adic 1054
p1054_t add_p1054(p1054_t a, p1054_t b);
// subtract p-adic 1054
p1054_t sub_p1054(p1054_t a, p1054_t b);
// negate p-adic 1054
p1054_t neg_p1054(p1054_t a);
// multiply p-adic 1054
p1054_t mul_p1054(p1054_t a, p1054_t b);
// divide p-adic 1054
p1054_t div_p1054(p1054_t a, p1054_t b);
// equals p-adic 1054
bool equ_p1054(p1054_t a, p1054_t b);
// compare p-adic 1054
int com_p1054(p1054_t a, p1054_t b);

#endif //C_P_ADIC_10_54_H

