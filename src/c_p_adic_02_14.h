#ifndef C_P_ADIC_02_14_H
#define C_P_ADIC_02_14_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_02_14 2
#define EXPONENT_BITS_P_02_14 14
#define BITS_P_02_14 SIGNIFICAND_BITS_P_02_14 + EXPONENT_BITS_P_02_14

#define C_P_ADIC_02_14_DEBUG true

typedef uint16_t p0214_t;

#define SIGNIFICAND_MASK_P_02_14 ((1ULL << SIGNIFICAND_BITS_P_02_14) - 1)
#define EXPONENT_MASK_P_02_14 (((1ULL << EXPONENT_BITS_P_02_14) - 1) << SIGNIFICAND_BITS_P_02_14)
#define SIGNIFICAND_SIGN_MASK_P_02_14 (1U << (SIGNIFICAND_BITS_P_02_14 - 1))
#define EXPONENT_SIGN_MASK_P_02_14 (1U << (EXPONENT_BITS_P_02_14 - 1))
#define BITS_SIGN_MASK_P_02_14 (1U << (BITS_P_02_14 - 1))

// construct p-adic 0214
p0214_t new_p0214(uint16_t exp, uint16_t sig);
// exponent part of p-adic 0214
uint16_t exp_p0214(p0214_t a);
// significand part of p-adic 0214
uint16_t sig_p0214(p0214_t a);
// add p-adic 0214
p0214_t add_p0214(p0214_t a, p0214_t b);
// subtract p-adic 0214
p0214_t sub_p0214(p0214_t a, p0214_t b);
// negate p-adic 0214
p0214_t neg_p0214(p0214_t a);
// multiply p-adic 0214
p0214_t mul_p0214(p0214_t a, p0214_t b);
// divide p-adic 0214
p0214_t div_p0214(p0214_t a, p0214_t b);
// equals p-adic 0214
bool equ_p0214(p0214_t a, p0214_t b);
// compare p-adic 0214
int com_p0214(p0214_t a, p0214_t b);

#endif //C_P_ADIC_02_14_H

