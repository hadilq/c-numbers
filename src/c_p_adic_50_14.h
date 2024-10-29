#ifndef C_P_ADIC_50_14_H
#define C_P_ADIC_50_14_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_50_14 50
#define EXPONENT_BITS_P_50_14 14
#define BITS_P_50_14 SIGNIFICAND_BITS_P_50_14 + EXPONENT_BITS_P_50_14

#define C_P_ADIC_50_14_DEBUG true

typedef uint64_t p5014_t;

#define SIGNIFICAND_MASK_P_50_14 ((1ULL << SIGNIFICAND_BITS_P_50_14) - 1)
#define EXPONENT_MASK_P_50_14 (((1ULL << EXPONENT_BITS_P_50_14) - 1) << SIGNIFICAND_BITS_P_50_14)
#define SIGNIFICAND_SIGN_MASK_P_50_14 (1ULL << (SIGNIFICAND_BITS_P_50_14 - 1))
#define EXPONENT_SIGN_MASK_P_50_14 (1ULL << (EXPONENT_BITS_P_50_14 - 1))
#define BITS_SIGN_MASK_P_50_14 (1ULL << (BITS_P_50_14 - 1))

#define MAX_VALUE_P_50_14 (((1ULL << (EXPONENT_BITS_P_50_14 - 2)) - 1) << SIGNIFICAND_BITS_P_50_14) | ((1ULL << (SIGNIFICAND_BITS_P_50_14 - 2)) - 1)
#define MIN_VALUE_P_50_14 (((1ULL << (EXPONENT_BITS_P_50_14 - 2)) - 1) << SIGNIFICAND_BITS_P_50_14) | (SIGNIFICAND_SIGN_MASK_P_50_14)

// construct p-adic 5014
p5014_t new_p5014(int64_t exp, int64_t sig);
// exponent part of p-adic 5014
int64_t exp_p5014(p5014_t a);
// significand part of p-adic 5014
int64_t sig_p5014(p5014_t a);
// add p-adic 5014
p5014_t add_p5014(p5014_t a, p5014_t b);
// subtract p-adic 5014
p5014_t sub_p5014(p5014_t a, p5014_t b);
// negate p-adic 5014
p5014_t neg_p5014(p5014_t a);
// multiply p-adic 5014
p5014_t mul_p5014(p5014_t a, p5014_t b);
// divide p-adic 5014
p5014_t div_p5014(p5014_t a, p5014_t b);
// equals p-adic 5014
bool equ_p5014(p5014_t a, p5014_t b);
// compare p-adic 5014
int com_p5014(p5014_t a, p5014_t b);

#endif //C_P_ADIC_50_14_H

