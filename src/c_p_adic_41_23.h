#ifndef C_P_ADIC_41_23_H
#define C_P_ADIC_41_23_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_41_23 41
#define EXPONENT_BITS_P_41_23 23
#define BITS_P_41_23 SIGNIFICAND_BITS_P_41_23 + EXPONENT_BITS_P_41_23

#define C_P_ADIC_41_23_DEBUG true

typedef uint64_t p4123_t;

#define SIGNIFICAND_MASK_P_41_23 ((1ULL << SIGNIFICAND_BITS_P_41_23) - 1)
#define EXPONENT_MASK_P_41_23 (((1ULL << EXPONENT_BITS_P_41_23) - 1) << SIGNIFICAND_BITS_P_41_23)
#define SIGNIFICAND_SIGN_MASK_P_41_23 (1ULL << (SIGNIFICAND_BITS_P_41_23 - 1))
#define EXPONENT_SIGN_MASK_P_41_23 (1ULL << (EXPONENT_BITS_P_41_23 - 1))
#define BITS_SIGN_MASK_P_41_23 (1ULL << (BITS_P_41_23 - 1))

#define MAX_VALUE_P_41_23 (((1ULL << (EXPONENT_BITS_P_41_23 - 2)) - 1) << SIGNIFICAND_BITS_P_41_23) | ((1ULL << (SIGNIFICAND_BITS_P_41_23 - 2)) - 1)
#define MIN_VALUE_P_41_23 (((1ULL << (EXPONENT_BITS_P_41_23 - 2)) - 1) << SIGNIFICAND_BITS_P_41_23) | (SIGNIFICAND_SIGN_MASK_P_41_23)

// construct p-adic 4123
p4123_t new_p4123(int64_t exp, int64_t sig);
// exponent part of p-adic 4123
int64_t exp_p4123(p4123_t a);
// significand part of p-adic 4123
int64_t sig_p4123(p4123_t a);
// add p-adic 4123
p4123_t add_p4123(p4123_t a, p4123_t b);
// subtract p-adic 4123
p4123_t sub_p4123(p4123_t a, p4123_t b);
// negate p-adic 4123
p4123_t neg_p4123(p4123_t a);
// multiply p-adic 4123
p4123_t mul_p4123(p4123_t a, p4123_t b);
// divide p-adic 4123
p4123_t div_p4123(p4123_t a, p4123_t b);
// equals p-adic 4123
bool equ_p4123(p4123_t a, p4123_t b);
// compare p-adic 4123
int com_p4123(p4123_t a, p4123_t b);

#endif //C_P_ADIC_41_23_H

