#ifndef C_P_ADIC_36_28_H
#define C_P_ADIC_36_28_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_36_28 36
#define EXPONENT_BITS_P_36_28 28
#define BITS_P_36_28 SIGNIFICAND_BITS_P_36_28 + EXPONENT_BITS_P_36_28

#define C_P_ADIC_36_28_DEBUG true

typedef uint64_t p3628_t;

#define SIGNIFICAND_MASK_P_36_28 ((1ULL << SIGNIFICAND_BITS_P_36_28) - 1)
#define EXPONENT_MASK_P_36_28 (((1ULL << EXPONENT_BITS_P_36_28) - 1) << SIGNIFICAND_BITS_P_36_28)
#define SIGNIFICAND_SIGN_MASK_P_36_28 (1ULL << (SIGNIFICAND_BITS_P_36_28 - 1))
#define EXPONENT_SIGN_MASK_P_36_28 (1ULL << (EXPONENT_BITS_P_36_28 - 1))
#define BITS_SIGN_MASK_P_36_28 (1ULL << (BITS_P_36_28 - 1))

#define MAX_VALUE_P_36_28 (((1ULL << (EXPONENT_BITS_P_36_28 - 2)) - 1) << SIGNIFICAND_BITS_P_36_28) | ((1ULL << (SIGNIFICAND_BITS_P_36_28 - 2)) - 1)
#define MIN_VALUE_P_36_28 (((1ULL << (EXPONENT_BITS_P_36_28 - 2)) - 1) << SIGNIFICAND_BITS_P_36_28) | (SIGNIFICAND_SIGN_MASK_P_36_28)

// construct p-adic 3628
p3628_t new_p3628(int64_t exp, int64_t sig);
// exponent part of p-adic 3628
int64_t exp_p3628(p3628_t a);
// significand part of p-adic 3628
int64_t sig_p3628(p3628_t a);
// add p-adic 3628
p3628_t add_p3628(p3628_t a, p3628_t b);
// subtract p-adic 3628
p3628_t sub_p3628(p3628_t a, p3628_t b);
// negate p-adic 3628
p3628_t neg_p3628(p3628_t a);
// multiply p-adic 3628
p3628_t mul_p3628(p3628_t a, p3628_t b);
// divide p-adic 3628
p3628_t div_p3628(p3628_t a, p3628_t b);
// equals p-adic 3628
bool equ_p3628(p3628_t a, p3628_t b);
// compare p-adic 3628
int com_p3628(p3628_t a, p3628_t b);

#endif //C_P_ADIC_36_28_H

