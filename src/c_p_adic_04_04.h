#ifndef C_P_ADIC_04_04_H
#define C_P_ADIC_04_04_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_04_04 04
#define EXPONENT_BITS_P_04_04 04
#define BITS_P_04_04 SIGNIFICAND_BITS_P_04_04 + EXPONENT_BITS_P_04_04

#define C_P_ADIC_04_04_DEBUG true

typedef uint8_t p0404_t;

#define SIGNIFICAND_MASK_P_04_04 ((1ULL << SIGNIFICAND_BITS_P_04_04) - 1)
#define EXPONENT_MASK_P_04_04 (((1ULL << EXPONENT_BITS_P_04_04) - 1) << SIGNIFICAND_BITS_P_04_04)
#define SIGNIFICAND_SIGN_MASK_P_04_04 (1U << (SIGNIFICAND_BITS_P_04_04 - 1))
#define EXPONENT_SIGN_MASK_P_04_04 (1U << (EXPONENT_BITS_P_04_04 - 1))

// construct p-adic 04 04
p0404_t new_p0404(uint8_t exp, uint8_t sig);
// exponent part of p-adic 04 04
uint8_t exp_p0404(p0404_t a);
// significand part of p-adic 04 04
uint8_t sig_p0404(p0404_t a);
// add p-adic 04 04
p0404_t add_p0404(p0404_t a, p0404_t b);
// subtract p-adic 04 04
p0404_t sub_p0404(p0404_t a, p0404_t b);
// negate p-adic 04 04
p0404_t neg_p0404(p0404_t a);
// multiply p-adic 04 04
p0404_t mul_p0404(p0404_t a, p0404_t b);
// divide p-adic 04 04
p0404_t div_p0404(p0404_t a, p0404_t b);
// equals p-adic 04 04
bool equ_p0404(p0404_t a, p0404_t b);
// compare p-adic 04 04
int com_p0404(p0404_t a, p0404_t b);

#endif //C_P_ADIC_04_04_H

