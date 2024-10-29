#ifndef C_P_ADIC_35_29_H
#define C_P_ADIC_35_29_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_35_29 35
#define EXPONENT_BITS_P_35_29 29
#define BITS_P_35_29 SIGNIFICAND_BITS_P_35_29 + EXPONENT_BITS_P_35_29

#define C_P_ADIC_35_29_DEBUG true

typedef uint64_t p3529_t;

#define SIGNIFICAND_MASK_P_35_29 ((1ULL << SIGNIFICAND_BITS_P_35_29) - 1)
#define EXPONENT_MASK_P_35_29 (((1ULL << EXPONENT_BITS_P_35_29) - 1) << SIGNIFICAND_BITS_P_35_29)
#define SIGNIFICAND_SIGN_MASK_P_35_29 (1ULL << (SIGNIFICAND_BITS_P_35_29 - 1))
#define EXPONENT_SIGN_MASK_P_35_29 (1ULL << (EXPONENT_BITS_P_35_29 - 1))
#define BITS_SIGN_MASK_P_35_29 (1ULL << (BITS_P_35_29 - 1))

#define MAX_VALUE_P_35_29 (((1ULL << (EXPONENT_BITS_P_35_29 - 2)) - 1) << SIGNIFICAND_BITS_P_35_29) | ((1ULL << (SIGNIFICAND_BITS_P_35_29 - 2)) - 1)
#define MIN_VALUE_P_35_29 (((1ULL << (EXPONENT_BITS_P_35_29 - 2)) - 1) << SIGNIFICAND_BITS_P_35_29) | (SIGNIFICAND_SIGN_MASK_P_35_29)

// construct p-adic 3529
p3529_t new_p3529(int64_t exp, int64_t sig);
// exponent part of p-adic 3529
int64_t exp_p3529(p3529_t a);
// significand part of p-adic 3529
int64_t sig_p3529(p3529_t a);
// add p-adic 3529
p3529_t add_p3529(p3529_t a, p3529_t b);
// subtract p-adic 3529
p3529_t sub_p3529(p3529_t a, p3529_t b);
// negate p-adic 3529
p3529_t neg_p3529(p3529_t a);
// multiply p-adic 3529
p3529_t mul_p3529(p3529_t a, p3529_t b);
// divide p-adic 3529
p3529_t div_p3529(p3529_t a, p3529_t b);
// equals p-adic 3529
bool equ_p3529(p3529_t a, p3529_t b);
// compare p-adic 3529
int com_p3529(p3529_t a, p3529_t b);

#endif //C_P_ADIC_35_29_H

