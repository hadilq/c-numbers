#ifndef C_P_ADIC_53_11_H
#define C_P_ADIC_53_11_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_53_11 53
#define EXPONENT_BITS_P_53_11 11
#define BITS_P_53_11 SIGNIFICAND_BITS_P_53_11 + EXPONENT_BITS_P_53_11

#define C_P_ADIC_53_11_DEBUG true

typedef uint64_t p5311_t;

#define SIGNIFICAND_MASK_P_53_11 ((1ULL << SIGNIFICAND_BITS_P_53_11) - 1)
#define EXPONENT_MASK_P_53_11 (((1ULL << EXPONENT_BITS_P_53_11) - 1) << SIGNIFICAND_BITS_P_53_11)
#define SIGNIFICAND_SIGN_MASK_P_53_11 (1ULL << (SIGNIFICAND_BITS_P_53_11 - 1))
#define EXPONENT_SIGN_MASK_P_53_11 (1ULL << (EXPONENT_BITS_P_53_11 - 1))
#define BITS_SIGN_MASK_P_53_11 (1ULL << (BITS_P_53_11 - 1))

#define MAX_VALUE_P_53_11 (((1ULL << (EXPONENT_BITS_P_53_11 - 2)) - 1) << SIGNIFICAND_BITS_P_53_11) | ((1ULL << (SIGNIFICAND_BITS_P_53_11 - 2)) - 1)
#define MIN_VALUE_P_53_11 (((1ULL << (EXPONENT_BITS_P_53_11 - 2)) - 1) << SIGNIFICAND_BITS_P_53_11) | (SIGNIFICAND_SIGN_MASK_P_53_11)

// construct p-adic 5311
p5311_t new_p5311(int64_t exp, int64_t sig);
// exponent part of p-adic 5311
int64_t exp_p5311(p5311_t a);
// significand part of p-adic 5311
int64_t sig_p5311(p5311_t a);
// add p-adic 5311
p5311_t add_p5311(p5311_t a, p5311_t b);
// subtract p-adic 5311
p5311_t sub_p5311(p5311_t a, p5311_t b);
// negate p-adic 5311
p5311_t neg_p5311(p5311_t a);
// multiply p-adic 5311
p5311_t mul_p5311(p5311_t a, p5311_t b);
// divide p-adic 5311
p5311_t div_p5311(p5311_t a, p5311_t b);
// equals p-adic 5311
bool equ_p5311(p5311_t a, p5311_t b);
// compare p-adic 5311
int com_p5311(p5311_t a, p5311_t b);

#endif //C_P_ADIC_53_11_H

