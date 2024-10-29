#ifndef C_P_ADIC_42_22_H
#define C_P_ADIC_42_22_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_42_22 42
#define EXPONENT_BITS_P_42_22 22
#define BITS_P_42_22 SIGNIFICAND_BITS_P_42_22 + EXPONENT_BITS_P_42_22

#define C_P_ADIC_42_22_DEBUG true

typedef uint64_t p4222_t;

#define SIGNIFICAND_MASK_P_42_22 ((1ULL << SIGNIFICAND_BITS_P_42_22) - 1)
#define EXPONENT_MASK_P_42_22 (((1ULL << EXPONENT_BITS_P_42_22) - 1) << SIGNIFICAND_BITS_P_42_22)
#define SIGNIFICAND_SIGN_MASK_P_42_22 (1ULL << (SIGNIFICAND_BITS_P_42_22 - 1))
#define EXPONENT_SIGN_MASK_P_42_22 (1ULL << (EXPONENT_BITS_P_42_22 - 1))
#define BITS_SIGN_MASK_P_42_22 (1ULL << (BITS_P_42_22 - 1))

#define MAX_VALUE_P_42_22 (((1ULL << (EXPONENT_BITS_P_42_22 - 2)) - 1) << SIGNIFICAND_BITS_P_42_22) | ((1ULL << (SIGNIFICAND_BITS_P_42_22 - 2)) - 1)
#define MIN_VALUE_P_42_22 (((1ULL << (EXPONENT_BITS_P_42_22 - 2)) - 1) << SIGNIFICAND_BITS_P_42_22) | (SIGNIFICAND_SIGN_MASK_P_42_22)

// construct p-adic 4222
p4222_t new_p4222(int64_t exp, int64_t sig);
// exponent part of p-adic 4222
int64_t exp_p4222(p4222_t a);
// significand part of p-adic 4222
int64_t sig_p4222(p4222_t a);
// add p-adic 4222
p4222_t add_p4222(p4222_t a, p4222_t b);
// subtract p-adic 4222
p4222_t sub_p4222(p4222_t a, p4222_t b);
// negate p-adic 4222
p4222_t neg_p4222(p4222_t a);
// multiply p-adic 4222
p4222_t mul_p4222(p4222_t a, p4222_t b);
// divide p-adic 4222
p4222_t div_p4222(p4222_t a, p4222_t b);
// equals p-adic 4222
bool equ_p4222(p4222_t a, p4222_t b);
// compare p-adic 4222
int com_p4222(p4222_t a, p4222_t b);

#endif //C_P_ADIC_42_22_H

