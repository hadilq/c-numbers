#ifndef C_P_ADIC_13_19_H
#define C_P_ADIC_13_19_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_13_19 13
#define EXPONENT_BITS_P_13_19 06
#define BITS_P_13_19 SIGNIFICAND_BITS_P_13_19 + EXPONENT_BITS_P_13_19

#define C_P_ADIC_13_19_DEBUG true

typedef uint32_t p1319_t;

#define SIGNIFICAND_MASK_P_13_19 ((1ULL << SIGNIFICAND_BITS_P_13_19) - 1)
#define EXPONENT_MASK_P_13_19 (((1ULL << EXPONENT_BITS_P_13_19) - 1) << SIGNIFICAND_BITS_P_13_19)
#define SIGNIFICAND_SIGN_MASK_P_13_19 (1U << (SIGNIFICAND_BITS_P_13_19 - 1))
#define EXPONENT_SIGN_MASK_P_13_19 (1U << (EXPONENT_BITS_P_13_19 - 1))
#define BITS_SIGN_MASK_P_13_19 (1U << (BITS_P_13_19 - 1))

#define MAX_VALUE_P_13_19 (((1U << (EXPONENT_BITS_P_13_19 - 2)) - 1) << SIGNIFICAND_BITS_P_13_19) | ((1U << (SIGNIFICAND_BITS_P_13_19 - 2)) - 1)
#define MIN_VALUE_P_13_19 (((1U << (EXPONENT_BITS_P_13_19 - 2)) - 1) << SIGNIFICAND_BITS_P_13_19) | (SIGNIFICAND_SIGN_MASK_P_13_19)

// construct p-adic 1319
p1319_t new_p1319(int32_t exp, int32_t sig);
// exponent part of p-adic 1319
int32_t exp_p1319(p1319_t a);
// significand part of p-adic 1319
int32_t sig_p1319(p1319_t a);
// add p-adic 1319
p1319_t add_p1319(p1319_t a, p1319_t b);
// subtract p-adic 1319
p1319_t sub_p1319(p1319_t a, p1319_t b);
// negate p-adic 1319
p1319_t neg_p1319(p1319_t a);
// multiply p-adic 1319
p1319_t mul_p1319(p1319_t a, p1319_t b);
// divide p-adic 1319
p1319_t div_p1319(p1319_t a, p1319_t b);
// equals p-adic 1319
bool equ_p1319(p1319_t a, p1319_t b);
// compare p-adic 1319
int com_p1319(p1319_t a, p1319_t b);

#endif //C_P_ADIC_13_19_H

