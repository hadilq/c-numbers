#ifndef C_P_ADIC_49_15_H
#define C_P_ADIC_49_15_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_49_15 49
#define EXPONENT_BITS_P_49_15 15
#define BITS_P_49_15 SIGNIFICAND_BITS_P_49_15 + EXPONENT_BITS_P_49_15

#define C_P_ADIC_49_15_DEBUG true

typedef uint64_t p4915_t;

#define SIGNIFICAND_MASK_P_49_15 ((1ULL << SIGNIFICAND_BITS_P_49_15) - 1)
#define EXPONENT_MASK_P_49_15 (((1ULL << EXPONENT_BITS_P_49_15) - 1) << SIGNIFICAND_BITS_P_49_15)
#define SIGNIFICAND_SIGN_MASK_P_49_15 (1ULL << (SIGNIFICAND_BITS_P_49_15 - 1))
#define EXPONENT_SIGN_MASK_P_49_15 (1ULL << (EXPONENT_BITS_P_49_15 - 1))
#define BITS_SIGN_MASK_P_49_15 (1ULL << (BITS_P_49_15 - 1))

#define MAX_VALUE_P_49_15 (((1ULL << (EXPONENT_BITS_P_49_15 - 2)) - 1) << SIGNIFICAND_BITS_P_49_15) | ((1ULL << (SIGNIFICAND_BITS_P_49_15 - 2)) - 1)
#define MIN_VALUE_P_49_15 (((1ULL << (EXPONENT_BITS_P_49_15 - 2)) - 1) << SIGNIFICAND_BITS_P_49_15) | (SIGNIFICAND_SIGN_MASK_P_49_15)

// construct p-adic 4915
p4915_t new_p4915(int64_t exp, int64_t sig);
// exponent part of p-adic 4915
int64_t exp_p4915(p4915_t a);
// significand part of p-adic 4915
int64_t sig_p4915(p4915_t a);
// add p-adic 4915
p4915_t add_p4915(p4915_t a, p4915_t b);
// subtract p-adic 4915
p4915_t sub_p4915(p4915_t a, p4915_t b);
// negate p-adic 4915
p4915_t neg_p4915(p4915_t a);
// multiply p-adic 4915
p4915_t mul_p4915(p4915_t a, p4915_t b);
// divide p-adic 4915
p4915_t div_p4915(p4915_t a, p4915_t b);
// equals p-adic 4915
bool equ_p4915(p4915_t a, p4915_t b);
// compare p-adic 4915
int com_p4915(p4915_t a, p4915_t b);

#endif //C_P_ADIC_49_15_H

