#ifndef C_P_ADIC_CCC_32_H
#define C_P_ADIC_CCC_32_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_CCC_32 26
#define EXPONENT_BITS_P_CCC_32 06
#define BITS_P_CCC_32 SIGNIFICAND_BITS_P_CCC_32 + EXPONENT_BITS_P_CCC_32

#define C_P_ADIC_CCC_32_DEBUG true

typedef uint32_t pDDD32_t;

#define SIGNIFICAND_MASK_P_CCC_32 ((1ULL << SIGNIFICAND_BITS_P_CCC_32) - 1)
#define EXPONENT_MASK_P_CCC_32 (((1ULL << EXPONENT_BITS_P_CCC_32) - 1) << SIGNIFICAND_BITS_P_CCC_32)
#define SIGNIFICAND_SIGN_MASK_P_CCC_32 (1U << (SIGNIFICAND_BITS_P_CCC_32 - 1))
#define EXPONENT_SIGN_MASK_P_CCC_32 (1U << (EXPONENT_BITS_P_CCC_32 - 1))
#define BITS_SIGN_MASK_P_CCC_32 (1U << (BITS_P_CCC_32 - 1))

#define MAX_VALUE_P_CCC_32 (((1U << (EXPONENT_BITS_P_CCC_32 - 2)) - 1) << SIGNIFICAND_BITS_P_CCC_32) | ((1U << (SIGNIFICAND_BITS_P_CCC_32 - 2)) - 1)
#define MIN_VALUE_P_CCC_32 (((1U << (EXPONENT_BITS_P_CCC_32 - 2)) - 1) << SIGNIFICAND_BITS_P_CCC_32) | (SIGNIFICAND_SIGN_MASK_P_CCC_32)

// construct p-adic DDD32
pDDD32_t new_pDDD32(uint32_t exp, uint32_t sig);
// exponent part of p-adic DDD32
uint32_t exp_pDDD32(pDDD32_t a);
// significand part of p-adic DDD32
uint32_t sig_pDDD32(pDDD32_t a);
// add p-adic DDD32
pDDD32_t add_pDDD32(pDDD32_t a, pDDD32_t b);
// subtract p-adic DDD32
pDDD32_t sub_pDDD32(pDDD32_t a, pDDD32_t b);
// negate p-adic DDD32
pDDD32_t neg_pDDD32(pDDD32_t a);
// multiply p-adic DDD32
pDDD32_t mul_pDDD32(pDDD32_t a, pDDD32_t b);
// divide p-adic DDD32
pDDD32_t div_pDDD32(pDDD32_t a, pDDD32_t b);
// equals p-adic DDD32
bool equ_pDDD32(pDDD32_t a, pDDD32_t b);
// compare p-adic DDD32
int com_pDDD32(pDDD32_t a, pDDD32_t b);

#endif //C_P_ADIC_CCC_32_H

