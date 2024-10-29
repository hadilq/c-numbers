#ifndef C_P_ADIC_06_26_H
#define C_P_ADIC_06_26_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_06_26 6
#define EXPONENT_BITS_P_06_26 06
#define BITS_P_06_26 SIGNIFICAND_BITS_P_06_26 + EXPONENT_BITS_P_06_26

#define C_P_ADIC_06_26_DEBUG true

typedef uint32_t p0626_t;

#define SIGNIFICAND_MASK_P_06_26 ((1ULL << SIGNIFICAND_BITS_P_06_26) - 1)
#define EXPONENT_MASK_P_06_26 (((1ULL << EXPONENT_BITS_P_06_26) - 1) << SIGNIFICAND_BITS_P_06_26)
#define SIGNIFICAND_SIGN_MASK_P_06_26 (1U << (SIGNIFICAND_BITS_P_06_26 - 1))
#define EXPONENT_SIGN_MASK_P_06_26 (1U << (EXPONENT_BITS_P_06_26 - 1))
#define BITS_SIGN_MASK_P_06_26 (1U << (BITS_P_06_26 - 1))

#define MAX_VALUE_P_06_26 (((1U << (EXPONENT_BITS_P_06_26 - 2)) - 1) << SIGNIFICAND_BITS_P_06_26) | ((1U << (SIGNIFICAND_BITS_P_06_26 - 2)) - 1)
#define MIN_VALUE_P_06_26 (((1U << (EXPONENT_BITS_P_06_26 - 2)) - 1) << SIGNIFICAND_BITS_P_06_26) | (SIGNIFICAND_SIGN_MASK_P_06_26)

// construct p-adic 0626
p0626_t new_p0626(int32_t exp, int32_t sig);
// exponent part of p-adic 0626
int32_t exp_p0626(p0626_t a);
// significand part of p-adic 0626
int32_t sig_p0626(p0626_t a);
// add p-adic 0626
p0626_t add_p0626(p0626_t a, p0626_t b);
// subtract p-adic 0626
p0626_t sub_p0626(p0626_t a, p0626_t b);
// negate p-adic 0626
p0626_t neg_p0626(p0626_t a);
// multiply p-adic 0626
p0626_t mul_p0626(p0626_t a, p0626_t b);
// divide p-adic 0626
p0626_t div_p0626(p0626_t a, p0626_t b);
// equals p-adic 0626
bool equ_p0626(p0626_t a, p0626_t b);
// compare p-adic 0626
int com_p0626(p0626_t a, p0626_t b);

#endif //C_P_ADIC_06_26_H

