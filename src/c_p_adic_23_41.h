#ifndef C_P_ADIC_23_41_H
#define C_P_ADIC_23_41_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_23_41 23
#define EXPONENT_BITS_P_23_41 41
#define BITS_P_23_41 SIGNIFICAND_BITS_P_23_41 + EXPONENT_BITS_P_23_41

#define C_P_ADIC_23_41_DEBUG true

typedef uint64_t p2341_t;

#define SIGNIFICAND_MASK_P_23_41 ((1ULL << SIGNIFICAND_BITS_P_23_41) - 1)
#define EXPONENT_MASK_P_23_41 (((1ULL << EXPONENT_BITS_P_23_41) - 1) << SIGNIFICAND_BITS_P_23_41)
#define SIGNIFICAND_SIGN_MASK_P_23_41 (1ULL << (SIGNIFICAND_BITS_P_23_41 - 1))
#define EXPONENT_SIGN_MASK_P_23_41 (1ULL << (EXPONENT_BITS_P_23_41 - 1))
#define BITS_SIGN_MASK_P_23_41 (1ULL << (BITS_P_23_41 - 1))

#define MAX_VALUE_P_23_41 (((1ULL << (EXPONENT_BITS_P_23_41 - 2)) - 1) << SIGNIFICAND_BITS_P_23_41) | ((1ULL << (SIGNIFICAND_BITS_P_23_41 - 2)) - 1)
#define MIN_VALUE_P_23_41 (((1ULL << (EXPONENT_BITS_P_23_41 - 2)) - 1) << SIGNIFICAND_BITS_P_23_41) | (SIGNIFICAND_SIGN_MASK_P_23_41)

// construct p-adic 2341
p2341_t new_p2341(int64_t exp, int64_t sig);
// exponent part of p-adic 2341
int64_t exp_p2341(p2341_t a);
// significand part of p-adic 2341
int64_t sig_p2341(p2341_t a);
// add p-adic 2341
p2341_t add_p2341(p2341_t a, p2341_t b);
// subtract p-adic 2341
p2341_t sub_p2341(p2341_t a, p2341_t b);
// negate p-adic 2341
p2341_t neg_p2341(p2341_t a);
// multiply p-adic 2341
p2341_t mul_p2341(p2341_t a, p2341_t b);
// divide p-adic 2341
p2341_t div_p2341(p2341_t a, p2341_t b);
// equals p-adic 2341
bool equ_p2341(p2341_t a, p2341_t b);
// compare p-adic 2341
int com_p2341(p2341_t a, p2341_t b);

#endif //C_P_ADIC_23_41_H

