#ifndef C_P_ADIC_30_34_H
#define C_P_ADIC_30_34_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_30_34 30
#define EXPONENT_BITS_P_30_34 34
#define BITS_P_30_34 SIGNIFICAND_BITS_P_30_34 + EXPONENT_BITS_P_30_34

#define C_P_ADIC_30_34_DEBUG true

typedef uint64_t p3034_t;

#define SIGNIFICAND_MASK_P_30_34 ((1ULL << SIGNIFICAND_BITS_P_30_34) - 1)
#define EXPONENT_MASK_P_30_34 (((1ULL << EXPONENT_BITS_P_30_34) - 1) << SIGNIFICAND_BITS_P_30_34)
#define SIGNIFICAND_SIGN_MASK_P_30_34 (1ULL << (SIGNIFICAND_BITS_P_30_34 - 1))
#define EXPONENT_SIGN_MASK_P_30_34 (1ULL << (EXPONENT_BITS_P_30_34 - 1))
#define BITS_SIGN_MASK_P_30_34 (1ULL << (BITS_P_30_34 - 1))

#define MAX_VALUE_P_30_34 (((1ULL << (EXPONENT_BITS_P_30_34 - 2)) - 1) << SIGNIFICAND_BITS_P_30_34) | ((1ULL << (SIGNIFICAND_BITS_P_30_34 - 2)) - 1)
#define MIN_VALUE_P_30_34 (((1ULL << (EXPONENT_BITS_P_30_34 - 2)) - 1) << SIGNIFICAND_BITS_P_30_34) | (SIGNIFICAND_SIGN_MASK_P_30_34)

// construct p-adic 3034
p3034_t new_p3034(int64_t exp, int64_t sig);
// exponent part of p-adic 3034
int64_t exp_p3034(p3034_t a);
// significand part of p-adic 3034
int64_t sig_p3034(p3034_t a);
// add p-adic 3034
p3034_t add_p3034(p3034_t a, p3034_t b);
// subtract p-adic 3034
p3034_t sub_p3034(p3034_t a, p3034_t b);
// negate p-adic 3034
p3034_t neg_p3034(p3034_t a);
// multiply p-adic 3034
p3034_t mul_p3034(p3034_t a, p3034_t b);
// divide p-adic 3034
p3034_t div_p3034(p3034_t a, p3034_t b);
// equals p-adic 3034
bool equ_p3034(p3034_t a, p3034_t b);
// compare p-adic 3034
int com_p3034(p3034_t a, p3034_t b);

#endif //C_P_ADIC_30_34_H

