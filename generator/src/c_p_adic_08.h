#ifndef C_P_ADIC_CCC_08_H
#define C_P_ADIC_CCC_08_H

#include <stdint.h>
#include <stdbool.h>

#define SIGNIFICAND_BITS_P_CCC_08 04
#define EXPONENT_BITS_P_CCC_08 04
#define BITS_P_CCC_08 SIGNIFICAND_BITS_P_CCC_08 + EXPONENT_BITS_P_CCC_08

#define C_P_ADIC_CCC_08_DEBUG true

typedef uint8_t pDDD08_t;

#define SIGNIFICAND_MASK_P_CCC_08 ((1ULL << SIGNIFICAND_BITS_P_CCC_08) - 1)
#define EXPONENT_MASK_P_CCC_08 (((1ULL << EXPONENT_BITS_P_CCC_08) - 1) << SIGNIFICAND_BITS_P_CCC_08)
#define SIGNIFICAND_SIGN_MASK_P_CCC_08 (1U << (SIGNIFICAND_BITS_P_CCC_08 - 1))
#define EXPONENT_SIGN_MASK_P_CCC_08 (1U << (EXPONENT_BITS_P_CCC_08 - 1))
#define BITS_SIGN_MASK_P_CCC_08 (1U << (BITS_P_CCC_08 - 1))

#define MAX_VALUE_P_CCC_08 (((1U << (EXPONENT_BITS_P_CCC_08 - 2)) - 1) << SIGNIFICAND_BITS_P_CCC_08) | ((1U << (SIGNIFICAND_BITS_P_CCC_08 - 2)) - 1)
#define MIN_VALUE_P_CCC_08 (((1U << (EXPONENT_BITS_P_CCC_08 - 2)) - 1) << SIGNIFICAND_BITS_P_CCC_08) | (SIGNIFICAND_SIGN_MASK_P_CCC_08)

// construct p-adic DDD08
pDDD08_t new_pDDD08(uint8_t exp, uint8_t sig);
// exponent part of p-adic DDD08
uint8_t exp_pDDD08(pDDD08_t a);
// significand part of p-adic DDD08
uint8_t sig_pDDD08(pDDD08_t a);
// add p-adic DDD08
pDDD08_t add_pDDD08(pDDD08_t a, pDDD08_t b);
// subtract p-adic DDD08
pDDD08_t sub_pDDD08(pDDD08_t a, pDDD08_t b);
// negate p-adic DDD08
pDDD08_t neg_pDDD08(pDDD08_t a);
// multiply p-adic DDD08
pDDD08_t mul_pDDD08(pDDD08_t a, pDDD08_t b);
// divide p-adic DDD08
pDDD08_t div_pDDD08(pDDD08_t a, pDDD08_t b);
// equals p-adic DDD08
bool equ_pDDD08(pDDD08_t a, pDDD08_t b);
// compare p-adic DDD08
int com_pDDD08(pDDD08_t a, pDDD08_t b);

#endif //C_P_ADIC_CCC_08_H

