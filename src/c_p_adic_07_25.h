#ifndef C_P_ADIC_07_25_H
#define C_P_ADIC_07_25_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_07_25 7
#define EXPONENT_BITS_P_07_25 06
#define BITS_P_07_25 SIGNIFICAND_BITS_P_07_25 + EXPONENT_BITS_P_07_25

#define C_P_ADIC_07_25_DEBUG true

typedef uint32_t p0725_t;

#define SIGNIFICAND_MASK_P_07_25 ((1ULL << SIGNIFICAND_BITS_P_07_25) - 1)
#define EXPONENT_MASK_P_07_25 (((1ULL << EXPONENT_BITS_P_07_25) - 1) << SIGNIFICAND_BITS_P_07_25)
#define SIGNIFICAND_SIGN_MASK_P_07_25 (1U << (SIGNIFICAND_BITS_P_07_25 - 1))
#define EXPONENT_SIGN_MASK_P_07_25 (1U << (EXPONENT_BITS_P_07_25 - 1))
#define BITS_SIGN_MASK_P_07_25 (1U << (BITS_P_07_25 - 1))

// construct p-adic 0725
p0725_t new_p0725(uint32_t exp, uint32_t sig);
// exponent part of p-adic 0725
uint32_t exp_p0725(p0725_t a);
// significand part of p-adic 0725
uint32_t sig_p0725(p0725_t a);
// add p-adic 0725
p0725_t add_p0725(p0725_t a, p0725_t b);
// subtract p-adic 0725
p0725_t sub_p0725(p0725_t a, p0725_t b);
// negate p-adic 0725
p0725_t neg_p0725(p0725_t a);
// multiply p-adic 0725
p0725_t mul_p0725(p0725_t a, p0725_t b);
// divide p-adic 0725
p0725_t div_p0725(p0725_t a, p0725_t b);
// equals p-adic 0725
bool equ_p0725(p0725_t a, p0725_t b);
// compare p-adic 0725
int com_p0725(p0725_t a, p0725_t b);

#endif //C_P_ADIC_07_25_H

