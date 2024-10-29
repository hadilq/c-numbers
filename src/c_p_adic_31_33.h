#ifndef C_P_ADIC_31_33_H
#define C_P_ADIC_31_33_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_31_33 31
#define EXPONENT_BITS_P_31_33 33
#define BITS_P_31_33 SIGNIFICAND_BITS_P_31_33 + EXPONENT_BITS_P_31_33

#define C_P_ADIC_31_33_DEBUG true

typedef uint64_t p3133_t;

#define SIGNIFICAND_MASK_P_31_33 ((1ULL << SIGNIFICAND_BITS_P_31_33) - 1)
#define EXPONENT_MASK_P_31_33 (((1ULL << EXPONENT_BITS_P_31_33) - 1) << SIGNIFICAND_BITS_P_31_33)
#define SIGNIFICAND_SIGN_MASK_P_31_33 (1ULL << (SIGNIFICAND_BITS_P_31_33 - 1))
#define EXPONENT_SIGN_MASK_P_31_33 (1ULL << (EXPONENT_BITS_P_31_33 - 1))
#define BITS_SIGN_MASK_P_31_33 (1ULL << (BITS_P_31_33 - 1))

#define MAX_VALUE_P_31_33 (((1ULL << (EXPONENT_BITS_P_31_33 - 2)) - 1) << SIGNIFICAND_BITS_P_31_33) | ((1ULL << (SIGNIFICAND_BITS_P_31_33 - 2)) - 1)
#define MIN_VALUE_P_31_33 (((1ULL << (EXPONENT_BITS_P_31_33 - 2)) - 1) << SIGNIFICAND_BITS_P_31_33) | (SIGNIFICAND_SIGN_MASK_P_31_33)

// construct p-adic 3133
p3133_t new_p3133(int64_t exp, int64_t sig);
// exponent part of p-adic 3133
int64_t exp_p3133(p3133_t a);
// significand part of p-adic 3133
int64_t sig_p3133(p3133_t a);
// add p-adic 3133
p3133_t add_p3133(p3133_t a, p3133_t b);
// subtract p-adic 3133
p3133_t sub_p3133(p3133_t a, p3133_t b);
// negate p-adic 3133
p3133_t neg_p3133(p3133_t a);
// multiply p-adic 3133
p3133_t mul_p3133(p3133_t a, p3133_t b);
// divide p-adic 3133
p3133_t div_p3133(p3133_t a, p3133_t b);
// equals p-adic 3133
bool equ_p3133(p3133_t a, p3133_t b);
// compare p-adic 3133
int com_p3133(p3133_t a, p3133_t b);

#endif //C_P_ADIC_31_33_H

