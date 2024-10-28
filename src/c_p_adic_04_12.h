#ifndef C_P_ADIC_04_12_H
#define C_P_ADIC_04_12_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_04_12 4
#define EXPONENT_BITS_P_04_12 12
#define BITS_P_04_12 SIGNIFICAND_BITS_P_04_12 + EXPONENT_BITS_P_04_12

#define C_P_ADIC_04_12_DEBUG true

typedef uint16_t p0412_t;

#define SIGNIFICAND_MASK_P_04_12 ((1ULL << SIGNIFICAND_BITS_P_04_12) - 1)
#define EXPONENT_MASK_P_04_12 (((1ULL << EXPONENT_BITS_P_04_12) - 1) << SIGNIFICAND_BITS_P_04_12)
#define SIGNIFICAND_SIGN_MASK_P_04_12 (1U << (SIGNIFICAND_BITS_P_04_12 - 1))
#define EXPONENT_SIGN_MASK_P_04_12 (1U << (EXPONENT_BITS_P_04_12 - 1))
#define BITS_SIGN_MASK_P_04_12 (1U << (BITS_P_04_12 - 1))

// construct p-adic 0412
p0412_t new_p0412(uint16_t exp, uint16_t sig);
// exponent part of p-adic 0412
uint16_t exp_p0412(p0412_t a);
// significand part of p-adic 0412
uint16_t sig_p0412(p0412_t a);
// add p-adic 0412
p0412_t add_p0412(p0412_t a, p0412_t b);
// subtract p-adic 0412
p0412_t sub_p0412(p0412_t a, p0412_t b);
// negate p-adic 0412
p0412_t neg_p0412(p0412_t a);
// multiply p-adic 0412
p0412_t mul_p0412(p0412_t a, p0412_t b);
// divide p-adic 0412
p0412_t div_p0412(p0412_t a, p0412_t b);
// equals p-adic 0412
bool equ_p0412(p0412_t a, p0412_t b);
// compare p-adic 0412
int com_p0412(p0412_t a, p0412_t b);

#endif //C_P_ADIC_04_12_H

