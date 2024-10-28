#ifndef C_P_ADIC_24_08_H
#define C_P_ADIC_24_08_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_24_08 24
#define EXPONENT_BITS_P_24_08 06
#define BITS_P_24_08 SIGNIFICAND_BITS_P_24_08 + EXPONENT_BITS_P_24_08

#define C_P_ADIC_24_08_DEBUG true

typedef uint32_t p2408_t;

#define SIGNIFICAND_MASK_P_24_08 ((1ULL << SIGNIFICAND_BITS_P_24_08) - 1)
#define EXPONENT_MASK_P_24_08 (((1ULL << EXPONENT_BITS_P_24_08) - 1) << SIGNIFICAND_BITS_P_24_08)
#define SIGNIFICAND_SIGN_MASK_P_24_08 (1U << (SIGNIFICAND_BITS_P_24_08 - 1))
#define EXPONENT_SIGN_MASK_P_24_08 (1U << (EXPONENT_BITS_P_24_08 - 1))
#define BITS_SIGN_MASK_P_24_08 (1U << (BITS_P_24_08 - 1))

// construct p-adic 2408
p2408_t new_p2408(uint32_t exp, uint32_t sig);
// exponent part of p-adic 2408
uint32_t exp_p2408(p2408_t a);
// significand part of p-adic 2408
uint32_t sig_p2408(p2408_t a);
// add p-adic 2408
p2408_t add_p2408(p2408_t a, p2408_t b);
// subtract p-adic 2408
p2408_t sub_p2408(p2408_t a, p2408_t b);
// negate p-adic 2408
p2408_t neg_p2408(p2408_t a);
// multiply p-adic 2408
p2408_t mul_p2408(p2408_t a, p2408_t b);
// divide p-adic 2408
p2408_t div_p2408(p2408_t a, p2408_t b);
// equals p-adic 2408
bool equ_p2408(p2408_t a, p2408_t b);
// compare p-adic 2408
int com_p2408(p2408_t a, p2408_t b);

#endif //C_P_ADIC_24_08_H

