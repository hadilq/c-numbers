#ifndef C_P_ADIC_CCC_16_H
#define C_P_ADIC_CCC_16_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_CCC_16 11
#define EXPONENT_BITS_P_CCC_16 5
#define BITS_P_CCC_16 SIGNIFICAND_BITS_P_CCC_16 + EXPONENT_BITS_P_CCC_16

#define C_P_ADIC_CCC_16_DEBUG true

typedef uint16_t pDDD16_t;

#define SIGNIFICAND_MASK_P_CCC_16 ((1ULL << SIGNIFICAND_BITS_P_CCC_16) - 1)
#define EXPONENT_MASK_P_CCC_16 (((1ULL << EXPONENT_BITS_P_CCC_16) - 1) << SIGNIFICAND_BITS_P_CCC_16)
#define SIGNIFICAND_SIGN_MASK_P_CCC_16 (1U << (SIGNIFICAND_BITS_P_CCC_16 - 1))
#define EXPONENT_SIGN_MASK_P_CCC_16 (1U << (EXPONENT_BITS_P_CCC_16 - 1))

// construct p-adic DDD16
pDDD16_t new_pDDD16(uint16_t exp, uint16_t sig);
// exponent part of p-adic DDD16
uint16_t exp_pDDD16(pDDD16_t a);
// significand part of p-adic DDD16
uint16_t sig_pDDD16(pDDD16_t a);
// add p-adic DDD16
pDDD16_t add_pDDD16(pDDD16_t a, pDDD16_t b);
// subtract p-adic DDD16
pDDD16_t sub_pDDD16(pDDD16_t a, pDDD16_t b);
// negate p-adic DDD16
pDDD16_t neg_pDDD16(pDDD16_t a);
// multiply p-adic DDD16
pDDD16_t mul_pDDD16(pDDD16_t a, pDDD16_t b);
// divide p-adic DDD16
pDDD16_t div_pDDD16(pDDD16_t a, pDDD16_t b);
// equals p-adic DDD16
bool equ_pDDD16(pDDD16_t a, pDDD16_t b);
// compare p-adic DDD16
int com_pDDD16(pDDD16_t a, pDDD16_t b);

#endif //C_P_ADIC_CCC_16_H

