#ifndef C_P_ADIC_10_22_H
#define C_P_ADIC_10_22_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_10_22 10
#define EXPONENT_BITS_P_10_22 06
#define BITS_P_10_22 SIGNIFICAND_BITS_P_10_22 + EXPONENT_BITS_P_10_22

#define C_P_ADIC_10_22_DEBUG true

typedef uint32_t p1022_t;

#define SIGNIFICAND_MASK_P_10_22 ((1ULL << SIGNIFICAND_BITS_P_10_22) - 1)
#define EXPONENT_MASK_P_10_22 (((1ULL << EXPONENT_BITS_P_10_22) - 1) << SIGNIFICAND_BITS_P_10_22)
#define SIGNIFICAND_SIGN_MASK_P_10_22 (1U << (SIGNIFICAND_BITS_P_10_22 - 1))
#define EXPONENT_SIGN_MASK_P_10_22 (1U << (EXPONENT_BITS_P_10_22 - 1))
#define BITS_SIGN_MASK_P_10_22 (1U << (BITS_P_10_22 - 1))

#define MAX_VALUE_P_10_22 (((1U << (EXPONENT_BITS_P_10_22 - 2)) - 1) << SIGNIFICAND_BITS_P_10_22) | ((1U << (SIGNIFICAND_BITS_P_10_22 - 2)) - 1)
#define MIN_VALUE_P_10_22 (((1U << (EXPONENT_BITS_P_10_22 - 2)) - 1) << SIGNIFICAND_BITS_P_10_22) | (SIGNIFICAND_SIGN_MASK_P_10_22)

// construct p-adic 1022
p1022_t new_p1022(int32_t exp, int32_t sig);
// exponent part of p-adic 1022
int32_t exp_p1022(p1022_t a);
// significand part of p-adic 1022
int32_t sig_p1022(p1022_t a);
// add p-adic 1022
p1022_t add_p1022(p1022_t a, p1022_t b);
// subtract p-adic 1022
p1022_t sub_p1022(p1022_t a, p1022_t b);
// negate p-adic 1022
p1022_t neg_p1022(p1022_t a);
// multiply p-adic 1022
p1022_t mul_p1022(p1022_t a, p1022_t b);
// divide p-adic 1022
p1022_t div_p1022(p1022_t a, p1022_t b);
// equals p-adic 1022
bool equ_p1022(p1022_t a, p1022_t b);
// compare p-adic 1022
int com_p1022(p1022_t a, p1022_t b);

#endif //C_P_ADIC_10_22_H

