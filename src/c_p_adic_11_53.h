#ifndef C_P_ADIC_11_53_H
#define C_P_ADIC_11_53_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_11_53 11
#define EXPONENT_BITS_P_11_53 53
#define BITS_P_11_53 SIGNIFICAND_BITS_P_11_53 + EXPONENT_BITS_P_11_53

#define C_P_ADIC_11_53_DEBUG true

typedef uint64_t p1153_t;

#define SIGNIFICAND_MASK_P_11_53 ((1ULL << SIGNIFICAND_BITS_P_11_53) - 1)
#define EXPONENT_MASK_P_11_53 (((1ULL << EXPONENT_BITS_P_11_53) - 1) << SIGNIFICAND_BITS_P_11_53)
#define SIGNIFICAND_SIGN_MASK_P_11_53 (1ULL << (SIGNIFICAND_BITS_P_11_53 - 1))
#define EXPONENT_SIGN_MASK_P_11_53 (1ULL << (EXPONENT_BITS_P_11_53 - 1))
#define BITS_SIGN_MASK_P_11_53 (1ULL << (BITS_P_11_53 - 1))

// construct p-adic 1153
p1153_t new_p1153(uint64_t exp, uint64_t sig);
// exponent part of p-adic 1153
uint64_t exp_p1153(p1153_t a);
// significand part of p-adic 1153
uint64_t sig_p1153(p1153_t a);
// add p-adic 1153
p1153_t add_p1153(p1153_t a, p1153_t b);
// subtract p-adic 1153
p1153_t sub_p1153(p1153_t a, p1153_t b);
// negate p-adic 1153
p1153_t neg_p1153(p1153_t a);
// multiply p-adic 1153
p1153_t mul_p1153(p1153_t a, p1153_t b);
// divide p-adic 1153
p1153_t div_p1153(p1153_t a, p1153_t b);
// equals p-adic 1153
bool equ_p1153(p1153_t a, p1153_t b);
// compare p-adic 1153
int com_p1153(p1153_t a, p1153_t b);

#endif //C_P_ADIC_11_53_H

