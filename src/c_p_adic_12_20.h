#ifndef C_P_ADIC_12_20_H
#define C_P_ADIC_12_20_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_12_20 12
#define EXPONENT_BITS_P_12_20 06
#define BITS_P_12_20 SIGNIFICAND_BITS_P_12_20 + EXPONENT_BITS_P_12_20

#define C_P_ADIC_12_20_DEBUG true

typedef uint32_t p1220_t;

#define SIGNIFICAND_MASK_P_12_20 ((1ULL << SIGNIFICAND_BITS_P_12_20) - 1)
#define EXPONENT_MASK_P_12_20 (((1ULL << EXPONENT_BITS_P_12_20) - 1) << SIGNIFICAND_BITS_P_12_20)
#define SIGNIFICAND_SIGN_MASK_P_12_20 (1U << (SIGNIFICAND_BITS_P_12_20 - 1))
#define EXPONENT_SIGN_MASK_P_12_20 (1U << (EXPONENT_BITS_P_12_20 - 1))
#define BITS_SIGN_MASK_P_12_20 (1U << (BITS_P_12_20 - 1))

// construct p-adic 1220
p1220_t new_p1220(uint32_t exp, uint32_t sig);
// exponent part of p-adic 1220
uint32_t exp_p1220(p1220_t a);
// significand part of p-adic 1220
uint32_t sig_p1220(p1220_t a);
// add p-adic 1220
p1220_t add_p1220(p1220_t a, p1220_t b);
// subtract p-adic 1220
p1220_t sub_p1220(p1220_t a, p1220_t b);
// negate p-adic 1220
p1220_t neg_p1220(p1220_t a);
// multiply p-adic 1220
p1220_t mul_p1220(p1220_t a, p1220_t b);
// divide p-adic 1220
p1220_t div_p1220(p1220_t a, p1220_t b);
// equals p-adic 1220
bool equ_p1220(p1220_t a, p1220_t b);
// compare p-adic 1220
int com_p1220(p1220_t a, p1220_t b);

#endif //C_P_ADIC_12_20_H

