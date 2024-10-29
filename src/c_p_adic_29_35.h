#ifndef C_P_ADIC_29_35_H
#define C_P_ADIC_29_35_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_29_35 29
#define EXPONENT_BITS_P_29_35 35
#define BITS_P_29_35 SIGNIFICAND_BITS_P_29_35 + EXPONENT_BITS_P_29_35

#define C_P_ADIC_29_35_DEBUG true

typedef uint64_t p2935_t;

#define SIGNIFICAND_MASK_P_29_35 ((1ULL << SIGNIFICAND_BITS_P_29_35) - 1)
#define EXPONENT_MASK_P_29_35 (((1ULL << EXPONENT_BITS_P_29_35) - 1) << SIGNIFICAND_BITS_P_29_35)
#define SIGNIFICAND_SIGN_MASK_P_29_35 (1ULL << (SIGNIFICAND_BITS_P_29_35 - 1))
#define EXPONENT_SIGN_MASK_P_29_35 (1ULL << (EXPONENT_BITS_P_29_35 - 1))
#define BITS_SIGN_MASK_P_29_35 (1ULL << (BITS_P_29_35 - 1))

#define MAX_VALUE_P_29_35 (((1ULL << (EXPONENT_BITS_P_29_35 - 2)) - 1) << SIGNIFICAND_BITS_P_29_35) | ((1ULL << (SIGNIFICAND_BITS_P_29_35 - 2)) - 1)
#define MIN_VALUE_P_29_35 (((1ULL << (EXPONENT_BITS_P_29_35 - 2)) - 1) << SIGNIFICAND_BITS_P_29_35) | (SIGNIFICAND_SIGN_MASK_P_29_35)

// construct p-adic 2935
p2935_t new_p2935(int64_t exp, int64_t sig);
// exponent part of p-adic 2935
int64_t exp_p2935(p2935_t a);
// significand part of p-adic 2935
int64_t sig_p2935(p2935_t a);
// add p-adic 2935
p2935_t add_p2935(p2935_t a, p2935_t b);
// subtract p-adic 2935
p2935_t sub_p2935(p2935_t a, p2935_t b);
// negate p-adic 2935
p2935_t neg_p2935(p2935_t a);
// multiply p-adic 2935
p2935_t mul_p2935(p2935_t a, p2935_t b);
// divide p-adic 2935
p2935_t div_p2935(p2935_t a, p2935_t b);
// equals p-adic 2935
bool equ_p2935(p2935_t a, p2935_t b);
// compare p-adic 2935
int com_p2935(p2935_t a, p2935_t b);

#endif //C_P_ADIC_29_35_H

