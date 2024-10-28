#ifndef C_P_ADIC_04_28_H
#define C_P_ADIC_04_28_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_04_28 4
#define EXPONENT_BITS_P_04_28 06
#define BITS_P_04_28 SIGNIFICAND_BITS_P_04_28 + EXPONENT_BITS_P_04_28

#define C_P_ADIC_04_28_DEBUG true

typedef uint32_t p0428_t;

#define SIGNIFICAND_MASK_P_04_28 ((1ULL << SIGNIFICAND_BITS_P_04_28) - 1)
#define EXPONENT_MASK_P_04_28 (((1ULL << EXPONENT_BITS_P_04_28) - 1) << SIGNIFICAND_BITS_P_04_28)
#define SIGNIFICAND_SIGN_MASK_P_04_28 (1U << (SIGNIFICAND_BITS_P_04_28 - 1))
#define EXPONENT_SIGN_MASK_P_04_28 (1U << (EXPONENT_BITS_P_04_28 - 1))
#define BITS_SIGN_MASK_P_04_28 (1U << (BITS_P_04_28 - 1))

// construct p-adic 0428
p0428_t new_p0428(uint32_t exp, uint32_t sig);
// exponent part of p-adic 0428
uint32_t exp_p0428(p0428_t a);
// significand part of p-adic 0428
uint32_t sig_p0428(p0428_t a);
// add p-adic 0428
p0428_t add_p0428(p0428_t a, p0428_t b);
// subtract p-adic 0428
p0428_t sub_p0428(p0428_t a, p0428_t b);
// negate p-adic 0428
p0428_t neg_p0428(p0428_t a);
// multiply p-adic 0428
p0428_t mul_p0428(p0428_t a, p0428_t b);
// divide p-adic 0428
p0428_t div_p0428(p0428_t a, p0428_t b);
// equals p-adic 0428
bool equ_p0428(p0428_t a, p0428_t b);
// compare p-adic 0428
int com_p0428(p0428_t a, p0428_t b);

#endif //C_P_ADIC_04_28_H

