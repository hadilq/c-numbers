#ifndef C_P_ADIC_47_17_H
#define C_P_ADIC_47_17_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_47_17 47
#define EXPONENT_BITS_P_47_17 17
#define BITS_P_47_17 SIGNIFICAND_BITS_P_47_17 + EXPONENT_BITS_P_47_17

#define C_P_ADIC_47_17_DEBUG true

typedef uint64_t p4717_t;

#define SIGNIFICAND_MASK_P_47_17 ((1ULL << SIGNIFICAND_BITS_P_47_17) - 1)
#define EXPONENT_MASK_P_47_17 (((1ULL << EXPONENT_BITS_P_47_17) - 1) << SIGNIFICAND_BITS_P_47_17)
#define SIGNIFICAND_SIGN_MASK_P_47_17 (1ULL << (SIGNIFICAND_BITS_P_47_17 - 1))
#define EXPONENT_SIGN_MASK_P_47_17 (1ULL << (EXPONENT_BITS_P_47_17 - 1))
#define BITS_SIGN_MASK_P_47_17 (1ULL << (BITS_P_47_17 - 1))

#define MAX_VALUE_P_47_17 (((1ULL << (EXPONENT_BITS_P_47_17 - 2)) - 1) << SIGNIFICAND_BITS_P_47_17) | ((1ULL << (SIGNIFICAND_BITS_P_47_17 - 2)) - 1)
#define MIN_VALUE_P_47_17 (((1ULL << (EXPONENT_BITS_P_47_17 - 2)) - 1) << SIGNIFICAND_BITS_P_47_17) | (SIGNIFICAND_SIGN_MASK_P_47_17)

// construct p-adic 4717
p4717_t new_p4717(int64_t exp, int64_t sig);
// exponent part of p-adic 4717
int64_t exp_p4717(p4717_t a);
// significand part of p-adic 4717
int64_t sig_p4717(p4717_t a);
// add p-adic 4717
p4717_t add_p4717(p4717_t a, p4717_t b);
// subtract p-adic 4717
p4717_t sub_p4717(p4717_t a, p4717_t b);
// negate p-adic 4717
p4717_t neg_p4717(p4717_t a);
// multiply p-adic 4717
p4717_t mul_p4717(p4717_t a, p4717_t b);
// divide p-adic 4717
p4717_t div_p4717(p4717_t a, p4717_t b);
// equals p-adic 4717
bool equ_p4717(p4717_t a, p4717_t b);
// compare p-adic 4717
int com_p4717(p4717_t a, p4717_t b);

#endif //C_P_ADIC_47_17_H

