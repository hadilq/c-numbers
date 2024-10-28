#ifndef C_P_ADIC_02_30_H
#define C_P_ADIC_02_30_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_02_30 2
#define EXPONENT_BITS_P_02_30 06
#define BITS_P_02_30 SIGNIFICAND_BITS_P_02_30 + EXPONENT_BITS_P_02_30

#define C_P_ADIC_02_30_DEBUG true

typedef uint32_t p0230_t;

#define SIGNIFICAND_MASK_P_02_30 ((1ULL << SIGNIFICAND_BITS_P_02_30) - 1)
#define EXPONENT_MASK_P_02_30 (((1ULL << EXPONENT_BITS_P_02_30) - 1) << SIGNIFICAND_BITS_P_02_30)
#define SIGNIFICAND_SIGN_MASK_P_02_30 (1U << (SIGNIFICAND_BITS_P_02_30 - 1))
#define EXPONENT_SIGN_MASK_P_02_30 (1U << (EXPONENT_BITS_P_02_30 - 1))
#define BITS_SIGN_MASK_P_02_30 (1U << (BITS_P_02_30 - 1))

// construct p-adic 0230
p0230_t new_p0230(uint32_t exp, uint32_t sig);
// exponent part of p-adic 0230
uint32_t exp_p0230(p0230_t a);
// significand part of p-adic 0230
uint32_t sig_p0230(p0230_t a);
// add p-adic 0230
p0230_t add_p0230(p0230_t a, p0230_t b);
// subtract p-adic 0230
p0230_t sub_p0230(p0230_t a, p0230_t b);
// negate p-adic 0230
p0230_t neg_p0230(p0230_t a);
// multiply p-adic 0230
p0230_t mul_p0230(p0230_t a, p0230_t b);
// divide p-adic 0230
p0230_t div_p0230(p0230_t a, p0230_t b);
// equals p-adic 0230
bool equ_p0230(p0230_t a, p0230_t b);
// compare p-adic 0230
int com_p0230(p0230_t a, p0230_t b);

#endif //C_P_ADIC_02_30_H

