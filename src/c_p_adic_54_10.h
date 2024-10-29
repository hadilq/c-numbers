#ifndef C_P_ADIC_54_10_H
#define C_P_ADIC_54_10_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_54_10 54
#define EXPONENT_BITS_P_54_10 10
#define BITS_P_54_10 SIGNIFICAND_BITS_P_54_10 + EXPONENT_BITS_P_54_10

#define C_P_ADIC_54_10_DEBUG true

typedef uint64_t p5410_t;

#define SIGNIFICAND_MASK_P_54_10 ((1ULL << SIGNIFICAND_BITS_P_54_10) - 1)
#define EXPONENT_MASK_P_54_10 (((1ULL << EXPONENT_BITS_P_54_10) - 1) << SIGNIFICAND_BITS_P_54_10)
#define SIGNIFICAND_SIGN_MASK_P_54_10 (1ULL << (SIGNIFICAND_BITS_P_54_10 - 1))
#define EXPONENT_SIGN_MASK_P_54_10 (1ULL << (EXPONENT_BITS_P_54_10 - 1))
#define BITS_SIGN_MASK_P_54_10 (1ULL << (BITS_P_54_10 - 1))

#define MAX_VALUE_P_54_10 (((1ULL << (EXPONENT_BITS_P_54_10 - 2)) - 1) << SIGNIFICAND_BITS_P_54_10) | ((1ULL << (SIGNIFICAND_BITS_P_54_10 - 2)) - 1)
#define MIN_VALUE_P_54_10 (((1ULL << (EXPONENT_BITS_P_54_10 - 2)) - 1) << SIGNIFICAND_BITS_P_54_10) | (SIGNIFICAND_SIGN_MASK_P_54_10)

// construct p-adic 5410
p5410_t new_p5410(int64_t exp, int64_t sig);
// exponent part of p-adic 5410
int64_t exp_p5410(p5410_t a);
// significand part of p-adic 5410
int64_t sig_p5410(p5410_t a);
// add p-adic 5410
p5410_t add_p5410(p5410_t a, p5410_t b);
// subtract p-adic 5410
p5410_t sub_p5410(p5410_t a, p5410_t b);
// negate p-adic 5410
p5410_t neg_p5410(p5410_t a);
// multiply p-adic 5410
p5410_t mul_p5410(p5410_t a, p5410_t b);
// divide p-adic 5410
p5410_t div_p5410(p5410_t a, p5410_t b);
// equals p-adic 5410
bool equ_p5410(p5410_t a, p5410_t b);
// compare p-adic 5410
int com_p5410(p5410_t a, p5410_t b);

#endif //C_P_ADIC_54_10_H

