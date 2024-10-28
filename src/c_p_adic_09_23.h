#ifndef C_P_ADIC_09_23_H
#define C_P_ADIC_09_23_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_09_23 9
#define EXPONENT_BITS_P_09_23 06
#define BITS_P_09_23 SIGNIFICAND_BITS_P_09_23 + EXPONENT_BITS_P_09_23

#define C_P_ADIC_09_23_DEBUG true

typedef uint32_t p0923_t;

#define SIGNIFICAND_MASK_P_09_23 ((1ULL << SIGNIFICAND_BITS_P_09_23) - 1)
#define EXPONENT_MASK_P_09_23 (((1ULL << EXPONENT_BITS_P_09_23) - 1) << SIGNIFICAND_BITS_P_09_23)
#define SIGNIFICAND_SIGN_MASK_P_09_23 (1U << (SIGNIFICAND_BITS_P_09_23 - 1))
#define EXPONENT_SIGN_MASK_P_09_23 (1U << (EXPONENT_BITS_P_09_23 - 1))
#define BITS_SIGN_MASK_P_09_23 (1U << (BITS_P_09_23 - 1))

// construct p-adic 0923
p0923_t new_p0923(uint32_t exp, uint32_t sig);
// exponent part of p-adic 0923
uint32_t exp_p0923(p0923_t a);
// significand part of p-adic 0923
uint32_t sig_p0923(p0923_t a);
// add p-adic 0923
p0923_t add_p0923(p0923_t a, p0923_t b);
// subtract p-adic 0923
p0923_t sub_p0923(p0923_t a, p0923_t b);
// negate p-adic 0923
p0923_t neg_p0923(p0923_t a);
// multiply p-adic 0923
p0923_t mul_p0923(p0923_t a, p0923_t b);
// divide p-adic 0923
p0923_t div_p0923(p0923_t a, p0923_t b);
// equals p-adic 0923
bool equ_p0923(p0923_t a, p0923_t b);
// compare p-adic 0923
int com_p0923(p0923_t a, p0923_t b);

#endif //C_P_ADIC_09_23_H

